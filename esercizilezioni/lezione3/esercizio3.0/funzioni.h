#ifndef __funzioni_h__
#define __funzioni_h__

#include"vettore.h"

//############################################################################
// DECLARATION
//############################################################################

//struct
struct informazioni{
    int ndata;
    char *infilename;
    char *outfilename;
};

//file
informazioni preliminary(informazioni &, int, char **);
template <typename t> vettore<t> read( int,  char*);


//computing
template <typename t> double calcmedia(vettore<t> &);
template <typename t> double calcvarianza(vettore<t> &, double mean);
template <typename t> void sortup(vettore<t> &);
template <typename t> double calcmediana(vettore<t> &);

//output
template <typename t> string outputdata(informazioni &, vettore<t> &, vettore<t> &, 
                                                                    double, double, double);
template <typename t> void outputfile(informazioni &, vettore<t> &, vettore<t> &, 
                                                                double, double, double);
template <typename t> void outputfile(ofstream &, informazioni &, vettore<t> &, vettore<t> &, 
                                                                double, double, double);

//############################################################################
// IMPLEMENTATION
//############################################################################

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
template <typename t> vettore<t> read( int ndata,  char *infilename){
    ifstream input;
    input.open(infilename, ios::in);
    if(!input.is_open()){
        cout << endl;
        cout << "Apertura file non riuscita." << endl;
        input.clear();
    }
    vettore<t> tmp(ndata);
    for(int i=0; i<tmp.getn(); i++){
        t mom=0;
        input >> mom;
        tmp.setcomponent(i, mom);
    }
    input.close();
    return tmp;
}

//computing
template <typename t> double calcmedia(vettore<t> &v){
    double tot=0;
    for(int i=0; i<v.getn(); i++){ 
        tot+=v.getcomponent(i);
    }
    return tot/double(v.getn());
}
template <typename t> double calcvarianza(vettore<t> &v, double mean){
    double sumsq=0;
    for(int i=0; i<v.getn(); i++){
        sumsq+=pow(v.getcomponent(i)-mean,2);
    }
    return sumsq/(v.getn()-1);
}
template <typename t> void sortup(vettore<t> &vs){
    for(int i=0; i<vs.getn()-1; i++){
        for(int j=i+1; j<vs.getn(); j++){
            if(vs.getcomponent(i)>vs.getcomponent(j)){
                vs.scambia(i, j);
            }
        }
    }
}
template <typename t> double calcmediana(vettore<t> &vs){
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
template <typename t> string outputdata(informazioni &info, vettore<t> &v, vettore<t> &vs, 
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
template <typename t> void outputfile(informazioni &info, vettore<t> &v, vettore<t> &vs, 
                                                                double mean, double var, double med){
    cout << endl;
    cout << outputdata(info, v, vs, mean, var, med);
    cout << endl;
}
template <typename t> void outputfile(ofstream &output, informazioni &info, vettore<t> &v, vettore<t> &vs, 
                                                                double mean, double var, double med){
    output.open(info.outfilename, ios::out);
    output << outputdata(info, v, vs, mean, var, med);
    output.close();
}

#endif