#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b) {   
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
    if (a == b) 
        return a; 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 

typedef struct{
    int numerator;
    int denominator;
}Fraction;

Fraction* SimplifyFraction(const Fraction* const frac){
    int nume = frac -> numerator;
    int denom = frac->denominator;
    int maximoComunDivisor = gcd(nume, denom);
    Fraction *f = malloc(sizeof(Fraction));
    f -> numerator = nume / maximoComunDivisor;
    f -> denominator = denom / maximoComunDivisor;
    return f;
}

void main(){
    int nume,denom;
    scanf("%d\n%d",&nume,&denom);
    Fraction *f = malloc(sizeof(Fraction));
    f -> numerator = nume;
    f -> denominator = denom;
    Fraction *newf = SimplifyFraction(f);
    free(f);
    printf("%d\n%d\n", newf -> numerator, newf -> denominator);
    free(newf);
}