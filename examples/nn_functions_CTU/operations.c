#include "operations.h"
#include <math.h>

void normalize(long *input, long *output, size_t size) {
    for (size_t i = 0; i < size; i++) {
        output[i] = (input[i] - 32) / 32; // Example normalization
    }
}

void conv(long *input, long *output, size_t size) {
    // Simplified convolution operation
    for (size_t i = 0; i < size; i++) {
        output[i] = input[i] * 0.5; // Example convolution operation
    }
}

void relu(long *input, long *output, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (input[i] < 0) {
            output[i] = 0;
        } else {
            output[i] = input[i];
        }
    }
}

void pool(long *input, long *output, size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        output[i] = fmax(input[2 * i], input[2 * i + 1]); // Example pooling
    }
}

