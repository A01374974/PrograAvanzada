#include <stdio.h>
int computeMin(int *lista,int size){
    int min = lista[0];
    for(int i=0;i<size;i++){
        if(lista[i]<=min){
            min=lista[i];
        }
    }
    return min;
}
int main(void){
    int size;
    scanf("%d",&size);
    int h[size];    
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    printf("%d",computeMin(h,size));
}