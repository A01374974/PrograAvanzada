#include <stdio.h>
void printOX(int n){
    int mid;
    int bot;
    if(n%2==0){
        mid=n/2;
        bot=mid;
    }else{
        mid=(n+1)/2;
        bot=n-mid;
    }
    int ohs = 0;
    int ohsMid = n - 2;
    for(int line=1;line<=mid;line++){
        for(int o=0;o<ohs;o++){
            printf("o");
        }printf("x");
        for(int o=0;o<ohsMid;o++){
            printf("o");
        }
        if(n%2!=0 && line == mid){
            printf("");
        }else{
            printf("x");
        }
        for(int o=0;o<ohs;o++){
            printf("o");
        }
        if(line!=mid){
            ohs++;
            ohsMid=ohsMid-2;
            printf("\n");   
        }else{
        printf("\n");
        }
    }
    int ohsB = ohs;
    int ohsMidB = ohsMid;
    if(n%2!=0){
        ohsB--;
        ohsMidB=ohsMidB+2;
    }
    for(int line=1;line<=bot;line++){
        for(int o=0;o<ohsB;o++){
            printf("o");
        }printf("x");
        for(int o=0;o<ohsMidB;o++){
            printf("o");
        }
        printf("x");
        for(int o=0;o<ohsB;o++){
            printf("o");
        }
        ohsB--;
        ohsMidB=ohsMidB+2;
        printf("\n");
    }
}
void main(){
    int n;
    scanf("%d",&n);
    printOX(n);
}