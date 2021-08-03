#include "../include/numRec_bits/interp_linear.hpp"

Linear_interp::Linear_interp(vecDoub_I &xv, vecDoub_I &yv)
: Base_interp(xv, &yv[0], 2){
    
}

double Linear_interp::rawinterp(int j, double x){
    if (xx[j] == xx[j+1]) return yy[j];
    else return yy[j] + ((x-xx[j])/ (xx[j+1] - xx[j]))*(yy[j+1]-yy[j]);
        
}
