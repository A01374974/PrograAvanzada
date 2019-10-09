#include <stdio.h>
int countInRange(int min,int max,int *lista, int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(lista[i]>=min && max>=lista[i]){
            count++;
        }
    }return count;
}
void main(){
    int size,min,max;
    scanf("%d\n%d\n%d",&min,&max,&size);
    int h[size];    
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    printf("%d",countInRange(min,max,h,size));
}