#include<TFile.h>
#include<TH1F.h>
#include<TF1.h>
#include<TDirectoryFile.h>
#include<iostream>

Int_t CalibrateE(){
    TFile* File = TFile::Open("run00039_final.root");
    TDirectoryFile *d = (TDirectoryFile*)File->Get("hist_dir");
        for(Int_t j = 0; j < 13; j++)
        {
            TH1F *h = (TH1F*)d -> Get(Form("hist_XIA_03_%02d", j)); 
            Int_t IndexMax = 0; 
            Int_t IndexNum = h -> GetNbinsX(); 
            for(Int_t k = 0; k < IndexNum; k++){
                if((h -> GetBinContent(IndexMax) < h -> GetBinContent(k) || h -> GetBinCenter(IndexMax) < 1000) && h -> GetBinCenter(k) < 6e4 && h -> GetBinCenter(k) > 4.5e4)
                {
                    IndexMax = k; 
                }
            }
            TF1* f = new TF1("f", "gaus",50000,60000); 

            h -> Fit(f, "SQ+", "", h -> GetBinCenter(IndexMax) - 300, h -> GetBinCenter(IndexMax) + 300); 

            std::cout<<Form("EA%d", j+1)<<"\t"<<f -> GetParameter(1)<<std::endl; 
        }
        for(Int_t i = 2; i < 13; i++)
        {
            TH1F *h1 = (TH1F*)d -> Get(Form("hist_XIA_04_%02d", i)); 
            Int_t IndexMax = 0; 
            Int_t IndexNum = h1 -> GetNbinsX(); 
            for(Int_t k = 0; k < IndexNum; k++){
                if((h1 -> GetBinContent(IndexMax) < h1 -> GetBinContent(k) || h1 -> GetBinCenter(IndexMax) < 1000) && h1 -> GetBinCenter(k) < 6e4 && h1 -> GetBinCenter(k) > 4.5e4)
                {
                    IndexMax = k; 
                }
            }
            TF1* f = new TF1("f", "gaus",50000,60000); 

            h1 -> Fit(f, "SQ+", "", h1 -> GetBinCenter(IndexMax) - 300, h1 -> GetBinCenter(IndexMax) + 300); 

            std::cout<<Form("EB%d", i+1)<<"\t"<<f -> GetParameter(1)<<std::endl; 
        }
    return 0; 
}