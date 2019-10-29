#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
}Point2D;

int Quadrant(const Point2D* const point){
    if(point ->x > 0 && point ->y > 0){
        return 1;
    }else if (point ->x < 0 && point ->y > 0){
        return 2;
    }else if (point -> x < 0 && point ->y < 0){
        return 3;
    }else if(point ->x > 0 && point ->y < 0){
        return 4;
    }else{
        return 0;
    }
}

void main(){
    float x1,y1;
    scanf("%f\n%f",&x1,&y1);
    Point2D *p = malloc(sizeof(Point2D));
    p -> x = x1;
    p -> y = y1;
    printf("%d",Quadrant(p));
    free(p);
}

