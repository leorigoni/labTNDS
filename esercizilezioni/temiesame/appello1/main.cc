#include"integrazione.h"

int main(){
    effe f;
    midpoint m;
    double inizio=0.;
    double fine=sqrt(M_E);
    double vv=3./16.*pow(M_E, 2);
    int nstep=2;

    cout << "Valore vero: " << vv << endl;
    cout << endl;
    cout << "Punto 1)" << endl;
    cout << endl;
    cout << "Valore integrale Midpoint: " << m.integra_step(inizio, fine, 1024, f) << endl;
    cout << "===================================" << endl;
    double integrale=0.;
    double err=0.;
    int index=1;
    double h=0.;
    do{
        integrale=m.integra_step(inizio, fine, nstep, f);
        err=fabs(integrale-vv);
        h=m.geth();
        cout << setw(4)<< nstep << setw(15) << h << setw(15) << err << endl;
        index++;
        nstep*=2;
    }while(nstep<=1024);
    cout << "===================================" << endl;
    cout << endl;
    cout << "Punto 2)" << endl;
    cout << endl;
    double err1=fabs(m.integra_step(inizio, fine, 256, f)-vv);
    double h1=m.geth();
    double err2=fabs(m.integra_step(inizio, fine, 512, f)-vv);
    double h2=m.geth();
    double k2=log(err1/err2)/log(h1/h2);
    double k1=err1/pow(h1, k2);
    cout << "midpoint --> err=" << k1 << "*h^" << k2 << endl;
    cout << endl;
    return 0;
}