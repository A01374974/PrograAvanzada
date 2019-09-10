#include <stdio.h>
int CountFactors(int n){
    int factors = 0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            factors++;
        }
    }
    return factors;
}
void main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",CountFactors(n));
}