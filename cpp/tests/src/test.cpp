#include <numRec>

#include <iostream>
#include <iomanip>


int testingVectors(){

	vecDoub v;
    vecDoub x(3);

    double *ans = x.data();

    for (int i=0; i<x.size(); i++){
        std::cout<<*(ans+1)<<std::endl;
    }

    double val = 1.99;

    vecDoub z(5,val);
    ans = z.data();
    for (int i=0; i<z.size(); i++){
        std::cout<<*(ans+i)<<std::endl;
    }

    double a[9] = {1,2,3,4,5,6,7,8,9};
    vecDoub y(9, a);
    ans = y.data();
    for (int i=0; i<y.size(); i++){
        std::cout<<*(ans+i)<<std::endl;
    }


    vecDoub u=y;
    ans = u.data();
    std::cout<<u[2]<<std::endl;
    try {
        double a = u[19];
    } catch (std::string &ex) {
        std::cout<<"Out of bounds"<<std::endl;
    }

	return 0;
}


int testingMatrix(){

    matDoub m;

    matDoub m1(2,4);
    std::cout<<"========="<<std::endl;
    for (int i=0; i<m1.nrows(); i++){
        for (int j=0; j<m1.ncols(); j++){
            std::cout<<m1(i,j)<< " ";
        }
        std::cout<<std::endl;
    }

    matDoub m2(3,5, 6.7);
    std::cout<<"========="<<std::endl;
    for (int i=0; i<m2.nrows(); i++){
        for (int j=0; j<m2.ncols(); j++){
            std::cout<<m2(i,j)<< " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"========="<<std::endl;
    double** a = new double*[3];

    for (int i=0; i<3; i++){
        a[i] = new double[5];
    }
    std::cout<<"========="<<std::endl;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<5; j++){
            a[i][j] = (double)((i+1)*j);
        }
    }
    std::cout<<"========="<<std::endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<5; j++){
            std::cout<<a[i][j]<< " ";
        }
        std::cout<<std::endl;
    }

    int g[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int* o = *g;

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            std::cout<<*o++<< " ";
        }
        std::cout<<std::endl;
    }
    o = *g;

    int** k = new int*[3];
//    for (int i = 0; i<3; i++){
//        k[i] = new int[3];
//    }

    k[0] = new int[9];

    for (int i = 1; i<3; i++){
        k[i] = k[i-1] + 3;
    }

    for (int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            k[i][j] = *o++;
        }
    }


    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            std::cout<<k[i][j]<< " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"========="<<std::endl;
    double g1[3][3] = {
        {1.34,2,3},
        {4,5,6},
        {7,8,9},
    };

    double **l = new double*[3];

    for (int i=0;i<3;i++){
        l[i] = new double[3];
    }
    double *o1 = *g1;
    std::cout<<"========="<<std::endl;
    for (int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            l[i][j] = *o1++;
        }
    }

    for (int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            std::cout<<l[i][j]<<" ";
        }
        std::cout<<"-------"<<std::endl;
    }
    std::cout<<*(*l)<<std::endl;



    std::cout<<"========="<<std::endl;
    matDoub m3(3,3,*g1);

    for (int i=0; i<m3.nrows(); i++){
        for (int j=0; j<m3.ncols(); j++){
            std::cout<<m3(i,j)<< " ";
        }
        std::cout<<std::endl;
    }

    std::cout<<m3(1,2)<<std::endl;

    return 0;
}


void print(matDoub &a){

    int n = a.nrows();
    int m = a.ncols();

    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            std::cout << std::right << std::setw(6)<<a(i,j)<<"\t";
        }
        std::cout<<std::endl;
    }

}


int testingGJ(){

    double a[3][3] = {
        {2,1,2},
        {1,2,1},
        {3,1,-1},
    };

    double b[3][4] = {
        {10,1,0,0},
        {8,0,1,0},
        {2,0,0,1},
    };

    double d[2][2] = {
        {4,3},
        {1,1}
    };

    matDoub A(3,3,*a);
    matDoub B(3,4,*b);

//    Matrix test(2,2,*d);
//    std::cout<<"Original matrices: "<<std::endl;
//    print(A);
//    std::cout<<"======"<<std::endl;
//    print(B);
//    std::cout<<"======"<<std::endl;
    try {
        gaussj(A,B);
    } catch (std::string &ex) {
        std::cout<<"ERROR"<<std::endl;
    }
    print(A);
    std::cout<<"======"<<std::endl;
    print(B);

    std::cout<<"Solution : b[0]="<<1<<" b[1]="<<2<<" b[2]="<<3<<std::endl;

    double a1[3][3] = {
        {3,0,2},
        {2,0,-2},
        {0,1,1},
    };

    matDoub C(3,3,*a);
    matDoub D(3,4,*b);

    try {
        gaussj(C);
    } catch (std::string &ex) {
        std::cout<<"ERROR"<<std::endl;
    }
    std::cout<<"======"<<std::endl;
    print(C);
    std::cout<<"======"<<std::endl;

//    try {
//        gaussj(test);
//    } catch (std::string &ex) {
//        std::cout<<"ERROR"<<std::endl;
//    }
//    std::cout<<"======"<<std::endl;
//    print(test);
//    std::cout<<"======"<<std::endl;

    return 0;
}

int testingLU(){

    double a[3][3] = {
        {2,1,2},
        {1,2,1},//2
        {3,1,-1},//1
    };

//    float a[3][3] = {
//        {1,2,4},
//        {3,8,14},
//        {2,6,13}
//    };

    double a1[2][2] = {
        {4,3},
        {6,3}
    };

    matDoub A(3,3,*a);
    print(A);

    LUdcmp test(A);
    matDoub A1(2,2,*a1);

    test.inverse(A1);
    print(A1);

//    for (int i=0; i<test.indx.size(); i++){
//        std::cout<<test.indx[i]<<std::endl;
//    }
//
    std::cout<<"========"<<std::endl;
    double y[3] = {10,8,2};
    vecDoub y1(3,y);
    vecDoub x1(y1);

    test.solve(y1,x1);

    for (int i = 0; i<x1.size(); i++){
        std::cout<<y1[i]<<std::endl;
    }

    std::cout<<"========"<<std::endl;
    x1=y1;
    test.mprove(y1,x1);

    for (int i = 0; i<x1.size(); i++){
        std::cout<<x1[i]<<std::endl;
    }

    for (int i = 0; i<test.indx.size(); i++){
        std::cout<<test.indx[i]<<std::endl;
    }

    print(test.lu);

    return 0;
}


int testingBandedMatrix(){

//This matrix has to be stored like this:
//    double test[7][7] = {
//        {3,1,0,0,0,0,0},
//        {4,1,5,0,0,0,0},
//        {9,2,6,5,0,0,0},
//        {0,3,5,8,9,0,0},
//        {0,0,7,9,3,2,0},
//        {0,0,0,3,8,4,6},
//        {0,0,0,0,2,4,4} };

    double test[7][4] = { {0,0,3,1},
                           {0,4,1,5},
                           {9,2,6,5},
                           {3,5,8,9},
                           {7,9,3,2},
                           {3,8,4,6},
                           {2,4,4,0} };

    matDoub t(7,4,*test);

    Bandec myBande(t,2,1);

    std::cout << std::setprecision(2);
    print(myBande.au);

    std::cout<<"========"<<std::endl;
    print(myBande.al);

    double test1[4][3] = {
        {0,-2,1},
        {1,-2,1},
        {1,-2,1},
        {1,-2,0}   };

    matDoub A2(4,3,*test1);
    print(A2);

    Bandec A_(A2,1,1);
    std::cout<<"====="<<std::endl;
    print(A_.au);
    std::cout<<"====="<<std::endl;
    print(A_.al);

////    double b3[]={-0.08,-0.12,-0.08,-0.12};
////    vecDoub y(4,b3);
////    vecDoub y1(4);
////
////    banmul(A, 1, 0, y, y1);
////    for (int i=0; i<y1.size(); i++){
////            std::cout<<y1[i]<<std::endl;
////        }
//
//
    double b1[] = {0.04,0.04,0.04,0.04};
    vecDoub x3(4);
    vecDoub b2(4, b1);

    A_.solve(b2,x3);
    std::cout<<"======="<<std::endl;
    for (int i=0; i<x3.size(); i++){
        std::cout<<x3[i]<<std::endl;
    }

    int i, j;

    vecDoub x(7), b(7);
    matDoub a(7, 4);


    a(0,0) = 0.0000000; // arbitrary: not used
    a(0,1) = 0.0000000; // arbitrary: not used
    a(0,2) = 0.5297000;
    a(0,3) = 0.9304360;
    a(1,0) = 0.0000000; // arbitrary: not used
    a(1,1) = 0.0668422;
    a(1,2) = 0.7226600;
    a(1,3) = 0.6711490;
    a(2,0) = 0.6316350;
    a(2,1) = 0.8847070;
    a(2,2) = 0.5194160;
    a(2,3) = 0.6515190;
    a(3,0) = 0.2624530;
    a(3,1) = 0.7621980;
    a(3,2) = 0.7533560;
    a(3,3) = 0.9092080;
    a(4,0) = 0.2727100;
    a(4,1) = 0.8976560;
    a(4,2) = 0.2749070;
    a(4,3) = 0.5162920;
    a(5,0) = 0.2470390;
    a(5,1) = 0.4865170;
    a(5,2) = 0.8461670;
    a(5,3) = 0.8309650;
    a(6,0) = 0.9910370;
    a(6,1) = 0.6792960;
    a(6,2) = 0.7664950;
    a(6,3) = 0.0000000; // arbitrary: not used

    x[0] = 0.4159990;
    x[1] = 0.3835020;
    x[2] = 0.3834160;
    x[3] = 0.2377740;
    x[4] = 0.0726859;
    x[5] = 0.3592650;
    x[6] = 0.0345721;

    std::cout << "Banded matrix [a]:" << std::endl;
    std::cout << std::fixed << std::setprecision(7);
    for (i = 0; i < a.nrows(); i++) {
    for (j = 0; j < a.ncols(); j++) {
    std::cout << std::setw(12) << a(i,j);
    }
    std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Vector [x]:" << std::endl;
    for (i = 0; i < x.size(); i++) {
    std::cout << std::setw(18) << x[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout<<"======="<<std::endl;
    // multiply a times x, giving b
    banmul(a, 2, 1, x, b);

    std::cout << "After multiplying [a] times [x] this is [b]:" << std::endl;

    for (i = 0; i < b.size(); i++) {
    std::cout << std::setw(18) << b[i] << std::endl;
    }
    std::cout << std::endl;

    vecDoub xsave(x);
    Bandec banded(a,2,1);

    banded.solve(b, x);

    std::cout << "After solving [a] times [x] = [b] with bandec.solve():" << std::endl;
    std::cout << " Original Solved" << std::endl
    << " x x" << std::endl;
    for (i = 0; i < x.size(); i++) {
    std::cout << std::setw(12) << xsave[i] << std::setw(12) << x[i] << std::endl;
    }



//    Bandec banded(a, 2, 1);
//    std::cout << "Matrix al" << std::endl;
//    for (i = 0; i < banded.al.nrows(); i++) {
//    for (j = 0; j < banded.al.ncols(); j++) {
//    std::cout << "al[" << i << "][" << j << "] = "
//    << std::setw(12) << banded.al(i,j) <<std::endl;
//    }
//    }
//    std::cout << std::endl;
//    for (i = 0; i < banded.au.nrows(); i++) {
//    for (j = 0; j < banded.au.ncols(); j++) {
//    std::cout << "au[" << i << "][" << j << "] = "
//    << std::setw(12) << banded.au(i,j) << std::endl;
//    }
//    }
//    std::cout << std::endl;



    return 0;
}


int testingSVD(){

    double a[3][3] = {
        {2,1,2},
        {1,2,1},//2
        {3,1,-1},//1
    };

    matDoub A(3,3,*a);
    print(A);
    std::cout<<"========"<<std::endl;
    SVD test(A);

    std::cout<<"========"<<std::endl;
    double y[3] = {10,8,2};
    vecDoub y1(3,y);
    vecDoub x1(y1);

    test.solve(y1, x1, -1);

    for (int i=0; i<x1.size(); i++){
        std::cout<<x1[i]<<std::endl;
    }

    return 0;
}


int testingVandermonde(){

//    double T[6][6]={
//        {1,2,0,-1,5,8},
//        {2,1,2,0,-1,5},
//        {0,2,1,2,0,-1},
//        {-1,0,2,1,2,0},
//        {5,-1,0,2,1,2},
//        {8,5,-1,0,2,1},
//    };

//    double b[6]={1,1,-1,0,-3,1};
//    vecDoub B(6,b);
//    vecDoub x(B);
//
//    matDoub t(6,6,*T);
//    print(t);

//    std::cout<<f(1)<<std::endl;
//    std::cout<<f(2)<<std::endl;
//    std::cout<<f(3)<<std::endl;
//    std::cout<<f(4)<<std::endl;
//    std::cout<<f(5)<<std::endl;
//    std::cout<<f(6)<<std::endl;

//    double x1[6]={1,2,3,4,5,6};
//    double y1[6]={19,279,1807,7141,21051,51259};
//    vecDoub x(6,x1);
//    vecDoub q(6,y1);
//    vecDoub w(x);
//
//    vander(x, w, q);
//    for (int i=0; i<w.size(); i++){
//        std::cout<<w[i]<<std::endl;
//    }

    double x1[3]={1,2,3};

    //    double T[3][3]={
    //        {1,1,1},
    //        {1,2,3},
    //        {1,4,9},
    //    };
    //Tw=y

    double y1[3]={16,38,98};
    vecDoub x(3,x1);
    vecDoub q(3,y1);
    vecDoub w(x);

    vander(x, w, q);
    for (int i=0; i<w.size(); i++){
        std::cout<<w[i]<<std::endl;
    }

    return 0;
}


int testingToeplitz(){

    //    double T[6][6]={
    //        {1,2,0,-1,5,8},
    //        {2,1,2,0,-1,5},
    //        {0,2,1,2,0,-1},
    //        {-1,0,2,1,2,0},
    //        {5,-1,0,2,1,2},
    //        {8,5,-1,0,2,1},
    //    };

    double r[11] = {8,5,-1,0,2,1,2,0,-1,5,8};
    double b[6]={1,-3,0,-1,1,1};

    vecDoub R(13,r);
    vecDoub B(6,b);
    vecDoub x(B);
    toeplz(R, x, B);

    for (int i=0; i<x.size(); i++){
        std::cout<<x[i]<<std::endl;
    }

    return 0;

}


int testingCholseky(){

	double a[3][3] = {
        {25,15,-5},
        {15,18,0},
        {-5,0,11},
    };

    matDoub A(3,3,*a);
    print(A);
    std::cout<<"========"<<std::endl;
    Cholesky test(A);

	print(test.el);

	return 0;
}

int testingQR(){

	double a[3][3] = {
        {1,0,0},
        {1,1,0},
        {1,1,1},
    };

	matDoub A(3,3, *a);
//Thi is from a website but not consistent with numpy. Our results are.
//	double q[3][3] = {
//        {1.0/sqrt(3),-2./sqrt(6),0},
//        {1.0/sqrt(3),1.0/sqrt(6),-1.0/sqrt(2)},
//        {1.0/sqrt(3),1.0/sqrt(6),1.0/sqrt(2)},
//    };
//
//    double r[3][3] = {
//        {3.0/sqrt(3),2./sqrt(3),1.0/sqrt(3)},
//        {0,2.0/sqrt(6),1.0/sqrt(6)},
//        {0,0,1.0/sqrt(2)},
//    };

//	matDoub Q(3,3,*q);
//    matDoub R(3,3,*r);

	print(A);
	std::cout<<"====="<<std::endl;
    std::cout<<"Q theorical:"<<std::endl;
	//print(Q);
    std::cout<<"====="<<std::endl;
    std::cout<<"R theorical:"<<std::endl;
    //print(R);
    
    QRdcmp test(A);
    std::cout<<"====="<<std::endl;
    std::cout<<"Q computed:"<<std::endl;
    print(test.qt);
    std::cout<<"====="<<std::endl;
    std::cout<<"R computed:"<<std::endl;
    print(test.r);
    
    


	return 0;
}


int testingLinearInterp(){
    
    double a[9] = {1,2,3,4,5,6,7,8,9};
    double b[9] = {1,4,3,16,25,36,49,64,81};
    
    vecDoub x(9, a);
    vecDoub y(9, b);
    
    Linear_interp myfunc(x,y);
    
    std::cout<<myfunc.rawinterp(3, 3.2)<<std::endl;
    double z = 5.1;
    double z1{};
    z1 = myfunc.interp(z);
    std::cout<<z1<<std::endl;
    
    
    
    
    
    return 0;
}

int main() {

    std::cout<<"Here we are :)"<<std::endl;
	//testingVectors();
    //testingMatrix();
    //testingGJ();
    //testingLU();
    //testingBandedMatrix();
    //testingSVD();
    //testingToeplitz();
    //testingVandermonde();
    //testingToeplitz();

    //testingCholseky();
    //testingQR();
    testingLinearInterp();

    return 0;
}
