#include "./nr.hpp"
#ifndef QRDCMP_H
#define QRDCMP_H

struct QRdcmp{
	int n;
	matDoub qt,r;
	bool sing;
	QRdcmp(matDoub_I &a);
	void solve(vecDoub_I &b, vecDoub_O &x);
	void qtmult(vecDoub_I &b, vecDoub_O &x);
	void rsolve(vecDoub_I &b, vecDoub_O &x);
	void update(vecDoub_I &u, vecDoub_I &v);
	void rotate(const int i, const double a, const double b);

};


#endif
