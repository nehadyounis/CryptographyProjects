#include <iostream>
#include <string>
#include "SubstitutionCypher.h"
#include <conio.h>

using namespace std;

int main()
{
    int x; //For holding

    SubstitutionCypher encrypter;
    string text = "TheQuickBrownFoxJumpsOverTheFencQuicklyWithoutAnyoneNoticingIncludingYou";
    string key = "bcdefghijklmnopqrstuvwxyza";
    string crypto = encrypter.encrypt(text, key);
    cout << text << endl;
    cout << crypto << endl;
    cout << encrypter.decrypt(crypto, key);

    cout << endl << "Press any key to exit....";
    x = getch(); //Hold
}