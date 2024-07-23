#define mytime_cxx
#include "mytime.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void mytime::Loop()
{
//   In a ROOT session, you can do:
//      root> .L mytime.C
//      root> mytime t
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
   TH2D *CE = new TH2D(Form("ha"),Form("hb"),1600,0,160,1600,0,160);
   // TH1D *H = new TH1D(Form("ceshi"), Form("ceshi"), 1600, -8000, 8000);
   // TH2D *CE[2];
   // TH1D *HDT[2];
   // TH1D *HE[2];
   // TH1D *HDE= new TH1D(Form("hdE"),Form("hdE"),1600,0,160);
   // for(int i=0; i<2; i++){
   //       CE[i] = new TH2D(Form("ha%d", i),Form("ha%d", i),1600,0,160,1600,0,160);
   //       HE[i] = new TH1D(Form("hE%d", i),Form("hE%d", i),2000,0,2000);
   //       HDT[i] = new TH1D(Form("hdt%d", i),Form("hdt%d", i),1600,-8000,8000);
   // }
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   Double_t dete,detE;
   Double_t ea;
   Double_t t1,t0;
   Double_t tt[2];
   Int_t cha1,cha2,cha3;
   Double_t g1,g2,g3;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      if(jentry%100000000 ==0) std::cout << "Finished "<< Form("%0.2f", 100.0*Double_t(jentry)/Double_t(nentries)) << "%" << std::endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      for(int i=0; i<2; i++)
      {
          tt[i] = -1;
      }
      t1 = -1;t0 = -1;g1=-10.0;dete=-10.0;detE=-10.0;ea=-10;      
      cha1 = 600;cha2 = 403;cha3 = 402;

   //    // if (Cut(ientry) < 0) continue;
       for(int i=0; i < nXIA ; i++)
       {
   //          if(channel[i] == 110 && t0 < 0)  
   //          { 
   //            g1 = Energy[i];
   //            t0 = t[i];
   //            HE[1]->Fill(g1);

   //          }         
            if(channel[i] == cha1 && t1 < 0)
            {
               dete = Energy[i];
               detE = dete*0.002385;
               t1 = t[i];        

            }
            if(channel[i] == cha2 && tt[0] < 0){
               ea = Energy[i];
               tt[0] = t[i];
               
            }
            // if(channel[i] == cha3 && tt[1] < 0){
            //    ea[1] = Energy[i];
            //    tt[1] = t[i];
            // }
            if(channel[i] == cha2 || channel[i] == cha1){
               if((tt[0] - t1) >= -60 && (tt[0]-t1 <=-10)){
                  CE ->Fill(ea,detE);
               }
            }
   //          if(channel[i] == cha3 || channel[i] == cha1){
   //             if((tt[1]-t1) >= -60 && (tt[1]-t1)<= -10){
   //                CE[1] ->Fill(ea[1],detE);
   //             }
   //          }
            // if(channel[i] == cha3 || channel[i] == 110){
            //    HDT[1] ->Fill(tt[0]-t0);
            // }

      //  }
      //  if(detE < 0) continue;

      //  if(ea[0] > 0.0)
      //  {
      //    HDT[0]->Fill(tt[0]-t1);

      //    if((tt[0]-t1) >= -60 && (tt[0]-t1)<= -10)
      //    CE[0] ->Fill(ea[0],detE);

      //  }
      //  if(ea[1] > 0.0)
      //  {
      //    HDT[1]->Fill(tt[1]-t1);
      //    if((tt[1]-t1) >= -60 && (tt[1]-t1)<= -10)
      //    CE[1] ->Fill(ea[1],detE);         
      //  }
      //  if(g1 < 0) continue;
      //  if(ea[0] > 0.0){         
      //    H->Fill(tt[0]-t0);         
      //    if((tt[0]-t0) >= -200 && (tt[0]-t0)<= 200)
      //    HE[0] ->Fill(g1);
      //  }
      //  for(int i=0; i<2; i++)
      //  {
      //    if(ea[i] < 0.0)   continue;         
      //    HDT[i]->Fill(tt[i]-t1);
      //    HE[i]->Fill(ea[i]);
      //    if((tt[i]-t1) >= -60 && (tt[i]-t1)<= -10)
      //       CE[i] ->Fill(ea[i],detE);         
       }
   
   }

//    TFile *f = new TFile(Form("Ddd.root"), "RECREATE");
//    f->cd();
//    for(int i=0; i<2; i++){
//       CE[i]->Write(Form("ha%d", i));
//       HDT[i]->Write(Form("hDT%d", i));
//       HE[i]->Write(Form("HE%d", i));
//    }
//    HDE->Write(Form("HDE"));
//    H->Write(Form("H"));
   // f->Close();
   CE->Draw("colz");  
}
