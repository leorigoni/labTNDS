#ifndef __solutore_h__
#define __solutore_h__

#include"funzioni.h"

//#################
//# DECLARATION #
//#################

class solutore{

    public:

    solutore(){m_prec=0;}
    solutore(double prec){m_prec=prec;}
    virtual ~solutore();
    virtual double cercazeri(double xmin, double xmax,
                                            const funzionebase &f,
                                            double prec=0.001,
                                            unsigned int nmax=100)=0;
    void setprec(double epsilon){m_prec=epsilon;}
    double getprec(){return m_prec;}
    void setnmax(unsigned int n){m_nmax=n;}
    unsigned int getnmax(){return m_nmax;}
    unsigned int getn(){return m_n;}

    protected:

    double m_a, m_b, m_prec;
    unsigned int m_nmax, m_n;

};
class bisezione: public solutore{

    public:
    bisezione(){m_prec=0;}
    bisezione(double prec){m_prec=prec;}
    ~bisezione();
    double cercazeri(double xmin, double xmax,
                                const funzionebase &f,
                                double prec=0.001,
                                unsigned int nmax=100) override;

};

//#####################
//# IMPLEMENTATION #
//#####################

solutore::~solutore(){
}

double bisezione::cercazeri(double xmin, double xmax,
                                        const funzionebase &f,
                                        double prec,
                                        unsigned int nmax){
    segno sign;
    m_n=0;
    m_prec=prec;
    m_nmax=nmax;
    if(xmin<xmax){
        m_a=xmin;
        m_b=xmax;
    }else{
        m_a=xmax;
        m_b=xmin;
    }
    double fa=f.eval(m_a);
    double fb=f.eval(m_b);
    while((m_b-m_a)>m_prec){
        double c=0.5*(m_b+m_a);
        double fc=f.eval(c);
        if(m_n>m_nmax) break;
        m_n++;
        if(sign.eval(fa)*sign.eval(fc)<0){
            m_b=c;
            fb=fc;
        }else if(sign.eval(fa)*sign.eval(fc)>0){
            m_a=c;
            fa=fc;
        }
    }
    return 0.5*(m_b+m_a);
}
bisezione::~bisezione(){
}

#endif