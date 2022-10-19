void PartialClone() {

	// Doesn't work either
	
	// Load old tree 
  	TFile *oldFile = TFile::Open("oldTree.root");
  	TTree *oldTree = (TTree*)oldFile->Get("trackAndTrackCalo/tree");
  	TFile *newFile = new TFile("newTree.root","recreate");

  	oldTree->SetBranchAddress("decayExtrapolatedDistance",0);

  	TTree *newTree = oldTree->CloneTree(-1,"fast");

  	delete oldTree; 

  	newTree->Write();

  	delete oldFile; delete newFile;

	return;
}