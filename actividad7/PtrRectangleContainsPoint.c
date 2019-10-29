#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int x,y,width,height;
}Rectangulo;

typedef struct{
    int x,y;
}Point2D;

int RectangleContainsPoint(const Rectangulo* const rec,const Point2D* const point){
    int xMax,yMax;
    xMax = rec -> x + rec -> width;
    yMax = rec -> y + rec -> height;
    if((point -> x <= xMax && point ->x >= rec ->x) && (point -> y <= yMax && point -> y >= rec -> y)){
        return 1;
    }else{
        return 0;
    }
}
void main(){
    int x,y,width,height,px,py;
    scanf("%d\n%d\n%d\n%d\n%d\n%d",&x,&y,&width,&height,&px,&py);
    Rectangulo *r = malloc(sizeof(Rectangulo));
    Point2D *p = malloc(sizeof(Point2D));
    r ->x = x;
    r ->y = y;
    r ->width = width;
    r ->height = height;
    p ->x = px;
    p ->y = py;
    printf("%d",RectangleContainsPoint(r,p));
    free(r);
    free(p);

}

