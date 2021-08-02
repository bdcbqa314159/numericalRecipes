#include "../include/numRec_bits/tridag.hpp"

void tridag(vecDoub_I &a, vecDoub_I &b, vecDoub_I &c, vecDoub_I &r, vecDoub_O &u){

	int j, n = a.size();
	double bet;

	vecDoub gam(n);

	if (b[0] == 0.0) throw std::string{"Error 1 in tridag"};

	u[0] = r[0]/(bet=b[0]);

	for (j=1; j<n; j++){

		gam[j] = c[j-1]/bet;
		bet=b[j]-a[j]*gam[j];
		if (bet == 0.0) throw std::string{"Error 2 in tridag"};
		u[j] = (r[j]-a[j]*u[j-1])/bet;
	}

	for (j = (n-2); j>=0; j--){
		u[j] -= gam[j+1]*u[j+1];
	}
}
