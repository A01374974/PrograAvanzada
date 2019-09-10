#include <stdio.h>
void Seasons(int month, int day){
    if(month==1 || month==2 || month ==3){
        if(month==3){
            if(day<=15){printf("Winter");}else if(day>15){printf("Spring");}
        }else{printf("Winter");}
    }else if(month==4 || month==5 || month ==6){
        if(month==6){
            if(day<=15){printf("Spring");}else if(day>15){printf("Summer");}
        }else{printf("Spring");}
    }else if(month==7 || month==8 || month==9){
        if(month==9){
            if(day<=15){printf("Summer");}else if(day>15){printf("Fall");}
        }else{printf("Summer");}
    }else if(month==10 || month==11 || month==12){
        if(month==12){
            if(day<=15){printf("Fall");}else if(day>15){printf("Winter");}
        }else{printf("Fall");}
    }
}
void main(){
    int m,d;
    scanf("%d",&m);
    scanf("%d",&d);
    Seasons(m,d);
}