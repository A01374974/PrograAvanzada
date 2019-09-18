#include "stdio.h"
#include "stdarg.h"

unsigned int pairBits(int totalVariables, ...)
{
    if (totalVariables > 16) totalVariables = 16;
    va_list variables;
    unsigned int result = 0;
    unsigned short nextNum;

    va_start(variables, totalVariables);

    for (int iteration = 0, movements = 2, position = 0; iteration < totalVariables; iteration++)
    {
        nextNum = va_arg(variables, int);

        while (position < movements)
        {
            unsigned short nextBit = (nextNum >> position) & 1;
            result ^= nextBit << position;
            position++;
        }
        movements += 2;

        if (movements == 18)
        {
            movements = 2;
            position = 0;
            result <<= 16;
        }
    }

    va_end(variables);

    return result;
}

int test_pairBits_0_parametros()
{
    return pairBits(0) == 0;
}

int test_pairBits_3_parametros()
{
    return pairBits(3, 
                    3, 8, 16) == 27;
}

int test_pairBits_18_parametros()
{
    return pairBits(18,
                     65535, 65535, 65535, 65535, 65535,
                     65535, 65535, 65535, 65535, 65535,
                     65535, 65535, 65535, 65535, 65535,
                     65535, 0, 0) == 4294901760;
}
void main()
{
    printf("Test 0 parámetros: %d\n", test_pairBits_0_parametros());
    printf("Test 3 parámetros: %d\n", test_pairBits_3_parametros());
    printf("Test 18 parámetros: %d\n", test_pairBits_18_parametros());
}