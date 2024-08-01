#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stddef.h> // For size_t

void normalize(long *input, long *output, size_t size);
void conv(long *input, long *output, size_t size);
void relu(long *input, long *output, size_t size);
void pool(long *input, long *output, size_t size);

#endif // OPERATIONS_H

