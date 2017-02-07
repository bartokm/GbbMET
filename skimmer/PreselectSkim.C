#include "PreselectSkim.h"
#include "datasets.h"
#include <TString.h>
#include <TSystem.h>
#include <TTree.h>
#include <TH1F.h>
#include <TKey.h>
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
  if (isMC) _sigma=_Asigma[config-3];

  _skimmedFileName=outDir+skimPartOfName;
  if (gSystem->AccessPathName(_skimmedFileName+".root")) _fileOut = new TFile(_skimmedFileName+".root","new");
  else _fileOut = new TFile(_skimmedFileName+"_temp.root","recreate");
  _outputTree = new TTree(_nameTree,_nameTree);
  _TREE.InitOutput(_outputTree,isMC);      //method of TInputOutputTree
  //_hStats= new TH1F("hStats","hStats",20,0,20);    
  if (isMC) { std::cout<< " this is simulation. Cross section = "<<_sigma <<std::endl;}
}

PreselectSkim::~PreselectSkim()
{

}

void PreselectSkim::LoopOverInputTree(bool isMC)
{
  TTree *tree;
  TChain * ch = new TChain("EventTree","");
  ch->Add(_inputFileName+"/ggNtuplizer/EventTree");
  tree = ch;
  std::cout<<"# of files: "<<ch->GetNtrees()<<std::endl;

  _TREE.InitInput(tree,isMC);

  Long64_t nentries = _TREE.fChain->GetEntries();
  std::cout<<"nentries "<<nentries<<std::endl;
  //get histograms outside of tree
  _hEvents= (TH1F*)_TREE.fChain->GetCurrentFile()->Get("ggNtuplizer/hEvents");
  _hEvents->SetDirectory(0);
  if (isMC) {
    _hPUTrue = (TH1F*)_TREE.fChain->GetCurrentFile()->GetDirectory("ggNtuplizer")->Get("hPUTrue");
    _hPUTrue->SetDirectory(0);
    _hGenWeight = (TH1F*)_TREE.fChain->GetCurrentFile()->GetDirectory("ggNtuplizer")->Get("hGenWeight");
    _hGenWeight->SetDirectory(0);
  }

  _h_cuts = new TH1F("_h_cuts","cuts;#sigma_{MC},Full,HLT",10,0,10);
  _h_cuts->SetBinContent(1,_sigma);
  if (!isMC) _h_cuts->SetBinContent(2,nentries);
  int temp=-1; std::string tempfilename=_TREE.fChain->GetCurrentFile()->GetName();
  int tempnumber=_TREE.fChain->GetTreeNumber();
  for (Long64_t jentry=0; jentry<nentries; jentry++) {
  //for (Long64_t jentry=0; jentry<100000; jentry++) {
    gWrite=false; // tells us what events to print to skim.
    Long64_t ientry = _TREE.LoadTree(jentry);
    if (ientry < 0) break;
    _TREE.GetEntry(ientry); 
    //progress bar
    double progress=(jentry+1)/double(nentries);
    if (temp!=int(progress * 10000)){
      temp=int(progress * 10000);
      int vmi=int(progress * 100)*100;
      std::cout << vmi/100 <<"."<< temp-vmi << " %\r";
      std::cout.flush();
    }
    if (tempnumber!=_TREE.fChain->GetTreeNumber()) {
      tempnumber=_TREE.fChain->GetTreeNumber();
      std::cout<<_TREE.fChain->GetCurrentFile()->GetName()<<std::endl;
    }
    if (tempfilename != _TREE.fChain->GetCurrentFile()->GetName()) {
      tempfilename = _TREE.fChain->GetCurrentFile()->GetName();
      _hEvents->Add((TH1D*)_TREE.fChain->GetCurrentFile()->GetDirectory("ggNtuplizer")->Get("hEvents"));
      if (isMC) {
        _hPUTrue->Add((TH1D*)_TREE.fChain->GetCurrentFile()->GetDirectory("ggNtuplizer")->Get("hPUTrue"));
        _hGenWeight->Add((TH1D*)_TREE.fChain->GetCurrentFile()->GetDirectory("ggNtuplizer")->Get("hGenWeight"));
      }
    }
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
        
        //MVA based photon selection
        else if (abs(_TREE.treeLeaf.phoEta->at(i))<1.4442 && _TREE.treeLeaf.phoIDMVA->at(i)>0.374) gWrite=true;
      }
    }

    if(gWrite) _outputTree->Fill();
  }//end of entry loop
  std::cout<<std::endl;
  _fileOut->cd();
  _h_cuts->Write();
  _hEvents->Write();
  if (isMC) {
    _hPUTrue->Write();
    _hGenWeight->Write();
  }
  _outputTree->Write(_nameTree,TObject::kOverwrite);

  //close output files
  _TREE.fChain = 0;
  std::cout<<"file "<<_fileOut->GetName()<<std::endl<<" closed..."<<std::endl;
}


float PreselectSkim::deltaR(float phi0, float phi1, float eta0, float eta1){
  double dR=0;
  if (abs(phi0-phi1)>M_PI) dR=sqrt(pow(phi1-phi0,2)+pow(eta0-eta1,2));
  else dR=sqrt(pow(phi0-phi1,2)+pow(eta0-eta1,2));
  return dR;
}
