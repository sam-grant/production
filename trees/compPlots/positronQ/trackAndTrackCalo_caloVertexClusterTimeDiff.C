void trackAndTrackCalo_caloVertexClusterTimeDiff()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:45 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-24.375,-427.0875,19.375,3843.788);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *caloVertexClusterTimeDiff__23 = new TH1D("caloVertexClusterTimeDiff__23","",35,-20,15);
   caloVertexClusterTimeDiff__23->SetBinContent(12,4);
   caloVertexClusterTimeDiff__23->SetBinContent(13,44);
   caloVertexClusterTimeDiff__23->SetBinContent(14,245);
   caloVertexClusterTimeDiff__23->SetBinContent(15,1164);
   caloVertexClusterTimeDiff__23->SetBinContent(16,2307);
   caloVertexClusterTimeDiff__23->SetBinContent(17,3088);
   caloVertexClusterTimeDiff__23->SetBinContent(18,3254);
   caloVertexClusterTimeDiff__23->SetBinContent(19,2482);
   caloVertexClusterTimeDiff__23->SetBinContent(20,1365);
   caloVertexClusterTimeDiff__23->SetBinContent(21,452);
   caloVertexClusterTimeDiff__23->SetBinContent(22,65);
   caloVertexClusterTimeDiff__23->SetBinContent(23,9);
   caloVertexClusterTimeDiff__23->SetBinError(12,2);
   caloVertexClusterTimeDiff__23->SetBinError(13,6.63325);
   caloVertexClusterTimeDiff__23->SetBinError(14,15.65248);
   caloVertexClusterTimeDiff__23->SetBinError(15,34.11744);
   caloVertexClusterTimeDiff__23->SetBinError(16,48.03124);
   caloVertexClusterTimeDiff__23->SetBinError(17,55.56978);
   caloVertexClusterTimeDiff__23->SetBinError(18,57.04384);
   caloVertexClusterTimeDiff__23->SetBinError(19,49.81967);
   caloVertexClusterTimeDiff__23->SetBinError(20,36.94591);
   caloVertexClusterTimeDiff__23->SetBinError(21,21.26029);
   caloVertexClusterTimeDiff__23->SetBinError(22,8.062258);
   caloVertexClusterTimeDiff__23->SetBinError(23,3);
   caloVertexClusterTimeDiff__23->SetEntries(14479);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("caloVertexClusterTimeDiff");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 14479  ");
   ptstats_LaTex = ptstats->AddText("Mean  =  -2.88");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  1.618");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   caloVertexClusterTimeDiff__23->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(caloVertexClusterTimeDiff__23);
   caloVertexClusterTimeDiff__23->SetLineWidth(2);
   caloVertexClusterTimeDiff__23->SetMarkerSize(1.5);
   caloVertexClusterTimeDiff__23->GetXaxis()->SetTitle("Calo vertex time #minus cluster time [ns]");
   caloVertexClusterTimeDiff__23->GetXaxis()->SetLabelFont(42);
   caloVertexClusterTimeDiff__23->GetXaxis()->SetTitleSize(0.035);
   caloVertexClusterTimeDiff__23->GetXaxis()->SetTitleOffset(1.2);
   caloVertexClusterTimeDiff__23->GetXaxis()->SetTitleFont(42);
   caloVertexClusterTimeDiff__23->GetYaxis()->SetLabelFont(42);
   caloVertexClusterTimeDiff__23->GetYaxis()->SetTitleSize(0.035);
   caloVertexClusterTimeDiff__23->GetYaxis()->SetTitleOffset(1.2);
   caloVertexClusterTimeDiff__23->GetYaxis()->SetTitleFont(42);
   caloVertexClusterTimeDiff__23->GetZaxis()->SetLabelFont(42);
   caloVertexClusterTimeDiff__23->GetZaxis()->SetLabelSize(0.035);
   caloVertexClusterTimeDiff__23->GetZaxis()->SetTitleSize(0.035);
   caloVertexClusterTimeDiff__23->GetZaxis()->SetTitleFont(42);
   caloVertexClusterTimeDiff__23->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
