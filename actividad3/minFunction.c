#include <stdio.h>

int smallest(int a,int b,int c){
    int min = __INT_MAX__;
    min = (a<=b && a<=c ? a : min);
    min = (b<=a && b<=c ? b : min);
    min = (c<=a && c<=b ? c : min);
    return min;
}
void main(){
    int a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    int small=smallest(a,b,c);
    printf("%d", small);
}