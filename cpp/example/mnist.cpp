#include "../include/cnn.hpp"

#include <fstream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>
#include <time.h>
#include <chrono>
#include <iostream>
#include <Eigen/Dense>

using namespace std;

pair<Matrix, Matrix> readinput(string file, int n)
{

    ifstream ifile(file);

    Matrix label = Matrix::Zero(n, 10);

    Matrix sample = Matrix::Zero(n, 28 * 28);

    for (int i = 0; i < n; i++)
    {
        string tmp;
        getline(ifile, tmp, ',');

        label(i, stoi(tmp, nullptr)) = 1;

        for (int j = 0; j < 28 * 28 - 1; j++)
        {
            getline(ifile, tmp, ',');
            sample(i, j) = stoi(tmp, nullptr);
            sample(i, j) /= 255;
        }
        getline(ifile, tmp, '\n');
        sample(i, 28 * 28 - 1) = stoi(tmp, nullptr);
        sample(i, 28 * 28 - 1) /= 255;
    }

    return make_pair(sample, label);
}

int main()
{
    string trainfile("mnist_train.csv");

    cout << "Reading data..." << endl;
    pair<Matrix, Matrix> tmp = readinput(trainfile, 10000);
    cout << "Data was successfully read!" << endl;
    Matrix x_train = tmp.first;
    Matrix y_train = tmp.second;

    ReLU relu = ReLU();
    Sigmoid sigmoid = Sigmoid();

    Sequential *model = new Sequential(0.5);
    model->addLayer(new Input(784));
    model->addLayer(new Dense(32, &relu));
    model->addLayer(new Dense(10, &sigmoid));

    model->run(x_train, y_train, 5, 128);

    model->saveModel("mnist_model.cnn");
    return 0;
}