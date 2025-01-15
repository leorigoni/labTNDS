#include"include.h"

int main(){

    string filename="out/"+to_string(i)+"out.txt"; //utile per stringhe

    //Root
    TGraph graph;
    TCanvas c(const char* name, const char* title, Int_t ww, Int_t wh);
    c.cd(Int_t padnumber);
    c.Divide(Int_t nx, Int_t ny, Float_t xmargin, Float_t ymargin, Int_t color);
    c.SetGridx();
    c.SetGridy();
    c.SetFillColor();
    graph.SetMarkerSize(0.7);
    graph.SetMarkerStyle(40);
    graph.SetMarkerColor(kBlack);
    graph.SetFillColor(kRed -4);
    graph.SetFillStyle(3018);
    graph.SetLineWidth(1);
    graph.SetTitle("Temperature graph");
    graph.GetXaxis()->SetNdivisions(510);
    graph.GetYaxis()->SetNdivisions(510);
    graph.GetXaxis()->SetTitle("Anno");
    graph.GetYaxis()->SetTitle("#Delta (#circ C)");
    graph.Draw("apl3");
    graph.Draw("pX");
    c.SaveAs("graph.pdf");

    return 0;
}