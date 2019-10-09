#include <stdio.h>
void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) { 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++){ 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
            min_idx = j;   
        swap(&arr[min_idx], &arr[i]); 
    }
}
float computeMedian(int *lista,int size){
    selectionSort(lista,size);
    int indexMid;
    float median=0.0;
    if((size % 2)==0){
        indexMid=(size/2)-1;
        median=0.5;
    }else{
        indexMid=(size/2);
    }
    median+=lista[indexMid];
    return median;
}
void main(){
    int size;
    scanf("%d",&size);
    int h[size];    
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    printf("%.1f",computeMedian(h,size));
}