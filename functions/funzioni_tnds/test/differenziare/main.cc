#include"differenziali.h"

int main(int argc, char **argv){
    double h, tmax;
    int nstep;
    if(argc>3||argc<2){
        cout << "Needed: " << argv[0] << " <stepsize> <time*>" << endl;
        cout << "*default time will be set to 70s if not given" << endl;
        return -1;
    }else if(argc==3){
        h=atof(argv[1]);
        tmax=atof(argv[2]);       
    }else{
        h=atof(argv[1]);
        tmax=70;
    }
    TApplication app("app", 0, 0);
    eulero e;
    rungekutta r;
    oscillatorearmonico o(1.0);
    vector<double> x{0.0,1.0};
    double t=0.0;
    TGraph grafico_e;
    nstep=int(tmax/h+0.5);
    for(int i=0; i<nstep; i++){
        grafico_e.SetPoint(i, t, x[0]);
        x=e.passo(t, x, h, o);
        t=t+h;
    }
    TGraph errore_e;
    double vv=sin(tmax);
    for(int i=0; i<10; i++){
        double h=0.1*pow(0.5, i);
        vector<double> x{0.0, 1.0};
        t=0.0;
        int step=int(tmax/h+0.5);
        for(int k=0; k<step; k++){
            x=e.passo(t, x, h, o);
            t=t+h;
        }
        double err=fabs(x[0]-vv);
        errore_e.SetPoint(i, h, err);
    }
    oscillatorearmonico u(1.0);
    vector<double> y{0.0,1.0};
    double tt=0.0;
    TGraph grafico_r;
    nstep=int(tmax/h+0.5);
    for(int i=0; i<nstep; i++){
        grafico_r.SetPoint(i, tt, y[0]);
        y=r.passo(tt, y, h, u);
        tt=tt+h;
    }
    TGraph errore_r;
    for(int i=0; i<10; i++){
        double h=0.1*pow(0.5, i);
        vector<double> y{0.0, 1.0};
        tt=0.0;
        int step=int(tmax/h+0.5);
        for(int k=0; k<step; k++){
            y=r.passo(tt, y, h, u);
            tt=tt+h;
        }
        double err=fabs(y[0]-vv);
        errore_r.SetPoint(i, h, err);
    }
    TCanvas c("grafico", "grafico", 1500, 1600);
    c.cd();
    c.Divide(2, 2);
    c.cd(1);
    string title1="Oscillatore armonico (Eulero h=" + convert(h) + ")";
    grafico_e.SetTitle(title1.c_str());
    grafico_e.GetXaxis()->SetTitle("Tempo [s]");
    grafico_e.GetYaxis()->SetTitle("Posizione x [m]");
    grafico_e.GetYaxis()->SetTitleOffset(1);
    grafico_e.SetLineColor(kRed);
    gPad->SetGridy();
    gPad->SetGridx();
    grafico_e.Draw("AL");
    c.cd(2);
    string title2="Errore sulla misura";
    errore_e.SetTitle(title2.c_str());
    errore_e.GetXaxis()->SetTitle("Passo di integrazione h [s]");
    errore_e.GetYaxis()->SetTitle("Errore [m]");
    errore_e.GetYaxis()->SetTitleOffset(1);
    errore_e.SetMarkerStyle(20);
    errore_e.SetMarkerSize(1);
    errore_e.SetMarkerColor(kBlack);
    errore_e.SetLineColor(kRed);
    gPad->SetLogy();
    gPad->SetLogx();
    gPad->SetGridy();
    gPad->SetGridx();
    errore_e.Draw("APL");
    c.cd(3);
    string title3="Oscillatore armonico (Runge-Kutta h=" + convert(h) + ")";
    grafico_r.SetTitle(title3.c_str());
    grafico_r.GetXaxis()->SetTitle("Tempo [s]");
    grafico_r.GetYaxis()->SetTitle("Posizione x [m]");
    grafico_r.GetYaxis()->SetTitleOffset(1);
    grafico_r.SetLineColor(kRed);
    gPad->SetGridy();
    gPad->SetGridx();
    grafico_r.Draw("AL");
    c.cd(4);
    string title4="Errore sulla misura";
    errore_r.SetTitle(title4.c_str());
    errore_r.GetXaxis()->SetTitle("Passo di integrazione h [s]");
    errore_r.GetYaxis()->SetTitle("Errore [m]");
    errore_r.GetYaxis()->SetTitleOffset(1);
    errore_r.SetMarkerStyle(20);
    errore_r.SetMarkerSize(1);
    errore_r.SetMarkerColor(kBlack);
    errore_r.SetLineColor(kRed);
    gPad->SetLogy();
    gPad->SetLogx();
    gPad->SetGridy();
    gPad->SetGridx();
    errore_r.Draw("APL");

    c.SaveAs("grafico.pdf");
}