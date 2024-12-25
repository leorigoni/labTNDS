#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"
#include "randomgen.h" 

int main(){
    Randomgen r(1);
    int nmax=1000000;
    vector<TH1F*> u;
    TGraph var;
    for(int i=0; i<12; i++){
        TString name=Form("legenda %d", i+1);
        TString title=Form("Uniforme %d", i+1);
        u.push_back(new TH1F(name, title, 70, 0, i+1));
    }
    for(int i=0; i<12; i++){
        u[i]->SetMinimum(0);
        //double totsum=0;
        //double totsumsq=0;
        //int tot=0;
        for(int k=0; k<nmax; k+=i+1){
            double sum=0;
            for(int j=1; j<=i+1; j++){
                sum+=r.unif(0, 1);
            }
            //tot++;
            //totsum+=sum;
            //double mean=totsum/nmax;
            //totsumsq+=pow(sum-mean, 2);
            u[i]->Fill(sum);
        }
        //var.SetPoint(i, i+1, totsumsq/(tot-1));
    }
    TCanvas c("randomgen", "randomgen");
    c.cd();
    c.Divide(3, 4);
    for(int i=0; i<12; i++){
        c.cd(i+1);
        u[i]->GetXaxis()->SetTitle("x [AU]");
        u[i]->GetYaxis()->SetTitle("N");
        u[i]->Draw();                
    }
    c.SaveAs("random.pdf");
    for(int i=0; i<12; i++){
        double stddev=u[i]->GetStdDev();
        double varianza=pow(stddev, 2);
        var.SetPoint(i, i+1, varianza);
    }
    TCanvas c1("c_varianza", "Grafico Varianza", 800, 600);
    c1.SetGrid();
    var.SetTitle("Varianza per ogni istogramma");
    var.GetXaxis()->SetTitle("Indice Istogramma");
    var.GetYaxis()->SetTitle("Varianza");
    var.SetMarkerColor(kBlack);
    var.SetMarkerSize(1.2);
    var.SetMarkerStyle(20);
    var.SetLineColor(kRed);
    var.SetLineWidth(1);
    var.Draw("APL");
    c1.SaveAs("varianza.pdf");
    return 0;
}