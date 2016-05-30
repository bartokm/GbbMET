#ifndef TInputOutputTree_h
#define TInputOutputTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <vector>
class TInputOutputTree{
  public : 
    TInputOutputTree();
    virtual ~TInputOutputTree();
    TString nameFile_;
    TString nameDir_;
    TString nameTree_; 
    bool isMC=true;
    void    InitOutput  (TTree* outputTree, bool isMC);
    void    InitInput   (TTree *tree, bool isMC);

    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
    Int_t           fCurrent; //!current Tree number in a TChain
    TObjArray*      listOfBranches;

    virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; } 
    struct InputTreeLeaves{
      //global event
      Int_t           run;
      Long64_t        event;
      Int_t           lumis;
      Bool_t          isData;
      Int_t           nVtx;
      Int_t           nTrksPV;
      Bool_t          isPVGood;
      Bool_t          hasGoodVtx;
      Float_t         vtx;
      Float_t         vty;
      Float_t         vtz;
      Float_t         rho;
      Float_t         rhoCentral;
      ULong64_t       HLTEleMuX;
      ULong64_t       HLTPho;
      ULong64_t       HLTJet;
      ULong64_t       HLTEleMuXIsPrescaled;
      ULong64_t       HLTPhoIsPrescaled;
      ULong64_t       HLTJetIsPrescaled;
        
      vector<float>   *pdf;
      Float_t         pthat;
      Float_t         processID;
      Float_t         genWeight;
      Float_t         genHT;
      Int_t           nPUInfo;
      vector<int>     *nPU;
      vector<int>     *puBX;
      vector<float>   *puTrue;
      Int_t           nMC;
      vector<int>     *mcPID;
      vector<float>   *mcVtx;
      vector<float>   *mcVty;
      vector<float>   *mcVtz;
      vector<float>   *mcPt;
      vector<float>   *mcMass;
      vector<float>   *mcEta;
      vector<float>   *mcPhi;
      vector<float>   *mcE;
      vector<float>   *mcEt;
      vector<int>     *mcGMomPID;
      vector<int>     *mcMomPID;
      vector<float>   *mcMomPt;
      vector<float>   *mcMomMass;
      vector<float>   *mcMomEta;
      vector<float>   *mcMomPhi;
      vector<int>     *mcIndex;
      vector<unsigned short> *mcStatusFlag;
      vector<int>     *mcParentage;
      vector<int>     *mcStatus;
      vector<float>   *mcCalIsoDR03;
      vector<float>   *mcTrkIsoDR03;
      vector<float>   *mcCalIsoDR04;
      vector<float>   *mcTrkIsoDR04;
      Float_t         genMET;
      Float_t         genMETPhi;
      
      Int_t           metFilters;
      Float_t         pfMET;
      Float_t         pfMETPhi;
      Float_t         pfMETsumEt;
      Float_t         pfMETmEtSig;
      Float_t         pfMETSig;
      Float_t         pfMET_T1JERUp;
      Float_t         pfMET_T1JERDo;
      Float_t         pfMET_T1JESUp;
      Float_t         pfMET_T1JESDo;
      Float_t         pfMET_T1MESUp;
      Float_t         pfMET_T1MESDo;
      Float_t         pfMET_T1EESUp;
      Float_t         pfMET_T1EESDo;
      Float_t         pfMET_T1PESUp;
      Float_t         pfMET_T1PESDo;
      Float_t         pfMET_T1TESUp;
      Float_t         pfMET_T1TESDo;
      Float_t         pfMET_T1UESUp;
      Float_t         pfMET_T1UESDo;
      //photon
      Int_t           nPho;
      vector<float>   *phoE;
      vector<float>   *phoEt;
      vector<float>   *phoEta;
      vector<float>   *phoPhi;
      vector<float>   *phoCalibE;
      vector<float>   *phoCalibEt;
      vector<float>   *phoSCE;
      vector<float>   *phoSCRawE;
      vector<float>   *phoESEn;
      vector<float>   *phoESEnP1;
      vector<float>   *phoESEnP2;
      vector<float>   *phoSCEta;
      vector<float>   *phoSCPhi;
      vector<float>   *phoSCEtaWidth;
      vector<float>   *phoSCPhiWidth;
      vector<float>   *phoSCBrem;
      vector<int>     *phohasPixelSeed;
      vector<int>     *phoEleVeto;
      vector<float>   *phoR9;
      vector<float>   *phoHoverE;
      vector<float>   *phoSigmaIEtaIEta;
      vector<float>   *phoSigmaIEtaIPhi;
      vector<float>   *phoSigmaIPhiIPhi;
      vector<float>   *phoE1x3;
      vector<float>   *phoE2x2;
      vector<float>   *phoE2x5Max;
      vector<float>   *phoE5x5;
      vector<float>   *phoESEffSigmaRR;
      vector<float>   *phoSigmaIEtaIEtaFull5x5;
      vector<float>   *phoSigmaIEtaIPhiFull5x5;
      vector<float>   *phoSigmaIPhiIPhiFull5x5;
      vector<float>   *phoE1x3Full5x5;
      vector<float>   *phoE2x2Full5x5;
      vector<float>   *phoE2x5MaxFull5x5;
      vector<float>   *phoE5x5Full5x5;
      vector<float>   *phoR9Full5x5;
      vector<float>   *phoSeedBCE;
      vector<float>   *phoSeedBCEta;
      vector<float>   *phoPFChIso;
      vector<float>   *phoPFPhoIso;
      vector<float>   *phoPFNeuIso;
      vector<float>   *phoPFChWorstIso;
      vector<float>   *phoPFChIsoFrix1;
      vector<float>   *phoPFChIsoFrix2;
      vector<float>   *phoPFChIsoFrix3;
      vector<float>   *phoPFChIsoFrix4;
      vector<float>   *phoPFChIsoFrix5;
      vector<float>   *phoPFChIsoFrix6;
      vector<float>   *phoPFChIsoFrix7;
      vector<float>   *phoPFChIsoFrix8;
      vector<float>   *phoPFPhoIsoFrix1;
      vector<float>   *phoPFPhoIsoFrix2;
      vector<float>   *phoPFPhoIsoFrix3;
      vector<float>   *phoPFPhoIsoFrix4;
      vector<float>   *phoPFPhoIsoFrix5;
      vector<float>   *phoPFPhoIsoFrix6;
      vector<float>   *phoPFPhoIsoFrix7;
      vector<float>   *phoPFPhoIsoFrix8;
      vector<float>   *phoPFNeuIsoFrix1;
      vector<float>   *phoPFNeuIsoFrix2;
      vector<float>   *phoPFNeuIsoFrix3;
      vector<float>   *phoPFNeuIsoFrix4;
      vector<float>   *phoPFNeuIsoFrix5;
      vector<float>   *phoPFNeuIsoFrix6;
      vector<float>   *phoPFNeuIsoFrix7;
      vector<float>   *phoPFNeuIsoFrix8;
      vector<float>   *phoEcalRecHitSumEtConeDR03;
      vector<float>   *phohcalDepth1TowerSumEtConeDR03;
      vector<float>   *phohcalDepth2TowerSumEtConeDR03;
      vector<float>   *phohcalTowerSumEtConeDR03;
      vector<float>   *photrkSumPtHollowConeDR03;
      vector<float>   *photrkSumPtSolidConeDR03;
      vector<float>   *phoIDMVA;
      vector<int>     *phoFiredSingleTrgs;
      vector<int>     *phoFiredDoubleTrgs;
      vector<unsigned short> *phoIDbit;
      //electron
      Int_t           nEle;
      vector<int>     *eleCharge;
      vector<int>     *eleChargeConsistent;
      vector<float>   *eleEn;
      vector<float>   *eleSCEn;
      vector<float>   *eleESEn;
      vector<float>   *eleESEnP1;
      vector<float>   *eleESEnP2;
      vector<float>   *eleD0;
      vector<float>   *eleDz;
      vector<float>   *elePt;
      vector<float>   *eleEta;
      vector<float>   *elePhi;
      vector<float>   *eleR9;
      vector<float>   *eleCalibPt;
      vector<float>   *eleCalibEn;
      vector<float>   *eleSCEta;
      vector<float>   *eleSCPhi;
      vector<float>   *eleSCRawEn;
      vector<float>   *eleSCEtaWidth;
      vector<float>   *eleSCPhiWidth;
      vector<float>   *eleHoverE;
      vector<float>   *eleEoverP;
      vector<float>   *eleEoverPout;
      vector<float>   *eleEoverPInv;
      vector<float>   *eleBrem;
      vector<float>   *eledEtaAtVtx;
      vector<float>   *eledPhiAtVtx;
      vector<float>   *eledEtaAtCalo;
      vector<float>   *eleSigmaIEtaIEta;
      vector<float>   *eleSigmaIEtaIPhi;
      vector<float>   *eleSigmaIPhiIPhi;
      vector<float>   *eleSigmaIEtaIEtaFull5x5;
      vector<float>   *eleSigmaIPhiIPhiFull5x5;
      vector<int>     *eleConvVeto;
      vector<int>     *eleMissHits;
      vector<float>   *eleESEffSigmaRR;
      vector<float>   *elePFChIso;
      vector<float>   *elePFPhoIso;
      vector<float>   *elePFNeuIso;
      vector<float>   *elePFPUIso;
      vector<float>   *elePFClusEcalIso;
      vector<float>   *elePFClusHcalIso;
      vector<float>   *elePFMiniIso;
      vector<float>   *eleIDMVANonTrg;
      vector<float>   *eleIDMVATrg;
      vector<float>   *eledEtaseedAtVtx;
      vector<float>   *eleE1x5;
      vector<float>   *eleE2x5;
      vector<float>   *eleE5x5;
      vector<float>   *eleE1x5Full5x5;
      vector<float>   *eleE2x5Full5x5;
      vector<float>   *eleE5x5Full5x5;
      vector<float>   *eleR9Full5x5;
      vector<int>     *eleEcalDrivenSeed;
      vector<float>   *eleDr03EcalRecHitSumEt;
      vector<float>   *eleDr03HcalDepth1TowerSumEt;
      vector<float>   *eleDr03HcalDepth2TowerSumEt;
      vector<float>   *eleDr03HcalTowerSumEt;
      vector<float>   *eleDr03TkSumPt;
      vector<float>   *elecaloEnergy;
      vector<float>   *eleTrkdxy;
      vector<float>   *eleKFHits;
      vector<float>   *eleKFChi2;
      vector<vector<float> > *eleGSFPt;
      vector<vector<float> > *eleGSFEta;
      vector<vector<float> > *eleGSFPhi;
      vector<vector<float> > *eleGSFCharge;
      vector<vector<int> > *eleGSFHits;
      vector<vector<int> > *eleGSFMissHits;
      vector<vector<int> > *eleGSFNHitsMax;
      vector<vector<float> > *eleGSFVtxProb;
      vector<vector<float> > *eleGSFlxyPV;
      vector<vector<float> > *eleGSFlxyBS;
      vector<vector<float> > *eleBCEn;
      vector<vector<float> > *eleBCEta;
      vector<vector<float> > *eleBCPhi;
      vector<vector<float> > *eleBCS25;
      vector<vector<float> > *eleBCS15;
      vector<vector<float> > *eleBCSieie;
      vector<vector<float> > *eleBCSieip;
      vector<vector<float> > *eleBCSipip;
      vector<int>     *eleFiredTrgs;
      vector<unsigned short> *eleIDbit;
      vector<float>   *eleESEnP1Raw;
      vector<float>   *eleESEnP2Raw;
      Int_t           nGSFTrk;
      vector<float>   *gsfPt;
      vector<float>   *gsfEta;
      vector<float>   *gsfPhi;
      Int_t           npfHF;
      vector<float>   *pfHFEn;
      vector<float>   *pfHFECALEn;
      vector<float>   *pfHFHCALEn;
      vector<float>   *pfHFPt;
      vector<float>   *pfHFEta;
      vector<float>   *pfHFPhi;
      vector<float>   *pfHFIso;
      //muon
      Int_t           nMu;
      vector<float>   *muPt;
      vector<float>   *muEn;
      vector<float>   *muEta;
      vector<float>   *muPhi;
      vector<int>     *muCharge;
      vector<int>     *muType;
      vector<bool>    *muIsLooseID;
      vector<bool>    *muIsMediumID;
      vector<bool>    *muIsTightID;
      vector<bool>    *muIsSoftID;
      vector<bool>    *muIsHighPtID;
      vector<float>   *muD0;
      vector<float>   *muDz;
      vector<float>   *muChi2NDF;
      vector<float>   *muInnerD0;
      vector<float>   *muInnerDz;
      vector<int>     *muTrkLayers;
      vector<int>     *muPixelLayers;
      vector<int>     *muPixelHits;
      vector<int>     *muMuonHits;
      vector<int>     *muStations;
      vector<int>     *muMatches;
      vector<int>     *muTrkQuality;
      vector<float>   *muIsoTrk;
      vector<float>   *muPFChIso;
      vector<float>   *muPFPhoIso;
      vector<float>   *muPFNeuIso;
      vector<float>   *muPFPUIso;
      vector<float>   *muPFMiniIso;
      vector<int>     *muFiredTrgs;
      vector<float>   *muInnervalidFraction;
      vector<float>   *musegmentCompatibility;
      vector<float>   *muchi2LocalPosition;
      vector<float>   *mutrkKink;
      vector<float>   *muBestTrkPtError;
      vector<float>   *muBestTrkPt;
      //AK4Jets
      Int_t           nJet;
      vector<float>   *jetPt;
      vector<float>   *jetEn;
      vector<float>   *jetEta;
      vector<float>   *jetPhi;
      vector<float>   *jetRawPt;
      vector<float>   *jetRawEn;
      vector<float>   *jetMt;
      vector<float>   *jetArea;
      vector<float>   *jetLeadTrackPt;
      vector<float>   *jetLeadTrackEta;
      vector<float>   *jetLeadTrackPhi;
      vector<int>     *jetLepTrackPID;
      vector<float>   *jetLepTrackPt;
      vector<float>   *jetLepTrackEta;
      vector<float>   *jetLepTrackPhi;
      vector<float>   *jetpfCombinedInclusiveSecondaryVertexV2BJetTags;
      vector<float>   *jetJetProbabilityBJetTags;
      vector<float>   *jetpfCombinedMVAV2BJetTags;
      vector<bool>    *jetPFLooseId;
      vector<float>   *jetPUidFullDiscriminant;
      vector<float>   *jetJECUnc;
      vector<int>     *jetFiredTrgs;
      vector<float>   *jetCHF;
      vector<float>   *jetNHF;
      vector<float>   *jetCEF;
      vector<float>   *jetNEF;
      vector<int>     *jetNCH;
      vector<float>   *jetVtxPt;
      vector<float>   *jetVtxMass;
      vector<float>   *jetVtxNtrks;
      vector<float>   *jetVtx3DVal;
      vector<float>   *jetVtx3DSig;
      vector<int>     *jetPartonID;
      vector<int>     *jetGenJetIndex;
      vector<float>   *jetGenJetEn;
      vector<float>   *jetGenJetPt;
      vector<float>   *jetGenJetEta;
      vector<float>   *jetGenJetPhi;
      vector<int>     *jetGenPartonID;
      vector<float>   *jetGenEn;
      vector<float>   *jetGenPt;
      vector<float>   *jetGenEta;
      vector<float>   *jetGenPhi;
      vector<int>     *jetGenPartonMomID;
      
      //AK8Jets
      Int_t           nAK8Jet;
      vector<float>   *AK8JetPt;
      vector<float>   *AK8JetEn;
      vector<float>   *AK8JetRawPt;
      vector<float>   *AK8JetRawEn;
      vector<float>   *AK8JetEta;
      vector<float>   *AK8JetPhi;
      vector<float>   *AK8JetMass;
      vector<float>   *AK8Jet_tau1;
      vector<float>   *AK8Jet_tau2;
      vector<float>   *AK8Jet_tau3;
      vector<float>   *AK8JetCHF;
      vector<float>   *AK8JetNHF;
      vector<float>   *AK8JetCEF;
      vector<float>   *AK8JetNEF;
      vector<int>     *AK8JetNCH;
      vector<int>     *AK8Jetnconstituents;
      vector<float>   *AK8JetMUF;
      vector<bool>    *AK8JetPFLooseId;
      vector<bool>    *AK8JetPFTightLepVetoId;
      vector<float>   *AK8CHSSoftDropJetMass;
      vector<float>   *AK8CHSSoftDropJetMassCorr;
      vector<float>   *AK8CHSPrunedJetMass;
      vector<float>   *AK8CHSPrunedJetMassCorr;
      vector<float>   *AK8JetpfBoostedDSVBTag;
      vector<float>   *AK8JetJECUnc;
      vector<float>   *AK8JetL2L3corr;
      vector<int>     *AK8JetPartonID;
      vector<int>     *AK8JetGenJetIndex;
      vector<float>   *AK8JetGenJetEn;
      vector<float>   *AK8JetGenJetPt;
      vector<float>   *AK8JetGenJetEta;
      vector<float>   *AK8JetGenJetPhi;
      vector<int>     *AK8JetGenPartonID;
      vector<float>   *AK8JetGenEn;
      vector<float>   *AK8JetGenPt;
      vector<float>   *AK8JetGenEta;
      vector<float>   *AK8JetGenPhi;
      vector<int>     *AK8JetGenPartonMomID;
      
      vector<int>     *nAK8softdropSubjet;
      vector<vector<float> > *AK8softdropSubjetPt;
      vector<vector<float> > *AK8softdropSubjetEta;
      vector<vector<float> > *AK8softdropSubjetPhi;
      vector<vector<float> > *AK8softdropSubjetMass;
      vector<vector<float> > *AK8softdropSubjetE;
      vector<vector<int> > *AK8softdropSubjetCharge;
      vector<vector<int> > *AK8softdropSubjetFlavour;
      vector<vector<float> > *AK8softdropSubjetCSV;
    };

    InputTreeLeaves treeLeaf;
    //Output tree additional leaves.
    struct OutputTreeLeaves{
      vector<float> eeMass;
      vector<float> eegMass;
      vector<float> gammaEt;
      vector<float> deltaR;
    };
    OutputTreeLeaves outLeaf;

    //Global branches
    TBranch        *b_run;   //!
    TBranch        *b_event;   //!
    TBranch        *b_lumis;   //!
    TBranch        *b_isData;   //!
    TBranch        *b_nVtx;   //!
    TBranch        *b_nTrksPV;   //!
    TBranch        *b_isPVGood;///////////////////////////
    TBranch        *b_hasGoodVtx;//////////////////////666
    TBranch        *b_vtx;   //!
    TBranch        *b_vty;   //!
    TBranch        *b_vtz;   //!
    TBranch        *b_rho;   //!
    TBranch        *b_rhoCentral;   //!
    TBranch        *b_HLTEleMuX;   //!
    TBranch        *b_HLTPho;   //!
    TBranch        *b_HLTJet;   //!
    TBranch        *b_HLTEleMuXIsPrescaled;   //!
    TBranch        *b_HLTPhoIsPrescaled;   //!
    TBranch        *b_HLTJetIsPrescaled;   //!
    TBranch        *b_pdf;   //!
    TBranch        *b_pthat;   //!
    TBranch        *b_processID;   //!
    TBranch        *b_genWeight;   //!
    TBranch        *b_genHT;   //!
    TBranch        *b_nPUInfo;   //!
    TBranch        *b_nPU;   //!
    TBranch        *b_puBX;   //!
    TBranch        *b_puTrue;   //!
    TBranch        *b_nMC;   //!
    TBranch        *b_mcPID;   //!
    TBranch        *b_mcVtx;   //!
    TBranch        *b_mcVty;   //!
    TBranch        *b_mcVtz;   //!
    TBranch        *b_mcPt;   //!
    TBranch        *b_mcMass;   //!
    TBranch        *b_mcEta;   //!
    TBranch        *b_mcPhi;   //!
    TBranch        *b_mcE;   //!
    TBranch        *b_mcEt;   //!
    TBranch        *b_mcGMomPID;   //!
    TBranch        *b_mcMomPID;   //!
    TBranch        *b_mcMomPt;   //!
    TBranch        *b_mcMomMass;   //!
    TBranch        *b_mcMomEta;   //!
    TBranch        *b_mcMomPhi;   //!
    TBranch        *b_mcIndex;   //!
    TBranch        *b_mcStatusFlag;   //!
    TBranch        *b_mcParentage;   //!
    TBranch        *b_mcStatus;   //!
    TBranch        *b_mcCalIsoDR03;   //!
    TBranch        *b_mcTrkIsoDR03;   //!
    TBranch        *b_mcCalIsoDR04;   //!
    TBranch        *b_mcTrkIsoDR04;   //!
    TBranch        *b_genMET;   //!
    TBranch        *b_genMETPhi;   //!
    
    TBranch        *b_metFilters;   //!
    TBranch        *b_pfMET;   //!
    TBranch        *b_pfMETPhi;   //!
    TBranch        *b_pfMETsumEt;   //!
    TBranch        *b_pfMETmEtSig;   //!
    TBranch        *b_pfMETSig;   //!
    TBranch        *b_pfMET_T1JERUp;   //!
    TBranch        *b_pfMET_T1JERDo;   //!
    TBranch        *b_pfMET_T1JESUp;   //!
    TBranch        *b_pfMET_T1JESDo;   //!
    TBranch        *b_pfMET_T1MESUp;   //!
    TBranch        *b_pfMET_T1MESDo;   //!
    TBranch        *b_pfMET_T1EESUp;   //!
    TBranch        *b_pfMET_T1EESDo;   //!
    TBranch        *b_pfMET_T1PESUp;   //!
    TBranch        *b_pfMET_T1PESDo;   //!
    TBranch        *b_pfMET_T1TESUp;   //!
    TBranch        *b_pfMET_T1TESDo;   //!
    TBranch        *b_pfMET_T1UESUp;   //!
    TBranch        *b_pfMET_T1UESDo;   //!
    //photon
    TBranch        *b_nPho;   //!
    TBranch        *b_phoE;   //!
    TBranch        *b_phoEt;   //!
    TBranch        *b_phoEta;   //!
    TBranch        *b_phoPhi;   //!
    TBranch        *b_phoCalibE;//6666666666666666666666666666666666666
    TBranch        *b_phoCalibEt;//66666666666666666666666666666666666666666
    TBranch        *b_phoSCE;   //!
    TBranch        *b_phoSCRawE;   //!
    TBranch        *b_phoESEn;   //!
    TBranch        *b_phoESEnP1;   //!
    TBranch        *b_phoESEnP2;   //!
    TBranch        *b_phoSCEta;   //!
    TBranch        *b_phoSCPhi;   //!
    TBranch        *b_phoSCEtaWidth;   //!
    TBranch        *b_phoSCPhiWidth;   //!
    TBranch        *b_phoSCBrem;   //!
    TBranch        *b_phohasPixelSeed;   //!
    TBranch        *b_phoEleVeto;   //!
    TBranch        *b_phoR9;   //!
    TBranch        *b_phoHoverE;   //!
    TBranch        *b_phoSigmaIEtaIEta;   //!
    TBranch        *b_phoSigmaIEtaIPhi;   //!
    TBranch        *b_phoSigmaIPhiIPhi;   //!
    TBranch        *b_phoE1x3;   //!
    TBranch        *b_phoE2x2;   //!
    TBranch        *b_phoE2x5Max;   //!
    TBranch        *b_phoE5x5;   //!
    TBranch        *b_phoESEffSigmaRR;   //!
    TBranch        *b_phoSigmaIEtaIEtaFull5x5;   //!
    TBranch        *b_phoSigmaIEtaIPhiFull5x5;   //!
    TBranch        *b_phoSigmaIPhiIPhiFull5x5;   //!
    TBranch        *b_phoE1x3Full5x5;   //!
    TBranch        *b_phoE2x2Full5x5;   //!
    TBranch        *b_phoE2x5MaxFull5x5;   //!
    TBranch        *b_phoE5x5Full5x5;   //!
    TBranch        *b_phoR9Full5x5;   //!
    TBranch        *b_phoSeedBCE;   //!
    TBranch        *b_phoSeedBCEta;   //!
    TBranch        *b_phoPFChIso;   //!
    TBranch        *b_phoPFPhoIso;   //!
    TBranch        *b_phoPFNeuIso;   //!
    TBranch        *b_phoPFChWorstIso;   //!
    TBranch        *b_phoPFChIsoFrix1;   //!
    TBranch        *b_phoPFChIsoFrix2;   //!
    TBranch        *b_phoPFChIsoFrix3;   //!
    TBranch        *b_phoPFChIsoFrix4;   //!
    TBranch        *b_phoPFChIsoFrix5;   //!
    TBranch        *b_phoPFChIsoFrix6;   //!
    TBranch        *b_phoPFChIsoFrix7;   //!
    TBranch        *b_phoPFChIsoFrix8;   //!
    TBranch        *b_phoPFPhoIsoFrix1;   //!
    TBranch        *b_phoPFPhoIsoFrix2;   //!
    TBranch        *b_phoPFPhoIsoFrix3;   //!
    TBranch        *b_phoPFPhoIsoFrix4;   //!
    TBranch        *b_phoPFPhoIsoFrix5;   //!
    TBranch        *b_phoPFPhoIsoFrix6;   //!
    TBranch        *b_phoPFPhoIsoFrix7;   //!
    TBranch        *b_phoPFPhoIsoFrix8;   //!
    TBranch        *b_phoPFNeuIsoFrix1;   //!
    TBranch        *b_phoPFNeuIsoFrix2;   //!
    TBranch        *b_phoPFNeuIsoFrix3;   //!
    TBranch        *b_phoPFNeuIsoFrix4;   //!
    TBranch        *b_phoPFNeuIsoFrix5;   //!
    TBranch        *b_phoPFNeuIsoFrix6;   //!
    TBranch        *b_phoPFNeuIsoFrix7;   //!
    TBranch        *b_phoPFNeuIsoFrix8;   //!
    TBranch        *b_phoEcalRecHitSumEtConeDR03;   //!
    TBranch        *b_phohcalDepth1TowerSumEtConeDR03;   //!
    TBranch        *b_phohcalDepth2TowerSumEtConeDR03;   //!
    TBranch        *b_phohcalTowerSumEtConeDR03;   //!
    TBranch        *b_photrkSumPtHollowConeDR03;   //!
    TBranch        *b_photrkSumPtSolidConeDR03;//6666666666666666666666666666666
    TBranch        *b_phoIDMVA;   //!
    TBranch        *b_phoFiredSingleTrgs;   //!
    TBranch        *b_phoFiredDoubleTrgs;   //!
    TBranch        *b_phoIDbit;   //!
    //electron
    TBranch        *b_nEle;   //!
    TBranch        *b_eleCharge;   //!
    TBranch        *b_eleChargeConsistent;   //!
    TBranch        *b_eleEn;   //!
    TBranch        *b_eleSCEn;   //!
    TBranch        *b_eleESEn;   //!
    TBranch        *b_eleESEnP1;   //!
    TBranch        *b_eleESEnP2;   //!
    TBranch        *b_eleD0;   //!
    TBranch        *b_eleDz;   //!
    TBranch        *b_elePt;   //!
    TBranch        *b_eleEta;   //!
    TBranch        *b_elePhi;   //!
    TBranch        *b_eleR9;   //!
    TBranch        *b_eleCalibPt;//66666666666666666666666666
    TBranch        *b_eleCalibEn;//6666666666666666666666666
    TBranch        *b_eleSCEta;   //!
    TBranch        *b_eleSCPhi;   //!
    TBranch        *b_eleSCRawEn;   //!
    TBranch        *b_eleSCEtaWidth;   //!
    TBranch        *b_eleSCPhiWidth;   //!
    TBranch        *b_eleHoverE;   //!
    TBranch        *b_eleEoverP;   //!
    TBranch        *b_eleEoverPout;   //!
    TBranch        *b_eleEoverPInv;   //!
    TBranch        *b_eleBrem;   //!
    TBranch        *b_eledEtaAtVtx;   //!
    TBranch        *b_eledPhiAtVtx;   //!
    TBranch        *b_eledEtaAtCalo;   //!
    TBranch        *b_eleSigmaIEtaIEta;   //!
    TBranch        *b_eleSigmaIEtaIPhi;   //!
    TBranch        *b_eleSigmaIPhiIPhi;   //!
    TBranch        *b_eleSigmaIEtaIEtaFull5x5;   //!
    TBranch        *b_eleSigmaIPhiIPhiFull5x5;   //!
    TBranch        *b_eleConvVeto;   //!
    TBranch        *b_eleMissHits;   //!
    TBranch        *b_eleESEffSigmaRR;   //!
    TBranch        *b_elePFChIso;   //!
    TBranch        *b_elePFPhoIso;   //!
    TBranch        *b_elePFNeuIso;   //!
    TBranch        *b_elePFPUIso;   //!
    TBranch        *b_elePFClusEcalIso;//6666666666666666
    TBranch        *b_elePFClusHcalIso;//66666666666666666666
    TBranch        *b_elePFMiniIso;//6666666666666666666666666
    TBranch        *b_eleIDMVANonTrg;   //!
    TBranch        *b_eleIDMVATrg;   //!
    TBranch        *b_eledEtaseedAtVtx;   //!
    TBranch        *b_eleE1x5;   //!
    TBranch        *b_eleE2x5;   //!
    TBranch        *b_eleE5x5;   //!
    TBranch        *b_eleE1x5Full5x5;   //!
    TBranch        *b_eleE2x5Full5x5;   //!
    TBranch        *b_eleE5x5Full5x5;   //!
    TBranch        *b_eleR9Full5x5;   //!
    TBranch        *b_eleEcalDrivenSeed;   //!
    TBranch        *b_eleDr03EcalRecHitSumEt;   //!
    TBranch        *b_eleDr03HcalDepth1TowerSumEt;   //!
    TBranch        *b_eleDr03HcalDepth2TowerSumEt;   //!
    TBranch        *b_eleDr03HcalTowerSumEt;   //!
    TBranch        *b_eleDr03TkSumPt;   //!
    TBranch        *b_elecaloEnergy;   //!
    TBranch        *b_eleTrkdxy;   //!
    TBranch        *b_eleKFHits;   //!
    TBranch        *b_eleKFChi2;   //!
    TBranch        *b_eleGSFPt;   //!
    TBranch        *b_eleGSFEta;   //!
    TBranch        *b_eleGSFPhi;   //!
    TBranch        *b_eleGSFCharge;   //!
    TBranch        *b_eleGSFHits;   //!
    TBranch        *b_eleGSFMissHits;   //!
    TBranch        *b_eleGSFNHitsMax;   //!
    TBranch        *b_eleGSFVtxProb;   //!
    TBranch        *b_eleGSFlxyPV;   //!
    TBranch        *b_eleGSFlxyBS;   //!
    TBranch        *b_eleBCEn;   //!
    TBranch        *b_eleBCEta;   //!
    TBranch        *b_eleBCPhi;   //!
    TBranch        *b_eleBCS25;   //!
    TBranch        *b_eleBCS15;   //!
    TBranch        *b_eleBCSieie;   //!
    TBranch        *b_eleBCSieip;   //!
    TBranch        *b_eleBCSipip;   //!
    TBranch        *b_eleFiredTrgs;   //!
    TBranch        *b_eleIDbit;   //!
    TBranch        *b_eleESEnP1Raw;   //!
    TBranch        *b_eleESEnP2Raw;   //!
    TBranch        *b_nGSFTrk;   //!
    TBranch        *b_gsfPt;   //!
    TBranch        *b_gsfEta;   //!
    TBranch        *b_gsfPhi;   //!
    TBranch        *b_npfHF;   //!
    TBranch        *b_pfHFEn;   //!
    TBranch        *b_pfHFECALEn;   //!
    TBranch        *b_pfHFHCALEn;   //!
    TBranch        *b_pfHFPt;   //!
    TBranch        *b_pfHFEta;   //!
    TBranch        *b_pfHFPhi;   //!
    TBranch        *b_pfHFIso;   //!
    //muon
    TBranch        *b_nMu;   //!
    TBranch        *b_muPt;   //!
    TBranch        *b_muEn;   //!
    TBranch        *b_muEta;   //!
    TBranch        *b_muPhi;   //!
    TBranch        *b_muCharge;   //!
    TBranch        *b_muType;   //!
    TBranch        *b_muIsLooseID;   //!
    TBranch        *b_muIsMediumID;   //!
    TBranch        *b_muIsTightID;   //!
    TBranch        *b_muIsSoftID;   //!
    TBranch        *b_muIsHighPtID;   //!
    TBranch        *b_muD0;   //!
    TBranch        *b_muDz;   //!
    TBranch        *b_muChi2NDF;   //!
    TBranch        *b_muInnerD0;   //!
    TBranch        *b_muInnerDz;   //!
    TBranch        *b_muTrkLayers;   //!
    TBranch        *b_muPixelLayers;   //!
    TBranch        *b_muPixelHits;   //!
    TBranch        *b_muMuonHits;   //!
    TBranch        *b_muStations;   //!
    TBranch        *b_muMatches;//666666666666666666666666666
    TBranch        *b_muTrkQuality;   //!
    TBranch        *b_muIsoTrk;   //!
    TBranch        *b_muPFChIso;   //!
    TBranch        *b_muPFPhoIso;   //!
    TBranch        *b_muPFNeuIso;   //!
    TBranch        *b_muPFPUIso;   //!
    TBranch        *b_muFiredTrgs;   //!
    TBranch        *b_muInnervalidFraction;   //!
    TBranch        *b_musegmentCompatibility;   //!
    TBranch        *b_muchi2LocalPosition;   //!
    TBranch        *b_mutrkKink;   //!
    TBranch        *b_muBestTrkPtError;   //!
    TBranch        *b_muBestTrkPt;   //!
    //AK4Jets
    TBranch        *b_nJet;   //!
    TBranch        *b_jetPt;   //!
    TBranch        *b_jetEn;   //!
    TBranch        *b_jetEta;   //!
    TBranch        *b_jetPhi;   //!
    TBranch        *b_jetRawPt;   //!
    TBranch        *b_jetRawEn;   //!
    TBranch        *b_jetMt;//666666666666666666666666
    TBranch        *b_jetArea;   //!
    TBranch        *b_jetLeadTrackPt;//66666666666666666666666
    TBranch        *b_jetLeadTrackEta;//66666666666666666666666
    TBranch        *b_jetLeadTrackPhi;//66666666666666666666666
    TBranch        *b_jetLepTrackPID;//66666666666666666666666
    TBranch        *b_jetLepTrackPt;//66666666666666666666666
    TBranch        *b_jetLepTrackEta;//66666666666666666666666
    TBranch        *b_jetLepTrackPhi;//66666666666666666666666
    TBranch        *b_jetpfCombinedInclusiveSecondaryVertexV2BJetTags;   //!
    TBranch        *b_jetJetProbabilityBJetTags;   //!
    TBranch        *b_jetpfCombinedMVAV2BJetTags;   //!
    TBranch        *b_jetPFLooseId;   //!
    TBranch        *b_jetPUidFullDiscriminant;   //!
    TBranch        *b_jetJECUnc;   //!
    TBranch        *b_jetFiredTrgs;   //!
    TBranch        *b_jetCHF;   //!
    TBranch        *b_jetNHF;   //!
    TBranch        *b_jetCEF;   //!
    TBranch        *b_jetNEF;   //!
    TBranch        *b_jetNCH;   //!
    TBranch        *b_jetVtxPt;//666666666666666666666
    TBranch        *b_jetVtxMass;//666666666666666666666
    TBranch        *b_jetVtxNtrks;//666666666666666666666
    TBranch        *b_jetVtx3DVal;//666666666666666666666
    TBranch        *b_jetVtx3DSig;//666666666666666666666
    TBranch        *b_jetPartonID;   //!
    TBranch        *b_jetGenJetIndex;   //!
    TBranch        *b_jetGenJetEn;   //!
    TBranch        *b_jetGenJetPt;   //!
    TBranch        *b_jetGenJetEta;   //!
    TBranch        *b_jetGenJetPhi;   //!
    TBranch        *b_jetGenPartonID;   //!
    TBranch        *b_jetGenEn;   //!
    TBranch        *b_jetGenPt;   //!
    TBranch        *b_jetGenEta;   //!
    TBranch        *b_jetGenPhi;   //!
    TBranch        *b_jetGenPartonMomID;   //!
    
    //AK8Jets
    TBranch        *b_nAK8Jet;   //!
    TBranch        *b_AK8JetPt;   //!
    TBranch        *b_AK8JetEn;   //!
    TBranch        *b_AK8JetRawPt;   //!
    TBranch        *b_AK8JetRawEn;   //!
    TBranch        *b_AK8JetEta;   //!
    TBranch        *b_AK8JetPhi;   //!
    TBranch        *b_AK8JetMass;   //!
    TBranch        *b_AK8Jet_tau1;   //!
    TBranch        *b_AK8Jet_tau2;   //!
    TBranch        *b_AK8Jet_tau3;   //!
    TBranch        *b_AK8JetCHF;   //!
    TBranch        *b_AK8JetNHF;   //!
    TBranch        *b_AK8JetCEF;   //!
    TBranch        *b_AK8JetNEF;   //!
    TBranch        *b_AK8JetNCH;   //!
    TBranch        *b_AK8Jetnconstituents;   //!
    TBranch        *b_AK8JetMUF;//666666666666666
    TBranch        *b_AK8JetPFLooseId;   //!
    TBranch        *b_AK8JetPFTightLepVetoId;//666666666666666666666
    TBranch        *b_AK8CHSSoftDropJetMass;   //!
    TBranch        *b_AK8CHSSoftDropJetMassCorr;   //666666666666666666666!
    TBranch        *b_AK8CHSPrunedJetMass;//66666666666666666
    TBranch        *b_AK8CHSPrunedJetMassCorr;//6666666666666666666
    TBranch        *b_AK8JetpfBoostedDSVBTag;   //!
    TBranch        *b_AK8JetJECUnc;   //!
    TBranch        *b_AK8JetL2L3corr;//6666666666666666666
    TBranch        *b_AK8JetPartonID;   //!
    TBranch        *b_AK8JetGenJetIndex;   //!
    TBranch        *b_AK8JetGenJetEn;   //!
    TBranch        *b_AK8JetGenJetPt;   //!
    TBranch        *b_AK8JetGenJetEta;   //!
    TBranch        *b_AK8JetGenJetPhi;   //!
    TBranch        *b_AK8JetGenPartonID;   //!
    TBranch        *b_AK8JetGenEn;   //!
    TBranch        *b_AK8JetGenPt;   //!
    TBranch        *b_AK8JetGenEta;   //!
    TBranch        *b_AK8JetGenPhi;   //!
    TBranch        *b_AK8JetGenPartonMomID;   //!
    
    TBranch        *b_nAK8softdropSubjet;   //!
    TBranch        *b_AK8softdropSubjetPt;   //!
    TBranch        *b_AK8softdropSubjetEta;   //!
    TBranch        *b_AK8softdropSubjetPhi;   //!
    TBranch        *b_AK8softdropSubjetMass;   //!
    TBranch        *b_AK8softdropSubjetE;   //!
    TBranch        *b_AK8softdropSubjetCharge;   //!
    TBranch        *b_AK8softdropSubjetFlavour;   //!
    TBranch        *b_AK8softdropSubjetCSV;   //!
};

#endif
