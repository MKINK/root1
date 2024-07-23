#include<TFile.h>
#include<TH1f.h>
#include<TF1.h>
#include<TDirectoryFile.h>
#include<iostream>

Int_t Calibrateg(){
    TFile* File = TFile::Open("run00074_final.root");
    TDirectoryFile *d = (TDirectoryFile*)File->Get("hist_dir");
        for(Int_t j = 0; j < 12; j++)
        {
            TH1F *h = (TH1F*)d -> Get(Form("hist_XIA_00_%02d", j)); 
            Int_t IndexMax = 0; 
            Int_t IndexNum = h -> GetNbinsX(); 
            for(Int_t k = 0; k < IndexNum; k++){
                if((h -> GetBinContent(IndexMax) < h -> GetBinContent(k) || h -> GetBinCenter(IndexMax) < 1000) && h -> GetBinCenter(k) < 2500 && h -> GetBinCenter(k) > 1000)
                {
                    IndexMax = k; 
                }
            }
            TF1* f = new TF1("f", "gaus",1000,2500); 

            h -> Fit(f, "SQ+", "", h -> GetBinCenter(IndexMax) - 10, h -> GetBinCenter(IndexMax) + 10); 

            std::cout<<Form("EA%d", j+1)<<"\t"<<f -> GetParameter(1)<<std::endl; 
        }
        for(Int_t i = 0; i < 4; i++)
        {
            TH1F *h1 = (TH1F*)d -> Get(Form("hist_XIA_01_%02d", i)); 
            Int_t IndexMax = 0; 
            Int_t IndexNum = h1 -> GetNbinsX(); 
            for(Int_t k = 0; k < IndexNum; k++){
                if((h1 -> GetBinContent(IndexMax) < h1 -> GetBinContent(k) || h1 -> GetBinCenter(IndexMax) < 1000) && h1 -> GetBinCenter(k) < 2500 && h1 -> GetBinCenter(k) > 1000)
                {
                    IndexMax = k; 
                }
            }
            TF1* f = new TF1("f", "gaus",1000,2500); 

            h1 -> Fit(f, "SQ+", "", h1 -> GetBinCenter(IndexMax) - 10, h1 -> GetBinCenter(IndexMax) + 10); 

            std::cout<<Form("EB%d", i+1)<<"\t"<<f -> GetParameter(1)<<std::endl; 
        }
    return 0; 
}