#define Analyzer_cxx
#include "Analyzer.h"
#include "whichGridpoint.h"
#include "SignalScanHistograms.h"
#include "cross_sections.h"
#include <bitset>
#include <algorithm>
#include <TRandom3.h>
#include <TH2.h>
#include <TH3.h>
#include <THn.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <cstdlib>

int main(int argc, char* argv[]){
  bool is_i=0, is_o=0, is_b=0, is_x=0, is_f=0, is_F=0, is_h=0, is_c=0, is_cuts=0, is_quiet=0, is_signalscan=0, is_signalstudy=0, is_countSignal=0;
  bool is_t=0, is_l=0, is_syst=0;
  bool inputs=0, cuts=0, syst=0, lept=0;
  int FR=0, tr=0;
  string output, bname, xname;
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
      else if (arg[1]=='f') is_f=1;
      else if (arg[1]=='F') is_F=1;
      else if (arg[1]=='h') is_h=1; 
      else if (arg[1]=='c') is_c=1; 
      else if (arg[1]=='q') is_quiet=1; 
      else if (arg[1]=='S') is_signalscan=1; 
      else if (arg[1]=='s') is_signalstudy=1;
      else if (arg[1]=='C') is_countSignal=1; 
      else if (arg[1]=='t') is_t=1; 
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
    if (is_x) {xname=argv[i+1]; is_x=0;}
    if (is_F) {FR=atoi(argv[i+1]); is_F=0;}
    if (is_t) {(atoi(argv[i+1])==0) ? tr=1000 : tr=atoi(argv[i+1]); is_t=0;}
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

  if (!is_quiet){
    if (!output.empty()) cout<<"Output name: "<<output<<endl;
    if (!bname.empty()) cout<<"Btag file name: "<<bname<<endl;
    if (!xname.empty()) cout<<"Xsec file name: "<<xname<<endl;
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
    for (auto const& x : systematics) cout<<"Systematics for "<<x.first<<" set to "<<x.second<<endl;
    for (auto const& x : leptonpts) cout<<"Lepton pt for "<<x.first<<" set to "<<x.second<<endl;
  }
  Analyzer t(inputfiles,output,bname,xname,is_f,FR,cut_variable,cut_operator,cut_value,is_quiet,is_signalscan,is_signalstudy,is_countSignal, tr, systematics, leptonpts);
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
   
   double L_data[3]={35920, 41530, 59740};
   
   //Btag SF
   BTCalibration calib_2016deep, calib_2016fast, calib_2017deep, calib_2017fast, calib_2018deep, calib_2018fast;
   BTCalibrationReader reader_L_2016deep, reader_M_2016deep, reader_T_2016deep, reader_L_2016fast, reader_M_2016fast, reader_T_2016fast;
   BTCalibrationReader reader_L_2017deep, reader_M_2017deep, reader_T_2017deep, reader_L_2017fast, reader_M_2017fast, reader_T_2017fast;
   BTCalibrationReader reader_L_2018deep, reader_M_2018deep, reader_T_2018deep, reader_L_2018fast, reader_M_2018fast, reader_T_2018fast;
   // setup calibration + reader https://twiki.cern.ch/twiki/bin/view/CMS/BTagCalibration#Standalone
   if (btag_file.size()>0){
     //2016 Deep
     calib_2016deep = *new BTCalibration("2016deep", "input/btag/DeepJet_2016LegacySF_WP_V1.csv");
     reader_L_2016deep = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_M_2016deep = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_T_2016deep = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_L_2016deep.load(calib_2016deep,BTEntry::FLAV_B,"comb");
     reader_L_2016deep.load(calib_2016deep,BTEntry::FLAV_C,"comb");
     reader_L_2016deep.load(calib_2016deep,BTEntry::FLAV_UDSG,"incl");
     reader_M_2016deep.load(calib_2016deep,BTEntry::FLAV_B,"comb");
     reader_M_2016deep.load(calib_2016deep,BTEntry::FLAV_C,"comb");
     reader_M_2016deep.load(calib_2016deep,BTEntry::FLAV_UDSG,"incl");
     reader_T_2016deep.load(calib_2016deep,BTEntry::FLAV_B,"comb");
     reader_T_2016deep.load(calib_2016deep,BTEntry::FLAV_C,"comb");
     reader_T_2016deep.load(calib_2016deep,BTEntry::FLAV_UDSG,"incl");
     
     //2017 Deep
     calib_2017deep = *new BTCalibration("2017deep", "input/btag/DeepFlavour_94XSF_WP_V3_B_F.csv");
     reader_L_2017deep = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_M_2017deep = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_T_2017deep = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_L_2017deep.load(calib_2017deep,BTEntry::FLAV_B,"comb");
     reader_L_2017deep.load(calib_2017deep,BTEntry::FLAV_C,"comb");
     reader_L_2017deep.load(calib_2017deep,BTEntry::FLAV_UDSG,"incl");
     reader_M_2017deep.load(calib_2017deep,BTEntry::FLAV_B,"comb");
     reader_M_2017deep.load(calib_2017deep,BTEntry::FLAV_C,"comb");
     reader_M_2017deep.load(calib_2017deep,BTEntry::FLAV_UDSG,"incl");
     reader_T_2017deep.load(calib_2017deep,BTEntry::FLAV_B,"comb");
     reader_T_2017deep.load(calib_2017deep,BTEntry::FLAV_C,"comb");
     reader_T_2017deep.load(calib_2017deep,BTEntry::FLAV_UDSG,"incl");
     
     //2018 Deep
     calib_2018deep = *new BTCalibration("2018deep", "input/btag/DeepJet_102XSF_WP_V1.csv");
     reader_L_2018deep = *new BTCalibrationReader(BTEntry::OP_LOOSE,"central",{"up", "down"});
     reader_M_2018deep = *new BTCalibrationReader(BTEntry::OP_MEDIUM,"central",{"up", "down"});
     reader_T_2018deep = *new BTCalibrationReader(BTEntry::OP_TIGHT,"central",{"up", "down"});
     reader_L_2018deep.load(calib_2018deep,BTEntry::FLAV_B,"comb");
     reader_L_2018deep.load(calib_2018deep,BTEntry::FLAV_C,"comb");
     reader_L_2018deep.load(calib_2018deep,BTEntry::FLAV_UDSG,"incl");
     reader_M_2018deep.load(calib_2018deep,BTEntry::FLAV_B,"comb");
     reader_M_2018deep.load(calib_2018deep,BTEntry::FLAV_C,"comb");
     reader_M_2018deep.load(calib_2018deep,BTEntry::FLAV_UDSG,"incl");
     reader_T_2018deep.load(calib_2018deep,BTEntry::FLAV_B,"comb");
     reader_T_2018deep.load(calib_2018deep,BTEntry::FLAV_C,"comb");
     reader_T_2018deep.load(calib_2018deep,BTEntry::FLAV_UDSG,"incl");
     
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

   std::string temp_fname="histos/Analyzer_histos"; 
   if (output_file != "default") {
     if (output_file.compare(0,1,"/") != 0) temp_fname+="_"+output_file;
     else {
       size_t found = output_file.find_last_of("/\\");
       string dir="mkdir -p "; dir+=output_file.substr(0,found);
       const int dir_err = system(dir.c_str());
       temp_fname=output_file;
     }
   }
   else temp_fname+=".root";
   TFile *f = new TFile(temp_fname.c_str(),"recreate");

   TH1::SetDefaultSumw2();

   //histograms
   h_cuts = new TH1D("h_cuts","cuts;Higgs,PV,METfilter,Pho,Pho175,Lep0,MT,ST,nonHjet,DDBvL,Deep1,Deep2",15,0,15);
   TH1D *h_eff    = new TH1D("h_eff","Events;Before cuts, After cuts",2,-0.5,1.5);
   TH1D *h_nISR_jet = new TH1D("h_nISR_jet",";number of ISR jets",10,0,10);
   TH1D *h_SR    = new TH1D("h_SR","",16,0.5,16.5);
   
   TH2D *h2_btag_weight = new TH2D("h2_btag_weight",";Event weight;# tagged light jets",20,0,200,11,-0.5,11.5);
   TH1D *h_btag_sf_b_2016 = new TH1D("h_btag_sf_b_2016",";SF(fullsim/fastsim)",20,0,5);
   TH1D *h_btag_sf_l_2016 = new TH1D("h_btag_sf_l_2016",";SF(fullsim/fastsim)",20,0,5);
   TH1D *h_btag_sf_b_2017 = new TH1D("h_btag_sf_b_2017",";SF(fullsim/fastsim)",20,0,5);
   TH1D *h_btag_sf_l_2017 = new TH1D("h_btag_sf_l_2017",";SF(fullsim/fastsim)",20,0,5);

   TH1D *h_phoEt    = new TH1D("h_phoEt",";E_{T}^{#gamma} [GeV]",10,25,1525);
   TH1D *h_phoEta    = new TH1D("h_phoEta",";#eta^{#gamma}",30,-3,3);

   const int nbins_photon=15;
   double xbins_photon[nbins_photon+1]={0,50,120,175,210,260,310,360,410,460,510,650,800,1000,1200,1500};
   TH1D *h_phoPt= new TH1D("h_phoPt",";#gamma{E}_{T} [GeV]",nbins_photon,xbins_photon);
   const int nbins_pfMET=13;
   double xbins_pfMET[nbins_pfMET+1]={0,20,40,70,100,150,200,300,500,700,1000,1500,2000,3000};
   TH1D *h_pfMET    = new TH1D("h_pfMET",";#slash{E}_{T} [GeV]",nbins_pfMET,xbins_pfMET);
   TH1D *h_pfMETsumEt    = new TH1D("h_pfMETsumEt",";#slash{E}_{T} sumEt",20,-50,5000);
   TH1D *h_pfMETPhi    = new TH1D("h_pfMETPhi",";#Phi^{#slash{E}_{T}}",20,-4,4);
   TH1D *h_pfMETSig    = new TH1D("h_pfMETSig",";#slash{E}_{T}Sig",20,0,1500);

   const int nbins_ST=13;
   double xbins_ST[nbins_ST+1]={0, 200, 400, 600, 800, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5500};
   TH1D *h_ST    = new TH1D("h_ST",";S_{T} [GeV]",nbins_ST,xbins_ST);
   TH1D *h_ST_G    = new TH1D("h_ST_G",";S_{T}^{#gamma} [GeV]",10,0,2000);
   const int nbins_MT=9;
   double xbins_MT[nbins_MT+1]={0, 30, 60, 100, 130, 200, 500, 1000, 1500, 2000};
   TH1D *h_MT    = new TH1D("h_MT",";M_{T} [GeV]",nbins_MT,xbins_MT);
   TH1D *h_HT_after = new TH1D("h_HT_after","HT after cuts;HT",20,0,5000);
   TH1D *h_EMHT_after = new TH1D("h_EMHT_after","EMHT after cuts;EMHT",20,0,5000);
   TH2D *h2_ST_HT = new TH2D("h2_ST_HT",";S_{T} [GeV];H_{T} [GeV]",nbins_ST,xbins_ST,20,0,5000);
   TH2D *h2_ST_MET= new TH2D("h2_ST_MET",";S_{T} [GeV];MET [GeV]",nbins_ST,xbins_ST,nbins_pfMET,xbins_pfMET);
   TH2D *h2_MT_MET= new TH2D("h2_MT_MET",";M_{T} [GeV];MET [GeV]",nbins_MT,xbins_MT,nbins_pfMET,xbins_pfMET);
   TH2D *h2_MET_HT = new TH2D("h2_MET_HT",";MET [GeV];H_{T} [GeV]",nbins_pfMET,xbins_pfMET,20,0,5000);
   TH2D *h2_MET_phoPt = new TH2D("h2_MET_phoPt",";MET [GeV];E_{T}^{#gamma} [GeV]",nbins_pfMET,xbins_pfMET,10,25,1525);
   TH2D *h2_MET_extrajets = new TH2D("h2_MET_extrajets",";MET [GeV];# extra jets",nbins_pfMET,xbins_pfMET,14,-1.5,12.5);
   TH2D *h2_extrajets_HT = new TH2D("h2_extrajets_HT",";# of extra jets;H_{T} [GeV]",14,-1.5,12.5,20,0,5000);

   TH1D *h_nPho    = new TH1D("h_nPho",";# of #gamma",10,-0.5,9.5);
   TH1D *h_nEle    = new TH1D("h_nEle",";# of e_{loose}",10,-0.5,9.5);
   TH1D *h_nEleM    = new TH1D("h_nEleM",";# of e_{medium}",10,-0.5,9.5);
   TH1D *h_nEleT    = new TH1D("h_nEleT",";# of e_{tight}",10,-0.5,9.5);
   TH1D *h_nMu    = new TH1D("h_nMu",";# of #mu_{loose}",10,-0.5,9.5);
   TH1D *h_nMuM    = new TH1D("h_nMuM",";# of #mu_{medium}",10,-0.5,9.5);
   TH1D *h_nMuT    = new TH1D("h_nMuT",";# of #mu_{tight}",10,-0.5,9.5);
   TH1D *h_nTau    = new TH1D("h_nTau",";# of #tau_{loose}",10,-0.5,9.5);
   TH1D *h_nIso    = new TH1D("h_nIso",";# of IsoTracks",10,-0.5,9.5);
  
   const int nbins_lepton=12;
   double xbins_lepton[nbins_lepton+1]={0,5,10,15,20,25,30,40,60,100,200,400,1000};
   TH1D *h_ElePt = new TH1D("h_ElePt",";leading p_{T}^{electron} [GeV]",nbins_lepton,xbins_lepton);
   TH1D *h_MuPt = new TH1D("h_MuPt",";leading p_{T}^{#mu} [GeV]",nbins_lepton,xbins_lepton);
   TH1D *h_TauPt = new TH1D("h_TauPt",";leading p_{T}^{#tau} [GeV]",nbins_lepton,xbins_lepton);

   TH1D *h_njets    = new TH1D("h_njets",";# of jets",15,-0.5,14.5);
   TH1D *h_nonHjets = new TH1D("h_nonHjets",";# of extra jets",14,-1.5,12.5);
   TH1D *h_jetpt    = new TH1D("h_jetpt","Leading jetpt;p_{T}^{Leading jet} [GeV]",10,30,2030);
   TH1D *h_nAK8jets    = new TH1D("h_nAK8jets",";# of AK8jets",15,-0.5,14.5);
   TH1D *h_AK8jetpt    = new TH1D("h_AK8jetpt","Leading AK8jetpt;p_{T}^{Leading AK8jet} [GeV]",10,30,2030);

   TH1D *h_mbbjet_select    = new TH1D("h_mbbjet_select","Invariant mass of selected bjets;M_{bb}[GeV]",10,18,278);
   TH1D *h_AK8mass_select= new TH1D("h_AK8mass_select","PUPPI corrected softdrop mass of selected bjet;m_{AK8jet} [GeV]",20,5,655);
   TH1D *h_dR_ak4_Hcandidate = new TH1D("h_dR_ak4_Hcandidate","dR between H candidate AK4 jets;dR",20,0,5);
   TH1D *h_pt_ak4_Hcandidate = new TH1D("h_pt_ak4_Hcandidate","pt of H candidate AK4 jets;p_T [GeV]",25,0,1000);
   TH1D *h_dphi_met_jet= new TH1D("h_dphi_met_jet",";|#Delta#phi|(MET,nearest jet)",10,0,3.2);
   TH2D *h2_dphi_met_jet_nonHjets= new TH2D("h2_dphi_met_jet_nonHjets",";|#Delta#phi|(MET,nearest jet);nonHiggsJets",10,0,3.2,14,-1.5,12.5);
   TH2D *h2_dphi_met_jet_njet= new TH2D("h2_dphi_met_jet_njet",";|#Delta#phi|(MET,nth jet);number",10,0,3.2,8,0.5,8.5);
   TH2D *h2_dphi_met_lowjet_pt= new TH2D("h2_dphi_met_lowjet_pt",";|#Delta#phi|(MET,jet);jet p_{T}",10,0,3.2,10,30,2030);
   TH2D *h2_dphi_met_highjet_pt= new TH2D("h2_dphi_met_highjet_pt",";|#Delta#phi|(MET,jet);jet p_{T}",10,0,3.2,10,30,2030);
   TH1D *h_dphi_met_h_ak8= new TH1D("h_dphi_met_h_ak8",";|#Delta#phi|(MET,ak8 H candidate)",10,0,3.2);
   TH1D *h_dphi_met_h_ak4= new TH1D("h_dphi_met_h_ak4",";|#Delta#phi|(MET,ak4 H candidate)",10,0,3.2);
   TH1D *h_dphi_met_hmin_ak4= new TH1D("h_dphi_met_hmin_ak4",";|#Delta#phi|(MET,ak4 Hmin candidate)",10,0,3.2);
   TH1D *h_dphi_met_ak4btag= new TH1D("h_dphi_met_ak4btag",";|#Delta#phi|(MET,ak4 btag)",10,0,3.2);
   TH2D *h2_dphi_met_h_ak8= new TH2D("h2_dphi_met_h_ak8",";Unrolled bins;|#Delta#phi|(MET,ak8 H candidate)",4,0.5,4.5,10,0,3.2);
   TH2D *h2_dphi_met_h_ak4= new TH2D("h2_dphi_met_h_ak4",";Unrolled bins;|#Delta#phi|(MET,ak4 H candidate)",8,0.5,8.5,10,0,3.2);
   TH2D *h2_dphi_met_hmin_ak4= new TH2D("h2_dphi_met_hmin_ak4",";Unrolled bins;|#Delta#phi|(MET,ak4 Hmin candidate)",8,0.5,8.5,10,0,3.2);
   TH2D *h2_dphi_met_ak4btag= new TH2D("h2_dphi_met_ak4btag",";Unrolled bins;|#Delta#phi|(MET,ak4 btag)",8,0.5,8.5,10,0,3.2);
   TH2D *h2_dphi_met_h_pt_lowjet= new TH2D("h2_dphi_met_h_pt_lowjet",";|#Delta#phi|(MET,jet/H);jet/H p_{T}",10,0,3.2,10,30,2030);
   TH2D *h2_dphi_met_h_pt_highjet= new TH2D("h2_dphi_met_h_pt_highjet",";|#Delta#phi|(MET,jet/H);jet/H p_{T}",10,0,3.2,10,30,2030);
   TH2D *h2_dphi_met_hmin_pt_lowjet= new TH2D("h2_dphi_met_hmin_pt_lowjet",";|#Delta#phi|(MET,jet/Hmin);jet/Hmin p_{T}",10,0,3.2,10,30,2030);
   TH2D *h2_dphi_met_hmin_pt_highjet= new TH2D("h2_dphi_met_hmin_pt_highjet",";|#Delta#phi|(MET,jet/Hmin);jet/Hmin p_{T}",10,0,3.2,10,30,2030);

   TH1D *h_mHAK8= new TH1D("h_mHAK8",";M_{AK8}[GeV]",20,18,278);
   TH1D *h_mHAK4= new TH1D("h_mHAK4",";M_{bb}[GeV]",10,18,278);
   TH2D *h2_mHAK8= new TH2D("h2_mHAK8",";Unrolled bins;M_{AK8}[GeV]",4,0.5,4.5,40,18,278);
   TH2D *h2_mHAK4= new TH2D("h2_mHAK4",";Unrolled bins;M_{bb}[GeV]",8,0.5,8.5,40,18,278);
   TH2D *h2_dr_SRHiggs = new TH2D("h2_dr_SRHiggs",";Unrolled bins;dR_{bb}",8,0.5,8.5,20,0,3.2);
   TH2D *h2_dr_VRHiggs = new TH2D("h2_dr_VRHiggs",";Unrolled bins;dR_{bb}",8,0.5,8.5,20,0,3.2);
   TH3D *h3_mHAK4_dr_Higgs = new TH3D("h3_mHAK4_dr_Higgs",";Unrolled bins;M_{bb}[GeV];dR_{bb}",8,0.5,8.5,10,18,278,20,0,3.2);

   //AK4 searchbins
   const int dim_ak4=4;
   int nbins_ak4[dim_ak4]={2,3,5,2};
   double xmin_ak4[dim_ak4]={-0.5,-0.5,0.5,0.5};
   double xmax_ak4[dim_ak4]={1.5,2.5,5.5,2.5};
   THnD *hn_AK4searchBins = new THnD("hn_AK4searchBins",";VR;AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
   THnD *hn_AK4searchBins_noweight = new THnD("hn_AK4searchBins_noweight",";VR;AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
   THnD *hn_AK4HTsearchBins = new THnD("hn_AK4HTsearchBins",";VR;AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
   hn_AK4searchBins->Sumw2(); hn_AK4HTsearchBins->Sumw2();
   unsigned int nsbins_ak4=hn_AK4searchBins->GetNbins();
   TH1D *h_AK4searchBins= new TH1D("h_AK4searchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
   TH1D *h_AK4searchBins_noweight= new TH1D("h_AK4searchBins_noweight",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
   TH1D *h_AK4HTsearchBins= new TH1D("h_AK4HTsearchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);

   //AK8 searchbins
   const int dim_ak8=4;
   int nbins_ak8[dim_ak8]={2,2,5,2};
   double xmin_ak8[dim_ak8]={-0.5,-0.5,0.5,0.5};
   double xmax_ak8[dim_ak8]={1.5,1.5,5.5,2.5};
   THnD *hn_AK8searchBins = new THnD("hn_AK8searchBins",";VR;AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
   THnD *hn_AK8searchBins_noweight = new THnD("hn_AK8searchBins_noweight",";VR;AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
   THnD *hn_AK8HTsearchBins = new THnD("hn_AK8HTsearchBins",";VR;AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
   hn_AK8searchBins->Sumw2(); hn_AK8HTsearchBins->Sumw2();
   unsigned int nsbins_ak8=hn_AK8searchBins->GetNbins();
   TH1D *h_AK8searchBins= new TH1D("h_AK8searchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
   TH1D *h_AK8searchBins_noweight= new TH1D("h_AK8searchBins_noweight",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
   TH1D *h_AK8HTsearchBins= new TH1D("h_AK8HTsearchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
  
   //Histograms for signalstudy
   map<int,vector<int>> grid;
   if (SignalScan) {
     grid=init_scan_histos(f,signalstudy,SignalScenario);
   }

   TBenchmark time;
   TDatime now;
   if (!is_quiet) now.Print();
   time.Start("time");

   TRandom3 *gen = new TRandom3(0);

   std::map<pair<int,int>,int> signal_events;
   if (CountSignal) signal_events=init_signal_event(SignalScenario);
   int file_counter=-1, temp=-1; std::string temp_f="";
   Double_t TotalEvents=0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
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
       if (run<=284044) year=2016;
       else if (run<=307082) year=2017;
       else if (run<=325273) year=2018;
     }
     //getting cross section & total number of events
     if (!isData && (jentry==0 || newfile)){
       TotalEvents=0;
       TTree *Runs; fChain->GetCurrentFile()->GetObject("Runs",Runs);
       if (Runs->GetBranch("year")) {
         TBranch *b_year;
         Runs->SetBranchAddress("year",&year,&b_year);
         b_year->GetEntry();
       }
       if (!SignalScan) {
         TBranch *b_genEventSumw;
         Double_t sub_TotalEvents=0;
         string eventsum="genEventSumw";
         if ((year==2017 || year==2018) && temp_f.find("ZGTo2NuG")!=std::string::npos) eventsum="genEventSumw_";
         if (temp_f.find("NanoAODv6")!=std::string::npos) eventsum="genEventSumw_";
         Runs->SetBranchAddress(eventsum.c_str(),&sub_TotalEvents,&b_genEventSumw);
         for (int i=0; i<Runs->GetEntries();i++) {b_genEventSumw->GetEntry(i); TotalEvents+=sub_TotalEvents;}
         //std::cout<<"Tot = "<<TotalEvents<<std::endl;
         if (xsec_file!="default") {
           ifstream f_xsec; f_xsec.open(xsec_file);
           f_xsec>>xsec;
           cout<<xsec<<endl;
           f_xsec.close();
         }
         else {
           if (Runs->GetBranch("xsec")) {
             TBranch *b_xsec;
             Runs->SetBranchAddress("xsec",&xsec,&b_xsec);
             b_xsec->GetEntry();
           }
           else std::cout<<"No xsec found. Using xsec = "<<xsec<<std::endl;
         }
       }
     }
     int year_chooser=(year==2016) ? 0 : (year==2017) ? 1 : 2;
     if (!isData) {
       b_puWeight->GetEntry(ientry);
       b_puWeightUp->GetEntry(ientry);
       b_puWeightDown->GetEntry(ientry);
       b_genWeight->GetEntry(ientry);
       b_Pileup_nPU->GetEntry(ientry);
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
       b_nGenJetAK8->GetEntry(ientry);
       b_GenJetAK8_pt->GetEntry(ientry);
       b_GenJetAK8_eta->GetEntry(ientry);
       b_GenJetAK8_phi->GetEntry(ientry);
       b_GenJetAK8_hadronFlavour->GetEntry(ientry);
       if (year!=2017) {
         b_MET_pt_jer->GetEntry(ientry);
         b_MET_pt_jerUp->GetEntry(ientry);
         b_MET_pt_jerDown->GetEntry(ientry);
         b_MET_pt_jesTotalUp->GetEntry(ientry);
         b_MET_pt_jesTotalDown->GetEntry(ientry);
         b_MET_pt_unclustEnUp->GetEntry(ientry);
         b_MET_pt_unclustEnDown->GetEntry(ientry);
         b_MET_phi_jer->GetEntry(ientry);
         b_MET_phi_jerUp->GetEntry(ientry);
         b_MET_phi_jerDown->GetEntry(ientry);
         b_MET_phi_jesTotalUp->GetEntry(ientry);
         b_MET_phi_jesTotalDown->GetEntry(ientry);
         b_MET_phi_unclustEnUp->GetEntry(ientry);
         b_MET_phi_unclustEnDown->GetEntry(ientry);
       }
       else {
         b_METFixEE2017_pt_jer->GetEntry(ientry);
         b_METFixEE2017_pt_jerUp->GetEntry(ientry);
         b_METFixEE2017_pt_jerDown->GetEntry(ientry);
         b_METFixEE2017_pt_jesTotalUp->GetEntry(ientry);
         b_METFixEE2017_pt_jesTotalDown->GetEntry(ientry);
         b_METFixEE2017_pt_unclustEnUp->GetEntry(ientry);
         b_METFixEE2017_pt_unclustEnDown->GetEntry(ientry);
         b_METFixEE2017_phi_jer->GetEntry(ientry);
         b_METFixEE2017_phi_jerUp->GetEntry(ientry);
         b_METFixEE2017_phi_jerDown->GetEntry(ientry);
         b_METFixEE2017_phi_jesTotalUp->GetEntry(ientry);
         b_METFixEE2017_phi_jesTotalDown->GetEntry(ientry);
         b_METFixEE2017_phi_unclustEnUp->GetEntry(ientry);
         b_METFixEE2017_phi_unclustEnDown->GetEntry(ientry);
       }
     }
     if (!_fastSim && !isData && year!=2018) b_L1PreFiringWeight_Dn->GetEntry(ientry);
     if (!_fastSim && !isData && year!=2018) b_L1PreFiringWeight_Nom->GetEntry(ientry);
     if (!_fastSim && !isData && year!=2018) b_L1PreFiringWeight_Up->GetEntry(ientry);
     b_luminosityBlock->GetEntry(ientry);
     b_PV_npvsGood->GetEntry(ientry);
     b_PV_npvs->GetEntry(ientry);
     b_PV_x->GetEntry(ientry);
     b_PV_y->GetEntry(ientry);
     b_PV_z->GetEntry(ientry);
     if (!_fastSim) {
       if (year==2016) {
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
     b_Flag_METFilters->GetEntry(ientry);
     if (year !=2017) {
       b_MET_pt->GetEntry(ientry);
       b_MET_pt_nom->GetEntry(ientry);
       b_MET_phi->GetEntry(ientry);
       b_MET_phi_nom->GetEntry(ientry);
       b_MET_sumEt->GetEntry(ientry);
       b_MET_significance->GetEntry(ientry);
     }
     else {
       b_METFixEE2017_pt->GetEntry(ientry);
       b_METFixEE2017_pt_nom->GetEntry(ientry);
       b_METFixEE2017_phi->GetEntry(ientry);
       b_METFixEE2017_phi_nom->GetEntry(ientry);
       b_METFixEE2017_sumEt->GetEntry(ientry);
       b_METFixEE2017_significance->GetEntry(ientry);
     }
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
     if (year==2016) b_Photon_cutBased17Bitmap->GetEntry(ientry);
     else b_Photon_cutBasedBitmap->GetEntry(ientry);
     Int_t Photon_cutBased_versionFree[99]; for (unsigned int i=0; i<nPhoton;i++) (year==2016) ? Photon_cutBased_versionFree[i]=Photon_cutBased17Bitmap[i] : Photon_cutBased_versionFree[i]=Photon_cutBasedBitmap[i];
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
     b_Tau_idMVAoldDM->GetEntry(ientry);
     b_Tau_idMVAoldDM2017v2->GetEntry(ientry);
     b_Tau_idMVAnewDM2017v2->GetEntry(ientry);
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
     b_FatJet_btagDDBvL->GetEntry(ientry);
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
     //if (isData && !IsGoldEvent(run,luminosityBlock)) continue;

     if (isData && signalstudy) {cout<<"ERROR! Signalstudy option set, but running on Data..."<<endl; return;}
     //SignalScan variables
     pair<int,int> mass_pair;
     if (SignalScan) {
       int neutralino=-1, gluino=-1; bool foundG=0, foundX=0;
       for (unsigned int i=0;i<nGenPart;i++) {
         if (!foundX && GenPart_pdgId[i]==1000023 && GenPart_status[i]==22) {neutralino=i; foundX=1;}
         if (!foundG && GenPart_pdgId[i]==1000021 && GenPart_status[i]==22) {gluino=i; foundG=1;}
         if (foundX && foundG) break;
       }
       int m_Gluino=1;
       if (SignalScenario==1) m_Gluino = GenPart_mass[gluino];
       //Neutralino/gluino mass is not exact. Need to find nearest grid point
       double m_Neutralino=GenPart_mass[neutralino];
       pair<double,double> initial_pair(m_Gluino,m_Neutralino);
       mass_pair = whichGridpoint(initial_pair, SignalScenario);
       if (CountSignal) {
         auto search = signal_events.find(mass_pair);
         if (search!=signal_events.end()) search->second +=1;
       }
     }
     if (jentry==0 || newfile) {
       //Egamma scaling & smearing systematic fluctuations
       std::map<int, std::map<std::string, std::string > > pathTo_photon_Scaling = {
         {2016,{{"v1","input/egamma/syst/Legacy2016_07Aug2017_FineEtaR9_v3_ele_unc_scales.dat"},}},
         {2017,{{"v1","input/egamma/syst/Run2017_17Nov2017_v1_ele_unc_scales.dat"},{"v2","input/egamma/syst/Run2017_24Feb2020_runEtaR9Gain_v2_scales.dat"},}},
         {2018,{{"v1","input/egamma/syst/Run2018_Step2Closure_CoarseEtaR9Gain_v2_scales.dat"},}},
       };
     
       std::map<int, std::map<std::string, std::string > > pathTo_photon_Smearing = {
         {2016,{{"v1","input/egamma/syst/Legacy2016_07Aug2017_FineEtaR9_v3_ele_unc_smearings.dat"},}},
         {2017,{{"v1","input/egamma/syst/Run2017_17Nov2017_v1_ele_unc_smearings.dat"},{"v2","input/egamma/syst/Run2017_24Feb2020_runEtaR9Gain_v2_smearings.dat"},}},
         {2018,{{"v1","input/egamma/syst/Run2018_Step2Closure_CoarseEtaR9Gain_v2_smearings.dat"},}},
       };
       std::string version = (year==2017) ? "v2" : "v1";
       EgammaScaling  = EgammaScalingReader(pathTo_photon_Scaling.at(year).at(version), year, version);
       EgammaSmearing = EgammaSmearingReader(pathTo_photon_Smearing.at(year).at(version), year);
     }

     w=1;
     //MC weights and scale factors
     double pu_weight=1, weight=1;
     if (!isData){
       if (SignalScan && temp_f.find("NanoAODv6")==std::string::npos) {xsec=get_cross_section(mass_pair.first, SignalScenario); TotalEvents=get_total_events(mass_pair,year,SignalScenario);}
       else if (SignalScan && temp_f.find("NanoAODv6")!=std::string::npos) {
         TBranch *b_genEventSumw;
         Double_t sub_TotalEvents=0; TotalEvents=0;
         TTree *Runs; fChain->GetCurrentFile()->GetObject("Runs",Runs);
         TObjArray *leaves=Runs->GetListOfLeaves();
         int dm_g=999, dm_n=999, re_mg=0, re_mn=0;
         for (int i = 0; i <= leaves->GetLast(); i++) {
           string name=leaves->At(i)->GetName();
           if (name.find("genEventCount_T5qqqqHg")==string::npos) continue;
           size_t found = name.find("T5qqqqHg");
           int mg=stoi(name.substr(name.find("_",found)+1,name.find_last_of("_")-name.find("_",found)-1));
           int mn=stoi(name.substr(name.find_last_of("_")+1));
           if (dm_g>abs(mg-mass_pair.first)) re_mg=mg;
           if (dm_n>abs(mn-mass_pair.second)) re_mn=mn;
         }
         string eventsum="genEventSumw_T5qqqqHg_"+to_string(re_mg)+"_"+to_string(re_mn);
         Runs->SetBranchAddress(eventsum.c_str(),&sub_TotalEvents,&b_genEventSumw);
         for (int i=0; i<Runs->GetEntries();i++) {b_genEventSumw->GetEntry(i); TotalEvents+=sub_TotalEvents;}
       }
       //weights
       (PUweight_whichSF==1) ? pu_weight=puWeightUp : (PUweight_whichSF==2) ? pu_weight=puWeightDown : pu_weight=puWeight;
       if (_fastSim || SignalScan) pu_weight=1;
       weight=L_data[year_chooser]*xsec*genWeight/TotalEvents;
       //if (newfile) std::cout<<"weight=L_data[year_chooser]*genWeight*xsec/TotalEvents "<<weight<<"="<<L_data[year_chooser]<<"*"<<genWeight<<"*"<<xsec<<"/"<<TotalEvents<<std::endl;
       w=weight*pu_weight;
       //trigger efficiency
       double w_trig[3]={0.9871,0.9913,0.9947};
       if (_fastSim) w*=w_trig[year_chooser];
       //std::cout<<"event "<<event<<" w=weight*pu_weight"<<w<<"="<<weight<<"("<<L_data[year_chooser]<<"*"<<genWeight<<"*"<<xsec<<"/"<<TotalEvents<<")"<<"*"<<pu_weight<<std::endl;
       //Scale factors
       if (jentry==0 || newfile) {
         //photon cutbased 2016
         if (year==2016) {
           TFile f_2016phoLooseSF("input/egamma/photon/2016LegacyReReco_PhotonCutBasedLoose.root","read");
           h_pho_EGamma_SF2D[0] = (TH2F*)f_2016phoLooseSF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[0]->SetDirectory(0);
           f_2016phoLooseSF.Close();
           TFile f_2016phoMediumSF("input/egamma/photon/2016LegacyReReco_PhotonCutBasedMedium.root","read");
           h_pho_EGamma_SF2D[1] = (TH2F*)f_2016phoMediumSF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[1]->SetDirectory(0);
           f_2016phoMediumSF.Close();
           TFile f_2016phoTightSF("input/egamma/photon/2016LegacyReReco_PhotonCutBasedTight.root","read");
           h_pho_EGamma_SF2D[2] = (TH2F*)f_2016phoTightSF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[2]->SetDirectory(0);
           f_2016phoTightSF.Close();
           TFile f_2016phoMVA80SF("input/egamma/photon/2016LegacyReReco_PhotonMVAWP80.root","read");
           h_pho_EGamma_SF2D[3] = (TH2F*)f_2016phoMVA80SF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[3]->SetDirectory(0);
           f_2016phoMVA80SF.Close();
           TFile f_2016phoMVA90SF("input/egamma/photon/2016LegacyReReco_PhotonMVAWP90.root","read");
           h_pho_EGamma_SF2D[4] = (TH2F*)f_2016phoMVA90SF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[4]->SetDirectory(0);
           f_2016phoMVA90SF.Close();
           TFile f_phoPV_2016("input/egamma/photon/ScalingFactors_80X_Summer16.root","read");
           h_Scaling_Factors_HasPix_R9_high = (TH2D*)f_phoPV_2016.Get("Scaling_Factors_HasPix_R9 > 0.94");
           h_Scaling_Factors_HasPix_R9_high->SetDirectory(0);
           h_Scaling_Factors_HasPix_R9_low = (TH2D*)f_phoPV_2016.Get("Scaling_Factors_HasPix_R9 < 0.94");
           h_Scaling_Factors_HasPix_R9_low->SetDirectory(0);
           f_phoPV_2016.Close();
         }
         else if (year==2017) {
           TFile f_2017phoLooseSF("input/egamma/photon/2017_PhotonsLoose.root","read");
           h_pho_EGamma_SF2D[0] = (TH2F*)f_2017phoLooseSF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[0]->SetDirectory(0);
           f_2017phoLooseSF.Close();
           TFile f_2017phoMediumSF("input/egamma/photon/2017_PhotonsMedium.root","read");
           h_pho_EGamma_SF2D[1] = (TH2F*)f_2017phoMediumSF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[1]->SetDirectory(0);
           f_2017phoMediumSF.Close();
           TFile f_2017phoTightSF("input/egamma/photon/2017_PhotonsTight.root","read");
           h_pho_EGamma_SF2D[2] = (TH2F*)f_2017phoTightSF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[2]->SetDirectory(0);
           f_2017phoTightSF.Close();
           TFile f_2017phoMVA80SF("input/egamma/photon/2017_PhotonsMVAwp80.root","read");
           h_pho_EGamma_SF2D[3] = (TH2F*)f_2017phoMVA80SF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[3]->SetDirectory(0);
           f_2017phoMVA80SF.Close();
           TFile f_2017phoMVA90SF("input/egamma/photon/2017_PhotonsMVAwp90.root","read");
           h_pho_EGamma_SF2D[4] = (TH2F*)f_2017phoMVA90SF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[4]->SetDirectory(0);
           f_2017phoMVA90SF.Close();
           TFile f_phoPV_2017("input/egamma/photon/PixelSeed_ScaleFactors_2017.root","read");
           h_PixelSeed_ScaleFactors_2017[0]= (TH1F*)f_phoPV_2017.Get("Loose_ID");
           h_PixelSeed_ScaleFactors_2017[0]->SetDirectory(0);
           h_PixelSeed_ScaleFactors_2017[1]= (TH1F*)f_phoPV_2017.Get("Medium_ID");
           h_PixelSeed_ScaleFactors_2017[1]->SetDirectory(0);
           h_PixelSeed_ScaleFactors_2017[2]= (TH1F*)f_phoPV_2017.Get("Tight_ID");
           h_PixelSeed_ScaleFactors_2017[2]->SetDirectory(0);
           h_PixelSeed_ScaleFactors_2017[3]= (TH1F*)f_phoPV_2017.Get("MVA_ID");
           h_PixelSeed_ScaleFactors_2017[3]->SetDirectory(0);
           f_phoPV_2017.Close();
         }
         else if (year==2018) {
           TFile f_2018phoLooseSF("input/egamma/photon/2018_PhotonsLoose.root","read");
           h_pho_EGamma_SF2D[0] = (TH2F*)f_2018phoLooseSF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[0]->SetDirectory(0);
           f_2018phoLooseSF.Close();
           TFile f_2018phoMediumSF("input/egamma/photon/2018_PhotonsMedium.root","read");
           h_pho_EGamma_SF2D[1] = (TH2F*)f_2018phoMediumSF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[1]->SetDirectory(0);
           f_2018phoMediumSF.Close();
           TFile f_2018phoTightSF("input/egamma/photon/2018_PhotonsTight.root","read");
           h_pho_EGamma_SF2D[2] = (TH2F*)f_2018phoTightSF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[2]->SetDirectory(0);
           f_2018phoTightSF.Close();
           TFile f_2018phoMVA80SF("input/egamma/photon/2018_PhotonsMVAwp80.root","read");
           h_pho_EGamma_SF2D[3] = (TH2F*)f_2018phoMVA80SF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[3]->SetDirectory(0);
           f_2018phoMVA80SF.Close();
           TFile f_2018phoMVA90SF("input/egamma/photon/2018_PhotonsMVAwp90.root","read");
           h_pho_EGamma_SF2D[4] = (TH2F*)f_2018phoMVA90SF.Get("EGamma_SF2D");
           h_pho_EGamma_SF2D[4]->SetDirectory(0);
           f_2018phoMVA90SF.Close();
           TFile f_phoPV_2018("input/egamma/photon/HasPix_2018.root","read");
           h_PixelSeed_ScaleFactors_2018= (TH2D*)f_phoPV_2018.Get("eleVeto_SF");
           h_PixelSeed_ScaleFactors_2018->SetDirectory(0);
           h_PixelSeed_ScaleFactors_2018_unc= (TH2D*)f_phoPV_2018.Get("eleVeto_Unc");
           h_PixelSeed_ScaleFactors_2018_unc->SetDirectory(0);
           f_phoPV_2018.Close();
         }
         if (year==2016) {
           //electron reconstruction efficiency
           TFile f_eleRecSF_low("input/egamma/electron/2016_Electron_EGM2D_BtoH_low_RecoSF_Legacy2016.root","read");
           h_eleRec_EGamma_SF2D[0] = (TH2F*)f_eleRecSF_low.Get("EGamma_SF2D");
           h_eleRec_EGamma_SF2D[0]->SetDirectory(0);
           f_eleRecSF_low.Close();
           TFile f_eleRecSF_high("input/egamma/electron/2016_Electron_EGM2D_BtoH_GT20GeV_RecoSF_Legacy2016.root","read");
           h_eleRec_EGamma_SF2D[1] = (TH2F*)f_eleRecSF_high.Get("EGamma_SF2D");
           h_eleRec_EGamma_SF2D[1]->SetDirectory(0);
           f_eleRecSF_high.Close();
           //electron cutbased veto
           TFile f_eleVetoSF("input/egamma/electron/2016_ElectronWPVeto_Fall17V2.root","read");
           h_ele_EGamma_SF2D[0] = (TH2F*)f_eleVetoSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[0]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[0] = (TH2F*)f_eleVetoSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[0]->SetDirectory(0);
           f_eleVetoSF.Close();
           //electron cutbased loose
           TFile f_eleLooseSF("input/egamma/electron/2016LegacyReReco_ElectronLoose_Fall17V2.root","read");
           h_ele_EGamma_SF2D[1] = (TH2F*)f_eleLooseSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[1]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[1] = (TH2F*)f_eleLooseSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[1]->SetDirectory(0);
           f_eleLooseSF.Close();
           //electron cutbased medium
           TFile f_eleMediumSF("input/egamma/electron/2016LegacyReReco_ElectronMedium_Fall17V2.root","read");
           h_ele_EGamma_SF2D[2] = (TH2F*)f_eleMediumSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[2]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[2] = (TH2F*)f_eleMediumSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[2]->SetDirectory(0);
           f_eleMediumSF.Close();
           //electron cutbased tight
           TFile f_eleTightSF("input/egamma/electron/2016LegacyReReco_ElectronTight_Fall17V2.root","read");
           h_ele_EGamma_SF2D[3] = (TH2F*)f_eleTightSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[3]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[3] = (TH2F*)f_eleTightSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[3]->SetDirectory(0);
           f_eleTightSF.Close();
         }
         else if (year==2017) {
           //electron reconstruction efficiency
           TFile f_eleRecSF_low("input/egamma/electron/2017_Electron_egammaEffi.txt_EGM2D_runBCDEF_passingRECO_lowEt.root","read");
           h_eleRec_EGamma_SF2D[0] = (TH2F*)f_eleRecSF_low.Get("EGamma_SF2D");
           h_eleRec_EGamma_SF2D[0]->SetDirectory(0);
           f_eleRecSF_low.Close();
           TFile f_eleRecSF_high("input/egamma/electron/2017_Electron_egammaEffi.txt_EGM2D_runBCDEF_passingRECO.root","read");
           h_eleRec_EGamma_SF2D[1] = (TH2F*)f_eleRecSF_high.Get("EGamma_SF2D");
           h_eleRec_EGamma_SF2D[1]->SetDirectory(0);
           f_eleRecSF_high.Close();
           //electron cutbased veto
           TFile f_eleVetoSF("input/egamma/electron/2017_ElectronWPVeto_Fall17V2.root","read");
           h_ele_EGamma_SF2D[0] = (TH2F*)f_eleVetoSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[0]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[0] = (TH2F*)f_eleVetoSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[0]->SetDirectory(0);
           f_eleVetoSF.Close();
           //electron cutbased loose
           TFile f_eleLooseSF("input/egamma/electron/2017_ElectronLoose.root","read");
           h_ele_EGamma_SF2D[1] = (TH2F*)f_eleLooseSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[1]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[1] = (TH2F*)f_eleLooseSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[1]->SetDirectory(0);
           f_eleLooseSF.Close();
           //electron cutbased medium
           TFile f_eleMediumSF("input/egamma/electron/2017_ElectronMedium.root","read");
           h_ele_EGamma_SF2D[2] = (TH2F*)f_eleMediumSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[2]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[2] = (TH2F*)f_eleMediumSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[2]->SetDirectory(0);
           f_eleMediumSF.Close();
           //electron cutbased tight
           TFile f_eleTightSF("input/egamma/electron/2017_ElectronTight.root","read");
           h_ele_EGamma_SF2D[3] = (TH2F*)f_eleTightSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[3]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[3] = (TH2F*)f_eleTightSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[3]->SetDirectory(0);
           f_eleTightSF.Close();
         }
         else if (year==2018) {
           //electron reconstruction efficiency
           TFile f_eleRecSF_low("input/egamma/electron/2018_Electron_egammaEffi.txt_EGM2D_updatedAll.root","read");
           h_eleRec_EGamma_SF2D[0] = (TH2F*)f_eleRecSF_low.Get("EGamma_SF2D");
           h_eleRec_EGamma_SF2D[0]->SetDirectory(0);
           h_eleRec_EGamma_SF2D[1] = (TH2F*)f_eleRecSF_low.Get("EGamma_SF2D");
           h_eleRec_EGamma_SF2D[1]->SetDirectory(0);
           f_eleRecSF_low.Close();
           //electron cutbased veto
           TFile f_eleVetoSF("input/egamma/electron/2018_ElectronWPVeto_Fall17V2.root","read");
           h_ele_EGamma_SF2D[0] = (TH2F*)f_eleVetoSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[0]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[0] = (TH2F*)f_eleVetoSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[0]->SetDirectory(0);
           f_eleVetoSF.Close();
           //electron cutbased loose
           TFile f_eleLooseSF("input/egamma/electron/2018_ElectronLoose.root","read");
           h_ele_EGamma_SF2D[1] = (TH2F*)f_eleLooseSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[1]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[1] = (TH2F*)f_eleLooseSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[1]->SetDirectory(0);
           f_eleLooseSF.Close();
           //electron cutbased medium
           TFile f_eleMediumSF("input/egamma/electron/2018_ElectronMedium.root","read");
           h_ele_EGamma_SF2D[2] = (TH2F*)f_eleMediumSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[2]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[2] = (TH2F*)f_eleMediumSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[2]->SetDirectory(0);
           f_eleMediumSF.Close();
           //electron cutbased tight
           TFile f_eleTightSF("input/egamma/electron/2018_ElectronTight.root","read");
           h_ele_EGamma_SF2D[3] = (TH2F*)f_eleTightSF.Get("EGamma_SF2D");
           h_ele_EGamma_SF2D[3]->SetDirectory(0);
           h_ele_EGamma_EffMC2D[3] = (TH2F*)f_eleTightSF.Get("EGamma_EffMC2D");
           h_ele_EGamma_EffMC2D[3]->SetDirectory(0);
           f_eleTightSF.Close();
         }
         if (year==2016){
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
         else if (year==2017){
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
         else if (year==2018){
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

         //Tau SF
         string f_tau="";
         if (year==2016) f_tau="input/tau_SF/TauID_SF_pt_MVAoldDM2017v2_2016Legacy.root";
         if (year==2017) f_tau="input/tau_SF/TauID_SF_pt_MVAoldDM2017v2_2017ReReco.root";
         if (year==2018) f_tau="input/tau_SF/TauID_SF_pt_MVAoldDM2017v2_2018ReReco.root";
         string sys_key="";
         switch(tau_whichSF){
           case 0: sys_key= "_cent";
                   break;
           case 1: sys_key= "_up";
                   break;
           case 2: sys_key= "_down";
                   break;
         }
         TFile f_TauID(f_tau.c_str(),"read");
         tf1_tau_ID_SF[0]=(TF1*)f_TauID.Get(("Loose"+sys_key).c_str());
         tf1_tau_ID_SF[1]=(TF1*)f_TauID.Get(("Medium"+sys_key).c_str());
         tf1_tau_ID_SF[2]=(TF1*)f_TauID.Get(("Tight"+sys_key).c_str());
         f_TauID.Close();

         //Loading btag efficiency file, fill efficiency histograms
         if (btag_file.size()>0) {
           string btag_fname=btag_file;
           if (btag_file.compare("hardcoded")==0) {
             string pretag="/data/BTagEff/nanoAODv5/";
             string tag="BTagEff_";
             if (temp_f.find("DYJetsToLL")!=std::string::npos) tag+="DYJetsToLL";
             else if (temp_f.find("TTGJets")!=std::string::npos) tag+="TTGJets";
             else if (temp_f.find("GJets")!=std::string::npos) tag+="GJets_HT_merged";
             else if (temp_f.find("QCD")!=std::string::npos) tag+="QCD_HT_merged";
             else if (temp_f.find("ST_s-channel_hadronicDecays")!=std::string::npos) tag+="ST_s-channel_hadronicDecays";
             else if (temp_f.find("ST_s-channel_leptonDecays")!=std::string::npos) tag+="ST_s-channel_leptonDecays";
             else if (temp_f.find("ST_s-channel")!=std::string::npos) tag+="ST_s-channel";
             else if (temp_f.find("ST_t-channel_antitop")!=std::string::npos) tag+="ST_t-channel_antitop";
             else if (temp_f.find("ST_t-channel_top")!=std::string::npos) tag+="ST_t-channel_top";
             else if (temp_f.find("ST_tW_antitop")!=std::string::npos) tag+="ST_tW_antitop";
             else if (temp_f.find("ST_tW_top")!=std::string::npos) tag+="ST_tW_top";
             else if (temp_f.find("TTGamma_Hadronic")!=std::string::npos) tag+="TTGamma_Hadronic";
             else if (temp_f.find("TTJets")!=std::string::npos) tag+="TTJets";
             else if (temp_f.find("WGJets")!=std::string::npos) tag+="WGJets";
             else if (temp_f.find("WJetsToLNu")!=std::string::npos) tag+="WJetsToLNu_HT_merged";
             else if (temp_f.find("WJetsToQQ_HT")!=std::string::npos) tag+="WJetsToQQ_HT_merged";
             else if (temp_f.find("WJetsToQQ")!=std::string::npos) tag+="WJetsToQQ";
             else if (temp_f.find("WW")!=std::string::npos) tag+="WW";
             else if (temp_f.find("WZ")!=std::string::npos) tag+="WZ";
             else if (temp_f.find("ZGTo2LG")!=std::string::npos) tag+="ZGTo2LG";
             else if (temp_f.find("ZGTo2NuG")!=std::string::npos) tag+="ZGTo2NuG";
             else if (temp_f.find("ZJetsToNuNu")!=std::string::npos) tag+="ZJetsToNuNu_HT_merged";
             else if (temp_f.find("ZJetsToQQ_HT")!=std::string::npos) tag+="ZJetsToQQ_HT_merged";
             else if (temp_f.find("ZJetsToQQ")!=std::string::npos) tag+="ZJetsToQQ";
             else if (temp_f.find("ZZ")!=std::string::npos) tag+="ZZ";
             else if (temp_f.find("T5qqqqHg")==std::string::npos && temp_f.find("TChiNG")==std::string::npos) cout<<"No btag eff file found for file "<<temp_f<<endl;;
             btag_fname=pretag+"hadded/"+to_string(year)+"/"+tag+".root";
             if (temp_f.find("T5qqqqHg")!=std::string::npos) btag_fname=pretag+"signal/tree_"+to_string(year)+"_all_out.root";
             if (temp_f.find("TChiNG")!=std::string::npos) btag_fname=pretag+"signal/TChiNg_tree_"+to_string(year)+"_all_out.root";
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
         if (year==2016) {
           TFile f_L1_phomap_2016("input/L1prefiring_photonpt_2016BtoH.root","read");
           h_L1prefire_phoMap = (TH2D*)f_L1_phomap_2016.Get("L1prefiring_photonpt_2016BtoH");
           h_L1prefire_phoMap->SetDirectory(0);
           f_L1_phomap_2016.Close();
           TFile f_L1_jetmap_2016("input/L1prefiring_jetpt_2016BtoH.root","read");
           h_L1prefire_jetMap = (TH2D*)f_L1_jetmap_2016.Get("L1prefiring_jetpt_2016BtoH");
           h_L1prefire_jetMap->SetDirectory(0);
           f_L1_jetmap_2016.Close();
         }
         else if (year==2017) {
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
         if (year==2016) {
           if (temp_f.find("TTJets")!=std::string::npos) ISR_MC=1;
           else if (temp_f.find("TTGamma_Hadronic")!=std::string::npos) ISR_MC=2;
           else if (temp_f.find("TTGJets")!=std::string::npos) ISR_MC=3;
           else if (temp_f.find("T5qqqqHg")!=std::string::npos) ISR_MC=4;
           else ISR_MC=0;
         }
         else if (temp_f.find("T5qqqqHg")!=std::string::npos) ISR_MC=4;
         else ISR_MC=0;
         if (ISR_MC){
           //ISR reweight files
           string isr_file="";
           if (ISR_MC==1) isr_file="input/ISR_reweight/D_factor_ttjets_"+to_string(year)+"_nophotonmatch.root";
           if (ISR_MC==2) isr_file="input/ISR_reweight/D_factor_ttghadronic_"+to_string(year)+"_nophotonmatch.root";
           if (ISR_MC==3) isr_file="input/ISR_reweight/D_factor_ttgjets_"+to_string(year)+"_nophotonmatch.root";
           if (ISR_MC==4) isr_file="input/ISR_reweight/D_factor_signal_"+to_string(year)+"_nophotonmatch.root";
           TFile f_ISR(isr_file.c_str(),"read");
           if (ISR_MC!=4) {
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
               size_t g_first =  s.find("_",3);
               size_t g_last = s.find("_",g_first+1);
               string g = s.substr(g_first+1,g_last-g_first-1);
               string n = s.substr(g_last+1,n.size()-g_last);
               m_ISR_D[pair<int,int> (stoi(g),stoi(n))] = h;
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
           if (!Photon_isScEtaEB[j] || !Photon_isScEtaEE[j] || Photon_pixelSeed[j]!=0 || Photon_pt[j]<40 || (Photon_cutBased_versionFree[i]&1)==0) continue;
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

       //ISR reweight
       vector<double> nISRjet2correction;
       vector<double> nISRjet2unceratinty;
       if (year==2016) {
         nISRjet2correction = {1.0, 0.920, 0.821, 0.715, 0.662, 0.561, 0.511};
         nISRjet2unceratinty= {0.0, 0.040, 0.090, 0.143, 0.169, 0.219, 0.244};
       }
       else {
         nISRjet2correction = {1.0, 0.914, 0.796, 0.698, 0.602, 0.579, 0.580};
         nISRjet2unceratinty= {0.0, 0.043, 0.102, 0.151, 0.199, 0.211, 0.210};
       }
       int njets=(n_isr_jets<6) ? n_isr_jets : 6;
       double D=1;
       double D_err=0;
       if (ISR_MC!=4) {
         D=h_ISR_D->GetBinContent(1);
         D_err=h_ISR_D->GetBinError(1);
       }
       else {
         D=m_ISR_D[mass_pair]->GetBinContent(1);
         D_err=m_ISR_D[mass_pair]->GetBinError(1);
       }
       int sign=(ISR_whichSF==1) ? 1 : (ISR_whichSF==2) ? -1 : 0;
       w_isr=(nISRjet2correction[njets]+sign*nISRjet2unceratinty[njets])*(D-sign*D_err);
       w*=w_isr;
       //cout<<"nisr "<<njets<<" syst "<<ISR_whichSF<<" w_isr "<<w_isr<<" = "<<nISRjet2correction[njets]<<" * "<<D<<endl;
     }

     //object definitions
     int leadpt_ak4=-1, leadpt_ak8=-1, highDDBvL=-1;
     vector<int> passPhoL, passPhoM, passPhoT, passPhoMVA80, passPhoMVA90, passPhotons;
     vector<int> passJet, passAK8Jet;
     vector<int> passEleV, passEleL, passEleM, passEleT, passElectrons;
     vector<int> passMuL, passMuM, passMuT, passMuNO, passMuons;
     vector<int> passTauL, passTauM, passTauT, passTaus, passIso;
     vector<int> passElePhoL, passElePhoM, passElePhoT, passElePhoMVA80, passElePhoMVA90, passElePhotons, passEleNO;
     vector<int> passFREleL, passFREleM, passFREleT;
     vector<float> jetSmearedPt, jetSmearedMass, AK8JetSmearedPt, AK8JetSmearedMass;
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
     if (!_fastSim && year!=2018) {nonPrefiringProbability[0]=L1PreFiringWeight_Nom;nonPrefiringProbability[1]=L1PreFiringWeight_Up;nonPrefiringProbability[2]=L1PreFiringWeight_Dn;}
     phoET.clear();
     //photon
     for (unsigned int i=0;i<nPhoton;i++){
       //Systematics for Egamma scaling
       float scale = 1;
       float smear = 0;
       float SCEta  = Photon_SCEta(i);
     
       if (isData){
         // scaling only
         int   trueGain;
         // the seed gain on the endcaps is saved erroneously.
         // try to figure out based on the correction the value.
         // since we care bout high energy photons only only 1 and 6 are considered.
         // especially because the entry belonging to 12 is often a direct copy of 1 or 6
         if (Photon_isScEtaEE[i]){
           //float scale12 = EgammaScaling.get_energyScale(SCEta, Photon_r9[i], 12,  run);
           float scale6  = EgammaScaling.get_energyScale(SCEta, Photon_r9[i], 6,  run);
           float scale1  = EgammaScaling.get_energyScale(SCEta, Photon_r9[i], 1,  run);

           if ( abs(Photon_eCorr[i]-scale1)/scale1<0.0001 && abs(Photon_eCorr[i]-scale6)/scale6>0.0001 ) {trueGain=1; scale = scale1;}
           else if ( abs(Photon_eCorr[i]-scale1)/scale1>0.0001 && abs(Photon_eCorr[i]-scale6)/scale6<0.0001) {trueGain=6; scale  = scale6;}
           else { trueGain = -1; scale = (scale6+scale1)/2;}
           // some weird thing: both r9=0.919941a and r9=0.93994 are taking their corrections from the 0.92-0.94 bin in the nanoAOD implelentation. no idea why this is.
         }
         else {
           scale    = EgammaScaling.get_energyScale(SCEta,Photon_r9[i], static_cast<int>(Photon_seedGain[i]) , run);
           trueGain = static_cast<int>(Photon_seedGain[i]);
         }

         if (Egamma_Statscale_whichSF || Egamma_Systscale_whichSF || Egamma_Gainscale_whichSF){
           if (trueGain>0) scale = EgammaScaling.get_energyScale(SCEta,Photon_r9[i], trueGain , run,
               Egamma_Statscale_whichSF, Egamma_Systscale_whichSF, Egamma_Gainscale_whichSF);
           else {
             float scale6    = EgammaScaling.get_energyScale(SCEta,Photon_r9[i], 6 , run,
               Egamma_Statscale_whichSF, Egamma_Systscale_whichSF, Egamma_Gainscale_whichSF);

             float scale1    = EgammaScaling.get_energyScale(SCEta,Photon_r9[i], 1 , run,
               Egamma_Statscale_whichSF, Egamma_Systscale_whichSF, Egamma_Gainscale_whichSF);

             scale    = (scale6+scale1)/2;

             //if (systematic_switches[ "EGamma_gain61" ] == 1) scale = max(scale6, scale1);
             //if (systematic_switches[ "EGamma_gain61" ] == 2) scale = min(scale6, scale1);
           }
         }
       }
       else smear = EgammaSmearing.get_Semar(SCEta, Photon_r9[i],  Photon_pt[i],Egamma_Rhoresol_whichSF,Egamma_Phiresol_whichSF);
     
       float corr = scale + smear * gen->Gaus(1, 1);
       phoET.push_back(Photon_pt[i] / Photon_eCorr[i] * corr);
       //L1prefire correction
       if (_fastSim && year!=2018 && Photon_pt[i]>20 && abs(Photon_eta[i])>2 && abs(Photon_eta[i])<3) {
         double max= h_L1prefire_phoMap->GetYaxis()->GetBinLowEdge(h_L1prefire_phoMap->GetNbinsY());
         double pt = (Photon_pt[i]>max) ? max-0.01 : Photon_pt[i];
         double prefireProb = h_L1prefire_phoMap->GetBinContent(h_L1prefire_phoMap->FindBin(Photon_eta[i],pt));
         double stat = h_L1prefire_phoMap->GetBinError(h_L1prefire_phoMap->FindBin(Photon_eta[i],pt));
         double syst = prefireProb*0.2;
         nonPrefiringProbability[0]*=(1-prefireProb);
         nonPrefiringProbability[1]*=(1-std::min(1.,prefireProb+sqrt(pow(stat,2)+pow(syst,2))));
         nonPrefiringProbability[2]*=(1-std::max(0.,prefireProb-sqrt(pow(stat,2)+pow(syst,2))));
       }
       if ((Photon_isScEtaEB[i] || Photon_isScEtaEE[i]) && Photon_pixelSeed[i]==0 && phoET[i]>40) {
         if (Photon_cutBased_versionFree[i]>0) passPhoL.push_back(i);
         if (Photon_cutBased_versionFree[i]>>1&1) passPhoM.push_back(i);
         if (Photon_cutBased_versionFree[i]>>2&1) passPhoT.push_back(i);
         if (Photon_mvaID_WP80[i]) passPhoMVA80.push_back(i);
         if (Photon_mvaID_WP90[i]) passPhoMVA90.push_back(i);
       }
       if ((Photon_isScEtaEB[i] || Photon_isScEtaEE[i]) && Photon_pixelSeed[i]!=0) {
         if (Photon_cutBased_versionFree[i]>0) passElePhoL.push_back(i);
         if (Photon_cutBased_versionFree[i]>>1&1) passElePhoM.push_back(i);
         if (Photon_cutBased_versionFree[i]>>2&1) passElePhoT.push_back(i);
         if (Photon_mvaID_WP80[i]) passElePhoMVA80.push_back(i);
         if (Photon_mvaID_WP90[i]) passElePhoMVA90.push_back(i);
       }
     }
     (whichPhoton==0) ? passPhotons=passPhoL : (whichPhoton==1) ? passPhotons=passPhoM : (whichPhoton==2) ? passPhotons=passPhoT :
     (whichPhoton==3) ? passPhotons=passPhoMVA80 : passPhotons=passPhoMVA90;
     (whichPhoton==0) ? passElePhotons=passElePhoL : (whichPhoton==1) ? passElePhotons=passElePhoM : (whichPhoton==2) ? passElePhotons=passElePhoT :
     (whichPhoton==3) ? passElePhotons=passElePhoMVA80 : passElePhotons=passElePhoMVA90;
     for (auto i : passPhotons) {
       if (phoET[i]>phoET[nleadPho]) nleadPho=i;
       EMHT_before+=phoET[i];
     }
     for (auto i : passElePhotons) if (phoET[i]>phoET[nleadElePho]) nleadElePho=i;
     if (_fakeRate==2 && passElePhotons.size() != 0) {nleadPho=nleadElePho; passPhotons=passElePhotons;}
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
     EMHT_after=EMHT_before;
     AK8EMHT_before=EMHT_before;
     AK8EMHT_after=EMHT_before;
     //Calculate photon SFs
     if (!isData) {
       double id_sf=0, pix_sf=0, syst_id=0, syst_pix=0;
       int sign_id=0, sign_pix=0;
       if (passPhotons.size()!=0){
         double photon_eta=Photon_eta[nleadPho]; //needed for difference between SCEta and photon_eta
         double photon_et=(phoET[nleadPho]>499) ? 499 : phoET[nleadPho]; //needed for maximum ET in SF histo
         if (photon_eta>1.2 && photon_eta<1.5)  photon_eta=1.2;
         if (photon_eta>1.5 && photon_eta<1.7)  photon_eta=1.7;
         if (photon_eta<-1.2 && photon_eta>-1.5)  photon_eta=-1.2;
         if (photon_eta<-1.5 && photon_eta>-1.7)  photon_eta=-1.7;
         if (photon_eta<=-2.5)  photon_eta=-2.4;
         if (photon_eta>=2.5)  photon_eta=2.4;
         double abs_photon_eta=(abs(Photon_eta[nleadPho])>1.5) ? 2 : 0.5;
         id_sf=h_pho_EGamma_SF2D[whichPhoton]->GetBinContent(h_pho_EGamma_SF2D[whichPhoton]->FindBin(photon_eta,photon_et));
         syst_id=h_pho_EGamma_SF2D[whichPhoton]->GetBinError(h_pho_EGamma_SF2D[whichPhoton]->FindBin(photon_eta,photon_et));
         if (year==2016) {
           if (Photon_r9[nleadPho]>0.94) {
             pix_sf=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs_photon_eta,100));
             syst_pix=h_Scaling_Factors_HasPix_R9_high->GetBinError(h_Scaling_Factors_HasPix_R9_high->FindBin(abs_photon_eta,100));
           }
           else {
             pix_sf=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs_photon_eta,100));
             syst_pix=h_Scaling_Factors_HasPix_R9_low->GetBinError(h_Scaling_Factors_HasPix_R9_low->FindBin(abs_photon_eta,100));
           }
         }
         else if (year==2017) {
           unsigned int wpchooser=(whichPhoton<3) ? whichPhoton : 3;
           if (Photon_r9[nleadPho]>0.94) {
             pix_sf=(Photon_isScEtaEB[nleadPho]) ? h_PixelSeed_ScaleFactors_2017[wpchooser]->GetBinContent(2) : h_PixelSeed_ScaleFactors_2017[wpchooser]->GetBinContent(5);
             syst_pix=(Photon_isScEtaEB[nleadPho]) ? h_PixelSeed_ScaleFactors_2017[wpchooser]->GetBinError(2) : h_PixelSeed_ScaleFactors_2017[wpchooser]->GetBinError(5);
           }
           else {
             pix_sf=(Photon_isScEtaEB[nleadPho]) ? h_PixelSeed_ScaleFactors_2017[wpchooser]->GetBinContent(3) : h_PixelSeed_ScaleFactors_2017[wpchooser]->GetBinContent(6);
             syst_pix=(Photon_isScEtaEB[nleadPho]) ? h_PixelSeed_ScaleFactors_2017[wpchooser]->GetBinError(3) : h_PixelSeed_ScaleFactors_2017[wpchooser]->GetBinError(6);
           }
         }
         else if (year==2018) {
           pix_sf=h_PixelSeed_ScaleFactors_2018->GetBinContent(h_PixelSeed_ScaleFactors_2018->FindBin((photon_et>200) ? 150 : photon_et,abs_photon_eta));
           syst_pix=h_PixelSeed_ScaleFactors_2018_unc->GetBinContent(h_PixelSeed_ScaleFactors_2018_unc->FindBin((photon_et>200) ? 150 : photon_et,abs_photon_eta));
         }
         (phoID_whichSF==1) ? sign_id=1 : (phoID_whichSF==2) ? sign_id=-1 : sign_id=0;
         (phoPix_whichSF==1) ? sign_pix=1 : (phoPix_whichSF==2) ? sign_pix=-1 : sign_pix=0;
         pho_SF[0]=(id_sf+sign_id*syst_id)*(pix_sf+sign_pix*syst_pix);
         if (id_sf==0 || pix_sf==0) cout<<"pho Et "<<phoET[nleadPho]<<" pho eta "<<Photon_eta[nleadPho]<<" mod_eta "<<photon_eta<<" scEB "<<Photon_isScEtaEB[nleadPho]<<" scEE "<<Photon_isScEtaEE[nleadPho]<<" id sf "<<id_sf<<" +- "<<syst_id<<" pix sf "<<pix_sf<<" +- "<<syst_pix<<endl;
       }
     }
     //electron
     for (unsigned int i=0;i<nElectron;i++) {
       bool passOverlap=true;
       for (auto j : passPhotons) if (deltaR(Electron_phi[i],Photon_phi[j],Electron_eta[i],Photon_eta[j])<0.3) {
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
     //Calculate electron SFs
     if (!isData) {
       double id_sf=0, rec_sf=0, syst_id=0, syst_rec=0;
       int sign_id=0, sign_rec=0;
       (eleID_whichSF==1) ? sign_id=1 : (eleID_whichSF==2) ? sign_id=-1 : sign_id=0;
       (eleRec_whichSF==1) ? sign_rec=1 : (eleRec_whichSF==2) ? sign_rec=-1 : sign_rec=0;
       if (passElectrons.size()!=0){
         double pt=Electron_pt[passElectrons[0]];
         pt=(pt<450) ? pt : 450; pt=(pt>10) ? pt : 10;
         id_sf=h_ele_EGamma_SF2D[whichElectron]->GetBinContent(h_ele_EGamma_SF2D[whichElectron]->FindBin(Electron_eta[passElectrons[0]],pt));
         syst_id=h_ele_EGamma_SF2D[whichElectron]->GetBinError(h_ele_EGamma_SF2D[whichElectron]->FindBin(Electron_eta[passElectrons[0]],pt));
         if (pt<20) {
           rec_sf=h_eleRec_EGamma_SF2D[0]->GetBinContent(h_eleRec_EGamma_SF2D[0]->FindBin(Electron_eta[passElectrons[0]],pt));
           syst_rec=h_eleRec_EGamma_SF2D[0]->GetBinError(h_eleRec_EGamma_SF2D[0]->FindBin(Electron_eta[passElectrons[0]],pt));
         }
         else {
           rec_sf=h_eleRec_EGamma_SF2D[1]->GetBinContent(h_eleRec_EGamma_SF2D[1]->FindBin(Electron_eta[passElectrons[0]],pt));
           syst_rec=h_eleRec_EGamma_SF2D[1]->GetBinError(h_eleRec_EGamma_SF2D[1]->FindBin(Electron_eta[passElectrons[0]],pt));
         }
         ele_SF[whichElectron]=(id_sf+sign_id*syst_id)*(rec_sf+sign_rec*syst_rec);
         if (id_sf==0 || rec_sf==0) cout<<"id_sf "<<id_sf<<"*"<<rec_sf<<"="<<id_sf*rec_sf<<" +- "<<syst_id<<" "<<syst_rec<<" finalSF= "<<ele_SF[0]<<endl;
       }
       if (nPassEleNO!=0){ //only for loose electrons so far
         double pt=Electron_pt[passEleNO[0]];//, pt2=Electron_pt[passEleNO[0]];
         pt=(pt<450) ? pt : 450; pt=(pt>10) ? pt : 10;// pt2=(pt>30) ? pt : 31;
         double epsilon=h_ele_EGamma_EffMC2D[1]->GetBinContent(h_ele_EGamma_EffMC2D[1]->FindBin(Electron_eta[passEleNO[0]],pt));
         id_sf=h_ele_EGamma_SF2D[1]->GetBinContent(h_ele_EGamma_SF2D[1]->FindBin(Electron_eta[passEleNO[0]],pt));
         syst_id=h_ele_EGamma_SF2D[1]->GetBinError(h_ele_EGamma_SF2D[1]->FindBin(Electron_eta[passEleNO[0]],pt));
         ele_VETOSF = (epsilon == 1) ? 1 : (1-(id_sf+sign_id*syst_id)*epsilon)/(1-epsilon);
         if (ele_VETOSF==0 || std::isnan(ele_VETOSF)) cout<<"ele veto id "<<id_sf<<" epsilon "<<epsilon<<" sf "<<ele_VETOSF<<endl;
       }
     }
     //muon
     for (unsigned int i=0;i<nMuon;i++) {
       bool passOverlap=true;
       for (auto j : passPhotons) if (deltaR(Muon_phi[i],Photon_phi[j],Muon_eta[i],Photon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passElectrons) if (deltaR(Muon_phi[i],Electron_phi[j],Muon_eta[i],Electron_eta[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
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
     //muon SF
     if (!isData){
       int iter[3]={-1,-1,-1};
       if (nPassMuL>0) iter[0]=passMuL.at(0);
       if (nPassMuM>0) iter[1]=passMuM.at(0);
       if (nPassMuT>0) iter[2]=passMuT.at(0);
       for (int i=0;i<3;i++) {
         if (iter[i]!=-1){
           float pt = ( Muon_pt[iter[i]]< 20)? 20 : (Muon_pt[iter[i]]< 100) ? Muon_pt[iter[i]] : 100 ; //Histo range is: 20-120, highest bin 60-120
           float eta = (year==2016) ? Muon_eta[iter[i]] : abs(Muon_eta[iter[i]]);
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
     }

     //Tau
     for (unsigned int i=0;i<nTau;i++) {
       bool passOverlap=true;
       for (auto j : passPhotons) if (deltaR(Tau_phi[i],Photon_phi[j],Tau_eta[i],Photon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passElectrons) if (deltaR(Tau_phi[i],Electron_phi[j],Tau_eta[i],Electron_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passMuons) if (deltaR(Tau_phi[i],Muon_phi[j],Tau_eta[i],Muon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
       if (Tau_pt[i]>tau_pt && abs(Tau_eta[i])<2.3) {
         if (Tau_idMVAoldDM2017v2[i]>>2&1) passTauL.push_back(i);
         if (Tau_idMVAoldDM2017v2[i]>>3&1) passTauM.push_back(i);
         if (Tau_idMVAoldDM2017v2[i]>>4&1) passTauT.push_back(i);
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

     //Tau SF
     if (!isData) {
       if (passTauL.size() != 0) tau_SF[0]=tf1_tau_ID_SF[0]->Eval(Tau_pt[nleadTauL]);
       if (passTauM.size() != 0) tau_SF[1]=tf1_tau_ID_SF[1]->Eval(Tau_pt[nleadTauM]);
       if (passTauT.size() != 0) tau_SF[2]=tf1_tau_ID_SF[2]->Eval(Tau_pt[nleadTauT]);
       if (tau_SF[0]==0 || tau_SF[1]==0 || tau_SF[2]==0) cout<<"nPassTauL "<<nPassTauL<<" nPassTauM "<<nPassTauM<<" nPassTauT "<<nPassTauT<<" tau L SF "<<tau_SF[0]<<" tau M SF "<<tau_SF[1]<<" tau T SF "<<tau_SF[2]<<endl;
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
       if (year==2017) MT_iso=sqrt(2*METFixEE2017_pt_nom*IsoTrack_pt[i]*(1-cos(abs(IsoTrack_phi[i]-METFixEE2017_phi_nom))));
       else MT_iso=sqrt(2*MET_pt_nom*IsoTrack_pt[i]*(1-cos(abs(IsoTrack_phi[i]-MET_phi_nom))));
       if (MT_iso<100) passIso.push_back(i);
     }
     nPassIso=passIso.size();
     if (passIso.size() != 0) nleadIso=passIso[0];

     //jet ID
     bool vetoFastSim=false; //veto for fastsim unmatched jets https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSRecommendationsMoriond17#Cleaning_up_of_fastsim_jets_from
     for (unsigned int i=0;i<nJet;i++) {
       //L1prefire correction
       if (_fastSim && year!=2018 && Jet_pt[i]>20 && abs(Jet_eta[i])>2 && abs(Jet_eta[i])<3) {
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
       jetSmearedPt.push_back(jetpt); jetSmearedMass.push_back(jetmass);
       HT_before+=jetSmearedPt[i];
       if (abs(Jet_eta[i])>2.4 || !(Jet_jetId[i]>>1&1) || jetSmearedPt[i]<30) passcut=false;
       if (jetSmearedPt[i]<50 && !(Jet_puId[i]&(1<<2))) passcut=false;
       for (auto j : passPhotons) if (deltaR(Jet_phi[i],Photon_phi[j],Jet_eta[i],Photon_eta[j])<0.4) {
         passcut=false;break;
       }
       for (auto j : passElectrons) if (deltaR(Jet_phi[i],Electron_phi[j],Jet_eta[i],Electron_eta[j])<0.4) {
         passcut=false;break;
       }
       for (auto j : passMuons) if (deltaR(Jet_phi[i],Muon_phi[j],Jet_eta[i],Muon_eta[j])<0.4) {
         passcut=false;break;
       }
       for (auto j : passTaus) if (deltaR(Jet_phi[i],Tau_phi[j],Jet_eta[i],Tau_eta[j])<0.4) {
         passcut=false;break;
       }
       //for (auto j : passIso) if (deltaR(Jet_phi[i],IsoTrack_phi[j],Jet_eta[i],IsoTrack_eta[j])<0.4) {
       //  passcut=false;break;
       //}
       if (_fastSim && year==2016 && passcut && Jet_chHEF[i]<0.1) {
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
     if (vetoFastSim) continue;
     //jet pt, btags
     for (auto i : passJet) {
       if (jetSmearedPt[i]>jetSmearedPt[leadpt_ak4]) leadpt_ak4=i;
       HT_after+=jetSmearedPt[i];
       if (Jet_btagDeepFlavB[i]>BtagDeepWP[year_chooser][2]) {passDeep.insert(pair<int,char>(i,'T'));bcounterDeep[3]++;}
       else if (Jet_btagDeepFlavB[i]>BtagDeepWP[year_chooser][1]) {passDeep.insert(pair<int,char>(i,'M'));bcounterDeep[2]++;}
       else if (Jet_btagDeepFlavB[i]>BtagDeepWP[year_chooser][0]) {passDeep.insert(pair<int,char>(i,'L'));bcounterDeep[1]++;}
       else {passDeep.insert(pair<int,char>(i,'0'));bcounterDeep[0]++;}
     }
     bcounterDeep[2] += bcounterDeep[3];
     bcounterDeep[1] += bcounterDeep[2];
     //Sort passJet from highest DeepJet btag to lowest
     for (unsigned int i=0;i<passJet.size();i++){
       int temp;
       for (unsigned int j=passJet.size()-1;j>i;j--){
         if (Jet_btagDeepFlavB[passJet[j]]>Jet_btagDeepFlavB[passJet[j-1]]){
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
     //AK8Jet pt, btag
     for (auto i : passAK8Jet) {
       if (AK8JetSmearedPt[i]>AK8JetSmearedPt[leadpt_ak8]) leadpt_ak8=i;
       AK8HT_after+=AK8JetSmearedPt[i];
       double i_jetdB=FatJet_btagDDBvL[i], h_jetdB;
       if (highDDBvL==-1) h_jetdB=-10; else h_jetdB=FatJet_btagDDBvL[highDDBvL];
       if (i_jetdB>h_jetdB) highDDBvL=i;
       if (FatJet_btagDDBvL[i]>BtagDDBvLWP[year_chooser][4]) {passDDBvL.insert(pair<int,char>(i,'C'));bcounterDDBvL[5]++;}
       else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[year_chooser][3]) {passDDBvL.insert(pair<int,char>(i,'T'));bcounterDDBvL[4]++;}
       else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[year_chooser][2]) {passDDBvL.insert(pair<int,char>(i,'H'));bcounterDDBvL[3]++;}
       else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[year_chooser][1]) {passDDBvL.insert(pair<int,char>(i,'M'));bcounterDDBvL[2]++;}
       else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[year_chooser][0]) {passDDBvL.insert(pair<int,char>(i,'L'));bcounterDDBvL[1]++;}
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
         if (FatJet_btagDDBvL[passAK8Jet[j]]>FatJet_btagDDBvL[passAK8Jet[j-1]]){
           temp=passAK8Jet[j-1];
           passAK8Jet[j-1]=passAK8Jet[j];
           passAK8Jet[j]=temp;
         }
       }
     }
     AK8EMHT_before+=HT_before;
     AK8EMHT_after+=HT_after;

     //AK8 genjet matching -- use closest in dR, if more fatjet than genjet pair extra fatjet with -1
     vector<int> FatJet_genJetIdx;
     vector<int> matched_reco;
     for (unsigned int i=0;i<nGenJetAK8;i++){
       double mindr=999; int matched_id=-1;
       for (unsigned int j=0;j<nFatJet;j++){
         double dr=deltaR(FatJet_phi[j],GenJetAK8_phi[i],FatJet_eta[j],GenJetAK8_eta[i]);
         if (dr<mindr) {mindr=dr;matched_id=j;}
       }
       matched_reco.push_back(matched_id);
     }

     for (unsigned int i=0;i<nFatJet;i++) {
       if (matched_reco.size()<=nFatJet) {
         bool matched=0;
         for (unsigned int j=0;j<matched_reco.size();j++) if (matched_reco[j]==i) {FatJet_genJetIdx.push_back(j); matched=1;}
         if (!matched) FatJet_genJetIdx.push_back(-1);
       }
       else {
         double mindr=999; int matched_id=-1;
         for (unsigned int j=0;j<nGenJetAK8;j++) {
           double dr=deltaR(FatJet_phi[i],GenJetAK8_phi[j],FatJet_eta[i],GenJetAK8_eta[j]);
           if (dr<mindr) {mindr=dr;matched_id=j;}
         }
         FatJet_genJetIdx.push_back(matched_id);
       }
     }

     //MET variables
     double METPhi=0, METsumEt=0, METSig=0;
     for (auto i : passPhotons) ST+=phoET[i];
     if (year!=2017) {
       MET=MET_pt_nom; METPhi=MET_phi_nom; METsumEt=MET_sumEt; METSig=MET_significance;
       if (JER_whichSF==1) {MET=MET_pt_jerUp; METPhi=MET_phi_jerUp;}
       else if (JER_whichSF==2) {MET=MET_pt_jerDown; METPhi=MET_phi_jerDown;}
       if (JES_whichSF==1) {MET=MET_pt_jesTotalUp; METPhi=MET_phi_jesTotalUp;}
       else if (JES_whichSF==2) {MET=MET_pt_jesTotalDown; METPhi=MET_phi_jesTotalDown;}
       if (UES_whichSF==1) {MET=MET_pt_unclustEnUp; METPhi=MET_phi_unclustEnUp;}
       else if (UES_whichSF==2) {MET=MET_pt_unclustEnDown; METPhi=MET_phi_unclustEnDown;}
     }
     else {
       MET=METFixEE2017_pt_nom; METPhi=METFixEE2017_phi_nom; METsumEt=METFixEE2017_sumEt; METSig=METFixEE2017_significance;
       if (JER_whichSF==1) {MET=METFixEE2017_pt_jerUp; METPhi=METFixEE2017_phi_jerUp;}
       else if (JER_whichSF==2) {MET=METFixEE2017_pt_jerDown; METPhi=METFixEE2017_phi_jerDown;}
       if (JES_whichSF==1) {MET=METFixEE2017_pt_jesTotalUp; METPhi=METFixEE2017_phi_jesTotalUp;}
       else if (JES_whichSF==2) {MET=METFixEE2017_pt_jesTotalDown; METPhi=METFixEE2017_phi_jesTotalDown;}
       if (UES_whichSF==1) {MET=METFixEE2017_pt_unclustEnUp; METPhi=METFixEE2017_phi_unclustEnUp;}
       else if (UES_whichSF==2) {MET=METFixEE2017_pt_unclustEnDown; METPhi=METFixEE2017_phi_unclustEnDown;}
     }
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
       mcLeptonFilter=false;
       for (unsigned int i=0; i<nGenPart; i++){
         if ((GenPart_statusFlags[i] & 1) != 0 && (abs(GenPart_pdgId[i])== 11 || abs(GenPart_pdgId[i])== 13 || abs(GenPart_pdgId[i])== 15)){
           mcLeptonFilter=true;
           //cout<<"pid "<<GenPart_pdgId[i]<<" pt "<<GenPart_pt[i]<<" status "<<GenPart_status[i]<<" statusflag "<<GenPart_statusFlags[i]<<" momPID "<<GenPart_pdgId[GenPart_genPartIdxMother[i]]<<endl;
         }
       }
       //cout<<"lepton "<<mcLeptonFilter<<endl;
     }

       //L1prefire
       //check events if there's a jet (photon) with pt>100 (>50) and 2.25<|eta|<3.0
       L1prefire=0;
       for (auto i : passPhotons) if (phoET[i]>50 && abs(Photon_eta[i])>2.25) L1prefire=1;
       for (auto i : passJet) if (jetSmearedPt[i]>100 && abs(Jet_eta[i])>2.25) L1prefire=1;

       //find which btag jet to use for Higgs mass
       //AK8
       passBtag=false; passHiggsMass=false;
       int SelectedAK8Jet=-1;
       DDBvL_selected=0; //DDBvL btag value of higgs candidate jet. 0-Nobtag, 1-loose, 2-medium 3-medium2 4-tight
       if (passAK8Jet.size()>0){
         SelectedAK8Jet=passAK8Jet[0];
         if (AK8JetSmearedMass[passAK8Jet[0]]>70 && AK8JetSmearedMass[passAK8Jet[0]]<200) {
           passHiggsMass=true;
           if (FatJet_btagDDBvL[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][4]) DDBvL_selected=5;
           else if (FatJet_btagDDBvL[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][3]) DDBvL_selected=4;
           else if (FatJet_btagDDBvL[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][2]) DDBvL_selected=3;
           else if (FatJet_btagDDBvL[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][1]) DDBvL_selected=2;
           else if (FatJet_btagDDBvL[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][0]) DDBvL_selected=1;
           else DDBvL_selected=0;
           if (FatJet_btagDDBvL[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][0]) passBtag=true;
           //if (FatJet_btagDDBvL[passAK8Jet[0]]>BtagDDBvLWP[year_chooser][1]) passBtag=true;//AK8medium
         }
       }

       //AK4
       double m_bb_deep=-1, phi_H_candidate=999, pt_H_candidate=-1;
       bool passAK4DeepHiggsMass=false;
       Deep_selected=0; //Deep btag value of higgs candidate jets. 0-Nobtag, 1-1 loose btag, 2-2 loose btag
       int Deep_medium_selected=0;
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
               if (Jet_btagDeepFlavB[passJet.at(i)]>BtagDeepWP[year_chooser][0]) Deep_selected++;
               if (Jet_btagDeepFlavB[passJet.at(j)]>BtagDeepWP[year_chooser][0]) Deep_selected++;
               if (Jet_btagDeepFlavB[passJet.at(i)]>BtagDeepWP[year_chooser][1]) Deep_medium_selected++;//medium
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

           //Calculate BTag SFs
           int countb=0;
           if (!isData && btag_file.size()>0) {
             if (year==2016) CalcBtagSF(_fastSim, Jet_eta, jetSmearedPt, Jet_hadronFlavour, passDeep, eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_L_2016deep, reader_M_2016deep, reader_T_2016deep, reader_L_2016fast, reader_M_2016fast, reader_T_2016fast, Deep_SF_L, Deep_SF_M, Deep_SF_T);
             //if (year==2016) CalcBtagSF(_fastSim, Jet_eta, jetSmearedPt, Jet_hadronFlavour, passDeep, eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_L_2016deep, reader_M_2016deep, reader_T_2016deep, reader_L_2017fast, reader_M_2017fast, reader_T_2017fast, Deep_SF_L, Deep_SF_M, Deep_SF_T);
             else if (year==2017) CalcBtagSF(_fastSim, Jet_eta, jetSmearedPt, Jet_hadronFlavour, passDeep, eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_L_2017deep, reader_M_2017deep, reader_T_2017deep, reader_L_2017fast, reader_M_2017fast, reader_T_2017fast, Deep_SF_L, Deep_SF_M, Deep_SF_T);
             else if (year==2018) CalcBtagSF(_fastSim, Jet_eta, jetSmearedPt, Jet_hadronFlavour, passDeep, eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_L_2018deep, reader_M_2018deep, reader_T_2018deep, reader_L_2018fast, reader_M_2018fast, reader_T_2018fast, Deep_SF_L, Deep_SF_M, Deep_SF_T);
             //BTEntry::JetFlavor flavour=BTEntry::FLAV_UDSG;
             //vector<double> v_eta={-2,-1.5,-0.5,0.5,1.5,2}, v_pt={100,200,300,600,1200};
             //for (auto i : v_eta) for (auto j : v_pt) {
             //cout<<"eta "<<i<<" pt "<<j<<" SF fast "<<reader_M_2016fast.eval_auto_bounds("central",flavour,i,j)<<" SF full "<<reader_M_2016deep.eval_auto_bounds("central",flavour,i,j)<<endl;
             //}
             if (bcounterDeep[1]>0) {
               for (map<int,char>::iterator it=passDeep.begin(); it!=passDeep.end(); ++it) {
                 if (Jet_hadronFlavour[it->first]==0 && it->second != '0') countb++;
                 BTEntry::JetFlavor FLAV;
                 double eta=Jet_eta[it->first];
                 double pt=jetSmearedPt[it->first];
                 if (pt>=2000) pt=1999;
                 if (Jet_hadronFlavour[it->first]==5) {
                   FLAV = BTEntry::FLAV_B;
                   double sf16 = reader_L_2016fast.eval_auto_bounds("central",FLAV,eta,pt);
                   double sf17 = reader_L_2017fast.eval_auto_bounds("central",FLAV,eta,pt);
                   if (sf16>5 || sf17>5) cout<<"too big!"<<endl;
                   h_btag_sf_b_2016->Fill(sf16);
                   h_btag_sf_b_2017->Fill(sf17);
                 }
                 else if (Jet_hadronFlavour[it->first]==0) {
                   FLAV = BTEntry::FLAV_UDSG;
                   double sf16 = reader_L_2016fast.eval_auto_bounds("central",FLAV,eta,pt);
                   double sf17 = reader_L_2017fast.eval_auto_bounds("central",FLAV,eta,pt);
                   if (sf16>5 || sf17>5) cout<<"too big!"<<endl;
                   h_btag_sf_l_2016->Fill(sf16);
                   h_btag_sf_l_2017->Fill(sf17);
                 }
               }
             }
             //cout<<event<<" "<<Deep_SF_L[0]<<" tagged light "<<count<<endl;
             //AK8
             if (_fastSim) CalcBtagSF_AK8(year, AK8JetSmearedPt, passDDBvL, DDBvL_SF_L, DDBvL_SF_M1, DDBvL_SF_M2, DDBvL_SF_T1, DDBvL_SF_T2);
           }

           //SignalStudy
           int Higgs_jet_b=-1, Higgs_jet_antib=-1, index_b=-1, index_ab=-1, njet_index=-1;
           double AK4Hmass=-1, Hbbmass=-1, genAK4Hmass=-1, dR_trueHbb=-1, dphi_trueH_ak4=999, dphi_trueHmin_ak4=999;
           double Higgs_pt=-1, Higgs_phi=-1, dphi_trueH_gravitino=999;
           if (SignalScan) {
             int nHiggs=0, ib1=-1, ib2=-1;
             for (unsigned int i=0;i<nGenPart;i++){
               if (GenPart_pdgId[i]==25 && GenPart_statusFlags[i]&int(pow(2,13))) {nHiggs++; Higgs_pt=GenPart_pt[i]; Higgs_phi=GenPart_phi[i];}
               if (GenPart_pdgId[i]==5 && GenPart_pdgId[GenPart_genPartIdxMother[i]]==25) ib1=i;
               if (GenPart_pdgId[i]==-5 && GenPart_pdgId[GenPart_genPartIdxMother[i]]==25) ib2=i;
             }
             SignalHiggs=nHiggs;
             (ib1!=-1 && ib2!=-1) ? Hbb=true : Hbb=false;
             if (SignalHiggs>2) cout<<"too many higgs in "<<fChain->GetCurrentFile()->GetName()<<" event "<<event<<endl;
             if (signalstudy) {
               vector<int> v_final_b;
               int final_b=-1, final_antib=-1, n_bq=0, n_abq=0, gravitino_1=-1, gravitino_2=-1;
               for (unsigned int i=0;i<nGenPart;i++){
                 //printf("Index %-2i PDGID %-8d mcPt %-12f Eta %-9f Phi %-9f mom %-8d momPt %-9f  momEta %-9f  momPhi %-9f status %-2i flag %-9s gmom %-8d\n",i,GenPart_pdgId[i],GenPart_pt[i],GenPart_eta[i],GenPart_phi[i],GenPart_pdgId[GenPart_genPartIdxMother[i]],GenPart_pt[GenPart_genPartIdxMother[i]],GenPart_eta[GenPart_genPartIdxMother[i]],GenPart_phi[GenPart_genPartIdxMother[i]],GenPart_status[i],bitset<9>(GenPart_statusFlags[i]).to_string().c_str(),GenPart_pdgId[GenPart_genPartIdxMother[GenPart_genPartIdxMother[i]]]);
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
           double met = (MET<70) ? 1 : (MET<100) ? 2 : (MET<200) ? 3 : (MET<500) ? 4 : 5;
           double njet;
           //AK4-AK8 searchBins
           int AK4AK8=0, VR=0, boost=0;
           //Signal Region
           //if (DDBvL_selected>1) {boost=1;AK4AK8=1;}//AK8medium
           if (DDBvL_selected>0) {boost=1;AK4AK8=1;}
           else {if (Deep_selected==2) AK4AK8=2; else if (Deep_medium_selected==1) AK4AK8=1;}//medium
           //else {if (Deep_selected==1 && Deep_medium_selected==1) AK4AK8=2; else if (Deep_medium_selected==1) AK4AK8=1;}//medium-loose
           //else {if (Deep_selected==1) AK4AK8=1; if (Deep_selected==2) AK4AK8=2;}
           //Control and Validation regions
           //if (DDBvL_selected==0 && Deep_selected==0) {
           //if (DDBvL_selected==0 && Deep_medium_selected==0) {//medium-loose
           //if (DDBvL_selected<2 && Deep_selected<2 && Deep_medium_selected==0) {//medium AK8medium
           if (DDBvL_selected==0 && Deep_selected<2 && Deep_medium_selected==0) {//medium
             //if (bcounterDDBvL[2]>0) {boost=1; VR=1; AK4AK8=1;}//AK8medium
             if (bcounterDDBvL[1]>0) {boost=1; VR=1; AK4AK8=1;}
             else if (passHiggsMass) boost=1;
             if (!boost) {
               //if (bcounterDeep[1]==1) {VR=1;AK4AK8=1;}
               //if (bcounterDeep[1]>0 && bcounterDeep[2]>0) {VR=1;AK4AK8=2;}//medium-loose
               if (bcounterDeep[1]>1) {VR=1;AK4AK8=2;}
               else if (bcounterDeep[2]>=1) {VR=1;AK4AK8=1;} //medium
               //if (!passAK4DeepHiggsMass && bcounterDeep[1]==0) {
               //if (!passAK4DeepHiggsMass && bcounterDeep[2]==0) {//medium-loose
               if (!passAK4DeepHiggsMass && bcounterDeep[1]<2 && bcounterDeep[2]==0) {//medium
                 if (nPassAK8>0) {boost=1; VR=1;}
                 else VR=1;
               }
             }
           }
           //MT & dphi VR version
           //if (DDBvL_selected==0 && Deep_selected<2 && Deep_medium_selected==0) {
           //  if (passHiggsMass) boost=1;
           //  else if (!passAK4DeepHiggsMass) continue;
           //}

           //AK4 AK8 overlap
           if (!boost) nonHiggsJet=passJet.size()-2;
           else {
             auto i = passJet.begin();
             while (i!=passJet.end()) {
               if (deltaR(FatJet_phi[SelectedAK8Jet],Jet_phi[*i],FatJet_eta[SelectedAK8Jet],Jet_eta[*i])<0.8) passJet.erase(i);
               else i++;
             }
             nonHiggsJet=passJet.size();
           }
           njet = (nonHiggsJet<4) ? 1 : 2;
          
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
           
           //MT & dphi VR version
           //if (MT<100) VR=1;
           //if (dphi_met_H_candidate<0.3) VR=1;
           double sbFill_ak4ak8[dim_ak4]={double(VR),double(AK4AK8),met,njet};
           
           
           //2d dphi distributions
           if (met>3 && VR==0 && AK4AK8>0) {
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
           h_eff->Fill(0.,w);
           //cuts with command line
           if (_cut_variable.size()>0) {if (!(Cut(ientry,mass_pair))) continue;}
           else { //Hardcoded cuts
             if (PV_npvsGood==0) continue;
           }

           //Cut for high njet region (need to implement in Cut() if decided as standard)
           //Filling histograms
           h_eff->Fill(1.,w);
           h_nISR_jet->Fill(n_isr_jets,w);
           double bw=(Deep_SF_L[0]>200) ? 199 : Deep_SF_L[0];
           h2_btag_weight->Fill(bw,countb);

           if (nleadPho!=-1) h_phoEt->Fill(phoET[nleadPho],w);
           if (nleadPho!=-1) h_phoEta->Fill(Photon_eta[nleadPho],w);
           if (nleadPho!=-1) h_phoPt->Fill(phoET[nleadPho],w);

           h_pfMET->Fill(MET,w);
           (METsumEt<5000) ? h_pfMETsumEt->Fill(METsumEt,w) : h_pfMETsumEt->Fill(4999,w);
           h_pfMETPhi->Fill(METPhi,w);
           (METSig<1500) ? h_pfMETSig->Fill(METSig,w) : h_pfMETSig->Fill(1499,w);
           h_ST->Fill(ST,w);
           h_ST_G->Fill(ST_G,w);
           h_MT->Fill(MT,w);
           h_HT_after->Fill(HT_after,w);
           h_EMHT_after->Fill(EMHT_after,w);
           h2_ST_HT->Fill(ST,HT_after,w);
           h2_ST_MET->Fill(ST,MET,w);
           h2_MT_MET->Fill(MT,MET,w);
           h2_MET_HT->Fill(MET,HT_after,w);
           h2_MET_extrajets->Fill(MET,nonHiggsJet,w);
           if (nleadPho!=-1) h2_MET_phoPt->Fill(MET,phoET[nleadPho],w);
           h2_extrajets_HT->Fill(nonHiggsJet,HT_after,w);

           h_nPho->Fill(nPassPhoL,w);
           h_nEle->Fill(nPassEleL,w);
           h_nEleM->Fill(nPassEleM,w);
           h_nEleT->Fill(nPassEleT,w);
           h_nMu->Fill(nPassEleL,w);
           h_nMuM->Fill(nPassMuM,w);
           h_nMuT->Fill(nPassMuT,w);
           h_nTau->Fill(nPassTauL,w);
           h_nIso->Fill(nPassIso,w);
           
           if (nleadEle!=-1) h_ElePt->Fill(Electron_pt[nleadEle],w);
           if (nleadMu!=-1) h_MuPt->Fill(Muon_pt[nleadMu],w);
           if (nleadTau!=-1) h_TauPt->Fill(Tau_pt[nleadTau],w);

           h_njets->Fill(nPassAK4,w);
           h_nonHjets->Fill(nonHiggsJet,w);
           if (leadpt_ak4!=-1) h_jetpt->Fill(Jet_pt_nom[leadpt_ak4],w);
           h_nAK8jets->Fill(nPassAK8,w);
           if (leadpt_ak8!=-1) h_AK8jetpt->Fill(FatJet_pt_nom[leadpt_ak8],w);


           if (m_bb_deep!=-1) h_mbbjet_select->Fill(m_bb_deep,w);
           if (DDBvL_selected>0) h_AK8mass_select->Fill(AK8JetSmearedMass[SelectedAK8Jet],w);
           if (dR_ak4_Hcandidate!=-1) h_dR_ak4_Hcandidate->Fill(dR_ak4_Hcandidate,w);
           if (pt_ak4_Hcandidate1!=-1) h_pt_ak4_Hcandidate->Fill(pt_ak4_Hcandidate1,w);
           if (pt_ak4_Hcandidate2!=-1) h_pt_ak4_Hcandidate->Fill(pt_ak4_Hcandidate2,w);
           if (dphi_met_jet!=999) h_dphi_met_jet->Fill(dphi_met_jet,w);
           if (njet==1 && met>3 && VR==0 && AK4AK8>0 &&dphi_met_jet!=999 && pt_dphi_jet!=-1) h2_dphi_met_lowjet_pt->Fill(dphi_met_jet,pt_dphi_jet,w);
           if (njet==2 && met>3 && VR==0 && AK4AK8>0 &&dphi_met_jet!=999 && pt_dphi_jet!=-1) h2_dphi_met_highjet_pt->Fill(dphi_met_jet,pt_dphi_jet,w);
           if (dphi_met_jet!=999) h2_dphi_met_jet_nonHjets->Fill(dphi_met_jet,nonHiggsJet,w);
           for (int i=0;i<8;i++) h2_dphi_met_jet_njet->Fill(dphi_met_jet_njet[i],i+1,w);
           if (dphi_H_ak8!=999) h_dphi_met_h_ak8->Fill(dphi_H_ak8,w);
           if (dphi_H_ak4!=999) h_dphi_met_h_ak4->Fill(dphi_H_ak4,w);
           if (dphi_Hmin_ak4!=999) h_dphi_met_hmin_ak4->Fill(dphi_Hmin_ak4,w);
           if (dphi_AK4btag!=999) h_dphi_met_ak4btag->Fill(dphi_AK4btag,w);

           //AK4-AK8 searchbin fills
           double w_AK4searchBin=w, w_AK8searchBin=w;
           //if (boost==1 && AK4AK8==1) w_AK8searchBin*=DDBvL_SF_M1[DDBvL_whichSF];//AK8medium
           if (boost==1 && AK4AK8==1) w_AK8searchBin*=DDBvL_SF_L[DDBvL_whichSF];
           else if (boost==0) {if (AK4AK8==1) w_AK4searchBin*=Deep_SF_M[Deep_whichSF]; if (AK4AK8==2) w_AK4searchBin*=Deep_SF_L[Deep_whichSF]*Deep_SF_L[Deep_whichSF];}//medium
           //else if (boost==0) {if (AK4AK8==1) w_AK4searchBin*=Deep_SF_L[Deep_whichSF]; if (AK4AK8==2) w_AK4searchBin*=Deep_SF_L[Deep_whichSF]*Deep_SF_L[Deep_whichSF];}
           //else if (boost==0) {if (AK4AK8==1) w_AK4searchBin*=Deep_SF_M[Deep_whichSF]; if (AK4AK8==2) w_AK4searchBin*=Deep_SF_M[Deep_whichSF]*Deep_SF_L[Deep_whichSF];}//medium-loose
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
           //if (w_AK4searchBin/weight>10) {
             //if (boost) cout << fixed << setprecision(4) << jentry<<" "<<event<<" "<<pu_weight<<" "<<weight<<" "<<pho_SF[0]<<" "<<nonPrefiringProbability[0]<<" "<<ele_SF[0]<<" "<<mu_SF[0]<<" "<<tau_SF[0]<<" "<<w_isr<<" "<<DDBvL_SF_L[DDBvL_whichSF]<<" "<<w_AK8searchBin<<endl;
             //else       cout << fixed << setprecision(4) << jentry<<" "<<event<<" "<<pu_weight<<" "<<weight<<" "<<pho_SF[0]<<" "<<nonPrefiringProbability[0]<<" "<<ele_SF[0]<<" "<<mu_SF[0]<<" "<<tau_SF[0]<<" "<<w_isr<<" "<<Deep_SF_L[Deep_whichSF]<<" "<<w_AK4searchBin<<endl;
           //}

           //higgs mass distribution plot fills
           if (boost && met>3 && AK4AK8>0) {
             int massRegion = (met-4)*2+njet;
             double m=AK8JetSmearedMass[SelectedAK8Jet]; (m<18) ? m=19 : (m>278) ? m=277 : m=m;
             double m2=AK8JetSmearedMass[passAK8Jet.at(0)]; (m2<18) ? m2=19 : (m2>278) ? m2=277 : m2=m2; //Needed because, in VR there can be passHiggsmass w/o btag AND a btagged jet
             if (VR) h2_mHAK8->Fill(massRegion,m2,w*DDBvL_SF_L[DDBvL_whichSF]);
             else if (!isData) h2_mHAK8->Fill(massRegion,m,w*DDBvL_SF_L[DDBvL_whichSF]);
             if (!VR) h2_dphi_met_h_ak8->Fill(massRegion,dphi_H_ak8,w*DDBvL_SF_L[DDBvL_whichSF]);
           }
           if (!boost && met>3 && AK4AK8>0 && passJet.size()>1) {
             int massRegion = (AK4AK8-1)*4+(met-4)*2+njet;
             double m=m_bb_deep; (m<18) ? m=19 : (m>278) ? m=277 : m=m;
             double wtemp=w*Deep_SF_L[Deep_whichSF]; (AK4AK8==2) ? wtemp*=Deep_SF_L[Deep_whichSF] : wtemp=wtemp;
             TLorentzVector bjet1, bjet2; //Needed because, in VR there can be passHiggsmass w/o btag AND a btagged jet
             bjet1.SetPtEtaPhiM(jetSmearedPt[passJet.at(0)],Jet_eta[passJet.at(0)],Jet_phi[passJet.at(0)],jetSmearedMass[passJet.at(0)]);
             bjet2.SetPtEtaPhiM(jetSmearedPt[passJet.at(1)],Jet_eta[passJet.at(1)],Jet_phi[passJet.at(1)],jetSmearedMass[passJet.at(1)]);
             double m2=(bjet1+bjet2).M(); (m2<18) ? m2=19 : (m2>278) ? m2=277 : m2=m2;
             double dR = deltaR(Jet_phi[SelectedAK4Jet1],Jet_phi[SelectedAK4Jet2],Jet_eta[SelectedAK4Jet1],Jet_eta[SelectedAK4Jet2]);
             double dR2= deltaR(Jet_phi[passJet.at(0)],Jet_phi[passJet.at(1)],Jet_eta[passJet.at(0)],Jet_eta[passJet.at(1)]);
             if (VR) {
               h2_mHAK4->Fill(massRegion,m2,wtemp);
               h2_dr_VRHiggs->Fill(massRegion,dR2,wtemp);
               h3_mHAK4_dr_Higgs->Fill(massRegion,m2,dR2,wtemp);
             }
             else if (!isData) {
               h2_mHAK4->Fill(massRegion,m,wtemp);
               h2_dr_SRHiggs->Fill(massRegion,dR,wtemp);
               h3_mHAK4_dr_Higgs->Fill(massRegion,m,dR,wtemp);
             }
             if (!VR) h2_dphi_met_h_ak4->Fill(massRegion,dphi_H_ak4,wtemp);
             if (!VR) h2_dphi_met_hmin_ak4->Fill(massRegion,dphi_Hmin_ak4,wtemp);
             if (!VR) h2_dphi_met_ak4btag->Fill(massRegion,dphi_AK4btag,wtemp);
           }
           if (VR==1 && boost==1 && AK4AK8>0 && met>3) {
             double m=AK8JetSmearedMass[passAK8Jet.at(0)]; (m<18) ? m=19 : (m>278) ? m=277 : m=m;
             h_mHAK8->Fill(m,w*DDBvL_SF_L[DDBvL_whichSF]);
           }
           if (VR==1 && boost==0 && passJet.size()>1 && AK4AK8>0 && met>3) {
             TLorentzVector bjet1, bjet2; //Needed because, in VR there can be passHiggsmass w/o btag AND a btagged jet
             bjet1.SetPtEtaPhiM(jetSmearedPt[passJet.at(0)],Jet_eta[passJet.at(0)],Jet_phi[passJet.at(0)],jetSmearedMass[passJet.at(0)]);
             bjet2.SetPtEtaPhiM(jetSmearedPt[passJet.at(1)],Jet_eta[passJet.at(1)],Jet_phi[passJet.at(1)],jetSmearedMass[passJet.at(1)]);
             double m=(bjet1+bjet2).M();  (m<18) ? m=19 : (m>278) ? m=277 : m=m;
             h_mHAK4->Fill(m,w*Deep_SF_L[Deep_whichSF]);
           }
           if (!isData && AK4AK8>0 && boost==1 && VR==0 && met>3) h_mHAK8->Fill(AK8JetSmearedMass[SelectedAK8Jet],w*DDBvL_SF_L[DDBvL_whichSF]);
           if (!isData && AK4AK8>0 && boost==0 && VR==0 && met>3) h_mHAK4->Fill(m_bb_deep,w*Deep_SF_L[Deep_whichSF]);
     
     //SignalRegion -- not the real SR, but almost
     int SignalRegion=0;
     if (met>3 && AK4AK8!=0) {
       SignalRegion=(met-4)*6+AK4AK8+boost*2+(njet-1)*3;
       if (SignalRegion==15 || SignalRegion==18) SignalRegion=16;
       else if (SignalRegion==16 || SignalRegion==17) SignalRegion=15;
       h_SR->Fill(SignalRegion,w); if (SignalScan) m_SR[mass_pair]->Fill(SignalRegion,w);
       //cout<<"met "<<met<<" njet "<<njet<<" boost "<<boost<<" ak4ak8 "<<AK4AK8<<" SRbin "<<SignalRegion<<endl;
     }
    
     if (SignalScan) {
       m_eff[mass_pair]->Fill(1.,w);
       m_nISR_jet[mass_pair]->Fill(n_isr_jets,w);
       if (nleadPho!=-1) m_phoEt[mass_pair]->Fill(phoET[nleadPho],w);
       if (nleadPho!=-1) m_phoEta[mass_pair]->Fill(Photon_eta[nleadPho],w);
       if (nleadPho!=-1) m_phoPt[mass_pair]->Fill(phoET[nleadPho],w);
       
       m_pfMET[mass_pair]->Fill(MET,w);
       (METsumEt<5000) ? m_pfMETsumEt[mass_pair]->Fill(METsumEt,w) : m_pfMETsumEt[mass_pair]->Fill(4999,w);
       m_pfMETPhi[mass_pair]->Fill(METPhi,w);
       (METSig<1500) ? m_pfMETSig[mass_pair]->Fill(METSig,w) : m_pfMETSig[mass_pair]->Fill(1499,w);
       m_ST[mass_pair]->Fill(ST,w);
       m_ST_G[mass_pair]->Fill(ST_G,w);
       m_MT[mass_pair]->Fill(MT,w);
       m_HT_after[mass_pair]->Fill(HT_after,w);
       m_EMHT_after[mass_pair]->Fill(EMHT_after,w);
       m2_ST_HT[mass_pair]->Fill(ST,HT_after,w);
       m2_ST_MET[mass_pair]->Fill(ST,MET,w);
       m2_MT_MET[mass_pair]->Fill(MT,MET,w);
       m2_MET_HT[mass_pair]->Fill(MET,HT_after,w);
       if (nleadPho!=-1) m2_MET_phoPt[mass_pair]->Fill(MET,phoET[nleadPho],w);
       m2_MET_extrajets[mass_pair]->Fill(MET,nonHiggsJet,w);
       m2_extrajets_HT[mass_pair]->Fill(nonHiggsJet,HT_after,w);
      
       m_nPho[mass_pair]->Fill(nPassPhoL,w);
       m_nEle[mass_pair]->Fill(nPassEleL,w);
       m_nEleM[mass_pair]->Fill(nPassEleM,w);
       m_nEleT[mass_pair]->Fill(nPassEleT,w);
       m_nMu[mass_pair]->Fill(nPassEleL,w);
       m_nMuM[mass_pair]->Fill(nPassMuM,w);
       m_nMuT[mass_pair]->Fill(nPassMuT,w);
       m_nTau[mass_pair]->Fill(nPassTauL,w);
       m_nIso[mass_pair]->Fill(nPassIso,w);
      
       if (nleadEle!=-1) m_ElePt[mass_pair]->Fill(Electron_pt[nleadEle],w);
       if (nleadMu!=-1) m_MuPt[mass_pair]->Fill(Muon_pt[nleadMu],w);
       if (nleadTau!=-1) m_TauPt[mass_pair]->Fill(Tau_pt[nleadTau],w);

       m_njets[mass_pair]->Fill(nPassAK4,w);
       m_nonHjets[mass_pair]->Fill(nonHiggsJet,w);
       if (leadpt_ak4!=-1) m_jetpt[mass_pair]->Fill(Jet_pt_nom[leadpt_ak4],w);
       m_nAK8jets[mass_pair]->Fill(nPassAK8,w);
       if (leadpt_ak8!=-1) m_AK8jetpt[mass_pair]->Fill(FatJet_pt_nom[leadpt_ak8],w);
		  
       
       if (m_bb_deep!=-1) m_mbbjet_select[mass_pair]->Fill(m_bb_deep,w);
       if (DDBvL_selected>0) m_AK8mass_select[mass_pair]->Fill(AK8JetSmearedMass[SelectedAK8Jet],w);
       if (dR_ak4_Hcandidate!=-1) m_dR_ak4_Hcandidate[mass_pair]->Fill(dR_ak4_Hcandidate,w);
       if (pt_ak4_Hcandidate1!=-1) m_pt_ak4_Hcandidate[mass_pair]->Fill(pt_ak4_Hcandidate1,w);
       if (pt_ak4_Hcandidate2!=-1) m_pt_ak4_Hcandidate[mass_pair]->Fill(pt_ak4_Hcandidate2,w);
       if (dphi_met_jet!=999) m_dphi_met_jet[mass_pair]->Fill(dphi_met_jet,w);
       if (dphi_met_jet!=999) m2_dphi_met_jet_nonHjets[mass_pair]->Fill(dphi_met_jet,nonHiggsJet,w);
       for (int i=0;i<8;i++) m2_dphi_met_jet_njet[mass_pair]->Fill(dphi_met_jet_njet[i],i+1,w);
       if (njet==1 && met>3 && VR==0 && AK4AK8>0 && dphi_met_jet!=999 && pt_dphi_jet!=-1) m2_dphi_met_lowjet_pt[mass_pair]->Fill(dphi_met_jet,pt_dphi_jet,w);
       if (njet==2 && met>3 && VR==0 && AK4AK8>0 && dphi_met_jet!=999 && pt_dphi_jet!=-1) m2_dphi_met_highjet_pt[mass_pair]->Fill(dphi_met_jet,pt_dphi_jet,w);
       if (dphi_H_ak8!=999) m_dphi_met_h_ak8[mass_pair]->Fill(dphi_H_ak8,w);
       if (dphi_H_ak4!=999) m_dphi_met_h_ak4[mass_pair]->Fill(dphi_H_ak4,w);
       if (dphi_Hmin_ak4!=999) m_dphi_met_hmin_ak4[mass_pair]->Fill(dphi_Hmin_ak4,w);
       if (dphi_AK4btag!=999) m_dphi_met_ak4btag[mass_pair]->Fill(dphi_AK4btag,w);

       if (signalstudy) {
         if (Higgs_pt!=-1) m_Hpt[mass_pair]->Fill(Higgs_pt,w);
         //m_AK8Hmass[mass_pair]
         if (Hbbmass!=-1) (Hbbmass>270) ? m_Hbbmass[mass_pair]->Fill(270,w) : (Hbbmass<18) ? m_Hbbmass[mass_pair]->Fill(19,w) : m_Hbbmass[mass_pair]->Fill(Hbbmass,w);
         if (genAK4Hmass!=-1) (genAK4Hmass>270) ? m_genAK4Hmass[mass_pair]->Fill(270,w) : (genAK4Hmass<18) ? m_genAK4Hmass[mass_pair]->Fill(19,w) : m_genAK4Hmass[mass_pair]->Fill(genAK4Hmass,w);
         if (AK4Hmass!=-1) (AK4Hmass>270) ? m_AK4Hmass[mass_pair]->Fill(270,w) : (AK4Hmass<18) ? m_AK4Hmass[mass_pair]->Fill(19,w) : m_AK4Hmass[mass_pair]->Fill(AK4Hmass,w);
         if (Higgs_jet_b!=-1) m_AK4Hpt[mass_pair]->Fill(jetSmearedPt[Higgs_jet_b],w);
         if (Higgs_jet_antib!=-1) m_AK4Hpt[mass_pair]->Fill(jetSmearedPt[Higgs_jet_antib],w);
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
           if (dphi_trueH_ak4!=999) m_dphi_met_trueh_ak4[mass_pair]->Fill(dphi_trueH_ak4,w);
           if (dphi_trueHmin_ak4!=999) m_dphi_met_truehmin_ak4[mass_pair]->Fill(dphi_trueHmin_ak4,w);
           if (dphi_trueH_gravitino!=999) m_dphi_trueh_gravitino[mass_pair]->Fill(dphi_trueH_gravitino,w);
         }
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
       if (met>3 && VR==0 && AK4AK8>0) {
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
       if (boost && met>3 && AK4AK8>0) {
         int massRegion = (met-4)*2+njet;
         double m=AK8JetSmearedMass[SelectedAK8Jet]; (m<18) ? m=19 : (m>278) ? m=277 : m=m;
         double m2=AK8JetSmearedMass[passAK8Jet.at(0)]; (m2<18) ? m2=19 : (m2>278) ? m2=277 : m2=m2; //Needed because, in VR there can be passHiggsmass w/o btag AND a btagged jet
         if (VR) m2_mHAK8[mass_pair]->Fill(massRegion,m2,w*DDBvL_SF_L[DDBvL_whichSF]);
         else if (!isData) m2_mHAK8[mass_pair]->Fill(massRegion,m,w*DDBvL_SF_L[DDBvL_whichSF]);
         if (!VR) m2_dphi_met_h_ak8[mass_pair]->Fill(massRegion,dphi_H_ak8,w*DDBvL_SF_L[DDBvL_whichSF]);
       }
       if (!boost && met>3 && AK4AK8>0 && passJet.size()>1) {
         int massRegion = (AK4AK8-1)*4+(met-4)*2+njet;
         double m=m_bb_deep; (m<18) ? m=19 : (m>278) ? m=277 : m=m;
         double wtemp=w*Deep_SF_L[Deep_whichSF]; (AK4AK8==2) ? wtemp*=Deep_SF_L[Deep_whichSF] : wtemp=wtemp;
         TLorentzVector bjet1, bjet2; //Needed because, in VR there can be passHiggsmass w/o btag AND a btagged jet
         bjet1.SetPtEtaPhiM(jetSmearedPt[passJet.at(0)],Jet_eta[passJet.at(0)],Jet_phi[passJet.at(0)],jetSmearedMass[passJet.at(0)]);
         bjet2.SetPtEtaPhiM(jetSmearedPt[passJet.at(1)],Jet_eta[passJet.at(1)],Jet_phi[passJet.at(1)],jetSmearedMass[passJet.at(1)]);
         double m2=(bjet1+bjet2).M(); (m2<18) ? m2=19 : (m2>278) ? m2=277 : m2=m2;
         double dR = deltaR(Jet_phi[SelectedAK4Jet1],Jet_phi[SelectedAK4Jet2],Jet_eta[SelectedAK4Jet1],Jet_eta[SelectedAK4Jet2]);
         double dR2= deltaR(Jet_phi[passJet.at(0)],Jet_phi[passJet.at(1)],Jet_eta[passJet.at(0)],Jet_eta[passJet.at(1)]);
         if (VR) {
           m2_mHAK4[mass_pair]->Fill(massRegion,m2,wtemp);
           m2_dr_VRHiggs[mass_pair]->Fill(massRegion,dR2,wtemp);
           m3_mHAK4_dr_Higgs[mass_pair]->Fill(massRegion,m2,dR2,wtemp);
         }
         else if (!isData) {
           m2_mHAK4[mass_pair]->Fill(massRegion,m,wtemp);
           m2_dr_SRHiggs[mass_pair]->Fill(massRegion,dR,wtemp);
           m3_mHAK4_dr_Higgs[mass_pair]->Fill(massRegion,m,dR,wtemp);
         }
         if (!VR) m2_dphi_met_h_ak4[mass_pair]->Fill(massRegion,dphi_H_ak4,wtemp);
         if (!VR) m2_dphi_met_hmin_ak4[mass_pair]->Fill(massRegion,dphi_Hmin_ak4,wtemp);
         if (!VR) m2_dphi_met_ak4btag[mass_pair]->Fill(massRegion,dphi_AK4btag,wtemp);
       }
       if (VR==1 && boost==1 && AK4AK8>0 && met>3) {
         double m=AK8JetSmearedMass[passAK8Jet.at(0)]; (m<18) ? m=19 : (m>278) ? m=277 : m=m;
         m_mHAK8[mass_pair]->Fill(m,w*DDBvL_SF_L[DDBvL_whichSF]);
       }
       if (VR==1 && boost==0 && passJet.size()>1 && AK4AK8>0 && met>3) {
         TLorentzVector bjet1, bjet2; //Needed because, in VR there can be passHiggsmass w/o btag AND a btagged jet
         bjet1.SetPtEtaPhiM(jetSmearedPt[passJet.at(0)],Jet_eta[passJet.at(0)],Jet_phi[passJet.at(0)],jetSmearedMass[passJet.at(0)]);
         bjet2.SetPtEtaPhiM(jetSmearedPt[passJet.at(1)],Jet_eta[passJet.at(1)],Jet_phi[passJet.at(1)],jetSmearedMass[passJet.at(1)]);
         double m=(bjet1+bjet2).M(); (m<18) ? m=19 : (m>278) ? m=277 : m=m;
         m_mHAK4[mass_pair]->Fill(m,w*Deep_SF_L[Deep_whichSF]);
       }
       if (!isData && AK4AK8>0 && boost==1 && VR==0 && met>3) m_mHAK8[mass_pair]->Fill(AK8JetSmearedMass[SelectedAK8Jet],w*DDBvL_SF_L[DDBvL_whichSF]);
       if (!isData && AK4AK8>0 && boost==0 && VR==0 && met>3) m_mHAK4[mass_pair]->Fill(m_bb_deep,w*Deep_SF_L[Deep_whichSF]);
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
     string temp="CountSignal_"+to_string(year)+".txt";
     counttxt.open (temp);
     if (SignalScenario==1) {
       bool newg=true;
       for (auto i : signal_events) {
         if (newg) counttxt<<"    if (a=="<<i.first.first<<") {\n      switch (b) {"<<endl;
         newg=false;
         counttxt<<"        case "<<i.first.second<<" : return "<<i.second<<";"<<endl;
         if (i.first.first-10==i.first.second) {newg=true; counttxt<<"    }\n  }"<<endl;}
       }
     }
     if (SignalScenario==2) for (auto i : signal_events) counttxt<<"      case "<<i.first.first<<" : return "<<i.second<<";"<<endl;
   }
}
