void RemoveBranch() {

	TFile *file = TFile::Open("oldTree.root","update");
  	TTree *tree = (TTree*)file->Get("trackAndTrackCalo/tree");

  	TBranch *b_trackClusterExtrapolatedDistance =tree->GetBranch("trackClusterExtrapolatedDistance");
    tree->GetListOfBranches()->Remove(b_trackClusterExtrapolatedDistance);
    TLeaf* l_trackClusterExtrapolatedDistance = tree->GetLeaf("trackClusterExtrapolatedDistance");
 	tree->GetListOfLeaves()->Remove(l_trackClusterExtrapolatedDistance);

    cout<<"Removed branch for trackClusterExtrapolatedDistance\t"<<b_trackClusterExtrapolatedDistance<<endl;
    cout<<"Removed leaf for trackClusterExtrapolatedDistance\t"<<l_trackClusterExtrapolatedDistance<<endl;
    // Seg fault here!!!! 
    // I think we need to remove this branch or else the old info will carry over 
    TBranch *b_decayExtrapolatedDistance = tree->GetBranch("decayExtrapolatedDistance");
    tree->GetListOfBranches()->Remove(b_decayExtrapolatedDistance);
    TLeaf* l_decayExtrapolatedDistance = tree->GetLeaf("decayExtrapolatedDistance");
 	tree->GetListOfLeaves()->Remove(l_decayExtrapolatedDistance);

    cout<<"Removed branch for decayExtrapolatedDistance\t"<<b_decayExtrapolatedDistance<<endl;
    cout<<"Removed leaf for decayExtrapolatedDistance\t"<<l_decayExtrapolatedDistance<<endl;

    tree->Write("",TObject::kOverwrite);
    //file->Write("",TObject::kOverwrite);

    //delete tree; delete file;

	return;
}