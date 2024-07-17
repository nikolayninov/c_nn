#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <fstream>
#include <string>

#include <Eigen/Dense>

#include "../Types.hpp"
#include "../Layers.hpp"
#include "../Utils.hpp"

class Model
{
public:
    Model();
    Model(Scalar alpha);
    ~Model();

    virtual void build();

    virtual void feedForward(int lo, int hi);
    virtual void backPropagate(int lo, int hi);

    virtual Scalar computeLoss();
    virtual void run(Matrix inpt, Matrix gt, int epochs, int minibatch_size);
    virtual Matrix predict(Matrix inpt);

    virtual void addLayer(Layer *);

    bool isBuilt();
    void setIsBuilt(bool);

    void loadModel(std::string);
    void saveModel(std::string);

protected:
    Matrix inpt;
    Matrix gt;
    Scalar alpha;
    bool built;
    std::vector<Layer *> layers;
};

#endif