void add(){
    TFile* d = TFile::Open("danew180.root");
    TH1F *h[18];
    for(int i=0; i<18; i++){
        char name[10];
        sprintf(name, "ha1%02d", i);
        h[i] = (TH1F*)d->Get(name)->Clone(Form("h%d", i));
        char nameToAdd[10];
        // sprintf(nameToAdd, "ha2%02d", i);
        // h[i]->Add((TH1F*)d->Get(nameToAdd));
        sprintf(nameToAdd, "ha9%02d", i);
        h[i]->Add((TH1F*)d->Get(nameToAdd));
        sprintf(nameToAdd, "ha10%02d", i);
        h[i]->Add((TH1F*)d->Get(nameToAdd));
        sprintf(nameToAdd, "hb4%02d", i);
        h[i]->Add((TH1F*)d->Get(nameToAdd));
        sprintf(nameToAdd, "hb5%02d", i);
        h[i]->Add((TH1F*)d->Get(nameToAdd));
        sprintf(nameToAdd, "hb7%02d", i);
        h[i]->Add((TH1F*)d->Get(nameToAdd));
        h[i]->GetXaxis()->SetTitle("E_{#gamma}(keV)");
        h[i]->GetYaxis()->SetTitle("Counts");
        h[i]->GetYaxis()->CenterTitle(true);
        h[i]->GetXaxis()->CenterTitle(true);
    }
    TFile *f = new TFile(Form("danew180t.root"), "RECREATE");
    f->cd();
    for(int i=0; i<18; i++){
        h[i]->Write(Form("h%02d", i));
    }
    f->Close();
    // TFile* d = TFile::Open("danew180.root");
    // TH1F *h[18]
    // for(i=0;i<18;i++){
    //     char name[10];
    //     sprintf(name, "ha1%02d", i);
    //     TH1F *h[i] = (TH1F*)d->Get(name)->Clone(Form("h%d", i));
    //     h[i]->Add("ha2%02d",i);
    //     h[i]->Add("ha9%02d",i);
    //     h[i]->Add("ha10%02d",i);
    //     h[i]->Add("hb4%02d",i);
    //     h[i]->Add("hb5%02d",i);
    //     h[i]->Add("hb7%02d",i);
    // }
    // TH1F *h1 = (TH1F*)ha100->Clone("h1");
    // h1->
    
}