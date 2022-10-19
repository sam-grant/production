void ReadTree() { 

  TFile *file = TFile::Open("/gm2/data/g2be/Production/TrackQualityTrees/run2C/trackRecoTrees_quality_8735923_24956.00171_corrected.root");///gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_15921.root");//newTree.root");
  //TFile *file = TFile::Open("oldTree.root");

  TTree *tree = (TTree*)file->Get("QualityTracks/QualityTracks");

  if (!tree) {
    cout << "Error: tree not found." << endl;
    delete file;
    return;
  }

  tree->Print();

  Float_t decayExtrapolatedDistance; 
  Float_t caloExtrapolatedDistance;

  tree->SetBranchAddress("decayExtrapolatedDistance",&decayExtrapolatedDistance);
  tree->SetBranchAddress("caloExtrapolatedDistance",&caloExtrapolatedDistance);

  TH1F *h_decayExtrapolatedDistance = new TH1F("h_decayExtrapolatedDistance","h_decayExtrapolatedDistance",1000, 0, 7000);
  TH1F *h_caloExtrapolatedDistance = new TH1F("h_caloExtrapolatedDistance","h_caloExtrapolatedDistance",1000, 0, 1500);
    
  Long64_t nEntries = tree->GetEntries();

  for (Long64_t i_entry=0; i_entry<nEntries; i_entry++) {

    tree->GetEntry(i_entry);

    h_decayExtrapolatedDistance->Fill(decayExtrapolatedDistance);
    h_caloExtrapolatedDistance->Fill(caloExtrapolatedDistance);

  }

  TCanvas *c1 = new TCanvas("c1","c1",800,600);
  h_caloExtrapolatedDistance->Draw("HIST");
  c1->SaveAs("h_caloExtrapolatedDistance.png");

  TCanvas *c2 = new TCanvas("c2","c2",800,600);
  h_decayExtrapolatedDistance->Draw("HIST");
  c2->SaveAs("h_decayExtrapolatedDistance.png");

  return;
}
