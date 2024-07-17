#include "../include/cnn/Initializers.hpp"

Scalar randomWeight(Scalar x)
{

    return (Scalar)rand() / RAND_MAX;
}