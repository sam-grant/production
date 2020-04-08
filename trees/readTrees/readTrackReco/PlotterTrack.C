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
//  plot1D("DecayTime", 4700, 0, 4700*0.148936, "Decay time [#mus]","Entries"); 
//  plot2D("DecayX_vs_DecayZ", 1000, -8000, 8000, 1000, -8000, 8000, "Decay time [#mus]", "Radial decay vertex [mm]");
//  plot2D("RadialDecayVertex_vs_DecayTime", 4700, 0, 4700*0.148936, 140, -70, 70, "Decay time [#mus]", "Radial decay vertex [mm]");
//
//  for(int stn = 12; stn<19; stn = stn + 6) {
//    
//    //plot1D("S"+std::to_string(stn)+"_DecayTime", 4700, 0, 4700*0.148936, "Decay time [ns]","Entries"); 
//    plot2D("S"+std::to_string(stn)+"_DecayX_vs_DecayZ", 1000, -8000, 8000, 1000, -8000, 8000, "Decay time [#mus]", "Radial decay vertex [mm]");
//    plot2D("S"+std::to_string(stn)+"_RadialDecayVertex_vs_DecayTime", 4700, 0, 4700*0.148936, 140, -70, 70, "Decay time [#mus]", "Radial decay vertex [mm]");
//  
//  }

  plot1D("radialPos",400,-200,200,"Radial position [mm]");
  plot1D("verticalPos",400,-200,200,"Vertical position [mm]");
  plot1D("decayVertexMom",128,0,3200,"Decay vertex momentum [MeV]");
  plot2D("zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  //plot2D("St12_zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  //plot2D("St18_zPos_vs_xPos",750,-7500,7500,750,-7500,7500,"Decay vertex position X [mm]","Decay vertex position Z [mm]");
  plot2D("radialPos_vs_time",6000,0,900000,500,-250,250,"Decay time [ns]","Radial decay vertex position [mm]");
  plot2D("verticalPos_vs_time",6000,0,900000,500,-100,100, "Decay time [ns]", "Vertical decay vertex position [mm]");


}

//=========================================================

//loop over the entries in the tree, making plots:

void Plotter::Run() {
  //    int count = 0;
  //loop over the clusterTracker/tracker tree:
  while( NextTrEvent() ) {

    //if(!tr->passVertexQuality) continue;
    if(!tr->passTrackQuality) continue;

    double R = sqrt(pow(tr->decayVertexPosX,2)+pow(tr->decayVertexPosZ,2))-7112;
    double p = sqrt(pow(tr->decayVertexMomX,2)+pow(tr->decayVertexMomY,2)+pow(tr->decayVertexMomZ,2));
    Fill1D("radialPos",R);
    Fill1D("verticalPos",tr->decayVertexPosY);
    Fill1D("decayVertexMom",p);
    Fill2D("zPos_vs_xPos",tr->decayVertexPosX,tr->decayVertexPosZ);
   // if(tr->station == 12) Fill2D("St12_zPos_vs_xPos",tr->decayVertexPosX,tr->decayVertexPosZ);
   // else if(tr->station == 18) Fill2D("St18_zPos_vs_xPos",tr->decayVertexPosX,tr->decayVertexPosZ);
    Fill2D("radialPos_vs_time",tr->decayTime, R);
    Fill2D("verticalPos_vs_time",tr->decayTime,tr->decayVertexPosY);

//    if(tr->passVertexQuality == false) continue;
//    
//    int stn = tr->station;
//    //    std::cout<<"Stn : "<<stn<<std::endl;
//    double decayT = (tr->decayT0);// * 1e-3; // ns -> us
//
//    double decayX = tr->decayVertexPosX;
//    double decayZ = tr->decayVertexPosZ;
//    double decayR = sqrt(decayX*decayX+decayZ*decayZ) - 7112; // Set the magic radius to zero
//
//    
//    Fill1D("DecayTime", decayT);
//    Fill2D("DecayX_vs_DecayZ", decayX, decayZ);
//    Fill2D("RadialDecayVertex_vs_DecayTime", decayT, decayR);
//
//
//    //Fill1D("S"+std::to_string(stn)+"_DecayTime", decayT);
//    Fill2D("S"+std::to_string(stn)+"_DecayX_vs_DecayZ",decayX, decayZ);
//    Fill2D("S"+std::to_string(stn)+"_RadialDecayVertex_vs_DecayTime", decayT, decayR);

  
  }

  delete tr;
  return;

}
