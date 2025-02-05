#include"utilities.h"

int main(){
    int n=10000;
    esperimentoprisma e(1);
    esperimento esp;

    /*doppiohisto histodm12;
    doppiohisto histon12; work in progress...
    doppiohisto histoab;*/

    for(int i=0; i<n; i++){
        e.esegui();
        e.analizza();
        esp.th0mis.push_back(e.getth0mis());
        esp.th1mis.push_back(e.getth1mis());
        esp.th2mis.push_back(e.getth2mis());
        esp.dm1mis.push_back(e.getdm1mis());
        esp.dm2mis.push_back(e.getdm2mis());
        esp.dm1input.push_back(e.getdm1input());
        esp.dm2input.push_back(e.getdm2input());
        esp.n1mis.push_back(e.getn1mis());
        esp.n2mis.push_back(e.getn2mis());
        esp.n1input.push_back(e.getn1input());
        esp.n2input.push_back(e.getn2input());
        esp.amis.push_back(e.getamis());
        esp.ainput.push_back(e.getainput());
        esp.bmis.push_back(e.getbmis());
        esp.binput.push_back(e.getbinput());
    }
    cout << scientific << setprecision(3);
    vector<TH1F*> histoth=getth(n, esp);
    vector<TH1F*> histodm=getdm(n, esp);
    TH2F histodm12=getdm12(n, esp);
    vector<TH1F*> histon=getn(n, esp);
    TH2F histon12=getn12(n, esp);
    vector<TH1F*> histtoab=gettab(n, esp);
    TH2F histoab=getab(n, esp);
    drawgraph(histoth, histodm, histodm12,
                       histon, histon12, histtoab, histoab);
    return 0;
}