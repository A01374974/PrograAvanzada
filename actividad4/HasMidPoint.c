#include <stdio.h>
int hasMidpoint(int a,int b,int c){
    if(a==b || a==c || b==c){
        return 0;
    }
    int mayor;
    int menor;
    if(b<a && a>c){
        mayor=a;
    }else if (a<b && b>c){
        mayor=b;
    }else{
        mayor=c;
    }
    if(b>a && a<c){
        menor=a;
    }else if (a>b && b<c){
        menor=b;
    }else{
        menor=c;
    }
    if((mayor-menor)%2!=0){
        return 0;
    }
    int dist_medio=(mayor-menor)/2;
    int medio = menor+dist_medio;
    if(a==medio || b==medio || c==medio){
        return 1;
    }
    
}
void main(){
    int a,b,c;
    scanf("%d\n%d\n%d",&a,&b,&c);
    int res=hasMidpoint(a,b,c);
    if (res==1){
        printf("true");
    }else{
        printf("false");
    }
    
}