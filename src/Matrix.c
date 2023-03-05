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

Matrix createRandomMatrix(int rows, int cols) {

    srand(time(0));

    Matrix m = createMatrix(rows, cols);
    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            m.data[i][j] = (double) rand() / RAND_MAX;

        }

    }

    return m;

}

void freeMatrix(Matrix m) {

    for (int i = 0; i < m.rows; i++) {

        free(m.data[i]);

    }

    free(m.data);

}

void copyMatrix(Matrix a, Matrix b) {

    if (a.cols != b.cols && a.rows != b.rows) {

        fprintf(stderr, "Error: Matrix dimensions did not match for addition.");
        exit(1);

    }

    for (int i = 0; i < a.rows; i++) {

        for (int j = 0; j < a.cols; j++) {

            b.data[i][j] = a.data[i][j];

        }

    }

}

Matrix add(Matrix a, Matrix b) {

    if (a.cols != b.cols && a.rows != b.rows) {

        fprintf(stderr, "Error: Matrix dimensions did not match for addition.");
        exit(1);

    }

    Matrix c = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {

        for (int j = 0; j < a.cols; j++) {

            c.data[i][j] = a.data[i][j] + b.data[i][j];

        }

    }

    return c;

}

Matrix sub(Matrix a, Matrix b) {

    if (a.cols != b.cols && a.rows != b.rows) {

        fprintf(stderr, "Error: Matrix dimensions did not match for addition.");
        exit(1);

    }

    Matrix c = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {

        for (int j = 0; j < a.cols; j++) {

            c.data[i][j] = a.data[i][j] - b.data[i][j];

        }

    }

    return c;

}

Matrix mult(Matrix m, double x) {

    Matrix y = createMatrix(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            y.data[i][j] = m.data[i][j] * x;
        
        }

    }

    return y;

}

Matrix sum(Matrix m, int d) {

    if (d != 0 && d != 1) {
    
        fprintf(stderr, "Error: Dimension can only be 0 or 1 for sum.");
        exit(1);
    
    }

    if (d == 0) {

        Matrix y = createMatrix(1, m.cols);
        for (int i = 0; i < m.rows; i++) {

            for (int j = 0; j < m.cols; j++) {

                y.data[0][j] += m.data[i][j];

            }

        }

        return y;

    } else if (d == 1) {

        Matrix y = createMatrix(m.rows, 1);
        for (int i = 0; i < m.rows; i++) {

            for (int j = 0; j < m.cols; j++) {

                y.data[i][0] += m.data[i][j];

            }

        }

        return y;

    }

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

double sigmoid(double x) {

    return 1 / (1 + exp(-x));

}

Matrix sigmoidMatrix(Matrix m) {

    Matrix y = createMatrix(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            y.data[i][j] = sigmoid(m.data[i][j]);

        }

    }

    return y;

}

Matrix logLiklyhood(Matrix m) {

    Matrix sums = sum(m, 1);
    Matrix y = createMatrix(m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            y.data[i][j] = m.data[i][j] / sums.data[i][0]; 

        }

    }

    freeMatrix(sums);

    return y;

}

Matrix transpose(Matrix m) {

    Matrix y = createMatrix(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            y.data[j][i] = m.data[i][j];

        }

    }

    return y;

}

void print(Matrix m) {

    for (int i = 0; i < m.rows; i++) {

        for (int j = 0; j < m.cols; j++) {

            printf("%f ", m.data[i][j]);

        }
        printf("\n");

    }

}
