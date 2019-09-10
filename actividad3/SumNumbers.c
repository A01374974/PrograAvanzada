#include <stdio.h>
int SumNumbers(int l,int h){
    int acum=0;
    for(int i=l; i<=h;i++){
        acum = acum + i;
    }
    return acum;
}
void main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    int l,h;
    if (a<=b){
        l=a;
        h=b;
    }else{
        l=b;
        h=a;
    }
    printf("low? high? sum = %d",SumNumbers(a,b));
}