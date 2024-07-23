#include<TFile.h>
#include<TH2F.h>
#include<TH1D.h>
#include<TF1.h>
#include<iostream>

Int_t canewE(){
    TFile* File = new TFile("KDetE_E_71.root", "read"); 
    Int_t LA[] = {0, 1, 8, 9}; 
    for(Int_t i = 0; i < 4; i++)
        for(Int_t j = 400; j < 413; j++){
            TH2F *h = (TH2F*)File -> Get(Form("hA%d_%d", LA[i], j)); 
            TH1D *H = h -> ProjectionX(); 

            Int_t IndexMax = 0; 
            Int_t IndexNum = H -> GetNbinsX(); 
            for(Int_t k = 0; k < IndexNum; k++){
                if(H -> GetBinContent(IndexMax) < H -> GetBinContent(k)  || H -> GetBinCenter(IndexMax) < 60){
                    IndexMax = k; 
                }
            }
            TF1* f = new TF1("f", "gaus"); 

            H -> Fit(f, "SQ+", "", H -> GetBinCenter(IndexMax) - 2, H -> GetBinCenter(IndexMax) + 2); 

            std::cout<<Form("hA%d_%d", LA[i], j)<<"\t"<<f -> GetParameter(1)<<std::endl; 
        }
    Int_t LB[] = {3, 4, 6}; 
    for(Int_t i = 0; i < 3; i++)
        for(Int_t j = 502; j < 513; j++){
            TH2F *h = (TH2F*)File -> Get(Form("hB%d_%d", LB[i], j)); 
            TH1D *H = h -> ProjectionX(); 

            Int_t IndexMax = 0; 
            Int_t IndexNum = H -> GetNbinsX(); 
            for(Int_t k = 0; k < IndexNum; k++){
                if(H -> GetBinContent(IndexMax) < H -> GetBinContent(k)  || H -> GetBinCenter(IndexMax) < 60){
                    IndexMax = k; 
                }
            }
            TF1* f = new TF1("f", "gaus"); 

            H -> Fit(f, "SQ+", "", H -> GetBinCenter(IndexMax) - 2, H -> GetBinCenter(IndexMax) + 2); 

            std::cout<<Form("hB%d_%d", LB[i], j)<<"\t"<<f -> GetParameter(1)<<std::endl; 
        }
    return 0; 
}