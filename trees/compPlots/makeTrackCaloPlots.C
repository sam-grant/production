{

  // trackAndTrackCaloAndTrackCalo plot
  TFile *f1 = TFile::Open("../readTrees/readTrackAndTrackCalo/plots_trackAndTrackCalo_track_noQ.root");
  TFile *f2 = TFile::Open("../readTrees/readTrackAndTrackCalo/plots_trackAndTrackCalo_track_caloQ.root");
  TFile *f3 = TFile::Open("../readTrees/readTrackAndTrackCalo/plots_trackAndTrackCalo_track_positronQ.root");
  TFile *f4 = TFile::Open("../readTrees/readTrackAndTrackCalo/plots_trackAndTrackCalo_track_lostMuonQ.root");
  TFile *f5 = TFile::Open("../readTrees/readTrackAndTrackCalo/plots_trackAndTrackCalo_track_noQ_noLaser.root");

  vector<TFile*> files_;

  files_.push_back(f1);
  files_.push_back(f2);
  files_.push_back(f3);
  files_.push_back(f4);
  files_.push_back(f5);

  string histNames[13] = {"caloAndDecayVertexMomDiff","trackAndDecayVertexMomDiff","trackAndCaloVertexMomDiff","clusterTime","clusterEnergy","caloVertexClusterRadialDiff","caloVertexClusterTimeDiff","logEoverP",
                          "caloVertY_vs_caloVertX","cluY_vs_cluX","EoverP_vs_time","uncorrEoverP_vs_time","EvsP"};


  for(int f = 0; f<files_.size(); f++) {

    cout<<"file\t"<<files_.at(f)<<endl;

    // Now get and draw histograms for each file
    for(int h = 0; h<13; h++) {

      
      if(h<8) {

	      TH1 *h1 = (TH1*)files_.at(f)->Get(histNames[h].c_str());
	      cout<<"h1\t"<<histNames[h]<<"\t"<<h1<<endl;
	
        TCanvas *c1 = new TCanvas("c1","c1",800,600);
	      h1->Draw("HIST");

	      if(f==0) {
          c1->SaveAs(("noQ/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c1->SaveAs(("noQ/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        }
	      else if(f==1) {
          c1->SaveAs(("caloQ/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c1->SaveAs(("caloQ/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        }
        else if(f==2) {
          c1->SaveAs(("positronQ/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c1->SaveAs(("positronQ/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        }
        else if(f==3) {
          c1->SaveAs(("lostMuonQ/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c1->SaveAs(("lostMuonQ/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        } else {
          c1->SaveAs(("noQ_noLaser/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c1->SaveAs(("noQ_noLaser/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        }

       	delete c1;
	     //	delete h1;

      } else {

	      TH2 *h2 = (TH2*)files_.at(f)->Get(histNames[h].c_str());
      	cout<<"h2\t"<<histNames[h]<<"\t"<<h2<<endl;

	      TCanvas *c2 = new TCanvas("c2","c2",800,600);
	      h2->Draw("COLZ");

        if(f==0) {
          c2->SaveAs(("noQ/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c2->SaveAs(("noQ/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        }
        else if(f==1) {
          c2->SaveAs(("caloQ/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c2->SaveAs(("caloQ/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        }
        else if(f==2) {
          c2->SaveAs(("positronQ/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c2->SaveAs(("positronQ/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        }
        else if(f==3) {
          c2->SaveAs(("lostMuonQ/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c2->SaveAs(("lostMuonQ/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        } else {
          c2->SaveAs(("noQ_noLaser/trackAndTrackCalo_"+histNames[h]+".png").c_str());
          c2->SaveAs(("noQ_noLaser/trackAndTrackCalo_"+histNames[h]+".C").c_str());
        }
        delete c2;
	//	delete h2;
      }
       
    }

    // close all files
    files_.at(f)->Close();

  }

}
