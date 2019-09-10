#include <stdio.h>

void main(){
    int ast=14;
    int money=7;
    int astExt=0;
    for(int i=0;i<7;i++){
        for(int a1=0;a1<astExt;a1++){
            printf("*");
        }
        for(int a=0;a<money;a++){
            printf("$");
        }
        for(int b=0;b<ast;b++){
            printf("*");
        }
        for(int c=0;c<money;c++){
            printf("$");
        }
        for(int c1=0;c1<astExt;c1++){
            printf("*");
        }
        printf("\n");
        ast=ast-2;
        astExt=astExt+2;
        money=money-1;
    }
}