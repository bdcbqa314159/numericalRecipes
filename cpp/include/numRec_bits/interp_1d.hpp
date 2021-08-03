#ifndef INTERP1D_H
#define INTERP1D_H

#include "./nr.hpp"
//Interpolation chapter

struct Base_interp {
    int n, mm, jsav, cor, dj;
    const double *xx, *yy;
    
    Base_interp(vecDoub_I &x, const double *y, int m);
    double interp(double x);
    
    int locate(const double x);
    int hunt(const double x);
    double virtual rawinterp(int jlo, double x) = 0;
};



#endif
