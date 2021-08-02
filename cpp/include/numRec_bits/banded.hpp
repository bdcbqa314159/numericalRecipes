#include "./nr.hpp"

#ifndef BANDED_H
#define BANDED_H

struct Bandec{

	int n,m1,m2;
	matDoub au, al;
	vecInt indx;
	double d;
	Bandec(matDoub_I &a, const int mm1,const int mm2);
	void solve(vecDoub_I &b, vecDoub_O &x);
	double det();

};

void banmul(matDoub_I &a, const int m1, const int m2, vecDoub_I &x, vecDoub_O &b);


#endif
