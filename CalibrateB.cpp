#include<TFile.h>
#include<TH2F.h>
#include<TH1D.h>
#include<TF1.h>
#include<iostream>

Int_t CalibrateB(){
    TFile* File = new TFile("wDetE_E_63.root", "read"); 
    Int_t LB[] = {3, 4, 6}; 
    for(Int_t i = 0; i < 3; i++)
        for(Int_t j = 502; j < 513; j++){
            TH2F *h = (TH2F*)File -> Get(Form("hB%d_%d", LB[i], j)); 
            TH1D *H = h -> ProjectionY(); 

            Int_t IndexMax = 0; 
            Int_t IndexNum = H -> GetNbinsX(); 
            for(Int_t k = 0; k < IndexNum; k++){
                if(H -> GetBinContent(IndexMax) < H -> GetBinContent(k) || H -> GetBinCenter(IndexMax) < 1000){
                    IndexMax = k; 
                }
            }
            TF1* f = new TF1("f", "gaus"); 

            H -> Fit(f, "SQ+", "", H -> GetBinCenter(IndexMax) - 500, H -> GetBinCenter(IndexMax) + 500); 

            std::cout<<Form("hB%d_%d", LB[i], j)<<"\t"<<f -> GetParameter(1)<<std::endl; 
        }
    return 0; 
}