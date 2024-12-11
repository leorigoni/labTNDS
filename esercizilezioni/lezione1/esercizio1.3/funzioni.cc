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
void openfile(char *filename, ifstream &input){
    input.open(filename, ios::in);
    if(!input.is_open()){
        cout << endl;
        cout << "Apertura file non riuscita." << endl;
        input.clear();
    }
}
void copydata(istream &input, double *data, int ndata){
    for(int i=0; i<ndata; i++){
        input >> data[i];
    }
}
void closefile(ifstream &input){
    input.close();
}

//computing
double calcmedia(double *data, int ndata){
    double sum=0;
    for(int i=0; i<ndata; i++){
        sum+=data[i];
    }
    double mean=sum/ndata;
    return mean;
}
double calcvarianza(double *data, int ndata, double mean){
    double sumsq=0;
    for(int i=0; i<ndata; i++){
        sumsq+=pow(data[i]-mean,2);
    }
    double var=sumsq/(ndata-1);
    return var;
}
void duplarray(double *data, double * sortdata, int ndata){
    for(int i=0; i<ndata; i++){
        sortdata[i]=data[i];
    }
}
void sortup(double *sortdata, int ndata){
    for(int i=0; i<ndata-1; i++){
        for(int j=i+1; j<ndata; j++){
            if(sortdata[i]>sortdata[j]){
                double tmp=sortdata[i];
                sortdata[i]=sortdata[j];
                sortdata[j]=tmp;
            }
        }
    }
}
double calcmediana(double *sortdata, int ndata){
    int halfdata=0;
    double med=0;
    if(ndata%2 == 0){
        halfdata=ndata/2;
        med=((sortdata[halfdata]+sortdata[halfdata+1])/2);
    }else{
        halfdata=ndata/2;
        med=sortdata[halfdata];
    }
    return med;
}

//output
string outputdata(informazioni &info, double *data, double *sortdata, 
                            double mean, double var, double med){
    stringstream output; //mettere meglio i dati
    output << "I dati analizzati provengono dal file: " << info.infilename << endl;
    output << "Sono stai analizzati i seguinti " << info.ndata << " valori." << endl;
    output << endl;
    output << setw(15) << "da file" << setw(15) << "ordinati" << endl;
    for(int i=0; i<info.ndata; i++){
        output << "n." << i+1 << setw(11) << fixed << setprecision(4) <<
                     data[i] << setw(15) << fixed << setprecision(4) << sortdata[i] << endl;
    }
    output << endl;
    output << "Dai dati sono state estrapolate le seguenti variabili." << endl;
    output << "Media: " << mean << endl;
    output << "Varianza: " << var << endl;
    output << "Mediana: " << med << endl;
    return output.str();
}
void outputfile(informazioni &info, double *data, double *sortdata, 
                        double mean, double var, double med){
    cout << endl;
    cout << outputdata(info, data, sortdata, mean, var, med);
    cout << endl;
                        }
void outputfile(ofstream &output, informazioni &info, double *data, double *sortdata, 
                        double mean, double var, double med){
    output.open(info.outfilename, ios::out);
    output << outputdata(info, data, sortdata, mean, var, med);
    output.close();
}

//clean
void clean(double *data, double *sortdata){
    delete[]data;
}