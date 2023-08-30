#include <iostream>

#include <Eigen/Dense>

#include "c_nn/Functions.hpp"

using namespace std;

int main()
{
    // ReLU definition
    // Function f = Max(Constant(0), Pol());

    Function f = Pol() * Pol(3) + Constant(7) / Pol(7) - Sin() * Cos() + Constant(M_E).exp(Pol());
    cout << "=============" << endl;
    cout << f << endl;
    for (double i = 0.5; i < 2.0; i += 0.1)
        printf("f(%.2f) = %f\n", i, f.call(i));

    cout << "Derivative: " << endl;
    for (double i = 0.5; i < 2.0; i += 0.1)
        printf("f'(%.2f) = %f\n", i, f.gradAt(i));

    return 0;
}