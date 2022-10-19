void caloAndDecayVertexMomDiff()
{
//=========Macro generated from canvas: c/c
//=========  (Fri Feb  5 17:53:16 2021) by ROOT version 6.12/04
   TCanvas *c = new TCanvas("c", "c",0,0,800,600);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   
   TH1D *caloAndDecayVertexMomDiff__1 = new TH1D("caloAndDecayVertexMomDiff__1","",1000,-7000,7000);
   caloAndDecayVertexMomDiff__1->SetBinContent(501,256795);
   caloAndDecayVertexMomDiff__1->SetBinError(501,506.7494);
   caloAndDecayVertexMomDiff__1->SetEntries(256795);
   caloAndDecayVertexMomDiff__1->SetLineWidth(2);
   caloAndDecayVertexMomDiff__1->SetMarkerSize(1.5);
   caloAndDecayVertexMomDiff__1->GetXaxis()->SetTitle("Calo vertex momentum #minus decay vertex momentum [MeV]");
   caloAndDecayVertexMomDiff__1->GetXaxis()->CenterTitle(true);
   caloAndDecayVertexMomDiff__1->GetXaxis()->SetLabelFont(42);
   caloAndDecayVertexMomDiff__1->GetXaxis()->SetTitleOffset(1.1);
   caloAndDecayVertexMomDiff__1->GetXaxis()->SetTitleFont(42);
   caloAndDecayVertexMomDiff__1->GetYaxis()->CenterTitle(true);
   caloAndDecayVertexMomDiff__1->GetYaxis()->SetNdivisions(4000510);
   caloAndDecayVertexMomDiff__1->GetYaxis()->SetLabelFont(42);
   caloAndDecayVertexMomDiff__1->GetYaxis()->SetTitleOffset(1.1);
   caloAndDecayVertexMomDiff__1->GetYaxis()->SetTitleFont(42);
   caloAndDecayVertexMomDiff__1->GetZaxis()->SetLabelFont(42);
   caloAndDecayVertexMomDiff__1->GetZaxis()->SetLabelSize(0.035);
   caloAndDecayVertexMomDiff__1->GetZaxis()->SetTitleSize(0.035);
   caloAndDecayVertexMomDiff__1->GetZaxis()->SetTitleFont(42);
   caloAndDecayVertexMomDiff__1->Draw("HIST");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
