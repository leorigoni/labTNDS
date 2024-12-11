#ifndef __funzione_h__
#define __funzione_h__

#include"operators.h"
#include<cmath>

using namespace std;

class funzionevettorialebase{
    public:
    virtual vector<double> eval(double t, const vector<double> &x)const=0;
};

class oscillatorearmonico: public funzionevettorialebase{
    public:
    oscillatorearmonico(double omega0){m_omega0=omega0;};
    virtual vector<double> eval(double t, const vector<double> &x)const{
        vector<double> derivata(x.size());
        derivata[0]=x[1];
        derivata[1]=-pow(m_omega0, 2)*x[0];
        return derivata;
    };
    private:
    double m_omega0;
};

#endif