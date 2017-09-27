#define BTagEff_cxx
#include "BTagEff.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

double deltaR(double phi1, double phi2, double eta1, double eta2){
  double dR=0;
  if (abs(phi1-phi2)>M_PI) dR=sqrt(pow(2*M_PI-(phi2-phi1),2)+pow(eta1-eta2,2));
  else dR=sqrt(pow(phi1-phi2,2)+pow(eta1-eta2,2));
  return dR;
}

void BTagEff::Loop()
{
//   In a ROOT session, you can do:
//      root> .L BTagEff.C
//      root> BTagEff t
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
   fChain->SetBranchStatus("*",0);
   fChain->SetBranchStatus("nJet",1);
   fChain->SetBranchStatus("jetPt",1);
   fChain->SetBranchStatus("jetEta",1);
   fChain->SetBranchStatus("jetPhi",1);
   fChain->SetBranchStatus("jetEn",1);
   fChain->SetBranchStatus("jetHadFlvr",1);
   fChain->SetBranchStatus("jetCSV2BJetTags",1);
   fChain->SetBranchStatus("jetpfCombinedMVAV2BJetTags",1);
   fChain->SetBranchStatus("jetPFLooseId",1);
   fChain->SetBranchStatus("jetPUFullID",1);
   fChain->SetBranchStatus("jetP4Smear",1);
   fChain->SetBranchStatus("nAK8Jet",1);
   fChain->SetBranchStatus("AK8JetPt",1);
   fChain->SetBranchStatus("AK8JetEta",1);
   fChain->SetBranchStatus("AK8JetPhi",1);
   fChain->SetBranchStatus("AK8JetEn",1);
   fChain->SetBranchStatus("AK8JetHadFlvr",1);
   fChain->SetBranchStatus("AK8JetPFLooseId",1);
   fChain->SetBranchStatus("AK8JetpfBoostedDSVBTag",1);
   fChain->SetBranchStatus("AK8JetP4Smear",1);

   //Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;

   TFile f(output_file.c_str(),"recreate");
   //Histograms
   TH1F *h_Events;
   const int nxbins=8, nybins=10, Bnxbins=8, Bnybins=8;
   double xbins[nxbins+1]={-3,-2.4,-1.6,-0.8,0,0.8,1.6,2.4,3};
   double ybins[nybins+1]={20,30,50,70,100,140,200,300,600,1000,2000};
   double Bxbins[nxbins+1]={-3,-2.4,-1.6,-0.8,0,0.8,1.6,2.4,3};
   double Bybins[nybins+1]={40,250,300,350,400,500,700,1000,2000};

   TH2D *h_allAK4bjets = new TH2D("h_allAK4bjets",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_b_CSV_L= new TH2D("h_b_CSV_L",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_b_CSV_M= new TH2D("h_b_CSV_M",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_b_CSV_T= new TH2D("h_b_CSV_T",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_b_cMVA_L= new TH2D("h_b_cMVA_L",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_b_cMVA_M= new TH2D("h_b_cMVA_M",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_b_cMVA_T= new TH2D("h_b_cMVA_T",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_allAK4cjets = new TH2D("h_allAK4cjets",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_c_CSV_L= new TH2D("h_c_CSV_L",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_c_CSV_M= new TH2D("h_c_CSV_M",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_c_CSV_T= new TH2D("h_c_CSV_T",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_c_cMVA_L= new TH2D("h_c_cMVA_L",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_c_cMVA_M= new TH2D("h_c_cMVA_M",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_c_cMVA_T= new TH2D("h_c_cMVA_T",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_allAK4ljets = new TH2D("h_allAK4ljets",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_l_CSV_L= new TH2D("h_l_CSV_L",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_l_CSV_M= new TH2D("h_l_CSV_M",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_l_CSV_T= new TH2D("h_l_CSV_T",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_l_cMVA_L= new TH2D("h_l_cMVA_L",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_l_cMVA_M= new TH2D("h_l_cMVA_M",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_l_cMVA_T= new TH2D("h_l_cMVA_T",";#eta;p_{T}[GeV]",nxbins,xbins,nybins,ybins);
   TH2D *h_allAK8bjets = new TH2D("h_allAK8bjets",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_b_BDSV_L= new TH2D("h_b_BDSV_L",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_b_BDSV_M1= new TH2D("h_b_BDSV_M1",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_b_BDSV_M2= new TH2D("h_b_BDSV_M2",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_b_BDSV_T= new TH2D("h_b_BDSV_T",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_allAK8cjets = new TH2D("h_allAK8cjets",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_c_BDSV_L= new TH2D("h_c_BDSV_L",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_c_BDSV_M1= new TH2D("h_c_BDSV_M1",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_c_BDSV_M2= new TH2D("h_c_BDSV_M2",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_c_BDSV_T= new TH2D("h_c_BDSV_T",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_allAK8ljets = new TH2D("h_allAK8ljets",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_l_BDSV_L= new TH2D("h_l_BDSV_L",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_l_BDSV_M1= new TH2D("h_l_BDSV_M1",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_l_BDSV_M2= new TH2D("h_l_BDSV_M2",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);
   TH2D *h_l_BDSV_T= new TH2D("h_l_BDSV_T",";#eta;p_{T}[GeV]",Bnxbins,Bxbins,Bnybins,Bybins);

   TBenchmark time;
   TDatime now;
   now.Print();
   time.Start("time");
   std::cout<<"CPU time = "<<time.GetCpuTime("time")<<", Real time = "<<time.GetRealTime("time")<<std::endl;

   int temp=-1; std::string temp_f=fChain->GetCurrentFile()->GetName();
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<10;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     bool newfile=false;
     if (jentry==0) {
       if (fChain->GetCurrentFile()->GetDirectory("ggNtuplizer") !=0) {
         h_Events = (TH1F*)fChain->GetCurrentFile()->Get("ggNtuplizer/hEvents");
         h_Events->SetDirectory(0);
       }
       else {
         h_Events = (TH1F*)fChain->GetCurrentFile()->Get("hEvents");
         h_Events->SetDirectory(0);
       }
     }

     //progress bar
     double progress=(jentry+1)/double(nentries);
     if (temp!=int(progress * 10000)){
       temp=int(progress * 10000);
       int vmi=int(progress * 100)*100;
       std::cout << vmi/100 <<"."<< temp-vmi << " %\r";
       std::cout.flush();
     }
     if (temp_f != fChain->GetCurrentFile()->GetName()) {
       temp_f=fChain->GetCurrentFile()->GetName();
       newfile=true;
       if (fChain->GetCurrentFile()->GetDirectory("ggNtuplizer") !=0) h_Events->Add((TH1F*)fChain->GetCurrentFile()->Get("ggNtuplizer/hEvents"));
       else h_Events->Add((TH1F*)fChain->GetCurrentFile()->Get("hEvents"));
     }
     //select jets for calculate eff. It should be the same selection as in Analyzer.C
     std::vector<int> passJet, passAK8Jet;
     passJet.clear(); passAK8Jet.clear();
     vector<float> jetSmearedPt;
     vector<float> jetSmearedEn;
     vector<float> AK8JetSmearedPt;
     vector<float> AK8JetSmearedEn;
     //AK4
     for (int i=0;i<nJet;i++) {
       bool passcut=true;
       jetSmearedPt.push_back((*jetPt)[i]);
       jetSmearedEn.push_back((*jetEn)[i]);
       TLorentzVector jetp4;
       jetp4.SetPtEtaPhiE((*jetPt)[i],(*jetEta)[i],(*jetPhi)[i],(*jetEn)[i]);
       if ((*jetP4Smear)[i]>0) {
         jetp4 *=(*jetP4Smear)[i];
         jetSmearedPt.at(i) = jetp4.Pt();
         jetSmearedEn.at(i) = jetp4.Energy();
       }
       if (abs((*jetEta)[i])>3 || (*jetPFLooseId)[i]==0 || jetSmearedPt[i]<40 || !((*jetPUFullID)[i]&(1<<2))) passcut=false;
       if (passcut) passJet.push_back(i);
     }
     //AK8
     for (int i=0;i<nAK8Jet;i++) {
       bool passcut=true;
       AK8JetSmearedPt.push_back((*AK8JetPt)[i]);
       AK8JetSmearedEn.push_back((*AK8JetEn)[i]);
       TLorentzVector jetp4;
       jetp4.SetPtEtaPhiE((*AK8JetPt)[i],(*AK8JetEta)[i],(*AK8JetPhi)[i],(*AK8JetEn)[i]);
       if ((*AK8JetP4Smear)[i]>0) {
         jetp4 *=(*AK8JetP4Smear)[i];
         AK8JetSmearedPt.at(i) = jetp4.Pt();
         AK8JetSmearedEn.at(i) = jetp4.Energy();
       }
       if (abs((*AK8JetEta)[i])>3 || (*AK8JetPFLooseId)[i]==0 || AK8JetSmearedPt[i]<300) passcut=false;
       if (passcut) passAK8Jet.push_back(i);
     }
     for (int i=0;i<passJet.size();i++) {
     //Fill bjet histograms
       if ((*jetHadFlvr)[passJet[i]]==5) {
         double eta=(*jetEta)[passJet[i]];
         double pt=jetSmearedPt[passJet[i]];
         if (pt>2000) pt=2000;
         h_allAK4bjets->Fill(eta,pt);
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[0]) h_b_CSV_L->Fill(eta,pt);
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[1]) h_b_CSV_M->Fill(eta,pt);
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[2]) h_b_CSV_T->Fill(eta,pt);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[0]) h_b_cMVA_L->Fill(eta,pt);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[1]) h_b_cMVA_M->Fill(eta,pt);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[2]) h_b_cMVA_T->Fill(eta,pt);
       }
     //Fill cjet histograms
       if ((*jetHadFlvr)[passJet[i]]==4) {
         double eta=(*jetEta)[passJet[i]];
         double pt=jetSmearedPt[passJet[i]];
         if (pt>2000) pt=2000;
         h_allAK4cjets->Fill(eta,pt);
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[0]) h_c_CSV_L->Fill(eta,pt);
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[1]) h_c_CSV_M->Fill(eta,pt);
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[2]) h_c_CSV_T->Fill(eta,pt);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[0]) h_c_cMVA_L->Fill(eta,pt);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[1]) h_c_cMVA_M->Fill(eta,pt);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[2]) h_c_cMVA_T->Fill(eta,pt);
       }
     //Fill light jet histograms
       if ((*jetHadFlvr)[passJet[i]]==0) {
         double eta=(*jetEta)[passJet[i]];
         double pt=jetSmearedPt[passJet[i]];
         if (pt>2000) pt=2000;
         h_allAK4ljets->Fill(eta,pt);
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[0]) h_l_CSV_L->Fill(eta,pt);
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[1]) h_l_CSV_M->Fill(eta,pt);
         if ((*jetCSV2BJetTags)[passJet.at(i)]>BtagCSVWP[2]) h_l_CSV_T->Fill(eta,pt);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[0]) h_l_cMVA_L->Fill(eta,pt);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[1]) h_l_cMVA_M->Fill(eta,pt);
         if ((*jetpfCombinedMVAV2BJetTags)[passJet.at(i)]>BtagcMVAWP[2]) h_l_cMVA_T->Fill(eta,pt);
       }
     }
     //same for AK8
     for (int i=0;i<passAK8Jet.size();i++){
       if ((*AK8JetHadFlvr)[passAK8Jet[i]]==5) {
         double eta=(*AK8JetEta)[passAK8Jet[i]];
         double pt=AK8JetSmearedPt[passAK8Jet[i]];
         if (pt>2000) pt=2000;
         h_allAK8bjets->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[0]) h_b_BDSV_L->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[1]) h_b_BDSV_M1->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[2]) h_b_BDSV_M2->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[3]) h_b_BDSV_T->Fill(eta,pt);
       }
       if ((*AK8JetHadFlvr)[passAK8Jet[i]]==4) {
         double eta=(*AK8JetEta)[passAK8Jet[i]];
         double pt=AK8JetSmearedPt[passAK8Jet[i]];
         if (pt>2000) pt=2000;
         h_allAK8cjets->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[0]) h_c_BDSV_L->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[1]) h_c_BDSV_M1->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[2]) h_c_BDSV_M2->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[3]) h_c_BDSV_T->Fill(eta,pt);
       }
       if ((*AK8JetHadFlvr)[passAK8Jet[i]]==0) {
         double eta=(*AK8JetEta)[passAK8Jet[i]];
         double pt=AK8JetSmearedPt[passAK8Jet[i]];
         if (pt>2000) pt=2000;
         h_allAK8ljets->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[0]) h_l_BDSV_L->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[1]) h_l_BDSV_M1->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[2]) h_l_BDSV_M2->Fill(eta,pt);
         if ((*AK8JetpfBoostedDSVBTag)[passAK8Jet[i]]>BtagBDSVWP[3]) h_l_BDSV_T->Fill(eta,pt);
       }
     }
   }//end of entry loop
   h_Events->Write();
   f.Write();
   f.Close();
   time.Stop("time");
   std::cout<<"CPU time = "<<time.GetCpuTime("time")<<", Real time = "<<time.GetRealTime("time")<<std::endl;
}
