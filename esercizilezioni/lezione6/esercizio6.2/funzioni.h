#ifndef __funzioni_h__
#define __funzioni_h__

#include<iostream>
#include<cmath>
using namespace std;

//#################
//# DECLARATION #
//#################

class funzionebase{

    public:

    virtual double eval(double x) const=0;
    virtual ~funzionebase();

};
class parabola: public funzionebase{

    public:

    parabola(){m_a=0; m_b=0; m_c=0;}
    parabola(double a, double b, double c){m_a=a; m_b=b; m_c=c;}
    ~parabola();
    double eval(double x) const override{return m_a*x*x+m_b*x+m_c;}
    void seta(double a){m_a=a;}
    double geta() const{return m_a;}
    void setb(double b){m_b=b;}
    double getb() const{return m_a;}
    void setc(double c){m_c=c;}
    double getc() const{return m_c;}
    double getvertex() const{return -m_b/(2*m_a);}

    private:

    double m_a, m_b, m_c;

};
class segno: public funzionebase{

  public:

    double eval(double x) const{return (x==0?0:(x>0?1:-1));};
    
};

//#####################
//# IMPLEMENTATION #
//#####################

funzionebase::~funzionebase(){
}
parabola::~parabola(){
}

#endif