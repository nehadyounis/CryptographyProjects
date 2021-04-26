//
// Created by MacBook Pro on 4/15/21.
//

#ifndef CRYPTOGRAPHYPROJECTS_SUBSTITUTIONCIPHER_H
#define CRYPTOGRAPHYPROJECTS_SUBSTITUTIONCIPHER_H

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class SubstitutionCipher
{
public:
    /***
     * Returns the most repeated string of the specified length in the input string.
     * length: The length of the string.
     * s: The input string.
     * */
    string mostFrequent(string s, int length);
    string encrypt(string plain, string key);
    string decrypt(string crypto, string key);
};



#endif //CRYPTOGRAPHYPROJECTS_SUBSTITUTIONCIPHER_H
