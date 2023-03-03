#include "DenseLayer.h"

DenseLayer createDenseLayer(int inputSize, int outputSize) {

    DenseLayer d;
    d.weights = createRandomMatrix(inputSize, outputSize);
    d.bias = createMatrix(1, outputSize);

    return d;

}

void freeDenseLayer(DenseLayer d) {

    freeMatrix(d.weights);
    freeMatrix(d.bias);

}

Matrix forward(DenseLayer d, Matrix m) {

    Matrix h = dot(m, d.weights);
    Matrix h2 = add(h, d.bias);
    Matrix h3 = sigmoidMatrix(h2);

    freeMatrix(h2);
    freeMatrix(h);
    return h3;

}
