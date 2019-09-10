#include <stdio.h>

int main(){
    int rows;
    scanf("%d",&rows);
    int slashes=0;
    int cols = (rows*4)-2;
    for(int i=0;i<rows;i++){
        for(int a=0;a<slashes;a++){
            printf("%c",92);
        }
        for(int b=0;b<cols;b++){
            printf("!");
        }
        for(int c=0;c<slashes;c++){
            printf("/");
        }
        slashes=slashes+2;
        cols=cols-4;
        printf("\n");
    }
}
