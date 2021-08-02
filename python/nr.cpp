#include "../cpp/include/numRec_bits/nr.hpp"
#include "../cpp/include/numRec_bits/gaussj.hpp"
#include "../cpp/include/numRec_bits/ludcmp.hpp"
#include "../cpp/include/numRec_bits/tridag.hpp"
#include "../cpp/include/numRec_bits/banded.hpp"
#include "../cpp/include/numRec_bits/svd.hpp"
#include "../cpp/include/numRec_bits/vander.hpp"
#include "../cpp/include/numRec_bits/toeplz.hpp"
#include "../cpp/include/numRec_bits/cholesky.hpp"
#include "../cpp/include/numRec_bits/qrdcmp.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void init_vectorFloat(py::module &m){

	py::class_<vecFlt>(m, "vecFlt32", py::buffer_protocol())
        .def(py::init<size_t>())
        /// Construct from a buffer
        .def(py::init([](const py::buffer &b) {
            py::buffer_info info = b.request();
            if (info.format != py::format_descriptor<float>::format() || info.ndim != 1)
            	throw std::runtime_error("Incompatible buffer format!");

            auto v = new vecFlt(info.shape[0]);
            memcpy(v->data(), info.ptr, sizeof(float) * v->size());
            return v;
        }))

        .def("size", &vecFlt::size)

        /// Bare bones interface
        .def("__getitem__",
             [](const vecFlt &m, size_t i) {
                 if (i<0 || i>=m.size())
                     throw py::index_error();
                 return m[i];
             })

        .def("__setitem__",
             [](vecFlt &m, size_t i, float v) {
				 if (i<0 || i>=m.size())
                     throw py::index_error();
                 return m[i] = v;
             })
        /// Provide buffer access
		.def_buffer([](vecFlt &m) -> py::buffer_info {
        return py::buffer_info(
            m.data(),                               /* Pointer to buffer */
            sizeof(float),                          /* Size of one scalar */
            py::format_descriptor<float>::format(), /* Python struct-style format descriptor */
            1,                                      /* Number of dimensions */
            { m.size()},                 /* Buffer dimensions */
            { sizeof(float) * m.size()}
        );
    });
}


void init_vectorDouble(py::module &m){

	py::class_<vecDoub>(m, "vecFlt64", py::buffer_protocol())
        .def(py::init<size_t>())
        /// Construct from a buffer
        .def(py::init([](const py::buffer &b) {
            py::buffer_info info = b.request();
            if (info.format != py::format_descriptor<double>::format() || info.ndim != 1)
            	throw std::runtime_error("Incompatible buffer format!");

            auto v = new vecDoub(info.shape[0]);
            memcpy(v->data(), info.ptr, sizeof(double) * v->size());
            return v;
        }))

        .def("size", &vecDoub::size)

        /// Bare bones interface
        .def("__getitem__",
             [](const vecDoub &m, size_t i) {
                 if (i<0 || i>=m.size())
                     throw py::index_error();
                 return m[i];
             })

        .def("__setitem__",
             [](vecDoub &m, size_t i, float v) {
				 if (i<0 || i>=m.size())
                     throw py::index_error();
                 return m[i] = v;
             })
        /// Provide buffer access
		.def_buffer([](vecDoub &m) -> py::buffer_info {
        return py::buffer_info(
            m.data(),                               /* Pointer to buffer */
            sizeof(double),                          /* Size of one scalar */
            py::format_descriptor<double>::format(), /* Python struct-style format descriptor */
            1,                                      /* Number of dimensions */
            { m.size()},                 /* Buffer dimensions */
            { sizeof(double) * m.size()}
        );
    });
}


void init_matrixFloat(py::module &m) {

	py::class_<Matrix<float>>(m, "matFlt32", py::buffer_protocol())
        .def(py::init<py::size_t, py::size_t>())
        /// Construct from a buffer
        .def(py::init([](const py::buffer &b) {
            py::buffer_info info = b.request();
            if (info.format != py::format_descriptor<float>::format() || info.ndim != 2)
                throw std::runtime_error("Incompatible buffer format!");

            auto v = new Matrix<float>(info.shape[0], info.shape[1]);
            memcpy(v->data(), info.ptr, sizeof(float) * (size_t) (v->nrows() * v->ncols()));
            return v;
        }))

        .def("rows", &Matrix<float>::nrows)
        .def("cols", &Matrix<float>::ncols)

        /// Bare bones interface
        .def("__getitem__",
             [](const Matrix<float> &m, std::pair<py::size_t, py::size_t> i) {
                 if (i.first >= m.nrows() || i.second >= m.ncols())
                     throw py::index_error();
                 return m(i.first,i.second);
             })
        .def("__setitem__",
             [](Matrix<float> &m, std::pair<py::ssize_t, py::ssize_t> i, float v) {
                 if (i.first >= m.nrows() || i.second >= m.ncols())
                     throw py::index_error();
                 m(i.first, i.second) = v;
             })
        // /// Provide buffer access
        // .def_buffer([](Matrix &m) -> py::buffer_info {
        //     return py::buffer_info(
        //         m.data(),                               /* Pointer to buffer */
        //         { m.nrows(), m.ncols() },                 /* Buffer dimensions */
        //         { sizeof(float) * size_t(m.ncols()),     /* Strides (in bytes) for each index */
        //           sizeof(float) }
        //     );
        // });

		.def_buffer([](Matrix<float> &m) -> py::buffer_info {
        return py::buffer_info(
            m.data(),                               /* Pointer to buffer */
            sizeof(float),                          /* Size of one scalar */
            py::format_descriptor<float>::format(), /* Python struct-style format descriptor */
            2,                                      /* Number of dimensions */
            {  m.nrows(), m.ncols() },                 /* Buffer dimensions */
            { sizeof(float) * size_t(m.ncols()),     /* Strides (in bytes) for each index */
			  sizeof(float) }
        );
    });
}


void init_matrixDouble(py::module &m) {

	py::class_<Matrix<double>>(m, "matFlt64", py::buffer_protocol())
        .def(py::init<py::size_t, py::size_t>())
        /// Construct from a buffer
        .def(py::init([](const py::buffer &b) {
            py::buffer_info info = b.request();
            if (info.format != py::format_descriptor<double>::format() || info.ndim != 2)
                throw std::runtime_error("Incompatible buffer format!");

            auto v = new Matrix<double>(info.shape[0], info.shape[1]);
            memcpy(v->data(), info.ptr, sizeof(double) * (size_t) (v->nrows() * v->ncols()));
            return v;
        }))

        .def("rows", &Matrix<double>::nrows)
        .def("cols", &Matrix<double>::ncols)

        /// Bare bones interface
        .def("__getitem__",
             [](const Matrix<double> &m, std::pair<py::size_t, py::size_t> i) {
                 if (i.first >= m.nrows() || i.second >= m.ncols())
                     throw py::index_error();
                 return m(i.first,i.second);
             })
        .def("__setitem__",
             [](Matrix<double> &m, std::pair<py::ssize_t, py::ssize_t> i, float v) {
                 if (i.first >= m.nrows() || i.second >= m.ncols())
                     throw py::index_error();
                 m(i.first, i.second) = v;
             })
        // /// Provide buffer access
        // .def_buffer([](Matrix &m) -> py::buffer_info {
        //     return py::buffer_info(
        //         m.data(),                               /* Pointer to buffer */
        //         { m.nrows(), m.ncols() },                 /* Buffer dimensions */
        //         { sizeof(float) * size_t(m.ncols()),     /* Strides (in bytes) for each index */
        //           sizeof(float) }
        //     );
        // });

		.def_buffer([](Matrix<double> &m) -> py::buffer_info {
        return py::buffer_info(
            m.data(),                               /* Pointer to buffer */
            sizeof(double),                          /* Size of one scalar */
            py::format_descriptor<double>::format(), /* Python struct-style format descriptor */
            2,                                      /* Number of dimensions */
            {  m.nrows(), m.ncols() },                 /* Buffer dimensions */
            { sizeof(double) * size_t(m.ncols()),     /* Strides (in bytes) for each index */
			  sizeof(double) }
        );
    });
}


void init_gaussj(py::module &m){

	m.def("gaussJ", py::overload_cast<Matrix<double> &>(&gaussj));

	m.def("gaussJ", py::overload_cast<Matrix<double> &, Matrix<double> &>(&gaussj));

}


void init_LU(py::module &m){

	py::class_<LUdcmp>(m, "LUdcmp")
		.def(py::init<const Matrix<double> &>())
		.def("solve", py::overload_cast<vecDoub_I &, vecDoub_O &>(&LUdcmp::solve))
		.def("solve", py::overload_cast<const Matrix<double> &, Matrix<double>&>(&LUdcmp::solve))
		.def("inverse", &LUdcmp::inverse)
		.def("mprove", &LUdcmp::mprove)
		.def("det", &LUdcmp::det);

}

void init_SVD(py::module &m){

	py::class_<SVD>(m, "SVD")
		.def(py::init<const Matrix<double> &>())
		.def("solve", py::overload_cast<vecDoub_I &, vecDoub_O &, double >(&SVD::solve))
		.def("solve", py::overload_cast<matDoub_I &, matDoub_O &, double >(&SVD::solve))
		.def("range", &SVD::range);
}


void init_banded(py::module &m){

	py::class_<Bandec>(m, "Bandec")
		.def(py::init<const Matrix<double> &, const int &,const int &>())
		.def("solve", &Bandec::solve)
		.def("det", &Bandec::det);

}

void init_banmul(py::module &m){

	m.def("banmul", &banmul);
}

void init_tridag(py::module &m){
	m.def("tridag", &tridag);
}

void init_vander(py::module &m){
	m.def("vander", &vander);
}

void init_toeplz(py::module &m){
	m.def("toeplz", &toeplz);
}

void init_cholesky(py::module &m){

	py::class_<Cholesky>(m, "Cholesky")
		.def(py::init<const Matrix<double> &>())
		.def_readonly("el", &Cholesky::el)
		.def("solve", &Cholesky::solve)
		.def("elmut", &Cholesky::elmut)
		.def("elsolve", &Cholesky::elsolve)
		.def("invese", &Cholesky::inverse)
		.def("logdet", &Cholesky::logdet);

}

void init_QR(py::module &m){

	py::class_<QRdcmp>(m, "QRdcmp")
		.def(py::init<const Matrix<double> &>())
		.def_readonly("qt", &QRdcmp::qt)
		.def_readonly("r", &QRdcmp::r)
		.def("solve", &QRdcmp::solve)
		.def("qtmult", &QRdcmp::qtmult)
		.def("rsolve", &QRdcmp::rsolve)
		.def("update", &QRdcmp::update)
		.def("rotate", &QRdcmp::rotate);

}
