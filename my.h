//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan  4 10:43:13 2024 by ROOT version 6.28/08
// from TTree tree/tree
// found on file: ceshie39.root
//////////////////////////////////////////////////////////

#ifndef my_h
#define my_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class my {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Short_t         nXIA;
   UShort_t        channel[12];   //[nXIA]
   Double_t        t[12];   //[nXIA]
   Double_t        Energy[12];   //[nXIA]

   // List of branches
   TBranch        *b_nXIA;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_t;   //!
   TBranch        *b_Energy;   //!

   my(TTree *tree=0);
   virtual ~my();
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

#ifdef my_cxx
my::my(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   std::cout << " Run number  " << std::endl;
   std::cin >> RunNo;      
   
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(Form("kdstore%d.root",RunNo));
      if (!f || !f->IsOpen()) {
         f = new TFile(Form("kdstore%d.root",RunNo));
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

my::~my()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t my::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t my::LoadTree(Long64_t entry)
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

void my::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nXIA", &nXIA, &b_nXIA);
   fChain->SetBranchAddress("channel", channel, &b_channel);
   fChain->SetBranchAddress("t", t, &b_t);
   fChain->SetBranchAddress("Energy", Energy, &b_Energy);
   Notify();
}

Bool_t my::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void my::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t my::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef my_cxx
