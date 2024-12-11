#ifndef __posizione_h__
#define __posizione_h__

#include<cmath>
using namespace std;

//#################
//# DECLARATION #
//#################

class posizione{

    public:

    //costruttori
    posizione();
    posizione(double x, double y, double z);

    //metodi
    double getx() const {return m_x;}
    double gety() const {return m_y;}
    double getz() const {return m_z;}
    void setx(double x) {m_x=x;}
    void sety(double y) {m_y=y;}
    void setz(double z) {m_z=z;}
    double getr() const;
    double getphi() const;
    double gettheta() const;
    double getrho() const;
    double distanza(const posizione &) const;

    //distruttore
    ~posizione();

    private:

    double m_x, m_y, m_z;

};

//#####################
//# IMPLEMENTATION #
//#####################

//costruttori
posizione::posizione(){
    m_x=0;
    m_y=0;
    m_z=0;
}
posizione::posizione(double x, double y, double z){
    m_x=x;
    m_y=y;
    m_z=z;
}

//metodi
double posizione::getr() const{
    return sqrt(m_x*m_x+m_y*m_y+m_z*m_z);
}
double posizione::getphi() const{
    return atan2(m_y, m_x);
}
double posizione::gettheta() const{
    return acos(m_z/getr());
}
double posizione::getrho() const{
    return sqrt(m_x*m_x+m_y*m_y);
}
double posizione::distanza(const posizione &p) const{
    return sqrt(pow(getx()-p.getx(),2)+pow(gety()-p.gety(),2)+pow(getz()-p.getz(),2));
}

//distruttore
posizione::~posizione(){
}

#endif