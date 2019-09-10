#include <stdio.h>

void PerfectNumbers(int n){
    printf("Perfect numbers up to %d: ",n);
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<i;j++){
            if(i%j==0){
                sum=sum+j;
            }
        }
        if(sum==i){
            printf("%d ",i);
        }
    }
}
void main(){
    int n;
    scanf("%d",&n);
    PerfectNumbers(n);
}