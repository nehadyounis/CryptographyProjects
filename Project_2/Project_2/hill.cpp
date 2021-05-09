#include "hill.h"

string hillCipher::encrypt(string plain, string key)
{
    //Generate matrix from the given key.
    Matrix keyM(3, 3);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            keyM.set(i, j, (key[3*i + j] - 'a')%26);

    //Test if the key is invertible.
    cout << "mod test: " << mod(keyM.determinant(),26) << endl;
    if(! (mod(keyM.determinant(),26)) )
    {
        cout << "ERROR: Key is not invertible, aborting encryption (returning a 0 string)..." << endl;
        return "\0";
    }

    string encrypt;

    //Loop through the plain text and encrypt each 3 characters.
    for(int i = 0; i < plain.length(); i+=3)
    {
        Matrix result(1, 3), letters(1, 3);

        //Modulo to wrap around the last letters in case the number of letters is not a multiple of 3.
        letters.set(0, 0, plain[(i)%plain.length()] - 'a');
        letters.set(0, 1, plain[(i+1)%plain.length()] - 'a');
        letters.set(0, 2, plain[(i+2)%plain.length()] - 'a');

        result = letters*keyM;
        result = result%26;

        //Add the result to the encrypt string.
        encrypt += toupper(result.get(0, 0) + 'a');
        encrypt += toupper(result.get(0, 1) + 'a');
        encrypt += toupper(result.get(0, 2) + 'a');
    }
    return encrypt;
}

string hillCipher::decrypt(string crypt, string key)
{
    //Generate matrix from the given key.
    Matrix keyM(3, 3);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            keyM.set(i, j, (key[3*i + j] - 'a')%26);

    //Test if the key is invertible.
    if(! (mod(keyM.determinant(),26)) )
    {
        cout << "ERROR: Key is not invertible, aborting decryption (returning a 0 string)..." << endl;
        return "\0";
    }

    //Obtain inverse of the matrix
    int b = modInverse(int(keyM.determinant()), 26);
    keyM = (keyM.adjoint()*b)%26;

    //Decrypt using the inverse key matrix
    string decrypt;

    //Loop through the crypted text and decrypt each 3 characters.
    for(int i = 0; i < crypt.length(); i+=3)
    {
        Matrix result(1, 3), letters(1, 3);

        //Modulo to wrap around the last letters in case the number of letters is not a multiple of 3.
        letters.set(0, 0, crypt[(i)%crypt.length()] - 'a');
        letters.set(0, 1, crypt[(i+1)%crypt.length()] - 'a');
        letters.set(0, 2, crypt[(i+2)%crypt.length()] - 'a');

        result = letters*keyM;
        result = result%26;

        //Add the result to the decrypt string.
        decrypt += tolower(result.get(0, 0) + 'a');
        decrypt += tolower(result.get(0, 1) + 'a');
        decrypt += tolower(result.get(0, 2) + 'a');
    }
    return decrypt;
}
