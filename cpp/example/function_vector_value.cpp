#include <iostream>
#include <chrono>
#include <math.h>
// #include <Eigen/Dense>

#include "cnn/Functions.hpp"
#include "cnn/Types.hpp"

using namespace std;

int main()
{
    Function f = Constant(exp(1)).exponent(Pol());

    long int n = 1000;
    long int m = 1000;
    Matrix v(n, m);
#pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            v(i, j) = i * m + j + 1;
        }
    }
    // cout << v << endl;
    // cout << v.col(0).size() << endl;
    // cout << v.row(0).size() << endl;

    Matrix r(n, n);
    ColVector v1(n);
    ColVector r1(n);

    auto start1 = chrono::high_resolution_clock::now();
    r = f.call(v);
    r1 = f.call(v1);

    r = f.gradAt(v);
    r1 = f.gradAt(v1);

    auto stop1 = chrono::high_resolution_clock::now();
    auto d1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
    cout << "Loop: \t\t" << d1.count() << endl;

    return 0;
}