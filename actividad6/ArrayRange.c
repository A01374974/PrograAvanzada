#include <stdio.h>
int computeMax(int *lista,int size){
    int max = lista[0];
    for(int i=0;i<size;i++){
        if(lista[i]>=max){
            max=lista[i];
        }
    }
    return max;
}
int computeMin(int *lista,int size){
    int min = lista[0];
    for(int i=0;i<size;i++){
        if(lista[i]<=min){
            min=lista[i];
        }
    }
    return min;
}

void main(){
    int size,min,max;
    scanf("%d",&size);
    int h[size];    
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    min=computeMin(h,size);
    max=computeMax(h,size);
    printf("%d",max-min+1);
}