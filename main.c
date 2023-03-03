#include "src/Matrix.h"

int main() {

    Matrix a = createMatrix(2, 3);
    Matrix b = createMatrix(3, 2);
    Matrix c = dot(a, b);
    print(c);

    freeMatrix(c);
    freeMatrix(b);
    freeMatrix(a);

    return 0;

}
