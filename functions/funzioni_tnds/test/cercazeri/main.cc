#include"cercazeri.h"

int main(){
    effe f;
    effeprimo g;
    bisezione b;
    secazione s;
    newtone n;
    double xmin=0.;
    double xmax=4.;
    double prec=0.000001;
    int nmax=1000000;

    fixed(cout);
    setprecision(6);

    auto start=chrono::high_resolution_clock::now();
    double zer_b=b.cercazeri(xmin, xmax, prec, nmax, f);
    auto end=chrono::high_resolution_clock::now();
    cout << "Bisezione: " << zer_b << " in " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " ms" << endl;
    auto start1=chrono::high_resolution_clock::now();
    double zer_s=s.cercazeri(xmin, xmax, prec, nmax, f);
    auto end1=chrono::high_resolution_clock::now();
    cout << "Secazione: " << zer_s << " in " << chrono::duration_cast<chrono::milliseconds>(end1-start1).count() << " ms" << endl;    
    auto start2=chrono::high_resolution_clock::now();
    double zer_n=n.cercazeri_n(xmin, xmax, prec, nmax, f, g);
    auto end2=chrono::high_resolution_clock::now();
    cout << "Newtone: " << zer_n << " in " << chrono::duration_cast<chrono::milliseconds>(end2-start2).count() << " ms" << endl;
    
    return 0;
}