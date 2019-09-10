#include <stdio.h>
int gcd(int x,int y){
    int temp, gcd;
    while (y != 0){
      temp = y;
      y = x % y;
      x = temp;
    }
    gcd = x;
    return gcd;
}

int gcd1all(int n){
    if(n>1000000 || n<=0){
        return 0;
    }
    int gcds1 = 0;
    for(int i=1;i<=n;i++){
        if(gcd(n,i)==1){
            gcds1++;
        }
    }
    return gcds1;
}

void main(){
    int n;
    scanf("%d",&n);
    printf("%d",gcd1all(n));
}