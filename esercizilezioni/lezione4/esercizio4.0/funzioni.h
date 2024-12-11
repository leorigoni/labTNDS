#ifndef __funzioni_h__
#define __funzioni_h__

//############################################################################
// DECLARATION
//############################################################################

#include<iostream>
#include<fstream>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include"TGraphErrors.h"
#include"TApplication.h"
#include"TCanvas.h"
#include"TAxis.h"
#include"TLine.h"
#include"TGraphSmooth.h"


using namespace std;

//file
template <typename t> vector<t> read(string);


//computing
template <typename t> double calcmedia(vector<t> &);
template <typename t> double calcvarianza(vector<t> &, double mean);
template <typename t> double calcstddevmean(vector<t> &v, double mean);
template <typename t> void sortup(vector<t> &);
template <typename t> double calcmediana(vector<t> &);

//output
template <typename t> string outputdata(string, vector<t> &, vector<t> &, 
                                                                    double, double, double);
template <typename t> void outputfile(string, vector<t> &, vector<t> &, 
                                                                double, double, double);
template <typename t> void outputfile(ofstream &, string, string, vector<t> &, vector<t> &, 
                                                                double, double, double);

//############################################################################
// IMPLEMENTATION
//############################################################################

//file
template <typename t> vector<t> read(string infilename){
    ifstream input;
    input.open(infilename, ios::in);
    if(!input.is_open()){
        cout << endl;
        cout << "Apertura file non riuscita." << endl;
        input.clear();
    }
    vector<t> tmp;
    t mom;
    while(input >> mom){
        tmp.push_back(mom);
    }
    input.close();
    return tmp;
}

//computing
template <typename t> double calcmedia(vector<t> &v){
    double tot=0;
    for(int i=0; i<v.size(); i++){ 
        tot+=v[i];
    }
    return tot/double(v.size());
}
template <typename t> double calcvarianza(vector<t> &v, double mean){
    double sumsq=0;
    for(int i=0; i<v.size(); i++){
        sumsq+=pow(v[i]-mean,2);
    }
    return sumsq/(v.size()-1);
}
template <typename t> double calcstddevmean(vector<t> &v, double mean){
    double sumsq=0;
    int n=0;
    for(int i=0; i<v.size(); i+=7){
        sumsq+=pow(v[i]-mean,2);
        n++;
    }
    double stddevmean=0;
    stddevmean=sqrt(sumsq/(n-1))/(sqrt(n));
    return stddevmean;
}
template <typename t> void sortup(vector<t> &vs){
    for(int i=0; i<vs.size()-1; i++){
        for(int j=i+1; j<vs.size(); j++){
            if(vs[i]>vs[j]){
                swap(vs[i], vs[j]);
            }
        }
    }
}
template <typename t> double calcmediana(vector<t> &vs){
    int halfdata=0;
    double med=0;
    if(vs.size()%2 == 0){
        halfdata=vs.size()/2;
        med=((vs[halfdata]+vs[halfdata+1])/2);
    }else{
        halfdata=vs.size()/2;
        med=vs[halfdata];
    }
    return med;
}

//output
template <typename t> string outputdata(string infilename, vector<t> &v, vector<t> &vs, 
                                                                    double mean, double var, double med){
    stringstream output; //mettere meglio i dati
    output << "I dati analizzati provengono dal file: "  << infilename << endl;
    output << "Sono stai analizzati i seguinti " << v.size() << " valori." << endl;
    output << endl;
    output << setw(15) << "da file" << setw(15) << "ordinati" << endl;
    for(int i=0; i<v.size(); i++){
        output << "n." << i+1 << setw(11) << fixed << setprecision(4) <<
                     v[i] << setw(15) << fixed << setprecision(4) << 
                     vs[i] << endl;
    }
    output << endl;
    output << "Dai dati sono state estrapolate le seguenti variabili." << endl;
    output << "Media: " << mean << endl;
    output << "Varianza: " << var << endl;
    output << "Mediana: " << med << endl;
    return output.str();
}
template <typename t> void outputfile(string infilename, vector<t> &v, vector<t> &vs, 
                                                                double mean, double var, double med){
    cout << endl;
    cout << outputdata(infilename, v, vs, mean, var, med);
    cout << endl;
}
template <typename t> void outputfile(ofstream &output, string infilename, string outfilename, vector<t> &v, vector<t> &vs, 
                                                                double mean, double var, double med){
    output.open(outfilename, ios::out);
    output << outputdata(infilename, v, vs, mean, var, med);
    output.close();
}

#endif