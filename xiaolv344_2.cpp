#include<TFile.h>
#include<TH1D.h>
#include<TF1.h>
#include<TDirectoryFile.h>
#include<iostream>

Int_t xiaolv344_2(){
    Int_t j = 0;
    TFile* f = TFile::Open("run00074_final.root");
    TDirectoryFile *d = (TDirectoryFile*)f->Get("hist_dir");
    TH1D *h = (TH1D*)d -> Get(Form("hist_XIA_00_%02d", j));
    Int_t IndexMax = 0; 
    Int_t IndexNum = h -> GetNbinsX(); 
    IndexMax = h -> FindBin(1824);
    double  count = 0;
    double_t bendi[9];
    double total,zhen;
    for(Int_t k = h -> FindBin(1824); k < h -> FindBin(1860); k++){
        if(h -> GetBinContent(IndexMax) < h -> GetBinContent(k))
        {
            IndexMax = k; 
        }
        count += h ->GetBinContent(k);   
    }
    for(int i = 0; i < 9; i ++){
        bendi[i] = h ->GetBinContent(i+457);
        total = bendi[1] + bendi[2] + bendi[3] + bendi[4] + bendi[5] + bendi[6] + bendi[7];;
        if(bendi[0] > bendi[8])
            {zhen = total - 7 * bendi[8];}
        else
            {zhen = total - 7 * bendi[0];}
    }
    
    std::cout<<count<<"\t"<<bendi[1]<<"\t"<<bendi[2]<<"\t"<<bendi[3]<<"\t"<<bendi[4]<<"\t"<<total<<std::endl;
    std::cout<<zhen<<std::endl;
return 0;
}
