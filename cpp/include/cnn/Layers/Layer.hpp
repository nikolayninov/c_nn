#ifndef LAYER_H
#define LAYER_H

#include <string>
#include <assert.h>
#include <fstream>

#include <Eigen/Dense>

#include "../Types.hpp"
#include "../Functions.hpp"
#include "../Initializers.hpp"
#include "../Utils.hpp"

class Layer
{

public:
    Layer();
    Layer(int, Function *);
    Layer(Layer &&);

    Matrix &getA();
    void setA(Matrix);

    Matrix &getZ();
    void setZ(Matrix);

    Matrix &getB();
    void setB(Matrix);

    Matrix &getW();
    void setW(Matrix);

    Function *getActivation();
    void setActivation(Function *);

    Layer *getL();
    void setL(Layer *);

    int getLayerNum();
    void setLayerNum(int);

    int getLayerSize();
    void setLayerSize(int);

    bool isBuilt();
    void setIsBuilt(bool);

    virtual void loadLayer(std::ifstream &);
    virtual void saveLayer(std::ofstream &);

    virtual void forward(Matrix a, int lo, int hi);

    virtual void build(Layer *, int);

    virtual void call(Matrix);

private:
    bool built;
    int layer_num;
    int layer_size;
    Matrix a;
    Matrix z;
    Matrix b;
    Matrix w;
    Function *activation;
    Layer *l;
};

#endif