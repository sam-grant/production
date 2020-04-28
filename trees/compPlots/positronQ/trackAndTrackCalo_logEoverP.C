void trackAndTrackCalo_logEoverP()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:45 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-6,-626.7188,4,5640.469);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *logEoverP__24 = new TH1D("logEoverP__24","",140,-5,3);
   logEoverP__24->SetBinContent(83,234);
   logEoverP__24->SetBinContent(84,438);
   logEoverP__24->SetBinContent(85,852);
   logEoverP__24->SetBinContent(86,2193);
   logEoverP__24->SetBinContent(87,4775);
   logEoverP__24->SetBinContent(88,4458);
   logEoverP__24->SetBinContent(89,1342);
   logEoverP__24->SetBinContent(90,158);
   logEoverP__24->SetBinContent(91,29);
   logEoverP__24->SetBinError(83,15.29706);
   logEoverP__24->SetBinError(84,20.92845);
   logEoverP__24->SetBinError(85,29.18904);
   logEoverP__24->SetBinError(86,46.82948);
   logEoverP__24->SetBinError(87,69.10137);
   logEoverP__24->SetBinError(88,66.76826);
   logEoverP__24->SetBinError(89,36.63332);
   logEoverP__24->SetBinError(90,12.56981);
   logEoverP__24->SetBinError(91,5.385165);
   logEoverP__24->SetEntries(14479);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("logEoverP");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 14479  ");
   ptstats_LaTex = ptstats->AddText("Mean  = -0.05091");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.07273");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   logEoverP__24->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(logEoverP__24);
   logEoverP__24->SetLineWidth(2);
   logEoverP__24->SetMarkerSize(1.5);
   logEoverP__24->GetXaxis()->SetTitle("log(E/p)");
   logEoverP__24->GetXaxis()->SetLabelFont(42);
   logEoverP__24->GetXaxis()->SetTitleSize(0.035);
   logEoverP__24->GetXaxis()->SetTitleOffset(1.2);
   logEoverP__24->GetXaxis()->SetTitleFont(42);
   logEoverP__24->GetYaxis()->SetLabelFont(42);
   logEoverP__24->GetYaxis()->SetTitleSize(0.035);
   logEoverP__24->GetYaxis()->SetTitleOffset(1.2);
   logEoverP__24->GetYaxis()->SetTitleFont(42);
   logEoverP__24->GetZaxis()->SetLabelFont(42);
   logEoverP__24->GetZaxis()->SetLabelSize(0.035);
   logEoverP__24->GetZaxis()->SetTitleSize(0.035);
   logEoverP__24->GetZaxis()->SetTitleFont(42);
   logEoverP__24->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
