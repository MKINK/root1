#define Dr_cxx
#include "Dr.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Dr::Loop()
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
    TH2D *hA1[10];
    TH1D *hdtA1[10];
    TH2D *hB1[10];
    TH1D *hdtB1[10];
    for(int i=0; i<10; i++) 
    {
        hA1[i]= new TH2D(Form("hA%d", i), Form("hA%d", i), 7000, 0, 70000, 6000, 0, 60000);
        hdtA1[i] = new TH1D(Form("hdtA%d", i), Form("hdtA%d", i), 1600, -8000, 8000);
        hB1[i]= new TH2D(Form("hB%d", i), Form("hB%d", i), 7000, 0, 70000, 6000, 0, 60000);
        hdtB1[i] = new TH1D(Form("hdtB%d", i), Form("hdtB%d", i), 1600, -8000, 8000);
    }
//    Double_t A1tmin[10] = {-30, -30, 0,   0, };
//    Double_t A1tmax[10] = {0,   0,   0,   0};
//    Double_t B1tmin[10] = {0,   0,   0, -30, -30};
//    Double_t B1tmax[10] = {0,   0,   0, -10, };

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   Double_t detE[10];
   Double_t t[10];
   Int_t chA1, chA2;
   Double_t EA1, EA2;
   Double_t tA1, tA2;
   Int_t chB1, chB2;
   Double_t EB1, EB2;
   Double_t tB1, tB2;
  
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
       if(jentry%1000000 ==0) std::cout << "Finished "<< Form("%0.2f", 100.0*Double_t(jentry)/Double_t(nentries)) << "%" << std::endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      for(int i=0; i<10; i++)
      {
          detE[i] = -10.0;
          t[i] = -1;
      }
      chA1 = 403;
      chA2 = 408;
      EA1 = -10.0;
      EA2 = -10.0;
      tA1 = -1;
      tA2 = -1;
      chB1 = 503;
      EB1 = -10.0;
      tB1 = -1;
      for(int i=0; i<nXIA; i++)
      {
          if(data_XIA_channel[i] >= 600 && t[data_XIA_channel[i] - 600] < 0)  
          { 
              detE[data_XIA_channel[i] - 600] = data_XIA_Energy[i];
              t[data_XIA_channel[i] - 600] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
          }
          if( data_XIA_channel[i] == chA1 && tA1 < 0)   
          {
              EA1 = data_XIA_Energy[i];
              tA1 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
          }
          if( data_XIA_channel[i] == chA2 && tA2 < 0)   
          {
              EA2 = data_XIA_Energy[i];
              tA2 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
          }
          if( data_XIA_channel[i] == chB1 && tB1 < 0)   
          {
              EB1 = data_XIA_Energy[i];
              tB1 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
          }
      }
      for(int i=0; i<10; i++)
      {
            if(detE[i] < 0.0)   continue;
            if(EA1 > 0.0)
            {
                hdtA1[i]->Fill(tA1-t[i]);
                if((tA1-t[i]) >= -60 && (tA1-t[i]) <= -10)
                    hA1[i]->Fill(EA1, detE[i]);
            }
            if(EB1 > 0.0)
            {
                hdtB1[i]->Fill(tB1-t[i]);
                if((tB1-t[i]) >= -60 && (tB1-t[i]) <= 60)
                    hB1[i]->Fill(EB1, detE[i]);
            }
      }
      // if (Cut(ientry) < 0) continue;
   }
   TFile *f = new TFile(Form("DetE_E_%d.root", RunNo), "RECREATE");
   f->cd();
   for(int i=0; i<10; i++)
   {
        hA1[i]->Write(Form("hA%d_%d", i, chA1));
        hdtA1[i]->Write(Form("hdtA%d_%d", i, chA1));
        hB1[i]->Write(Form("hB%d_%d", i, chB1));
        hdtB1[i]->Write(Form("hdtB%d_%d", i, chB1));
   }
   f->Close();
}
