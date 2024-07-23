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
   TH1D *Ha1[18];
   TH1D *Ha2[18];
   TH1D *Ha9[18];
   TH1D *Ha10[18];
   TH1D *Hb4[18];
   TH1D *Hb5[18]; 
   TH1D *Hb7[18];     
   for(int i=0; i<18; i++){
      Ha1[i] = new TH1D(Form("ha1%d", i), Form("ha1%d", i), 2048, 0, 1600);
      Ha2[i] = new TH1D(Form("ha2%d", i), Form("ha2%d", i), 2048, 0, 1600);
      Ha9[i] = new TH1D(Form("ha9%d", i), Form("ha9%d", i), 2048, 0, 1600);
      Ha10[i] = new TH1D(Form("ha10%d", i), Form("ha10%d", i), 2048, 0, 1600);
      Hb4[i] = new TH1D(Form("hb4%d", i), Form("hb4%d", i), 2048, 0, 1600);
      Hb5[i] = new TH1D(Form("hb5%d", i), Form("hb5%d", i), 2048, 0, 1600);
      Hb7[i] = new TH1D(Form("hb7%d", i), Form("hb7%d", i), 2048, 0, 1600);
   } 
   gROOT->Macro("cut0103.C"); 
   gROOT->Macro("cut0903.C"); 
   TCutG *cut0103 = (TCutG *)gROOT->GetListOfSpecials()->FindObject("cut0103"); 
   TCutG *cut0903 = (TCutG *)gROOT->GetListOfSpecials()->FindObject("cut0903"); 

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   Int_t lookup[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 200, 201, 202, 203, 204, 205};
   Int_t MOD4[] = {400,401,402,403,404,405,406,407,408,409,410,411,412};
   Int_t MOD5[] = {502,503,504,505,506,507,508,509,510,511,512};

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      if(jentry%100000000 ==0) std::cout << "Finished "<< Form("%0.2f", 100.0*Double_t(jentry)/Double_t(nentries)) << "%" << std::endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;


      for(int i=0; i < nXIA ; i++){
        if(channel[i]== 600){
            for(int j=0; j < nXIA ; j++){
                for(int i0=0; i0<13;i0++){
                   if(channel[j] == MOD4[i0] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60 && cut0103 -> IsInside(Energy[j]+Energy[i], Energy[i])){
                        HA1[i0]->Fill(Energy[j]+Energy[i],Energy[i]);                        
                        for(int k=0; k < nXIA; k++){
                            if(channel[j] < 413 && channel[j] >= 400){                    
                                for(int cc = 0; cc < 18; cc++){
                                    if(channel[k] == lookup[cc]){
                                        Ha1[cc]->Fill(Energy[k]);
                                        break;
                                    }
                                }
                            }
                        }
                    break;
                   } 
                }
            }
        }
        if(channel[i]== 601){
            for(int j=0; j < nXIA ; j++){
                for(int i1=0; i1<13;i1++){
                   if(channel[j] == MOD4[i1] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60 && cut0103 -> IsInside(Energy[j]+Energy[i], Energy[i])){
                        HA2[i1]->Fill(Energy[j]+Energy[i],Energy[i]);
                        for(int k=0; k < nXIA; k++){
                            if(channel[j] < 413 && channel[j] >= 400){                    
                                for(int cc = 0; cc < 18; cc++){
                                    if(channel[k] == lookup[cc]){
                                        Ha2[cc]->Fill(Energy[k]);
                                        break;
                                    }
                                }
                            }                        
                        }
                    break;
                   } 
                }
            }
        } 
        if(channel[i]== 608){
            for(int j=0; j < nXIA ; j++){
                for(int i8=0; i8<13;i8++){
                   if(channel[j] == MOD4[i8] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60 && cut0903 -> IsInside(Energy[j]+Energy[i], Energy[i])){
                        HA9[i8]->Fill(Energy[j]+Energy[i],Energy[i]);
                        for(int k=0; k < nXIA; k++){
                            if(channel[j] < 413 && channel[j] >= 400){                    
                                for(int cc = 0; cc < 18; cc++){
                                    if(channel[k] == lookup[cc]){
                                        Ha9[cc]->Fill(Energy[k]);
                                        break;
                                    }
                                }
                            }                        
                        }
                    break;
                   } 
                } 
            }
        }  
        if(channel[i]== 609){
            for(int j=0; j < nXIA ; j++){
                for(int i9=0; i9<13;i9++){
                   if(channel[j] == MOD4[i9] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60 && cut0103 -> IsInside(Energy[j]+Energy[i], Energy[i])){
                        HA10[i9]->Fill(Energy[j]+Energy[i],Energy[i]);
                        for(int k=0; k < nXIA; k++){
                            if(channel[j] < 413 && channel[j] >= 400){                    
                                for(int cc = 0; cc < 18; cc++){
                                    if(channel[k] == lookup[cc]){
                                        Ha10[cc]->Fill(Energy[k]);
                                        break;
                                    }
                                }
                            }                        
                        }                        
                    break;
                   } 
                } 
            }
        }
        if(channel[i]== 603){
            for(int j=0; j < nXIA ; j++){
                for(int i3=0; i3<11;i3++){
                   if(channel[j] == MOD5[i3] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60 && cut0103 -> IsInside(Energy[j]+Energy[i], Energy[i])){
                        HB4[i3]->Fill(Energy[j]+Energy[i],Energy[i]);
                        for(int k=0; k < nXIA; k++){
                            if(channel[j] < 513 && channel[j] >= 502){                    
                                for(int cc = 0; cc < 18; cc++){
                                    if(channel[k] == lookup[cc]){
                                        Hb4[cc]->Fill(Energy[k]);
                                        break;
                                    }
                                }
                            }                        
                        }   
                    break;
                   } 
                } 
            }
        } 
        if(channel[i]== 604){
            for(int j=0; j < nXIA ; j++){
                for(int i4=0; i4<11;i4++){
                   if(channel[j] == MOD5[i4] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60 && cut0103 -> IsInside(Energy[j]+Energy[i], Energy[i])){
                        HB5[i4]->Fill(Energy[j]+Energy[i],Energy[i]);
                        for(int k=0; k < nXIA; k++){
                            if(channel[j] < 513 && channel[j] >= 502){                    
                                for(int cc = 0; cc < 18; cc++){
                                    if(channel[k] == lookup[cc]){
                                        Hb5[cc]->Fill(Energy[k]);
                                        break;
                                    }
                                }
                            }                        
                        }                         
                    break;
                   } 
                } 
            }
        }  
        if(channel[i]== 606){
            for(int j=0; j < nXIA ; j++){
                for(int i6=0; i6<11;i6++){
                   if(channel[j] == MOD5[i6] && t[j] -t[i] >=-60 && t[j] -t[i] <= 60 && cut0103 -> IsInside(Energy[j]+Energy[i], Energy[i])){
                        HB7[i6]->Fill(Energy[j]+Energy[i],Energy[i]);
                        for(int k=0; k < nXIA; k++){
                            if(channel[j] < 513 && channel[j] >= 502){                    
                                for(int cc = 0; cc < 18; cc++){
                                    if(channel[k] == lookup[cc]){
                                        Hb7[cc]->Fill(Energy[k]);
                                        break;
                                    }
                                }
                            }                        
                        }                         
                    break;
                   } 
                } 
            }
        }                    
      }
   }

   TFile *f = new TFile(Form("danew%d.root",RunNo), "RECREATE");
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
   for(int i=0; i<18; i++){
      Ha1[i]->Write(Form("ha1%02d", i));
      Ha2[i]->Write(Form("ha2%02d", i));
      Ha9[i]->Write(Form("ha9%02d", i));
      Ha10[i]->Write(Form("ha10%02d", i));
      Hb4[i]->Write(Form("hb4%02d", i));
      Hb5[i]->Write(Form("hb5%02d", i));
      Hb7[i]->Write(Form("hb7%02d", i));
   }
   f->Close();
}
