#include <stdio.h>
void PrintTriangleType(int a,int b,int c){
    if(a==b && b==c){
        printf("equilateral");
    }else if(a==b && a!=c){
        printf("isosceles");
    }else if(b==c && b!=a){
        printf("isosceles");
    }else if(c==a && c!=b){
        printf("isosceles");
    }else{
        printf("scalene");
    }
}
void main(){
    int a,b,c;
    scanf("%d\n%d\n%d",&a,&b,&c);
    PrintTriangleType(a,b,c);
}