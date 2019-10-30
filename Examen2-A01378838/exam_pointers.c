#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "exam_pointers.h"

Minutia * createMinutia (unsigned short x, unsigned short y,float angle, MinutiaType type){
    Minutia *minu = malloc(sizeof(Minutia));
    minu -> x = x;
    minu -> y = y;
    minu -> angle = angle;
    minu -> type = type;
    return minu;
}
MinutiaArray * createMinutiaArray(unsigned short lenght){
    MinutiaArray *minuArr = malloc(sizeof(MinutiaArray));
    minuArr ->length = lenght;
    minuArr ->minutiae = calloc(lenght,sizeof(Minutia));
    return minuArr;
}

void releaseMinutiaArray (MinutiaArray *minArr){
    free(minArr ->minutiae);
    free(minArr);
}

double computeDistance(const Minutia *const minutia1,const Minutia *const minutia2){
    int xSum = pow((minutia2 ->x - minutia1 ->x),2);
    int ySum = pow((minutia2 ->y - minutia1 ->y),2);
    double distance = sqrt(xSum+ySum);
    return distance;
}

Minutia *findCentroid(const MinutiaArray *const minutiaArray,double (*distance)(const Minutia *const minutia1,const Minutia *const minutia2)){
    double minDist = __DBL_MAX__;
    int itemIndex = 0;
    for (int i = 0; i<minutiaArray->length;i++){
        double newDist = 0;
        for(int j = 0;j<minutiaArray->length;j++){
            newDist += distance(&minutiaArray->minutiae[i],&minutiaArray->minutiae[j]);
        }
        if (newDist < minDist){
            minDist=newDist;
            itemIndex = i;
        }
    }
    return &minutiaArray->minutiae[itemIndex];  
}

int testFindCentroid(){
    MinutiaArray *minutiaArray = createMinutiaArray(10);

    Minutia *minutia0 = createMinutia(20, 19, 10, Ending);
    minutiaArray->minutiae[0] = *minutia0;
    free(minutia0);

    Minutia *minutia1 = createMinutia(15, 9, 20, Bifurcation);
    minutiaArray->minutiae[1] = *minutia1;
    free(minutia1);

    Minutia *minutia2 = createMinutia(6, 24, 30, Bifurcation);
    minutiaArray->minutiae[2] = *minutia2;
    free(minutia2);

    Minutia *minutia3 = createMinutia(4, 7, 40, Unknown);
    minutiaArray->minutiae[3] = *minutia3;
    free(minutia3);

    Minutia *minutia4 = createMinutia(4, 5, 50, Unknown);
    minutiaArray->minutiae[4] = *minutia4;
    free(minutia4);

    Minutia *minutia5 = createMinutia(8, 9, 60, Ending);
    minutiaArray->minutiae[5] = *minutia5;
    free(minutia5);

    Minutia *minutia6 = createMinutia(5, 12, 70, Bifurcation);
    minutiaArray->minutiae[6] = *minutia6;
    free(minutia6);

    Minutia *minutia7 = createMinutia(7, 21, 80, Bifurcation);
    minutiaArray->minutiae[7] = *minutia7;
    free(minutia7);

    Minutia *minutia8 = createMinutia(13, 1, 90, Unknown);
    minutiaArray->minutiae[8] = *minutia8;
    free(minutia8);

    Minutia *minutia9 = createMinutia(2, 10, 100, Unknown);
    minutiaArray->minutiae[9] = *minutia9;
    free(minutia9);

    Minutia *result = findCentroid(minutiaArray, computeDistance);

    // Checa que la minuta con la menor distacia acumulada sea la minuta en el indice 5
    if (&minutiaArray->minutiae[5] == result){
        releaseMinutiaArray(minutiaArray);
        return 1;
    }else{
        releaseMinutiaArray(minutiaArray);
        return 0;
    }
    
}

void main(){
    int result = testFindCentroid();
    printf("%d", result);
}