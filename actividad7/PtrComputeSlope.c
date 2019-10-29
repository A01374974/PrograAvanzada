#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y;
}Point2D;

double Slope(const Point2D* const point1,const Point2D* const point2){
    double yRES = point2 ->y - point1 ->y;
    double xRES = point2 ->x - point1 ->x;
    return yRES/xRES;
}

void main(){
    int x1,y1,x2,y2;
    scanf("%d\n%d\n%d\n%d",&x1,&y1,&x2,&y2);
    Point2D *p1 = malloc(sizeof(Point2D));
    Point2D *p2 = malloc(sizeof(Point2D));
    p1 ->x = x1;
    p1 ->y = y1;
    p2 ->x = x2;
    p2 ->y = y2;
    printf("%.1f",Slope(p1,p2));
    free(p1);
    free(p2);
}