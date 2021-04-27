#include "SubstitutionCipher.h"

using namespace std;

SubstitutionCipher::SubstitutionCipher()
{
    //Initialize the frequencies to zero.
    for(int i = 0; i < 26; i++)
    {
        freq_1[i] = 0;
        for(int j = 0; j < 26; j++)
        {
            freq_2[i][j] = 0;
            for(int k = 0; k < 26; k++)
            {
                freq_3[i][j][k] = 0;
            }
        }
    }
}

void SubstitutionCipher::generateTopFrequencies()
{
    //Single letter frequencies
    for(int i = 0; i< TOP_SIZE; i++)
    {
        int maxInd = 0;
        for (int j = 0; j < 26; j++)
        {
            if(freq_1[maxInd] < freq_1[j])
            {
                //Place the current letter if not already placed.
                //Loop through the top frequencies
                for(int l = 0; l < TOP_SIZE; l++)
                {
                    //If the current letter index is one of the top frequencies, don't record it in maxInd.
                    if((topFreq_1[l][0] - 'a') == j)
                        break;
                    //If it is not in the top frequencies array, then maxInd = current letter index.
                    if(l == TOP_SIZE-1) maxInd = j;
                }
            }
        }
        //Add the maxInd to the i'th location in the top frequencies array.
        topFreq_1[i] += maxInd + 'a';
    }

    //Double letter frequencies
    for(int i = 0; i< TOP_SIZE; i++)
    {
        int maxInd0 = 0;
        int maxInd1 = 0;
        for (int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++)
            {
                if(freq_2[maxInd0][maxInd1] < freq_2[j][k])
                {
                    //Place the current letter if not already placed.
                    //Loop through the top frequencies
                    for(int l = 0; l < TOP_SIZE; l++)
                    {
                        //If the current letter index is one of the top frequencies, don't record it in maxInd.
                        if((topFreq_2[l][0] - 'a') == j && (topFreq_2[l][1] - 'a') == k)
                            break;
                        //If it is not in the top frequencies array, then maxInd = current letter index.
                        if(l == TOP_SIZE-1) {maxInd0 = j; maxInd1 = k;}
                    }
                }
            }
        }
        //Add the maxInd to the i'th location in the top frequencies array.
        topFreq_2[i] += maxInd0 + 'a';
        topFreq_2[i] += maxInd1 + 'a';
    }

    //Triple letter frequencies
    for(int i = 0; i< TOP_SIZE; i++)
    {
        int maxInd0 = 0;
        int maxInd1 = 0;
        int maxInd2 = 0;
        for (int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++)
            {
                for(int t = 0; t < 26; t++)
                {
                    if(freq_3[maxInd0][maxInd1][maxInd2] < freq_3[j][k][t])
                    {
                        //Place the current letter if not already placed.
                        //Loop through the top frequencies
                        for(int l = 0; l < TOP_SIZE; l++)
                        {
                            //If the current letter index is one of the top frequencies, don't record it in maxInd.
                            if((topFreq_3[l][0] - 'a') == j && (topFreq_3[l][1] - 'a') == k && (topFreq_3[l][2] - 'a') == t)
                                break;
                            //If it is not in the top frequencies array, then maxInd = current letter index.
                            if(l == TOP_SIZE-1) {maxInd0 = j; maxInd1 = k; maxInd2 = t;}
                        }
                    }
                }
            }
        }
        //Add the maxInd to the i'th location in the top frequencies array.
        topFreq_3[i] += maxInd0 + 'a';
        topFreq_3[i] += maxInd1 + 'a';
        topFreq_3[i] += maxInd2 + 'a';
    }
}

void SubstitutionCipher::printTopFrequencies(int length)
{
    if(length == 1)
    {
        for(int i = 0; i < 5; i++)
        {
            cout << "Top " << i+1 << " letter frequency: " << topFreq_1[i] << endl;
        }
    }
    else if(length == 2)
    {
        for(int i = 0; i < 5; i++)
        {
            cout << "Top " << i+1 << " diagram frequency: " << topFreq_2[i] << endl;
        }
    }
    else if(length == 3)
    {
        for(int i = 0; i < 5; i++)
        {
            cout << "Top " << i+1 << " triagram frequency: " << topFreq_3[i] << endl;
        }
    }
    cout << "Invalid length of frequencies..." << endl;
}

/***
 * Updates the frequencies arrays according to the string s.
 * s: The input string.
 * */
void SubstitutionCipher::updateFrequencies(string s)
{
    int l = s.length();
    int i;

    //Lowercase the whole string to avoid complicated code (this is not efficient though)
    /*
    for(int t = 0; t < l; t++)
        s[t] = tolower(s[t]);
    */

    for(i = 0; i < l-2; i++)
    {
        freq_1[s[i] - 'a']++;
        freq_2[s[i] - 'a'][s[i+1] - 'a']++;
        freq_3[s[i] - 'a'][s[i+1] - 'a'][s[i+2] - 'a']++;
    }

    freq_1[s[i] - 'a']++;
    freq_2[s[i] - 'a'][s[i+1] - 'a']++;

    i++;
    freq_1[s[i] - 'a']++;
}

void SubstitutionCipher::printFrequencies(int length, bool printZeros /*= false*/)
{
    if(length == 1)
    {
        for(int i = 0; i < 26; i++)
        {
            if(!printZeros && freq_1[i] == 0) continue;
            cout << setw(3) << (char)('a'+i) << ": " <<  setw(3) << freq_1[i] << endl;
        }
    }
    else if(length == 2)
    {
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(!printZeros && freq_2[i][j] == 0) continue;
                cout << setw(3) << (char)('a'+i) << (char)('a'+j) << ": " <<  setw(3) << freq_2[i][j] << endl;
            }
        }
    }
    else if(length == 3)
    {
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                for(int k = 0; k < 26; k++)
                {
                    if(!printZeros && freq_3[i][j][k] == 0) continue;
                    cout << setw(3) << (char)('a'+i) << (char)('a'+j) << (char)('a'+k) << ": " <<  setw(3) << freq_3[i][j][k] << endl;
                }
            }
        }
    }
    else
    {
        cout << "Unsupported character frequency length." << endl;
    }
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

string SubstitutionCipher::hack(string crypto)
{
    string inverseKey = "abcdefghijklmnopqrstuvwxyz";
    string freqTable = "etaiosnrhdlucmfywgpbvkxqjz";

    char tIndex = topFreq_1[1][0] - 'a';
    char eIndex = topFreq_1[0][0] - 'a';
    char nIndex;
    char aIndex;
    char dIndex;

    //Initial code for inverse key
    for (int i = 0; i < 26; i++)
    {
        int maxInd = 0;
        for (int j = 0; j < 26; j++)
        { // find max
            if (freq_1[maxInd] < freq_1[j]) maxInd = j;
        }
        inverseKey[maxInd] = freqTable[i];
        freq_1[maxInd] = -1;
    }

    //Update inverse key with the top 5 single frequencies
    for(int i = 0; i < TOP_SIZE; i++)
    {
        inverseKey[(topFreq_1[i][0]) - 'a'] = freqTable[i];
        //cout << topFreq_1[i][0] << "-->" << freqTable[i] << endl;
    }

    //Use triple frequencies to obtain h
    for(int i = 0; i < TOP_SIZE; i++)
    {
        if(topFreq_3[i][0] == tIndex + 'a' && topFreq_3[i][2] == eIndex + 'a' )
        {
            //Then h is the middle character
            inverseKey[topFreq_3[i][1] - 'a'] = 'h';
        }
    }

    //Use triple frequencies to obtain a, n and d
    for(int i = 0; i < TOP_SIZE; i++)
    {
        //Loop until the highest frequency not including a t is found
        if(topFreq_3[i][0] == 't') continue;

        //a is the first character in the second frequency... and so on
        inverseKey[topFreq_3[i][0] - 'a'] = 'a'; aIndex = topFreq_3[i][0] - 'a';
        inverseKey[topFreq_3[i][1] - 'a'] = 'n'; nIndex = topFreq_3[i][1] - 'a';
        inverseKey[topFreq_3[i][2] - 'a'] = 'd'; dIndex = topFreq_3[i][2] - 'a';
        break;
    }

    //Use double frequencies to obtain r from er
    for(int i = 0; i < TOP_SIZE; i++)
    {
        if(topFreq_2[i][1] != tIndex + 'a' && topFreq_2[i][0] == eIndex + 'a' )
        {
            //Then r is the second character
            inverseKey[topFreq_2[i][1] - 'a'] = 'r';
        }
    }

    //Use triple frequencies to obtain i and g from ing
    for(int i = 0; i < TOP_SIZE; i++)
    {
        if(topFreq_3[i][1] == nIndex + 'a')
        {
            if(topFreq_3[i][0] == eIndex + 'a' || topFreq_3[i][0] == aIndex + 'a') break;
            if(topFreq_3[i][2] == dIndex + 'a' || topFreq_3[i][2] == tIndex + 'a') break;
            //Then i is the first character and g is the third character.
            inverseKey[topFreq_3[i][0] - 'a'] = 'i';
            inverseKey[topFreq_3[i][2] - 'a'] = 'g';
        }
    }

    //cout << inverseKey << endl;

    //if(inverseKey.length() < 26) return "Encryption ERROR: small key length";
    for(int i = 0; i < crypto.length(); i++)
    {
        int charIndex = tolower(crypto[i]) - 'a';
        crypto[i] = inverseKey[charIndex];
    }
    return crypto;
}

float SubstitutionCipher::getHitRatio (string plain, string encrypted)
{
    float hits = 0;
    for (int i = 0; i<encrypted.length(); i++){
        if (tolower(plain[i]) == encrypted[i]) hits++;
    }
    cout << "Hit ratio: " << hits * 100 / encrypted.length() << "%";
    return hits;
}
