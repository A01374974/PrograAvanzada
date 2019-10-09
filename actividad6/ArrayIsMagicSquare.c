#include <stdio.h>

void isMagicSquare(int *lista, int size, int dimen){
    int lineSumVal=0;
    int horiSum=0;
    for(int i=0;i<dimen;i++){
        lineSumVal+=lista[i];
    }
    for(int i=0;i<size;i++){
        horiSum+=lista[i];
    }
    if(horiSum % lineSumVal == 0){
        printf("true");
    }else{
        printf("false");
    }

}
void main(){
    int dim,size;
    scanf("%d",&dim);
    size=dim*dim;
    int h[size];
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    isMagicSquare(h,size,dim);
}
