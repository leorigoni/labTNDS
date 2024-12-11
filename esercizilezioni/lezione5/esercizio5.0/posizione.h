#ifndef __posizione_h__
#define __posizione_h__

#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class posizione{
    public:

        //costruttori
        posizione();
        posizione(double x, double y, double z); 

        //distruttore
        ~posizione();

        //metodi di accesso
        double getx() const;
        double gety() const;
        double getz() const;
        double getr() const;
        double getphi() const;
        double gettheta() const;
        double getrho() const;
        double distanza(const posizione &) const;

    private:

        double m_x, m_y, m_z;  
};

#endif // __posizione_h__
