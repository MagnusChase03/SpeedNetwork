#include "Matrix.h"

Matrix createMatrix(int rows, int cols) {

    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double**) malloc(sizeof(double*) * rows);

    for (int i = 0; i < rows; i++) {
    
        m.data[i] = (double*) calloc(cols, sizeof(double));

    }

    return m;

}

void freeMatrix(Matrix m) {

    for (int i = 0; i < m.rows; i++) {

        free(m.data[i]);

    }

    free(m.data);

}

Matrix dot(Matrix a, Matrix b) {

    if (a.cols != b.rows) {

        fprintf(stderr, "Error: Matrix dimensions did not match for dot product.");
        exit(1);

    }

    Matrix c = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {

        for (int j = 0; j < b.cols; j++) {

            for (int k = 0; k < a.cols; k++) {

                c.data[i][j] += a.data[i][k] * b.data[k][j];

            }

        }

    }

    return c;

}

void print(Matrix m) {

    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            printf("%f ", m.data[i][j]);

        }
        printf("\n");

    }

}
