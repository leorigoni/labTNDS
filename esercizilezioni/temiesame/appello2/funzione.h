#ifndef __funzione_h__
#define __funzione_h__

#include"operators.h"
#include"include.h"
#include"utilities.h"

using namespace std;

class funzione{
    public:
    virtual vector<double> eval(double t, const vector<double> &x)const=0;
};

class oscillatorearmonico: public funzione{
    public:
    oscillatorearmonico(double omega0, double alpha){m_omega0=omega0; m_alpha=alpha;};
    virtual vector<double> eval(double t, const vector<double> &x)const{
        vector<double> derivata(x.size());
        derivata[0]=x[1];
        derivata[1]=-pow(m_omega0, 2)*x[0]-m_alpha*x[1];
        return derivata;
    };
    private:
    double m_omega0, m_alpha;
};

#endif