#include  <stdio.h>
#include <stdlib.h>

void main(){
    printf("#include %cstdio.h%c\n\n\n",34,34);
    printf("int main(void) {\n");
    printf("printf(%cHello World%cn%c);\n",34,92,34);
    printf("return 0;\n");
    printf("}");
}