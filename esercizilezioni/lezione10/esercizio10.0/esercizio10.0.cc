#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "randomgen.h" 

int main(){
    Randomgen r(1);
    int nmax=10000;
    TH1F u("uniforme", "uniforme", 70, -10, 10);
    TH1F e("esponenziale", "esponenziale", 70, 0, 10);
    TH1F gbm("gaussiana b-m", "gaussiana b-m", 70, -10, 10);
    TH1F gar("gaussiana a-r", "gaussiana a-r", 70, -10, 10);
    for(int k=0; k<nmax; k++){
        u.Fill(r.unif(-4, 2));
        e.Fill(r.exp(4));
        gbm.Fill(r.gausbm(0, 2));
        gar.Fill(r.gausar(1, 1, -10, 10));
    }
    TCanvas c("randomgen", "randomgen");
    c.cd();
    c.Divide(2, 2);
    c.cd(1);
    u.GetXaxis()->SetTitle("x [AU]");
    u.GetYaxis()->SetTitle("N");
    u.Draw();
    c.cd(2);
    e.GetXaxis()->SetTitle("x [AU]");
    e.GetYaxis()->SetTitle("N");
    e.Draw();
    c.cd(3);
    gbm.GetXaxis()->SetTitle("x [AU]");
    gbm.GetYaxis()->SetTitle("N");
    gbm.Draw();
    c.cd(4);
    gar.GetXaxis()->SetTitle("x [AU]");
    gar.GetYaxis()->SetTitle("N");
    gar.Draw();
    c.SaveAs("random.pdf");
}
