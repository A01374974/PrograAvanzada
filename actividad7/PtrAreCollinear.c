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
int AreCollinear(const Point2D* const point1,const Point2D* const point2,const Point2D* const point3){
    int m1,m2,m3;
    m1 = Slope(point1,point2);
    m2 = Slope(point2,point3);
    m3 = Slope(point1,point3);
    if (m1==m2 && m2==m3){
        return 1;
    }else{
        return 0;
    }
    
}
void main(){
    int x1,y1,x2,y2,x3,y3;
    scanf("%d\n%d\n%d\n%d\n%d\n%d",&x1,&y1,&x2,&y2,&x3,&y3);
    Point2D *p1 = malloc(sizeof(Point2D));
    Point2D *p2 = malloc(sizeof(Point2D));
    Point2D *p3 = malloc(sizeof(Point2D));
    p1 ->x = x1;
    p1 ->y = y1;
    p2 ->x = x2;
    p2 ->y = y2;
    p3 ->x = x3;
    p3 ->y = y3;
    printf("%d",AreCollinear(p1,p2,p3));
    free(p1);
    free(p2);
    free(p3);
    
}