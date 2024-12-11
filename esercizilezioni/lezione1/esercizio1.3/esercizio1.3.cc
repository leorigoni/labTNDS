#include"funzioni.h"

int main(int argc, char **argv){

    //file
    ifstream input;
    informazioni info;
    info=preliminary(info, argc, argv);
    double *data=new double[info.ndata];
    openfile(info.infilename, input);
    copydata(input, data, info.ndata);
    closefile(input);

    //computing
    double mean=calcmedia(data, info.ndata);
    double var=calcvarianza(data, info.ndata, mean);
    double *sortdata=new double[info.ndata];
    duplarray(data, sortdata, info.ndata);
    sortup(sortdata, info.ndata);
    double med=calcmediana(sortdata, info.ndata);

    //output
    outputfile(info, data, sortdata, mean, var, med);
    ofstream output;
    outputfile(output, info, data, sortdata, mean, var, med);

    //clean
    clean(data, sortdata);

    return 0;
}