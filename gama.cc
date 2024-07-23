#define gama_cxx
#include "gama.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

using namespace std;

void gama::Loop()
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
    TFile *f = new TFile(Form("kkd%d.root", RunNo), "RECREATE"); 
    TTree* tree = new TTree("tree", "tree"); 
    std::cout<<f<<std::endl; 
    TH1D *kdgama[18]; 
    for(int i=0; i<18; i++) 
    {
        // kdgama[data_XIA_channel[i] - llll] = new TH1D(Form("hdtA%d", i), Form("hdtA%d", i), 750, 0, 3000);
        kdgama[i] = new TH1D(Form("hdtA%d", i), Form("hdtA%d", i), 2683, 0, 2000); 
    }
//    Double_t A1tmin[10] = {-30, -30, 0,   0, };
//    Double_t A1tmax[10] = {0,   0,   0,   0};
//    Double_t B1tmin[10] = {0,   0,   0, -30, -30};
//    Double_t B1tmax[10] = {0,   0,   0, -10, };

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   cout << "nentries: " <<  nentries << endl;
//    exit(0);

    Long64_t nbytes = 0, nb = 0; 
    Double_t kgama[18]; 
    Double_t t[127]; 
    Double_t g[127]; 
    Double_t a[18];  
    Double_t gkb[2][127];
    Double_t gabc[3][18];
    Double_t EA[13];
    Double_t EB[11];
    Double_t detE[10];

    Short_t hit = 0; 
    // Short_t EE[127] = 0; 
    UShort_t channel[127] = {0}; 
    // UShort_t channel2[127][13] = {0}; 
    tree -> Branch("nXIA", &hit, "nXIA/S"); 
    tree -> Branch("channel", channel, "channel[nXIA]/s"); 
    tree -> Branch("t", t, "t[nXIA]/D"); 
    tree -> Branch("Energy", g, "Energy[nXIA]/D"); 
    // tree -> Branch("EE", EE, "EE[nXIA]/S"); 
    // tree -> Branch("channel2", channel2, "channel2[nXIA][EE]/s"); 

    gabc[0][0] = 0.117594; gabc[1][0] = 1.004887; gabc[2][0] = -0.0000149388;
    gabc[0][1] = -5.36962; gabc[1][1] = 1.016547; gabc[2][1] = -0.000000116729;
    gabc[0][2] = -0.11156; gabc[1][2] = 1.000753; gabc[2][2] = -0.000000503032;
    gabc[0][3] = -2.75794; gabc[1][3] = 1.019422; gabc[2][3] = -0.0000219248;
    gabc[0][4] = -0.06416; gabc[1][4] = 1.00059; gabc[2][4] = -0.000000585092;
    gabc[0][5] = -0.64316; gabc[1][5] = 1.002238; gabc[2][5] = -0.000000157947;
    gabc[0][6] = -0.26473; gabc[1][6] = 1.000994; gabc[2][6] = -0.0000000327184;
    gabc[0][7] = -0.26473; gabc[1][7] = 1.000994; gabc[2][7] = -0.0000000327184;
    gabc[0][8] = -0.18349; gabc[1][8] = 1.001155; gabc[2][8] = -0.000000279595;
    gabc[0][9] = -0.26267; gabc[1][9] = 1.001227; gabc[2][9] = -0.000000275701;
    gabc[0][10] = -0.29265; gabc[1][10] = 1.000898; gabc[2][10] = -0.000000266449;
    gabc[0][11] = 1.903473; gabc[1][11] = 0.994607; gabc[2][11] = -0.000000130956;
    gabc[0][12] = -0.91482; gabc[1][12] = 1.003058; gabc[2][12] = -0.000000128074;
    gabc[0][13] = -0.47159; gabc[1][13] = 1.001591; gabc[2][13] = -0.000000409603;
    gabc[0][14] = 0.216581; gabc[1][14] = 0.999759; gabc[2][14] = -0.000000682741;
    gabc[0][15] = -0.10357; gabc[1][15] = 1.000947; gabc[2][15] = -0.000000630999;
    gabc[0][16] = -0.35098; gabc[1][16] = 1.00138; gabc[2][16] = -0.000000145366;
    gabc[0][17] = -0.03223; gabc[1][17] = 1.000532; gabc[2][17] = -0.0000000436429;
    gkb[0][0] =0.1871;
    gkb[0][1] =0.2145;
    gkb[0][2] =0.2151;
    gkb[0][3] =0.1913;
    gkb[0][4] =0.1843;
    gkb[0][5] =0.1856;
    gkb[0][6] =0.1836;
    gkb[0][7] =0.0452;
    gkb[0][8] =0.1825;
    gkb[0][9] =0.1836;
    gkb[0][10] =0.1775;
    gkb[0][11] =0.1842;
    gkb[0][12] =0.191;
    gkb[0][13] =0.1882;
    gkb[0][14] =0.1883;
    gkb[0][15] =0.1936;
    gkb[0][16] =0.3635;
    gkb[0][17] =0.3612;
    gkb[1][0] =-0.3002;
    gkb[1][1] =5.3025;
    gkb[1][2] =0.2409;
    gkb[1][3] =0.7974;
    gkb[1][4] =0.0176;
    gkb[1][5] =0.6207;
    gkb[1][6] =0.3922;
    gkb[1][7] =272.0699;
    gkb[1][8] =0.3004;
    gkb[1][9] =0.4013;
    gkb[1][10] =0.4721;
    gkb[1][11] =-1.9511;
    gkb[1][12] =0.9793;
    gkb[1][13] =0.5312;
    gkb[1][14] =-0.0956;
    gkb[1][15] =0.2632;
    gkb[1][16] =0.7174;
    gkb[1][17] =0.1842;

    gkb[0][18] = 0.002327 ;
    gkb[0][19] =0.002222 ;
    gkb[0][20] =0.002276 ;
    gkb[0][21] =0.002294 ;
    gkb[0][22] =0.002275 ;
    gkb[0][23] =0.002274 ;
    gkb[0][24] =0.002309 ;
    gkb[0][25] =0.002264 ;
    gkb[0][26] =0.002357 ;
    gkb[0][27] =0.002302 ;
    gkb[0][28] =0.002273 ;
    gkb[0][29] =0.002325 ;
    gkb[0][30] =0.002293 ;
    gkb[0][31] =0.002319 ;
    gkb[0][32] =0.002284 ;
    gkb[0][33] =0.002315 ;
    gkb[0][34] =0.002324 ;
    gkb[0][35] =0.00224 ;
    gkb[0][36] =0.002274 ;
    gkb[0][37] =0.002272 ;
    gkb[0][38] =0.002288 ;
    gkb[0][39] =0.002268 ;
    gkb[0][40] =0.002263 ;
    gkb[0][41] =0.002265 ;
    gkb[0][42] = 0.002648 ;
    gkb[0][43] =0.002644 ;
    gkb[0][44] =0.002643 ;
    gkb[0][45] =0.002642 ;
    gkb[0][46] =0.002639 ;
    gkb[0][47] =0.00264 ;
    gkb[0][48] =0.002641 ;
    gkb[0][49] =0.002639 ;
    gkb[0][50] =0.002641 ;
    gkb[0][51] =0.002642 ;
    gkb[0][52] =0.002641 ;
    gkb[0][53] =0.002643 ;
    gkb[0][54] =0.002643 ;
    gkb[0][55] =0.002486 ;
    gkb[0][56] =0.002481 ;
    gkb[0][57] =0.002481 ;
    gkb[0][58] =0.002479 ;
    gkb[0][59] =0.002477 ;
    gkb[0][60] =0.002476 ;
    gkb[0][61] =0.002477 ;
    gkb[0][62] =0.002475 ;
    gkb[0][63] =0.002476 ;
    gkb[0][64] =0.002477 ;
    gkb[0][65] =0.002477 ;
    gkb[0][66] =0.002479 ;
    gkb[0][67] =0.002477 ;
    gkb[0][68] =0.002467 ;
    gkb[0][69] =0.002467 ;
    gkb[0][70] =0.002466 ;
    gkb[0][71] =0.002467 ;
    gkb[0][72] =0.002465 ;
    gkb[0][73] =0.002469 ;
    gkb[0][74] =0.002468 ;
    gkb[0][75] =0.002467 ;
    gkb[0][76] =0.002467 ;
    gkb[0][77] =0.002468 ;
    gkb[0][78] =0.00247 ;
    gkb[0][79] =0.002474 ;
    gkb[0][80] =0.002474 ;
    gkb[0][81] =0.002376 ;
    gkb[0][82] =0.002376 ;
    gkb[0][83] =0.002375 ;
    gkb[0][84] =0.002376 ;
    gkb[0][85] =0.002373 ;
    gkb[0][86] =0.002376 ;
    gkb[0][87] =0.002374 ;
    gkb[0][88] =0.002373 ;
    gkb[0][89] =0.002373 ;
    gkb[0][90] =0.002373 ;
    gkb[0][91] =0.002374 ;
    gkb[0][92] =0.002377 ;
    gkb[0][93] =0.002378 ;
    gkb[0][94] =0.002935 ;
    gkb[0][95] =0.002921 ;
    gkb[0][96] =0.00292 ;
    gkb[0][97] =0.002918 ;
    gkb[0][98] =0.002913 ;
    gkb[0][99] =0.002913 ;
    gkb[0][100] =0.002914 ;
    gkb[0][101] =0.002913 ;
    gkb[0][102] =0.002913 ;
    gkb[0][103] =0.00291 ;
    gkb[0][104] =0.002915 ;
    gkb[0][105] =0.002407 ;
    gkb[0][106] =0.002394 ;
    gkb[0][107] =0.002394 ;
    gkb[0][108] =0.002393 ;
    gkb[0][109] =0.002389 ;
    gkb[0][110] =0.00239 ;
    gkb[0][111] =0.002393 ;
    gkb[0][112] =0.002392 ;
    gkb[0][113] =0.002394 ;
    gkb[0][114] =0.002393 ;
    gkb[0][115] =0.0024 ;
    gkb[0][116] =0.002329 ;
    gkb[0][117] =0.002319 ;
    gkb[0][118] =0.002319 ;
    gkb[0][119] =0.00232 ;
    gkb[0][120] =0.002317 ;
    gkb[0][121] =0.002317 ;
    gkb[0][122] =0.002323 ;
    gkb[0][123] =0.002318 ;
    gkb[0][124] =0.002319 ;
    gkb[0][125] =0.002316 ;
    gkb[0][126] =0.002323 ;


    for(int i=18; i<127; i++)
    {
        gkb[1][i] = 0;
    }
    
    
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        if(jentry%Int_t(1e7) ==0) std::cout << "Finished "<< Form("%0.2f", 100.0*Double_t(jentry)/Double_t(nentries)) << "%" << std::endl;
        fChain -> GetEntry(jentry); 
        for(int i = 0; i <nXIA; i++)
        {
            Int_t llll = 100; 
            if(data_XIA_channel[i] >= 100  && data_XIA_channel[i] < 112)
            {
               kgama[i] = data_XIA_Energy[i]; 
               t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i]; 
               a[hit] = gkb[0][data_XIA_channel[i] - 100] * kgama[i] + gkb[1][data_XIA_channel[i] - 100]; 
               g[hit] = gabc[0][data_XIA_channel[i] - 100] + a[hit] * gabc[1][data_XIA_channel[i] - 100] + a[hit] * a[hit] * gabc[2][data_XIA_channel[i] - 100]; 
               kdgama[data_XIA_channel[i] - 100] -> Fill(g[hit]); 
               channel[hit] = data_XIA_channel[i]; 
               hit++; 
            }
            llll = 200 - 12; 
            if(data_XIA_channel[i] >= 200 && data_XIA_channel[i] < 206)
            { 
               kgama[i] = data_XIA_Energy[i]; 
               t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i]; 
               a[hit] = gkb[0][data_XIA_channel[i] - llll] * kgama[i] + gkb[1][data_XIA_channel[i] - llll];
               g[hit] = gabc[0][data_XIA_channel[i] - llll] + a[hit] * gabc[1][data_XIA_channel[i] - llll] + a[hit] * a[hit] * gabc[2][data_XIA_channel[i] - llll]; 
               kdgama[data_XIA_channel[i] - llll] -> Fill(g[hit]); 
               channel[hit] = data_XIA_channel[i]; 
               hit++;
            }
            llll = 400 - 12 - 6; 
            if(data_XIA_channel[i] >= 400 && data_XIA_channel[i] < 413)  
            {
                EA[hit] = data_XIA_Energy[i];
                t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i]; 
                g[hit] = gkb[0][data_XIA_channel[i] - llll] * EA[hit] + gkb[1][data_XIA_channel[i] - llll];
                channel[hit] = data_XIA_channel[i]; 
                hit++;     
            }
            llll = 500 - 12 - 6 - 13; 
            if(data_XIA_channel[i] >= 500 && data_XIA_channel[i] < 511)  
            {
                EB[hit] = data_XIA_Energy[i];
                t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i]; 
                g[hit] = gkb[0][data_XIA_channel[i] - llll] * EB[hit] + gkb[1][data_XIA_channel[i] - llll];
                channel[hit] = data_XIA_channel[i]; 
                hit++; 
            }
            llll = 600 - 12 - 6 - 13 - 11; 
            // if (data_XIA_channel[i] >= 600)
            // { 
            //     detE[hit] = data_XIA_Energy[i]; 
            //     g[hit] = detE[hit];
            //     t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
            //     channel[hit] = data_XIA_channel[i]; 
            //     hit++;
            // }
            // llll = 600 - 12 - 6 - 13 - 11 - 13 ;            
            if (data_XIA_channel[i] == 600)
            { 
                detE[hit] = data_XIA_Energy[i];
                t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
                channel[hit] = data_XIA_channel[i];
                for(int j= 0;j<nXIA; j++)
                {
                 if(data_XIA_channel[j] >= 400 && data_XIA_channel[j] < 413){
                    g[hit] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + data_XIA_channel[j] - 400];
                 }
                                        
                }
                hit++;
            }
            llll = 601 - 12 - 6 - 13 - 11 - 13 ;
            if (data_XIA_channel[i] == 601)
            { 
                detE[hit] = data_XIA_Energy[i];
                t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
                channel[hit] = data_XIA_channel[i];
                for(int j= 0;j<nXIA; j++)
                {
                 if(data_XIA_channel[j] >= 400 && data_XIA_channel[j] < 413){
                    g[hit] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + data_XIA_channel[j] - 400];
                 }
                                        
                }
                hit++;
            }  
            llll = 608 - 12 - 6 - 13 - 11 - 13 - 13;
            if (data_XIA_channel[i] == 608)
            { 
                detE[hit] = data_XIA_Energy[i];
                t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
                channel[hit] = data_XIA_channel[i];
                for(int j= 0;j<nXIA; j++)
                {
                 if(data_XIA_channel[j] >= 400 && data_XIA_channel[j] < 413){
                    g[hit] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + data_XIA_channel[j] - 400];
                 }
                                        
                }
                hit++;
            }   
            llll = 609 - 12 - 6 - 13 - 11 - 13 - 13 - 13;
            if (data_XIA_channel[i] == 609)
            { 
                detE[hit] = data_XIA_Energy[i];
                t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
                channel[hit] = data_XIA_channel[i];
                for(int j= 0;j<nXIA; j++)
                {
                 if(data_XIA_channel[j] >= 400 && data_XIA_channel[j] < 413){
                    g[hit] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + data_XIA_channel[j] - 400];
                 }
                                        
                }
                hit++;
            }
            llll = 603 - 12 - 6 - 13 - 11 - 13 - 13 - 13 - 13;
            if (data_XIA_channel[i] == 603)
            { 
                detE[hit] = data_XIA_Energy[i];
                t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
                channel[hit] = data_XIA_channel[i];
                for(int j= 0;j<nXIA; j++)
                {
                 if(data_XIA_channel[j] >= 502 && data_XIA_channel[j] < 513){
                    g[hit] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + data_XIA_channel[j] - 502];
                 }
                                        
                }
                hit++;
            }
            llll = 604 - 12 - 6 - 13 - 11 - 13 - 13 - 13 - 13 - 11;
            if (data_XIA_channel[i] == 604)
            { 
                detE[hit] = data_XIA_Energy[i];
                t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
                channel[hit] = data_XIA_channel[i];
                for(int j= 0;j<nXIA; j++)
                {
                 if(data_XIA_channel[j] >= 502 && data_XIA_channel[j] < 513){
                    g[hit] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + data_XIA_channel[j] - 502];
                 }
                                        
                }
                hit++;
            }
            llll = 606 - 12 - 6 - 13 - 11 - 13 - 13 - 13 - 13 - 11 - 11;
            if (data_XIA_channel[i] == 606)
            { 
                detE[hit] = data_XIA_Energy[i];
                t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
                channel[hit] = data_XIA_channel[i];
                for(int j= 0;j<nXIA; j++)
                {
                 if(data_XIA_channel[j] >= 502 && data_XIA_channel[j] < 513){
                    g[hit] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + data_XIA_channel[j] - 502];
                 }
                                        
                }
                hit++;
            }                                                                      
            // llll = 600 - 12 - 6 - 13 - 11 - 13 - 13;            
            // if (data_XIA_channel[i] == 608)
            // { 
            //     detE[hit] = data_XIA_Energy[i];
            //     for(int j=0; j<13; j++)
            //     {
            //         g[data_XIA_channel[hit] - llll + j] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + j];
            //         t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
            //         channel[hit] = data_XIA_channel[i]; 
            //         hit++;
            //     }
            // }
            // llll = 600 - 12 - 6 - 13 - 11 - 13 - 13 - 13;            
            // if (data_XIA_channel[i] == 609)
            // { 
            //     detE[hit] = data_XIA_Energy[i];
            //     for(int j=0; j<13; j++)
            //     {
            //         g[data_XIA_channel[hit] - llll + j] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + j];
            //         t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
            //         channel[hit] = data_XIA_channel[i]; 
            //         hit++;
            //     }
            // }
            // llll = 600 - 12 - 6 - 13 - 11 - 13 - 13 - 13 - 13;            
            // if (data_XIA_channel[i] == 603)
            // { 
            //     detE[hit] = data_XIA_Energy[i];
            //     for(int j=0; j<11; j++)
            //     {
            //         g[data_XIA_channel[hit] - llll + j] = detE[hit] * gkb[0][data_XIA_channel[i] - llll + j];
            //         t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
            //         channel[hit] = data_XIA_channel[i]; 
            //         hit++;
            //     }
            // }
            // llll = 600 - 12 - 6 - 13 - 11 - 13 - 13 - 13 - 13 -11;            
            // if (data_XIA_channel[i] == 604)
            // { 
            //     detE[hit] = data_XIA_Energy[i];
            //     for(int j=0; j<11; j++)
            //     {
            //         g[data_XIA_channel[hit] - llll + j] = detE[i] * gkb[0][data_XIA_channel[hit] - llll + j];
            //         t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
            //         channel[hit] = data_XIA_channel[i]; 
            //         hit++;
            //     }
            // }
            // llll = 600 - 12 - 6 - 13 - 11 - 13 - 13 - 13 - 13 -11 - 11;            
            // if (data_XIA_channel[i] == 606)
            // { 
            //     detE[hit] = data_XIA_Energy[i];
            //     for(int j=0; j<11; j++)
            //     {
            //         g[data_XIA_channel[hit] - llll + j] = detE[i] * gkb[0][data_XIA_channel[hit] - llll + j];
            //         t[hit] =  data_XIA_Event_ts[i] + data_XIA_CFD[i];
            //         channel[hit] = data_XIA_channel[i]; 
            //         hit++;
            //     }
            // }                                                                                     
        }
        tree -> Fill(); 
        hit = 0; 
   }


   for(int i=0; i<18; i++)
   {
        f -> WriteObject(kdgama[i], Form("kd6gama_%02d", i)); 
   }
   f -> WriteObject(tree, "tree"); 
   f->Close(); 
}