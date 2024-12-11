#ifndef __funzione_h__
#define __funzione_h__

#include"operators.h"
#include<cmath>

using namespace std;

class funzionevettorialebase{
    public:
    virtual vector<double> eval(double t, const vector<double> &x)const=0;
};

class pendolo: public funzionevettorialebase{
    public:
    pendolo(double l){m_l=l;};
    virtual vector<double> eval(double t, const vector<double> &x)const{
        vector<double> derivata(x.size());
        derivata[0]=x[1];
        derivata[1]=-((m_g/m_l)*sin(x[0]));
        return derivata;
    };
    private:
    double m_g=9.80665;
    double m_l;
};

#endif