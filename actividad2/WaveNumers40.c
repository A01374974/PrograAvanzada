#include <stdio.h>

void main(){
    for(int i=0; i<40;i++){
        printf("%c",45);
    }printf("\n");
    for (int i=0;i<10;i++){
        printf("%c%c%c%c",95,45,94,45);
    }printf("\n");
    for(int i=0;i<2;i++){
        for(int j=1;j<10;j++){
            printf("%d%d",j,j);
        }printf("%d%d",0,0);
    }printf("\n");
    for(int i=0; i<40;i++){
        printf("%c",45);
    }printf("\n");
}