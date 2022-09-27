#define Analyzer_cxx
#include "Analyzer.h"
#include "whichGridpoint.h"
#include "SignalScanHistograms.h"
#include "cross_sections.h"
#include <bitset>
#include <algorithm>
#include <TKey.h>
#include <TH2.h>
#include <THn.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <cstdlib>

using namespace correction;

int main(int argc, char* argv[]){
  bool is_i=0, is_o=0, is_b=0, is_x=0, is_y=0, is_f=0, is_F=0, is_h=0, is_c=0, is_cuts=0, is_quiet=0, is_signalscan=0, is_signalstudy=0, is_countSignal=0;
  bool is_t=0, is_l=0, is_syst=0, is_debug=0, is_A=0;
  bool inputs=0, cuts=0, syst=0, lept=0;
  int FR=0, tr=0, ABCD=0;
  string year;
  double xsec=0;
  string output, bname;
  vector<string> inputfiles, v_cuts, cut_variable, cut_operator, v_syst, v_lept;
  vector<double> cut_value;
  map<string, int> systematics;
  map<string, double> leptonpts;
  for(int i=1; i<argc; i++) {
    std::string arg = argv[i];
    // Check existence of an option
    if (arg[0]=='-' && arg.size()==2) {
      is_i=0; is_cuts=0; is_syst=0, is_l=0;
      if (arg[1]=='i') is_i=1;
      else if (arg[1]=='o') is_o=1;
      else if (arg[1]=='b') is_b=1;
      else if (arg[1]=='x') is_x=1;
      else if (arg[1]=='y') is_y=1;
      else if (arg[1]=='f') is_f=1;
      else if (arg[1]=='F') is_F=1;
      else if (arg[1]=='h') is_h=1; 
      else if (arg[1]=='c') is_c=1; 
      else if (arg[1]=='q') is_quiet=1; 
      else if (arg[1]=='S') is_signalscan=1; 
      else if (arg[1]=='s') is_signalstudy=1;
      else if (arg[1]=='C') is_countSignal=1; 
      else if (arg[1]=='t') is_t=1; 
      else if (arg[1]=='d') is_debug=1; 
      else if (arg[1]=='A') is_A=1; 
      else {cout<<"ERROR! Unknown option '-"<<arg[1]<<"' Exiting..."<<std::endl; return 0;}
    }
    else if (arg=="--syst") {is_i=0;is_syst=1;}
    else if (arg=="--cuts") {is_i=0;is_cuts=1;}
    else if (arg=="--lept") {is_i=0;is_l=1;}
    //Print out help
    if (is_h) {PrintHelp();return 1;}
    //Print out cuts
    if (is_c) {PrintCuts();return 1;}
    // Check second argument after option
    if (inputs && is_i) inputfiles.push_back(arg);
    if (is_o) {output=argv[i+1]; is_o=0;}
    if (is_b) {bname=argv[i+1]; is_b=0;}
    if (is_x) {xsec=stod(argv[i+1]); is_x=0;}
    if (is_y) {year=argv[i+1]; is_y=0;}
    if (is_F) {FR=atoi(argv[i+1]); is_F=0;}
    if (is_t) {(atoi(argv[i+1])==0) ? tr=1000 : tr=atoi(argv[i+1]); is_t=0;}
    if (is_A) {(atoi(argv[i+1])==0) ? ABCD=200 : ABCD=atoi(argv[i+1]); is_A=0;}
    if (lept && arg[0]=='-') is_l=0;
    if (cuts && arg[0]=='-') is_cuts=0;
    if (syst && arg[0]=='-') is_syst=0;
    if (cuts && is_cuts) v_cuts.push_back(arg);
    if (syst && is_syst) v_syst.push_back(arg);
    if (lept && is_l) v_lept.push_back(arg);
    if (is_i) inputs=1;
    if (is_cuts) cuts=1;
    if (is_syst) syst=1;
    if (is_l) lept=1;
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
  
  //Fill systematics variables
  if (v_syst.size()%2 != 0) {cout<<"Wrong number of --syst input! Exiting..."<<endl; return 0;}
  else {
    string stemp; int itemp;
    for (unsigned int i=0;i<v_syst.size();i++) {
      if ((i+1)%2 ==1) stemp=v_syst[i];
      if ((i+1)%2 ==0) itemp=stoi(v_syst[i]);
      if (i!=0 && (i+1)%2 ==0) systematics.insert(pair<string,int>(stemp,itemp));
    }
  }
  
  //Fill leptonic pt variables
  if (v_lept.size()%2 != 0) {cout<<"Wrong number of --lept input! Exiting..."<<endl; return 0;}
  else {
    string stemp; double dtemp;
    for (unsigned int i=0;i<v_lept.size();i++) {
      if ((i+1)%2 ==1) stemp=v_lept[i];
      if ((i+1)%2 ==0) dtemp=stof(v_lept[i]);
      if (i!=0 && (i+1)%2 ==0) leptonpts.insert(pair<string,double>(stemp,dtemp));
    }
  }

  if (is_debug) cout<<"Running in debugging mode"<<endl;
  if (!is_quiet){
    if (!output.empty()) cout<<"Output name: "<<output<<endl;
    if (!bname.empty()) cout<<"Btag file name: "<<bname<<endl;
    if (xsec) cout<<"Xsec set by hand (pb): "<<xsec<<endl;
    if (year.size()>0) cout<<"Year set by hand: "<<year<<endl;
    if (is_f) cout<<"FastSim is true!"<<endl;
    if (tr) cout<<"This is a test run on "<<tr<<" events!"<<endl;
    if (ABCD) cout<<"ABCD distribution histograms turned on. MET cut is="<<ABCD<<" GeV. Attention! MET>"<<ABCD<<" and sth_selected>0 cut is automatically implied!"<<endl;
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
    for (auto const& x : systematics) cout<<"Systematics for "<<x.first<<" set to "<<x.second<<endl;
    for (auto const& x : leptonpts) cout<<"Lepton pt for "<<x.first<<" set to "<<x.second<<endl;
  }
  Analyzer t(inputfiles,output,bname,xsec,year,is_f,FR,cut_variable,cut_operator,cut_value,is_quiet,is_debug,is_signalscan,is_signalstudy,is_countSignal, tr, systematics, leptonpts, ABCD);
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

   Long64_t nentries = 0;
   if (!_testRun) nentries = fChain->GetEntries();
   else nentries = _testRun;
   
   //2016 pre: 19502, 2016 post: 16812, 2017 41480, 2018 59833
   double L_data[4]={19502, 16812, 41480, 59833};
   
   //Btag SF
   BTCalibration calib_2016fast, calib_2017fast, calib_2018fast;
   BTCalibrationReader reader_L_2016fast, reader_M_2016fast, reader_T_2016fast;
   BTCalibrationReader reader_L_2017fast, reader_M_2017fast, reader_T_2017fast;
   BTCalibrationReader reader_L_2018fast, reader_M_2018fast, reader_T_2018fast;
   // setup calibration + reader https://twiki.cern.ch/twiki/bin/view/CMS/BTagCalibration#Standalone
   if (btag_file.size()>0){
     //2016 fastsim
     calib_2016fast = *new BTCalibration("2016fast", "input/btag/DeepFlav_13TEV_16SL_18_3_2019.csv");
     reader_L_2016fast = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_M_2016fast = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_T_2016fast = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_L_2016fast.load(calib_2016fast,BTEntry::FLAV_B,"fastsim");
     reader_L_2016fast.load(calib_2016fast,BTEntry::FLAV_C,"fastsim");
     reader_L_2016fast.load(calib_2016fast,BTEntry::FLAV_UDSG,"fastsim");
     reader_M_2016fast.load(calib_2016fast,BTEntry::FLAV_B,"fastsim");
     reader_M_2016fast.load(calib_2016fast,BTEntry::FLAV_C,"fastsim");
     reader_M_2016fast.load(calib_2016fast,BTEntry::FLAV_UDSG,"fastsim");
     reader_T_2016fast.load(calib_2016fast,BTEntry::FLAV_B,"fastsim");
     reader_T_2016fast.load(calib_2016fast,BTEntry::FLAV_C,"fastsim");
     reader_T_2016fast.load(calib_2016fast,BTEntry::FLAV_UDSG,"fastsim");
     
     //2017 fastsim
     calib_2017fast = *new BTCalibration("2017fast", "input/btag/DeepFlav_13TEV_17SL_18_3_2019.csv");
     reader_L_2017fast = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_M_2017fast = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_T_2017fast = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_L_2017fast.load(calib_2017fast,BTEntry::FLAV_B,"fastsim");
     reader_L_2017fast.load(calib_2017fast,BTEntry::FLAV_C,"fastsim");
     reader_L_2017fast.load(calib_2017fast,BTEntry::FLAV_UDSG,"fastsim");
     reader_M_2017fast.load(calib_2017fast,BTEntry::FLAV_B,"fastsim");
     reader_M_2017fast.load(calib_2017fast,BTEntry::FLAV_C,"fastsim");
     reader_M_2017fast.load(calib_2017fast,BTEntry::FLAV_UDSG,"fastsim");
     reader_T_2017fast.load(calib_2017fast,BTEntry::FLAV_B,"fastsim");
     reader_T_2017fast.load(calib_2017fast,BTEntry::FLAV_C,"fastsim");
     reader_T_2017fast.load(calib_2017fast,BTEntry::FLAV_UDSG,"fastsim");
     
     //2018 fastsim
     calib_2018fast = *new BTCalibration("2018fast", "input/btag/DeepFlav_13TEV_18SL_7_5_2019.csv");
     reader_L_2018fast = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_M_2018fast = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_T_2018fast = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_L_2018fast.load(calib_2018fast,BTEntry::FLAV_B,"fastsim");
     reader_L_2018fast.load(calib_2018fast,BTEntry::FLAV_C,"fastsim");
     reader_L_2018fast.load(calib_2018fast,BTEntry::FLAV_UDSG,"fastsim");
     reader_M_2018fast.load(calib_2018fast,BTEntry::FLAV_B,"fastsim");
     reader_M_2018fast.load(calib_2018fast,BTEntry::FLAV_C,"fastsim");
     reader_M_2018fast.load(calib_2018fast,BTEntry::FLAV_UDSG,"fastsim");
     reader_T_2018fast.load(calib_2018fast,BTEntry::FLAV_B,"fastsim");
     reader_T_2018fast.load(calib_2018fast,BTEntry::FLAV_C,"fastsim");
     reader_T_2018fast.load(calib_2018fast,BTEntry::FLAV_UDSG,"fastsim");
   }
         
   std::unique_ptr<CorrectionSet> cset_ele, cset_tau, cset_pho, cset_btag;

   std::string temp_fname="histos/Analyzer_histos"; 
   if (output_file != "default") {
     if (output_file.compare(0,1,"/") != 0) temp_fname+="_"+output_file;
     else {
       size_t found = output_file.find_last_of("/\\");
       string dir="mkdir -p "; dir+=output_file.substr(0,found);
       system(dir.c_str());
       temp_fname=output_file;
     }
   }
   else temp_fname+=".root";
   TFile *f = new TFile(temp_fname.c_str(),"recreate");

   TH1::SetDefaultSumw2();

   if (is_debug) cout<<"Defining histograms"<<endl;

   //histograms
   h_cuts = new TH1D("h_cuts","cuts;Higgs,PV,METfilter,Pho,Pho175,Lep0,MT,ST,nonHjet,DDBvL,Deep1,Deep2",15,0,15);
   TH1D *h_eff    = new TH1D("h_eff","Events;Before cuts, After cuts",3,-0.5,2.5);
   
   TH1D *h_nISR_jet = new TH1D("h_nISR_jet",";number of ISR jets",10,0,10);
   TH1D *h_SR    = new TH1D("h_SR","",16,0.5,16.5);
   
   TH1D *h_nPV = new TH1D("h_nPV",";number of good vertices",20,0,70);
   
   TH1D *h_puW= new TH1D("h_puW",";trueInt",100,0,100);
   TH1D *h_nTrueInt= new TH1D("h_nTrueInt",";trueInt",100,0,100);
   TH1D *h_nPU= new TH1D("h_nPU",";nPU",100,0,100);
   
   TH1D *h_phoEt    = new TH1D("h_phoEt",";E_{T}^{#gamma} [GeV]",7,25,1075);
   TH1D *h_phoEta    = new TH1D("h_phoEta",";#eta^{#gamma}",30,-3,3);

   const int nbins_photon=15;
   double xbins_photon[nbins_photon+1]={0,50,120,175,210,260,310,360,410,460,510,650,800,1000,1200,1500};
   TH1D *h_phoPt= new TH1D("h_phoPt",";#gamma{E}_{T} [GeV]",nbins_photon,xbins_photon);
   const int nbins_pfMET=13;
   double xbins_pfMET[nbins_pfMET+1]={0,20,40,70,100,150,200,300,500,700,1000,1500,2000,3000};
   TH1D *h_pfMET    = new TH1D("h_pfMET",";#slash{E}_{T} [GeV]",nbins_pfMET,xbins_pfMET);
   TH1D *h_pfMET_fix= new TH1D("h_pfMET_fix",";#slash{E}_{T} [GeV]",50,0,500);
   TH1D *h_pfMET_fix2= new TH1D("h_pfMET_fix2",";#slash{E}_{T} [GeV]",15,0,1500);
   TH1D *h_pfMETsumEt    = new TH1D("h_pfMETsumEt",";#slash{E}_{T} sumEt",20,-50,5000);
   TH1D *h_pfMETPhi    = new TH1D("h_pfMETPhi",";#Phi^{#slash{E}_{T}}",20,-4,4);
   TH1D *h_pfMETSig    = new TH1D("h_pfMETSig",";#slash{E}_{T}Sig",20,0,1500);
   
   TH2D *h2_higgs_pfMET = new TH2D("h2_higgs_pfMET",";fakeAk4, fakeAK8, 1b, B;#slash{E}_{T} [GeV]",4,0.5,4.5,nbins_pfMET,xbins_pfMET);

   const int nbins_ST=13;
   double xbins_ST[nbins_ST+1]={0, 200, 400, 600, 800, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5500};
   TH1D *h_ST    = new TH1D("h_ST",";S_{T} [GeV]",nbins_ST,xbins_ST);
   TH1D *h_ST_G    = new TH1D("h_ST_G",";S_{T}^{#gamma} [GeV]",10,0,2000);
   TH1D *h_ST_fix= new TH1D("h_ST_fix",";S_{T} [GeV]",15,0,3000);
   const int nbins_MT=9;
   double xbins_MT[nbins_MT+1]={0, 30, 60, 100, 130, 200, 500, 1000, 1500, 2000};
   TH1D *h_MT    = new TH1D("h_MT",";M_{T} [GeV]",nbins_MT,xbins_MT);
   TH1D *h_MT_fix= new TH1D("h_MT_fix",";M_{T} [GeV]",10,0,1000);
   TH1D *h_HT_after = new TH1D("h_HT_after","H_{T} after cuts;H_{T}[GeV]",15,0,3000);
   TH1D *h_EMHT_after = new TH1D("h_EMHT_after","EMHT after cuts;EMHT",15,0,3000);
   TH2D *h2_ST_HT = new TH2D("h2_ST_HT",";S_{T} [GeV];H_{T} [GeV]",nbins_ST,xbins_ST,20,0,5000);
   TH2D *h2_ST_MET= new TH2D("h2_ST_MET",";S_{T} [GeV];MET [GeV]",nbins_ST,xbins_ST,nbins_pfMET,xbins_pfMET);
   TH2D *h2_MT_MET= new TH2D("h2_MT_MET",";M_{T} [GeV];MET [GeV]",nbins_MT,xbins_MT,nbins_pfMET,xbins_pfMET);
   TH2D *h2_MET_HT = new TH2D("h2_MET_HT",";MET [GeV];H_{T} [GeV]",nbins_pfMET,xbins_pfMET,20,0,5000);
   TH2D *h2_MET_phoPt = new TH2D("h2_MET_phoPt",";MET [GeV];E_{T}^{#gamma} [GeV]",nbins_pfMET,xbins_pfMET,10,25,1525);
   TH2D *h2_MET_extrajets = new TH2D("h2_MET_extrajets",";MET [GeV];# extra jets",nbins_pfMET,xbins_pfMET,14,-1.5,12.5);
   TH2D *h2_extrajets_HT = new TH2D("h2_extrajets_HT",";# of extra jets;H_{T} [GeV]",14,-1.5,12.5,20,0,5000);

   TH1D *h_nPho    = new TH1D("h_nPho",";# of #gamma",5,-0.5,4.5);
   TH1D *h_nEle    = new TH1D("h_nEle",";# of e_{loose}",5,-0.5,4.5);
   TH1D *h_nEleM    = new TH1D("h_nEleM",";# of e_{medium}",5,-0.5,4.5);
   TH1D *h_nEleT    = new TH1D("h_nEleT",";# of e_{tight}",5,-0.5,4.5);
   TH1D *h_nMu    = new TH1D("h_nMu",";# of #mu_{loose}",5,-0.5,4.5);
   TH1D *h_nMuM    = new TH1D("h_nMuM",";# of #mu_{medium}",5,-0.5,4.5);
   TH1D *h_nMuT    = new TH1D("h_nMuT",";# of #mu_{tight}",5,-0.5,4.5);
   TH1D *h_nTau    = new TH1D("h_nTau",";# of #tau_{loose}",5,-0.5,4.5);
   TH1D *h_nIso    = new TH1D("h_nIso",";# of IsoTracks",5,-0.5,4.5);
  
   const int nbins_lepton=12;
   double xbins_lepton[nbins_lepton+1]={0,5,10,15,20,25,30,40,60,100,200,400,1000};
   TH1D *h_ElePt = new TH1D("h_ElePt",";leading p_{T}^{electron} [GeV]",nbins_lepton,xbins_lepton);
   TH1D *h_MuPt = new TH1D("h_MuPt",";leading p_{T}^{#mu} [GeV]",nbins_lepton,xbins_lepton);
   TH1D *h_TauPt = new TH1D("h_TauPt",";leading p_{T}^{#tau} [GeV]",nbins_lepton,xbins_lepton);
   TH1D *h_ElePt_fix = new TH1D("h_ElePt_fix",";leading p_{T}^{electron} [GeV]",10,0,1000);
   TH1D *h_MuPt_fix = new TH1D("h_MuPt_fix",";leading p_{T}^{electron} [GeV]",10,0,1000);
   TH1D *h_TauPt_fix = new TH1D("h_TauPt_fix",";leading p_{T}^{electron} [GeV]",10,0,1000);

   TH1D *h_njets    = new TH1D("h_njets",";# of jets",11,-0.5,10.5);
   TH1D *h_nonHjets = new TH1D("h_nonHjets",";# of extra jets",14,-1.5,12.5);
   TH1D *h_jetpt    = new TH1D("h_jetpt","Leading jetpt;p_{T}^{Leading jet} [GeV]",10,30,1030);
   TH1D *h_nAK8jets    = new TH1D("h_nAK8jets",";# of AK8jets",4,-0.5,3.5);
   TH1D *h_AK8jetpt    = new TH1D("h_AK8jetpt","Leading AK8jetpt;p_{T}^{Leading AK8jet} [GeV]",10,300,1300);

   TH1D *h_bjets_l  = new TH1D("h_bjets_l",";# of loose b-tagged jets",5,-0.5,4.5);
   TH1D *h_bjets_m  = new TH1D("h_bjets_m",";# of medium b-tagged jets",5,-0.5,4.5);
   TH1D *h_bjets_t  = new TH1D("h_bjets_t",";# of tight b-tagged jets",5,-0.5,4.5);
   TH1D *h_AK8bjets_l  = new TH1D("h_AK8bjets_l",";# of loose b-tagged AK8 jets",5,-0.5,4.5);
   TH1D *h_AK8bjets_m  = new TH1D("h_AK8bjets_m",";# of medium2 b-tagged AK8 jets",5,-0.5,4.5);
   TH1D *h_AK8bjets_h  = new TH1D("h_AK8bjets_h",";# of medium1 b-tagged AK8 jets",5,-0.5,4.5);
   TH1D *h_AK8bjets_t  = new TH1D("h_AK8bjets_t",";# of tight b-tagged AK8 jets",5,-0.5,4.5);
   TH1D *h_disc_bjets_1  = new TH1D("h_disc_bjets_1","; Highest DeepJet discr. value",15,0,1);
   TH1D *h_disc_bjets_2  = new TH1D("h_disc_bjets_2","; 2nd highest DeepJet discr. value",15,0,1);
   TH1D *h_disc_AK8bjets_1  = new TH1D("h_disc_AK8bjets_1","; Highest DeepDoubleB discr. value",15,0,1);
   
   TH1D *h_pt_bjets_l1  = new TH1D("h_pt_bjets_l1",";p_{T} of loose b-tagged jet (highest discr. valued) [GeV]",10,30,1030);
   TH1D *h_pt_bjets_l2  = new TH1D("h_pt_bjets_l2",";p_{T} of loose b-tagged jet (2nd highest discr. valued) [GeV]",10,30,1030);
   TH1D *h_pt_bjets_m  = new TH1D("h_pt_bjets_m",";p_{T} of medium b-tagged jet (highest discr. valued) [GeV]",10,30,1030);
   TH1D *h_pt_AK8bjets_l  = new TH1D("h_pt_AK8bjets_l",";p_{T} of loose b-tagged AK8jet (highest discr. valued) [GeV]",10,300,1300);
   
   TH1D *h_dr_pho_parton = new TH1D("h_dr_pho_parton",";#Delta R",200,0,5);
   TH1D *h_true_b = new TH1D("h_true_b",";True b quark (0,1), true b jet (2,3)",4,-0.5,3.5);

   TH1D *h_mbbjet_select    = new TH1D("h_mbbjet_select","Invariant mass of selected bjets;M_{bb}[GeV]",13,20,280);
   TH1D *h_AK8mass_select= new TH1D("h_AK8mass_select","PUPPI corrected softdrop mass of selected bjet;m_{AK8jet} [GeV]",20,5,655);
   TH1D *h_dR_ak4_Hcandidate = new TH1D("h_dR_ak4_Hcandidate","dR between H candidate AK4 jets;dR",20,0,5);
   TH1D *h_pt_ak4_Hcandidate = new TH1D("h_pt_ak4_Hcandidate","pt of H candidate AK4 jets;p_T [GeV]",25,0,1000);
   TH1D *h_dphi_met_jet= new TH1D("h_dphi_met_jet",";|#Delta#phi|(MET,nearest jet)",11,0,3.3);
   TH2D *h2_dphi_met_jet_nonHjets= new TH2D("h2_dphi_met_jet_nonHjets",";|#Delta#phi|(MET,nearest jet);nonHiggsJets",11,0,3.3,14,-1.5,12.5);
   TH2D *h2_dphi_met_jet_njet= new TH2D("h2_dphi_met_jet_njet",";|#Delta#phi|(MET,nth jet);number",11,0,3.3,8,0.5,8.5);
   TH2D *h2_dphi_met_lowjet_pt= new TH2D("h2_dphi_met_lowjet_pt",";|#Delta#phi|(MET,jet);jet p_{T}",11,0,3.3,10,30,2030);
   TH2D *h2_dphi_met_highjet_pt= new TH2D("h2_dphi_met_highjet_pt",";|#Delta#phi|(MET,jet);jet p_{T}",11,0,3.3,10,30,2030);
   TH1D *h_dphi_met_h_ak8= new TH1D("h_dphi_met_h_ak8",";|#Delta#phi|(MET,ak8 H candidate)",11,0,3.3);
   TH1D *h_dphi_met_h_ak4= new TH1D("h_dphi_met_h_ak4",";|#Delta#phi|(MET,ak4 H candidate)",11,0,3.3);
   TH1D *h_dphi_met_hmin_ak4= new TH1D("h_dphi_met_hmin_ak4",";|#Delta#phi|(MET,ak4 Hmin candidate)",11,0,3.3);
   TH1D *h_dphi_met_ak4btag= new TH1D("h_dphi_met_ak4btag",";|#Delta#phi|(MET,ak4 btag)",11,0,3.3);
   TH1D *h_dphi_met_btags= new TH1D("h_dphi_met_btags",";|#Delta#phi|(MET,loose-jets)",11,0,3.3);
   TH2D *h2_dphi_met_h_ak8= new TH2D("h2_dphi_met_h_ak8",";Unrolled bins;|#Delta#phi|(MET,ak8 H candidate)",4,0.5,4.5,11,0,3.3);
   TH2D *h2_dphi_met_h_ak4= new TH2D("h2_dphi_met_h_ak4",";Unrolled bins;|#Delta#phi|(MET,ak4 H candidate)",8,0.5,8.5,11,0,3.3);
   TH2D *h2_dphi_met_btags_ak8= new TH2D("h2_dphi_met_btags_ak8",";Unrolled bins;|#Delta#phi|(MET,loose-jets)",4,0.5,4.5,11,0,3.3);
   TH2D *h2_dphi_met_btags_ak4= new TH2D("h2_dphi_met_btags_ak4",";Unrolled bins;|#Delta#phi|(MET,loose-jets)",8,0.5,8.5,11,0,3.3);
   TH2D *h2_dphi_met_hmin_ak4= new TH2D("h2_dphi_met_hmin_ak4",";Unrolled bins;|#Delta#phi|(MET,ak4 Hmin candidate)",8,0.5,8.5,11,0,3.3);
   TH2D *h2_dphi_met_ak4btag= new TH2D("h2_dphi_met_ak4btag",";Unrolled bins;|#Delta#phi|(MET,ak4 btag)",8,0.5,8.5,11,0,3.3);
   TH2D *h2_dphi_met_h_pt_lowjet= new TH2D("h2_dphi_met_h_pt_lowjet",";|#Delta#phi|(MET,jet/H);jet/H p_{T}",11,0,3.3,10,30,2030);
   TH2D *h2_dphi_met_h_pt_highjet= new TH2D("h2_dphi_met_h_pt_highjet",";|#Delta#phi|(MET,jet/H);jet/H p_{T}",11,0,3.3,10,30,2030);
   TH2D *h2_dphi_met_hmin_pt_lowjet= new TH2D("h2_dphi_met_hmin_pt_lowjet",";|#Delta#phi|(MET,jet/Hmin);jet/Hmin p_{T}",11,0,3.3,10,30,2030);
   TH2D *h2_dphi_met_hmin_pt_highjet= new TH2D("h2_dphi_met_hmin_pt_highjet",";|#Delta#phi|(MET,jet/Hmin);jet/Hmin p_{T}",11,0,3.3,10,30,2030);
   TH2D *h2_bjet1_pt_disc = new TH2D("h2_bjet1_pt_disc",";p_{T} [GeV];DeepJet discr",10,0,1000,10,0,1);
   TH2D *h2_bjet2_pt_disc = new TH2D("h2_bjet2_pt_disc",";p_{T} [GeV];DeepJet discr",10,0,1000,10,0,1);
   TH2D *h2_AK4_btags = new TH2D("h2_AK4_btags",";btag WP of highest b-tagged jet;btag WP of 2nd highest jet",4,-0.5,3.5,4,-0.5,3.5);
   TH2D *h2_AK4Higgs_btags = new TH2D("h2_AK4Higgs_btags",";btag WP of AK4 Higgs candidates",4,-0.5,3.5,4,-0.5,3.5);

   TH1D *h_mHAK8= new TH1D("h_mHAK8",";M_{AK8}[GeV]",30,0,300);
   TH1D *h_mHAK4= new TH1D("h_mHAK4",";M_{bb}[GeV]",30,0,300);
   TH2D *h2_mHAK8= new TH2D("h2_mHAK8",";Unrolled bins;M_{AK8}[GeV]",12,0.5,12.5,30,0,300);
   TH2D *h2_mHAK4= new TH2D("h2_mHAK4",";Unrolled bins;M_{bb}[GeV]",12,0.5,12.5,30,0,300);
   TH1D *h_mHAK8_fake= new TH1D("h_mHAK8_fake",";M_{AK8}[GeV]",20,18,278);
   TH1D *h_mHAK4_fake= new TH1D("h_mHAK4_fake",";M_{bb}[GeV]",13,20,280);
   TH2D *h2_mHAK8_fake= new TH2D("h2_mHAK8_fake",";Unrolled bins;M_{AK8}[GeV]",12,0.5,12.5,30,0,300);
   TH2D *h2_mHAK4_fake= new TH2D("h2_mHAK4_fake",";Unrolled bins;M_{bb}[GeV]",12,0.5,12.5,30,0,300);
   TH1D *h_mHAK4_clean= new TH1D("h_mHAK4_clean",";M_{bb}[GeV]",13,20,280);
   TH2D *h2_mHAK4_clean= new TH2D("h2_mHAK4_clean",";Unrolled bins;M_{bb}[GeV]",12,0.5,12.5,30,0,300);
   TH1D *h_mHAK8_clean_fake= new TH1D("h_mHAK8_clean_fake",";M_{AK8}[GeV]",20,18,278);
   TH1D *h_mHAK4_clean_fake= new TH1D("h_mHAK4_clean_fake",";M_{bb}[GeV]",13,20,280);
   TH2D *h2_mHAK8_clean_fake= new TH2D("h2_mHAK8_clean_fake",";Unrolled bins;M_{AK8}[GeV]",12,0.5,12.5,30,0,300);
   TH2D *h2_mHAK4_clean_fake= new TH2D("h2_mHAK4_clean_fake",";Unrolled bins;M_{bb}[GeV]",12,0.5,12.5,30,0,300);
   TH2D *h2_dr_SRHiggs = new TH2D("h2_dr_SRHiggs",";Unrolled bins;dR_{bb}",12,0.5,12.5,20,0,3.2);
   TH3D *h3_mHAK4_dr_Higgs = new TH3D("h3_mHAK4_dr_Higgs",";Unrolled bins;M_{bb}[GeV];dR_{bb}",21,0.5,12.5,13,20,280,20,0,3.2);

   //AK4 searchbins
   const int dim_ak4=3;
   int nbins_ak4[dim_ak4]={2,6,2};
   double xmin_ak4[dim_ak4]={-0.5,0.5,0.5};
   double xmax_ak4[dim_ak4]={1.5,6.5,2.5};
   THnD *hn_AK4searchBins = new THnD("hn_AK4searchBins",";AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
   THnD *hn_AK4searchBins_noweight = new THnD("hn_AK4searchBins_noweight",";AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
   THnD *hn_AK4HTsearchBins = new THnD("hn_AK4HTsearchBins",";AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
   hn_AK4searchBins->Sumw2(); hn_AK4HTsearchBins->Sumw2();
   unsigned int nsbins_ak4=hn_AK4searchBins->GetNbins();
   TH1D *h_AK4searchBins= new TH1D("h_AK4searchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
   TH1D *h_AK4searchBins_noweight= new TH1D("h_AK4searchBins_noweight",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
   TH1D *h_AK4HTsearchBins= new TH1D("h_AK4HTsearchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);

   //AK8 searchbins
   const int dim_ak8=3;
   int nbins_ak8[dim_ak8]={2,6,2};
   double xmin_ak8[dim_ak8]={-0.5,0.5,0.5};
   double xmax_ak8[dim_ak8]={1.5,6.5,2.5};
   THnD *hn_AK8searchBins = new THnD("hn_AK8searchBins",";AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
   THnD *hn_AK8searchBins_noweight = new THnD("hn_AK8searchBins_noweight",";AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
   THnD *hn_AK8HTsearchBins = new THnD("hn_AK8HTsearchBins",";AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
   hn_AK8searchBins->Sumw2(); hn_AK8HTsearchBins->Sumw2();
   unsigned int nsbins_ak8=hn_AK8searchBins->GetNbins();
   TH1D *h_AK8searchBins= new TH1D("h_AK8searchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
   TH1D *h_AK8searchBins_noweight= new TH1D("h_AK8searchBins_noweight",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
   TH1D *h_AK8HTsearchBins= new TH1D("h_AK8HTsearchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);

   //histograms for ABCD prediction
   vector<TH1D*> histos_for_abcd{h_eff,h_nPV,h_phoEt,h_phoEta,h_pfMETPhi,h_ST_fix,h_HT_after,h_dphi_met_btags,h_nPho,h_nEle,h_nMu,h_nTau,h_ElePt_fix,h_MuPt_fix,h_TauPt_fix,h_njets,h_jetpt,h_nAK8jets,h_AK8jetpt,h_bjets_l,h_bjets_m,h_bjets_t,h_AK8bjets_l,h_AK8bjets_m,h_disc_bjets_1,h_disc_bjets_2,h_disc_AK8bjets_1,h_pt_bjets_l1,h_pt_bjets_l2,h_pt_bjets_m,h_pt_AK8bjets_l};
   if (_ABCD) for (auto i : histos_for_abcd) set_ABCD_histo(i);
  
   //Histograms for signalstudy
   map<int,vector<int>> grid;
   if (SignalScan) {
     grid=init_scan_histos(f,signalstudy,SignalScenario);
   }

   TBenchmark time;
   TDatime now;
   if (!is_quiet) now.Print();
   time.Start("time");

   TRandom3 *gen_btag = new TRandom3(137);

   if (is_debug) cout<<"Starting loop on event tree"<<endl;
   std::map<pair<int,int>,int> signal_events;
   if (CountSignal) signal_events=init_signal_event(SignalScenario);
   int file_counter=-1, temp=-1; std::string temp_f="";
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     if (is_debug) cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
     if (is_debug) cout<<"RUNNING ON ENTRY "<<jentry<<endl;
     if (is_debug) cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
     b_event->GetEntry(ientry);
     b_run->GetEntry(ientry);
     if (run==1) isData=false;
     bool newfile=false;
     if (temp_f != fChain->GetCurrentFile()->GetName()) {
       temp_f=fChain->GetCurrentFile()->GetName();
       file_counter++;
       //std::cout<<"file "<<file_counter<<" "<<fChain->GetCurrentFile()->GetName()<<std::endl;
       newfile=true;
     }
     //Set year from run number in data
     if (isData && (jentry==0 || newfile)) {
       if (run<=278509 || run==278770) year="2016preVFP";
       else if (run<=284044) year="2016postVFP";
       else if (run<=307082) year="2017";
       else if (run<=325273) year="2018";
     }
     if (is_debug && isData) cout<<"Getting year info: year="<<year<<endl;
     //getting cross section & total number of events
     if (!isData && (jentry==0 || newfile)){
       if (year.size()==0) {
         if (temp_f.find("2016APV")!=std::string::npos || temp_f.find("UL16APV")!=std::string::npos) year="2016preVFP";
         else if (temp_f.find("2016")!=std::string::npos || temp_f.find("UL16")!=std::string::npos) year="2016postVFP";
         else if (temp_f.find("2017")!=std::string::npos || temp_f.find("UL17")!=std::string::npos) year="2017";
         else if (temp_f.find("2018")!=std::string::npos || temp_f.find("UL18")!=std::string::npos) year="2018";
       }
       if (is_debug) cout<<"Getting year info: year="<<year<<endl;
       if (!SignalScan && (xsec==1 || newfile)) {
         xsec=get_cross_section(temp_f, year);
         if (xsec==1) cout<<"WARNING! No xsec found. Using xsec = "<<xsec<<endl;
       }
       if (is_debug) cout<<"Getting xsec info: xsec="<<xsec<<endl;
     }
     int year_chooser=(year.find("2016preVFP")!=std::string::npos) ? 0 : (year.find("2016postVFP")!=std::string::npos) ? 1 : (year.find("2017")!=std::string::npos) ? 2 : 3;
     if (is_debug) cout<<"Initializing branches"<<endl;
     if (!isData) {
       if (is_debug) cout<<"Initializing MC only branches"<<endl;
       b_puAutoWeight->GetEntry(ientry);
       b_puAutoWeightUp->GetEntry(ientry);
       b_puAutoWeightDown->GetEntry(ientry);
       b_puWeight->GetEntry(ientry);
       b_puWeightUp->GetEntry(ientry);
       b_puWeightDown->GetEntry(ientry);
       b_genWeight->GetEntry(ientry);
       b_Pileup_nPU->GetEntry(ientry);
       b_Pileup_nTrueInt->GetEntry(ientry);
       b_nGenPart->GetEntry(ientry);
       b_GenPart_pdgId->GetEntry(ientry);
       b_GenPart_pt->GetEntry(ientry);
       b_GenPart_phi->GetEntry(ientry);
       b_GenPart_eta->GetEntry(ientry);
       b_GenPart_mass->GetEntry(ientry);
       b_GenPart_status->GetEntry(ientry);
       b_GenPart_statusFlags->GetEntry(ientry);
       b_GenPart_genPartIdxMother->GetEntry(ientry);
       b_GenMET_pt->GetEntry(ientry);
       b_GenMET_phi->GetEntry(ientry);
       b_nGenJet->GetEntry(ientry);
       b_GenJet_pt->GetEntry(ientry);
       b_GenJet_eta->GetEntry(ientry);
       b_GenJet_phi->GetEntry(ientry);
       b_GenJet_hadronFlavour->GetEntry(ientry);
       b_GenJet_partonFlavour->GetEntry(ientry);
       b_Tau_genPartFlav->GetEntry(ientry);
       b_Jet_pt_jerUp->GetEntry(ientry);
       b_Jet_pt_jerDown->GetEntry(ientry);
       b_Jet_pt_jesTotalUp->GetEntry(ientry);
       b_Jet_pt_jesTotalDown->GetEntry(ientry);
       b_Jet_hadronFlavour->GetEntry(ientry);
       //b_Jet_mass_jesTotalUp->GetEntry(ientry);
       //b_Jet_mass_jesTotalDown->GetEntry(ientry);
       //b_Jet_mass_jerUp->GetEntry(ientry);
       //b_Jet_mass_jerDown->GetEntry(ientry);
       b_Jet_genJetIdx->GetEntry(ientry);
       b_FatJet_pt_jerUp->GetEntry(ientry);
       b_FatJet_pt_jerDown->GetEntry(ientry);
       b_FatJet_pt_jesTotalUp->GetEntry(ientry);
       b_FatJet_pt_jesTotalDown->GetEntry(ientry);
       b_FatJet_msoftdrop_jerUp->GetEntry(ientry);
       b_FatJet_msoftdrop_jerDown->GetEntry(ientry);
       b_FatJet_msoftdrop_jesTotalUp->GetEntry(ientry);
       b_FatJet_msoftdrop_jesTotalDown->GetEntry(ientry);
       b_FatJet_msoftdrop_jmrUp->GetEntry(ientry);
       b_FatJet_msoftdrop_jmrDown->GetEntry(ientry);
       b_FatJet_msoftdrop_jmsUp->GetEntry(ientry);
       b_FatJet_msoftdrop_jmsDown->GetEntry(ientry);
       b_FatJet_genJetAK8Idx->GetEntry(ientry);
       b_nGenJetAK8->GetEntry(ientry);
       b_GenJetAK8_pt->GetEntry(ientry);
       b_GenJetAK8_eta->GetEntry(ientry);
       b_GenJetAK8_phi->GetEntry(ientry);
       b_GenJetAK8_hadronFlavour->GetEntry(ientry);
       b_MET_T1_pt_jerUp->GetEntry(ientry);
       b_MET_T1_pt_jerDown->GetEntry(ientry);
       b_MET_T1_pt_jesTotalUp->GetEntry(ientry);
       b_MET_T1_pt_jesTotalDown->GetEntry(ientry);
       b_MET_T1_pt_unclustEnUp->GetEntry(ientry);
       b_MET_T1_pt_unclustEnDown->GetEntry(ientry);
       b_MET_T1_phi_jerUp->GetEntry(ientry);
       b_MET_T1_phi_jerDown->GetEntry(ientry);
       b_MET_T1_phi_jesTotalUp->GetEntry(ientry);
       b_MET_T1_phi_jesTotalDown->GetEntry(ientry);
       b_MET_T1_phi_unclustEnUp->GetEntry(ientry);
       b_MET_T1_phi_unclustEnDown->GetEntry(ientry);
     }
     if (!_fastSim && !isData && year.find("2018")==std::string::npos) b_L1PreFiringWeight_Dn->GetEntry(ientry);
     if (!_fastSim && !isData && year.find("2018")==std::string::npos) b_L1PreFiringWeight_Nom->GetEntry(ientry);
     if (!_fastSim && !isData && year.find("2018")==std::string::npos) b_L1PreFiringWeight_Up->GetEntry(ientry);
     b_luminosityBlock->GetEntry(ientry);
     b_PV_npvsGood->GetEntry(ientry);
     b_PV_npvs->GetEntry(ientry);
     b_PV_x->GetEntry(ientry);
     b_PV_y->GetEntry(ientry);
     b_PV_z->GetEntry(ientry);
     if (!_fastSim) {
       if (year.find("2016")!=std::string::npos) {
         b_HLT_Photon165_HE10->GetEntry(ientry);
         b_HLT_Photon175->GetEntry(ientry);
         b_HLT_Photon250_NoHE->GetEntry(ientry);
       }
       else {
         b_HLT_Photon200->GetEntry(ientry);
         b_HLT_Photon300_NoHE->GetEntry(ientry);
       }
     }
     b_Flag_goodVertices->GetEntry(ientry);
     b_Flag_globalSuperTightHalo2016Filter->GetEntry(ientry);
     b_Flag_HBHENoiseFilter->GetEntry(ientry);
     b_Flag_HBHENoiseIsoFilter->GetEntry(ientry);
     b_Flag_EcalDeadCellTriggerPrimitiveFilter->GetEntry(ientry);
     b_Flag_BadPFMuonFilter->GetEntry(ientry);
     b_Flag_BadChargedCandidateFilter->GetEntry(ientry);
     b_Flag_eeBadScFilter->GetEntry(ientry);
     b_Flag_ecalBadCalibFilter->GetEntry(ientry);
     b_Flag_BadPFMuonDzFilter->GetEntry(ientry);
     b_Flag_hfNoisyHitsFilter->GetEntry(ientry);
     b_Flag_METFilters->GetEntry(ientry);
     b_MET_pt->GetEntry(ientry);
     b_MET_T1_pt->GetEntry(ientry);
     b_MET_phi->GetEntry(ientry);
     b_MET_T1_phi->GetEntry(ientry);
     b_MET_sumEt->GetEntry(ientry);
     b_MET_significance->GetEntry(ientry);
     b_nElectron->GetEntry(ientry);
     b_Electron_eta->GetEntry(ientry);
     b_Electron_phi->GetEntry(ientry);
     b_Electron_pt->GetEntry(ientry);
     b_Electron_miniPFRelIso_all->GetEntry(ientry);
     b_Electron_cutBased->GetEntry(ientry);
     b_nMuon->GetEntry(ientry);
     b_Muon_pt->GetEntry(ientry);
     b_Muon_eta->GetEntry(ientry);
     b_Muon_phi->GetEntry(ientry);
     b_Muon_sip3d->GetEntry(ientry);
     b_Muon_dz->GetEntry(ientry);
     b_Muon_dxy->GetEntry(ientry);
     b_Muon_miniPFRelIso_all->GetEntry(ientry);
     b_Muon_looseId->GetEntry(ientry);
     b_Muon_mediumId->GetEntry(ientry);
     b_Muon_tightId->GetEntry(ientry);
     b_nPhoton->GetEntry(ientry); if (nPhoton>99) continue;
     b_Photon_pt->GetEntry(ientry);
     b_Photon_dEscaleUp->GetEntry(ientry);
     b_Photon_dEscaleDown->GetEntry(ientry);
     b_Photon_dEsigmaUp->GetEntry(ientry);
     b_Photon_dEsigmaDown->GetEntry(ientry);
     b_Photon_eCorr->GetEntry(ientry);
     b_Photon_eta->GetEntry(ientry);
     b_Photon_phi->GetEntry(ientry);
     b_Photon_r9->GetEntry(ientry);
     b_Photon_seedGain->GetEntry(ientry);
     b_Photon_pixelSeed->GetEntry(ientry);
     b_Photon_electronVeto->GetEntry(ientry);
     b_Photon_hoe->GetEntry(ientry);
     b_Photon_isScEtaEB->GetEntry(ientry);
     b_Photon_isScEtaEE->GetEntry(ientry);
     b_Photon_cutBased->GetEntry(ientry);
     b_Photon_mvaID_WP80->GetEntry(ientry);
     b_Photon_mvaID_WP90->GetEntry(ientry);
     /*
        b_phoScale_stat_up->GetEntry(ientry);
        b_phoScale_stat_dn->GetEntry(ientry);
        b_phoScale_syst_up->GetEntry(ientry);
        b_phoScale_syst_dn->GetEntry(ientry);
        b_phoScale_gain_up->GetEntry(ientry);
        b_phoScale_gain_dn->GetEntry(ientry);
        b_phoResol_rho_up->GetEntry(ientry);
        b_phoResol_rho_dn->GetEntry(ientry);
        b_phoResol_phi_up->GetEntry(ientry);
        b_phoResol_phi_dn->GetEntry(ientry);
        */
     b_nTau->GetEntry(ientry);
     b_Tau_pt->GetEntry(ientry);
     b_Tau_eta->GetEntry(ientry);
     b_Tau_phi->GetEntry(ientry);
     b_Tau_decayMode->GetEntry(ientry);
     b_Tau_idDeepTau2017v2p1VSjet->GetEntry(ientry);
     b_Tau_idDeepTau2017v2p1VSe->GetEntry(ientry);
     b_Tau_idDeepTau2017v2p1VSmu->GetEntry(ientry);
     b_nJet->GetEntry(ientry); if (nJet>99) continue;
     b_Jet_pt->GetEntry(ientry);
     b_Jet_pt_nom->GetEntry(ientry);
     b_Jet_pt_raw->GetEntry(ientry);
     b_Jet_phi->GetEntry(ientry);
     b_Jet_eta->GetEntry(ientry);
     b_Jet_mass->GetEntry(ientry);
     //b_Jet_mass_nom->GetEntry(ientry);
     b_Jet_chHEF->GetEntry(ientry);
     b_Jet_btagDeepFlavB->GetEntry(ientry);
     b_Jet_jetId->GetEntry(ientry);
     b_Jet_puId->GetEntry(ientry);
     b_nFatJet->GetEntry(ientry);
     b_FatJet_pt->GetEntry(ientry);
     b_FatJet_pt_nom->GetEntry(ientry);
     b_FatJet_eta->GetEntry(ientry);
     b_FatJet_phi->GetEntry(ientry);
     b_FatJet_mass->GetEntry(ientry);
     b_FatJet_msoftdrop->GetEntry(ientry);
     b_FatJet_msoftdrop_nom->GetEntry(ientry);
     b_FatJet_jetId->GetEntry(ientry);
     b_FatJet_btagDDBvLV2->GetEntry(ientry);
     b_FatJet_tau1->GetEntry(ientry);
     b_FatJet_tau2->GetEntry(ientry);
     b_FatJet_tau3->GetEntry(ientry);
     b_nIsoTrack->GetEntry(ientry);
     b_IsoTrack_pt->GetEntry(ientry);
     b_IsoTrack_eta->GetEntry(ientry);
     b_IsoTrack_phi->GetEntry(ientry);
     b_IsoTrack_dxy->GetEntry(ientry);
     b_IsoTrack_dz->GetEntry(ientry);
     b_IsoTrack_miniPFRelIso_chg->GetEntry(ientry);
     b_IsoTrack_pdgId->GetEntry(ientry);
     //nb = fChain->GetEntry(jentry);   nbytes += nb;
     if (is_debug) cout<<"Branch Initialization complete"<<endl;

     //progress bar
     if (jentry==0 && !is_quiet) cout<<"Total number of events: "<<nentries<<endl;;
     double progress=(jentry+1)/double(nentries);
     if (!is_quiet){
       if (temp!=int(progress * 10000)){
         temp=int(progress * 10000);
         int vmi=int(progress * 100)*100;
         std::cout << vmi/100 <<"."<< temp-vmi << " %\r";
         std::cout.flush();
       }
     }
     if (_fakeRate && jentry==0) {
       TFile f_FR("input/FakeRate_EGamma.root","read");
       h2_FR = (TH2D*)f_FR.Get("FR_Data_EtaPhi_50_110");
       h2_FR->SetDirectory(0);
       f_FR.Close();
     }
     //check data if inside Golden json file
     if (isData && !IsGoldEvent(run,luminosityBlock)) continue;

     if (isData && signalstudy) {cout<<"ERROR! Signalstudy option set, but running on Data..."<<endl; return;}
     //SignalScan variables
     pair<int,int> mass_pair; int neutralino=-1, gluino=-1;
     if (SignalScan) {
       bool foundG=0, foundX=0;
       for (unsigned int i=0;i<nGenPart;i++) {
         if (!foundX && GenPart_pdgId[i]==1000023 && GenPart_status[i]==22) {neutralino=i; foundX=1;}
         if (!foundG && GenPart_pdgId[i]==1000021 && GenPart_status[i]==22) {gluino=i; foundG=1;}
         if (foundX && foundG) break;
       }
       int m_Gluino=1;
       if (SignalScenario==1 || SignalScenario==3 || SignalScenario==4) m_Gluino = GenPart_mass[gluino];
       //Neutralino/gluino mass is not exact. Need to find nearest grid point
       double m_Neutralino=GenPart_mass[neutralino];
       pair<double,double> initial_pair(m_Gluino,m_Neutralino);
       mass_pair = whichGridpoint(initial_pair, SignalScenario);
       if (is_debug) cout<<"Determining mass point mg="<<m_Gluino<<" mN="<<m_Neutralino<<endl;
       if (CountSignal) {
         auto search = signal_events.find(mass_pair);
         if (search!=signal_events.end()) search->second +=1;
       }
     }

     w=1;
     //MC weights and scale factors
     double pu_weight=1, weight=1;
     if (!isData){
       if (SignalScan) {
         xsec=get_cross_section(mass_pair.first, SignalScenario);
         TotalEvents=get_total_events(mass_pair,year,SignalScenario);
         if (TotalEvents==0) continue;
       }
       //weights
       if (is_debug) cout<<"Determining weights"<<endl;
       (PUweight_whichSF==1) ? pu_weight=puWeightUp : (PUweight_whichSF==2) ? pu_weight=puWeightDown : pu_weight=puWeight;
       //(PUweight_whichSF==1) ? pu_weight=puAutoWeightUp : (PUweight_whichSF==2) ? pu_weight=puAutoWeightDown : pu_weight=puAutoWeight;
       weight=L_data[year_chooser]*xsec*genWeight/TotalEvents;
       w=weight*pu_weight;
       if (is_debug) cout<<"weight=L_data[year_chooser]*genWeight*xsec/TotalEvents "<<weight<<"="<<L_data[year_chooser]<<"*"<<genWeight<<"*"<<xsec<<"/"<<TotalEvents<<endl;
       if (is_debug) cout<<"w=weight*pu_weight "<<w<<"="<<weight<<"*"<<pu_weight<<endl;
       //trigger efficiency
       double w_trig[4]={0.9871,0.9871,0.9913,0.9947};//use same trig eff for full 2016 year
       if (_fastSim) w*=w_trig[year_chooser];
       //std::cout<<"event "<<event<<" w=weight*pu_weight = "<<w<<"="<<weight<<"("<<L_data[year_chooser]<<"*"<<genWeight<<"*"<<xsec<<"/"<<TotalEvents<<")"<<"*"<<pu_weight<<std::endl;
       //Scale factors
       if (jentry==0 || newfile) {
         if (is_debug) cout<<"Loading scale factor json files"<<endl;
         string sf_ele_fname="correctionlib/POG/EGM/"+year+"_UL/electron.json";
         cset_ele = CorrectionSet::from_file(sf_ele_fname);
         string sf_tau_fname="correctionlib/POG/TAU/"+year+"_UL/tau.json";
         cset_tau = CorrectionSet::from_file(sf_tau_fname);
         string sf_pho_fname="correctionlib/POG/EGM/"+year+"_UL/photon.json";
         cset_pho = CorrectionSet::from_file(sf_pho_fname);
         string sf_btag_fname="correctionlib/POG/BTV/"+year+"_UL/btagging.json";
         cset_btag = CorrectionSet::from_file(sf_btag_fname);
         if (year.find("2016")!=std::string::npos){
           //Muon ID SF
           float lum_ratio_BCDEF = 0.5481;
           TH2D *h_temp_BCDEF[3];
           TFile f_muID_BCDEF("input/muon_SF/2016/RunBCDEF_SF_ID_syst_muon2016.root","read");
           h_temp_BCDEF[0] = (TH2D*)f_muID_BCDEF.Get("NUM_LooseID_DEN_genTracks_eta_pt");
           h_temp_BCDEF[1] = (TH2D*)f_muID_BCDEF.Get("NUM_MediumID_DEN_genTracks_eta_pt");
           h_temp_BCDEF[2] = (TH2D*)f_muID_BCDEF.Get("NUM_TightID_DEN_genTracks_eta_pt");
           for (auto i : h_temp_BCDEF) {i->SetDirectory(0); i->Scale(lum_ratio_BCDEF);}
           f_muID_BCDEF.Close();
           TFile f_muID_GH("input/muon_SF/2016/RunGH_SF_ID_syst_muon2016.root","read");
           h_muID_SF2D[0] = (TH2D*)f_muID_GH.Get("NUM_LooseID_DEN_genTracks_eta_pt");
           h_muID_SF2D[1] = (TH2D*)f_muID_GH.Get("NUM_MediumID_DEN_genTracks_eta_pt");
           h_muID_SF2D[2] = (TH2D*)f_muID_GH.Get("NUM_TightID_DEN_genTracks_eta_pt");
           for (auto i : h_muID_SF2D) {i->SetDirectory(0); i->Scale(1-lum_ratio_BCDEF);}
           f_muID_GH.Close();
           h_muID_SF2D[0]->Add(h_temp_BCDEF[0]);
           h_muID_SF2D[1]->Add(h_temp_BCDEF[1]);
           h_muID_SF2D[2]->Add(h_temp_BCDEF[2]);

           //Muon ISO SF
           TFile f_muISO_BCDEF("input/muon_SF/2016/RunBCDEF_SF_ISO_syst_muon2016.root","read");
           h_temp_BCDEF[0] = (TH2D*)f_muISO_BCDEF.Get("NUM_LooseRelIso_DEN_LooseID_eta_pt");
           h_temp_BCDEF[1] = (TH2D*)f_muISO_BCDEF.Get("NUM_LooseRelIso_DEN_MediumID_eta_pt");
           h_temp_BCDEF[2] = (TH2D*)f_muISO_BCDEF.Get("NUM_LooseRelIso_DEN_TightIDandIPCut_eta_pt");
           for (auto i : h_temp_BCDEF) {i->SetDirectory(0); i->Scale(lum_ratio_BCDEF);}
           f_muISO_BCDEF.Close();
           TFile f_muISO_GH("input/muon_SF/2016/RunGH_SF_ISO_syst_muon2016.root","read");
           h_muISO_SF2D[0] = (TH2D*)f_muISO_GH.Get("NUM_LooseRelIso_DEN_LooseID_eta_pt");
           h_muISO_SF2D[1] = (TH2D*)f_muISO_GH.Get("NUM_LooseRelIso_DEN_MediumID_eta_pt");
           h_muISO_SF2D[2] = (TH2D*)f_muISO_GH.Get("NUM_LooseRelIso_DEN_TightIDandIPCut_eta_pt");
           for (auto i : h_muISO_SF2D) {i->SetDirectory(0); i->Scale(1-lum_ratio_BCDEF);}
           f_muISO_GH.Close();
           h_muISO_SF2D[0]->Add(h_temp_BCDEF[0]);
           h_muISO_SF2D[1]->Add(h_temp_BCDEF[1]);
           h_muISO_SF2D[2]->Add(h_temp_BCDEF[2]);

           // transpose histograms
           for (int i = 0; i<3; i++){
             std::string name    = std::string(h_muID_SF2D[i]->GetName()) + "_transposed";
             std::string title   = name;
             std::string name_iso = std::string(h_muISO_SF2D[i]->GetName()) + "_transposed";
             std::string title_iso= name_iso;

             unsigned int nbinsx          = h_muID_SF2D[i]->GetNbinsX();
             double *xbins        = (double*)((TAxis*)h_muID_SF2D[i]->GetXaxis())->GetXbins()->GetArray();
             unsigned int nbinsy          = h_muID_SF2D[i]->GetNbinsY();
             double *ybins        = (double*)((TAxis*)h_muID_SF2D[i]->GetYaxis())->GetXbins()->GetArray();
             TH2D *h_temp        = new TH2D(name.c_str(), title.c_str(), nbinsy, ybins, nbinsx, xbins);
             unsigned int nbinsx_iso      = h_muISO_SF2D[i]->GetNbinsX();
             double *xbins_iso    = (double*)((TAxis*)h_muISO_SF2D[i]->GetXaxis())->GetXbins()->GetArray();
             unsigned int nbinsy_iso      = h_muISO_SF2D[i]->GetNbinsY();
             double *ybins_iso    = (double*)((TAxis*)h_muISO_SF2D[i]->GetYaxis())->GetXbins()->GetArray();
             TH2D *h_temp_iso    = new TH2D(name_iso.c_str(), title_iso.c_str(), nbinsy_iso, ybins_iso, nbinsx_iso, xbins_iso);

             for (unsigned int ix=0;ix<nbinsx;ix++){
               double x=xbins[ix];
               for (unsigned int iy=0;iy<nbinsy;iy++){
                 double y=ybins[iy];
                 int i_bin               = h_muID_SF2D[i]->FindBin(x,y);
                 int i_bin_transposed    = h_temp->FindBin(y,x);

                 h_temp->SetBinContent(i_bin_transposed, h_muID_SF2D[i]->GetBinContent(i_bin));
                 h_temp->SetBinError(  i_bin_transposed, h_muID_SF2D[i]->GetBinError(i_bin));
               }
             }

             for (unsigned int ix=0;ix<nbinsx_iso;ix++){
               double x=xbins_iso[ix];
               for (unsigned int iy=0;iy<nbinsy_iso;iy++){
                 double y=ybins_iso[iy];
                 int i_bin               = h_muISO_SF2D[i]->FindBin(x,y);
                 int i_bin_transposed    = h_temp_iso->FindBin(y,x);

                 h_temp_iso->SetBinContent(i_bin_transposed, h_muISO_SF2D[i]->GetBinContent(i_bin));
                 h_temp_iso->SetBinError(  i_bin_transposed, h_muISO_SF2D[i]->GetBinError(i_bin));
               }
             }

             h_muID_SF2D[i] = h_temp;
             h_muID_SF2D[i]->SetDirectory(0);
             h_muISO_SF2D[i] = h_temp_iso;
             h_muISO_SF2D[i]->SetDirectory(0);
           }
         }
         else if (year.find("2017")!=std::string::npos){
           // preliminary sys unc. available!
           TFile f_muID("input/muon_SF/2017/RunBCDEF_SF_ID_syst_muon2017_TOBEUPDATED.root","read");
           h_muID_SF2D[0] = (TH2D*)f_muID.Get("NUM_LooseID_DEN_genTracks_pt_abseta");
           h_muID_SF2D[1] = (TH2D*)f_muID.Get("NUM_MediumID_DEN_genTracks_pt_abseta");
           h_muID_SF2D[2] = (TH2D*)f_muID.Get("NUM_TightID_DEN_genTracks_pt_abseta");
           for (auto i : h_muID_SF2D) i->SetDirectory(0);
           f_muID.Close();

           //Muon ISO SF
           // preliminary sys unc. available!
           TFile f_muISO("input/muon_SF/2017/RunBCDEF_SF_ISO_syst_muon_2017_TOBEUPDATED.root","read");
           h_muISO_SF2D[0] = (TH2D*)f_muISO.Get("NUM_LooseRelIso_DEN_LooseID_pt_abseta");
           h_muISO_SF2D[1] = (TH2D*)f_muISO.Get("NUM_LooseRelIso_DEN_MediumID_pt_abseta");
           h_muISO_SF2D[2] = (TH2D*)f_muISO.Get("NUM_LooseRelIso_DEN_TightIDandIPCut_pt_abseta");
           for (auto i : h_muISO_SF2D) i->SetDirectory(0);
           f_muISO.Close();
         }
         else if (year.find("2018")!=std::string::npos){
           //contains stat and sys uncertainty too! 
           TFile f_muID("input/muon_SF/2018/RunABCD_SF_ID_muon2018.root","read");
           h_muID_SF2D[0] = (TH2D*)f_muID.Get("NUM_LooseID_DEN_TrackerMuons_pt_abseta");
           h_muID_SF2D[1] = (TH2D*)f_muID.Get("NUM_MediumID_DEN_TrackerMuons_pt_abseta");
           h_muID_SF2D[2] = (TH2D*)f_muID.Get("NUM_TightID_DEN_TrackerMuons_pt_abseta");
           for (auto i : h_muID_SF2D) i->SetDirectory(0);
           f_muID.Close();

           //Muon ISO SF
           //contains stat and sys uncertainty too! 
           TFile f_muISO("input/muon_SF/2018/RunABCD_SF_ISO_muon2018.root","read");
           h_muISO_SF2D[0] = (TH2D*)f_muISO.Get("NUM_LooseRelIso_DEN_LooseID_pt_abseta");
           h_muISO_SF2D[1] = (TH2D*)f_muISO.Get("NUM_LooseRelIso_DEN_MediumID_pt_abseta");
           h_muISO_SF2D[2] = (TH2D*)f_muISO.Get("NUM_LooseRelIso_DEN_TightIDandIPCut_pt_abseta");
           for (auto i : h_muISO_SF2D) i->SetDirectory(0);
           f_muISO.Close();
         }

         //Loading btag efficiency file, fill efficiency histograms
         if (btag_file.size()>0) {
           if (is_debug) cout<<"Loading btag efficiencies"<<endl;
           string btag_fname=btag_file;
           if (btag_file.compare("hardcoded")==0) {
             string pretag="/data/BTagEff/nanoAODv5/";
             string tag="BTagEff_";
             if (temp_f.find("DYJetsToLL_Pt")!=std::string::npos) tag+="DYJetsToLL_Pt_merged";
             else if (temp_f.find("DYJetsToLL_M-10to50")!=std::string::npos) tag+="DYJetsToLL_M-10to50";
             else if (temp_f.find("DYJetsToLL")!=std::string::npos) tag+="DYJetsToLL";
             else if (temp_f.find("WGJets_MonoPhoton_PtG-40to130")!=std::string::npos) tag+="WGJets_MonoPhoton_PtG-40to130";
             else if (temp_f.find("WGJets")!=std::string::npos) tag+="WGJets";
             else if (temp_f.find("TTGJets")!=std::string::npos) tag+="TTGJets";
             else if (temp_f.find("GJets_DR-0p4")!=std::string::npos) tag+="GJets_DR-0p4_HT_merged";
             else if (temp_f.find("GJets")!=std::string::npos) tag+="GJets_HT_merged";
             else if (temp_f.find("QCD")!=std::string::npos) tag+="QCD_HT_merged";
             else if (temp_f.find("ST_s-channel_4f_hadronicDecays")!=std::string::npos) tag+="ST_s-channel_hadronicDecays";
             else if (temp_f.find("ST_s-channel_leptonDecays")!=std::string::npos) tag+="ST_s-channel_leptonDecays";
             else if (temp_f.find("ST_s-channel")!=std::string::npos) tag+="ST_s-channel";
             else if (temp_f.find("ST_t-channel_antitop")!=std::string::npos) tag+="ST_t-channel_antitop";
             else if (temp_f.find("ST_t-channel_top")!=std::string::npos) tag+="ST_t-channel_top";
             else if (temp_f.find("ST_tW_antitop")!=std::string::npos) tag+="ST_tW_antitop";
             else if (temp_f.find("ST_tW_top")!=std::string::npos) tag+="ST_tW_top";
             else if (temp_f.find("TTGamma_Hadronic")!=std::string::npos) tag+="TTGamma_Hadronic";
             else if (temp_f.find("TTGamma_Dilept")!=std::string::npos) tag+="TTGamma_Dilept_merged";
             else if (temp_f.find("TTGamma_SingleLept")!=std::string::npos) tag+="TTGamma_SingleLept_merged";
             else if (temp_f.find("TTJets")!=std::string::npos) tag+="TTJets";
             else if (temp_f.find("TTTo2L2Nu")!=std::string::npos) tag+="TTTo2L2Nu";
             else if (temp_f.find("TTToSemiLeptonic")!=std::string::npos) tag+="TTToSemiLeptonic";
             else if (temp_f.find("WJetsToLNu")!=std::string::npos) tag+="WJetsToLNu_HT_merged";
             else if (temp_f.find("WJetsToQQ_HT")!=std::string::npos) tag+="WJetsToQQ_HT_merged";
             else if (temp_f.find("WJetsToQQ")!=std::string::npos) tag+="WJetsToQQ";
             else if (temp_f.find("WWG")!=std::string::npos) tag+="WWG";
             else if (temp_f.find("WW")!=std::string::npos) tag+="WW";
             else if (temp_f.find("WZ")!=std::string::npos) tag+="WZ";
             else if (temp_f.find("ZGTo2LG")!=std::string::npos) tag+="ZGTo2LG";
             else if (temp_f.find("ZGTo2NuG")!=std::string::npos) tag+="ZGTo2NuG";
             else if (temp_f.find("ZJetsToNuNu")!=std::string::npos) tag+="ZJetsToNuNu_HT_merged";
             else if (temp_f.find("ZJetsToQQ_HT")!=std::string::npos) tag+="ZJetsToQQ_HT_merged";
             else if (temp_f.find("ZJetsToQQ")!=std::string::npos) tag+="ZJetsToQQ";
             else if (temp_f.find("ZZ")!=std::string::npos) tag+="ZZ";
             else if (temp_f.find("T5qqqqHg")==std::string::npos && temp_f.find("TChiNG")==std::string::npos) cout<<"No btag eff file found for file "<<temp_f<<endl;;
             if (year.find("2016")!=std::string::npos) btag_fname=pretag+"hadded/2016/"+tag+".root"; //temporarly added until we have new btag efficiency files for UL16 & APV
             else btag_fname=pretag+"hadded/"+year+"/"+tag+".root";
             if (temp_f.find("T5qqqqHg")!=std::string::npos) btag_fname=pretag+"signal/tree_"+year+"_all_out.root";
             if (temp_f.find("TChiNG")!=std::string::npos) btag_fname=pretag+"signal/TChiNg_tree_"+year+"_all_out.root";
             if (!is_quiet) cout<<"btag efficiency file "<<btag_fname<<endl;
           }
           TFile f_btag(btag_fname.c_str(),"read");
           eff_b_Deep_L = new TEfficiency(*(TH2D*)f_btag.Get("h_b_Deep_L"),*(TH2D*)f_btag.Get("h_allAK4bjets"));
           eff_b_Deep_M = new TEfficiency(*(TH2D*)f_btag.Get("h_b_Deep_M"),*(TH2D*)f_btag.Get("h_allAK4bjets"));
           eff_b_Deep_T = new TEfficiency(*(TH2D*)f_btag.Get("h_b_Deep_T"),*(TH2D*)f_btag.Get("h_allAK4bjets"));
           eff_c_Deep_L = new TEfficiency(*(TH2D*)f_btag.Get("h_c_Deep_L"),*(TH2D*)f_btag.Get("h_allAK4cjets"));
           eff_c_Deep_M = new TEfficiency(*(TH2D*)f_btag.Get("h_c_Deep_M"),*(TH2D*)f_btag.Get("h_allAK4cjets"));
           eff_c_Deep_T = new TEfficiency(*(TH2D*)f_btag.Get("h_c_Deep_T"),*(TH2D*)f_btag.Get("h_allAK4cjets"));
           eff_l_Deep_L = new TEfficiency(*(TH2D*)f_btag.Get("h_l_Deep_L"),*(TH2D*)f_btag.Get("h_allAK4ljets"));
           eff_l_Deep_M = new TEfficiency(*(TH2D*)f_btag.Get("h_l_Deep_M"),*(TH2D*)f_btag.Get("h_allAK4ljets"));
           eff_l_Deep_T = new TEfficiency(*(TH2D*)f_btag.Get("h_l_Deep_T"),*(TH2D*)f_btag.Get("h_allAK4ljets"));
           f_btag.Close();
         }

         //L1prefire maps
         if (year.find("2016")!=std::string::npos) {
           if (is_debug) cout<<"Loading L1 prefire maps"<<endl;
           TFile f_L1_phomap_2016("input/L1prefiring_photonpt_2016BtoH.root","read");
           h_L1prefire_phoMap = (TH2D*)f_L1_phomap_2016.Get("L1prefiring_photonpt_2016BtoH");
           h_L1prefire_phoMap->SetDirectory(0);
           f_L1_phomap_2016.Close();
           TFile f_L1_jetmap_2016("input/L1prefiring_jetpt_2016BtoH.root","read");
           h_L1prefire_jetMap = (TH2D*)f_L1_jetmap_2016.Get("L1prefiring_jetpt_2016BtoH");
           h_L1prefire_jetMap->SetDirectory(0);
           f_L1_jetmap_2016.Close();
         }
         else if (year.find("2017")!=std::string::npos) {
           if (is_debug) cout<<"Loading L1 prefire maps"<<endl;
           TFile f_L1_phomap_2017("input/L1prefiring_photonpt_2017BtoF.root","read");
           h_L1prefire_phoMap = (TH2D*)f_L1_phomap_2017.Get("L1prefiring_photonpt_2017BtoF");
           h_L1prefire_phoMap->SetDirectory(0);
           f_L1_phomap_2017.Close();
           TFile f_L1_jetmap_2017("input/L1prefiring_jetpt_2017BtoF.root","read");
           h_L1prefire_jetMap = (TH2D*)f_L1_jetmap_2017.Get("L1prefiring_jetpt_2017BtoF");
           h_L1prefire_jetMap->SetDirectory(0);
           f_L1_jetmap_2017.Close();
         }
         //ISR MC
         if (year.find("2016")!=std::string::npos) {
           if (temp_f.find("TTJets")!=std::string::npos) ISR_MC=1;
           else if (temp_f.find("TTGamma_Hadronic")!=std::string::npos) ISR_MC=2;
           else if (temp_f.find("TTGJets")!=std::string::npos) ISR_MC=3;
           else if (temp_f.find("T5qqqqHg")!=std::string::npos) ISR_MC=4;
           else if (temp_f.find("TChiNG")!=std::string::npos) ISR_MC=5;
           else ISR_MC=0;
         }
         else if (temp_f.find("T5qqqqHg")!=std::string::npos) ISR_MC=4;
         else ISR_MC=0;
         if (ISR_MC){
           if (is_debug) cout<<"Loading ISR reweighting files"<<endl;
           //ISR reweight files
           string isr_file="", y=(year.find("2016")!=std::string::npos) ? "2016" : year;//temporary needed for 2016, since there's no separate APV/VFP D_factor calculated
           if (ISR_MC==1) isr_file="input/ISR_reweight/D_factor_ttjets_"+y+"_nophotonmatch.root";
           if (ISR_MC==2) isr_file="input/ISR_reweight/D_factor_ttghadronic_"+y+"_nophotonmatch.root";
           if (ISR_MC==3) isr_file="input/ISR_reweight/D_factor_ttgjets_"+y+"_nophotonmatch.root";
           if (ISR_MC==4) isr_file="input/ISR_reweight/D_factor_signal_"+y+"_nophotonmatch.root";
           if (ISR_MC==5) isr_file="input/ISR_reweight/D_factor_signal_"+y+"_ew.root";
           TFile f_ISR(isr_file.c_str(),"read");
           if (ISR_MC!=4 && ISR_MC!=5) {
             h_ISR_D = (TH1D*)f_ISR.Get("h_Dfactor");
             h_ISR_D->SetDirectory(0);
           }
           else {
             TIter next(f_ISR.GetDirectory("singleBin_noPU")->GetListOfKeys());
             TKey *key;
             while ((key = (TKey*)next())) {
               TH1D *h=(TH1D*)key->ReadObj();
               h->SetDirectory(0);
               string s =h->GetName(); //h_Dfactor_2800_2550
               if (ISR_MC==4) {
                 size_t g_first =  s.find("_",3);
                 size_t g_last = s.find("_",g_first+1);
                 string g = s.substr(g_first+1,g_last-g_first-1);
                 string n = s.substr(g_last+1,n.size()-g_last);
                 m_ISR_D[pair<int,int> (stoi(g),stoi(n))] = h;
               }
               else if (ISR_MC==5) {
                 string n = s.substr(s.find("_",3)+1);
                 m_ISR_D[pair<int,int> (stoi(n),1)] = h;
               }
             }
           }
           f_ISR.Close();
         }
       }
     }

     //ISR jet counting (https://github.com/manuelfs/babymaker/blob/0136340602ee28caab14e3f6b064d1db81544a0a/bmaker/plugins/bmaker_full.cc#L1268-L1295)
     int n_isr_jets=0;
     double w_isr=1;
     if (!isData && ISR_MC) {
       if (is_debug) cout<<"Calculating ISR jets"<<endl;
       for (unsigned int i=0;i<nJet;i++) {
         if (abs(Jet_eta[i])>2.4 ||  !(Jet_jetId[i]>>1&1) || Jet_pt_nom[i]<30 ) continue;
         //cleaning jet from electrons, muons  and photons
         bool lepton_photon_match=false;
         for (unsigned int j=0;j<nElectron;j++) {
           if (Electron_pt[j]<20 || abs(Electron_eta[j])>2.5 || Electron_miniPFRelIso_all[j]>0.1) continue;
           if (deltaR(Electron_phi[j],Jet_phi[i],Electron_eta[j],Jet_eta[i])<0.4) {lepton_photon_match=true; break;}
         }
         for (unsigned int j=0;j<nMuon;j++) {
           if (Muon_pt[j]<20 || abs(Muon_eta[j])>2.4 || Muon_miniPFRelIso_all[j]>0.2) continue;
           if (deltaR(Muon_phi[j],Jet_phi[i],Muon_eta[j],Jet_eta[i])<0.4) {lepton_photon_match=true; break;}
         }
         for (unsigned int j=0;j<nPhoton;j++){
           if (!Photon_isScEtaEB[j] || !Photon_isScEtaEE[j] || Photon_pixelSeed[j]!=0 || Photon_pt[j]<40 || Photon_cutBased[i]>=1) continue;
           if (deltaR(Photon_phi[j],Jet_phi[i],Photon_eta[j],Jet_eta[i])<0.4) {lepton_photon_match=true; break;}
         }
         if (lepton_photon_match) continue;
         //matching with MC particles
         bool matched=false;
         for (unsigned int j=0;j<nGenPart;j++){
           if (matched) break;
           if (abs(GenPart_pdgId[j])>5 || GenPart_status[j]!=23) continue;
           int momid = abs(GenPart_pdgId[GenPart_genPartIdxMother[j]]);
           if (!(momid==6 || momid==23 || momid==24 || momid==25 || momid>1e6)) continue;
           for (unsigned int k=0;k<nGenPart;k++){
             if (GenPart_genPartIdxMother[k] != j) continue;
             if (deltaR(GenPart_phi[k],Jet_phi[i],GenPart_eta[k],Jet_eta[i])<0.3) {matched=true; 
               //  printf("Index %-2i PDGID %-8d mcPt %-12f Eta %-9f Phi %-9f mom %-8d momPt %-9f  momEta %-9f  momPhi %-9f status %-2i flag %-9s gmom %-8d\n",k,GenPart_pdgId[k],GenPart_pt[k],GenPart_eta[k],GenPart_phi[k],GenPart_pdgId[GenPart_genPartIdxMother[k]],GenPart_pt[GenPart_genPartIdxMother[k]],GenPart_eta[GenPart_genPartIdxMother[k]],GenPart_phi[GenPart_genPartIdxMother[k]],GenPart_status[k],bitset<9>(GenPart_statusFlags[k]).to_string().c_str(),GenPart_pdgId[GenPart_genPartIdxMother[GenPart_genPartIdxMother[k]]]);
               break;}
           }
         }
         if (!matched) n_isr_jets++;
       }

       //ISR pt for EW
       double isr_pt=0;
       if (ISR_MC==5) {
         std::vector<unsigned int> neutralino_indexes;
         for(unsigned int i=0;i<nGenPart;i++){
           if((abs(GenPart_pdgId[i])==1000023 || (abs(GenPart_pdgId[i])==1000025 )) && GenPart_status[i]==22 ){
             if (GenPart_genPartIdxMother[i]!=-1 && (abs(GenPart_pdgId[GenPart_genPartIdxMother[i]])!=1000023 || abs(GenPart_pdgId[GenPart_genPartIdxMother[i]])!=1000025)){
               neutralino_indexes.push_back(i);
             }
           }
         }

         if (neutralino_indexes.size()!=2){
           std::cout<<"neutralino indexes size incorrect! size="<<neutralino_indexes.size()<<std::endl;
           for (int i : neutralino_indexes) std::cout<<i<<" "<<GenPart_genPartIdxMother[i]<<" "<<abs(GenPart_pdgId[i])<<" "<<abs(GenPart_pdgId[GenPart_genPartIdxMother[i]])<<std::endl;
           for(unsigned int i=0;i<nGenPart;i++) std::cout<<i<<" "<<GenPart_genPartIdxMother[i]<<" "<<abs(GenPart_pdgId[i])<<" "<<abs(GenPart_pdgId[GenPart_genPartIdxMother[i]])<<std::endl;
           std::cout<<"Not correct number of chi! "+std::to_string(neutralino_indexes.size())<<std::endl;
           break;
         } 

         int i_chi1 = neutralino_indexes[0];
         int i_chi2 = neutralino_indexes[1];
         TLorentzVector chi1, chi2;
         chi1.SetPtEtaPhiM(	GenPart_pt[i_chi1],
             GenPart_eta[i_chi1],
             GenPart_phi[i_chi1],
             GenPart_mass[i_chi1]   );
         chi2.SetPtEtaPhiM(	GenPart_pt[i_chi2],
             GenPart_eta[i_chi2],
             GenPart_phi[i_chi2],
             GenPart_mass[i_chi2]   );

         isr_pt = (chi1+chi2).Pt();
       }

       //ISR reweight
       vector<double> nISRjet2correction;
       vector<double> nISRjet2unceratinty;
       if (year.find("2016")!=std::string::npos) {
         nISRjet2correction = {1.0, 0.920, 0.821, 0.715, 0.662, 0.561, 0.511};
         nISRjet2unceratinty= {0.0, 0.040, 0.090, 0.143, 0.169, 0.219, 0.244};
         if (ISR_MC==5) {
           nISRjet2correction.clear(); nISRjet2unceratinty.clear();
           nISRjet2correction = {1.0, 1.052, 1.179, 1.150, 1.057, 1.000, 0.912, 0.783};
           for (auto i : nISRjet2correction) nISRjet2unceratinty.push_back(i-1);
         }
       }
       else {
         nISRjet2correction = {1.0, 0.914, 0.796, 0.698, 0.602, 0.579, 0.580};
         nISRjet2unceratinty= {0.0, 0.043, 0.102, 0.151, 0.199, 0.211, 0.210};
       }
       int njets=(n_isr_jets<6) ? n_isr_jets : 6;
       unsigned int isr_pt_bin=0;
       double D=1;
       double D_err=0;
       if (ISR_MC!=4 && ISR_MC!=5) {
         D=h_ISR_D->GetBinContent(1);
         D_err=h_ISR_D->GetBinError(1);
       }
       else {
         D=m_ISR_D[mass_pair]->GetBinContent(1);
         D_err=m_ISR_D[mass_pair]->GetBinError(1);
       }
       int sign=(ISR_whichSF==1) ? 1 : (ISR_whichSF==2) ? -1 : 0;
       if (ISR_MC!=5) w_isr=(nISRjet2correction[njets]+sign*nISRjet2unceratinty[njets])*(D-sign*D_err);
       else {
         vector<double> pt_limits    = {  0,    50,   100,   150,   200,   300,   400,   600};
         for (unsigned int i=1; i<pt_limits.size(); i++){
           if (isr_pt<pt_limits[i]){
             isr_pt_bin = i-1;
             break;
           }
         }
         w_isr=(nISRjet2correction[isr_pt_bin]+sign*nISRjet2unceratinty[isr_pt_bin])*(D-sign*D_err);
       }
       if (is_debug) cout<<"Applying ISR weights"<<endl;
       w*=w_isr;
       //cout<<"nisr "<<njets<<" syst "<<ISR_whichSF<<" w_isr "<<w_isr<<" = "<<nISRjet2correction[njets]<<" * "<<D<<endl;
       //cout<<"isrpt "<<isr_pt<<" syst "<<ISR_whichSF<<" w_isr "<<w_isr<<" = "<<nISRjet2correction[isr_pt_bin]<<" * "<<D<<endl;
     }

     //object definitions
     if (is_debug) cout<<"Object definitions"<<endl;
     int leadpt_ak4=-1, leadpt_ak8=-1, highDDBvL=-1;
     vector<int> passPhoL, passPhoM, passPhoT, passPhoMVA80, passPhoMVA90, passPhotons;
     vector<int> passJet, passAK8Jet;
     vector<int> passEleV, passEleL, passEleM, passEleT, passElectrons;
     vector<int> passMuL, passMuM, passMuT, passMuNO, passMuons;
     vector<int> passTauL, passTauM, passTauT, passTaus, passIso;
     vector<int> passElePhoL, passElePhoM, passElePhoT, passElePhoMVA80, passElePhoMVA90, passElePhotons, passEleNO;
     vector<int> passFREleL, passFREleM, passFREleT;
     vector<float> jetSmearedPt, jetSmearedMass, jetbtagDeepFlavB, AK8JetSmearedPt, AK8JetSmearedMass;
     vector<float> tauPt;
     map<int,char> passDDBvL, passDeep;
     HT_before=0; EMHT_before=0; HT_after=0; EMHT_after=0;
     AK8HT_before=0; AK8EMHT_before=0; AK8HT_after=0; AK8EMHT_after=0;
     ST=0; ST_G=0; MT=0; nonHiggsJet=-1;
     nleadElePho=-1;
     nleadFREleL=-1; nleadFREleM=-1; nleadFREleT=-1;
     nleadPho=-1; nleadEle=-1; nleadMu=-1; nleadTau=-1;
     nleadEleV=-1; nleadEleL=-1; nleadEleM=-1; nleadEleT=-1;
     nleadMuL=-1; nleadMuM=-1; nleadMuT=-1;
     nleadTauL=-1; nleadTauM=-1; nleadTauT=-1;
     ele_VETOSF=1;
     for (int i=0;i<3;i++) {pho_SF[i]=1; mu_SF[i]=1; tau_SF[i]=1;}
     for (int i=0;i<4;i++) ele_SF[i]=1;
     memset(bcounterDDBvL,0,sizeof bcounterDDBvL);
     memset(bcounterDeep,0,sizeof bcounterDeep);
     double nonPrefiringProbability[3]={1,1,1};
     if (!_fastSim && year.find("2018")==std::string::npos) {nonPrefiringProbability[0]=L1PreFiringWeight_Nom;nonPrefiringProbability[1]=L1PreFiringWeight_Up;nonPrefiringProbability[2]=L1PreFiringWeight_Dn;}
     phoET.clear();
     //muon
     for (unsigned int i=0;i<nMuon;i++) {
       if (Muon_pt[i]>mu_pt && abs(Muon_eta[i])<2.4 && Muon_sip3d[i]<4 && Muon_dz[i]<0.1 && Muon_dxy[i]<0.05 && Muon_miniPFRelIso_all[i]<0.2) {
         if (Muon_looseId[i]) passMuL.push_back(i);
         if (Muon_mediumId[i]) passMuM.push_back(i);
         if (Muon_tightId[i]) passMuT.push_back(i);
         if (!Muon_looseId[i]) passMuNO.push_back(i);
       }
     }
     (whichMuon==0) ? passMuons=passMuL : (whichMuon==1) ? passMuons=passMuM : passMuons=passMuT;
     nPassMuL=passMuL.size();
     nPassMuM=passMuM.size();
     nPassMuT=passMuT.size();
     nPassMuNO=passMuNO.size();
     if (passMuons.size() != 0) nleadMu=passMuons[0];
     if (passMuL.size() != 0) nleadMuL=passMuL[0];
     if (passMuM.size() != 0) nleadMuM=passMuM[0];
     if (passMuT.size() != 0) nleadMuT=passMuT[0];
     if (is_debug) cout<<"Muon object done"<<endl;
     //muon SF
     if (!isData){
       int iter[3]={-1,-1,-1};
       if (nPassMuL>0) iter[0]=passMuL.at(0);
       if (nPassMuM>0) iter[1]=passMuM.at(0);
       if (nPassMuT>0) iter[2]=passMuT.at(0);
       for (int i=0;i<3;i++) {
         if (iter[i]!=-1){
           float pt = ( Muon_pt[iter[i]]< 20)? 20 : (Muon_pt[iter[i]]< 100) ? Muon_pt[iter[i]] : 100 ; //Histo range is: 20-120, highest bin 60-120
           float eta = (year.find("2016")!=std::string::npos) ? Muon_eta[iter[i]] : abs(Muon_eta[iter[i]]);
           double id_sf=0, iso_sf=0, syst_id=0, syst_iso=0;
           int sign_id=0, sign_iso=0;
           id_sf=h_muID_SF2D[i]->GetBinContent(h_muID_SF2D[i]->FindBin(pt,eta));
           syst_id=h_muID_SF2D[i]->GetBinError(h_muID_SF2D[i]->FindBin(pt,eta));
           iso_sf=h_muISO_SF2D[i]->GetBinContent(h_muISO_SF2D[i]->FindBin(pt,eta));
           syst_iso=h_muISO_SF2D[i]->GetBinError(h_muISO_SF2D[i]->FindBin(pt,eta));
           (muID_whichSF==1) ? sign_id=1 : (muID_whichSF==2) ? sign_id=-1 : sign_id=0;
           (muISO_whichSF==1) ? sign_iso=1 : (muISO_whichSF==2) ? sign_iso=-1 : sign_iso=0;
           mu_SF[i]=(id_sf+sign_id*syst_id)*(iso_sf+sign_iso*syst_iso);
           if (id_sf==0 || iso_sf==0) cout<<i<<" id_sf "<<id_sf<<" iso_sf "<<iso_sf<<" mu_SF "<<mu_SF[i]<<endl;
         }
       }
       if (is_debug) cout<<"Muon SF applied"<<endl;
     }
     //electron
     for (unsigned int i=0;i<nElectron;i++) {
       bool passOverlap=true;
       for (auto j : passMuons) if (deltaR(Electron_phi[i],Muon_phi[j],Electron_eta[i],Muon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       if (Electron_pt[i]>e_pt && abs(Electron_eta[i])<2.5 && Electron_miniPFRelIso_all[i]<0.2) {
         if (Electron_cutBased[i]>=2) passFREleL.push_back(i);
         if (Electron_cutBased[i]>=3) passFREleM.push_back(i);
         if (Electron_cutBased[i]>=4) passFREleT.push_back(i);
         if (!passOverlap) continue;
         if (Electron_cutBased[i]>=1) passEleV.push_back(i);
         if (Electron_cutBased[i]>=2) passEleL.push_back(i);
         if (Electron_cutBased[i]>=3) passEleM.push_back(i);
         if (Electron_cutBased[i]>=4) passEleT.push_back(i);
         if (Electron_cutBased[i]<=1) passEleNO.push_back(i); //vetoElectron is also considered no electron
       }
     }
     (whichElectron==0) ? passElectrons=passEleV : (whichElectron==1) ? passElectrons=passEleL : (whichElectron==2) ? passElectrons=passEleM : passElectrons=passEleT;
     nPassEleV=passEleV.size();
     nPassEleL=passEleL.size();
     nPassEleM=passEleM.size();
     nPassEleT=passEleT.size();
     nPassEleNO=passEleNO.size();
     if (passElectrons.size() != 0) nleadEle=passElectrons[0];
     if (passEleV.size() != 0) nleadEleV=passEleV[0];
     if (passEleL.size() != 0) nleadEleL=passEleL[0];
     if (passEleM.size() != 0) nleadEleM=passEleM[0];
     if (passEleT.size() != 0) nleadEleT=passEleT[0];
     nPassFREleL=passFREleL.size();
     nPassFREleM=passFREleM.size();
     nPassFREleT=passFREleT.size();
     if (nPassFREleL != 0) nleadFREleL=passFREleL[0];
     if (nPassFREleM != 0) nleadFREleM=passFREleM[0];
     if (nPassFREleT != 0) nleadFREleT=passFREleT[0];
     if (is_debug) cout<<"Electron object done"<<endl;

     //Calculate electron SFs
     if (!isData) {
       double id_sf=0, rec_sf=0;
       string id_whichsf="sf", rec_whichsf="sf", which_id="";
       (eleID_whichSF==1) ? id_whichsf="sfup" : (eleID_whichSF==2) ? id_whichsf="sfdown" : id_whichsf="sf";
       (eleRec_whichSF==1) ? rec_whichsf="sfup" : (eleRec_whichSF==2) ? rec_whichsf="sfdown" : rec_whichsf="sf";
       (whichElectron==0) ? which_id="Veto" : (whichElectron==1) ? which_id="Loose": (whichElectron==2) ? which_id="Medium" : which_id="Tight";
       if (passElectrons.size()!=0){
         double pt=Electron_pt[passElectrons[0]], eta=Electron_eta[passElectrons[0]];
         if (pt<10) pt=10; //There are no SFs below 10 GeV
         id_sf = cset_ele->at("UL-Electron-ID-SF")->evaluate({year,id_whichsf,which_id,eta, pt});
         string temprec = (pt>20) ? "RecoAbove20" : "RecoBelow20";
         rec_sf = cset_ele->at("UL-Electron-ID-SF")->evaluate({year,rec_whichsf,temprec,eta, pt});
         ele_SF[whichElectron]=id_sf*rec_sf;
         if (id_sf==0 || rec_sf==0) cout<<"id_sf "<<id_sf<<"*"<<rec_sf<<"="<<id_sf*rec_sf<<" finalSF= "<<ele_SF[0]<<endl;
       }
       if (is_debug) cout<<"Electron SF applied"<<endl;
     }

     //Tau
     for (unsigned int i=0;i<nTau;i++) {
       bool passOverlap=true;
       double pt = Tau_pt[i], eta = Tau_eta[i];
       //Tau energy scale (TES) correction
       if (!isData) {
         int dm = Tau_decayMode[i], gen = Tau_genPartFlav[i];
         string tes_whichsf="nom";
         (tauTES_whichSF==1) ? tes_whichsf="up" : (tauTES_whichSF==2) ? tes_whichsf="down" : tes_whichsf="nom";
         if (dm<5 || dm>7) pt*=cset_tau->at("tau_energy_scale")->evaluate({pt,eta,dm,gen,"DeepTau2017v2p1",tes_whichsf});
       }
       tauPt.push_back(pt);
       for (auto j : passMuons) if (deltaR(Tau_phi[i],Muon_phi[j],Tau_eta[i],Muon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passElectrons) if (deltaR(Tau_phi[i],Electron_phi[j],Tau_eta[i],Electron_eta[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
       if (pt>tau_pt && abs(Tau_eta[i])<2.3) {
         if (Tau_idDeepTau2017v2p1VSjet[i]>>3&1 && Tau_idDeepTau2017v2p1VSe[i]>>3&1 && Tau_idDeepTau2017v2p1VSmu[i]>>1&1) passTauL.push_back(i);
         if (Tau_idDeepTau2017v2p1VSjet[i]>>4&1 && Tau_idDeepTau2017v2p1VSe[i]>>4&1 && Tau_idDeepTau2017v2p1VSmu[i]>>2&1) passTauM.push_back(i);
         if (Tau_idDeepTau2017v2p1VSjet[i]>>5&1 && Tau_idDeepTau2017v2p1VSe[i]>>5&1 && Tau_idDeepTau2017v2p1VSmu[i]>>3&1) passTauT.push_back(i);
       }
     }
     (whichTau==0) ? passTaus=passTauL : (whichTau==1) ? passTaus=passTauM : passTaus=passTauT;
     nPassTauL=passTauL.size();
     nPassTauM=passTauM.size();
     nPassTauT=passTauT.size();
     //nPassTauNO=passTauNO.size();
     if (passTaus.size() != 0) nleadTau=passTaus[0];
     if (passTauL.size() != 0) nleadTauL=passTauL[0];
     if (passTauM.size() != 0) nleadTauM=passTauM[0];
     if (passTauT.size() != 0) nleadTauT=passTauT[0];

     if (is_debug) cout<<"Tau object done"<<endl;

     if (!isData) {
       //Tau SF
       if (passTaus.size() != 0) {
         string id_whichsf="nom", which_id="Loose";
         (tau_whichSF==1) ? id_whichsf="up" : (eleID_whichSF==2) ? id_whichsf="down" : id_whichsf="nom";
         (whichTau==0) ? which_id="Loose": (whichTau==1) ? which_id="Medium" : which_id="Tight";

         double pt = tauPt[nleadTau], eta = Tau_eta[nleadTau];
         int dm = Tau_decayMode[nleadTau], gen = Tau_genPartFlav[nleadTau];
         double jet_sf = cset_tau->at("DeepTau2017v2p1VSjet")->evaluate({pt,dm,gen,which_id,id_whichsf,"pt"});
         double e_sf = cset_tau->at("DeepTau2017v2p1VSe")->evaluate({eta,gen,which_id,id_whichsf});
         double mu_sf = cset_tau->at("DeepTau2017v2p1VSmu")->evaluate({eta,gen,which_id,id_whichsf});
         tau_SF[whichTau]=jet_sf*e_sf*mu_sf;
         if (tau_SF[0]==0 || tau_SF[1]==0 || tau_SF[2]==0) cout<<"nPassTauL "<<nPassTauL<<" nPassTauM "<<nPassTauM<<" nPassTauT "<<nPassTauT<<" tau L SF "<<tau_SF[0]<<" tau M SF "<<tau_SF[1]<<" tau T SF "<<tau_SF[2]<<endl;

         if (is_debug) cout<<"Tau SF applied"<<endl;
       }
     }
     //photon
     for (unsigned int i=0;i<nPhoton;i++){
       //Systematics for Egamma scaling
       double pt = Photon_pt[i];
       (Egamma_scale_whichSF ==1) ? pt+=Photon_dEscaleUp[i] : (Egamma_scale_whichSF ==2) ? pt+=Photon_dEscaleDown[i] : pt=pt;
       (Egamma_smear_whichSF ==1) ? pt+=Photon_dEsigmaUp[i] : (Egamma_smear_whichSF ==2) ? pt+=Photon_dEsigmaDown[i] : pt=pt;

       phoET.push_back(pt);
       //L1prefire correction
       if (_fastSim && year.find("2018")==std::string::npos && Photon_pt[i]>20 && abs(Photon_eta[i])>2 && abs(Photon_eta[i])<3) {
         double max= h_L1prefire_phoMap->GetYaxis()->GetBinLowEdge(h_L1prefire_phoMap->GetNbinsY());
         double pt = (Photon_pt[i]>max) ? max-0.01 : Photon_pt[i];
         double prefireProb = h_L1prefire_phoMap->GetBinContent(h_L1prefire_phoMap->FindBin(Photon_eta[i],pt));
         double stat = h_L1prefire_phoMap->GetBinError(h_L1prefire_phoMap->FindBin(Photon_eta[i],pt));
         double syst = prefireProb*0.2;
         nonPrefiringProbability[0]*=(1-prefireProb);
         nonPrefiringProbability[1]*=(1-std::min(1.,prefireProb+sqrt(pow(stat,2)+pow(syst,2))));
         nonPrefiringProbability[2]*=(1-std::max(0.,prefireProb-sqrt(pow(stat,2)+pow(syst,2))));
       }
       bool passOverlap=true;
       for (auto j : passMuons) if (deltaR(Photon_phi[i],Muon_phi[j],Photon_eta[i],Muon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passElectrons) if (deltaR(Photon_phi[i],Electron_phi[j],Photon_eta[i],Electron_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passTaus) if (deltaR(Photon_phi[i],Tau_phi[j],Photon_eta[i],Tau_eta[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
       if ((Photon_isScEtaEB[i] || Photon_isScEtaEE[i]) && Photon_pixelSeed[i]==0 && phoET[i]>100) {
         if (Photon_cutBased[i]>=1) passPhoL.push_back(i);
         if (Photon_cutBased[i]>=2) passPhoM.push_back(i);
         if (Photon_cutBased[i]>=3) passPhoT.push_back(i);
         if (Photon_mvaID_WP80[i]) passPhoMVA80.push_back(i);
         if (Photon_mvaID_WP90[i]) passPhoMVA90.push_back(i);
       }
       if ((Photon_isScEtaEB[i] || Photon_isScEtaEE[i]) && Photon_pixelSeed[i]!=0) {
         if (Photon_cutBased[i]>=1) passElePhoL.push_back(i);
         if (Photon_cutBased[i]>=2) passElePhoM.push_back(i);
         if (Photon_cutBased[i]>=3) passElePhoT.push_back(i);
         if (Photon_mvaID_WP80[i]) passElePhoMVA80.push_back(i);
         if (Photon_mvaID_WP90[i]) passElePhoMVA90.push_back(i);
       }
     }
     (whichPhoton==0) ? passPhotons=passPhoL : (whichPhoton==1) ? passPhotons=passPhoM : (whichPhoton==2) ? passPhotons=passPhoT : (whichPhoton==3) ? passPhotons=passPhoMVA80 : passPhotons=passPhoMVA90;
     (whichPhoton==0) ? passElePhotons=passElePhoL : (whichPhoton==1) ? passElePhotons=passElePhoM : (whichPhoton==2) ? passElePhotons=passElePhoT : (whichPhoton==3) ? passElePhotons=passElePhoMVA80 : passElePhotons=passElePhoMVA90;
     for (auto i : passPhotons) {
       if (phoET[i]>phoET[nleadPho]) nleadPho=i;
       EMHT_before+=phoET[i];
     }
     nPassElePhoL=passElePhoL.size();
     nPassElePhoM=passElePhoM.size();
     nPassElePhoT=passElePhoT.size();
     nPassElePhoMVA80=passElePhoMVA80.size();
     nPassElePhoMVA90=passElePhoMVA90.size();
     nPassPhoL=passPhoL.size();
     nPassPhoM=passPhoM.size();
     nPassPhoT=passPhoT.size();
     nPassPhoMVA80=passPhoMVA80.size();
     nPassPhoMVA90=passPhoMVA90.size();
     for (auto i : passElePhotons) if (phoET[i]>phoET[nleadElePho]) nleadElePho=i;
     if (_fakeRate==2 && passElePhotons.size() != 0) {
       nleadPho=nleadElePho;
       passPhotons=passElePhotons;
       nPassPhoL=passElePhotons.size();
     }
     EMHT_after=EMHT_before;
     AK8EMHT_before=EMHT_before;
     AK8EMHT_after=EMHT_before;
     if (is_debug) cout<<"Photon object done"<<endl;
     //Calculate photon SFs
     if (!isData) {
       double id_sf=0, pix_sf=0;
       string id_whichsf="sf", pix_whichsf="sf";
       (phoID_whichSF==1) ? id_whichsf="sfup" : (phoID_whichSF==2) ? id_whichsf="sfdown" : id_whichsf="sf";
       (phoPix_whichSF==1) ? pix_whichsf="sfup" : (phoPix_whichSF==2) ? pix_whichsf="sfdown" : pix_whichsf="sf";
       if (passPhotons.size()!=0){
         id_sf = cset_pho->at("UL-Photon-ID-SF")->evaluate({year,id_whichsf,"Loose",Photon_SCEta(nleadPho), phoET[nleadPho]});
         string pixtemp="";
         if (Photon_r9[nleadPho]>0.94) (Photon_isScEtaEB[nleadPho]) ? pixtemp="EBHighR9" : pixtemp="EEHighR9";
         else (Photon_isScEtaEB[nleadPho]) ? pixtemp="EBLowR9" : pixtemp="EELowR9";
         pix_sf = cset_pho->at("UL-Photon-PixVeto-SF")->evaluate({year,pix_whichsf,"Loose",pixtemp});
         pho_SF[0]=id_sf*pix_sf;
         //cout<<"photon "<<phoET[nleadPho]<<" "<<Photon_eta[nleadPho]<<" UL loose ID sf "<<id_sf<<" pix sf "<<pix_sf<<" total SF "<<pho_SF[0]<<endl;
       }
       if (is_debug) cout<<"Photon SF applied"<<endl;
     }
     //Applying Fake Rate
     if (_fakeRate) {
       if (_fakeRate==1 && nPassFREleL != 0) w*=h2_FR->GetBinContent(h2_FR->FindBin(Electron_eta[nleadFREleL],Electron_phi[nleadFREleL]));
       if (_fakeRate==2 && nPassElePhoL != 0) {
         double FRetaphi=h2_FR->GetBinContent(h2_FR->FindBin(Photon_eta[nleadElePho],Photon_phi[nleadElePho]));
         double FRvalue=FRetaphi*_C*(_A*PV_npvsGood+_B);
         //cout<<"etaphi "<<Photon_eta[nleadElePho]<<" "<<Photon_phi[nleadElePho]<<endl;
         //cout<<FRvalue<<" = "<<FRetaphi<<" * "<<_C<<" *("<<_A<<" * "<<PV_npvsGood<<" + "<<_B<<")"<<endl;
         w*=FRvalue;
       }
     }

     //IsoTrack
     for (unsigned int i=0;i<nIsoTrack;i++) {
       bool passOverlap=true;
       for (auto j : passPhotons) if (deltaR(IsoTrack_phi[i],Photon_phi[j],IsoTrack_eta[i],Photon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passElectrons) if (deltaR(IsoTrack_phi[i],Electron_phi[j],IsoTrack_eta[i],Electron_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passMuons) if (deltaR(IsoTrack_phi[i],Muon_phi[j],IsoTrack_eta[i],Muon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passTaus) if (deltaR(IsoTrack_phi[i],Tau_phi[j],IsoTrack_eta[i],Tau_eta[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
       if (abs(IsoTrack_pdgId[i])==11 || abs(IsoTrack_pdgId[i])==13) {if (IsoTrack_pt[i]<5) continue;}
       else if (IsoTrack_pt[i]<10) continue;
       double MT_iso;
       MT_iso=sqrt(2*MET_T1_pt*IsoTrack_pt[i]*(1-cos(abs(IsoTrack_phi[i]-MET_T1_phi))));
       if (MT_iso<100) passIso.push_back(i);
     }
     nPassIso=passIso.size();
     if (passIso.size() != 0) nleadIso=passIso[0];
     if (is_debug) cout<<"IsoTrack object done"<<endl;

     //jet ID
     bool vetoFastSim=false; //veto for fastsim unmatched jets https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSRecommendationsMoriond17#Cleaning_up_of_fastsim_jets_from
     for (unsigned int i=0;i<nJet;i++) {
       //L1prefire correction
       if (_fastSim && year.find("2018")==std::string::npos && Jet_pt[i]>20 && abs(Jet_eta[i])>2 && abs(Jet_eta[i])<3) {
         double nonPrefiringProb_overlapPho[3]={1,1,1};
         for (unsigned int j=0;j<nPhoton;j++) {
           if (!isData && Photon_pt[j]>20 && abs(Photon_eta[j])>2 && abs(Photon_eta[j])<3) {
             if (deltaR(Jet_phi[i],Photon_phi[j],Jet_eta[i],Photon_eta[j])>0.4) continue;
             double max=h_L1prefire_phoMap->GetYaxis()->GetBinLowEdge(h_L1prefire_phoMap->GetNbinsY());
             double pt = (Photon_pt[j]>max) ? max-0.01 : Photon_pt[j];
             double prefireProb = h_L1prefire_phoMap->GetBinContent(h_L1prefire_phoMap->FindBin(Photon_eta[j],pt));
             double stat = h_L1prefire_phoMap->GetBinError(h_L1prefire_phoMap->FindBin(Photon_eta[j],pt));
             double syst = prefireProb*0.2;
             nonPrefiringProb_overlapPho[0]*=(1-prefireProb);
             nonPrefiringProb_overlapPho[1]*=(1-std::min(1.,prefireProb+sqrt(pow(stat,2)+pow(syst,2))));
             nonPrefiringProb_overlapPho[2]*=(1-std::max(0.,prefireProb-sqrt(pow(stat,2)+pow(syst,2))));
           }
         }
         double max=h_L1prefire_jetMap->GetYaxis()->GetBinLowEdge(h_L1prefire_jetMap->GetNbinsY());
         double pt = (Jet_pt[i]>max) ? max-0.01 : Jet_pt[i];
         double prefireProb_jet = h_L1prefire_jetMap->GetBinContent(h_L1prefire_jetMap->FindBin(Jet_eta[i],pt));
         double stat = h_L1prefire_jetMap->GetBinError(h_L1prefire_jetMap->FindBin(Jet_eta[i],pt));
         double syst = prefireProb_jet*0.2;
         double nonPrefiringProb_overlapJet[3]={1,1,1};
         nonPrefiringProb_overlapJet[0]*=(1-prefireProb_jet);
         nonPrefiringProb_overlapJet[1]*=(1-std::min(1.,prefireProb_jet+sqrt(pow(stat,2)+pow(syst,2))));
         nonPrefiringProb_overlapJet[2]*=(1-std::max(0.,prefireProb_jet-sqrt(pow(stat,2)+pow(syst,2))));
         if (nonPrefiringProb_overlapPho[0] == 1) {
           nonPrefiringProbability[0]*=nonPrefiringProb_overlapJet[0];
           nonPrefiringProbability[1]*=nonPrefiringProb_overlapJet[1];
           nonPrefiringProbability[2]*=nonPrefiringProb_overlapJet[2];
         }
         else if (nonPrefiringProb_overlapPho[0] > nonPrefiringProb_overlapJet[0]) {
           if (nonPrefiringProb_overlapPho[0]!=0) {
             nonPrefiringProbability[0]*=nonPrefiringProb_overlapJet[0]/nonPrefiringProb_overlapPho[0];
             nonPrefiringProbability[1]*=nonPrefiringProb_overlapJet[1]/nonPrefiringProb_overlapPho[1];
             nonPrefiringProbability[2]*=nonPrefiringProb_overlapJet[2]/nonPrefiringProb_overlapPho[2];
           }
           else {nonPrefiringProbability[0]=0;nonPrefiringProbability[1]=0;nonPrefiringProbability[2]=0;}
         }
       }

       bool passcut=true;
       double jetpt=Jet_pt_nom[i], jetmass=Jet_mass[i]; //jetmass=Jet_mass_nom[i];
       if (!isData) {
         if (JER_whichSF==1) {jetpt=Jet_pt_jerUp[i];} //jetmass=Jet_mass_jerUp[i];}
         else if (JER_whichSF==2) {jetpt=Jet_pt_jerDown[i];} //jetmass=Jet_mass_jerDown[i];}
         if (JES_whichSF==1) {jetpt=Jet_pt_jesTotalUp[i];} //jetmass=Jet_mass_jesTotalUp[i];}
         else if (JES_whichSF==2) {jetpt=Jet_pt_jesTotalDown[i];} //jetmass=Jet_mass_jesTotalDown[i];}
       }
       jetSmearedPt.push_back(jetpt); jetSmearedMass.push_back(jetmass); jetbtagDeepFlavB.push_back(Jet_btagDeepFlavB[i]);
       HT_before+=jetSmearedPt[i];
       if (abs(Jet_eta[i])>2.4 || !(Jet_jetId[i]>>1&1) || jetSmearedPt[i]<30) passcut=false;
       if (jetSmearedPt[i]<50 && !(Jet_puId[i]&(1<<2))) passcut=false;
       for (auto j : passPhotons) if (deltaR(Jet_phi[i],Photon_phi[j],Jet_eta[i],Photon_eta[j])<0.4) {passcut=false;break;}
       for (auto j : passElectrons) if (deltaR(Jet_phi[i],Electron_phi[j],Jet_eta[i],Electron_eta[j])<0.4) {passcut=false;break;}
       for (auto j : passMuons) if (deltaR(Jet_phi[i],Muon_phi[j],Jet_eta[i],Muon_eta[j])<0.4) {passcut=false;break;}
       for (auto j : passTaus) if (deltaR(Jet_phi[i],Tau_phi[j],Jet_eta[i],Tau_eta[j])<0.4) {passcut=false;break;}
       //for (auto j : passIso) if (deltaR(Jet_phi[i],IsoTrack_phi[j],Jet_eta[i],IsoTrack_eta[j])<0.4) {passcut=false;break;}
       if (_fastSim && year.find("2016")!=std::string::npos && passcut && Jet_chHEF[i]<0.1) {
         bool match=0;
         for (unsigned int j=0;j<nJet;j++){
           if (Jet_genJetIdx[i]==-1) continue;
           if (deltaR(Jet_phi[i],GenJet_phi[Jet_genJetIdx[j]],Jet_eta[i],GenJet_phi[Jet_genJetIdx[j]])<0.3) {match=true;break;}
         }
         if (!match) vetoFastSim=1;
       }
       if (passcut) passJet.push_back(i);
     }
     nPassAK4=passJet.size();
     if (!isData) w*=nonPrefiringProbability[L1prefire_whichSF];
     if (vetoFastSim) {
       if (CountSignal) {
         auto search = signal_events.find(mass_pair);
         if (search!=signal_events.end()) search->second -=1;
       }
       continue;
     }
     if (is_debug) cout<<"AK4 object done"<<endl;
     //jet pt, btags
     for (auto i : passJet) {
       //Updating jet b-tagging status
       if (!isData && btag_file.size()>0) {
         if (year.find("2016")!=std::string::npos) jetbtagDeepFlavB[i]=UpdateBtags(cset_btag, is_debug,_fastSim, Jet_eta[i], jetSmearedPt[i], Jet_hadronFlavour[i], jetbtagDeepFlavB[i], BtagDeepWP[year_chooser][1], BtagDeepWP[year_chooser][0], eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_L_2016fast, reader_M_2016fast, reader_T_2016fast, gen_btag);
         if (year.find("2017")!=std::string::npos) jetbtagDeepFlavB[i]=UpdateBtags(cset_btag, is_debug,_fastSim, Jet_eta[i], jetSmearedPt[i], Jet_hadronFlavour[i], jetbtagDeepFlavB[i], BtagDeepWP[year_chooser][1], BtagDeepWP[year_chooser][0], eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_L_2017fast, reader_M_2017fast, reader_T_2017fast, gen_btag);
         if (year.find("2018")!=std::string::npos) jetbtagDeepFlavB[i]=UpdateBtags(cset_btag, is_debug,_fastSim, Jet_eta[i], jetSmearedPt[i], Jet_hadronFlavour[i], jetbtagDeepFlavB[i], BtagDeepWP[year_chooser][1], BtagDeepWP[year_chooser][0], eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_L_2018fast, reader_M_2018fast, reader_T_2018fast, gen_btag);
       }
       if (jetSmearedPt[i]>jetSmearedPt[leadpt_ak4]) leadpt_ak4=i;
       HT_after+=jetSmearedPt[i];
       if (jetbtagDeepFlavB[i]>BtagDeepWP[year_chooser][2]) {passDeep.insert(pair<int,char>(i,'T'));bcounterDeep[3]++;}
       else if (jetbtagDeepFlavB[i]>BtagDeepWP[year_chooser][1]) {passDeep.insert(pair<int,char>(i,'M'));bcounterDeep[2]++;}
       else if (jetbtagDeepFlavB[i]>BtagDeepWP[year_chooser][0]) {passDeep.insert(pair<int,char>(i,'L'));bcounterDeep[1]++;}
       else {passDeep.insert(pair<int,char>(i,'0'));bcounterDeep[0]++;}
     }
     if (is_debug && !isData && btag_file.size()>0) cout<<"AK4 update b-tagging status done"<<endl;
     bcounterDeep[2] += bcounterDeep[3];
     bcounterDeep[1] += bcounterDeep[2];
    
     //Sort passJet from highest DeepJet btag to lowest
     for (unsigned int i=0;i<passJet.size();i++){
       int temp;
       for (unsigned int j=passJet.size()-1;j>i;j--){
         if (jetbtagDeepFlavB[passJet[j]]>jetbtagDeepFlavB[passJet[j-1]]){
           temp=passJet[j-1];
           passJet[j-1]=passJet[j];
           passJet[j]=temp;
         }
       }
     }
     EMHT_before+=HT_before;
     EMHT_after+=HT_after;
    
     //AK8Jet ID
     for (unsigned int i=0;i<nFatJet;i++) {
       bool passcut=true;
       double jetpt=FatJet_pt_nom[i], jetmass=FatJet_msoftdrop_nom[i];
       if (!isData) {
         if (JER_whichSF==1) {jetpt=FatJet_pt_jerUp[i]; jetmass=FatJet_msoftdrop_jerUp[i];}
         else if (JER_whichSF==2) {jetpt=FatJet_pt_jerDown[i]; jetmass=FatJet_msoftdrop_jerDown[i];}
         if (JES_whichSF==1) {jetpt=FatJet_pt_jesTotalUp[i]; jetmass=FatJet_msoftdrop_jesTotalUp[i];}
         else if (JES_whichSF==2) {jetpt=FatJet_pt_jesTotalDown[i]; jetmass=FatJet_msoftdrop_jesTotalUp[i];}
         if (JMR_whichSF==1) jetmass=FatJet_msoftdrop_jmrUp[i];
         else if (JMR_whichSF==2) jetmass=FatJet_msoftdrop_jmrDown[i];
         if (JMS_whichSF==1) jetmass=FatJet_msoftdrop_jmsUp[i];
         else if (JMS_whichSF==2) jetmass=FatJet_msoftdrop_jmsDown[i];
       }
       AK8JetSmearedPt.push_back(jetpt); AK8JetSmearedMass.push_back(jetmass);
       AK8HT_before+=AK8JetSmearedPt[i];
       if (abs(FatJet_eta[i])>2.4 || !(FatJet_jetId[i]>>1&1) || AK8JetSmearedPt[i]<300) passcut=false;
       for (auto j : passPhotons) if (deltaR(FatJet_phi[i],Photon_phi[j],FatJet_eta[i],Photon_eta[j])<0.8) {
         passcut=false;break;
       }
       for (auto j : passElectrons) if (deltaR(FatJet_phi[i],Electron_phi[j],FatJet_eta[i],Electron_eta[j])<0.8) {
         passcut=false;break;
       }
       for (auto j : passMuons) if (deltaR(FatJet_phi[i],Muon_phi[j],FatJet_eta[i],Muon_eta[j])<0.8) {
         passcut=false;break;
       }
       for (auto j : passTaus) if (deltaR(FatJet_phi[i],Tau_phi[j],FatJet_eta[i],Tau_eta[j])<0.8) {
         passcut=false;break;
       }
       //for (auto j : passIso) if (deltaR(FatJet_phi[i],IsoTrack_phi[j],FatJet_eta[i],IsoTrack_eta[j])<0.8) {
       //  passcut=false;break;
       //}
       if (passcut) passAK8Jet.push_back(i);
     }
     nPassAK8=passAK8Jet.size();
     if (is_debug) cout<<"AK8 object done"<<endl;
     //AK8Jet pt, btag
     for (auto i : passAK8Jet) {
       if (AK8JetSmearedPt[i]>AK8JetSmearedPt[leadpt_ak8]) leadpt_ak8=i;
       AK8HT_after+=AK8JetSmearedPt[i];
       double i_jetdB=FatJet_btagDDBvLV2[i], h_jetdB;
       if (highDDBvL==-1) h_jetdB=-10; else h_jetdB=FatJet_btagDDBvLV2[highDDBvL];
       if (i_jetdB>h_jetdB) highDDBvL=i;
       if (FatJet_btagDDBvLV2[i]>BtagDDBvLWP[year_chooser][4]) {passDDBvL.insert(pair<int,char>(i,'C'));bcounterDDBvL[5]++;}
       else if (FatJet_btagDDBvLV2[i]>BtagDDBvLWP[year_chooser][3]) {passDDBvL.insert(pair<int,char>(i,'T'));bcounterDDBvL[4]++;}
       else if (FatJet_btagDDBvLV2[i]>BtagDDBvLWP[year_chooser][2]) {passDDBvL.insert(pair<int,char>(i,'H'));bcounterDDBvL[3]++;}
       else if (FatJet_btagDDBvLV2[i]>BtagDDBvLWP[year_chooser][1]) {passDDBvL.insert(pair<int,char>(i,'M'));bcounterDDBvL[2]++;}
       else if (FatJet_btagDDBvLV2[i]>BtagDDBvLWP[year_chooser][0]) {passDDBvL.insert(pair<int,char>(i,'L'));bcounterDDBvL[1]++;}
       else {passDDBvL.insert(pair<int,char>(i,'0'));bcounterDDBvL[0]++;}
     }
     bcounterDDBvL[4] += bcounterDDBvL[5];
     bcounterDDBvL[3] += bcounterDDBvL[4];
     bcounterDDBvL[2] += bcounterDDBvL[3];
     bcounterDDBvL[1] += bcounterDDBvL[2];
     //Sort passAK8Jet from highest DDBvL btag to lowest
     for (unsigned int i=0;i<passAK8Jet.size();i++){
       int temp;
       for (unsigned int j=passAK8Jet.size()-1;j>i;j--){
         if (FatJet_btagDDBvLV2[passAK8Jet[j]]>FatJet_btagDDBvLV2[passAK8Jet[j-1]]){
           temp=passAK8Jet[j-1];
           passAK8Jet[j-1]=passAK8Jet[j];
           passAK8Jet[j]=temp;
         }
       }
     }
     AK8EMHT_before+=HT_before;
     AK8EMHT_after+=HT_after;
     OneOr2jet=false; if (passJet.size()>1 || passAK8Jet.size()>0) OneOr2jet=true;
    
     //MET variables
     if (is_debug) cout<<"Calculating MET variables"<<endl;
     double METPhi=0, METsumEt=0, METSig=0;
     for (auto i : passPhotons) ST+=phoET[i];
     MET=MET_T1_pt; METPhi=MET_T1_phi; METsumEt=MET_sumEt; METSig=MET_significance;
     if (JER_whichSF==1) {MET=MET_T1_pt_jerUp; METPhi=MET_T1_phi_jerUp;}
     else if (JER_whichSF==2) {MET=MET_T1_pt_jerDown; METPhi=MET_T1_phi_jerDown;}
     if (JES_whichSF==1) {MET=MET_T1_pt_jesTotalUp; METPhi=MET_T1_phi_jesTotalUp;}
     else if (JES_whichSF==2) {MET=MET_T1_pt_jesTotalDown; METPhi=MET_T1_phi_jesTotalDown;}
     if (UES_whichSF==1) {MET=MET_T1_pt_unclustEnUp; METPhi=MET_T1_phi_unclustEnUp;}
     else if (UES_whichSF==2) {MET=MET_T1_pt_unclustEnDown; METPhi=MET_T1_phi_unclustEnDown;}
     if (!isData && genMET_whichSF==1) {MET=GenMET_pt; METPhi=GenMET_phi;}
     ST+=MET;
     ST_G=ST;
     for (auto i : passJet) ST+=jetSmearedPt[i];
     if (passPhotons.size()>0) {
       double dphi_MT=deltaPhi(Photon_phi[nleadPho],METPhi);
       MT=sqrt(2*MET*phoET[nleadPho]*(1-cos(abs(dphi_MT))));
     }
     if (_fakeRate) {
       if (_fakeRate==1 && nPassFREleL != 0) {
         double dphi_MT=deltaPhi(Electron_phi[nleadFREleL],METPhi);
         MT=sqrt(2*MET*Electron_pt[nleadFREleL]*(1-cos(abs(dphi_MT))));
       }
     }
     dphi_met_jet=999;
     double dphi_met_jet_njet[8]={-1,-1,-1,-1,-1,-1,-1,-1};
     double pt_dphi_jet=-1;
     int counter=0;
     for (auto i : passJet) {
       if (jetSmearedPt[i]<100) continue;
       double dphi=deltaPhi(Jet_phi[i],METPhi);
       if (counter<8) dphi_met_jet_njet[counter]=abs(dphi);
       if (abs(dphi)<dphi_met_jet) {dphi_met_jet=abs(dphi);  pt_dphi_jet=jetSmearedPt[i];}
       counter++;
     }
     double dphi_pho=999;
     for (auto i : passPhotons) {
       double dphi=deltaPhi(Photon_phi[i],METPhi);
       if (abs(dphi)<dphi_pho) dphi_pho=abs(dphi);
     }
     if (dphi_met_jet>dphi_pho) dphi_met_jet=dphi_pho;
    
     if (!isData ){
       mcLeptonFilter=0;
       for (unsigned int i=0; i<nGenPart; i++){
         //if ((GenPart_statusFlags[i] & 8193) == 8193 && (abs(GenPart_pdgId[i])== 11 || abs(GenPart_pdgId[i])== 13 || abs(GenPart_pdgId[i])== 15)){
         if ((GenPart_statusFlags[i] & 4097) == 4097 && (abs(GenPart_pdgId[i])== 11 || abs(GenPart_pdgId[i])== 13 || abs(GenPart_pdgId[i])== 15)){
           mcLeptonFilter++;
           //cout<<"pid "<<GenPart_pdgId[i]<<" pt "<<GenPart_pt[i]<<" status "<<GenPart_status[i]<<" statusflag "<<GenPart_statusFlags[i]<<" momPID "<<GenPart_pdgId[GenPart_genPartIdxMother[i]]<<endl;
         }
       }
     //cout<<"lepton "<<mcLeptonFilter<<endl;
     }

     double dr_pho_parton=999;
     if (!isData ){
       for (unsigned int i=0; i<nGenPart; i++){
         if ((GenPart_statusFlags[i] & 4353) != 4353 || abs(GenPart_pdgId[i])!= 22) continue;
         //4353: isPrompt, fromHardProcess, isFirstCopy
         for (unsigned int j=0; j<nGenPart; j++) {
           if ((abs(GenPart_pdgId[j])>5 && GenPart_pdgId[j]!=21) || GenPart_status[GenPart_genPartIdxMother[j]]!=21) continue;
           double dR = deltaR(GenPart_phi[i],GenPart_phi[j],GenPart_eta[i],GenPart_eta[j]);
           if (dR<dr_pho_parton) dr_pho_parton=dR;
         }
       }
     }
     bool true_b_quark=0, true_b_jet=0;;
     if (!isData ){
       for (unsigned int i=0; i<nGenPart; i++){
         if ((GenPart_statusFlags[i] & 1) != 1 || abs(GenPart_pdgId[i])!= 5) continue;
         true_b_quark=1;
         break;
       }
       for (unsigned int i=0; i<nGenJet;i++){
         if (abs(GenJet_partonFlavour[i])==5) {true_b_jet=1; break;}
       }
     }
     
     //HEM15/16 veto
     bool HEMveto_electron=false, HEMveto_jet=false;
     if (year.find("2018")!=std::string::npos) {
       if ((isData && run>=319077) || (!isData && jentry%100<65)) {
         for (unsigned int i=0;i<nElectron;i++) {
           //Veto events with any electron with pT > 30GeV, -3.0 < eta < -1.4, and -1.57 < phi < -0.87
           if (Electron_pt[i]>30 && Electron_eta[i]<-1.4 && Electron_eta[i]>-3.0 && Electron_phi[i]<-0.87 && Electron_phi[i]>-1.57) HEMveto_electron=true;
           //if (HEMveto_electron) cout<<"ele pt "<<Electron_pt[i]<<" eta "<<Electron_eta[i]<<" phi "<<Electron_phi[i]<<endl;
           if (HEMveto_electron) break; 
         }
         for (unsigned int i=0;i<nJet;i++) {
           //Veto events with any jet with pT > 30 GeV, DeltaPhi(jet, HT,miss) < 0.5, -3.2 <eta< -1.2, and -1.77 < phi < -0.67 (veto enlarged by half the jet cone)
           if (jetSmearedPt[i]>30 && Jet_eta[i]<-1.2 && Jet_eta[i]>-3.2 && Jet_phi[i]<-0.67 && Jet_phi[i]>-1.77 && deltaPhi(Jet_phi[i],METPhi)<0.5) HEMveto_jet=true;
           //if (HEMveto_jet) cout<<"jet pt "<<jetSmearedPt[i]<<" eta "<<Jet_eta[i]<<" phi "<<Jet_phi[i]<<" dphi "<<deltaPhi(Jet_phi[i],METPhi)<<endl;
           if (HEMveto_jet) break; 
         }
       }
     }
     if (HEMveto_electron || HEMveto_jet) continue;

       //L1prefire
       //check events if there's a jet (photon) with pt>100 (>50) and 2.25<|eta|<3.0
       //
       L1prefire=0;
       for (auto i : passPhotons) if (phoET[i]>50 && abs(Photon_eta[i])>2.25) L1prefire=1;
       for (auto i : passJet) if (jetSmearedPt[i]>100 && abs(Jet_eta[i])>2.25) L1prefire=1;

       //find which btag jet to use for Higgs mass
       //AK8
       if (is_debug) cout<<"Boosted Higgs tagging"<<endl;
       passBtag=false; passHiggsMass=false;
       int SelectedAK8Jet=-1;
       DDBvL_selected=0; //DDBvL btag value of higgs candidate jet. 0-Nobtag, 1-loose, 2-medium 3-medium2 4-tight
       if (passAK8Jet.size()>0){
         SelectedAK8Jet=passAK8Jet[0];
         if (AK8JetSmearedMass[passAK8Jet[0]]>70 && AK8JetSmearedMass[passAK8Jet[0]]<200) {
           passHiggsMass=true;
           if (FatJet_btagDDBvLV2[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][4]) DDBvL_selected=5;
           else if (FatJet_btagDDBvLV2[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][3]) DDBvL_selected=4;
           else if (FatJet_btagDDBvLV2[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][2]) DDBvL_selected=3;
           else if (FatJet_btagDDBvLV2[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][1]) DDBvL_selected=2;
           else if (FatJet_btagDDBvLV2[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][0]) DDBvL_selected=1;
           else DDBvL_selected=0;
           if (FatJet_btagDDBvLV2[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][0]) passBtag=true;
           //if (FatJet_btagDDBvLV2[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][1]) passBtag=true;//AK8medium
         }
       }

       //AK4
       if (is_debug) cout<<"Resolved Higgs tagging"<<endl;
       double m_bb_deep=-1, phi_H_candidate=999, pt_H_candidate=-1;
       bool passAK4DeepHiggsMass=false;
       Deep_selected=0; //Deep btag value of higgs candidate jets. 0-Nobtag, 1-1 loose btag, 2-2 loose btag
       Deep_medium_selected=0;
       int SelectedAK4Jet1=-1, SelectedAK4Jet2=-1;
       double dR_ak4_Hcandidate=-1, pt_ak4_Hcandidate1=-1, pt_ak4_Hcandidate2=-1;
       if (passJet.size()>1){
         for (unsigned int i=0;i<passJet.size();i++){
           if (i!=0) continue;
           for (unsigned int j=i+1;j<passJet.size();j++){
             //double dR = deltaR(Jet_phi[passJet.at(i)],Jet_phi[passJet.at(j)],Jet_eta[passJet.at(i)],Jet_eta[passJet.at(j)]);
             //if (dR>1.5) continue;
             TLorentzVector bjet1, bjet2;
             bjet1.SetPtEtaPhiM(jetSmearedPt[passJet.at(i)],Jet_eta[passJet.at(i)],Jet_phi[passJet.at(i)],jetSmearedMass[passJet.at(i)]);
             bjet2.SetPtEtaPhiM(jetSmearedPt[passJet.at(j)],Jet_eta[passJet.at(j)],Jet_phi[passJet.at(j)],jetSmearedMass[passJet.at(j)]);
             m_bb_deep=(bjet1+bjet2).M();
             phi_H_candidate=(bjet1+bjet2).Phi();
             pt_H_candidate=(bjet1+bjet2).Pt();
             //if (m_bb_deep>70 && m_bb_deep<200) {
             if (m_bb_deep>80 && m_bb_deep<160) {
               if (jetbtagDeepFlavB[passJet.at(i)]>BtagDeepWP[year_chooser][0]) Deep_selected++;
               if (jetbtagDeepFlavB[passJet.at(j)]>BtagDeepWP[year_chooser][0]) Deep_selected++;
               if (jetbtagDeepFlavB[passJet.at(i)]>BtagDeepWP[year_chooser][1]) Deep_medium_selected++;//medium
               SelectedAK4Jet1=passJet.at(i); SelectedAK4Jet2=passJet.at(j);
               passAK4DeepHiggsMass=true;
               break;
             }
           }
           if (passAK4DeepHiggsMass) break;
         }
         if (!passAK4DeepHiggsMass) {SelectedAK4Jet1=passJet.at(0); SelectedAK4Jet2=passJet.at(1);};
         dR_ak4_Hcandidate=deltaR(Jet_phi[SelectedAK4Jet1],Jet_phi[SelectedAK4Jet2],Jet_eta[SelectedAK4Jet1],Jet_eta[SelectedAK4Jet2]);
         pt_ak4_Hcandidate1= jetSmearedPt[SelectedAK4Jet1];
         pt_ak4_Hcandidate2= jetSmearedPt[SelectedAK4Jet2];
       }

           //Calculate AK8 BTag SFs
           if (!isData && btag_file.size()>0 && SignalScan) {
             CalcBtagSF_AK8(year, AK8JetSmearedPt, passDDBvL, DDBvL_SF_L, DDBvL_SF_M1, DDBvL_SF_M2, DDBvL_SF_T1, DDBvL_SF_T2);
           }

           //SignalStudy
           int Higgs_jet_b=-1, Higgs_jet_antib=-1, index_b=-1, index_ab=-1, njet_index=-1;
           double AK4Hmass=-1, Hbbmass=-1, genAK4Hmass=-1, dR_trueHbb=-1, dphi_trueH_ak4=999, dphi_trueHmin_ak4=999;
           double Higgs_pt=-1, Higgs_phi=-1, dphi_trueH_gravitino=999;
           double disc_true_Hjet1=-1, disc_true_Hjet2=-1, pt_true_Hjet1=-1, pt_true_Hjet2=-1;
           if (SignalScan) {
             int nHiggs=0, ib1=-1, ib2=-1, nZ=0;
             for (unsigned int i=0;i<nGenPart;i++){
               if (GenPart_pdgId[i]==25 && GenPart_statusFlags[i]&int(pow(2,13))) {nHiggs++; Higgs_pt=GenPart_pt[i]; Higgs_phi=GenPart_phi[i];}
               if (GenPart_pdgId[i]==5 && GenPart_pdgId[GenPart_genPartIdxMother[i]]==25) ib1=i;
               if (GenPart_pdgId[i]==-5 && GenPart_pdgId[GenPart_genPartIdxMother[i]]==25) ib2=i;
               if (GenPart_pdgId[i]==23 && GenPart_pdgId[GenPart_genPartIdxMother[i]]>1000000) nZ++;
             }
             SignalHiggs=nHiggs;
             SignalZ=nZ;
             (ib1!=-1 && ib2!=-1) ? Hbb=true : Hbb=false;
             //cout<<"H "<<nHiggs<<" Z "<<nZ<<endl;
             if (SignalScenario==5 && nHiggs==0) w*=0.315; //For GG final state, to have same BF as in T5qqqqHg
             if (SignalScenario==5 && nHiggs==2) w*=1.25;  //For HH final state, to have same BF as in T5qqqqHg
             if (CountSignal && SignalScenario==5 && (nZ>0 || nHiggs==1)) {
               auto search = signal_events.find(mass_pair);
               if (search!=signal_events.end()) search->second -=1;
             }
             if (SignalHiggs>2 || SignalZ>2 || (SignalHiggs+SignalZ)>2) cout<<"too many higgs/Z: nHiggs = "<<SignalHiggs<<", nZ = "<<SignalZ<<" in "<<fChain->GetCurrentFile()->GetName()<<" event "<<event<<endl;
             if (signalstudy) {
               vector<int> v_final_b;
               int final_b=-1, final_antib=-1, n_bq=0, n_abq=0, gravitino_1=-1, gravitino_2=-1;
               for (unsigned int i=0;i<nGenPart;i++){
                 //printf("Index %-2i PDGID %-8d mcPt %-12f Eta %-9f Phi %-9f mom %-8d momPt %-9f  momEta %-9f  momPhi %-9f status %-2i flag %-14s gmom %-8d\n",i,GenPart_pdgId[i],GenPart_pt[i],GenPart_eta[i],GenPart_phi[i],GenPart_pdgId[GenPart_genPartIdxMother[i]],GenPart_pt[GenPart_genPartIdxMother[i]],GenPart_eta[GenPart_genPartIdxMother[i]],GenPart_phi[GenPart_genPartIdxMother[i]],GenPart_status[i],bitset<14>(GenPart_statusFlags[i]).to_string().c_str(),GenPart_pdgId[GenPart_genPartIdxMother[GenPart_genPartIdxMother[i]]]);
                 if (abs(GenPart_pdgId[i])==5 && GenPart_statusFlags[i]&int(pow(2,13))) v_final_b.push_back(i);
                 if (GenPart_pdgId[i]==5 && GenPart_statusFlags[i]&int(pow(2,13))) n_bq++;
                 if (GenPart_pdgId[i]==-5 && GenPart_statusFlags[i]&int(pow(2,13))) n_abq++;
                 if (GenPart_pdgId[i]==1000022 && GenPart_status[i]==1) (gravitino_1==-1) ? gravitino_1=i : gravitino_2=i;
               }
               if (Higgs_phi!=-1) {
                 TLorentzVector g1, g2;
                 g1.SetPtEtaPhiM(GenPart_pt[gravitino_1],GenPart_eta[gravitino_1],GenPart_phi[gravitino_1],1);
                 g2.SetPtEtaPhiM(GenPart_pt[gravitino_2],GenPart_eta[gravitino_2],GenPart_phi[gravitino_2],1);
                 double phi=(g1+g2).Phi();
                 dphi_trueH_gravitino=abs(deltaPhi(Higgs_phi,phi));
               }
               bool foundHiggs=0;
               for (auto i : v_final_b) {
                 int loop_b=i;
                 bool loop_foundHiggs=0;
                 while (!loop_foundHiggs){
                   if (loop_b==-1) break;
                   int mother=GenPart_genPartIdxMother[loop_b];
                   if (mother==-1) break;
                   if (GenPart_pdgId[mother]==25) {
                     loop_foundHiggs=1; foundHiggs=1;
                     (GenPart_pdgId[i]==5) ? final_b=i : final_antib=i;
                   }
                   else loop_b=mother;
                 }
               }
               double dR_b=0.3, dR_antib=0.3;
               if (foundHiggs && final_b!=-1 && final_antib!=-1) {
                 TLorentzVector b_quark, b_aquark;
                 b_quark.SetPtEtaPhiM(GenPart_pt[final_b],GenPart_eta[final_b],GenPart_phi[final_b],4.18);
                 b_aquark.SetPtEtaPhiM(GenPart_pt[final_antib],GenPart_eta[final_antib],GenPart_phi[final_antib],4.18);
                 Hbbmass=(b_quark+b_aquark).M();

                 int genjet_b=-1, genjet_antib=-1, nbjets=0, nantibjets=0;
                 for (unsigned int i=0;i<nGenJet;i++){
                   if (GenJet_partonFlavour[i]==5) nbjets++;
                   if (GenJet_partonFlavour[i]==-5) nantibjets++;
                   double temp_dR_b=deltaR(GenJet_phi[i],GenPart_phi[final_b],GenJet_eta[i],GenPart_eta[final_b]);
                   double temp_dR_antib=deltaR(GenJet_phi[i],GenPart_phi[final_antib],GenJet_eta[i],GenPart_eta[final_antib]);
                   if (GenJet_partonFlavour[i]==5 && temp_dR_b<dR_b) {genjet_b=i; dR_b=temp_dR_b;}
                   if (GenJet_partonFlavour[i]==-5 && temp_dR_antib<dR_antib) {genjet_antib=i; dR_antib=temp_dR_antib;}
                 }
                 if (genjet_b!=-1 && genjet_antib!=-1) {
                   TLorentzVector bjet1, bjet2;
                   bjet1.SetPtEtaPhiM(GenJet_pt[genjet_b],GenJet_eta[genjet_b],GenJet_phi[genjet_b],GenJet_mass[genjet_b]);
                   bjet2.SetPtEtaPhiM(GenJet_pt[genjet_antib],GenJet_eta[genjet_antib],GenJet_phi[genjet_antib],GenJet_mass[genjet_antib]);
                   genAK4Hmass=(bjet1+bjet2).M();
                 }
                 njet_index=passJet.size();
                 if (genjet_b!=-1) {
                   for (unsigned int i=0;i<nJet;i++) if (Jet_genJetIdx[i]==genjet_b) Higgs_jet_b=i;
                   bool passId=0; for (unsigned int i=0;i<passJet.size();i++) if (passJet[i]==Higgs_jet_b) {index_b=i; passId=1; break;}
                   if (!passId) Higgs_jet_b=-1;
                 }
                 if (genjet_antib!=-1) {
                   for (unsigned int i=0;i<nJet;i++) if (Jet_genJetIdx[i]==genjet_antib) Higgs_jet_antib=i;
                   bool passId=0; for (unsigned int i=0;i<passJet.size();i++) if (passJet[i]==Higgs_jet_antib) {index_ab=i; passId=1; break;}
                   if (!passId) Higgs_jet_antib=-1;
                 }

                 if (Higgs_jet_b!=-1 && Higgs_jet_antib!=-1) {
                   TLorentzVector bjet1, bjet2;
                   bjet1.SetPtEtaPhiM(jetSmearedPt[Higgs_jet_b],Jet_eta[Higgs_jet_b],Jet_phi[Higgs_jet_b],jetSmearedMass[Higgs_jet_b]);
                   bjet2.SetPtEtaPhiM(jetSmearedPt[Higgs_jet_antib],Jet_eta[Higgs_jet_antib],Jet_phi[Higgs_jet_antib],jetSmearedMass[Higgs_jet_antib]);
                   AK4Hmass=(bjet1+bjet2).M();
                   dR_trueHbb=deltaR(Jet_phi[Higgs_jet_b],Jet_phi[Higgs_jet_antib],Jet_eta[Higgs_jet_b],Jet_eta[Higgs_jet_antib]);
                   double dphi1=deltaPhi(Jet_phi[Higgs_jet_b],METPhi);
                   double dphi2=deltaPhi(Jet_phi[Higgs_jet_antib],METPhi);
                   (abs(dphi1)<abs(dphi2)) ? dphi_trueHmin_ak4=abs(dphi1) : dphi_trueHmin_ak4=abs(dphi2);
                   double h_phi=(bjet1+bjet2).Phi();
                   dphi_trueH_ak4=abs(deltaPhi(h_phi,METPhi));
                   disc_true_Hjet1=jetbtagDeepFlavB[Higgs_jet_b]; disc_true_Hjet2=jetbtagDeepFlavB[Higgs_jet_antib];
                   pt_true_Hjet1=jetSmearedPt[Higgs_jet_b]; pt_true_Hjet2=jetSmearedPt[Higgs_jet_antib];
                   if (jetbtagDeepFlavB[Higgs_jet_b]<jetbtagDeepFlavB[Higgs_jet_antib]) {
                     disc_true_Hjet2=jetbtagDeepFlavB[Higgs_jet_b]; disc_true_Hjet1=jetbtagDeepFlavB[Higgs_jet_antib];
                     pt_true_Hjet2=jetSmearedPt[Higgs_jet_b]; pt_true_Hjet1=jetSmearedPt[Higgs_jet_antib];
                   }
                 }

                 /*
                 if (Higgs_jet_b!=-1) cout<<"genpart b "<<GenPart_pt[final_b]<<" "<<GenPart_eta[final_b]<<" "<<GenPart_phi[final_b]<<endl;
                 if (Higgs_jet_b!=-1) cout<<"genjet b "<<GenJet_pt[genjet_b]<<" "<<GenJet_eta[genjet_b]<<" "<<GenJet_phi[genjet_b]<<endl;
                 if (Higgs_jet_b!=-1) cout<<"recojet b "<<Jet_pt[Higgs_jet_b]<<" "<<Jet_eta[Higgs_jet_b]<<" "<<Jet_phi[Higgs_jet_b]<<endl;
                 if (Higgs_jet_antib!=-1) cout<<"genpart antib "<<GenPart_pt[final_antib]<<" "<<GenPart_eta[final_antib]<<" "<<GenPart_phi[final_antib]<<endl;
                 if (Higgs_jet_antib!=-1) cout<<"genjet antib "<<GenJet_pt[genjet_antib]<<" "<<GenJet_eta[genjet_antib]<<" "<<GenJet_phi[genjet_antib]<<endl;
                 if (Higgs_jet_antib!=-1) cout<<"recojet antib "<<Jet_pt[Higgs_jet_antib]<<" "<<Jet_eta[Higgs_jet_antib]<<" "<<Jet_phi[Higgs_jet_antib]<<endl;
                 */
               }
             }
           }

           //Region definitions
           if (is_debug) cout<<"Search region definitions"<<endl;
           double met = (MET<70) ? 1 : (MET<100) ? 2 : (MET<200) ? 3 : (MET<300) ? 4 : (MET<500) ? 5 : 6;
           double njet;
           //AK4-AK8 searchBins
           int AK4AK8=0, boost=0; noHmass_in_event=0;
           int higgs_category=-1;
           //Signal Region
           if (DDBvL_selected>0) {boost=1;AK4AK8=1;higgs_category=4;}
           else if (Deep_medium_selected==1) {AK4AK8=1;higgs_category=3;}
           //Control regions
           if (DDBvL_selected==0 && Deep_medium_selected==0) {
             if (passHiggsMass) {boost=1;higgs_category=2;}
             else if (!passAK4DeepHiggsMass) {noHmass_in_event=1;higgs_category=-1;}
                  else higgs_category=1;
           }

           //highest btag phi
           double btag_phi=999, dphi_closest=999; dphi_met_btags=999;
           if (passJet.size()>0) {btag_phi=Jet_phi[passJet[0]]; dphi_met_btag=deltaPhi(btag_phi,METPhi);}
           for (auto i : passJet) {
             if (jetbtagDeepFlavB[i]<BtagDeepWP[year_chooser][0]) continue;
             if (deltaPhi(Jet_phi[i],METPhi)<dphi_closest) {dphi_met_btags=deltaPhi(Jet_phi[i],METPhi); dphi_closest=dphi_met_btags;}
           }
           //AK4 AK8 overlap
           if (!boost) {
             if (!noHmass_in_event) nonHiggsJet=passJet.size()-2;
             else nonHiggsJet=passJet.size();
           }
           else {
             int overlapped=0;
             for (auto i : passJet) if (deltaR(FatJet_phi[SelectedAK8Jet],Jet_phi[i],FatJet_eta[SelectedAK8Jet],Jet_eta[i])<0.8) overlapped++;
             nonHiggsJet=passJet.size()-overlapped;
           }
           njet = (nonHiggsJet<4) ? 1 : 2;
           
           int nonHiggsJet_forAK8=0, nonHiggsJet_forAK4=0;
           if (passAK8Jet.size()>0) {
             int overlapped=0;
             for (auto i : passJet) if (deltaR(FatJet_phi[SelectedAK8Jet],Jet_phi[i],FatJet_eta[SelectedAK8Jet],Jet_eta[i])<0.8) overlapped++;
             nonHiggsJet_forAK8=passJet.size()-overlapped;
           }
           if (passJet.size()>2) nonHiggsJet_forAK4=passJet.size()-2;
           int njet_AK8 = (nonHiggsJet_forAK8<4) ? 1 : 2;
           int njet_AK4 = (nonHiggsJet_forAK4<4) ? 1 : 2;

           //dphi met and selected jet(s)
           double dphi_H_ak8=999, dphi_H_ak4=999, dphi_Hmin_ak4=999, dphi_AK4btag=999;
           double pt_Hmin=-1;
           if (passAK8Jet.size()>0) dphi_H_ak8=abs(deltaPhi(FatJet_phi[SelectedAK8Jet],METPhi));
           if (passJet.size()>1) {
             double dphi1=deltaPhi(Jet_phi[passJet[0]],METPhi);
             double dphi2=deltaPhi(Jet_phi[passJet[1]],METPhi);
             (abs(dphi1)<abs(dphi2)) ? dphi_AK4btag=abs(dphi1) : dphi_AK4btag=abs(dphi2);
             dphi1=deltaPhi(Jet_phi[SelectedAK4Jet1],METPhi);
             dphi2=deltaPhi(Jet_phi[SelectedAK4Jet2],METPhi);
             if (abs(dphi1)<abs(dphi2)) {dphi_Hmin_ak4=abs(dphi1); pt_Hmin=jetSmearedPt[SelectedAK4Jet1];}
             else {dphi_Hmin_ak4=abs(dphi2); pt_Hmin=jetSmearedPt[SelectedAK4Jet2];}
             dphi_H_ak4=abs(deltaPhi(phi_H_candidate,METPhi));
           }
           if (boost) dphi_met_H_candidate=dphi_H_ak8;
           else {dphi_met_H_candidate=dphi_H_ak4; dphi_met_Hmin_candidate=dphi_Hmin_ak4;}
           
           double sbFill_ak4ak8[dim_ak4]={double(AK4AK8),met,njet};
           
           
           //2d dphi distributions
           if (met>3 && AK4AK8>0) {
             if (njet==1) {
               if (boost) {
                 h2_dphi_met_h_pt_lowjet->Fill(dphi_H_ak8,FatJet_pt_nom[SelectedAK8Jet],w);
                 h2_dphi_met_hmin_pt_lowjet->Fill(dphi_H_ak8,FatJet_pt_nom[SelectedAK8Jet],w);
               }
               else {
                 h2_dphi_met_h_pt_lowjet->Fill(dphi_H_ak4,pt_H_candidate,w);
                 h2_dphi_met_hmin_pt_lowjet->Fill(dphi_Hmin_ak4,pt_Hmin,w);
               }
             }
             else {
               if (boost) {
                 h2_dphi_met_h_pt_highjet->Fill(dphi_H_ak8,FatJet_pt_nom[SelectedAK8Jet],w);
                 h2_dphi_met_hmin_pt_highjet->Fill(dphi_H_ak8,FatJet_pt_nom[SelectedAK8Jet],w);
               }
               else {
                 h2_dphi_met_h_pt_lowjet->Fill(dphi_H_ak4,pt_H_candidate,w);
                 h2_dphi_met_hmin_pt_highjet->Fill(dphi_Hmin_ak4,pt_Hmin,w);
               }
             }
           }
           //Efficiency fill for no cuts bin
           h_eff->Fill(0.,w); if (SignalScan) m_eff[mass_pair]->Fill(0.,w);
           //cuts with command line
           if (is_debug) cout<<"Applying cuts"<<endl;
           if (_cut_variable.size()>0) {if (!(Cut(ientry,mass_pair))) continue;}
           else { //Hardcoded cuts
             if (PV_npvsGood==0) continue;
           }
           
           //Filling histograms
           if (is_debug) cout<<"Event accepted, filling histograms"<<endl;
                 
           if (h_puW->GetBinContent(h_puW->FindBin(Pileup_nTrueInt))==0) h_puW->SetBinContent(h_puW->FindBin(Pileup_nTrueInt),pu_weight);
           OverFill(h_eff,1.,w); OverFill(h_eff,2.,weight);
           OverFill(h_nISR_jet,n_isr_jets,w);

           OverFill(h_nPV,PV_npvsGood,w);
           OverFill(h_nTrueInt,Pileup_nTrueInt,1);
           OverFill(h_nPU,Pileup_nPU,1);

           if (nleadPho!=-1) OverFill(h_phoEt,phoET[nleadPho],w);
           if (nleadPho!=-1) OverFill(h_phoEta,Photon_eta[nleadPho],w);
           if (nleadPho!=-1) OverFill(h_phoPt,phoET[nleadPho],w);

           OverFill(h_pfMET,MET,w);
           OverFill(h_pfMET_fix,MET,w);
           OverFill(h_pfMET_fix2,MET,w);
           OverFill(h_pfMETsumEt,METsumEt,w);
           OverFill(h_pfMETPhi,METPhi,w);
           OverFill(h_pfMETSig,METSig,w);
           
           OverFill(h2_higgs_pfMET,higgs_category,MET,w);

           OverFill(h_ST,ST,w);
           OverFill(h_ST_fix,ST,w);
           OverFill(h_ST_G,ST_G,w);
           OverFill(h_MT,MT,w);
           OverFill(h_MT_fix,MT,w);
           OverFill(h_HT_after,HT_after,w);
           OverFill(h_EMHT_after,EMHT_after,w);
           OverFill(h2_ST_HT,ST,HT_after,w);
           OverFill(h2_ST_MET,ST,MET,w);
           OverFill(h2_MT_MET,MT,MET,w);
           OverFill(h2_MET_HT,MET,HT_after,w);
           OverFill(h2_MET_extrajets,MET,nonHiggsJet,w);
           if (nleadPho!=-1) OverFill(h2_MET_phoPt,MET,phoET[nleadPho],w);
           OverFill(h2_extrajets_HT,nonHiggsJet,HT_after,w);

           OverFill(h_nPho,nPassPhoL,w);
           OverFill(h_nEle,nPassEleL,w);
           OverFill(h_nEleM,nPassEleM,w);
           OverFill(h_nEleT,nPassEleT,w);
           OverFill(h_nMu,nPassMuL,w);
           OverFill(h_nMuM,nPassMuM,w);
           OverFill(h_nMuT,nPassMuT,w);
           OverFill(h_nTau,nPassTauL,w);
           OverFill(h_nIso,nPassIso,w);
           
           if (nleadEle!=-1) OverFill(h_ElePt,Electron_pt[nleadEle],w);
           if (nleadMu!=-1) OverFill(h_MuPt,Muon_pt[nleadMu],w);
           if (nleadTau!=-1) OverFill(h_TauPt,tauPt[nleadTau],w);
           if (nleadEle!=-1) OverFill(h_ElePt_fix,Electron_pt[nleadEle],w);
           if (nleadMu!=-1) OverFill(h_MuPt_fix,Muon_pt[nleadMu],w);
           if (nleadTau!=-1) OverFill(h_TauPt_fix,tauPt[nleadTau],w);

           OverFill(h_njets,nPassAK4,w);
           OverFill(h_nonHjets,nonHiggsJet,w);
           if (leadpt_ak4!=-1) OverFill(h_jetpt,Jet_pt_nom[leadpt_ak4],w);
           OverFill(h_nAK8jets,nPassAK8,w);
           if (leadpt_ak8!=-1) OverFill(h_AK8jetpt,FatJet_pt_nom[leadpt_ak8],w);
   
           if (passJet.size()>0) {
             OverFill(h_bjets_l,bcounterDeep[1],w);
             OverFill(h_bjets_m,bcounterDeep[2],w);
             OverFill(h_bjets_t,bcounterDeep[3],w);
             if (bcounterDeep[1]>0) OverFill(h_pt_bjets_l1,Jet_pt_nom[passJet.at(0)],w);
             if (passJet.size()>1) if (bcounterDeep[1]>1) OverFill(h_pt_bjets_l2,Jet_pt_nom[passJet.at(1)],w);
             if (bcounterDeep[2]>0) OverFill(h_pt_bjets_m,Jet_pt_nom[passJet.at(0)],w);
             OverFill(h_disc_bjets_1,jetbtagDeepFlavB[passJet.at(0)],w);
             if (passJet.size()>1) OverFill(h_disc_bjets_2,jetbtagDeepFlavB[passJet.at(1)],w);
           }
           if (passAK8Jet.size()>0) {
             OverFill(h_AK8bjets_l,bcounterDDBvL[1],w);
             OverFill(h_AK8bjets_m,bcounterDDBvL[2],w);
             OverFill(h_AK8bjets_h,bcounterDDBvL[3],w);
             OverFill(h_AK8bjets_t,bcounterDDBvL[4],w);
             if (bcounterDDBvL[1]>0) OverFill(h_pt_AK8bjets_l,FatJet_pt_nom[passAK8Jet.at(0)],w);
             OverFill(h_disc_AK8bjets_1,FatJet_btagDDBvLV2[passAK8Jet.at(0)],w);
           }
   
           OverFill(h_dr_pho_parton,dr_pho_parton,w);
           OverFill(h_true_b,true_b_quark,w); (true_b_jet) ? OverFill(h_true_b,3,w) : OverFill(h_true_b,2,w);


           if (m_bb_deep!=-1) OverFill(h_mbbjet_select,m_bb_deep,w);
           if (DDBvL_selected>0) OverFill(h_AK8mass_select,AK8JetSmearedMass[SelectedAK8Jet],w);
           if (dR_ak4_Hcandidate!=-1) OverFill(h_dR_ak4_Hcandidate,dR_ak4_Hcandidate,w);
           if (pt_ak4_Hcandidate1!=-1) OverFill(h_pt_ak4_Hcandidate,pt_ak4_Hcandidate1,w);
           if (pt_ak4_Hcandidate2!=-1) OverFill(h_pt_ak4_Hcandidate,pt_ak4_Hcandidate2,w);
           if (dphi_met_jet!=999) OverFill(h_dphi_met_jet,dphi_met_jet,w);
           if (njet==1 && met>3 && AK4AK8>0 &&dphi_met_jet!=999 && pt_dphi_jet!=-1) OverFill(h2_dphi_met_lowjet_pt,dphi_met_jet,pt_dphi_jet,w);
           if (njet==2 && met>3 && AK4AK8>0 &&dphi_met_jet!=999 && pt_dphi_jet!=-1) OverFill(h2_dphi_met_highjet_pt,dphi_met_jet,pt_dphi_jet,w);
           if (dphi_met_jet!=999) OverFill(h2_dphi_met_jet_nonHjets,dphi_met_jet,nonHiggsJet,w);
           for (int i=0;i<8;i++) OverFill(h2_dphi_met_jet_njet,dphi_met_jet_njet[i],i+1,w);
           if (dphi_H_ak8!=999) OverFill(h_dphi_met_h_ak8,dphi_H_ak8,w);
           if (dphi_H_ak4!=999) OverFill(h_dphi_met_h_ak4,dphi_H_ak4,w);
           if (dphi_Hmin_ak4!=999) OverFill(h_dphi_met_hmin_ak4,dphi_Hmin_ak4,w);
           if (dphi_AK4btag!=999) OverFill(h_dphi_met_ak4btag,dphi_AK4btag,w);
           if (dphi_met_btags!=999) OverFill(h_dphi_met_btags,dphi_met_btags,w);
           if (passJet.size()>1) {
             OverFill(h2_bjet1_pt_disc,jetSmearedPt[passJet.at(0)],jetbtagDeepFlavB[passJet.at(0)],w);
             OverFill(h2_bjet2_pt_disc,jetSmearedPt[passJet.at(1)],jetbtagDeepFlavB[passJet.at(1)],w);
             int b1=0, b2=0;
             (passDeep.find(passJet.at(0))->second=='L') ? b1=1 : (passDeep.find(passJet.at(0))->second=='M') ? b1=2 : (passDeep.find(passJet.at(0))->second=='T') ? b1=3 : b1=0;
             (passDeep.find(passJet.at(1))->second=='L') ? b2=1 : (passDeep.find(passJet.at(1))->second=='M') ? b2=2 : (passDeep.find(passJet.at(1))->second=='T') ? b2=3 : b2=0;
             int H1=0, H2=0;
             (passDeep.find(SelectedAK4Jet1)->second=='L') ? H1=1 : (passDeep.find(SelectedAK4Jet1)->second=='M') ? H1=2 : (passDeep.find(SelectedAK4Jet1)->second=='T') ? H1=3 : H1=0;
             (passDeep.find(SelectedAK4Jet2)->second=='L') ? H2=1 : (passDeep.find(SelectedAK4Jet2)->second=='M') ? H2=2 : (passDeep.find(SelectedAK4Jet2)->second=='T') ? H2=3 : H2=0;
             OverFill(h2_AK4_btags,b1,b2,w);
             OverFill(h2_AK4Higgs_btags,H1,H2,w);
           }

           //AK4-AK8 searchbin fills
           double w_AK4searchBin=w, w_AK8searchBin=w;
           //if (boost==1 && AK4AK8==1) w_AK8searchBin*=DDBvL_SF_M1[DDBvL_whichSF];//AK8medium
           if (boost==1 && AK4AK8==1) w_AK8searchBin*=DDBvL_SF_L[DDBvL_whichSF];
           switch (boost) {
             case 0 :
               {
               //double check= hn_AK4searchBins->GetBinContent(230);
               hn_AK4searchBins->Fill(sbFill_ak4ak8,w_AK4searchBin);
               hn_AK4searchBins_noweight->Fill(sbFill_ak4ak8);
               if (HT_after>1500) hn_AK4HTsearchBins->Fill(sbFill_ak4ak8,w_AK4searchBin);
               break;
               }
             case 1 :
               hn_AK8searchBins->Fill(sbFill_ak4ak8,w_AK8searchBin);
               hn_AK8searchBins_noweight->Fill(sbFill_ak4ak8);
               if (HT_after>1500) hn_AK8HTsearchBins->Fill(sbFill_ak4ak8,w_AK8searchBin);
               break;
           }
           //if (jentry==3302907) {
             //if (boost) cout << fixed << setprecision(4) << jentry<<" "<<event<<" "<<pu_weight<<" "<<weight<<" "<<pho_SF[0]<<" "<<nonPrefiringProbability[0]<<" "<<ele_SF[1]<<" "<<ele_VETOSF<<" "<<mu_SF[0]<<" "<<tau_SF[0]<<" "<<w_isr<<" "<<" "<<w_AK8searchBin<<endl;
             //else       cout << fixed << setprecision(4) << jentry<<" "<<event<<" "<<pu_weight<<" "<<weight<<" "<<pho_SF[0]<<" "<<nonPrefiringProbability[0]<<" "<<ele_SF[1]<<" "<<ele_VETOSF<<" "<<mu_SF[0]<<" "<<tau_SF[0]<<" "<<w_isr<<" "<<" "<<w_AK4searchBin<<endl;
           //}

           //higgs mass distribution plot fills
           if (passAK8Jet.size()>0) {
             int massRegion = (met-1)*2+njet_AK8;
             double m=AK8JetSmearedMass[SelectedAK8Jet];
             if (bcounterDDBvL[1]>0) {
               if (!isData || (m<70 || m>200)) {
                 OverFill(h2_mHAK8,massRegion,m,w*DDBvL_SF_L[DDBvL_whichSF]);
                 OverFill(h_mHAK8,m,w*DDBvL_SF_L[DDBvL_whichSF]);
               }
               OverFill(h2_dphi_met_h_ak8,massRegion,dphi_H_ak8,w*DDBvL_SF_L[DDBvL_whichSF]);
               OverFill(h2_dphi_met_btags_ak8,massRegion,dphi_met_btags,w*DDBvL_SF_L[DDBvL_whichSF]);
             }
             else {
               OverFill(h2_mHAK8_clean_fake,massRegion,m,w*DDBvL_SF_L[DDBvL_whichSF]);
               OverFill(h_mHAK8_clean_fake,m,w*DDBvL_SF_L[DDBvL_whichSF]);
               if (AK4AK8==0){
                 OverFill(h2_mHAK8_fake,massRegion,m,w*DDBvL_SF_L[DDBvL_whichSF]);
                 OverFill(h_mHAK8_fake,m,w*DDBvL_SF_L[DDBvL_whichSF]);
               }
             }
           }
           if (passJet.size()>1) {
             int massRegion = (met-1)*2+njet_AK4;
             double m=m_bb_deep;
             TLorentzVector bjet1, bjet2; //Needed because, in VR there can be passHiggsmass w/o btag AND a btagged jet
             bjet1.SetPtEtaPhiM(jetSmearedPt[passJet.at(0)],Jet_eta[passJet.at(0)],Jet_phi[passJet.at(0)],jetSmearedMass[passJet.at(0)]);
             bjet2.SetPtEtaPhiM(jetSmearedPt[passJet.at(1)],Jet_eta[passJet.at(1)],Jet_phi[passJet.at(1)],jetSmearedMass[passJet.at(1)]);
             double m2=(bjet1+bjet2).M();
             double dR = deltaR(Jet_phi[SelectedAK4Jet1],Jet_phi[SelectedAK4Jet2],Jet_eta[SelectedAK4Jet1],Jet_eta[SelectedAK4Jet2]);
             double dR2= deltaR(Jet_phi[passJet.at(0)],Jet_phi[passJet.at(1)],Jet_eta[passJet.at(0)],Jet_eta[passJet.at(1)]);
             if (bcounterDeep[2]>0) {
               double mass = (Deep_medium_selected==1) ? m : m2;
               double delta_r = (Deep_medium_selected==1) ? dR : dR2;
               if (!isData || (mass<80 || mass>160)) {
                 OverFill(h2_mHAK4_clean,massRegion,mass,w);
                 OverFill(h_mHAK4_clean,mass,w);
                 if (higgs_category!=4) {
                   OverFill(h2_mHAK4,massRegion,mass,w);
                   OverFill(h_mHAK4,mass,w);
                 }
                 OverFill(h2_dr_SRHiggs,massRegion,delta_r,w);
                 h3_mHAK4_dr_Higgs->Fill(massRegion,mass,delta_r,w);
               }
             }
             if (bcounterDeep[2]==0){
               OverFill(h2_mHAK4_clean_fake,massRegion,m,w);
               OverFill(h_mHAK4_clean_fake,m,w);
               if (!boost) {
                 OverFill(h2_mHAK4_fake,massRegion,m,w);
                 OverFill(h_mHAK4_fake,m,w);
               }
             }
             OverFill(h2_dphi_met_h_ak4,massRegion,dphi_H_ak4,w);
             OverFill(h2_dphi_met_hmin_ak4,massRegion,dphi_Hmin_ak4,w);
             OverFill(h2_dphi_met_ak4btag,massRegion,dphi_AK4btag,w);
             OverFill(h2_dphi_met_btags_ak4,massRegion,dphi_met_btags,w*DDBvL_SF_L[DDBvL_whichSF]);
           }
     
     //SignalRegion -- not the real SR, but almost
     int SignalRegion=0;
     if (met>3 && AK4AK8!=0) {
       SignalRegion=(met-4)*6+AK4AK8+boost*2+(njet-1)*3;
       if (SignalRegion==15 || SignalRegion==18) SignalRegion=16;
       else if (SignalRegion==16 || SignalRegion==17) SignalRegion=15;
       OverFill(h_SR,SignalRegion,w); if (SignalScan) OverFill(m_SR[mass_pair],SignalRegion,w);
       //cout<<"met "<<met<<" njet "<<njet<<" boost "<<boost<<" ak4ak8 "<<AK4AK8<<" SRbin "<<SignalRegion<<endl;
     }
    
     if (SignalScan) {
       if (is_debug) cout<<"Filling mass point histograms"<<endl;
       OverFill(m_eff[mass_pair],1.,w); OverFill(m_eff[mass_pair],2.,weight);

       OverFill(m_nISR_jet[mass_pair],n_isr_jets,w);
       
       OverFill(m_nPV[mass_pair],PV_npvsGood,w);

       if (nleadPho!=-1) OverFill(m_phoEt[mass_pair],phoET[nleadPho],w);
       if (nleadPho!=-1) OverFill(m_phoEta[mass_pair],Photon_eta[nleadPho],w);
       if (nleadPho!=-1) OverFill(m_phoPt[mass_pair],phoET[nleadPho],w);
       
       OverFill(m_pfMET[mass_pair],MET,w);
       OverFill(m_pfMET_fix[mass_pair],MET,w);
       OverFill(m_pfMET_fix2[mass_pair],MET,w);
       OverFill(m_pfMETsumEt[mass_pair],METsumEt,w);
       OverFill(m_pfMETPhi[mass_pair],METPhi,w);
       OverFill(m_pfMETSig[mass_pair],METSig,w);

       OverFill(m2_higgs_pfMET[mass_pair],higgs_category,MET,w);

       OverFill(m_ST[mass_pair],ST,w);
       OverFill(m_ST_fix[mass_pair],ST,w);
       OverFill(m_ST_G[mass_pair],ST_G,w);
       OverFill(m_MT[mass_pair],MT,w);
       OverFill(m_MT_fix[mass_pair],MT,w);
       OverFill(m_HT_after[mass_pair],HT_after,w);
       OverFill(m_EMHT_after[mass_pair],EMHT_after,w);
       OverFill(m2_ST_HT[mass_pair],ST,HT_after,w);
       OverFill(m2_ST_MET[mass_pair],ST,MET,w);
       OverFill(m2_MT_MET[mass_pair],MT,MET,w);
       OverFill(m2_MET_HT[mass_pair],MET,HT_after,w);
       if (nleadPho!=-1) OverFill(m2_MET_phoPt[mass_pair],MET,phoET[nleadPho],w);
       OverFill(m2_MET_extrajets[mass_pair],MET,nonHiggsJet,w);
       OverFill(m2_extrajets_HT[mass_pair],nonHiggsJet,HT_after,w);
      
       OverFill(m_nPho[mass_pair],nPassPhoL,w);
       OverFill(m_nEle[mass_pair],nPassEleL,w);
       OverFill(m_nEleM[mass_pair],nPassEleM,w);
       OverFill(m_nEleT[mass_pair],nPassEleT,w);
       OverFill(m_nMu[mass_pair],nPassMuL,w);
       OverFill(m_nMuM[mass_pair],nPassMuM,w);
       OverFill(m_nMuT[mass_pair],nPassMuT,w);
       OverFill(m_nTau[mass_pair],nPassTauL,w);
       OverFill(m_nIso[mass_pair],nPassIso,w);
      
       if (nleadEle!=-1) OverFill(m_ElePt[mass_pair],Electron_pt[nleadEle],w);
       if (nleadMu!=-1) OverFill(m_MuPt[mass_pair],Muon_pt[nleadMu],w);
       if (nleadTau!=-1) OverFill(m_TauPt[mass_pair],tauPt[nleadTau],w);
       if (nleadEle!=-1) OverFill(m_ElePt_fix[mass_pair],Electron_pt[nleadEle],w);
       if (nleadMu!=-1) OverFill(m_MuPt_fix[mass_pair],Muon_pt[nleadMu],w);
       if (nleadTau!=-1) OverFill(m_TauPt_fix[mass_pair],tauPt[nleadTau],w);

       OverFill(m_njets[mass_pair],nPassAK4,w);
       OverFill(m_nonHjets[mass_pair],nonHiggsJet,w);
       if (leadpt_ak4!=-1) OverFill(m_jetpt[mass_pair],Jet_pt_nom[leadpt_ak4],w);
       OverFill(m_nAK8jets[mass_pair],nPassAK8,w);
       if (leadpt_ak8!=-1) OverFill(m_AK8jetpt[mass_pair],FatJet_pt_nom[leadpt_ak8],w);
   
       if (passJet.size()>0) {
         OverFill(m_bjets_l[mass_pair],bcounterDeep[1],w);
         OverFill(m_bjets_m[mass_pair],bcounterDeep[2],w);
         OverFill(m_bjets_t[mass_pair],bcounterDeep[3],w);
         if (bcounterDeep[1]>0) OverFill(m_pt_bjets_l1[mass_pair],Jet_pt_nom[passJet.at(0)],w);
         if (passJet.size()>1) if (bcounterDeep[1]>1) OverFill(m_pt_bjets_l2[mass_pair],Jet_pt_nom[passJet.at(1)],w);
         if (bcounterDeep[2]>0) OverFill(m_pt_bjets_m[mass_pair],Jet_pt_nom[passJet.at(0)],w);
         OverFill(m_disc_bjets_1[mass_pair],jetbtagDeepFlavB[passJet.at(0)],w);
         if (passJet.size()>1) OverFill(m_disc_bjets_2[mass_pair],jetbtagDeepFlavB[passJet.at(1)],w);
       }
       if (passAK8Jet.size()>0) {
         OverFill(m_AK8bjets_l[mass_pair],bcounterDDBvL[1],w);
         OverFill(m_AK8bjets_m[mass_pair],bcounterDDBvL[2],w);
         OverFill(m_AK8bjets_h[mass_pair],bcounterDDBvL[3],w);
         OverFill(m_AK8bjets_t[mass_pair],bcounterDDBvL[4],w);
         if (bcounterDDBvL[1]>0) OverFill(m_pt_AK8bjets_l[mass_pair],FatJet_pt_nom[passAK8Jet.at(0)],w);
         OverFill(m_disc_AK8bjets_1[mass_pair],FatJet_btagDDBvLV2[passAK8Jet.at(0)],w);
       }
		  
       
       if (m_bb_deep!=-1) OverFill(m_mbbjet_select[mass_pair],m_bb_deep,w);
       if (DDBvL_selected>0) OverFill(m_AK8mass_select[mass_pair],AK8JetSmearedMass[SelectedAK8Jet],w);
       if (dR_ak4_Hcandidate!=-1) OverFill(m_dR_ak4_Hcandidate[mass_pair],dR_ak4_Hcandidate,w);
       if (pt_ak4_Hcandidate1!=-1) OverFill(m_pt_ak4_Hcandidate[mass_pair],pt_ak4_Hcandidate1,w);
       if (pt_ak4_Hcandidate2!=-1) OverFill(m_pt_ak4_Hcandidate[mass_pair],pt_ak4_Hcandidate2,w);
       if (dphi_met_jet!=999) OverFill(m_dphi_met_jet[mass_pair],dphi_met_jet,w);
       if (dphi_met_jet!=999) OverFill(m2_dphi_met_jet_nonHjets[mass_pair],dphi_met_jet,nonHiggsJet,w);
       for (int i=0;i<8;i++) OverFill(m2_dphi_met_jet_njet[mass_pair],dphi_met_jet_njet[i],i+1,w);
       if (njet==1 && met>3 && AK4AK8>0 && dphi_met_jet!=999 && pt_dphi_jet!=-1) OverFill(m2_dphi_met_lowjet_pt[mass_pair],dphi_met_jet,pt_dphi_jet,w);
       if (njet==2 && met>3 && AK4AK8>0 && dphi_met_jet!=999 && pt_dphi_jet!=-1) OverFill(m2_dphi_met_highjet_pt[mass_pair],dphi_met_jet,pt_dphi_jet,w);
       if (dphi_H_ak8!=999) OverFill(m_dphi_met_h_ak8[mass_pair],dphi_H_ak8,w);
       if (dphi_H_ak4!=999) OverFill(m_dphi_met_h_ak4[mass_pair],dphi_H_ak4,w);
       if (dphi_Hmin_ak4!=999) OverFill(m_dphi_met_hmin_ak4[mass_pair],dphi_Hmin_ak4,w);
       if (dphi_AK4btag!=999) OverFill(m_dphi_met_ak4btag[mass_pair],dphi_AK4btag,w);
       if (dphi_met_btags!=999) OverFill(m_dphi_met_btags[mass_pair],dphi_met_btags,w);
       if (passJet.size()>1) {
         OverFill(m2_bjet1_pt_disc[mass_pair],jetSmearedPt[passJet.at(0)],jetbtagDeepFlavB[passJet.at(0)],w);
         OverFill(m2_bjet2_pt_disc[mass_pair],jetSmearedPt[passJet.at(1)],jetbtagDeepFlavB[passJet.at(1)],w);
         int b1=0, b2=0;
         (passDeep.find(passJet.at(0))->second=='L') ? b1=1 : (passDeep.find(passJet.at(0))->second=='M') ? b1=2 : (passDeep.find(passJet.at(0))->second=='T') ? b1=3 : b1=0;
         (passDeep.find(passJet.at(1))->second=='L') ? b2=1 : (passDeep.find(passJet.at(1))->second=='M') ? b2=2 : (passDeep.find(passJet.at(1))->second=='T') ? b2=3 : b2=0;
         int H1=0, H2=0;
         (passDeep.find(SelectedAK4Jet1)->second=='L') ? H1=1 : (passDeep.find(SelectedAK4Jet1)->second=='M') ? H1=2 : (passDeep.find(SelectedAK4Jet1)->second=='T') ? H1=3 : H1=0;
         (passDeep.find(SelectedAK4Jet2)->second=='L') ? H2=1 : (passDeep.find(SelectedAK4Jet2)->second=='M') ? H2=2 : (passDeep.find(SelectedAK4Jet2)->second=='T') ? H2=3 : H2=0;
         OverFill(m2_AK4_btags[mass_pair],b1,b2,w);
         OverFill(m2_AK4Higgs_btags[mass_pair],H1,H2,w);
       }

       if (signalstudy) {
         if (Higgs_pt!=-1) OverFill(m_Hpt[mass_pair],Higgs_pt,w);
         //m_AK8Hmass[mass_pair]
         if (Hbbmass!=-1) (Hbbmass>270) ? m_Hbbmass[mass_pair]->Fill(270,w) : (Hbbmass<18) ? m_Hbbmass[mass_pair]->Fill(19,w) : m_Hbbmass[mass_pair]->Fill(Hbbmass,w);
         if (genAK4Hmass!=-1) (genAK4Hmass>270) ? m_genAK4Hmass[mass_pair]->Fill(270,w) : (genAK4Hmass<18) ? m_genAK4Hmass[mass_pair]->Fill(19,w) : m_genAK4Hmass[mass_pair]->Fill(genAK4Hmass,w);
         if (AK4Hmass!=-1) (AK4Hmass>270) ? m_AK4Hmass[mass_pair]->Fill(270,w) : (AK4Hmass<18) ? m_AK4Hmass[mass_pair]->Fill(19,w) : m_AK4Hmass[mass_pair]->Fill(AK4Hmass,w);
         if (Higgs_jet_b!=-1) OverFill(m_AK4Hpt[mass_pair],jetSmearedPt[Higgs_jet_b],w);
         if (Higgs_jet_antib!=-1) OverFill(m_AK4Hpt[mass_pair],jetSmearedPt[Higgs_jet_antib],w);
         //m_PhoEt[mass_pair]
         if (dR_trueHbb!=-1) m_dR_AK4AK4_trueHbb[mass_pair]->Fill(dR_trueHbb,w);
         if (dR_trueHbb!=-1 && AK4Hmass!=-1) (AK4Hmass>270) ? m2_true_dR_AK4AK4_mass[mass_pair]->Fill(dR_trueHbb,270,w) : (AK4Hmass<18) ? m2_true_dR_AK4AK4_mass[mass_pair]->Fill(dR_trueHbb,19,w) : m2_true_dR_AK4AK4_mass[mass_pair]->Fill(dR_trueHbb,AK4Hmass,w);
         if (Higgs_jet_b!=-1 && Higgs_jet_antib!=-1) {
           m2_AK4_ij[mass_pair]->Fill(index_b+1,index_ab+1,w);
           m2_AK4_ij_njet[mass_pair]->Fill((index_b+1)/njet_index,(index_ab+1)/njet_index,w);
         }
         if (Higgs_jet_b!=-1 && Higgs_jet_antib!=-1) {
           int b=0, ab=0;
           (passDeep.find(Higgs_jet_b)->second=='L') ? b=1 : (passDeep.find(Higgs_jet_b)->second=='M') ? b=2 : (passDeep.find(Higgs_jet_b)->second=='T') ? b=3 : b=0;
           (passDeep.find(Higgs_jet_antib)->second=='L') ? ab=1 : (passDeep.find(Higgs_jet_antib)->second=='M') ? ab=2 : (passDeep.find(Higgs_jet_antib)->second=='T') ? ab=3 : ab=0;
           m2_AK4_btag[mass_pair]->Fill(b,ab,w);
           (b>ab) ? m2_AK4_btag_highest[mass_pair]->Fill(b,ab,w) : m2_AK4_btag_highest[mass_pair]->Fill(ab,b,w);
           if (dphi_trueH_ak4!=999) m_dphi_met_trueh_ak4[mass_pair]->Fill(dphi_trueH_ak4,w);
           if (dphi_trueHmin_ak4!=999) m_dphi_met_truehmin_ak4[mass_pair]->Fill(dphi_trueHmin_ak4,w);
           if (dphi_trueH_gravitino!=999) m_dphi_trueh_gravitino[mass_pair]->Fill(dphi_trueH_gravitino,w);
           OverFill(m2_true_Hjet1_pt_disc[mass_pair],pt_true_Hjet1,disc_true_Hjet1,w);
           OverFill(m2_true_Hjet2_pt_disc[mass_pair],pt_true_Hjet2,disc_true_Hjet2,w);
         }
         int first=-1, second=-1;
         for (auto i : passJet) {
           if (i==Higgs_jet_b || i==Higgs_jet_antib) continue;
           if (first==-1) first=i;
           else {second=i;break;}
         }
         if (first!=-1 && second!=-1) OverFill(m2_true_nonHjet1_pt_disc[mass_pair],jetSmearedPt[first],jetbtagDeepFlavB[first],w);
         if (first!=-1 && second!=-1) OverFill(m2_true_nonHjet2_pt_disc[mass_pair],jetSmearedPt[second],jetbtagDeepFlavB[second],w);
       }
       
       switch (boost) {
         case 0 : 
           mn_AK4searchBins[mass_pair]->Fill(sbFill_ak4ak8,w_AK4searchBin);
           mn_AK4searchBins_noweight[mass_pair]->Fill(sbFill_ak4ak8);
           if (HT_after>1500) mn_AK4HTsearchBins[mass_pair]->Fill(sbFill_ak4ak8,w_AK4searchBin);
           break;
         case 1 :
           mn_AK8searchBins[mass_pair]->Fill(sbFill_ak4ak8,w_AK8searchBin);
           mn_AK8searchBins_noweight[mass_pair]->Fill(sbFill_ak4ak8);
           if (HT_after>1500) mn_AK8HTsearchBins[mass_pair]->Fill(sbFill_ak4ak8,w_AK8searchBin);
         break;
       }
       //dphi histogram fills
       if (met>3 && AK4AK8>0) {
         if (njet==1) {
           if (boost) {
             m2_dphi_met_h_pt_lowjet[mass_pair]->Fill(dphi_H_ak8,FatJet_pt_nom[SelectedAK8Jet],w);
             m2_dphi_met_hmin_pt_lowjet[mass_pair]->Fill(dphi_H_ak8,FatJet_pt_nom[SelectedAK8Jet],w);
           }
           else {
             m2_dphi_met_h_pt_lowjet[mass_pair]->Fill(dphi_H_ak4,pt_H_candidate,w);
             m2_dphi_met_hmin_pt_lowjet[mass_pair]->Fill(dphi_Hmin_ak4,pt_Hmin,w);
           }
         }
         else {
           if (boost) {
             m2_dphi_met_h_pt_highjet[mass_pair]->Fill(dphi_H_ak8,FatJet_pt_nom[SelectedAK8Jet],w);
             m2_dphi_met_hmin_pt_highjet[mass_pair]->Fill(dphi_H_ak8,FatJet_pt_nom[SelectedAK8Jet],w);
           }
           else {
             m2_dphi_met_h_pt_lowjet[mass_pair]->Fill(dphi_H_ak4,pt_H_candidate,w);
             m2_dphi_met_hmin_pt_highjet[mass_pair]->Fill(dphi_Hmin_ak4,pt_Hmin,w);
           }
         }
       }
       //higgs mass distribution plot fills
       if (passAK8Jet.size()>0) {
         int massRegion = (met-1)*2+njet_AK8;
         double m=AK8JetSmearedMass[SelectedAK8Jet];
         if (bcounterDDBvL[1]>0) {
           if (!isData || (m<70 || m>200)) {
             OverFill(m2_mHAK8[mass_pair],massRegion,m,w*DDBvL_SF_L[DDBvL_whichSF]);
             OverFill(m_mHAK8[mass_pair],m,w*DDBvL_SF_L[DDBvL_whichSF]);
           }
           OverFill(m2_dphi_met_h_ak8[mass_pair],massRegion,dphi_H_ak8,w*DDBvL_SF_L[DDBvL_whichSF]);
           OverFill(m2_dphi_met_btags_ak8[mass_pair],massRegion,dphi_met_btags,w*DDBvL_SF_L[DDBvL_whichSF]);
         }
         else {
           OverFill(m2_mHAK8_clean_fake[mass_pair],massRegion,m,w*DDBvL_SF_L[DDBvL_whichSF]);
           OverFill(m_mHAK8_clean_fake[mass_pair],m,w*DDBvL_SF_L[DDBvL_whichSF]);
           if (AK4AK8==0){
             OverFill(m2_mHAK8_fake[mass_pair],massRegion,m,w*DDBvL_SF_L[DDBvL_whichSF]);
             OverFill(m_mHAK8_fake[mass_pair],m,w*DDBvL_SF_L[DDBvL_whichSF]);
           }
         }
       }
       if (passJet.size()>1) {
         int massRegion = (met-1)*2+njet_AK4;
         double m=m_bb_deep;
         TLorentzVector bjet1, bjet2; //Needed because, in VR there can be passHiggsmass w/o btag AND a btagged jet
         bjet1.SetPtEtaPhiM(jetSmearedPt[passJet.at(0)],Jet_eta[passJet.at(0)],Jet_phi[passJet.at(0)],jetSmearedMass[passJet.at(0)]);
         bjet2.SetPtEtaPhiM(jetSmearedPt[passJet.at(1)],Jet_eta[passJet.at(1)],Jet_phi[passJet.at(1)],jetSmearedMass[passJet.at(1)]);
         double m2=(bjet1+bjet2).M();
         double dR = deltaR(Jet_phi[SelectedAK4Jet1],Jet_phi[SelectedAK4Jet2],Jet_eta[SelectedAK4Jet1],Jet_eta[SelectedAK4Jet2]);
         double dR2= deltaR(Jet_phi[passJet.at(0)],Jet_phi[passJet.at(1)],Jet_eta[passJet.at(0)],Jet_eta[passJet.at(1)]);
         if (bcounterDeep[2]>0) {
           double mass = (Deep_medium_selected==1) ? m : m2;
           double delta_r = (Deep_medium_selected==1) ? dR : dR2;
           if (!isData || (mass<80 || mass>160)) {
             OverFill(m2_mHAK4_clean[mass_pair],massRegion,mass,w);
             OverFill(m_mHAK4_clean[mass_pair],mass,w);
             if (higgs_category!=5) {
               OverFill(m2_mHAK4[mass_pair],massRegion,mass,w);
               OverFill(m_mHAK4[mass_pair],mass,w);
             }
             OverFill(m2_dr_SRHiggs[mass_pair],massRegion,delta_r,w);
             m3_mHAK4_dr_Higgs[mass_pair]->Fill(massRegion,mass,delta_r,w);
           }
         }
         if (bcounterDeep[2]==0){
           OverFill(m2_mHAK4_clean_fake[mass_pair],massRegion,m,w);
           OverFill(m_mHAK4_clean_fake[mass_pair],m,w);
           if (!boost) {
             OverFill(m2_mHAK4_fake[mass_pair],massRegion,m,w);
             OverFill(m_mHAK4_fake[mass_pair],m,w);
           }
         }
         OverFill(m2_dphi_met_h_ak4[mass_pair],massRegion,dphi_H_ak4,w);
         OverFill(m2_dphi_met_hmin_ak4[mass_pair],massRegion,dphi_Hmin_ak4,w);
         OverFill(m2_dphi_met_ak4btag[mass_pair],massRegion,dphi_AK4btag,w);
         OverFill(m2_dphi_met_btags_ak4[mass_pair],massRegion,dphi_met_btags,w*DDBvL_SF_L[DDBvL_whichSF]);
       }
     }
   }

         for (unsigned int i=1;i<nsbins_ak4+1;i++) {
           h_AK4searchBins->SetBinContent(i,hn_AK4searchBins->GetBinContent(i));
           h_AK4searchBins->SetBinError(i,hn_AK4searchBins->GetBinError(i));
           h_AK4searchBins_noweight->SetBinContent(i,hn_AK4searchBins_noweight->GetBinContent(i));
           h_AK4searchBins_noweight->SetBinError(i,hn_AK4searchBins_noweight->GetBinError(i));
           h_AK8searchBins->SetBinContent(i,hn_AK8searchBins->GetBinContent(i));
           h_AK8searchBins->SetBinError(i,hn_AK8searchBins->GetBinError(i));
           h_AK8searchBins_noweight->SetBinContent(i,hn_AK8searchBins_noweight->GetBinContent(i));
           h_AK8searchBins_noweight->SetBinError(i,hn_AK8searchBins_noweight->GetBinError(i));
           h_AK4HTsearchBins->SetBinContent(i,hn_AK4HTsearchBins->GetBinContent(i));
           h_AK4HTsearchBins->SetBinError(i,hn_AK4HTsearchBins->GetBinError(i));
           h_AK8HTsearchBins->SetBinContent(i,hn_AK8HTsearchBins->GetBinContent(i));
           h_AK8HTsearchBins->SetBinError(i,hn_AK8HTsearchBins->GetBinError(i));
         }

   if (SignalScan) {
     for (auto const&i : grid) {
       for (auto j : i.second) {
       std::pair<int,int> MassPair(i.first,j);
         for (unsigned int k=1;k<nsbins_ak4+1;k++) {
           m_AK4searchBins[MassPair]->SetBinContent(k,mn_AK4searchBins[MassPair]->GetBinContent(k));
           m_AK4searchBins[MassPair]->SetBinError(k,mn_AK4searchBins[MassPair]->GetBinError(k));
           m_AK4searchBins_noweight[MassPair]->SetBinContent(k,mn_AK4searchBins_noweight[MassPair]->GetBinContent(k));
           m_AK4searchBins_noweight[MassPair]->SetBinError(k,mn_AK4searchBins_noweight[MassPair]->GetBinError(k));
           m_AK8searchBins[MassPair]->SetBinContent(k,mn_AK8searchBins[MassPair]->GetBinContent(k));
           m_AK8searchBins[MassPair]->SetBinError(k,mn_AK8searchBins[MassPair]->GetBinError(k));
           m_AK8searchBins_noweight[MassPair]->SetBinContent(k,mn_AK8searchBins_noweight[MassPair]->GetBinContent(k));
           m_AK8searchBins_noweight[MassPair]->SetBinError(k,mn_AK8searchBins_noweight[MassPair]->GetBinError(k));
           m_AK4HTsearchBins[MassPair]->SetBinContent(k,mn_AK4HTsearchBins[MassPair]->GetBinContent(k));
           m_AK4HTsearchBins[MassPair]->SetBinError(k,mn_AK4HTsearchBins[MassPair]->GetBinError(k));
           m_AK8HTsearchBins[MassPair]->SetBinContent(k,mn_AK8HTsearchBins[MassPair]->GetBinContent(k));
           m_AK8HTsearchBins[MassPair]->SetBinError(k,mn_AK8HTsearchBins[MassPair]->GetBinError(k));
         }
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
     string temp="CountSignal_"+year+".txt";
     counttxt.open (temp);
     if (SignalScenario==1 || SignalScenario==4) {
       bool newg=true;
       for (auto i : signal_events) {
         if (newg) counttxt<<"    if (a=="<<i.first.first<<") {\n      switch (b) {"<<endl;
         newg=false;
         counttxt<<"        case "<<i.first.second<<" : return "<<i.second<<";"<<endl;
         if (i.first.first-10==i.first.second) {newg=true; counttxt<<"    }\n  }"<<endl;}
       }
     }
     if (SignalScenario==2 || SignalScenario==5) for (auto i : signal_events) counttxt<<"      case "<<i.first.first<<" : return "<<i.second<<";"<<endl;
     if (SignalScenario==3) {
       for (auto i : signal_events) {
         if (i.first.second==127 || i.first.second==1000) counttxt<<"    if (a=="<<i.first.first<<") {\n      switch (b) {"<<endl;
         counttxt<<"        case "<<i.first.second<<" : return "<<i.second<<";"<<endl;
         if (i.first.second==200 || i.first.second==2190) counttxt<<"    }\n  }"<<endl;
       }
     }
   }
}
