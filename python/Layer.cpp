#include "../cpp/include/cnn/Layers.hpp"
#include "../cpp/include/cnn/Functions/Function.hpp"

#include <pybind11/stl.h>
#include <pybind11/operators.h>

#include <pybind11/pybind11.h>
#include <iostream>
namespace py = pybind11;

void init_layer(py::module &m)
{
    py::class_<Layer>(m, "Layer")
        .def(py::init<>())
        .def(py::init<int, Function *>(), py::arg("layer_size"), py::arg("activation"))
        .def("get_A", &Layer::getA)
        .def("set_A", &Layer::setA)
        .def("get_Z", &Layer::getZ)
        .def("set_Z", &Layer::setZ)
        .def("get_B", &Layer::getB)
        .def("set_B", &Layer::setB)
        .def("get_W", &Layer::getW)
        .def("set_W", &Layer::setW)
        .def("get_activation", &Layer::getActivation)
        .def("set_activation", &Layer::setActivation)
        .def("get_l", &Layer::getL)
        .def("set_l", &Layer::setL)
        .def("get_layer_size", &Layer::getLayerSize)
        .def("set_layer_size", &Layer::setLayerSize)
        .def("get_layer_num", &Layer::getLayerNum)
        .def("set_layer_num", &Layer::setLayerNum);
    py::class_<Input, Layer>(m, "Input")
        .def(py::init<>())
        .def(py::init<int>(), py::arg("layer_size"));
    py::class_<Dense, Layer>(m, "Dense")
        .def(py::init<>())
        .def(py::init<int, Function *>(), py::arg("layer_size"), py::arg("activation"));
}