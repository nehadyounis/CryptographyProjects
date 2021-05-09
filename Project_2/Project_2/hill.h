#ifndef HILL_H_INCLUDED
#define HILL_H_INCLUDED

#include <iostream>
#include <string>
#include <ctype.h>
#include "Matrix.h"
#include "modulo.h"

using namespace std;

class hillCipher
{
private:
public:
    string encrypt(string plain, string key);
    string decrypt(string crypt, string key);
};

#endif // HILL_H_INCLUDED
