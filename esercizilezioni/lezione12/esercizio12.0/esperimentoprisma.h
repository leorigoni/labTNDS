#ifndef _esperimentoprisma_h_
#define _esperimentoprisma_h_
#include "randomgen.h"

class esperimentoprisma{

    public :
    esperimentoprisma(unsigned int seed);
    ~esperimentoprisma(){;};
    void esegui();
    void analizza();
    double getamis(){return m_amis;};
    double getbmis(){return m_bmis;};
    double getn1mis(){return m_n1mis;};
    double getn2mis(){return m_n2mis;};
    double getdm1mis(){return m_dm1mis;};
    double getdm2mis(){return m_dm2mis;};
    double getth0mis(){return m_th0mis;};
    double getth1mis(){return m_th1mis;};
    double getth2mis(){return m_th2mis;};

    private:
    randomgen m_rgen ;
    double m_lambda1, m_lambda2, m_alpha, m_sigmat;
    double m_ainput, m_amis;
    double m_binput, m_bmis;
    double m_n1input, m_n1mis;
    double m_n2input, m_n2mis;
    double m_dm1input, m_dm1mis;
    double m_dm2input, m_dm2mis;
    double m_th0input, m_th0mis;
    double m_th1input, m_th1mis;
    double m_th2input, m_th2mis;

};

esperimentoprisma::esperimentoprisma(unsigned int seed):
    m_rgen(seed), m_lambda1(579.1E-9), m_lambda2(404.7E-9),
    m_alpha(60.*M_PI/180.), m_sigmat(0.3E-3), m_ainput(2.7),
    m_binput(60000E-18) 
{
    m_n1input=sqrt(m_ainput+m_binput/pow(m_lambda1, 2));
    m_n2input=sqrt(m_ainput+m_binput/pow(m_lambda2, 2));
    m_th0input=M_PI/2.;
    m_dm1input=2.*asin(m_n1input*sin(0.5*m_alpha))-m_alpha;
    m_th1input=m_th0input+m_dm1input;
    m_dm2input=2.*asin(m_n2input*sin(0.5*m_alpha))-m_alpha;
    m_th2input=m_th0input+m_dm2input;
}
void esperimentoprisma::esegui(){
    m_th0mis=m_rgen.gaussbm(m_th0input, m_sigmat);
    m_th1mis=m_rgen.gaussbm(m_th1input, m_sigmat);
    m_th2mis=m_rgen.gaussbm(m_th2input, m_sigmat);
}
void esperimentoprisma::analizza(){
    m_dm2mis=m_th2mis-m_th0mis;
    m_n2mis=sin((m_dm2mis+m_alpha)/2.)/sin(0.5*m_alpha);
    m_dm1mis=m_th1mis-m_th0mis;
    m_n1mis=sin((m_dm1mis+m_alpha)/2.)/sin(0.5*m_alpha);
    m_amis=(abs(pow(m_n2mis, 2)*pow(m_lambda2, 2)-pow(m_n1mis, 2)*pow(m_lambda1, 2)))/2;
    m_bmis=pow(m_n2mis, 2)*pow(m_lambda2, 2)-m_amis;
}
#endif