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
