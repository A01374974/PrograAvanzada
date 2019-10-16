#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int numerator;
    int denominator;
}Fraction;

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
Fraction* SimplifyFraction(const Fraction* const frac){
    int nume = frac -> numerator;
    int denom = frac->denominator;
    int maximoComunDivisor = gcd(nume, denom);
    Fraction *f = malloc(sizeof(Fraction));
    f -> numerator = nume / maximoComunDivisor;
    f -> denominator = denom / maximoComunDivisor;
    return f;
}

Fraction* SumFraction(const Fraction* const frac1, const Fraction* const frac2){
    int a = frac1 -> numerator;
    int b = frac1 -> denominator;
    int c = frac2 -> numerator;
    int d = frac2 -> denominator;
    Fraction *fRes = malloc(sizeof(Fraction));
    fRes -> numerator = (a*d)+(b*c);
    fRes -> denominator = b*d;
    Fraction *fRes_simp = SimplifyFraction(fRes);
    free(fRes);
    return fRes_simp;
}

void main(){
    int nume1,denom1,nume2,denom2;
    scanf("%d\n%d\n%d\n%d",&nume1,&denom1,&nume2,&denom2);
    Fraction *f1 = malloc(sizeof(Fraction));
    Fraction *f2 = malloc(sizeof(Fraction));
    f1 -> numerator = nume1;
    f1 -> denominator = denom1;
    f2 -> numerator = nume2;
    f2 -> denominator = denom2;
    Fraction *fRes = SumFraction(f1,f2);
    free(f1);
    free(f2);
    printf("%d\n%d\n",fRes -> numerator, fRes -> denominator);
    free(fRes);
}