#include <iostream>
#include <pybind11/embed.h>

namespace py = pybind11;
using namespace std;

void call_sum_in_python(double a, double b) {
	py::scoped_interpreter guard{};
	auto clib = py::module_::import("clib");
	py::print(clib.attr("sum")(a, b).cast<double>());
}

int main() {
	double x;
	double y;
	cin >> x;
	cin >> y;
	call_sum_in_python(x, y);
	return 0;
}