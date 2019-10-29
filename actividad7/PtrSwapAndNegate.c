#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Point2D;

Point2D* SwapAndNegate(const Point2D* const point){
    int x,y,tempX;
    x = point ->x;
    y = point ->y;
    tempX = x;
    x = y * -1;
    y = tempX * -1;
    Point2D *res = malloc(sizeof(Point2D));
    res ->x = x;
    res ->y = y;
    return res;
} 
void main(){
    int x1,y1;
    scanf("%d\n%d",&x1,&y1);
    Point2D *p = malloc(sizeof(Point2D));
    p ->x = x1;
    p ->y = y1;
    Point2D *res = SwapAndNegate(p);
    free(p);
    printf("%d\n%d",res ->x,res ->y);
    free(res);
}