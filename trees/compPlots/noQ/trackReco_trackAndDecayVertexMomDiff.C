void trackReco_trackAndDecayVertexMomDiff()
{
//=========Macro generated from canvas: c1/c1
//=========  (Sat Apr 11 11:50:29 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-8750,-36954.36,8750,332589.2);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *trackAndDecayVertexMomDiff__2 = new TH1D("trackAndDecayVertexMomDiff__2","",1000,-7000,7000);
   trackAndDecayVertexMomDiff__2->SetBinContent(501,281557);
   trackAndDecayVertexMomDiff__2->SetBinError(501,530.6194);
   trackAndDecayVertexMomDiff__2->SetEntries(281557);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("trackAndDecayVertexMomDiff");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 281557 ");
   ptstats_LaTex = ptstats->AddText("Mean  =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   trackAndDecayVertexMomDiff__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(trackAndDecayVertexMomDiff__2);
   trackAndDecayVertexMomDiff__2->SetLineWidth(2);
   trackAndDecayVertexMomDiff__2->SetMarkerSize(1.5);
   trackAndDecayVertexMomDiff__2->GetXaxis()->SetTitle("Track momentum #minus decay vertex momentum [MeV]");
   trackAndDecayVertexMomDiff__2->GetXaxis()->SetLabelFont(42);
   trackAndDecayVertexMomDiff__2->GetXaxis()->SetTitleSize(0.035);
   trackAndDecayVertexMomDiff__2->GetXaxis()->SetTitleOffset(1.2);
   trackAndDecayVertexMomDiff__2->GetXaxis()->SetTitleFont(42);
   trackAndDecayVertexMomDiff__2->GetYaxis()->SetLabelFont(42);
   trackAndDecayVertexMomDiff__2->GetYaxis()->SetTitleSize(0.035);
   trackAndDecayVertexMomDiff__2->GetYaxis()->SetTitleOffset(1.2);
   trackAndDecayVertexMomDiff__2->GetYaxis()->SetTitleFont(42);
   trackAndDecayVertexMomDiff__2->GetZaxis()->SetLabelFont(42);
   trackAndDecayVertexMomDiff__2->GetZaxis()->SetLabelSize(0.035);
   trackAndDecayVertexMomDiff__2->GetZaxis()->SetTitleSize(0.035);
   trackAndDecayVertexMomDiff__2->GetZaxis()->SetTitleFont(42);
   trackAndDecayVertexMomDiff__2->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
