#include "src/Matrix.h"
#include "src/DenseLayer.h"

#include <stdio.h>

int main() {

    DenseLayer d = createDenseLayer(3, 2, 0.01);

    Matrix i = createRandomMatrix(1, 3);
    Matrix e = createRandomMatrix(1, 2);

    print(e);

    for (int j = 0; j < 10; j++) {

        printf("======");
        forward(d, i);
        print(d.outputs);
        backward(d, e);

    }

    freeDenseLayer(d);

    return 0;

}
