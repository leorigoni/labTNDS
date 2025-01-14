#include<iostream> //sempre
#include<fstream> //modificare file
#include<sstream> //stringhe più belle
#include<string> //stringhe (include anche io iostream)
#include<cmath> //funzioni matematiche
#include<cstdlib> //input da terminale
#include<iomanip> //modifica output
#include<vector> //vettori
#include<algorithm> //sorting vari
#include<cassert> //assert
#include<numeric> //accumulate
#include<limits> //limiti numerici
#include<filesystem> //controllo esistenza file

#include"TH1F.h" //istogrammi 1D
#include"TApplication.h" //app per mostrare grafici
#include"TCanvas.h" //canvas per grafici
#include"TGraphErrors.h" //grafico x-y con errori
#include"TAxis.h" //modifica gli assi
#include"TLine.h" //modifica le linee
#include"TGraphSmooth.h" //grafico liscio
#include"TGraph.h" //grafici x-y
#include"TH2F.h" //istogrammi 2D
#include"altro di root..."

#include"funzioni.h" //funzioni definite dall'utente

using namespace std; //sempre
namespace fs=std::filesystem; //per includere librerie con std diverso