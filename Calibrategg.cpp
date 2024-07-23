#include<TFile.h>
#include<TH1D.h>
#include<TF1.h>
#include<TDirectoryFile.h>
#include<iostream>

Int_t Calibrategg(){

    Short_t MIN[6] = {70,110,340,352,770,1380}; 
    Short_t MAX[6] = {85,130,348,360,800,1460}; 


    TFile* d = TFile::Open("ceshi274.root");
    for(Int_t j = 0; j < 18; j++)
        {
            TH1D *h = (TH1D*)d -> Get(Form("kd6gama_%02d", j)); 
            Int_t IndexMax = 0; 
            Int_t IndexNum = h -> GetNbinsX(); 
            IndexMax = h -> FindBin(70); 
            for(Int_t k = h -> FindBin(MIN[0]); k < h -> FindBin(MAX[0]); k++){
                if(h -> GetBinContent(IndexMax) < h -> GetBinContent(k))
                {
                    IndexMax = k; 
                }
            }
            TF1* f1 = new TF1("f1", "gaus",70,85); 

            h -> Fit(f1, "SQ+", "", h -> GetBinCenter(IndexMax) - 2, h -> GetBinCenter(IndexMax) + 2); 

            std::cout<<Form("81_%d", j+1)<<"\t"<<f1 -> GetParameter(1)<<std::endl; 

            IndexMax = h -> FindBin(110); 
            for(Int_t k = h -> FindBin(MIN[1]); k < h -> FindBin(MAX[1]); k++){
                if(h -> GetBinContent(IndexMax) < h -> GetBinContent(k))
                {
                    IndexMax = k; 
                }
            }
            TF1* f2 = new TF1("f2", "gaus",110,130); 

            h -> Fit(f2, "SQ+", "", h -> GetBinCenter(IndexMax) - 2, h -> GetBinCenter(IndexMax) + 2); 

            std::cout<<Form("122_%d", j+1)<<"\t"<<f2 -> GetParameter(1)<<std::endl;
            IndexMax = h -> FindBin(340); 
            for(Int_t k = h -> FindBin(MIN[2]); k < h -> FindBin(MAX[2]); k++){
                if(h -> GetBinContent(IndexMax) < h -> GetBinContent(k))
                {
                    IndexMax = k; 
                }
            }
            TF1* f3 = new TF1("f3", "gaus",340,350); 

            h -> Fit(f3, "SQ+", "", h -> GetBinCenter(IndexMax) - 2, h -> GetBinCenter(IndexMax) + 2); 

            std::cout<<Form("344_%d", j+1)<<"\t"<<f3 -> GetParameter(1)<<std::endl;
            IndexMax = h -> FindBin(352); 
            for(Int_t k = h -> FindBin(MIN[3]); k < h -> FindBin(MAX[3]); k++){
                if(h -> GetBinContent(IndexMax) < h -> GetBinContent(k))
                {
                    IndexMax = k; 
                }
            }
            TF1* f4 = new TF1("f4", "gaus",352,360); 

            h -> Fit(f4, "SQ+", "", h -> GetBinCenter(IndexMax) - 2, h -> GetBinCenter(IndexMax) + 2); 

            std::cout<<Form("356_%d", j+1)<<"\t"<<f4 -> GetParameter(1)<<std::endl;
            IndexMax = h -> FindBin(770); 
            for(Int_t k = h -> FindBin(MIN[4]); k < h -> FindBin(MAX[4]); k++){
                if(h -> GetBinContent(IndexMax) < h -> GetBinContent(k))
                {
                    IndexMax = k; 
                }
            }
            TF1* f5 = new TF1("f5", "gaus",770,800); 

            h -> Fit(f5, "SQ+", "", h -> GetBinCenter(IndexMax) - 2, h -> GetBinCenter(IndexMax) + 2); 

            std::cout<<Form("779_%d", j+1)<<"\t"<<f5 -> GetParameter(1)<<std::endl;
            IndexMax = h -> FindBin(1380); 
            for(Int_t k = h -> FindBin(MIN[5]); k < h -> FindBin(MAX[5]); k++){
                if(h -> GetBinContent(IndexMax) < h -> GetBinContent(k))
                {
                    IndexMax = k; 
                }
            }
            TF1* f6 = new TF1("f6", "gaus",1380,1460); 

            h -> Fit(f6, "SQ+", "", h -> GetBinCenter(IndexMax) - 2, h -> GetBinCenter(IndexMax) + 2); 

            std::cout<<Form("1408_%d", j+1)<<"\t"<<f6 -> GetParameter(1)<<std::endl;
        }
    return 0; 
}