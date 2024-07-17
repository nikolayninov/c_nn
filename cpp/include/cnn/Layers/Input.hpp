#ifndef INPUT_H
#define INPUT_H

#include "Layer.hpp"

class Input : public Layer
{
public:
    Input();
    Input(int);
    void forward(Matrix a, int lo, int hi) override;
    void build(Layer *, int) override;
    void call(Matrix) override;
    std::string get_config();
    void loadLayer(std::ifstream &) override;
    void saveLayer(std::ofstream &) override;

private:
};

#endif