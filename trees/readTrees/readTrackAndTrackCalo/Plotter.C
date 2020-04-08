//////////////////////////////
// Sam Grant                //
// Test branch variables    //
// Read tracker branch      //
//////////////////////////////

#define Plotter_C
#include "Plotter.h"
#include "TMath.h"

void Plotter::InitTrees(TString input_file) {
   ttc = new trackAndTrackCaloReader(input_file);  
}

void Plotter::InitHistos() {

  // Radial position resolution at 1.5 GeV is 1 mm

  // Time resolution is around 1 ns
  // Forwards/backwards vertices check (should always be zero)
  // Extrapolation plots
  plot1D("radialPos",400,-200,200,"Radial position [mm]");
  plot1D("verticalPos",400,-200,200,"Vertical position [mm]");
  plot1D("decayVertexMom",128,0,3200,"Decay vertex momentum [MeV]");
  plot2D("zPos_vs_xPos",750,-6000,6000,750,-6000,6000,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  plot2D("St12_zPos_vs_xPos",750,-6000,6000,750,-6000,6000,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  plot2D("St18_zPos_vs_xPos",750,-6000,6000,750,-6000,6000,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  plot2D("radialPos_vs_time",6000,0,900,500,-250,250,"Radial decay vertex position [mm]", "Track time [#mus]");
  plot2D("verticalPos_vs_time",6000,0,900,500,-100,100,"Vertical decay vertex position [mm]", "Track time [#mus]");

  //plot1D("caloAndDecayVertexMomDiff",1000,-7000,7000,"Calo vertex momentum #minus decay vertex momentum [MeV]");
  //plot1D("trackAndDecayVertexMomDiff",1000,-7000,7000,"Track momentum #minus decay vertex momentum [MeV]");
  //plot1D("trackAndCaloVertexMomDiff",1000,-7000,7000,"Track momentum #minus calo vertex momentum [MeV]");
  // Factor of 0.148936 removes the fast rotation
  //plot1D("clusterTime",4700, 0, 4700*0.148936, "Cluster time [ns]","Matched clusters");
  //plot1D("caloVertexTime",4700, 0, 4700*0.148936, "Cluster time [ns]","Calo vertices");
  //plot1D("decayVertexTime",4700, 0, 4700*0.148936, "Cluster time [ns]","Decay vertices");
  //plot1D("trackClusterRadialDiff",1000,0,100, ";Calo radial position #minus track vertex radial position [mm]""")
}

//=========================================================

//loop over the entries in the tree, making plots:

void Plotter::Run() {
  //    int count = 0;
  //loop over the clusterTracker/tracker tree:
  while( NextTrackAndTrackCaloEvent() ) {

    // Track and vertex varaibles are not arrays

    // These should all be zero!
    Fill1D("caloAndDecayVertexMomDiff",ttc->caloVertexMom - ttc->decayVertexMom);
    Fill1D("trackAndDecayVertexMomDiff",ttc->trackMomentum - ttc->decayVertexMom);
    Fill1D("trackAndCaloVertexMomDiff",ttc->trackMomentum - ttc->caloVertexMom);

    // Cluster varaibles are arrays
    for(int i = 0; i<ttc->nCluMatches; i++) { 

      Fill1D("clusterTime", ttc->clusterTime[i] * 1e-3);
    }


  }

  delete ttc;
  return;

}
