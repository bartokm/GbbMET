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
   fChain->SetBranchStatus("nJet",1);
   fChain->SetBranchStatus("jetPt",1);
   fChain->SetBranchStatus("jetPhi",1);
   fChain->SetBranchStatus("jetEta",1);
   fChain->SetBranchStatus("jetJetProbabilityBJetTags",1);
   fChain->SetBranchStatus("jetpfCombinedInclusiveSecondaryVertexV2BJetTags",1);
   fChain->SetBranchStatus("jetpfCombinedMVABJetTags",1);
   fChain->SetBranchStatus("jetPFLooseId",1);
   fChain->SetBranchStatus("nAK8Jet",1);
   fChain->SetBranchStatus("AK8JetPt",1);
   fChain->SetBranchStatus("AK8JetEta",1);
   fChain->SetBranchStatus("AK8JetPhi",1);
   fChain->SetBranchStatus("AK8JetMass",1);
   fChain->SetBranchStatus("AK8JetPFLooseId",1);
   fChain->SetBranchStatus("AK8JetpfBoostedDSVBTag",1);

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   
   TFile f_dataPU("/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/ggNtuple_AOD_PU.root","read");
   TH1D *hdata_nPU = (TH1D*)f_dataPU.Get("pileup");
   hdata_nPU->SetDirectory(0);
   f_dataPU.Close();

   TFile f("skimmed_data_histos.root","recreate");

   TH1D *hdata_cuts = new TH1D("hdata_cuts","cuts;Full,HLT,PhoID,noPixel,PhoEt,btag,pfMET",10,0,10);
   TH1D *hdata_nVtx = new TH1D("hdata_nVtx",";nVtx",50,0,50);

   TH1D *hdata_phoEt = new TH1D("hdata_phoEt",";phoEt",30,0,1000);
   TH1D *hdata_phoEta = new TH1D("hdata_phoEta",";Eta",30,-3,3);
   TH1D *hdata_pfMET = new TH1D("hdata_pfMET",";pfMET",30,0,500);
   TH1D *hdata_nPho = new TH1D("hdata_nPho",";nPho",10,0,10);
   TH1D *hdata_nTrksPV = new TH1D("hdata_nTrksPV",";nTrksPV",30,0,500);
   TH1D *hdata_nEle= new TH1D("hdata_nEle",";nEle",10,0,10);
   TH1D *hdata_nMu= new TH1D("hdata_nMu",";nMu",10,0,10);

   TH1D *hdata_njets = new TH1D("hdata_njets",";# of jets",10,0,10);
   TH1D *hdata_jetpt = new TH1D("hdata_jetpt","Leading jetpt;jetpt",50,0,2000);
   TH1D *hdata_nAK8jets = new TH1D("hdata_nAK8jets",";# of AK8jets",10,0,10);
   TH1D *hdata_AK8jetpt = new TH1D("hdata_AK8jetpt","Leading AK8jetpt;AK8jetpt",50,0,2000);
   TH1D *hdata_AK8ljetmass = new TH1D("hdata_AK8ljetmass","Leading AK8jetmass;AK8jetmass",30,0,700);
   TH1D *hdata_AK8bjetmass = new TH1D("hdata_AK8bjetmass","Btagged AK8jetmass;AK8jetmass",30,0,700);
   TH1D *hdata_AK8jetmass = new TH1D("hdata_AK8jetmass","AK8jetmass;AK8jetmass",30,0,700);
    
   TH1D *hdata_dRphoAK8jet= new TH1D("hdata_dRphoAK8jet","Distance between leading photon and leading AK8jet;dR",30,0,8);
   
   TH1D *hdata_bjets = new TH1D("hdata_bjets",";# of bjets",10,0,10);
   TH1D *hdata_doubleB = new TH1D("hdata_doubleB","Highest jetPt;BoostedDoubleSVTagger",30,-1,1);
   TH1D *hdata_doubleB_highdB = new TH1D("hdata_doubleB_highdB","Highest Boosted;BoostedDoubleSVTagger",30,-1,1);
   TH1D *hdata_bjetprob = new TH1D("hdata_bjetprob","Highest prob;JetProbabilityBJetTags",30,0,1);
   TH1D *hdata_bjetprob2 = new TH1D("hdata_bjetprob2","2nd Highest prob;JetProbabilityBJetTags",30,0,1);
   TH1D *hdata_bjetCSV= new TH1D("hdata_bjetCSV","Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags",30,0,1);
   TH1D *hdata_bjetCSV2= new TH1D("hdata_bjetCSV2","2nd Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags",30,0,1);
   TH1D *hdata_bjetcMVA = new TH1D("hdata_bjetcMVA","Highest cMVA;CombinedMVABJetTags",30,0,1);
   TH1D *hdata_bjetcMVA2 = new TH1D("hdata_bjetcMVA2","2nd Highest cMVA;CombinedMVABJetTags",30,0,1);
  
   TH1D *hdata_HT_before = new TH1D("hdata_HT_before","HT before cuts;HT",50,0,2500);
   TH1D *hdata_EMHT_before = new TH1D("hdata_EMHT_before","EMHT before cuts;EMHT",50,0,2500);
   TH1D *hdata_HT_after = new TH1D("hdata_HT_after","HT after cuts;HT",50,0,2500);
   TH1D *hdata_EMHT_after = new TH1D("hdata_EMHT_after","EMHT after cuts;EMHT",50,0,2500);

   TH1D *hdata_AK8HT_before = new TH1D("hdata_AK8HT_before","AK8HT before cuts;HT",50,0,2500);
   TH1D *hdata_AK8EMHT_before = new TH1D("hdata_AK8EMHT_before","AK8EMHT before cuts;EMHT",50,0,2500);
   TH1D *hdata_AK8HT_after = new TH1D("hdata_AK8HT_after","AK8HT after cuts;HT",50,0,2500);
   TH1D *hdata_AK8EMHT_after = new TH1D("hdata_AK8EMHT_after","AK8EMHT after cuts;EMHT",50,0,2500);

   fChain->ls();

   int file_counter=-1; std::string temp_f="";
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
     //getting _h_cuts for Nevents
     TH1D *h_cuts = (TH1D*)fChain->GetCurrentFile()->Get("_h_cuts");
     if (temp_f != fChain->GetCurrentFile()->GetName()) {
       temp_f=fChain->GetCurrentFile()->GetName();
       file_counter++;
       std::cout<<"file "<<file_counter<<" "<<fChain->GetCurrentFile()->GetName()<<std::endl;
       //cutflow
       hdata_cuts->SetBinContent(1,hdata_cuts->GetBinContent(1)+h_cuts->GetBinContent(2));
       hdata_cuts->SetBinContent(2,hdata_cuts->GetBinContent(2)+h_cuts->GetBinContent(3));
     }
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
     if (phoid) hdata_cuts->Fill(2);
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
       hdata_cuts->Fill(3);
       if ((*phoEt)[nleadPho]>=175){
         hdata_cuts->Fill(4);
         if ((*AK8JetpfBoostedDSVBTag)[leadbtag]>0.4){
         hdata_cuts->Fill(5);
         if (pfMET<150){
         hdata_cuts->Fill(6);
         int bcounter=0;
         int highjetprob1=-1, highjetprob2=-1, highCSV1=-1, highCSV2=-1, highcMVA1=-1, highcMVA2=-1;
         for (int i=0;i<passJet.size();i++){
           if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>0.89) bcounter++;
           if ((*jetJetProbabilityBJetTags)[passJet.at(i)]>(*jetJetProbabilityBJetTags)[highjetprob1]) {highjetprob2=highjetprob1;highjetprob1=passJet.at(i);}
           else if (highjetprob2!=-1) if ((*jetJetProbabilityBJetTags)[passJet.at(i)]>(*jetJetProbabilityBJetTags)[highjetprob2]) highjetprob2=passJet.at(i);
           if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>(*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV1]) {highCSV2=highCSV1;highCSV1=passJet.at(i);}
           else if (highCSV2!=-1) if ((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[passJet.at(i)]>(*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV2]) highCSV2=passJet.at(i);
           if ((*jetpfCombinedMVABJetTags)[passJet.at(i)]>(*jetpfCombinedMVABJetTags)[highcMVA1]) {highcMVA2=highcMVA1;highcMVA1=passJet.at(i);}
           else if (highcMVA2!=-1) if ((*jetpfCombinedMVABJetTags)[passJet.at(i)]>(*jetpfCombinedMVABJetTags)[highcMVA2]) highcMVA2=passJet.at(i);
         }
         int highdB_ak8=-1;
         for (int i=0;i<passAK8Jet.size();i++) {
           double i_jetpt=(*AK8JetPt)[passAK8Jet.at(i)], i_jetdB=(*AK8JetpfBoostedDSVBTag)[passAK8Jet.at(i)], h_jetdB;
           if (highdB_ak8==-1) h_jetdB=-10; else h_jetdB=(*AK8JetpfBoostedDSVBTag)[highdB_ak8];
           if (i_jetdB>h_jetdB) highdB_ak8=passAK8Jet.at(i);
         }
         if (highdB_ak8!=leadbtag) std::cout<<"baj van: highdB_ak8, leadbtag "<<highdB_ak8<<", "<<leadbtag<<std::endl;
         double dR_pho_AK8=-1;
         if (abs((*AK8JetEta)[leadpt_ak8])<1.4442){
           dR_pho_AK8=deltaR((*AK8JetPhi)[leadpt_ak8],(*phoPhi)[nleadPho],(*AK8JetEta)[leadpt_ak8],(*phoEta)[nleadPho]);
         }
         //Filling histograms
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
         hdata_phoEt->Fill((*phoEt)[nleadPho]);
         hdata_phoEta->Fill((*phoEta)[nleadPho]);
         hdata_pfMET->Fill(pfMET);
         hdata_nPho->Fill(passPho.size());
         hdata_nTrksPV->Fill(nTrksPV);
         hdata_njets->Fill(passJet.size());
         hdata_bjets->Fill(bcounter);
         if (highjetprob1!=-1) hdata_bjetprob->Fill((*jetJetProbabilityBJetTags)[highjetprob1]);
         if (highjetprob2!=-1) hdata_bjetprob2->Fill((*jetJetProbabilityBJetTags)[highjetprob2]);
         if (highCSV1!=-1) hdata_bjetCSV->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV1]);
         if (highCSV2!=-1) hdata_bjetCSV2->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV2]);
         if (highcMVA1!=-1) hdata_bjetcMVA->Fill((*jetpfCombinedMVABJetTags)[highcMVA1]);
         if (highcMVA2!=-1) hdata_bjetcMVA2->Fill((*jetpfCombinedMVABJetTags)[highcMVA2]);
         if (leadpt_ak8!=-1) hdata_doubleB->Fill((*AK8JetpfBoostedDSVBTag)[leadpt_ak8]);
         if (highdB_ak8!=-1) hdata_doubleB_highdB->Fill((*AK8JetpfBoostedDSVBTag)[highdB_ak8]);
         for (int i=0;i<passAK8Jet.size();i++) hdata_AK8jetmass->Fill((*AK8JetMass)[passAK8Jet.at(i)]);
         hdata_nEle->Fill(passEle.size());
         hdata_nMu->Fill(passMu.size());
         if (leadpt_ak4!=-1) hdata_jetpt->Fill((*jetPt)[leadpt_ak4]);
         if (leadpt_ak8!=-1) hdata_AK8jetpt->Fill((*AK8JetPt)[leadpt_ak8]);
         if (leadpt_ak8!=-1) hdata_AK8ljetmass->Fill((*AK8JetMass)[leadpt_ak8]);
         if (leadpt_ak8!=-1) hdata_AK8bjetmass->Fill((*AK8JetMass)[highdB_ak8]);
         if (dR_pho_AK8!=-1) hdata_dRphoAK8jet->Fill(dR_pho_AK8);
         }//pfMET cut
         }//btag cut
       }//offline HLT cut
     }//phoid cut 
   }
   hdata_nPU->Write();
   f.Write();
   f.Close();
}
