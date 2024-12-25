#ifndef __Randomgen_h__
#define __Randomgen_h__

#include<iostream>
#include<cmath>

using namespace std;

class Randomgen{

    public:
    Randomgen(unsigned int);
    void seta(unsigned int a){m_a=a;}
    void setc(unsigned int c){m_c=c;}
    void setm(unsigned int m){m_m=m;}
    double Rand();
    double unif(double xmin, double xmax);
    double exp(double lambda);
    double gausbm(double mean, double sigma);
    double gausar(double mean, double sigma, double a, double b);

    private:
    unsigned int m_a, m_c, m_m;
    unsigned int m_seed;

};

Randomgen::Randomgen(unsigned int seed){
    m_seed=seed;
    m_a=1664525;
    m_c=1013904223;
    m_m=1<<31;
}
double Randomgen::Rand(){
    m_seed=(m_a*m_seed+m_c)%m_m;
    return double(m_seed)/double(m_m);
}
double Randomgen::unif(double xmin, double xmax){
    m_seed=(m_a*m_seed+m_c)%m_m;
    return xmin+(xmax-xmin)*double(m_seed)/double(m_m);
}
double Randomgen::exp(double lambda){
    double x=-log(1-Rand());
    return x/lambda;
}
double Randomgen::gausbm(double mean, double sigma){
    double s=Rand();
    double t=Rand();
    double x=sqrt(-2.0*log(1.0-s))*cos(2.0*M_PI*t);
    return mean+x*sigma;
}
double calcgauss(double x, double mean, double sigma){
    return 1/(sigma*sqrt(2*M_PI))*exp(-pow(mean-x, 2)/(2*sigma*sigma));
    };
double Randomgen::gausar(double mean, double sigma, double a, double b){
    double max=calcgauss(mean, mean, sigma);
    double y=max*Rand();
    double x=unif(a, b);
    while(y>=calcgauss(x, mean, sigma)){
        y=max*Rand();
        x=unif(a, b);  
    }
    return x;
}

#endif
