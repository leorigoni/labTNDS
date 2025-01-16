#ifndef __rugnekutta_h__
#define __rugnekutta_h__
#include"include.h" //cmath, operators.h, iostream, vector, cassert, algorithm, numeric
#include"funzione.h" //funzione

//#################
//# DECLARATION #
//#################

class eqdiff{
    public:
    virtual ~eqdiff();
    virtual vector<double> passo(double, const vector<double> &,
                                double, const funzione &)const=0;
};

//EULERO
class eulero: public eqdiff{
    public:
    ~eulero();
    vector<double> passo(double, const vector<double> &,
                                        double, const funzione &)const override;
};

//RUNGE-KUTTA
class rungekutta: public eqdiff{
    public:
    ~rungekutta();
    vector<double> passo(double, const vector<double> &,
                                        double, const funzione &)const override;
}; 

//#####################
//# IMPLEMENTATION #
//#####################

eqdiff::~eqdiff(){
}

//EULERO
vector<double> eulero::passo(double t, const vector<double> &x,
                                                double h, const funzione &f)const override{
    return x+(f.eval(t, x))*h;
}
eulero::~eulero(){
}

//RUNGE-KUTTA
vector<double> rungekutta::passo(double t, const vector<double> &x,
                                                        double h, const funzione &f)const override{
        vector<double> k1=f.eval(t, x);
        vector<double> k2=f.eval(t+h/2.0, x+k1*(h/2.0));
        vector<double> k3=f.eval(t+h/2.0, x+k2*(h/2.0));
        vector<double> k4=f.eval(t+h, x+k3*h);
        return x+(k1+k2*2.0+k3*2.0+k4)*(h/6.0);
}
rungekutta::~rungekutta(){
}
#endif