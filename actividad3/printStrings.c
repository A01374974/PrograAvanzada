#include <stdio.h>

void printStrings(char *word, int rep){
    for(int i=0; i<rep;i++){
        printf("%s",word);
    }
}

void main(){
    char word[256];
    int rep;
    scanf("%d\n",&rep);
    scanf("%[^\n]",&word);
    printStrings(word,rep);
}