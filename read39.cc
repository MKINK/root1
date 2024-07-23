void read39(){
    TFile *ipf = new TFile("kd&store39.root");
    if (ipf->IsZombie()) {
    cout << "Error opening file!" << endl;
    exit(-1);
}
ipf->cd();
TTree *tree=(TTree*)ipf->Get("tree");
