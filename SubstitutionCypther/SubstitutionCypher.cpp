

//#include "SubstitutionCypher.h"

#include <iostream>

using namespace std;

class SubstitutionCypher {
    const string alpha = "abcdefghijklmnopqrstuvwxyz";

    public:

    bool replace(string& str, const string& from, const std::string& to) {
        size_t start_pos = str.find(from);
        if(start_pos == string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        return true;
    }

    string encrypt(string plain, string key) {

    string crypto = "";
    crypto = plain;
    for (int i = 0; i <26; i++){
    bool x = replace(crypto, alpha[i], key[i]);
    if (!x) {crypto = "error parsing"; break;}
    }

    return crypto;

    }

    string decrypt(string crypto, string key) {

     string plain = "";



     return plain;
    }

};
