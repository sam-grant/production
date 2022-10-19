void h_decayExtrapolatedDistance()
{
//=========Macro generated from canvas: c2/c2
//=========  (Thu Feb  4 12:59:49 2021) by ROOT version 6.12/04
   TCanvas *c2 = new TCanvas("c2", "c2",0,0,800,600);
   c2->SetHighLightColor(2);
   c2->Range(0,0,1,1);
   c2->SetFillColor(0);
   c2->SetBorderMode(0);
   c2->SetBorderSize(2);
   c2->SetFrameBorderMode(0);
   
   TH1F *h_decayExtrapolatedDistance__2 = new TH1F("h_decayExtrapolatedDistance__2","h_decayExtrapolatedDistance",1000,0,7000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_decayExtrapolatedDistance__2->SetLineColor(ci);
   h_decayExtrapolatedDistance__2->GetXaxis()->SetLabelFont(42);
   h_decayExtrapolatedDistance__2->GetXaxis()->SetLabelSize(0.035);
   h_decayExtrapolatedDistance__2->GetXaxis()->SetTitleSize(0.035);
   h_decayExtrapolatedDistance__2->GetXaxis()->SetTitleFont(42);
   h_decayExtrapolatedDistance__2->GetYaxis()->SetLabelFont(42);
   h_decayExtrapolatedDistance__2->GetYaxis()->SetLabelSize(0.035);
   h_decayExtrapolatedDistance__2->GetYaxis()->SetTitleSize(0.035);
   h_decayExtrapolatedDistance__2->GetYaxis()->SetTitleOffset(0);
   h_decayExtrapolatedDistance__2->GetYaxis()->SetTitleFont(42);
   h_decayExtrapolatedDistance__2->GetZaxis()->SetLabelFont(42);
   h_decayExtrapolatedDistance__2->GetZaxis()->SetLabelSize(0.035);
   h_decayExtrapolatedDistance__2->GetZaxis()->SetTitleSize(0.035);
   h_decayExtrapolatedDistance__2->GetZaxis()->SetTitleFont(42);
   h_decayExtrapolatedDistance__2->Draw("HIST");
   c2->Modified();
   c2->cd();
   c2->SetSelected(c2);
}
