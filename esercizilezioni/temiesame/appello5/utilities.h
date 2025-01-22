#include"condensiamo.h"

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
vector<TH1F*> getth(int n, condensatore &e){
    vector<TH1F*> histoth;
    for(auto &hist:histoth){
        hist->StatOverflows(kTRUE);
    }
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
    /*for(int i=0; i<n; i++){
        th0mis[i]=th0mis[i]-e.getth0input();
        th1mis[i]=th1mis[i]-e.getth1input();
        th2mis[i]=th2mis[i]-e.getth2input();
    }*/
    for(int t=0; t<3; t++){
        if(t==0){
            double min=findmin(th0mis);
            double max=findmax(th0mis);
            histoth.push_back(new TH1F(Form("Legenda %d", t), Form("Th%d misurati", t), 100, min, max));
            for(int i=0; i<n; i++){
                histoth[t]->Fill(th0mis[i]);
            }
            double mean=histoth[t]->GetMean();
            double stddev=histoth[t]->GetStdDev();
            cout << "Th0: " << mean << " ± " << stddev << endl;
        }else if(t==1){
            double min=findmin(th1mis);
            double max=findmax(th1mis);
            histoth.push_back(new TH1F(Form("Legenda %d", t), Form("Th%d misurati", t), 100, min, max));
            for(int i=0; i<n; i++){
                histoth[t]->Fill(th1mis[i]);
            }
            double mean=histoth[t]->GetMean();
            double stddev=histoth[t]->GetStdDev();
            cout << "Th1: " << mean << " ± " << stddev << endl;
        }else if(t==2){
            double min=findmin(th2mis);
            double max=findmax(th2mis);
            histoth.push_back(new TH1F(Form("Legenda %d", t), Form("Th%d misurati", t), 100, min, max));
            for(int i=0; i<n; i++){
                histoth[t]->Fill(th2mis[i]);
            }
            double mean=histoth[t]->GetMean();
            double stddev=histoth[t]->GetStdDev();
            cout << "Th2: " << mean << " ± " << stddev << endl;
        }
    }
    return histoth;
}
vector<TH1F*> getdm(int n, condensatore &e){
    vector<TH1F*> histodm;
    for(auto &hist:histodm){
        hist->StatOverflows(kTRUE);
    }
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
    double totdm1=0.;
    double totdm2=0.;
    for(int i=0; i<n; i++){
        totdm1+=dm1mis[i];
        totdm2+=dm2mis[i];
    }
    double meandm1=totdm1/n;
    double meandm2=totdm2/n;
    double sumsqdm1=0.;
    double sumsqdm2=0.;
    for(int i=0; i<n; i++){
        sumsqdm1+=pow(dm1mis[i]-meandm1, 2);
        sumsqdm2+=pow(dm2mis[i]-meandm2, 2);
    }
    double stddevdm1=sqrt(sumsqdm1/n);
    double stddevdm2=sqrt(sumsqdm2/n);
    for(int i=0; i<n; i++){
        dm1mis[i]=dm1mis[i]-e.getdm1input();
        dm2mis[i]=dm2mis[i]-e.getdm2input();
    }
    for(int t=0; t<2; t++){
        if(t==0){
            double min=findmin(dm1mis);
            double max=findmax(dm1mis);
            histodm.push_back(new TH1F(Form("Legenda %d", t+3), Form("Dm%d.mis-Dm%d.in", t+1, t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histodm[t]->Fill(dm1mis[i]);
            }
            double mean=histodm[t]->GetMean();
            double stddev=histodm[t]->GetStdDev();
            cout << "Dm1.mis: " << meandm1 << " ± " << stddevdm1 << endl;
            cout << "Dm1.mis-Dm1.in: " << mean << " ± " << stddev << endl;
        }else if(t==1){
            double min=findmin(dm2mis);
            double max=findmax(dm2mis);
            histodm.push_back(new TH1F(Form("Legenda %d", t+3), Form("Dm%d.mis-Dm%d.in", t+1, t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histodm[t]->Fill(dm2mis[i]);
            }
            double mean=histodm[t]->GetMean();
            double stddev=histodm[t]->GetStdDev();
            cout << "Dm2.mis: " << meandm2 << " ± " << stddevdm2 << endl;
            cout << "Dm2.mis-Dm2.in: " << mean << " ± " << stddev << endl;
        }
    }
    return histodm;
}
TH2F getdm12(int n, condensatore &e){
    vector<double> dm1mis;
    vector<double> dm2mis;
    double sumx=0.;
    double sumy=0.;
    double sumxy=0.;
    double sumxsq=0.;
    double sumysq=0.;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                dm1mis.push_back(e.getdm1mis());
                sumx+=e.getdm1mis();
                sumxsq+=pow(e.getdm1mis(), 2);
            }else if(t==1){
                dm2mis.push_back(e.getdm2mis());
                sumy+=e.getdm2mis();
                sumysq+=pow(e.getdm2mis(), 2);
            }
        }
    }
    for(int i=0; i<n; i++){
        sumxy+=dm1mis[i]*dm2mis[i];
    }
    for(int i=0; i<n; i++){
        dm1mis[i]=dm1mis[i]-e.getdm1input();
        dm2mis[i]=dm2mis[i]-e.getdm2input();
    }
    double sigmax=sqrt((sumxsq/n)-pow(sumx/n, 2));
    double sigmay=sqrt((sumysq/n)-pow(sumy/n, 2));
    double corr=((sumxy/n)-(sumx/n)*(sumy/n))/(sigmax*sigmay);
    double min1=findmin(dm1mis);
    double max1=findmax(dm1mis);
    double min2=findmin(dm2mis);
    double max2=findmax(dm2mis);
    TH2F histodm12("Legenda 5", "(Dm1.mis-Dm1.in)/(Dm2.mis-Dm2.in)", 100, min1, max1, 100, min2, max2);
    for(int i=0; i<n; i++){
        histodm12.Fill(dm1mis[i], dm2mis[i]);
    }
    cout << "Corr. Dm1-Dm2: " << corr << endl;
    return histodm12;
}
vector<TH1F*> getn(int n, condensatore &e){
    vector<TH1F*> histon;
    for(auto &hist:histon){
        hist->StatOverflows(kTRUE);
    }
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
    double totn1=0.;
    double totn2=0.;
    for(int i=0; i<n; i++){
        totn1+=n1mis[i];
        totn2+=n2mis[i];
    }
    double meann1=totn1/n;
    double meann2=totn2/n;
    double sumsqn1=0.;
    double sumsqn2=0.;
    for(int i=0; i<n; i++){
        sumsqn1+=pow(n1mis[i]-meann1, 2);
        sumsqn2+=pow(n2mis[i]-meann2, 2);
    }
    double stddevn1=sqrt(sumsqn1/n);
    double stddevn2=sqrt(sumsqn2/n);
    for(int i=0; i<n; i++){
        n1mis[i]=n1mis[i]-e.getn1input();
        n2mis[i]=n2mis[i]-e.getn2input();
    }
    for(int t=0; t<2; t++){
        if(t==0){
            double min=findmin(n1mis);
            double max=findmax(n1mis);
            histon.push_back(new TH1F(Form("Legenda %d", t+6), Form("n%d.mis-n%d.in", t+1, t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histon[t]->Fill(n1mis[i]);
            }
            double mean=histon[t]->GetMean();
            double stddev=histon[t]->GetStdDev();
            cout << "n1.mis: " << meann1 << " ± " << stddevn1 << endl;
            cout << "n1.mis-n1.in: " << mean << " ± " << stddev << endl;
        }else if(t==1){
            double min=findmin(n2mis);
            double max=findmax(n2mis);
            histon.push_back(new TH1F(Form("Legenda %d", t+6), Form("n%d.mis-n%d.in", t+1, t+1), 100, min, max));
            for(int i=0; i<n; i++){
                histon[t]->Fill(n2mis[i]);
            }
            double mean=histon[t]->GetMean();
            double stddev=histon[t]->GetStdDev();
            cout << "n2.mis: " << meann2 << " ± " << stddevn2 << endl;
            cout << "n2.mis-n2.in: " << mean << " ± " << stddev << endl;
        }
    }
    return histon;
}
TH2F getn12(int n, condensatore &e){
    vector<double> n1mis;
    vector<double> n2mis;
    double sumx=0.;
    double sumy=0.;
    double sumxy=0.;
    double sumxsq=0.;
    double sumysq=0.;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                n1mis.push_back(e.getn1mis());
                sumx+=e.getn1mis();
                sumxsq+=pow(e.getn1mis(), 2);
            }else if(t==1){
                n2mis.push_back(e.getn2mis());
                sumy+=e.getn2mis();
                sumysq+=pow(e.getn2mis(), 2);
            }
        }
    }
    for(int i=0; i<n; i++){
        sumxy+=n1mis[i]*n2mis[i];
    }
    for(int i=0; i<n; i++){
        n1mis[i]=n1mis[i]-e.getn1input();
        n2mis[i]=n2mis[i]-e.getn2input();
    }
    double sigmax=sqrt((sumxsq/n)-pow(sumx/n, 2));
    double sigmay=sqrt((sumysq/n)-pow(sumy/n, 2));
    double corr=((sumxy/n)-(sumx/n)*(sumy/n))/(sigmax*sigmay);
    double min1=findmin(n1mis);
    double max1=findmax(n1mis);
    double min2=findmin(n2mis);
    double max2=findmax(n2mis);
    TH2F histon12("Legenda 8", "(n1.mis-n1.in)/(n2.mis-n2.in)", 100, min1, max1, 100, min2, max2);
    for(int i=0; i<n; i++){
        histon12.Fill(n1mis[i], n2mis[i]);
    }
    cout << "Corr. n1-n2: " << corr << endl;
    return histon12;
}
vector<TH1F*> gettab(int n, condensatore &e){
    vector<TH1F*> histoab;
    for(auto &hist:histoab){
        hist->StatOverflows(kTRUE);
    }
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
    double tota=0.;
    double totb=0.;
    for(int i=0; i<n; i++){
        tota+=amis[i];
        totb+=bmis[i];
    }
    double meana=tota/n;
    double meanb=totb/n;
    double sumsqa=0.;
    double sumsqb=0.;
    for(int i=0; i<n; i++){
        sumsqa+=pow(amis[i]-meana, 2);
        sumsqb+=pow(bmis[i]-meanb, 2);
    }
    double stddeva=sqrt(sumsqa/n);
    double stddevb=sqrt(sumsqb/n);
    for(int i=0; i<n; i++){
        amis[i]=amis[i]-e.getainput();
        bmis[i]=bmis[i]-e.getbinput();
    }
    for(int t=0; t<2; t++){
        if(t==0){
            double min=findmin(amis);
            double max=findmax(amis);
            histoab.push_back(new TH1F(Form("Legenda %d", t+9),"A.mis-A.in", 100, min, max));
            for(int i=0; i<n; i++){
                histoab[t]->Fill(amis[i]);
            }
            double mean=histoab[t]->GetMean();
            double stddev=histoab[t]->GetStdDev();
            cout << "A.mis: " << meana << " ± " << stddeva << endl;
            cout << "A.mis-A.in: " << mean << " ± " << stddev << endl;
        }else if(t==1){
            double min=findmin(bmis);
            double max=findmax(bmis);
            histoab.push_back(new TH1F(Form("Legenda %d", t+9),"B.mis-B.in", 100, min, max));
            for(int i=0; i<n; i++){
                histoab[t]->Fill(bmis[i]);
            }
            double mean=histoab[t]->GetMean();
            double stddev=histoab[t]->GetStdDev();
            cout << "B.mis: " << meanb << " ± " << stddevb << endl;
            cout << "B.mis-B.in: " << mean << " ± " << stddev << endl;
        }
    }
    return histoab;
}
TH2F getab(int n, condensatore &e){
    vector<double> amis;
    vector<double> bmis;
    double sumx=0.;
    double sumy=0.;
    double sumxy=0.;
    double sumxsq=0.;
    double sumysq=0.;
    for(int t=0; t<2; t++){
        for(int i=0; i<n; i++){
            e.esegui();
            e.analizza();
            if(t==0){
                amis.push_back(e.getamis());
                sumx+=e.getamis(); 
                sumxsq+=pow(e.getamis(), 2); 
            }else if(t==1){
                bmis.push_back(e.getbmis());
                sumy+=e.getbmis();
                sumysq+=pow(e.getbmis(), 2);
            } 
        }
    }
    for(int i=0; i<n; i++){
        sumxy+=amis[i]*bmis[i];
    }
    for(int i=0; i<n; i++){
        amis[i]=amis[i]-e.getainput();
        bmis[i]=bmis[i]-e.getbinput();
    }
    double sigmax=sqrt((sumxsq/n)-pow(sumx/n, 2));
    double sigmay=sqrt((sumysq/n)-pow(sumy/n, 2));
    double corr=((sumxy/n)-(sumx/n)*(sumy/n))/(sigmax*sigmay);
    double min1=findmin(amis);
    double max1=findmax(amis);
    double min2=findmin(bmis);
    double max2=findmax(bmis);
    TH2F histoab("Legenda 11", "(A.mis-A.in)/(B.mis-B.in)", 100, min1, max1, 100, min2, max2);
    for(int i=0; i<n; i++){
        histoab.Fill(amis[i], bmis[i]);
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