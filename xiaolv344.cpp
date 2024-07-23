#include<TFile.h>
#include<TH1D.h>
#include<TF1.h>
#include<TDirectoryFile.h>
#include<iostream>

Int_t xiaolv344(){
    Int_t j = 12;
    TFile* d = TFile::Open("74kedu6gama74.root");
    TH1D *h = (TH1D*)d -> Get(Form("kd6gama_%02d", j));
    Int_t IndexMax = 0; 
    Int_t IndexNum = h -> GetNbinsX(); 
    IndexMax = h -> FindBin(340);
    double  count = 0;
    double_t bendi[4];
    double total,zhen;
    for(Int_t k = h -> FindBin(340); k < h -> FindBin(348); k++){
        if(h -> GetBinContent(IndexMax) < h -> GetBinContent(k))
        {
            IndexMax = k; 
        }
        count += h ->GetBinContent(k);   
    }
    for(int i = 0; i < 4; i ++){
        bendi[i] = h ->GetBinContent(i+171);
        total = bendi[1] + bendi[2];
        //  + bendi[3]  + bendi[3] + bendi[4];
        if(bendi[0] > bendi[3])
            {zhen = total - 2 * bendi[3];}
        else
            {zhen = total - 2 * bendi[0];}
    }
    
    std::cout<<count<<"\t"<<bendi[1]<<"\t"<<bendi[2]<<"\t"<<bendi[3]<<"\t"<<total<<std::endl;
    std::cout<<zhen<<std::endl;
return 0;
}
