#define who_cxx
#include "who.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void who::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Dr.C
//      root> Dr t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   TH1D *H = new TH1D(Form("ceshi"), Form("ceshi"), 1600, 0, 160);
   TH2D *CE[2];
   TH1D *HDT[2];
   TH1D *HE[2];
   TH1D *HDE= new TH1D(Form("hdE"),Form("hdE"),1600,0,160);
   for(int i=0; i<2; i++){
         CE[i] = new TH2D(Form("ha%d", i),Form("ha%d", i),1600,0,160,1600,0,160);
         HE[i] = new TH1D(Form("hE%d", i),Form("hE%d", i),1600,0,160);
         HDT[i] = new TH1D(Form("hdt%d", i),Form("hdt%d", i),1600,-8000,8000);
   }
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   Double_t dete,detE;
   Double_t ea[2];
   Double_t t1,t0;
   Double_t tt[2];
   Int_t cha1,cha2,cha3;
   Double_t g1,g2,g3;
  
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
       if(jentry%100000000 ==0) std::cout << "Finished "<< Form("%0.2f", 100.0*Double_t(jentry)/Double_t(nentries)) << "%" << std::endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      cha1 = 600;cha2 = 403;cha3 = 402;

      for(int i=0; i<nXIA; i++)
      {
            if(data_XIA_channel[i] == 110)  
            { 
              g1 = data_XIA_Energy[i];
              t0 = data_XIA_Event_ts[i] + data_XIA_CFD[i];

            }         
            if(data_XIA_channel[i] == cha1)
            {
               dete = data_XIA_Energy[i];
               detE = dete*0.002385;
               t1 = data_XIA_Event_ts[i] + data_XIA_CFD[i];
               HDE->Fill(detE);          

            }
            if(data_XIA_channel[i] == cha2){
               ea[0] = data_XIA_Energy[i];
               tt[0] = data_XIA_Event_ts[i] + data_XIA_CFD[i];
               H->Fill(ea[0]);
               
            }
            if(data_XIA_channel[i] == cha3){
               ea[1] = data_XIA_Energy[i];
               tt[1] = data_XIA_Event_ts[i] + data_XIA_CFD[i];
            }

      }
       for(int i=0; i<2; i++)
       {
         if(ea[i] < 0.0)   continue;
         if(detE > 0.0)
         {
            HDT[i]->Fill(tt[i]-t1);
            HE[i]->Fill(ea[i]);
            if((tt[i]-t1) >= -60 && (tt[i]-t1)<= -10)
               CE[i] ->Fill(ea[i],detE);
         }
       }
      // if (Cut(ientry) < 0) continue;
   }
   TFile *f = new TFile(Form("who%d.root", RunNo), "RECREATE");
   f->cd();
   for(int i=0; i<2; i++){
      CE[i]->Write(Form("ha%d", i));
      HDT[i]->Write(Form("hDT%d", i));
      HE[i]->Write(Form("HE%d", i));
   }
   HDE->Write(Form("HDE"));
   H->Write(Form("H"));
   f->Close();
}
