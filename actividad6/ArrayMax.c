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
int main(void){
    int size;
    scanf("%d",&size);
    int h[size];    
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    printf("%d",computeMax(h,size));
}