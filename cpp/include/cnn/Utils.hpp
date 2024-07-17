#ifndef UTILS_HPP
#define UTILS_HPP

#include "Types.hpp"

#include <fstream>

Matrix readMatrix(std::ifstream &);
void writeMatrix(Matrix &, std::ofstream &);

#endif