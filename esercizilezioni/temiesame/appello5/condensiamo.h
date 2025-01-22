#ifndef __condensiamo_h__
#define __condensiamo_h__
#include "randomgen.h"

class condensatore{

    public :
    condensatore(unsigned int seed);
    ~condensatore(){;};
    void esegui();
    void analizza();
    double getc_mis() const{return m_Cmis;}
    double getdeltat_mis() const{return m_Deltatmis;}
    double getr_mis() const{return m_Rmis;}
    double getv0_mis() const{return m_V0mis;}
    double getv1_mis() const{return m_V1mis;}
    double getc_input() const{return m_Cinput;}
    double getdeltat_input() const{return m_Deltatinput;}
    double getr_input() const{return m_Rinput;}
    double getv0_input() const{return m_V0input;}
    double getv1_input() const{return m_V1input;}

    private:
    randomgen m_rgen ;
    double m_Cmis, m_Deltatmis, m_Rmis, m_V0mis, m_V1mis;
    double m_Cinput, m_Deltatinput, m_Rinput, m_V0input, m_V1input;
};

condensatore::condensatore(unsigned int seed):
    m_rgen(seed), m_Cinput(2), m_Rinput(100), m_V0input(12), m_V1input(3)
{
    m_Deltatinput=m_Cinput*(m_Rinput*log(m_V0input/m_V1input));
}
void condensatore::esegui(){
    m_Deltatmis=m_rgen.gaussbm(m_Deltatinput, 0.03);
    m_Rmis=m_rgen.gaussbm(m_Rinput, 0.03);
    m_V1mis=m_rgen.gaussbm(m_V1input, 0.03);
    m_V0mis=m_rgen.gaussbm(m_V0input, 0.03);
}
void condensatore::analizza(){
    m_Cmis=m_Deltatmis/(m_Rmis*log(m_V0mis/m_V1mis));
}
#endif