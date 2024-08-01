#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "operations.h"

int main() {
    int initSize = 10;
    long inputData[initSize]; // Source
    getData(inputData, initSize);
    
    // Output vectors
    long normOutput[initSize];
    long convOutput[initSize];
    long reluOutput[initSize];
    // Sizes are halved due to pooling function
    long poolOutput[initSize / 2];

    // Taint-propagating functions
    normalize(inputData, normOutput, initSize);
    conv(normOutput, convOutput, initSize);
    relu(convOutput, reluOutput, initSize);
    pool(reluOutput, poolOutput, initSize);

    outputResults(poolOutput, initSize / 2); // Sink

    return 0;
}

