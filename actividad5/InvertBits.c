#include <stdio.h>
#include <math.h>

int invertBits(int x, int p, int n){
    int mascara,index = p, max_bits=p+n;
    while(index < max_bits){
        mascara=pow(2,index);
        x ^= mascara;
        index++;
    }
    return x;
}

void main(){
    int x,p,n;
    scanf("%d\n%d\n%d",&x,&p,&n);
    printf("%d",invertBits(x,p,n));
}