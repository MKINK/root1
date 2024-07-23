{
//========= Macro generated from object: CUTG/Graph
//========= by ROOT version6.28/08
   
   TCutG *cutg = new TCutG("cut1",8);
   cutg->SetVarX("Energy[0]");
   cutg->SetVarY("Energy[1]*0.002385");
   cutg->SetTitle("Graph");
   cutg->SetFillStyle(1000);
   cutg->SetPoint(0,1.83818,74.9813);
   cutg->SetPoint(1,40.6441,57.0037);
   cutg->SetPoint(2,51.5632,54.4569);
   cutg->SetPoint(3,52.663,55.6554);
   cutg->SetPoint(4,30.1178,64.1948);
   cutg->SetPoint(5,1.28829,77.5281);
   cutg->SetPoint(6,1.83818,74.5318);
   cutg->SetPoint(7,1.83818,74.9813);
   cutg->Draw("");
}
