#include <stdio.h>

void main(){
    int guiones = 5;
    int numbers = 1;
    int num = 1;
    for(int i=0;i<5;i++){
        for(int g = 0; g<guiones;g++){
            printf("-");
        }
        for(int n = 0; n<numbers;n++){
            printf("%d",num);
        }
        for(int g = 0; g<guiones;g++){
            printf("-");
        }printf("\n");
        guiones--;
        numbers=numbers+2;
        num=num+2;
    }
}