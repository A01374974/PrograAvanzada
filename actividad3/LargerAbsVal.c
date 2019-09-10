#include <stdio.h>
#include <stdlib.h>

int LargerAbsVal(int a,int b){
    int largerAbsVal=(abs(a)>=abs(b)? abs(a):abs(b));
    return largerAbsVal;
}
void main() {
    int a,b;
    scanf("%d\n%d",&a,&b);
    printf("%d",LargerAbsVal(a,b));
}