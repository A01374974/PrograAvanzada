typedef enum {
    Ending,Bifurcation,Unknown
} MinutiaType;

typedef struct{
    unsigned short x,y;
    float angle;
    MinutiaType type;
}Minutia;

typedef struct{
    Minutia *minutiae;
    unsigned short length;
}MinutiaArray;

Minutia *createMinutia (unsigned short x, unsigned short y,float angle, MinutiaType type);
MinutiaArray *createMinutiaArray(unsigned short lenght);
void releaseMinutiaArray (MinutiaArray *minArr);
double computeDistance(const Minutia *const minutia1,const Minutia *const minutia2);
Minutia *findCentroid(const MinutiaArray *const minutiaArray,double (*distance)(const Minutia *const minutia1,const Minutia *const minutia2));
int testFindCentroid();
