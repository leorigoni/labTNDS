#include"eulero.h"
#include"utilities.h"
#include"TApplication.h"
#include"TAxis.h"
#include"TCanvas.h"
#include"TGraph.h"

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
    oscillatorearmonico o(1.0);
    vector<double> x{0.0,1.0};
    double t=0.0;
    TGraph grafico;
    nstep=int(tmax/h+0.5);
    for(int i=0; i<nstep; i++){
        grafico.SetPoint(i, t, x[0]);
        x=e.passo(t, x, h, o);
        t=t+h;
    }
    TGraph errore;
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
        errore.SetPoint(i, h, err);
    }
    TCanvas c("grafico", "grafico", 1500, 800);
    c.cd();
    c.Divide(2, 1);
    string title1="Oscillatore armonico (Eulero h=" + convert(h) + ")";
    grafico.SetTitle(title1.c_str());
    grafico.GetXaxis()->SetTitle("Tempo [s]");
    grafico.GetYaxis()->SetTitle("Posizione x [m]");
    grafico.GetYaxis()->SetTitleOffset(1);
    grafico.SetLineColor(kRed);
    c.cd(1);
    gPad->SetGridy();
    gPad->SetGridx();
    grafico.Draw("AL");
    string title2="Errore sulla misura";
    errore.SetTitle(title2.c_str());
    errore.GetXaxis()->SetTitle("Passo di integrazione h [s]");
    errore.GetYaxis()->SetTitle("Errore [m]");
    errore.GetYaxis()->SetTitleOffset(1);
    errore.SetMarkerStyle(20);
    errore.SetMarkerSize(1);
    errore.SetMarkerColor(kBlack);
    errore.SetLineColor(kRed);
    c.cd(2);
    gPad->SetLogy();
    gPad->SetLogx();
    gPad->SetGridy();
    gPad->SetGridx();
    errore.Draw("APL");
    c.SaveAs("grafico.pdf");
}