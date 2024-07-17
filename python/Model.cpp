#include "../cpp/include/cnn/Models.hpp"

#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <pybind11/operators.h>
#include <pybind11/eigen.h>

#include <pybind11/pybind11.h>
namespace py = pybind11;

// class PyModel : public Model {
// public:
//     using Model::Model;

//     void run(Matrix inpt, Matrix gt, int epochs, int minibatch_size) override
//     {
//         PYBIND11_OVERLOAD(
//             void,
//             Model,
//             run,
//             inpt,
//             gt,
//             epochs,
//             minibatch_size);
//     }
// };

void init_model(py::module &m)
{
    py::class_<Model>(m, "Model")
        .def(py::init<>())
        .def(py::init<double>(), py::arg("alpha"))
        .def("add_layer", &Model::addLayer)
        .def("save", &Model::saveModel)
        .def("load", &Model::loadModel)
        .def("predict", py::overload_cast<Matrix>(&Model::predict))
        .def("run", py::overload_cast<Matrix, Matrix, int, int>(&Model::run));
    py::class_<Sequential, Model>(m, "Sequential")
        .def(py::init<>())
        .def(py::init<double>(), py::arg("alpha"));
    // .def("save", &Sequential::saveModel)
    // .def("load", &Sequential::loadModel)
    // .def("predict", &Sequential::predict)
    // .def("run", py::overload_cast<Matrix, Matrix, int, int>(&Sequential::run));
}