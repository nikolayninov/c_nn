#ifndef DENSE_H
#define DENSE_H

#include <string>

#include "../Functions/Function.hpp"
#include "../Functions/Pol.hpp"

#include "Layer.hpp"

class Dense : public Layer
{
public:
    Dense();
    Dense(int, Function *);

    void forward(Matrix a, int lo, int hi) override;
    virtual void build(Layer *, int) override;

    virtual void call(Matrix) override;
    void loadLayer(std::ifstream &) override;
    void saveLayer(std::ofstream &) override;

private:
};

#endif