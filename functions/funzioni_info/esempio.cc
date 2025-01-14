#include<iostream>
using namespace std;
int main(){
    struct esempione{
        int n=0;
        char *es=new char[n];
    };
    esempione esempio;
    cout << "quante lettere si vogliono inserire ?" << endl;
    cin >> esempio.n;
    cout << "inserire le " << esempio.n << " lettere:" << endl;
    for(int i=0; i<esempio.n; i++){
        cin >> esempio.es[i];
    }
    cout << "le lettere inserite sono:" << endl;
    for(int i=0; i<esempio.n; i++){
        cout << esempio.es[i] << endl;
    }
    cout << "ciao eva !!!" << endl;
    return 0;
}