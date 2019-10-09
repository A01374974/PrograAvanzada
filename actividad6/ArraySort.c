#include <stdio.h>
void intercambio(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int lista[], int size) {
   for (int i = 0; i < size-1; i++)          
       for (int j = 0; j < size-i-1; j++)  
           if (lista[j] > lista[j+1]) 
              intercambio(&lista[j], &lista[j+1]); 
    for(int i=0;i<size;i++){
        printf("%d\n",lista[i]);
    }
} 
void main(){
    int size;
    scanf("%d",&size);
    int h[size];    
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    bubbleSort(h,size);
}