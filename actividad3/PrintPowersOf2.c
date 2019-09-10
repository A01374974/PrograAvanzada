#include <stdio.h>
#include <math.h> 

void PrintPowersOf2(int n){
    for(int i=0;i <= n; i++ ){
        double p = pow(2,i);
        printf("%.0lf ",p);
    }
}
void main(){
    int n;
    scanf("%d", &n);
    PrintPowersOf2(n);
}