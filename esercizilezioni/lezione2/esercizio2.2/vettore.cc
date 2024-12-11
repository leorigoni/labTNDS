#include "vettore.h"

//stuff
vettore::vettore(){
    m_N=0;
    m_v=NULL;
}
vettore::vettore(int N){
    if (N<0){
        cout << "Errore: la dimensione deve essere positiva " << endl;
        exit(4);
    }else{
        m_N=N;
        m_v=new double[N];
        for(int i=0; i<N; i++){
            m_v[i]=0;
        }
    }
}
vettore::vettore(const vettore& v){
    m_N=v.getn();
    m_v=new double[m_N];
    for(int i=0; i<m_N; i++){
        m_v[i]=v.getcomponent(i);
    }
}
vettore::~vettore(){
    delete[]m_v;
}

//actions
void vettore::setcomponent(int i, double a){
    if(i<m_N){
        m_v[i]=a;
    }else{
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(1);
    }
}
double vettore::getcomponent(int i) const{
    if(i<m_N ){
        return m_v[i];
    }else{
        cout << "Errore: indice " << i << ", dimensione " << m_N << endl;
        exit(2);
    }
}
void vettore::scambia(int primo, int secondo){
    double tmp=getcomponent(primo);
    setcomponent(primo, getcomponent(secondo));
    setcomponent(secondo, tmp);
}