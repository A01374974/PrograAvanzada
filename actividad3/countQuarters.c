#include <stdio.h>

int countQuarters(int q){
    return (q % 100) / 25;
}

void main(){
    int qrtrs;
    scanf("%d",&qrtrs);
    int qlf = countQuarters(qrtrs);
    printf("%d",qlf);
}