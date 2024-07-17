#include "../include/cnn.hpp"
#include "../include/cnn/Utils.hpp"

#include <fstream>
#include <iostream>

using namespace std;
int main()
{
    Sigmoid sig = Sigmoid();
    ReLU relu = ReLU();
    Sequential *model = new Sequential(0.5);

    model->addLayer(new Input(2));
    model->addLayer(new Dense(2, &relu));
    model->addLayer(new Dense(2, &relu));
    model->addLayer(new Dense(1, &sig));

    Matrix x_train = Matrix::Zero(4, 2);
    Matrix y_train = Matrix::Zero(4, 1);

    x_train(1, 1) = 1;
    x_train(2, 0) = 1;
    x_train(3, 0) = 1;
    x_train(3, 1) = 1;
    y_train(1, 0) = 1;
    y_train(2, 0) = 1;

    model->run(x_train, y_train, 5000, 1);
    model->saveModel("test_model.cnn");

    cout << x_train << endl;
    cout << y_train << endl;
    cout << "Prediction:" << endl;
    cout << model->predict(x_train) << endl;
    Model *new_model = new Sequential(0.2);
    new_model->loadModel("test_model.cnn");
    cout << "Prediction (loaded):" << endl;
    cout << new_model->predict(x_train) << endl;

    return 0;
}