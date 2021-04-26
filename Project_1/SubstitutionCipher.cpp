#include "SubstitutionCipher.h"

using namespace std;

    /* Old implementation that uses strings replacement
bool replace(string& str, const string& from, const string& to)
{

    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;

}
*/

/***
 * Returns the most repeated string of the specified length in the input string.
 * length: The length of the string.
 * s: The input string.
 * */
string SubstitutionCipher::mostFrequent(string s, int length)
{

}

string SubstitutionCipher::encrypt(string plain, string key)
{
    if(key.length() < 26) return "Encryption ERROR: small key length";
    for(int i = 0; i < plain.length(); i++)
    {
        int charIndex = tolower(plain[i]) - 'a';
        plain[i] = toupper(key[charIndex]);
    }
    return plain;
}

string SubstitutionCipher::decrypt(string crypto, string key)
{
    if (key.length() < 26)
        return "Decryption ERROR: small key length";

    /*** Create an inverse key where each letter is replaced by an alphabetical letter depending on its position in the key
     * */
    string inverseKey = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < 26; i++)
    {
        //inverseKey[Key letter alphabetical order] = Letter corresponding to its order in key;
        inverseKey[tolower(key[i]) - 'a'] = i + 'a';
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
