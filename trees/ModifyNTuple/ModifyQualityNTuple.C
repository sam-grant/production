#include <iostream>

#include "TFile.h"
#include "TTree.h"

using namespace std;

// Takes sub-run number as input
int main(int argc, char *argv[]) { 

	// Get run
    string subRun = argv[1];
    string oldFileName = "/gm2/data/g2be/Production/TrackQualityTrees/run2C/gm2tracker_quality_"+subRun+".root";
    string newFileName = "/gm2/data/g2be/Production/TrackQualityTrees/run2C/trackRecoTrees_quality_"+subRun+"_corrected.root";

    // Load old tree
  	TFile *oldFile = TFile::Open(oldFileName.c_str(),"READ");
    // Choosing just to clone the quality tracks tree
  	TTree *oldTree = (TTree*)oldFile->Get("QualityTracks");
    //cout<<"oldTree\t"<<oldTree<<endl;

    // Deactivate broken branch before cloning
    oldTree->SetBranchStatus("trackClusterExtrapolatedDistance",0);
    
    // Get branches needed from old tree
    float caloExtrapolatedDistance, decayExtrapolatedDistance, decayTime, caloVertexTime, trackT0;
    oldTree->SetBranchAddress("decayExtrapolatedDistance",&decayExtrapolatedDistance);
    oldTree->SetBranchAddress("decayTime",&decayTime);
    oldTree->SetBranchAddress("caloVertexTime",&caloVertexTime);
    oldTree->SetBranchAddress("trackT0",&trackT0);

    // Create new file + clone of old tree in new file
    TFile *newFile = new TFile(newFileName.c_str(),"RECREATE");
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
        decayExtrapolatedDistance = (1/0.00333564095) * (trackT0 - decayTime);
        caloExtrapolatedDistance = (1/0.00333564095) * (caloVertexTime - trackT0);

        newTree->Fill();
    }

    newTree->AutoSave();

    delete oldFile;
    delete newFile;
  
    return 0;

}
