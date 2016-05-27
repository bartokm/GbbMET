#ifndef datasets_h
#define datasets_h

using namespace std;

std::string ggFile[21]={
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_04_14_00/GoldenJSON/job_SinglePho_Run2015C_PR_25ns.root",//data L=16.34
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_06_03_00/job_SinglePho_Run2015C_Dec16_miniAOD.root", //data L=16.345
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_06_03_00/job_SinglePho_Run2015D_Dec16_miniAOD.root", //data L=2516.978
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/V07_06_03_00/job_fall15_gjet_pt15to6000_miniAOD.root", //sigma=365896
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/V07_06_03_00/job_fall15_WJetsToLNu_aMCatNLO_miniAOD.root", //sigma=61526.7
   "/afs/cern.ch/user/m/mbartok/eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/V07_06_03_00/job_fall15_Zg_aMCatNLO_miniAOD.root", //sigma=117.864
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT200to300_25ns.root", //sigma=1717000
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT300to500_25ns.root", //sigma=351300
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT500to700_25ns.root", //sigma=31630
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT700to1000_25ns.root", //sigma=6802
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT1000to1500_25ns.root", //sigma=1206
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT1500to2000_25ns.root", //sigma=120.4
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT2000toInf_25ns.root", //sigma=25.25
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToNuNu_HT-100To200_25ns.root", //sigma=280.35
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToNuNu_HT-200To400_25ns.root", //sigma=77.67
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToNuNu_HT-400To600_25ns.root", //sigma=10.73
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToNuNu_HT-600ToInf_25ns.root", //sigma=4.116
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_TTGJets_25ns.root", //sigma=3.697
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToQQ_HT600toInf_25ns.root", //sigma=5.67
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_WGJets_MonoPhoton_PtG-130_25ns.root", //sigma=0.834
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_TTJets_25ns.root" //sigma=831.76
}; 

TString skimName[21]={
  "skimtest",
  "job_SinglePho_Run2015C_Dec16_miniAOD",
  "job_SinglePho_Run2015D_Dec16_miniAOD",
  "job_fall15_gjet_pt15to6000_miniAOD",
  "job_fall15_WJetsToLNu_aMCatNLO_miniAOD",
  "job_fall15_Zg_aMCatNLO_miniAOD",
  "job_fall15_QCD_HT200to300_25ns",
  "job_fall15_QCD_HT300to500_25ns",
  "job_fall15_QCD_HT500to700_25ns",
  "job_fall15_QCD_HT700to1000_25ns",
  "job_fall15_QCD_HT1000to1500_25ns",
  "job_fall15_QCD_HT1500to2000_25ns",
  "job_fall15_QCD_HT2000toInf_25ns",
  "job_fall15_ZJetsToNuNu_HT-100To200_25ns",
  "job_fall15_ZJetsToNuNu_HT-200To400_25ns",
  "job_fall15_ZJetsToNuNu_HT-400To600_25ns",
  "job_fall15_ZJetsToNuNu_HT-600ToInf_25ns",
  "job_fall15_TTGJets_25ns",
  "job_fall15_ZJetsToQQ_HT600toInf_25ns",
  "job_fall15_WGJets_MonoPhoton_PtG-130_25ns",
  "job_fall15_TTJets_25ns"
};
#endif
