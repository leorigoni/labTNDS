#include"funzioni.h"

//file
informazioni preliminary(informazioni &info, int argc, char **argv){
    if (argc<4){
        cout << "Uso del programma: " << argv[0] << " <n_data> <infilename> <outfilename> " << endl;
    }
    info.ndata=atoi(argv[1]);
    info.infilename=argv[2];
    info.outfilename=argv[3];
    return info;
}
vettore read( int ndata,  char *infilename){
    ifstream input;
    input.open(infilename, ios::in);
    if(!input.is_open()){
        cout << endl;
        cout << "Apertura file non riuscita." << endl;
        input.clear();
    }
    vettore tmp(ndata);
    for(int i=0; i<tmp.getn(); i++){
        double mom=0;
        input >> mom;
        tmp.setcomponent(i, mom);
    }
    input.close();
    return tmp;
}


//computing
double calcmedia(vettore &v){
    double tot=0;
    for(int i=0; i<v.getn(); i++){ 
        tot+=v.getcomponent(i);
    }
    return tot/double(v.getn());
}
double calcvarianza(vettore &v, double mean){
    double sumsq=0;
    for(int i=0; i<v.getn(); i++){
        sumsq+=pow(v.getcomponent(i)-mean,2);
    }
    return sumsq/(v.getn()-1);
}
void sortup(vettore &vs){
    for(int i=0; i<vs.getn()-1; i++){
        for(int j=i+1; j<vs.getn(); j++){
            if(vs.getcomponent(i)>vs.getcomponent(j)){
                vs.scambia(i, j);
            }
        }
    }
}
double calcmediana(vettore &vs){
    int halfdata=0;
    double med=0;
    if(vs.getn()%2 == 0){
        halfdata=vs.getn()/2;
        med=((vs.getcomponent(halfdata)+vs.getcomponent(halfdata+1))/2);
    }else{
        halfdata=vs.getn()/2;
        med=vs.getcomponent(halfdata);
    }
    return med;
}

//output
string outputdata(informazioni &info, vettore &v, vettore &vs, 
                            double mean, double var, double med){
    stringstream output; //mettere meglio i dati
    output << "I dati analizzati provengono dal file: " << info.infilename << endl;
    output << "Sono stai analizzati i seguinti " << info.ndata << " valori." << endl;
    output << endl;
    output << setw(15) << "da file" << setw(15) << "ordinati" << endl;
    for(int i=0; i<info.ndata; i++){
        output << "n." << i+1 << setw(11) << fixed << setprecision(4) <<
                     v.getcomponent(i) << setw(15) << fixed << setprecision(4) << 
                     vs.getcomponent(i) << endl;
    }
    output << endl;
    output << "Dai dati sono state estrapolate le seguenti variabili." << endl;
    output << "Media: " << mean << endl;
    output << "Varianza: " << var << endl;
    output << "Mediana: " << med << endl;
    return output.str();
}
void outputfile(informazioni &info, vettore &v, vettore &vs, 
                        double mean, double var, double med){
    cout << endl;
    cout << outputdata(info, v, vs, mean, var, med);
    cout << endl;
                        }
void outputfile(ofstream &output, informazioni &info, vettore &v, vettore &vs, 
                        double mean, double var, double med){
    output.open(info.outfilename, ios::out);
    output << outputdata(info, v, vs, mean, var, med);
    output.close();
}

/*obsolete
void openfile(char *filename, ifstream &input){
    input.open(filename, ios::in);
    if(!input.is_open()){
        cout << endl;
        cout << "Apertura file non riuscita." << endl;
        input.clear();
    }
}
void copydata(istream &input, vettore &v){
    for(int i=0; i<v.getn(); i++){
        double tmp=0;
        input >> tmp;
        v.setcomponent(i, tmp);
    }
}
void closefile(ifstream &input){
    input.close();
}
*/