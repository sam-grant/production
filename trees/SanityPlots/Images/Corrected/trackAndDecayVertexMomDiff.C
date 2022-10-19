void trackAndDecayVertexMomDiff()
{
//=========Macro generated from canvas: c/c
//=========  (Fri Feb  5 17:53:16 2021) by ROOT version 6.12/04
   TCanvas *c = new TCanvas("c", "c",0,0,800,600);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   
   TH1D *trackAndDecayVertexMomDiff__2 = new TH1D("trackAndDecayVertexMomDiff__2","",1000,-7000,7000);
   trackAndDecayVertexMomDiff__2->SetBinContent(501,256795);
   trackAndDecayVertexMomDiff__2->SetBinError(501,506.7494);
   trackAndDecayVertexMomDiff__2->SetEntries(256795);
   trackAndDecayVertexMomDiff__2->SetLineWidth(2);
   trackAndDecayVertexMomDiff__2->SetMarkerSize(1.5);
   trackAndDecayVertexMomDiff__2->GetXaxis()->SetTitle("Track momentum #minus decay vertex momentum [MeV]");
   trackAndDecayVertexMomDiff__2->GetXaxis()->CenterTitle(true);
   trackAndDecayVertexMomDiff__2->GetXaxis()->SetLabelFont(42);
   trackAndDecayVertexMomDiff__2->GetXaxis()->SetTitleOffset(1.1);
   trackAndDecayVertexMomDiff__2->GetXaxis()->SetTitleFont(42);
   trackAndDecayVertexMomDiff__2->GetYaxis()->CenterTitle(true);
   trackAndDecayVertexMomDiff__2->GetYaxis()->SetNdivisions(4000510);
   trackAndDecayVertexMomDiff__2->GetYaxis()->SetLabelFont(42);
   trackAndDecayVertexMomDiff__2->GetYaxis()->SetTitleOffset(1.1);
   trackAndDecayVertexMomDiff__2->GetYaxis()->SetTitleFont(42);
   trackAndDecayVertexMomDiff__2->GetZaxis()->SetLabelFont(42);
   trackAndDecayVertexMomDiff__2->GetZaxis()->SetLabelSize(0.035);
   trackAndDecayVertexMomDiff__2->GetZaxis()->SetTitleSize(0.035);
   trackAndDecayVertexMomDiff__2->GetZaxis()->SetTitleFont(42);
   trackAndDecayVertexMomDiff__2->Draw("HIST");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
