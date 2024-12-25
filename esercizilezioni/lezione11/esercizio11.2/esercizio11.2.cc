#include<iostream>
#include<filesystem>
#include"integrale.h"
using namespace std;
namespace fs=std::filesystem;
int main(){
    string filename="data.txt";
    double a=0.;
    double b=M_PI/2;
    if(fs::exists(filename)){
        //aprire il file e caricare i dati
        //fare il grafico con i dati
    }else{
        vector<double> dati;
        int tmp=20;
        for(int i=0; i<1; i++){
            xsinx f;
            media m(0);
            for(int j=0; j<tmp*5; j++){
                dati.push_back(m.integra(tmp*5, a, b, f));
            }
            tmp=tmp*5;
        }
        ofstream data;
        data.open(filename, ios::out);
        for(int i=0; i<dati.size(); i++){
            data << dati[i];
            data << endl;
        }
        data.close();
        vector<TH1F*> histo;
        int mom=20;
        for(int i=0; i<1; i++){
            for(int j=0; j<mom*5; j++){
                histo[i]->Fill(dati[j]);
            }
            mom=mom*5;
        }
    }
    return 0;
}
