#ifndef SEQUENTIAL_HPP
#define SEQUENTIAL_HPP

#include "Model.hpp"

class Sequential : public Model
{
public:
    Sequential();
    Sequential(Scalar alpha);

    void addLayer(Layer *) override;

    void build() override;

    void feedForward(int lo, int hi) override;
    void backPropagate(int lo, int hi) override;

    Scalar computeLoss() override;
    void run(Matrix inpt, Matrix gt, int epochs, int minibatch_size) override;
    Matrix predict(Matrix inpt) override;

protected:
    Matrix inpt;
    Matrix gt;
};

#endif