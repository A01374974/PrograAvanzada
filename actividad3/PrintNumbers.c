#include <stdio.h>
void PrintNumbers(int max){
    for(int i=1; i<=max;i++){
        printf("[%d] ",i);
    }
}

void main(){
    int max;
    scanf("%d",&max);
    PrintNumbers(max);
}