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

    //Prompt the user for the key
    cout << "Welcome to the encryption software..." << endl << endl;
    cout << "Please enter the key consisting of a combination of the 26 alphabetical letters: ";
    cin >> key;

    encrypt = encrypter.encrypt(text, key);
    cryptFile << encrypt;
    cout << "The encrypted text is saved to encrypt.txt file." << endl;
}
