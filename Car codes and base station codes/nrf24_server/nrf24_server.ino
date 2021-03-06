// nrf24_server.pde
// -*- mode: C++ -*-
// Example sketch showing how to create a simple messageing server
// with the RH_NRF24 class. RH_NRF24 class does not provide for addressing or
// reliability, so you should only use RH_NRF24  if you do not need the higher
// level messaging abilities.
// It is designed to work with the other example nrf24_client
// Tested on Uno with Sparkfun NRF25L01 module
// Tested on Anarduino Mini (http://www.anarduino.com/mini/) with RFM73 module
// Tested on Arduino Mega with Sparkfun WRL-00691 NRF25L01 module

#include <SPI.h>
#include <RH_NRF24.h>

#include <Servo.h>  //servo library
Servo myservo;      // create servo object to control servo


/*Team: Initializatio Section 
  * 
  * ***** RF ******
  */
// Singleton instance of the radio driver
RH_NRF24 nrf24;
//RH_NRF24 nrf24_Follower;

// RH_NRF24 nrf24(8, 7); // use this to be electrically compatible with Mirf
// RH_NRF24 nrf24(8, 10);// For Leonardo, need explicit SS pin
// RH_NRF24 nrf24(8, 7); // For RFM73 on Anarduino Mini

int Address=0;
String Command="";
uint8_t Follower_Stop[] = "2_Stop!";
uint8_t Follower_Forward[] = "2_Forward!";
uint8_t Follower_Back[] = "2_Back!";
uint8_t Follower_Right[] = "2_Right!";
uint8_t Follower_Left[] = "2_Left!";
uint8_t Dist_BaseStation[]="0_ ";

void  DebugPrintln(String message)
  {
    //DebugPrintln(message);
  }
  void DebugPrint(String message)
  {
    //DebugPrint(message);
  }

/*Team: Initializatio Section 
  * 
  * ***** Car Robot ******
  */

  int Echo = A4;  
  int Trig = A5; 
  
  #define ENA 5
  #define ENB 6
  #define IN1 7
  #define IN2 8
  #define IN3 9
  #define IN4 4 //11
  #define carSpeed 255
  #define rotationSpeed1 200
  #define rotationSpeed2 50
  int rightDistance = 0, leftDistance = 0, middleDistance = 0;

/*Team: Car Move Functions Section 
  * 
  * ***** Car Robot ******
  */
  
  void forward(){ 
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  DebugPrintln("Forward");
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  DebugPrintln("Back");
}

void left() {
  analogWrite(ENA, rotationSpeed2);
  analogWrite(ENB, rotationSpeed1);
  digitalWrite(IN1, HIGH);//LOW
  digitalWrite(IN2, LOW);//HIGH
  digitalWrite(IN3, LOW);//LOW
  digitalWrite(IN4, HIGH); //HIGH
  DebugPrintln("Left");
}

void right() {
  analogWrite(ENA, rotationSpeed1);
  analogWrite(ENB, rotationSpeed2);
  digitalWrite(IN1, HIGH);//HIGH
  digitalWrite(IN2, LOW);//LOW
  digitalWrite(IN3, LOW);//HIGH
  digitalWrite(IN4, HIGH);//LOW
  DebugPrintln("Right");
}
  
void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  DebugPrintln("Stop!");
} 

//Ultrasonic distance measurement Sub function
int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(1);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
}  




void setup() 
{


//Team:********** RF Code Begin************  
  Serial.begin(9600);
  while (!Serial) 
    ; // wait for serial port to connect. Needed for Leonardo only
  if (!nrf24.init())
    DebugPrintln("nrf24 init failed");
  //if (!nrf24_Follower.init())
   // DebugPrintln("nrf24_Follower nrf24 init failed");
   
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1))
    DebugPrintln("setChanne l failed");
 // if (!nrf24_Follower.setChannel(2))
    //DebugPrintln("setChanne 2 failed");
    
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    DebugPrintln("setRF 1 failed");  
 // if (!nrf24_Follower.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
  //  DebugPrintln("setRF 2 failed");
//Team:********** RF Code End************


//Team:********** Car Code Begin************
myservo.attach(3);  // attach servo on pin 3 to servo object
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
  //Team:********** Car Code End************

      
}

void loop()
{

    //Team:********** RF Code Begin************

  //delay(50);

  middleDistance = Distance_test();
  Dist_BaseStation[2]=( uint8_t)middleDistance;
   nrf24.send(Dist_BaseStation, sizeof(Dist_BaseStation));
   nrf24.waitPacketSent();
   DebugPrint("Sending Distance:");
   DebugPrintln(middleDistance +"");
  DebugPrintln("Listening.....");
  if (nrf24.available())//&& nrf24_Follower.available())
  {
    // Should be a message for us now   
    uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
    //uint8_t buf[2];
    uint8_t len = sizeof(buf);

   int i=2;
    if (nrf24.recv(buf, &len))
    {
//      NRF24::printBuffer("request: ", buf, len);
      
     Command="";
      //Address=atoi(strtok((char*)buf,"_"));
      Address=buf[0];
      i=2;
      while(buf[i] !=0)
      {
        Command+=(char)buf[i];
        i++;
      }
      
      //Command;
       DebugPrintln(char(Address)+"");
      if(Address=='1')
      { 
        if(Command.equals("Forward!"))
        {
        DebugPrint("got Command: ");
        DebugPrintln((char*)buf);
        DebugPrintln("Calling Function Forward();");
        stop(); 
        forward(); 
        DebugPrintln("Sending Forward Command to the follower...");
        nrf24.send(Follower_Forward, sizeof(Follower_Forward));
        nrf24.send(Follower_Forward, sizeof(Follower_Forward));
        //nrf24.send(Follower_Forward, sizeof(Follower_Forward));


         }
        else if(Command.equals("Back!"))
        {
         DebugPrint("got command: ");
         DebugPrintln((char*)buf); 
         DebugPrintln("Calling Function Back();");
         stop();
         back();
         DebugPrintln("Sending Back Command to the follower...");
         nrf24.send(Follower_Back, sizeof(Follower_Back));
         nrf24.send(Follower_Back, sizeof(Follower_Back));
         nrf24.send(Follower_Back, sizeof(Follower_Back));
        }
        else if(Command.equals("Stop!"))
        {
         DebugPrint("got command: ");
         DebugPrintln((char*)buf); 
         DebugPrintln("Calling Function Stop();");
         stop();
         DebugPrintln("Sending Stop Command to the follower...");
         nrf24.send(Follower_Stop, sizeof(Follower_Stop));
         //nrf24.send(Follower_Stop, sizeof(Follower_Stop));
         //nrf24.send(Follower_Stop, sizeof(Follower_Stop));

        }
        else if(Command.equals("Left!"))
        {
         DebugPrint("got command: ");
         DebugPrintln((char*)buf); 
         DebugPrintln("Calling Function Left();");
         stop();
         left(); 
         DebugPrintln("Sending Left Command to the follower...");
         nrf24.send(Follower_Left, sizeof(Follower_Left));
        nrf24.send(Follower_Left, sizeof(Follower_Left));
        nrf24.send(Follower_Left, sizeof(Follower_Left));

        }
  
        else if(Command.equals("Right!"))
        {
         DebugPrint("got command: ");
         DebugPrintln((char*)buf); 
         DebugPrintln("Calling Function Right();");
         stop();
         right();
         DebugPrintln("Sending Right Command to the follower...");
         nrf24.send(Follower_Right, sizeof(Follower_Right));
        nrf24.send(Follower_Right, sizeof(Follower_Right));
        nrf24.send(Follower_Right, sizeof(Follower_Right));
        }
      }
      // Send a reply
      uint8_t data[] = "And hello back to you";
      nrf24.send(data, sizeof(data));
      nrf24.waitPacketSent();
      DebugPrintln("Sent a reply");
    }
    else
    {
      DebugPrintln("recv failed");
    }
  }
  //Team:********** RF Code End************

  //Team:********** Car Code Begin************

 /*
 //myservo.write(90);  //setservo position according to scaled value
    delay(500); 
    middleDistance = Distance_test();

    if(middleDistance <= 20) {     
      stop();
      delay(500);                         
      myservo.write(10);          
      delay(1000);      
      rightDistance = Distance_test();
      
      delay(500);
      myservo.write(90);              
      delay(1000);                                                  
      myservo.write(180);              
      delay(1000); 
      leftDistance = Distance_test();
      
      delay(500);
      myservo.write(90);              
      delay(1000);
      if(rightDistance > leftDistance) {
        right();
        delay(360);
      }
      else if(rightDistance < leftDistance) {
        left();
        delay(360);
      }
      else if((rightDistance <= 20) || (leftDistance <= 20)) {
        back();
        delay(180);
      }
      else {
        forward();
      }
    }  
    else {
        forward();
    }   
    */
    //Team:********** Car Code End************ 

}

