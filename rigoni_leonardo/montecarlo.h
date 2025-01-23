#ifndef _stimaerrint_h_
#define _stimaerrint_h_
#include"randomgen.h"
#include"integrazione.h"

class stimaerrint{
    public :
    stimaerrint(unsigned int seed, double x1, double x2, double sigma);
    ~stimaerrint(){;};
    void esegui();
    void analizza(effe &f, trapezi &t);
    double getx1mis(){return m_x1mis;};
    double getx2mis(){return m_x2mis;};
    double getx1input(){return m_x1input;};
    double getx2input(){return m_x2input;};
    double getintegrale(){return m_integrale;};

    private:
    randomgen m_rgen ;
    double m_x1mis, m_x2mis, m_x1input, m_x2input, m_sigma, m_integrale;
};

stimaerrint::stimaerrint(unsigned int seed, double x1, double x2, double sigma):
        m_rgen(seed), m_x1input(x1), m_x2input(x2), m_sigma(sigma){;}
void stimaerrint::esegui(){
    m_x1mis=m_rgen.gaussbm(m_x1input, m_sigma/2);
    m_x2mis=m_rgen.gaussbm(m_x2input, m_sigma/2);
}
void stimaerrint::analizza(effe &f, trapezi &t){
    m_integrale=t.integra_prec(m_x1mis, m_x2mis, 0.0001, f);
}
#endif