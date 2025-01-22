/*
Test function: y=sin(x)+1
Test interval: [0; 1000]
Integer: 1000,43762
Precision: 0.0000001
Number of steps: 10000000

Simpson (step): 1000,437621 in 270 ms
Simpson (prec): 1000.437621 in 2 ms
Trapezi (step): 1000.437621 in 224 ms
Trapezi (prec): 1000.437621 in 97 ms
Midpoint (step): 1000.437621 in 228 ms
Midpoint (prec): 1000.437621 in 60 ms
Midright (step): 1000.929833 in 219 ms
Midright (prec): 1000.929839 in 23787 ms
Midleft (step): 1000.437580 in 215 ms
Midleft (prec): "correct" in "to long to compute" ms
*/
#ifndef __integrazione_h__
#define __integrazione_h__
#include"include.h" //cstdlib, cmath, iostream, iomanip
#include"funzione.h" //funzione

//#################
//# DECLARATION #
//#################

class integrale{
    public:
    virtual ~integrale();
    virtual double integra_step(double, double, int, const funzione &){
        cout << "Error, this function is not implemented" << endl;
        exit(-1);
    };
    virtual double integra_prec(double, double, double, const funzione &){
        cout << "Error, this function is not implemented" << endl;
        exit(-1);
    };
    virtual double integra_step_comp(double, double, int, int, const funzione &){
        cout << "Error, this function is not implemented" << endl;
        exit(-1);
    }; //non incluso, uguale al metodo non comp solo che l'intervallo viene divisio in sotto intervalli nei quali poi viene applicato il relativo metodo
    virtual double integra_prec_comp(double, double, double, int, const funzione &){
        cout << "Error, this function is not implemented" << endl;
        exit(-1);
    }; //non incluso, uguale al metodo non comp solo che l'intervallo viene divisio in sotto intervalli nei quali poi viene applicato il relativo metodo
    double geth() const{return m_h;};
    double getprec() const{return m_prec;};
    double geterr() const{return m_err;};
    int getnstep() const{return m_nstep;};
    int getnintervals() const{return m_nintervals;};

    protected:
    void checkintervallo(double a, double b){
        m_inizio=min(a,b);
        m_fine=max(a,b);
        if(a>b){m_sign=-1;}
        else{m_sign=1;}
    }
    double m_inizio, m_fine, m_sum, m_integrale, m_h, m_prec, m_err;
    int m_sign, m_nstep, m_nintervals;
};

//SIMPSON
class simpson: public integrale{
    public:
    ~simpson();
    double integra_step(double, double, int, const funzione &) override;
    double integra_prec(double, double, double, const funzione &) override;
};

//TRAPEZI (MEDIA ???)
class trapezi: public integrale{
    public:
    ~trapezi();
    double integra_step(double, double, int, const funzione &) override;
    double integra_prec(double, double, double, const funzione &) override;
};

//MIDPOINT
class midpoint: public integrale{
    public:
    ~midpoint();
    double integra_step(double, double, int, const funzione &) override;
    double integra_prec(double, double, double, const funzione &) override;
};

//MIDRIGHT
class midright: public integrale{
    public:
    ~midright();
    double integra_step(double, double, int, const funzione &) override;
    double integra_prec(double, double, double, const funzione &) override;
};

//MIDLEFT
class midleft: public integrale{
    public:
    ~midleft();
    double integra_step(double, double, int, const funzione &) override;
    double integra_prec(double, double, double, const funzione &) override;
};

//#####################
//# IMPLEMENTATION #
//#####################

integrale::~integrale(){
}

//SIMPSON
double simpson::integra_step(double inizio, double fine, int nstep, const funzione &f){
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
double simpson::integra_prec(double inizio, double fine, double prec, const funzione &f){
    checkintervallo(inizio, fine);
    m_prec=prec;
    m_nstep=2;
    double tmp=0.;
    do{
        m_sum=0.;
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
        m_err=fabs(m_integrale-tmp);
        if(m_err<=prec){
            break;
        }
        tmp=m_integrale;
        m_nstep*=2;
    }while(true);
    return m_integrale;
}
simpson::~simpson(){
}

//TRAPEZI (MEDIA ???)
double trapezi::integra_step(double inizio, double fine, int nstep, const funzione &f){
    checkintervallo(inizio, fine);
    m_nstep=nstep;
    double m_integrale=0.0;
    m_sum=0.0;
    double step=(m_fine-m_inizio)/m_nstep;
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
    return m_integrale;
}
double trapezi::integra_prec(double inizio, double fine, double prec, const funzione &f){
    checkintervallo(inizio, fine);
    m_nstep=2;
    double tmp=0.0;
    double m_integrale=0.0;
    do{
        m_sum=0.0;
        double step=(m_fine-m_inizio)/m_nstep;
        m_h=(m_fine-m_inizio)/m_nstep;
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
double midpoint::integra_step(double inizio, double fine, int nstep, const funzione &f){
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
    m_integrale=m_sign*m_sum*m_h;
    return m_integrale;
}
double midpoint::integra_prec(double inizio, double fine, double prec, const funzione &f){
    checkintervallo(inizio, fine);
    m_prec=prec;
    m_nstep=2;
    double tmp=0.;
    do{
        m_h=(m_fine-m_inizio)/m_nstep;
        m_sum=0.;
        for(unsigned int i=0; i<m_nstep; i++){
            m_sum+=f.eval(m_inizio+(i+0.5)*m_h);
        }
        m_integrale=m_sign*m_sum*m_h;
        m_err=fabs(m_integrale-tmp);
        if(m_err<=prec){
            break;
        }
        tmp=m_integrale;
        m_nstep*=2;
    }while(true);
    return m_integrale;
}
midpoint::~midpoint(){
}

//MIDRIGHT
double midright::integra_step(double inizio, double fine, int nstep, const funzione &f){
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
    m_integrale=m_sign*m_sum*m_h;
    return m_integrale;
}
double midright::integra_prec(double inizio, double fine, double prec, const funzione &f){
    checkintervallo(inizio, fine);
    m_prec=prec;
    m_nstep=2;
    double tmp=0.;
    do{
        m_h=(m_fine-m_inizio)/m_nstep;
        m_sum=0.;
        for(unsigned int i=0; i<m_nstep; i++){
            m_sum+=f.eval(m_fine+(i*m_h));
        }
        m_integrale=m_sign*m_sum*m_h;
        m_err=fabs(m_integrale-tmp);
        if(m_err<=prec){
            break;
        }
        tmp=m_integrale;
        m_nstep*=2;
    }while(true);
    return m_integrale;
}
midright::~midright(){
}

//MIDLEFT
double midleft::integra_step(double inizio, double fine, int nstep, const funzione &f){
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
    m_integrale=m_sign*m_sum*m_h;
    return m_integrale;
}
double midleft::integra_prec(double inizio, double fine, double prec, const funzione &f){
    checkintervallo(inizio, fine);
    m_prec=prec;
    m_nstep=2;
    double tmp=0.;
    do{
        m_h=(m_fine-m_inizio)/m_nstep;
        m_sum=0.;
        for(unsigned int i=0; i<m_nstep; i++){
            m_sum+=f.eval(m_inizio+(i*m_h));
        }
        m_integrale=m_sign*m_sum*m_h;
        m_err=fabs(m_integrale-tmp);
        if(m_err<=prec){
            break;
        }
        tmp=m_integrale;
        m_nstep*=2;
    }while(true);
    return m_integrale;
}
midleft::~midleft(){
}

#endif