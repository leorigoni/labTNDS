/*
Test function: y=-2x^3x^2+2
Test interval: [0; 4]
Integer: 1,806443
Precision: 0.000001
N maximum: 1000000

Bisezione: 1.806444 in 0 ms
Secazione: 1.806444 in 0 ms
Newtone: 1.806444 in 0 ms
*/
#ifndef __solutore_h__
#define __solutore_h__
#include"includes.h" //iostream, cmath
#include"funzione.h" //funzione

//#################
//# DECLARATION #
//#################

class solutore{
    public:
    solutore(){m_prec=0;}
    solutore(double prec){m_prec=prec;}
    virtual ~solutore();
    virtual double cercazeri(double, double, double, int, const funzione &){
        cout << "Error, this function is not implemented" << endl;
        exit(-1);
    };
    virtual double cercazeri_n(double, double, double, int, const funzione &, const funzione &){
        cout << "Error, this function is not implemented" << endl;
        exit(-1);
    };
    void setprec(double epsilon){m_prec=epsilon;}
    double getprec(){return m_prec;}
    void setnmax(unsigned int n){m_nmax=n;}
    unsigned int getnmax(){return m_nmax;}
    unsigned int getn(){return m_n;}

    protected:
    double m_a, m_b, m_prec;
    unsigned int m_nmax, m_n;
};

//BISEZIONE (converge)
class bisezione: public solutore{
    public:
    bisezione(){m_prec=0;}
    bisezione(double prec){m_prec=prec;}
    ~bisezione();
    double cercazeri(double, double, double, int, const funzione &) override;
};

//SECANTI (può non convergere)
class secanti: public solutore{
    public:
    secanti(){m_prec=0;}
    secanti(double prec){m_prec=prec;}
    ~secanti();
    double cercazeri(double, double, double, int, const funzione &) override;
};

//SECANTI+BISEZIONE (converge)
class secazione: public solutore{
    public:
    secazione(){m_prec=0;}
    secazione(double prec){m_prec=prec;}
    ~secazione();
    double cercazeri(double, double, double, int, const funzione &) override;
};

//NEWTON (può non convergere)
class newton: public solutore{
    public:
    newton(){m_prec=0;}
    newton(double prec){m_prec=prec;}
    ~newton();
    double cercazeri_n(double, double, double, int, const funzione &, const funzione &) override;
};

//NEWTON+BISEZIONE (converge)
class newtone: public solutore{
    public:
    newtone(){m_prec=0;}
    newtone(double prec){m_prec=prec;}
    ~newtone();
    double cercazeri_n(double, double, double, int, const funzione &, const funzione &) override;
};

//#####################
//# IMPLEMENTATION #
//#####################

solutore::~solutore(){
}

//BISEZIONE (converge)
double bisezione::cercazeri(double xmin, double xmax, double prec, int nmax, const funzione &f){
    segno sign;
    m_n=0;
    m_prec=prec;
    m_nmax=nmax;
    if(xmin<xmax){
        m_a=xmin;
        m_b=xmax;
    }else{
        m_a=xmax;
        m_b=xmin;
    }
    double fa=f.eval(m_a);
    double fb=f.eval(m_b);
    while((m_b-m_a)>m_prec){
        double c=0.5*(m_b+m_a);
        double fc=f.eval(c);
        if(m_n>m_nmax) break;
        m_n++;
        if(sign.eval(fa)*sign.eval(fc)<0){
            m_b=c;
            fb=fc;
        }else if(sign.eval(fa)*sign.eval(fc)>0){
            m_a=c;
            fa=fc;
        }
    }
    return 0.5*(m_b+m_a);
}
bisezione::~bisezione(){
}

//SECANTI (può non convergere)
double secanti::cercazeri(double xmin, double xmax, double prec, int nmax, const funzione &f){
    m_a=xmin;
    m_b=xmax;
    double fa=f.eval(m_a);
    double fb=f.eval(m_b);
    double c=0.;
    for(int i=0; i<nmax; i++){
        if(fabs(fb-fa)<prec){
            throw runtime_error("Division by zero in secant method");            
        }
        c=m_b-fb*(m_b-m_a)/(fb-fa);
        if(fabs(c-m_b)<prec){
            return c;
        }
        m_a=m_b;
        fa=fb;
        m_b=c;
        fb=f.eval(m_b);
    }
    throw runtime_error("Secant method did not converge");
}
secanti::~secanti(){
}

//SECANTI+BISEZIONE (converge)
double secazione::cercazeri(double xmin, double xmax, double prec, int nmax, const funzione &f){
    m_a=xmin;
    m_b=xmax;
    double fa=f.eval(m_a);
    double fb=f.eval(m_b);
    if(fa*fb>0){
        throw runtime_error("Function values at the interval endpoints must have opposite signs");
    }
    double c=0.;
    for(unsigned int i=0; i<nmax; ++i){
        if(fabs(fb-fa)<prec){
            c=0.5*(m_a+m_b);
        }else{
            c=m_b-fb*(m_b-m_a)/(fb-fa);
        }
        if(fabs(f.eval(c))<prec || fabs(m_b-m_a)<prec){
            return c;
        }
        double fc=f.eval(c);
        if(fa*fc<0){
            m_b=c;
            fb=fc;
        }else{
            m_a=c;
            fa=fc;
        }
    }
    throw runtime_error("Convergence not reached within the maximum number of iterations");
}
secazione::~secazione(){
}

//NEWTON (può non convergere)
double newton::cercazeri_n(double xmin, double xmax, double prec, int nmax, const funzione &f, const funzione &g){
    double a=(xmin+xmax)/2.;
    double fa=f.eval(a);
    double dfa;
    for(unsigned int i=0; i<nmax; ++i){
        dfa=g.eval_der(a);
        if(fabs(dfa)<prec){
            throw runtime_error("Derivative is too small, division by zero risk");
        }
        double a_new=a-fa/dfa;
        if(fabs(a_new-a)<prec){
            return a_new;
        }
        a=a_new;
        fa=f.eval(a);
    }
    throw runtime_error("Newton-Raphson method did not converge");
}
newton::~newton(){
}

//NEWTON+BISEZIONE (converge)
double newtone::cercazeri_n(double xmin,double xmax,double prec,int nmax,const funzione &f,const funzione &g){
    double a=(xmin+xmax)/2.;
    double fa=f.eval(a);
    for(unsigned int i=0; i<nmax; ++i){
        double dfa=g.eval_der(a);
        if(fabs(dfa)<prec){
            double b=0.5*(xmin+xmax);
            double fb=f.eval(b);
            if(fa*fb<0){
                xmax=b;
            }else{
                xmin=b;
                fa=fb;
            }
            a=0.5*(xmin+xmax);
        }else{
            double a_new=a-fa/dfa;
            if(a_new<xmin || a_new>xmax){
                double b=0.5*(xmin+xmax);
                double fb=f.eval(b);
                if(fa*fb<0){
                    xmax=b;
                }else{
                    xmin=b;
                    fa=fb;
                }
                a=0.5*(xmin+xmax);
            }else{
                a=a_new;
                fa=f.eval(a);
            }
        }
        if(fabs(f.eval(a))<prec || fabs(xmax-xmin)<prec){
            return a;
        }
    }
    throw runtime_error("Convergence not reached within the maximum number of iterations");
}
newtone::~newtone(){
}

#endif