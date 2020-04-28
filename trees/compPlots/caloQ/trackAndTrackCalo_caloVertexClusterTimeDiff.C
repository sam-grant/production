void trackAndTrackCalo_caloVertexClusterTimeDiff()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:44 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-24.375,-506.3625,19.375,4557.263);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *caloVertexClusterTimeDiff__15 = new TH1D("caloVertexClusterTimeDiff__15","",35,-20,15);
   caloVertexClusterTimeDiff__15->SetBinContent(12,5);
   caloVertexClusterTimeDiff__15->SetBinContent(13,65);
   caloVertexClusterTimeDiff__15->SetBinContent(14,348);
   caloVertexClusterTimeDiff__15->SetBinContent(15,1449);
   caloVertexClusterTimeDiff__15->SetBinContent(16,2813);
   caloVertexClusterTimeDiff__15->SetBinContent(17,3734);
   caloVertexClusterTimeDiff__15->SetBinContent(18,3858);
   caloVertexClusterTimeDiff__15->SetBinContent(19,2910);
   caloVertexClusterTimeDiff__15->SetBinContent(20,1613);
   caloVertexClusterTimeDiff__15->SetBinContent(21,547);
   caloVertexClusterTimeDiff__15->SetBinContent(22,93);
   caloVertexClusterTimeDiff__15->SetBinContent(23,10);
   caloVertexClusterTimeDiff__15->SetBinError(12,2.236068);
   caloVertexClusterTimeDiff__15->SetBinError(13,8.062258);
   caloVertexClusterTimeDiff__15->SetBinError(14,18.65476);
   caloVertexClusterTimeDiff__15->SetBinError(15,38.06573);
   caloVertexClusterTimeDiff__15->SetBinError(16,53.03772);
   caloVertexClusterTimeDiff__15->SetBinError(17,61.10646);
   caloVertexClusterTimeDiff__15->SetBinError(18,62.1128);
   caloVertexClusterTimeDiff__15->SetBinError(19,53.94442);
   caloVertexClusterTimeDiff__15->SetBinError(20,40.16217);
   caloVertexClusterTimeDiff__15->SetBinError(21,23.38803);
   caloVertexClusterTimeDiff__15->SetBinError(22,9.643651);
   caloVertexClusterTimeDiff__15->SetBinError(23,3.162278);
   caloVertexClusterTimeDiff__15->SetEntries(17445);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("caloVertexClusterTimeDiff");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 17445  ");
   ptstats_LaTex = ptstats->AddText("Mean  = -2.914");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  1.641");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   caloVertexClusterTimeDiff__15->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(caloVertexClusterTimeDiff__15);
   caloVertexClusterTimeDiff__15->SetLineWidth(2);
   caloVertexClusterTimeDiff__15->SetMarkerSize(1.5);
   caloVertexClusterTimeDiff__15->GetXaxis()->SetTitle("Calo vertex time #minus cluster time [ns]");
   caloVertexClusterTimeDiff__15->GetXaxis()->SetLabelFont(42);
   caloVertexClusterTimeDiff__15->GetXaxis()->SetTitleSize(0.035);
   caloVertexClusterTimeDiff__15->GetXaxis()->SetTitleOffset(1.2);
   caloVertexClusterTimeDiff__15->GetXaxis()->SetTitleFont(42);
   caloVertexClusterTimeDiff__15->GetYaxis()->SetLabelFont(42);
   caloVertexClusterTimeDiff__15->GetYaxis()->SetTitleSize(0.035);
   caloVertexClusterTimeDiff__15->GetYaxis()->SetTitleOffset(1.2);
   caloVertexClusterTimeDiff__15->GetYaxis()->SetTitleFont(42);
   caloVertexClusterTimeDiff__15->GetZaxis()->SetLabelFont(42);
   caloVertexClusterTimeDiff__15->GetZaxis()->SetLabelSize(0.035);
   caloVertexClusterTimeDiff__15->GetZaxis()->SetTitleSize(0.035);
   caloVertexClusterTimeDiff__15->GetZaxis()->SetTitleFont(42);
   caloVertexClusterTimeDiff__15->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
