#include <gtest/gtest.h>
#include "cnn.hpp"

TEST(Model, FullyWorking)
{
    Sequential *model = new Sequential(0.5);
    Sigmoid sig = Sigmoid();
    ReLU relu = ReLU();
    model->addLayer(new Input(2));
    model->addLayer(new Dense(2, &relu));
    model->addLayer(new Dense(2, &relu));
    model->addLayer(new Dense(1, &sig));

    // model->build();

    // string trainfile("mnist_train.csv");
    // string testfile("mnist_test.csv");
    // pair<Matrix, Matrix> tmp = readinput(trainfile, 1000);

    // Matrix x_train = tmp.first;
    // Matrix y_train = tmp.second;
    Matrix x_train = Matrix::Zero(4, 2);
    Matrix y_train = Matrix::Zero(4, 1);

    x_train(1, 1) = 1;
    x_train(2, 0) = 1;
    x_train(3, 0) = 1;
    x_train(3, 1) = 1;
    y_train(1, 0) = 1;
    y_train(2, 0) = 1;
    model->run(x_train, y_train, 5000, 1);
    Matrix predictions = model->predict(x_train);
    predictions(0, 0) = std::round(predictions(0, 0) * 10.0) / 10.0;
    predictions(1, 0) = std::round(predictions(1, 0) * 10.0) / 10.0;
    predictions(2, 0) = std::round(predictions(2, 0) * 10.0) / 10.0;
    predictions(3, 0) = std::round(predictions(3, 0) * 10.0) / 10.0;
    ASSERT_TRUE(y_train.isApprox(predictions));
    model->saveModel("test_model.cnn");
    Sequential *loaded_model = new Sequential(0.5);
    loaded_model->loadModel("test_model.cnn");

    ASSERT_TRUE((model->predict(x_train) - loaded_model->predict(x_train)).norm() < 0.001);
}
TEST(Functions, Identity)
{
    Function f = Pol();
    EXPECT_FLOAT_EQ(f.call(1), 1);
    f = Constant();
    EXPECT_FLOAT_EQ(f.call(1), 1);
    f = Sin();
    EXPECT_FLOAT_EQ(f.call(0), 0);
    f = Cos();
    EXPECT_FLOAT_EQ(f.call(0), 1);
    f = Log();
    EXPECT_FLOAT_EQ(f.call(1), 0);
}