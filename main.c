#include "src/Matrix.h"
#include "src/DenseLayer.h"

int main() {

    DenseLayer d = createDenseLayer(3, 2);
    Matrix i = createRandomMatrix(1, 3);
    Matrix o = forward(d, i);
    print(o);
    freeMatrix(o);

    Matrix e = createRandomMatrix(1, 2);
    print(e);
    backward(d, i, e);
    o = forward(d, i);
    print(o);

    freeMatrix(o);
    freeMatrix(e);
    freeMatrix(i);
    freeDenseLayer(d);
    
    return 0;

}
