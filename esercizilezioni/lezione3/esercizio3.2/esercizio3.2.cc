#include"funzioni.h"

int main(int argc, char **argv){

    //file
    TApplication app("app",0,0);
    informazioni info;
    info=preliminary(info, argc, argv);
    vector <double> v=read<double>(info.infilename);

    //computing
    double mean=calcmedia<double>(v);
    double var=calcvarianza<double>(v, mean);
    vector <double> vs=v;
    sortup<double>(vs);
    double med=calcmediana<double>(vs);

    //output
    outputfile<double>(info, v, vs, mean, var, med);
    ofstream output;
    outputfile<double>(output, info, v, vs, mean, var, med);

    //histo
    TH1F histo("Legend","Histo", 100, -10, 10);
    histo.StatOverflows(kTRUE);
    for(int k=0; k<v.size(); k++){
        histo.Fill(v[k]);
    }
    TCanvas mycanvas("Histo","Histo");
    histo.Draw();
    histo.GetXaxis()->SetTitle("measures");
    histo.GetYaxis()->SetTitle("n.");
    app.Run();

    return 0;
}