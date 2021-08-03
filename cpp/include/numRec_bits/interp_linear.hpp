#ifndef INTERPLINEAR_H
#define INTERPLINEAR_H

#include "./nr.hpp"
#include "./interp_1d.hpp"

//Interpolation chapter

struct Linear_interp : Base_interp {
    Linear_interp(vecDoub_I &xv, vecDoub_I &yv);
    double rawinterp(int j, double x);
};



#endif
