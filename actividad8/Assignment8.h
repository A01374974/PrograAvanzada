typedef enum{
    numerical,
    nominal
}FeatureType;

typedef struct {
    double * features;
    FeatureType * featureTypes;
    int length;
}Instance;

double computeEuclideanDissimilarity(const Instance * const instanceOnePtr, const Instance * const instanceTwoPtr);

Instance * findNearestNeighbor(const Instance * const instance,
                               const int length,
                               const Instance * const query,
                               double (*dissimilarityFunction)(const Instance * const instanceOne, const Instance * const instanceTwo));

int testDissimilarityLength0();

int testDissimilarityNotEqualLengths();

int testDissimilarityNotEqualFeatureTypes();

int testDissimilarity();

int testFindNearestNeighborLength0();

int testFindNearestNeighborNotEqualLengths();

int testFindNearestNeighborNotEqualLabels();

int testFindNearestNeighbor();

