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
      else if (arg[1]=='c') is_c=1; 
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
   
   //double L_data=35867.06;
   double L_data=101270;
   
   //Btag SF
   BTCalibration calib, calib_fs, calib_deep, calib_deep_fs;;
   BTCalibrationReader reader_L, reader_M, reader_T, reader_L_fs, reader_M_fs, reader_T_fs;
   BTCalibrationReader reader_deep_L, reader_deep_M, reader_deep_T, reader_deep_L_fs, reader_deep_M_fs, reader_deep_T_fs;
   // setup calibration + reader https://twiki.cern.ch/twiki/bin/view/CMS/BTagCalibration#Standalone
   if (btag_file.size()>0){
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

   std::string temp_fname="histos/Analyzer_histos"; 
   if (signalstudy) temp_fname+="_truth";
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

   TH1D *h_phoEtL    = new TH1D("h_phoEtL",";E_{T}^{#gamma_L} [GeV]",10,25,1525);
   TH1D *h_phoEtM    = new TH1D("h_phoEtM",";E_{T}^{#gamma_M} [GeV]",10,25,1525);
   TH1D *h_phoEtT    = new TH1D("h_phoEtT",";E_{T}^{#gamma_T} [GeV]",10,25,1525);
   TH1D *h_phoEtaL    = new TH1D("h_phoEtaL",";#eta^{#gamma_{L}}",30,-3,3);
   TH1D *h_phoEtaM    = new TH1D("h_phoEtaM",";#eta^{#gamma_{M}}",30,-3,3);
   TH1D *h_phoEtaT    = new TH1D("h_phoEtaT",";#eta^{#gamma_{T}}",30,-3,3);
   
   const int nbins_photon=15;
   double xbins_photon[nbins_photon+1]={0,50,120,175,210,260,310,360,410,460,510,650,800,1000,1200,1500};
   TH1D *h_phoPt= new TH1D("h_phoPt",";#gamma{E}_{T} [GeV]",nbins_photon,xbins_photon);
   const int nbins_pfMET=13;
   double xbins_pfMET[nbins_pfMET+1]={0,20,40,70,100,150,200,300,500,700,1000,1500,2000,3000};
   TH1D *h_pfMET    = new TH1D("h_pfMET",";#slash{E}_{T} [GeV]",nbins_pfMET,xbins_pfMET);
   TH1D *h_pfMETsumEt    = new TH1D("h_pfMETsumEt",";#slash{E}_{T} sumEt",20,-50,5000);
   TH1D *h_pfMETPhi    = new TH1D("h_pfMETPhi",";#Phi^{#slash{E}_{T}}",20,-4,4);
   TH1D *h_pfMETSig    = new TH1D("h_pfMETSig",";#slash{E}_{T}Sig",50,0,2000);
   
   const int nbins_ST=13;
   double xbins_ST[nbins_ST+1]={0, 200, 400, 600, 800, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5500};
   TH1D *h_ST    = new TH1D("h_ST",";S_{T} [GeV]",nbins_ST,xbins_ST);
   TH1D *h_ST_G    = new TH1D("h_ST_G",";S_{T}^{#gamma} [GeV]",10,0,2000);
   const int nbins_MT=9;
   double xbins_MT[nbins_MT+1]={0, 30, 60, 100, 130, 200, 500, 1000, 1500, 2000};
   TH1D *h_MT    = new TH1D("h_MT",";M_{T} [GeV]",nbins_MT,xbins_MT);
   TH1D *h_HT_after = new TH1D("h_HT_after","HT after cuts;HT",20,0,5000);
   TH1D *h_EMHT_after = new TH1D("h_EMHT_after","EMHT after cuts;EMHT",20,0,5000);
  
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
   
   TH1D *h_mbbjet_select    = new TH1D("h_mbbjet_select","Invariant mass of selected bjets;M_{bb}[GeV]",10,18,278);
   TH1D *h_AK8mass_select= new TH1D("h_AK8mass_select","PUPPI corrected softdrop mass of selected bjet;m_{AK8jet} [GeV]",20,5,655);
   TH1D *h_dR_ak4_Hcandidate = new TH1D("h_dR_ak4_Hcandidate","dR between H candidate AK4 jets;dR",20,0,5);
   TH1D *h_dphi_met_jet= new TH1D("h_dphi_met_jet",";|#Delta#phi|(MET,nearest jet)",10,0,3.2);

   //AK4 searchbins
   const int dim_ak4=4;
   int nbins_ak4[dim_ak4]={2,3,6,2};
   double xmin_ak4[dim_ak4]={-0.5,-0.5,0.5,0.5};
   double xmax_ak4[dim_ak4]={1.5,2.5,6.5,2.5};
   THnD *hn_AK4searchBins = new THnD("hn_AK4searchBins",";VR;AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
   hn_AK4searchBins->Sumw2();
   unsigned int nsbins_ak4=hn_AK4searchBins->GetNbins();
   TH1D *h_AK4searchBins= new TH1D("h_AK4searchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
   
   //AK8 searchbins
   const int dim_ak8=4;
   int nbins_ak8[dim_ak8]={2,2,6,2};
   double xmin_ak8[dim_ak8]={-0.5,-0.5,0.5,0.5};
   double xmax_ak8[dim_ak8]={1.5,1.5,6.5,2.5};
   THnD *hn_AK8searchBins = new THnD("hn_AK8searchBins",";VR;AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
   hn_AK8searchBins->Sumw2();
   unsigned int nsbins_ak8=hn_AK8searchBins->GetNbins();
   TH1D *h_AK8searchBins= new TH1D("h_AK8searchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
   
   //Histograms for signalstudy
   map<int,vector<int>> grid;
   if (SignalScan) {
     grid=init_scan_histos(f,signalstudy);
   }

   TBenchmark time;
   TDatime now;
   if (!is_quiet) now.Print();
   time.Start("time");
       
   TRandom3 *gen = new TRandom3(0);

   std::map<pair<int,int>,int> signal_events;
   if (CountSignal) signal_events=init_signal_event();
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
       TBranch *b_genEventSumw;
       Double_t sub_TotalEvents=0;
       Runs->SetBranchAddress("genEventSumw",&sub_TotalEvents,&b_genEventSumw);
       for (int i=0; i<Runs->GetEntries();i++) {b_genEventSumw->GetEntry(i); TotalEvents+=sub_TotalEvents;}
       if (Runs->GetBranch("year")) {
         TBranch *b_year;
         Runs->SetBranchAddress("year",&year,&b_year);
         b_year->GetEntry();
       }
       //std::cout<<"Tot = "<<TotalEvents<<std::endl;
       if (xsec_file!="default") {
         ifstream f_xsec; f_xsec.open(xsec_file);
         f_xsec>>xsec;
         cout<<xsec<<endl;
         f_xsec.close();
       }
       else if (!SignalScan) {
         if (Runs->GetBranch("xsec")) {
           TBranch *b_xsec;
           Runs->SetBranchAddress("xsec",&xsec,&b_xsec);
           b_xsec->GetEntry();
         }
         else std::cout<<"No xsec found. Using xsec = "<<xsec<<std::endl;
       }
     }
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
       b_Jet_pt_jerUp->GetEntry(ientry);
       b_Jet_pt_jerDown->GetEntry(ientry);
       b_Jet_pt_jesTotalUp->GetEntry(ientry);
       b_Jet_pt_jesTotalDown->GetEntry(ientry);
       b_Jet_hadronFlavour->GetEntry(ientry);
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
     if (!SignalScan && !isData) b_L1PreFiringWeight_Dn->GetEntry(ientry);
     if (!SignalScan && !isData) b_L1PreFiringWeight_Nom->GetEntry(ientry);
     if (!SignalScan && !isData) b_L1PreFiringWeight_Up->GetEntry(ientry);
     b_luminosityBlock->GetEntry(ientry);
     b_PV_npvsGood->GetEntry(ientry);
     b_PV_npvs->GetEntry(ientry);
     if (!SignalScan) {
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
     b_Flag_eeBadScFilter->GetEntry(ientry);
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
     b_nPhoton->GetEntry(ientry);
     b_Photon_pt->GetEntry(ientry);
     b_Photon_eCorr->GetEntry(ientry);
     b_Photon_eta->GetEntry(ientry);
     b_Photon_phi->GetEntry(ientry);
     b_Photon_r9->GetEntry(ientry);
     b_Photon_pixelSeed->GetEntry(ientry);
     b_Photon_electronVeto->GetEntry(ientry);
     b_Photon_hoe->GetEntry(ientry);
     b_Photon_isScEtaEB->GetEntry(ientry);
     b_Photon_isScEtaEE->GetEntry(ientry);
     if (year==2016) b_Photon_cutBased17Bitmap->GetEntry(ientry);
     else b_Photon_cutBasedV1Bitmap->GetEntry(ientry);
     Int_t Photon_cutBased_versionFree[99]; for (unsigned int i=0; i<nPhoton;i++) (year==2016) ? Photon_cutBased_versionFree[i]=Photon_cutBased17Bitmap[i] : Photon_cutBased_versionFree[i]=Photon_cutBasedV1Bitmap[i];
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
     b_nJet->GetEntry(ientry);
     b_Jet_pt->GetEntry(ientry);
     b_Jet_pt_nom->GetEntry(ientry);
     b_Jet_pt_raw->GetEntry(ientry);
     b_Jet_phi->GetEntry(ientry);
     b_Jet_eta->GetEntry(ientry);
     b_Jet_mass->GetEntry(ientry);
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
       int neutralino=-1, gluino=-1;
       for (unsigned int i=0;i<nGenPart;i++) {
         if (GenPart_pdgId[i]==1000023 && GenPart_status[i]==22) neutralino=i;
         if (GenPart_pdgId[i]==1000021 && GenPart_status[i]==22) gluino=i;
       }
       int m_Gluino = GenPart_mass[gluino];
       //Neutralino/gluino mass is not exact. Need to find nearest grid point
       double m_Neutralino=GenPart_mass[neutralino];
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
       if (SignalScan) {xsec=get_cross_section(mass_pair.first); TotalEvents=get_total_events(mass_pair,year);}
     //weights
       double pu_weight=puWeight;
       if (_fastSim || SignalScan) pu_weight=1;
       double weight=L_data*xsec*genWeight/TotalEvents;
       //if (newfile) std::cout<<"weight=L_data*genWeight*xsec/TotalEvents "<<weight<<"="<<L_data<<"*"<<genWeight<<"*"<<xsec<<"/"<<TotalEvents<<std::endl;
       w=weight*pu_weight;
       //std::cout<<"event "<<event<<" w=weight*pu_weight"<<w<<"="<<weight<<"("<<L_data<<"*"<<genWeight<<"*"<<xsec<<"/"<<TotalEvents<<")"<<"*"<<pu_weight<<std::endl;
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
       }
     }

     //ISR jet counting (https://github.com/manuelfs/babymaker/blob/0136340602ee28caab14e3f6b064d1db81544a0a/bmaker/plugins/bmaker_full.cc#L1268-L1295)
     int n_isr_jets=0;
     if (!isData) {
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
           if (!Photon_isScEtaEB || !Photon_isScEtaEE || Photon_pixelSeed[j]!=0 || Photon_pt[j]<40 || (Photon_cutBased_versionFree[i]&1)==0) continue;
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
             if (!(GenPart_statusFlags[k]&int(pow(2,13)))) continue;
             if (deltaR(GenPart_phi[k],Jet_phi[i],GenPart_eta[k],Jet_eta[i])<0.3) {matched=true; 
             //  printf("Index %-2i PDGID %-8d mcPt %-12f Eta %-9f Phi %-9f mom %-8d momPt %-9f  momEta %-9f  momPhi %-9f status %-2i flag %-9s gmom %-8d\n",k,GenPart_pdgId[k],GenPart_pt[k],GenPart_eta[k],GenPart_phi[k],GenPart_pdgId[GenPart_genPartIdxMother[k]],GenPart_pt[GenPart_genPartIdxMother[k]],GenPart_eta[GenPart_genPartIdxMother[k]],GenPart_phi[GenPart_genPartIdxMother[k]],GenPart_status[k],bitset<9>(GenPart_statusFlags[k]).to_string().c_str(),GenPart_pdgId[GenPart_genPartIdxMother[GenPart_genPartIdxMother[k]]]);
             break;}
           }
         }
         if (!matched) n_isr_jets++;
       }
     }

     //object definitions
     int leadpt_ak4=-1, leadpt_ak8=-1, highDDBvL=-1;
     vector<int> passPhoL, passPhoM, passPhoT, passJet, passAK8Jet, passEleV, passEleL, passEleM, passEleT, passMuL, passMuM, passMuT, passMuNO;
     vector<int> passTauL, passTauM, passTauT, passIso;
     vector<int> passElePhoL, passElePhoM, passElePhoT, passEleNO;
     vector<int> passFREleL, passFREleM, passFREleT;
     vector<float> jetSmearedPt, jetSmearedEn, AK8JetSmearedPt, AK8JetSmearedEn;
     map<int,char> passDDBvL, passDeep;
     HT_before=0; EMHT_before=0; HT_after=0; EMHT_after=0;
     AK8HT_before=0; AK8EMHT_before=0; AK8HT_after=0; AK8EMHT_after=0;
     ST=0; ST_G=0; MT=0; nonHiggsJet=-1;
     nleadElePhoL=-1; nleadElePhoM=-1; nleadElePhoT=-1;
     nleadFREleL=-1; nleadFREleM=-1; nleadFREleT=-1;
     nleadPhoL=-1; nleadPhoM=-1; nleadPhoT=-1;
     nleadEleV=-1; nleadEleL=-1; nleadEleM=-1; nleadEleT=-1, nleadEleNO=-1;
     nleadMuL=-1; nleadMuM=-1; nleadMuT=-1, nleadMuNO=-1;
     nleadTauL=-1; nleadTauM=-1; nleadTauT=-1; nleadIso=-1;
     ele_VETOSF=1; mu_VETOSF=1;
     for (int i=0;i<3;i++) {pho_SF[i]=1; mu_SF[i]=1;}
     for (int i=0;i<4;i++) ele_SF[i]=1;
     memset(bcounterDDBvL,0,sizeof bcounterDDBvL);
     memset(bcounterDeep,0,sizeof bcounterDeep);
     double nonPrefiringProbability[3]={1,1,1};
     if (!SignalScan) nonPrefiringProbability[0]=L1PreFiringWeight_Nom;nonPrefiringProbability[1]=L1PreFiringWeight_Up;nonPrefiringProbability[2]=L1PreFiringWeight_Dn;
     phoET.clear();
     //photon
     for (unsigned int i=0;i<nPhoton;i++){
       //Systematics for Egamma scaling
       double correction = 1;
       /*
       (Egamma_Statscale_whichSF==1) ? correction*=(*phoScale_stat_up)[i] : (Egamma_Statscale_whichSF==2) ? correction*=(*phoScale_stat_dn)[i] : correction=correction;
       (Egamma_Systscale_whichSF==1) ? correction*=(*phoScale_syst_up)[i] : (Egamma_Systscale_whichSF==2) ? correction*=(*phoScale_syst_dn)[i] : correction=correction;
       (Egamma_Gainscale_whichSF==1) ? correction*=(*phoScale_gain_up)[i] : (Egamma_Gainscale_whichSF==2) ? correction*=(*phoScale_gain_dn)[i] : correction=correction;
       (Egamma_Rhoresol_whichSF==1) ? correction*=gen->Gaus(1,(*phoResol_rho_up)[i]) : (Egamma_Rhoresol_whichSF==2) ? correction*=gen->Gaus(1,(*phoResol_rho_dn)[i]) : correction=correction;
       (Egamma_Phiresol_whichSF==1) ? correction*=gen->Gaus(1,(*phoResol_phi_up)[i]) : correction=correction;
       */
       phoET.push_back(Photon_pt[i]*correction);
       //L1prefire correction
       if (SignalScan && year!=2018 && Photon_pt[i]>20 && abs(Photon_eta[i])>2 && abs(Photon_eta[i])<3) {
         double max= h_L1prefire_phoMap->GetYaxis()->GetBinLowEdge(h_L1prefire_phoMap->GetNbinsY());
         double pt = (Photon_pt[i]>max) ? max-0.01 : Photon_pt[i];
         double prefireProb = h_L1prefire_phoMap->GetBinContent(h_L1prefire_phoMap->FindBin(Photon_eta[i],pt));
         double stat = h_L1prefire_phoMap->GetBinError(h_L1prefire_phoMap->FindBin(Photon_eta[i],pt));
         double syst = prefireProb*0.2;
         nonPrefiringProbability[0]*=(1-prefireProb);
         nonPrefiringProbability[1]*=(1-std::min(1.,prefireProb+sqrt(pow(stat,2)+pow(syst,2))));
         nonPrefiringProbability[2]*=(1-std::max(0.,prefireProb-sqrt(pow(stat,2)+pow(syst,2))));
       }
       if ((Photon_isScEtaEB || Photon_isScEtaEE) && Photon_pixelSeed[i]==0 && phoET[i]>40) {
        if (Photon_cutBased_versionFree[i]>0) {
         passPhoL.push_back(i);
        }
        if (Photon_cutBased_versionFree[i]>>1&1) {
         passPhoM.push_back(i);
        }
        if (Photon_cutBased_versionFree[i]>>2&1) {
         passPhoT.push_back(i);
        }
       }
       if ((Photon_isScEtaEB || Photon_isScEtaEE) && Photon_pixelSeed[i]!=0) {
        if (Photon_cutBased_versionFree[i]>>0&1) {
         passElePhoL.push_back(i);
        }
        if (Photon_cutBased_versionFree[i]>>1&1) {
         passElePhoM.push_back(i);
        }
        if (Photon_cutBased_versionFree[i]>>2&1) {
         passElePhoT.push_back(i);
        }
       }
     }
     for (auto i : passPhoL) {
       if (phoET[i]>phoET[nleadPhoL]) nleadPhoL=i;
       EMHT_before+=phoET[i];
     }
     for (auto i : passPhoM) if (phoET[i]>phoET[nleadPhoM]) nleadPhoM=i;
     for (auto i : passPhoT) if (phoET[i]>phoET[nleadPhoT]) nleadPhoT=i;
     for (auto i : passElePhoL) if (phoET[i]>phoET[nleadElePhoL]) nleadElePhoL=i;
     for (auto i : passElePhoM) if (phoET[i]>phoET[nleadElePhoM]) nleadElePhoM=i;
     for (auto i : passElePhoT) if (phoET[i]>phoET[nleadElePhoT]) nleadElePhoT=i;
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
       double id_sf=0, pix_sf=0, syst_id=0, syst_pix=0;
       int sign_id=0, sign_pix=0;
       if (nPassPhoL!=0){
         id_sf=h_pho_EGamma_SF2D[0]->GetBinContent(h_pho_EGamma_SF2D[0]->FindBin(Photon_eta[nleadPhoL],phoET[nleadPhoL]));
         syst_id=h_pho_EGamma_SF2D[0]->GetBinError(h_pho_EGamma_SF2D[0]->FindBin(Photon_eta[nleadPhoL],phoET[nleadPhoL]));
         if (Photon_r9[nleadPhoL]>0.94) {
           pix_sf=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs(Photon_eta[nleadPhoL]),100));
           syst_pix=h_Scaling_Factors_HasPix_R9_high->GetBinError(h_Scaling_Factors_HasPix_R9_high->FindBin(abs(Photon_eta[nleadPhoL]),100));
         }
         else {
           pix_sf=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs(Photon_eta[nleadPhoL]),100));
           syst_pix=h_Scaling_Factors_HasPix_R9_low->GetBinError(h_Scaling_Factors_HasPix_R9_low->FindBin(abs(Photon_eta[nleadPhoL]),100));
         }
         (phoID_whichSF==1) ? sign_id=1 : (phoID_whichSF==2) ? sign_id=-1 : sign_id=0;
         (phoPix_whichSF==1) ? sign_pix=1 : (phoPix_whichSF==2) ? sign_pix=-1 : sign_pix=0;
         pho_SF[0]=(id_sf+sign_id*syst_id)*(pix_sf+sign_pix*syst_pix);
       }
       if (nPassPhoM!=0){
         id_sf=h_pho_EGamma_SF2D[1]->GetBinContent(h_pho_EGamma_SF2D[1]->FindBin(Photon_eta[passPhoM[0]],phoET[passPhoM[0]]));
         syst_id=h_pho_EGamma_SF2D[1]->GetBinContent(h_pho_EGamma_SF2D[1]->FindBin(Photon_eta[passPhoM[0]],phoET[passPhoM[0]]));
         if (Photon_r9[passPhoM[0]]>0.94) {
           pix_sf=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs(Photon_eta[passPhoM[0]]),100));
           syst_pix=h_Scaling_Factors_HasPix_R9_high->GetBinError(h_Scaling_Factors_HasPix_R9_high->FindBin(abs(Photon_eta[passPhoM[0]]),100));
         }
         else {
           pix_sf=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs(Photon_eta[passPhoM[0]]),100));
           syst_pix=h_Scaling_Factors_HasPix_R9_low->GetBinError(h_Scaling_Factors_HasPix_R9_low->FindBin(abs(Photon_eta[passPhoM[0]]),100));
         }
         (phoID_whichSF==1) ? sign_id=1 : (phoID_whichSF==2) ? sign_id=-1 : sign_id=0;
         (phoPix_whichSF==1) ? sign_pix=1 : (phoPix_whichSF==2) ? sign_pix=-1 : sign_pix=0;
         pho_SF[1]=(id_sf+sign_id*syst_id)*(pix_sf+sign_pix*syst_pix);
       }
       if (nPassPhoT!=0){
         id_sf=h_pho_EGamma_SF2D[2]->GetBinContent(h_pho_EGamma_SF2D[2]->FindBin(Photon_eta[passPhoT[0]],phoET[passPhoT[0]]));
         syst_id=h_pho_EGamma_SF2D[2]->GetBinError(h_pho_EGamma_SF2D[2]->FindBin(Photon_eta[passPhoT[0]],phoET[passPhoT[0]]));
         if (Photon_r9[passPhoT[0]]>0.94) {
           pix_sf=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs(Photon_eta[passPhoT[0]]),100));
           syst_pix=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs(Photon_eta[passPhoT[0]]),100));
         }
         else {
           pix_sf=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs(Photon_eta[passPhoT[0]]),100));
           syst_pix=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs(Photon_eta[passPhoT[0]]),100));
         }
         (phoID_whichSF==1) ? sign_id=1 : (phoID_whichSF==2) ? sign_id=-1 : sign_id=0;
         (phoPix_whichSF==1) ? sign_pix=1 : (phoPix_whichSF==2) ? sign_pix=-1 : sign_pix=0;
         pho_SF[2]=(id_sf+sign_id*syst_id)*(pix_sf+sign_pix*syst_pix);
       }
     }
     //electron
     for (unsigned int i=0;i<nElectron;i++) {
       bool passOverlap=true;
         for (auto j : passPhoL) if (deltaR(Electron_phi[i],Photon_phi[j],Electron_eta[i],Photon_eta[j])<0.3) {
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
     nPassEleV=passEleV.size();
     nPassEleL=passEleL.size();
     nPassEleM=passEleM.size();
     nPassEleT=passEleT.size();
     nPassEleNO=passEleNO.size();
     if (nPassEleV != 0) nleadEleV=passEleV[0];
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
         if (abs(Electron_eta[nleadFREleL])>1.4442) continue;
         w*=h2_FR->GetBinContent(h2_FR->FindBin(Electron_eta[nleadFREleL],Electron_phi[nleadFREleL]));
       }
       if (_fakeRate==2 && nPassElePhoL != 0) {
         if (!Photon_isScEtaEB || !Photon_isScEtaEE) continue;
         double FRetaphi=h2_FR->GetBinContent(h2_FR->FindBin(Photon_eta[nleadElePhoL],Photon_phi[nleadElePhoL]));
         double FRvalue=FRetaphi*_C*(_A*PV_npvsGood+_B);
         //cout<<"etaphi "<<Photon_eta[nleadElePhoL]<<" "<<Photon_phi[nleadElePhoL]<<endl;
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
       if (nPassEleV!=0){
         double pt=Electron_pt[passEleV[0]], pt2=Electron_pt[passEleV[0]];
         pt=(pt<450) ? pt : 450; pt=(pt>10) ? pt : 10; pt2=(pt>30) ? pt : 31;
         id_sf=h_ele_EGamma_SF2D[0]->GetBinContent(h_ele_EGamma_SF2D[1]->FindBin(Electron_eta[passEleV[0]],pt));
         syst_id=h_ele_EGamma_SF2D[0]->GetBinError(h_ele_EGamma_SF2D[1]->FindBin(Electron_eta[passEleV[0]],pt));
         rec_sf=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin(Electron_eta[passEleV[0]],pt2));
         syst_rec=h_eleRec_EGamma_SF2D->GetBinError(h_eleRec_EGamma_SF2D->FindBin(Electron_eta[passEleV[0]],pt2));
         ele_SF[0]=(id_sf+sign_id*syst_id)*(rec_sf+sign_rec*syst_rec);
         //cout<<"id_sf "<<id_sf<<"*"<<rec_sf<<"="<<id_sf*rec_sf<<" +- "<<syst_id<<" "<<syst_rec<<" finalSF= "<<ele_SF[0]<<endl;
       }
       if (nPassEleL!=0){
         double pt=Electron_pt[passEleL[0]], pt2=Electron_pt[passEleL[0]];
         pt=(pt<450) ? pt : 450; pt=(pt>10) ? pt : 10; pt2=(pt>30) ? pt : 31;
         id_sf=h_ele_EGamma_SF2D[1]->GetBinContent(h_ele_EGamma_SF2D[1]->FindBin(Electron_eta[passEleL[0]],pt));
         syst_id=h_ele_EGamma_SF2D[1]->GetBinError(h_ele_EGamma_SF2D[1]->FindBin(Electron_eta[passEleL[0]],pt));
         rec_sf=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin(Electron_eta[passEleL[0]],pt2));
         syst_rec=h_eleRec_EGamma_SF2D->GetBinError(h_eleRec_EGamma_SF2D->FindBin(Electron_eta[passEleL[0]],pt2));
         ele_SF[1]=(id_sf+sign_id*syst_id)*(rec_sf+sign_rec*syst_rec);
       }
       if (nPassEleM!=0){
         double pt=Electron_pt[passEleM[0]], pt2=Electron_pt[passEleM[0]];
         pt=(pt<450) ? pt : 450; pt=(pt>10) ? pt : 10; pt2=(pt>30) ? pt : 31;
         id_sf=h_ele_EGamma_SF2D[2]->GetBinContent(h_ele_EGamma_SF2D[2]->FindBin(Electron_eta[passEleM[0]],pt));
         syst_id=h_ele_EGamma_SF2D[2]->GetBinError(h_ele_EGamma_SF2D[2]->FindBin(Electron_eta[passEleM[0]],pt));
         rec_sf=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin(Electron_eta[passEleM[0]],pt2));
         syst_rec=h_eleRec_EGamma_SF2D->GetBinError(h_eleRec_EGamma_SF2D->FindBin(Electron_eta[passEleM[0]],pt2));
         ele_SF[2]=(id_sf+sign_id*syst_id)*(rec_sf+sign_rec*syst_rec);
       }
       if (nPassEleT!=0){
         double pt=Electron_pt[passEleT[0]], pt2=Electron_pt[passEleT[0]];
         pt=(pt<450) ? pt : 450; pt=(pt>10) ? pt : 10; pt2=(pt>30) ? pt : 31;
         id_sf=h_ele_EGamma_SF2D[3]->GetBinContent(h_ele_EGamma_SF2D[3]->FindBin(Electron_eta[passEleT[0]],pt));
         syst_id=h_ele_EGamma_SF2D[3]->GetBinError(h_ele_EGamma_SF2D[3]->FindBin(Electron_eta[passEleT[0]],pt));
         rec_sf=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin(Electron_eta[passEleT[0]],pt2));
         syst_rec=h_eleRec_EGamma_SF2D->GetBinError(h_eleRec_EGamma_SF2D->FindBin(Electron_eta[passEleT[0]],pt2));
         ele_SF[3]=(id_sf+sign_id*syst_id)*(rec_sf+sign_rec*syst_rec);
       }
       if (nPassEleNO!=0){ //only for loose electrons so far
         double pt=Electron_pt[passEleNO[0]];//, pt2=Electron_pt[passEleNO[0]];
         pt=(pt<450) ? pt : 450; pt=(pt>10) ? pt : 10;// pt2=(pt>30) ? pt : 31;
         double epsilon=h_ele_EGamma_EffMC2D[1]->GetBinContent(h_ele_EGamma_EffMC2D[1]->FindBin(Electron_eta[passEleNO[0]],pt));
         id_sf=h_ele_EGamma_SF2D[1]->GetBinContent(h_ele_EGamma_SF2D[1]->FindBin(Electron_eta[passEleNO[0]],pt));
         syst_id=h_ele_EGamma_SF2D[1]->GetBinError(h_ele_EGamma_SF2D[1]->FindBin(Electron_eta[passEleNO[0]],pt));
         ele_VETOSF = (1-(id_sf+sign_id*syst_id)*epsilon)/(1-epsilon);
       }
     }
     //muon
     for (unsigned int i=0;i<nMuon;i++) {
       bool passOverlap=true;
       for (auto j : passPhoL) if (deltaR(Muon_phi[i],Photon_phi[j],Muon_eta[i],Photon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passEleL) if (deltaR(Muon_phi[i],Electron_phi[j],Muon_eta[i],Electron_eta[j])<0.3) {
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
           float pt = ( Muon_pt[iter[i]]< 20)? 20 : (Muon_pt[iter[i]]< 100) ? Muon_pt[iter[i]] : 100 ; //Histo range is: 20-120, highest bin 60-120
           double id_sf=0, iso_sf=0, syst_id=0, syst_iso=0;
           int sign_id=0, sign_iso=0;
           id_sf=h_muID_SF2D[i]->GetBinContent(h_muID_SF2D[i]->FindBin(pt,abs(Muon_eta[iter[i]])));
           syst_id=h_muID_SF2D[i]->GetBinError(h_muID_SF2D[i]->FindBin(pt,abs(Muon_eta[iter[i]])));
           iso_sf=h_muISO_SF2D[i]->GetBinContent(h_muISO_SF2D[i]->FindBin(pt,abs(Muon_eta[iter[i]])));
           syst_iso=h_muISO_SF2D[i]->GetBinError(h_muISO_SF2D[i]->FindBin(pt,abs(Muon_eta[iter[i]])));
           (muID_whichSF==1) ? sign_id=1 : (muID_whichSF==2) ? sign_id=-1 : sign_id=0;
           (muISO_whichSF==1) ? sign_iso=1 : (muISO_whichSF==2) ? sign_iso=-1 : sign_iso=0;
           mu_SF[i]=(id_sf+sign_id*syst_id)*(iso_sf+sign_iso*syst_iso);
           double *y = h_muTrk_SF->GetY(); double *x = h_muTrk_SF->GetX(); int whichx=0;
           for (int j=0;;j++) {
             double xdo=h_muTrk_SF->GetErrorXlow(j); double xup=h_muTrk_SF->GetErrorXhigh(j);
             if (Muon_eta[iter[i]] >= (x[j]-xdo) && Muon_eta[iter[i]] <= (x[j]+xup)) {whichx=j;break;}
           }
           mu_SF[i]*=y[whichx];
         }
       }
       //muon vetoSF (only for vetoing loose muons)
       if (nPassMuNO>0) {
         int i=passMuNO.at(0);
         float pt = ( Muon_pt[i]< 20)? 20 : (Muon_pt[i]< 100) ? Muon_pt[i] : 100 ; //Histo range is: 20-120, highest bin 60-120
         double epsilon=h_muID_EffMC2D[0]->GetBinContent(h_muID_EffMC2D[0]->FindBin(pt,abs(Muon_eta[i])));
         double sf=h_muID_SF2D[0]->GetBinContent(h_muID_SF2D[0]->FindBin(pt,abs(Muon_eta[i])));
         mu_VETOSF = (1-sf*epsilon)/(1-epsilon);
       }
     }

     //Tau
     for (unsigned int i=0;i<nTau;i++) {
       bool passOverlap=true;
       for (auto j : passPhoL) if (deltaR(Tau_phi[i],Photon_phi[j],Tau_eta[i],Photon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passEleL) if (deltaR(Tau_phi[i],Electron_phi[j],Tau_eta[i],Electron_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passMuL) if (deltaR(Tau_phi[i],Muon_phi[j],Tau_eta[i],Muon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
       if (Tau_pt[i]>tau_pt && abs(Tau_eta[i])<2.3) {
         if (Tau_idMVAoldDM2017v2[i]>>2&1) passTauL.push_back(i);
         if (Tau_idMVAoldDM2017v2[i]>>3&1) passTauM.push_back(i);
         if (Tau_idMVAoldDM2017v2[i]>>4&1) passTauT.push_back(i);
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
     
     //Tau SF uncertainty
     if (!isData) for (unsigned int i=0;i<3;i++) (tau_whichSF==1) ? tau_SF[i]+=0.05 : (tau_whichSF==2) ? tau_SF[i]-=0.05 : tau_SF[i]+=0;

     //IsoTrack
     for (unsigned int i=0;i<nIsoTrack;i++) {
       bool passOverlap=true;
       for (auto j : passPhoL) if (deltaR(IsoTrack_phi[i],Photon_phi[j],IsoTrack_eta[i],Photon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passEleL) if (deltaR(IsoTrack_phi[i],Electron_phi[j],IsoTrack_eta[i],Electron_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passMuL) if (deltaR(IsoTrack_phi[i],Muon_phi[j],IsoTrack_eta[i],Muon_eta[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passTauL) if (deltaR(IsoTrack_phi[i],Tau_phi[j],IsoTrack_eta[i],Tau_eta[j])<0.3) {
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
       if (SignalScan && year!=2018 && Jet_pt[i]>20 && abs(Jet_eta[i])>2 && abs(Jet_eta[i])<3) {
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
       double jetpt=Jet_pt_nom[i];
       if (!isData) {
         if (AK4Smear_whichSF==1) jetpt=Jet_pt_jerUp[i];
         else if (AK4Smear_whichSF==2) jetpt=Jet_pt_jerDown[i];
         if (AK4jetJEC_whichSF==1) jetpt=Jet_pt_jesTotalUp[i];
         else if (AK4jetJEC_whichSF==2) jetpt=Jet_pt_jesTotalDown[i];
       }
       jetSmearedPt.push_back(jetpt);
       HT_before+=jetSmearedPt[i];
       if (abs(Jet_eta[i])>2.4 || !(Jet_jetId[i]>>1&1) || jetSmearedPt[i]<30 || !(Jet_puId[i]&(1<<2))) passcut=false;
       for (auto j : passPhoL) if (deltaR(Jet_phi[i],Photon_phi[j],Jet_eta[i],Photon_eta[j])<0.4) {
         passcut=false;break;
       }
       for (auto j : passEleL) if (deltaR(Jet_phi[i],Electron_phi[j],Jet_eta[i],Electron_eta[j])<0.4) {
         passcut=false;break;
       }
       for (auto j : passMuL) if (deltaR(Jet_phi[i],Muon_phi[j],Jet_eta[i],Muon_eta[j])<0.4) {
         passcut=false;break;
       }
       for (auto j : passTauL) if (deltaR(Jet_phi[i],Tau_phi[j],Jet_eta[i],Tau_eta[j])<0.4) {
         passcut=false;break;
       }
       //for (auto j : passIso) if (deltaR(Jet_phi[i],IsoTrack_phi[j],Jet_eta[i],IsoTrack_eta[j])<0.4) {
       //  passcut=false;break;
       //}
       if (_fastSim && passcut && Jet_chHEF[i]<0.1) {
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
     int BtagWP_chooser=(year==2016) ? 0 : (year==2017) ? 1 : 2;
     for (auto i : passJet) {
       if (jetSmearedPt[i]>jetSmearedPt[leadpt_ak4]) leadpt_ak4=i;
       HT_after+=jetSmearedPt[i];
       if (Jet_btagDeepFlavB[i]>BtagDeepWP[BtagWP_chooser][2]) {passDeep.insert(pair<int,char>(i,'T'));bcounterDeep[3]++;}
       else if (Jet_btagDeepFlavB[i]>BtagDeepWP[BtagWP_chooser][1]) {passDeep.insert(pair<int,char>(i,'M'));bcounterDeep[2]++;}
       else if (Jet_btagDeepFlavB[i]>BtagDeepWP[BtagWP_chooser][0]) {passDeep.insert(pair<int,char>(i,'L'));bcounterDeep[1]++;}
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
       double jetpt=FatJet_pt_nom[i];
       if (!isData) {
         if (AK8Smear_whichSF==1) jetpt=FatJet_pt_jerUp[i];
         else if (AK8Smear_whichSF==2) jetpt=FatJet_pt_jerDown[i];
         if (AK8jetJEC_whichSF==1) jetpt=FatJet_pt_jesTotalUp[i];
         else if (AK8jetJEC_whichSF==2) jetpt=FatJet_pt_jesTotalDown[i];
       }
       AK8JetSmearedPt.push_back(jetpt);
       AK8HT_before+=AK8JetSmearedPt[i];
       if (abs(FatJet_eta[i])>2.4 || !(FatJet_jetId[i]>>1&1) || AK8JetSmearedPt[i]<300) passcut=false;
       for (auto j : passPhoL) if (deltaR(FatJet_phi[i],Photon_phi[j],FatJet_eta[i],Photon_eta[j])<0.8) {
         passcut=false;break;
       }
       for (auto j : passEleL) if (deltaR(FatJet_phi[i],Electron_phi[j],FatJet_eta[i],Electron_eta[j])<0.8) {
         passcut=false;break;
       }
       for (auto j : passMuL) if (deltaR(FatJet_phi[i],Muon_phi[j],FatJet_eta[i],Muon_eta[j])<0.8) {
         passcut=false;break;
       }
       for (auto j : passTauL) if (deltaR(FatJet_phi[i],Tau_phi[j],FatJet_eta[i],Tau_eta[j])<0.8) {
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
       if (FatJet_btagDDBvL[i]>BtagDDBvLWP[BtagWP_chooser][3]) {passDDBvL.insert(pair<int,char>(i,'T'));bcounterDDBvL[4]++;}
       else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[BtagWP_chooser][2]) {passDDBvL.insert(pair<int,char>(i,'H'));bcounterDDBvL[3]++;}
       else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[BtagWP_chooser][1]) {passDDBvL.insert(pair<int,char>(i,'M'));bcounterDDBvL[2]++;}
       else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[BtagWP_chooser][0]) {passDDBvL.insert(pair<int,char>(i,'L'));bcounterDDBvL[1]++;}
       else {passDDBvL.insert(pair<int,char>(i,'0'));bcounterDDBvL[0]++;}
     }
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
     //cout<<"njet "<<nJet<<" nGenJet "<<nGenJet;
     //for (unsigned int i=0;i<nJet;i++) cout<<" idx "<<Jet_genJetIdx[i];
     //cout<<endl;

     //MET variables
     for (auto i : passPhoL) ST+=phoET[i];
     (!isData && genMET_whichSF==1) ? MET=GenMET_pt : MET=MET;
     double METPhi=0, METsumEt=0, METSig=0;
     if (year!=2017) {
       MET=MET_pt_nom; METPhi=MET_phi_nom; METsumEt=MET_sumEt; METSig=MET_significance;
       if (metJER_whichSF==1) {MET=MET_pt_jerUp; METPhi=MET_phi_jerUp;}
       else if (metJER_whichSF==2) {MET=MET_pt_jerDown; METPhi=MET_phi_jerDown;}
       if (metJES_whichSF==1) {MET=MET_pt_jesTotalUp; METPhi=MET_phi_jesTotalUp;}
       else if (metJES_whichSF==2) {MET=MET_pt_jesTotalDown; METPhi=MET_phi_jesTotalDown;}
       if (metUES_whichSF==1) {MET=MET_pt_unclustEnUp; METPhi=MET_phi_unclustEnUp;}
       else if (metUES_whichSF==2) {MET=MET_pt_unclustEnDown; METPhi=MET_phi_unclustEnDown;}
     }
     else {
       MET=METFixEE2017_pt_nom; METPhi=METFixEE2017_phi_nom; METsumEt=METFixEE2017_sumEt; METSig=METFixEE2017_significance;
       if (metJER_whichSF==1) {MET=METFixEE2017_pt_jerUp; METPhi=METFixEE2017_phi_jerUp;}
       else if (metJER_whichSF==2) {MET=METFixEE2017_pt_jerDown; METPhi=METFixEE2017_phi_jerDown;}
       if (metJES_whichSF==1) {MET=METFixEE2017_pt_jesTotalUp; METPhi=METFixEE2017_phi_jesTotalUp;}
       else if (metJES_whichSF==2) {MET=METFixEE2017_pt_jesTotalDown; METPhi=METFixEE2017_phi_jesTotalDown;}
       if (metUES_whichSF==1) {MET=METFixEE2017_pt_unclustEnUp; METPhi=METFixEE2017_phi_unclustEnUp;}
       else if (metUES_whichSF==2) {MET=METFixEE2017_pt_unclustEnDown; METPhi=METFixEE2017_phi_unclustEnDown;}
     }
     ST+=MET;
     ST_G=ST;
     for (auto i : passJet) ST+=jetSmearedPt[i];
     if (passPhoL.size()>0) {
       double dphi_MT=(Photon_phi[nleadPhoL]-METPhi)>M_PI ? 2*M_PI-(METPhi-Photon_phi[nleadPhoL]) : Photon_phi[nleadPhoL]-METPhi;
       MT=sqrt(2*MET*phoET[nleadPhoL]*(1-cos(abs(dphi_MT))));
     }
     if (_fakeRate) {
       if (_fakeRate==1 && nPassFREleL != 0) {
         double dphi_MT=(Electron_phi[nleadFREleL]-METPhi)>M_PI ? 2*M_PI-(METPhi-Electron_phi[nleadFREleL]) : Electron_phi[nleadFREleL]-METPhi;
         MT=sqrt(2*MET*Electron_pt[nleadFREleL]*(1-cos(abs(dphi_MT))));
       }
     }
     dphi_met_jet=999;
     for (auto i : passJet) {
       if (jetSmearedPt[i]<100) continue;
       double dphi=(Jet_phi[i]-METPhi>M_PI) ? 2*M_PI-abs(METPhi-Jet_phi[i]) : Jet_phi[i]-METPhi;
       if (abs(dphi)<dphi_met_jet) dphi_met_jet=abs(dphi);
     }
     double dphi_pho=999;
     for (auto i : passPhoL) {
       double dphi=(Photon_phi[i]-METPhi>M_PI) ? 2*M_PI-abs(METPhi-Photon_phi[i]) : Photon_phi[i]-METPhi;
       if (abs(dphi)<dphi_pho) dphi_pho=abs(dphi);
     }
     if (dphi_met_jet>dphi_pho) dphi_met_jet=dphi_pho;

     if (!isData ){
       mcLeptonFilter=false;
       for (unsigned int i=0; i<nGenPart; i++){
         if (abs(GenPart_pdgId[GenPart_genPartIdxMother[i]])==24 && (abs(GenPart_pdgId[i])== 11 ||abs(GenPart_pdgId[i])== 13 ||abs(GenPart_pdgId[i])== 15 )){
         //if (abs(GenPart_pdgId[i])== 24 && GenPart_statusFlags[i] & 240 != 0){ //this status flag not works in nanoAOD
           mcLeptonFilter=true;
           //cout<<"pid "<<GenPart_pdgId[i]<<" pt "<<GenPart_pt[i]<<" statusflag "<<GenPart_statusFlags[i]<<" momPID "<<GenPart_pdgId[GenPart_genPartIdxMother[i]]<<endl;
         }
       }
       //cout<<"lepton "<<mcLeptonFilter<<endl;
     }

     //L1prefire
     //check events if there's a jet (photon) with pt>100 (>50) and 2.25<|eta|<3.0
     L1prefire=0;
     for (auto i : passPhoL) if (phoET[i]>50 && abs(Photon_eta[i])>2.25) L1prefire=1;
     for (auto i : passJet) if (jetSmearedPt[i]>100 && abs(Jet_eta[i])>2.25) L1prefire=1;
     //for (auto i : passAK8Jet) if (abs(FatJet_eta[i])>2.25) L1prefire=1; //should it be used for AK8 jets?

     //find which btag jet to use for Higgs mass
     //AK8
     passBtag=false; passHiggsMass=false;
     int SelectedAK8Jet=-1;
     DDBvL_selected=0; //DDBvL btag value of higgs candidate jet. 0-Nobtag, 1-loose, 2-medium 3-medium2 4-tight
     for (auto i : passAK8Jet){
       if (FatJet_msoftdrop_nom[i]>70 && FatJet_msoftdrop_nom[i]<200) {
         passHiggsMass=true;
         SelectedAK8Jet=i;
         if (FatJet_btagDDBvL[i]>BtagDDBvLWP[BtagWP_chooser][3]) DDBvL_selected=4;
         else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[BtagWP_chooser][2]) DDBvL_selected=3;
         else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[BtagWP_chooser][1]) DDBvL_selected=2;
         else if (FatJet_btagDDBvL[i]>BtagDDBvLWP[BtagWP_chooser][0]) DDBvL_selected=1;
         else DDBvL_selected=0;
         if (FatJet_btagDDBvL[i]>BtagDDBvLWP[BtagWP_chooser][0]) passBtag=true;
         break;
       }
     }
     if (!passHiggsMass && nPassAK8>0) SelectedAK8Jet = passAK8Jet.at(0);

     //AK4
     double m_bb_deep=-1;
     bool passAK4DeepHiggsMass=false;
     Deep_selected=0; //Deep btag value of higgs candidate jets. 0-Nobtag, 1-1 loose btag, 2-2 loose btag
     int SelectedAK4Jet1=-1, SelectedAK4Jet2=-1;
     double dR_ak4_Hcandidate=-1;
     if (passJet.size()>1){
       for (unsigned int i=0;i<passJet.size();i++){
         for (unsigned int j=i+1;j<passJet.size();j++){
       //for (unsigned int i=0;i<2;i++){
       //  for (unsigned int j=i+1;j<2;j++){
           //double dR = deltaR(Jet_phi[passJet.at(i)],Jet_phi[passJet.at(j)],Jet_eta[passJet.at(i)],Jet_eta[passJet.at(j)]);
           //if (dR>1.5) continue;
           TLorentzVector bjet1, bjet2;
           bjet1.SetPtEtaPhiM(jetSmearedPt[passJet.at(i)],Jet_eta[passJet.at(i)],Jet_phi[passJet.at(i)],Jet_mass[passJet.at(i)]);
           bjet2.SetPtEtaPhiM(jetSmearedPt[passJet.at(j)],Jet_eta[passJet.at(j)],Jet_phi[passJet.at(j)],Jet_mass[passJet.at(j)]);
           m_bb_deep=(bjet1+bjet2).M();
           if (m_bb_deep>70 && m_bb_deep<200) {
             if (Jet_btagDeepFlavB[passJet.at(i)]>BtagDeepWP[BtagWP_chooser][0]) Deep_selected++;
             if (Jet_btagDeepFlavB[passJet.at(j)]>BtagDeepWP[BtagWP_chooser][0]) Deep_selected++;
             SelectedAK4Jet1=passJet.at(i); SelectedAK4Jet2=passJet.at(j);
             passAK4DeepHiggsMass=true;
             break;
           }
         }
         if (passAK4DeepHiggsMass) break;
       }
       if (!passAK4DeepHiggsMass) {SelectedAK4Jet1=passJet.at(0); SelectedAK4Jet2=passJet.at(1);};
       dR_ak4_Hcandidate=deltaR(Jet_phi[SelectedAK4Jet1],Jet_phi[SelectedAK4Jet2],Jet_eta[SelectedAK4Jet1],Jet_eta[SelectedAK4Jet2]);
     }

     //Calculate BTag SFs
     /*
     if (!isData && btag_file.size()>0) {
       //AK4
       if (!_fastSim) {
         CalcBtagSF(Jet_eta, jetSmearedPt, Jet_hadronFlavour, passDeep, eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_deep_L, reader_deep_M, reader_deep_T, Deep_SF_L, Deep_SF_M, Deep_SF_T);
       }
       else {
         CalcBtagSF(Jet_eta, jetSmearedPt, Jet_hadronFlavour, passDeep, eff_b_Deep_L, eff_c_Deep_L, eff_l_Deep_L, eff_b_Deep_M, eff_c_Deep_M, eff_l_Deep_M, eff_b_Deep_T, eff_c_Deep_T, eff_l_Deep_T, reader_deep_L_fs, reader_deep_M_fs, reader_deep_T_fs, Deep_SF_L, Deep_SF_M, Deep_SF_T);
         //AK8
         CalcBtagSF_AK8(FatJet_eta, AK8JetSmearedPt, GenJetAK8_hadronFlavour, passDDBvL, eff_b_BDSV_L, eff_b_BDSV_M1, eff_b_BDSV_M2, eff_b_BDSV_T, DDBvL_SF_L, DDBvL_SF_M1, DDBvL_SF_M2, DDBvL_SF_T);
       }
     }
     */

     //Region definitions
     double met = (MET<50) ? 1 : (MET<70) ? 2 : (MET<100) ? 3 : (MET<200) ? 4 : (MET<500) ? 5 : 6;
     //double njet = (passJet.size()<6) ? 1 : (passJet.size()==6) ? 2 : 3;
     //double njet = (passJet.size()<6) ? 1 : 2;
     double njet;
     //AK4-AK8 searchBins
     int AK4AK8=0, VR=0, boost=0;
     //Signal Region
     if (DDBvL_selected>0) {boost=1;AK4AK8=1;}
     else {if (Deep_selected==1) AK4AK8=1; if (Deep_selected==2) AK4AK8=2;}
     //Control and Validation regions
     if (DDBvL_selected==0 && Deep_selected==0) {
       if (bcounterDDBvL[1]>0) {boost=1; VR=1; AK4AK8=1;}
       else if (passHiggsMass) boost=1;
       if (!boost) {
         if (bcounterDeep[1]==1) {VR=1;AK4AK8=1;}
         if (bcounterDeep[1]>1) {VR=1;AK4AK8=2;}
         if (!passAK4DeepHiggsMass && bcounterDeep[1]==0) {
           if (nPassAK8>0) {boost=1; VR=1;}
           else VR=1;
         }
       }
     }
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
     double sbFill_ak4ak8[dim_ak4]={double(VR),double(AK4AK8),met,njet};
    
     //Efficiency fill for no cuts bin
     h_eff->Fill(0.,w);
     //cuts with command line
     if (_cut_variable.size()>0) {if (!(Cut(ientry,mass_pair))) continue;}
     else { //Hardcoded cuts
       if (!HLT_Photon165_HE10) continue;
     }
     
     //Cut for high njet region (need to implement in Cut() if decided as standard)
     //if (njet==1 && dphi_met_jet<0.3) continue; 
     //Filling histograms
     h_eff->Fill(1.,w);
     h_nISR_jet->Fill(n_isr_jets,w);
     if (nleadPhoL!=-1) h_phoEtL->Fill(phoET[nleadPhoL],w);
     if (nleadPhoM!=-1) h_phoEtM->Fill(phoET[nleadPhoM],w);
     if (nleadPhoT!=-1) h_phoEtT->Fill(phoET[nleadPhoT],w);
     if (nleadPhoL!=-1) h_phoEtaL->Fill(Photon_eta[nleadPhoL],w);
     if (nleadPhoM!=-1) h_phoEtaM->Fill(Photon_eta[nleadPhoM],w);
     if (nleadPhoT!=-1) h_phoEtaT->Fill(Photon_eta[nleadPhoT],w);
     if (nleadPhoL!=-1) h_phoPt->Fill(phoET[nleadPhoL],w);
     
     h_pfMET->Fill(MET,w);
     h_pfMETsumEt->Fill(MET_sumEt,w);
     h_pfMETPhi->Fill(METPhi,w);
     h_pfMETSig->Fill(MET_significance,w);
     h_ST->Fill(ST,w);
     h_ST_G->Fill(ST_G,w);
     h_MT->Fill(MT,w);
     h_HT_after->Fill(HT_after,w);
     h_EMHT_after->Fill(EMHT_after,w);
    
     h_nPho->Fill(nPassPhoL,w);
     h_nEle->Fill(nPassEleL,w);
     h_nEleM->Fill(nPassEleM,w);
     h_nEleT->Fill(nPassEleT,w);
     h_nMu->Fill(nPassEleL,w);
     h_nMuM->Fill(nPassMuM,w);
     h_nMuT->Fill(nPassMuT,w);
     h_nTau->Fill(nPassTauL,w);
     h_nIso->Fill(nPassIso,w);
    
     h_njets->Fill(nPassAK4,w);
     if (leadpt_ak4!=-1) h_jetpt->Fill(Jet_pt_nom[leadpt_ak4],w);
     h_nAK8jets->Fill(nPassAK8,w);
     if (leadpt_ak8!=-1) h_AK8jetpt->Fill(FatJet_pt_nom[leadpt_ak8],w);
		

     if (m_bb_deep!=-1) h_mbbjet_select->Fill(m_bb_deep,w);
     if (DDBvL_selected>0) h_AK8mass_select->Fill(FatJet_msoftdrop_nom[SelectedAK8Jet],w);
     if (dR_ak4_Hcandidate!=-1) h_dR_ak4_Hcandidate->Fill(dR_ak4_Hcandidate,w);
     if (dphi_met_jet!=999) h_dphi_met_jet->Fill(dphi_met_jet,w);
     
     //AK4-AK8 searchbin fills
     double w_AK4searchBin=w, w_AK8searchBin=w;
     if (boost==1 && AK4AK8==1) w_AK8searchBin*=DDBvL_SF_L[DDBvL_whichSF];
     //if (boost==1 && AK4AK8==1) {w_AK8searchBin*=DDBvL_SF_L[DDBvL_whichSF];cout<<"ak8 w "<<DDBvL_SF_L[DDBvL_whichSF]<<endl;}
     else if (boost==0) {if (AK4AK8==1) w_AK4searchBin*=Deep_SF_L[Deep_whichSF]; if (AK4AK8==2) w_AK4searchBin*=Deep_SF_L[Deep_whichSF]*Deep_SF_L[Deep_whichSF];}
     //else if (boost==0) {cout<<AK4AK8<<" ak4 w "<<Deep_SF_L[Deep_whichSF]<<" "<<Deep_SF_L[1]<<" "<<Deep_SF_L[2]<<" deep selected "<<Deep_selected<<" nbjet "<<bcounterDeep[1]<<endl;if (AK4AK8==1) w_AK4searchBin*=Deep_SF_L[Deep_whichSF]; if (AK4AK8==2) w_AK4searchBin*=Deep_SF_L[Deep_whichSF]*Deep_SF_L[Deep_whichSF];}
       switch (boost) {
         case 0 : hn_AK4searchBins->Fill(sbFill_ak4ak8,w_AK4searchBin);
         break;
         case 1 : hn_AK8searchBins->Fill(sbFill_ak4ak8,w_AK8searchBin);
         break;
       }
     
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
       if (nleadPhoL!=-1) m_phoEtL[mass_pair]->Fill(phoET[nleadPhoL],w);
       if (nleadPhoM!=-1) m_phoEtM[mass_pair]->Fill(phoET[nleadPhoM],w);
       if (nleadPhoT!=-1) m_phoEtT[mass_pair]->Fill(phoET[nleadPhoT],w);
       if (nleadPhoL!=-1) m_phoEtaL[mass_pair]->Fill(Photon_eta[nleadPhoL],w);
       if (nleadPhoM!=-1) m_phoEtaM[mass_pair]->Fill(Photon_eta[nleadPhoM],w);
       if (nleadPhoT!=-1) m_phoEtaT[mass_pair]->Fill(Photon_eta[nleadPhoT],w);
       if (nleadPhoL!=-1) m_phoPt[mass_pair]->Fill(phoET[nleadPhoL],w);
       
       m_pfMET[mass_pair]->Fill(MET,w);
       m_pfMETsumEt[mass_pair]->Fill(MET_sumEt,w);
       m_pfMETPhi[mass_pair]->Fill(METPhi,w);
       m_pfMETSig[mass_pair]->Fill(MET_significance,w);
       m_ST[mass_pair]->Fill(ST,w);
       m_ST_G[mass_pair]->Fill(ST_G,w);
       m_MT[mass_pair]->Fill(MT,w);
       m_HT_after[mass_pair]->Fill(HT_after,w);
       m_EMHT_after[mass_pair]->Fill(EMHT_after,w);
      
       m_nPho[mass_pair]->Fill(nPassPhoL,w);
       m_nEle[mass_pair]->Fill(nPassEleL,w);
       m_nEleM[mass_pair]->Fill(nPassEleM,w);
       m_nEleT[mass_pair]->Fill(nPassEleT,w);
       m_nMu[mass_pair]->Fill(nPassEleL,w);
       m_nMuM[mass_pair]->Fill(nPassMuM,w);
       m_nMuT[mass_pair]->Fill(nPassMuT,w);
       m_nTau[mass_pair]->Fill(nPassTauL,w);
       m_nIso[mass_pair]->Fill(nPassIso,w);
      
       m_njets[mass_pair]->Fill(nPassAK4,w);
       if (leadpt_ak4!=-1) m_jetpt[mass_pair]->Fill(Jet_pt_nom[leadpt_ak4],w);
       m_nAK8jets[mass_pair]->Fill(nPassAK8,w);
       if (leadpt_ak8!=-1) m_AK8jetpt[mass_pair]->Fill(FatJet_pt_nom[leadpt_ak8],w);
		  
       
       if (m_bb_deep!=-1) m_mbbjet_select[mass_pair]->Fill(m_bb_deep,w);
       if (DDBvL_selected>0) m_AK8mass_select[mass_pair]->Fill(FatJet_msoftdrop_nom[SelectedAK8Jet],w);
       if (dR_ak4_Hcandidate!=-1) m_dR_ak4_Hcandidate[mass_pair]->Fill(dR_ak4_Hcandidate,w);
       if (dphi_met_jet!=999) m_dphi_met_jet[mass_pair]->Fill(dphi_met_jet,w);
       
       switch (boost) {
         case 0 : mn_AK4searchBins[mass_pair]->Fill(sbFill_ak4ak8,w_AK4searchBin);
         break;
         case 1 : mn_AK8searchBins[mass_pair]->Fill(sbFill_ak4ak8,w_AK8searchBin);
         break;
       }

     }
   }
   for (unsigned int i=1;i<nsbins_ak4+1;i++) {
     h_AK4searchBins->SetBinContent(i,hn_AK4searchBins->GetBinContent(i));
     h_AK4searchBins->SetBinError(i,hn_AK4searchBins->GetBinError(i));
     h_AK8searchBins->SetBinContent(i,hn_AK8searchBins->GetBinContent(i));
     h_AK8searchBins->SetBinError(i,hn_AK8searchBins->GetBinError(i));
   }
   if (SignalScan) {
     for (auto const&i : grid) {
       for (auto j : i.second) {
       std::pair<int,int> MassPair(i.first,j);
         for (unsigned int k=1;k<nsbins_ak4+1;k++) {
           m_AK4searchBins[MassPair]->SetBinContent(k,mn_AK4searchBins[MassPair]->GetBinContent(k));
           m_AK4searchBins[MassPair]->SetBinError(k,mn_AK4searchBins[MassPair]->GetBinError(k));
           m_AK8searchBins[MassPair]->SetBinContent(k,mn_AK8searchBins[MassPair]->GetBinContent(k));
           m_AK8searchBins[MassPair]->SetBinError(k,mn_AK8searchBins[MassPair]->GetBinError(k));
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
     counttxt.open ("CountSignal.txt");
     bool newg=true;
     for (auto i : signal_events) {
       if (newg) counttxt<<"  if (a=="<<i.first.first<<") {\n    switch (b) {"<<endl;
       newg=false;
       counttxt<<"      case "<<i.first.second<<" : return "<<i.second<<";"<<endl;
       if (i.first.first-10==i.first.second) {newg=true; counttxt<<"    }\n  }"<<endl;}
     }
   }
}
