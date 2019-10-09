#include <stdio.h>

int priceIsRight(int *lista,int size,int price){
    int flag=-1;
    int n=0;
    while(n<size){
        if(lista[n]<=price){
            if(flag==-1 || (price-flag)>(price-lista[n])){
                flag = lista[n];
            }
        }
        n++;
    }
    return flag;
}

void main(){
    int price,size;
    scanf("%d\n%d",&price,&size);
    int h[size];
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    printf("%d",priceIsRight(h,size,price));
}