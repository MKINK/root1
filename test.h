//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jun 16 04:25:43 2023 by ROOT version 6.16/00
// from TTree tr/data tree
// found on file: run00012_final.root
//////////////////////////////////////////////////////////

#ifndef test_h
#define test_h
#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"

class test {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxdata_XIA = 40;

   // Declaration of leaf types
   Int_t           nXIA;
   Int_t           data_XIA_;
   UInt_t          data_XIA_fUniqueID[kMaxdata_XIA];   //[data_XIA_]
   UInt_t          data_XIA_fBits[kMaxdata_XIA];   //[data_XIA_]
   Long64_t        data_XIA_Event_ts[kMaxdata_XIA];   //[data_XIA_]
   Long64_t        data_XIA_Ext_ts[kMaxdata_XIA];   //[data_XIA_]
   UShort_t        data_XIA_finish_code[kMaxdata_XIA];   //[data_XIA_]
   UShort_t        data_XIA_crate_id[kMaxdata_XIA];   //[data_XIA_]
   UShort_t        data_XIA_channel[kMaxdata_XIA];   //[data_XIA_]
   UShort_t        data_XIA_Energy[kMaxdata_XIA];   //[data_XIA_]
   Double_t        data_XIA_CFD[kMaxdata_XIA];   //[data_XIA_]
   UShort_t        data_XIA_CFD_Bit[kMaxdata_XIA];   //[data_XIA_]
   UInt_t          data_XIA_nESum[kMaxdata_XIA];   //[data_XIA_]
   UInt_t         *data_XIA_ESum[kMaxdata_XIA];   //[data_XIA_nESum]
   UInt_t          data_XIA_nQDC[kMaxdata_XIA];   //[data_XIA_]
   UInt_t         *data_XIA_QDC[kMaxdata_XIA];   //[data_XIA_nQDC]
   UInt_t          data_XIA_trace_length[kMaxdata_XIA];   //[data_XIA_]
   UShort_t       *data_XIA_trace[kMaxdata_XIA];   //[data_XIA_trace_length]

   // List of branches
   TBranch        *b_nXIA;   //!
   TBranch        *b_data_XIA_;   //!
   TBranch        *b_data_XIA_fUniqueID;   //!
   TBranch        *b_data_XIA_fBits;   //!
   TBranch        *b_data_XIA_Event_ts;   //!
   TBranch        *b_data_XIA_Ext_ts;   //!
   TBranch        *b_data_XIA_finish_code;   //!
   TBranch        *b_data_XIA_crate_id;   //!
   TBranch        *b_data_XIA_channel;   //!
   TBranch        *b_data_XIA_Energy;   //!
   TBranch        *b_data_XIA_CFD;   //!
   TBranch        *b_data_XIA_CFD_Bit;   //!
   TBranch        *b_data_XIA_nESum;   //!
   TBranch        *b_data_XIA_ESum;   //!
   TBranch        *b_data_XIA_nQDC;   //!
   TBranch        *b_data_XIA_QDC;   //!
   TBranch        *b_data_XIA_trace_length;   //!
   TBranch        *b_data_XIA_trace;   //!

   test(TTree *tree=0);
   virtual ~test();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   int RunNo;
};

#endif

#ifdef test_cxx
test::test(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   std::cout << " Run number  " << std::endl;
   std::cin >> RunNo;

   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Form("run%05d_final.root", RunNo));
      if (!f || !f->IsOpen()) {
         f = new TFile(Form("run%05d_final.root", RunNo));
      }
      f->GetObject("tr",tree);

   }
   Init(tree);
}

test::~test()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t test::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t test::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void test::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set array pointer
   for(int i=0; i<kMaxdata_XIA; ++i) data_XIA_ESum[i] = 0;
   for(int i=0; i<kMaxdata_XIA; ++i) data_XIA_QDC[i] = 0;
   for(int i=0; i<kMaxdata_XIA; ++i) data_XIA_trace[i] = 0;

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nXIA", &nXIA, &b_nXIA);
   fChain->SetBranchAddress("data_XIA", &data_XIA_, &b_data_XIA_);
   fChain->SetBranchAddress("data_XIA.fUniqueID", data_XIA_fUniqueID, &b_data_XIA_fUniqueID);
   fChain->SetBranchAddress("data_XIA.fBits", data_XIA_fBits, &b_data_XIA_fBits);
   fChain->SetBranchAddress("data_XIA.Event_ts", data_XIA_Event_ts, &b_data_XIA_Event_ts);
   fChain->SetBranchAddress("data_XIA.Ext_ts", data_XIA_Ext_ts, &b_data_XIA_Ext_ts);
   fChain->SetBranchAddress("data_XIA.finish_code", data_XIA_finish_code, &b_data_XIA_finish_code);
   fChain->SetBranchAddress("data_XIA.crate_id", data_XIA_crate_id, &b_data_XIA_crate_id);
   fChain->SetBranchAddress("data_XIA.channel", data_XIA_channel, &b_data_XIA_channel);
   fChain->SetBranchAddress("data_XIA.Energy", data_XIA_Energy, &b_data_XIA_Energy);
   fChain->SetBranchAddress("data_XIA.CFD", data_XIA_CFD, &b_data_XIA_CFD);
   fChain->SetBranchAddress("data_XIA.CFD_Bit", data_XIA_CFD_Bit, &b_data_XIA_CFD_Bit);
   fChain->SetBranchAddress("data_XIA.nESum", data_XIA_nESum, &b_data_XIA_nESum);
   fChain->SetBranchAddress("data_XIA.ESum", data_XIA_ESum, &b_data_XIA_ESum);
   fChain->SetBranchAddress("data_XIA.nQDC", data_XIA_nQDC, &b_data_XIA_nQDC);
   fChain->SetBranchAddress("data_XIA.QDC", data_XIA_QDC, &b_data_XIA_QDC);
   fChain->SetBranchAddress("data_XIA.trace_length", data_XIA_trace_length, &b_data_XIA_trace_length);
   fChain->SetBranchAddress("data_XIA.trace", data_XIA_trace, &b_data_XIA_trace);
   Notify();
}

Bool_t test::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void test::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t test::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Dr_cxx
