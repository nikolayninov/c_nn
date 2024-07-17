#ifndef TYPES_H
#define TYPES_H

#include <functional>
#include <Eigen/Dense>

// function types
typedef std::function<double(double)> func;
typedef std::function<std::string()> sfunc;

// vector & matrix types
typedef double Scalar;
typedef Eigen::MatrixXd Matrix;
typedef Eigen::RowVectorXd RowVector;
typedef Eigen::VectorXd ColVector;

#endif