#include <pybind11/embed.h>

namespace py = pybind11;

double sum(double a, double b) {
	return a + b;
}

PYBIND11_EMBEDDED_MODULE(clib, m) {
    m.def("sum", &sum, py::arg("a"), py::arg("b"));
}