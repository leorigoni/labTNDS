#include"funzioni.h"

int main(int argc, char **argv){

    //file
    informazioni info;
    info=preliminary(info, argc, argv);
    vettore v=read(info.ndata , info.infilename);


    //computing
    double mean=calcmedia(v);
    double var=calcvarianza(v, mean);
    vettore vs=v;
    sortup(vs);
    double med=calcmediana(vs);

    //output
    outputfile(info, v, vs, mean, var, med);
    ofstream output;
    outputfile(output, info, v, vs, mean, var, med);

    /*obsolete
    ifstream input;
    openfile(info.infilename, input);
    copydata(input, v);
    closefile(input);
    */

    return 0;
}