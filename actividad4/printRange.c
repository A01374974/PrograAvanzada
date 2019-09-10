#include <stdio.h>
void printRange(int a,int b){
    if(a<=b){
        for(int i=a;i<=b;i++){
            printf("%d ",i);
        }
    }else{
        for(int i=a;i>=b;i--){
            printf("%d ",i);
        }
    }
}
void main(){
    int a,b;
    scanf("%d\n%d",&a,&b);
    printRange(a,b);
}