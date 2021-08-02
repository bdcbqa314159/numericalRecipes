#include "./nr.hpp"
#ifndef SVD_H
#define SVD_H

struct SVD{

	int m,n;
	matDoub u,v;
	vecDoub w;
	double eps, tsh;
	SVD(matDoub_I &a);

	void solve(vecDoub_I &b, vecDoub_O &x, double thresh);
	void solve(matDoub_I &b, matDoub_O &x, double thresh);

	int rank(double thresh);
	int nullity(double thresh);
	matDoub range(double thresh);
	matDoub nullspace(double thresh);

	double inv_condition();
	void decompose();
	void reorder();
	double pythag(const double a, const double b);

};

#endif
