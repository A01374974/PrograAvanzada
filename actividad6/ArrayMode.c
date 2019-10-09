#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool exists(int item, int *lista){
    int size = sizeof(lista)/sizeof(int);
    for(int i=0; i<size;i++){
        if (item==lista[i]) return true;
    }
    return false;
}
int computeMode(int *lista,int size){
    int nonRep[size];
    int lastIdex = -1;
    for(int i=0;i<size;i++){
        if(!exists(lista[i],nonRep)){
            lastIdex++;
            nonRep[lastIdex]=lista[i];
        }
    }
    int countNonRep[lastIdex];
    for(int i=0;i<=lastIdex;i++){
        int count=0;
        for(int j=0;j<size;j++){
            if(nonRep[i]==lista[j]){
                count++;
            }
        }countNonRep[i]=count;
    }
    int max = countNonRep[0];
    for(int i=0;i<=lastIdex;i++){
        if(countNonRep[i]>=max){
            max=countNonRep[i];
        }
    }
    int indexMode=0;
    for(int i=0;i<=lastIdex;i++){
        if(max==countNonRep[i]){
            indexMode=i;
            break;
        }
    }
    return nonRep[indexMode];
}
void main(){
    int size;
    scanf("%d",&size);
    unsigned int h[size];    
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    printf("%d",computeMode(h,size));    
}