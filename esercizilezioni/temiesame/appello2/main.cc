#include"differenziali.h"

int main(){
    double h=0.1;
    double t=0.0;
    double tmax=43.;
    int nstep;
    rungekutta r;
    oscillatorearmonico o(1.15, 0.01);
    vector<double> x{1.0,0.0};
    TGraph grafico;
    nstep=int(tmax/h);
    for(int i=0; i<nstep; i++){
        grafico.SetPoint(i, t, x[0]);
        x=r.passo(t, x, h, o);
        t=t+h;
    }
    TCanvas c("grafico", "grafico", 1500, 1600);
    c.cd();
    string title1="Oscillatore armonico (Eulero h=" + convert(h) + ")";
    grafico.SetTitle(title1.c_str());
    grafico.GetXaxis()->SetTitle("Tempo [s]");
    grafico.GetYaxis()->SetTitle("Posizione x [m]");
    grafico.GetYaxis()->SetTitleOffset(1);
    grafico.SetLineColor(kRed);
    gPad->SetGridy();
    gPad->SetGridx();
    grafico.Draw("AL");
    c.SaveAs("grafico.pdf");
    cout << "Posizione finale con passo " << h << " al tempo " << tmax << ": " << x[0] << endl;
    cout << endl;
    double h1=0.05;
    double t1=0.0;
    double tmax1=43.;
    int nstep1;
    rungekutta r1;
    oscillatorearmonico o1(1.15, 0.01);
    vector<double> x1{1.0,0.0};
    nstep1=int(tmax1/h1);
    for(int i=0; i<nstep1; i++){
        x1=r1.passo(t1, x1, h1, o1);
        t1=t1+h1;
    }
    cout << "Posizione finale con passo " << h1 << " al tempo " << tmax1 << ": " << x1[0] << endl;
    cout << endl;
    cout << "Errore commesso con passo " << h << ": " << abs(x[0]-x1[0]) << endl;
    cout << endl;
    double h2=0.2;
    double t2=0.0;
    double tmax2=43.;
    int nstep2;
    double tmp=0.;
    rungekutta r2;
    oscillatorearmonico o2(1.15, 0.01);
    vector<double> x2{1.0,0.0};
    do{
        x2={1.0, 0.0};
        t2=0.0;
        nstep2=int(tmax2/h2);
        for(int i=0; i<nstep2; i++){
            x2=r2.passo(t2, x2, h2, o2);
            t2+=h2;
        }
        if(fabs(x2[0]-x1[0])<5e-05){
            break;
        }
        h2=h2-0.00001;
    }while(true);
    cout << "Passo minimo per ottenere un errore inferiore a 5e-05: " << h2 << endl;

   return 0; 
}