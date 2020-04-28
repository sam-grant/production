void trackAndTrackCalo_caloAndDecayVertexMomDiff()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:43 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-8750,-1485.881,8750,13372.93);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *caloAndDecayVertexMomDiff__1 = new TH1D("caloAndDecayVertexMomDiff__1","",1000,-7000,7000);
   caloAndDecayVertexMomDiff__1->SetBinContent(501,11321);
   caloAndDecayVertexMomDiff__1->SetBinError(501,106.4002);
   caloAndDecayVertexMomDiff__1->SetEntries(11321);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("caloAndDecayVertexMomDiff");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 11321  ");
   ptstats_LaTex = ptstats->AddText("Mean  =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   caloAndDecayVertexMomDiff__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(caloAndDecayVertexMomDiff__1);
   caloAndDecayVertexMomDiff__1->SetLineWidth(2);
   caloAndDecayVertexMomDiff__1->SetMarkerSize(1.5);
   caloAndDecayVertexMomDiff__1->GetXaxis()->SetTitle("Calo vertex momentum #minus decay vertex momentum [MeV]");
   caloAndDecayVertexMomDiff__1->GetXaxis()->SetLabelFont(42);
   caloAndDecayVertexMomDiff__1->GetXaxis()->SetTitleSize(0.035);
   caloAndDecayVertexMomDiff__1->GetXaxis()->SetTitleOffset(1.2);
   caloAndDecayVertexMomDiff__1->GetXaxis()->SetTitleFont(42);
   caloAndDecayVertexMomDiff__1->GetYaxis()->SetLabelFont(42);
   caloAndDecayVertexMomDiff__1->GetYaxis()->SetTitleSize(0.035);
   caloAndDecayVertexMomDiff__1->GetYaxis()->SetTitleOffset(1.2);
   caloAndDecayVertexMomDiff__1->GetYaxis()->SetTitleFont(42);
   caloAndDecayVertexMomDiff__1->GetZaxis()->SetLabelFont(42);
   caloAndDecayVertexMomDiff__1->GetZaxis()->SetLabelSize(0.035);
   caloAndDecayVertexMomDiff__1->GetZaxis()->SetTitleSize(0.035);
   caloAndDecayVertexMomDiff__1->GetZaxis()->SetTitleFont(42);
   caloAndDecayVertexMomDiff__1->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
