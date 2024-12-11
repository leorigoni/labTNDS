#ifndef __integralee_h__
#define __integralee_h__

#include"funzioni.h"

//#################
//# DECLARATION #
//#################

class integrale{

    public:
    virtual ~integrale();
    virtual double integra(double inizio, double fine,
                                        const funzione &,
                                        double prec)=0;
    
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
class trapezi: public integrale{

    public:
    ~trapezi();
    double integra(double inizio, double fine,
                                        const funzione &,
                                        double prec) override;
    int getnstep() const{return m_nstep;}
    double geterr() const{return m_err;}
};

//#####################
//# IMPLEMENTATION #
//#####################

integrale::~integrale(){
}
double trapezi::integra(double inizio, double fine, const funzione &f, double prec){
    checkintervallo(inizio, fine);
    m_nstep=2;
    double tmp=0.0;
    double m_integrale=0.0;
    do{
        m_sum=0.0;
        double step=(fine-inizio)/m_nstep;
        m_h=(fine-inizio)/m_nstep;
        for(int i=0; i<=m_nstep; i++){
            double x=inizio+i*step;
            if(i==0||i==m_nstep){
                m_sum+=0.5*f.eval(x);
            }else{
                m_sum+=f.eval(x);
            }
        }
        m_integrale=m_h*m_sum*m_sign;
        m_err=(4.0/3.0)*fabs(m_integrale-tmp);
        if(m_err<=prec){
            break;
        }
        tmp=m_integrale;
        m_nstep*=2;
    }while(true);
    return m_integrale;
}
trapezi::~trapezi(){
}

#endif