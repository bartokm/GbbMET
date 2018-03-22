#define Analyzer_cxx
#include "Analyzer.h"
#include "whichGridpoint.h"
#include "SignalScanHistograms.h"
#include "cross_sections.h"
#include <TH2.h>
#include <TH3.h>
#include <THn.h>
#include <TStyle.h>
#include <TCanvas.h>

int main(int argc, char* argv[]){
  bool is_i=0, is_o=0, is_b=0, is_p=0, is_f=0, is_F=0, is_h=0, is_c=0, is_cuts=0, is_quiet=0, is_signalscan=0, is_signalstudy=0, is_countSignal=0;
  bool is_t=0;
  bool inputs=0, cuts=0;
  int FR=0, tr=0;
  string output, bname, pname;
  vector<string> inputfiles, v_cuts, cut_variable, cut_operator;
  vector<double> cut_value;
  for(int i=1; i<argc; i++) {
    std::string arg = argv[i];
    // Check existence of an option
    if (arg[0]=='-' && arg.size()==2) {
      is_i=0; is_cuts=0;
      if (arg[1]=='i') is_i=1;
      else if (arg[1]=='o') is_o=1;
      else if (arg[1]=='b') is_b=1;
      else if (arg[1]=='p') is_p=1;
      else if (arg[1]=='f') is_f=1;
      else if (arg[1]=='F') is_F=1;
      else if (arg[1]=='h') is_h=1; 
      else if (arg[1]=='c') is_c=1; 
      else if (arg[1]=='q') is_quiet=1; 
      else if (arg[1]=='S') is_signalscan=1; 
      else if (arg[1]=='s') is_signalstudy=1;
      else if (arg[1]=='c') is_c=1; 
      else if (arg[1]=='C') is_countSignal=1; 
      else if (arg[1]=='t') is_t=1; 
      else {cout<<"ERROR! Unknown option '-"<<arg[1]<<"' Exiting..."<<std::endl; return 0;}
    }
    else if (arg=="--cuts") {is_i=0;is_cuts=1;}
    //Print out help
    if (is_h) {PrintHelp();return 1;}
    //Print out cuts
    if (is_c) {PrintCuts();return 1;}
    // Check second argument after option
    if (inputs && is_i) inputfiles.push_back(arg);
    if (is_o) {output=argv[i+1]; is_o=0;}
    if (is_b) {bname=argv[i+1]; is_b=0;}
    if (is_p) {pname=argv[i+1]; is_p=0;}
    if (is_F) {FR=atoi(argv[i+1]); is_F=0;}
    if (is_t) {(atoi(argv[i+1])==0) ? tr=1000 : tr=atoi(argv[i+1]); is_t=0;}
    if (cuts && is_cuts) v_cuts.push_back(arg);
    if (is_i) inputs=1;
    if (is_cuts) cuts=1;
  }
  //Fill cut variables
  if (v_cuts.size()%3 != 0) {cout<<"Wrong number of --cuts input! Exiting..."<<endl; return 0;}
  else {
    for (unsigned int i=0;i<v_cuts.size();i++) {
      if ((i+1)%3 ==1) cut_variable.push_back(v_cuts[i]);
      if ((i+1)%3 ==2) cut_operator.push_back(v_cuts[i]);
      if ((i+1)%3 ==0) cut_value.push_back(stof(v_cuts[i]));
    }
  }
  //Check if input cuts exist in the code
  if (!CompareCuts(cut_variable)) return 0;

  if (!is_quiet){
    if (!output.empty()) cout<<"Output name: "<<output<<endl;
    if (!bname.empty()) cout<<"Btag file name: "<<bname<<endl;
    if (!pname.empty()) cout<<"Data PileUp file name: "<<pname<<endl;
    if (is_f) cout<<"FastSim is true!"<<endl;
    if (tr) cout<<"This is a test run on "<<tr<<" events!"<<endl;
    if (is_signalscan) cout<<"SignalScan is true!"<<endl;
    if (is_signalstudy) cout<<"Signal study histograms will be filled! (works only on MC...)"<<endl;
    if (is_countSignal) cout<<"Signal Count is ON, only works on T5qqqqHg sample."<<endl;
    if (FR) cout<<"EGamma Fake Rate is true!"<<" FR="<<FR<<endl;
    if (inputfiles.size()) cout<<"Running on the following inputfiles:"<<endl;
    for (unsigned int i=0;i<inputfiles.size();i++) {std::cout<<inputfiles[i]<<std::endl; if (i==30) {cout<<"...More files..."<<endl;break;}}
    if (!cut_variable.size()) cout<<"No cuts are set, running on hardcoded cuts."<<endl;
    for (unsigned int i=0;i<cut_variable.size();i++) {
      if (!i) cout<<"Following cuts are set:"<<endl;
      string op=cut_operator[i];
      cout<<cut_variable[i]<<" ";
      if      (op == "eq") cout<<" == "; 
      else if (op == "Neq") cout<<" != "; 
      else if (op == "less") cout<<" < "; 
      else if (op == "great") cout<<" > "; 
      else if (op == "lesseq") cout<<" <= "; 
      else if (op == "greateq") cout<<" >= "; 
      else if (op == "and") cout<<" & "; 
      else if (op == "or") cout<<" | "; 
      else if (op == "xor") cout<<" ^ ";
      else {cout<<"ERROR! Unknown operator type: "<<op<<" Exiting..."<<endl; return 0;}
      cout<<cut_value[i]<<endl;
    }
  }
  Analyzer t(inputfiles,output,bname,pname,is_f,FR,cut_variable,cut_operator,cut_value,is_quiet,is_signalscan,is_signalstudy,is_countSignal, tr);
  t.Loop();
  return 1;
}

void Analyzer::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Analyzer.C
//      root> Analyzer t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;
   //Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nentries = 0;
   if (!_testRun) nentries = fChain->GetEntries();
   else nentries = _testRun;

   //Long64_t nbytes = 0, nb = 0; //not used
   //Luminosity of data in [pb]
   //double L_data=2689.38644;
   //double L_data=4353.449;
   double L_data=35867.06;
   
   //Btag SF
   BTCalibration calib, calib_fs, calib_deep, calib_deep_fs;;
   BTCalibrationReader reader_L, reader_M, reader_T, reader_L_fs, reader_M_fs, reader_T_fs;
   BTCalibrationReader reader_deep_L, reader_deep_M, reader_deep_T, reader_deep_L_fs, reader_deep_M_fs, reader_deep_T_fs;
   // setup calibration + reader https://twiki.cern.ch/twiki/bin/view/CMS/BTagCalibration#Standalone
   if (btag_file.size()>0){
     calib = *new BTCalibration("csvv1", "input/CSVv2_Moriond17_B_H.csv");
     reader_L = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_M = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_T = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_L.load(calib,BTEntry::FLAV_B,"comb");
     reader_L.load(calib,BTEntry::FLAV_C,"comb");
     reader_L.load(calib,BTEntry::FLAV_UDSG,"incl");
     reader_M.load(calib,BTEntry::FLAV_B,"comb");
     reader_M.load(calib,BTEntry::FLAV_C,"comb");
     reader_M.load(calib,BTEntry::FLAV_UDSG,"incl");
     reader_T.load(calib,BTEntry::FLAV_B,"comb");
     reader_T.load(calib,BTEntry::FLAV_C,"comb");
     reader_T.load(calib,BTEntry::FLAV_UDSG,"incl");
     
     //fastsim
     calib_fs = *new BTCalibration("csvv1_fs", "input/fastsim_v2.csv");
     reader_L_fs = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_M_fs = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_T_fs = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_L_fs.load(calib_fs,BTEntry::FLAV_B,"fastsim");
     reader_L_fs.load(calib_fs,BTEntry::FLAV_C,"fastsim");
     reader_L_fs.load(calib_fs,BTEntry::FLAV_UDSG,"fastsim");
     reader_M_fs.load(calib_fs,BTEntry::FLAV_B,"fastsim");
     reader_M_fs.load(calib_fs,BTEntry::FLAV_C,"fastsim");
     reader_M_fs.load(calib_fs,BTEntry::FLAV_UDSG,"fastsim");
     reader_T_fs.load(calib_fs,BTEntry::FLAV_B,"fastsim");
     reader_T_fs.load(calib_fs,BTEntry::FLAV_C,"fastsim");
     reader_T_fs.load(calib_fs,BTEntry::FLAV_UDSG,"fastsim");
    
     //DeepCSV
     calib_deep = *new BTCalibration("deepcsv", "input/DeepCSV_Moriond17_B_H.csv");
     reader_deep_L = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_deep_M = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_deep_T = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_deep_L.load(calib_deep,BTEntry::FLAV_B,"comb");
     reader_deep_L.load(calib_deep,BTEntry::FLAV_C,"comb");
     reader_deep_L.load(calib_deep,BTEntry::FLAV_UDSG,"incl");
     reader_deep_M.load(calib_deep,BTEntry::FLAV_B,"comb");
     reader_deep_M.load(calib_deep,BTEntry::FLAV_C,"comb");
     reader_deep_M.load(calib_deep,BTEntry::FLAV_UDSG,"incl");
     reader_deep_T.load(calib_deep,BTEntry::FLAV_B,"comb");
     reader_deep_T.load(calib_deep,BTEntry::FLAV_C,"comb");
     reader_deep_T.load(calib_deep,BTEntry::FLAV_UDSG,"incl");
     
     //fastsim
     calib_deep_fs = *new BTCalibration("deepcsv_fs", "input/fastsim_deepcsv_ttbar_26_1_2017.csv");
     reader_deep_L_fs = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_deep_M_fs = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_deep_T_fs = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_deep_L_fs.load(calib_deep_fs,BTEntry::FLAV_B,"fastsim");
     reader_deep_L_fs.load(calib_deep_fs,BTEntry::FLAV_C,"fastsim");
     reader_deep_L_fs.load(calib_deep_fs,BTEntry::FLAV_UDSG,"fastsim");
     reader_deep_M_fs.load(calib_deep_fs,BTEntry::FLAV_B,"fastsim");
     reader_deep_M_fs.load(calib_deep_fs,BTEntry::FLAV_C,"fastsim");
     reader_deep_M_fs.load(calib_deep_fs,BTEntry::FLAV_UDSG,"fastsim");
     reader_deep_T_fs.load(calib_deep_fs,BTEntry::FLAV_B,"fastsim");
     reader_deep_T_fs.load(calib_deep_fs,BTEntry::FLAV_C,"fastsim");
     reader_deep_T_fs.load(calib_deep_fs,BTEntry::FLAV_UDSG,"fastsim");
   }

   //pu reweight
   //TFile f_dataPU("/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/PILEUP/2016DPileUp_FINALCert_forggNtuple.root","read");
   if (pu_file=="default"){
     pu_file="input/Full2016PileUp_ReReco_FINALCert_forggNtuple.root";
   }
   TFile f_dataPU(pu_file.c_str(),"read");
   TH1D *h_dataPU = (TH1D*)f_dataPU.Get("pileup");
   h_dataPU->Scale(1/(h_dataPU->Integral()));
   h_dataPU->SetDirectory(0);
   f_dataPU.Close();

   std::string temp_fname="histos/Analyzer_histos"; 
   if (signalstudy) temp_fname+="_truth";
   if (output_file != "default") temp_fname+="_"+output_file;
   else temp_fname+=".root";
   TFile *f = new TFile(temp_fname.c_str(),"recreate");
   
   TH1::SetDefaultSumw2();
   
   h_cuts = new TH1D("h_cuts","cuts;HLT,PhoID,PhoEt,eleVeto,muVeto,nJet,MT,ST,MET,btag",15,0,15);
   TH1D *h_eff    = new TH1D("h_eff","Events;Before cuts, After cuts",2,-0.5,1.5);
   TH1D *h_nVtx    = new TH1D("h_nVtx",";# of vertices",70,-0.5,69.5);
   TH1D *h_nGoodVtx    = new TH1D("h_nGoodVtx",";# of good vertices",70,-0.5,69.5);
   TH1D *h_nPU    = new TH1D("h_nPU",";# of PileUp",70,-0.5,69.5);

   TH1D *h_phoEtL    = new TH1D("h_phoEtL",";CalibE_{T}^{#gamma_L} [GeV]",10,25,1525);
   TH1D *h_phoEtM    = new TH1D("h_phoEtM",";CalibE_{T}^{#gamma_M} [GeV]",10,25,1525);
   TH1D *h_phoEtT    = new TH1D("h_phoEtT",";CalibE_{T}^{#gamma_T} [GeV]",10,25,1525);
   TH1D *h_phoSCEtaL    = new TH1D("h_phoSCEtaL",";#eta^{#gamma_{L}}",30,-3,3);
   TH1D *h_phoSCEtaM    = new TH1D("h_phoSCEtaM",";#eta^{#gamma_{M}}",30,-3,3);
   TH1D *h_phoSCEtaT    = new TH1D("h_phoSCEtaT",";#eta^{#gamma_{T}}",30,-3,3);
   const int nbins_pfMET=10;
   double xbins_pfMET[nbins_pfMET+1]={0,20,40,70,100,150,200,300,500,700,1000};
   TH1D *h_pfMET    = new TH1D("h_pfMET",";#slash{E}_{T} [GeV]",nbins_pfMET,xbins_pfMET);
   TH1D *h_pfMETsumEt    = new TH1D("h_pfMETsumEt",";#slash{E}_{T} sumEt",20,-50,5000);
   TH1D *h_pfMETPhi    = new TH1D("h_pfMETPhi",";#Phi^{#slash{E}_{T}}",20,-4,4);
   TH1D *h_pfMETSig    = new TH1D("h_pfMETSig",";#slash{E}_{T}Sig",50,0,2000);
   TH2D *h_MET_AK8btag    = new TH2D("h_MET_AK8btag","MET vs selected AK8btag;pfMET;BDSV",30,5,980,30,-1,1);
   TH2D *h_MET_AK4btag    = new TH2D("h_MET_AK4btag","MET vs selected AK4btag1+AK4btag2;pfMET;CSV_{bjet1}+CSV_{bjet2}",30,5,980,30,0,2);
   const int nbins_ST=7;
   double xbins_ST[nbins_ST+1]={0, 200, 400, 600, 800, 1000, 1500, 2000};
   TH1D *h_ST    = new TH1D("h_ST",";S_{T} [GeV]",nbins_ST,xbins_ST);
   TH1D *h_ST_G    = new TH1D("h_ST_G",";S_{T}^{#gamma} [GeV]",10,0,2000);
   const int nbins_MT=9;
   double xbins_MT[nbins_MT+1]={0, 30, 60, 100, 130, 200, 500, 1000, 1500, 2000};
   TH1D *h_MT    = new TH1D("h_MT",";M_{T} [GeV]",nbins_MT,xbins_MT);
   TH1D *h_nPho    = new TH1D("h_nPho",";# of #gamma",10,-0.5,9.5);
   TH1D *h_nEle    = new TH1D("h_nEle",";# of e_{loose}",10,-0.5,9.5);
   TH1D *h_nEleM    = new TH1D("h_nEleM",";# of e_{medium}",10,-0.5,9.5);
   TH1D *h_nEleT    = new TH1D("h_nEleT",";# of e_{tight}",10,-0.5,9.5);
   TH1D *h_nMu    = new TH1D("h_nMu",";# of #mu_{loose}",10,-0.5,9.5);
   TH1D *h_nMuM    = new TH1D("h_nMuM",";# of #mu_{medium}",10,-0.5,9.5);
   TH1D *h_nMuT    = new TH1D("h_nMuT",";# of #mu_{tight}",10,-0.5,9.5);
   TH1D *h_nTau    = new TH1D("h_nTau",";# of #tau_{loose}",10,-0.5,9.5);
   TH1D *h_nIso    = new TH1D("h_nIso",";# of IsoTracks",10,-0.5,9.5);

   TH1D *h_njets    = new TH1D("h_njets",";# of jets",15,-0.5,14.5);
   TH1D *h_jetpt    = new TH1D("h_jetpt","Leading jetpt;p_{T}^{Leading jet} [GeV]",10,30,2030);
   TH1D *h_nAK8jets    = new TH1D("h_nAK8jets",";# of AK8jets",15,-0.5,14.5);
   TH1D *h_AK8jetpt    = new TH1D("h_AK8jetpt","Leading AK8jetpt;p_{T}^{Leading AK8jet} [GeV]",10,30,2030);
   TH1D *h_AK8bjetpt    = new TH1D("h_AK8bjetpt","Btagged AK8jetpt;p_{T}^{btagged AK8jet} [GeV]",10,100,2100);
   TH1D *h_AK8bhjetpt    = new TH1D("h_AK8bhjetpt","Btagged,Higgs-mass AK8jetpt;p_{T}^{Higgs btagged AK8jet} [GeV]",10,100,2100);
   TH1D *h_AK8ljetmass    = new TH1D("h_AK8ljetmass","Leading AK8jetmass;m_{AK8leading jet} [GeV]",10,5,655);
   TH1D *h_AK8jetmass    = new TH1D("h_AK8jetmass","AK8jetmass;m_{AK8jets} [GeV]",10,5,655);
   TH1D *h_AK8bjetmass    = new TH1D("h_AK8bjetmass","Btagged AK8jetmass;m_{btagged AK8jets} [GeV]",10,5,655);
   TH1D *h_AK8bhjetmass    = new TH1D("h_AK8bhjetmass","Btagged, Higgs-mass AK8jetmass;m_{Higgs btagged AK8jets} [GeV]",10,5,655);
   TH1D *h_AK8bPrunedjetmass    = new TH1D("h_AK8bPrunedjetmass","Btagged AK8Prunedjetmass;Pruned m_{btagged AK8jets} [GeV]",10,5,655);
   TH1D *h_AK8bhPrunedjetmass    = new TH1D("h_AK8bhPrunedjetmass","Btagged, Higgs-mass AK8Prunedjetmass;Pruned m_{Higgs btagged AK8jets} [GeV]",10,5,655);
   TH1D *h_AK8bhPrunedCorrjetmass    = new TH1D("h_AK8bhPrunedCorrjetmass","Btagged, Higgs-mass AK8PrunedCorrjetmass;PrunedCorr m_{Higgs btagged AK8jets} [GeV]",10,5,655);
   TH1D *h_AK8PrunedCorrjetmass    = new TH1D("h_AK8PrunedCorrjetmass","Highest btagged AK8jetmess;PrunedCorr m_{AK8jets} [GeV]",20,5,655);
   TH1D *h_AK8SoftDropCorrjetmass    = new TH1D("h_AK8SoftDropCorrjetmass","Highest btagged AK8jetmess;SoftDropCorr m_{AK8jets} [GeV]",20,5,655);
   TH1D *h_AK8PUPPISDjetmass    = new TH1D("h_AK8PUPPISDjetmass","Highest btagged AK8jetmess;PUPPISD m_{AK8jets} [GeV]",20,5,655);
   TH1D *h_AK8tau1    = new TH1D("h_AK8tau1",";#tau_{1}^{AK8Jet}",10,0,1);
   TH1D *h_AK8tau2    = new TH1D("h_AK8tau2",";#tau_{2}^{AK8Jet}",10,0,1);
   TH1D *h_AK8tau3    = new TH1D("h_AK8tau3",";#tau_{3}^{AK8Jet}",10,0,1);
   TH1D *h_AK8tau2_tau1    = new TH1D("h_AK8tau2_tau1",";AK8Jet_tau2/tau1",10,0,1);
   TH1D *h_AK8tau3_tau2    = new TH1D("h_AK8tau3_tau2",";AK8Jet_tau3/tau2",10,0,1);
   TH1D *h_AK8puppitau1    = new TH1D("h_AK8puppitau1",";puppi#tau_{1}^{AK8Jet}",10,0,1);
   TH1D *h_AK8puppitau2    = new TH1D("h_AK8puppitau2",";puppi#tau_{2}^{AK8Jet}",10,0,1);
   TH1D *h_AK8puppitau3    = new TH1D("h_AK8puppitau3",";puppi#tau_{3}^{AK8Jet}",10,0,1);
   TH1D *h_AK8puppitau2_tau1    = new TH1D("h_AK8puppitau2_tau1",";AK8Jetpuppi_tau2/tau1",10,0,1);
   TH1D *h_AK8puppitau3_tau2    = new TH1D("h_AK8puppitau3_tau2",";AK8Jetpuppi_tau3/tau2",10,0,1);
   
   TH1D *h_CSVbjetsL    = new TH1D("h_CSVbjetsL",";# of CSVLoosebjets",10,-0.5,9.5);
   TH1D *h_CSVbjetsM    = new TH1D("h_CSVbjetsM",";# of CSVMediumbjets",10,-0.5,9.5);
   TH1D *h_CSVbjetsT    = new TH1D("h_CSVbjetsT",";# of CSVTightbjets",10,-0.5,9.5);
   TH1D *h_cMVAbjetsL    = new TH1D("h_cMVAbjetsL",";# of cMVALoosebjets",10,-0.5,9.5);
   TH1D *h_cMVAbjetsM    = new TH1D("h_cMVAbjetsM",";# of cMVAMediumbjets",10,-0.5,9.5);
   TH1D *h_cMVAbjetsT    = new TH1D("h_cMVAbjetsT",";# of cMVATightbjets",10,-0.5,9.5);
   TH1D *h_BDSVbjetsL    = new TH1D("h_BDSVbjetsL",";# of BDSVLoosebjets",10,-0.5,9.5);
   TH1D *h_BDSVbjetsM    = new TH1D("h_BDSVbjetsM",";# of BDSVMediumbjets",10,-0.5,9.5);
   TH1D *h_BDSVbjetsT    = new TH1D("h_BDSVbjetsT",";# of BDSVTightbjets",10,-0.5,9.5);
    
   TH1D *h_dRphoAK8jet= new TH1D("h_dRphoAK8jet","Distance between leading photon and leading AK8jet;dR",20,0,8);
   
   TH1D *h_doubleB = new TH1D("h_doubleB","Highest jetPt;BoostedDoubleSVTagger",10,-1,1);
   TH1D *h_doubleB_highdB = new TH1D("h_doubleB_highdB","Highest Boosted;BoostedDoubleSVTagger",10,-1,1);
   TH1D *h_doubleB_highdB_hmass= new TH1D("h_doubleB_highdB_hmass","Highest Boosted with Hmass;BoostedDoubleSVTagger",10,-1,1);
   TH1D *h_bjetCSV= new TH1D("h_bjetCSV","Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags",10,0,1);
   TH1D *h_bjetCSV2= new TH1D("h_bjetCSV2","2nd Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags",10,0,1);
   TH1D *h_b1pb2CSV= new TH1D("h_b1pb2CSV","Highest bjet CSVs;CSV_{bjet1}+CSV_{bjet2}",20,0,2);
   TH1D *h_b1tb2CSV= new TH1D("h_b1tb2CSV","Highest bjet CSVs;CSV_{bjet1}*CSV_{bjet2}",20,0,1);
   TH2D *h_b1b2CSV= new TH2D("h_b1b2CSV","Highest bjet CSVs;CSV_{bjet1};CSV_{bjet2}",20,0,1,30,0,1);
   TH1D *h_selectbjetCSV= new TH1D("h_selectbjetCSV","Selected jet CSV;CombinedInclusiveSecondaryVertexV2BJetTags",10,0,1);
   TH1D *h_selectbjetCSV2= new TH1D("h_selectbjetCSV2","Selected2 jet CSV;CombinedInclusiveSecondaryVertexV2BJetTags",10,0,1);
   TH1D *h_bjetcMVA = new TH1D("h_bjetcMVA","Highest cMVA;CombinedMVAV2BJetTags",10,-1,1);
   TH1D *h_bjetcMVA2 = new TH1D("h_bjetcMVA2","2nd Highest cMVA;CombinedMVAV2BJetTags",10,-1,1);

   TH1D *h_selectAK8bjetpt    = new TH1D("h_selectAK8bjetpt","Selected AK8 jet pt;pt[GeV]",10,100,2100);
   TH1D *h_selectbjetpt    = new TH1D("h_selectbjetpt","Selected jet pt1;pt[GeV]",10,30,2030);
   TH1D *h_selectbjetpt2    = new TH1D("h_selectbjetpt2","Selected jet pt2;pt[GeV]",10,30,2030);
  
   TH1D *h_HT_before = new TH1D("h_HT_before","HT before cuts;HT",10,0,3500);
   TH1D *h_EMHT_before = new TH1D("h_EMHT_before","EMHT before cuts;EMHT",10,0,3500);
   TH1D *h_HT_after = new TH1D("h_HT_after","HT after cuts;HT",10,0,3500);
   TH1D *h_EMHT_after = new TH1D("h_EMHT_after","EMHT after cuts;EMHT",10,0,3500);

   TH1D *h_AK8HT_before = new TH1D("h_AK8HT_before","AK8HT before cuts;HT",10,0,3500);
   TH1D *h_AK8EMHT_before = new TH1D("h_AK8EMHT_before","AK8EMHT before cuts;EMHT",10,0,3500);
   TH1D *h_AK8HT_after = new TH1D("h_AK8HT_after","AK8HT after cuts;HT",10,0,3500);
   TH1D *h_AK8EMHT_after = new TH1D("h_AK8EMHT_after","AK8EMHT after cuts;EMHT",10,0,3500);
  
   TH1D *h_AK8PrunedCorrjetmass_select    = new TH1D("h_AK8PrunedCorrjetmass_select","Selected AK8PrunedCorrjetmass;PrunedCorr m_{Higgs btagged AK8jets} [GeV]",10,18,278);
   TH1D *h_AK8PrunedCorrjetmass_withABCD    = new TH1D("h_AK8PrunedCorrjetmass_select_withABCD","Highest btagged AK8PrunedCorrjetmass in Higgs mass range;PrunedCorr m_{highest btag AK8jets} [GeV]",10,18,278);
   TH2D *h_AK8mass_vs_pt    = new TH2D("h_AK8mass_vs_pt","Highest btagged AK8PrunedCorrjetmass in Higgs mass range vs its pt;PrunedCorr m_{highest btag AK8jets} [GeV];p_{T}^{highest btag AK8jets} [GeV]",20,18,278,50,0,1500);
   TH2D *h_AK8mass_all_vs_pt    = new TH2D("h_AK8mass_all_vs_pt","All AK8PrunedCorrjetmass in Higgs mass range vs its pt;PrunedCorr m_{highest btag AK8jets} [GeV];p_{T}^{highest btag AK8jets} [GeV]",20,18,278,50,0,1500);
   TH1D *h_mbbjet_select    = new TH1D("h_mbbjet_select","Invariant mass of selected bjets;M_{bb}[GeV]",10,18,278);
   TH1D *h_mbbjet_withABCD    = new TH1D("h_mbbjet_select_withABCD","Invariant mass of highest btag bjets in Higgs mass range;M_{bb}[GeV]",10,18,278);
   TH2D *h_mbbjet_vs_pt1    = new TH2D("h_mbbjet_vs_pt1","Invariant mass of highest btag bjets in Higgs mass range vs 1st p_{T};M_{bb}[GeV];p_{T}^{1} [GeV]",20,18,278,30,30,1030);
   TH2D *h_mbbjet_vs_pt2    = new TH2D("h_mbbjet_vs_pt2","Invariant mass of highest btag bjets in Higgs mass range vs 2nd p_{T};M_{bb}[GeV];p_{T}^{2} [GeV]",20,18,278,30,30,1030);
   TH2D *h_mbbjet_comb_vs_pt1    = new TH2D("h_mbbjet_comb_vs_pt1","Invariant mass of combination of all jets in Higgs mass range vs 1st p_{T};M_{bb}[GeV];p_{T}^{1} [GeV]",20,18,278,30,30,1030);
   TH2D *h_mbbjet_comb_vs_pt2    = new TH2D("h_mbbjet_comb_vs_pt2","Invariant mass of combination of all jets in Higgs mass range vs 1st p_{T};M_{bb}[GeV];p_{T}^{1} [GeV]",20,18,278,30,30,1030);
     
   TH1D *h_AK4_AK8 = new TH1D("h_AK4_AK8","Higgs candidate findings;",9,0.5,9.5);
   const int nbins_MET=6;
   double xbins_MET[nbins_MET+1]={0,50,70,100,200,500,1000};
   double yz[4]={-0.5,0.5,1.5,2.5};
   TH3D *h_MET_AK4_AK8 = new TH3D("h_MET_AK4_AK8",";MET [GeV];AK4 (0, 1, 2 loose);AK8 0, 1 loose, 1 medium",nbins_MET,xbins_MET,3,yz,3,yz);
   TH1D *h_AK4_category = new TH1D("h_AK4_category","AK4 btag-Higgs window categories;NoBtag-NoWindow, 1Btag-NoWindow, 2Btag-NoWindow, NoBtag-Window, Undecided, 1Selected, 2Selected",7,0.5,7.5);

   const int dim=4;
   int nbins[dim]={3,3,6,3};
   double xmin[dim]={-0.5,-0.5,0.5,0.5};
   double xmax[dim]={2.5,2.5,6.5,3.5};
   THnD *hn_searchBins = new THnD("hn_searchBins",";AK4;AK8;MET;njets",dim,nbins,xmin,xmax);
   hn_searchBins->Sumw2();
   unsigned int nsbins=hn_searchBins->GetNbins();
   TH1D *h_searchBins= new TH1D("h_searchBins",";searchBins",nsbins,0.5,nsbins+0.5);
   
   //AK4 searchbins
   const int dim_ak4=4;
   int nbins_ak4[dim_ak4]={2,3,6,3};
   double xmin_ak4[dim_ak4]={-0.5,-0.5,0.5,0.5};
   double xmax_ak4[dim_ak4]={1.5,2.5,6.5,3.5};
   THnD *hn_AK4searchBins = new THnD("hn_AK4searchBins",";VR;AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
   hn_AK4searchBins->Sumw2();
   unsigned int nsbins_ak4=hn_AK4searchBins->GetNbins();
   TH1D *h_AK4searchBins= new TH1D("h_AK4searchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
   
   //AK8 searchbins
   const int dim_ak8=4;
   int nbins_ak8[dim_ak8]={2,2,6,3};
   double xmin_ak8[dim_ak8]={-0.5,-0.5,0.5,0.5};
   double xmax_ak8[dim_ak8]={1.5,1.5,6.5,3.5};
   THnD *hn_AK8searchBins = new THnD("hn_AK8searchBins",";VR;AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
   hn_AK8searchBins->Sumw2();
   unsigned int nsbins_ak8=hn_AK8searchBins->GetNbins();
   TH1D *h_AK8searchBins= new TH1D("h_AK8searchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);

   //Histograms for signalstudy
   TH1D *hs_Hpt, *hs_AK8Hmass, *hs_AK4Hmass, *hs_PhoEt, *hs_AK4_AK8_true, *hs_drmin_AK4AK8[4], *hs_drmax_AK4AK8[4], *hs_dr_AK4AK4[4];
   TH1D *hs_true_HiggsAK8Jet, *hs_true_HiggsAK4Jet, *hs_true_ak4bjets;
   TH2D *hs_gMET_Bquark, *hs_MET_Bquark, *hs_gMET_Bjetlikequark, *hs_MET_Bjetlikequark;
   TH2D *hs_MET_trueBjets, *hs_MET_trueBjets_loose, *hs_MET_trueBjets_medium, *hs_MET_trueBjets_tight;
   TH2D *hs_MET_trueBjets_AK8, *hs_MET_trueBjets_loose_AK8, *hs_MET_trueBjets_medium_AK8, *hs_MET_trueBjets_tight_AK8;
   TH2D *hs_ak4_selected;
   if (signalstudy) {
     hs_Hpt = new TH1D("hs_Hpt","Higgs pt;p_{T}[GeV]",25,0,1000);
     hs_PhoEt = new TH1D("hs_PhoEt","Et of Photon from neutralino;E_{T}[GeV]",25,0,1000);
     hs_AK8Hmass = new TH1D("hs_AK8Hmass","PrunedCorr AK8mass of Higgsmother jet;PrunedCorr m[GeV]",10,18,278);
     hs_AK4Hmass = new TH1D("hs_AK4Hmass","Invariant mass of Higgsmother AK4jets;m_{bb}[GeV]",10,18,278);
     hs_AK4_AK8_true = new TH1D("hs_AK4_AK8_true","Higgs candidate findings with truth;",9,0.5,9.5);
     string names[4]={"_5","_6","_8","_9"};
     string pre[3]={"hs_drmin_AK4AK8","hs_drmax_AK4AK8","hs_dr_AK4AK4"};
     for (int i=0; i<4; i++) {
       hs_drmin_AK4AK8[i] = new TH1D((pre[0]+names[i]).c_str(),"Min dR between Higgs candidate AK4, AK8 jets;dR",20,0,5);
       hs_drmax_AK4AK8[i] = new TH1D((pre[1]+names[i]).c_str(),"Max dR between Higgs candidate AK4, AK8 jets;dR",20,0,5);
       hs_dr_AK4AK4[i] = new TH1D((pre[2]+names[i]).c_str(),"dR between Higgs candidate AK4 jets;dR",20,0,5);
     }
     hs_true_HiggsAK8Jet= new TH1D("hs_true_HiggsAK8Jet","True Higgs AK8Jet;1 Higgs, HAK8jet, HAK8jet=highest, HAK8jet=semi-highest, HAK8jet=selected",5,0.5,5.5);
     hs_true_HiggsAK4Jet= new TH1D("hs_true_HiggsAK4Jet","True Higgs AK4Jet;1 Higgs, 1 Hjet, 1Hjet=highest, 1Hjet=semi-highest, 1 Hjet=selected, 2 Hjet, 2Hjet=highest, 2Hjet=semi-highest, 2Hjet=selected",9,0.5,9.5);
     hs_gMET_Bquark = new TH2D("hs_gMET_Bquark",";genMET[GeV];# of b quarks",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_Bquark = new TH2D("hs_MET_Bquark",";MET[GeV];# of b quarks",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_gMET_Bjetlikequark = new TH2D("hs_gMET_Bjetlikequark",";genMET[GeV];# of b quarks",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_Bjetlikequark = new TH2D("hs_MET_Bjetlikequark",";MET[GeV];# of b quarks",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_trueBjets = new TH2D("hs_MET_trueBjets",";MET[GeV];# of true b jets",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_trueBjets_loose = new TH2D("hs_MET_trueBjets_loose",";MET[GeV];# of loose tagged true b jets",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_trueBjets_medium = new TH2D("hs_MET_trueBjets_medium",";MET[GeV];# of medium tagged true b jets",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_trueBjets_tight = new TH2D("hs_MET_trueBjets_tight",";MET[GeV];# of tight tagged true b jets",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_trueBjets_AK8 = new TH2D("hs_MET_trueBjets_AK8",";MET[GeV];# of true b ak8jets",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_trueBjets_loose_AK8 = new TH2D("hs_MET_trueBjets_loose_AK8",";MET[GeV];# of loose tagged true b ak8jets",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_trueBjets_medium_AK8 = new TH2D("hs_MET_trueBjets_medium_AK8",";MET[GeV];# of medium tagged true b ak8jets",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_MET_trueBjets_tight_AK8 = new TH2D("hs_MET_trueBjets_tight_AK8",";MET[GeV];# of tight tagged true b ak8jets",nbins_pfMET,xbins_pfMET,7,-0.5,6.5);
     hs_ak4_selected = new TH2D("hs_ak4_selected","Index of Higgs candidate ak4 jets;First;Second",20,-0.5,19.5,20,-0.5,19.5);
     hs_true_ak4bjets = new TH1D("hs_true_ak4bjets","# of true ak4 b jets;# of true b jets",10,-0.5,9.5);
   }
   if (SignalScan) {
     init_scan_histos(f,signalstudy);
   }

   TBenchmark time;
   TDatime now;
   if (!is_quiet) now.Print();
   time.Start("time");

   std::map<pair<int,int>,int> signal_events;
   if (CountSignal) signal_events=init_signal_event();
   int file_counter=-1, temp=-1; std::string temp_f="";
   ULong64_t TotalEvents=1;
   int zbx=0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     //nb = fChain->GetEntry(jentry);   nbytes += nb;
     b_isData->GetEntry(ientry); //read only this branch
     b_isPVGood->GetEntry(ientry);
     if (!isData) {
       b_genWeight->GetEntry(ientry);
       b_nPUInfo->GetEntry(ientry);
       b_nPU->GetEntry(ientry);
       b_puBX->GetEntry(ientry);
       b_puTrue->GetEntry(ientry);
       b_nMC->GetEntry(ientry);
       b_mcPID->GetEntry(ientry);
       b_mcMomPID->GetEntry(ientry);
       b_mcGMomPID->GetEntry(ientry);
       b_mcVtx->GetEntry(ientry);
       b_mcVty->GetEntry(ientry);
       b_mcVtz->GetEntry(ientry);
       b_mcPt->GetEntry(ientry);
       b_mcE->GetEntry(ientry);
       b_mcEt->GetEntry(ientry);
       b_mcPhi->GetEntry(ientry);
       b_mcEta->GetEntry(ientry);
       b_mcMass->GetEntry(ientry);
       b_mcStatus->GetEntry(ientry);
       b_genMET->GetEntry(ientry);
       b_jetGenEta->GetEntry(ientry);
       b_jetGenPhi->GetEntry(ientry);
       b_jetGenPartonMomID->GetEntry(ientry);
       b_jetHadFlvr->GetEntry(ientry);
       b_jetP4Smear->GetEntry(ientry);
       b_jetP4SmearUp->GetEntry(ientry);
       b_jetP4SmearDo->GetEntry(ientry);
       b_AK8JetGenPartonMomID->GetEntry(ientry);
       b_AK8JetHadFlvr->GetEntry(ientry);
       b_AK8JetP4Smear->GetEntry(ientry);
       b_AK8JetP4SmearUp->GetEntry(ientry);
       b_AK8JetP4SmearDo->GetEntry(ientry);
     }
     b_event->GetEntry(ientry);
     b_nGoodVtx->GetEntry(ientry);
     b_nVtx->GetEntry(ientry);
     b_HLTEleMuX->GetEntry(ientry);
     b_HLTPho->GetEntry(ientry);
     b_metFilters->GetEntry(ientry);
     b_pfMET->GetEntry(ientry);
     b_pfMETPhi->GetEntry(ientry);
     b_pfMETsumEt->GetEntry(ientry);
     b_pfMETSig->GetEntry(ientry);
     b_nEle->GetEntry(ientry);
     b_eleEta->GetEntry(ientry);
     b_elePhi->GetEntry(ientry);
     b_elePt->GetEntry(ientry);
     b_eleSCEta->GetEntry(ientry);
     b_eleSCPhi->GetEntry(ientry);
     b_eleCalibPt->GetEntry(ientry);
     b_elePFMiniIso->GetEntry(ientry);
     b_eleIDMVA->GetEntry(ientry);
     b_eleIDbit->GetEntry(ientry);
     b_nMu->GetEntry(ientry);
     b_muPt->GetEntry(ientry);
     b_muEta->GetEntry(ientry);
     b_muPhi->GetEntry(ientry);
     b_muSIP->GetEntry(ientry);
     b_muDz->GetEntry(ientry);
     b_muD0->GetEntry(ientry);
     b_muPFMiniIso->GetEntry(ientry);
     b_muIDbit->GetEntry(ientry);
     b_nPho->GetEntry(ientry);
     b_phoEt->GetEntry(ientry);
     b_phoCalibEt->GetEntry(ientry);
     b_phoEta->GetEntry(ientry);
     b_phoPhi->GetEntry(ientry);
     b_phoSCEta->GetEntry(ientry);
     b_phoSCPhi->GetEntry(ientry);
     b_phoR9->GetEntry(ientry);
     b_phohasPixelSeed->GetEntry(ientry);
     b_phoEleVeto->GetEntry(ientry);
     b_phoHoverE->GetEntry(ientry);
     b_phoPFChIso->GetEntry(ientry);
     b_phoPFPhoIso->GetEntry(ientry);
     b_phoPFNeuIso->GetEntry(ientry);
     b_phoIDMVA->GetEntry(ientry);
     b_phoIDbit->GetEntry(ientry);
     b_nTau->GetEntry(ientry);
     b_tauPt->GetEntry(ientry);
     b_tauEta->GetEntry(ientry);
     b_tauPhi->GetEntry(ientry);
     b_tauByLooseCombinedIsolationDeltaBetaCorr3Hits->GetEntry(ientry);
     b_tauByMediumCombinedIsolationDeltaBetaCorr3Hits->GetEntry(ientry);
     b_tauByTightCombinedIsolationDeltaBetaCorr3Hits->GetEntry(ientry);
     b_nJet->GetEntry(ientry);
     b_jetEn->GetEntry(ientry);
     b_jetPt->GetEntry(ientry);
     b_jetPhi->GetEntry(ientry);
     b_jetEta->GetEntry(ientry);
     b_jetCHF->GetEntry(ientry);
     b_jetJetProbabilityBJetTags->GetEntry(ientry);
     b_jetCSV2BJetTags->GetEntry(ientry);
     b_jetpfCombinedMVAV2BJetTags->GetEntry(ientry);
     b_jetDeepCSVTags_b->GetEntry(ientry);
     b_jetDeepCSVTags_bb->GetEntry(ientry);
     b_jetDeepCSVTags_c->GetEntry(ientry);
     b_jetDeepCSVTags_cc->GetEntry(ientry);
     b_jetDeepCSVTags_udsg->GetEntry(ientry);
     b_jetPFLooseId->GetEntry(ientry);
     b_jetPUFullID->GetEntry(ientry);
     b_nAK8Jet->GetEntry(ientry);
     b_AK8JetPt->GetEntry(ientry);
     b_AK8JetEta->GetEntry(ientry);
     b_AK8JetPhi->GetEntry(ientry);
     b_AK8JetEn->GetEntry(ientry);
     b_AK8JetMass->GetEntry(ientry);
     b_AK8JetPrunedMass->GetEntry(ientry);
     b_AK8JetPrunedMassCorr->GetEntry(ientry);
     b_AK8JetSoftDropMassCorr->GetEntry(ientry);
     b_AK8JetPFLooseId->GetEntry(ientry);
     b_AK8JetpfBoostedDSVBTag->GetEntry(ientry);
     b_AK8Jet_tau1->GetEntry(ientry);
     b_AK8Jet_tau2->GetEntry(ientry);
     b_AK8Jet_tau3->GetEntry(ientry);
     b_AK8puppiSDMassL2L3Corr->GetEntry(ientry);
     b_AK8puppiTau1->GetEntry(ientry);
     b_AK8puppiTau2->GetEntry(ientry);
     b_AK8puppiTau3->GetEntry(ientry);
     b_nIsoTrack->GetEntry(ientry);
     b_isoPt->GetEntry(ientry);
     b_isoEta->GetEntry(ientry);
     b_isoPhi->GetEntry(ientry);
     b_isoD0->GetEntry(ientry);
     b_isoDz->GetEntry(ientry);
     b_isoChIso->GetEntry(ientry);
     b_isoChRelIso->GetEntry(ientry);
     b_isoPdgID->GetEntry(ientry);
     b_isoLeptonOverlap->GetEntry(ientry);
     bool newfile=false;
  
     //progress bar
     double progress=(jentry+1)/double(nentries);
     if (!is_quiet){
       if (temp!=int(progress * 10000)){
         temp=int(progress * 10000);
         int vmi=int(progress * 100)*100;
         std::cout << vmi/100 <<"."<< temp-vmi << " %\r";
         std::cout.flush();
       }
     }
     if (temp_f != fChain->GetCurrentFile()->GetName()) {
       temp_f=fChain->GetCurrentFile()->GetName();
       file_counter++;
       //std::cout<<"file "<<file_counter<<" "<<fChain->GetCurrentFile()->GetName()<<std::endl;
       newfile=true;
     }
     if (_fakeRate && jentry==0) {
       TFile f_FR("input/FakeRate_EGamma.root","read");
       h2_FR = (TH2D*)f_FR.Get("FR_Data_EtaPhi_50_110");
       h2_FR->SetDirectory(0);
       f_FR.Close();
     }
     if (isData && signalstudy) {cout<<"ERROR! Signalstudy option set, but running on Data..."<<endl; return;}
     //SignalScan variables
     pair<int,int> mass_pair;
     if (SignalScan) {
       int neutralino=-1, gluino=-1;
       for (int i=0;i<nMC;i++) {
         if ((*mcPID)[i]==1000023 && (*mcStatus)[i]==22) neutralino=i;
         if ((*mcPID)[i]==1000021 && (*mcStatus)[i]==22) gluino=i;
       }
       int m_Gluino = (*mcMass)[gluino];
       //Neutralino mass is not exact. Need to find nearest grid point
       double m_Neutralino=(*mcMass)[neutralino];
       pair<double,double> initial_pair(m_Gluino,m_Neutralino);
       mass_pair = whichGridpoint(initial_pair);
       if (CountSignal) {
         auto search = signal_events.find(mass_pair);
         if (search!=signal_events.end()) search->second +=1;
       }
     }
     w=1;
     //MC weights and scale factors
     if (!isData){
     //getting h_cross_section & total number of events
       if (jentry==0 || newfile){
         if (fChain->GetCurrentFile()->GetListOfKeys()->Contains("h_cross_section")) {
           TH1D *htemp=(TH1D*)fChain->GetCurrentFile()->Get("h_cross_section");
           xsec=htemp->GetBinContent(1);
         }
         else if (!SignalScan) std::cout<<"No h_cross_section found in file using xsec = "<<xsec<<std::endl;
         //for amc at nlo the TotalEvents is the sum of + and - events
         if (fChain->GetCurrentFile()->GetDirectory("ggNtuplizer") !=0) {
           TH1F *htemp = (TH1F*)fChain->GetCurrentFile()->Get("ggNtuplizer/hSumGenWeight");
           TotalEvents = htemp->GetBinContent(1);
         }
         else {
           TH1F *htemp = (TH1F*)fChain->GetCurrentFile()->Get("hSumGenWeight");
           TotalEvents = htemp->GetBinContent(1);
           //if (abs(genWeight)>1) {
             //TH1D *htemp=(TH1D*)fChain->GetCurrentFile()->Get("hEvents");
             //double calcXsec = TotalEvents*abs(genWeight)/htemp->GetBinContent(1);
             //std::cout<<"xsec = "<<xsec<<" calcXsec = "<<calcXsec<<std::endl;
           //}
           //std::cout<<"Tot = "<<TotalEvents<<std::endl;
         }
         //calculate PU weight
         h_PUweight = (TH1D*)h_dataPU->Clone("h_PUweight");
         h_PUweight->SetDirectory(0);
         if (newfile) {
           TH1F *h_mcPU;
           if (fChain->GetCurrentFile()->GetDirectory("ggNtuplizer") !=0) h_mcPU = (TH1F*)fChain->GetCurrentFile()->GetDirectory("ggNtuplizer")->Get("hPUTrue");
           else h_mcPU = (TH1F*)fChain->GetCurrentFile()->Get("hPUTrue");
           h_mcPU->Scale(1/(h_mcPU->Integral()));
           h_PUweight->Divide(h_mcPU);
         }
       }
       if (SignalScan) {xsec=get_cross_section(mass_pair.first); TotalEvents=get_total_events(mass_pair);}
     //weights
       //get zero bunchcrossing (puTrue always the same for every bx, just in case...)
       for (unsigned int i=0;i<(*puBX).size();i++) if ((*puBX)[i]==0) zbx=i;
       double pu_weight=h_PUweight->GetBinContent(h_PUweight->FindBin((*puTrue)[zbx]));
       if (_fastSim || SignalScan) pu_weight=1;
       double weight=L_data*xsec/TotalEvents;
       //if (newfile) std::cout<<"weight=L_data*xsec/TotalEvents "<<weight<<"="<<L_data<<"*"<<xsec<<"/"<<TotalEvents<<std::endl;
       if (abs(genWeight)>1) w=copysign(weight*pu_weight,genWeight); //only a sign for amc@nlo
       else w=weight*pu_weight*genWeight;
       //std::cout<<"w=weight*pu_weight*genWeight "<<w<<"="<<weight<<"*"<<pu_weight<<"*"<<genWeight<<std::endl;
       //Scale factors
       if (jentry==0) {
         //photon cutbased loose
         TFile f_phoLooseSF("input/pho_looseSF_egammaEffi.txt_EGM2D.root","read");
         h_pho_EGamma_SF2D[0] = (TH2F*)f_phoLooseSF.Get("EGamma_SF2D");
         h_pho_EGamma_SF2D[0]->SetDirectory(0);
         f_phoLooseSF.Close();
         //photon cutbased medium
         TFile f_phoMediumSF("input/pho_mediumSF_egammaEffi.txt_EGM2D.root","read");
         h_pho_EGamma_SF2D[1] = (TH2F*)f_phoMediumSF.Get("EGamma_SF2D");
         h_pho_EGamma_SF2D[1]->SetDirectory(0);
         f_phoMediumSF.Close();
         //photon cutbased tight
         TFile f_phoTightSF("input/pho_tightSF_egammaEffi.txt_EGM2D.root","read");
         h_pho_EGamma_SF2D[2] = (TH2F*)f_phoTightSF.Get("EGamma_SF2D");
         h_pho_EGamma_SF2D[2]->SetDirectory(0);
         f_phoTightSF.Close();
         //photon haspixelseed SF
         TFile f_phoPV("input/ScalingFactors_80X_Summer16.root","read");
         h_Scaling_Factors_HasPix_R9_high = (TH2D*)f_phoPV.Get("Scaling_Factors_HasPix_R9 > 0.94");
         h_Scaling_Factors_HasPix_R9_high->SetDirectory(0);
         h_Scaling_Factors_HasPix_R9_low = (TH2D*)f_phoPV.Get("Scaling_Factors_HasPix_R9 < 0.94");
         h_Scaling_Factors_HasPix_R9_low->SetDirectory(0);
         f_phoPV.Close();
         //electron reconstruction efficiency
         TFile f_eleRecSF("input/ele_recEff_egammaEffi.txt_EGM2D.root","read");
         h_eleRec_EGamma_SF2D = (TH2F*)f_eleRecSF.Get("EGamma_SF2D");
         h_eleRec_EGamma_SF2D->SetDirectory(0);
         f_eleRecSF.Close();
         //electron cutbased veto
         TFile f_eleVetoSF("input/ele_vetoSF_egammaEffi.txt_EGM2D.root","read");
         h_ele_EGamma_SF2D[0] = (TH2F*)f_eleVetoSF.Get("EGamma_SF2D");
         h_ele_EGamma_SF2D[0]->SetDirectory(0);
         h_ele_EGamma_EffMC2D[0] = (TH2F*)f_eleVetoSF.Get("EGamma_EffMC2D");
         h_ele_EGamma_EffMC2D[0]->SetDirectory(0);
         f_eleVetoSF.Close();
         //electron cutbased loose
         TFile f_eleLooseSF("input/ele_looseSF_egammaEffi.txt_EGM2D.root","read");
         h_ele_EGamma_SF2D[1] = (TH2F*)f_eleLooseSF.Get("EGamma_SF2D");
         h_ele_EGamma_SF2D[1]->SetDirectory(0);
         h_ele_EGamma_EffMC2D[1] = (TH2F*)f_eleLooseSF.Get("EGamma_EffMC2D");
         h_ele_EGamma_EffMC2D[1]->SetDirectory(0);
         f_eleLooseSF.Close();
         //electron cutbased medium
         TFile f_eleMediumSF("input/ele_mediumSF_egammaEffi.txt_EGM2D.root","read");
         h_ele_EGamma_SF2D[2] = (TH2F*)f_eleMediumSF.Get("EGamma_SF2D");
         h_ele_EGamma_SF2D[2]->SetDirectory(0);
         h_ele_EGamma_EffMC2D[2] = (TH2F*)f_eleMediumSF.Get("EGamma_EffMC2D");
         h_ele_EGamma_EffMC2D[2]->SetDirectory(0);
         f_eleMediumSF.Close();
         //electron cutbased tight
         TFile f_eleTightSF("input/ele_tightSF_egammaEffi.txt_EGM2D.root","read");
         h_ele_EGamma_SF2D[3] = (TH2F*)f_eleTightSF.Get("EGamma_SF2D");
         h_ele_EGamma_SF2D[3]->SetDirectory(0);
         h_ele_EGamma_EffMC2D[3] = (TH2F*)f_eleTightSF.Get("EGamma_EffMC2D");
         h_ele_EGamma_EffMC2D[3]->SetDirectory(0);
         f_eleTightSF.Close();
         //Muon ID SF
         float lum_ratio_BCDEF = 0.5481;
         TH2D *h_temp[3], *h_temp_eff[3];
         TFile f_muID_BCDEF("input/EfficienciesAndSF_BCDEF.root","read");
         h_temp[0] = (TH2D*)f_muID_BCDEF.Get("MC_NUM_LooseID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
         h_temp[1] = (TH2D*)f_muID_BCDEF.Get("MC_NUM_MediumID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
         h_temp[2] = (TH2D*)f_muID_BCDEF.Get("MC_NUM_TightID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
         h_temp_eff[0] = (TH2D*)f_muID_BCDEF.Get("MC_NUM_LooseID_DEN_genTracks_PAR_pt_eta/efficienciesMC/pt_abseta_MC");
         h_temp_eff[1] = (TH2D*)f_muID_BCDEF.Get("MC_NUM_MediumID_DEN_genTracks_PAR_pt_eta/efficienciesMC/pt_abseta_MC");
         h_temp_eff[2] = (TH2D*)f_muID_BCDEF.Get("MC_NUM_TightID_DEN_genTracks_PAR_pt_eta/efficienciesMC/pt_abseta_MC");
         for (auto i : h_temp) {i->SetDirectory(0); i->Scale(lum_ratio_BCDEF);}
         for (auto i : h_temp_eff) {i->SetDirectory(0); i->Scale(lum_ratio_BCDEF);}
         f_muID_BCDEF.Close();
         TFile f_muID_GH("input/EfficienciesAndSF_GH.root","read");
         h_muID_SF2D[0] = (TH2D*)f_muID_GH.Get("MC_NUM_LooseID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
         h_muID_SF2D[1] = (TH2D*)f_muID_GH.Get("MC_NUM_MediumID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
         h_muID_SF2D[2] = (TH2D*)f_muID_GH.Get("MC_NUM_TightID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
         h_muID_EffMC2D[0] = (TH2D*)f_muID_GH.Get("MC_NUM_LooseID_DEN_genTracks_PAR_pt_eta/efficienciesMC/pt_abseta_MC");
         h_muID_EffMC2D[1] = (TH2D*)f_muID_GH.Get("MC_NUM_MediumID_DEN_genTracks_PAR_pt_eta/efficienciesMC/pt_abseta_MC");
         h_muID_EffMC2D[2] = (TH2D*)f_muID_GH.Get("MC_NUM_TightID_DEN_genTracks_PAR_pt_eta/efficienciesMC/pt_abseta_MC");
         for (auto i : h_muID_SF2D) {i->SetDirectory(0); i->Scale(1-lum_ratio_BCDEF);}
         for (auto i : h_muID_EffMC2D) {i->SetDirectory(0); i->Scale(1-lum_ratio_BCDEF);}
         f_muID_GH.Close();
         h_muID_SF2D[0]->Add(h_temp[0]);
         h_muID_SF2D[1]->Add(h_temp[1]);
         h_muID_SF2D[2]->Add(h_temp[2]);
         h_muID_EffMC2D[0]->Add(h_temp_eff[0]);
         h_muID_EffMC2D[1]->Add(h_temp_eff[1]);
         h_muID_EffMC2D[2]->Add(h_temp_eff[2]);
         //Muon ISO SF
         TFile f_muISO_BCDEF("input/EfficienciesAndSF_ISO_BCDEF.root","read");
         h_temp[0] = (TH2D*)f_muISO_BCDEF.Get("LooseISO_LooseID_pt_eta/pt_abseta_ratio");
         h_temp[1] = (TH2D*)f_muISO_BCDEF.Get("LooseISO_MediumID_pt_eta/pt_abseta_ratio");
         h_temp[2] = (TH2D*)f_muISO_BCDEF.Get("LooseISO_TightID_pt_eta/pt_abseta_ratio");
         for (auto i : h_temp) {i->SetDirectory(0); i->Scale(lum_ratio_BCDEF);}
         f_muISO_BCDEF.Close();
         TFile f_muISO_GH("input/EfficienciesAndSF_ISO_GH.root","read");
         h_muISO_SF2D[0] = (TH2D*)f_muISO_GH.Get("LooseISO_LooseID_pt_eta/pt_abseta_ratio");
         h_muISO_SF2D[1] = (TH2D*)f_muISO_GH.Get("LooseISO_MediumID_pt_eta/pt_abseta_ratio");
         h_muISO_SF2D[2] = (TH2D*)f_muISO_GH.Get("LooseISO_TightID_pt_eta/pt_abseta_ratio");
         for (auto i : h_muISO_SF2D) {i->SetDirectory(0); i->Scale(1-lum_ratio_BCDEF);}
         f_muISO_GH.Close();
         h_muISO_SF2D[0]->Add(h_temp[0]);
         h_muISO_SF2D[1]->Add(h_temp[1]);
         h_muISO_SF2D[2]->Add(h_temp[2]);
         //Muon Tracking SF
         TFile f_muTrk("input/Tracking_EfficienciesAndSF_BCDEFGH.root","read");
         h_muTrk_SF = (TGraph*)f_muTrk.Get("ratio_eff_eta3_dr030e030_corr");
         f_muTrk.Close();

         //Loading btag efficiency file, fill efficiency histograms
         if (btag_file.size()>0) {
           TFile f_btag(btag_file.c_str(),"read");
           eff_b_CSV_L = new TEfficiency(*(TH2D*)f_btag.Get("h_b_CSV_L"),*(TH2D*)f_btag.Get("h_allAK4bjets"));
           eff_b_CSV_M = new TEfficiency(*(TH2D*)f_btag.Get("h_b_CSV_M"),*(TH2D*)f_btag.Get("h_allAK4bjets"));
           eff_b_CSV_T = new TEfficiency(*(TH2D*)f_btag.Get("h_b_CSV_T"),*(TH2D*)f_btag.Get("h_allAK4bjets"));
           eff_c_CSV_L = new TEfficiency(*(TH2D*)f_btag.Get("h_c_CSV_L"),*(TH2D*)f_btag.Get("h_allAK4cjets"));
           eff_c_CSV_M = new TEfficiency(*(TH2D*)f_btag.Get("h_c_CSV_M"),*(TH2D*)f_btag.Get("h_allAK4cjets"));
           eff_c_CSV_T = new TEfficiency(*(TH2D*)f_btag.Get("h_c_CSV_T"),*(TH2D*)f_btag.Get("h_allAK4cjets"));
           eff_l_CSV_L = new TEfficiency(*(TH2D*)f_btag.Get("h_l_CSV_L"),*(TH2D*)f_btag.Get("h_allAK4ljets"));
           eff_l_CSV_M = new TEfficiency(*(TH2D*)f_btag.Get("h_l_CSV_M"),*(TH2D*)f_btag.Get("h_allAK4ljets"));
           eff_l_CSV_T = new TEfficiency(*(TH2D*)f_btag.Get("h_l_CSV_T"),*(TH2D*)f_btag.Get("h_allAK4ljets"));
           eff_b_Deep_L = new TEfficiency(*(TH2D*)f_btag.Get("h_b_Deep_L"),*(TH2D*)f_btag.Get("h_allAK4bjets"));
           eff_b_Deep_M = new TEfficiency(*(TH2D*)f_btag.Get("h_b_Deep_M"),*(TH2D*)f_btag.Get("h_allAK4bjets"));
           eff_b_Deep_T = new TEfficiency(*(TH2D*)f_btag.Get("h_b_Deep_T"),*(TH2D*)f_btag.Get("h_allAK4bjets"));
           eff_c_Deep_L = new TEfficiency(*(TH2D*)f_btag.Get("h_c_Deep_L"),*(TH2D*)f_btag.Get("h_allAK4cjets"));
           eff_c_Deep_M = new TEfficiency(*(TH2D*)f_btag.Get("h_c_Deep_M"),*(TH2D*)f_btag.Get("h_allAK4cjets"));
           eff_c_Deep_T = new TEfficiency(*(TH2D*)f_btag.Get("h_c_Deep_T"),*(TH2D*)f_btag.Get("h_allAK4cjets"));
           eff_l_Deep_L = new TEfficiency(*(TH2D*)f_btag.Get("h_l_Deep_L"),*(TH2D*)f_btag.Get("h_allAK4ljets"));
           eff_l_Deep_M = new TEfficiency(*(TH2D*)f_btag.Get("h_l_Deep_M"),*(TH2D*)f_btag.Get("h_allAK4ljets"));
           eff_l_Deep_T = new TEfficiency(*(TH2D*)f_btag.Get("h_l_Deep_T"),*(TH2D*)f_btag.Get("h_allAK4ljets"));
           eff_b_BDSV_L = new TEfficiency(*(TH2D*)f_btag.Get("h_b_BDSV_L"),*(TH2D*)f_btag.Get("h_allAK8bjets"));
           eff_b_BDSV_M1 = new TEfficiency(*(TH2D*)f_btag.Get("h_b_BDSV_M1"),*(TH2D*)f_btag.Get("h_allAK8bjets"));
           eff_b_BDSV_M2 = new TEfficiency(*(TH2D*)f_btag.Get("h_b_BDSV_M2"),*(TH2D*)f_btag.Get("h_allAK8bjets"));
           eff_b_BDSV_T = new TEfficiency(*(TH2D*)f_btag.Get("h_b_BDSV_T"),*(TH2D*)f_btag.Get("h_allAK8bjets"));
           f_btag.Close();
         }
       }
     }
     
     //object definitions
     int leadpt_ak4=-1, leadpt_ak8=-1, highBDSV=-1, highCSV1=-1, highCSV2=-1, highcMVA1=-1, highcMVA2=-1;
     vector<int> passPhoL, passPhoM, passPhoT, passJet, passAK8Jet, passEleV, passEleL, passEleM, passEleT, passMuL, passMuM, passMuT, passMuNO;
     vector<int> passTauL, passTauM, passTauT, passIso;
     vector<int> passElePhoL, passElePhoM, passElePhoT, passEleNO;
     vector<int> passFREleL, passFREleM, passFREleT;
     vector<float> jetSmearedPt, jetSmearedEn, AK8JetSmearedPt, AK8JetSmearedEn;
     map<int,char> passCSV, passcMVA, passBDSV, passDeep;
     HT_before=0; EMHT_before=0; HT_after=0; EMHT_after=0;
     AK8HT_before=0; AK8EMHT_before=0; AK8HT_after=0; AK8EMHT_after=0;
     ST=0; ST_G=0; MT=0;
     nleadElePhoL=-1; nleadElePhoM=-1; nleadElePhoT=-1;
     nleadFREleL=-1; nleadFREleM=-1; nleadFREleT=-1;
     nleadPhoL=-1; nleadPhoM=-1; nleadPhoT=-1;
     nleadEleL=-1; nleadEleM=-1; nleadEleT=-1, nleadEleNO=-1;
     nleadMuL=-1; nleadMuM=-1; nleadMuT=-1, nleadMuNO=-1;
     nleadTauL=-1; nleadTauM=-1; nleadTauT=-1; nleadIso=-1;
     ele_VETOSF=1; mu_VETOSF=1;
     for (int i=0;i<3;i++) {pho_SF[i]=1; mu_SF[i]=1;}
     for (int i=0;i<4;i++) ele_SF[i]=1;
     memset(bcounterCSV,0,sizeof bcounterCSV);
     memset(bcountercMVA,0,sizeof bcountercMVA);
     memset(bcounterBDSV,0,sizeof bcounterBDSV);
     memset(bcounterDeep,0,sizeof bcounterDeep);
     //photon
     for (int i=0;i<nPho;i++){
       if (abs((*phoSCEta)[i])<1.4442 && (*phohasPixelSeed)[i]==0 && (*phoCalibEt)[i]>40) {
        if ((*phoIDbit)[i]>>0&1) {
         passPhoL.push_back(i);
        }
        if ((*phoIDbit)[i]>>1&1) {
         passPhoM.push_back(i);
        }
        if ((*phoIDbit)[i]>>2&1) {
         passPhoT.push_back(i);
        }
       }
       if (abs((*phoSCEta)[i])<2.5 && (*phohasPixelSeed)[i]!=0) {
        if ((*phoIDbit)[i]>>0&1) {
         passElePhoL.push_back(i);
        }
        if ((*phoIDbit)[i]>>1&1) {
         passElePhoM.push_back(i);
        }
        if ((*phoIDbit)[i]>>2&1) {
         passElePhoT.push_back(i);
        }
       }
     }
     for (auto i : passPhoL) {
       if ((*phoCalibEt)[i]>(*phoCalibEt)[nleadPhoL]) nleadPhoL=i;
       EMHT_before+=(*phoCalibEt)[i];
     }
     for (auto i : passPhoM) if ((*phoCalibEt)[i]>(*phoCalibEt)[nleadPhoM]) nleadPhoM=i;
     for (auto i : passPhoT) if ((*phoCalibEt)[i]>(*phoCalibEt)[nleadPhoT]) nleadPhoT=i;
     for (auto i : passElePhoL) if ((*phoCalibEt)[i]>(*phoCalibEt)[nleadElePhoL]) nleadElePhoL=i;
     for (auto i : passElePhoM) if ((*phoCalibEt)[i]>(*phoCalibEt)[nleadElePhoM]) nleadElePhoM=i;
     for (auto i : passElePhoT) if ((*phoCalibEt)[i]>(*phoCalibEt)[nleadElePhoT]) nleadElePhoT=i;
     if (_fakeRate==2 && nPassElePhoL != 0) {nleadPhoL=nleadElePhoL; passPhoL.push_back(nleadElePhoL);}
     nPassElePhoL=passElePhoL.size();
     nPassElePhoM=passElePhoM.size();
     nPassElePhoT=passElePhoT.size();
     nPassPhoL=passPhoL.size();
     nPassPhoM=passPhoM.size();
     nPassPhoT=passPhoT.size();
     EMHT_after=EMHT_before;
     AK8EMHT_before=EMHT_before;
     AK8EMHT_after=EMHT_before;
     //Calculate photon SFs
     if (!isData) {
       if (nPassPhoL!=0){
         pho_SF[0]=h_pho_EGamma_SF2D[0]->GetBinContent(h_pho_EGamma_SF2D[0]->FindBin((*phoSCEta)[nleadPhoL],(*phoCalibEt)[nleadPhoL]));
         if ((*phoR9)[nleadPhoL]>0.94) pho_SF[0]*=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs((*phoSCEta)[nleadPhoL]),100));
         else pho_SF[0]*=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs((*phoSCEta)[nleadPhoL]),100));
       }
       if (nPassPhoM!=0){
         pho_SF[1]=h_pho_EGamma_SF2D[1]->GetBinContent(h_pho_EGamma_SF2D[1]->FindBin((*phoSCEta)[passPhoM[0]],(*phoCalibEt)[passPhoM[0]]));
         if ((*phoR9)[passPhoM[0]]>0.94) pho_SF[1]*=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs((*phoSCEta)[passPhoM[0]]),100));
         else pho_SF[1]*=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs((*phoSCEta)[passPhoM[0]]),100));
       }
       if (nPassPhoT!=0){
         pho_SF[2]=h_pho_EGamma_SF2D[2]->GetBinContent(h_pho_EGamma_SF2D[2]->FindBin((*phoSCEta)[passPhoT[0]],(*phoCalibEt)[passPhoT[0]]));
         if ((*phoR9)[passPhoT[0]]>0.94) pho_SF[2]*=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs((*phoSCEta)[passPhoT[0]]),100));
         else pho_SF[2]*=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs((*phoSCEta)[passPhoT[0]]),100));
       }
     }
     //electron
     for (int i=0;i<nEle;i++) {
       bool passOverlap=true;
         for (auto j : passPhoL) if (deltaR((*eleSCPhi)[i],(*phoSCPhi)[j],(*eleSCEta)[i],(*phoSCEta)[j])<0.3) {
           passOverlap=false;break;
         }
       if ((*eleCalibPt)[i]>5 && abs((*eleSCEta)[i])<2.5 && (*elePFMiniIso)[i]<0.2) {
         if ((*eleIDbit)[i]>>1&1) passFREleL.push_back(i);
         if ((*eleIDbit)[i]>>2&1) passFREleM.push_back(i);
         if ((*eleIDbit)[i]>>3&1) passFREleT.push_back(i);
         if (!passOverlap) continue;
         if ((*eleIDbit)[i]>>0&1) passEleV.push_back(i);
         if ((*eleIDbit)[i]>>1&1) passEleL.push_back(i);
         if ((*eleIDbit)[i]>>2&1) passEleM.push_back(i);
         if ((*eleIDbit)[i]>>3&1) passEleT.push_back(i);
         if (((*eleIDbit)[i]>>1&1) == 0) passEleNO.push_back(i);
       }
     }
     nPassEleV=passEleV.size();
     nPassEleL=passEleL.size();
     nPassEleM=passEleM.size();
     nPassEleT=passEleT.size();
     nPassEleNO=passEleNO.size();
     if (nPassEleL != 0) nleadEleL=passEleL[0];
     if (nPassEleM != 0) nleadEleM=passEleM[0];
     if (nPassEleT != 0) nleadEleT=passEleT[0];
     if (nPassEleNO != 0) nleadEleNO=passEleNO[0];
     nPassFREleL=passFREleL.size();
     nPassFREleM=passFREleM.size();
     nPassFREleT=passFREleT.size();
     if (nPassFREleL != 0) nleadFREleL=passFREleL[0];
     if (nPassFREleM != 0) nleadFREleM=passFREleM[0];
     if (nPassFREleT != 0) nleadFREleT=passFREleT[0];
     //Fake Rate
     if (_fakeRate) {
       if (_fakeRate==1 && nPassFREleL != 0) {
         if (abs((*eleSCEta)[nleadFREleL])>1.4442) continue;
         w*=h2_FR->GetBinContent(h2_FR->FindBin((*eleSCEta)[nleadFREleL],(*eleSCPhi)[nleadFREleL]));
       }
       if (_fakeRate==2 && nPassElePhoL != 0) {
         if (abs((*phoSCEta)[nleadElePhoL])>1.4442) continue;
         double FRetaphi=h2_FR->GetBinContent(h2_FR->FindBin((*phoSCEta)[nleadElePhoL],(*phoSCPhi)[nleadElePhoL]));
         double FRvalue=FRetaphi*_C*(_A*nGoodVtx+_B);
         //cout<<"etaphi "<<(*phoSCEta)[nleadElePhoL]<<" "<<(*phoSCPhi)[nleadElePhoL]<<endl;
         //cout<<FRvalue<<" = "<<FRetaphi<<" * "<<_C<<" *("<<_A<<" * "<<nGoodVtx<<" + "<<_B<<")"<<endl;
         w*=FRvalue;
       }
     }
     //Calculate electron SFs
     if (!isData) {
       if (nPassEleV!=0){
         ele_SF[0]=h_ele_EGamma_SF2D[0]->GetBinContent(h_ele_EGamma_SF2D[1]->FindBin((*eleSCEta)[passEleV[0]],(*eleCalibPt)[passEleV[0]]));
         ele_SF[0]*=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin((*eleSCEta)[passEleV[0]],(*eleCalibPt)[passEleV[0]]));
       }
       if (nPassEleL!=0){
         ele_SF[1]=h_ele_EGamma_SF2D[1]->GetBinContent(h_ele_EGamma_SF2D[1]->FindBin((*eleSCEta)[passEleL[0]],(*eleCalibPt)[passEleL[0]]));
         ele_SF[1]*=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin((*eleSCEta)[passEleL[0]],(*eleCalibPt)[passEleL[0]]));
       }
       if (nPassEleM!=0){
         ele_SF[2]=h_ele_EGamma_SF2D[2]->GetBinContent(h_ele_EGamma_SF2D[2]->FindBin((*eleSCEta)[passEleM[0]],(*eleCalibPt)[passEleM[0]]));
         ele_SF[2]*=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin((*eleSCEta)[passEleM[0]],(*eleCalibPt)[passEleM[0]]));
       }
       if (nPassEleT!=0){
         ele_SF[3]=h_ele_EGamma_SF2D[3]->GetBinContent(h_ele_EGamma_SF2D[3]->FindBin((*eleSCEta)[passEleT[0]],(*eleCalibPt)[passEleT[0]]));
         ele_SF[3]*=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin((*eleSCEta)[passEleT[0]],(*eleCalibPt)[passEleT[0]]));
       }
       if (nPassEleNO!=0){ //only for loose electrons so far
         double epsilon=h_ele_EGamma_EffMC2D[1]->GetBinContent(h_ele_EGamma_EffMC2D[1]->FindBin((*eleSCEta)[passEleNO[0]],(*eleCalibPt)[passEleNO[0]]));
         double sf=h_ele_EGamma_SF2D[1]->GetBinContent(h_ele_EGamma_SF2D[1]->FindBin((*eleSCEta)[passEleNO[0]],(*eleCalibPt)[passEleNO[0]]));
         ele_VETOSF = (1-sf*epsilon)/(1-epsilon);
       }
     }
     //muon
     for (int i=0;i<nMu;i++) {
       bool passOverlap=true;
       for (auto j : passPhoL) if (deltaR((*muPhi)[i],(*phoSCPhi)[j],(*muEta)[i],(*phoSCEta)[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passEleL) if (deltaR((*muPhi)[i],(*eleSCPhi)[j],(*muEta)[i],(*eleSCEta)[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
       if ((*muPt)[i]>5 && abs((*muEta)[i])<2.4 && (*muSIP)[i]<4 && (*muDz)[i]<0.1 && (*muD0)[i]<0.05 && (*muPFMiniIso)[i]<0.2) {
         if ((*muIDbit)[i]>>0&1) passMuL.push_back(i);
         if ((*muIDbit)[i]>>1&1) passMuM.push_back(i);
         if ((*muIDbit)[i]>>2&1) passMuT.push_back(i);
         if (((*muIDbit)[i]>>0&1) == 0) passMuNO.push_back(i);
       }
     }
     nPassMuL=passMuL.size();
     nPassMuM=passMuM.size();
     nPassMuT=passMuT.size();
     nPassMuNO=passMuNO.size();
     if (passMuL.size() != 0) nleadMuL=passMuL[0];
     if (passMuM.size() != 0) nleadMuM=passMuM[0];
     if (passMuT.size() != 0) nleadMuT=passMuT[0];
     if (passMuNO.size() != 0) nleadMuNO=passMuNO[0];
     //muon SF
     if (!isData){
       int iter[3]={-1,-1,-1};
       if (nPassMuL>0) iter[0]=passMuL.at(0);
       if (nPassMuM>0) iter[1]=passMuM.at(0);
       if (nPassMuT>0) iter[2]=passMuT.at(0);
       for (int i=0;i<3;i++) {
         if (iter[i]!=-1){
           float pt = ( (*muPt)[iter[i]]< 20)? 20 : ((*muPt)[iter[i]]< 100) ? (*muPt)[iter[i]] : 100 ; //Histo range is: 20-120, highest bin 60-120
           mu_SF[i]=h_muID_SF2D[i]->GetBinContent(h_muID_SF2D[i]->FindBin(pt,abs((*muEta)[iter[i]])));
           mu_SF[i]*=h_muISO_SF2D[i]->GetBinContent(h_muISO_SF2D[i]->FindBin(pt,abs((*muEta)[iter[i]])));
           double *y = h_muTrk_SF->GetY(); double *x = h_muTrk_SF->GetX(); int whichx=0;
           for (int j=0;;j++) {
             double xdo=h_muTrk_SF->GetErrorXlow(j); double xup=h_muTrk_SF->GetErrorXhigh(j);
             if ((*muEta)[iter[i]] >= (x[j]-xdo) && (*muEta)[iter[i]] <= (x[j]+xup)) {whichx=j;break;}
           }
           mu_SF[i]*=y[whichx];
         }
       }
       //muon vetoSF (only for vetoing loose muons)
       if (nPassMuNO>0) {
         int i=passMuNO.at(0);
         float pt = ( (*muPt)[i]< 20)? 20 : ((*muPt)[i]< 100) ? (*muPt)[i] : 100 ; //Histo range is: 20-120, highest bin 60-120
         double epsilon=h_muID_EffMC2D[0]->GetBinContent(h_muID_EffMC2D[0]->FindBin(pt,abs((*muEta)[i])));
         double sf=h_muID_SF2D[0]->GetBinContent(h_muID_SF2D[0]->FindBin(pt,abs((*muEta)[i])));
         mu_VETOSF = (1-sf*epsilon)/(1-epsilon);
       }
     }

     //Tau
     for (int i=0;i<nTau;i++) {
       bool passOverlap=true;
       for (auto j : passPhoL) if (deltaR((*tauPhi)[i],(*phoSCPhi)[j],(*tauEta)[i],(*phoSCEta)[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passEleL) if (deltaR((*tauPhi)[i],(*eleSCPhi)[j],(*tauEta)[i],(*eleSCEta)[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passMuL) if (deltaR((*tauPhi)[i],(*muPhi)[j],(*tauEta)[i],(*muEta)[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
       if ((*tauPt)[i]>20 && abs((*tauEta)[i])<2.3) {
         if ((*tauByLooseCombinedIsolationDeltaBetaCorr3Hits)[i]) passTauL.push_back(i);
         if ((*tauByMediumCombinedIsolationDeltaBetaCorr3Hits)[i]) passTauM.push_back(i);
         if ((*tauByTightCombinedIsolationDeltaBetaCorr3Hits)[i]) passTauT.push_back(i);
         //if ((*tauByLooseCombinedIsolationDeltaBetaCorr3Hits)[i] == 0) passTauNO.push_back(i);
       }
     }
     nPassTauL=passTauL.size();
     nPassTauM=passTauM.size();
     nPassTauT=passTauT.size();
     //nPassTauNO=passTauNO.size();
     if (passTauL.size() != 0) nleadTauL=passTauL[0];
     if (passTauM.size() != 0) nleadTauM=passTauM[0];
     if (passTauT.size() != 0) nleadTauT=passTauT[0];
     //if (passTauNO.size() != 0) nleadTauNO=passTauNO[0];
     
     //IsoTrack
     for (int i=0;i<nIsoTrack;i++) {
       bool passOverlap=true;
       for (auto j : passPhoL) if (deltaR((*isoPhi)[i],(*phoSCPhi)[j],(*isoEta)[i],(*phoSCEta)[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passEleL) if (deltaR((*isoPhi)[i],(*eleSCPhi)[j],(*isoEta)[i],(*eleSCEta)[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passMuL) if (deltaR((*isoPhi)[i],(*muPhi)[j],(*isoEta)[i],(*muEta)[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passTauL) if (deltaR((*isoPhi)[i],(*tauPhi)[j],(*isoEta)[i],(*tauEta)[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue; if ((*isoLeptonOverlap)[i]) continue;
       if (abs((*isoPdgID)[i])==11 || abs((*isoPdgID)[i])==13) {if ((*isoPt)[i]<5) continue;}
       else if ((*isoPt)[i]<10) continue;
       double MT_iso=sqrt(2*pfMET*(*isoPt)[i]*(1-cos(abs((*isoPhi)[i]-pfMETPhi))));
       if (abs((*isoEta)[i])<2.5 && (*isoD0)[i]<0.2 && (*isoDz)[i]<0.1 && MT_iso<100){
         if ((*isoPt)[i]<25 && (*isoChIso)[i]<5) passIso.push_back(i);
         if ((*isoPt)[i]>=25 && (*isoChRelIso)[i]<0.2) passIso.push_back(i);
       }
     }
     nPassIso=passIso.size();
     if (passIso.size() != 0) nleadIso=passIso[0];
     
     //jet ID
     //bool vetoEvent=false; //veto for fastsim unmatched jets https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSRecommendationsMoriond17#Cleaning_up_of_fastsim_jets_from
     for (int i=0;i<nJet;i++) {
       bool passcut=true;
       jetSmearedPt.push_back((*jetPt)[i]);
       jetSmearedEn.push_back((*jetEn)[i]);
       TLorentzVector jetp4;
       jetp4.SetPtEtaPhiE((*jetPt)[i],(*jetEta)[i],(*jetPhi)[i],(*jetEn)[i]);
       if (!isData && (*jetP4Smear)[i]>0) {
         jetp4 *=(*jetP4Smear)[i];
         jetSmearedPt.at(i) = jetp4.Pt();
         jetSmearedEn.at(i) = jetp4.Energy();
       }
       HT_before+=jetSmearedPt[i];
       if (abs((*jetEta)[i])>2.4 || (*jetPFLooseId)[i]==0 || jetSmearedPt[i]<30 || !((*jetPUFullID)[i]&(1<<2))) passcut=false;
       //if (_fastSim && (*jetPt)[i]>20 && abs((*jetEta)[i])<2.5 && (*jetCHF)[i]<0.1) {
       //if (_fastSim && passcut && (*jetCHF)[i]<0.1) {
       //  if ((*jetGenEta)[i]==-999) {std::cout<<"veto 999"<<std::endl;vetoEvent=true;}
       //  else if (deltaR((*jetPhi)[i],(*jetGenPhi)[i],(*jetEta)[i],(*jetGenEta)[i])>0.3) {std::cout<<"veto deltar"<<std::endl;vetoEvent=true;}
       //}
       for (auto j : passPhoL) if (deltaR((*jetPhi)[i],(*phoSCPhi)[j],(*jetEta)[i],(*phoSCEta)[j])<0.4) {
         passcut=false;break;
       }
       for (auto j : passEleL) if (deltaR((*jetPhi)[i],(*eleSCPhi)[j],(*jetEta)[i],(*eleSCEta)[j])<0.4) {
         passcut=false;break;
       }
       for (auto j : passMuL) if (deltaR((*jetPhi)[i],(*muPhi)[j],(*jetEta)[i],(*muEta)[j])<0.4) {
         passcut=false;break;
       }
       //for (auto j : passTauL) if (deltaR((*jetPhi)[i],(*tauPhi)[j],(*jetEta)[i],(*tauEta)[j])<0.4) {
       //  passcut=false;break;
       //}
       //for (auto j : passIso) if (deltaR((*jetPhi)[i],(*isoPhi)[j],(*jetEta)[i],(*isoEta)[j])<0.4) {
       //  passcut=false;break;
       //}
       if (passcut) passJet.push_back(i);
     }
     nPassAK4=passJet.size();
     //if (vetoEvent) {continue;}
     //jet pt, btags
     for (auto i : passJet) {
       float DeepCSVTag=(*jetDeepCSVTags_b)[i]+(*jetDeepCSVTags_bb)[i];
       if (jetSmearedPt[i]>jetSmearedPt[leadpt_ak4]) leadpt_ak4=i;
       HT_after+=jetSmearedPt[i];
       if ((*jetCSV2BJetTags)[i]>(*jetCSV2BJetTags)[highCSV1]) {highCSV2=highCSV1;highCSV1=i;}
       else if (highCSV2!=-1) if ((*jetCSV2BJetTags)[i]>(*jetCSV2BJetTags)[highCSV2]) highCSV2=i;
       if ((*jetpfCombinedMVAV2BJetTags)[i]>(*jetpfCombinedMVAV2BJetTags)[highcMVA1]) {highcMVA2=highcMVA1;highcMVA1=i;}
       else if (highcMVA2!=-1) if ((*jetpfCombinedMVAV2BJetTags)[i]>(*jetpfCombinedMVAV2BJetTags)[highcMVA2]) highcMVA2=i;
       if ((*jetpfCombinedMVAV2BJetTags)[i]>BtagcMVAWP[2]) {passcMVA.insert(pair<int,char>(i,'T'));bcountercMVA[3]++;}
       else if ((*jetpfCombinedMVAV2BJetTags)[i]>BtagcMVAWP[1]) {passcMVA.insert(pair<int,char>(i,'M'));bcountercMVA[2]++;}
       else if ((*jetpfCombinedMVAV2BJetTags)[i]>BtagcMVAWP[0]) {passcMVA.insert(pair<int,char>(i,'L'));bcountercMVA[1]++;}
       else {passcMVA.insert(pair<int,char>(i,'0'));bcountercMVA[0]++;}
       if ((*jetCSV2BJetTags)[i]>BtagCSVWP[2]) {passCSV.insert(pair<int,char>(i,'T'));bcounterCSV[3]++;}
       else if ((*jetCSV2BJetTags)[i]>BtagCSVWP[1]) {passCSV.insert(pair<int,char>(i,'M'));bcounterCSV[2]++;}
       else if ((*jetCSV2BJetTags)[i]>BtagCSVWP[0]) {passCSV.insert(pair<int,char>(i,'L'));bcounterCSV[1]++;}
       else {passCSV.insert(pair<int,char>(i,'0'));bcounterCSV[0]++;}
       if (DeepCSVTag>BtagDeepWP[2]) {passDeep.insert(pair<int,char>(i,'T'));bcounterDeep[3]++;}
       else if (DeepCSVTag>BtagDeepWP[1]) {passDeep.insert(pair<int,char>(i,'M'));bcounterDeep[2]++;}
       else if (DeepCSVTag>BtagDeepWP[0]) {passDeep.insert(pair<int,char>(i,'L'));bcounterDeep[1]++;}
       else {passDeep.insert(pair<int,char>(i,'0'));bcounterDeep[0]++;}
     }
     bcounterCSV[2] += bcounterCSV[3];
     bcounterCSV[1] += bcounterCSV[2];
     bcountercMVA[2] += bcountercMVA[3];
     bcountercMVA[1] += bcountercMVA[2];
     bcounterDeep[2] += bcounterDeep[3];
     bcounterDeep[1] += bcounterDeep[2];
     //Sort passJet from highest CSV btag to lowest
     for (unsigned int i=0;i<passJet.size();i++){
     int temp;
       for (unsigned int j=passJet.size()-1;j>i;j--){
         if ((*jetCSV2BJetTags)[passJet[j]]>(*jetCSV2BJetTags)[passJet[j-1]]){
           temp=passJet[j-1];
           passJet[j-1]=passJet[j];
           passJet[j]=temp;
         }
       }
     }
     EMHT_before+=HT_before;
     EMHT_after+=HT_after;

     //AK8Jet ID
     for (int i=0;i<nAK8Jet;i++) {
       bool passcut=true;
       AK8JetSmearedPt.push_back((*AK8JetPt)[i]);
       AK8JetSmearedEn.push_back((*AK8JetEn)[i]);
       TLorentzVector jetp4;
       jetp4.SetPtEtaPhiE((*AK8JetPt)[i],(*AK8JetEta)[i],(*AK8JetPhi)[i],(*AK8JetEn)[i]);
       if (!isData && (*AK8JetP4Smear)[i]>0) {
         jetp4 *=(*AK8JetP4Smear)[i];
         AK8JetSmearedPt.at(i) = jetp4.Pt();
         AK8JetSmearedEn.at(i) = jetp4.Energy();
       }
       AK8HT_before+=AK8JetSmearedPt[i];
       if (abs((*AK8JetEta)[i])>2.4 || (*AK8JetPFLooseId)[i]==0 || AK8JetSmearedPt[i]<300) passcut=false;
       for (auto j : passPhoL) if (deltaR((*AK8JetPhi)[i],(*phoSCPhi)[j],(*AK8JetEta)[i],(*phoSCEta)[j])<0.8) {
         passcut=false;break;
       }
       for (auto j : passEleL) if (deltaR((*AK8JetPhi)[i],(*eleSCPhi)[j],(*AK8JetEta)[i],(*eleSCEta)[j])<0.8) {
         passcut=false;break;
       }
       for (auto j : passMuL) if (deltaR((*AK8JetPhi)[i],(*muPhi)[j],(*AK8JetEta)[i],(*muEta)[j])<0.8) {
         passcut=false;break;
       }
       //for (auto j : passTauL) if (deltaR((*AK8JetPhi)[i],(*tauPhi)[j],(*AK8JetEta)[i],(*tauEta)[j])<0.8) {
       //  passcut=false;break;
       //}
       //for (auto j : passIso) if (deltaR((*AK8JetPhi)[i],(*isoPhi)[j],(*AK8JetEta)[i],(*isoEta)[j])<0.8) {
       //  passcut=false;break;
       //}
       if (passcut) passAK8Jet.push_back(i);
     }
     nPassAK8=passAK8Jet.size();
     //AK8Jet pt, btag
     for (auto i : passAK8Jet) {
       if (AK8JetSmearedPt[i]>AK8JetSmearedPt[leadpt_ak8]) leadpt_ak8=i;
       AK8HT_after+=AK8JetSmearedPt[i];
       double i_jetdB=(*AK8JetpfBoostedDSVBTag)[i], h_jetdB;
       if (highBDSV==-1) h_jetdB=-10; else h_jetdB=(*AK8JetpfBoostedDSVBTag)[highBDSV];
       if (i_jetdB>h_jetdB) highBDSV=i;
       if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[3]) {passBDSV.insert(pair<int,char>(i,'T'));bcounterBDSV[4]++;}
       else if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[2]) {passBDSV.insert(pair<int,char>(i,'H'));bcounterBDSV[3]++;}
       else if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[1]) {passBDSV.insert(pair<int,char>(i,'M'));bcounterBDSV[2]++;}
       else if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[0]) {passBDSV.insert(pair<int,char>(i,'L'));bcounterBDSV[1]++;}
       else {passBDSV.insert(pair<int,char>(i,'0'));bcounterBDSV[0]++;}
     }
     bcounterBDSV[3] += bcounterBDSV[4];
     bcounterBDSV[2] += bcounterBDSV[3];
     bcounterBDSV[1] += bcounterBDSV[2];
     //Sort passAK8Jet from highest BDSV btag to lowest
     for (unsigned int i=0;i<passAK8Jet.size();i++){
       int temp;
       for (unsigned int j=passAK8Jet.size()-1;j>i;j--){
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[j]]>(*AK8JetpfBoostedDSVBTag)[passAK8Jet[j-1]]){
           temp=passAK8Jet[j-1];
           passAK8Jet[j-1]=passAK8Jet[j];
           passAK8Jet[j]=temp;
         }
       }
     }
     AK8EMHT_before+=HT_before;
     AK8EMHT_after+=HT_after;
     //dR between leading photon & leading pt AK8
     double dR_pho_AK8=-1;
     if (passPhoL.size()>0 && passAK8Jet.size()>0){
       if (abs((*AK8JetEta)[leadpt_ak8])<1.4442){
         dR_pho_AK8=deltaR((*AK8JetPhi)[leadpt_ak8],(*phoSCPhi)[nleadPhoL],(*AK8JetEta)[leadpt_ak8],(*phoSCEta)[nleadPhoL]);
       }
     }
     //MET variables
     for (auto i : passPhoL) ST+=(*phoCalibEt)[i];
     ST+=pfMET;
     ST_G=ST;
     for (auto i : passJet) ST+=jetSmearedPt[i];
     if (passPhoL.size()>0) MT=sqrt(2*pfMET*(*phoCalibEt)[nleadPhoL]*(1-cos(abs((*phoSCPhi)[nleadPhoL]-pfMETPhi))));
     if (_fakeRate) {
       if (_fakeRate==1 && nPassFREleL != 0) MT=sqrt(2*pfMET*(*eleCalibPt)[nleadFREleL]*(1-cos(abs((*eleSCPhi)[nleadFREleL]-pfMETPhi))));
     }
     
     //find which btag jet to use for Higgs mass
     //AK8
     passBtag=false, passHiggsMass=false;
     int SelectedAK8Jet=-1;
     BDSV_selected=0; //BDSV btag value of higgs candidate jet. 0-Nobtag, 1-loose, 2-medium 3-medium2 4-tight
     for (auto i : passAK8Jet){
       if ((*AK8JetPrunedMassCorr)[i]>70 && (*AK8JetPrunedMassCorr)[i]<200) {
       //if ((*AK8puppiSDMassL2L3Corr)[i]>70 && (*AK8puppiSDMassL2L3Corr)[i]<200) {
         passHiggsMass=true;
         SelectedAK8Jet=i;
         if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[3]) BDSV_selected=4;
         else if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[2]) BDSV_selected=3;
         else if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[1]) BDSV_selected=2;
         else if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[0]) BDSV_selected=1;
         else BDSV_selected=0;
         if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[0]) passBtag=true;
         break;
       }
     }
     if (!passHiggsMass && nPassAK8>0) SelectedAK8Jet = passAK8Jet.at(0);

      //AK4
     passAK4Btag1=false, passAK4Btag2=false, passAK4HiggsMass=false;
     double m_bb=-1;
     int SelectedAK4Jet1=-1, SelectedAK4Jet2=-1;
     int ith_jet=-1, jth_jet=-1;
     CSV_selected=0; //CSV btag value of higgs candidate jets. 0-Nobtag, 1-1 loose btag, 2-2 loose btag
     for (unsigned int i=0;i<passJet.size();i++){
       for (unsigned int j=i+1;j<passJet.size();j++){
         TLorentzVector bjet1, bjet2;
         bjet1.SetPtEtaPhiE(jetSmearedPt[passJet.at(i)],(*jetEta)[passJet.at(i)],(*jetPhi)[passJet.at(i)],jetSmearedEn[passJet.at(i)]);
         bjet2.SetPtEtaPhiE(jetSmearedPt[passJet.at(j)],(*jetEta)[passJet.at(j)],(*jetPhi)[passJet.at(j)],jetSmearedEn[passJet.at(j)]);
         m_bb=(bjet1+bjet2).M();
         if (m_bb>70 && m_bb<200) {
           SelectedAK4Jet1=passJet.at(i); ith_jet=i;
           SelectedAK4Jet2=passJet.at(j); jth_jet=j;
           if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[0]) {passAK4Btag1=true;CSV_selected++;}
           if ((*jetCSV2BJetTags)[passJet.at(j)]>BtagCSVWP[0]) {passAK4Btag2=true;CSV_selected++;}
           passAK4HiggsMass=true;
           break;
         }
       }
       if (passAK4HiggsMass) break;
     }
     if (!passAK4HiggsMass && nPassAK4>1) {SelectedAK4Jet1 = passJet.at(0); SelectedAK4Jet2 = passJet.at(1);}

     //Calculate all pairs
     unsigned int bpairs=0;
     for (unsigned int i=0;i<passJet.size();i++){
       for (unsigned int j=i+1;j<passJet.size();j++){
         bool passBtag1=false, passBtag2=false, passHmass=false;
         TLorentzVector bjet1, bjet2;
         bjet1.SetPtEtaPhiE(jetSmearedPt[passJet.at(i)],(*jetEta)[passJet.at(i)],(*jetPhi)[passJet.at(i)],jetSmearedEn[passJet.at(i)]);
         bjet2.SetPtEtaPhiE(jetSmearedPt[passJet.at(j)],(*jetEta)[passJet.at(j)],(*jetPhi)[passJet.at(j)],jetSmearedEn[passJet.at(j)]);
         m_bb=(bjet1+bjet2).M();
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[0]) passBtag1=true;
         if ((*jetCSV2BJetTags)[passJet.at(j)]>BtagCSVWP[0]) passBtag2=true;
         if (m_bb>70 && m_bb<200) passHmass=true;
         if (passBtag2 && passHmass) bpairs|=1;
         if (passBtag1 && !passBtag2 && passHmass) bpairs|=2;
         if (!passBtag1 && passHmass) bpairs|=4;
         if (passBtag2 && !passHmass) bpairs|=8;
         if (passBtag1 && !passBtag2 && !passHmass) bpairs|=16;
         if (!passBtag2 && !passHmass) bpairs|=32;
       }
     }
     int catFill=0;
     if (bpairs&1) catFill=7;
     else if (bpairs&2) catFill=6;
     if (bpairs&4 && bpairs&24 && !(bpairs&3)) catFill=5;
     unsigned int tmpb=bpairs&31;
     if (tmpb == 4) catFill=4;
     if ((tmpb == 8) || (tmpb == 24)) catFill=3;
     if (tmpb == 16) catFill=2;
     if (bpairs == 32) catFill=1;
     
     //Sort passJet according to DeepCSV
     for (unsigned int i=0;i<passJet.size();i++){
     int temp;
       for (unsigned int j=passJet.size()-1;j>i;j--){
         float DeepCSVTag_1=(*jetDeepCSVTags_b)[passJet.at(j)]+(*jetDeepCSVTags_bb)[passJet.at(j)];
         float DeepCSVTag_2=(*jetDeepCSVTags_b)[passJet.at(j-1)]+(*jetDeepCSVTags_bb)[passJet.at(j-1)];
         if (DeepCSVTag_1>DeepCSVTag_2){
           temp=passJet[j-1];
           passJet[j-1]=passJet[j];
           passJet[j]=temp;
         }
       }
     }
     double m_bb_deep=-1;
     bool passAK4DeepHiggsMass=false;
     Deep_selected=0; //Deep btag value of higgs candidate jets. 0-Nobtag, 1-1 loose btag, 2-2 loose btag
     for (unsigned int i=0;i<passJet.size();i++){
       for (unsigned int j=i+1;j<passJet.size();j++){
         TLorentzVector bjet1, bjet2;
         bjet1.SetPtEtaPhiE(jetSmearedPt[passJet.at(i)],(*jetEta)[passJet.at(i)],(*jetPhi)[passJet.at(i)],jetSmearedEn[passJet.at(i)]);
         bjet2.SetPtEtaPhiE(jetSmearedPt[passJet.at(j)],(*jetEta)[passJet.at(j)],(*jetPhi)[passJet.at(j)],jetSmearedEn[passJet.at(j)]);
         m_bb_deep=(bjet1+bjet2).M();
         if (m_bb_deep>70 && m_bb_deep<200) {
           float DeepCSVTag_1=(*jetDeepCSVTags_b)[passJet.at(i)]+(*jetDeepCSVTags_bb)[passJet.at(i)];
           float DeepCSVTag_2=(*jetDeepCSVTags_b)[passJet.at(j)]+(*jetDeepCSVTags_bb)[passJet.at(j)];
           if (DeepCSVTag_1>BtagDeepWP[0]) Deep_selected++;
           if (DeepCSVTag_2>BtagDeepWP[0]) Deep_selected++;
           passAK4DeepHiggsMass=true;
           break;
         }
       }
       if (passAK4DeepHiggsMass) break;
     }

     //Calculate dR between higgs candidate jets
     double drmin_ak4ak8=-1, drmax_ak4ak8=-1, dr_ak4ak4=-1;
     if (signalstudy) {
       double dr1 = deltaR((*jetPhi)[SelectedAK4Jet1],(*AK8JetPhi)[SelectedAK8Jet],(*jetEta)[SelectedAK4Jet1],(*AK8JetEta)[SelectedAK8Jet]);
       double dr2 = deltaR((*jetPhi)[SelectedAK4Jet2],(*AK8JetPhi)[SelectedAK8Jet],(*jetEta)[SelectedAK4Jet2],(*AK8JetEta)[SelectedAK8Jet]);
       drmin_ak4ak8 = (dr1 > dr2) ? dr2 : dr1;
       drmax_ak4ak8 = (dr1 > dr2) ? dr1 : dr2;
       dr_ak4ak4 = deltaR((*jetPhi)[SelectedAK4Jet1],(*jetPhi)[SelectedAK4Jet2],(*jetEta)[SelectedAK4Jet1],(*jetEta)[SelectedAK4Jet2]);
     }
     /*
     double high_plus=0, high_mult=0, good_mbb=0;
     for (int i=0;i<passJet.size();i++){
       if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[0]) passAK4Btag1=true;
       for (int j=i+1;j<passJet.size();j++){
         if ((*jetCSV2BJetTags)[passJet.at(j)]>BtagCSVWP[0]) passAK4Btag2=true;
         double plus=(*jetCSV2BJetTags)[passJet.at(i)]+(*jetCSV2BJetTags)[passJet.at(j)];
         double mult=(*jetCSV2BJetTags)[passJet.at(i)]*(*jetCSV2BJetTags)[passJet.at(j)];
         TLorentzVector bjet1, bjet2;
         bjet1.SetPtEtaPhiE(jetSmearedPt[passJet.at(i)],(*jetEta)[passJet.at(i)],(*jetPhi)[passJet.at(i)],jetSmearedEn[passJet.at(i)]);
         bjet2.SetPtEtaPhiE(jetSmearedPt[passJet.at(j)],(*jetEta)[passJet.at(j)],(*jetPhi)[passJet.at(j)],jetSmearedEn[passJet.at(j)]);
         m_bb=(bjet1+bjet2).M();
         //if (m_bb>70 && m_bb<200 && plus>high_plus) {
         if (m_bb>70 && m_bb<200 && mult>high_mult) {
           //high_plus=plus;
           high_mult=mult;
           good_mbb=m_bb;
           SelectedAK4Jet1=passJet.at(i);
           SelectedAK4Jet2=passJet.at(j);
           passAK4HiggsMass=true;
         }
       }
     }
     m_bb=good_mbb;
     */
     //NOT AK4 cut
     notAK4=true;
     if (passAK4HiggsMass && CSV_selected>=2) notAK4=false;

     //Calculate BTag SFs
     if (!isData && btag_file.size()>0) {
       //AK4
       if (!_fastSim) {
         CalcBtagSF(jetEta, jetSmearedPt, jetHadFlvr, passCSV, eff_b_CSV_L, eff_c_CSV_L, eff_l_CSV_L, eff_b_CSV_M, eff_c_CSV_M, eff_l_CSV_M, eff_b_CSV_T, eff_c_CSV_T, eff_l_CSV_T, reader_L, reader_M, reader_T, CSV_SF_L, CSV_SF_M, CSV_SF_T);
         CalcBtagSF(jetEta, jetSmearedPt, jetHadFlvr, passDeep, eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_deep_L, reader_deep_M, reader_deep_T, Deep_SF_L, Deep_SF_M, Deep_SF_T);
       }
       else {
         CalcBtagSF(jetEta, jetSmearedPt, jetHadFlvr, passCSV, eff_b_CSV_L, eff_c_CSV_L, eff_l_CSV_L, eff_b_CSV_M, eff_c_CSV_M, eff_l_CSV_M, eff_b_CSV_T, eff_c_CSV_T, eff_l_CSV_T, reader_L_fs, reader_M_fs, reader_T_fs, CSV_SF_L, CSV_SF_M, CSV_SF_T);
         CalcBtagSF(jetEta, jetSmearedPt, jetHadFlvr, passDeep, eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_deep_L_fs, reader_deep_M_fs, reader_deep_T_fs, Deep_SF_L, Deep_SF_M, Deep_SF_T);
       //AK8
         CalcBtagSF_AK8(AK8JetEta, AK8JetSmearedPt, AK8JetHadFlvr, passBDSV, eff_b_BDSV_L, eff_b_BDSV_M1, eff_b_BDSV_M2, eff_b_BDSV_T, BDSV_SF_L, BDSV_SF_M1, BDSV_SF_M2, BDSV_SF_T);
       }
     }
     //MC truth for signal study
     int iHiggs=-1, iPho=-1, ib1=-1, ib2=-1, iHjet1=-1, iHjet2=-1, iHAK8jet=-1;
     int nHiggs=0, nPho=0;
     int nBquark=0, nBjetlikequark=0, nBjets=0, nBjets_tagged[3]={0,0,0}, nBjets_ak8=0, nBjets_tagged_ak8[3]={0,0,0};
     if (signalstudy) {
     //Get Higgs->bb and photon mc index & # of b quarks
       for (int i=0;i<nMC;i++) {
         if ((*mcPID)[i]==25) {iHiggs=i; nHiggs++;}
         if ((*mcPID)[i]==22 && (*mcMomPID)[i]==1000023) {iPho=i; nPho++;}
         if ((*mcPID)[i]==5 && (*mcMomPID)[i]==25) ib1=i;
         if ((*mcPID)[i]==-5 && (*mcMomPID)[i]==25) ib2=i;
         if (abs((*mcPID)[i])==5 && (*mcStatus)[i]==71) nBquark++;
         if (abs((*mcPID)[i])==5 && (*mcStatus)[i]==71 && (*mcPt)[i]>30) nBjetlikequark++;
       }
       Hbb=false;
       if (nHiggs==1 && ib1!=-1 && (*mcPt)[ib1]>30 && abs((*mcEta)[ib1])<2.4 && ib2!=-1 && (*mcPt)[ib2]>30 && abs((*mcEta)[ib2])<2.4) Hbb=true;

       //Get b jets and jets with Higgs mother
       vector<int> ak4_hjets, ak8_hjets;
       for (auto i : passJet) {
         if ((*jetGenPartonMomID)[i]==25) ak4_hjets.push_back(i);
         if ((*jetHadFlvr)[i]==5) nBjets++;
         if ((*jetHadFlvr)[i]==5 && (*jetCSV2BJetTags)[i]>BtagCSVWP[0]) nBjets_tagged[0]++;
         if ((*jetHadFlvr)[i]==5 && (*jetCSV2BJetTags)[i]>BtagCSVWP[1]) nBjets_tagged[1]++;
         if ((*jetHadFlvr)[i]==5 && (*jetCSV2BJetTags)[i]>BtagCSVWP[2]) nBjets_tagged[2]++;
       }
       for (auto i : passAK8Jet) {
         if ((*AK8JetGenPartonMomID)[i]==25) ak8_hjets.push_back(i);
         if ((*AK8JetHadFlvr)[i]==5) nBjets_ak8++;
         if ((*AK8JetHadFlvr)[i]==5 && (*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[0]) nBjets_tagged_ak8[0]++;
         if ((*AK8JetHadFlvr)[i]==5 && (*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[1]) nBjets_tagged_ak8[1]++;
         if ((*AK8JetHadFlvr)[i]==5 && (*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[2]) nBjets_tagged_ak8[2]++;
       }
       if (ak4_hjets.size() ==1) iHjet1=ak4_hjets[0]; 
       if (ak4_hjets.size() > 1){
         double dr_min1=9999, dr_min2=9999;
         for (auto i : ak4_hjets) {
           double dR_b1=deltaR((*jetPhi)[i],(*mcPhi)[ib1],(*jetEta)[i],(*mcEta)[ib1]);
           double dR_b2=deltaR((*jetPhi)[i],(*mcPhi)[ib2],(*jetEta)[i],(*mcEta)[ib2]);
           if (dR_b1<dr_min1) {dr_min1=dR_b1; iHjet1=i;}
           if (dR_b2<dr_min2) {dr_min2=dR_b2; iHjet2=i;}
         }
         if (iHjet1==iHjet2) {
           double dR_b1=deltaR((*jetPhi)[iHjet1],(*mcPhi)[ib1],(*jetEta)[iHjet1],(*mcEta)[ib1]);
           double dR_b2=deltaR((*jetPhi)[iHjet2],(*mcPhi)[ib2],(*jetEta)[iHjet2],(*mcEta)[ib2]);
           int ib = (dR_b1<dR_b2) ? ib2 : ib1;
           double dr_min=9999;
           int initH=iHjet1;
           for (auto i : ak4_hjets) {
             if (i==initH) continue;
             double dR_b=deltaR((*jetPhi)[i],(*mcPhi)[ib],(*jetEta)[i],(*mcEta)[ib]);
             if (dR_b<dr_min) {dr_min=dR_b; (dR_b1<dR_b2) ? iHjet2=i : iHjet1=i;}
           }
         }
       }
       double dr_min=9999;
       for (auto i : ak8_hjets) {
         double dR=deltaR((*AK8JetPhi)[i],(*mcPhi)[iHiggs],(*AK8JetEta)[i],(*mcEta)[iHiggs]);
         if (dR<dr_min) {dr_min=dR; iHAK8jet=i;}
       }
     }
     //for efficiency
     if (_fastSim && !SignalScan) w*=0.5; //temporary solution to BR=0.5
     h_eff->Fill(0.,w);
     //cuts
     if (_cut_variable.size()>0) {if (!(Cut(ientry))) continue;}
     else {
       //if (!(HLTPho&128)) continue; //HLT_Photon175
       if (!_fastSim && !(HLTPho&4096)) continue; //HLT_Photon165_HE10
       h_cuts->Fill(0.,w);
       if (passPhoL.size()==0) continue;
       h_cuts->Fill(1,w);
       if ((*phoCalibEt)[nleadPhoL]<175) continue;
       h_cuts->Fill(2,w);
       if (passJet.size()<5) continue;
       h_cuts->Fill(3,w);
       if (MT<100) continue;
       h_cuts->Fill(4,w);
       if (ST<1300) continue;
       h_cuts->Fill(5,w);
       if (isData) if (metFilters!=1536) continue;
       if (!isData && !_fastSim) if (metFilters&94) continue;
       if (!isData && _fastSim) if (metFilters&86) continue;
       h_cuts->Fill(6,w);
       if (pfMET<100) continue;
       //if (pfMET<70 || pfMET>100) continue;
       h_cuts->Fill(7,w);
       if (bcounterCSV[1]<2) continue;
       if (!isData) w*=CSV_SF_L[0];
       //if (bcounterBDSV[2]==0) continue;
       //if (bcounterBDSV[1]==0 || bcounterBDSV[2]!=0) continue;
       h_cuts->Fill(8,w);
       if (!passHiggsMass) continue;
       h_cuts->Fill(9,w);

       /*
       //pfht300_met110 cuts
       if (!(HLTJet&4194304)) continue; //HLT_PFHT300_PFMET110_v
       if (HT_after<300) continue;
       h_cuts->Fill(0.,w);
       if (isData) if (metFilters!=1536) continue;
       if (!isData) if (metFilters&94) continue; //86 for FASTSIM!!
       if (pfMET<110) continue;
       h_cuts->Fill(1,w);
       if (MT<100) continue;
       h_cuts->Fill(2,w);
       if (ST<600) continue;
       h_cuts->Fill(3,w);
       if (passPhoL.size()==0) continue;
       h_cuts->Fill(4,w);
       double phoCut=150;
       if ((*phoCalibEt)[nleadPhoL]<phoCut) continue;
       h_cuts->Fill(5,w);
       if (bcounterCSV[1]<2) continue;
       h_cuts->Fill(6,w);
       */
     }

     //Filling histograms
     h_eff->Fill(1.,w);
     h_phoEtL->Fill((*phoCalibEt)[nleadPhoL],w);
     h_phoSCEtaL->Fill((*phoSCEta)[nleadPhoL],w);
     if (passPhoM.size()>0) {
       h_phoEtM->Fill((*phoCalibEt)[nleadPhoM],w);
       h_phoSCEtaM->Fill((*phoSCEta)[nleadPhoM],w);
     }
     if (passPhoT.size()>0){
       h_phoEtT->Fill((*phoCalibEt)[nleadPhoT],w);
       h_phoSCEtaT->Fill((*phoSCEta)[nleadPhoT],w);
     }
     h_nVtx->Fill(nVtx,w);
     h_nGoodVtx->Fill(nGoodVtx,w);
     if (!isData) h_nPU->Fill((*puTrue)[zbx],w);
     h_HT_before->Fill(HT_before,w);
     h_EMHT_before->Fill(EMHT_before,w);
     h_HT_after->Fill(HT_after,w);
     h_EMHT_after->Fill(EMHT_after,w);
     h_AK8HT_before->Fill(AK8HT_before,w);
     h_AK8EMHT_before->Fill(AK8EMHT_before,w);
     h_AK8HT_after->Fill(AK8HT_after,w);
     h_AK8EMHT_after->Fill(AK8EMHT_after,w);
     h_nAK8jets->Fill(passAK8Jet.size(),w);
     h_pfMET->Fill(pfMET,w);
     h_pfMETsumEt->Fill(pfMETsumEt,w);
     h_pfMETPhi->Fill(pfMETPhi,w);
     h_pfMETSig->Fill(pfMETSig,w);
     h_MET_AK8btag->Fill(pfMET,(*AK8JetpfBoostedDSVBTag)[SelectedAK8Jet],w);
     h_MET_AK4btag->Fill(pfMET,(*jetCSV2BJetTags)[SelectedAK4Jet1]+(*jetCSV2BJetTags)[SelectedAK4Jet2],w);
     h_ST->Fill(ST,w);
     h_ST_G->Fill(ST_G,w);
     h_MT->Fill(MT,w);
     h_nPho->Fill(passPhoL.size(),w);
     h_njets->Fill(passJet.size(),w);
     h_CSVbjetsL->Fill(bcounterCSV[1],w);
     h_CSVbjetsM->Fill(bcounterCSV[2],w);
     h_CSVbjetsT->Fill(bcounterCSV[3],w);
     h_cMVAbjetsL->Fill(bcountercMVA[1],w);
     h_cMVAbjetsM->Fill(bcountercMVA[2],w);
     h_cMVAbjetsT->Fill(bcountercMVA[3],w);
     h_BDSVbjetsL->Fill(bcounterBDSV[1],w);
     h_BDSVbjetsM->Fill(bcounterBDSV[2],w);
     h_BDSVbjetsT->Fill(bcounterBDSV[3],w);
     if (highCSV1!=-1) h_bjetCSV->Fill((*jetCSV2BJetTags)[highCSV1],w);
     if (highCSV2!=-1) h_bjetCSV2->Fill((*jetCSV2BJetTags)[highCSV2],w);
     if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) h_b1pb2CSV->Fill((*jetCSV2BJetTags)[SelectedAK4Jet1]+(*jetCSV2BJetTags)[SelectedAK4Jet2],w);
     if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) h_b1tb2CSV->Fill((*jetCSV2BJetTags)[SelectedAK4Jet1]*(*jetCSV2BJetTags)[SelectedAK4Jet2],w);
     if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) h_b1b2CSV->Fill((*jetCSV2BJetTags)[SelectedAK4Jet1],(*jetCSV2BJetTags)[SelectedAK4Jet2],w);
     if (SelectedAK4Jet1!=-1) h_selectbjetCSV->Fill((*jetCSV2BJetTags)[SelectedAK4Jet1],w);
     if (SelectedAK4Jet2!=-1) h_selectbjetCSV2->Fill((*jetCSV2BJetTags)[SelectedAK4Jet2],w);
     if (highcMVA1!=-1) h_bjetcMVA->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA1],w);
     if (highcMVA2!=-1) h_bjetcMVA2->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA2],w);
     if (leadpt_ak8!=-1) h_doubleB->Fill((*AK8JetpfBoostedDSVBTag)[leadpt_ak8],w);
     if (highBDSV!=-1) h_doubleB_highdB->Fill((*AK8JetpfBoostedDSVBTag)[highBDSV],w);
     if (passHiggsMass) h_doubleB_highdB_hmass->Fill((*AK8JetpfBoostedDSVBTag)[SelectedAK8Jet],w);
     for (auto i : passAK8Jet) h_AK8jetmass->Fill((*AK8JetMass)[i],w);
     h_nEle->Fill(passEleL.size(),w);
     h_nEleM->Fill(passEleM.size(),w);
     h_nEleT->Fill(passEleT.size(),w);
     h_nMu->Fill(passMuL.size(),w);
     h_nMuM->Fill(passMuM.size(),w);
     h_nMuT->Fill(passMuT.size(),w);
     h_nTau->Fill(passTauL.size(),w);
     h_nIso->Fill(passIso.size(),w);
     if (leadpt_ak4!=-1) h_jetpt->Fill(jetSmearedPt[leadpt_ak4],w);
     if (leadpt_ak8!=-1) h_AK8jetpt->Fill(AK8JetSmearedPt[leadpt_ak8],w);
     if (highBDSV!=-1) h_AK8bjetpt->Fill(AK8JetSmearedPt[highBDSV],w);
     if (SelectedAK8Jet!=-1 && passBtag) h_AK8bhjetpt->Fill(AK8JetSmearedPt[SelectedAK8Jet],w);
     if (leadpt_ak8!=-1) h_AK8ljetmass->Fill((*AK8JetMass)[leadpt_ak8],w);
     if (leadpt_ak8!=-1) h_AK8bjetmass->Fill((*AK8JetMass)[highBDSV],w);
     if (SelectedAK8Jet!=-1 && passBtag) h_AK8bhjetmass->Fill((*AK8JetMass)[SelectedAK8Jet],w);
     if (leadpt_ak8!=-1) h_AK8bPrunedjetmass->Fill((*AK8JetPrunedMass)[highBDSV],w);
     if (SelectedAK8Jet!=-1 && passBtag) h_AK8bhPrunedjetmass->Fill((*AK8JetPrunedMass)[SelectedAK8Jet],w);
     if (SelectedAK8Jet!=-1 && passBtag) h_AK8bhPrunedCorrjetmass->Fill((*AK8JetPrunedMassCorr)[SelectedAK8Jet],w);
     if (leadpt_ak8!=-1) h_AK8PrunedCorrjetmass->Fill((*AK8JetPrunedMassCorr)[highBDSV],w);
     if (leadpt_ak8!=-1) h_AK8SoftDropCorrjetmass->Fill((*AK8JetSoftDropMassCorr)[highBDSV],w);
     if (leadpt_ak8!=-1) h_AK8PUPPISDjetmass->Fill((*AK8puppiSDMassL2L3Corr)[highBDSV],w);
     if (leadpt_ak8!=-1) h_AK8puppitau1->Fill((*AK8puppiTau1)[highBDSV],w);
     if (leadpt_ak8!=-1) h_AK8puppitau2->Fill((*AK8puppiTau2)[highBDSV],w);
     if (leadpt_ak8!=-1) h_AK8puppitau3->Fill((*AK8puppiTau3)[highBDSV],w);
     if (leadpt_ak8!=-1) h_AK8puppitau2_tau1->Divide(h_AK8puppitau2,h_AK8puppitau1);
     if (leadpt_ak8!=-1) h_AK8puppitau3_tau2->Divide(h_AK8puppitau3,h_AK8puppitau2);
     if (dR_pho_AK8!=-1) h_dRphoAK8jet->Fill(dR_pho_AK8,w);
     if (SelectedAK8Jet!=-1 && passBtag) h_AK8PrunedCorrjetmass_select->Fill((*AK8JetPrunedMassCorr)[SelectedAK8Jet],w);
     if (SelectedAK8Jet!=-1) h_selectAK8bjetpt->Fill(AK8JetSmearedPt[SelectedAK8Jet],w);
     if (SelectedAK4Jet1!=-1) h_selectbjetpt->Fill(jetSmearedPt[SelectedAK4Jet1],w);
     if (SelectedAK4Jet2!=-1) h_selectbjetpt2->Fill(jetSmearedPt[SelectedAK4Jet2],w);
     if (SelectedAK8Jet!=-1) h_AK8PrunedCorrjetmass_withABCD->Fill((*AK8JetPrunedMassCorr)[SelectedAK8Jet],w);
     if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1 && passAK4Btag1 && passAK4Btag2)h_mbbjet_select->Fill(m_bb,w);
     if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1)h_mbbjet_withABCD->Fill(m_bb,w);
     if (SelectedAK8Jet!=-1) h_AK8tau1->Fill((*AK8Jet_tau1)[SelectedAK8Jet],w);
     if (SelectedAK8Jet!=-1) h_AK8tau2->Fill((*AK8Jet_tau2)[SelectedAK8Jet],w);
     if (SelectedAK8Jet!=-1) h_AK8tau3->Fill((*AK8Jet_tau3)[SelectedAK8Jet],w);
     if (SelectedAK8Jet!=-1) h_AK8tau2_tau1->Divide(h_AK8tau2,h_AK8tau1);
     if (SelectedAK8Jet!=-1) h_AK8tau3_tau2->Divide(h_AK8tau3,h_AK8tau2);
     if (SelectedAK8Jet!=-1) h_AK8mass_vs_pt->Fill((*AK8JetPrunedMassCorr)[SelectedAK8Jet],AK8JetSmearedPt[SelectedAK8Jet],w);
     if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) h_mbbjet_vs_pt1->Fill(m_bb,jetSmearedPt[SelectedAK4Jet1],w);
     if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) h_mbbjet_vs_pt2->Fill(m_bb,jetSmearedPt[SelectedAK4Jet2],w);
     for (auto i : passAK8Jet) {
       if ((*AK8JetPrunedMassCorr)[i]>70 && (*AK8JetPrunedMassCorr)[i]<200) h_AK8mass_all_vs_pt->Fill((*AK8JetPrunedMassCorr)[i],AK8JetSmearedPt[i],w);
     }
     for (unsigned int i=0;i<passJet.size();i++){
       for (unsigned int j=i+1;j<passJet.size();j++){
         TLorentzVector jet1, jet2;
         jet1.SetPtEtaPhiE(jetSmearedPt[passJet.at(i)],(*jetEta)[passJet.at(i)],(*jetPhi)[passJet.at(i)],jetSmearedEn[passJet.at(i)]);
         jet2.SetPtEtaPhiE(jetSmearedPt[passJet.at(j)],(*jetEta)[passJet.at(j)],(*jetPhi)[passJet.at(j)],jetSmearedEn[passJet.at(j)]);
         double temp_mbb=(jet1+jet2).M();
         if (temp_mbb>70 && temp_mbb<200) {
           h_mbbjet_comb_vs_pt1->Fill(temp_mbb,jetSmearedPt[passJet.at(i)],w);
           h_mbbjet_comb_vs_pt2->Fill(temp_mbb,jetSmearedPt[passJet.at(j)],w);
         }
       }
     }

       int AK8=0, AK4=0;
       double met = (pfMET<50) ? 1 : (pfMET<70) ? 2 : (pfMET<100) ? 3 : (pfMET<200) ? 4 : (pfMET<500) ? 5 : 6;
       double njet = (passJet.size()<6) ? 1 : (passJet.size()==6) ? 2 : 3;
       if (BDSV_selected==1) {AK8=1; if (!isData) w*=BDSV_SF_L[0];}
       if (BDSV_selected>=2) {AK8=2; if (!isData) w*=BDSV_SF_M1[0];}
       if (CSV_selected==1) {AK4=1; if (!isData) w*=CSV_SF_L[0];}
       if (CSV_selected>=2) {AK4=2; if (!isData) w*=CSV_SF_L[0]*CSV_SF_L[0];}
       //if (Deep_selected==1) {AK4=1; if (!isData) w*=Deep_SF_L[0];}
       //if (Deep_selected>=2) {AK4=2; if (!isData) w*=Deep_SF_L[0]*Deep_SF_L[0];}
       double ak4ak8=0;
       if (AK8==0 && AK4==0) ak4ak8=1;
       if (AK8==0 && AK4==1) ak4ak8=2;
       if (AK8==0 && AK4==2) ak4ak8=3;
       if (AK8==1 && AK4==0) ak4ak8=4;
       if (AK8==1 && AK4==1) ak4ak8=5;
       if (AK8==1 && AK4==2) ak4ak8=6;
       if (AK8==2 && AK4==0) ak4ak8=7;
       if (AK8==2 && AK4==1) ak4ak8=8;
       if (AK8==2 && AK4==2) ak4ak8=9;
       h_AK4_AK8->Fill(ak4ak8,w);
       (pfMET>1000) ? h_MET_AK4_AK8->Fill(999,AK4,AK8,w) : h_MET_AK4_AK8->Fill(pfMET,AK4,AK8,w);
       double sbFill[dim]={double(AK4),double(AK8),met,njet};
       hn_searchBins->Fill(sbFill,w);
       h_AK4_category->Fill(catFill,w);

       //AK4-AK8 searchBins
       int AK4AK8=0, VR=0, boost=0;
       //Signal Region
       if (BDSV_selected>0) {boost=1;AK4AK8=1; w*=BDSV_SF_L[0];}
       else {if (CSV_selected==1) {AK4AK8=1; w*=CSV_SF_L[0];} if (CSV_selected==2) {AK4AK8=2; w*=CSV_SF_L[0]*CSV_SF_L[0];}}
       //Control and Validation regions
       if (BDSV_selected==0 && CSV_selected==0) {
         if (bcounterBDSV[1]>0) {boost=1; VR=1; AK4AK8=1; w*=BDSV_SF_L[0];}
         else if (passHiggsMass) boost=1;
         if (!boost) {
           if (bcounterCSV[1]==1) {VR=1;AK4AK8=1; w*=CSV_SF_L[0];}
           if (bcounterCSV[1]>1) {VR=1;AK4AK8=2; w*=CSV_SF_L[0]*CSV_SF_L[0];}
           if (!passAK4HiggsMass && bcounterCSV[1]==0) boost=2;
         }
       }
       double sbFill_ak4ak8[dim_ak4]={double(VR),double(AK4AK8),met,njet};
       switch (boost) {
         case 0 : hn_AK4searchBins->Fill(sbFill_ak4ak8,w);
         break;
         case 1 : hn_AK8searchBins->Fill(sbFill_ak4ak8,w);
         break;
         case 2 : {hn_AK4searchBins->Fill(sbFill_ak4ak8,w); hn_AK8searchBins->Fill(sbFill_ak4ak8,w);}
         break;
       }

     //signalstudy histos fill
     if (signalstudy) {
       hs_gMET_Bquark->Fill(genMET,nBquark,w);
       hs_MET_Bquark->Fill(pfMET,nBquark,w);
       hs_gMET_Bjetlikequark->Fill(genMET,nBjetlikequark,w);
       hs_MET_Bjetlikequark->Fill(pfMET,nBjetlikequark,w);
       hs_MET_trueBjets->Fill(pfMET,nBjets,w);
       hs_MET_trueBjets_loose->Fill(pfMET,nBjets_tagged[0],w);
       hs_MET_trueBjets_medium->Fill(pfMET,nBjets_tagged[1],w);
       hs_MET_trueBjets_tight->Fill(pfMET,nBjets_tagged[2],w);
       hs_MET_trueBjets_AK8->Fill(pfMET,nBjets_ak8,w);
       hs_MET_trueBjets_loose_AK8->Fill(pfMET,nBjets_tagged_ak8[0],w);
       hs_MET_trueBjets_medium_AK8->Fill(pfMET,nBjets_tagged_ak8[1],w);
       hs_MET_trueBjets_tight_AK8->Fill(pfMET,nBjets_tagged_ak8[2],w);
       if (iHiggs!=-1) hs_Hpt->Fill((*mcPt)[iHiggs]);
       if (iPho!=-1) hs_PhoEt->Fill((*mcEt)[iPho]);
       if (iHAK8jet!=-1) hs_AK8Hmass->Fill((*AK8JetPrunedMassCorr)[iHAK8jet]);
       if (iHjet1!=-1 && iHjet2!=-1) {
         TLorentzVector jet1, jet2;
         jet1.SetPtEtaPhiE(jetSmearedPt[iHjet1],(*jetEta)[iHjet1],(*jetPhi)[iHjet1],jetSmearedEn[iHjet1]);
         jet2.SetPtEtaPhiE(jetSmearedPt[iHjet2],(*jetEta)[iHjet2],(*jetPhi)[iHjet2],jetSmearedEn[iHjet2]);
         double temp_mbb=(jet1+jet2).M();
         hs_AK4Hmass->Fill(temp_mbb);
       }
       int AK8=0 ,AK4=0;
       if (BDSV_selected==1) AK8=1;
       if (BDSV_selected>=2) AK8=2;
       if (CSV_selected==1) AK4=1;
       if (CSV_selected>=2) AK4=2;
       if (AK8==1 && AK4==1) {
         hs_drmin_AK4AK8[0]->Fill(drmin_ak4ak8,w);
         hs_drmax_AK4AK8[0]->Fill(drmax_ak4ak8,w);
         hs_dr_AK4AK4[0]->Fill(dr_ak4ak4,w);
       }
       if (AK8==1 && AK4==2) {
         hs_drmin_AK4AK8[1]->Fill(drmin_ak4ak8,w);
         hs_drmax_AK4AK8[1]->Fill(drmax_ak4ak8,w);
         hs_dr_AK4AK4[1]->Fill(dr_ak4ak4,w);
       }
       if (AK8==2 && AK4==1) {
         hs_drmin_AK4AK8[2]->Fill(drmin_ak4ak8,w);
         hs_drmax_AK4AK8[2]->Fill(drmax_ak4ak8,w);
         hs_dr_AK4AK4[2]->Fill(dr_ak4ak4,w);
       }
       if (AK8==2 && AK4==2) {
         hs_drmin_AK4AK8[3]->Fill(drmin_ak4ak8,w);
         hs_drmax_AK4AK8[3]->Fill(drmax_ak4ak8,w);
         hs_dr_AK4AK4[3]->Fill(dr_ak4ak4,w);
       }
       if (iHAK8jet!=-1 && iHjet1!=-1 && iHjet2!=-1){
         if (AK8==0 && AK4==0) hs_AK4_AK8_true->Fill(1,w);
         if (AK8==0 && AK4==1) hs_AK4_AK8_true->Fill(2,w);
         if (AK8==0 && AK4==2) hs_AK4_AK8_true->Fill(3,w);
         if (AK8==1 && AK4==0) hs_AK4_AK8_true->Fill(4,w);
         if (AK8==1 && AK4==1) hs_AK4_AK8_true->Fill(5,w);
         if (AK8==1 && AK4==2) hs_AK4_AK8_true->Fill(6,w);
         if (AK8==2 && AK4==0) hs_AK4_AK8_true->Fill(7,w);
         if (AK8==2 && AK4==1) hs_AK4_AK8_true->Fill(8,w);
         if (AK8==2 && AK4==2) hs_AK4_AK8_true->Fill(9,w);
       }
       if (nHiggs==1 && ib1!=-1 && ib2!=-1) {
         hs_true_HiggsAK8Jet->Fill(1.,w);
         hs_true_HiggsAK4Jet->Fill(1.,w);
         if (iHAK8jet!=-1) {
           hs_true_HiggsAK8Jet->Fill(2.,w);
           if (iHAK8jet==passAK8Jet[0]) hs_true_HiggsAK8Jet->Fill(3.,w);
           if (iHAK8jet==SelectedAK8Jet) hs_true_HiggsAK8Jet->Fill(4.,w);
           if (iHAK8jet==SelectedAK8Jet && passHiggsMass) hs_true_HiggsAK8Jet->Fill(5.,w);
         }
         if (iHjet1!=-1 && iHjet2==-1) {
           hs_true_HiggsAK4Jet->Fill(2.,w);
           if (iHjet1==passJet[0]) hs_true_HiggsAK4Jet->Fill(3.,w);
           if (iHjet1==SelectedAK4Jet1) hs_true_HiggsAK4Jet->Fill(4.,w);
           if (iHjet1==SelectedAK4Jet1 && passAK4HiggsMass) hs_true_HiggsAK4Jet->Fill(5.,w);
         }
         if (iHjet1!=-1 && iHjet2!=-1) {
           hs_true_HiggsAK4Jet->Fill(6.,w);
           if ((iHjet1==passJet[0] && iHjet2==passJet[1]) || (iHjet1==passJet[1] && iHjet2==passJet[0])) hs_true_HiggsAK4Jet->Fill(7.,w);
           if ((iHjet1==SelectedAK4Jet1 && iHjet2==SelectedAK4Jet2) || (iHjet1==SelectedAK4Jet2 && iHjet2==SelectedAK4Jet1)) {
             hs_true_HiggsAK4Jet->Fill(8.,w);
             if (passAK4HiggsMass) hs_true_HiggsAK4Jet->Fill(9.,w);
           }
         }
       }
       hs_ak4_selected->Fill(ith_jet,jth_jet,w);
       hs_true_ak4bjets->Fill(nBjets,w);
     }
     //Filling for signal scan
     if (SignalScan) {
       m_eff[mass_pair]->Fill(1.,w);
       m_phoEtL[mass_pair]->Fill((*phoCalibEt)[nleadPhoL],w);
       m_phoSCEtaL[mass_pair]->Fill((*phoSCEta)[nleadPhoL],w);
       if (passPhoM.size()>0) {
         m_phoEtM[mass_pair]->Fill((*phoCalibEt)[nleadPhoM],w);
         m_phoSCEtaM[mass_pair]->Fill((*phoSCEta)[nleadPhoM],w);
       }
       if (passPhoT.size()>0){
         m_phoEtT[mass_pair]->Fill((*phoCalibEt)[nleadPhoT],w);
         m_phoSCEtaT[mass_pair]->Fill((*phoSCEta)[nleadPhoT],w);
       }
       m_nVtx[mass_pair]->Fill(nVtx,w);
       m_nGoodVtx[mass_pair]->Fill(nGoodVtx,w);
       if (!isData) m_nPU[mass_pair]->Fill((*puTrue)[zbx],w);
       m_HT_before[mass_pair]->Fill(HT_before,w);
       m_EMHT_before[mass_pair]->Fill(EMHT_before,w);
       m_HT_after[mass_pair]->Fill(HT_after,w);
       m_EMHT_after[mass_pair]->Fill(EMHT_after,w);
       m_AK8HT_before[mass_pair]->Fill(AK8HT_before,w);
       m_AK8EMHT_before[mass_pair]->Fill(AK8EMHT_before,w);
       m_AK8HT_after[mass_pair]->Fill(AK8HT_after,w);
       m_AK8EMHT_after[mass_pair]->Fill(AK8EMHT_after,w);
       m_nAK8jets[mass_pair]->Fill(passAK8Jet.size(),w);
       m_pfMET[mass_pair]->Fill(pfMET,w);
       m_pfMETsumEt[mass_pair]->Fill(pfMETsumEt,w);
       m_pfMETPhi[mass_pair]->Fill(pfMETPhi,w);
       m_pfMETSig[mass_pair]->Fill(pfMETSig,w);
       m_MET_AK8btag[mass_pair]->Fill(pfMET,(*AK8JetpfBoostedDSVBTag)[SelectedAK8Jet],w);
       m_MET_AK4btag[mass_pair]->Fill(pfMET,(*jetCSV2BJetTags)[SelectedAK4Jet1]+(*jetCSV2BJetTags)[SelectedAK4Jet2],w);
       m_ST[mass_pair]->Fill(ST,w);
       m_ST_G[mass_pair]->Fill(ST_G,w);
       m_MT[mass_pair]->Fill(MT,w);
       m_nPho[mass_pair]->Fill(passPhoL.size(),w);
       m_njets[mass_pair]->Fill(passJet.size(),w);
       m_CSVbjetsL[mass_pair]->Fill(bcounterCSV[1],w);
       m_CSVbjetsM[mass_pair]->Fill(bcounterCSV[2],w);
       m_CSVbjetsT[mass_pair]->Fill(bcounterCSV[3],w);
       m_cMVAbjetsL[mass_pair]->Fill(bcountercMVA[1],w);
       m_cMVAbjetsM[mass_pair]->Fill(bcountercMVA[2],w);
       m_cMVAbjetsT[mass_pair]->Fill(bcountercMVA[3],w);
       m_BDSVbjetsL[mass_pair]->Fill(bcounterBDSV[1],w);
       m_BDSVbjetsM[mass_pair]->Fill(bcounterBDSV[2],w);
       m_BDSVbjetsT[mass_pair]->Fill(bcounterBDSV[3],w);
       if (highCSV1!=-1) m_bjetCSV[mass_pair]->Fill((*jetCSV2BJetTags)[highCSV1],w);
       if (highCSV2!=-1) m_bjetCSV2[mass_pair]->Fill((*jetCSV2BJetTags)[highCSV2],w);
       if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) m_b1pb2CSV[mass_pair]->Fill((*jetCSV2BJetTags)[SelectedAK4Jet1]+(*jetCSV2BJetTags)[SelectedAK4Jet2],w);
       if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) m_b1tb2CSV[mass_pair]->Fill((*jetCSV2BJetTags)[SelectedAK4Jet1]*(*jetCSV2BJetTags)[SelectedAK4Jet2],w);
       if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) m_b1b2CSV[mass_pair]->Fill((*jetCSV2BJetTags)[SelectedAK4Jet1],(*jetCSV2BJetTags)[SelectedAK4Jet2],w);
       if (SelectedAK4Jet1!=-1) m_selectbjetCSV[mass_pair]->Fill((*jetCSV2BJetTags)[SelectedAK4Jet1],w);
       if (SelectedAK4Jet2!=-1) m_selectbjetCSV2[mass_pair]->Fill((*jetCSV2BJetTags)[SelectedAK4Jet2],w);
       if (highcMVA1!=-1) m_bjetcMVA[mass_pair]->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA1],w);
       if (highcMVA2!=-1) m_bjetcMVA2[mass_pair]->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA2],w);
       if (leadpt_ak8!=-1) m_doubleB[mass_pair]->Fill((*AK8JetpfBoostedDSVBTag)[leadpt_ak8],w);
       if (highBDSV!=-1) m_doubleB_highdB[mass_pair]->Fill((*AK8JetpfBoostedDSVBTag)[highBDSV],w);
       if (passHiggsMass) m_doubleB_highdB_hmass[mass_pair]->Fill((*AK8JetpfBoostedDSVBTag)[SelectedAK8Jet],w);
       for (auto i : passAK8Jet) m_AK8jetmass[mass_pair]->Fill((*AK8JetMass)[i],w);
       m_nEle[mass_pair]->Fill(passEleL.size(),w);
       m_nEleM[mass_pair]->Fill(passEleM.size(),w);
       m_nEleT[mass_pair]->Fill(passEleT.size(),w);
       m_nMu[mass_pair]->Fill(passMuL.size(),w);
       m_nMuM[mass_pair]->Fill(passMuM.size(),w);
       m_nMuT[mass_pair]->Fill(passMuT.size(),w);
       m_nTau[mass_pair]->Fill(passTauL.size(),w);
       m_nIso[mass_pair]->Fill(passIso.size(),w);
       if (leadpt_ak4!=-1) m_jetpt[mass_pair]->Fill(jetSmearedPt[leadpt_ak4],w);
       if (leadpt_ak8!=-1) m_AK8jetpt[mass_pair]->Fill(AK8JetSmearedPt[leadpt_ak8],w);
       if (highBDSV!=-1) m_AK8bjetpt[mass_pair]->Fill(AK8JetSmearedPt[highBDSV],w);
       if (SelectedAK8Jet!=-1 && passBtag) m_AK8bhjetpt[mass_pair]->Fill(AK8JetSmearedPt[SelectedAK8Jet],w);
       if (leadpt_ak8!=-1) m_AK8ljetmass[mass_pair]->Fill((*AK8JetMass)[leadpt_ak8],w);
       if (leadpt_ak8!=-1) m_AK8bjetmass[mass_pair]->Fill((*AK8JetMass)[highBDSV],w);
       if (SelectedAK8Jet!=-1 && passBtag) m_AK8bhjetmass[mass_pair]->Fill((*AK8JetMass)[SelectedAK8Jet],w);
       if (leadpt_ak8!=-1) m_AK8bPrunedjetmass[mass_pair]->Fill((*AK8JetPrunedMass)[highBDSV],w);
       if (SelectedAK8Jet!=-1 && passBtag) m_AK8bhPrunedjetmass[mass_pair]->Fill((*AK8JetPrunedMass)[SelectedAK8Jet],w);
       if (SelectedAK8Jet!=-1 && passBtag) m_AK8bhPrunedCorrjetmass[mass_pair]->Fill((*AK8JetPrunedMassCorr)[SelectedAK8Jet],w);
       if (dR_pho_AK8!=-1) m_dRphoAK8jet[mass_pair]->Fill(dR_pho_AK8,w);
       if (SelectedAK8Jet!=-1 && passBtag) m_AK8PrunedCorrjetmass_select[mass_pair]->Fill((*AK8JetPrunedMassCorr)[SelectedAK8Jet],w);
       if (leadpt_ak8!=-1) m_AK8PrunedCorrjetmass[mass_pair]->Fill((*AK8JetPrunedMassCorr)[highBDSV],w);
       if (leadpt_ak8!=-1) m_AK8SoftDropCorrjetmass[mass_pair]->Fill((*AK8JetSoftDropMassCorr)[highBDSV],w);
       if (leadpt_ak8!=-1) m_AK8PUPPISDjetmass[mass_pair]->Fill((*AK8puppiSDMassL2L3Corr)[highBDSV],w);
       if (leadpt_ak8!=-1) m_AK8puppitau1[mass_pair]->Fill((*AK8puppiTau1)[highBDSV],w);
       if (leadpt_ak8!=-1) m_AK8puppitau2[mass_pair]->Fill((*AK8puppiTau2)[highBDSV],w);
       if (leadpt_ak8!=-1) m_AK8puppitau3[mass_pair]->Fill((*AK8puppiTau3)[highBDSV],w);
       if (leadpt_ak8!=-1) m_AK8puppitau2_tau1[mass_pair]->Divide(h_AK8puppitau2,h_AK8puppitau1);
       if (leadpt_ak8!=-1) m_AK8puppitau3_tau2[mass_pair]->Divide(h_AK8puppitau3,h_AK8puppitau2);
       if (SelectedAK8Jet!=-1) m_selectAK8bjetpt[mass_pair]->Fill(AK8JetSmearedPt[SelectedAK8Jet],w);
       if (SelectedAK4Jet1!=-1) m_selectbjetpt[mass_pair]->Fill(jetSmearedPt[SelectedAK4Jet1],w);
       if (SelectedAK4Jet2!=-1) m_selectbjetpt2[mass_pair]->Fill(jetSmearedPt[SelectedAK4Jet2],w);
       if (SelectedAK8Jet!=-1) m_AK8PrunedCorrjetmass_withABCD[mass_pair]->Fill((*AK8JetPrunedMassCorr)[SelectedAK8Jet],w);
       if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1 && passAK4Btag1 && passAK4Btag2)m_mbbjet_select[mass_pair]->Fill(m_bb,w);
       if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1)m_mbbjet_withABCD[mass_pair]->Fill(m_bb,w);
       if (SelectedAK8Jet!=-1) m_AK8tau1[mass_pair]->Fill((*AK8Jet_tau1)[SelectedAK8Jet],w);
       if (SelectedAK8Jet!=-1) m_AK8tau2[mass_pair]->Fill((*AK8Jet_tau2)[SelectedAK8Jet],w);
       if (SelectedAK8Jet!=-1) m_AK8tau3[mass_pair]->Fill((*AK8Jet_tau3)[SelectedAK8Jet],w);
       if (SelectedAK8Jet!=-1) m_AK8tau2_tau1[mass_pair]->Divide(m_AK8tau2[mass_pair],m_AK8tau1[mass_pair]);
       if (SelectedAK8Jet!=-1) m_AK8tau3_tau2[mass_pair]->Divide(m_AK8tau3[mass_pair],m_AK8tau2[mass_pair]);
       if (SelectedAK8Jet!=-1) m_AK8mass_vs_pt[mass_pair]->Fill((*AK8JetPrunedMassCorr)[SelectedAK8Jet],AK8JetSmearedPt[SelectedAK8Jet],w);
       if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) m_mbbjet_vs_pt1[mass_pair]->Fill(m_bb,jetSmearedPt[SelectedAK4Jet1],w);
       if (SelectedAK4Jet1!=-1 && SelectedAK4Jet2!=-1) m_mbbjet_vs_pt2[mass_pair]->Fill(m_bb,jetSmearedPt[SelectedAK4Jet2],w);
       for (auto i : passAK8Jet) {
         if ((*AK8JetPrunedMassCorr)[i]>70 && (*AK8JetPrunedMassCorr)[i]<200) m_AK8mass_all_vs_pt[mass_pair]->Fill((*AK8JetPrunedMassCorr)[i],AK8JetSmearedPt[i],w);
       }
       for (unsigned int i=0;i<passJet.size();i++){
         for (unsigned int j=i+1;j<passJet.size();j++){
           TLorentzVector jet1, jet2;
           jet1.SetPtEtaPhiE(jetSmearedPt[passJet.at(i)],(*jetEta)[passJet.at(i)],(*jetPhi)[passJet.at(i)],jetSmearedEn[passJet.at(i)]);
           jet2.SetPtEtaPhiE(jetSmearedPt[passJet.at(j)],(*jetEta)[passJet.at(j)],(*jetPhi)[passJet.at(j)],jetSmearedEn[passJet.at(j)]);
           double temp_mbb=(jet1+jet2).M();
           if (temp_mbb>70 && temp_mbb<200) {
             m_mbbjet_comb_vs_pt1[mass_pair]->Fill(temp_mbb,jetSmearedPt[passJet.at(i)],w);
             m_mbbjet_comb_vs_pt2[mass_pair]->Fill(temp_mbb,jetSmearedPt[passJet.at(j)],w);
           }
         }
       }
       m_AK4_AK8[mass_pair]->Fill(ak4ak8,w);
       m_AK4_category[mass_pair]->Fill(catFill,w);
       mn_searchBins[mass_pair]->Fill(sbFill,w);
       switch (boost) {
         case 0 : mn_AK4searchBins[mass_pair]->Fill(sbFill_ak4ak8,w);
         break;
         case 1 : mn_AK8searchBins[mass_pair]->Fill(sbFill_ak4ak8,w);
         break;
         case 2 : {mn_AK4searchBins[mass_pair]->Fill(sbFill_ak4ak8,w); mn_AK8searchBins[mass_pair]->Fill(sbFill_ak4ak8,w);}
         break;
       }
       if (signalstudy) {
         m_ak4_selected[mass_pair]->Fill(ith_jet,jth_jet,w);
         m_true_ak4bjets[mass_pair]->Fill(nBjets,w);
         if (ak4ak8==1) {
           bool passak4btag = (*jetCSV2BJetTags)[passJet.at(0)]>BtagCSVWP[0];
           bool passak8btag=0;
           if (!passAK4HiggsMass && passak4btag) m_whyNoAK4Higgs[mass_pair]->Fill(1,w);
           if (passAK4HiggsMass && !passak4btag) m_whyNoAK4Higgs[mass_pair]->Fill(2,w);
           if (!passAK4HiggsMass && !passak4btag) m_whyNoAK4Higgs[mass_pair]->Fill(3,w);
           if (passAK8Jet.size()==0) m_whyNoAK8Higgs[mass_pair]->Fill(1,w);
           else {passak8btag = (*AK8JetpfBoostedDSVBTag)[passAK8Jet.at(0)]>BtagBDSVWP[0];
             if (!passHiggsMass && passak8btag) m_whyNoAK8Higgs[mass_pair]->Fill(2,w);
             if (passHiggsMass && !passak8btag) m_whyNoAK8Higgs[mass_pair]->Fill(3,w);
             if (!passHiggsMass && !passak8btag) m_whyNoAK8Higgs[mass_pair]->Fill(4,w);
           }
         }
         if (iHiggs!=-1) m_Hpt[mass_pair]->Fill((*mcPt)[iHiggs]);
         if (iPho!=-1) m_PhoEt[mass_pair]->Fill((*mcEt)[iPho]);
         if (iHAK8jet!=-1) m_AK8Hmass[mass_pair]->Fill((*AK8JetPrunedMassCorr)[iHAK8jet]);
         if (iHjet1!=-1 && iHjet2!=-1) {
           TLorentzVector jet1, jet2;
           jet1.SetPtEtaPhiE(jetSmearedPt[iHjet1],(*jetEta)[iHjet1],(*jetPhi)[iHjet1],jetSmearedEn[iHjet1]);
           jet2.SetPtEtaPhiE(jetSmearedPt[iHjet2],(*jetEta)[iHjet2],(*jetPhi)[iHjet2],jetSmearedEn[iHjet2]);
           double temp_mbb=(jet1+jet2).M();
           m_AK4Hmass[mass_pair]->Fill(temp_mbb);
         }
         int AK8=0 ,AK4=0;
         if (BDSV_selected==1) AK8=1;
         if (BDSV_selected>=2) AK8=2;
         if (CSV_selected==1) AK4=1;
         if (CSV_selected>=2) AK4=2;
         if (iHAK8jet!=-1 && iHjet1!=-1 && iHjet2!=-1){
           if (AK8==0 && AK4==0) m_AK4_AK8_true[mass_pair]->Fill(1,w);
           if (AK8==0 && AK4==1) m_AK4_AK8_true[mass_pair]->Fill(2,w);
           if (AK8==0 && AK4==2) m_AK4_AK8_true[mass_pair]->Fill(3,w);
           if (AK8==1 && AK4==0) m_AK4_AK8_true[mass_pair]->Fill(4,w);
           if (AK8==1 && AK4==1) m_AK4_AK8_true[mass_pair]->Fill(5,w);
           if (AK8==1 && AK4==2) m_AK4_AK8_true[mass_pair]->Fill(6,w);
           if (AK8==2 && AK4==0) m_AK4_AK8_true[mass_pair]->Fill(7,w);
           if (AK8==2 && AK4==1) m_AK4_AK8_true[mass_pair]->Fill(8,w);
           if (AK8==2 && AK4==2) m_AK4_AK8_true[mass_pair]->Fill(9,w);
         }
       if (nHiggs==1 && ib1!=-1 && ib2!=-1) {
         m_true_HiggsAK8Jet[mass_pair]->Fill(1.,w);
         m_true_HiggsAK4Jet[mass_pair]->Fill(1.,w);
         if (iHAK8jet!=-1) {
           m_true_HiggsAK8Jet[mass_pair]->Fill(2.,w);
           if (iHAK8jet==SelectedAK8Jet) m_true_HiggsAK8Jet[mass_pair]->Fill(3.,w);
           if (iHAK8jet==SelectedAK8Jet && passHiggsMass) m_true_HiggsAK8Jet[mass_pair]->Fill(4.,w);
         }
         if (iHjet1!=-1 && iHjet2==-1) {
           m_true_HiggsAK4Jet[mass_pair]->Fill(2.,w);
           if (iHjet1==SelectedAK4Jet1) m_true_HiggsAK4Jet[mass_pair]->Fill(3.,w);
           if (iHjet1==SelectedAK4Jet1 && passAK4HiggsMass) m_true_HiggsAK4Jet[mass_pair]->Fill(4.,w);
         }
         if (iHjet1!=-1 && iHjet2!=-1) {
           m_true_HiggsAK4Jet[mass_pair]->Fill(5.,w);
           if ((iHjet1==SelectedAK4Jet1 && iHjet2==SelectedAK4Jet2) || (iHjet1==SelectedAK4Jet2 && iHjet2==SelectedAK4Jet1)) {
             m_true_HiggsAK4Jet[mass_pair]->Fill(6.,w);
             if (passAK4HiggsMass) m_true_HiggsAK4Jet[mass_pair]->Fill(7.,w);
           }
         }
       }
       }
     }
     }
   for (unsigned int i=1;i<nsbins+1;i++) {
     h_searchBins->SetBinContent(i,hn_searchBins->GetBinContent(i));
     h_searchBins->SetBinError(i,hn_searchBins->GetBinError(i));
     h_AK4searchBins->SetBinContent(i,hn_AK4searchBins->GetBinContent(i));
     h_AK4searchBins->SetBinError(i,hn_AK4searchBins->GetBinError(i));
     h_AK8searchBins->SetBinContent(i,hn_AK8searchBins->GetBinContent(i));
     h_AK8searchBins->SetBinError(i,hn_AK8searchBins->GetBinError(i));
   }
   if (SignalScan) {
     for (unsigned int i=0;i<GridX.size();i++ ) {	
       std::pair<int,int> MassPair(GridX[i],GridY[i]);
       for (unsigned int i=1;i<nsbins+1;i++) {
         m_searchBins[MassPair]->SetBinContent(i,mn_searchBins[MassPair]->GetBinContent(i));
         m_searchBins[MassPair]->SetBinError(i,mn_searchBins[MassPair]->GetBinError(i));
         m_AK4searchBins[MassPair]->SetBinContent(i,mn_AK4searchBins[MassPair]->GetBinContent(i));
         m_AK4searchBins[MassPair]->SetBinError(i,mn_AK4searchBins[MassPair]->GetBinError(i));
         m_AK8searchBins[MassPair]->SetBinContent(i,mn_AK8searchBins[MassPair]->GetBinContent(i));
         m_AK8searchBins[MassPair]->SetBinError(i,mn_AK8searchBins[MassPair]->GetBinError(i));
       }
     }
   }
   cout<<"Saving histograms..."<<endl;
   f->Write();
   gROOT->GetListOfFiles()->Remove(f);
   f->Close();
   time.Stop("time");
   if (!is_quiet) std::cout<<"CPU time = "<<time.GetCpuTime("time")<<", Real time = "<<time.GetRealTime("time")<<std::endl;
   if (CountSignal) {
     ofstream counttxt;
     counttxt.open ("CountSignal.txt");
     bool newg=true;
     for (auto i : signal_events) {
       if (newg) counttxt<<"  if (a=="<<i.first.first<<") {\n    switch (b) {"<<endl;
       newg=false;
       counttxt<<"      case "<<i.first.second<<" : return "<<i.second<<";"<<endl;
       if (i.first.first==i.first.second) {newg=true; counttxt<<"    }\n  }"<<endl;}
     }
   }
}
