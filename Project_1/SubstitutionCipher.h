//
// Created by MacBook Pro on 4/15/21.
//

#ifndef CRYPTOGRAPHYPROJECTS_SUBSTITUTIONCIPHER_H
#define CRYPTOGRAPHYPROJECTS_SUBSTITUTIONCIPHER_H

#include <iostream>
#include <string>
#include <ctype.h>
#include <iomanip>

#define TOP_SIZE 5

using namespace std;

class SubstitutionCipher
{
private:
    int freq_1[26];
    int freq_2[26][26];
    int freq_3[26][26][26];

    string topFreq_1[TOP_SIZE];
    string topFreq_2[TOP_SIZE];
    string topFreq_3[TOP_SIZE];
public:
    SubstitutionCipher();
    void printFrequencies(int length, bool printZeros = false);
    void printTopFrequencies(int length);
    void updateFrequencies(string s);
    void generateTopFrequencies();
    string encrypt(string plain, string key);
    string decrypt(string crypto, string key);
    string hack(string crypto);
    float getHitRatio (string plain, string encrypted);
};



#endif //CRYPTOGRAPHYPROJECTS_SUBSTITUTIONCIPHER_H
