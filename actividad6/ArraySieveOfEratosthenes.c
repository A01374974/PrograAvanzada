#include <stdio.h>
#include <stdbool.h>
bool esPrimo(int num1){
    int a=0;
    for(int i=1;i<=num1;i++){
        if(num1%i==0)
        a++;
    }
    if(a==2){
        return true;
    }
    else{
        return false;
    }
}
void primos(int val){
    int lista[val];
    for(int i=0; i<=val;i++){
        if(esPrimo(i)){
            lista[i]=1;
        }else{
            lista[i]=0;
        }
    }
    for(int i=2;i<=val;i++){
        if(lista[i]==1) printf("%d\n",i);
    }
}
void main(){
    int val;
    scanf("%d",&val);
    primos(val);
}