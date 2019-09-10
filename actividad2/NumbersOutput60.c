#include <stdio.h>

void main(){
    for(int i=0;i<6;i++){
        for(int j=1;j<10;j++){
            if(j==9) {
                printf("|");
            }else{
                printf(" ");
            }
        }printf(" ");
    }printf("\n");
    for(int i=0;i<6;i++){
        for(int j=1;j<10;j++){
            printf("%d",j);
        }printf("0");
    }
}