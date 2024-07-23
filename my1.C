#define my1_cxx
#include "my1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<TTree.h>
#include<TCutG.h>

void my1::Loop()
{
//   In a ROOT session, you can do:
//      root> .L my1.C
//      root> my1 t
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
   TH1D *H1 = new TH1D(Form("H"), Form("H"), 2000, 0, 2000);
   TH2D *HH1 = new TH2D(Form("ha"),Form("hb"),1600,0,160,1600,0,160);   
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
   // tree->Draw("Energy[1]*0.002385:Energy[0]>>ha(1600,0,160,1600,0,160)","channel[1]==600 && channel[0]==403","colz");
   // gROOT->Macro(Form("cut%02d%02d.C", i, j));
   gROOT->Macro("cutttt.C");   
   TCutG *cutttt = (TCutG *)gROOT->GetListOfSpecials()->FindObject("cutttt");   
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
      for(int i=0; i < nXIA ; i++) if(channel[i]== 603 ||  channel[i]== 604 || channel[i]== 606) 
         for(int j=0; j < nXIA ; j++) if(channel[j] < 600 && channel[j] > 501) 
            if(cutttt -> IsInside( Energy[j],Energy[i] * 0.002385)) 
               for(int k=0; k < nXIA; k++)   if(channel[k] < 299)
               {
               // std::cout << "Condition met at index: " << i << std::endl;
                  HH1->Fill(Energy[j],Energy[i]* 0.002385);
                  H1->Fill(Energy[k]);    
            // if(channel[i] == cha3 && tt[1] < 0){
            //    ea[1] = Energy[i];
            //    tt[1] = t[i];
            // }
            // if(channel[i] == cha2 || channel[i] == cha1){
            //    if((tt[0] - t1) >= -60 && (tt[0]-t1 <=-10)){
            //       CE ->Fill(ea,detE);
            //    }
            // }
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
   TCanvas* canvas1 = new TCanvas();
   H1->Draw();
   TCanvas* canvas2 = new TCanvas();
   HH1-> Draw("colz");     
}
