#include"cercazeri.h"
#include"integrazione.h"
#include"montecarlo.h"

template <typename t> double stddev(vector<t> &a){
    t sum=0;
    for(int i=0; i<a.size(); i++){
        sum+=a[i];
    }
    double mean=sum/a.size();
    double sumsq=0;
    for(int i=0; i<a.size(); i++){
        sumsq+=pow(a[i]-mean,2);
    }
    double stddev=sqrt(sumsq/(a.size()));
    return stddev;
}

int main(){
    cout << endl;

    //Punto 1)
    effe f;
    bisezione b(0.001);
    double x1=b.cercazeri(1, 2, 0.001, 1000, f);
    int nstep_x1=b.getn();
    double x2=b.cercazeri(4, 5, 0.001, 1000, f);
    int nstep_x2=b.getn();
    double x3=b.cercazeri(7, 8, 0.001, 1000, f);
    int nstep_x3=b.getn();
    cout << "Punto 1)" << endl;
    cout << endl;
    cout << "Valore di x1: " << setprecision(4) << x1 << endl;
    cout << "trovato in n. " << nstep_x1 << " steps." << endl;
    cout << "Valore di x2: " << setprecision(4) << x2 << endl;
    cout << "trovato in n. " << nstep_x2 << " steps." << endl;
    cout << "Valore di x3: " << setprecision(4) << x3 << endl;
    cout << "trovato in n. " << nstep_x3 << " steps." << endl;
    cout << endl;

    //Punto 2)
    trapezi t;
    int n=4;
    double integrale_x1x2=t.integra_step(x1, x2, n, f);
    cout << "Punto 2)" << endl;
    cout << endl;
    cout << "Valore dell'integrale della funzione sull'intervallo [" << setprecision(4) << x1 << "; " << x2 <<  "]: " << integrale_x1x2 << endl;
    cout << "calcolato con N=" << n << " steps." << endl;
    cout << endl;

    //Punto 3)
    double epsilon1=4/3*fabs(t.integra_step(x1, x2, n, f)-t.integra_step(x1, x2, n*2, f));
    cout << "Punto 3)" << endl;
    cout << endl;
    cout << "Valore stimato dell'errore dell'integrale della funzione sull'intervallo [" << setprecision(4) << x1 << "; " << x2 <<  "]: " << epsilon1 << endl;
    cout << "calcolato con N=" << n << " steps." << endl;
    cout << endl;

    //Punto 4)
    int N=10000;
    randomgen rgen(1);
    vector<double> integrali_x1x2;
    double x1tmp=0.;
    double x2tmp=0.;
    double tmp=0.;
    for(int i=0; i<N; i++){
        x1tmp=rgen.unif(x1-0.001/2, x1+0.001/2);
        x2tmp=rgen.unif(x2-0.001/2, x2+0.001/2);
        tmp=t.integra_prec(x1tmp, x2tmp, 0.0001, f);
        integrali_x1x2.push_back(tmp);
    }
    double epsilon2=stddev<double>(integrali_x1x2);
    cout << "Punto 4)" << endl;
    cout << endl;
    cout << "Valore stimato dell'errore dell'integrale della funzione sull'intervallo [" << setprecision(4) << x1 << "; " << x2 <<  "]: " << epsilon2 << endl;
    cout << "calcolato con sigma di " << 0.001/2 << " e un totale di n." << N << " ripetizioni." << endl;
    cout << endl;

    //Punto 5)
    double useless=t.integra_prec(x1, x2, epsilon2, f);
    int nstep=t.getnstep();
    cout << "Punto 5)" << endl;
    cout << endl;
    cout << "Numero di passi per trovare il valore dell'integrale con un precisione di " << epsilon2 << ": " << nstep << endl;
    cout << endl;

    //Punto 6)
    double passo=0.1;
    int totstep=fabs(x1-x3)/passo;
    vector<double> integrale_x1x3;
    double tmp1=0.;
    for(int i=0; i<totstep; i++){
        tmp1=t.integra_step(x1, x1+(passo*i), 4, f);
        integrale_x1x3.push_back(tmp1); 
    }
    cout << "Punto 6)" << endl;
    cout << endl;
    cout << "Tabulati relativi all'andamento dell'integrale della funzione sull'intervallo [" << setprecision(4) << x1 << "; " << x3 <<  "], con step di  " << passo << "." << endl;
    cout << endl;
    cout << "Delta_t" << setw(15) << "Valore_int" << endl;
    cout << "=======================" << endl;
    for(int i=0; i<totstep; i++){
        cout << setprecision(5) << setw(4) << x1+(passo*i) << setw(15) << integrale_x1x3[i] << endl;
    }
    cout << "=======================" << endl;
    cout << endl;

    return 0;
}