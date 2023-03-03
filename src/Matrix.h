#ifndef MatrixH
#define MatrixH

#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int rows;
    int cols;
    double** data;

} Matrix;

Matrix createMatrix(int rows, int cols);
void freeMatrix(Matrix m);

Matrix add(Matrix a, Matrix b);
Matrix dot(Matrix a, Matrix b);

void print(Matrix m);

#endif
