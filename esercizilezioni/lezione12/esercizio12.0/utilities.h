#include"esperimentoprisma.h"

double findmin(vector<double> a){
    double min=numeric_limits<double>::max();
    for(int i=0; i<a.size(); i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    return min;
}
double findmax(vector<double> a){
    double max=numeric_limits<double>::lowest();
    for(int i=0; i<a.size(); i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
vector<TH1F*> getth(int n, esperimentoprisma &e){
    vector<TH1F*> histoth;
    vector<double> th0mis;
    vector<double> th1mis;
    vector<double> th2mis;
    for(int t=0; t<3; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                th0mis.push_back(e.getth0mis());
            }else if(t==1){
                th1mis.push_back(e.getth1mis());
            }else if(t==2){
                th2mis.push_back(e.getth2mis());
            }       
        }
    }
    for(int t=0; t<3; t++){
        if(t==0){
            double min=findmin(th0mis);
            double max=findmax(th0mis);
            histoth.push_back(new TH1F(Form("Legenda %d", t), Form("Th%d misurati", t), 100, min, max));
            for(int i=0; i<n; i++){
                histoth[t]->Fill(th0mis[i]);
            }
            double mean=histoth[t]->GetMean();
            cout << "Th0: " << mean << endl;
        }else if(t==1){
            double min=findmin(th1mis);
            double max=findmax(th1mis);
            histoth.push_back(new TH1F(Form("Legenda %d", t), Form("Th%d misurati", t), 100, min, max));
            for(int i=0; i<n; i++){
                histoth[t]->Fill(th1mis[i]);
            }
            double mean=histoth[t]->GetMean();
            cout << "Th1: " << mean << endl;
        }else if(t==2){
            double min=findmin(th2mis);
            double max=findmax(th2mis);
            histoth.push_back(new TH1F(Form("Legenda %d", t), Form("Th%d misurati", t), 100, min, max));
            for(int i=0; i<n; i++){
                histoth[t]->Fill(th2mis[i]);
            }
            double mean=histoth[t]->GetMean();
            cout << "Th2: " << mean << endl;
        }
    }
    return histoth;
}
vector<TH1F*> getdm(int n, esperimentoprisma &e){
    vector<TH1F*> histodm;
    vector<double> dm1mis;
    vector<double> dm2mis;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                dm1mis.push_back(e.getdm1mis());
            }else if(t==1){
                dm2mis.push_back(e.getdm2mis());
            }  
        }
    }
    for(int t=0; t<2; t++){
        if(t==0){
            double min=findmin(dm1mis);
            double max=findmax(dm1mis);
            histodm.push_back(new TH1F(Form("Legenda %d", t+3), Form("Dm%d misurati", t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histodm[t]->Fill(dm1mis[i]);
            }
            double mean=histodm[t]->GetMean();
            cout << "Dm1: " << mean << endl;
        }else if(t==1){
            double min=findmin(dm2mis);
            double max=findmax(dm2mis);
            histodm.push_back(new TH1F(Form("Legenda %d", t+3), Form("Dm%d misurati", t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histodm[t]->Fill(dm2mis[i]);
            }
            double mean=histodm[t]->GetMean();
            cout << "Dm2: " << mean << endl;
        }
    }
    return histodm;
}
TH2F getdm12(int n, esperimentoprisma &e){
    vector<double> dm1mis;
    vector<double> dm2mis;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                dm1mis.push_back(e.getdm1mis());
            }else if(t==1){
                dm2mis.push_back(e.getdm2mis());
            }  
        }
    }
    double min1=findmin(dm1mis);
    double max1=findmax(dm1mis);
    double min2=findmin(dm2mis);
    double max2=findmax(dm2mis);
    TH2F histodm12("Legenda 5", "Dm1/Dm2", 100, min1, max1, 100, min2, max2);
    for(int i=0; i<n; i++){
        histodm12.Fill(dm1mis[i], dm2mis[i]);
    }
    return histodm12;
}
vector<TH1F*> getn(int n, esperimentoprisma &e){
    vector<TH1F*> histon;
    vector<double> n1mis;
    vector<double> n2mis;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                n1mis.push_back(e.getn1mis());
            }else if(t==1){
                n2mis.push_back(e.getn2mis());
            }  
        }
    }
    for(int t=0; t<2; t++){
        if(t==0){
            double min=findmin(n1mis);
            double max=findmax(n1mis);
            histon.push_back(new TH1F(Form("Legenda %d", t+6), Form("n%d misurati", t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histon[t]->Fill(n1mis[i]);
            }
            double mean=histon[t]->GetMean();
            cout << "n1: " << mean << endl;
        }else if(t==1){
            double min=findmin(n2mis);
            double max=findmax(n2mis);
            histon.push_back(new TH1F(Form("Legenda %d", t+6), Form("n%d misurati", t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histon[t]->Fill(n2mis[i]);
            }
            double mean=histon[t]->GetMean();
            cout << "n2: " << mean << endl;
        }
    }
    return histon;
}
TH2F getn12(int n, esperimentoprisma &e){
    vector<double> n1mis;
    vector<double> n2mis;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                n1mis.push_back(e.getn1mis());
            }else if(t==1){
                n2mis.push_back(e.getn2mis());
            }  
        }
    }
    double min1=findmin(n1mis);
    double max1=findmax(n1mis);
    double min2=findmin(n2mis);
    double max2=findmax(n2mis);
    TH2F histon12("Legenda 8", "n1/n2", 100, min1, max1, 100, min2, max2);
    for(int i=0; i<n; i++){
        histon12.Fill(n1mis[i], n2mis[i]);
    }
    return histon12;
}
vector<TH1F*> gettab(int n, esperimentoprisma &e){
    vector<TH1F*> histoab;
    vector<double> amis;
    vector<double> bmis;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                amis.push_back(e.getamis());
            }else if(t==1){
                bmis.push_back(e.getbmis());
            }  
        }
    }
    for(int t=0; t<2; t++){
        if(t==0){
            double min=findmin(amis);
            double max=findmax(amis);
            histoab.push_back(new TH1F(Form("Legenda %d", t+9),"A/B misurati", 100, min, max));
            for(int i=0; i<n; i++){
                histoab[t]->Fill(amis[i]);
            }
            double mean=histoab[t]->GetMean();
            cout << "A: " << mean << endl;
        }else if(t==1){
            double min=findmin(bmis);
            double max=findmax(bmis);
            histoab.push_back(new TH1F(Form("Legenda %d", t+9),"A/B misurati", 100, min, max));
            for(int i=0; i<n; i++){
                histoab[t]->Fill(bmis[i]);
            }
            double mean=histoab[t]->GetMean();
            cout << "B: " << mean << endl;
        }
    }
    return histoab;
}
TH2F getab(int n, esperimentoprisma &e){
    vector<double> amis;
    vector<double> bmis;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                amis.push_back(e.getamis());
            }else if(t==1){
                bmis.push_back(e.getbmis());
            }  
        }
    }
    double min1=findmin(amis);
    double max1=findmax(amis);
    double min2=findmin(bmis);
    double max2=findmax(bmis);
    TH2F histoab("Legenda 11", "A/B", 100, min1, max1, 100, min2, max2);
    for(int i=0; i<n; i++){
        histoab.Fill(amis[i], bmis[i]);
    }
    return histoab;
}
void drawgraph(vector<TH1F*> &histoth, vector<TH1F*> &histodm, TH2F &histodm12,
                          vector<TH1F*> &histon, TH2F &histon12, vector<TH1F*> &histtoab, TH2F &histoab){
    TCanvas c;
    c.cd();
    c.Divide(3, 4);
    for(int i=0; i<3; i++){
        c.cd(i+1);
        histoth[i]->GetYaxis()->SetTitleOffset(1);
        histoth[i]->GetXaxis()->SetTitle(Form("Th%d", i));
        histoth[i]->GetYaxis()->SetTitle("N");
        histoth[i]->Draw();                
    }
    for(int i=0; i<2; i++){
        c.cd(i+4);
        histodm[i]->GetYaxis()->SetTitleOffset(1);
        histodm[i]->GetXaxis()->SetTitle(Form("Dm%d", i-2));
        histodm[i]->GetYaxis()->SetTitle("N");
        histodm[i]->Draw();     
    }
    c.cd(6);
    histodm12.GetYaxis()->SetTitleOffset(1);
    histodm12.GetXaxis()->SetTitle("Dm1");
    histodm12.GetYaxis()->SetTitle("Dm2");
    histodm12.Draw();   
    for(int i=0; i<2; i++){
        c.cd(i+7);
        histon[i]->GetYaxis()->SetTitleOffset(1);
        histon[i]->GetXaxis()->SetTitle(Form("n%d", i-5));
        histon[i]->GetYaxis()->SetTitle("N");
        histon[i]->Draw();     
    }
    c.cd(9);
    histon12.GetYaxis()->SetTitleOffset(1);
    histon12.GetXaxis()->SetTitle("n1");
    histon12.GetYaxis()->SetTitle("n2");
    histon12.Draw();  
    for(int i=0; i<2; i++){
        c.cd(i+10);
        histtoab[i]->GetYaxis()->SetTitleOffset(1);
        histtoab[i]->GetXaxis()->SetTitle("A/B");
        histtoab[i]->GetYaxis()->SetTitle("N");
        histtoab[i]->Draw();     
    }
    c.cd(12);
    histoab.GetYaxis()->SetTitleOffset(1);
    histoab.GetXaxis()->SetTitle("A");
    histoab.GetYaxis()->SetTitle("B");
    histoab.Draw();   
    c.SaveAs("Graphs.pdf");
}