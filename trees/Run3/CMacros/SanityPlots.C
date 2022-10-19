void SanityPlots() {

  string config = "run1"; 
  //  string config = "caloReco"; 

  TFile *file = TFile::Open("/gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_15921.root");// /pnfs/GM2/persistent/Tracking/autoTests/Run3/NW/34186/hadd/2021-02-08-02-39-04/data/gm234186_hadd_41702868_1.root"); //("../testTree/"+config+".root").c_str());

  TTree *tree = (TTree*)file->Get("trackAndTrackCalo/tree");

  if (!tree) {
    cout << "Error: tree not found." << endl;
    delete file;
    return;
  }

  // tree->Print();

  Float_t decayExtrapolatedDistance;
  Float_t caloExtrapolatedDistance;
  Float_t caloVertexMom;
  Bool_t hasDecayVertex;

  tree->SetBranchAddress("hasDecayVertex",&hasDecayVertex);
  tree->SetBranchAddress("decayExtrapolatedDistance",&decayExtrapolatedDistance);
  tree->SetBranchAddress("caloExtrapolatedDistance",&caloExtrapolatedDistance);
  tree->SetBranchAddress("caloVertexMom",&caloVertexMom);

  TH1F *h_decayExtrapolatedDistance = new TH1F("h_decayExtrapolatedDistance","h_decayExtrapolatedDistance",1000, 0, 100000);
  TH1F *h_caloExtrapolatedDistance = new TH1F("h_caloExtrapolatedDistance","h_caloExtrapolatedDistance",1000, 0, 1500);
  TH1F *h_caloVertexMom = new TH1F("h_caloVertexMom","h_caloVertexMom",1000, 0, 3200);

  Long64_t nEntries = tree->GetEntries();

  for (Long64_t i_entry=0; i_entry<nEntries; i_entry++) {

    tree->GetEntry(i_entry);

    h_decayExtrapolatedDistance->Fill(decayExtrapolatedDistance);
    h_caloExtrapolatedDistance->Fill(caloExtrapolatedDistance);
    h_caloVertexMom->Fill(caloVertexMom);

  }

  TCanvas *c1 = new TCanvas("c1","c1",800,600);
  h_caloExtrapolatedDistance->Draw("HIST");
  c1->SaveAs(("../Images/"+config+"/h_caloExtrapolatedDistance.png").c_str());

  TCanvas *c2 = new TCanvas("c2","c2",800,600);
  h_decayExtrapolatedDistance->Draw("HIST");
  c2->SaveAs(("../Images/"+config+"/h_decayExtrapolatedDistance.C").c_str());

  TCanvas *c3 = new TCanvas("c3","c3",800,600);
  h_caloVertexMom->Draw("HIST");
  c3->SaveAs(("../Images/"+config+"/h_caloVertexMom.png").c_str());
  return;
}
