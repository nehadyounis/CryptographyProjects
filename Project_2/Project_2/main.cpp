#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "hill.h"
#include <iomanip>

using namespace std;

string readKey();
string readLetterString(ifstream& fileObj, string fileName, bool upperCase = false);
void writeToFile(ofstream& fileObj, string fileName, string s);

int main()
{
    //Files for encryption input/output
    ifstream plainTxtFile;
    ofstream encryptTxtFile;

    //Files for decryption input/output
    ifstream decryptSrcFile;
    ofstream decryptTxtFile;

    //Encryption and decryption class
    hillCipher hillObj;

    char inputChoice = 'r';
    while(tolower(inputChoice) == 'r')
    {
        cout << "Welcome to the Hill cipher program." << endl << endl;
        cout <<"Would you like to (e)ncrypt or (d)ecrypt? : ";
        cin >> inputChoice;
        if(tolower(inputChoice) == 'e')
        {
            //Encryption code.
            cout << endl << "Encrypting..." << endl;

            string plainS;
            string key;

            plainS = readLetterString(plainTxtFile, "plainTxt.txt");
            key = readKey();

            //Print key and confirm it is read
            cout << "Key successfully read as :" << endl;
            cout << setw(3) << key[0] << setw(3) << key[1] << setw(3) << key[2] << endl;
            cout << setw(3) << key[3] << setw(3) << key[4] << setw(3) << key[5] << endl;
            cout << setw(3) << key[6] << setw(3) << key[7] << setw(3) << key[8] << endl;

            writeToFile(encryptTxtFile, "encryptTxt.txt", hillObj.encrypt(plainS, key));
            cout << "Encryption completed. Results are written in encryptTxt.txt file." << endl;
        }
        else if(tolower(inputChoice) == 'd')
        {
            //Decryption code
            cout << endl << "Decrypting..." << endl;

            string encryptS;
            string key;

            encryptS = readLetterString(decryptSrcFile, "decryptSrcTxt.txt");
            key = readKey();
            writeToFile(decryptTxtFile, "decryptTxt.txt", hillObj.decrypt(encryptS, key));
            cout << "Decryption completed. Results are written in decryptTxt.txt file." << endl;
        }
        else
        {
            cout << endl << "Unknown input.." << endl;
        }
        cout << endl << "Write (r) to re-run the program or any other character to exit: ";
        cin >> inputChoice;
    }


    cout << endl << "Thank you for using the Hill cipher encryption program." << endl;
    return 0;
}

string readKey()
{
    string s;
    char x;
    cout << "Enter 9 letters for the key: " << endl;
    for(int i = 0; i < 9; i++)
    {
        cin >> x;
        s += (x);
    }
    return s;
}

string readLetterString(ifstream& fileObj, string fileName, bool upperCase)
{
    string s;
    char ch;
    fileObj.open(fileName);
    while(1)
    {
        fileObj >> ch;
        if(fileObj.eof())
            break;
        if(tolower(ch) <= 'z' && tolower(ch) >= 'a')
            s += ( tolower(ch)*(!upperCase) + toupper(ch)*upperCase);
    }
    fileObj.close();
    return s;
}

void writeToFile(ofstream& fileObj, string fileName, string s)
{
    fileObj.open(fileName);
    fileObj << s;
    fileObj.close();
}
