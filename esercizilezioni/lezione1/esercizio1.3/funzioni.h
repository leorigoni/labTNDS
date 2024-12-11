#include<iostream>
#include<fstream>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdlib>

using namespace std;

//struct
struct informazioni{
    int ndata;
    char *infilename;
    char *outfilename;
};

//file
informazioni preliminary(informazioni &info, int argc, char **argv);
void openfile(char *filename, ifstream &input);
void copydata(istream &input, double *data, int ndata);
void closefile(ifstream &input);

//computing
double calcmedia(double *data, int ndata);
double calcvarianza(double *data, int ndata, double mean);
void duplarray(double *data, double *sortdata, int ndata);
void sortup(double *sortdata, int ndata);
double calcmediana(double *sortdata, int ndata);

//output
string outputdata(informazioni &info, double *data, double *sortdata, 
                            double mean, double var, double med);
void outputfile(informazioni &info, double *data, double *sortdata, 
                        double mean, double var, double med);
void outputfile(ofstream &output, informazioni &info, double *data, double *sortdata, 
                        double mean, double var, double med);

//clean
void clean(double *data, double *sortdata);