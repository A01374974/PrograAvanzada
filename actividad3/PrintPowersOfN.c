#include <stdio.h>
#include <math.h> 

void PrintPowersOfN(int base,int n){
    for(int i=0;i <= n; i++ ){
        double p = pow(base,i);
        printf("%.0lf ",p);
    }
}
void main(){
    int base,n;
    scanf("%d\n%d",&base ,&n);
    PrintPowersOfN(base,n);
}