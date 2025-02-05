#include"integrale.h"
#include"TGraph.h"
#include"TApplication.h"
#include"TCanvas.h"
#include"TAxis.h"
#include"TLine.h"
#include"TH1F.h"

double findymax(double a, double b, const funzione &f){
    double ymax=numeric_limits<double>::lowest();
    double tmp=0.;
    for(double i=a; i<b; i+=0.0001){
        tmp=f.eval(i);
        if(tmp>ymax){
            ymax=tmp;
        }
    }
    return ymax;
}
double findmaxfirst(vector<double> &dati, int toth){
    double max=numeric_limits<double>::lowest();
    for(int i=0; i<static_cast<int>(dati.size()/toth); i++){
        if(dati[i]>max){
            max=dati[i];
        }
    }
    return max;
}
double findminfirst(vector<double> &dati, int toth){
    double min=numeric_limits<double>::max();
    for(int i=0; i<static_cast<int>(dati.size()/toth); i++){
        if(dati[i]<min){
            min=dati[i];
        }
    }
    return min;
}
vector<double> calcint(int n, int toth, int tmp, double a, double b, integrale *m){
    double inizio=min(a, b);
    double fine=max(a, b);
    int sgn;
    if(a<b){
        sgn=1;
    }else{
        sgn=-1;
    }
    vector<double> dati;
    xsinx f;
    double ymax=findymax(inizio, fine, f);
    double tmpint;
    for(int i=0; i<toth; i++){
        tmp=tmp*5;
        for(int j=0; j<n; j++){
            tmpint=m->integra(tmp, inizio, fine, f, ymax, sgn);
            dati.push_back(tmpint);
            cout << i+1 << "." << j << ": "<< tmpint << endl;
        }
    }    
    return dati;
}
void creafile(vector<double> &dati, string filename){
    ofstream data;
    data.open(filename, ios::out);
    for(int i=0; i<dati.size(); i++){
        data << dati[i];
        data << endl;
    }
    data.close();
}
vector<double> copiadati(string filename){
    ifstream data;
    vector<double> dati;
    data.open(filename, ios::in);
    double mom=0.;
    while(data >> mom){
        dati.push_back(mom);
    }
    data.close();
    return dati;
}
vector<TH1F*> istogrammi(int n, int toth, vector<double> &dati){
    int tmp=20;
    vector<TH1F*> histo;
    double max=findmaxfirst(dati, toth);
    double min=findminfirst(dati, toth);
    for (int i=0; i<toth; i++){
        histo.push_back(new TH1F(Form("Legenda %d", i+1), Form("Integrale (N: %d)", tmp*5), 100, min, max));
        tmp=tmp*5;
    }
    for(int i=0; i<toth; i++){
        for(int j=n*i; j<n*(i+1); j++){
            histo[i]->Fill(dati[j]);
        }
    }
    return histo;
}
void grafici(int n, int toth, vector<TH1F*> histo, vector<double> &dati, string method){
    TCanvas c("Integrale (xsin(x))", "Integrale (xsin(x))");
    c.cd();
    c.Divide(4, 2);
    for(int i=0; i<toth; i++){
        c.cd(i+1);
        histo[i]->GetYaxis()->SetTitleOffset(1);
        histo[i]->GetXaxis()->SetTitle("Integrale");
        histo[i]->GetYaxis()->SetTitle("N");
        histo[i]->Draw();                
    }
    TGraph err;
    c.cd(8);
    gPad->SetLogy();
    gPad->SetLogx();
    gPad->SetGridy();
    gPad->SetGridx();
    int tmp=100;
    for(int i=0; i<toth; i++){
        for(int k=tmp; k<tmp*5; k+=tmp*5){
        double mean=0.;
        double sum=0.;
        for(int t=n*i; t<n*(i+1); t++){
            sum+=dati[t];
        }
        mean=sum/n;
        double totsum=0.;
        for(int t=n*i; t<n*(i+1); t++){
            totsum+=pow(dati[t]-mean, 2);
        }
        double stddev=sqrt(totsum/n);
        err.SetPoint(i, k, stddev);
        }
        tmp=tmp*5;
    }
    err.GetYaxis()->SetTitleOffset(1);
    err.SetTitle("Errore su ogni Integrale");
    err.GetXaxis()->SetTitle("N");
    err.GetYaxis()->SetTitle("Errore");
    err.SetMarkerColor(kBlack);
    err.SetMarkerSize(0.4);
    err.SetMarkerStyle(20);
    err.SetLineColor(kRed);
    err.SetLineWidth(1);
    err.Draw("APL");
    stringstream nomepdf;
    nomepdf << "Integrale_" << method << ".pdf";
    c.SaveAs(nomepdf.str().c_str());
}