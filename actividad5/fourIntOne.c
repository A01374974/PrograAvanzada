#include <stdio.h>

int fourIntOne(unsigned a,unsigned b,unsigned c,unsigned d){
    unsigned step1,step2,res;
    step1 = a | (b<<8);
    step2 = step1 | (c<<16);
    res = step2 | (d<<24);
    return res;
}

void main(){
    unsigned a,b,c,d;
    scanf("%u\n%u\n%u\n%u",&a,&b,&c,&d);
    printf("%u",fourIntOne(a,b,c,d));
}