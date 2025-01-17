#ifndef __integralee_h__
#define __integralee_h__
#include"include.h" //cstdlib, cmath, iostream, iomanip
#include"funzione.h" //funzione

//#################
//# DECLARATION #
//#################

class integrale{
    public:
    virtual ~integrale();
    virtual double integra(double, double,
                                        const funzione &,
                                        int)=0;

    protected:
    void checkintervallo(double a, double b){
        m_inizio=min(a,b);
        m_fine=max(a,b);
        if(a>b){m_sign=-1;}
        else{m_sign=1;}
    }
    double m_inizio, m_fine, m_sum, m_integrale, m_h, m_prec, m_err;
    int m_sign, m_nstep;
};

//SIMPSON
class simpson: public integrale{
    public:
    ~simpson();
    double integra(double, double,
                                        const funzione &,
                                        int) override;
    double geth() const{return m_h;}
    int getnstep() const{return m_nstep;}
};

//TRAPEZI (MEDIA ???)
class trapezi: public integrale{
    public:
    ~trapezi();
    double integra(double, double,
                            const funzione &,
                            double) override;
    int getnstep() const{return m_nstep;}
    double geterr() const{return m_err;}
};

//MIDPOINT
class midpoint: public integrale{
    public:
    ~midpoint();
    double integra(double, double, 
                            unsigned int, 
                            const funzione &) override;
    int getnstep() const{return m_nstep;}
};

//MIDRIGHT
class midright: public integrale{
    public:
    ~midright();
    double integra(double, double, 
                            unsigned int, 
                            const funzione &) override;
    int getnstep() const{return m_nstep;}
};

//MIDLEFT
class midleft: public integrale{
    public:
    ~midleft();
    double integra(double, double, 
                            unsigned int, 
                            const funzione &) override;
    int getnstep() const{return m_nstep;}
};

//#####################
//# IMPLEMENTATION #
//#####################

integrale::~integrale(){
}

//SIMPSON
double simpson::integra(double inizio, double fine, const funzione &f, int nstep){
    checkintervallo(inizio, fine);
    m_nstep=nstep;
    if(m_nstep%2!=0){
        m_nstep++;
    }
    m_sum=0.0;
    m_h=(m_fine-m_inizio)/m_nstep;
    for(int i=0; i<=m_nstep; ++i){
        double x=m_inizio+i*m_h;
        if(i==0 || i==m_nstep){
            m_sum+=f.eval(x);
        }else if(i%2==0){
            m_sum+=2*f.eval(x);
        }else{
            m_sum+=4*f.eval(x);
        }
    }
    m_integrale=(m_h/3.0)*m_sum*m_sign;
    return m_integrale;
}
simpson::~simpson(){
}

//TRAPEZI (MEDIA ???)
double trapezi::integra(double inizio, double fine, const funzione &f, double prec){
    checkintervallo(inizio, fine);
    m_nstep=2;
    double tmp=0.0;
    double m_integrale=0.0;
    do{
        m_sum=0.0;
        double step=(fine-inizio)/m_nstep;
        m_h=(fine-inizio)/m_nstep;
        for(int i=0; i<=m_nstep; i++){
            double x=inizio+i*step;
            if(i==0||i==m_nstep){
                m_sum+=0.5*f.eval(x);
            }else{
                m_sum+=f.eval(x);
            }
        }
        m_integrale=m_h*m_sum*m_sign;
        m_err=(4.0/3.0)*fabs(m_integrale-tmp);
        if(m_err<=prec){
            break;
        }
        tmp=m_integrale;
        m_nstep*=2;
    }while(true);
    return m_integrale;
}
trapezi::~trapezi(){
}

//MIDPOINT
double midpoint::integra(double inizio, double fine, unsigned int nstep, const funzione &f){
    checkintervallo(inizio, fine);
    if(nstep<=0){
        cout << "Error, number of steps is negative" << endl;
        exit(-1);
    }
    m_nstep=nstep;
    m_h=(m_fine-m_inizio)/m_nstep;
    m_sum=0.;
    for(unsigned int i=0; i<m_nstep; i++){
        m_sum+=f.eval(m_inizio+(i+0.5)*m_h);
    }
    m_integral=m_sign*m_sum*m_h;
    return m_integral;
}
midpoint::~midpoint(){
}

//MIDRIGHT
double midright::integra(double inizio, double fine, unsigned int nstep, const funzione &f){
    checkintervallo(inizio, fine);
    if(nstep<=0){
        cout << "Error, number of steps is negative" << endl;
        exit(-1);
    }
    m_nstep=nstep;
    m_h=(m_fine-m_inizio)/m_nstep;
    m_sum=0.;
    for(unsigned int i=0; i<m_nstep; i++){
        m_sum+=f.eval(m_fine+(i*m_h));
    }
    m_integral=m_sign*m_sum*m_h;
    return m_integral;
}
midright::~midright(){
}

//MIDLEFT
double midleft::integra(double inizio, double fine, unsigned int nstep, const funzione &f){
    checkintervallo(inizio, fine);
    if(nstep<=0){
        cout << "Error, number of steps is negative" << endl;
        exit(-1);
    }
    m_nstep=nstep;
    m_h=(m_fine-m_inizio)/m_nstep;
    m_sum=0.;
    for(unsigned int i=0; i<m_nstep; i++){
        m_sum+=f.eval(m_inizio+(i*m_h));
    }
    m_integral=m_sign*m_sum*m_h;
    return m_integral;
}
midleft::~midleft(){
}

#endif