#include <stdio.h>

void showTwos(int n){
    int lastN=n;
    int dos=0;
    while(lastN%2==0){
        lastN=lastN/2;
        dos++;
    }
    printf("%d = ",n);
    for(int i=0;i<dos;i++){
        printf("2 * ");
    }
    printf("%d", lastN);

}
void main(){
    int n;
    scanf("%d",&n);
    showTwos(n);
}