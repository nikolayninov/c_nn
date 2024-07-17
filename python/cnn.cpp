#include "../cpp/include/cnn/Layers.hpp"
#include "../cpp/include/cnn/Functions.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_function(py::module &);
void init_layer(py::module &);
void init_model(py::module &);

namespace mcl
{

    PYBIND11_MODULE(cnn, m)
    {
        m.doc() = "Neural Networks ibrary";

        init_function(m);
        init_layer(m);
        init_model(m);
    }
}