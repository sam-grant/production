// Book and plot histograms from track-calo matched trees

// Base code written by Gavin Hesketh 

// Modified by Sam Grant

#define Plotter_C
#include "Plotter.h"
#include "TMath.h"

void Plotter::InitTrees(TString input_file) {
   ttc = new trackAndTrackCaloReader(input_file);  
}

void Plotter::InitHistos() {

  // Some example histograms

  // Tracker plots
  plot1D("pValues",1000,0,1,"p-values");
  plot1D("trackT0",6000,0,900000,"Track T0 [ns]");
  plot1D("trackMomentum",128,0,3200,"Track momentum [MeV]");
  plot1D("strawHits",34,-0.5,33.5,"Layers hit");
  // Extrapolation plots
  plot1D("radialPos",400,-200,200,"Radial position [mm]");
  plot1D("verticalPos",400,-200,200,"Vertical position [mm]");
  plot1D("decayVertexMom",128,0,3200,"Decay vertex momentum [MeV]");
  plot2D("zPos_vs_xPos",750,-6000,6000,750,-6000,6000,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  plot2D("St12_zPos_vs_xPos",750,-6000,6000,750,-6000,6000,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  plot2D("St18_zPos_vs_xPos",750,-6000,6000,750,-6000,6000,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  plot2D("radialPos_vs_time",6000,0,900,500,-250,250,"Radial decay vertex position [mm]", "Track time [#mus]");
  plot2D("verticalPos_vs_time",6000,0,900,500,-100,100,"Vertical decay vertex position [mm]", "Track time [#mus]");
  // Cut plots
  plot1D("caloVertexClusterTimeDiff",35,-20,15,"Calo vertex time #minus cluster time [ns]");
  plot1D("caloVertexClusterRadialDiff",100,0,100,"Calo vertex time #minus cluster time [mm]");
  plot1D("logEoverP",140,-5,3,"log(E/p)");
  plot2D("EvsP",128,0,3200,128,0,3200,"Cluster energy [MeV]","Track momentum [MeV]");
  // Cluster matched plots
  plot1D("clusterTime",6000,0,900000, "Cluster time [ns]");
  plot1D("clusterEnergy",128,0,3200, "Cluste energy [MeV]");
  plot2D("cluY_vs_cluX",300,-150,150,200,-100,100,"Cluster X [mm]", "Cluster Y [mm]");
  plot2D("EoverP_vs_time",6000,0,900000,100,0,3,"Cluster time [ns]", "E/p");
  plot2D("uncorrEoverP_vs_time",6000,0,900000,100,0,3,"Cluster time [ns]", "E_{uncorr}/p");
}

//=========================================================

//loop over the entries in the tree, making plots:

void Plotter::Run() {

  //loop over the clusterTracker/tracker tree:
  while( NextTrackAndTrackCaloEvent() ) {

    // I recommend always keeping these on
    if(!ttc->hasCaloVertex) continue;
    if(!ttc->hasDecayVertex) continue;

    // Track and decay vertex level quality cuts

    //if(!ttc->passTrackQuality) continue;
    //if(!ttc->passDecayVertexQuality) continue;

    // Tracker plots
    Fill1D("pValues",ttc->trackPValue);
    Fill1D("trackT0",ttc->trackT0);
    Fill1D("trackMomentum",ttc->trackMomentum);
    Fill1D("strawHits",ttc->nHits);

    // Extrapolation plots
    Fill1D("radialPos",ttc->decayVertexPosR-7112);
    Fill1D("verticalPos",ttc->decayVertexPosY);
    Fill1D("decayVertexMom",ttc->decayVertexMom);
    Fill2D("zPos_vs_xPos",ttc->decayVertexPosX,ttc->decayVertexPosZ);
    if(ttc->station == 12) Fill2D("St12_zPos_vs_xPos",ttc->decayVertexPosX,ttc->decayVertexPosZ);
    else if(ttc->station == 18) Fill2D("St18_zPos_vs_xPos",ttc->decayVertexPosX,ttc->decayVertexPosZ);
    Fill2D("radialPos_vs_time",ttc->decayTime, ttc->decayVertexPosR-7112);
    Fill2D("verticalPos_vs_time",ttc->decayTime,ttc->decayVertexPosY);

    // Filter out laser fills (useful for gain studies)
    if(ttc->inFillLaserCount!=0) continue;

    // Cluster and track-calo plots (variables are arrays)
    for(int i = 0; i<ttc->nCluMatches; i++) { 

      //if(!ttc->passCaloVertexQuality[i]) continue;
      //if(!ttc->passPositronVertexQuality[i]) continue;
      //if(!ttc->passLostMuonVertexQuality[i]) continue;

      Fill1D("clusterTime",ttc->clusterTime[i]);
      Fill1D("clusterEnergy",ttc->clusterEnergy[i]);
      Fill2D("cluY_vs_cluX",ttc->clusterX[i],ttc->clusterY[i]);
      Fill2D("EoverP_vs_time",ttc->clusterTime[i],ttc->EoverP[i]);
      Fill2D("uncorrEoverP_vs_time",ttc->clusterTime[i],ttc->uncorrEoverP[i]);
      Fill2D("EvsP",ttc->trackMomentum,ttc->clusterEnergy[i]);
      Fill1D("logEoverP",ttc->logEoverP[i]);
      Fill1D("caloVertexClusterRadialDiff",ttc->caloVertexClusterRadialDiff[i]);
      Fill1D("caloVertexClusterTimeDiff",ttc->caloVertexClusterTimeDiff[i]);

    }


  }

  delete ttc;
  return;

}
