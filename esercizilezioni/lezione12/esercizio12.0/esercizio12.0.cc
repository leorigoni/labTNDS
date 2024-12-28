#include"utilities.h"

int main(){
    int n=10000;
    esperimentoprisma e(1);
    vector<TH1F*> histoth=getth(n, e);
    vector<TH1F*> histodm=getdm(n, e);
    TH2F histodm12=getdm12(n, e);
    vector<TH1F*> histon=getn(n, e);
    TH2F histon12=getn12(n, e);
    vector<TH1F*> histtoab=gettab(n, e);
    TH2F histoab=getab(n, e);
    drawgraph(histoth, histodm, histodm12,
                       histon, histon12, histtoab, histoab);
    return 0;
}