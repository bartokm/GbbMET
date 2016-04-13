#include "PreselectSkim.h"
#include "datasets.h"
#include "TString.h"
#include "TBenchmark.h"

#include <iostream>

void Preselect()
{
  int nS=9; // 0:test, 1,2,3:singlephoton, 4:TTJets, 5:WJetsToLNu, 6-9:ZJetsToNuNu, 10-16:QCD, 17:GJet
  TString fileToSkimName(ggFile[nS]);

  bool isMC=false;
  if (nS>3) isMC= true;
  TString outDir;
  if (isMC) outDir="/afs/cern.ch/work/m/mbartok/public/mc/ggNtuple/skimmed/";
  else outDir="/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/skimmed/";
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
