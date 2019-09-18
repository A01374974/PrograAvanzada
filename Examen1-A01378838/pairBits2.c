#include "stdio.h"
#include "stdarg.h"
#include "math.h"


unsigned int pairBits(unsigned int totalVariables, ...){
    if(totalVariables> 16){
        totalVariables= 16;
    }
    unsigned int valorActual = 0;
    unsigned int resultado = 0;
	va_list valores;

    va_start(valores, totalVariables);
    int iteracion=0;
    int posicion = 0;
    int movimientos = 0;
    while(iteracion < totalVariables) {
        valorActual = va_arg(valores, int);
        if(posicion == 2){
            valorActual >>= 4;
            valorActual &= 3;
        } else if(posicion == 1){
            valorActual >>= 2;
            valorActual &= 3;
        } else if(posicion == 0){
            valorActual &= 3;
        } else {
            valorActual >>= 6;
            valorActual &= 3;
            posicion = -1;
        }
        valorActual <<= movimientos;
        resultado |= valorActual;
        iteracion++;
        posicion++;
        movimientos=movimientos+2;
    }
    va_end(valores);

    return resultado;
}
int test_pairBits_0_parametros()
{
    return pairBits(0) == 0;
}

int test_pairBits_3_parametros()
{
    return pairBits(3, 3, 8, 16) == 27;
}
int test_pairBits_8_parametros(){
    return pairBits(8, 2, 8, 32, 128,512,2048,8192,32768)==43690;
}
int test_pairBits_18_parametros()
{
    return pairBits(18,65535, 65535, 65535, 65535, 65535,
                     65535, 65535, 65535, 65535, 65535,
                     65535, 65535, 65535, 65535, 65535,
                     65535, 0, 0) == 0xFFFFFFFF;
}

void main()
{
    printf("Test 0 parámetros: %d\n", test_pairBits_0_parametros());
    printf("Test 3 parámetros: %d\n", test_pairBits_3_parametros());
    printf("Test 8 parámetros : %d\n",test_pairBits_8_parametros());
    printf("Test 18 parámetros: %d\n", test_pairBits_18_parametros());
}