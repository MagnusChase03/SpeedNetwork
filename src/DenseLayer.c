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

Matrix backward(DenseLayer d, Matrix i, Matrix e, double lr) {

    Matrix i2 = transpose(i);        
    Matrix c = dot(i2, e);

    Matrix w = sub(d.weights, c);
    Matrix w2 = mult(w, lr);
    freeMatrix(w);

    copyMatrix(w2, d.weights);
    
    freeMatrix(w2);
    freeMatrix(c);

    Matrix e2 = transpose(e);
    Matrix e3 = dot(d.weights, e2);

    freeMatrix(e2);
    freeMatrix(i2);

    return e3;

}
