#ifndef __vettore_h__
#define __vettore_h__

#include <iostream>
#include<fstream>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdlib>

using namespace std;

//class
class vettore{
    public:

    vettore(); 
    vettore(int N);
    vettore(const vettore&);
    ~vettore();
    int getn() const{return m_N;}
    void setcomponent(int, double);
    double getcomponent(int) const;
    void scambia(int, int);

    private:

    int m_N;
    double* m_v;
};

#endif
