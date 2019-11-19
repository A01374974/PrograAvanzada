#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Assignment8.h"

Instance * createInstance(const int length){
    Instance * instance = (Instance *) malloc(sizeof(Instance));
    instance->features = malloc(length * sizeof(double));
    instance->featureTypes = malloc(length * sizeof(FeatureType));
    instance->length = length;

    return instance;
}

void freeInstance(Instance * instance){
    free(instance->features);
    free(instance->featureTypes);
    free(instance);
}

double computeEuclideanDissimilarity(const Instance * const instanceOnePtr, const Instance * const instanceTwoPtr){

    if(instanceOnePtr->length == 0 || instanceTwoPtr->length == 0 ){
        return -1;
    }

    if(instanceOnePtr->length != instanceTwoPtr->length){
        return -2;
    }

    double suma = 0;

    for (int i = 0; i <= instanceOnePtr->length-1; i++) {
        if (instanceOnePtr->featureTypes[i] == 0 && instanceTwoPtr->featureTypes[i] == 0) {
            double instanceOneValue = instanceOnePtr->features[i];
            double instanceTwoValue = instanceTwoPtr->features[i];
            suma += pow(instanceOneValue - instanceTwoValue, 2);
        } else if (instanceOnePtr->featureTypes[i] == 1 && instanceTwoPtr->featureTypes[i] == 1){
            suma += instanceOnePtr->features[i] != instanceTwoPtr->features[i] ? 1 : 0;
        }
        if (instanceOnePtr->featureTypes[i] != instanceTwoPtr->featureTypes[i]) {
            return -3;
        }
    }

    double dissimilarity = sqrt(suma);

    return dissimilarity;
}

Instance * findNearestNeighbor(const Instance * const instances,
        const int length,
        const Instance * const query,
        double (*dissimilarityFunction)(const Instance * const instanceOne, const Instance * const instanceTwo)){

    double minorDissimilarity = 0;

    minorDissimilarity = dissimilarityFunction(&instances[0], query);

    if (minorDissimilarity == -1 || minorDissimilarity == -2 || minorDissimilarity == -3){
        return (int) minorDissimilarity;
    }

    int index = 0;

    for (int i = 1; i < length-1; i++) {
        double newDissimilarity = 0;
        newDissimilarity += dissimilarityFunction(&instances[i], query);

        if (newDissimilarity == -1 || newDissimilarity == -2 || newDissimilarity == -3){
            return (int) newDissimilarity;
        }

        if (newDissimilarity < minorDissimilarity){
            minorDissimilarity = newDissimilarity;
            index = i;
        }
    }
    return &instances[index];
}

int testDissimilarityLength0(){

    Instance * instancePtrOne = createInstance(3);
    instancePtrOne->features[0] = 1;
    instancePtrOne->features[1] = 1;
    instancePtrOne->features[2] = 1;
    instancePtrOne->featureTypes[0] = 1;
    instancePtrOne->featureTypes[1] = 1;
    instancePtrOne->featureTypes[2] = 1;

    Instance * instancePtrTwo = createInstance(0);

    double result = computeEuclideanDissimilarity(instancePtrOne, instancePtrTwo);

    freeInstance(instancePtrOne);
    freeInstance(instancePtrTwo);

    return (result == -1);
}

int testDissimilarityNotEqualLengths(){

    Instance * instancePtrOne = createInstance(1);
    instancePtrOne->features[0] = 9;
    instancePtrOne->featureTypes[0] = 0;

    Instance * instancePtrTwo = createInstance(3);
    instancePtrTwo->features[0] = 8;
    instancePtrTwo->features[1] = 6;
    instancePtrTwo->features[2] = 17;
    instancePtrTwo->featureTypes[0] = 0;
    instancePtrTwo->featureTypes[1] = 1;
    instancePtrTwo->featureTypes[2] = 0;


    double result = computeEuclideanDissimilarity(instancePtrOne, instancePtrTwo);

    freeInstance(instancePtrOne);
    freeInstance(instancePtrTwo);

    return (result == -2);
}

int testDissimilarityNotEqualFeatureTypes(){

    Instance * instancePtrOne = createInstance(5);
    instancePtrOne->features[0] = 1;
    instancePtrOne->features[1] = 2;
    instancePtrOne->features[2] = 3;
    instancePtrOne->features[3] = 4;
    instancePtrOne->features[4] = 5;
    instancePtrOne->featureTypes[0] = 1;
    instancePtrOne->featureTypes[1] = 1;
    instancePtrOne->featureTypes[2] = 1;
    instancePtrOne->featureTypes[3] = 1;
    instancePtrOne->featureTypes[4] = 1; //FeatureType marked as 1

    Instance* instancePtrTwo = createInstance(5);
    instancePtrTwo->features[0] = 1;
    instancePtrTwo->features[1] = 2;
    instancePtrTwo->features[2] = 3;
    instancePtrTwo->features[3] = 4;
    instancePtrTwo->features[4] = 5;
    instancePtrTwo->featureTypes[0] = 1;
    instancePtrTwo->featureTypes[1] = 1;
    instancePtrTwo->featureTypes[2] = 1;
    instancePtrTwo->featureTypes[3] = 1;
    instancePtrTwo->featureTypes[4] = 0; //FeatureType marked as 0

    double result = computeEuclideanDissimilarity(instancePtrOne, instancePtrTwo);

    freeInstance(instancePtrOne);
    freeInstance(instancePtrTwo);

    return (result == -3);
}

int testDissimilarity(){

    Instance * instancePtrOne = createInstance(4);
    instancePtrOne->features[0] = 11;
    instancePtrOne->features[1] = 10;
    instancePtrOne->features[2] = 3;
    instancePtrOne->features[3] = 4;
    instancePtrOne->featureTypes[0] = 0;
    instancePtrOne->featureTypes[1] = 1;
    instancePtrOne->featureTypes[2] = 0;
    instancePtrOne->featureTypes[3] = 1;

    Instance* instancePtrTwo = createInstance(4);
    instancePtrTwo->features[0] = 25;
    instancePtrTwo->features[1] = 2;
    instancePtrTwo->features[2] = 9;
    instancePtrTwo->features[3] = 4;
    instancePtrTwo->featureTypes[0] = 0;
    instancePtrTwo->featureTypes[1] = 1;
    instancePtrTwo->featureTypes[2] = 0;
    instancePtrTwo->featureTypes[3] = 1;


    double result = computeEuclideanDissimilarity(instancePtrOne, instancePtrTwo);

    freeInstance(instancePtrOne);
    freeInstance(instancePtrTwo);

    // (11-25)^2 + 1 + (3-9)^2 + 0 = 233 -> sqrt(233) = 15.26433
    return (result - 15.26433) < 0.0001;
}

int testFindNearestNeighborLength0(){

    Instance * instancePtrOne = createInstance(3);
    instancePtrOne->features[0] = 1;
    instancePtrOne->features[1] = 2;
    instancePtrOne->features[2] = 3;
    instancePtrOne->featureTypes[0] = 0;
    instancePtrOne->featureTypes[1] = 1;
    instancePtrOne->featureTypes[2] = 0;

    Instance * instancePtrTwo = createInstance(3);
    instancePtrTwo->features[0] = 4;
    instancePtrTwo->features[1] = 5;
    instancePtrTwo->features[2] = 6;
    instancePtrTwo->featureTypes[0] = 0;
    instancePtrTwo->featureTypes[1] = 1;
    instancePtrTwo->featureTypes[2] = 0;

    Instance * instancesArr = (Instance *) malloc(2 * sizeof(Instance));
    instancesArr[0] = *instancePtrOne;
    instancesArr[1] = *instancePtrTwo;

    Instance * query = createInstance(0);

    int result = findNearestNeighbor(instancesArr, 2, query, computeEuclideanDissimilarity);

    freeInstance(instancePtrOne);
    freeInstance(instancePtrTwo);
    freeInstance(query);

    int res = result == &instancesArr[0] ? 1 : result;

    free(instancesArr);

    return (res == -1);
}

int testFindNearestNeighborNotEqualLengths(){

    Instance * instancePtrOne = createInstance(3);
    instancePtrOne->features[0] = 1;
    instancePtrOne->features[1] = 2;
    instancePtrOne->features[2] = 3;
    instancePtrOne->featureTypes[0] = 0;
    instancePtrOne->featureTypes[1] = 1;
    instancePtrOne->featureTypes[2] = 0;

    Instance * instancePtrTwo = createInstance(3);
    instancePtrTwo->features[0] = 4;
    instancePtrTwo->features[1] = 5;
    instancePtrTwo->features[2] = 6;
    instancePtrTwo->featureTypes[0] = 0;
    instancePtrTwo->featureTypes[1] = 1;
    instancePtrTwo->featureTypes[2] = 0;

    Instance * instancesArr = (Instance *) malloc(2 * sizeof(Instance));
    instancesArr[0] = *instancePtrOne;
    instancesArr[1] = *instancePtrTwo;

    Instance * query = createInstance(1);
    query->features[0] = 1;
    query->featureTypes[0] = 0;

    int result = findNearestNeighbor(instancesArr, 2, query, computeEuclideanDissimilarity);

    freeInstance(instancePtrOne);
    freeInstance(instancePtrTwo);
    freeInstance(query);

    int res = result == &instancesArr[0] ? 1 : result;

    free(instancesArr);

    return (res == -2);
}

int testFindNearestNeighborNotEqualLabels(){

    Instance * instancePtrOne = createInstance(3);
    instancePtrOne->features[0] = 1;
    instancePtrOne->features[1] = 2;
    instancePtrOne->features[2] = 3;
    instancePtrOne->featureTypes[0] = 0;
    instancePtrOne->featureTypes[1] = 1;
    instancePtrOne->featureTypes[2] = 0;

    Instance * instancePtrTwo = createInstance(3);
    instancePtrTwo->features[0] = 4;
    instancePtrTwo->features[1] = 5;
    instancePtrTwo->features[2] = 6;
    instancePtrTwo->featureTypes[0] = 0;
    instancePtrTwo->featureTypes[1] = 1;
    instancePtrTwo->featureTypes[2] = 0;

    Instance * instancesArr = (Instance *) malloc(2 * sizeof(Instance));
    instancesArr[0] = *instancePtrOne;
    instancesArr[1] = *instancePtrTwo;

    Instance * query = createInstance(3);
    instancePtrTwo->features[0] = 7;
    instancePtrTwo->features[1] = 8;
    instancePtrTwo->features[2] = 9;
    instancePtrTwo->featureTypes[0] = 0;
    instancePtrTwo->featureTypes[1] = 0;
    instancePtrTwo->featureTypes[2] = 0;

    int result = findNearestNeighbor(instancesArr, 2, query, computeEuclideanDissimilarity);

    freeInstance(instancePtrOne);
    freeInstance(instancePtrTwo);
    freeInstance(query);

    int res = result == &instancesArr[0] ? 1 : result;

    free(instancesArr);

    return (res == -3);
}

int testFindNearestNeighbor(){
    Instance * instancePtrOne = createInstance(3);
    instancePtrOne->features[0] = 1;
    instancePtrOne->features[1] = 2;
    instancePtrOne->features[2] = 3;
    instancePtrOne->featureTypes[0] = 0;
    instancePtrOne->featureTypes[1] = 1;
    instancePtrOne->featureTypes[2] = 0;

    Instance * instancePtrTwo = createInstance(3);
    instancePtrTwo->features[0] = 4;
    instancePtrTwo->features[1] = 5;
    instancePtrTwo->features[2] = 6;
    instancePtrTwo->featureTypes[0] = 0;
    instancePtrTwo->featureTypes[1] = 1;
    instancePtrTwo->featureTypes[2] = 0;

    Instance * instancesArr = (Instance *) malloc(2 * sizeof(Instance));
    instancesArr[0] = *instancePtrOne;
    instancesArr[1] = *instancePtrTwo;

    Instance * query = createInstance(3);
    query->features[0] = 1;
    query->features[1] = 2;
    query->features[2] = 3;
    query->featureTypes[0] = 0;
    query->featureTypes[1] = 1;
    query->featureTypes[2] = 0;

    int res = findNearestNeighbor(instancesArr, 2, query, computeEuclideanDissimilarity) == &instancesArr[0];

    freeInstance(instancePtrOne);
    freeInstance(instancePtrTwo);
    freeInstance(query);
    free(instancesArr);

    return (res);
}

void main() {
    printf("testDissimilarityLength0 = %d\n", testDissimilarityLength0());
    printf("testDissimilarityNotEqualLengths = %d\n", testDissimilarityNotEqualLengths());
    printf("testDissimilarityNotEqualFeatureTypes = %d\n", testDissimilarityNotEqualFeatureTypes());
    printf("testDissimilarity = %d\n", testDissimilarity());
    printf("testFindNearestNeighborLength0 = %d\n", testFindNearestNeighborLength0());
    printf("testFindNearestNeighborNotEqualLengths = %d\n", testFindNearestNeighborNotEqualLengths());
    printf("testFindNearestNeighborNotEqualLabels = %d\n", testFindNearestNeighborNotEqualLabels());
    printf("testFindNearestNeighbor = %d\n", testFindNearestNeighbor());
}