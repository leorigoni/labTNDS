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
                                        const funzione &)=0;
    
    protected:
    void checkintervallo(double a, double b){
        m_inizio=min(a,b);
        m_fine=max(a,b);
        if(a>b){
            m_sign=-1;
        }else{
            m_sign=1;
        }
    }
    double m_inizio, m_fine, m_sum, m_integrale, m_h, m_prec, m_err;
    int m_sign, m_nstep;
};
class media: public integrale, public randomgen{
    public:
    media(unsigned int seed) : randomgen(seed){;};
    ~media();
    double integra(int n, double a, double b,
                             const funzione &) override;
    int getnstep() const{return m_nstep;}
    double geterr() const{return m_err;}
};

//#####################
//# IMPLEMENTATION #
//#####################

integrale::~integrale(){
}
double media::integra(int n, double a, double b, const funzione &f){
    checkintervallo(a, b);
    double sum=0.;
    for(int i=0; i<n; i++){
        sum+=f.eval(unif(a, b));
    }
    m_integrale=(b-a)*(sum/n);
    return m_integrale;
}
media::~media(){
}

#endif