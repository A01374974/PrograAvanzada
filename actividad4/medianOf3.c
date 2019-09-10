#include <stdio.h>

int medianOf3(int a,int b,int c);

void main(){
    int a,b,c;
    scanf("%d\n%d\n%d",&a,&b,&c);
    printf("%d\n",medianOf3(a,b,c));
}

int medianOf3(int a,int b,int c){
    if((b<=a && a<=c) || (c<=a && a<=b)){
        return a;
    }else if((a<=b && b<=c) || (c<=b && b<=a)){
        return b;
    }else if((b<=c && c<=a) || (a<=c && c<=b)){
        return c;
    }
}