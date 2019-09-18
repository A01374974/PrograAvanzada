#include <stdio.h>
void hopscotch(int n){
    int top = 1;
    int maxNumbers = (3*n)+top;
    while(top<=maxNumbers){
        if(top % 3 == 1){
            printf("   %d\n", top);
        }
        else if( top % 3 == 0){
            printf("     %d\n", top);
        }
        else{
            printf("%d", top);
        }
        top++;
    }
}

void main(void){
    int n;
    scanf("%d",&n);
    hopscotch(n);
}