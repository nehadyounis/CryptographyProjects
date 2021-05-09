#include "modulo.h"

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if ((mod(a,m)) * (x%m) % m == 1)
            return x;
}
