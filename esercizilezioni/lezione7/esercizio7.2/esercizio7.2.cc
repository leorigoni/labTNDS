#include"integrale.h"

int main(int argc, char** argv){
    if(argc!=2){
        cout << "Neded by " << argv[0] << ": <prec> " << endl;
        exit(-1);
    }
    double inizio=0.0;
    double fine=M_PI/2.0;
    double prec=atof(argv[1]);
    xsinx f;
    trapezi i;
    cout << "L'integrale è: "<<  i.integra(inizio, fine, f, prec) << ", risolto con una precisione di " << i.geterr() << " in un totale di " << i.getnstep() << " step." << endl;
}