//Name: Ahmad Mohamad Bani Hani
//ID: FL6800
//CSC5270 HW1

#include<iostream>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;
//System Variables & Data
char Tableau[27][27];
string Key="ABCDEFGHIJKLMNOPQRSTUVWXYZ_";
string PlainText="";
string EncryptedText="";
string DecryptedText="";

//System Functions
int GetIndex(char);
void GetTableau();
void FileLineInTableau(string line,int linenumber);
void GetPlainTextFile(string filename);
void GetEncryptedTextFile(string filename);
void VigenereCipher();
void VigenereDecipher();

void main()
{
	//--Code Block One:
	/*The block is used to:
	1-load the Tablueau into memory from txt file in the same directory
	of the EXE file. This file is called tableau.txt
	2- Then load the Plain Text from the file called plaintext.txt
	3-Encrypt the loaded text & print the result
	4-Dycrypt the previously encrypted text & print the result
	*/
	string TempKey;
	cout << "\n Please insert the Encryption key you want. OtherWise, if you entered 0 it will use the 26 English letters and _\n";
	cin >> TempKey;
	if (TempKey[0]!='0')
	{
		Key = "";
		for (int i = 0; i < TempKey.length();i++)
		Key+= toupper(TempKey[i]);
	}
		
	/**/GetTableau();//Load the Tablueau from the txt file
	GetPlainTextFile("plaintext.txt");//load the plain text 
	cout << "\nThe Origional Text:\n" << PlainText << endl;
	VigenereCipher();
	cout << "\nThe Encrypted Text:\n" << EncryptedText << endl;
	VigenereDecipher();
	cout << "\nThe Decrypted Text:\n" << DecryptedText << endl;
	//************************************************************************
	//************************************************************************
	//--Code Block Two:
	/*The block is used to:
	1-load the Tablueau into memory from txt file in the same directory
	of the EXE file. This file is called tableau.txt
	2- Then load the Encrypted Text from the file called encryptedtext.txt
	3-Dycrypt the previously encrypted text & print the result
	*/
	/*GetTableau();//Load the Tablueau from the txt file
	GetEncryptedTextFile("encryptedtext.txt");
	VigenereDecipher();
	cout << "\nThe Decrypted Text:\n" << DecryptedText << endl; */
}

int GetIndex(char n)
{
	int o = 'A';
	if (n != '_')
		return static_cast<int>(toupper(n)) - o;
	return 26;
}
void GetTableau()
{
	
	string line;
	int linecount = 0;

	ifstream tableauFile("tableau.txt");
	if (tableauFile.is_open())
	{
		while (getline(tableauFile, line))
		{
			FileLineInTableau(line, linecount);
			linecount++;
		}
		tableauFile.close();
	}

	else cout << "Unable to open file";



}

void FileLineInTableau(string line, int linenumber)
{

	if (line.length() > 27)
	{
		cout << "\nThe is bigger than the Tableau row. \n "<< endl;
	}
	else
	{
		for (int i = 0; i < 27; i++)
		{
			Tableau[linenumber][i] = line[i];
			//cout << Tableau[linenumber][i] ;

		}
	//	cout << endl;
	}

}

void GetPlainTextFile(string filename)
{
	PlainText = "";
	string line;
	ifstream TxtFile(filename);
	if (TxtFile.is_open())
	{
		while (getline(TxtFile, line))
		{
			PlainText += line;
		}
		TxtFile.close();
	}

	else cout << "Unable to open file";


}

void GetEncryptedTextFile(string filename)
{
	EncryptedText = "";
	string line;
	ifstream TxtFile(filename);
	if (TxtFile.is_open())
	{
		while (getline(TxtFile, line))
		{
			EncryptedText += line;
		}
		TxtFile.close();
	}

	else cout << "Unable to open file";


}

void VigenereCipher()
{
	EncryptedText = "";
	int row = -1;
	int column = -1;
	int j = 0;
	for (int i = 0; i < PlainText.length();i++)
	{
		row = GetIndex(Key[j]);
		column=GetIndex(PlainText[i]);
		
		j = (j + 1) % Key.length();//To keep rotating in the key
		if (row >= 0 && row < 27 && column >= 0 && column < 27)
			EncryptedText += Tableau[row][column];
		else
			cout << "\n Out of Tableau index..." << endl;
	}

}

void VigenereDecipher()
{
	DecryptedText = "";
	int row = -1;
	int column = -1;
	int j = 0;
	char l ;
	for (int i = 0; i < EncryptedText.length(); i++)
	{
		row = GetIndex(Key[j]);
		j = (j + 1) % Key.length();//To keep rotating in the key
		l = EncryptedText[i];
		if (l != '_')
		l = toupper(l);
		for (int k = 0; k < 27; k++)
		{
			if (Tableau[row][k] == l)
			{
				column = k;
				break;
			}
				
		}
		DecryptedText += Tableau[0][column];
	}

}