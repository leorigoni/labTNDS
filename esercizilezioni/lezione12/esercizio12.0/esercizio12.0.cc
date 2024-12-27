#include"esperimentoprisma.h"

int main(){
    int n=1000;
    esperimentoprisma e(1);
    TH1F histoa("A", "A", 100, 0, 4);
    TCanvas c;
    for(int i=0; i<n; i++){
        e.esegui();
        e.analizza();
        histoa.Fill(e.getamis());
        cout << e.getamis() << endl;
    }
    histoa.Draw();
    c.SaveAs("histoa.pdf");
    return 0;
}