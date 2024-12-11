#ifndef __funzioni_h__
#define __funzioni_h__

#include"vettore.h"

//struct
struct informazioni{
    int ndata;
    char *infilename;
    char *outfilename;
};

//file
informazioni preliminary(informazioni &, int, char **);
vettore read( int,  char*);


//computing
double calcmedia(vettore &);
double calcvarianza(vettore &, double mean);
void sortup(vettore &);
double calcmediana(vettore &);

//output
string outputdata(informazioni &, vettore &, vettore &, 
                            double, double, double);
void outputfile(informazioni &, vettore &, vettore &, 
                        double, double, double);
void outputfile(ofstream &, informazioni &, vettore &, vettore &, 
                        double, double, double);

/*obsolete
void openfile(char *filename, ifstream &);
void copydata(istream &, vettore &);
void closefile(ifstream &);
*/

#endif