{
  string datasets[8] = {"60h", "9d", "HK", "EG", "HK_trim", "EG_trim", "Run1", "Run1_trim"};

  for(int i = 0; i<8; i++) {

    std::cout<<"Dataset\t"<<datasets[i]<<std::endl;

        // trackRecoAndTrackCalo plot
    TFile *f2 = TFile::Open(("../readTrees/readTrackAndTrackCalo/plots/plots_"+datasets[i]+"_lostMuons.root").c_str()); 

    std::cout<<"File 2\t"<<f2<<std::endl;

    vector<TFile*> files_;  

    files_.push_back(f2); 

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


          c1->SaveAs(("images/"+datasets[i]+"/trackAndTrackCalo_"+histNames[h]+"_lostMuons.png").c_str()); 
          c1->SaveAs(("images/"+datasets[i]+"/trackAndTrackCalo_"+histNames[h]+"_lostMuons.pdf").c_str()); 
          c1->SaveAs(("images/"+datasets[i]+"/trackAndTrackCalo_"+histNames[h]+"_lostMuons.C").c_str()); 


         delete c1; 
  

        } else {  

         TH2 *h2 = (TH2*)files_.at(f)->Get(histNames[h].c_str());
         cout<<"h2\t"<<histNames[h]<<"\t"<<h2<<endl;  

         TCanvas *c2 = new TCanvas("c2","c2",800,600);
         h2->Draw("COLZ");  

          c2->SaveAs(("images/"+datasets[i]+"/trackAndTrackCalo_"+histNames[h]+"_lostMuons.png").c_str()); 
          c2->SaveAs(("images/"+datasets[i]+"/trackAndTrackCalo_"+histNames[h]+"_lostMuons.pdf").c_str()); 
          c2->SaveAs(("images/"+datasets[i]+"/trackAndTrackCalo_"+histNames[h]+"_lostMuons.C").c_str()); 


         delete c2;
         // delete h2;
        }
         
      } 

      // close all files
      files_.at(f)->Close();

  }



  }



}
