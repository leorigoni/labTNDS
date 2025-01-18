#ifndef __funzione_h__
#define __funzione_h__
#include"include.h"

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
    double eval(double x) const override{return sin(x)+1;}
};

//#####################
//# IMPLEMENTATION #
//#####################

funzione::~funzione(){
}
xsinx::~xsinx(){
}

#endif