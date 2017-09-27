#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

int main(int argc, char* argv[]){
  bool is_i=0, is_o=0, is_b=0, is_p=0, is_f=0, is_F=0, is_h=0, is_c=0, is_cuts=0, is_quiet=0;
  bool inputs=0, cuts=0;
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
    if (is_F) cout<<"EGamma Fake Rate is true!"<<endl;
    if (inputfiles.size()) cout<<"Running on the following inputfiles:"<<endl;
    for (auto i : inputfiles) std::cout<<i<<std::endl;
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
  Analyzer t(inputfiles,output,bname,pname,is_f,is_F,cut_variable,cut_operator,cut_value,is_quiet);
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
   Long64_t nentries = fChain->GetEntries();

   //Long64_t nbytes = 0, nb = 0; //not used
   //Luminosity of data in [pb]
   //double L_data=2689.38644;
   //double L_data=4353.449;
   double L_data=35867.06;
   
   //Btag SF
   BTCalibration calib, calib_fs;
   BTCalibrationReader reader_L, reader_M, reader_T, reader_L_fs, reader_M_fs, reader_T_fs;
   // setup calibration + reader https://twiki.cern.ch/twiki/bin/view/CMS/BTagCalibration#Standalone
   if (btag_file.size()>0){
     calib = *new BTCalibration("csvv1", "CSVv2_Moriond17_B_H.csv");
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
     calib_fs = *new BTCalibration("csvv1_fs", "fastsim_v2.csv");
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
   }

   //pu reweight
   //TFile f_dataPU("/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/PILEUP/2016DPileUp_FINALCert_forggNtuple.root","read");
   if (pu_file=="default"){
     pu_file="/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/PILEUP/Full2016PileUp_ReReco_FINALCert_forggNtuple.root";
   }
   TFile f_dataPU(pu_file.c_str(),"read");
   TH1D *h_dataPU = (TH1D*)f_dataPU.Get("pileup");
   h_dataPU->Scale(1/(h_dataPU->Integral()));
   h_dataPU->SetDirectory(0);
   f_dataPU.Close();

   std::string temp_fname="histos/Analyzer_histos"; 
   if (output_file != "default") temp_fname+="_"+output_file;
   else temp_fname+=".root";
   TFile f(temp_fname.c_str(),"recreate");
   
   TH1::SetDefaultSumw2();
   
   h_cuts = new TH1D("h_cuts","cuts;HLT,PhoID,PhoEt,eleVeto,muVeto,nJet,MT,ST,MET,btag",15,0,15);
   TH1D *h_nVtx = new TH1D("h_nVtx",";# of vertices",70,0,70);
   TH1D *h_nGoodVtx = new TH1D("h_nGoodVtx",";# of good vertices",70,0,70);
   TH1D *h_nPU = new TH1D("h_nPU",";# of PileUp",70,0,70);

   TH1D *h_phoEtL = new TH1D("h_phoEtL",";CalibE_{T}^{#gamma_L} [GeV]",10,0,1500);
   TH1D *h_phoEtM = new TH1D("h_phoEtM",";CalibE_{T}^{#gamma_M} [GeV]",10,0,1500);
   TH1D *h_phoEtT = new TH1D("h_phoEtT",";CalibE_{T}^{#gamma_T} [GeV]",10,0,1500);
   TH1D *h_phoEtaL = new TH1D("h_phoEtaL",";#eta^{#gamma_{L}}",30,-3,3);
   TH1D *h_phoEtaM = new TH1D("h_phoEtaM",";#eta^{#gamma_{M}}",30,-3,3);
   TH1D *h_phoEtaT = new TH1D("h_phoEtaT",";#eta^{#gamma_{T}}",30,-3,3);
   const int nbins_pfMET=10;
   double xbins_pfMET[nbins_pfMET+1]={0,20,40,70,100,150,200,300,500,700,1000};
   TH1D *h_pfMET = new TH1D("h_pfMET",";#slash{E}_{T} [GeV]",nbins_pfMET,xbins_pfMET);
   TH1D *h_pfMETsumEt = new TH1D("h_pfMETsumEt",";#slash{E}_{T} sumEt",20,-50,5000);
   TH1D *h_pfMETPhi = new TH1D("h_pfMETPhi",";#Phi^{#slash{E}_{T}}",20,-4,4);
   TH1D *h_pfMETSig = new TH1D("h_pfMETSig",";#slash{E}_{T}Sig",50,0,2000);
   TH2D *h_MET_AK8btag= new TH2D("h_MET_AK8btag","MET vs selected AK8btag;pfMET;BDSV",30,0,1000,30,-1,1);
   TH2D *h_MET_AK4btag= new TH2D("h_MET_AK4btag","MET vs selected AK4btag1+AK4btag2;pfMET;CSV_{bjet1}+CSV_{bjet2}",30,0,1000,30,0,2);
   TH1D *h_ST = new TH1D("h_ST",";S_{T} [GeV]",10,0,4000);
   TH1D *h_ST_G = new TH1D("h_ST_G",";S_{T}^{#gamma} [GeV]",10,0,2000);
   TH1D *h_MT = new TH1D("h_MT",";M_{T} [GeV]",10,0,2000);
   TH1D *h_nPho = new TH1D("h_nPho",";# of #gamma",10,0,10);
   TH1D *h_nEle= new TH1D("h_nEle",";# of e_{loose}",10,0,10);
   TH1D *h_nEleM= new TH1D("h_nEleM",";# of e_{medium}",10,0,10);
   TH1D *h_nEleT= new TH1D("h_nEleT",";# of e_{tight}",10,0,10);
   TH1D *h_nMu= new TH1D("h_nMu",";# of #mu_{loose}",10,0,10);
   TH1D *h_nMuM= new TH1D("h_nMuM",";# of #mu_{medium}",10,0,10);
   TH1D *h_nMuT= new TH1D("h_nMuT",";# of #mu_{tight}",10,0,10);

   TH1D *h_njets = new TH1D("h_njets",";# of jets",15,0,15);
   TH1D *h_jetpt = new TH1D("h_jetpt","Leading jetpt;p_{T}^{Leading jet} [GeV]",10,0,2000);
   TH1D *h_nAK8jets = new TH1D("h_nAK8jets",";# of AK8jets",15,0,15);
   TH1D *h_AK8jetpt = new TH1D("h_AK8jetpt","Leading AK8jetpt;p_{T}^{Leading AK8jet} [GeV]",10,0,2000);
   TH1D *h_AK8bjetpt = new TH1D("h_AK8bjetpt","Btagged AK8jetpt;p_{T}^{btagged AK8jet} [GeV]",10,0,2000);
   TH1D *h_AK8bhjetpt = new TH1D("h_AK8bhjetpt","Btagged,Higgs-mass AK8jetpt;p_{T}^{Higgs btagged AK8jet} [GeV]",10,0,2000);
   TH1D *h_AK8ljetmass = new TH1D("h_AK8ljetmass","Leading AK8jetmass;m_{AK8leading jet} [GeV]",10,0,700);
   TH1D *h_AK8jetmass = new TH1D("h_AK8jetmass","AK8jetmass;m_{AK8jets} [GeV]",10,0,700);
   TH1D *h_AK8bjetmass = new TH1D("h_AK8bjetmass","Btagged AK8jetmass;m_{btagged AK8jets} [GeV]",10,0,700);
   TH1D *h_AK8bhjetmass = new TH1D("h_AK8bhjetmass","Btagged, Higgs-mass AK8jetmass;m_{Higgs btagged AK8jets} [GeV]",10,0,700);
   TH1D *h_AK8bPrunedjetmass = new TH1D("h_AK8bPrunedjetmass","Btagged AK8Prunedjetmass;Pruned m_{btagged AK8jets} [GeV]",10,0,700);
   TH1D *h_AK8bhPrunedjetmass = new TH1D("h_AK8bhPrunedjetmass","Btagged, Higgs-mass AK8Prunedjetmass;Pruned m_{Higgs btagged AK8jets} [GeV]",10,0,700);
   TH1D *h_AK8bPrunedCorrjetmass = new TH1D("h_AK8bPrunedCorrjetmass","Btagged AK8PrunedCorrjetmass;PrunedCorr m_{btagged AK8jets} [GeV]",10,0,700);
   TH1D *h_AK8bhPrunedCorrjetmass = new TH1D("h_AK8bhPrunedCorrjetmass","Btagged, Higgs-mass AK8PrunedCorrjetmass;PrunedCorr m_{Higgs btagged AK8jets} [GeV]",10,0,700);
   TH1D *h_AK8tau1= new TH1D("h_AK8tau1",";#tau_{1}^{AK8Jet}",10,0,1);
   TH1D *h_AK8tau2= new TH1D("h_AK8tau2",";#tau_{2}^{AK8Jet}",10,0,1);
   TH1D *h_AK8tau3= new TH1D("h_AK8tau3",";#tau_{3}^{AK8Jet}",10,0,1);
   TH1D *h_AK8tau2_tau1= new TH1D("h_AK8tau2_tau1",";AK8Jet_tau2/tau1",10,0,1);
   TH1D *h_AK8tau3_tau2= new TH1D("h_AK8tau3_tau2",";AK8Jet_tau3/tau2",10,0,1);
   
   TH1D *h_CSVbjetsL = new TH1D("h_CSVbjetsL",";# of CSVLoosebjets",10,0,10);
   TH1D *h_CSVbjetsM = new TH1D("h_CSVbjetsM",";# of CSVMediumbjets",10,0,10);
   TH1D *h_CSVbjetsT = new TH1D("h_CSVbjetsT",";# of CSVTightbjets",10,0,10);
   TH1D *h_cMVAbjetsL = new TH1D("h_cMVAbjetsL",";# of cMVALoosebjets",10,0,10);
   TH1D *h_cMVAbjetsM = new TH1D("h_cMVAbjetsM",";# of cMVAMediumbjets",10,0,10);
   TH1D *h_cMVAbjetsT = new TH1D("h_cMVAbjetsT",";# of cMVATightbjets",10,0,10);
   TH1D *h_BDSVbjetsL = new TH1D("h_BDSVbjetsL",";# of BDSVLoosebjets",10,0,10);
   TH1D *h_BDSVbjetsM = new TH1D("h_BDSVbjetsM",";# of BDSVMediumbjets",10,0,10);
   TH1D *h_BDSVbjetsT = new TH1D("h_BDSVbjetsT",";# of BDSVTightbjets",10,0,10);
    
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

   TH1D *h_selectAK8bjetpt= new TH1D("h_selectAK8bjetpt","Selected AK8 jet pt;pt[GeV]",10,0,2000);
   TH1D *h_selectbjetpt= new TH1D("h_selectbjetpt","Selected jet pt1;pt[GeV]",10,0,2000);
   TH1D *h_selectbjetpt2= new TH1D("h_selectbjetpt2","Selected jet pt2;pt[GeV]",10,0,2000);
  
   TH1D *h_HT_before = new TH1D("h_HT_before","HT before cuts;HT",10,0,3500);
   TH1D *h_EMHT_before = new TH1D("h_EMHT_before","EMHT before cuts;EMHT",10,0,3500);
   TH1D *h_HT_after = new TH1D("h_HT_after","HT after cuts;HT",10,0,3500);
   TH1D *h_EMHT_after = new TH1D("h_EMHT_after","EMHT after cuts;EMHT",10,0,3500);

   TH1D *h_AK8HT_before = new TH1D("h_AK8HT_before","AK8HT before cuts;HT",10,0,3500);
   TH1D *h_AK8EMHT_before = new TH1D("h_AK8EMHT_before","AK8EMHT before cuts;EMHT",10,0,3500);
   TH1D *h_AK8HT_after = new TH1D("h_AK8HT_after","AK8HT after cuts;HT",10,0,3500);
   TH1D *h_AK8EMHT_after = new TH1D("h_AK8EMHT_after","AK8EMHT after cuts;EMHT",10,0,3500);
  
   TH1D *h_AK8PrunedCorrjetmass_select = new TH1D("h_AK8PrunedCorrjetmass_select","Selected AK8PrunedCorrjetmass;PrunedCorr m_{Higgs btagged AK8jets} [GeV]",10,0,250);
   TH1D *h_AK8PrunedCorrjetmass_withABCD= new TH1D("h_AK8PrunedCorrjetmass_select_withABCD","Highest btagged AK8PrunedCorrjetmass in Higgs mass range;PrunedCorr m_{highest btag AK8jets} [GeV]",10,0,250);
   TH2D *h_AK8mass_vs_pt= new TH2D("h_AK8mass_vs_pt","Highest btagged AK8PrunedCorrjetmass in Higgs mass range vs its pt;PrunedCorr m_{highest btag AK8jets} [GeV];p_{T}^{highest btag AK8jets} [GeV]",20,0,250,40,0,1500);
   TH2D *h_AK8mass_all_vs_pt= new TH2D("h_AK8mass_all_vs_pt","All AK8PrunedCorrjetmass in Higgs mass range vs its pt;PrunedCorr m_{highest btag AK8jets} [GeV];p_{T}^{highest btag AK8jets} [GeV]",20,0,250,40,0,1500);
   TH1D *h_mbbjet_select= new TH1D("h_mbbjet_select","Invariant mass of selected bjets;M_{bb}[GeV]",10,0,250);
   TH1D *h_mbbjet_withABCD= new TH1D("h_mbbjet_select_withABCD","Invariant mass of highest btag bjets in Higgs mass range;M_{bb}[GeV]",10,0,250);
   TH2D *h_mbbjet_vs_pt1= new TH2D("h_mbbjet_vs_pt1","Invariant mass of highest btag bjets in Higgs mass range vs 1st p_{T};M_{bb}[GeV];p_{T}^{1} [GeV]",20,0,250,30,0,1000);
   TH2D *h_mbbjet_vs_pt2= new TH2D("h_mbbjet_vs_pt2","Invariant mass of highest btag bjets in Higgs mass range vs 2nd p_{T};M_{bb}[GeV];p_{T}^{2} [GeV]",20,0,250,30,0,1000);
   TH2D *h_mbbjet_comb_vs_pt1= new TH2D("h_mbbjet_comb_vs_pt1","Invariant mass of combination of all jets in Higgs mass range vs 1st p_{T};M_{bb}[GeV];p_{T}^{1} [GeV]",20,0,250,30,0,1000);
   TH2D *h_mbbjet_comb_vs_pt2= new TH2D("h_mbbjet_comb_vs_pt2","Invariant mass of combination of all jets in Higgs mass range vs 1st p_{T};M_{bb}[GeV];p_{T}^{1} [GeV]",20,0,250,30,0,1000);

   TBenchmark time;
   TDatime now;
   if (!is_quiet) now.Print();
   time.Start("time");

   int file_counter=-1, temp=-1; std::string temp_f="";
   ULong64_t TotalEvents=1;
   int zbx=0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<10;jentry++) {
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
       b_mcStatus->GetEntry(ientry);
       b_genMET->GetEntry(ientry);
       b_jetGenEta->GetEntry(ientry);
       b_jetGenPhi->GetEntry(ientry);
       b_jetHadFlvr->GetEntry(ientry);
       b_jetP4Smear->GetEntry(ientry);
       b_jetP4SmearUp->GetEntry(ientry);
       b_jetP4SmearDo->GetEntry(ientry);
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
     b_phoR9->GetEntry(ientry);
     b_phohasPixelSeed->GetEntry(ientry);
     b_phoEleVeto->GetEntry(ientry);
     b_phoHoverE->GetEntry(ientry);
     b_phoPFChIso->GetEntry(ientry);
     b_phoPFPhoIso->GetEntry(ientry);
     b_phoPFNeuIso->GetEntry(ientry);
     b_phoIDMVA->GetEntry(ientry);
     b_phoIDbit->GetEntry(ientry);
     b_nJet->GetEntry(ientry);
     b_jetEn->GetEntry(ientry);
     b_jetPt->GetEntry(ientry);
     b_jetPhi->GetEntry(ientry);
     b_jetEta->GetEntry(ientry);
     b_jetCHF->GetEntry(ientry);
     b_jetJetProbabilityBJetTags->GetEntry(ientry);
     b_jetCSV2BJetTags->GetEntry(ientry);
     b_jetpfCombinedMVAV2BJetTags->GetEntry(ientry);
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
     b_AK8JetPFLooseId->GetEntry(ientry);
     b_AK8JetpfBoostedDSVBTag->GetEntry(ientry);
     b_AK8Jet_tau1->GetEntry(ientry);
     b_AK8Jet_tau2->GetEntry(ientry);
     b_AK8Jet_tau3->GetEntry(ientry);
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
       TFile f_FR("All_results.root","read");
       h2_FR = (TH2D*)f_FR.Get("FR_Data_EtaPhi_50_110");
       h2_FR->SetDirectory(0);
       f_FR.Close();
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
         else std::cout<<"No h_cross_section found in file using xsec = "<<xsec<<std::endl;
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
     //weights
       //get zero bunchcrossing (puTrue always the same for every bx, just in case...)
       for (unsigned int i=0;i<(*puBX).size();i++) if ((*puBX)[i]==0) zbx=i;
       double pu_weight=h_PUweight->GetBinContent(h_PUweight->FindBin((*puTrue)[zbx]));
       if (_fastSim) pu_weight=1;
       double weight=L_data*xsec/TotalEvents;
       //std::cout<<"weight=L_data*xsec/TotalEvents "<<weight<<"="<<L_data<<"*"<<xsec<<"/"<<TotalEvents<<std::endl;
       if (abs(genWeight)>1) w=copysign(weight*pu_weight,genWeight); //only a sign for amc@nlo
       else w=weight*pu_weight*genWeight;
       //std::cout<<"w=weight*pu_weight*genWeight "<<w<<"="<<weight<<"*"<<pu_weight<<"*"<<genWeight<<std::endl;
       //Scale factors
       if (jentry==0) {
         //photon cutbased loose
         TFile f_phoLooseSF("pho_looseSF_egammaEffi.txt_EGM2D.root","read");
         h_pho_EGamma_SF2D[0] = (TH2F*)f_phoLooseSF.Get("EGamma_SF2D");
         h_pho_EGamma_SF2D[0]->SetDirectory(0);
         f_phoLooseSF.Close();
         //photon cutbased medium
         TFile f_phoMediumSF("pho_mediumSF_egammaEffi.txt_EGM2D.root","read");
         h_pho_EGamma_SF2D[1] = (TH2F*)f_phoMediumSF.Get("EGamma_SF2D");
         h_pho_EGamma_SF2D[1]->SetDirectory(0);
         f_phoMediumSF.Close();
         //photon cutbased tight
         TFile f_phoTightSF("pho_tightSF_egammaEffi.txt_EGM2D.root","read");
         h_pho_EGamma_SF2D[2] = (TH2F*)f_phoTightSF.Get("EGamma_SF2D");
         h_pho_EGamma_SF2D[2]->SetDirectory(0);
         f_phoTightSF.Close();
         //photon haspixelseed SF
         TFile f_phoPV("ScalingFactors_80X_Summer16.root","read");
         h_Scaling_Factors_HasPix_R9_high = (TH2D*)f_phoPV.Get("Scaling_Factors_HasPix_R9 > 0.94");
         h_Scaling_Factors_HasPix_R9_high->SetDirectory(0);
         h_Scaling_Factors_HasPix_R9_low = (TH2D*)f_phoPV.Get("Scaling_Factors_HasPix_R9 < 0.94");
         h_Scaling_Factors_HasPix_R9_low->SetDirectory(0);
         f_phoPV.Close();
         //electron reconstruction efficiency
         TFile f_eleRecSF("ele_recEff_egammaEffi.txt_EGM2D.root","read");
         h_eleRec_EGamma_SF2D = (TH2F*)f_eleRecSF.Get("EGamma_SF2D");
         h_eleRec_EGamma_SF2D->SetDirectory(0);
         f_eleRecSF.Close();
         //electron cutbased veto
         TFile f_eleVetoSF("ele_vetoSF_egammaEffi.txt_EGM2D.root","read");
         h_ele_EGamma_SF2D[0] = (TH2F*)f_eleVetoSF.Get("EGamma_SF2D");
         h_ele_EGamma_SF2D[0]->SetDirectory(0);
         f_eleVetoSF.Close();
         //electron cutbased loose
         TFile f_eleLooseSF("ele_looseSF_egammaEffi.txt_EGM2D.root","read");
         h_ele_EGamma_SF2D[1] = (TH2F*)f_eleLooseSF.Get("EGamma_SF2D");
         h_ele_EGamma_SF2D[1]->SetDirectory(0);
         f_eleLooseSF.Close();
         //electron cutbased medium
         TFile f_eleMediumSF("ele_mediumSF_egammaEffi.txt_EGM2D.root","read");
         h_ele_EGamma_SF2D[2] = (TH2F*)f_eleMediumSF.Get("EGamma_SF2D");
         h_ele_EGamma_SF2D[2]->SetDirectory(0);
         f_eleMediumSF.Close();
         //electron cutbased tight
         TFile f_eleTightSF("ele_tightSF_egammaEffi.txt_EGM2D.root","read");
         h_ele_EGamma_SF2D[3] = (TH2F*)f_eleTightSF.Get("EGamma_SF2D");
         h_ele_EGamma_SF2D[3]->SetDirectory(0);
         f_eleTightSF.Close();
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
     vector<int> passPhoL, passPhoM, passPhoT, passJet, passAK8Jet, passEleV, passEleL, passEleM, passEleT, passMuL, passMuM, passMuT;
     vector<float> jetSmearedPt, jetSmearedEn, AK8JetSmearedPt, AK8JetSmearedEn;
     map<int,char> passCSV, passcMVA, passBDSV;
     HT_before=0; EMHT_before=0; HT_after=0; EMHT_after=0;
     AK8HT_before=0; AK8EMHT_before=0; AK8HT_after=0; AK8EMHT_after=0;
     ST=0; ST_G=0; MT=0;
     nleadPhoL=-1; nleadPhoM=-1; nleadPhoT=-1;
     nleadEleL=-1; nleadEleM=-1; nleadEleT=-1;
     nleadMuL=-1; nleadMuM=-1; nleadMuT=-1;
     memset(bcounterCSV,0,sizeof bcounterCSV);
     memset(bcountercMVA,0,sizeof bcountercMVA);
     memset(bcounterBDSV,0,sizeof bcounterBDSV);
     //photon
     for (int i=0;i<nPho;i++){
       if (abs((*phoEta)[i])<1.4442 && (*phohasPixelSeed)[i]==0) {
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
     }
     for (auto i : passPhoL) {
       if ((*phoCalibEt)[i]>(*phoCalibEt)[nleadPhoL]) nleadPhoL=i;
       EMHT_before+=(*phoCalibEt)[i];
     }
     for (auto i : passPhoM) if ((*phoCalibEt)[i]>(*phoCalibEt)[nleadPhoM]) nleadPhoM=i;
     for (auto i : passPhoT) if ((*phoCalibEt)[i]>(*phoCalibEt)[nleadPhoT]) nleadPhoT=i;
     nPassPhoL=passPhoL.size();
     nPassPhoM=passPhoM.size();
     nPassPhoT=passPhoT.size();
     EMHT_after=EMHT_before;
     AK8EMHT_before=EMHT_before;
     AK8EMHT_after=EMHT_before;
     //Calculate photon SFs
     if (!isData) {
       if (nPassPhoL!=0){
         pho_SF[0]=h_pho_EGamma_SF2D[0]->GetBinContent(h_pho_EGamma_SF2D[0]->FindBin((*phoSCEta)[passPhoL[0]],(*phoCalibEt)[passPhoL[0]]));
         if ((*phoR9)[passPhoL[0]]>0.94) pho_SF[0]*=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs((*phoSCEta)[passPhoL[0]]),100));
         else pho_SF[0]=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs((*phoSCEta)[passPhoL[0]]),100));
       }
       if (nPassPhoM!=0){
         pho_SF[1]=h_pho_EGamma_SF2D[1]->GetBinContent(h_pho_EGamma_SF2D[1]->FindBin((*phoSCEta)[passPhoM[0]],(*phoCalibEt)[passPhoM[0]]));
         if ((*phoR9)[passPhoM[0]]>0.94) pho_SF[1]*=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs((*phoSCEta)[passPhoM[0]]),100));
         else pho_SF[1]=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs((*phoSCEta)[passPhoM[0]]),100));
       }
       if (nPassPhoT!=0){
         pho_SF[2]=h_pho_EGamma_SF2D[2]->GetBinContent(h_pho_EGamma_SF2D[2]->FindBin((*phoSCEta)[passPhoT[0]],(*phoCalibEt)[passPhoT[0]]));
         if ((*phoR9)[passPhoT[0]]>0.94) pho_SF[2]*=h_Scaling_Factors_HasPix_R9_high->GetBinContent(h_Scaling_Factors_HasPix_R9_high->FindBin(abs((*phoSCEta)[passPhoT[0]]),100));
         else pho_SF[2]=h_Scaling_Factors_HasPix_R9_low->GetBinContent(h_Scaling_Factors_HasPix_R9_low->FindBin(abs((*phoSCEta)[passPhoT[0]]),100));
       }
     }
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
       if (abs((*jetEta)[i])>2.4 || (*jetPFLooseId)[i]==0 || jetSmearedPt[i]<40 || !((*jetPUFullID)[i]&(1<<2))) passcut=false;
       //if (_fastSim && (*jetPt)[i]>20 && abs((*jetEta)[i])<2.5 && (*jetCHF)[i]<0.1) {
       //if (_fastSim && passcut && (*jetCHF)[i]<0.1) {
       //  if ((*jetGenEta)[i]==-999) {std::cout<<"veto 999"<<std::endl;vetoEvent=true;}
       //  else if (deltaR((*jetPhi)[i],(*jetGenPhi)[i],(*jetEta)[i],(*jetGenEta)[i])>0.3) {std::cout<<"veto deltar"<<std::endl;vetoEvent=true;}
       //}
       for (auto j : passPhoL) if (deltaR((*jetPhi)[i],(*phoPhi)[j],(*jetEta)[i],(*phoEta)[j])<0.3) {
         passcut=false;break;
       }
       if (passcut) passJet.push_back(i);
     }
     nPassAK4=passJet.size();
     //if (vetoEvent) {continue;}
     //jet pt, btags
     for (auto i : passJet) {
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
     }
     bcounterCSV[2] += bcounterCSV[3];
     bcounterCSV[1] += bcounterCSV[2];
     bcountercMVA[2] += bcountercMVA[3];
     bcountercMVA[1] += bcountercMVA[2];
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
       for (auto j : passPhoL) if (deltaR((*AK8JetPhi)[i],(*phoPhi)[j],(*AK8JetEta)[i],(*phoEta)[j])<0.5) {
         passcut=false;break;
       }
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
     //electron
     for (int i=0;i<nEle;i++) {
       bool passOverlap=true;
       for (auto j : passPhoL) if (deltaR((*elePhi)[i],(*phoPhi)[j],(*eleEta)[i],(*phoEta)[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passAK8Jet) if (deltaR((*elePhi)[i],(*AK8JetPhi)[j],(*eleEta)[i],(*AK8JetEta)[j])<0.5) {
         passOverlap=false;break;
       }
       for (auto j : passJet) if (deltaR((*elePhi)[i],(*jetPhi)[j],(*eleEta)[i],(*jetEta)[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
       if ((*eleIDbit)[i]>>0&1 && (*eleCalibPt)[i]>5 && abs((*eleEta)[i])<2.5 && (*elePFMiniIso)[i]<0.2) passEleV.push_back(i);
       if ((*eleIDbit)[i]>>1&1 && (*eleCalibPt)[i]>5 && abs((*eleEta)[i])<2.5 && (*elePFMiniIso)[i]<0.2) passEleL.push_back(i);
       if ((*eleIDbit)[i]>>2&1 && (*eleCalibPt)[i]>5 && abs((*eleEta)[i])<2.5 && (*elePFMiniIso)[i]<0.2) passEleM.push_back(i);
       if ((*eleIDbit)[i]>>3&1 && (*eleCalibPt)[i]>5 && abs((*eleEta)[i])<2.5 && (*elePFMiniIso)[i]<0.2) passEleT.push_back(i);
     }
     nPassEleV=passEleV.size();
     nPassEleL=passEleL.size();
     nPassEleM=passEleM.size();
     nPassEleT=passEleT.size();
     if (nPassEleL != 0) nleadEleL=passEleL[0];
     if (nPassEleM != 0) nleadEleM=passEleM[0];
     if (nPassEleT != 0) nleadEleT=passEleT[0];
     //Fake Rate
     if (_fakeRate && nPassEleL != 0) {
       if (abs((*eleEta)[nleadEleL])>1.4442) continue;
       w*=h2_FR->GetBinContent(h2_FR->FindBin((*eleEta)[nleadEleL],(*elePhi)[nleadEleL]));
     }
     //Calculate electron SFs
     if (!isData) {
       if (nPassEleV!=0){
         ele_SF[0]=h_ele_EGamma_SF2D[0]->GetBinContent(h_ele_EGamma_SF2D[1]->FindBin((*eleSCEta)[passEleV[0]],(*eleCalibPt)[passEleV[0]]));
         ele_SF[0]=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin((*eleSCEta)[passEleV[0]],(*eleCalibPt)[passEleV[0]]));
       }
       if (nPassEleL!=0){
         ele_SF[1]=h_ele_EGamma_SF2D[1]->GetBinContent(h_ele_EGamma_SF2D[1]->FindBin((*eleSCEta)[passEleL[0]],(*eleCalibPt)[passEleL[0]]));
         ele_SF[1]=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin((*eleSCEta)[passEleL[0]],(*eleCalibPt)[passEleL[0]]));
       }
       if (nPassEleM!=0){
         ele_SF[2]=h_ele_EGamma_SF2D[2]->GetBinContent(h_ele_EGamma_SF2D[2]->FindBin((*eleSCEta)[passEleM[0]],(*eleCalibPt)[passEleM[0]]));
         ele_SF[2]=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin((*eleSCEta)[passEleM[0]],(*eleCalibPt)[passEleM[0]]));
       }
       if (nPassEleT!=0){
         ele_SF[3]=h_ele_EGamma_SF2D[3]->GetBinContent(h_ele_EGamma_SF2D[3]->FindBin((*eleSCEta)[passEleT[0]],(*eleCalibPt)[passEleT[0]]));
         ele_SF[3]=h_eleRec_EGamma_SF2D->GetBinContent(h_eleRec_EGamma_SF2D->FindBin((*eleSCEta)[passEleT[0]],(*eleCalibPt)[passEleT[0]]));
       }
     }
     //muon
     for (int i=0;i<nMu;i++) {
       bool passOverlap=true;
       for (auto j : passPhoL) if (deltaR((*muPhi)[i],(*phoPhi)[j],(*muEta)[i],(*phoEta)[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passAK8Jet) if (deltaR((*muPhi)[i],(*AK8JetPhi)[j],(*muEta)[i],(*AK8JetEta)[j])<0.5) {
         passOverlap=false;break;
       }
       for (auto j : passJet) if (deltaR((*muPhi)[i],(*jetPhi)[j],(*muEta)[i],(*jetEta)[j])<0.3) {
         passOverlap=false;break;
       }
       for (auto j : passEleL) if (deltaR((*muPhi)[i],(*elePhi)[j],(*muEta)[i],(*eleEta)[j])<0.3) {
         passOverlap=false;break;
       }
       if (!passOverlap) continue;
       if ((*muIDbit)[i]>>0&1 && (*muPt)[i]>5 && abs((*muEta)[i])<2.4 && (*muSIP)[i]<4 && (*muDz)[i]<0.1 && (*muD0)[i]<0.05 && (*muPFMiniIso)[i]<0.2) passMuL.push_back(i);
       if ((*muIDbit)[i]>>1&1 && (*muPt)[i]>5 && abs((*muEta)[i])<2.4 && (*muSIP)[i]<4 && (*muDz)[i]<0.1 && (*muD0)[i]<0.05 && (*muPFMiniIso)[i]<0.2) passMuM.push_back(i);
       if ((*muIDbit)[i]>>2&1 && (*muPt)[i]>5 && abs((*muEta)[i])<2.4 && (*muSIP)[i]<4 && (*muDz)[i]<0.1 && (*muD0)[i]<0.05 && (*muPFMiniIso)[i]<0.2) passMuT.push_back(i);
     }
     nPassMuL=passMuL.size();
     nPassMuM=passMuM.size();
     nPassMuT=passMuT.size();
     if (passMuL.size() != 0) nleadMuL=passMuL[0];
     if (passMuM.size() != 0) nleadMuM=passMuM[0];
     if (passMuT.size() != 0) nleadMuT=passMuT[0];
     //dR between leading photon & leading pt AK8
     double dR_pho_AK8=-1;
     if (passPhoL.size()>0 && passAK8Jet.size()>0){
       if (abs((*AK8JetEta)[leadpt_ak8])<1.4442){
         dR_pho_AK8=deltaR((*AK8JetPhi)[leadpt_ak8],(*phoPhi)[nleadPhoL],(*AK8JetEta)[leadpt_ak8],(*phoEta)[nleadPhoL]);
       }
     }
     //MET variables
     for (auto i : passPhoL) ST+=(*phoCalibEt)[i];
     ST+=pfMET;
     ST_G=ST;
     for (auto i : passJet) ST+=jetSmearedPt[i];
     if (passPhoL.size()>0) MT=sqrt(2*pfMET*(*phoCalibEt)[nleadPhoL]*(1-cos(abs((*phoPhi)[nleadPhoL]-pfMETPhi))));
     
     //find which btag jet to use for Higgs mass
     //AK8
     passBtag=false, passHiggsMass=false;
     int SelectedAK8Jet=-1;
     BDSV_selected=0; //BDSV btag value of higgs candidate jet. 0-Nobtag, 1-loose, 2-medium 3-medium2 4-tight
     for (auto i : passAK8Jet){
       if ((*AK8JetPrunedMassCorr)[i]>70 && (*AK8JetPrunedMassCorr)[i]<200) {
         passHiggsMass=true;
         SelectedAK8Jet=i;
         if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[3]) BDSV_selected=4;
         else if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[2]) BDSV_selected=3;
         else if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[1]) BDSV_selected=2;
         else if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[0]) BDSV_selected=1;
         else BDSV_selected=0;
         if ((*AK8JetpfBoostedDSVBTag)[i]>BtagBDSVWP[1]) passBtag=true;
         break;
       }
     }
      //AK4
     passAK4Btag1=false, passAK4Btag2=false, passAK4HiggsMass=false;
     double m_bb=-1;
     int SelectedAK4Jet1=-1, SelectedAK4Jet2=-1;
     CSV_selected=0; //CSV btag value of higgs candidate jets. 0-Nobtag, 1-1 loose btag, 2-2 loose btag
     for (unsigned int i=0;i<passJet.size();i++){
       for (unsigned int j=i+1;j<passJet.size();j++){
         TLorentzVector bjet1, bjet2;
         bjet1.SetPtEtaPhiE(jetSmearedPt[passJet.at(i)],(*jetEta)[passJet.at(i)],(*jetPhi)[passJet.at(i)],jetSmearedEn[passJet.at(i)]);
         bjet2.SetPtEtaPhiE(jetSmearedPt[passJet.at(j)],(*jetEta)[passJet.at(j)],(*jetPhi)[passJet.at(j)],jetSmearedEn[passJet.at(j)]);
         m_bb=(bjet1+bjet2).M();
         if (m_bb>70 && m_bb<200) {
           SelectedAK4Jet1=passJet.at(i);
           SelectedAK4Jet2=passJet.at(j);
           if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[0]) {passAK4Btag1=true;CSV_selected++;}
           if ((*jetCSV2BJetTags)[passJet.at(j)]>BtagCSVWP[0]) {passAK4Btag2=true;CSV_selected++;}
           passAK4HiggsMass=true;
           break;
         }
       }
       if (passAK4HiggsMass) break;
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
       if (!_fastSim) CalcBtagSF(jetEta, jetSmearedPt, jetHadFlvr, passCSV, eff_b_CSV_L, eff_c_CSV_L, eff_l_CSV_L, eff_b_CSV_M, eff_c_CSV_M, eff_l_CSV_M, eff_b_CSV_T, eff_c_CSV_T, eff_l_CSV_T, reader_L, reader_M, reader_T, CSV_SF_L, CSV_SF_M, CSV_SF_T);
       else {
         CalcBtagSF(jetEta, jetSmearedPt, jetHadFlvr, passCSV, eff_b_CSV_L, eff_c_CSV_L, eff_l_CSV_L, eff_b_CSV_M, eff_c_CSV_M, eff_l_CSV_M, eff_b_CSV_T, eff_c_CSV_T, eff_l_CSV_T, reader_L_fs, reader_M_fs, reader_T_fs, CSV_SF_L, CSV_SF_M, CSV_SF_T);
       //AK8
         CalcBtagSF_AK8(AK8JetEta, AK8JetSmearedPt, AK8JetHadFlvr, passBDSV, eff_b_BDSV_L, eff_b_BDSV_M1, eff_b_BDSV_M2, eff_b_BDSV_T, BDSV_SF_L, BDSV_SF_M1, BDSV_SF_M2, BDSV_SF_T);
       }
     }
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
     h_phoEtL->Fill((*phoCalibEt)[nleadPhoL],w);
     h_phoEtaL->Fill((*phoEta)[nleadPhoL],w);
     if (passPhoM.size()>0) {
       h_phoEtM->Fill((*phoCalibEt)[nleadPhoM],w);
       h_phoEtaM->Fill((*phoEta)[nleadPhoM],w);
     }
     if (passPhoT.size()>0){
       h_phoEtT->Fill((*phoCalibEt)[nleadPhoT],w);
       h_phoEtaT->Fill((*phoEta)[nleadPhoT],w);
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
     if (leadpt_ak4!=-1) h_jetpt->Fill(jetSmearedPt[leadpt_ak4],w);
     if (leadpt_ak8!=-1) h_AK8jetpt->Fill(AK8JetSmearedPt[leadpt_ak8],w);
     if (highBDSV!=-1) h_AK8bjetpt->Fill(AK8JetSmearedPt[highBDSV],w);
     if (SelectedAK8Jet!=-1 && passBtag) h_AK8bhjetpt->Fill(AK8JetSmearedPt[SelectedAK8Jet],w);
     if (leadpt_ak8!=-1) h_AK8ljetmass->Fill((*AK8JetMass)[leadpt_ak8],w);
     if (leadpt_ak8!=-1) h_AK8bjetmass->Fill((*AK8JetMass)[highBDSV],w);
     if (SelectedAK8Jet!=-1 && passBtag) h_AK8bhjetmass->Fill((*AK8JetMass)[SelectedAK8Jet],w);
     if (leadpt_ak8!=-1) h_AK8bPrunedjetmass->Fill((*AK8JetPrunedMass)[highBDSV],w);
     if (SelectedAK8Jet!=-1 && passBtag) h_AK8bhPrunedjetmass->Fill((*AK8JetPrunedMass)[SelectedAK8Jet],w);
     if (leadpt_ak8!=-1) h_AK8bPrunedCorrjetmass->Fill((*AK8JetPrunedMassCorr)[highBDSV],w);
     if (SelectedAK8Jet!=-1 && passBtag) h_AK8bhPrunedCorrjetmass->Fill((*AK8JetPrunedMassCorr)[SelectedAK8Jet],w);
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
     }
   f.Write();
   f.Close();
   time.Stop("time");
   if (!is_quiet) std::cout<<"CPU time = "<<time.GetCpuTime("time")<<", Real time = "<<time.GetRealTime("time")<<std::endl;
}
