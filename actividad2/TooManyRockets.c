#include <stdio.h>

void main(){
    int numRcokets;
    scanf("%d",&numRcokets);
    char rocket[16][9]= {"   /\\   ","  /  \\  "," /    \\ ","+------+","|      |",
    "|      |","+------+","| Viva |","|Mexico|","+------+","|      |","|      |",
    "+------+","   /\\   ","  /  \\  "," /    \\ "};
    for(int i=0;i<16;i++){
        for(int j=0;j<numRcokets;j++){
            printf(rocket[i]);
            printf(" ");
        }printf("\n");
    }
}