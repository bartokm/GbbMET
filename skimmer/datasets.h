#ifndef datasets_h
#define datasets_h

using namespace std;

std::string ggFile[6]={
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_04_14_00/GoldenJSON/job_SinglePho_Run2015C_PR_25ns.root",//data L=16.34
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_06_03_00/data3/ggNtuples/V07_06_03_00/job_SinglePho_Run2015C_Dec16_miniAOD.root", //data L=16.345
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_06_03_00/data3/ggNtuples/V07_06_03_00/job_SinglePho_Run2015D_Dec16_miniAOD.root", //data L=2516.978
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/V07_06_03_00/data6/ggNtuples/V07_06_03_00/job_fall15_gjet_pt15to6000_miniAOD.root", //sigma=? N=?
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/V07_06_03_00/data6/ggNtuples/V07_06_03_00/job_fall15_WJetsToLNu_aMCatNLO_miniAOD.root", //sigma=? N=?
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/V07_06_03_00/job_fall15_Zg_aMCatNLO_miniAOD.root" //sigma=? N=?
}; 

TString skimName[6]={
  "skimtest",
  "job_SinglePho_Run2015C_Dec16_miniAOD",
  "job_SinglePho_Run2015D_Dec16_miniAOD",
  "job_fall15_gjet_pt15to6000_miniAOD",
  "job_fall15_WJetsToLNu_aMCatNLO_miniAOD",
  "job_fall15_Zg_aMCatNLO_miniAOD"
};
#endif
