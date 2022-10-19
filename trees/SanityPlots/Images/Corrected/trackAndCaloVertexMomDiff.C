void trackAndCaloVertexMomDiff()
{
//=========Macro generated from canvas: c/c
//=========  (Fri Feb  5 17:53:16 2021) by ROOT version 6.12/04
   TCanvas *c = new TCanvas("c", "c",0,0,800,600);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetFrameBorderMode(0);
   
   TH1D *trackAndCaloVertexMomDiff__3 = new TH1D("trackAndCaloVertexMomDiff__3","",1000,-7000,7000);
   trackAndCaloVertexMomDiff__3->SetBinContent(501,256795);
   trackAndCaloVertexMomDiff__3->SetBinError(501,506.7494);
   trackAndCaloVertexMomDiff__3->SetEntries(256795);
   trackAndCaloVertexMomDiff__3->SetLineWidth(2);
   trackAndCaloVertexMomDiff__3->SetMarkerSize(1.5);
   trackAndCaloVertexMomDiff__3->GetXaxis()->SetTitle("Track momentum #minus calo vertex momentum [MeV]");
   trackAndCaloVertexMomDiff__3->GetXaxis()->CenterTitle(true);
   trackAndCaloVertexMomDiff__3->GetXaxis()->SetLabelFont(42);
   trackAndCaloVertexMomDiff__3->GetXaxis()->SetTitleOffset(1.1);
   trackAndCaloVertexMomDiff__3->GetXaxis()->SetTitleFont(42);
   trackAndCaloVertexMomDiff__3->GetYaxis()->CenterTitle(true);
   trackAndCaloVertexMomDiff__3->GetYaxis()->SetNdivisions(4000510);
   trackAndCaloVertexMomDiff__3->GetYaxis()->SetLabelFont(42);
   trackAndCaloVertexMomDiff__3->GetYaxis()->SetTitleOffset(1.1);
   trackAndCaloVertexMomDiff__3->GetYaxis()->SetTitleFont(42);
   trackAndCaloVertexMomDiff__3->GetZaxis()->SetLabelFont(42);
   trackAndCaloVertexMomDiff__3->GetZaxis()->SetLabelSize(0.035);
   trackAndCaloVertexMomDiff__3->GetZaxis()->SetTitleSize(0.035);
   trackAndCaloVertexMomDiff__3->GetZaxis()->SetTitleFont(42);
   trackAndCaloVertexMomDiff__3->Draw("HIST");
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
