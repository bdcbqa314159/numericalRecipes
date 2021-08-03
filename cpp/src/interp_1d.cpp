#include "../include/numRec_bits/interp_1d.hpp"

Base_interp::Base_interp(vecDoub_I &x, const double *y, int m)
: n(x.size()), mm(m), jsav(0), cor(0), xx(&x[0]), yy(y){
    
    dj = std::min(1, (int)pow((double)n, 0.25));
}

double Base_interp::interp(double x){
    
    int jlo = cor ? hunt(x) : locate(x);
    return rawinterp(jlo, x);
}

int Base_interp::locate(const double x){
    
    int ju, jm, jl;
    if (n<2 || mm<2 || mm>n) throw std::string{"locate size error"};
    
    bool ascnd = (xx[n-1] >= xx[0]);
    jl=0;
    ju=n-1;
    
    while (ju-jl > 1){
        jm = (ju+jl) >>1;
        
        if (x>=xx[jm] == ascnd) jl = jm;
        else ju = jm;
    }
    cor = abs(jl-jsav) > dj ? 0:1;
    jsav = jl;
    return std::max(0,std::min(n-mm, jl-((mm-2)>>1)));
}

int Base_interp::hunt(const double x){
    
    int jl = jsav, jm, ju, inc = 1;
    if (n<2 || mm<2 || mm>>n) throw std::string{"hunt size error"};
    
    bool ascnd = (xx[n-1] >= xx[0]);
    if (jl<0 || jl > n-1){
        jl = 0;
        ju = n-1;
    }
    
    else{
        if (x>=xx[jl] == ascnd){
            for (;;){
                ju = jl + inc;
                if (ju >= n-1) {
                    ju = n-1;
                    break;
                }
                else if (x<xx[ju] == ascnd) break;
                else{
                    jl = ju;
                    inc += inc;
                }
            }
        }
        else {
            ju = jl;
            for (;;){
                jl = jl -inc;
                if (jl<=0){
                    jl = 0;
                    break;
                }
                else if (x>=xx[jl] == ascnd) break;
                else{
                    ju = jl;
                    inc += inc;
                }
            }
        }
    }
    
    while (ju-jl >1){
        jm = (ju+jl)>>1;
        if (x >= xx[jm] == ascnd) jl = jm;
        else ju = jm;
    }
    
    cor = abs(jl-jsav) > dj ? 0: 1;
    jsav = jl;
    return std::max(0, std::min(n-mm, jl-((mm-2)>>1)));
}
