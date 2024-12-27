#include<iostream>
#include<filesystem>
#include"utilities.h"
using namespace std;
namespace fs=std::filesystem;
int main(int argc, char **argv){
    if(argc<2){
        cout << "Needed by " << argv[0] << ": <media/hitmiss>" << endl;
        return -1; 
    }
    string method=argv[1];
    int tmp=20;
    int toth=7;
    int n=10000;
    double a=0.;
    double b=M_PI/2;    
    if(method=="media"){
        string filename="data_media.txt";
        if(fs::exists(filename)){
            vector<double> dati=copiadati(filename);
            vector<TH1F*> histo=istogrammi(n, toth, dati);
            grafici(n, toth, histo, dati, method);
        }else{
            vector<double> dati=calcint(n, toth, tmp, a, b, method);
            creafile(dati, filename);
            vector<TH1F*> histo=istogrammi(n, toth, dati);
            grafici(n, toth, histo, dati, method);
        }
    }else if(method=="hitmiss"){
        string filename="hitmiss_hitmiss.txt";
        if(fs::exists(filename)){
            vector<double> dati=copiadati(filename);
            vector<TH1F*> histo=istogrammi(n, toth, dati);
            grafici(n, toth, histo, dati, method);
        }else{
            vector<double> dati=calcint(n, toth, tmp, a, b, method);
            creafile(dati, filename);
            vector<TH1F*> histo=istogrammi(n, toth, dati);
            grafici(n, toth, histo, dati, method);
        }
    }else{
        cout << "Errore, metodo non integrato." << endl;
        return -1;
    }
    return 0;
}
