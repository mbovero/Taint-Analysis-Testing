#include "data.h"

void getData(long *output, size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        output[i] = 128;
        output[i+1] = -128;
    }
}

void outputResults(long *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%li\n", data[i]);
    }
}

