#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to simulate retrieval of tensor data (source)
void getData(long *output, size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        output[i] = 128;
        output[i+1] = -128;
    }
}

// Function to normalize input data (taint propagation)
void normalize(long *input, long *output, size_t size) {
    for (size_t i = 0; i < size; i++) {
        output[i] = (input[i] - 32) / 32; // Example normalization
    }
}

// Function for convolutional layer (taint propagation)
void conv(long *input, long *output, size_t size) {
    // Simplified convolution operation
    for (size_t i = 0; i < size; i++) {
        output[i] = input[i] * 0.5; // Example convolution operation
    }
}

// ReLU activation function (taint propagation)
void relu(long *input, long *output, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (input[i] < 0) {
            output[i] = 0;
        } else {
            output[i] = input[i];
        }
    }
}

// Pooling function (taint propagation)
void pool(long *input, long *output, size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        output[i] = fmax(input[2 * i], input[2 * i + 1]); // Example pooling

    }
}

// Function to output the final results (sink)
void outputResults(long *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%li\n", data[i]);
    }
}

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

