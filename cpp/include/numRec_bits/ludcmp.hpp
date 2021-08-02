#include "./nr.hpp"
#ifndef LUDCMP_H
#define LUDCMP_H

struct LUdcmp{

	int n;
	matDoub lu;
	vecInt indx;
	double d;
	LUdcmp(matDoub_I &a);
	void solve(vecDoub_I &b, vecDoub_O &x);
	void solve(matDoub_I &b, matDoub_O &x);
	void inverse(matDoub_O &ainv);
	double det();
	void mprove(vecDoub_I &b, vecDoub_IO &x);
	matDoub_I &aref;
};

#endif
