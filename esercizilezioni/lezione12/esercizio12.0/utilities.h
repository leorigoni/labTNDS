#include"esperimentoprisma.h"

struct esperimento{
    vector<double> th0mis;
    vector<double> th1mis;
    vector<double> th2mis;
    vector<double> dm1mis;
    vector<double> dm2mis;
    vector<double> dm1input;
    vector<double> dm2input;
    vector<double> n1mis;
    vector<double> n2mis;
    vector<double> n1input;
    vector<double> n2input;
    vector<double> amis;
    vector<double> ainput;
    vector<double> bmis;
    vector<double> binput;
};

/*struct doppiohisto{
    vector<TH1F*> histo1;
    TH2F histo2; work in progress...
};*/

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

vector<TH1F*> getth(int n, esperimento &esp){
    vector<TH1F*> histoth;
    for(auto &hist:histoth){
        hist->StatOverflows(kTRUE);
    }
    for(int t=0; t<3; t++){
        if(t==0){
            double min=findmin(esp.th0mis);
            double max=findmax(esp.th0mis);
            histoth.push_back(new TH1F(Form("Legenda %d", t), Form("Th%d misurati", t), 100, min, max));
            for(int i=0; i<n; i++){
                histoth[t]->Fill(esp.th0mis[i]);
            }
            double mean=histoth[t]->GetMean();
            double stddev=histoth[t]->GetStdDev();
            cout << "Th0: " << mean << " ± " << stddev << endl;
        }else if(t==1){
            double min=findmin(esp.th1mis);
            double max=findmax(esp.th1mis);
            histoth.push_back(new TH1F(Form("Legenda %d", t), Form("Th%d misurati", t), 100, min, max));
            for(int i=0; i<n; i++){
                histoth[t]->Fill(esp.th1mis[i]);
            }
            double mean=histoth[t]->GetMean();
            double stddev=histoth[t]->GetStdDev();
            cout << "Th1: " << mean << " ± " << stddev << endl;
        }else if(t==2){
            double min=findmin(esp.th2mis);
            double max=findmax(esp.th2mis);
            histoth.push_back(new TH1F(Form("Legenda %d", t), Form("Th%d misurati", t), 100, min, max));
            for(int i=0; i<n; i++){
                histoth[t]->Fill(esp.th2mis[i]);
            }
            double mean=histoth[t]->GetMean();
            double stddev=histoth[t]->GetStdDev();
            cout << "Th2: " << mean << " ± " << stddev << endl;
        }
    }
    return histoth;
}

/*doppiohisto getdm(int n, esperimento &esp.vector1, esperimento &esp.vector2){
work in progress...
}*/

vector<TH1F*> getdm(int n, esperimento &esp){
    vector<TH1F*> histodm;
    for(auto &hist:histodm){
        hist->StatOverflows(kTRUE);
    }
    double totdm1=0.;
    double totdm2=0.;
    for(int i=0; i<n; i++){
        totdm1+=esp.dm1mis[i];
        totdm2+=esp.dm2mis[i];
    }
    double meandm1=totdm1/n;
    double meandm2=totdm2/n;
    double sumsqdm1=0.;
    double sumsqdm2=0.;
    for(int i=0; i<n; i++){
        sumsqdm1+=pow(esp.dm1mis[i]-meandm1, 2);
        sumsqdm2+=pow(esp.dm2mis[i]-meandm2, 2);
    }
    double stddevdm1=sqrt(sumsqdm1/n);
    double stddevdm2=sqrt(sumsqdm2/n);
    for(int i=0; i<n; i++){
        esp.dm1mis[i]=esp.dm1mis[i]-esp.dm1input[i];
        esp.dm2mis[i]=esp.dm2mis[i]-esp.dm2input[i];
    }
    for(int t=0; t<2; t++){
        if(t==0){
            double min=findmin(esp.dm1mis);
            double max=findmax(esp.dm1mis);
            histodm.push_back(new TH1F(Form("Legenda %d", t+3), Form("Dm%d.mis-Dm%d.in", t+1, t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histodm[t]->Fill(esp.dm1mis[i]);
            }
            double mean=histodm[t]->GetMean();
            double stddev=histodm[t]->GetStdDev();
            cout << "Dm1.mis: " << meandm1 << " ± " << stddevdm1 << endl;
            cout << "Dm1.mis-Dm1.in: " << mean << " ± " << stddev << endl;
        }else if(t==1){
            double min=findmin(esp.dm2mis);
            double max=findmax(esp.dm2mis);
            histodm.push_back(new TH1F(Form("Legenda %d", t+3), Form("Dm%d.mis-Dm%d.in", t+1, t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histodm[t]->Fill(esp.dm2mis[i]);
            }
            double mean=histodm[t]->GetMean();
            double stddev=histodm[t]->GetStdDev();
            cout << "Dm2.mis: " << meandm2 << " ± " << stddevdm2 << endl;
            cout << "Dm2.mis-Dm2.in: " << mean << " ± " << stddev << endl;
        }
    }
    return histodm;
}

TH2F getdm12(int n, esperimento &esp){
    double sumx=0.;
    double sumy=0.;
    double sumxy=0.;
    double sumxsq=0.;
    double sumysq=0.;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            if(t==0){
                sumx+=esp.dm1mis[i];
                sumxsq+=pow(esp.dm1mis[i], 2);
            }else if(t==1){
                sumy+=esp.dm2mis[i];
                sumysq+=pow(esp.dm2mis[i], 2);
            }
        }
    }
    for(int i=0; i<n; i++){
        sumxy+=esp.dm1mis[i]*esp.dm2mis[i];
    }
    for(int i=0; i<n; i++){
        esp.dm1mis[i]=esp.dm1mis[i]-esp.dm1input[i];
        esp.dm2mis[i]=esp.dm2mis[i]-esp.dm2input[i];
    }
    double sigmax=sqrt((sumxsq/n)-pow(sumx/n, 2));
    double sigmay=sqrt((sumysq/n)-pow(sumy/n, 2));
    double corr=((sumxy/n)-(sumx/n)*(sumy/n))/(sigmax*sigmay);
    double min1=findmin(esp.dm1mis);
    double max1=findmax(esp.dm1mis);
    double min2=findmin(esp.dm2mis);
    double max2=findmax(esp.dm2mis);
    TH2F histodm12("Legenda 5", "(Dm1.mis-Dm1.in)/(Dm2.mis-Dm2.in)", 100, min1, max1, 100, min2, max2);
    for(int i=0; i<n; i++){
        histodm12.Fill(esp.dm1mis[i], esp.dm2mis[i]);
    }
    cout << "Corr. Dm1-Dm2: " << corr << endl;
    return histodm12;
}

vector<TH1F*> getn(int n, esperimento &esp){
    vector<TH1F*> histon;
    for(auto &hist:histon){
        hist->StatOverflows(kTRUE);
    }
    double totn1=0.;
    double totn2=0.;
    for(int i=0; i<n; i++){
        totn1+=esp.n1mis[i];
        totn2+=esp.n2mis[i];
    }
    double meann1=totn1/n;
    double meann2=totn2/n;
    double sumsqn1=0.;
    double sumsqn2=0.;
    for(int i=0; i<n; i++){
        sumsqn1+=pow(esp.n1mis[i]-meann1, 2);
        sumsqn2+=pow(esp.n2mis[i]-meann2, 2);
    }
    double stddevn1=sqrt(sumsqn1/n);
    double stddevn2=sqrt(sumsqn2/n);
    for(int i=0; i<n; i++){
        esp.n1mis[i]=esp.n1mis[i]-esp.n1input[i];
        esp.n2mis[i]=esp.n2mis[i]-esp.n2input[i];
    }
    for(int t=0; t<2; t++){
        if(t==0){
            double min=findmin(esp.n1mis);
            double max=findmax(esp.n1mis);
            histon.push_back(new TH1F(Form("Legenda %d", t+6), Form("n%d.mis-n%d.in", t+1, t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histon[t]->Fill(esp.n1mis[i]);
            }
            double mean=histon[t]->GetMean();
            double stddev=histon[t]->GetStdDev();
            cout << "n1.mis: " << meann1 << " ± " << stddevn1 << endl;
            cout << "n1.mis-n1.in: " << mean << " ± " << stddev << endl;
        }else if(t==1){
            double min=findmin(esp.n2mis);
            double max=findmax(esp.n2mis);
            histon.push_back(new TH1F(Form("Legenda %d", t+6), Form("n%d.mis-n%d.in", t+1, t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histon[t]->Fill(esp.n2mis[i]);
            }
            double mean=histon[t]->GetMean();
            double stddev=histon[t]->GetStdDev();
            cout << "n2.mis: " << meann2 << " ± " << stddevn2 << endl;
            cout << "n2.mis-n2.in: " << mean << " ± " << stddev << endl;
        }
    }
    return histon;
}

TH2F getn12(int n, esperimento &esp){
    double sumx=0.;
    double sumy=0.;
    double sumxy=0.;
    double sumxsq=0.;
    double sumysq=0.;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            if(t==0){
                sumx+=esp.n1mis[i];
                sumxsq+=pow(esp.n1mis[i], 2);
            }else if(t==1){
                sumy+=esp.n2mis[i];
                sumysq+=pow(esp.n2mis[i], 2);
            }
        }
    }
    for(int i=0; i<n; i++){
        sumxy+=esp.n1mis[i]*esp.n2mis[i];
    }
    for(int i=0; i<n; i++){
        esp.n1mis[i]=esp.n1mis[i]-esp.n1input[i];
        esp.n2mis[i]=esp.n2mis[i]-esp.n2input[i];
    }
    double sigmax=sqrt((sumxsq/n)-pow(sumx/n, 2));
    double sigmay=sqrt((sumysq/n)-pow(sumy/n, 2));
    double corr=((sumxy/n)-(sumx/n)*(sumy/n))/(sigmax*sigmay);
    double min1=findmin(esp.n1mis);
    double max1=findmax(esp.n1mis);
    double min2=findmin(esp.n2mis);
    double max2=findmax(esp.n2mis);
    TH2F histon12("Legenda 8", "(n1.mis-n1.in)/(n2.mis-n2.in)", 100, min1, max1, 100, min2, max2);
    for(int i=0; i<n; i++){
        histon12.Fill(esp.n1mis[i], esp.n2mis[i]);
    }
    cout << "Corr. n1-n2: " << corr << endl;
    return histon12;
}

vector<TH1F*> gettab(int n, esperimento &esp){
    vector<TH1F*> histoab;
    for(auto &hist:histoab){
        hist->StatOverflows(kTRUE);
    }
    double tota=0.;
    double totb=0.;
    for(int i=0; i<n; i++){
        tota+=esp.amis[i];
        totb+=esp.bmis[i];
    }
    double meana=tota/n;
    double meanb=totb/n;
    double sumsqa=0.;
    double sumsqb=0.;
    for(int i=0; i<n; i++){
        sumsqa+=pow(esp.amis[i]-meana, 2);
        sumsqb+=pow(esp.bmis[i]-meanb, 2);
    }
    double stddeva=sqrt(sumsqa/n);
    double stddevb=sqrt(sumsqb/n);
    for(int i=0; i<n; i++){
        esp.amis[i]=esp.amis[i]-esp.ainput[i];
        esp.bmis[i]=esp.bmis[i]-esp.binput[i];
    }
    for(int t=0; t<2; t++){
        if(t==0){
            double min=findmin(esp.amis);
            double max=findmax(esp.amis);
            histoab.push_back(new TH1F(Form("Legenda %d", t+9),"A.mis-A.in", 100, min, max));
            for(int i=0; i<n; i++){
                histoab[t]->Fill(esp.amis[i]);
            }
            double mean=histoab[t]->GetMean();
            double stddev=histoab[t]->GetStdDev();
            cout << "A.mis: " << meana << " ± " << stddeva << endl;
            cout << "A.mis-A.in: " << mean << " ± " << stddev << endl;
        }else if(t==1){
            double min=findmin(esp.bmis);
            double max=findmax(esp.bmis);
            histoab.push_back(new TH1F(Form("Legenda %d", t+9),"B.mis-B.in", 100, min, max));
            for(int i=0; i<n; i++){
                histoab[t]->Fill(esp.bmis[i]);
            }
            double mean=histoab[t]->GetMean();
            double stddev=histoab[t]->GetStdDev();
            cout << "B.mis: " << meanb << " ± " << stddevb << endl;
            cout << "B.mis-B.in: " << mean << " ± " << stddev << endl;
        }
    }
    return histoab;
}

TH2F getab(int n, esperimento &esp){
    double sumx=0.;
    double sumy=0.;
    double sumxy=0.;
    double sumxsq=0.;
    double sumysq=0.;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            if(t==0){
                sumx+=esp.amis[i]; 
                sumxsq+=pow(esp.amis[i], 2); 
            }else if(t==1){
                sumy+=esp.bmis[i];
                sumysq+=pow(esp.bmis[i], 2);
            } 
        }
    }
    for(int i=0; i<n; i++){
        sumxy+=esp.amis[i]*esp.bmis[i];
    }
    for(int i=0; i<n; i++){
        esp.amis[i]=esp.amis[i]-esp.ainput[i];
        esp.bmis[i]=esp.bmis[i]-esp.binput[i];
    }
    double sigmax=sqrt((sumxsq/n)-pow(sumx/n, 2));
    double sigmay=sqrt((sumysq/n)-pow(sumy/n, 2));
    double corr=((sumxy/n)-(sumx/n)*(sumy/n))/(sigmax*sigmay);
    double min1=findmin(esp.amis);
    double max1=findmax(esp.amis);
    double min2=findmin(esp.bmis);
    double max2=findmax(esp.bmis);
    TH2F histoab("Legenda 11", "(A.mis-A.in)/(B.mis-B.in)", 100, min1, max1, 100, min2, max2);
    for(int i=0; i<n; i++){
        histoab.Fill(esp.amis[i], esp.bmis[i]);
    }
    cout << "Corr. A-B: " << corr << endl;
    return histoab;
}
void drawgraph(vector<TH1F*> &histoth, vector<TH1F*> &histodm, TH2F &histodm12,
                          vector<TH1F*> &histon, TH2F &histon12, vector<TH1F*> &histtoab, TH2F &histoab){
    TCanvas c("c", "Graphs", 1200, 2100);
    c.cd();
    c.Divide(3, 4);
    for(int i=0; i<3; i++){
        c.cd(i+1);
        histoth[i]->GetYaxis()->SetTitleOffset(1);
        histoth[i]->GetXaxis()->SetTitle(Form("Th%d [rad]", i));
        histoth[i]->GetYaxis()->SetTitle("N");
        histoth[i]->Draw();                
    }
    for(int i=0; i<2; i++){
        c.cd(i+4);
        histodm[i]->GetYaxis()->SetTitleOffset(1);
        histodm[i]->GetXaxis()->SetTitle(Form("Dm%d.mis-Dm%d.in [rad]", i+1, i+1));
        histodm[i]->GetYaxis()->SetTitle("N");
        histodm[i]->Draw();     
    }
    c.cd(6);
    histodm12.GetYaxis()->SetTitleOffset(1);
    histodm12.GetXaxis()->SetTitle("Dm1.mis-Dm1.in [rad]");
    histodm12.GetYaxis()->SetTitle("Dm2.mis-Dm2.in [rad]");
    histodm12.Draw();   
    for(int i=0; i<2; i++){
        c.cd(i+7);
        histon[i]->GetYaxis()->SetTitleOffset(1);
        histon[i]->GetXaxis()->SetTitle(Form("n%d.mis-n%d.in", i+1, i+1));
        histon[i]->GetYaxis()->SetTitle("N");
        histon[i]->Draw();     
    }
    c.cd(9);
    histon12.GetYaxis()->SetTitleOffset(1);
    histon12.GetXaxis()->SetTitle("n1.mis-n1.in");
    histon12.GetYaxis()->SetTitle("n2.mis-n2.in");
    histon12.Draw();  
    for(int i=0; i<2; i++){
        if(i==0){
            c.cd(i+10);
            histtoab[i]->GetYaxis()->SetTitleOffset(1);
            histtoab[i]->GetXaxis()->SetTitle("A.mis-A.in");
            histtoab[i]->GetYaxis()->SetTitle("N");
            histtoab[i]->Draw(); 
        }else if(i==1){
            c.cd(i+10);
            histtoab[i]->GetYaxis()->SetTitleOffset(1);
            histtoab[i]->GetXaxis()->SetTitle("B.mis-B.in");
            histtoab[i]->GetYaxis()->SetTitle("N");
            histtoab[i]->Draw(); 
        }
    }
    c.cd(12);
    histoab.GetYaxis()->SetTitleOffset(1);
    histoab.GetXaxis()->SetTitle("A.mis-A.in");
    histoab.GetYaxis()->SetTitle("B.mis-B.in");
    histoab.Draw();   
    c.SaveAs("Graphs.pdf");
}