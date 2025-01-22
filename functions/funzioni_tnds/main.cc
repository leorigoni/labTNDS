#include"include.h"

int main(){

    string filename="out/"+to_string(i)+"out.txt"; //utile per stringhe

    //Root
    TGraph graph;
    TCanvas c(const char* name, const char* title, Int_t ww, Int_t wh);
    c.cd(Int_t padnumber);
    c.Divide(Int_t nx, Int_t ny, Float_t xmargin, Float_t ymargin, Int_t color);
    gPad->SetLogy();
    gPad->SetLogx();
    gPad->SetGridy();
    gPad->SetGridx();
    c.SetGridx();
    c.SetGridy();
    c.SetLogy();
    c.SetLogx();
    c.SetLogy();
    c.SetLogx();
    c.SetGridx();
    c.SetGridy();
    c.SetFillColor();
    c.SetFillColor(Int_t color);
    graph.SetMinimum(Double_t minimum);
    graph.SetMaximum(Double_t maximum);
    graph.SetMarkerSize(Double_t size);
    graph.SetMarkerStyle(Int_t style);
    graph.SetMarkerColor(String_t kColor);
    graph.SetFillColor(String_t kColor);
    graph.SetFillStyle(Int_t style);
    graph.SetLineWidth(Int_t width);
    graph.SetLineStyle(Int_t style);
    graph.SetLineColor(String_t kColor);
    graph.SetTitle("Graph Title");
    graph.GetXaxis()->SetNdivisions(510);
    graph.GetYaxis()->SetNdivisions(510);
    graph.GetXaxis()->SetTitle("X axis Title");
    graph.GetYaxis()->SetTitle("Y axis Title");
    graph.GetXaxis()->SetTitleOffset(Int_t offset);
    graph.GetYaxis()->SetTitleOffset(Int_t offset);
    graph.Draw("APL"); //A: axis, P:points, L:line
    graph.Draw("same");
    c.SaveAs("graph.pdf");

    //Form("Something %d", i): places i in the string where %d is placed

    return 0;
}