#include"include.h"

string convert(double h){
    int cifre_significative=-log10(h);
    ostringstream streamobj3;
    streamobj3 << fixed;
    streamobj3 << setprecision(cifre_significative);
    streamobj3 << h;
    string strobj3=streamobj3.str();
    return strobj3;
};