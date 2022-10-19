#include "TFile.h"
#include "TTree.h"

void ModifyNTuple(string inputFile = "/gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_15921.root", string outputFile = "newTree.root") { 

  // Load old tree and set branch addresses
  TFile *oldFile = new TFile(inputFile.c_str(),"READ");
  TTree *oldTree = (TTree*)oldFile->Get("trackAndTrackCalo/tree");
  float decayExtrapolatedDistance, decayTime, caloVertexTime, trackT0;
  float caloExtrapolatedDistance[1000];
  unsigned int nCluMatches;
  oldTree->SetBranchAddress("decayExtrapolatedDistance",&decayExtrapolatedDistance);
  oldTree->SetBranchAddress("decayTime",&decayTime);
  oldTree->SetBranchAddress("caloVertexTime",&caloVertexTime);
  oldTree->SetBranchAddress("trackT0",&trackT0);
  oldTree->SetBranchAddress("trackClusterExtrapolatedDistance",caloExtrapolatedDistance);
  oldTree->SetBranchAddress("nCluMatches",&nCluMatches);

  // Create new file + clone of old tree in new file
  TFile *newFile = new TFile(outputFile.c_str(),"RECREATE");
  newFile->mkdir("trackAndTrackCalo");
  newFile->cd("trackAndTrackCalo");
  TTree *newTree = oldTree->CloneTree(0);

  // Loop over old tree and make correction, then fill new tree
  Long64_t nEntries = oldTree->GetEntries();
  for (Long64_t i_entry=0; i_entry<nEntries; i_entry++) {
    oldTree->GetEntry(i_entry);
    decayExtrapolatedDistance = (1/0.00333564095) * (trackT0 - decayTime);
    for(unsigned int i = 0; i < nCluMatches; i++){
      caloExtrapolatedDistance[i] = (1/0.00333564095) * (caloVertexTime - trackT0);
    }
    newTree->Fill();
  }

  newTree->AutoSave();
  delete oldFile;
  delete newFile;
  
  return;

}
