#include "Functions.hpp"

#include <iostream>

using namespace std;

int main()
{
    // ReLU definition
    Function f = Max(Constant(0), Pol());
    cout << "=============" << endl;
    cout << f << endl;
    for (double i = -1; i < 2.0; i += 0.5)
        printf("f(%.2f) = %f\n", i, f.call(i));

    cout << "Derivative: " << endl;
    for (double i = -1; i < 2.0; i += 0.5)
        printf("f(%.2f) = %f\n", i, f.gradAt(i));

    return 0;
}