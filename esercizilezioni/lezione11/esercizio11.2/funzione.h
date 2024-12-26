#ifndef __funzioni_h__
#define __funzioni_h__

#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

//#################
//# DECLARATION #
//#################

class funzione{

    public:

    virtual double eval(double x) const=0;
    virtual ~funzione();

};
class xsinx: public funzione{

    public:

    ~xsinx();
    double eval(double x) const override{return x*sin(x);}

};

//#####################
//# IMPLEMENTATION #
//#####################

funzione::~funzione(){
}
xsinx::~xsinx(){
}

#endif