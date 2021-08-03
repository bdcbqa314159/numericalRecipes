#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_matrixDouble(py::module &);
void init_matrixFloat(py::module &);
void init_vectorDouble(py::module &);
void init_vectorFloat(py::module &);
void init_gaussj(py::module &);
void init_LU(py::module &);
void init_banded(py::module &);
void init_tridag(py::module &);
void init_banmul(py::module &);
void init_SVD(py::module &);
void init_vander(py::module &);
void init_toeplz(py::module &);
void init_cholesky(py::module &);
void init_QR(py::module &);
void init_interp_linear(py::module &);

namespace nr {

PYBIND11_MODULE(numRec, m) {
    // Optional docstring
    m.doc() = "Building Numerical Recipes functions\nfrom the cpp book and\ninterfacing with python.";

	init_matrixDouble(m);
	init_matrixFloat(m);
	init_vectorDouble(m);
	init_vectorFloat(m);
	init_gaussj(m);
	init_LU(m);
	init_banded(m);
	init_tridag(m);
	init_banmul(m);
	init_SVD(m);
	init_vander(m);
	init_toeplz(m);
	init_cholesky(m);
	init_QR(m);
    init_interp_linear(m);

	}

}
