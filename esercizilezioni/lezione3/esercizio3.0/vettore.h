#ifndef __vettore_h__
#define __vettore_h__

//############################################################################
// DECLARATION
//############################################################################

#include <iostream>
#include<fstream>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdlib>

using namespace std;

//class
template <typename t> class vettore{
    public:

    vettore(); 
    vettore(int N);
    vettore(const vettore&);
    ~vettore();
    int getn() const{return m_N;}
    void setcomponent(int, t);
    t getcomponent(int) const;
    void scambia(int, int);

    private:

    int m_N;
    t* m_v;
};

//############################################################################
// IMPLEMENTATION
//############################################################################

//stuff
template <typename t> vettore<t>::vettore(){
    m_N=0;
    m_v=NULL;
}
template <typename t> vettore<t>::vettore(int N){
    if (N<0){
        cout << "Errore: la dimensione deve essere positiva " << endl;
        exit(4);
    }else{
        m_N=N;
        m_v=new t[N];
        for(int i=0; i<N; i++){
            m_v[i]=0;
        }
    }
}
template <typename t> vettore<t>::vettore(const vettore& v){
    m_N=v.getn();
    m_v=new t[m_N];
    for(int i=0; i<m_N; i++){
        m_v[i]=v.getcomponent(i);
    }
}
template <typename t> vettore<t>::~vettore(){
    delete[]m_v;
}

//actions
template <typename t> void vettore<t>::setcomponent(int i, t a){
    if(i<m_N){
        m_v[i]=a;
    }else{
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(1);
    }
}
template <typename t> t vettore<t>::getcomponent(int i) const{
    if(i<m_N ){
        return m_v[i];
    }else{
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(2);
    }
}
template <typename t> void  vettore<t>::scambia(int primo, int secondo){
    t tmp=getcomponent(primo);
    setcomponent(primo, getcomponent(secondo));
    setcomponent(secondo, tmp);
}

#endif