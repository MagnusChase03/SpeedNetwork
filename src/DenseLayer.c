#include "DenseLayer.h"

DenseLayer createDenseLayer(int inputSize, int outputSize, double lr) {

    DenseLayer d;
    d.weights = createRandomMatrix(inputSize, outputSize);
    d.bias = createMatrix(1, outputSize);

    d.inputs = createMatrix(1, inputSize);
    d.outputs = createMatrix(1, outputSize);

    d.learningRate = lr;

    return d;

}

void freeDenseLayer(DenseLayer d) {

    freeMatrix(d.weights);
    freeMatrix(d.bias);
    freeMatrix(d.inputs);
    freeMatrix(d.outputs);

}

Matrix forward(DenseLayer d, Matrix m) {

    if (m.rows != d.inputs.rows || m.cols != d.inputs.cols) {

        fprintf(stderr, "Error: Matrix dimensions did not match for forward.");
        exit(1);

    }

    copyMatrix(m, d.inputs);

    Matrix h = dot(m, d.weights);
    Matrix h2 = add(h, d.bias);
    Matrix h3 = sigmoidMatrix(h2);

    copyMatrix(h3, d.outputs);

    freeMatrix(h2);
    freeMatrix(h);
    return h3;

}

Matrix backward(DenseLayer d, Matrix e) {

    if (d.outputs.rows != e.rows || d.outputs.cols != e.cols) {

        fprintf(stderr, "Error: Matrix dimensions did not match for backward.");
        exit(1);

    }

    Matrix e2 = mult(e, d.learningRate);
    for (int i = 0; i < e.cols; i++) {

        e2.data[0][i] = d.outputs.data[0][i] * (1.0 - d.outputs.data[0][i]);

    }
    

    Matrix i = transpose(d.inputs);

    Matrix c = dot(i, e2);
    
    Matrix w = sub(d.weights, c);    

    copyMatrix(w, d.weights);

    freeMatrix(w);
    freeMatrix(c);
    freeMatrix(i);
    freeMatrix(e2);

    Matrix e3 = transpose(e);
    Matrix e4 = dot(d.weights, e3);
    Matrix e5 = transpose(e4);

    freeMatrix(e4);
    freeMatrix(e3);

    return e5;

}
