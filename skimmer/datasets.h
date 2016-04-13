#ifndef datasets_h
#define datasets_h

using namespace std;

std::string ggFile[18]={
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_04_14_00/GoldenJSON/job_SinglePho_Run2015C_PR_25ns.root",//data L=16.34
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_04_14_00/GoldenJSON/job_SinglePho_Run2015C_PR_25ns.root",//data L=16.34
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_04_14_00/GoldenJSON/job_SinglePho_Run2015D_PR_v3_25ns.root",//data L=552.67
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_04_14_00/GoldenJSON/job_SinglePho_Run2015D_PR_v4_25ns.root",//data L=711.21
   //TTJets
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_ggNtuple_TTJets_amcatnlo_pythia8_25ns_miniAOD.root",//sigma=670.3 N=42784971
   //WJetsToLNu
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_ggNtuple_WJetsToLNu_amcatnlo_pythia8_25ns_miniAOD.root", //sigma=60290 N=24184766
   //ZJetsToNuNu
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_ZJetsToNuNu_HT-100To200_13TeV-madgraph.root", //sigma=93.49 N=5154824
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_ZJetsToNuNu_HT-200To400_13TeV-madgraph.root", //sigma=26.12 N=4998316
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_ZJetsToNuNu_HT-400To600_13TeV-madgraph.root", //sigma=3.648 N=1018882
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_ZJetsToNuNu_HT-600ToInf_13TeV-madgraph.root", //sigma=1.401 N=1008333
   //QCD
   //"root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_qcd_HT100To200_25ns.root", //sigma=27500000 N=81906377
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_qcd_HT200To300_25ns.root", //sigma=1740000 N=18718905
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_qcd_HT300To500_25ns.root", //sigma=367000 N=19826197  (das=20278243)
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_qcd_HT500To700_25ns.root", //sigma=29400 N=19664159  (das=44370193)
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_qcd_HT700To1000_25ns.root", //sigma=6524 N=15356448
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_qcd_HT1000To1500_25ns.root", //sigma=1206 N=4963895
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_qcd_HT1500To2000_25ns.root", //sigma=120.04 N=3868886  (das=3962712)
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_qcd_HT2000ToInf_25ns.root", //sigma=25.25 N=1912529  (das=1984407)
   //GJet
   "root://eoscms.cern.ch//eos/cms/store/group/phys_smp/ggNtuples/13TeV/mc/job_spring15_gjet_pt15to6000_25ns.root" //sigma=365896 N=9891424 (das=9896992)

}; 

TString skimName[18]={
  "skimtest",
  "SinglePho_Run2015C_PR_25ns",
  "SinglePho_Run2015D_PR_v3_25ns",
  "SinglePho_Run2015D_PR_v4_25ns",
  "job_spring15_ggNtuple_TTJets_amcatnlo_pythia8_25ns_miniAOD",
  "job_spring15_ggNtuple_WJetsToLNu_amcatnlo_pythia8_25ns_miniAOD",
  "job_spring15_ZJetsToNuNu_HT-100To200_13TeV-madgraph",
  "job_spring15_ZJetsToNuNu_HT-200To400_13TeV-madgraph",
  "job_spring15_ZJetsToNuNu_HT-400To600_13TeV-madgraph",
  "job_spring15_ZJetsToNuNu_HT-600ToInf_13TeV-madgraph",
  //"job_spring15_qcd_HT100To200_25ns",
  "job_spring15_qcd_HT200To300_25ns",
  "job_spring15_qcd_HT300To500_25ns",
  "job_spring15_qcd_HT500To700_25ns",
  "job_spring15_qcd_HT700To1000_25ns",
  "job_spring15_qcd_HT1000To1500_25ns",
  "job_spring15_qcd_HT1500To2000_25ns",
  "job_spring15_qcd_HT2000ToInf_25ns",
  "job_spring15_gjet_pt15to6000_25ns"

};
#endif
