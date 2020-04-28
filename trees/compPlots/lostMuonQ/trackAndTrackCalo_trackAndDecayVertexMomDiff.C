void trackAndTrackCalo_trackAndDecayVertexMomDiff()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:46 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-8750,-36954.36,8750,332589.2);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *trackAndDecayVertexMomDiff__26 = new TH1D("trackAndDecayVertexMomDiff__26","",1000,-7000,7000);
   trackAndDecayVertexMomDiff__26->SetBinContent(501,281557);
   trackAndDecayVertexMomDiff__26->SetBinError(501,530.6194);
   trackAndDecayVertexMomDiff__26->SetEntries(281557);
   
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
   trackAndDecayVertexMomDiff__26->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(trackAndDecayVertexMomDiff__26);
   trackAndDecayVertexMomDiff__26->SetLineWidth(2);
   trackAndDecayVertexMomDiff__26->SetMarkerSize(1.5);
   trackAndDecayVertexMomDiff__26->GetXaxis()->SetTitle("Track momentum #minus decay vertex momentum [MeV]");
   trackAndDecayVertexMomDiff__26->GetXaxis()->SetLabelFont(42);
   trackAndDecayVertexMomDiff__26->GetXaxis()->SetTitleSize(0.035);
   trackAndDecayVertexMomDiff__26->GetXaxis()->SetTitleOffset(1.2);
   trackAndDecayVertexMomDiff__26->GetXaxis()->SetTitleFont(42);
   trackAndDecayVertexMomDiff__26->GetYaxis()->SetLabelFont(42);
   trackAndDecayVertexMomDiff__26->GetYaxis()->SetTitleSize(0.035);
   trackAndDecayVertexMomDiff__26->GetYaxis()->SetTitleOffset(1.2);
   trackAndDecayVertexMomDiff__26->GetYaxis()->SetTitleFont(42);
   trackAndDecayVertexMomDiff__26->GetZaxis()->SetLabelFont(42);
   trackAndDecayVertexMomDiff__26->GetZaxis()->SetLabelSize(0.035);
   trackAndDecayVertexMomDiff__26->GetZaxis()->SetTitleSize(0.035);
   trackAndDecayVertexMomDiff__26->GetZaxis()->SetTitleFont(42);
   trackAndDecayVertexMomDiff__26->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
