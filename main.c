#include "src/Matrix.h"

int main() {

    Matrix a = createRandomMatrix(2, 3);
    print(a);

    freeMatrix(a);

    return 0;

}
