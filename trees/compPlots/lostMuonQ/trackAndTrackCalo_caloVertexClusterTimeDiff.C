void trackAndTrackCalo_caloVertexClusterTimeDiff()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:46 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-24.375,-37.66875,19.375,339.0188);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *caloVertexClusterTimeDiff__31 = new TH1D("caloVertexClusterTimeDiff__31","",35,-20,15);
   caloVertexClusterTimeDiff__31->SetBinContent(13,16);
   caloVertexClusterTimeDiff__31->SetBinContent(14,63);
   caloVertexClusterTimeDiff__31->SetBinContent(15,169);
   caloVertexClusterTimeDiff__31->SetBinContent(16,277);
   caloVertexClusterTimeDiff__31->SetBinContent(17,287);
   caloVertexClusterTimeDiff__31->SetBinContent(18,203);
   caloVertexClusterTimeDiff__31->SetBinContent(19,87);
   caloVertexClusterTimeDiff__31->SetBinContent(20,33);
   caloVertexClusterTimeDiff__31->SetBinContent(21,4);
   caloVertexClusterTimeDiff__31->SetBinError(13,4);
   caloVertexClusterTimeDiff__31->SetBinError(14,7.937254);
   caloVertexClusterTimeDiff__31->SetBinError(15,13);
   caloVertexClusterTimeDiff__31->SetBinError(16,16.64332);
   caloVertexClusterTimeDiff__31->SetBinError(17,16.94107);
   caloVertexClusterTimeDiff__31->SetBinError(18,14.24781);
   caloVertexClusterTimeDiff__31->SetBinError(19,9.327379);
   caloVertexClusterTimeDiff__31->SetBinError(20,5.744563);
   caloVertexClusterTimeDiff__31->SetBinError(21,2);
   caloVertexClusterTimeDiff__31->SetEntries(1139);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("caloVertexClusterTimeDiff");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 1139   ");
   ptstats_LaTex = ptstats->AddText("Mean  = -3.831");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  1.475");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   caloVertexClusterTimeDiff__31->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(caloVertexClusterTimeDiff__31);
   caloVertexClusterTimeDiff__31->SetLineWidth(2);
   caloVertexClusterTimeDiff__31->SetMarkerSize(1.5);
   caloVertexClusterTimeDiff__31->GetXaxis()->SetTitle("Calo vertex time #minus cluster time [ns]");
   caloVertexClusterTimeDiff__31->GetXaxis()->SetLabelFont(42);
   caloVertexClusterTimeDiff__31->GetXaxis()->SetTitleSize(0.035);
   caloVertexClusterTimeDiff__31->GetXaxis()->SetTitleOffset(1.2);
   caloVertexClusterTimeDiff__31->GetXaxis()->SetTitleFont(42);
   caloVertexClusterTimeDiff__31->GetYaxis()->SetLabelFont(42);
   caloVertexClusterTimeDiff__31->GetYaxis()->SetTitleSize(0.035);
   caloVertexClusterTimeDiff__31->GetYaxis()->SetTitleOffset(1.2);
   caloVertexClusterTimeDiff__31->GetYaxis()->SetTitleFont(42);
   caloVertexClusterTimeDiff__31->GetZaxis()->SetLabelFont(42);
   caloVertexClusterTimeDiff__31->GetZaxis()->SetLabelSize(0.035);
   caloVertexClusterTimeDiff__31->GetZaxis()->SetTitleSize(0.035);
   caloVertexClusterTimeDiff__31->GetZaxis()->SetTitleFont(42);
   caloVertexClusterTimeDiff__31->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
