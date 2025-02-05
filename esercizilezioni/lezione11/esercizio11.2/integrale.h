#ifndef __integrale_h__
#define __integrale_h__

#include"funzione.h"
#include"randomgen.h"

//#################
//# DECLARATION #
//#################

class integrale{

    public:
    virtual ~integrale();
    virtual double integra(int n, double a, double b,
                                        const funzione &, double ymax, int sgn)=0;
    
    protected:
    double m_inizio, m_fine, m_sum, m_integrale, m_h, m_prec, m_err;
    int m_nstep;
};
class media: public integrale, public randomgen{
    public:
    media(unsigned int seed) : randomgen(seed){;};
    ~media();
    double integra(int n, double a, double b,
                             const funzione &, double ymax, int sgn) override;
    int getnstep() const{return m_nstep;}
    double geterr() const{return m_err;}
};
class hitmiss: public integrale, public randomgen{
    public:
    hitmiss(unsigned int seed) : randomgen(seed){;};
    ~hitmiss();
    double integra(int n, double a, double b,
                             const funzione &, double ymax, int sgn) override;
    int getnstep() const{return m_nstep;}
    double geterr() const{return m_err;}
};

//#####################
//# IMPLEMENTATION #
//#####################

integrale::~integrale(){
}
double media::integra(int n, double a, double b, const funzione &f, double ymax, int sgn){
    double sum=0.;
    for(int i=0; i<n; i++){
        sum+=f.eval(unif(a, b));
    }
    m_integrale=(b-a)*(sum/n)*sgn;
    return m_integrale;
}
media::~media(){
}
double hitmiss::integra(int n, double a, double b, const funzione &f, double ymax, int sgn){
    double ntot=0.;
    double nhit=0.;
    for(int i=0; i<n; i++){
        double x=unif(a, b);
        double y=unif(0, ymax);
        ntot++;
        if(y<=f.eval(x)){
            nhit++;
        }
    }
    m_integrale=(b-a)*ymax*(nhit/ntot)*sgn;
    return m_integrale;
}
hitmiss::~hitmiss(){
}

#endif