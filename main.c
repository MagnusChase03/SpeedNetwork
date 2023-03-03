#include "src/Matrix.h"
#include "src/DenseLayer.h"

int main() {

    DenseLayer d = createDenseLayer(3, 2);
    Matrix i = createRandomMatrix(1, 3);
    Matrix o = forward(d, i);
    print(o);

    freeMatrix(o);
    freeMatrix(i);
    freeDenseLayer(d);

    return 0;

}
