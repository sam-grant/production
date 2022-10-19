
#include "TFile.h"
#include "TTree.h"

void CompareTrees() { // int argc, char *argv[]) { 

	string subRun = "15921";//argv[1];

	// Load tree 1
    string fileName1 = "/gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_"+subRun+".root";
  	TFile *file1 = TFile::Open(fileName1.c_str(),"READ");
  	TTree *tree1 = (TTree*)file1->Get("trackAndTrackCalo/tree");

  	// Deactivate all the branches which have been modified
  	tree1->SetBranchStatus("decayExtrapolatedDistance",0);
  	tree1->SetBranchStatus("trackClusterExtrapolatedDistance",0);

  	// Now clone them both into new trees and write
  	TFile *newFile1 = new TFile("newTree1.root","RECREATE");
    newFile1->mkdir("trackAndTrackCalo");
    newFile1->cd("trackAndTrackCalo");
    TTree *newTree1 = tree1->CloneTree(0);

    // Fill
    Long64_t nEntries1 = tree1->GetEntries();
    for (Long64_t i_entry=0; i_entry<nEntries1; i_entry++) {
    	newTree1->GetEntry(i_entry);
    	newTree1->Fill();
    }

    newTree1->AutoSave();

  	// Load tree 2
  	string fileName2 = "/gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_"+subRun+"_corrected.root";
  	TFile *file2 = TFile::Open(fileName2.c_str(),"READ");
  	TTree *tree2 = (TTree*)file2->Get("trackAndTrackCalo/tree");

  	// Deactivate all the branches which have been modified
  	tree2->SetBranchStatus("decayExtrapolatedDistance",0);
  	tree2->SetBranchStatus("caloExtrapolatedDistance",0);

    TFile *newFile2 = new TFile("newTree2.root","RECREATE");
    newFile2->mkdir("trackAndTrackCalo");
    newFile2->cd("trackAndTrackCalo");
    TTree *newTree2 = tree2->CloneTree(0);

    // Fill
    Long64_t nEntries2 = tree2->GetEntries();
    for (Long64_t i_entry=0; i_entry<nEntries2; i_entry++) {
    	newTree2->GetEntry(i_entry);
    	newTree2->Fill();
    }
    
    newTree2->AutoSave();

    cout<<"nEntries1\t"<<nEntries1<<endl;
    cout<<"nEntries2\t"<<nEntries2<<endl;

    delete file1; //delete file2;
    delete newFile1; //delete newFile2;

	return;//  0;
}

/*float midasSerialNum;
float runNum;
float subRunNum;
float eventNum;
float islandNum;
float inFillLaserCount;
float passTrackQuality;
float passCandidateQuality;
float passDecayVertexQuality;
float hitVolume;
float hasDecayVertex;
float hasCaloVertex;
float station;
float nHits;
float nUHits;
float missedLayersFrac;
float trackPValue;
float trackT0;
float trackMomentum;
float trackMomentumX;
float trackMomentumY;
float trackMomentumZ;
float decayTime;
float decayVertexPosX;
float decayVertexPosY;
float decayVertexPosZ;
float decayVertexPosR;
float decayVertexMom;
float decayVertexMomX;
float decayVertexMomY;
float decayVertexMomZ;
float decayVertexMomUnc;
float decayVertexUncR;
float decayVertexUncY;
float decayVertexUncPR;
float decayVertexUncPY;
float caloVertexTime;
float caloVertexPosX;
float caloVertexPosY;
float caloVertexPosZ;
float caloVertexPosR;//", caloVertexPosR, b_caloVertexPosR);
float caloVertexMom;//", caloVertexMom, b_caloVertexMom);
float caloVertexMomX", caloVertexMomX, b_caloVertexMomX);
float caloVertexMomY", caloVertexMomY, b_caloVertexMomY);
float caloVertexMomZ", caloVertexMomZ, b_caloVertexMomZ);
float caloVertexMomUnc", caloVertexMomUnc, b_caloVertexMomUnc);
float caloVertexUncX", caloVertexUncX, b_caloVertexUncX);
float caloVertexUncY", caloVertexUncY, b_caloVertexUncY);
float caloVertexUncPX", caloVertexUncPX, b_caloVertexUncPX);
float caloVertexUncPY", caloVertexUncPY, b_caloVertexUncPY);
float minDriftTime", minDriftTime, b_minDriftTime);
float maxDriftTime", maxDriftTime, b_maxDriftTime);
float maxResidual", maxResidual, b_maxResidual);
float decayExtrapolatedDistance", decayExtrapolatedDistance, b_decayExtrapolatedDistance);
float loExtrapolatedDistance", caloExtrapolatedDistance, b_caloExtrapolatedDistance);
float nCluMatches", nCluMatches, b_nCluMatches);

  LoadBranchVector("passCaloVertexQuality", passCaloVertexQuality, b_passCaloVertexQuality);
  LoadBranchVector("passPositronVertexQuality", passPositronVertexQuality, b_passPositronVertexQuality);
  LoadBranchVector("passLostMuonVertexQuality", passLostMuonVertexQuality, b_passLostMuonVertexQuality);
  LoadBranchVector("clusterIslandNum", clusterIslandNum, b_clusterIslandNum);
  LoadBranchVector("clusterFillNum", clusterFillNum, b_clusterFillNum);
  LoadBranchVector("clusterCaloNum", clusterCaloNum, b_clusterCaloNum);
  LoadBranchVector("clusterTime", clusterTime, b_clusterTime);
  LoadBranchVector("clusterX", clusterX, b_clusterX);
  LoadBranchVector("clusterY", clusterY, b_clusterY);
  LoadBranchVector("clusterEnergy", clusterEnergy, b_clusterEnergy);
  LoadBranchVector("uncorrClusterEnergy", uncorrClusterEnergy, b_uncorrClusterEnergy);
  LoadBranchVector("EoverP", EoverP, b_EoverP);
  LoadBranchVector("uncorrEoverP", uncorrEoverP, b_uncorrEoverP);
  LoadBranchVector("logEoverP", logEoverP, b_logEoverP);
  LoadBranchVector("logUncorrEoverP", logUncorrEoverP, b_logUncorrEoverP);
  LoadBranchVector("nXtalHits", nXtalHits, b_nXtalHits);
  LoadBranchVector("xtalWithMaxE", xtalWithMaxE, b_xtalWithMaxE);
  LoadBranchVector("xtalMaxEnergyFrac", xtalMaxEnergyFrac, b_xtalMaxEnergyFrac);
  LoadBranchVector("caloVertexClusterTimeDiff", caloVertexClusterTimeDiff, b_caloVertexClusterTimeDiff);
  LoadBranchVector("caloVertexClusterRadialDiff", caloVertexClusterRadialDiff, b_caloVertexClusterRadialDiff);*/