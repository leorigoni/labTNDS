#ifndef __particella_h__
#define __particella_h__

#include<iostream>
using namespace std;

//#################
//# DECLARATION #
//#################

class particella{

    public:

    //costruttori
    particella();
    particella(double massa, double carica);

    //metodi
    double getmassa() const {return m_massa;}
    double getcarica() const {return m_carica;}
    void print() const;
    
    //distruttore
    ~particella();

    protected:

    double m_massa, m_carica;

};

//#####################
//# IMPLEMENTATION #
//#####################

//costruttori
particella::particella(){
    m_massa=0;
    m_carica=0;
}
particella::particella(double massa, double carica){
    m_massa=massa;
    m_carica=carica;
}

//metodi
void particella::print() const{
    cout << "Particella:" << endl;
    cout << "m= " << m_massa << endl;
    cout << "q= " << m_carica << endl;
}

//distruttore
particella::~particella(){
}

#endif