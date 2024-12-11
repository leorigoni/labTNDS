#include"campovettoriale.h"
#include"puntomateriale.h"
#include<cstdlib>
#include<string>
#include"TApplication.h"
#include"TGraph.h"
#include"TCanvas.h"
#include"TAxis.h"
#include"TLine.h"

string fieldtype(double a){
    string type;
    if(a==0){
        type="Costante";
    }if(a>0){
        type="Cresce con R";
    }if(-1.5<a && a<0){
        type="Decresce con R";
    }if(-2.5<a && a<=-1.5){
        type="Decresce come R^2";
    }if(-3.5<a && a<=-2.5){
        type="Decresce Logaritmicamente"; 
    }if(a<=-3.5){
        type="Decresce più velocemente";
    }
    return type;
}

int main(int argc, char** argv){

    //input
    TApplication app("app",0,0);
    if(argc!=4){
        cout << "Neded: " << argv[0] << " <x> <y> <z>" << endl;
        exit(-1);
    }
    const double e=1.60217653E-19;
    const double me=9.1093826E-31;
    const double mp=1.6726219E-27;  
    const double d=1.E-10;
    posizione p(atof(argv[1]), atof(argv[2]), atof(argv[3]));

    //computing
    puntomateriale elettrone(me, -e, 0, 0, d/2);
    puntomateriale protone(mp, e, 0, 0, -d/2);
    campovettoriale ev=elettrone.campoelettrico(p)+protone.campoelettrico(p);

    //output
    cout << "E=(" << ev.getfx() << ", " << ev.getfy() << ", " << ev.getfz() << ")" << endl;
        //outputgrafico
        TGraph field;
        posizione p0(0, 0, 0);
        double e1=0;
        double e2=0;
        for(int i=100; i<=10000; i++){
            p0.setz(i*d);
            campovettoriale ef=elettrone.campoelettrico(p0)+protone.campoelettrico(p0);
            if(i==100){
                e1=ef.modulo();
            }
            if(i==1000){
                e2=ef.modulo();
            }
            field.SetPoint(i-100, i*d, ef.modulo());
        }
        double alpha=log(e1/e2)/log((100*d)/(1000*d));
        TCanvas c("Electric Field","Electric Field");
        c.cd();
        c.SetLogy();
        c.SetGridx();
        c.SetGridy();
        c.SetFillColor(0);
        field.SetLineWidth(1);
        field.SetTitle("Electric Field");
        field.GetXaxis()->SetNdivisions(510);
        field.GetYaxis()->SetNdivisions(510);
        field.GetXaxis()->SetTitle("Distance (m)");
        field.GetYaxis()->SetTitle("Field Module (N/C)");
        field.Draw("APL");
        c.SaveAs("Electric Field.pdf");
        string type=fieldtype(alpha);
        cout << "Alfa= " << alpha << " Tipo: " << type << endl;
        cout << "Done." << endl;
        app.Run();

    return 0;
}