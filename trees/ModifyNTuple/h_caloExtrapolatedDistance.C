void h_caloExtrapolatedDistance()
{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Feb  4 12:59:49 2021) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,800,600);
   c1->SetHighLightColor(2);
   c1->Range(0,0,1,1);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   
   TH1F *h_caloExtrapolatedDistance__1 = new TH1F("h_caloExtrapolatedDistance__1","h_caloExtrapolatedDistance",1000,0,1500);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_caloExtrapolatedDistance__1->SetLineColor(ci);
   h_caloExtrapolatedDistance__1->GetXaxis()->SetLabelFont(42);
   h_caloExtrapolatedDistance__1->GetXaxis()->SetLabelSize(0.035);
   h_caloExtrapolatedDistance__1->GetXaxis()->SetTitleSize(0.035);
   h_caloExtrapolatedDistance__1->GetXaxis()->SetTitleFont(42);
   h_caloExtrapolatedDistance__1->GetYaxis()->SetLabelFont(42);
   h_caloExtrapolatedDistance__1->GetYaxis()->SetLabelSize(0.035);
   h_caloExtrapolatedDistance__1->GetYaxis()->SetTitleSize(0.035);
   h_caloExtrapolatedDistance__1->GetYaxis()->SetTitleOffset(0);
   h_caloExtrapolatedDistance__1->GetYaxis()->SetTitleFont(42);
   h_caloExtrapolatedDistance__1->GetZaxis()->SetLabelFont(42);
   h_caloExtrapolatedDistance__1->GetZaxis()->SetLabelSize(0.035);
   h_caloExtrapolatedDistance__1->GetZaxis()->SetTitleSize(0.035);
   h_caloExtrapolatedDistance__1->GetZaxis()->SetTitleFont(42);
   h_caloExtrapolatedDistance__1->Draw("HIST");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
