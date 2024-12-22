#include"differenziale.h"
#include"utilities.h"
#include"TAxis.h"
#include"TCanvas.h"
#include"TGraph.h"

int main(int argc, char **argv){
    double h=0.;
    double tempo=0.;
    if(argc>3||argc<2){
        cout << "Needed: " << argv[0] << " <stepsize> <time*> " << endl;
        cout << "*default time will be set to 70s if not given" << endl;
        return -1;
    }else if(argc==3){
        h=atof(argv[1]);
        tempo=atof(argv[2]);    
    }else{
        h=atof(argv[1]);
        tempo=300;
    }
    rugnekutta r;
    double omega0=10.;
    double omega=10.;
    double alpha=1./30.;
    int nstep=int(tempo/h+0.5);
    pendolo o(omega0, alpha, omega);
    TGraph grafico;
    double t=0.;
    vector<double> x{0., 0.};
    for(int i=0; i<nstep; i++){
        x=r.passo(t, x, h, o);
        grafico.SetPoint(i, t, x[0]);
        t=t+h;
    }
    TGraph amp;
    rugnekutta r2;
    int nstep2=50;
    for(int i=0; i<nstep2; i++){
        double omega2=0.9*omega0+(0.2*omega0/nstep2)*(i+1);
        pendolo o2(omega0, alpha, omega2);
        double t2=0.;
        vector<double> x2{0., 0.};
        double max=0.;
        while(t2<tempo){
            x2=r2.passo(t2, x2, h, o2);
            t2=t2+h;
            if(fabs(x2[0])>max){
                max=fabs(x2[0]);
            }
        }
        amp.SetPoint(i, omega2, max);
    }
    TCanvas c("grafico", "grafico", 1500, 800);
    c.cd();
    c.Divide(2, 1);
    string title1="Pendolo smorzato-forzato (Rugne-Kutta h=" + convert(h) + ")";
    grafico.SetTitle(title1.c_str());
    grafico.GetYaxis()->SetTitle("Ampiezza [rad]");
    grafico.GetXaxis()->SetTitle("Tempo [s]");
    grafico.GetYaxis()->SetTitleOffset(1);
    grafico.SetLineColor(kRed);
    grafico.SetMarkerSize(0.1);
    grafico.SetMarkerStyle(20);
    grafico.SetMarkerColor(kBlack);
    c.cd(1);
    gPad->SetGridy();
    gPad->SetGridx();
    grafico.Draw("APC");
    string title2="Risonanza";
    amp.SetTitle(title2.c_str());
    amp.GetYaxis()->SetTitle("Ampiezza [rad]");
    amp.GetXaxis()->SetTitle("Omega [rad/s]");
    amp.GetYaxis()->SetTitleOffset(1);
    amp.SetLineColor(kRed);
    amp.SetMarkerSize(0.5);
    amp.SetMarkerStyle(20);
    amp.SetMarkerColor(kBlack);
    c.cd(2);
    gPad->SetGridy();
    gPad->SetGridx();
    amp.Draw("APC");
    c.SaveAs("grafico.pdf");
    return 0;
}