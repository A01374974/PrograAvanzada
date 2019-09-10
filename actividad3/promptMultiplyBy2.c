#include <stdio.h>
int promptMultiplyBy2(int n){
    return n * 2;
}
void main(){
    int n;
    scanf("%d",&n);
    printf("%d times 2 = %d",n,promptMultiplyBy2(n));
}