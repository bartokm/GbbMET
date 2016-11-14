#define skimmed_data_cxx
#include "skimmed_data.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

double deltaR(double phi1, double phi2, double eta1, double eta2){
  double dR=0;
  if (abs(phi1-phi2)>M_PI) dR=sqrt(pow(phi2-phi1,2)+pow(eta1-eta2,2));
  else dR=sqrt(pow(phi1-phi2,2)+pow(eta1-eta2,2));
  return dR;
}

void skimmed_data::Loop()
{
//   In a ROOT session, you can do:
//      root> .L skimmed_data.C
//      root> skimmed_data t
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
   fChain->SetBranchStatus("*",0);  // disable all branches
   fChain->SetBranchStatus("event", 1);
   fChain->SetBranchStatus("nVtx", 1);
   fChain->SetBranchStatus("nTrksPV", 1);
   fChain->SetBranchStatus("HLTEleMuX",1);
   fChain->SetBranchStatus("HLTPho",1);
   fChain->SetBranchStatus("pfMET",1);
   fChain->SetBranchStatus("pfMETPhi",1);
   fChain->SetBranchStatus("pfMETsumEt",1);
   fChain->SetBranchStatus("pfMETmEtSig",1);
   fChain->SetBranchStatus("pfMETSig",1);
   fChain->SetBranchStatus("nEle", 1);
   fChain->SetBranchStatus("eleEta", 1);
   fChain->SetBranchStatus("elePhi", 1);
   fChain->SetBranchStatus("elePt", 1);
   fChain->SetBranchStatus("eleIDMVANonTrg", 1);
   fChain->SetBranchStatus("eleIDbit", 1);
   fChain->SetBranchStatus("nMu", 1);
   fChain->SetBranchStatus("muEta", 1);
   fChain->SetBranchStatus("muPhi", 1);
   fChain->SetBranchStatus("muIsLooseID", 1);
   fChain->SetBranchStatus("muIsMediumID", 1);
   fChain->SetBranchStatus("muIsTightID", 1);
   fChain->SetBranchStatus("nPho", 1);
   fChain->SetBranchStatus("phoEt", 1);
   fChain->SetBranchStatus("phoEta",1);
   fChain->SetBranchStatus("phoPhi",1);
   fChain->SetBranchStatus("phohasPixelSeed",1);
   fChain->SetBranchStatus("phoEleVeto",1);
   fChain->SetBranchStatus("phoHoverE",1);
   fChain->SetBranchStatus("phoSigmaIEtaIEta",1);
   fChain->SetBranchStatus("phoPFChIso",1);
   fChain->SetBranchStatus("phoPFPhoIso",1);
   fChain->SetBranchStatus("phoPFNeuIso",1);
   fChain->SetBranchStatus("phoIDMVA",1);
   fChain->SetBranchStatus("phoIDbit",1);
   fChain->SetBranchStatus("nJet",1);
   fChain->SetBranchStatus("jetPt",1);
   fChain->SetBranchStatus("jetPhi",1);
   fChain->SetBranchStatus("jetEta",1);
   fChain->SetBranchStatus("jetJetProbabilityBJetTags",1);
   fChain->SetBranchStatus("jetpfCombinedInclusiveSecondaryVertexV2BJetTags",1);
   fChain->SetBranchStatus("jetpfCombinedMVAV2BJetTags",1);
   fChain->SetBranchStatus("jetPFLooseId",1);
   fChain->SetBranchStatus("nAK8Jet",1);
   fChain->SetBranchStatus("AK8JetPt",1);
   fChain->SetBranchStatus("AK8JetEta",1);
   fChain->SetBranchStatus("AK8JetPhi",1);
   fChain->SetBranchStatus("AK8JetMass",1);
   fChain->SetBranchStatus("AK8CHSPrunedJetMass",1);
   fChain->SetBranchStatus("AK8CHSPrunedJetMassCorr",1);
   fChain->SetBranchStatus("AK8JetPFLooseId",1);
   fChain->SetBranchStatus("AK8JetpfBoostedDSVBTag",1);

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   
   TFile f_dataPU("/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/ggNtuple_AOD_PU.root","read");
   TH1D *hdata_nPU = (TH1D*)f_dataPU.Get("pileup");
   hdata_nPU->SetDirectory(0);
   f_dataPU.Close();

   TFile f("skimmed_data_histos.root","recreate");

   TH1D *hdata_cuts = new TH1D("hdata_cuts","cuts;HLT,PhoID,PhoEt,pfMET,btag,Hmass",10,0,10);
   TH1D *hdata_nVtx = new TH1D("hdata_nVtx",";nVtx",50,0,50);

   TH1D *hdata_phoEtL = new TH1D("hdata_phoEtL",";phoEtL",30,0,1000);
   TH1D *hdata_phoEtM = new TH1D("hdata_phoEtM",";phoEtM",30,0,1000);
   TH1D *hdata_phoEtT = new TH1D("hdata_phoEtT",";phoEtT",30,0,1000);
   TH1D *hdata_phoEtaL = new TH1D("hdata_phoEtaL",";EtaL",30,-3,3);
   TH1D *hdata_phoEtaM = new TH1D("hdata_phoEtaM",";EtaM",30,-3,3);
   TH1D *hdata_phoEtaT = new TH1D("hdata_phoEtaT",";EtaT",30,-3,3);
   TH1D *hdata_pfMET = new TH1D("hdata_pfMET",";pfMET",30,0,1000);
   TH1D *hdata_pfMETsumEt = new TH1D("hdata_pfMETsumEt",";pfMETsumEt",30,-50,5000);
   TH1D *hdata_pfMETPhi = new TH1D("hdata_pfMETPhi",";pfMETPhi",30,-4,4);
   TH1D *hdata_pfMETmEtSig = new TH1D("hdata_pfMETmEtSig",";pfMETmEtSig",30,0,1000);
   TH1D *hdata_pfMETSig = new TH1D("hdata_pfMETSig",";pfMETSig",30,0,1000);
   TH1D *hdata_nPho = new TH1D("hdata_nPho",";nPho",10,0,10);
   TH1D *hdata_nTrksPV = new TH1D("hdata_nTrksPV",";nTrksPV",30,0,500);
   TH1D *hdata_nEle= new TH1D("hdata_nEle",";nEle",10,0,10);
   TH1D *hdata_nEleM= new TH1D("hdata_nEleM",";nEleM",10,0,10);
   TH1D *hdata_nEleT= new TH1D("hdata_nEleT",";nEleT",10,0,10);
   TH1D *hdata_nMu= new TH1D("hdata_nMu",";nMu",10,0,10);
   TH1D *hdata_nMuM= new TH1D("hdata_nMuM",";nMuM",10,0,10);
   TH1D *hdata_nMuT= new TH1D("hdata_nMuT",";nMuT",10,0,10);

   TH1D *hdata_njets = new TH1D("hdata_njets",";# of jets",10,0,10);
   TH1D *hdata_jetpt = new TH1D("hdata_jetpt","Leading jetpt;jetpt",50,0,2000);
   TH1D *hdata_nAK8jets = new TH1D("hdata_nAK8jets",";# of AK8jets",10,0,10);
   TH1D *hdata_AK8jetpt = new TH1D("hdata_AK8jetpt","Leading AK8jetpt;AK8jetpt",50,0,2000);
   TH1D *hdata_AK8bjetpt = new TH1D("hdata_AK8bjetpt","Btagged AK8jetpt;AK8bjetpt",50,0,2000);
   TH1D *hdata_AK8ljetmass = new TH1D("hdata_AK8ljetmass","Leading AK8jetmass;AK8jetmass",30,0,700);
   TH1D *hdata_AK8bjetmass = new TH1D("hdata_AK8bjetmass","Btagged AK8jetmass;AK8jetmass",30,0,700);
   TH1D *hdata_AK8jetmass = new TH1D("hdata_AK8jetmass","AK8jetmass;AK8jetmass",30,0,700);
   TH1D *hdata_AK8bPrunedjetmass = new TH1D("hdata_AK8bPrunedjetmass","Btagged AK8Prunedjetmass;AK8Prunedjetmass",30,0,700);
   TH1D *hdata_AK8bPrunedCorrjetmass = new TH1D("hdata_AK8bPrunedCorrjetmass","Btagged AK8PrunedCorrjetmass;AK8PrunedCorrjetmass",30,0,700);
   
   TH1D *hdata_CSVbjetsL = new TH1D("hdata_CSVbjetsL",";# of CSVLoosebjets",10,0,10);
   TH1D *hdata_CSVbjetsM = new TH1D("hdata_CSVbjetsM",";# of CSVMediumbjets",10,0,10);
   TH1D *hdata_CSVbjetsT = new TH1D("hdata_CSVbjetsT",";# of CSVTightbjets",10,0,10);
   TH1D *hdata_cMVAbjetsL = new TH1D("hdata_cMVAbjetsL",";# of cMVALoosebjets",10,0,10);
   TH1D *hdata_cMVAbjetsM = new TH1D("hdata_cMVAbjetsM",";# of cMVAMediumbjets",10,0,10);
   TH1D *hdata_cMVAbjetsT = new TH1D("hdata_cMVAbjetsT",";# of cMVATightbjets",10,0,10);
   TH1D *hdata_BDSVbjetsL = new TH1D("hdata_BDSVbjetsL",";# of BDSVLoosebjets",10,0,10);
   TH1D *hdata_BDSVbjetsM = new TH1D("hdata_BDSVbjetsM",";# of BDSVMediumbjets",10,0,10);
   TH1D *hdata_BDSVbjetsT = new TH1D("hdata_BDSVbjetsT",";# of BDSVTightbjets",10,0,10);
    
   TH1D *hdata_dRphoAK8jet= new TH1D("hdata_dRphoAK8jet","Distance between leading photon and leading AK8jet;dR",30,0,8);
   
   TH1D *hdata_doubleB = new TH1D("hdata_doubleB","Highest jetPt;BoostedDoubleSVTagger",30,-1,1);
   TH1D *hdata_doubleB_highdB = new TH1D("hdata_doubleB_highdB","Highest Boosted;BoostedDoubleSVTagger",30,-1,1);
   TH1D *hdata_bjetCSV= new TH1D("hdata_bjetCSV","Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags",30,0,1);
   TH1D *hdata_bjetCSV2= new TH1D("hdata_bjetCSV2","2nd Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags",30,0,1);
   TH1D *hdata_bjetcMVA = new TH1D("hdata_bjetcMVA","Highest cMVA;CombinedMVAV2BJetTags",30,-1,1);
   TH1D *hdata_bjetcMVA2 = new TH1D("hdata_bjetcMVA2","2nd Highest cMVA;CombinedMVAV2BJetTags",30,-1,1);
  
   TH1D *hdata_HT_before = new TH1D("hdata_HT_before","HT before cuts;HT",50,0,3500);
   TH1D *hdata_EMHT_before = new TH1D("hdata_EMHT_before","EMHT before cuts;EMHT",50,0,3500);
   TH1D *hdata_HT_after = new TH1D("hdata_HT_after","HT after cuts;HT",50,0,3500);
   TH1D *hdata_EMHT_after = new TH1D("hdata_EMHT_after","EMHT after cuts;EMHT",50,0,3500);

   TH1D *hdata_AK8HT_before = new TH1D("hdata_AK8HT_before","AK8HT before cuts;HT",50,0,3500);
   TH1D *hdata_AK8EMHT_before = new TH1D("hdata_AK8EMHT_before","AK8EMHT before cuts;EMHT",50,0,3500);
   TH1D *hdata_AK8HT_after = new TH1D("hdata_AK8HT_after","AK8HT after cuts;HT",50,0,3500);
   TH1D *hdata_AK8EMHT_after = new TH1D("hdata_AK8EMHT_after","AK8EMHT after cuts;EMHT",50,0,3500);

   fChain->ls();
   int file_counter=-1; std::string temp_f="";
   int temp=-1;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
     //progress bar
     double progress=(jentry+1)/double(nentries);
     if (temp!=int(progress * 100.0)){
       temp=int(progress * 100.0);
       std::cout << temp << " %\r";
       std::cout.flush();
     }
      nb = fChain->GetEntry(jentry);   nbytes += nb;
     bool newfile=false;

     if (temp_f != fChain->GetCurrentFile()->GetName()) {
       temp_f=fChain->GetCurrentFile()->GetName();
       file_counter++;
       std::cout<<"file "<<file_counter<<" "<<fChain->GetCurrentFile()->GetName()<<std::endl;
       newfile=true;
     }
     //object definitions
     int nleadPhoL=-1, nleadPhoM=-1, nleadPhoT=-1;
     int leadpt_ak4=-1, leadpt_ak8=-1, highBDSV=-1, highCSV1=-1, highCSV2=-1, highcMVA1=-1, highcMVA2=-1;
     std::vector<int> passPhoL, passPhoM, passPhoT, passJet, passAK8Jet, passEleL, passEleM, passEleT, passMuL, passMuM, passMuT;
     passPhoL.clear(); passPhoM.clear(); passPhoT.clear(); passJet.clear(); passAK8Jet.clear(); passEleL.clear(); passEleM.clear(); passEleT.clear(); passMuL.clear(); passMuM.clear(); passMuT.clear();
     double HT_before=0, EMHT_before=0, HT_after=0, EMHT_after=0;
     double AK8HT_before=0, AK8EMHT_before=0, AK8HT_after=0, AK8EMHT_after=0;
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
     for (int i=0;i<passPhoL.size();i++) {
       if ((*phoEt)[passPhoL.at(i)]>(*phoEt)[nleadPhoL]) nleadPhoL=passPhoL.at(i);
       EMHT_before+=(*phoEt)[passPhoL.at(i)];
     }
     for (int i=0;i<passPhoM.size();i++) if ((*phoEt)[passPhoM.at(i)]>(*phoEt)[nleadPhoM]) nleadPhoM=passPhoL.at(i);
     for (int i=0;i<passPhoT.size();i++) if ((*phoEt)[passPhoT.at(i)]>(*phoEt)[nleadPhoT]) nleadPhoT=passPhoL.at(i);
     EMHT_after=EMHT_before;
     AK8EMHT_before=EMHT_before;
     AK8EMHT_after=EMHT_before;
     //electron
     for (int i=0;i<nEle;i++) {
     /*
       if (abs((*eleEta)[i])<=0.8 && (*elePt)[i]>5 && (*elePt)[i]<10) if ((*eleIDMVANonTrg)[i]>-0.083313) passEleL.push_back(i);
       if (abs((*eleEta)[i])<=0.8 && (*elePt)[i]>=10) if ((*eleIDMVANonTrg)[i]>0.913286) passEleL.push_back(i);
       if (abs((*eleEta)[i])>0.8 && abs((*eleEta)[i])<1.4442 && (*elePt)[i]>5 && (*elePt)[i]<10) if ((*eleIDMVANonTrg)[i]>-0.235222) passEleL.push_back(i);
       if (abs((*eleEta)[i])>0.8 && abs((*eleEta)[i])<1.4442 && (*elePt)[i]>=10) if ((*eleIDMVANonTrg)[i]>0.805013) passEleL.push_back(i);
     */
       if ((*eleIDbit)[i]>>1&1) passEleL.push_back(i);
       if ((*eleIDbit)[i]>>2&1) passEleM.push_back(i);
       if ((*eleIDbit)[i]>>3&1) passEleT.push_back(i);
     }
     //muon
     for (int i=0;i<nMu;i++) {
       if ((*muIsLooseID)[i]==1) passMuL.push_back(i);
       if ((*muIsMediumID)[i]==1) passMuM.push_back(i);
       if ((*muIsTightID)[i]==1) passMuT.push_back(i);
     }
     //jet
     for (int i=0;i<nJet;i++) {
       bool passcut=true;
       HT_before+=(*jetPt)[i];
       if (abs((*jetEta)[i])>3 || (*jetPFLooseId)[i]==0 || (*jetPt)[i]<40) passcut=false;
       for (int j=0;j<passPhoL.size();j++) if (deltaR((*jetPhi)[i],(*phoPhi)[passPhoL.at(j)],(*jetEta)[i],(*phoEta)[passPhoL.at(j)])<0.3) {
         passcut=false;break;
       }
       for (int j=0;j<passEleL.size();j++) if (deltaR((*jetPhi)[i],(*elePhi)[passEleL.at(j)],(*jetEta)[i],(*eleEta)[passEleL.at(j)])<0.3) {
         passcut=false;break;
       }
       for (int j=0;j<passMuT.size();j++) if (deltaR((*jetPhi)[i],(*muPhi)[passMuT.at(j)],(*jetEta)[i],(*muEta)[passMuT.at(j)])<0.3) {
         passcut=false;break;
       }
       if (passcut) passJet.push_back(i);
     }
     //jet pt, btags
     int bcounterCSV[3]={}, bcountercMVA[3]={}, bcounterBDSV[3]={};
     double CSV1_val=-9999, CSV2_val=-9999, cMVA1_val=-9999, cMVA2_val=-9999;
     for (int i=0;i<passJet.size();i++){
       if ((*jetPt)[passJet.at(i)]>(*jetPt)[leadpt_ak4]) leadpt_ak4=passJet.at(i);
       HT_after+=(*jetPt)[passJet.at(i)];
       if (highCSV1!=-1) CSV1_val=(*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV1];
       if (highCSV2!=-1) CSV2_val=(*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV2];
       if (highcMVA1!=-1) cMVA1_val=(*jetpfCombinedMVAV2BJetTags)[highcMVA1];
       if (highcMVA2!=-1) cMVA2_val=(*jetpfCombinedMVAV2BJetTags)[highcMVA2];
       if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>CSV1_val) {highCSV2=highCSV1;highCSV1=passJet.at(i);}
       else if (highCSV2!=-1) if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>CSV2_val) highCSV2=passJet.at(i);
       if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>cMVA1_val) {highcMVA2=highcMVA1;highcMVA1=passJet.at(i);}
       else if (highcMVA2!=-1) if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>cMVA2_val) highcMVA2=passJet.at(i);
       if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>BtagCSVWP[0]) bcounterCSV[0]++;
       if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>BtagCSVWP[1]) bcounterCSV[1]++;
       if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>BtagCSVWP[2]) bcounterCSV[2]++;
       if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[0]) bcountercMVA[0]++;
       if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[1]) bcountercMVA[1]++;
       if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[2]) bcountercMVA[2]++;
     }
     EMHT_before+=HT_before;
     EMHT_after+=HT_after;
     //AK8Jet
     for (int i=0;i<nAK8Jet;i++) {
       bool passcut=true;
       AK8HT_before+=(*AK8JetPt)[i];
       if (abs((*AK8JetEta)[i])>3 || (*AK8JetPFLooseId)[i]==0 || (*AK8JetPt)[i]<40) passcut=false;
       for (int j=0;j<passPhoL.size();j++) if (deltaR((*AK8JetPhi)[i],(*phoPhi)[passPhoL.at(j)],(*AK8JetEta)[i],(*phoEta)[passPhoL.at(j)])<0.3) {
         passcut=false;break;
       }
       for (int j=0;j<passEleL.size();j++) if (deltaR((*AK8JetPhi)[i],(*elePhi)[passEleL.at(j)],(*AK8JetEta)[i],(*eleEta)[passEleL.at(j)])<0.3) {
         passcut=false;break;
       }
       for (int j=0;j<passMuT.size();j++) if (deltaR((*AK8JetPhi)[i],(*muPhi)[passMuT.at(j)],(*AK8JetEta)[i],(*muEta)[passMuT.at(j)])<0.3) {
         passcut=false;break;
       }
       if (passcut) passAK8Jet.push_back(i);
     }
     //AK8Jet pt, btag
     for (int i=0;i<passAK8Jet.size();i++) {
       if ((*AK8JetPt)[passAK8Jet.at(i)]>(*AK8JetPt)[leadpt_ak8]) leadpt_ak8=passAK8Jet.at(i);
       AK8HT_after+=(*AK8JetPt)[passAK8Jet.at(i)];
       double i_jetdB=(*AK8JetpfBoostedDSVBTag)[passAK8Jet.at(i)], h_jetdB;
       if (highBDSV==-1) h_jetdB=-10; else h_jetdB=(*AK8JetpfBoostedDSVBTag)[highBDSV];
       if (i_jetdB>h_jetdB) highBDSV=passAK8Jet.at(i);
       if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet.at(i)]>BtagBDSVWP[0]) bcounterBDSV[0]++;
       if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet.at(i)]>BtagBDSVWP[1]) bcounterBDSV[1]++;
       if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet.at(i)]>BtagBDSVWP[2]) bcounterBDSV[2]++;
     }
     AK8EMHT_before+=HT_before;
     AK8EMHT_after+=HT_after;
     //dR between leading photon & leading pt AK8
     double dR_pho_AK8=-1;
     if (abs((*AK8JetEta)[leadpt_ak8])<1.4442){
       dR_pho_AK8=deltaR((*AK8JetPhi)[leadpt_ak8],(*phoPhi)[nleadPhoT],(*AK8JetEta)[leadpt_ak8],(*phoEta)[nleadPhoT]);
     }
     //cuts
     //if (passAK8Jet.size()==0) continue;
     //if (passPhoL.size()>0 && (*phoEt)[nleadPhoL]>175 && (*AK8JetpfBoostedDSVBTag)[highBDSV]>=BtagBDSVWPWP[2]){
     if (!HLTPho&128) continue; //HLT_Photon175
     hdata_cuts->Fill(0);
     if (passPhoL.size()==0) continue;
     hdata_cuts->Fill(1);
     if ((*phoEt)[nleadPhoL]<175) continue;
     hdata_cuts->Fill(2);
     if (!metFilters&126) continue;
     if (pfMET<100) continue;
     hdata_cuts->Fill(3);
     //if ((*AK8JetpfBoostedDSVBTag)[highBDSV]<BtagBDSVWP[0]) continue;
     //hdata_cuts->Fill(4);
     //if ((*AK8CHSPrunedJetMassCorr)[highBDSV]<70 || (*AK8CHSPrunedJetMassCorr)[highBDSV]>200) continue;
     //hdata_cuts->Fill(5);
     //if (passPhoL.size()>0 && (*phoEt)[nleadPhoL]>175 && pfMET>100 && (*AK8JetpfBoostedDSVBTag)[highBDSV]>=BtagBDSVWP[0] && (*AK8CHSPrunedJetMassCorr)[highBDSV]>70 && (*AK8CHSPrunedJetMassCorr)[highBDSV]<200){
         //Filling histograms
         hdata_phoEtL->Fill((*phoEt)[nleadPhoL]);
         hdata_phoEtaL->Fill((*phoEta)[nleadPhoL]);
         if (passPhoM.size()>0 && (*phoEt)[nleadPhoM]>175) hdata_phoEtM->Fill((*phoEt)[nleadPhoM]);
         if (passPhoM.size()>0 && (*phoEt)[nleadPhoM]>175) hdata_phoEtaM->Fill((*phoEta)[nleadPhoM]);
         if (passPhoT.size()>0 && (*phoEt)[nleadPhoT]>175) hdata_phoEtT->Fill((*phoEt)[nleadPhoT]);
         if (passPhoT.size()>0 && (*phoEt)[nleadPhoT]>175) hdata_phoEtaT->Fill((*phoEta)[nleadPhoT]);
         hdata_nVtx->Fill(nVtx);
         hdata_HT_before->Fill(HT_before);
         hdata_EMHT_before->Fill(EMHT_before);
         hdata_HT_after->Fill(HT_after);
         hdata_EMHT_after->Fill(EMHT_after);
         hdata_AK8HT_before->Fill(AK8HT_before);
         hdata_AK8EMHT_before->Fill(AK8EMHT_before);
         hdata_AK8HT_after->Fill(AK8HT_after);
         hdata_AK8EMHT_after->Fill(AK8EMHT_after);
         hdata_nAK8jets->Fill(passAK8Jet.size());
         //if (metFilters&126) hdata_pfMET->Fill(pfMET);
         hdata_pfMET->Fill(pfMET);
         hdata_nPho->Fill(passPhoL.size());
         hdata_nTrksPV->Fill(nTrksPV);
         hdata_njets->Fill(passJet.size());
         hdata_CSVbjetsL->Fill(bcounterCSV[0]);
         hdata_CSVbjetsM->Fill(bcounterCSV[1]);
         hdata_CSVbjetsT->Fill(bcounterCSV[2]);
         hdata_cMVAbjetsL->Fill(bcountercMVA[0]);
         hdata_cMVAbjetsM->Fill(bcountercMVA[1]);
         hdata_cMVAbjetsT->Fill(bcountercMVA[2]);
         hdata_BDSVbjetsL->Fill(bcounterBDSV[0]);
         hdata_BDSVbjetsM->Fill(bcounterBDSV[1]);
         hdata_BDSVbjetsT->Fill(bcounterBDSV[2]);
         if (highCSV1!=-1) hdata_bjetCSV->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV1]);
         if (highCSV2!=-1) hdata_bjetCSV2->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV2]);
         if (highcMVA1!=-1) hdata_bjetcMVA->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA1]);
         if (highcMVA2!=-1) hdata_bjetcMVA2->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA2]);
         if (leadpt_ak8!=-1) hdata_doubleB->Fill((*AK8JetpfBoostedDSVBTag)[leadpt_ak8]);
         if (highBDSV!=-1) hdata_doubleB_highdB->Fill((*AK8JetpfBoostedDSVBTag)[highBDSV]);
         for (int i=0;i<passAK8Jet.size();i++) hdata_AK8jetmass->Fill((*AK8JetMass)[passAK8Jet.at(i)]);
         hdata_nEle->Fill(passEleL.size());
         hdata_nEleM->Fill(passEleM.size());
         hdata_nEleT->Fill(passEleT.size());
         hdata_nMu->Fill(passMuL.size());
         hdata_nMuM->Fill(passMuM.size());
         hdata_nMuT->Fill(passMuT.size());
         if (leadpt_ak4!=-1) hdata_jetpt->Fill((*jetPt)[leadpt_ak4]);
         if (leadpt_ak8!=-1) hdata_AK8jetpt->Fill((*AK8JetPt)[leadpt_ak8]);
         if (highBDSV!=-1) hdata_AK8jetpt->Fill((*AK8JetPt)[highBDSV]);
         if (leadpt_ak8!=-1) hdata_AK8ljetmass->Fill((*AK8JetMass)[leadpt_ak8]);
         if (leadpt_ak8!=-1) hdata_AK8bjetmass->Fill((*AK8JetMass)[highBDSV]);
         if (leadpt_ak8!=-1) hdata_AK8bPrunedjetmass->Fill((*AK8CHSPrunedJetMass)[highBDSV]);
         if (leadpt_ak8!=-1) hdata_AK8bPrunedCorrjetmass->Fill((*AK8CHSPrunedJetMassCorr)[highBDSV]);
         if (dR_pho_AK8!=-1) hdata_dRphoAK8jet->Fill(dR_pho_AK8);
     //}//phoid cut 
   }
   hdata_nPU->Write();
   f.Write();
   f.Close();
}
