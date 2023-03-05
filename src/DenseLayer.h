#ifndef DenseLayerH
#define DenseLayerH

#include "Matrix.h"

typedef struct {

    Matrix inputs;
    Matrix outputs;
    Matrix weights;
    Matrix bias;
    double learningRate;

} DenseLayer;

DenseLayer createDenseLayer(int inputSize, int outputSize, double lr);
void freeDenseLayer(DenseLayer d);

Matrix forward(DenseLayer d, Matrix m);
Matrix backward(DenseLayer d, Matrix e);

#endif
