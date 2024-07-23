void zjntest2(TH2D* h)
{
    int nbinsX = h->GetNbinsX();
    int nbinsY = h->GetNbinsY();

    // 创建一个新的 TH2D 对象来存储更新后的数据
    TH2D *h2d_new = new TH2D("h2d_new", "Updated Histogram", nbinsX, 0, 160, nbinsY, 0, 160);

    // 遍历原始直方图的每个 bin
    for (int i = 1; i <= nbinsX; ++i) {
        for (int j = 1; j <= nbinsY; ++j) {
            // 获取原始 bin 的内容
            double content = h->GetBinContent(i, j);
            
            // 计算新的横坐标值
            double newX = h->GetXaxis()->GetBinCenter(i) + h->GetYaxis()->GetBinCenter(j);
            
            // 找到新横坐标对应的 bin
            int newBinX = h2d_new->GetXaxis()->FindBin(newX);
            
            // 更新新直方图的 bin 内容
            h2d_new->SetBinContent(newBinX, j, content + h2d_new->GetBinContent(newBinX, j));
        }
    }
    h2d_new -> Draw("colz");
    gStyle->SetOptStat(0);
    h2d_new->GetXaxis()->SetTitle("E_{total}(MeV)");
    h2d_new->GetYaxis()->SetTitle("#DeltaE(MeV)");
    h2d_new->GetYaxis()->CenterTitle(true);
    h2d_new->GetXaxis()->CenterTitle(true);
}