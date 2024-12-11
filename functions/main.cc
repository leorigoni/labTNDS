#include<iostream>
#include<cmath>
#include<fstream>
#include<sstream>
#include<iomanip>
#include"functions.h"

using namespace std;

int main(){

    //file
    ifstream input;
    string infilename=openfile(input);
    int lines=linecount(input);
    int columns=columncount(input);
    mesure *mesures=new mesure[lines];
    copydata(input, mesures, lines);
    closefile(input);

    //computing
    sortup(mesures, lines);
    sortdown(mesures, lines);
    int max=findmax(mesures, lines);
    int min=findmin(mesures, lines);
    double mean=calcmean(mesures, lines);
    double stddevmean=calcstddevmean(mesures, lines, mean);
    int tottrue=findtottrue(mesures, lines);
    int totfalse=findtotfalse(mesures, lines);
    mesure *tmesures=new mesure[tottrue];
    mesure *fmesures=new mesure[totfalse];
    devidetruefalse(mesures, tmesures, fmesures, lines, tottrue, totfalse);

    //output
    ofstream output;
    outputfile(mesures, output, infilename, max, min, mean,
    stddevmean, tottrue, totfalse, lines, columns);

    //clean
    clean(mesures, tmesures, fmesures);

    //else
    int i=0;
    int expo=exp(i);
    
    return 0;
}