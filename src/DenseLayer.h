#ifndef DenseLayerH
#define DenseLayerH

#include "Matrix.h"

typedef struct {

    Matrix weights;
    Matrix bias;

} DenseLayer;

DenseLayer createDenseLayer(int inputSize, int outputSize);
void freeDenseLayer(DenseLayer d);

Matrix forward(DenseLayer d, Matrix m);

#endif