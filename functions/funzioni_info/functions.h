#include<iostream>
#include<cmath>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;

//struct
struct mesure{
    int m1;
    double m2;
    string m3;
    char m4;
    bool m5;
    //you can also add arrays
};

//file
string openfile(ifstream &input);
int linecount(ifstream &input);
int columncount(ifstream &input);
void copydata(ifstream &input, mesure *mesures, int lines);
void closefile(ifstream &input);

//computing
void sortup(mesure *mesures, int lines);
void sortdown(mesure *mesures, int lines);
int findmax(mesure *mesures, int lines);
int findmin(mesure *mesures, int lines);
double calcmean(mesure *mesures, int lines);
double calcstddevmean(mesure *mesures, int lines, double mean);
int findtottrue(mesure *mesures, int lines);
int findtotfalse(mesure *mesures, int lines);
void devidetruefalse(mesure *mesures, mesure *tmesures,
mesure *fmesures, int lines, int tottrue, int totfalse);

//output
string outputdata(mesure *mesures, string infilename, int max, int min,
double mean, double stddevmean, int tottrue, int totfalse, int lines, int columns);
string outputisto(mesure *mesures, int max, int min, int lines);
void outputfile(mesure *mesures, ofstream &output, string infilename, int max, int min,
double mean, double stddevmean, int tottrue, int totfalse, int lines, int columns);

//clean
void clean(mesure *mesures, mesure *tmesures, mesure *fmesures);

//else
int exp(int i);