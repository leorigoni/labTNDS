#ifndef __campovettoriale_h__
#define __campovettoriale_h__

#include<iostream>
#include"posizione.h"

//#################
//# DECLARATION #
//#################

class campovettoriale: public posizione{

    public:

    //costruttori
    campovettoriale(const posizione &);
    campovettoriale(const posizione &, double fx, double fy, double fz);
    campovettoriale(double x, double y, double z, double fx, double fy, double fz);

    //metodi
    campovettoriale &operator+=(const campovettoriale &);
    campovettoriale operator+(const campovettoriale &) const;
    double getfx() const {return m_fx;}
    double getfy() const {return m_fy;}
    double getfz() const {return m_fz;}
    void setfx(double fx) {m_fx=fx;}
    void setfy(double fy) {m_fy=fy;}
    void setfz(double fz) {m_fz=fz;}
    double modulo() const;

    //distruttore
    ~campovettoriale();

    private:

    double m_fx, m_fy, m_fz;

};

//#####################
//# IMPLEMENTATION #
//#####################

//costruttori
campovettoriale::campovettoriale(const posizione &p): posizione(p.getx(), p.gety(), p.getz()){
    m_fx=0;
    m_fy=0;
    m_fz=0;
}
campovettoriale::campovettoriale(const posizione &p, double fx, double fy, double fz): posizione(p){
    m_fx=fx;
    m_fy=fy;
    m_fz=fz;
}
campovettoriale::campovettoriale(double x, double y, double z, double fx, double fy, double fz): posizione(x, y, z){
    m_fx=fx;
    m_fy=fy;
    m_fz=fz;
}

//metodi
campovettoriale campovettoriale::operator+(const campovettoriale &v) const{
    if((v.getx()!=getx())||(v.gety()!=gety())||(v.getz()!=getz())){
        cout << "Somma di campi vettoriali in punti diversi non ammessa" << endl;
        exit(-11);
    }
    campovettoriale sum(posizione(getx(), gety(), getz()));
    sum.setfx(getfx()+v.getfx());
    sum.setfy(getfy()+v.getfy());
    sum.setfz(getfz()+v.getfz());
    return sum;
}
campovettoriale &campovettoriale::operator+=(const campovettoriale &v){
    return (*this)=(*this)+v;
}
double campovettoriale::modulo() const{
    return sqrt(m_fx*m_fx+m_fy*m_fy+m_fz*m_fz);
}

//distruttore
campovettoriale::~campovettoriale(){
}

#endif