#include "../include/numRec_bits/cholesky.hpp"

Cholesky::Cholesky(matDoub_I &a) : n(a.nrows()), el(a) {

	int i,j,k;
	vecDoub tmp;
	double sum;
	if (el.ncols()!=n) throw std::string{"need square matrix"};

	for (i=0; i<n; i++){
		for (j=i; j<n; j++){
			for (sum=el(i,j), k=i-1;k>=0; k--) sum -= el(i,k)*el(j,k);
			if (i==j){
				if (sum<=0.0) throw std::string{"Cholesky failed"};
				el(i,i)=sqrt(sum);
			}
			else{
				el(j,i)=sum/el(i,i);
			}
		}
	}
	for (i=0; i<n; i++) for (j=0; j<i;j++) el(j,i)=0.0;

}

void Cholesky::solve(vecDoub_I &b, vecDoub_O &x){

	int i,k;
	double sum;
	if(b.size() != n || x.size() != n) throw std::string{"bad lengths in Cholesky"};
	for (i=0; i<n; i++){
		for (sum=b[i], k=i-1; k>=0; k--) sum -= el(i,k)*x[k];
		x[i]=sum/el(i,i);
	}

	for (i=n-1; i>=0; i--){
		for (sum = x[i], k=i+1; k<n; k++) sum -= el(k,i)*x[k];
		x[i]=sum/el(i,i);
	}

}

void Cholesky::elmut(vecDoub_I &y, vecDoub_O &b){

	int i,j;
	if (b.size() != n || y.size() != n) throw std::string{"bad lengths"};
	for (i=0; i<n; i++){
		b[i]=0;
		for (j=0; j<=i; j++) b[i]+=el(i,j)*y[j];
	}
}

void Cholesky::elsolve(vecDoub_I &b, vecDoub_O &y){

	int i,j;
	double sum;
	if (b.size() != n || y.size() !=n) throw std::string{"bad lengths"};
	for (i=0; i<n; i++){
		for (sum=b[i], j=0; i<j; j++) sum -= el(i,j)*y[j];
		y[i] = sum/el(i,i);
	}
}

void Cholesky::inverse(matDoub_O &ainv){

	int i,j,k;
	double sum;
	ainv.resize(n,n);

	for (i=0; i<=n; i++) for (j=0; j<=i; j++){
		sum = (i==j ? 1.0 : 0.0);
		for (k=i-1; k>=j; k--) sum -= el(i,k)*ainv(j,k);
		ainv(j,i)=sum/el(i,i);
	}

	for (i=n-1; i>=0; i--) for (j=0; j<=i; j++){
		sum = (i<j ? 0.0 : ainv(j,i));
		for (k=i+1; k<n; k++) sum -= el(k,i)*ainv(j,k);
		ainv(i,j) = ainv(j,i) = sum/el(i,i);
	}
}
double Cholesky::logdet(){

	double sum = 0.0;
	for (int i = 0; i<n; i++) sum += log(el(i,i));
	return 2.0*sum;
}
