#include <stdio.h>

void main(){
    int slashes=0;
    int adSign=22;
    for(int i=0;i<6;i++){
        for(int a=0;a<slashes;a++){
            printf("%c",92);
        }
        for(int b=0;b<adSign;b++){
            printf("!");
        }
        for(int c=0;c<slashes;c++){
            printf("/");
        }
        slashes=slashes+2;
        adSign=adSign-4;
        printf("\n");
    }
}