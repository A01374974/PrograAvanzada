#include <stdio.h>

double ftoc(double *tf) {
    return (*tf - 32) * 5 / 9;
}

void main() {
    double tempf = 98.6;
    double tempc = ftoc(&tempf);
    printf("Body temp in C is: %.1lf\n",tempc);
}

