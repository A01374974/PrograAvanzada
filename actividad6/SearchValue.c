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

int searchValue(int lista[], int l, int r, int x) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (lista[mid] == x) 
            return mid; 
        if (lista[mid] > x) 
            return searchValue(lista, l, mid - 1, x); 
        return searchValue(lista, mid + 1, r, x); 
    }  
    return -1; 
}
void main(){
    int size,value;
    scanf("%d\n%d",&size,&value);
    int h[size];
    for(int i=0;i<size;i++){
        scanf("%d",&h[i]);
    }
    selectionSort(h,size);
    printf("%d",searchValue(h,0,size-1,value));
}