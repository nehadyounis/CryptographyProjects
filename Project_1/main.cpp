#include <iostream>
#include <string>
#include "SubstitutionCipher.h"
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    //Plain text file to be encrypted
    ifstream plainFile("plain text.txt");

    //Encrypted file writing
    ofstream cryptFile("encrypt.txt");

    //Encrypted file reading
    ifstream decryptSource("decrypt source.txt");

    //Decrypted file
    ofstream decryptFile("decrypt.txt");

    string text;
    string decrypt;
    string encrypt;
    string key = "qwertyuiopasdfghjklzxcvbnm";


    SubstitutionCipher encrypter;

    //Loop for reading from plainFile to text string.
    char c;
    while(1)
    {
        //Read character from file and insure it has not reached the end.
        plainFile >> c;
        if(plainFile.eof()) break;

        //If the character is not a space, add it to text string.
        c = tolower(c);
        if(c <= 'z' && c >= 'a')
            text += c;

    }

    while(1)
    {
        //Read character from file and insure it has not reached the end.
        decryptSource >> c;
        if(decryptSource.eof()) break;

        //If the character is not a space, add it to text string.
        c = tolower(c);
        if(c <= 'z' && c >= 'a')
            encrypt += c;

    }

    char choice;
    cout << "Welcome to the encryption software..." << endl << endl;
    cout << "Do you want to (e)ncrypt, (d)ecrypt, (h)ack, or (c)heck hit ratio: ";
    cin >> choice;

    if(choice == 'e')
    {
        //Prompt the user for the key
        cout << "Please enter the key consisting of a combination of the 26 alphabetical letters. (a) for default key: ";
        cin >> key;
        if(key == "a") key = "qwertyuiopasdfghjklzxcvbnm";

        //Clear the encrypt file.
        cryptFile.clear();

        //Encrypt and place the result in the encrypt.txt file.
        cryptFile << encrypter.encrypt(text, key);
        cout << "The encrypted text is saved to encrypt.txt file." << endl;
    }
    else if (choice == 'd')
    {
        //Prompt the user for the key
        cout << "Please enter the key consisting of a combination of the 26 alphabetical letters: ";
        cin >> key;

        //Decrypt and place the result in the decrypt.txt file.
        decryptFile << encrypter.decrypt(encrypt, key);
        cout << "The decrypted text is saved to decrypt.txt file." << endl;
    }
    else if (choice == 'h')
    {
        encrypter.updateFrequencies(encrypt);
        encrypter.generateTopFrequencies();
        //encrypter.printTopFrequencies(1);
        string hacked = encrypter.hack(encrypt);
        decryptFile << hacked << endl;
        encrypter.getHitRatio(text, hacked);
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
