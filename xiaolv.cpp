#include<TFile.h>
#include<TH1D.h>
#include<TF1.h>
#include<TDirectoryFile.h>
#include<iostream>

Int_t xiaolv(){
    Int_t j = 0;
    TFile* d = TFile::Open("74kedu6gama74.root");
    TH1D *h = (TH1D*)d -> Get(Form("kd6gama_%02d", j));
    Int_t IndexMax = 0; 
    Int_t IndexNum = h -> GetNbinsX(); 
    IndexMax = h -> FindBin(76);
    double  count = 0;
    double bendi = 0;
    double bendi2 = 0;
    double bendi3 = 0;
    double bendi4 = 0;
    double bendi5 = 0;
    double total,zhen;
    for(Int_t k = h -> FindBin(76); k < h -> FindBin(84); k++){
        if(h -> GetBinContent(IndexMax) < h -> GetBinContent(k))
        {
            IndexMax = k; 
        }
        count += h ->GetBinContent(k);
        bendi = h ->GetBinContent(39);
        bendi2 = h ->GetBinContent(40);
        bendi3 = h ->GetBinContent(41);
        bendi4 = h ->GetBinContent(42);
        bendi5 = h ->GetBinContent(43);
        total = bendi + bendi2 + bendi3 + bendi4;
        if(bendi>bendi5)
        {zhen=total-4*bendi5;}
        else
        {zhen=total-4*bendi;}
    }
    std::cout<<count<<"\t"<<bendi<<"\t"<<bendi2<<"\t"<<bendi3<<"\t"<<bendi4<<"\t"<<total<<std::endl;
    std::cout<<zhen<<std::endl;
return 0;
}
