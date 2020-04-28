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
   //tr = new trackerReader(input_file); 
}

void Plotter::InitHistos() {

  // Radial position resolution at 1.5 GeV is 1 mm

  // Time resolution is around 1 ns
  // Forwards/backwards vertices check (should always be zero)
  // Extrapolation plots
  //plot1D("radialPos",400,-200,200,"Radial position [mm]");
  //plot1D("verticalPos",400,-200,200,"Vertical position [mm]");
  //plot1D("decayVertexMom",128,0,3200,"Decay vertex momentum [MeV]");
  //plot2D("zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  ////plot2D("St12_zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  ////plot2D("St18_zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  //plot2D("radialPos_vs_time",6000,0,900000,500,-250,250,"Decay time [ns]","Radial decay vertex position [mm]");
  //plot2D("verticalPos_vs_time",6000,0,900000,500,-100,100,"Decay time [ns]", "Vertical decay vertex position [mm]");

  // Tracker plots
  plot1D("pValues",1000,0,1,"p-values");
  plot1D("trackT0",6000,0,900000,"Track T0 [ns]");
  plot1D("trackMomentum",128,0,3200,"Track momentum [MeV]");
  plot1D("strawHits",34,-0.5,33.5,"Layers hit");

  // Decay vertex plots
  plot1D("radialPos",400,-200,200,"Radial position [mm]");
  plot1D("verticalPos",400,-200,200,"Vertical position [mm]");
  plot1D("decayVertexMom",128,0,3200,"Decay vertex momentum [MeV]");
  plot2D("zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  //plot2D("St12_zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  //plot2D("St18_zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  plot2D("radialPos_vs_time",6000,0,900000,500,-250,250,"Decay time [ns]","Radial decay vertex position [mm]");
  plot2D("verticalPos_vs_time",6000,0,900000,500,-100,100, "Decay time [ns]", "Vertical decay vertex position [mm]");

  // Momentum compariosn
  plot1D("caloAndDecayVertexMomDiff",1000,-7000,7000,"Calo vertex momentum #minus decay vertex momentum [MeV]");
  plot1D("trackAndDecayVertexMomDiff",1000,-7000,7000,"Track momentum #minus decay vertex momentum [MeV]");
  plot1D("trackAndCaloVertexMomDiff",1000,-7000,7000,"Track momentum #minus calo vertex momentum [MeV]");

  // Factor of 0.148936 removes the fast rotation
  // Calo vertex variables
  // plot1D("caloVertexTime",6000,0,900000, "Calo vertex time [ns]");
  // plot1D("caloVertexMom",6000,0,900000, "Calo vertex time [ns]");

  // Cut params
  plot1D("caloVertexClusterTimeDiff",35,-20,15,"Calo vertex time #minus cluster time [ns]");
  plot1D("caloVertexClusterRadialDiff",100,0,100,"Calo vertex time #minus cluster time [mm]");
  plot1D("logEoverP",140,-5,3,"log(E/p)");
  plot2D("EvsP",128,0,3200,128,0,3200,"Cluster energy [MeV]","Track momentum [MeV]");

  // Cluster matched params
  plot1D("clusterTime",6000,0,900000, "Cluster time [ns]");
  plot1D("clusterEnergy",128,0,3200, "Cluste energy [MeV]");
  plot2D("cluY_vs_cluX",300,-150,150,200,-100,100,"Cluster X [mm]", "Cluster Y [mm]");
  plot2D("caloVertY_vs_caloVertX",300,-150,150,200,-100,100,"Calo vertex postition X [mm]", "Calo vertex position Y [mm]");
  plot2D("EoverP_vs_time",6000,0,900000,100,0,3,"Cluster time [ns]", "E/p");
  plot2D("uncorrEoverP_vs_time",6000,0,900000,100,0,3,"Cluster time [ns]", "E_{uncorr}/p");

  //plot1D("decayVertexTime",4700, 0, 4700*0.148936, "Cluster time [ns]","Decay vertices");
  //plot1D("trackClusterRadialDiff",1000,0,100, ";Calo radial position #minus track vertex radial position [mm]""")
}

//=========================================================

//loop over the entries in the tree, making plots:

void Plotter::Run() {
  //    int count = 0;
  //loop over the clusterTracker/tracker tree:
  while( NextTrackAndTrackCaloEvent() ) {
    
    //if(!ttc->passCaloVertexQuality) continue;
    
    //if(!ttc->passLostMuonVertexQuality) continue;
    //if(!ttc->passDecayVertexQuality) continue;
    if(!ttc->passTrackQuality) continue;
    if(!ttc->hasCaloVertex) continue;
    if(!ttc->hasDecayVertex) continue;

    Fill1D("pValues",ttc->trackPValue);
    Fill1D("trackT0",ttc->trackT0);
    Fill1D("trackMomentum",ttc->trackMomentum);
    Fill1D("strawHits",ttc->nHits);

    Fill1D("radialPos",ttc->decayVertexPosR-7112);
    Fill1D("verticalPos",ttc->decayVertexPosY);
    Fill1D("decayVertexMom",ttc->decayVertexMom);
    Fill2D("zPos_vs_xPos",ttc->decayVertexPosX,ttc->decayVertexPosZ);
    //if(ttc->station == 12) Fill2D("St12_zPos_vs_xPos",ttc->decayVertexPosX,ttc->decayVertexPosZ);
    //else if(ttc->station == 18) Fill2D("St18_zPos_vs_xPos",ttc->decayVertexPosX,ttc->decayVertexPosZ);
    Fill2D("radialPos_vs_time",ttc->decayTime, ttc->decayVertexPosR-7112);
    Fill2D("verticalPos_vs_time",ttc->decayTime,ttc->decayVertexPosY);

    // These should all be zero!
    Fill1D("caloAndDecayVertexMomDiff",ttc->caloVertexMom - ttc->decayVertexMom);
    Fill1D("trackAndDecayVertexMomDiff",ttc->trackMomentum - ttc->decayVertexMom);
    Fill1D("trackAndCaloVertexMomDiff",ttc->trackMomentum - ttc->caloVertexMom);

    // // Cluster matched params
    // plot1D("clusterTime",6000,0,900000, "Cluster time [ns]");
    // plot1D("clusterEnergy",128,0,3200, "Cluste energy [MeV]");
    // plot2D("cluY_vs_cluX",300,-150,150,200,-100,100,"Cluster X [mm]", "Cluster Y [mm]");
    // plot2D("caloVertY_vs_caloVertX",,300,-150,150,200,-100,100,"Calo vertex postition X [mm]", "Calo vertex position Y [mm]");
    // plot2D("EoverP_vs_time",6000,0,900000,100,0,3,"Cluster time [ns]", "E/p");
    // plot2D("uncorrEoverP_vs_time",6000,0,900000,100,0,3,"Cluster time [ns]", "E_{uncorr}/p");

    Fill2D("caloVertY_vs_caloVertX",ttc->caloVertexPosX,ttc->caloVertexPosY);
    
    // Filter out laser fills
    if(ttc->inFillLaserCount!=0) continue;
    // Cluster varaibles are arrays
    for(int i = 0; i<ttc->nCluMatches; i++) { 

      if(!ttc->passPositronVertexQuality[i]) continue;
      //if(!ttc->passLostMuonVertexQuality[i]) continue;
      //if(!ttc->passCaloVertexQuality[i]) continue;

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
  //delete tr;
  return;

}
