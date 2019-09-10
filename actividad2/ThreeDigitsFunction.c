#include <stdio.h>
int TDF(int n){
    return n%1000;
}
int main(void){
    int number;
    scanf("%d",&number);
    printf("%d", TDF(number));
}
