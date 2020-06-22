{
	
	// Loop tho' sub runs and make plots of track momentum for debugging

	for(int i = 16113; i < 16235; i++) {

  		TFile *f1 = TFile::Open(("../readTrees/readTrackReco/plots_Run1_"+std::to_string(i)+".root").c_str());
  		TFile *f2 = TFile::Open(("../readTrees/readTrackAndTrackCalo/plots_HK_final_"+std::to_string(i)+".root").c_str());

  		// if(f1!=0) std::cout<<f1<<std::endl;
  		if(f1==0 && f2==0) continue;

  		TH1 *h1 = (TH1*)f1->Get("trackMomentum");
  		TH1 *h2 = (TH1*)f2->Get("trackMomentum");

  		if(h1==0 && h2==0) continue;

      // Print out entries and mean momentum
/*      std::cout<<"\n************** TRACK RECO **************"<<std::endl;*/
      std::cout<<"Entries:\t"<<h1.GetEntries()<<std::endl;
      std::cout<<"Mean momentum:\t"<<h1.GetMean()<<std::endl;
/*      std::cout<<"\n************** TRACK CALO **************"<<std::endl;
      std::cout<<"Entries:\t"<<h2.GetEntries()<<std::endl;       
      std::cout<<"Mean momentum:\t"<<h2.GetMean()<<std::endl;*/

      // MAKE PLOTS
/*  		TCanvas *c1 = new TCanvas("c1","c1",800,600);

  		h1->Draw("HIST");

  		c1->SaveAs(("images/trackMomPlots/trackReco_"+std::to_string(i)+".png").c_str());
  		c1->SaveAs(("images/trackMomPlots/trackReco_"+std::to_string(i)+".C").c_str());

  		TCanvas *c2 = new TCanvas("c1","c1",800,600);

  		h2->Draw("HIST");

  		c2->SaveAs(("images/trackMomPlots/trackCalo_"+std::to_string(i)+".png").c_str());
  		c2->SaveAs(("images/trackMomPlots/trackCalo_"+std::to_string(i)+".C").c_str());
*/
	}


}