#include "SubstitutionCypher.h"

string SubstitutionCypher::encrypt(string plain, string key)
{
    if(key.length() < 26) return "Encryption ERROR: small key length";
    for(int i = 0; i < plain.length(); i++)
    {
        int charIndex = tolower(plain[i]) - 'a';
        plain[i] = toupper(key[charIndex]);
    }
    return plain;
}

string SubstitutionCypher::decrypt(string crypto, string key)
{
    if (key.length() < 26)
        return "Decryption ERROR: small key length";
    
    /*** Create an inverse key where each letter is replaced by an alphabetical letter depending on its position in the key
     * */
    string inverseKey = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i<26; i++){
            //inverseKey[Key letter alphabetical order] = Letter corresponding to its order in key;
            char currentLetter = i + 'a';
            char currentKeyLetter = tolower(key[i]) - 'a';
            inverseKey[currentKeyLetter] = currentLetter;
        }

    /*** Ecnrypt the message using the inverse key, resulting in its decryption.
     * */
    for(int i = 0; i < crypto.length(); i++)
    {
        int charIndex = tolower(crypto[i]) - 'a';
        crypto[i] = tolower(inverseKey[charIndex]);
    }
    return crypto;
}

string SubstitutionCypher::hack(string crypto) {
    string sFrequencyTable = "etaiosnrhdlucmfywgpbvkxqjz";
    string alphabit = "abcdefghijklmnopqrstuvwxyz";


    /////////bigrams
    int** doubleFreq = new int* [26];
    for (int i = 0; i<26; i++)
        doubleFreq[i] = new int[26];

    for (int i = 0; i<26; i++)
        for (int j = 0; i<26; i++)
            doubleFreq[i][j]  = 0;

    for (int i = 0; i<crypto.length()-1; i++) {
        int a = tolower(crypto[i]);
        int b = tolower(crypto[i+1]);
        int firstCharIndex = a - 'a';
        int secondCharIndex = b - 'a';
        doubleFreq[firstCharIndex][secondCharIndex]++;
    }


    int singleFreq[26] = {0};

    for (int i = 0; i<crypto.length(); i++) {
        crypto[i] = tolower(crypto[i]);
        int charIndex = crypto[i] - 'a';
        singleFreq[charIndex]++;
    }


    string invkey = "00000000000000000000000000";

    for (int i = 0; i<26; i++){
        int maxInd = 0;
        for (int j = 0; j<26; j++){ // find max
            if (singleFreq[maxInd]<singleFreq[j]) maxInd = j;
        }
        invkey[maxInd] = sFrequencyTable[i];
        singleFreq[maxInd] = -1;
    }


    for (int i = 0; i<crypto.length(); i++)
        crypto[i] = tolower(invkey[tolower(crypto[i]) - 'a']);
    return crypto;

}

float SubstitutionCypher::getHitRatio (string plain, string encrypted) {
    float hits = 0;
    for (int i = 0; i<encrypted.length(); i++){
        if (tolower(plain[i]) == encrypted[i]) hits++;
    }
    cout << "Hit ratio: " << hits * 100 / encrypted.length() << "%";
    return hits;
}

