#include "./nr.hpp"
#ifndef CHOLESKY_H
#define CHOLESKY_H

struct Cholesky{

	int n;
	matDoub el;
	Cholesky(matDoub_I &a);
	void solve(vecDoub_I &b, vecDoub_O &x);
	void elmut(vecDoub_I &y, vecDoub_O &b);
	void elsolve(vecDoub_I &b, vecDoub_O &y);
	void inverse(matDoub_O &ainv);
	double logdet();
};

#endif
