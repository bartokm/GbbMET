#define mc_signal_cxx
#include "mc_signal.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

double deltaR(double phi1, double phi2, double eta1, double eta2){
  double dR=0;
  if (abs(phi1-phi2)>M_PI) dR=sqrt(pow(phi2-phi1,2)+pow(eta1-eta2,2));
  else dR=sqrt(pow(phi1-phi2,2)+pow(eta1-eta2,2));
  return dR;
}

void mc_signal::Loop()
{
//   In a ROOT session, you can do:
//      root> .L mc_signal.C
//      root> mc_signal t
//      root> t.GetEntry(12); // Fill t mCh1400_mN200 members with entry number 12
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
   fChain->SetBranchStatus("nPUInfo",1);
   fChain->SetBranchStatus("nPU",1);
   fChain->SetBranchStatus("puBX",1);
   fChain->SetBranchStatus("puTrue",1);
   fChain->SetBranchStatus("nEle", 1);
   fChain->SetBranchStatus("eleEta", 1);
   fChain->SetBranchStatus("elePhi", 1);
   fChain->SetBranchStatus("elePt", 1);
   fChain->SetBranchStatus("eleIDMVANonTrg", 1);
   fChain->SetBranchStatus("nMu", 1);
   fChain->SetBranchStatus("muEta", 1);
   fChain->SetBranchStatus("muPhi", 1);
   fChain->SetBranchStatus("muIsLooseID", 1);
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
   fChain->SetBranchStatus("jetGenPartonMomID",1);
   fChain->SetBranchStatus("jetPFLooseId",1);
   fChain->SetBranchStatus("nAK8Jet",1);
   fChain->SetBranchStatus("AK8JetPt",1);
   fChain->SetBranchStatus("AK8JetEta",1);
   fChain->SetBranchStatus("AK8JetPhi",1);
   fChain->SetBranchStatus("AK8JetMass",1);
   fChain->SetBranchStatus("AK8JetPFLooseId",1);
   fChain->SetBranchStatus("AK8JetpfBoostedDSVBTag",1);
   fChain->SetBranchStatus("AK8JetGenPartonMomID",1);

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   //double L_data=2202.14;
   double L_data=1280.22;
   
   //pu reweight
   TFile f_dataPU("/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/ggNtuple_AOD_PU_norm.root","read");
   TH1D *h_dataPU = (TH1D*)f_dataPU.Get("pileup");
   h_dataPU->SetDirectory(0);
   f_dataPU.Close();

   TFile f("mc_signal_histos.root","recreate");
   for (Int_t i=0;i<nfile;i++){
     h_PUweight[i] = (TH1D*)h_dataPU->Clone(Form("h_PUweight[%i]",i));
     h_PUweight[i]->SetDirectory(0);
     
     hsignal_cuts[i] = new TH1D(Form("hsignal_cuts[%i]",i),std::string(mc_input_file[i]+" cuts;Full,HLT,PhoID,noPixel,PhoEt,pfMET,HT").c_str(),10,0,10);
     hsignal_nVtx[i] = new TH1D(Form("hsignal_nVtx[%i]",i),std::string(mc_input_file[i]+";nVtx").c_str(),50,0,50);
     hsignal_nPU[i] = new TH1D(Form("hsignal_nPU[%i]",i),std::string(mc_input_file[i]+";nPU").c_str(),50,0,50);

     hsignal_phoEt[i] = new TH1D(Form("hsignal_phoEt[%i]",i),std::string(mc_input_file[i]+";phoEt").c_str(),30,0,1000);
     hsignal_phoEta[i]= new TH1D(Form("hsignal_phoEta[%i]",i),std::string(mc_input_file[i]+";Eta").c_str(),30,-3,3);
     hsignal_pfMET[i]= new TH1D(Form("hsignal_pfMET[%i]",i),std::string(mc_input_file[i]+";pfMET").c_str(),30,0,500);
     hsignal_nPho[i]= new TH1D(Form("hsignal_nPho[%i]",i),std::string(mc_input_file[i]+";nPho").c_str(),10,0,10);
     hsignal_nTrksPV[i]= new TH1D(Form("hsignal_nTrksPV[%i]",i),std::string(mc_input_file[i]+";nTrksPV").c_str(),30,0,500);
     hsignal_nEle[i]= new TH1D(Form("hsignal_nEle[%i]",i),std::string(mc_input_file[i]+";nEle").c_str(),10,0,10);
     hsignal_nMu[i]= new TH1D(Form("hsignal_nMu[%i]",i),std::string(mc_input_file[i]+";nMu").c_str(),10,0,10);
     
     hsignal_njets[i] = new TH1D(Form("hsignal_njets[%i]",i),std::string(mc_input_file[i]+";# of jets").c_str(),10,0,10);
     hsignal_jetpt[i] = new TH1D(Form("hsignal_jetpt[%i]",i),std::string(mc_input_file[i]+" Leading jetpt;jetpt").c_str(),50,0,2000);
     hsignal_nAK8jets[i] = new TH1D(Form("hsignal_nAK8jets[%i]",i),std::string(mc_input_file[i]+";# of AK8jets").c_str(),10,0,10);
     hsignal_AK8jetpt[i] = new TH1D(Form("hsignal_AK8jetpt[%i]",i),std::string(mc_input_file[i]+" Leading AK8jetpt;AK8jetpt").c_str(),50,0,2000);
     hsignal_AK8ljetmass[i] = new TH1D(Form("hsignal_AK8ljetmass[%i]",i),std::string(mc_input_file[i]+" Leading AK8jetmass;AK8jetmass").c_str(),30,0,700);
     hsignal_AK8bjetmass[i] = new TH1D(Form("hsignal_AK8bjetmass[%i]",i),std::string(mc_input_file[i]+" Btagged AK8jetmass;AK8jetmass").c_str(),30,0,700);
     hsignal_AK8jetmass[i] = new TH1D(Form("hsignal_AK8jetmass[%i]",i),std::string(mc_input_file[i]+" AK8jetmass;AK8jetmass").c_str(),30,0,700);
     
     hsignal_dRphoAK8jet[i]= new TH1D(Form("hsignal_dRphoAK8jet[%i]",i),std::string(mc_input_file[i]+" Distance between leading photon and leading AK8jet;dR").c_str(),30,0,8);
     
     hsignal_bjets[i] = new TH1D(Form("hsignal_bjets[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hsignal_doubleB[i] = new TH1D(Form("hsignal_doubleB[%i]",i),std::string(mc_input_file[i]+";BoostedDoubleSVTagger").c_str(),30,-1,1);
     hsignal_doubleB_highdB[i] = new TH1D(Form("hsignal_doubleB_highdB[%i]",i),std::string(mc_input_file[i]+" Highest Boosted;BoostedDoubleSVTagger").c_str(),30,-1,1);
     hsignal_bjetprob[i] = new TH1D(Form("hsignal_bjetprob[%i]",i),std::string(mc_input_file[i]+" Highest prob;JetProbabilityBJetTags").c_str(),30,0,1);
     hsignal_bjetprob2[i] = new TH1D(Form("hsignal_bjetprob2[%i]",i),std::string(mc_input_file[i]+" 2nd Highest prob;JetProbabilityBJetTags").c_str(),30,0,1);
     hsignal_bjetCSV[i]= new TH1D(Form("hsignal_bjetCSV[%i]",i),std::string(mc_input_file[i]+" Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags").c_str(),30,0,1);
     hsignal_bjetCSV2[i]= new TH1D(Form("hsignal_bjetCSV2[%i]",i),std::string(mc_input_file[i]+" 2nd Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags").c_str(),30,0,1);
     hsignal_bjetcMVA[i] = new TH1D(Form("hsignal_bjetcMVA[%i]",i),std::string(mc_input_file[i]+" Highest cMVA;CombinedMVABJetTags").c_str(),30,0,1);
     hsignal_bjetcMVA2[i] = new TH1D(Form("hsignal_bjetcMVA2[%i]",i),std::string(mc_input_file[i]+" 2nd Highest cMVA;CombinedMVABJetTags").c_str(),30,0,1);
     
     hsignal_HT_before[i] = new TH1D(Form("hsignal_HT_before[%i]",i),std::string(mc_input_file[i]+" HT before cuts;HT").c_str(),50,0,2500);
     hsignal_EMHT_before[i] = new TH1D(Form("hsignal_EMHT_before[%i]",i),std::string(mc_input_file[i]+" EMHT before cuts;EMHT").c_str(),50,0,2500);
     hsignal_HT_after[i] = new TH1D(Form("hsignal_HT_after[%i]",i),std::string(mc_input_file[i]+" HT after cuts;HT").c_str(),50,0,2500);
     hsignal_EMHT_after[i] = new TH1D(Form("hsignal_EMHT_after[%i]",i),std::string(mc_input_file[i]+" EMHT after cuts;EMHT").c_str(),50,0,2500);
     
     hsignal_AK8HT_before[i] = new TH1D(Form("hsignal_AK8HT_before[%i]",i),std::string(mc_input_file[i]+" AK8HT before cuts;HT").c_str(),50,0,2500);
     hsignal_AK8EMHT_before[i] = new TH1D(Form("hsignal_AK8EMHT_before[%i]",i),std::string(mc_input_file[i]+" AK8EMHT before cuts;EMHT").c_str(),50,0,2500);
     hsignal_AK8HT_after[i] = new TH1D(Form("hsignal_AK8HT_after[%i]",i),std::string(mc_input_file[i]+" AK8HT after cuts;HT").c_str(),50,0,2500);
     hsignal_AK8EMHT_after[i] = new TH1D(Form("hsignal_AK8EMHT_after[%i]",i),std::string(mc_input_file[i]+" AK8EMHT after cuts;EMHT").c_str(),50,0,2500);

     //mc truth histograms
     hsignal_Hjetpt[i] = new TH1D(Form("hsignal_Hjetpt[%i]",i),std::string(mc_input_file[i]+" Higgs mom jetpt;jetpt").c_str(),50,0,2000);
     hsignal_AK8Hjetpt[i] = new TH1D(Form("hsignal_AK8Hjetpt[%i]",i),std::string(mc_input_file[i]+" Higgs mom AK8jetpt;AK8jetpt").c_str(),50,0,2000);
     hsignal_AK8Hjetmass[i] = new TH1D(Form("hsignal_AK8Hjetmass[%i]",i),std::string(mc_input_file[i]+" Higgs mom AK8jetmass;AK8jetmass").c_str(),30,0,700);
     
     hsignal_dRphoH[i]= new TH1D(Form("hsignal_dRphoH[%i]",i),std::string(mc_input_file[i]+" Distance between leading photon and H;dR").c_str(),30,0,8);
     hsignal_dRTphoH[i]= new TH1D(Form("hsignal_dRTphoH[%i]",i),std::string(mc_input_file[i]+" Distance between true photon and H;dR").c_str(),30,0,8);
     
     hsignal_AK8ptHpt[i]= new TH2D(Form("hsignal_AK8ptHpt[%i]",i),std::string(mc_input_file[i]+" ;leading AK8pt;Higgs pt").c_str(),30,0,2000,30,0,2000);
     hsignal_AK8massHpt[i]= new TH2D(Form("hsignal_AK8massHpt[%i]",i),std::string(mc_input_file[i]+" ;leading AK8mass;Higgs pt").c_str(),30,0,700,30,0,2000);
    
     hsignal_Hpt[i] = new TH1D(Form("hsignal_Hpt[%i]",i),std::string(mc_input_file[i]+" Higgs pt;pt").c_str(),50,0,2000);
     
     hsignal_btag_ak8pt[i] = new TH1D(Form("hsignal_btag_ak8pt[%i]",i),std::string(mc_input_file[i]+" tagged jet pt;pt").c_str(),50,0,2000);
     hsignal_nobtag_ak8pt[i] = new TH1D(Form("hsignal_nobtag_ak8pt[%i]",i),std::string(mc_input_file[i]+" no tagged jet pt;pt").c_str(),50,0,2000);
   }
   
   fChain->ls();
   int file_counter=-1; std::string temp_f="";
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

     bool newfile=false;

     if (temp_f != fChain->GetCurrentFile()->GetName()) {
       temp_f=fChain->GetCurrentFile()->GetName();
       file_counter++;
       std::cout<<"file "<<file_counter<<" "<<fChain->GetCurrentFile()->GetName()<<std::endl;
       newfile=true;
     }
     //weights
     /*
     int zbx=0;//get zero bunchcrossing (puTrue always the same for every bx, just in case...)
     for (int i=0;i<(*puBX).size();i++) if ((*puBX)[i]==0) zbx=i;
     double pu_weight=h_PUweight[file_counter]->GetBinContent(h_PUweight[file_counter]->FindBin((*puTrue)[zbx]));
     */
     double pu_weight=1;//currently no puinfo in signal mc :(
     double weight=L_data*sigma[file_counter]/nmax[file_counter];
     double w=0;
     w=weight*pu_weight*genWeight;
     //HLTcut
     if   (HLTPho&128) { //HLT_Photon175
       hsignal_cuts[file_counter]->Fill(1,w);

     //object definitions
     int nleadPho=-1, leadpt_ak4=-1, leadpt_ak8=-1, leadbtag=-1;
     std::vector<int> passPho, passJet, passAK8Jet, passEle, passMu;
     passPho.clear(); passJet.clear(); passAK8Jet.clear(); passEle.clear(); passMu.clear();
     double HT_before=0, EMHT_before=0, HT_after=0, EMHT_after=0;
     double AK8HT_before=0, AK8EMHT_before=0, AK8HT_after=0, AK8EMHT_after=0;
     //photon
     bool phoid=false;
     for (int i=0;i<nPho;i++){
       if (abs((*phoEta)[i])<1.4442 && (*phoIDbit)[i]>>0&1) {
         phoid=true; 
         if ((*phohasPixelSeed)[i]==0) passPho.push_back(i);
       }
       //to study pho by pho
       //if (file_counter==2) std::cout<<"Eta<1.4442 "<<abs((*phoEta)[i])<<" PixelSeed "<<(*phohasPixelSeed)[i]<<" HoverE<0.05 "<<(*phoHoverE)[i]<<" IEtaIEta<0.0102 "<<(*phoSigmaIEtaIEta)[i]<<" ChIso<3.32 "<<(*phoPFChIso)[i]<<" NeuIso<"<<1.92+(*phoEt)[i]*0.014+pow((*phoEt)[i],2)*0.000019<<" "<<(*phoPFNeuIso)[i]<<" PhoIso<"<<0.81+(*phoEt)[i]*0.0053<<" "<<(*phoPFPhoIso)[i]<<std::endl;
     }
     if (phoid) hsignal_cuts[file_counter]->Fill(2,w);
     for (int i=0;i<passPho.size();i++) {
       if ((*phoEt)[passPho.at(i)]>(*phoEt)[nleadPho]) nleadPho=passPho.at(i);
       EMHT_before+=(*phoEt)[passPho.at(i)];
     }
     EMHT_after=EMHT_before;
     AK8EMHT_before=EMHT_before;
     AK8EMHT_after=EMHT_before;
     //electron
     for (int i=0;i<nEle;i++) {
       if (abs((*eleEta)[i])<=0.8 && (*elePt)[i]>5 && (*elePt)[i]<10) if ((*eleIDMVANonTrg)[i]>-0.083313) passEle.push_back(i);
       if (abs((*eleEta)[i])<=0.8 && (*elePt)[i]>=10) if ((*eleIDMVANonTrg)[i]>0.913286) passEle.push_back(i);
       if (abs((*eleEta)[i])>0.8 && abs((*eleEta)[i])<1.4442 && (*elePt)[i]>5 && (*elePt)[i]<10) if ((*eleIDMVANonTrg)[i]>-0.235222) passEle.push_back(i);
       if (abs((*eleEta)[i])>0.8 && abs((*eleEta)[i])<1.4442 && (*elePt)[i]>=10) if ((*eleIDMVANonTrg)[i]>0.805013) passEle.push_back(i);
     }
     //muon
     for (int i=0;i<nMu;i++) if ((*muIsLooseID)[i]==1) passMu.push_back(i);
     //jet
     for (int i=0;i<nJet;i++) {
       bool passcut=true;
       HT_before+=(*jetPt)[i];
       if (abs((*jetEta)[i])>3 || (*jetPFLooseId)[i]==0 || (*jetPt)[i]<40) passcut=false;
       for (int j=0;j<passPho.size();j++) if (deltaR((*jetPhi)[i],(*phoPhi)[passPho.at(j)],(*jetEta)[i],(*phoEta)[passPho.at(j)])<0.3) {
         passcut=false;break;
       }
       for (int j=0;j<passEle.size();j++) if (deltaR((*jetPhi)[i],(*elePhi)[passEle.at(j)],(*jetEta)[i],(*eleEta)[passEle.at(j)])<0.3) {
         passcut=false;break;
       }
       for (int j=0;j<passMu.size();j++) if (deltaR((*jetPhi)[i],(*muPhi)[passMu.at(j)],(*jetEta)[i],(*muEta)[passMu.at(j)])<0.3) {
         passcut=false;break;
       }
       if (passcut) passJet.push_back(i);
     }
     for (int i=0;i<passJet.size();i++) {
       if ((*jetPt)[passJet.at(i)]>(*jetPt)[leadpt_ak4]) leadpt_ak4=passJet.at(i);
       HT_after+=(*jetPt)[passJet.at(i)];
     }
     EMHT_before+=HT_before;
     EMHT_after+=HT_after;
     //AK8Jet
     for (int i=0;i<nAK8Jet;i++) {
       bool passcut=true;
       AK8HT_before+=(*AK8JetPt)[i];
       if (abs((*AK8JetEta)[i])>3 || (*AK8JetPFLooseId)[i]==0 || (*AK8JetPt)[i]<40) passcut=false;
       for (int j=0;j<passPho.size();j++) if (deltaR((*AK8JetPhi)[i],(*phoPhi)[passPho.at(j)],(*AK8JetEta)[i],(*phoEta)[passPho.at(j)])<0.3) {
         passcut=false;break;
       }
       for (int j=0;j<passEle.size();j++) if (deltaR((*AK8JetPhi)[i],(*elePhi)[passEle.at(j)],(*AK8JetEta)[i],(*eleEta)[passEle.at(j)])<0.3) {
         passcut=false;break;
       }
       for (int j=0;j<passMu.size();j++) if (deltaR((*AK8JetPhi)[i],(*muPhi)[passMu.at(j)],(*AK8JetEta)[i],(*muEta)[passMu.at(j)])<0.3) {
         passcut=false;break;
       }
       if (passcut) passAK8Jet.push_back(i);
     }
     for (int i=0;i<passAK8Jet.size();i++) {
       if ((*AK8JetPt)[passAK8Jet.at(i)]>(*AK8JetPt)[leadpt_ak8]) leadpt_ak8=passAK8Jet.at(i);
       AK8HT_after+=(*AK8JetPt)[passAK8Jet.at(i)];
       if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet.at(i)]>(*AK8JetpfBoostedDSVBTag)[leadbtag]) leadbtag=passAK8Jet.at(i);
     }
     AK8EMHT_before+=HT_before;
     AK8EMHT_after+=HT_after;
     //cuts
       if (passPho.size()>0){
         hsignal_cuts[file_counter]->Fill(3,w);
         if ((*phoEt)[nleadPho]>175){
           hsignal_cuts[file_counter]->Fill(4,w);
           //if (HT_after>200){
           //  hsignal_cuts[file_counter]->Fill(5,w);
//specko btag eff
for (int i=0;i<passAK8Jet.size();i++) {
  if ((*AK8JetGenPartonMomID)[passAK8Jet.at(i)]==25) {
    if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet.at(i)]>0.4) hsignal_btag_ak8pt[file_counter]->Fill((*AK8JetPt)[passAK8Jet.at(i)],w);
    else hsignal_nobtag_ak8pt[file_counter]->Fill((*AK8JetPt)[passAK8Jet.at(i)],w);
  }
}
           if ((*AK8JetpfBoostedDSVBTag)[leadbtag]>0.4){
             hsignal_cuts[file_counter]->Fill(5,w);
           if (pfMET<150){
             hsignal_cuts[file_counter]->Fill(6,w);
           }

        int bcounter=0;
        int highjetprob1=-1, highjetprob2=-1, highCSV1=-1, highCSV2=-1, highcMVA1=-1, highcMVA2=-1;
        for (int i=0;i<passJet.size();i++){
          if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>0.89) bcounter++;
          if ((*jetJetProbabilityBJetTags)[passJet.at(i)]>(*jetJetProbabilityBJetTags)[highjetprob1]) {highjetprob2=highjetprob1;highjetprob1=passJet.at(i);}
          else if (highjetprob2!=-1) if ((*jetJetProbabilityBJetTags)[passJet.at(i)]>(*jetJetProbabilityBJetTags)[highjetprob2]) highjetprob2=passJet.at(i);
          if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>(*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV1]) {highCSV2=highCSV1;highCSV1=passJet.at(i);}
          else if (highCSV2!=-1) if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>(*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV2]) highCSV2=passJet.at(i);
          if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>(*jetpfCombinedMVAV2BJetTags)[highcMVA1]) {highcMVA2=highcMVA1;highcMVA1=passJet.at(i);}
          else if (highcMVA2!=-1) if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>(*jetpfCombinedMVAV2BJetTags)[highcMVA2]) highcMVA2=passJet.at(i);
        //mc truth histos
          if ((*jetGenPartonMomID)[passJet.at(i)]==25) hsignal_Hjetpt[file_counter]->Fill((*jetPt)[passJet.at(i)],w);
        }
        int highdB_ak8=-1;
        for (int i=0;i<passAK8Jet.size();i++) {
          double i_jetpt=(*AK8JetPt)[passAK8Jet.at(i)], i_jetdB=(*AK8JetpfBoostedDSVBTag)[passAK8Jet.at(i)], h_jetdB;
          if (highdB_ak8==-1) h_jetdB=-10; else h_jetdB=(*AK8JetpfBoostedDSVBTag)[highdB_ak8];
          if (i_jetdB>h_jetdB) highdB_ak8=passAK8Jet.at(i);
        //mc truth histos
          if ((*AK8JetGenPartonMomID)[passAK8Jet.at(i)]==25) {
            hsignal_AK8Hjetpt[file_counter]->Fill((*AK8JetPt)[passAK8Jet.at(i)],w);
            hsignal_AK8Hjetmass[file_counter]->Fill((*AK8JetMass)[passAK8Jet.at(i)],w);
          }
        }
        double dR_pho_AK8=-1;
        if (abs((*AK8JetEta)[leadpt_ak8])<1.4442){
          dR_pho_AK8=deltaR((*AK8JetPhi)[leadpt_ak8],(*phoPhi)[nleadPho],(*AK8JetEta)[leadpt_ak8],(*phoEta)[nleadPho]);
        }
        //mc truth histos
        int iHiggs=-1, iPho=-1;
          for (int i=0;i<nMC;i++){
            if ((*mcPID)[i]==25){
              hsignal_Hpt[file_counter]->Fill((*mcPt)[i],w);
              iHiggs=i;
            }
            if ((*mcPID)[i]==22 && (*mcMomPID)[i]==1000022) iPho=i;
          }
          double dR_pho_H=-1;
          if (abs((*mcEta)[iHiggs])<1.4442 && iHiggs!=-1){
            if (abs((*mcPhi)[iHiggs]-(*phoPhi)[nleadPho])>M_PI) {
              dR_pho_H=sqrt(pow((*phoPhi)[nleadPho]-(*mcPhi)[iHiggs],2)+pow((*mcEta)[iHiggs]-(*phoEta)[nleadPho],2));
            }
            else {
              dR_pho_H=sqrt(pow((*mcPhi)[iHiggs]-(*phoPhi)[nleadPho],2)+pow((*mcEta)[iHiggs]-(*phoEta)[nleadPho],2));
            }
          }
          double dR_Tpho_H=-1;
          if (abs((*mcEta)[iHiggs])<1.479 && iHiggs!=-1 &&iPho!=-1){
            if (abs((*mcPhi)[iHiggs]-(*mcPhi)[iPho])>M_PI) {
              dR_Tpho_H=sqrt(pow((*mcPhi)[iPho]-(*mcPhi)[iHiggs],2)+pow((*mcEta)[iHiggs]-(*mcEta)[iPho],2));
            }
            else {
              dR_Tpho_H=sqrt(pow((*mcPhi)[iHiggs]-(*mcPhi)[iPho],2)+pow((*mcEta)[iHiggs]-(*mcEta)[iPho],2));
            }
          }
         //Filling histograms
         hsignal_nVtx[file_counter]->Fill(nVtx,w);
         //hsignal_nPU[file_counter]->Fill((*puTrue)[zbx],w);
         hsignal_HT_before[file_counter]->Fill(HT_before,w);
         hsignal_EMHT_before[file_counter]->Fill(EMHT_before,w);
         hsignal_HT_after[file_counter]->Fill(HT_after,w);
         hsignal_EMHT_after[file_counter]->Fill(EMHT_after,w);
         hsignal_AK8HT_before[file_counter]->Fill(AK8HT_before,w);
         hsignal_AK8EMHT_before[file_counter]->Fill(AK8EMHT_before,w);
         hsignal_AK8HT_after[file_counter]->Fill(AK8HT_after,w);
         hsignal_AK8EMHT_after[file_counter]->Fill(AK8EMHT_after,w);
         hsignal_nAK8jets[file_counter]->Fill(passAK8Jet.size(),w);
         hsignal_phoEt[file_counter]->Fill((*phoEt)[nleadPho],w);
         hsignal_phoEta[file_counter]->Fill((*phoEta)[nleadPho],w);
         hsignal_pfMET[file_counter]->Fill(pfMET,w);
         hsignal_nPho[file_counter]->Fill(passPho.size(),w);
         hsignal_nTrksPV[file_counter]->Fill(nTrksPV,w);
         hsignal_njets[file_counter]->Fill(passJet.size(),w);
         hsignal_bjets[file_counter]->Fill(bcounter,w);
         if (highjetprob1!=-1) hsignal_bjetprob[file_counter]->Fill((*jetJetProbabilityBJetTags)[highjetprob1],w);
         if (highjetprob2!=-1) hsignal_bjetprob2[file_counter]->Fill((*jetJetProbabilityBJetTags)[highjetprob2],w);
         if (highCSV1!=-1) hsignal_bjetCSV[file_counter]->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV1],w);
         if (highCSV2!=-1) hsignal_bjetCSV2[file_counter]->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV2],w);
         if (highcMVA1!=-1) hsignal_bjetcMVA[file_counter]->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA1],w);
         if (highcMVA2!=-1) hsignal_bjetcMVA2[file_counter]->Fill((*jetpfCombinedMVAV2BJetTags)[highcMVA2],w);
         if (leadpt_ak8!=-1) hsignal_doubleB[file_counter]->Fill((*AK8JetpfBoostedDSVBTag)[leadpt_ak8],w);
         if (highdB_ak8!=-1) hsignal_doubleB_highdB[file_counter]->Fill((*AK8JetpfBoostedDSVBTag)[highdB_ak8],w);
         for (int i=0;i<passAK8Jet.size();i++) hsignal_AK8jetmass[file_counter]->Fill((*AK8JetMass)[passAK8Jet.at(i)],w);
         hsignal_nEle[file_counter]->Fill(passEle.size(),w);
         hsignal_nMu[file_counter]->Fill(passMu.size(),w);
         if (leadpt_ak4!=-1) hsignal_jetpt[file_counter]->Fill((*jetPt)[leadpt_ak4],w);
         if (leadpt_ak8!=-1) hsignal_AK8jetpt[file_counter]->Fill((*AK8JetPt)[leadpt_ak8],w);
         if (leadpt_ak8!=-1) hsignal_AK8ljetmass[file_counter]->Fill((*AK8JetMass)[leadpt_ak8],w);
         if (leadpt_ak8!=-1) hsignal_AK8bjetmass[file_counter]->Fill((*AK8JetMass)[highdB_ak8],w);
         if (dR_pho_AK8!=-1) hsignal_dRphoAK8jet[file_counter]->Fill(dR_pho_AK8,w);
         //mctruth
         if (leadpt_ak8!=-1 && iHiggs!=-1) hsignal_AK8ptHpt[file_counter]->Fill((*AK8JetPt)[leadpt_ak8],(*mcPt)[iHiggs],w);
         if (leadpt_ak8!=-1 && iHiggs!=-1) hsignal_AK8massHpt[file_counter]->Fill((*AK8JetMass)[leadpt_ak8],(*mcPt)[iHiggs],w);
         if (dR_pho_H!=-1) hsignal_dRphoH[file_counter]->Fill(dR_pho_H,w);
         if (dR_Tpho_H!=-1) hsignal_dRTphoH[file_counter]->Fill(dR_Tpho_H,w);
           }//btag cut
         }//offline HLT
        }//phoID
      }//HLT
   }
   f.Write();
   f.Close();
}
