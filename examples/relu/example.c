#include <stdio.h>
#include <stdlib.h>

#define TENSOR_SIZE 10

// Function to simulate retrieval of tensor data (source)
void getTensor(int *output, size_t size) {
    int temp[TENSOR_SIZE] = {128, 127, -130, 125, 129, -124, 123, 132, -133, -128};
    for (size_t i = 0; i < size; i++) {
        output[i] = temp[i];
    }
}

// ReLU activation function (taint propagation)
void relu(int *input, int *output, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (input[i] < 0) {
            output[i] = 0;
        } else {
            output[i] = input[i];
        }
    }
}

// Function to output the final results (sink)
void outputResult(int *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d\n", data[i]);
    }
}

int main() {
    int tensor[TENSOR_SIZE];
    int reluOutput[TENSOR_SIZE];

    getTensor(tensor, TENSOR_SIZE); // Source
    relu(tensor, reluOutput, TENSOR_SIZE); // Taint-propagating function
    outputResult(reluOutput, TENSOR_SIZE); // Sink

    return 0;
}

