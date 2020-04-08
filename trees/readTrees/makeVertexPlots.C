{
  // trackReco
  TFile *f1 = TFile::Open("plots_trackReco_15921.root");
  TFile *f2 = TFile::Open("plots_trackReco_15921_noQ.root");
  // trackRecoAndTrackCalo
  TFile *f3 = TFile::Open("plots_trackAndTrackCalo_15921.root");
  TFile *f4 = TFile::Open("plots_trackAndTrackCalo_15921_noQ.root");

  vector<TFile*> files_;

  files_.push_back(f1);
  files_.push_back(f2);
  files_.push_back(f3);
  files_.push_back(f4);
  
  string histNames[6] = {"radialPos","verticalPos","decayVertexMom","zPos_vs_xPos","radialPos_vs_time","verticalPos_vs_time"};

  for(int f = 0; f<files_.size(); f++) {

    cout<<"file\t"<<files_.at(f)<<endl;

    // Now get and draw histograms for each file
    for(int h = 0; h<6; h++) {
      
      if(h<3) {

	TH1 *h1 = (TH1*)files_.at(f)->Get(histNames[h].c_str());
	cout<<"h1\t"<<histNames[h]<<"\t"<<h1<<endl;
	
	TCanvas *c1 = new TCanvas("c1","c1",800,600);
	h1->Draw("HIST");

	if(f==0) c1->SaveAs(("decayVertexImages/trackReco_"+histNames[h]+".png").c_str());
	else if(f==1) c1->SaveAs(("decayVertexImages/trackReco_"+histNames[h]+"_noQ.png").c_str());
	else if(f==2) c1->SaveAs(("decayVertexImages/trackAndTrackCalo_"+histNames[h]+".png").c_str());
	else if(f==3) c1->SaveAs(("decayVertexImages/trackAndTrackCalo_"+histNames[h]+"_noQ.png").c_str());

	delete c1;

      } else {

	TH2 *h2 = (TH2*)files_.at(f)->Get(histNames[h].c_str());
	cout<<"h2\t"<<histNames[h]<<"\t"<<h2<<endl;

	TCanvas *c2 = new TCanvas("c2","c2",800,600);
	h2->Draw("COLZ");

	if(f==0) c2->SaveAs(("decayVertexImages/trackReco_"+histNames[h]+".png").c_str());
	else if(f==1) c2->SaveAs(("decayVertexImages/trackReco_"+histNames[h]+"_noQ.png").c_str());
	else if(f==2) c2->SaveAs(("decayVertexImages/trackAndTrackCalo_"+histNames[h]+".png").c_str());
	else if(f==3) c2->SaveAs(("decayVertexImages/trackAndTrackCalo_"+histNames[h]+"_noQ.png").c_str());

	delete c2;
      }
       
    }



    // close all files
    files_.at(f)->Close();

  }

}
