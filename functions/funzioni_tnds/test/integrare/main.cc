#include"integra.h"

int main(){
    xsinx f;
    simpson s;
    trapezi t;
    midpoint m;
    midright mr;
    midleft ml;
    double inizio=0.;
    double fine=1000.;
    double prec=0.001;
    int nstep=10;

    fixed(cout);
    setprecision(6);

    auto start=chrono::high_resolution_clock::now();
    double int_ss=s.integra_step(inizio, fine, nstep, f);
    auto end=chrono::high_resolution_clock::now();
    cout << "Simpson (step): " << int_ss << " in " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " ms" << endl;
    auto start1=chrono::high_resolution_clock::now();
    double int_sp=s.integra_prec(inizio, fine, prec, f);
    auto end1=chrono::high_resolution_clock::now();
    cout << "Simpson (prec): " << int_sp << " in " << chrono::duration_cast<chrono::milliseconds>(end1-start1).count() << " ms" << endl;
    
    auto start2=chrono::high_resolution_clock::now();
    double int_ts=t.integra_step(inizio, fine, nstep, f);
    auto end2=chrono::high_resolution_clock::now();
    cout << "Trapezi (step): " << int_ts << " in " << chrono::duration_cast<chrono::milliseconds>(end2-start2).count() << " ms" << endl;
    auto start3=chrono::high_resolution_clock::now();
    double int_tp=t.integra_prec(inizio, fine, prec, f);
    auto end3=chrono::high_resolution_clock::now();
    cout << "Trapezi (prec): " << int_tp << " in " << chrono::duration_cast<chrono::milliseconds>(end3-start3).count() << " ms" << endl;
    
    auto start4=chrono::high_resolution_clock::now();
    double int_ms=m.integra_step(inizio, fine, nstep, f);
    auto end4=chrono::high_resolution_clock::now();
    cout << "Midpoint (step): " << int_ms << " in " << chrono::duration_cast<chrono::milliseconds>(end4-start4).count() << " ms" << endl;
    auto start5=chrono::high_resolution_clock::now();
    double int_mp=m.integra_prec(inizio, fine, prec, f);
    auto end5=chrono::high_resolution_clock::now();
    cout << "Midpoint (prec): " << int_mp << " in " << chrono::duration_cast<chrono::milliseconds>(end5-start5).count() << " ms" << endl;

    auto start6=chrono::high_resolution_clock::now();
    double int_mrs=mr.integra_step(inizio, fine, nstep, f);
    auto end6=chrono::high_resolution_clock::now();
    cout << "Midright (step): " << int_mrs << " in " << chrono::duration_cast<chrono::milliseconds>(end6-start6).count() << " ms" << endl;
    auto start7=chrono::high_resolution_clock::now();
    double int_mrp=mr.integra_prec(inizio, fine, prec, f);
    auto end7=chrono::high_resolution_clock::now();
    cout << "Midright (prec): " << int_mrp << " in " << chrono::duration_cast<chrono::milliseconds>(end7-start7).count() << " ms" << endl;
    
    auto start8=chrono::high_resolution_clock::now();
    double int_mls=ml.integra_step(inizio, fine, nstep, f);
    auto end8=chrono::high_resolution_clock::now();
    cout << "Midleft (step): " << int_mls << " in " << chrono::duration_cast<chrono::milliseconds>(end8-start8).count() << " ms" << endl;
    auto start9=chrono::high_resolution_clock::now();
    double int_mlp=ml.integra_prec(inizio, fine, prec, f);
    auto end9=chrono::high_resolution_clock::now();
    cout << "Midleft (prec): " << int_mlp << " in " << chrono::duration_cast<chrono::milliseconds>(end9-start9).count() << " ms" << endl;
    
    return 0;
}