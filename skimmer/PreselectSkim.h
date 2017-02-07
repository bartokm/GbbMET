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

    TH1F *_h_cuts;
    TH1F *_hPUTrue;
    TH1F *_hEvents;
    TH1F *_hGenWeight;
    //mc cross sections
    float _Asigma[18] = {
      365896,  //gjet
      61526.7, //WjetsToLNu
      117.864, //ZG
      1717000, //qcd_HT_200To300
      351300,  //qcd_HT_300To500
      31630,   //qcd_HT_500To700
      6802,    //qcd_HT_700To1000
      1206,    //qcd_HT_1000To1500
      120.4,   //qcd_HT_1500To2000
      25.25,   //qcd_HT_2000ToInf
      280.35,  //ZJetsToNuNu_HT_100To200
      77.67,   //ZJetsToNuNu_HT_200To400
      10.73,   //ZJetsToNuNu_HT_400To600
      4.116,   //ZJetsToNuNu_HT_600ToInf
      3.697,   //TTGjets
      5.67,    //ZJetsToQQ
      0.834,   //WGJets
      831.76   //TTjets
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
