#ifndef __funzione_h__
#define __funzione_h__
#include"include.h"

//#################
//# DECLARATION #
//#################

class funzione{
    public:
    virtual double eval(double) const{
        cout << "Error, this function is not implemented" << endl;
        exit(-1);
    };
    virtual double eval_der(double) const{
        cout << "Error, this function is not implemented" << endl;
        exit(-1);
    };
    virtual ~funzione();
};

class effe: public funzione{
    public:
    ~effe();
    double eval(double) const override;
};

class effeprimo: public funzione{
    public:
    ~effeprimo();
    double eval_der(double) const override;
};

class segno: public funzione{
    public:
    ~segno();
    double eval(double) const override;
};

//#####################
//# IMPLEMENTATION #
//#####################

funzione::~funzione(){
}

double effe::eval(double x) const{
    return pow(x, 3)*log(sqrt(M_E+pow(x, 2)));
}
effe::~effe(){
}

double effeprimo::eval_der(double x) const{
    return x; //non implementato
}
effeprimo::~effeprimo(){
}

double segno::eval(double x) const{
    return (x==0?0:(x>0?1:-1));
}
segno::~segno(){
}

#endif