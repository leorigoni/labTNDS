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
    string filename;
    integrale *metodo;
    if(method=="media"){
        metodo=new media(0);
        filename="data_media.txt";
    }else if(method=="hitmiss"){
        metodo=new hitmiss(0);
        filename="data_hitmiss.txt";
    }else{
        cout << "Errore, metodo non integrato." << endl;
        return -1;
    }
    if(fs::exists(filename)){
        vector<double> dati=copiadati(filename);
        vector<TH1F*> histo=istogrammi(n, toth, dati);
        grafici(n, toth, histo, dati, method);
    }else{
        vector<double> dati=calcint(n, toth, tmp, a, b, metodo);
        creafile(dati, filename);
        vector<TH1F*> histo=istogrammi(n, toth, dati);
        grafici(n, toth, histo, dati, method);
    }
    return 0;
}
