#include"solutore.h"

int main(int argc, char** argv){
    if(argc<5 || argc>8){
        cout << "Neded by " << argv[0] << ": <a> <b> <xmin> <xmax> {<c> <d> <prec>}" << endl;
        cout << "{not necessary}" <<  endl; 
        exit(-1);
    }
    if(argc==8){
        bisezione bisettore;
        tangente f(atof(argv[1]), atof(argv[2]), atof(argv[5]), atof(argv[6]));
        for(int i=1; i<=20; i++){
            cout << bisettore.cercazeri(atof(argv[3]), atof(argv[4]), f, atof(argv[7])) << "+" << i*M_PI << endl;
        }
    }else{
        bisezione bisettore;
        tangente f(atof(argv[1]), atof(argv[2]), 0, 0);
        for(int i=1; i<=20; i++){
            cout << bisettore.cercazeri(atof(argv[3]), atof(argv[4]), f, 10e-16) << "+" << i*M_PI << endl;
        }
    }
    return 0;
}