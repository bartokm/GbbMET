#define CopyTree_cxx
#include "CopyTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

double deltaR(double phi1, double phi2, double eta1, double eta2){
  double dR=0;
  if (abs(phi1-phi2)>M_PI) dR=sqrt(pow(2*M_PI-(phi2-phi1),2)+pow(eta1-eta2,2));
  else dR=sqrt(pow(phi1-phi2,2)+pow(eta1-eta2,2));
  return dR;
}

void CopyTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L CopyTree.C
//      root> CopyTree t
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

   Long64_t nbytes = 0, nb = 0;

   TFile f(output_file.c_str(),"recreate");
   TTree *skimtree = fChain->CloneTree(0);
   //Histograms outside of the EventTree
   TH1F *h_Events;
   TH1F *h_PU;
   TH1F *h_PUTrue;
   TH1F *h_GenWeight;
   TH1F *h_SumGenWeight;

   TBenchmark time;
   TDatime now;
   now.Print();
   time.Start("time");
   std::cout<<"CPU time = "<<time.GetCpuTime("time")<<", Real time = "<<time.GetRealTime("time")<<std::endl;

   bool wasData;
   std::string gDir="";
   int file_counter=-1, temp=-1; std::string temp_f=fChain->GetCurrentFile()->GetName();
   unsigned int maxevents=0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<100;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     bool newfile=false;
     if (jentry==0) {
       if (fChain->GetCurrentFile()->GetDirectory("ggNtuplizer") !=0) gDir="ggNtuplizer/";
       wasData=isData;
       h_Events = (TH1F*)fChain->GetCurrentFile()->Get((gDir+"hEvents").c_str());
       h_Events->SetDirectory(0);
       if (!isData) {
         h_PU = (TH1F*)fChain->GetCurrentFile()->Get((gDir+"hPU").c_str());
         h_PUTrue = (TH1F*)fChain->GetCurrentFile()->Get((gDir+"hPUTrue").c_str());
         h_GenWeight = (TH1F*)fChain->GetCurrentFile()->Get((gDir+"hGenWeight").c_str());
         h_SumGenWeight = (TH1F*)fChain->GetCurrentFile()->Get((gDir+"hSumGenWeight").c_str());
         h_PU->SetDirectory(0);
         h_PUTrue->SetDirectory(0);
         h_GenWeight->SetDirectory(0);
         h_SumGenWeight->SetDirectory(0);
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
       file_counter++;
       newfile=true;
       h_Events->Add((TH1F*)fChain->GetCurrentFile()->Get((gDir+"hEvents").c_str()));
       if (!isData) {
         h_PU->Add((TH1F*)fChain->GetCurrentFile()->Get((gDir+"hPU").c_str()));
         h_PUTrue->Add((TH1F*)fChain->GetCurrentFile()->Get((gDir+"hPUTrue").c_str()));
         h_GenWeight->Add((TH1F*)fChain->GetCurrentFile()->Get((gDir+"hGenWeight").c_str()));
         h_SumGenWeight->Add((TH1F*)fChain->GetCurrentFile()->Get((gDir+"hSumGenWeight").c_str()));
       }
     }
     //Skimming conditions
     bool gWrite=false;
     //For selecting 1H->bb SUSY signal only
     /*
     int higgs=0, neutralino=-1, gluino=-1;
     for (int i=0;i<nMC;i++) {
       if ((*mcPID)[i]==25) higgs++;
       if ((*mcPID)[i]==1000023 && (*mcStatus)[i]==22) neutralino=i;
       if ((*mcPID)[i]==1000021 && (*mcStatus)[i]==22) gluino=i;
     }
     if ((*mcMass)[gluino]!=1000) continue;
     if ((*mcMass)[neutralino]<799 || (*mcMass)[neutralino]>801) continue;
     if (higgs!=1) continue;
     maxevents++;
     gWrite=true;
     int higgs=0, ib1=-1, ib2=-1;
     for (int i=0;i<nMC;i++) {
       if ((*mcPID)[i]==25) higgs++;
       if ((*mcPID)[i]==5 && (*mcMomPID)[i]==25) ib1=i;
       if ((*mcPID)[i]==-5 && (*mcMomPID)[i]==25) ib2=i;
     }
     if (higgs==1 && ib1!=-1 && ib2!=-1) gWrite=true;
     */
     //Requiring 1 loose photon with Et>90, Eta<1.4442, pixelseed==0
     //for (int i=0;i<nPho;i++) if ((*phoCalibEt)[i]>90 && abs((*phoEta)[i])<1.4442 && (*phohasPixelSeed)[i]==0 && (*phoIDbit)[i]>>0&1) {gWrite=true;break;};

     //Requiring trigger
     //if (HLTPho&128) gWrite=true; //HLT_Photon175
     if (HLTPho&4096) gWrite=true; //HLT_Photon165_HE10
     //if (HLTJet&4194304) gWrite=true; //HLT_PFHT300_PFMET110_v

     if (gWrite) skimtree->Fill();
   }//end of entry loop
   skimtree->Write();
   h_Events->Write();
   if (!wasData) {
     //FOR EWKINO:
     //h_SumGenWeight->SetBinContent(1,maxevents);
     h_PU->Write();
     h_PUTrue->Write();
     h_GenWeight->Write();
     h_SumGenWeight->Write();
     TH1D *h_cross_section = new TH1D("h_cross_section","",1,0,1);
     h_cross_section->SetBinContent(1,Cross_Section);
     h_cross_section->Write();
   }
   f.Close();
   time.Stop("time");
   std::cout<<"CPU time = "<<time.GetCpuTime("time")<<", Real time = "<<time.GetRealTime("time")<<std::endl;
}
