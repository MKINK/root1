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
   TH2D *HA1[13];
   TH2D *HA2[13];
   TH2D *HA9[13];
   TH2D *HA10[13];
   TH2D *HB4[11];
   TH2D *HB5[11];
   TH2D *HB7[11];
   for(int i=0; i<13; i++){
        HA1[i]= new TH2D(Form("hA1%d", i), Form("hA1%d", i), 1600, 0, 160, 1600, 0, 160);
        HA2[i]= new TH2D(Form("hA2%d", i), Form("hA2%d", i), 1600, 0, 160, 1600, 0, 160);
        HA9[i]= new TH2D(Form("hA9%d", i), Form("hA9%d", i), 1600, 0, 160, 1600, 0, 160);
        HA10[i]= new TH2D(Form("hA10%d", i), Form("hA10%d", i), 1600, 0, 160, 1600, 0, 160);

   }
   for(int i=0; i<11; i++){
        HB4[i]= new TH2D(Form("hB4%d", i), Form("hB4%d", i), 1600, 0, 160, 1600, 0, 160);
        HB5[i]= new TH2D(Form("hB5%d", i), Form("hB5%d", i), 1600, 0, 160, 1600, 0, 160);
        HB7[i]= new TH2D(Form("hB7%d", i), Form("hB7%d", i), 1600, 0, 160, 1600, 0, 160);
   } 
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
  
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   Int_t MOD4[] = {400,401,402,403,404,405,406,407,408,409,410,411,412};
   Int_t MOD5[] = {502,503,504,505,506,507,508,509,510,511,512};
   Int_t Mu;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      if(jentry%100000000 ==0) std::cout << "Finished "<< Form("%0.2f", 100.0*Double_t(jentry)/Double_t(nentries)) << "%" << std::endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;


      for(int i=0; i < nXIA ; i++){
        if(channel[i]== 600){
            Mu=0;
            for(int j=0; j < nXIA ; j++){
                for(int i0=0; i0<13;i0++){
                   if(channel[j] == MOD4[i0] && t[j] -t[i] >=-40 && t[j] -t[i] <= 0){                    
                        Mu=Mu+1;
                        if(Mu<2){
                            HA1[i0]->Fill(Energy[j]+Energy[i],Energy[i]);
                        }
                   } 
                }
            }
        }
        if(channel[i]== 601){
            for(int j=0; j < nXIA ; j++){
                for(int i1=0; i1<13;i1++){
                   if(channel[j] == MOD4[i1] && t[j] -t[i] >=-40 && t[j] -t[i] <= 0){
                    HA2[i1]->Fill(Energy[j]+Energy[i],Energy[i]);
                    break;
                   } 
                }
            }
        } 
        if(channel[i]== 608){
            for(int j=0; j < nXIA ; j++){
                for(int i8=0; i8<13;i8++){
                   if(channel[j] == MOD4[i8] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60 && nXIA = 2){
                    HA9[i8]->Fill(Energy[j]+Energy[i],Energy[i]);
                    break;
                   } 
                } 
            }
        }  
        if(channel[i]== 609){
            for(int j=0; j < nXIA ; j++){
                for(int i9=0; i9<13;i9++){
                   if(channel[j] == MOD4[i9] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60){
                    HA10[i9]->Fill(Energy[j]+Energy[i],Energy[i]);
                    break;
                   } 
                } 
            }
        }
        if(channel[i]== 603){
            for(int j=0; j < nXIA ; j++){
                for(int i3=0; i3<11;i3++){
                   if(channel[j] == MOD5[i3] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60){
                    HB4[i3]->Fill(Energy[j]+Energy[i],Energy[i]);
                    break;
                   } 
                } 
            }
        } 
        if(channel[i]== 604){
            for(int j=0; j < nXIA ; j++){
                for(int i4=0; i4<11;i4++){
                   if(channel[j] == MOD5[i4] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60){
                    HB5[i4]->Fill(Energy[j]+Energy[i],Energy[i]);
                    break;
                   } 
                } 
            }
        }  
        if(channel[i]== 606){
            for(int j=0; j < nXIA ; j++){
                for(int i6=0; i6<11;i6++){
                   if(channel[j] == MOD5[i6] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60){
                    HB7[i6]->Fill(Energy[j]+Energy[i],Energy[i]);
                    break;
                   } 
                } 
            }
        }                    
      }
   }

   TFile *f = new TFile(Form("ceshi3S4I%d.root",RunNo), "RECREATE");
   f->cd();
   for(int i=0; i<13; i++){
      HA1[i]->Write(Form("HA1_%02d", i));
      HA2[i]->Write(Form("HA2_%02d", i));
      HA9[i]->Write(Form("HA9_%02d", i));
      HA10[i]->Write(Form("HA10_%02d", i));
    }
   for(int i=0; i<11; i++){
      HB4[i]->Write(Form("HB4_%02d", i));
      HB5[i]->Write(Form("HB5_%02d", i));
      HB7[i]->Write(Form("HB7_%02d", i));
    }
   f->Close();
}
