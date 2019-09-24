#include <stdio.h>
int countOnes(int n){
    int ones=0;
    while(n!=0){
        n &= (n -1);
        ones ++;
    }
    return ones;
}

void main(){
    int number;
    scanf("%d",&number);
    printf("%d",countOnes(number));
}