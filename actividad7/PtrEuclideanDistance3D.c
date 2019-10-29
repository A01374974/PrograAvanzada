#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point3D{
    float x;
    float y;
    float z;
}Point3D;

double EucDist(const Point3D* const point1,const Point3D* const point2){
    double sumX = pow(point1 ->x - point2 ->x,2);
    double sumY = pow(point1 ->y - point2 ->y,2);
    double sumZ = pow(point1 ->z - point2 ->z,2);
    double res = sqrt(sumX +  sumY + sumZ);
    return res;
}

void main(){
    float x1,x2,y1,y2,z1,z2;
    scanf("%f\n%f\n%f\n%f\n%f\n%f",&x1,&y1,&z1,&x2,&y2,&z2);
    Point3D *p1 = malloc(sizeof(Point3D));
    Point3D *p2 = malloc(sizeof(Point3D));
    p1 ->x = x1;
    p1 ->y = y1;
    p1 ->z = z1;
    p2 ->x = x2;
    p2 ->y = y2;
    p2 ->z = z2;
    printf("%.2f",EucDist(p1,p2));
    free(p1);
    free(p2);
}