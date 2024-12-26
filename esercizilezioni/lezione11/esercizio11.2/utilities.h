#include"integrale.h"
#include"TGraph.h"
#include"TApplication.h"
#include"TCanvas.h"
#include"TAxis.h"
#include"TLine.h"
#include"TH1F.h"

vector<double> calcint(int n, int toth, int tmp, double a, double b){
    vector<double> dati;
    for(int i=0; i<toth; i++){
        xsinx f;
        media m(0);
        for(int j=0; j<n; j++){
            dati.push_back(m.integra(tmp*5, a, b, f));
            cout << i+1 << "." << j << ": "<< m.integra(tmp*5, a, b, f) << endl;
        }
        tmp=tmp*5;
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
    for (int i=0; i<toth; i++){
        histo.push_back(new TH1F(Form("Legenda %d", i+1), Form("Integrale (N: %d)", tmp*5), 100, 0.5, 1.5));
        tmp=tmp*5;
    }
    for(int i=0; i<toth; i++){
        for(int j=n*i; j<n*(i+1); j++){
            histo[i]->Fill(dati[j]);
        }
    }
    return histo;
}
void grafici(int n, int toth, vector<TH1F*> histo, vector<double> &dati){
    TCanvas c("Integrale (xsin(x))", "Integrale (xsin(x))");
    c.cd();
    c.Divide(4, 2);
    for(int i=0; i<toth; i++){
        c.cd(i+1);
        histo[i]->GetXaxis()->SetTitle("Integrale");
        histo[i]->GetYaxis()->SetTitle("N");
        histo[i]->Draw();                
    }
    TGraph err;
    c.cd(8);
    for(int i=0; i<(toth-1); i++){
        int tmp=20;
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
        err.SetPoint(i, i, stddev);
    }
    err.Draw("APL");
    c.SaveAs("Integrale.pdf");
}