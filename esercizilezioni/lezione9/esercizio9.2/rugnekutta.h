#ifndef __rugnekutta_h__
#define __rugnekutta_h__

#include"funzione.h"

class equazionedifferenzialebase{
    public:
    virtual vector<double> passo(double t, const vector<double> &x,
                                double h, const funzionevettorialebase &f)const=0;
};

class rugnekutta: public equazionedifferenzialebase{
    public:
    virtual vector<double> passo(double t, const vector<double> &x,
                                double h, const funzionevettorialebase &f)const override{
        vector<double> k1=f.eval(t, x);
        vector<double> k2=f.eval(t+h/2.0, x+k1*(h/2.0));
        vector<double> k3=f.eval(t+h/2.0, x+k2*(h/2.0));
        vector<double> k4=f.eval(t+h, x+k3*h);
        return x+(k1+k2*2.0+k3*2.0+k4)*(h/6.0);
    };
}; 

#endif