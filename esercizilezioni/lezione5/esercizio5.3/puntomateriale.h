#ifndef __puntomateriale_h__
#define __puntomateriale_h__

#include"posizione.h"
#include"particella.h"
#include"campovettoriale.h"

//#################
//# DECLARATION #
//#################

class puntomateriale: public posizione, public particella{

    public:

    //costruttori
    puntomateriale(double massa, double carica, const posizione &);
    puntomateriale(double massa, double carica, double x, double y, double z);

    //metodi
    campovettoriale campoelettrico(const posizione &) const;
    campovettoriale campogravitazionale(const posizione &) const;

    //distruttori
    ~puntomateriale();

};

//#####################
//# IMPLEMENTATION #
//#####################

//costruttori
puntomateriale::puntomateriale(double massa, double carica, const posizione &p): posizione(p){
    m_massa=massa;
    m_carica=carica;
}
puntomateriale::puntomateriale(double massa, double carica, double x, double y, double z): posizione(x, y, z){
    m_massa=massa;
    m_carica=carica;
}

//metodi
campovettoriale puntomateriale::campoelettrico(const posizione &p) const{
  const double epsilon_0=8.854187817e-12;
  double ex=((1)/(4*M_PI*epsilon_0))*((getcarica())/(pow(distanza(p),3)))*(p.getx()-getx());
  double ey=((1)/(4*M_PI*epsilon_0))*((getcarica())/(pow(distanza(p),3)))*(p.gety()-gety());
  double ez=((1)/(4*M_PI*epsilon_0))*((getcarica())/(pow(distanza(p),3)))*(p.getz()-getz());
    return campovettoriale(p.getx(), p.gety(), p.getz(), ex, ey, ez);
}
campovettoriale puntomateriale::campogravitazionale(const posizione &p) const{
  const double G=6.67430e-11;
  double ex=((1)/(4*M_PI*G))*((getmassa())/(pow(distanza(p),3)))*(p.getx()-getx());
  double ey=((1)/(4*M_PI*G))*((getmassa())/(pow(distanza(p),3)))*(p.gety()-gety());
  double ez=((1)/(4*M_PI*G))*((getmassa())/(pow(distanza(p),3)))*(p.getz()-getz());
    return campovettoriale(p.getx(), p.gety(), p.getz(), ex, ey, ez);
}

//distruttore
puntomateriale::~puntomateriale(){
}

#endif