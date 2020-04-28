void trackAndTrackCalo_clusterEnergy()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:46 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-400,-51.975,3600,467.775);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *clusterEnergy__29 = new TH1D("clusterEnergy__29","",128,0,3200);
   clusterEnergy__29->SetBinContent(5,17);
   clusterEnergy__29->SetBinContent(6,123);
   clusterEnergy__29->SetBinContent(7,379);
   clusterEnergy__29->SetBinContent(8,396);
   clusterEnergy__29->SetBinContent(9,163);
   clusterEnergy__29->SetBinContent(10,56);
   clusterEnergy__29->SetBinContent(11,5);
   clusterEnergy__29->SetBinError(5,4.123106);
   clusterEnergy__29->SetBinError(6,11.09054);
   clusterEnergy__29->SetBinError(7,19.46792);
   clusterEnergy__29->SetBinError(8,19.89975);
   clusterEnergy__29->SetBinError(9,12.76715);
   clusterEnergy__29->SetBinError(10,7.483315);
   clusterEnergy__29->SetBinError(11,2.236068);
   clusterEnergy__29->SetEntries(1139);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("clusterEnergy");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 1139   ");
   ptstats_LaTex = ptstats->AddText("Mean  =  178.9");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  25.66");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   clusterEnergy__29->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(clusterEnergy__29);
   clusterEnergy__29->SetLineWidth(2);
   clusterEnergy__29->SetMarkerSize(1.5);
   clusterEnergy__29->GetXaxis()->SetTitle("Cluste energy [MeV]");
   clusterEnergy__29->GetXaxis()->SetLabelFont(42);
   clusterEnergy__29->GetXaxis()->SetTitleSize(0.035);
   clusterEnergy__29->GetXaxis()->SetTitleOffset(1.2);
   clusterEnergy__29->GetXaxis()->SetTitleFont(42);
   clusterEnergy__29->GetYaxis()->SetLabelFont(42);
   clusterEnergy__29->GetYaxis()->SetTitleSize(0.035);
   clusterEnergy__29->GetYaxis()->SetTitleOffset(1.2);
   clusterEnergy__29->GetYaxis()->SetTitleFont(42);
   clusterEnergy__29->GetZaxis()->SetLabelFont(42);
   clusterEnergy__29->GetZaxis()->SetLabelSize(0.035);
   clusterEnergy__29->GetZaxis()->SetTitleSize(0.035);
   clusterEnergy__29->GetZaxis()->SetTitleFont(42);
   clusterEnergy__29->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
