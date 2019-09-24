#include <stdio.h>
int palindrome(int x) {
    int copyX = x , reverse = 0;
    while (copyX > 0) {
        reverse <<=1;
        reverse |= (copyX & 1);
        copyX = copyX >> 1;
    }
    if(reverse==x){
        return 1;
    }else{
        return 0;
    }
}
void main(){
    int number;
    scanf("%d", &number);
    printf("%d",palindrome(number));
}
