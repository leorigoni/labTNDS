#include "class.h"

//particella

//costruttore
particella::particella(){
    m_massa=0;
    m_carica=0;
}
particella::particella(double massa, double carica){ 
    m_massa=massa;
    m_carica=carica;
}

//distruttore 
particella::~particella(){
}

//metodi
void particella::print() const{
    cout << "particella: m=" << m_massa << ", q=" << m_carica << endl; 
}


//elettrone

//costruttore
elettrone::elettrone(const particella &p){
    m_carica=p.getcarica();
    m_massa=p.getmassa();
}
elettrone::elettrone():particella(9.1093826E-31,-1.60217653E-19){
}

//distruttore
elettrone::~elettrone(){
}

//metodi
void elettrone::print() const{
    cout << "elettrone: m=" << m_massa << ", q=" << m_carica << endl;
}
