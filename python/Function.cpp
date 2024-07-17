#include "../cpp/include/cnn/Functions.hpp"
#include "../cpp/include/cnn/Layers.hpp"

#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <pybind11/eigen.h>

#include <pybind11/pybind11.h>
namespace py = pybind11;

void init_function(py::module &m)
{
     py::class_<Function>(m, "Function")
         .def(py::init<>())
         .def(py::init<Function const &>())
         .def("__call__",
              py::overload_cast<double>(&Function::call, py::const_))
         .def("__call_",
              py::overload_cast<ColVector &>(&Function::call, py::const_))
         .def("__call__",
              py::overload_cast<Matrix &>(&Function::call, py::const_))
         .def("grad_at",
              py::overload_cast<double>(&Function::gradAt, py::const_))
         .def("grad_at",
              py::overload_cast<ColVector &>(&Function::gradAt, py::const_))
         .def("grad_at",
              py::overload_cast<Matrix &>(&Function::gradAt, py::const_))
         .def("exponent", &Function::exponent)
         .def(py::self + py::self)
         .def(py::self - py::self)
         .def(py::self * py::self)
         .def(py::self / py::self)
         .def("__repr__", &Function::to_string);

     py::class_<Pol, Function>(m, "Pol")
         .def(py::init<>())
         .def(py::init<double>(), py::arg("power"));
     py::class_<Constant, Function>(m, "Constant")
         .def(py::init<>())
         .def(py::init<double>(), py::arg("x"));
     py::class_<Cos, Function>(m, "Cos")
         .def(py::init<>());
     py::class_<Sin, Function>(m, "Sin")
         .def(py::init<>());
     py::class_<Log, Function>(m, "Log")
         .def(py::init<>())
         .def(py::init<double>(), py::arg("b"));
     py::class_<Sigmoid, Function>(m, "Sigmoid")
         .def(py::init<>());
     py::class_<ReLU, Function>(m, "ReLU")
         .def(py::init<>());
     py::class_<Max, Function>(m, "Max")
         .def(py::init<Function &, Function &>(), py::arg("lhs"), py::arg("rhs"));
     py::class_<Min, Function>(m, "Min")
         .def(py::init<Function, Function>(), py::arg("lhs"), py::arg("rhs"));
}