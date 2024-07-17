#include "../include/cnn/Utils.hpp"

#include <iostream>
Matrix readMatrix(std::ifstream &f)
{
    int rows, cols;
    f >> rows >> cols;
    Matrix m(rows, cols);
    char v;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            f >> m(i, j);
        }
        // f >> v;
    }
    return m;
}

void writeMatrix(Matrix &m, std::ofstream &f)
{
    f << m.innerSize() << " " << m.outerSize() << '\n';
    const int rows = m.innerSize();
    const int cols = m.outerSize();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            f << m(i, j) << ' ';
        }
        f << '\n';
    }
}