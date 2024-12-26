#include<iostream>
#include<filesystem>
#include"utilities.h"
using namespace std;
namespace fs=std::filesystem;
int main(){
    int tmp=20;
    int toth=7;
    int n=10000;
    double a=0.;
    double b=M_PI/2;
    string filename="data.txt";
    if(fs::exists(filename)){
        vector<double> dati=copiadati(filename);
        vector<TH1F*> histo=istogrammi(n, toth, dati);
        grafici(n, toth, histo, dati);
    }else{
        vector<double> dati=calcint(n, toth, tmp, a, b);
        creafile(dati, filename);
        vector<TH1F*> histo=istogrammi(n, toth, dati);
        grafici(n, toth, histo, dati);
    }
    return 0;
}
