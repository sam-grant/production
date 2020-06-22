//////////////////////////////
// Sam Grant                //
// August 2019              //
// Read tracker branch      //
//////////////////////////////

#define Plotter_C
#include "Plotter.h"
#include "TMath.h"
#include <set>

void Plotter::InitTrees(TString input_file) {
   tr = new trackerReader(input_file);  
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

  std::set<long long> id;

  while( NextTrEvent() ) {

 
    long long run = tr->runNum;
    long long subRun = tr->subRunNum;
    long long event = tr->eventNum;

    id.insert( run*1000000+subRun*1000+event );

  }

  print(id);


  delete tr;
  return;

}
