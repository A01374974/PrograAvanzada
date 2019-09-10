#include <stdio.h>
#include <string.h>

int ZeroDigits(char *number){
    int zeros=0;
    for(int index=0;index<strlen(number);index++){
        if(number[index]=='0'){
            zeros++;
        }
    }
    return zeros;
}

void main(){
    char n[256];
    scanf("%[^\n]", &n); 
    printf("%d",ZeroDigits(n));
}