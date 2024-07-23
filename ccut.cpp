#include<TFile.h>
#include<TH2F.h>
#include<TH1D.h>
#include<TF1.h>
#include<iostream>
#include<TTree.h>
#include<TCutG.h>

void ccut(){
    TFile* File = new TFile("kdstore39.root", "read");
    TTree* tree = (TTree*)File->Get("tree");
    tree->SetBranchAddress("nXIA", &nXIA);
    tree->Draw("Energy[1]*0.002385:Energy[0]>>ha(1600,0,160,1600,0,160)","channel[1]==600 && channel[0]==403","colz");
    gROOT->Macro("cut1.C");
    TCutG *cut1 = (TCutG *)gROOT->GetListOfSpecials()->FindObject("cut1");
    

}