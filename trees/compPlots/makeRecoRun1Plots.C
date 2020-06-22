{

  // trackReco plot
  TFile *f1 = TFile::Open("../readTrees/readTrackReco/plots/plots_Run1.root");

  std::cout<<f1<<std::endl;
  vector<TFile*> files_;

  files_.push_back(f1);

string histNames[9] = {"pValues_noQ","trackT0_noQ","trackMomentum_noQ","pValues_tQ","trackT0_tQ","trackMomentum_tQ","pValues_bQ","trackT0_bQ","trackMomentum_bQ"};

  for(int f = 0; f<files_.size(); f++) {

    cout<<"file\t"<<files_.at(f)<<endl;

    // Now get and draw histograms for each file
    for(int h = 0; h<9; h++) {
     

      TH1 *h1 = (TH1*)files_.at(f)->Get(histNames[h].c_str());
      
      cout<<"h1\t"<<histNames[h]<<"\t"<<h1<<endl;
      cout<<"tracks:\n"<<h1->GetEntries()<<endl;
	
      TCanvas *c1 = new TCanvas("c1","c1",800,600);
      h1->Draw("HIST");

      c1->SaveAs(("images/Run1/trackReco_"+histNames[h]+".png").c_str());
      c1->SaveAs(("images/Run1/trackReco_"+histNames[h]+".C").c_str());

      delete c1;

    }

    // close all files
    files_.at(f)->Close();

  }

}
