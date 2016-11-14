#define skimmed_mc_cxx
#include "skimmed_mc.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

double deltaR(double phi1, double phi2, double eta1, double eta2){
  double dR=0;
  if (abs(phi1-phi2)>M_PI) dR=sqrt(pow(phi2-phi1,2)+pow(eta1-eta2,2));
  else dR=sqrt(pow(phi1-phi2,2)+pow(eta1-eta2,2));
  return dR;
}

void skimmed_mc::Loop()
{
//   In a ROOT session, you can do:
//      root> .L skimmed_mc.C
//      root> skimmed_mc t
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
   fChain->SetBranchStatus("genWeight",1);
   fChain->SetBranchStatus("pfMET",1);
   fChain->SetBranchStatus("pfMETPhi",1);
   fChain->SetBranchStatus("pfMETsumEt",1);
   fChain->SetBranchStatus("pfMETmEtSig",1);
   fChain->SetBranchStatus("pfMETSig",1);
   fChain->SetBranchStatus("nPUInfo",1);
   fChain->SetBranchStatus("nPU",1);
   fChain->SetBranchStatus("puBX",1);
   fChain->SetBranchStatus("puTrue",1);
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
   fChain->SetBranchStatus("nMC",1);
   fChain->SetBranchStatus("mcPID",1);
   fChain->SetBranchStatus("mcMomPID",1);
   fChain->SetBranchStatus("mcGMomPID",1);
   fChain->SetBranchStatus("mcVtx",1);
   fChain->SetBranchStatus("mcVty",1);
   fChain->SetBranchStatus("mcVtz",1);
   fChain->SetBranchStatus("mcPt",1);
   fChain->SetBranchStatus("mcE",1);
   fChain->SetBranchStatus("mcEt",1);
   fChain->SetBranchStatus("mcPhi",1);
   fChain->SetBranchStatus("mcEta",1);
   fChain->SetBranchStatus("mcIndex",1);
   fChain->SetBranchStatus("mcStatus",1);
   fChain->SetBranchStatus("genMET",1);
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
   //double L_data=2689.38644;
   //L_data=4369.850;
   L_data=30000;
   //L_data=4369.850;

   //pu reweight
   TFile f_dataPU("/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/ggNtuple_dec16_PU_norm.root","read");
   TH1D *h_dataPU = (TH1D*)f_dataPU.Get("pileup");
   h_dataPU->SetDirectory(0);
   f_dataPU.Close();

   TFile f("skimmed_mc_histos.root","recreate");
   for (Int_t i=0;i<nfile;i++){
     h_PUweight[i] = (TH1D*)h_dataPU->Clone(Form("h_PUweight[%i]",i));
     h_PUweight[i]->SetDirectory(0);
     
     hbkg_cuts[i] = new TH1D(Form("hbkg_cuts[%i]",i),std::string(mc_input_file[i]+" cuts;HLT,PhoID,PhoEt,pfMET,btag,Hmass").c_str(),10,0,10);
     hbkg_nVtx[i] = new TH1D(Form("hbkg_nVtx[%i]",i),std::string(mc_input_file[i]+";nVtx").c_str(),50,0,50);
     hbkg_nPU[i] = new TH1D(Form("hbkg_nPU[%i]",i),std::string(mc_input_file[i]+";nPU").c_str(),50,0,50);

     hbkg_phoEtL[i] = new TH1D(Form("hbkg_phoEtL[%i]",i),std::string(mc_input_file[i]+";phoEt").c_str(),30,0,1000);
     hbkg_phoEtM[i] = new TH1D(Form("hbkg_phoEtM[%i]",i),std::string(mc_input_file[i]+";phoEt").c_str(),30,0,1000);
     hbkg_phoEtT[i] = new TH1D(Form("hbkg_phoEtT[%i]",i),std::string(mc_input_file[i]+";phoEt").c_str(),30,0,1000);
     hbkg_phoEtaL[i]= new TH1D(Form("hbkg_phoEtaL[%i]",i),std::string(mc_input_file[i]+";Eta").c_str(),30,-3,3);
     hbkg_phoEtaM[i]= new TH1D(Form("hbkg_phoEtaM[%i]",i),std::string(mc_input_file[i]+";Eta").c_str(),30,-3,3);
     hbkg_phoEtaT[i]= new TH1D(Form("hbkg_phoEtaT[%i]",i),std::string(mc_input_file[i]+";Eta").c_str(),30,-3,3);
     hbkg_pfMET[i]= new TH1D(Form("hbkg_pfMET[%i]",i),std::string(mc_input_file[i]+";pfMET").c_str(),30,0,1000);
     hbkg_pfMETsumEt[i] = new TH1D(Form("hbkg_pfMETsumEt[%i]",i),std::string(mc_input_file[i]+";pfMETsumEt").c_str(),30,-50,5000);
     hbkg_pfMETPhi[i] = new TH1D(Form("hbkg_pfMET[%i]",i),std::string(mc_input_file[i]+";pfMET").c_str(),30,-4,4);
     hbkg_pfMETmEtSig[i] = new TH1D(Form("hbkg_pfMET[%i]",i),std::string(mc_input_file[i]+";pfMET").c_str(),30,0,1000);
     hbkg_pfMETSig[i] = new TH1D(Form("hbkg_pfMET[%i]",i),std::string(mc_input_file[i]+";pfMET").c_str(),30,0,1000);
     hbkg_nPho[i]= new TH1D(Form("hbkg_nPho[%i]",i),std::string(mc_input_file[i]+";nPho").c_str(),10,0,10);
     hbkg_nTrksPV[i]= new TH1D(Form("hbkg_nTrksPV[%i]",i),std::string(mc_input_file[i]+";nTrksPV").c_str(),30,0,500);
     hbkg_nEle[i]= new TH1D(Form("hbkg_nEle[%i]",i),std::string(mc_input_file[i]+";nEle").c_str(),10,0,10);
     hbkg_nEleM[i]= new TH1D(Form("hbkg_nEleM[%i]",i),std::string(mc_input_file[i]+" MediumID electrons;nEle").c_str(),10,0,10);
     hbkg_nEleT[i]= new TH1D(Form("hbkg_nEleT[%i]",i),std::string(mc_input_file[i]+" TightID electrons;nEle").c_str(),10,0,10);
     hbkg_nMu[i]= new TH1D(Form("hbkg_nMu[%i]",i),std::string(mc_input_file[i]+";nMu").c_str(),10,0,10);
     hbkg_nMuM[i]= new TH1D(Form("hbkg_nMuM[%i]",i),std::string(mc_input_file[i]+" MediumID muons;nMu").c_str(),10,0,10);
     hbkg_nMuT[i]= new TH1D(Form("hbkg_nMuT[%i]",i),std::string(mc_input_file[i]+" TightID muons;nMu").c_str(),10,0,10);
     
     hbkg_njets[i] = new TH1D(Form("hbkg_njets[%i]",i),std::string(mc_input_file[i]+";# of jets").c_str(),10,0,10);
     hbkg_CSVbjetsL[i] = new TH1D(Form("hbkg_CSVbjetsL[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_CSVbjetsM[i] = new TH1D(Form("hbkg_CSVbjetsM[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_CSVbjetsT[i] = new TH1D(Form("hbkg_CSVbjetsT[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_cMVAbjetsL[i] = new TH1D(Form("hbkg_cMVAbjetsL[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_cMVAbjetsM[i] = new TH1D(Form("hbkg_cMVAbjetsM[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_cMVAbjetsT[i] = new TH1D(Form("hbkg_cMVAbjetsT[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_BDSVbjetsL[i] = new TH1D(Form("hbkg_BDSVbjetsL[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_BDSVbjetsM[i] = new TH1D(Form("hbkg_BDSVbjetsM[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_BDSVbjetsT[i] = new TH1D(Form("hbkg_BDSVbjetsT[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_jetpt[i] = new TH1D(Form("hbkg_jetpt[%i]",i),std::string(mc_input_file[i]+" Leading jetpt;jetpt").c_str(),50,0,2000);
     hbkg_nAK8jets[i] = new TH1D(Form("hbkg_nAK8jets[%i]",i),std::string(mc_input_file[i]+";# of AK8jets").c_str(),10,0,10);
     hbkg_AK8jetpt[i] = new TH1D(Form("hbkg_AK8jetpt[%i]",i),std::string(mc_input_file[i]+" Leading AK8jetpt;AK8jetpt").c_str(),50,0,2000);
     hbkg_AK8bjetpt[i] = new TH1D(Form("hbkg_AK8bjetpt[%i]",i),std::string(mc_input_file[i]+" Btagged AK8jetpt;AK8bjetpt").c_str(),50,0,2000);
     hbkg_AK8ljetmass[i] = new TH1D(Form("hbkg_AK8ljetmass[%i]",i),std::string(mc_input_file[i]+" Leading AK8jetmass;AK8jetmass").c_str(),30,0,700);
     hbkg_AK8bjetmass[i] = new TH1D(Form("hbkg_AK8bjetmass[%i]",i),std::string(mc_input_file[i]+" Btagged AK8jetmass;AK8jetmass").c_str(),30,0,700);
     hbkg_AK8bPrunedjetmass[i] = new TH1D(Form("hbkg_AK8bPrunedjetmass[%i]",i),std::string(mc_input_file[i]+" Btagged AK8Prunedjetmass;Pruned AK8jetmass").c_str(),30,0,700);
     hbkg_AK8bPrunedCorrjetmass[i] = new TH1D(Form("hbkg_AK8bPrunedCorrjetmass[%i]",i),std::string(mc_input_file[i]+" Btagged AK8PrunedCorrjetmass;Pruned Corr AK8jetmass").c_str(),30,0,700);
     hbkg_AK8jetmass[i] = new TH1D(Form("hbkg_AK8jetmass[%i]",i),std::string(mc_input_file[i]+" AK8jetmass;AK8jetmass").c_str(),30,0,700);
     
     hbkg_dRphoAK8jet[i]= new TH1D(Form("hbkg_dRphoAK8jet[%i]",i),std::string(mc_input_file[i]+" Distance between leading photon and leading AK8jet;dR").c_str(),30,0,8);
     
     hbkg_doubleB[i] = new TH1D(Form("hbkg_doubleB[%i]",i),std::string(mc_input_file[i]+";BoostedDoubleSVTagger").c_str(),30,-1,1);
     hbkg_doubleB_highdB[i] = new TH1D(Form("hbkg_doubleB_highdB[%i]",i),std::string(mc_input_file[i]+" Highest Boosted;BoostedDoubleSVTagger").c_str(),30,-1,1);
     hbkg_bjetCSV[i]= new TH1D(Form("hbkg_bjetCSV[%i]",i),std::string(mc_input_file[i]+" Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags").c_str(),30,0,1);
     hbkg_bjetCSV2[i]= new TH1D(Form("hbkg_bjetCSV2[%i]",i),std::string(mc_input_file[i]+" 2nd Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags").c_str(),30,0,1);
     hbkg_bjetcMVA[i] = new TH1D(Form("hbkg_bjetcMVA[%i]",i),std::string(mc_input_file[i]+" Highest cMVA;CombinedMVAV2BJetTags").c_str(),30,0,1);
     hbkg_bjetcMVA2[i] = new TH1D(Form("hbkg_bjetcMVA2[%i]",i),std::string(mc_input_file[i]+" 2nd Highest cMVA;CombinedMVAV2BJetTags").c_str(),30,0,1);
     
     hbkg_HT_before[i] = new TH1D(Form("hbkg_HT_before[%i]",i),std::string(mc_input_file[i]+" HT before cuts;HT").c_str(),50,0,3500);
     hbkg_EMHT_before[i] = new TH1D(Form("hbkg_EMHT_before[%i]",i),std::string(mc_input_file[i]+" EMHT before cuts;EMHT").c_str(),50,0,3500);
     hbkg_HT_after[i] = new TH1D(Form("hbkg_HT_after[%i]",i),std::string(mc_input_file[i]+" HT after cuts;HT").c_str(),50,0,3500);
     hbkg_EMHT_after[i] = new TH1D(Form("hbkg_EMHT_after[%i]",i),std::string(mc_input_file[i]+" EMHT after cuts;EMHT").c_str(),50,0,3500);
     
     hbkg_AK8HT_before[i] = new TH1D(Form("hbkg_AK8HT_before[%i]",i),std::string(mc_input_file[i]+" AK8HT before cuts;HT").c_str(),50,0,3500);
     hbkg_AK8EMHT_before[i] = new TH1D(Form("hbkg_AK8EMHT_before[%i]",i),std::string(mc_input_file[i]+" AK8EMHT before cuts;EMHT").c_str(),50,0,3500);
     hbkg_AK8HT_after[i] = new TH1D(Form("hbkg_AK8HT_after[%i]",i),std::string(mc_input_file[i]+" AK8HT after cuts;HT").c_str(),50,0,3500);
     hbkg_AK8EMHT_after[i] = new TH1D(Form("hbkg_AK8EMHT_after[%i]",i),std::string(mc_input_file[i]+" AK8EMHT after cuts;EMHT").c_str(),50,0,3500);
   }

   fChain->ls();
   int file_counter=-1; std::string temp_f="";
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<10000;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;

     bool newfile=false;

     if (temp_f != fChain->GetCurrentFile()->GetName()) {
       temp_f=fChain->GetCurrentFile()->GetName();
       file_counter++;
       //if (file_counter==6) {file_counter++; std::cout<<"file 6 /afs/cern.ch/work/m/mbartok/public/mc/ggNtuple/skimmed/job_spring15_qcd_HT200To300_25ns_cutbased.root has 0 Events"<<std::endl;}
       std::cout<<"file "<<file_counter<<" "<<fChain->GetCurrentFile()->GetName()<<std::endl;
       newfile=true;
     }

     //getting _h_cuts for cross sections and Nevents, and PU distribution
     TH1D *h_cuts = (TH1D*)fChain->GetCurrentFile()->Get("_h_cuts");
     if (newfile) {
       TH1D *h_mcPU = (TH1D*)fChain->GetCurrentFile()->Get("hPUTrue");
       h_mcPU->Rebin(5);
       h_mcPU->Scale(1/(h_mcPU->Integral()));
       h_PUweight[file_counter]->Divide(h_mcPU);
     }

     //weights
     int zbx=0;//get zero bunchcrossing (puTrue always the same for every bx, just in case...)
     for (int i=0;i<(*puBX).size();i++) if ((*puBX)[i]==0) zbx=i;
     //double pu_weight=h_PUweight[file_counter]->GetBinContent(h_PUweight[file_counter]->FindBin((*puTrue)[zbx]));
     double pu_weight=1; //no pu weight since this is 2015mc
     double weight=L_data*h_cuts->GetBinContent(1)/h_cuts->GetBinContent(2);
     double w=0;
     if (abs(genWeight)>1) w=copysign(weight*pu_weight,genWeight); //only a sign for amcatnlo
     else w=weight*pu_weight*genWeight; //0-1 for madgraph
     
     //cutflow
     //if (newfile){
     //  hbkg_cuts[file_counter]->SetBinContent(1,h_cuts->GetBinContent(2)*weight);
     //  hbkg_cuts[file_counter]->SetBinContent(2,h_cuts->GetBinContent(3)*weight);
     //}
     
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
     //jet ID
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
     for (int i=0;i<passJet.size();i++) {
       if ((*jetPt)[passJet.at(i)]>(*jetPt)[leadpt_ak4]) leadpt_ak4=passJet.at(i);
       HT_after+=(*jetPt)[passJet.at(i)];
       if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>(*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV1]) {highCSV2=highCSV1;highCSV1=passJet.at(i);}
       else if (highCSV2!=-1) if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>(*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV2]) highCSV2=passJet.at(i);
       if (file_counter>2){
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>(*jetpfCombinedMVAV2BJetTags)[highcMVA1]) {highcMVA2=highcMVA1;highcMVA1=passJet.at(i);}
         else if (highcMVA2!=-1) if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>(*jetpfCombinedMVAV2BJetTags)[highcMVA2]) highcMVA2=passJet.at(i);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[0]) bcountercMVA[0]++;
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[1]) bcountercMVA[1]++;
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[2]) bcountercMVA[2]++;
       }
       if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>BtagCSVWP[0]) bcounterCSV[0]++;
       if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>BtagCSVWP[1]) bcounterCSV[1]++;
       if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>BtagCSVWP[2]) bcounterCSV[2]++;
     }
     EMHT_before+=HT_before;
     EMHT_after+=HT_after;
     //AK8Jet ID
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
     if (!HLTPho&128) continue; //HLT_Photon175
     hbkg_cuts[file_counter]->Fill(0.,w);
     if (passPhoL.size()==0) continue;
     hbkg_cuts[file_counter]->Fill(1,w);
     if ((*phoEt)[nleadPhoL]<175) continue;
     hbkg_cuts[file_counter]->Fill(2,w);
     //if (!metFilters&126) continue;
     if (pfMET<100) continue;
     hbkg_cuts[file_counter]->Fill(3,w);
     if ((*AK8JetpfBoostedDSVBTag)[highBDSV]<BtagBDSVWP[0]) continue;
     hbkg_cuts[file_counter]->Fill(4,w);
     if ((*AK8CHSPrunedJetMassCorr)[highBDSV]<70 || (*AK8CHSPrunedJetMassCorr)[highBDSV]>200) continue;
     hbkg_cuts[file_counter]->Fill(5,w);
     //Filling histograms
     hbkg_phoEtL[file_counter]->Fill((*phoEt)[nleadPhoL],w);
     hbkg_phoEtaL[file_counter]->Fill((*phoEta)[nleadPhoL],w);
     if (passPhoM.size()>0 && (*phoEt)[nleadPhoM]>175) hbkg_phoEtM[file_counter]->Fill((*phoEt)[nleadPhoM],w);
     if (passPhoM.size()>0 && (*phoEt)[nleadPhoM]>175) hbkg_phoEtaM[file_counter]->Fill((*phoEta)[nleadPhoM],w);
     if (passPhoT.size()>0 && (*phoEt)[nleadPhoT]>175) hbkg_phoEtT[file_counter]->Fill((*phoEt)[nleadPhoT],w);
     if (passPhoT.size()>0 && (*phoEt)[nleadPhoT]>175) hbkg_phoEtaT[file_counter]->Fill((*phoEta)[nleadPhoT],w);
     hbkg_cuts[file_counter]->Fill(3,w);
     hbkg_nVtx[file_counter]->Fill(nVtx,w);
     hbkg_nPU[file_counter]->Fill((*puTrue)[zbx],w);
     hbkg_HT_before[file_counter]->Fill(HT_before,w);
     hbkg_EMHT_before[file_counter]->Fill(EMHT_before,w);
     hbkg_HT_after[file_counter]->Fill(HT_after,w);
     hbkg_EMHT_after[file_counter]->Fill(EMHT_after,w);
     hbkg_AK8HT_before[file_counter]->Fill(AK8HT_before,w);
     hbkg_AK8EMHT_before[file_counter]->Fill(AK8EMHT_before,w);
     hbkg_AK8HT_after[file_counter]->Fill(AK8HT_after,w);
     hbkg_AK8EMHT_after[file_counter]->Fill(AK8EMHT_after,w);
     hbkg_nAK8jets[file_counter]->Fill(passAK8Jet.size(),w);
     hbkg_pfMET[file_counter]->Fill(pfMET,w);
     hbkg_nPho[file_counter]->Fill(passPhoL.size(),w);
     hbkg_nTrksPV[file_counter]->Fill(nTrksPV,w);
     hbkg_njets[file_counter]->Fill(passJet.size(),w);
     hbkg_CSVbjetsL[file_counter]->Fill(bcounterCSV[0],w);
     hbkg_CSVbjetsM[file_counter]->Fill(bcounterCSV[1],w);
     hbkg_CSVbjetsT[file_counter]->Fill(bcounterCSV[2],w);
     hbkg_cMVAbjetsL[file_counter]->Fill(bcountercMVA[0],w);
     hbkg_cMVAbjetsM[file_counter]->Fill(bcountercMVA[1],w);
     hbkg_cMVAbjetsT[file_counter]->Fill(bcountercMVA[2],w);
     hbkg_BDSVbjetsL[file_counter]->Fill(bcounterBDSV[0],w);
     hbkg_BDSVbjetsM[file_counter]->Fill(bcounterBDSV[1],w);
     hbkg_BDSVbjetsT[file_counter]->Fill(bcounterBDSV[2],w);
     if (highCSV1!=-1) hbkg_bjetCSV[file_counter]->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV1],w);
     if (highCSV2!=-1) hbkg_bjetCSV2[file_counter]->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV2],w);
     if (highcMVA1!=-1) hbkg_bjetcMVA[file_counter]->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA1],w);
     if (highcMVA2!=-1) hbkg_bjetcMVA2[file_counter]->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA2],w);
     if (leadpt_ak8!=-1) hbkg_doubleB[file_counter]->Fill((*AK8JetpfBoostedDSVBTag)[leadpt_ak8],w);
     if (highBDSV!=-1) hbkg_doubleB_highdB[file_counter]->Fill((*AK8JetpfBoostedDSVBTag)[highBDSV],w);
     for (int i=0;i<passAK8Jet.size();i++) hbkg_AK8jetmass[file_counter]->Fill((*AK8JetMass)[passAK8Jet.at(i)],w);
     hbkg_nEle[file_counter]->Fill(passEleL.size(),w);
     hbkg_nEleM[file_counter]->Fill(passEleM.size(),w);
     hbkg_nEleT[file_counter]->Fill(passEleT.size(),w);
     hbkg_nMu[file_counter]->Fill(passMuL.size(),w);
     hbkg_nMuM[file_counter]->Fill(passMuM.size(),w);
     hbkg_nMuT[file_counter]->Fill(passMuT.size(),w);
     if (leadpt_ak4!=-1) hbkg_jetpt[file_counter]->Fill((*jetPt)[leadpt_ak4],w);
     if (leadpt_ak8!=-1) hbkg_AK8jetpt[file_counter]->Fill((*AK8JetPt)[leadpt_ak8],w);
     if (highBDSV!=-1) hbkg_AK8bjetpt[file_counter]->Fill((*AK8JetPt)[highBDSV],w);
     if (leadpt_ak8!=-1) hbkg_AK8ljetmass[file_counter]->Fill((*AK8JetMass)[leadpt_ak8],w);
     if (leadpt_ak8!=-1) hbkg_AK8bjetmass[file_counter]->Fill((*AK8JetMass)[highBDSV],w);
     if (leadpt_ak8!=-1) hbkg_AK8bPrunedjetmass[file_counter]->Fill((*AK8CHSPrunedJetMass)[highBDSV],w);
     if (leadpt_ak8!=-1) hbkg_AK8bPrunedCorrjetmass[file_counter]->Fill((*AK8CHSPrunedJetMassCorr)[highBDSV],w);
     if (dR_pho_AK8!=-1) hbkg_dRphoAK8jet[file_counter]->Fill(dR_pho_AK8,w);
     }
   f.Write();
   f.Close();
}
/*   
   double BtagBDSVWP[3]={0.3,0.6,0.9};
   double BtagCSVWP[3]={0.46,0.8,0.935};
   double BtagcMVAWP[3]={-0.715,0.285,0.875};
*/
