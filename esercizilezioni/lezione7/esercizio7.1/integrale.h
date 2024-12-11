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
                                        int nstep)=0;
    
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
    double m_inizio, m_fine, m_sum, m_integrale, m_h;
    int m_sign, m_nstep;
};
class simpson: public integrale{

    public:
    ~simpson();
    double integra(double inizio, double fine,
                                        const funzione &,
                                        int nstep) override;
    double geth() const{return m_h;}
};

//#####################
//# IMPLEMENTATION #
//#####################

integrale::~integrale(){
}
double simpson::integra(double inizio, double fine, const funzione &f, int nstep){
    checkintervallo(inizio, fine);
    m_nstep=nstep;
    if(m_nstep%2!=0){
        m_nstep++;
    }
    m_sum=0.0;
    m_h=(m_fine-m_inizio)/m_nstep;
    for(int i=0; i<=m_nstep; ++i){
        double x=m_inizio+i*m_h;
        if(i==0 || i==m_nstep){
            m_sum+=f.eval(x);
        }else if(i%2==0){
            m_sum+=2*f.eval(x);
        }else{
            m_sum+=4*f.eval(x);
        }
    }
    m_integrale=(m_h/3.0)*m_sum*m_sign;
    return m_integrale;
}
simpson::~simpson(){
}

#endif