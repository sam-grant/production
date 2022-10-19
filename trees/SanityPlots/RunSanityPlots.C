void DrawTH1(TH1D *hist, std::string fname) {

  TCanvas *c = new TCanvas("c","c",800,600);

  gStyle->SetOptStat(2210);
      
  hist->GetXaxis()->SetTitleSize(.04);
  hist->GetYaxis()->SetTitleSize(.04);
  hist->GetXaxis()->SetTitleOffset(1.1);
  hist->GetYaxis()->SetTitleOffset(1.1);
  hist->GetXaxis()->CenterTitle(1);
  hist->GetYaxis()->CenterTitle(1);
  hist->GetYaxis()->SetMaxDigits(4);
  hist->SetLineColor(1);

  hist->Draw("HIST");
  
  c->SaveAs((fname+".C").c_str());
  c->SaveAs((fname+".pdf").c_str());
  c->SaveAs((fname+".png").c_str());

  delete c;

  return;
}

void DrawTH2(TH2D *hist, std::string fname) {

  TCanvas *c = new TCanvas("c","c",800,600);
  //hist->SetStats(0);
      
  hist->GetXaxis()->SetTitleSize(.04);
  hist->GetYaxis()->SetTitleSize(.04);
  hist->GetXaxis()->SetTitleOffset(1.1);
  hist->GetYaxis()->SetTitleOffset(1.1);
  hist->GetXaxis()->CenterTitle(1);
  hist->GetYaxis()->CenterTitle(1);
  hist->GetYaxis()->SetMaxDigits(4);

  gStyle->SetPalette(55);
  c->SetRightMargin(0.13);

  hist->Draw("COLZ");
  
  c->SaveAs((fname+".C").c_str());
  c->SaveAs((fname+".pdf").c_str());
  c->SaveAs((fname+".png").c_str());

  delete c;

  return;
}


void RunSanityPlots() {
  
    string outDir = "Images/Uncorrected";
    TFile *file = TFile::Open("Plots/plots_Run1_15921.root");

    // string outDir = "Images/Corrected";
    // TFile *file = TFile::Open("Plots/plots_Run1_15921_corrected.root");


    string histNames[20] = {"pValues", "trackT0", "trackMomentum", "radialPos", "verticalPos",
                            "clusterTime", "clusterEnergy", "caloVertexClusterRadialDiff", "caloVertexClusterTimeDiff", "logEoverP", 
                            "zPos_vs_xPos", "St12_zPos_vs_xPos", "St18_zPos_vs_xPos", "radialPos_vs_time", "verticalPos_vs_time",
                            "caloVertY_vs_caloVertX", "cluY_vs_cluX", "EoverP_vs_time", "uncorrEoverP_vs_time", "EvsP"};
  
    for(int i_hist = 0; i_hist<13; i_hist++) {
        
        if(i_hist<10) { 

          TH1D *hist1 = (TH1D*)file->Get(histNames[i_hist].c_str());

          DrawTH1(hist1,outDir+"/"+histNames[i_hist]);

        } else {  

          TH2D *hist2 = (TH2D*)file->Get(histNames[i_hist].c_str());

          DrawTH2(hist2,outDir+"/"+histNames[i_hist]);

        }

    }


  return;

}
