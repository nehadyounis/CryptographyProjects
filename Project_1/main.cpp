#include <iostream>
#include <string>
#include "SubstitutionCipher.h"
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream plainFile("plain text.txt");
    ofstream cryptFile("encrypt.txt");
    ofstream decryptFile("decrypt.txt");

    string text;
    string key = "qwertyuiopasdfghjklzxcvbnm";
    string encrypt;

    SubstitutionCipher encrypter;

    //Loop for reading from plainFile to text string.
    char c;
    while(1)
    {
        //Read character from file and insure it has not reached the end.
        plainFile >> c;
        if(plainFile.eof()) break;

        //If the character is not a space, add it to text string.
        if(c != ' ')
            text += c;
    }

    char choice;
    cout << "Welcome to the encryption software..." << endl << endl;
    cout << "Do you want to (e)ncrypt, (d)ecrypt, (h)ack, or (c)heck hit ratio: ";
    cin >> choice;

    if(choice == 'e')
    {
        //Prompt the user for the key
        cout << "Please enter the key consisting of a combination of the 26 alphabetical letters: ";
        cin >> key;

        //Encrypt and place the result in the encrypt.txt file.
        encrypt = encrypter.encrypt(text, key);
        cryptFile << encrypt;
        cout << "The encrypted text is saved to encrypt.txt file." << endl;
    }
    else if (choice == 'd')
    {
        //Prompt the user for the key
        cout << "Please enter the key consisting of a combination of the 26 alphabetical letters: ";
        cin >> key;

        //Decrypt and place the result in the decrypt.txt file.
        decryptFile << encrypter.decrypt(text, key);
        cout << "The decrypted text is saved to decrypt.txt file." << endl;
    }
    else if (choice == 'h')
    {
        //To Do
    }
    else if (choice == 'c')
    {
        //To Do
    }
    else
    {
        cout << "Wrong user input. Restart the program and try again." << endl;
    }
}
