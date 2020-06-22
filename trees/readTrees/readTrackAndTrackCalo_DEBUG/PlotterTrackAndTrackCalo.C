//////////////////////////////
// Sam Grant                //
// Test branch variables    //
// Read tracker branch      //
//////////////////////////////

#define Plotter_C
#include "Plotter.h"
#include "TMath.h"
#include <set>
void Plotter::InitTrees(TString input_file) {
   ttc = new trackAndTrackCaloReader(input_file);
   //tr = new trackerReader(input_file); 
}

void Plotter::InitHistos() {

}

//=========================================================

//loop over the entries in the tree, making plots:

void print(std::set<long long> const &s)
{
  for (auto const& i: s) {
    std::cout << i << "\n";
  }
}


void Plotter::Run() {
  //    int count = 0;
  //loop over the clusterTracker/tracker tree:

  std::set<long long> id;


  while( NextTrackAndTrackCaloEvent() ) {
    
    long long run = ttc->runNum;
    long long subRun = ttc->subRunNum;
    long long event = ttc->eventNum;

    id.insert( run*1000000+subRun*1000+event );
    //  std::cout<<id<<std::endl;
  }

  print(id);
  //   std::cout<<id.at(0)<<std::endl;

  delete ttc;
  //delete tr;
  return;

}
