#include"solutore.h"

int main(int argc, char** argv){
    if(argc<6 || argc>7){
        cout << "Neded by " << argv[0] << ": <a> <b> <c> <xmin> <xmax> {<prec>}" << endl;
        cout << "{not necessary}" <<  endl; 
        exit(-1);
    }
    if(argc==7){
        bisezione bisettore;
        parabola f(atof(argv[1]), atof(argv[2]), atof(argv[3]));
        cout << bisettore.cercazeri(atof(argv[4]), atof(argv[5]), f, atof(argv[6])) << endl;
    }else{
        bisezione bisettore;
        parabola f(atof(argv[1]), atof(argv[2]), atof(argv[3]));
        cout << bisettore.cercazeri(atof(argv[4]), atof(argv[5]), f, 0.001) << endl;
    }
    return 0;
}