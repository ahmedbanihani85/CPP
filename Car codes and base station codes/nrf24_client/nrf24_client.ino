// nrf24_client.pde
// -*- mode: C++ -*-
// Example sketch showing how to create a simple messageing client
// with the RH_NRF24 class. RH_NRF24 class does not provide for addressing or
// reliability, so you should only use RH_NRF24 if you do not need the higher
// level messaging abilities.
// It is designed to work with the other example nrf24_server.
// Tested on Uno with Sparkfun NRF25L01 module
// Tested on Anarduino Mini (http://www.anarduino.com/mini/) with RFM73 module
// Tested on Arduino Mega with Sparkfun WRL-00691 NRF25L01 module

#include <SPI.h>
#include <RH_NRF24.h>

// Singleton instance of the radio driver
RH_NRF24 nrf24;
// RH_NRF24 nrf24(8, 7); // use this to be electrically compatible with Mirf
// RH_NRF24 nrf24(8, 10);// For Leonardo, need explicit SS pin
// RH_NRF24 nrf24(8, 7); // For RFM73 on Anarduino Mini


uint8_t receivedChar=NULL;
boolean newData = false;
 uint8_t data[] = "Hello World!";
  uint8_t ForwardCommand[]="1_Forward!\0";
 uint8_t BackCommand[]="1_Back!\0";
 uint8_t StopCommand[]="1_Stop!\0";
 uint8_t LeftCommand[]="1_Left!\0";
 uint8_t RightCommand[]="1_Right!\0";
 uint8_t ObstacleDistance=255;
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);

  void  DebugPrintln(String message)
  {
    //DebugPrintln(message);
  }
  void DebugPrint(String message)
  {
    //DebugPrint(message);
  }
void setup() 
{
  Serial.begin(9600);
  while (!Serial) 
    ; // wait for serial port to connect. Needed for Leonardo only
  if (!nrf24.init())
    DebugPrintln("init failed");
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!nrf24.setChannel(1))
    DebugPrintln("setChannel failed");
  if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    DebugPrintln("setRF failed");    
}


void loop()
{

   /**/if (nrf24.waitAvailableTimeout(10))
    {
      if (nrf24.recv(buf, &len))
      {
        if(buf[0]=='0')
        {
          ObstacleDistance=buf[2];
        DebugPrint("got Distance: ");
        char sd[10];
        sprintf(sd,"%d",ObstacleDistance);
        DebugPrintln(sd);
        }
      }
      else
      {
        DebugPrintln("recv failed");
      }
    }

  
   recvOneChar();
 
  DebugPrintln("Sending to nrf24_server");
  // Send a message to nrf24_server
  
  //
  
  if(recvOneChar()!=NULL)
  {
  nrf24.send(data, sizeof(data));
  }
  else
  {
    if((char)receivedChar =='f' ||(char)receivedChar =='F' ||(char)receivedChar =='1' )
    {
      nrf24.send(ForwardCommand, sizeof(ForwardCommand));
      nrf24.send(ForwardCommand, sizeof(ForwardCommand));
      nrf24.send(ForwardCommand, sizeof(ForwardCommand));

    }
    else if((char)receivedChar =='b' ||(char)receivedChar =='B' ||(char)receivedChar =='2' )
    {
      nrf24.send(BackCommand, sizeof(BackCommand));
     nrf24.send(BackCommand, sizeof(BackCommand));
     nrf24.send(BackCommand, sizeof(BackCommand));

    }
    else if((char)receivedChar =='r' ||(char)receivedChar =='R' ||(char)receivedChar =='3' )
    {
      nrf24.send(RightCommand, sizeof(RightCommand));
      nrf24.send(RightCommand, sizeof(RightCommand));
      nrf24.send(RightCommand, sizeof(RightCommand));

    }
    else if((char)receivedChar =='l' ||(char)receivedChar =='L' ||(char)receivedChar =='4' )
    {
      nrf24.send(LeftCommand, sizeof(LeftCommand));
      nrf24.send(LeftCommand, sizeof(LeftCommand));
      nrf24.send(LeftCommand, sizeof(LeftCommand));

    }
    else if((char)receivedChar =='s' ||(char)receivedChar =='S' ||(char)receivedChar =='0' || (ObstacleDistance >0 && ObstacleDistance<=60 ) )
    {
      nrf24.send(StopCommand, sizeof(StopCommand));
      nrf24.send(StopCommand, sizeof(StopCommand));
      nrf24.send(StopCommand, sizeof(StopCommand));

    }
    else
    {
      DebugPrintln("Command Not Found!");  
    }

    receivedChar=NULL;
  }
  showNewData();
  nrf24.waitPacketSent();
  // Now wait for a reply
  

  /**/
  if (nrf24.waitAvailableTimeout(10))
  { 
    // Should be a reply message for us now   
    if (nrf24.recv(buf, &len))
    {
      DebugPrint("got reply: ");
      DebugPrintln((char*)buf);
    }
    else
    {
      DebugPrintln("recv failed");
    }
  }
  else
  {
    DebugPrintln("No reply, is nrf24_server running?");
  }
 // delay(400);
 ObstacleDistance=255;
}


 uint8_t recvOneChar() {
  //while(!Serial.available());
  // while(!(receivedChar = Serial.read()) || !newData);

 if (Serial.available() > 0) 
{
 receivedChar = Serial.read();
 //newData = true;
 return receivedChar;
}
return NULL;
}

void showNewData() {
   if (newData == true) {
   DebugPrint("This just in ... ");
   DebugPrintln(receivedChar+"");
  
    
   
   newData = false;
   }
}


