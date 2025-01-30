#include"integrale.h"

//ciao sofi

int main(int argc, char** argv){
    if(argc!=2){
        cout << "Neded by " << argv[0] << ": <nstep> " << endl;
        exit(-1);
    }
    double inizio=0;
    double fine=M_PI/2;
    int nstep=atof(argv[1]);
    xsinx f;
    simpson s;
    double integrale=s.integra(inizio, fine, f, nstep); 
    cout << "L'integrale è: "<<  integrale << ", risolto con " << nstep << " step e una precisone di " << fabs(1.0-integrale) << "." << endl;
    TGraph g_errore;
    nstep=4;
    double ivero=1.0, err=0, h=0;
    for(unsigned int k=0; k<20; k++){
        h=(fine-inizio)/nstep; 
        err=fabs(s.integra(inizio, fine, f, nstep)-ivero);
        g_errore.SetPoint(k, h, err);
        nstep*=2;
    }
    /*double tmp=0;
    for(int i=1; i<=nstep; i++){
        double h=(fine-inizio)/i; 
        double tmp=s.integra(inizio, fine, f, i); 
        double err=fabs(integrale-tmp);
        g_errore.SetPoint(i-1, h, err);
    }*/
    TCanvas c("Error","Error");
    c.cd();
    c.SetLogy();
    c.SetLogx();
    c.SetGridx();
    c.SetGridy();
    c.SetFillColor(0);
    g_errore.SetMinimum(1e-16);
    g_errore.SetMaximum(1.0);
    g_errore.SetLineColor(kRed);
    g_errore.SetLineWidth(2);
    g_errore.SetLineStyle(1); 
    g_errore.SetMarkerStyle(20);
    g_errore.SetMarkerSize(0.7);
    g_errore.SetMarkerColor(kBlack);
    g_errore.SetTitle("Precisione dell'errore al passo h");
    g_errore.GetXaxis()->SetNdivisions(510);
    g_errore.GetYaxis()->SetNdivisions(510);
    g_errore.GetXaxis()->SetTitle("h");
    g_errore.GetYaxis()->SetTitle("error");
    g_errore.Draw("APL");
    c.SaveAs("grafico.pdf");
    return 0;
}