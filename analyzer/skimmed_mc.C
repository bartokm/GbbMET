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
   //double L_data=2202.14;
   double L_data=1280.22;

   //pu reweight
   TFile f_dataPU("/afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/ggNtuple_AOD_PU_norm.root","read");
   TH1D *h_dataPU = (TH1D*)f_dataPU.Get("pileup");
   h_dataPU->SetDirectory(0);
   f_dataPU.Close();

   TFile f("skimmed_mc_histos.root","recreate");
   for (Int_t i=0;i<nfile;i++){
     h_PUweight[i] = (TH1D*)h_dataPU->Clone(Form("h_PUweight[%i]",i));
     h_PUweight[i]->SetDirectory(0);
     
     hbkg_cuts[i] = new TH1D(Form("hbkg_cuts[%i]",i),std::string(mc_input_file[i]+" cuts;Full,HLT,PhoID,noPixel,PhoEt,pfMET").c_str(),10,0,10);
     hbkg_nVtx[i] = new TH1D(Form("hbkg_nVtx[%i]",i),std::string(mc_input_file[i]+";nVtx").c_str(),50,0,50);
     hbkg_nPU[i] = new TH1D(Form("hbkg_nPU[%i]",i),std::string(mc_input_file[i]+";nPU").c_str(),50,0,50);

     hbkg_phoEt[i] = new TH1D(Form("hbkg_phoEt[%i]",i),std::string(mc_input_file[i]+";phoEt").c_str(),30,0,1000);
     hbkg_phoEta[i]= new TH1D(Form("hbkg_phoEta[%i]",i),std::string(mc_input_file[i]+";Eta").c_str(),30,-3,3);
     hbkg_pfMET[i]= new TH1D(Form("hbkg_pfMET[%i]",i),std::string(mc_input_file[i]+";pfMET").c_str(),30,0,500);
     hbkg_nPho[i]= new TH1D(Form("hbkg_nPho[%i]",i),std::string(mc_input_file[i]+";nPho").c_str(),10,0,10);
     hbkg_nTrksPV[i]= new TH1D(Form("hbkg_nTrksPV[%i]",i),std::string(mc_input_file[i]+";nTrksPV").c_str(),30,0,500);
     hbkg_nEle[i]= new TH1D(Form("hbkg_nEle[%i]",i),std::string(mc_input_file[i]+";nEle").c_str(),10,0,10);
     hbkg_nMu[i]= new TH1D(Form("hbkg_nMu[%i]",i),std::string(mc_input_file[i]+";nMu").c_str(),10,0,10);
     
     hbkg_njets[i] = new TH1D(Form("hbkg_njets[%i]",i),std::string(mc_input_file[i]+";# of jets").c_str(),10,0,10);
     hbkg_jetpt[i] = new TH1D(Form("hbkg_jetpt[%i]",i),std::string(mc_input_file[i]+" Leading jetpt;jetpt").c_str(),50,0,2000);
     hbkg_nAK8jets[i] = new TH1D(Form("hbkg_nAK8jets[%i]",i),std::string(mc_input_file[i]+";# of AK8jets").c_str(),10,0,10);
     hbkg_AK8jetpt[i] = new TH1D(Form("hbkg_AK8jetpt[%i]",i),std::string(mc_input_file[i]+" Leading AK8jetpt;AK8jetpt").c_str(),50,0,2000);
     hbkg_AK8ljetmass[i] = new TH1D(Form("hbkg_AK8ljetmass[%i]",i),std::string(mc_input_file[i]+" Leading AK8jetmass;AK8jetmass").c_str(),30,0,700);
     hbkg_AK8jetmass[i] = new TH1D(Form("hbkg_AK8jetmass[%i]",i),std::string(mc_input_file[i]+" AK8jetmass;AK8jetmass").c_str(),30,0,700);
     
     hbkg_dRphoAK8jet[i]= new TH1D(Form("hbkg_dRphoAK8jet[%i]",i),std::string(mc_input_file[i]+" Distance between leading photon and leading AK8jet;dR").c_str(),30,0,8);
     
     hbkg_bjets[i] = new TH1D(Form("hbkg_bjets[%i]",i),std::string(mc_input_file[i]+";# of bjets").c_str(),10,0,10);
     hbkg_doubleB[i] = new TH1D(Form("hbkg_doubleB[%i]",i),std::string(mc_input_file[i]+";BoostedDoubleSVTagger").c_str(),30,-1,1);
     hbkg_doubleB_highdB[i] = new TH1D(Form("hbkg_doubleB_highdB[%i]",i),std::string(mc_input_file[i]+" Highest Boosted;BoostedDoubleSVTagger").c_str(),30,-1,1);
     hbkg_bjetprob[i] = new TH1D(Form("hbkg_bjetprob[%i]",i),std::string(mc_input_file[i]+" Highest prob;JetProbabilityBJetTags").c_str(),30,0,1);
     hbkg_bjetprob2[i] = new TH1D(Form("hbkg_bjetprob2[%i]",i),std::string(mc_input_file[i]+" 2nd Highest prob;JetProbabilityBJetTags").c_str(),30,0,1);
     hbkg_bjetCSV[i]= new TH1D(Form("hbkg_bjetCSV[%i]",i),std::string(mc_input_file[i]+" Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags").c_str(),30,0,1);
     hbkg_bjetCSV2[i]= new TH1D(Form("hbkg_bjetCSV2[%i]",i),std::string(mc_input_file[i]+" 2nd Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags").c_str(),30,0,1);
     hbkg_bjetcMVA[i] = new TH1D(Form("hbkg_bjetcMVA[%i]",i),std::string(mc_input_file[i]+" Highest cMVA;CombinedMVABJetTags").c_str(),30,0,1);
     hbkg_bjetcMVA2[i] = new TH1D(Form("hbkg_bjetcMVA2[%i]",i),std::string(mc_input_file[i]+" 2nd Highest cMVA;CombinedMVABJetTags").c_str(),30,0,1);
     
     hbkg_HT_before[i] = new TH1D(Form("hbkg_HT_before[%i]",i),std::string(mc_input_file[i]+" HT before cuts;HT").c_str(),50,0,2500);
     hbkg_EMHT_before[i] = new TH1D(Form("hbkg_EMHT_before[%i]",i),std::string(mc_input_file[i]+" EMHT before cuts;EMHT").c_str(),50,0,2500);
     hbkg_HT_after[i] = new TH1D(Form("hbkg_HT_after[%i]",i),std::string(mc_input_file[i]+" HT after cuts;HT").c_str(),50,0,2500);
     hbkg_EMHT_after[i] = new TH1D(Form("hbkg_EMHT_after[%i]",i),std::string(mc_input_file[i]+" EMHT after cuts;EMHT").c_str(),50,0,2500);
     
     hbkg_AK8HT_before[i] = new TH1D(Form("hbkg_AK8HT_before[%i]",i),std::string(mc_input_file[i]+" AK8HT before cuts;HT").c_str(),50,0,2500);
     hbkg_AK8EMHT_before[i] = new TH1D(Form("hbkg_AK8EMHT_before[%i]",i),std::string(mc_input_file[i]+" AK8EMHT before cuts;EMHT").c_str(),50,0,2500);
     hbkg_AK8HT_after[i] = new TH1D(Form("hbkg_AK8HT_after[%i]",i),std::string(mc_input_file[i]+" AK8HT after cuts;HT").c_str(),50,0,2500);
     hbkg_AK8EMHT_after[i] = new TH1D(Form("hbkg_AK8EMHT_after[%i]",i),std::string(mc_input_file[i]+" AK8EMHT after cuts;EMHT").c_str(),50,0,2500);
   }

   fChain->ls();
   int file_counter=-1; std::string temp_f="";
   //for (Long64_t jentry=0; jentry<nentries;jentry++) {
   for (Long64_t jentry=0; jentry<10000;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;

     bool newfile=false;

     if (temp_f != fChain->GetCurrentFile()->GetName()) {
       temp_f=fChain->GetCurrentFile()->GetName();
       file_counter++;
       if (file_counter==6) {file_counter++; std::cout<<"file 6 /afs/cern.ch/work/m/mbartok/public/mc/ggNtuple/skimmed/job_spring15_qcd_HT200To300_25ns_cutbased.root has 0 Events"<<std::endl;}
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

     //puInfo study
     /*
     std::cout<<"nPUInfo "<<nPUInfo<<" event "<<event<<"\nnPU";
     for (int i=0; i<(*nPU).size();i++) std::cout<<" "<<(*nPU)[i];
     std::cout<<"\npuTrue";
     for (int i=0; i<(*puTrue).size();i++) std::cout<<" "<<(*puTrue)[i];
     std::cout<<"\npuBX";
     for (int i=0; i<(*puBX).size();i++) std::cout<<" "<<(*puBX)[i];
     std::cout<<"\n====================================================="<<endl;
     */
     //weights
     int zbx=0;//get zero bunchcrossing (puTrue always the same for every bx, just in case...)
     for (int i=0;i<(*puBX).size();i++) if ((*puBX)[i]==0) zbx=i;
     double pu_weight=h_PUweight[file_counter]->GetBinContent(h_PUweight[file_counter]->FindBin((*puTrue)[zbx]));
     double weight=L_data*h_cuts->GetBinContent(1)/h_cuts->GetBinContent(2);
     
     //cutflow
     if (newfile){
       hbkg_cuts[file_counter]->SetBinContent(1,h_cuts->GetBinContent(2)*weight);
       hbkg_cuts[file_counter]->SetBinContent(2,h_cuts->GetBinContent(3)*weight);
     }
     
     //weights
     double w=0;
     if (abs(genWeight)>1) w=copysign(weight*pu_weight,genWeight); //only a sign for amcatnlo
     else w=weight*pu_weight*genWeight; //0-1 for madgraph
    
     //object definitions
     int nleadPho=-1, leadpt_ak4=-1, leadpt_ak8=-1;
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
     if (phoid) hbkg_cuts[file_counter]->Fill(2,w);
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
     }
     AK8EMHT_before+=HT_before;
     AK8EMHT_after+=HT_after;
     //cuts
     if (passPho.size()>0){
       hbkg_cuts[file_counter]->Fill(3,w);
       if ((*phoEt)[nleadPho]>=175){
         hbkg_cuts[file_counter]->Fill(4,w);
         if (pfMET<150){
         hbkg_cuts[file_counter]->Fill(5,w);
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
           if (i_jetdB>h_jetdB) highdB_ak8=i;
         }
         double dR_pho_AK8=-1;
         if (abs((*AK8JetEta)[leadpt_ak8])<1.4442){
           dR_pho_AK8=deltaR((*AK8JetPhi)[leadpt_ak8],(*phoPhi)[nleadPho],(*AK8JetEta)[leadpt_ak8],(*phoEta)[nleadPho]);
         }
         //Filling histograms
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
         hbkg_phoEt[file_counter]->Fill((*phoEt)[nleadPho],w);
         hbkg_phoEta[file_counter]->Fill((*phoEta)[nleadPho],w);
         hbkg_pfMET[file_counter]->Fill(pfMET,w);
         hbkg_nPho[file_counter]->Fill(passPho.size(),w);
         hbkg_nTrksPV[file_counter]->Fill(nTrksPV,w);
         hbkg_njets[file_counter]->Fill(passJet.size(),w);
         hbkg_bjets[file_counter]->Fill(bcounter,w);
         if (highjetprob1!=-1) hbkg_bjetprob[file_counter]->Fill((*jetJetProbabilityBJetTags)[highjetprob1],w);
         if (highjetprob2!=-1) hbkg_bjetprob2[file_counter]->Fill((*jetJetProbabilityBJetTags)[highjetprob2],w);
         if (highCSV1!=-1) hbkg_bjetCSV[file_counter]->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV1],w);
         if (highCSV2!=-1) hbkg_bjetCSV2[file_counter]->Fill((*jetpfCombinedInclusiveSecondaryVertexV2BJetTags)[highCSV2],w);
         if (highcMVA1!=-1) hbkg_bjetcMVA[file_counter]->Fill((*jetpfCombinedMVABJetTags)[highcMVA1],w);
         if (highcMVA2!=-1) hbkg_bjetcMVA2[file_counter]->Fill((*jetpfCombinedMVABJetTags)[highcMVA2],w);
         if (leadpt_ak8!=-1) hbkg_doubleB[file_counter]->Fill((*AK8JetpfBoostedDSVBTag)[leadpt_ak8],w);
         if (highdB_ak8!=-1) hbkg_doubleB_highdB[file_counter]->Fill((*AK8JetpfBoostedDSVBTag)[highdB_ak8],w);
         for (int i=0;i<passAK8Jet.size();i++) hbkg_AK8jetmass[file_counter]->Fill((*AK8JetMass)[passAK8Jet.at(i)],w);
         hbkg_nEle[file_counter]->Fill(passEle.size(),w);
         hbkg_nMu[file_counter]->Fill(passMu.size(),w);
         if (leadpt_ak4!=-1) hbkg_jetpt[file_counter]->Fill((*jetPt)[leadpt_ak4],w);
         if (leadpt_ak8!=-1) hbkg_AK8jetpt[file_counter]->Fill((*AK8JetPt)[leadpt_ak8],w);
         if (leadpt_ak8!=-1) hbkg_AK8ljetmass[file_counter]->Fill((*AK8JetMass)[leadpt_ak8],w);
         if (dR_pho_AK8!=-1) hbkg_dRphoAK8jet[file_counter]->Fill(dR_pho_AK8,w);
         }//pfMET cut
       }//offline HLT cut
     }//phoid cut 
   }
   f.Write();
   f.Close();
}
