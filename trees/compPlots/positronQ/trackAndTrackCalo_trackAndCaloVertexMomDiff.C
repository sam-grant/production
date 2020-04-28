void trackAndTrackCalo_trackAndCaloVertexMomDiff()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:45 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-8750,-36954.36,8750,332589.2);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *trackAndCaloVertexMomDiff__19 = new TH1D("trackAndCaloVertexMomDiff__19","",1000,-7000,7000);
   trackAndCaloVertexMomDiff__19->SetBinContent(501,281557);
   trackAndCaloVertexMomDiff__19->SetBinError(501,530.6194);
   trackAndCaloVertexMomDiff__19->SetEntries(281557);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("trackAndCaloVertexMomDiff");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 281557 ");
   ptstats_LaTex = ptstats->AddText("Mean  =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   trackAndCaloVertexMomDiff__19->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(trackAndCaloVertexMomDiff__19);
   trackAndCaloVertexMomDiff__19->SetLineWidth(2);
   trackAndCaloVertexMomDiff__19->SetMarkerSize(1.5);
   trackAndCaloVertexMomDiff__19->GetXaxis()->SetTitle("Track momentum #minus calo vertex momentum [MeV]");
   trackAndCaloVertexMomDiff__19->GetXaxis()->SetLabelFont(42);
   trackAndCaloVertexMomDiff__19->GetXaxis()->SetTitleSize(0.035);
   trackAndCaloVertexMomDiff__19->GetXaxis()->SetTitleOffset(1.2);
   trackAndCaloVertexMomDiff__19->GetXaxis()->SetTitleFont(42);
   trackAndCaloVertexMomDiff__19->GetYaxis()->SetLabelFont(42);
   trackAndCaloVertexMomDiff__19->GetYaxis()->SetTitleSize(0.035);
   trackAndCaloVertexMomDiff__19->GetYaxis()->SetTitleOffset(1.2);
   trackAndCaloVertexMomDiff__19->GetYaxis()->SetTitleFont(42);
   trackAndCaloVertexMomDiff__19->GetZaxis()->SetLabelFont(42);
   trackAndCaloVertexMomDiff__19->GetZaxis()->SetLabelSize(0.035);
   trackAndCaloVertexMomDiff__19->GetZaxis()->SetTitleSize(0.035);
   trackAndCaloVertexMomDiff__19->GetZaxis()->SetTitleFont(42);
   trackAndCaloVertexMomDiff__19->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
