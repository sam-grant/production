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


  plot1D("radialPos",400,-200,200,"Radial position [mm]");
  plot1D("verticalPos",400,-200,200,"Vertical position [mm]");
  plot1D("decayVertexMom",128,0,3200,"Decay vertex momentum [MeV]");
  plot2D("zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  //plot2D("St12_zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  //plot2D("St18_zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  plot2D("radialPos_vs_time",6000,0,900000,500,-250,250,"Decay time [ns]","Radial decay vertex position [mm]");
  plot2D("verticalPos_vs_time",6000,0,900000,500,-100,100, "Decay time [ns]", "Vertical decay vertex position [mm]");

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
  //while( NextTrEvent() ) {

    // Track and vertex varaibles are not arrays

//    if(!tr->passVertexQuality) continue;
//
//    double R = sqrt(pow(tr->decayVertexPosX,2)+pow(tr->decayVertexPosY,2)+pow(tr->decayVertexPosZ,2));
//    double p = sqrt(pow(tr->decayVertexMomX,2)+pow(tr->decayVertexMomY,2)+pow(tr->decayVertexMomZ,2));
//    Fill1D("radialPos",R);
//    Fill1D("verticalPos",tr->decayVertexPosY);
//    Fill1D("decayVertexMom",p);
//    Fill2D("zPos_vs_xPos",tr->decayVertexPosX,tr->decayVertexPosZ);
//    if(tr->station == 12) Fill2D("St12_zPos_vs_xPos",tr->decayVertexPosX,tr->decayVertexPosZ);
//    else if(tr->station == 18) Fill2D("St18_zPos_vs_xPos",tr->decayVertexPosX,tr->decayVertexPosZ);
//    Fill2D("radialPos_vs_time",tr->trackT0, R);
//    Fill2D("verticalPos_vs_time",tr->trackT0,tr->decayVertexPosY);

    if(!ttc->hasDecayVertex) continue;
    //if(!ttc->passDecayVertexQuality) continue;
    if(!ttc->passTrackQuality) continue;
    Fill1D("radialPos",ttc->decayVertexPosR-7112);
    Fill1D("verticalPos",ttc->decayVertexPosY);
    Fill1D("decayVertexMom",ttc->decayVertexMom);
    Fill2D("zPos_vs_xPos",ttc->decayVertexPosX,ttc->decayVertexPosZ);
    //if(ttc->station == 12) Fill2D("St12_zPos_vs_xPos",ttc->decayVertexPosX,ttc->decayVertexPosZ);
    //else if(ttc->station == 18) Fill2D("St18_zPos_vs_xPos",ttc->decayVertexPosX,ttc->decayVertexPosZ);
    Fill2D("radialPos_vs_time",ttc->decayTime, ttc->decayVertexPosR-7112);
    Fill2D("verticalPos_vs_time",ttc->decayTime,ttc->decayVertexPosY);
  // Cluster varaibles are arrays
 //   for(int i = 0; i<ttc->nCluMatches; i++) { 
//
// //     
 //   }


  }

  delete ttc;
  //delete tr;
  return;

}
