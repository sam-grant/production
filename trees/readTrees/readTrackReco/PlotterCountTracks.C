//////////////////////////////
// Sam Grant                //
// August 2019              //
// Read tracker branch      //
//////////////////////////////

#define Plotter_C
#include "Plotter.h"
#include "TMath.h"

void Plotter::InitTrees(TString input_file) {
   tr = new trackerReader(input_file);  
}

void Plotter::InitHistos() {

  // Radial position resolution at 1.5 GeV is 1 mm
  // Time resolution is around 1 ns
  // Factor of 0.148936 removes the fast rotation

  // Tracker plots
  plot1D("pValues_noQ",1000,0,1,"p-values");
  plot1D("trackT0_noQ",6000,0,900000,"Track T0 [ns]");
  plot1D("trackMomentum_noQ",128,0,3200,"Track momentum [MeV]");

  plot1D("pValues_tQ",1000,0,1,"p-values");
  plot1D("trackT0_tQ",6000,0,900000,"Track T0 [ns]");
  plot1D("trackMomentum_tQ",128,0,3200,"Track momentum [MeV]");

  plot1D("pValues_bQ",1000,0,1,"p-values");
  plot1D("trackT0_bQ",6000,0,900000,"Track T0 [ns]");
  plot1D("trackMomentum_bQ",128,0,3200,"Track momentum [MeV]");
}

//=========================================================

//loop over the entries in the tree, making plots:

void Plotter::Run() {
  //    int count = 0;
  //loop over the clusterTracker/tracker tree:
  while( NextTrEvent() ) {

    Fill1D("pValues_noQ",tr->trackPValue);
    Fill1D("trackT0_noQ",tr->trackT0);
    Fill1D("trackMomentum_noQ",tr->trackMomentum);
    
    if(!tr->passTrackQuality) continue;

    Fill1D("pValues_tQ",tr->trackPValue);
    Fill1D("trackT0_tQ",tr->trackT0);
    Fill1D("trackMomentum_tQ",tr->trackMomentum);
    
    if(!tr->passVertexQuality) continue;

    Fill1D("pValues_bQ",tr->trackPValue);
    Fill1D("trackT0_bQ",tr->trackT0);
    Fill1D("trackMomentum_bQ",tr->trackMomentum);
      
  }

  delete tr;
  return;

}
