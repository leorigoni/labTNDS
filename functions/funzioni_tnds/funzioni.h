#include"include.h" //iostream, cmath, fstream, sstream, iomanip

namespace funzioni_info{
    struct mesure{
        double m1, m2, m3, m4;
        bool m5;
    }; //da trasformare nel main in vettore di struct

    //file
    string openfile(ifstream &input){
        string infilename;
        do{
            cout << "Inserire il nome del file che si desidera analizzare: ";
            cin >> infilename;
            input.open(infilename, ios::in);
            if(!input.is_open()){
                cout << endl;
                cout << "Apertura file non riuscita." << endl;
                input.clear();
                input.ignore(numeric_limits<streamsize>::max(), '\n');
            }else{
                break;
            }
        }while(true);
        return infilename;
    }
    int linecount(ifstream &input){
        int linecount=0;
        string line;
        while(getline(input, line)){
            linecount++;
        }
        input.clear();
        input.seekg(0, ios::beg);
        return linecount;
    }
    int columncount(ifstream &input){
        int columncount=0;
        string firstline;
        if(getline(input, firstline)){
            istringstream iss(firstline);
            string word;
            while (iss>>word){
                columncount++;
            }
        }
        input.clear();
        input.seekg(0, ios::beg);
        return columncount;
    }
    void copydata(ifstream &input, mesure *mesures, int lines){
        for(int i=0; i<lines; i++){
            input >> mesures[i].m1 >> mesures[i].m2
                >> mesures[i].m3 >> mesures[i].m4
                >> mesures[i].m5;
        }
    }
    void closefile(ifstream &input){
        input.close();
    }

    //computing
    template <typename t> void sortup(vector<t>& a){
        for(int i=0; i<a.size()-1; i++){
            for(int j=i+1; j<a.size(); j++){
                if(a[i]>a[j]){
                    t tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
            }
        }
    }
    template <typename t> void sortupfast(vector<t>& a){
        sort(a.begin(), a.end());
    }
    void sortdown(mesure *mesures, int lines){
        for(int i=0; i<lines-1; i++){
            for(int j=i+1; j<lines; j++){
                if(mesures[i].m1<mesures[j].m1){
                    mesure tmp=mesures[i];
                    mesures[i]=mesures[j];
                    mesures[j]=tmp;
                }
            }
        }
    }
    int findmax(mesure *mesures, int lines){
        int max=numeric_limits<int>::min();
        for(int i=0; i<lines; i++){
            if(mesures[i].m1>max){
                max=mesures[i].m1;
            }
        }
        return max;
    }
    int findmin(mesure *mesures, int lines){
        int min=numeric_limits<int>::max();
        for(int i=0; i<lines; i++){
            if(mesures[i].m1<min){
                min=mesures[i].m1;
            }
        }
        return min;
    }
    double calcmean(mesure *mesures, int lines){
        double sum=0;
        for(int i=0; i<lines; i++){
            sum+=mesures[i].m2;
        }
        double mean=sum/lines;
        return mean;
    }
    double calcstddevmean(mesure *mesures, int lines, double mean){
        double sumsq=0;
        for(int i=0; i<lines; i++){
            sumsq+=pow(mesures[i].m2-mean,2);
        }
        double stddevmean=0;
        stddevmean=sqrt(sumsq/(lines-1))/sqrt(lines);
        return stddevmean;
    }
    int findtottrue(mesure *mesures, int lines){
        int tottrue=0;
        for(int i=0; i<lines; i++){
            if(mesures[i].m5==true){
                tottrue++;
            }
        }
        return tottrue;
    }
    int findtotfalse(mesure *mesures, int lines){
        int totfalse=0;
        for(int i=0; i<lines; i++){
            if(mesures[i].m5==false){
                totfalse++;
            }
        }
        return totfalse;
    }
    void devidetruefalse(mesure *mesures, mesure *tmesures,
    mesure *fmesures, int lines, int tottrue, int totfalse){
        int jtrue=0;
        for(int i=0; i<lines; i++){
            if(mesures[i].m5==true){
                tmesures[jtrue].m1=mesures[i].m1;
                tmesures[jtrue].m2=mesures[i].m2;
                tmesures[jtrue].m3=mesures[i].m3;
                tmesures[jtrue].m4=mesures[i].m4;
                tmesures[jtrue].m5=mesures[i].m5;
                jtrue++;
            }
        }
        int jfalse=0;
            for(int i=0; i<lines; i++){
            if(mesures[i].m5==false){
                fmesures[jfalse].m1=mesures[i].m1;
                fmesures[jfalse].m2=mesures[i].m2;
                fmesures[jfalse].m3=mesures[i].m3;
                fmesures[jfalse].m4=mesures[i].m4;
                fmesures[jfalse].m5=mesures[i].m5;
                jfalse++;
            }
        }
    }
    void duplarray(double *data, double * sortdata, int ndata){
        for(int i=0; i<ndata; i++){
            sortdata[i]=data[i];
        }
    }

    //output
    string outputdata(mesure *mesures, string infilename, int max, int min,
    double mean, double stddevmean, int tottrue, int totfalse, int lines, int columns){
        stringstream result;
        result << "I seguenti dati provengono dal file: " << infilename << endl;
        result << endl;
        result << "In cui sono contenute " << lines << " misure, di " << columns << " variabili differenti." << endl;
        result << endl;
        result << "Le misure contenute nel file sono elencate nella seguente tabella." << endl;
        result << setw(10) << "m1" << setw(10) << "m2"
            << setw(10) << "m3" << setw(10) << "m4"
            << setw(10) << "m5" << endl;
        result << endl;
        for(int i=0; i<lines; i++){
            result << setw(10) << fixed << setprecision(3) << mesures[i].m1
                << setw(10) << fixed << setprecision(3) << mesures[i].m2
                << setw(10) << fixed << setprecision(3) << mesures[i].m3
                << setw(10) << fixed << setprecision(3) << mesures[i].m4
                << setw(10) << fixed << setprecision(3) << mesures[i].m5 << endl;
        }
        result << endl;
        result << "Con un massimo su m1 di " << max << " ed un minimo di " << min << "." << endl;
        result << endl;
        result << "Una media di " << mean << " ed una relativa deviazione standard di ±" << stddevmean << endl;
        result << endl;
        result << "Su un totale di " << tottrue << " misure true e " << totfalse << " misure false." << endl;
        return result.str();
    }
    string outputisto(mesure *mesures, int max, int min, int lines){
        stringstream isto;
        const int precision=30;
        double binwidth=(max-min)/precision;
        int *freq=new int[precision]();
        for(int i=0; i<lines; ++i){
            int binindex=static_cast<int>((mesures[i].m1-min)/binwidth);
                if(binindex==precision){
                binindex--;
            }
            freq[binindex]++;
        }
        isto << "A seguito è riportato l'istogramma relativo alle misure della massa background:" << endl;
        isto << endl;
        for(int i=0; i<precision; ++i){
            double binstart=min+i*binwidth;
            double binend=min+(i+1)*binwidth;
            isto << "[" << setw(9) << fixed << setprecision(5) << binstart << setw(3) << " , " 
                << setw(9) << fixed << setprecision(5) << binend << setw(3) << "]: ";
            for(int j=0; j<freq[i]; ++j){
                isto << "=";
            }
            isto << " " << freq[i] << endl;
        }
        delete[] freq;
        return isto.str();
    }
    void outputfile(mesure *mesures, ofstream &output, string infilename, int max, int min,
    double mean, double stddevmean, int tottrue, int totfalse, int lines, int columns){
        string outfilename;
        cout << "Come si desidera chiamare il file di output: ";
        cin >> outfilename;
        output.open(outfilename, ios::out);
        output << outputdata(mesures, infilename, max, min, mean, stddevmean,
                tottrue, totfalse, lines, columns);
        output << endl;
        output << outputisto(mesures, max, min, lines);
        output.close();
    }

    //clean
    void clean(mesure *mesures, mesure *tmesures, mesure *fmesures){
        delete[]mesures;
        delete[]tmesures;
        delete[]fmesures;
    }

    //else
    int exp(int i){
        int exp=1;
        for(int j=1; j<=i; j++){
            exp*=j;
        }
        return exp;
    }
}