#include"posizione.h"

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

//distruttore
posizione::~posizione(){
}

//metodi di accesso
double posizione::getx() const{
    return m_x;
}
double posizione::gety() const{
    return m_y;
}
double posizione::getz() const{
    return m_z;
}
double posizione::getr() const{
    return sqrt(m_x*m_x+m_y*m_y+m_z*m_z);
}       
double posizione::getphi() const{
    return atan2(m_y,m_x);
}
double posizione::gettheta() const{
    return acos(m_z/getr());
}  
double posizione::getrho() const{
    return sqrt(m_x*m_x+m_y*m_y);
}
double posizione::distanza(const posizione& b) const{
    return sqrt(pow(getx()-b.getx(),2)+pow(gety()-b.gety(),2)+pow(getz()-b.getz(),2));
}
