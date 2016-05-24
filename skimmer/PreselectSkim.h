#ifndef PreselectSkim_h
#define PreselectSkim_h

#include "TInputOutputTree.h"

#include <TTree.h>
#include <TString.h>
#include <TFile.h>
#include <TH1F.h>
#include <TLorentzVector.h>


class PreselectSkim{
  public :
    PreselectSkim(TString inputFileName="/afs/cern.ch/user/n/nfilipov/eos/cms/store/group/phys_smp/ggNtuples/13TeV/data/V07_04_14_00/GoldenJSON/job_data_ggNtuple_DoubleEG_Run2015D_PromptReco-v4_25ns_JSON_Golden_1560pb_miniAOD.root",
        TString outDir="./",
        TString nameDir="ggNtuplizer",
        TString nameTree="EventTree",
        bool isMC = false,
        int config=0
        );
    virtual ~PreselectSkim();
    void LoopOverInputTree(bool isMC);
    float deltaR(float phi0, float phi1, float eta0, float eta1);

    //the main function which is called from outside
    //const static int numberOfTrees=5;
    //tree [0] is input tree;
    //trees [1]-[4] are output trees

  private :
    TInputOutputTree _TREE;
    TFile    *_fileOut; //output Files
    TTree    *_outputTree; //output Trees
    TString  _inputFileName;
    TString  _skimmedFileName;
    TString  _nameDir;
    TString  _nameTree;

    TH1D *_h_cuts;
    TH1D *_hPUTrue;
    //mc cross sections
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT200to300_25ns.root", //sigma=1717000
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT300to500_25ns.root", //sigma=351300
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT500to700_25ns.root", //sigma=31630
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT700to1000_25ns.root", //sigma=6802
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT1000to1500_25ns.root", //sigma=? N=?
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT1500to2000_25ns.root", //sigma=? N=?
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_QCD_HT2000toInf_25ns.root", //sigma=? N=?
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToNuNu_HT-100To200_25ns.root", //sigma=280.35
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToNuNu_HT-200To400_25ns.root", //sigma=313.2
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToNuNu_HT-400To600_25ns.root", //sigma=? N=?
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToNuNu_HT-600ToInf_25ns.root", //sigma=? N=?
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_TTGJets_25ns.root", //sigma=? N=?
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_ZJetsToQQ_HT600toInf_25ns.root", //sigma=? N=?
   "/data/gridout/mbartok/Analysis/BkgMC/CMSSW763p2/job_fall15_WGJets_MonoPhoton_PtG-130_25ns.root" //sigma=? N=?
    float _Asigma[17] = {
      365896,  //gjet
      60290,   //WjetsToLNu
      0,       //ZG
      1717000, //qcd_HT_200To300
      351300,  //qcd_HT_300To500
      31630,   //qcd_HT_500To700
      6802,    //qcd_HT_700To1000
      1206,    //qcd_HT_1000To1500
      120.04,  //qcd_HT_1500To2000
      25.25,   //qcd_HT_2000ToInf
      280.35,   //ZJetsToNuNu_HT_100To200
      313.2,   //ZJetsToNuNu_HT_200To400
      3.648,   //ZJetsToNuNu_HT_400To600
      1.401,   //ZJetsToNuNu_HT_600ToInf
      0,       //TTGjets
      0,       //ZJetsToQQ
      0       //WGJets
      //670.3,   //TTjets
    };
    float _sigma=0;

    bool gWrite ;
    //some leptons...
    //const float _eMass = 0.000510998910; // GeV/c2
    //const float _muMass = 0.1056583715; // GeV/c2
    //const float _tauMass = 1.77682; // GeV/c2
    //        //photon...for safety
    //const float _gMass = 0.; 
    //TLorentzVector lepton1;
    //TLorentzVector lepton2;
    //TLorentzVector ll; 
    //TLorentzVector photon;
    //TLorentzVector llg;
    // some variables for the Filling of events:

    //float _ePt[100]; 
    //float _ePhi[100];
    //float _eEta[100];
    //std::vector<float> _llgm;
    //std::vector<float> _llm;
    //std::vector<float> _gammaEt;
    //std::vector<float> _deltaR;
    //float _goodPhotonsEt[100];
    //int iip;
    //float Mll;
    //float _llpt[100];
    //float _llphi[100];
    //float _lleta[100];
    //float _phoEt[100];
    //float _phoEta[100];
    //float _phoPhi[100];
    //float dR1=0;
    //float dR2=0;
};

#endif
