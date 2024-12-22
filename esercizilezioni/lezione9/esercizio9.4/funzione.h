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
    pendolo(double omega0, double alpha, double omega){m_omega0=omega0; m_alpha=alpha; m_omega=omega;};
    virtual vector<double> eval(double t, const vector<double> &x)const{
        vector<double> derivata(x.size());
        derivata[0]=x[1];
        derivata[1]=-pow(m_omega0, 2)*x[0]-m_alpha*x[1]+sin(m_omega*t);
        return derivata;
    };
    private:
    double m_omega0;
    double m_alpha;
    double m_omega;
};

#endif