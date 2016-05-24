#include "PreselectSkim.h"
#include "datasets.h"
#include "TString.h"
#include "TBenchmark.h"

#include <iostream>

void Preselect()
{
  int nS=3; // 0:test, 1,2:data singlephoton, 3:GJets, 4:WJetsToLNu, 5:ZG,7-13:QCD, 14-17:ZJetsToNuNu, 18:TTGJets, 19:ZJetsToQQ, 20:WGJets
  TString fileToSkimName(ggFile[nS]);

  bool isMC=false;
  if (nS>2) isMC= true;
  TString outDir;
  if (isMC) outDir="/afs/cern.ch/work/m/mbartok/public/mc/ggNtuple/skimmed/V07-06-03-00";
  else outDir="/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/skimmed/V07-06-03-00";
  TString nameDir("ggNtuplizer");
  TString nameTree("EventTree");
  TBenchmark time;
  TDatime now;
  now.Print();
  time.Start("time");
  std::cout<<"CPU time = "<<time.GetCpuTime("time")<<", Real time = "<<time.GetRealTime("time")<<std::endl;  

  // //  TString fileToSkimFullName = "/afs/cern.ch/user/n/nfilipov/eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_04_14_00/GoldenJSON/" + fileToSkimName;
  //
  std::cout<<"file "<<fileToSkimName<<std::endl<<" will be skimmed"<<std::endl;

  //  PreselectSkim skimmer(TConfiguration::MUON, TConfiguration::W_GAMMA, TConfiguration::DATA,fileToSkimName);
  PreselectSkim skimmer(fileToSkimName,outDir,nameDir,nameTree,isMC,nS);
  skimmer.LoopOverInputTree(isMC);
  std::cout<<"file "<<fileToSkimName<<std::endl<<" was skimmed"<<std::endl;

  time.Stop("time");
  std::cout<<"CPU time = "<<time.GetCpuTime("time")<<", Real time = "<<time.GetRealTime("time")<<std::endl; 

  std::cout<< "help I'm a rock!"<<std::endl;
                               
}
