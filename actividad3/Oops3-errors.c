#include "stdio.h"
void printer(double x, double y,double b) {
    
    int z = 5;
    printf("x = %.2lf and y = %.1lf\n",x,y);
    printf("x = %.2lf and y = %.4lf\n",x,b);
    printf("The value from main is: %.4lf\n",b);
    printf("z = %d\n",z);
}
void main() {

    double bubble = 867.5309;
    double x = 10.01;
    double y = 8.0;
    printer(x,y,bubble);
}
