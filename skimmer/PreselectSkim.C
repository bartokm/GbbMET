#include "PreselectSkim.h"
#include "datasets.h"
#include <TString.h>
#include <TSystem.h>
#include <TTree.h>
#include <TH1F.h>
#include <iostream>

PreselectSkim::PreselectSkim(TString inputFileName, TString outDir, TString nameDir, TString nameTree, bool isMC, int config)
{
 
  _nameDir=nameDir;
  _nameTree=nameTree;
  _inputFileName=inputFileName;

  TString inpTemp = _inputFileName;
  while (inpTemp.Contains('/')){
    inpTemp.Remove(0,1);
  }
  inpTemp.ReplaceAll(".root","");
  TString skimPartOfName=skimName[config]; //expand this!
  if (isMC) _sigma=_Asigma[config-4];

  _skimmedFileName=outDir+skimPartOfName;
  if (gSystem->AccessPathName(_skimmedFileName+".root")) _fileOut = new TFile(_skimmedFileName+".root","new");
  else _fileOut = new TFile(_skimmedFileName+"_temp.root","recreate");
  _outputTree = new TTree(_nameTree,_nameTree);
  _TREE.InitOutput(_outputTree,isMC);      //method of TInputOutputTree
  //_hStats= new TH1F("hStats","hStats",20,0,20);    
  if (isMC) { std::cout<< " this is simulation " <<std::endl;}
}

PreselectSkim::~PreselectSkim()
{

}

void PreselectSkim::LoopOverInputTree(bool isMC)
{
  //TFile f(_inputFileName,"READ");
  TFile *f=TFile::Open(_inputFileName,"READ");
  std::cout<<"processing "<<_inputFileName<<std::endl;
  f->cd(_nameDir);
  TTree* tree =(TTree*)gDirectory->Get(_nameTree);

  _TREE.InitInput(tree,isMC);

  Long64_t nentries = _TREE.fChain->GetEntries();
  std::cout<<"nentries "<<nentries<<std::endl;
             
  _h_cuts = new TH1D("_h_cuts","cuts;#sigma_{MC},Full,HLT",10,0,10);
  _h_cuts->SetBinContent(1,_sigma);
  if (!isMC) _h_cuts->SetBinContent(2,nentries);
  int temp=-1;
  for (Long64_t entry=0; entry<nentries; entry++) {
  //for (Long64_t entry=0; entry<100; entry++) {
    gWrite=false; // tells us what events to print to skim.
    if (entry < 0) break;
    //progress bar
    double progress=(entry+1)/double(nentries);
    if (temp!=int(progress * 100.0)){
      temp=int(progress * 100.0);
      std::cout << temp << " %\r";
      std::cout.flush();
    }
    _TREE.GetEntry(entry); 
    double genWeight=1;
    if (isMC){
      if (abs(_TREE.treeLeaf.genWeight)>1) genWeight=copysign(1,_TREE.treeLeaf.genWeight); //only a sign for amcatnlo
      else genWeight=_TREE.treeLeaf.genWeight; //0-1 for madgraph
      _h_cuts->Fill(1,genWeight);
    }

    //basic pre-selection corrected.
    if (_TREE.treeLeaf.HLTPho&128){ //HLT_Photon175
      _h_cuts->Fill(2,genWeight);
      for (int i=0;i<_TREE.treeLeaf.nPho;i++){
        //cut based photon selection
        if (abs(_TREE.treeLeaf.phoEta->at(i))<1.4442 && _TREE.treeLeaf.phoIDbit->at(i)>>0&1) gWrite=true;
        //if (abs(_TREE.treeLeaf.phoEta->at(i))<1.4442 && _TREE.treeLeaf.phoHoverE->at(i)<0.05 && _TREE.treeLeaf.phoSigmaIEtaIEta->at(i)<0.0102 && _TREE.treeLeaf.phoPFChIso->at(i)<3.32 && _TREE.treeLeaf.phoPFNeuIso->at(i)<(1.92+_TREE.treeLeaf.phoEt->at(i)*0.014+pow(_TREE.treeLeaf.phoEt->at(i),2)*0.000019) && _TREE.treeLeaf.phoPFPhoIso->at(i)<(0.81+_TREE.treeLeaf.phoEt->at(i)*0.0053)) gWrite=true; //not correct
        
        //MVA based photon selection
        else if (abs(_TREE.treeLeaf.phoEta->at(i))<1.4442 && _TREE.treeLeaf.phoIDMVA->at(i)>0.374) gWrite=true;
      }
    }

    if(gWrite) _outputTree->Fill();
  }//end of entry loop
  std::cout<<std::endl;
  if (isMC) _hPUTrue = (TH1D*)gROOT->FindObject("hPUTrue");
  //_hPUTrue = (TH1D*)f->Get("hPUTrue");
  _fileOut->cd();
  _h_cuts->Write();
  if (isMC) _hPUTrue->Write();
  _outputTree->Write(_nameTree,TObject::kOverwrite);

  //close output files
  _TREE.fChain = 0;
  std::cout<<"file "<<_fileOut->GetName()<<std::endl<<" closed..."<<std::endl;
  f->Close();
  //_hStats->SaveAs("hstats"+_nameTree+".root");
}


float PreselectSkim::deltaR(float phi0, float phi1, float eta0, float eta1){
  double dR=0;
  if (abs(phi0-phi1)>M_PI) dR=sqrt(pow(phi1-phi0,2)+pow(eta0-eta1,2));
  else dR=sqrt(pow(phi0-phi1,2)+pow(eta0-eta1,2));
  return dR;
}
