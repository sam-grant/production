#include <iostream>

#include "TFile.h"
#include "TTree.h"

using namespace std;

// Takes sub-run number as input
int main(int argc, char *argv[]) { 

	// Get run
    string subRun = argv[1];
    string path = argv[2];

    string oldFileName = path+"/"+subRun+"/gm2tracker_"+subRun+".root";
    string newFileName = "trackRecoTrees_"+subRun+".root";// path+"/trackRecoTrees_"+subRun+".root";

    // Load old tree
  	TFile *oldFile = TFile::Open(oldFileName.c_str(),"READ");
  	TTree *oldTree = (TTree*)oldFile->Get("trackAndTrackCalo/tree");

    // Deactivate broken branch before cloning
    oldTree->SetBranchStatus("trackClusterExtrapolatedDistance",0);

    // Get branches needed from old tree
    float caloExtrapolatedDistance, decayExtrapolatedDistance, decayTime, caloVertexTime, trackT0;
    bool hasDecayVertex;
    oldTree->SetBranchAddress("decayExtrapolatedDistance",&decayExtrapolatedDistance);
    oldTree->SetBranchAddress("decayTime",&decayTime);
    oldTree->SetBranchAddress("caloVertexTime",&caloVertexTime);
    oldTree->SetBranchAddress("trackT0",&trackT0);
    oldTree->SetBranchAddress("hasDecayVertex",&hasDecayVertex);

    // Create new file + clone of old tree in new file
    TFile *newFile = new TFile(newFileName.c_str(),"RECREATE");
    // Copy histograms, just makes an empty directo
    //newFile->mkdir("Extrapolation");
    //newFile->WriteObject( oldFile->GetDirectory("Extrapolation"), "Extrapolation");
    // newFile->Write();

    newFile->mkdir("trackAndTrackCalo");
    newFile->cd("trackAndTrackCalo");
    TTree *newTree = oldTree->CloneTree(0);

    // Set up a new branch
    TBranch *b_caloExtrapolatedDistance = newTree->Branch("caloExtrapolatedDistance",&caloExtrapolatedDistance,"caloExtrapolatedDistance/F");
    newTree->SetBranchAddress("caloExtrapolatedDistance",&caloExtrapolatedDistance);

    // Loop over old tree and make correction, then fill new tree
    Long64_t nEntries = oldTree->GetEntries();

    for (Long64_t i_entry=0; i_entry<nEntries; i_entry++) {

        oldTree->GetEntry(i_entry);
        if(hasDecayVertex) decayExtrapolatedDistance = (1/0.00333564095) * (trackT0 - decayTime);
        caloExtrapolatedDistance = (1/0.00333564095) * (caloVertexTime - trackT0);

        newTree->Fill();
    }

    newTree->AutoSave();
    //newFile->Write();

    delete oldFile;
    delete newFile;
  
    return 0;

}
