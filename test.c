#define test_cxx
#include "test.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void test::Loop()
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
    TH2D *hA2[10];
    TH2D *hA3[10];
    TH2D *hA4[10];
    TH2D *hA5[10];
    TH2D *hA6[10];
    TH2D *hA7[10];
    TH2D *hA8[10];
    TH2D *hA9[10];
    TH2D *hA10[10];
    TH2D *hA11[10];
    TH2D *hA12[10];
    TH2D *hA13[10];
    TH1D *hdtA1[10];
    TH1D *hdtA2[10];
    TH1D *hdtA3[10];
    TH1D *hdtA4[10];
    TH1D *hdtA5[10];
    TH1D *hdtA6[10];
    TH1D *hdtA7[10];
    TH1D *hdtA8[10];
    TH1D *hdtA9[10];
    TH1D *hdtA10[10];
    TH1D *hdtA11[10];
    TH1D *hdtA12[10];
    TH1D *hdtA13[10];
    TH2D *hB1[10];
    TH2D *hB2[10];
    TH2D *hB3[10];
    TH2D *hB4[10];
    TH2D *hB5[10];
    TH2D *hB6[10];
    TH2D *hB7[10];
    TH2D *hB8[10];
    TH2D *hB9[10];
    TH2D *hB10[10];
    TH2D *hB11[10];
    TH1D *hdtB1[10];
    TH1D *hdtB2[10];
    TH1D *hdtB3[10];
    TH1D *hdtB4[10];
    TH1D *hdtB5[10];
    TH1D *hdtB6[10];
    TH1D *hdtB7[10];
    TH1D *hdtB8[10];
    TH1D *hdtB9[10];
    TH1D *hdtB10[10];
    TH1D *hdtB11[10];
    for(int i=0; i<10; i++) 
    {
        hA1[i]= new TH2D(Form("hA1%d", i), Form("hA1%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA2[i]= new TH2D(Form("hA2%d", i), Form("hA2%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA3[i]= new TH2D(Form("hA3%d", i), Form("hA3%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA4[i]= new TH2D(Form("hA4%d", i), Form("hA4%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA5[i]= new TH2D(Form("hA5%d", i), Form("hA5%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA6[i]= new TH2D(Form("hA6%d", i), Form("hA6%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA7[i]= new TH2D(Form("hA7%d", i), Form("hA7%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA8[i]= new TH2D(Form("hA8%d", i), Form("hA8%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA9[i]= new TH2D(Form("hA9%d", i), Form("hA9%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA10[i]= new TH2D(Form("hA10%d", i), Form("hA10%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA11[i]= new TH2D(Form("hA11%d", i), Form("hA11%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA12[i]= new TH2D(Form("hA12%d", i), Form("hA12%d", i), 1600, 0, 160, 6000, 0, 60000);
        hA13[i]= new TH2D(Form("hA13%d", i), Form("hA13%d", i), 1600, 0, 160, 6000, 0, 60000);
        hdtA1[i] = new TH1D(Form("hdtA1%d", i), Form("hdtA1%d", i), 1600, -8000, 8000);
        hdtA2[i] = new TH1D(Form("hdtA2%d", i), Form("hdtA2%d", i), 1600, -8000, 8000);
        hdtA3[i] = new TH1D(Form("hdtA3%d", i), Form("hdtA3%d", i), 1600, -8000, 8000);
        hdtA4[i] = new TH1D(Form("hdtA4%d", i), Form("hdtA4%d", i), 1600, -8000, 8000);
        hdtA5[i] = new TH1D(Form("hdtA5%d", i), Form("hdtA5%d", i), 1600, -8000, 8000);
        hdtA6[i] = new TH1D(Form("hdtA6%d", i), Form("hdtA6%d", i), 1600, -8000, 8000);
        hdtA7[i] = new TH1D(Form("hdtA7%d", i), Form("hdtA7%d", i), 1600, -8000, 8000);
        hdtA8[i] = new TH1D(Form("hdtA8%d", i), Form("hdtA8%d", i), 1600, -8000, 8000);
        hdtA9[i] = new TH1D(Form("hdtA9%d", i), Form("hdtA9%d", i), 1600, -8000, 8000);
        hdtA10[i] = new TH1D(Form("hdtA10%d", i), Form("hdtA10%d", i), 1600, -8000, 8000);
        hdtA11[i] = new TH1D(Form("hdtA11%d", i), Form("hdtA11%d", i), 1600, -8000, 8000);
        hdtA12[i] = new TH1D(Form("hdtA12%d", i), Form("hdtA12%d", i), 1600, -8000, 8000);
        hdtA13[i] = new TH1D(Form("hdtA13%d", i), Form("hdtA13%d", i), 1600, -8000, 8000);
        hB1[i]= new TH2D(Form("hB1%d", i), Form("hB1%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB2[i]= new TH2D(Form("hB2%d", i), Form("hB2%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB3[i]= new TH2D(Form("hB3%d", i), Form("hB3%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB4[i]= new TH2D(Form("hB4%d", i), Form("hB4%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB5[i]= new TH2D(Form("hB5%d", i), Form("hB5%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB6[i]= new TH2D(Form("hB6%d", i), Form("hB6%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB7[i]= new TH2D(Form("hB7%d", i), Form("hB7%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB8[i]= new TH2D(Form("hB8%d", i), Form("hB8%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB9[i]= new TH2D(Form("hB9%d", i), Form("hB9%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB10[i]= new TH2D(Form("hB10%d", i), Form("hB10%d", i), 1600, 0, 160, 6000, 0, 60000);
        hB11[i]= new TH2D(Form("hB11%d", i), Form("hB11%d", i), 1600, 0, 160, 6000, 0, 60000);
        hdtB1[i] = new TH1D(Form("hdtB1%d", i), Form("hdtB1%d", i), 1600, -8000, 8000);
        hdtB2[i] = new TH1D(Form("hdtB2%d", i), Form("hdtB2%d", i), 1600, -8000, 8000);
        hdtB3[i] = new TH1D(Form("hdtB3%d", i), Form("hdtB3%d", i), 1600, -8000, 8000);
        hdtB4[i] = new TH1D(Form("hdtB4%d", i), Form("hdtB4%d", i), 1600, -8000, 8000);
        hdtB5[i] = new TH1D(Form("hdtB5%d", i), Form("hdtB5%d", i), 1600, -8000, 8000);
        hdtB6[i] = new TH1D(Form("hdtB6%d", i), Form("hdtB6%d", i), 1600, -8000, 8000);
        hdtB7[i] = new TH1D(Form("hdtB7%d", i), Form("hdtB7%d", i), 1600, -8000, 8000);
        hdtB8[i] = new TH1D(Form("hdtB8%d", i), Form("hdtB8%d", i), 1600, -8000, 8000);
        hdtB9[i] = new TH1D(Form("hdtB9%d", i), Form("hdtB9%d", i), 1600, -8000, 8000);
        hdtB10[i] = new TH1D(Form("hdtB10%d", i), Form("hdtB10%d", i), 1600, -8000, 8000);
        hdtB11[i] = new TH1D(Form("hdtB11%d", i), Form("hdtB11%d", i), 1600, -8000, 8000);
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
   Int_t chA1, chA2, chA3, chA4, chA5, chA6, chA7, chA8, chA9, chA10, chA11,chA12, chA13;
   Double_t EA1, EA2, EA3, EA4, EA5, EA6, EA7, EA8, EA9, EA10, EA11, EA12, EA13;
   Double_t tA1, tA2, tA3, tA4, tA5, tA6, tA7, tA8, tA9, tA10, tA11, tA12, tA13;
   Int_t chB1, chB2, chB3, chB4, chB5, chB6, chB7, chB8, chB9, chB10, chB11;
   Double_t EB1, EB2, EB3, EB4, EB5, EB6, EB7, EB8, EB9, EB10, EB11;
   Double_t tB1, tB2, tB3, tB4, tB5, tB6, tB7, tB8, tB9, tB10, tB11;
   Double_t EAA1,EAA2,EAA3,EAA4,EAA5,EAA6,EAA7,EAA8,EAA9,EAA10,EAA11,EAA12,EAA13;
   Double_t EBB1,EBB2,EBB3,EBB4,EBB5,EBB6,EBB7,EBB8,EBB9,EBB10,EBB11;
  
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
      chA1 = 400;
      chA2 = 401;
      chA3 = 402;
      chA4 = 403;
      chA5 = 404;
      chA6 = 405;
      chA7 = 406;
      chA8 = 407;
      chA9 = 408;
      chA10 = 409;
      chA11 = 410;
      chA12 = 411;
      chA13 = 412;
      EA1 = -10.0;
      EA2 = -10.0;
      EA3 = -10.0;
      EA4 = -10.0;
      EA5 = -10.0;
      EA6 = -10.0;
      EA7 = -10.0;
      EA8 = -10.0;
      EA9 = -10.0;
      EA10 = -10.0;
      EA11 = -10.0;
      EA12 = -10.0;
      EA13 = -10.0;
      tA1 = -1;
      tA2 = -1;
      tA3 = -1;
      tA4 = -1;
      tA5 = -1;
      tA6 = -1;
      tA7 = -1;
      tA8 = -1;
      tA9 = -1;
      tA10 = -1;
      tA11 = -1;
      tA12 = -1;
      tA13 = -1;
      chB1 = 502;
      chB2 = 503;
      chB3 = 504;
      chB4 = 505;
      chB5 = 506;
      chB6 = 507;
      chB7 = 508;
      chB8 = 509;
      chB9 = 510;
      chB10 = 511;
      chB11 = 512;
      EB1 = -10.0;
      EB2 = -10.0;
      EB3 = -10.0;
      EB4 = -10.0;
      EB5 = -10.0;
      EB6 = -10.0;
      EB7 = -10.0;
      EB8 = -10.0;
      EB9 = -10.0;
      EB10 = -10.0;
      EB11 = -10.0;
      tB1 = -1;
      tB2 = -1;
      tB3 = -1;
      tB4 = -1;
      tB5 = -1;
      tB6 = -1;
      tB7 = -1;
      tB8 = -1;
      tB9 = -1;
      tB10 = -1;
      tB11 = -1;
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
              EAA1 = EA1*0.002327;
          }
          if( data_XIA_channel[i] == chA2 && tA2 < 0)   
          {
              EA2 = data_XIA_Energy[i];
              tA2 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA2 = EA2*0.002221;
          }
          if( data_XIA_channel[i] == chA3 && tA3 < 0)   
          {
              EA3 = data_XIA_Energy[i];
              tA3 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA3 = EA3*0.002275;
          }
          if( data_XIA_channel[i] == chA4 && tA4 < 0)   
          {
              EA4 = data_XIA_Energy[i];
              tA4 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA4 = EA4*0.002292;
          }
          if( data_XIA_channel[i] == chA5 && tA5 < 0)   
          {
              EA5 = data_XIA_Energy[i];
              tA5 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA5 = EA5*0.002273;
          }
          if( data_XIA_channel[i] == chA6 && tA6 < 0)   
          {
              EA6 = data_XIA_Energy[i];
              tA6 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA6 = EA6*0.002271;
          }
          if( data_XIA_channel[i] == chA7 && tA7 < 0)   
          {
              EA7 = data_XIA_Energy[i];
              tA7 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA7 = EA7*0.002306;
          }
          if( data_XIA_channel[i] == chA8 && tA8 < 0)   
          {
              EA8 = data_XIA_Energy[i];
              tA8 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA8 = EA8*0.00226;
          }
          if( data_XIA_channel[i] == chA9 && tA9 < 0)   
          {
              EA9 = data_XIA_Energy[i];
              tA9 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA9 = EA9*0.002353;
          }
          if( data_XIA_channel[i] == chA10 && tA10 < 0)   
          {
              EA10 = data_XIA_Energy[i];
              tA10 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA10 = EA10*0.002298;
          }
          if( data_XIA_channel[i] == chA11 && tA11 < 0)   
          {
              EA11 = data_XIA_Energy[i];
              tA11 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA11 = EA11*0.002266;
          }
          if( data_XIA_channel[i] == chA12 && tA12 < 0)   
          {
              EA12 = data_XIA_Energy[i];
              tA12 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA12 = EA12*0.002319;
          }
          if( data_XIA_channel[i] == chA13 && tA13 < 0)   
          {
              EA13 = data_XIA_Energy[i];
              tA13 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EAA13 = EA13*0.002316;
          }
          if( data_XIA_channel[i] == chB1 && tB1 < 0)   
          {
              EB1 = data_XIA_Energy[i];
              tB1 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB1 = EB1*0.002326;
          }
          if( data_XIA_channel[i] == chB2 && tB2 < 0)   
          {
              EB2 = data_XIA_Energy[i];
              tB2 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB2 = EB2*0.002284;
          }
          if( data_XIA_channel[i] == chB3 && tB3 < 0)   
          {
              EB3 = data_XIA_Energy[i];
              tB3 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB3 = EB3*0.002314;
          }
          if( data_XIA_channel[i] == chB4 && tB4 < 0)   
          {
              EB4 = data_XIA_Energy[i];
              tB4 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB4 = EB4*0.002323;
          }
          if( data_XIA_channel[i] == chB5 && tB5 < 0)   
          {
              EB5 = data_XIA_Energy[i];
              tB5 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB5 = EB5*0.002237;
          }
          if( data_XIA_channel[i] == chB6 && tB6 < 0)   
          {
              EB6 = data_XIA_Energy[i];
              tB6 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB6 = EB6*0.002271;
          }
          if( data_XIA_channel[i] == chB7 && tB7 < 0)   
          {
              EB7 = data_XIA_Energy[i];
              tB7 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB7 = EB7*0.002269;
          }
          if( data_XIA_channel[i] == chB8 && tB8 < 0)   
          {
              EB8 = data_XIA_Energy[i];
              tB8 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB8 = EB8*0.002285;
          }
          if( data_XIA_channel[i] == chB9 && tB9 < 0)   
          {
              EB9 = data_XIA_Energy[i];
              tB9 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB9 = EB9*0.002265;
          }
          if( data_XIA_channel[i] == chB10 && tB10 < 0)   
          {
              EB10 = data_XIA_Energy[i];
              tB10 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB10 = EB10*0.002258;
          }
          if( data_XIA_channel[i] == chB11 && tB11 < 0)   
          {
              EB11 = data_XIA_Energy[i];
              tB11 =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
              EBB11 = EB11*0.00226;
          }
      }
      for(int i=0; i<10; i++)
      {
            if(detE[i] < 0.0)   continue;
            if(EA1 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA1[i]->Fill(tA1-t[i]);
                if((tA1-t[i]) >= -60 && (tA1-t[i]) <= -10)
                    hA1[i]->Fill(EAA1, detE[i]);
            }
            if(EA2 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA2[i]->Fill(tA2-t[i]);
                if((tA2-t[i]) >= -60 && (tA2-t[i]) <= -10)
                    hA2[i]->Fill(EAA2, detE[i]);
            }
            if(EA3 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA3[i]->Fill(tA3-t[i]);
                if((tA3-t[i]) >= -60 && (tA3-t[i]) <= -10)
                    hA3[i]->Fill(EAA3, detE[i]);
            }
            if(EA4 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA4[i]->Fill(tA4-t[i]);
                if((tA4-t[i]) >= -60 && (tA4-t[i]) <= -10)
                    hA4[i]->Fill(EAA4, detE[i]);
            }
            if(EA5 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA5[i]->Fill(tA5-t[i]);
                if((tA5-t[i]) >= -60 && (tA5-t[i]) <= -10)
                    hA5[i]->Fill(EAA5, detE[i]);
            }
            if(EA6 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA6[i]->Fill(tA6-t[i]);
                if((tA6-t[i]) >= -60 && (tA6-t[i]) <= -10)
                    hA6[i]->Fill(EAA6, detE[i]);
            }
            if(EA7 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA7[i]->Fill(tA7-t[i]);
                if((tA7-t[i]) >= -60 && (tA7-t[i]) <= -10)
                    hA7[i]->Fill(EAA7, detE[i]);
            }
            if(EA8 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA8[i]->Fill(tA8-t[i]);
                if((tA8-t[i]) >= -60 && (tA8-t[i]) <= -10)
                    hA8[i]->Fill(EAA8, detE[i]);
            }
            if(EA9 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA9[i]->Fill(tA9-t[i]);
                if((tA9-t[i]) >= -60 && (tA9-t[i]) <= -10)
                    hA9[i]->Fill(EAA9, detE[i]);
            }
            if(EA10 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA10[i]->Fill(tA10-t[i]);
                if((tA10-t[i]) >= -60 && (tA10-t[i]) <= -10)
                    hA10[i]->Fill(EAA10, detE[i]);
            }
            if(EA11 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA11[i]->Fill(tA11-t[i]);
                if((tA11-t[i]) >= -60 && (tA11-t[i]) <= -10)
                    hA11[i]->Fill(EAA11, detE[i]);
            }
            if(EA12 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA12[i]->Fill(tA12-t[i]);
                if((tA12-t[i]) >= -60 && (tA12-t[i]) <= -10)
                    hA12[i]->Fill(EAA12, detE[i]);
            }
            if(EA13 > 0.0 && (i == 0 || i==1 || i == 8 || i == 9 ))
            {
                hdtA13[i]->Fill(tA13-t[i]);
                if((tA13-t[i]) >= -60 && (tA13-t[i]) <= -10)
                    hA13[i]->Fill(EAA13, detE[i]);
            }
            if(EB1 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB1[i]->Fill(tB1-t[i]);
                if((tB1-t[i]) >= -60 && (tB1-t[i]) <= 60)
                    hB1[i]->Fill(EBB1, detE[i]);
            }
            if(EB2 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB2[i]->Fill(tB2-t[i]);
                if((tB2-t[i]) >= -60 && (tB2-t[i]) <= 60)
                    hB2[i]->Fill(EBB2, detE[i]);
            }
            if(EB3 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB3[i]->Fill(tB3-t[i]);
                if((tB3-t[i]) >= -60 && (tB3-t[i]) <= 60)
                    hB3[i]->Fill(EBB3, detE[i]);
            }
            if(EB4 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB4[i]->Fill(tB4-t[i]);
                if((tB4-t[i]) >= -60 && (tB4-t[i]) <= 60)
                    hB4[i]->Fill(EBB4, detE[i]);
            }
            if(EB5 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB5[i]->Fill(tB5-t[i]);
                if((tB5-t[i]) >= -60 && (tB5-t[i]) <= 60)
                    hB5[i]->Fill(EBB5, detE[i]);
            }
            if(EB6 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB6[i]->Fill(tB6-t[i]);
                if((tB6-t[i]) >= -60 && (tB6-t[i]) <= 60)
                    hB6[i]->Fill(EBB6, detE[i]);
            }
            if(EB7 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB7[i]->Fill(tB7-t[i]);
                if((tB7-t[i]) >= -60 && (tB7-t[i]) <= 60)
                    hB7[i]->Fill(EBB7, detE[i]);
            }
            if(EB8 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB8[i]->Fill(tB8-t[i]);
                if((tB8-t[i]) >= -60 && (tB8-t[i]) <= 60)
                    hB8[i]->Fill(EBB8, detE[i]);
            }
            if(EB9 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB9[i]->Fill(tB9-t[i]);
                if((tB9-t[i]) >= -60 && (tB9-t[i]) <= 60)
                    hB9[i]->Fill(EBB9, detE[i]);
            }
            if(EB10 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB10[i]->Fill(tB10-t[i]);
                if((tB10-t[i]) >= -60 && (tB10-t[i]) <= 60)
                    hB10[i]->Fill(EBB10, detE[i]);
            }
            if(EB11 > 0.0 && ( i == 3 || i == 4 || i == 6))
            {
                hdtB11[i]->Fill(tB11-t[i]);
                if((tB11-t[i]) >= -60 && (tB11-t[i]) <= 60)
                    hB11[i]->Fill(EBB11, detE[i]);
            }
      }
      // if (Cut(ientry) < 0) continue;
   }
   TFile *f = new TFile(Form("47DetE_E_%d.root", RunNo), "RECREATE");
   f->cd();
   for(int i=0; i<10; i++)
   {
        hA1[i]->Write(Form("hA%d_%d", i, chA1));
        hA2[i]->Write(Form("hA%d_%d", i, chA2));
        hA3[i]->Write(Form("hA%d_%d", i, chA3));
        hA4[i]->Write(Form("hA%d_%d", i, chA4));
        hA5[i]->Write(Form("hA%d_%d", i, chA5));
        hA6[i]->Write(Form("hA%d_%d", i, chA6));
        hA7[i]->Write(Form("hA%d_%d", i, chA7));
        hA8[i]->Write(Form("hA%d_%d", i, chA8));
        hA9[i]->Write(Form("hA%d_%d", i, chA9));
        hA10[i]->Write(Form("hA%d_%d", i, chA10));
        hA11[i]->Write(Form("hA%d_%d", i, chA11));
        hA12[i]->Write(Form("hA%d_%d", i, chA12));
        hA13[i]->Write(Form("hA%d_%d", i, chA13));
        hdtA1[i]->Write(Form("hdtA%d_%d", i, chA1));
        hdtA2[i]->Write(Form("hdtA%d_%d", i, chA2));
        hdtA3[i]->Write(Form("hdtA%d_%d", i, chA3));
        hdtA4[i]->Write(Form("hdtA%d_%d", i, chA4));
        hdtA5[i]->Write(Form("hdtA%d_%d", i, chA5));
        hdtA6[i]->Write(Form("hdtA%d_%d", i, chA6));
        hdtA7[i]->Write(Form("hdtA%d_%d", i, chA7));
        hdtA8[i]->Write(Form("hdtA%d_%d", i, chA8));
        hdtA9[i]->Write(Form("hdtA%d_%d", i, chA9));
        hdtA10[i]->Write(Form("hdtA%d_%d", i, chA10));
        hdtA11[i]->Write(Form("hdtA%d_%d", i, chA11));
        hdtA12[i]->Write(Form("hdtA%d_%d", i, chA12));
        hdtA13[i]->Write(Form("hdtA%d_%d", i, chA13));
        hB1[i]->Write(Form("hB%d_%d", i, chB1));
        hB2[i]->Write(Form("hB%d_%d", i, chB2));
        hB3[i]->Write(Form("hB%d_%d", i, chB3));
        hB4[i]->Write(Form("hB%d_%d", i, chB4));
        hB5[i]->Write(Form("hB%d_%d", i, chB5));
        hB6[i]->Write(Form("hB%d_%d", i, chB6));
        hB7[i]->Write(Form("hB%d_%d", i, chB7));
        hB8[i]->Write(Form("hB%d_%d", i, chB8));
        hB9[i]->Write(Form("hB%d_%d", i, chB9));
        hB10[i]->Write(Form("hB%d_%d", i, chB10));
        hB11[i]->Write(Form("hB%d_%d", i, chB11));
        hdtB1[i]->Write(Form("hdtB%d_%d", i, chB1));
        hdtB2[i]->Write(Form("hdtB%d_%d", i, chB2));
        hdtB3[i]->Write(Form("hdtB%d_%d", i, chB3));
        hdtB4[i]->Write(Form("hdtB%d_%d", i, chB4));
        hdtB5[i]->Write(Form("hdtB%d_%d", i, chB5));
        hdtB6[i]->Write(Form("hdtB%d_%d", i, chB6));
        hdtB7[i]->Write(Form("hdtB%d_%d", i, chB7));
        hdtB8[i]->Write(Form("hdtB%d_%d", i, chB8));
        hdtB9[i]->Write(Form("hdtB%d_%d", i, chB9));
        hdtB10[i]->Write(Form("hdtB%d_%d", i, chB10));
        hdtB11[i]->Write(Form("hdtB%d_%d", i, chB11));
   }
   f->Close();
}