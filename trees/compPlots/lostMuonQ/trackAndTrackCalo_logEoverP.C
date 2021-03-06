void trackAndTrackCalo_logEoverP()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Apr 21 10:18:46 2020) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->Range(-6,-22.96875,4,206.7188);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1D *logEoverP__32 = new TH1D("logEoverP__32","",140,-5,3);
   logEoverP__32->SetBinContent(32,1);
   logEoverP__32->SetBinContent(33,11);
   logEoverP__32->SetBinContent(34,10);
   logEoverP__32->SetBinContent(35,19);
   logEoverP__32->SetBinContent(36,51);
   logEoverP__32->SetBinContent(37,78);
   logEoverP__32->SetBinContent(38,122);
   logEoverP__32->SetBinContent(39,143);
   logEoverP__32->SetBinContent(40,175);
   logEoverP__32->SetBinContent(41,166);
   logEoverP__32->SetBinContent(42,138);
   logEoverP__32->SetBinContent(43,96);
   logEoverP__32->SetBinContent(44,62);
   logEoverP__32->SetBinContent(45,46);
   logEoverP__32->SetBinContent(46,21);
   logEoverP__32->SetBinError(32,1);
   logEoverP__32->SetBinError(33,3.316625);
   logEoverP__32->SetBinError(34,3.162278);
   logEoverP__32->SetBinError(35,4.358899);
   logEoverP__32->SetBinError(36,7.141428);
   logEoverP__32->SetBinError(37,8.831761);
   logEoverP__32->SetBinError(38,11.04536);
   logEoverP__32->SetBinError(39,11.95826);
   logEoverP__32->SetBinError(40,13.22876);
   logEoverP__32->SetBinError(41,12.8841);
   logEoverP__32->SetBinError(42,11.74734);
   logEoverP__32->SetBinError(43,9.797959);
   logEoverP__32->SetBinError(44,7.874008);
   logEoverP__32->SetBinError(45,6.78233);
   logEoverP__32->SetBinError(46,4.582576);
   logEoverP__32->SetEntries(1139);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("logEoverP");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 1139   ");
   ptstats_LaTex = ptstats->AddText("Mean  =  -2.73");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.1501");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   logEoverP__32->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(logEoverP__32);
   logEoverP__32->SetLineWidth(2);
   logEoverP__32->SetMarkerSize(1.5);
   logEoverP__32->GetXaxis()->SetTitle("log(E/p)");
   logEoverP__32->GetXaxis()->SetLabelFont(42);
   logEoverP__32->GetXaxis()->SetTitleSize(0.035);
   logEoverP__32->GetXaxis()->SetTitleOffset(1.2);
   logEoverP__32->GetXaxis()->SetTitleFont(42);
   logEoverP__32->GetYaxis()->SetLabelFont(42);
   logEoverP__32->GetYaxis()->SetTitleSize(0.035);
   logEoverP__32->GetYaxis()->SetTitleOffset(1.2);
   logEoverP__32->GetYaxis()->SetTitleFont(42);
   logEoverP__32->GetZaxis()->SetLabelFont(42);
   logEoverP__32->GetZaxis()->SetLabelSize(0.035);
   logEoverP__32->GetZaxis()->SetTitleSize(0.035);
   logEoverP__32->GetZaxis()->SetTitleFont(42);
   logEoverP__32->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
