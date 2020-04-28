void trackAndTrackCalo_trackAndCaloVertexMomDiff()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:44 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-8750,-1485.881,8750,13372.93);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *trackAndCaloVertexMomDiff__3 = new TH1D("trackAndCaloVertexMomDiff__3","",1000,-7000,7000);
   trackAndCaloVertexMomDiff__3->SetBinContent(501,11321);
   trackAndCaloVertexMomDiff__3->SetBinError(501,106.4002);
   trackAndCaloVertexMomDiff__3->SetEntries(11321);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("trackAndCaloVertexMomDiff");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 11321  ");
   ptstats_LaTex = ptstats->AddText("Mean  =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   trackAndCaloVertexMomDiff__3->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(trackAndCaloVertexMomDiff__3);
   trackAndCaloVertexMomDiff__3->SetLineWidth(2);
   trackAndCaloVertexMomDiff__3->SetMarkerSize(1.5);
   trackAndCaloVertexMomDiff__3->GetXaxis()->SetTitle("Track momentum #minus calo vertex momentum [MeV]");
   trackAndCaloVertexMomDiff__3->GetXaxis()->SetLabelFont(42);
   trackAndCaloVertexMomDiff__3->GetXaxis()->SetTitleSize(0.035);
   trackAndCaloVertexMomDiff__3->GetXaxis()->SetTitleOffset(1.2);
   trackAndCaloVertexMomDiff__3->GetXaxis()->SetTitleFont(42);
   trackAndCaloVertexMomDiff__3->GetYaxis()->SetLabelFont(42);
   trackAndCaloVertexMomDiff__3->GetYaxis()->SetTitleSize(0.035);
   trackAndCaloVertexMomDiff__3->GetYaxis()->SetTitleOffset(1.2);
   trackAndCaloVertexMomDiff__3->GetYaxis()->SetTitleFont(42);
   trackAndCaloVertexMomDiff__3->GetZaxis()->SetLabelFont(42);
   trackAndCaloVertexMomDiff__3->GetZaxis()->SetLabelSize(0.035);
   trackAndCaloVertexMomDiff__3->GetZaxis()->SetTitleSize(0.035);
   trackAndCaloVertexMomDiff__3->GetZaxis()->SetTitleFont(42);
   trackAndCaloVertexMomDiff__3->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
