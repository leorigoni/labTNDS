#include"utilities.h"

int main(){
    int n=10000;
    condensatore e(1);
    scientific(cout);
    setprecision(3);

    /*vector<TH1F*> histoth=getth(n, e);
    vector<TH1F*> histodm=getdm(n, e);
    TH2F histodm12=getdm12(n, e);
    vector<TH1F*> histon=getn(n, e);
    TH2F histon12=getn12(n, e);
    vector<TH1F*> histtoab=gettab(n, e);
    TH2F histoab=getab(n, e);
    drawgraph(histoth, histodm, histodm12,
                       histon, histon12, histtoab, histoab);*/
    
    TH1F histo("Legenda", "Histo misure C", 100, 1.9, 2.1);
    double tot=0.;
    for(int i=0; i<n; i++){
        e.esegui();
        e.analizza();
        histo.Fill(e.getc_mis());
        tot+=e.getc_mis();
        cout << "Misura n. " << i+1 << ": " << e.getc_mis() << endl;
    }
    cout << "Media: " << tot/n << endl;
    TCanvas c;
    histo.Draw();
    c.SaveAs("histo.pdf");

    return 0;
}