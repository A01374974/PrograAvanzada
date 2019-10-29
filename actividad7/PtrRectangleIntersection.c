#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y,width,height;
}Rectangulo;

Rectangulo* sumRec(const Rectangulo* const rec1,const Rectangulo* const rec2){
    int x,y,width,height;
    int xMax1,xMax2,yMax1,yMax2;

    if(rec1->x >= rec2->x){
        x = rec1->x;
    }else{
        x = rec2 ->x;
    }
    if(rec1->y >= rec2->y){
        y= rec1->y;
    }else{
        y= rec2->y;
    }
    xMax1 = rec1->x + rec1->width;
    xMax2 = rec2->x + rec2->width;
    yMax1 = rec1->y + rec1->height;
    yMax2 = rec2->y + rec2->height;
    if(xMax1<=xMax2){
        width = xMax1 - rec2->x;
    }else{
        width = xMax2 - rec1->x;
    }
    if(yMax1<=yMax2){
        height = yMax1 - rec2->y;
    }else{
        height = yMax2 - rec1->y;
    }
    Rectangulo *res = malloc(sizeof(Rectangulo));
    res -> x = x;
    res -> y = y;
    res -> width = width;
    res -> height = height;
    return res;
}

void main(){
    int x1,y1,width1,height1;
    int x2,y2,width2,height2;
    scanf("%d\n%d\n%d\n%d",&x1,&y1,&width1,&height1);
    scanf("%d\n%d\n%d\n%d",&x2,&y2,&width2,&height2);
    Rectangulo *r1 = malloc(sizeof(Rectangulo));
    Rectangulo *r2 = malloc(sizeof(Rectangulo));
    r1 ->x = x1;
    r1 ->y = y1;
    r1 ->width = width1;
    r1 ->height = height1;
    r2 ->x = x2;
    r2 ->y = y2;
    r2 ->width = width2;
    r2 ->height = height2;
    Rectangulo *res = sumRec(r1,r2);
    free(r1);
    free(r2);
    printf("%d\n%d\n%d\n%d",res->x,res->y,res->width,res->height);
    free(res);
}