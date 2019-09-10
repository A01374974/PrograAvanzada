#include <stdio.h>

void PrintSquare(int min,int max){
    int left = min;
    for (int i=min;i<=max;i++){
        for(int l=left;l<=max;l++){
            printf("%d",l);
        }
        for(int r=min;r<left;r++){
            printf("%d",r);
        }printf("\n");
        left=left+1;
    }
}
void main(){
    int a,b;
    scanf("%d\n%d",&a,&b);
    int l,h;
    l=(a<=b? a : b);
    h=(b<=a? a : b);
    PrintSquare(l,h);
}