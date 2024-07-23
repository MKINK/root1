#define ggtt_cxx
#include "ggtt.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include<TTree.h>
#include<TCutG.h>
#include<TRandom3.h>

void ggtt::Loop()
{
//   In a ROOT session, you can do:
//      root> .L get.C
//      root> get t
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
   TH1D *HA[18];
   TH1D *HB[18];
   for(int i=0; i<18; i++){
      HA[i] = new TH1D(Form("ha%d", i), Form("ha%d", i), 2048, 0, 1800);
      HB[i] = new TH1D(Form("hb%d", i), Form("hb%d", i), 2048, 0, 1800);
   }
   TH2D *HH1 = new TH2D(Form("ha"),Form("hb"),1600,0,160,1600,0,160);
   TH2D *HH2 = new TH2D(Form("hc"),Form("hd"),1600,0,160,1600,0,160);   
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
   gROOT->Macro("cut0103.C");   
   TCutG *cut0103 = (TCutG *)gROOT->GetListOfSpecials()->FindObject("cut0103");   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   Double_t dete,detE;
   Double_t ea;
   Double_t t1,t0;
   Double_t tt[2];
   Double_t ttt[18];
   Double_t ccc[18];
   Int_t cha1,cha2,cha3;
   Double_t g1,g2,g3;
   TRandom3 *r = new TRandom3(0);
   Int_t lookup[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 200, 201, 202, 203, 204, 205};

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
      // for(int i=0; i < nXIA ; i++) if(channel[i]== 603 ||  channel[i]== 604 || channel[i]== 606) 
      //    for(int j=0; j < nXIA ; j++) if(channel[j] < 600 && channel[j] > 501) 
      //       if(cutttt -> IsInside(Energy[i], Energy[j])) 
      //          for(int k=0; k < nXIA; k++)   if(channel[k] < 107 && channel[k] > 103)
      //          {
      //             ea=Energy[k]+r->Rndm()*0.2;
      //             HH1->Fill(Energy[i], Energy[j]);
      //             H1->Fill(Energy[k]);
      //             H2->Fill(ea);           
      //  }
      for(int i=0; i < nXIA ; i++){
         if(channel[i]== 603 ||  channel[i]== 604 || channel[i]== 606){
            for(int j=0; j < nXIA ; j++){
               if(channel[j] < 513 && channel[j] > 501 && cut0103 -> IsInside(Energy[j]+Energy[i], Energy[i])){
                  for(int k=0; k < nXIA; k++){
                     for(int ii = 0; ii < 18; ii++){
                        if(channel[k] == lookup[ii]){
                           HA[ii]->Fill(Energy[k]);
                           break;
                        }
                     }
                     // if(channel[k] == 100){
                     //    HA[0]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 101){
                     //    HA[1]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 102){
                     //    HA[2]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 103){
                     //    HA[3]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 104){
                     //    HA[4]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 105){
                     //    HA[5]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 106){
                     //    HA[6]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 107){
                     //    HA[7]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 108){
                     //    HA[8]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 109){
                     //    HA[9]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 110){
                     //    HA[10]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 111){
                     //    HA[11]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 200){
                     //    HA[12]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 201){
                     //    HA[13]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 202){
                     //    HA[14]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 203){
                     //    HA[15]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 204){
                     //    HA[16]->Fill(Energy[k]);
                     // }
                     // if(channel[k] == 205){
                     //    HA[17]->Fill(Energy[k]);
                     // }                                                                                                                                                                                                              
                     // if((channel[k] < 112 && channel[k] >= 100) || (channel[k]  >= 200 && channel[k] <206)){
                     //    if(channel[k] >= 100){
                     //       ttt[index1] = Energy[k];
                     //       std::cout << index1 << std::endl;
                     //       HA[index1]->Fill(ttt[index1]);
                     //       index1++;
                     //    }
                     // }
                        // ea=Energy[k]+r->Rndm()*0.2;
                     HH1->Fill(Energy[j]+Energy[i], Energy[i]);
                  }
               }
            }
         }
         // std::cout << "qq" << std::endl;
         if(channel[i]== 601 ||  channel[i]== 600 || channel[i]== 608 || channel[i]== 609)
         {  for(int a=0; a < nXIA ; a++){
               if(channel[a] < 413 && channel[a] >= 400 && cut0103 -> IsInside(Energy[a]+Energy[i], Energy[i])){
                  for(int c=0; c < nXIA; c++){
                     for(int cc = 0; cc < 18; cc++){
                        if(channel[c] == lookup[cc]){
                           HB[cc]->Fill(Energy[c]);
                           break;
                        }
                     }                     
                     HH2->Fill(Energy[a]+Energy[i], Energy[i]);
                  }
               }
            }
         }            
      }
      //   if(channel[i]== 601 ||  channel[i]== 600 || channel[i]== 608 || channel[i]== 609) 
   //     for(int a=0; a < nXIA ; a++){
   //       if(channel[a] == 100){
   //          
   //          
   //       }
   //     }
   
   }
   // std::cout << "qq" << std::endl;

   TFile *f = new TFile(Form("da%d.root",RunNo), "RECREATE");
   f->cd();
   for(int i=0; i<18; i++){
      HA[i]->Write(Form("ha%02d", i));
      HB[i]->Write(Form("hb%02d", i));
   }
   HH1->Write(Form("HH1"));
   HH2->Write(Form("HH2"));
   f->Close();
   // TCanvas* canvas1 = new TCanvas();
   // H1->Draw();
   // TCanvas* canvas2 = new TCanvas();
   // HH1-> Draw("colz");
   // TCanvas* canvas3 = new TCanvas();
   // H2->Draw();
   // TCanvas* canvas4 = new TCanvas();
   // HH2-> Draw("colz");     
}
