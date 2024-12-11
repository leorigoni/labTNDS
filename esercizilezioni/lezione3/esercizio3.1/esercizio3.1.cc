#include"funzioni.h"

int main(int argc, char **argv){

    //file
    informazioni info;
    info=preliminary(info, argc, argv);
    vector <double> v=read<double>(info.infilename);

    //computing
    double mean=calcmedia<double>(v);
    double var=calcvarianza<double>(v, mean);
    vector <double> vs=v;
    sortup<double>(vs);
    double med=calcmediana<double>(vs);

    //output
    outputfile<double>(info, v, vs, mean, var, med);
    ofstream output;
    outputfile<double>(output, info, v, vs, mean, var, med);

    return 0;
}