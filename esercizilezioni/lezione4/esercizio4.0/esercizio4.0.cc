#include"funzioni.h"

int main(){
    
    //file
    TApplication app("app",0,0);
    TGraphErrors trend;
    int index {0};
    vector<double> v;
    for(int i=1941; i<2024; i++){
        string infilename="data/"+to_string(i)+".txt";
        v=read<double>(infilename.c_str());

        //computing        
        double mean=calcmedia<double>(v);
        double var=calcvarianza<double>(v, mean);
        double err=calcstddevmean<double>(v, mean);
        vector<double> vs=v;
        sortup<double>(vs);
        double med=calcmediana<double>(vs);

        //output
        string outfilename="out/"+to_string(i)+"out.txt";
        //outputfile<double>(outfilename, v, vs, mean, var, med);
        ofstream output;
        outputfile<double>(output, infilename, outfilename, v, vs, mean, var, med);
        trend.SetPoint(index, i, mean);
        trend.SetPointError(index , 0, err);
        index++;
    }

    //graph                                                                          
    TCanvas c("Temperature trend","Temperature trend");
    c.cd();
    c.SetGridx();
    c.SetGridy();
    c.SetFillColor(0);
    trend.SetMarkerSize(0.7);
    trend.SetMarkerStyle(40);
    trend.SetMarkerColor(kBlack);
    trend.SetFillColor(kRed -4);
    //trend.SetFillStyle(3018);
    trend.SetLineWidth(1);
    trend.SetTitle("Temperature trend");
    trend.GetXaxis()->SetNdivisions(510);
    trend.GetYaxis()->SetNdivisions(510);
    trend.GetXaxis()->SetTitle("Anno");
    trend.GetYaxis()->SetTitle("#Delta (#circ C)");
    trend.Draw("apl3");
    trend.Draw("pX");
    c.SaveAs("trend.pdf");
    cout << "Done." << endl;
    app.Run();

    return 0;
}