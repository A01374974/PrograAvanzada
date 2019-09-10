#include <stdio.h>

void PrintGrid(int rows, int cols){
    int init = 1;
    for(int row=1;row<=rows; row++){
        int sum = init;
        for(int i=1;i<=cols;i++){
            if(i==cols){
                printf("%d",sum);
            }else{
                printf("%d, ",sum);
            }
            sum=sum+rows;
        }
        printf("\n");
        init=init+1;
    }
}

void main(){
    int a,b;
    scanf("%d\n%d",&a,&b);
    PrintGrid(a,b);
}