#ifndef __eulero_h__
#define __eulero_h__

#include"funzione.h"

class equazionedifferenzialebase{
    public:
    virtual vector<double> passo(double t, const vector<double> &x,
                                double h, const funzionevettorialebase &f)const=0;
};

class eulero: public equazionedifferenzialebase{
    public:
    virtual vector<double> passo(double t, const vector<double> &x,
                                double h, const funzionevettorialebase &f)const override{
        return x+(f.eval(t, x))*h;
    };
};

#endif