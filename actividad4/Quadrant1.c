#include <stdio.h>

int quadrant(float x, float y){
    if(x==0 || y==0){
        return 0;
    }else if(x>0 && y>0){
        return 1;
    }else if(x<0 && y>0){
        return 2;
    }else if(x<0 && y<0){
        return 3;  
    }else if(x>0 && y<0){
        return 4;
    }
}
void main(){
    float x,y;
    scanf("%f\n%f",&x,&y);
    printf("%d",quadrant(x,y));
}