#include"differenziale.h"
#include"utilities.h"
#include"TAxis.h"
#include"TCanvas.h"
#include"TGraph.h"

int main(int argc, char **argv){
    double h, tmax, l;
    int nstep;
    if(argc>4||argc<2){
        cout << "Needed: " << argv[0] << " <stepsize> <time*> <length**>" << endl;
        cout << "*default time will be set to 70s if not given" << endl;
        cout << "**default length will be set to 1m if not given" << endl;
        return -1;
    }else if(argc==4){
        h=atof(argv[1]);
        tmax=atof(argv[2]);    
        l=atof(argv[3]);
    }else{
        h=atof(argv[1]);
        tmax=70;
        l=1;
    }

    rugnekutta r;
    pendolo o(l);
    TGraph grafico;
    for(int i=0; i<31; i++){
        double a=0.1*(i+1);
        double v=0.0;
        double t=0.0;
        vector<double> x{-a, v};
        while(x[1]>=0.0){
            v=x[1];    
            x=r.passo(t, x, h, o);
            t+=h;
            cout << a << " " << x[0] << " " << t << endl;
            if(x[1]<0.0){
            //t+=-v*h/(x[1]-v);
            t=((t-h)*(x[1])+t*(-v))/(x[1]-v);
            }
        }
        double period=2*t;
        grafico.SetPoint(i, a, period);
    }
    for(double i=31; i<31.415; i+=0.001){
        double a=0.1*(i+0.001);
        double v=0.0;
        double t=0.0;
        vector<double> x{-a, v};
        while(x[1]>=0.0){
            v=x[1];    
            x=r.passo(t, x, h, o);
            t+=h;
            cout << a << " " << x[0] << " " << t << endl;
            if(x[1]<0.0){
            //t+=-v*h/(x[1]-v);
            t=((t-h)*(x[1])+t*(-v))/(x[1]-v);
            }
        }
        double period=2*t;
        grafico.SetPoint(i, a, period);
    }
    TCanvas c("grafico", "grafico");
    string title1="Pendolo (Rugne-Kutta h=" + convert(h) + ")";
    grafico.SetTitle(title1.c_str());
    grafico.GetYaxis()->SetTitle("Periodo [s]");
    grafico.GetXaxis()->SetTitle("Ampiezza [rad]");
    grafico.GetYaxis()->SetTitleOffset(1);
    grafico.SetLineColor(kRed);
    grafico.SetMarkerSize(0.7);
    grafico.SetMarkerStyle(20);
    grafico.SetMarkerColor(kBlack);
    gPad->SetGridy();
    gPad->SetGridx();
    grafico.Draw("APC");
    c.SaveAs("grafico_rugnekutta.pdf");
}