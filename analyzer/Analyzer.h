//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May 30 10:28:51 2016 by ROOT version 6.02/13
// from TTree EventTree/EventTree
// found on file: /afs/cern.ch/work/m/mbartok/public/mc/ggNtuple/skimmed/V07-06-03-00/job_fall15_QCD_HT200to300_25ns.root
//////////////////////////////////////////////////////////

// Standard C++ libraries
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <typeinfo>
// ROOT libraries
#include "TChain.h"
#include "TChainElement.h"
#include "TCanvas.h"
#include "TStopwatch.h"
#include "TBenchmark.h"
#include "TFile.h"
#include "TEfficiency.h"
#include "TLorentzVector.h"
//BTagSF
#include "input/BTCalibrationStandalone.cpp"

#ifndef Analyzer_h
#define Analyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TGraph.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"

using namespace std;
   
class Analyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Long64_t        event;
   Int_t           lumis;
   Bool_t          isData;
   Int_t           nVtx;
   Int_t           nGoodVtx;
   Int_t           nTrksPV;
   Bool_t          isPVGood;
   Float_t         vtx;
   Float_t         vty;
   Float_t         vtz;
   Float_t         rho;
   Float_t         rhoCentral;
   ULong64_t       HLTEleMuX;
   ULong64_t       HLTPho;
   ULong64_t       HLTPhoRejectedByPS;
   ULong64_t       HLTJet;
   ULong64_t       HLTEleMuXIsPrescaled;
   ULong64_t       HLTPhoIsPrescaled;
   ULong64_t       HLTJetIsPrescaled;
   vector<float>   *pdf;
   Float_t         pthat;
   Float_t         processID;
   Float_t         genWeight;
   Float_t         genHT;
   Float_t         genPho1;
   Float_t         genPho2;
   TString         *EventTag;
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
   Float_t         pfMET_T1UESUp;
   Float_t         pfMET_T1UESDo;
   Float_t         pfMETPhi_T1JESUp;
   Float_t         pfMETPhi_T1JESDo;
   Float_t         pfMETPhi_T1UESUp;
   Float_t         pfMETPhi_T1UESDo;
   Int_t           nPho;
   vector<float>   *phoE;
   vector<float>   *phoEt;
   vector<float>   *phoEta;
   vector<float>   *phoPhi;
   vector<float>   *phoCalibE;
   vector<float>   *phoCalibEt;
   vector<float>   *phoSCE;
   vector<float>   *phoSCRawE;
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
   vector<float>   *phoE1x3;
   vector<float>   *phoE1x5;
   vector<float>   *phoE2x2;
   vector<float>   *phoE2x5Max;
   vector<float>   *phoE5x5;
   vector<float>   *phoESEffSigmaRR;
   vector<float>   *phoSigmaIEtaIEtaFull5x5;
   vector<float>   *phoSigmaIEtaIPhiFull5x5;
   vector<float>   *phoSigmaIPhiIPhiFull5x5;
   vector<float>   *phoE1x3Full5x5;
   vector<float>   *phoE1x5Full5x5;
   vector<float>   *phoE2x2Full5x5;
   vector<float>   *phoE2x5MaxFull5x5;
   vector<float>   *phoE5x5Full5x5;
   vector<float>   *phoR9Full5x5;
   vector<float>   *phoPFChIso;
   vector<float>   *phoPFPhoIso;
   vector<float>   *phoPFNeuIso;
   vector<float>   *phoPFChWorstIso;
   vector<float>   *phoPFRandConeChIso;
   vector<float>   *phoCITKChIso;
   vector<float>   *phoCITKPhoIso;
   vector<float>   *phoCITKNeuIso;
   vector<float>   *phoIDMVA;
   vector<ULong64_t> *phoFiredSingleTrgs;
   vector<ULong64_t> *phoFiredDoubleTrgs;
   vector<ULong64_t> *phoFiredL1Trgs;
   vector<float>   *phoSeedTime;
   vector<float>   *phoSeedEnergy;
   vector<unsigned short> *phoxtalBits;
   vector<unsigned short> *phoIDbit;
   vector<float>   *phoScale_stat_up;
   vector<float>   *phoScale_stat_dn;
   vector<float>   *phoScale_syst_up;
   vector<float>   *phoScale_syst_dn;
   vector<float>   *phoScale_gain_up;
   vector<float>   *phoScale_gain_dn;
   vector<float>   *phoResol_rho_up;
   vector<float>   *phoResol_rho_dn;
   vector<float>   *phoResol_phi_up;
   vector<float>   *phoResol_phi_dn;
   Int_t           nEle;
   vector<int>     *eleCharge;
   vector<int>     *eleChargeConsistent;
   vector<float>   *eleEn;
   vector<float>   *eleSCEn;
   vector<float>   *eleEcalEn;
   vector<float>   *eleESEnP1;
   vector<float>   *eleESEnP2;
   vector<float>   *eleD0;
   vector<float>   *eleDz;
   vector<float>   *eleSIP;
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
   vector<float>   *eleIDMVA;
   vector<float>   *eleIDMVAHZZ;
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
   vector<float>   *eleGSFChi2;
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
   vector<ULong64_t> *eleFiredSingleTrgs;
   vector<ULong64_t> *eleFiredDoubleTrgs;
   vector<ULong64_t> *eleFiredL1Trgs;
   vector<unsigned short> *eleIDbit;
   vector<float>   *eleScale_stat_up;
   vector<float>   *eleScale_stat_dn;
   vector<float>   *eleScale_syst_up;
   vector<float>   *eleScale_syst_dn;
   vector<float>   *eleScale_gain_up;
   vector<float>   *eleScale_gain_dn;
   vector<float>   *eleResol_rho_up;
   vector<float>   *eleResol_rho_dn;
   vector<float>   *eleResol_phi_up;
   vector<float>   *eleResol_phi_dn;
   Int_t           nMu;
   vector<float>   *muPt;
   vector<float>   *muEn;
   vector<float>   *muEta;
   vector<float>   *muPhi;
   vector<int>     *muCharge;
   vector<int>     *muType;
   vector<unsigned short> *muIDbit;
   vector<float>   *muD0;
   vector<float>   *muDz;
   vector<float>   *muSIP;
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
   vector<float>   *muPFChIso03;
   vector<float>   *muPFPhoIso03;
   vector<float>   *muPFNeuIso03;
   vector<float>   *muPFPUIso03;
   vector<float>   *muPFMiniIso;
   vector<ULong64_t> *muFiredTrgs;
   vector<ULong64_t> *muFiredL1Trgs;
   vector<float>   *muInnervalidFraction;
   vector<float>   *musegmentCompatibility;
   vector<float>   *muchi2LocalPosition;
   vector<float>   *mutrkKink;
   vector<float>   *muBestTrkPtError;
   vector<float>   *muBestTrkPt;
   vector<int>     *muBestTrkType;
   Int_t           npfPho;
   vector<float>   *pfphoEt;
   vector<float>   *pfphoEta;
   vector<float>   *pfphoPhi;
   Int_t           npfHF;
   vector<float>   *pfHFEn;
   vector<float>   *pfHFECALEn;
   vector<float>   *pfHFHCALEn;
   vector<float>   *pfHFPt;
   vector<float>   *pfHFEta;
   vector<float>   *pfHFPhi;
   vector<float>   *pfHFIso;
   Int_t           nTau;
   vector<bool>    *taupfTausDiscriminationByDecayModeFinding;
   vector<bool>    *taupfTausDiscriminationByDecayModeFindingNewDMs;
   vector<bool>    *tauByMVA6VLooseElectronRejection;
   vector<bool>    *tauByMVA6LooseElectronRejection;
   vector<bool>    *tauByMVA6MediumElectronRejection;
   vector<bool>    *tauByMVA6TightElectronRejection;
   vector<bool>    *tauByMVA6VTightElectronRejection;
   vector<bool>    *tauByLooseMuonRejection3;
   vector<bool>    *tauByTightMuonRejection3;
   vector<bool>    *tauByLooseCombinedIsolationDeltaBetaCorr3Hits;
   vector<bool>    *tauByMediumCombinedIsolationDeltaBetaCorr3Hits;
   vector<bool>    *tauByTightCombinedIsolationDeltaBetaCorr3Hits;
   vector<float>   *tauCombinedIsolationDeltaBetaCorrRaw3Hits;
   vector<float>   *tauByIsolationMVArun2v1DBnewDMwLTraw;
   vector<float>   *tauByIsolationMVArun2v1DBoldDMwLTraw;
   vector<float>   *tauByIsolationMVArun2v1PWnewDMwLTraw;
   vector<float>   *tauByIsolationMVArun2v1PWoldDMwLTraw;
   vector<bool>    *tauByVTightIsolationMVArun2v1DBnewDMwLT;
   vector<bool>    *tauByVTightIsolationMVArun2v1DBoldDMwLT;
   vector<bool>    *tauByVTightIsolationMVArun2v1PWnewDMwLT;
   vector<bool>    *tauByVTightIsolationMVArun2v1PWoldDMwLT;
   vector<bool>    *tauByTightIsolationMVArun2v1DBnewDMwLT;
   vector<bool>    *tauByTightIsolationMVArun2v1DBoldDMwLT;
   vector<bool>    *tauByTightIsolationMVArun2v1PWnewDMwLT;
   vector<bool>    *tauByTightIsolationMVArun2v1PWoldDMwLT;
   vector<bool>    *tauByMediumIsolationMVArun2v1DBnewDMwLT;
   vector<bool>    *tauByMediumIsolationMVArun2v1DBoldDMwLT;
   vector<bool>    *tauByMediumIsolationMVArun2v1PWnewDMwLT;
   vector<bool>    *tauByMediumIsolationMVArun2v1PWoldDMwLT;
   vector<bool>    *tauByLooseIsolationMVArun2v1DBnewDMwLT;
   vector<bool>    *tauByLooseIsolationMVArun2v1DBoldDMwLT;
   vector<bool>    *tauByLooseIsolationMVArun2v1PWnewDMwLT;
   vector<bool>    *tauByLooseIsolationMVArun2v1PWoldDMwLT;
   vector<bool>    *tauByVLooseIsolationMVArun2v1DBnewDMwLT;
   vector<bool>    *tauByVLooseIsolationMVArun2v1DBoldDMwLT;
   vector<bool>    *tauByVLooseIsolationMVArun2v1PWnewDMwLT;
   vector<bool>    *tauByVLooseIsolationMVArun2v1PWoldDMwLT;
   vector<float>   *tauEta;
   vector<float>   *tauPhi;
   vector<float>   *tauPt;
   vector<float>   *tauEt;
   vector<float>   *tauCharge;
   vector<float>   *tauP;
   vector<float>   *tauPx;
   vector<float>   *tauPy;
   vector<float>   *tauPz;
   vector<float>   *tauVz;
   vector<float>   *tauEnergy;
   vector<float>   *tauMass;
   vector<float>   *tauDxy;
   vector<float>   *tauZImpact;
   vector<int>     *tauDecayMode;
   vector<bool>    *tauLeadChargedHadronExists;
   vector<float>   *tauLeadChargedHadronEta;
   vector<float>   *tauLeadChargedHadronPhi;
   vector<float>   *tauLeadChargedHadronPt;
   vector<float>   *tauChargedIsoPtSum;
   vector<float>   *tauNeutralIsoPtSum;
   vector<float>   *tauPuCorrPtSum;
   vector<int>     *tauNumSignalPFChargedHadrCands;
   vector<int>     *tauNumSignalPFNeutrHadrCands;
   vector<int>     *tauNumSignalPFGammaCands;
   vector<int>     *tauNumSignalPFCands;
   vector<int>     *tauNumIsolationPFChargedHadrCands;
   vector<int>     *tauNumIsolationPFNeutrHadrCands;
   vector<int>     *tauNumIsolationPFGammaCands;
   vector<int>     *tauNumIsolationPFCands;
   vector<float>   *taufootprintCorrection;
   vector<float>   *tauphotonPtSumOutsideSignalCone;
   vector<float>   *taudz;
   vector<float>   *taudxy;
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
   vector<float>   *jetCSV2BJetTags;
   vector<float>   *jetJetProbabilityBJetTags;
   vector<float>   *jetpfCombinedMVAV2BJetTags;
   vector<float>   *jetDeepCSVTags_b;
   vector<float>   *jetDeepCSVTags_bb;
   vector<float>   *jetDeepCSVTags_c;
   vector<float>   *jetDeepCSVTags_cc;
   vector<float>   *jetDeepCSVTags_udsg;
   vector<int>     *jetPartonID;
   vector<int>     *jetHadFlvr;
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
   vector<float>   *jetP4Smear;
   vector<float>   *jetP4SmearUp;
   vector<float>   *jetP4SmearDo;
   vector<bool>    *jetPFLooseId;
   vector<int>     *jetID;
   vector<float>   *jetPUID;
   vector<int>     *jetPUFullID;
   vector<float>   *jetJECUnc;
   vector<ULong64_t> *jetFiredTrgs;
   vector<float>   *jetCHF;
   vector<float>   *jetNHF;
   vector<float>   *jetCEF;
   vector<float>   *jetNEF;
   vector<int>     *jetNCH;
   vector<int>     *jetNNP;
   vector<float>   *jetMUF;
   vector<float>   *jetVtxPt;
   vector<float>   *jetVtxMass;
   vector<float>   *jetVtxNtrks;
   vector<float>   *jetVtx3DVal;
   vector<float>   *jetVtx3DSig;
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
   vector<int>     *AK8JetNNP;
   vector<float>   *AK8JetMUF;
   vector<int>     *AK8Jetnconstituents;
   vector<bool>    *AK8JetPFLooseId;
   vector<bool>    *AK8JetPFTightLepVetoId;
   vector<float>   *AK8JetSoftDropMass;
   vector<float>   *AK8JetSoftDropMassCorr;
   vector<float>   *AK8JetPrunedMass;
   vector<float>   *AK8JetPrunedMassCorr;
   vector<float>   *AK8JetpfBoostedDSVBTag;
   vector<float>   *AK8JetDSVnewV4;
   vector<float>   *AK8JetCSV;
   vector<float>   *AK8JetJECUnc;
   vector<float>   *AK8JetL2L3corr;
   vector<float>   *AK8puppiPt;
   vector<float>   *AK8puppiMass;
   vector<float>   *AK8puppiEta;
   vector<float>   *AK8puppiPhi;
   vector<float>   *AK8puppiTau1;
   vector<float>   *AK8puppiTau2;
   vector<float>   *AK8puppiTau3;
   vector<float>   *AK8puppiSDL2L3corr;
   vector<float>   *AK8puppiSDMass;
   vector<float>   *AK8puppiSDMassL2L3Corr;
   vector<int>     *AK8JetPartonID;
   vector<int>     *AK8JetHadFlvr;
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
   vector<float>   *AK8JetP4Smear;
   vector<float>   *AK8JetP4SmearUp;
   vector<float>   *AK8JetP4SmearDo;
   vector<int>     *nAK8SDSJ;
   vector<vector<float> > *AK8SDSJPt;
   vector<vector<float> > *AK8SDSJEta;
   vector<vector<float> > *AK8SDSJPhi;
   vector<vector<float> > *AK8SDSJMass;
   vector<vector<float> > *AK8SDSJE;
   vector<vector<int> > *AK8SDSJCharge;
   vector<vector<int> > *AK8SDSJFlavour;
   vector<vector<float> > *AK8SDSJCSV;
   vector<int>     *nAK8puppiSDSJ;
   vector<vector<float> > *AK8puppiSDSJPt;
   vector<vector<float> > *AK8puppiSDSJEta;
   vector<vector<float> > *AK8puppiSDSJPhi;
   vector<vector<float> > *AK8puppiSDSJMass;
   vector<vector<float> > *AK8puppiSDSJE;
   vector<vector<int> > *AK8puppiSDSJCharge;
   vector<vector<int> > *AK8puppiSDSJFlavour;
   vector<vector<float> > *AK8puppiSDSJCSV;
   Int_t           nIsoTrack;
   vector<float>   *isoPt;
   vector<float>   *isoEta;
   vector<float>   *isoPhi;
   vector<float>   *isoD0;
   vector<float>   *isoDz;
   vector<float>   *isoCharge;
   vector<int>     *isoFromPV;
   vector<int>     *isoPdgID;
   vector<bool>    *isoLeptonOverlap;
   vector<float>   *isoChIso;
   vector<float>   *isoChRelIso;
   vector<float>   *isoChMiniIso;
   vector<float>   *isoChRelMiniIso;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumis;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_nGoodVtx;   //!
   TBranch        *b_nTrksPV;   //!
   TBranch        *b_isPVGood;   //!
   TBranch        *b_vtx;   //!
   TBranch        *b_vty;   //!
   TBranch        *b_vtz;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_rhoCentral;   //!
   TBranch        *b_HLTEleMuX;   //!
   TBranch        *b_HLTPho;   //!
   TBranch        *b_HLTPhoRejectedByPS;   //!
   TBranch        *b_HLTJet;   //!
   TBranch        *b_HLTEleMuXIsPrescaled;   //!
   TBranch        *b_HLTPhoIsPrescaled;   //!
   TBranch        *b_HLTJetIsPrescaled;   //!
   TBranch        *b_pdf;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_processID;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_genHT;   //!
   TBranch        *b_genPho1;   //!
   TBranch        *b_genPho2;   //!
   TBranch        *b_EventTag;   //!
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
   TBranch        *b_pfMET_T1UESUp;   //!
   TBranch        *b_pfMET_T1UESDo;   //!
   TBranch        *b_pfMETPhi_T1JESUp;   //!
   TBranch        *b_pfMETPhi_T1JESDo;   //!
   TBranch        *b_pfMETPhi_T1UESUp;   //!
   TBranch        *b_pfMETPhi_T1UESDo;   //!
   TBranch        *b_nPho;   //!
   TBranch        *b_phoE;   //!
   TBranch        *b_phoEt;   //!
   TBranch        *b_phoEta;   //!
   TBranch        *b_phoPhi;   //!
   TBranch        *b_phoCalibE;   //!
   TBranch        *b_phoCalibEt;   //!
   TBranch        *b_phoSCE;   //!
   TBranch        *b_phoSCRawE;   //!
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
   TBranch        *b_phoE1x3;   //!
   TBranch        *b_phoE1x5;   //!
   TBranch        *b_phoE2x2;   //!
   TBranch        *b_phoE2x5Max;   //!
   TBranch        *b_phoE5x5;   //!
   TBranch        *b_phoESEffSigmaRR;   //!
   TBranch        *b_phoSigmaIEtaIEtaFull5x5;   //!
   TBranch        *b_phoSigmaIEtaIPhiFull5x5;   //!
   TBranch        *b_phoSigmaIPhiIPhiFull5x5;   //!
   TBranch        *b_phoE1x3Full5x5;   //!
   TBranch        *b_phoE1x5Full5x5;   //!
   TBranch        *b_phoE2x2Full5x5;   //!
   TBranch        *b_phoE2x5MaxFull5x5;   //!
   TBranch        *b_phoE5x5Full5x5;   //!
   TBranch        *b_phoR9Full5x5;   //!
   TBranch        *b_phoPFChIso;   //!
   TBranch        *b_phoPFPhoIso;   //!
   TBranch        *b_phoPFNeuIso;   //!
   TBranch        *b_phoPFChWorstIso;   //!
   TBranch        *b_phoPFRandConeChIso;   //!
   TBranch        *b_phoCITKChIso;   //!
   TBranch        *b_phoCITKPhoIso;   //!
   TBranch        *b_phoCITKNeuIso;   //!
   TBranch        *b_phoIDMVA;   //!
   TBranch        *b_phoFiredSingleTrgs;   //!
   TBranch        *b_phoFiredDoubleTrgs;   //!
   TBranch        *b_phoFiredL1Trgs;   //!
   TBranch        *b_phoSeedTime;   //!
   TBranch        *b_phoSeedEnergy;   //!
   TBranch        *b_phoxtalBits;   //!
   TBranch        *b_phoIDbit;   //!
   TBranch        *b_phoScale_stat_up;   //!
   TBranch        *b_phoScale_stat_dn;   //!
   TBranch        *b_phoScale_syst_up;   //!
   TBranch        *b_phoScale_syst_dn;   //!
   TBranch        *b_phoScale_gain_up;   //!
   TBranch        *b_phoScale_gain_dn;   //!
   TBranch        *b_phoResol_rho_up;   //!
   TBranch        *b_phoResol_rho_dn;   //!
   TBranch        *b_phoResol_phi_up;   //!
   TBranch        *b_phoResol_phi_dn;   //!
   TBranch        *b_nEle;   //!
   TBranch        *b_eleCharge;   //!
   TBranch        *b_eleChargeConsistent;   //!
   TBranch        *b_eleEn;   //!
   TBranch        *b_eleSCEn;   //!
   TBranch        *b_eleEcalEn;   //!
   TBranch        *b_eleESEnP1;   //!
   TBranch        *b_eleESEnP2;   //!
   TBranch        *b_eleD0;   //!
   TBranch        *b_eleDz;   //!
   TBranch        *b_eleSIP;   //!
   TBranch        *b_elePt;   //!
   TBranch        *b_eleEta;   //!
   TBranch        *b_elePhi;   //!
   TBranch        *b_eleR9;   //!
   TBranch        *b_eleCalibPt;   //!
   TBranch        *b_eleCalibEn;   //!
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
   TBranch        *b_eleSigmaIEtaIEtaFull5x5;   //!
   TBranch        *b_eleSigmaIPhiIPhiFull5x5;   //!
   TBranch        *b_eleConvVeto;   //!
   TBranch        *b_eleMissHits;   //!
   TBranch        *b_eleESEffSigmaRR;   //!
   TBranch        *b_elePFChIso;   //!
   TBranch        *b_elePFPhoIso;   //!
   TBranch        *b_elePFNeuIso;   //!
   TBranch        *b_elePFPUIso;   //!
   TBranch        *b_elePFClusEcalIso;   //!
   TBranch        *b_elePFClusHcalIso;   //!
   TBranch        *b_elePFMiniIso;   //!
   TBranch        *b_eleIDMVA;   //!
   TBranch        *b_eleIDMVAHZZ;   //!
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
   TBranch        *b_eleGSFChi2;   //!
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
   TBranch        *b_eleFiredSingleTrgs;   //!
   TBranch        *b_eleFiredDoubleTrgs;   //!
   TBranch        *b_eleFiredL1Trgs;   //!
   TBranch        *b_eleIDbit;   //!
   TBranch        *b_eleScale_stat_up;   //!
   TBranch        *b_eleScale_stat_dn;   //!
   TBranch        *b_eleScale_syst_up;   //!
   TBranch        *b_eleScale_syst_dn;   //!
   TBranch        *b_eleScale_gain_up;   //!
   TBranch        *b_eleScale_gain_dn;   //!
   TBranch        *b_eleResol_rho_up;   //!
   TBranch        *b_eleResol_rho_dn;   //!
   TBranch        *b_eleResol_phi_up;   //!
   TBranch        *b_eleResol_phi_dn;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_muPt;   //!
   TBranch        *b_muEn;   //!
   TBranch        *b_muEta;   //!
   TBranch        *b_muPhi;   //!
   TBranch        *b_muCharge;   //!
   TBranch        *b_muType;   //!
   TBranch        *b_muIDbit;   //!
   TBranch        *b_muD0;   //!
   TBranch        *b_muDz;   //!
   TBranch        *b_muSIP;   //!
   TBranch        *b_muChi2NDF;   //!
   TBranch        *b_muInnerD0;   //!
   TBranch        *b_muInnerDz;   //!
   TBranch        *b_muTrkLayers;   //!
   TBranch        *b_muPixelLayers;   //!
   TBranch        *b_muPixelHits;   //!
   TBranch        *b_muMuonHits;   //!
   TBranch        *b_muStations;   //!
   TBranch        *b_muMatches;   //!
   TBranch        *b_muTrkQuality;   //!
   TBranch        *b_muIsoTrk;   //!
   TBranch        *b_muPFChIso;   //!
   TBranch        *b_muPFPhoIso;   //!
   TBranch        *b_muPFNeuIso;   //!
   TBranch        *b_muPFPUIso;   //!
   TBranch        *b_muPFChIso03;   //!
   TBranch        *b_muPFPhoIso03;   //!
   TBranch        *b_muPFNeuIso03;   //!
   TBranch        *b_muPFPUIso03;   //!
   TBranch        *b_muPFMiniIso;   //!
   TBranch        *b_muFiredTrgs;   //!
   TBranch        *b_muFiredL1Trgs;   //!
   TBranch        *b_muInnervalidFraction;   //!
   TBranch        *b_musegmentCompatibility;   //!
   TBranch        *b_muchi2LocalPosition;   //!
   TBranch        *b_mutrkKink;   //!
   TBranch        *b_muBestTrkPtError;   //!
   TBranch        *b_muBestTrkPt;   //!
   TBranch        *b_muBestTrkType;   //!
   TBranch        *b_npfPho;   //!
   TBranch        *b_pfphoEt;   //!
   TBranch        *b_pfphoEta;   //!
   TBranch        *b_pfphoPhi;   //!
   TBranch        *b_npfHF;   //!
   TBranch        *b_pfHFEn;   //!
   TBranch        *b_pfHFECALEn;   //!
   TBranch        *b_pfHFHCALEn;   //!
   TBranch        *b_pfHFPt;   //!
   TBranch        *b_pfHFEta;   //!
   TBranch        *b_pfHFPhi;   //!
   TBranch        *b_pfHFIso;   //!
   TBranch        *b_nTau;   //!
   TBranch        *b_taupfTausDiscriminationByDecayModeFinding;   //!
   TBranch        *b_taupfTausDiscriminationByDecayModeFindingNewDMs;   //!
   TBranch        *b_tauByMVA6VLooseElectronRejection;   //!
   TBranch        *b_tauByMVA6LooseElectronRejection;   //!
   TBranch        *b_tauByMVA6MediumElectronRejection;   //!
   TBranch        *b_tauByMVA6TightElectronRejection;   //!
   TBranch        *b_tauByMVA6VTightElectronRejection;   //!
   TBranch        *b_tauByLooseMuonRejection3;   //!
   TBranch        *b_tauByTightMuonRejection3;   //!
   TBranch        *b_tauByLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tauByMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tauByTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tauCombinedIsolationDeltaBetaCorrRaw3Hits;   //!
   TBranch        *b_tauByIsolationMVArun2v1DBnewDMwLTraw;   //!
   TBranch        *b_tauByIsolationMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_tauByIsolationMVArun2v1PWnewDMwLTraw;   //!
   TBranch        *b_tauByIsolationMVArun2v1PWoldDMwLTraw;   //!
   TBranch        *b_tauByVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tauByVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tauByVTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tauByVTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tauByTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tauByTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tauByTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tauByTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tauByMediumIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tauByMediumIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tauByMediumIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tauByMediumIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tauByLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tauByLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tauByLooseIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tauByLooseIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tauByVLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tauByVLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tauByVLooseIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tauByVLooseIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tauEta;   //!
   TBranch        *b_tauPhi;   //!
   TBranch        *b_tauPt;   //!
   TBranch        *b_tauEt;   //!
   TBranch        *b_tauCharge;   //!
   TBranch        *b_tauP;   //!
   TBranch        *b_tauPx;   //!
   TBranch        *b_tauPy;   //!
   TBranch        *b_tauPz;   //!
   TBranch        *b_tauVz;   //!
   TBranch        *b_tauEnergy;   //!
   TBranch        *b_tauMass;   //!
   TBranch        *b_tauDxy;   //!
   TBranch        *b_tauZImpact;   //!
   TBranch        *b_tauDecayMode;   //!
   TBranch        *b_tauLeadChargedHadronExists;   //!
   TBranch        *b_tauLeadChargedHadronEta;   //!
   TBranch        *b_tauLeadChargedHadronPhi;   //!
   TBranch        *b_tauLeadChargedHadronPt;   //!
   TBranch        *b_tauChargedIsoPtSum;   //!
   TBranch        *b_tauNeutralIsoPtSum;   //!
   TBranch        *b_tauPuCorrPtSum;   //!
   TBranch        *b_tauNumSignalPFChargedHadrCands;   //!
   TBranch        *b_tauNumSignalPFNeutrHadrCands;   //!
   TBranch        *b_tauNumSignalPFGammaCands;   //!
   TBranch        *b_tauNumSignalPFCands;   //!
   TBranch        *b_tauNumIsolationPFChargedHadrCands;   //!
   TBranch        *b_tauNumIsolationPFNeutrHadrCands;   //!
   TBranch        *b_tauNumIsolationPFGammaCands;   //!
   TBranch        *b_tauNumIsolationPFCands;   //!
   TBranch        *b_taufootprintCorrection;   //!
   TBranch        *b_tauphotonPtSumOutsideSignalCone;   //!
   TBranch        *b_taudz;   //!
   TBranch        *b_taudxy;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_jetPt;   //!
   TBranch        *b_jetEn;   //!
   TBranch        *b_jetEta;   //!
   TBranch        *b_jetPhi;   //!
   TBranch        *b_jetRawPt;   //!
   TBranch        *b_jetRawEn;   //!
   TBranch        *b_jetMt;   //!
   TBranch        *b_jetArea;   //!
   TBranch        *b_jetLeadTrackPt;   //!
   TBranch        *b_jetLeadTrackEta;   //!
   TBranch        *b_jetLeadTrackPhi;   //!
   TBranch        *b_jetLepTrackPID;   //!
   TBranch        *b_jetLepTrackPt;   //!
   TBranch        *b_jetLepTrackEta;   //!
   TBranch        *b_jetLepTrackPhi;   //!
   TBranch        *b_jetCSV2BJetTags;   //!
   TBranch        *b_jetJetProbabilityBJetTags;   //!
   TBranch        *b_jetpfCombinedMVAV2BJetTags;   //!
   TBranch        *b_jetDeepCSVTags_b;   //!
   TBranch        *b_jetDeepCSVTags_bb;   //!
   TBranch        *b_jetDeepCSVTags_c;   //!
   TBranch        *b_jetDeepCSVTags_cc;   //!
   TBranch        *b_jetDeepCSVTags_udsg;   //!
   TBranch        *b_jetPartonID;   //!
   TBranch        *b_jetHadFlvr;   //!
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
   TBranch        *b_jetP4Smear;   //!
   TBranch        *b_jetP4SmearUp;   //!
   TBranch        *b_jetP4SmearDo;   //!
   TBranch        *b_jetPFLooseId;   //!
   TBranch        *b_jetID;   //!
   TBranch        *b_jetPUID;   //!
   TBranch        *b_jetPUFullID;   //!
   TBranch        *b_jetJECUnc;   //!
   TBranch        *b_jetFiredTrgs;   //!
   TBranch        *b_jetCHF;   //!
   TBranch        *b_jetNHF;   //!
   TBranch        *b_jetCEF;   //!
   TBranch        *b_jetNEF;   //!
   TBranch        *b_jetNCH;   //!
   TBranch        *b_jetNNP;   //!
   TBranch        *b_jetMUF;   //!
   TBranch        *b_jetVtxPt;   //!
   TBranch        *b_jetVtxMass;   //!
   TBranch        *b_jetVtxNtrks;   //!
   TBranch        *b_jetVtx3DVal;   //!
   TBranch        *b_jetVtx3DSig;   //!
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
   TBranch        *b_AK8JetNNP;   //!
   TBranch        *b_AK8JetMUF;   //!
   TBranch        *b_AK8Jetnconstituents;   //!
   TBranch        *b_AK8JetPFLooseId;   //!
   TBranch        *b_AK8JetPFTightLepVetoId;   //!
   TBranch        *b_AK8JetSoftDropMass;   //!
   TBranch        *b_AK8JetSoftDropMassCorr;   //!
   TBranch        *b_AK8JetPrunedMass;   //!
   TBranch        *b_AK8JetPrunedMassCorr;   //!
   TBranch        *b_AK8JetpfBoostedDSVBTag;   //!
   TBranch        *b_AK8JetDSVnewV4;   //!
   TBranch        *b_AK8JetCSV;   //!
   TBranch        *b_AK8JetJECUnc;   //!
   TBranch        *b_AK8JetL2L3corr;   //!
   TBranch        *b_AK8puppiPt;   //!
   TBranch        *b_AK8puppiMass;   //!
   TBranch        *b_AK8puppiEta;   //!
   TBranch        *b_AK8puppiPhi;   //!
   TBranch        *b_AK8puppiTau1;   //!
   TBranch        *b_AK8puppiTau2;   //!
   TBranch        *b_AK8puppiTau3;   //!
   TBranch        *b_AK8puppiSDL2L3corr;   //!
   TBranch        *b_AK8puppiSDMass;   //!
   TBranch        *b_AK8puppiSDMassL2L3Corr;   //!
   TBranch        *b_AK8JetPartonID;   //!
   TBranch        *b_AK8JetHadFlvr;   //!
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
   TBranch        *b_AK8JetP4Smear;   //!
   TBranch        *b_AK8JetP4SmearUp;   //!
   TBranch        *b_AK8JetP4SmearDo;   //!
   TBranch        *b_nAK8SDSJ;   //!
   TBranch        *b_AK8SDSJPt;   //!
   TBranch        *b_AK8SDSJEta;   //!
   TBranch        *b_AK8SDSJPhi;   //!
   TBranch        *b_AK8SDSJMass;   //!
   TBranch        *b_AK8SDSJE;   //!
   TBranch        *b_AK8SDSJCharge;   //!
   TBranch        *b_AK8SDSJFlavour;   //!
   TBranch        *b_AK8SDSJCSV;   //!
   TBranch        *b_nAK8puppiSDSJ;   //!
   TBranch        *b_AK8puppiSDSJPt;   //!
   TBranch        *b_AK8puppiSDSJEta;   //!
   TBranch        *b_AK8puppiSDSJPhi;   //!
   TBranch        *b_AK8puppiSDSJMass;   //!
   TBranch        *b_AK8puppiSDSJE;   //!
   TBranch        *b_AK8puppiSDSJCharge;   //!
   TBranch        *b_AK8puppiSDSJFlavour;   //!
   TBranch        *b_AK8puppiSDSJCSV;   //!
   TBranch        *b_nIsoTrack;   //!
   TBranch        *b_isoPt;   //!
   TBranch        *b_isoEta;   //!
   TBranch        *b_isoPhi;   //!
   TBranch        *b_isoD0;   //!
   TBranch        *b_isoDz;   //!
   TBranch        *b_isoCharge;   //!
   TBranch        *b_isoFromPV;   //!
   TBranch        *b_isoPdgID;   //!
   TBranch        *b_isoLeptonOverlap;   //!
   TBranch        *b_isoChIso;   //!
   TBranch        *b_isoChRelIso;   //!
   TBranch        *b_isoChMiniIso;   //!
   TBranch        *b_isoChRelMiniIso;   //!

   //Added
   double BtagCSVWP[3]={0.5426,0.8484,0.9535};
   double BtagcMVAWP[3]={-0.5884,0.4432,0.9432};
   double BtagBDSVWP[4]={0.3,0.6,0.8,0.9};
   double BtagDeepWP[3]={0.2219,0.6324,0.8958};
   std::string output_file="default", btag_file="", pu_file="default";
   unsigned int nFiles=0;
   bool _fastSim=false;
   int _fakeRate=0;
   int _testRun=0;
   bool is_quiet=false;
   bool signalstudy=false;
   bool SignalScan=false;
   bool CountSignal=false;
   vector<string> _cut_variable, _cut_operator;
   vector<double> _cut_value;
   //For cuts
   int nPassPhoL=-1, nPassPhoM=-1, nPassPhoT=-1, nPassAK4=-1, nPassAK8=-1, nonHiggsJet=-1;
   int nPassEleV=-1, nPassEleL=-1, nPassEleM=-1, nPassEleT=-1, nPassEleNO=-1;
   int nPassFREleL=0, nPassFREleM=0, nPassFREleT=0;
   int nPassElePhoL=0, nPassElePhoM=0, nPassElePhoT=0;
   int nPassMuL=-1, nPassMuM=-1, nPassMuT=-1, nPassMuNO=-1;
   int nPassTauL=-1, nPassTauM=-1, nPassTauT=-1, nPassIso=-1;
   int nPassLepL=-1, nPassLepM=-1, nPassLepT=-1;
   int nleadElePhoL=-1, nleadElePhoM=-1, nleadElePhoT=-1;
   int nleadFREleL=-1, nleadFREleM=-1, nleadFREleT=-1;
   int nleadPhoL=-1, nleadPhoM=-1, nleadPhoT=-1;
   int nleadEleL=-1, nleadEleM=-1, nleadEleT=-1, nleadEleNO=-1;
   int nleadMuL=-1, nleadMuM=-1, nleadMuT=-1, nleadMuNO=-1;
   int nleadTauL=-1, nleadTauM=-1, nleadTauT=-1, nleadIso=-1;
   int bcounterCSV[4]={}, bcountercMVA[4]={}, bcounterBDSV[5]={}, bcounterDeep[4]={};
   int BDSV_selected=0, CSV_selected=0, Deep_selected=0;
   bool L1prefire=false;
   bool passBtag=false, passHiggsMass=false;
   bool passAK4Btag1=false, passAK4Btag2=false, passAK4HiggsMass=false;
   bool notAK4=true;
   bool Hbb=false, mcLeptonFilter=false;
   int SignalHiggs=0;
   double HT_before=0, EMHT_before=0, HT_after=0, EMHT_after=0;
   double AK8HT_before=0, AK8EMHT_before=0, AK8HT_after=0, AK8EMHT_after=0;
   double CSV_SF_L[3]={1,1,1}, CSV_SF_M[3]={1,1,1}, CSV_SF_T[3]={1,1,1};
   double BDSV_SF_L[3]={1,1,1}, BDSV_SF_M1[3]={1,1,1}, BDSV_SF_M2[3]={1,1,1}, BDSV_SF_T[3]={1,1,1};
   double Deep_SF_L[3]={1,1,1}, Deep_SF_M[3]={1,1,1}, Deep_SF_T[3]={1,1,1};
   double pho_SF[3]={1,1,1}, ele_SF[4]={1,1,1,1}, mu_SF[3]={1,1,1}, tau_SF[3]={0.99,0.97,0.95};//tau: 5% unceartainty
   double ele_VETOSF=1, mu_VETOSF=1;
   int BDSV_whichSF=0, CSV_whichSF=0, Deep_whichSF=0;
   int AK4Smear_whichSF=0, AK8Smear_whichSF=0;
   int phoID_whichSF=0, phoPix_whichSF=0, eleID_whichSF=0, eleRec_whichSF=0, muID_whichSF=0, muISO_whichSF=0, tau_whichSF=0;
   int metJER_whichSF=0, metJES_whichSF=0, metUES_whichSF=0, AK4jetJEC_whichSF=0, AK8jetJEC_whichSF=0; 
   int L1prefire_whichSF=0;
   double ST=0, ST_G=0, MT=0;
   double dphi_met_jet=999;
   double e_pt=10, mu_pt=10, tau_pt=20;
   double w=0, xsec=1;
   //histograms
   TH1D *h_cuts;
   TH1D *h_PUweight;
   //histograms needed for SFs
   TH2F *h_pho_EGamma_SF2D[3];
   TH2F *h_ele_EGamma_SF2D[4];
   TH2F *h_ele_EGamma_EffMC2D[4];
   TH2F *h_eleRec_EGamma_SF2D;
   TH2D *h_Scaling_Factors_HasPix_R9_high;
   TH2D *h_Scaling_Factors_HasPix_R9_low;
   TH2D *h_muID_SF2D[3];
   TH2D *h_muID_EffMC2D[3];
   TH2D *h_muISO_SF2D[3];
   TH2D *h_L1prefire_phoMap;
   TH2D *h_L1prefire_jetMap;
   TGraph *h_muTrk_SF;
   TEfficiency* eff_b_CSV_L;
   TEfficiency* eff_b_CSV_M;
   TEfficiency* eff_b_CSV_T;
   TEfficiency* eff_c_CSV_L;
   TEfficiency* eff_c_CSV_M;
   TEfficiency* eff_c_CSV_T;
   TEfficiency* eff_l_CSV_L;
   TEfficiency* eff_l_CSV_M;
   TEfficiency* eff_l_CSV_T;
   TEfficiency* eff_b_Deep_L;
   TEfficiency* eff_b_Deep_M;
   TEfficiency* eff_b_Deep_T;
   TEfficiency* eff_c_Deep_L;
   TEfficiency* eff_c_Deep_M;
   TEfficiency* eff_c_Deep_T;
   TEfficiency* eff_l_Deep_L;
   TEfficiency* eff_l_Deep_M;
   TEfficiency* eff_l_Deep_T;
   TEfficiency* eff_b_BDSV_L;
   TEfficiency* eff_b_BDSV_M1;
   TEfficiency* eff_b_BDSV_M2;
   TEfficiency* eff_b_BDSV_T;
   //histogram for Fake Rate
   TH2D *h2_FR;
   //hardcoded values for FR
   double _A=0.0308, _B=0.4942, _C=0.615192;

   Analyzer(vector<string> arg={"default"}, string outname={"default"}, string btag_fname={""}, string pu_fname={""}, bool fastSim=false, int fakeRate=0, vector<string> cut_variable={}, vector<string> cut_operator={}, vector<double> cut_value={}, bool is_q=0, bool is_signalscan=0, bool is_signalstudy=0, bool is_countSignal=0, int testrun=0, map<string,int> systematics={}, map<string,double> leptonpts={});
   virtual ~Analyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   void             Systematics(map<string, int> systematics);
   double           deltaR(double phi1, double phi2, double eta1, double eta2);
   void             CalcBtagSF(vector<float> *v_eta, vector<float> v_pt, vector<int> *v_had, map<int,char> passCut, TEfficiency *eff_b_L, TEfficiency *eff_c_L, TEfficiency *eff_l_L, TEfficiency *eff_b_M, TEfficiency *eff_c_M, TEfficiency *eff_l_M, TEfficiency *eff_b_T, TEfficiency *eff_c_T, TEfficiency *eff_l_T, BTCalibrationReader reader_L, BTCalibrationReader reader_M, BTCalibrationReader reader_T, double (&SF_L)[3], double (&SF_M)[3], double (&SF_T)[3]);
   void             CalcBtagSF_AK8(vector<float> *v_eta, vector<float> v_pt, vector<int> *v_had, map<int,char> passCut, TEfficiency *eff_b_L, TEfficiency *eff_b_M1, TEfficiency *eff_b_M2, TEfficiency *eff_b_T, double (&SF_L)[3], double (&SF_M1)[3], double (&SF_M2)[3], double (&SF_T)[3]);
   void             Sort(vector<pair<int,int>> &v, vector<float> *b, vector<float> *bb, unsigned int operation);
   void             SelectAK4(vector<pair<int,int>> v, vector<float> *eta, vector<float> *phi, vector<float> *b, vector<float> *bb, vector<float> en, vector<float> pt, vector<int> ak4_hjets, vector<bool> &ak4selected, vector<int> &ak4trueselected);
   void             FillAK4tagging(vector<bool> ak4selected, vector<int> ak4trueselected, bool (&MassBtagAK4)[6], int (&true_higgsak4jet)[7]);

};

#endif

#ifdef Analyzer_cxx
Analyzer::Analyzer(vector<string> arg, string outname, string btag_fname, string pu_fname, bool fastSim, int fakeRate, vector<string> cut_variable, vector<string> cut_operator, vector<double> cut_value, bool is_q, bool is_signalscan, bool is_signalstudy, bool is_countSignal, int testrun, map<string,int> systematics, map<string,double> leptonpts) : fChain(0) 
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.

  _cut_variable=cut_variable;
  _cut_operator=cut_operator;
  _cut_value=cut_value;
  Systematics(systematics);
  //Determine lepton pt cuts
  
  for (auto const& x : leptonpts) {
    if (x.first=="e") e_pt=x.second;
    else if (x.first=="m") mu_pt=x.second;
    else if (x.first=="t") tau_pt=x.second;
    else cout<<"Unkown lepton type \""<<x.first<<"\""<<endl;
  }

  is_quiet=is_q;
  signalstudy=is_signalstudy;
  SignalScan=is_signalscan;
  CountSignal=is_countSignal;
  TTree *tree;
  TChain * ch = new TChain("EventTree","");
  btag_file=btag_fname;
  if (pu_fname!="") pu_file=pu_fname;
  if (fastSim) _fastSim=true;
  if (fakeRate) _fakeRate=fakeRate;
  if (testrun) _testRun=testrun;
  if (outname=="" && !is_quiet) std::cout<<"No output filename is defined, using: Analyzer_histos.root"<<std::endl;
  if (outname!="") output_file=outname;
  if (arg.size()==0) {
    const char* fdefault = "/data/ggntuples/skimmed_ntuples/Data/V08_00_26_07/Run2016C_Pho165_HE10_CopyTree_skimmed.root/EventTree";
    if (!is_quiet) std::cout<<"No input files are defined, using: "<<fdefault<<std::endl;
    ch->Add(fdefault);
    tree = ch;
  }
  else {
    for (auto i : arg) {
      const char* cstr_i=i.c_str();
      std::string temp=i;
      if (temp.find("*") != std::string::npos) {
        if (!is_quiet){
          std::cout<<"Wildcard found in input argument, assuming ntuple structure: /ggNtuplizer/EventTree"<<std::endl;
        }
        temp+="/ggNtuplizer/EventTree";
        ch->Add(temp.c_str());
        continue;
      }
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(cstr_i);
      if (!f || !f->IsOpen()) {
        f = new TFile(cstr_i);
      }
      if (f->GetDirectory("ggNtuplizer") !=0) temp+="/ggNtuplizer/EventTree";
      else temp+="/EventTree";
      ch->Add(temp.c_str());
      f->Close();
    }
    nFiles=ch->GetNtrees();
    if (!is_quiet){
      std::cout<<nFiles<<" trees are read."<<std::endl; 
    }
    tree = ch;
  }
  Init(tree);
}

Analyzer::~Analyzer()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t Analyzer::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t Analyzer::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void Analyzer::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set object pointer
  pdf = 0;
  EventTag = 0;
  nPU = 0;
  puBX = 0;
  puTrue = 0;
  mcPID = 0;
  mcVtx = 0;
  mcVty = 0;
  mcVtz = 0;
  mcPt = 0;
  mcMass = 0;
  mcEta = 0;
  mcPhi = 0;
  mcE = 0;
  mcEt = 0;
  mcGMomPID = 0;
  mcMomPID = 0;
  mcMomPt = 0;
  mcMomMass = 0;
  mcMomEta = 0;
  mcMomPhi = 0;
  mcStatusFlag = 0;
  mcParentage = 0;
  mcStatus = 0;
  mcCalIsoDR03 = 0;
  mcTrkIsoDR03 = 0;
  mcCalIsoDR04 = 0;
  mcTrkIsoDR04 = 0;
  phoE = 0;
  phoEt = 0;
  phoEta = 0;
  phoPhi = 0;
  phoCalibE = 0;
  phoCalibEt = 0;
  phoSCE = 0;
  phoSCRawE = 0;
  phoESEnP1 = 0;
  phoESEnP2 = 0;
  phoSCEta = 0;
  phoSCPhi = 0;
  phoSCEtaWidth = 0;
  phoSCPhiWidth = 0;
  phoSCBrem = 0;
  phohasPixelSeed = 0;
  phoEleVeto = 0;
  phoR9 = 0;
  phoHoverE = 0;
  phoE1x3 = 0;
  phoE1x5 = 0;
  phoE2x2 = 0;
  phoE2x5Max = 0;
  phoE5x5 = 0;
  phoESEffSigmaRR = 0;
  phoSigmaIEtaIEtaFull5x5 = 0;
  phoSigmaIEtaIPhiFull5x5 = 0;
  phoSigmaIPhiIPhiFull5x5 = 0;
  phoE1x3Full5x5 = 0;
  phoE1x5Full5x5 = 0;
  phoE2x2Full5x5 = 0;
  phoE2x5MaxFull5x5 = 0;
  phoE5x5Full5x5 = 0;
  phoR9Full5x5 = 0;
  phoPFChIso = 0;
  phoPFPhoIso = 0;
  phoPFNeuIso = 0;
  phoPFChWorstIso = 0;
  phoPFRandConeChIso = 0;
  phoCITKChIso = 0;
  phoCITKPhoIso = 0;
  phoCITKNeuIso = 0;
  phoIDMVA = 0;
  phoFiredSingleTrgs = 0;
  phoFiredDoubleTrgs = 0;
  phoFiredL1Trgs = 0;
  phoSeedTime = 0;
  phoSeedEnergy = 0;
  phoxtalBits = 0;
  phoIDbit = 0;
  phoScale_stat_up = 0;
  phoScale_stat_dn = 0;
  phoScale_syst_up = 0;
  phoScale_syst_dn = 0;
  phoScale_gain_up = 0;
  phoScale_gain_dn = 0;
  phoResol_rho_up = 0;
  phoResol_rho_dn = 0;
  phoResol_phi_up = 0;
  phoResol_phi_dn = 0;
  eleCharge = 0;
  eleChargeConsistent = 0;
  eleEn = 0;
  eleSCEn = 0;
  eleEcalEn = 0;
  eleESEnP1 = 0;
  eleESEnP2 = 0;
  eleD0 = 0;
  eleDz = 0;
  eleSIP = 0;
  elePt = 0;
  eleEta = 0;
  elePhi = 0;
  eleR9 = 0;
  eleCalibPt = 0;
  eleCalibEn = 0;
  eleSCEta = 0;
  eleSCPhi = 0;
  eleSCRawEn = 0;
  eleSCEtaWidth = 0;
  eleSCPhiWidth = 0;
  eleHoverE = 0;
  eleEoverP = 0;
  eleEoverPout = 0;
  eleEoverPInv = 0;
  eleBrem = 0;
  eledEtaAtVtx = 0;
  eledPhiAtVtx = 0;
  eledEtaAtCalo = 0;
  eleSigmaIEtaIEtaFull5x5 = 0;
  eleSigmaIPhiIPhiFull5x5 = 0;
  eleConvVeto = 0;
  eleMissHits = 0;
  eleESEffSigmaRR = 0;
  elePFChIso = 0;
  elePFPhoIso = 0;
  elePFNeuIso = 0;
  elePFPUIso = 0;
  elePFClusEcalIso = 0;
  elePFClusHcalIso = 0;
  elePFMiniIso = 0;
  eleIDMVA = 0;
  eleIDMVAHZZ = 0;
  eledEtaseedAtVtx = 0;
  eleE1x5 = 0;
  eleE2x5 = 0;
  eleE5x5 = 0;
  eleE1x5Full5x5 = 0;
  eleE2x5Full5x5 = 0;
  eleE5x5Full5x5 = 0;
  eleR9Full5x5 = 0;
  eleEcalDrivenSeed = 0;
  eleDr03EcalRecHitSumEt = 0;
  eleDr03HcalDepth1TowerSumEt = 0;
  eleDr03HcalDepth2TowerSumEt = 0;
  eleDr03HcalTowerSumEt = 0;
  eleDr03TkSumPt = 0;
  elecaloEnergy = 0;
  eleTrkdxy = 0;
  eleKFHits = 0;
  eleKFChi2 = 0;
  eleGSFChi2 = 0;
  eleGSFPt = 0;
  eleGSFEta = 0;
  eleGSFPhi = 0;
  eleGSFCharge = 0;
  eleGSFHits = 0;
  eleGSFMissHits = 0;
  eleGSFNHitsMax = 0;
  eleGSFVtxProb = 0;
  eleGSFlxyPV = 0;
  eleGSFlxyBS = 0;
  eleBCEn = 0;
  eleBCEta = 0;
  eleBCPhi = 0;
  eleBCS25 = 0;
  eleBCS15 = 0;
  eleBCSieie = 0;
  eleBCSieip = 0;
  eleBCSipip = 0;
  eleFiredSingleTrgs = 0;
  eleFiredDoubleTrgs = 0;
  eleFiredL1Trgs = 0;
  eleIDbit = 0;
  eleScale_stat_up = 0;
  eleScale_stat_dn = 0;
  eleScale_syst_up = 0;
  eleScale_syst_dn = 0;
  eleScale_gain_up = 0;
  eleScale_gain_dn = 0;
  eleResol_rho_up = 0;
  eleResol_rho_dn = 0;
  eleResol_phi_up = 0;
  eleResol_phi_dn = 0;
  muPt = 0;
  muEn = 0;
  muEta = 0;
  muPhi = 0;
  muCharge = 0;
  muType = 0;
  muIDbit = 0;
  muD0 = 0;
  muDz = 0;
  muSIP = 0;
  muChi2NDF = 0;
  muInnerD0 = 0;
  muInnerDz = 0;
  muTrkLayers = 0;
  muPixelLayers = 0;
  muPixelHits = 0;
  muMuonHits = 0;
  muStations = 0;
  muMatches = 0;
  muTrkQuality = 0;
  muIsoTrk = 0;
  muPFChIso = 0;
  muPFPhoIso = 0;
  muPFNeuIso = 0;
  muPFPUIso = 0;
  muPFChIso03 = 0;
  muPFPhoIso03 = 0;
  muPFNeuIso03 = 0;
  muPFPUIso03 = 0;
  muPFMiniIso = 0;
  muFiredTrgs = 0;
  muFiredL1Trgs = 0;
  muInnervalidFraction = 0;
  musegmentCompatibility = 0;
  muchi2LocalPosition = 0;
  mutrkKink = 0;
  muBestTrkPtError = 0;
  muBestTrkPt = 0;
  muBestTrkType = 0;
  pfphoEt = 0;
  pfphoEta = 0;
  pfphoPhi = 0;
  pfHFEn = 0;
  pfHFECALEn = 0;
  pfHFHCALEn = 0;
  pfHFPt = 0;
  pfHFEta = 0;
  pfHFPhi = 0;
  pfHFIso = 0;
  taupfTausDiscriminationByDecayModeFinding = 0;
  taupfTausDiscriminationByDecayModeFindingNewDMs = 0;
  tauByMVA6VLooseElectronRejection = 0;
  tauByMVA6LooseElectronRejection = 0;
  tauByMVA6MediumElectronRejection = 0;
  tauByMVA6TightElectronRejection = 0;
  tauByMVA6VTightElectronRejection = 0;
  tauByLooseMuonRejection3 = 0;
  tauByTightMuonRejection3 = 0;
  tauByLooseCombinedIsolationDeltaBetaCorr3Hits = 0;
  tauByMediumCombinedIsolationDeltaBetaCorr3Hits = 0;
  tauByTightCombinedIsolationDeltaBetaCorr3Hits = 0;
  tauCombinedIsolationDeltaBetaCorrRaw3Hits = 0;
  tauByIsolationMVArun2v1DBnewDMwLTraw = 0;
  tauByIsolationMVArun2v1DBoldDMwLTraw = 0;
  tauByIsolationMVArun2v1PWnewDMwLTraw = 0;
  tauByIsolationMVArun2v1PWoldDMwLTraw = 0;
  tauByVTightIsolationMVArun2v1DBnewDMwLT = 0;
  tauByVTightIsolationMVArun2v1DBoldDMwLT = 0;
  tauByVTightIsolationMVArun2v1PWnewDMwLT = 0;
  tauByVTightIsolationMVArun2v1PWoldDMwLT = 0;
  tauByTightIsolationMVArun2v1DBnewDMwLT = 0;
  tauByTightIsolationMVArun2v1DBoldDMwLT = 0;
  tauByTightIsolationMVArun2v1PWnewDMwLT = 0;
  tauByTightIsolationMVArun2v1PWoldDMwLT = 0;
  tauByMediumIsolationMVArun2v1DBnewDMwLT = 0;
  tauByMediumIsolationMVArun2v1DBoldDMwLT = 0;
  tauByMediumIsolationMVArun2v1PWnewDMwLT = 0;
  tauByMediumIsolationMVArun2v1PWoldDMwLT = 0;
  tauByLooseIsolationMVArun2v1DBnewDMwLT = 0;
  tauByLooseIsolationMVArun2v1DBoldDMwLT = 0;
  tauByLooseIsolationMVArun2v1PWnewDMwLT = 0;
  tauByLooseIsolationMVArun2v1PWoldDMwLT = 0;
  tauByVLooseIsolationMVArun2v1DBnewDMwLT = 0;
  tauByVLooseIsolationMVArun2v1DBoldDMwLT = 0;
  tauByVLooseIsolationMVArun2v1PWnewDMwLT = 0;
  tauByVLooseIsolationMVArun2v1PWoldDMwLT = 0;
  tauEta = 0;
  tauPhi = 0;
  tauPt = 0;
  tauEt = 0;
  tauCharge = 0;
  tauP = 0;
  tauPx = 0;
  tauPy = 0;
  tauPz = 0;
  tauVz = 0;
  tauEnergy = 0;
  tauMass = 0;
  tauDxy = 0;
  tauZImpact = 0;
  tauDecayMode = 0;
  tauLeadChargedHadronExists = 0;
  tauLeadChargedHadronEta = 0;
  tauLeadChargedHadronPhi = 0;
  tauLeadChargedHadronPt = 0;
  tauChargedIsoPtSum = 0;
  tauNeutralIsoPtSum = 0;
  tauPuCorrPtSum = 0;
  tauNumSignalPFChargedHadrCands = 0;
  tauNumSignalPFNeutrHadrCands = 0;
  tauNumSignalPFGammaCands = 0;
  tauNumSignalPFCands = 0;
  tauNumIsolationPFChargedHadrCands = 0;
  tauNumIsolationPFNeutrHadrCands = 0;
  tauNumIsolationPFGammaCands = 0;
  tauNumIsolationPFCands = 0;
  taufootprintCorrection = 0;
  tauphotonPtSumOutsideSignalCone = 0;
  taudz = 0;
  taudxy = 0;
  jetPt = 0;
  jetEn = 0;
  jetEta = 0;
  jetPhi = 0;
  jetRawPt = 0;
  jetRawEn = 0;
  jetMt = 0;
  jetArea = 0;
  jetLeadTrackPt = 0;
  jetLeadTrackEta = 0;
  jetLeadTrackPhi = 0;
  jetLepTrackPID = 0;
  jetLepTrackPt = 0;
  jetLepTrackEta = 0;
  jetLepTrackPhi = 0;
  jetCSV2BJetTags = 0;
  jetJetProbabilityBJetTags = 0;
  jetpfCombinedMVAV2BJetTags = 0;
  jetDeepCSVTags_b = 0;
  jetDeepCSVTags_bb = 0;
  jetDeepCSVTags_c = 0;
  jetDeepCSVTags_cc = 0;
  jetDeepCSVTags_udsg = 0;
  jetPartonID = 0;
  jetHadFlvr = 0;
  jetGenJetEn = 0;
  jetGenJetPt = 0;
  jetGenJetEta = 0;
  jetGenJetPhi = 0;
  jetGenPartonID = 0;
  jetGenEn = 0;
  jetGenPt = 0;
  jetGenEta = 0;
  jetGenPhi = 0;
  jetGenPartonMomID = 0;
  jetP4Smear = 0;
  jetP4SmearUp = 0;
  jetP4SmearDo = 0;
  jetPFLooseId = 0;
  jetID = 0;
  jetPUID = 0;
  jetPUFullID = 0;
  jetJECUnc = 0;
  jetFiredTrgs = 0;
  jetCHF = 0;
  jetNHF = 0;
  jetCEF = 0;
  jetNEF = 0;
  jetNCH = 0;
  jetNNP = 0;
  jetMUF = 0;
  jetVtxPt = 0;
  jetVtxMass = 0;
  jetVtxNtrks = 0;
  jetVtx3DVal = 0;
  jetVtx3DSig = 0;
  AK8JetPt = 0;
  AK8JetEn = 0;
  AK8JetRawPt = 0;
  AK8JetRawEn = 0;
  AK8JetEta = 0;
  AK8JetPhi = 0;
  AK8JetMass = 0;
  AK8Jet_tau1 = 0;
  AK8Jet_tau2 = 0;
  AK8Jet_tau3 = 0;
  AK8JetCHF = 0;
  AK8JetNHF = 0;
  AK8JetCEF = 0;
  AK8JetNEF = 0;
  AK8JetNCH = 0;
  AK8JetNNP = 0;
  AK8JetMUF = 0;
  AK8Jetnconstituents = 0;
  AK8JetPFLooseId = 0;
  AK8JetPFTightLepVetoId = 0;
  AK8JetSoftDropMass = 0;
  AK8JetSoftDropMassCorr = 0;
  AK8JetPrunedMass = 0;
  AK8JetPrunedMassCorr = 0;
  AK8JetpfBoostedDSVBTag = 0;
  AK8JetDSVnewV4 = 0;
  AK8JetCSV = 0;
  AK8JetJECUnc = 0;
  AK8JetL2L3corr = 0;
  AK8puppiPt = 0;
  AK8puppiMass = 0;
  AK8puppiEta = 0;
  AK8puppiPhi = 0;
  AK8puppiTau1 = 0;
  AK8puppiTau2 = 0;
  AK8puppiTau3 = 0;
  AK8puppiSDL2L3corr = 0;
  AK8puppiSDMass = 0;
  AK8puppiSDMassL2L3Corr = 0;
  AK8JetPartonID = 0;
  AK8JetHadFlvr = 0;
  AK8JetGenJetIndex = 0;
  AK8JetGenJetEn = 0;
  AK8JetGenJetPt = 0;
  AK8JetGenJetEta = 0;
  AK8JetGenJetPhi = 0;
  AK8JetGenPartonID = 0;
  AK8JetGenEn = 0;
  AK8JetGenPt = 0;
  AK8JetGenEta = 0;
  AK8JetGenPhi = 0;
  AK8JetGenPartonMomID = 0;
  AK8JetP4Smear = 0;
  AK8JetP4SmearUp = 0;
  AK8JetP4SmearDo = 0;
  nAK8SDSJ = 0;
  AK8SDSJPt = 0;
  AK8SDSJEta = 0;
  AK8SDSJPhi = 0;
  AK8SDSJMass = 0;
  AK8SDSJE = 0;
  AK8SDSJCharge = 0;
  AK8SDSJFlavour = 0;
  AK8SDSJCSV = 0;
  nAK8puppiSDSJ = 0;
  AK8puppiSDSJPt = 0;
  AK8puppiSDSJEta = 0;
  AK8puppiSDSJPhi = 0;
  AK8puppiSDSJMass = 0;
  AK8puppiSDSJE = 0;
  AK8puppiSDSJCharge = 0;
  AK8puppiSDSJFlavour = 0;
  AK8puppiSDSJCSV = 0;
  isoPt = 0;
  isoEta = 0;
  isoPhi = 0;
  isoD0 = 0;
  isoDz = 0;
  isoCharge = 0;
  isoFromPV = 0;
  isoPdgID = 0;
  isoLeptonOverlap = 0;
  isoChIso = 0;
  isoChRelIso = 0;
  isoChMiniIso = 0;
  isoChRelMiniIso = 0;
  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("run", &run, &b_run);
  fChain->SetBranchAddress("event", &event, &b_event);
  fChain->SetBranchAddress("lumis", &lumis, &b_lumis);
  fChain->SetBranchAddress("isData", &isData, &b_isData);
  fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
  fChain->SetBranchAddress("nGoodVtx", &nGoodVtx, &b_nGoodVtx);
  fChain->SetBranchAddress("nTrksPV", &nTrksPV, &b_nTrksPV);
  fChain->SetBranchAddress("isPVGood", &isPVGood, &b_isPVGood);
  fChain->SetBranchAddress("vtx", &vtx, &b_vtx);
  fChain->SetBranchAddress("vty", &vty, &b_vty);
  fChain->SetBranchAddress("vtz", &vtz, &b_vtz);
  fChain->SetBranchAddress("rho", &rho, &b_rho);
  fChain->SetBranchAddress("rhoCentral", &rhoCentral, &b_rhoCentral);
  fChain->SetBranchAddress("HLTEleMuX", &HLTEleMuX, &b_HLTEleMuX);
  fChain->SetBranchAddress("HLTPho", &HLTPho, &b_HLTPho);
  fChain->SetBranchAddress("HLTPhoRejectedByPS", &HLTPhoRejectedByPS, &b_HLTPhoRejectedByPS);
  fChain->SetBranchAddress("HLTJet", &HLTJet, &b_HLTJet);
  fChain->SetBranchAddress("HLTEleMuXIsPrescaled", &HLTEleMuXIsPrescaled, &b_HLTEleMuXIsPrescaled);
  fChain->SetBranchAddress("HLTPhoIsPrescaled", &HLTPhoIsPrescaled, &b_HLTPhoIsPrescaled);
  fChain->SetBranchAddress("HLTJetIsPrescaled", &HLTJetIsPrescaled, &b_HLTJetIsPrescaled);
  if (fChain->GetBranch("pdf")) fChain->SetBranchAddress("pdf", &pdf, &b_pdf);
  if (fChain->GetBranch("pthat")) fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
  if (fChain->GetBranch("processID")) fChain->SetBranchAddress("processID", &processID, &b_processID);
  if (fChain->GetBranch("genWeight")) fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
  if (fChain->GetBranch("genHT")) fChain->SetBranchAddress("genHT", &genHT, &b_genHT);
  if (fChain->GetBranch("genPho1")) fChain->SetBranchAddress("genPho1", &genPho1, &b_genPho1);
  if (fChain->GetBranch("genPho2")) fChain->SetBranchAddress("genPho2", &genPho2, &b_genPho2);
  if (fChain->GetBranch("EventTag")) fChain->SetBranchAddress("EventTag", &EventTag, &b_EventTag);
  if (fChain->GetBranch("nPUInfo")) fChain->SetBranchAddress("nPUInfo", &nPUInfo, &b_nPUInfo);
  if (fChain->GetBranch("nPU")) fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
  if (fChain->GetBranch("puBX")) fChain->SetBranchAddress("puBX", &puBX, &b_puBX);
  if (fChain->GetBranch("puTrue")) fChain->SetBranchAddress("puTrue", &puTrue, &b_puTrue);
  if (fChain->GetBranch("nMC")) fChain->SetBranchAddress("nMC", &nMC, &b_nMC);
  if (fChain->GetBranch("mcPID")) fChain->SetBranchAddress("mcPID", &mcPID, &b_mcPID);
  if (fChain->GetBranch("mcVtx")) fChain->SetBranchAddress("mcVtx", &mcVtx, &b_mcVtx);
  if (fChain->GetBranch("mcVty")) fChain->SetBranchAddress("mcVty", &mcVty, &b_mcVty);
  if (fChain->GetBranch("mcVtz")) fChain->SetBranchAddress("mcVtz", &mcVtz, &b_mcVtz);
  if (fChain->GetBranch("mcPt")) fChain->SetBranchAddress("mcPt", &mcPt, &b_mcPt);
  if (fChain->GetBranch("mcMass")) fChain->SetBranchAddress("mcMass", &mcMass, &b_mcMass);
  if (fChain->GetBranch("mcEta")) fChain->SetBranchAddress("mcEta", &mcEta, &b_mcEta);
  if (fChain->GetBranch("mcPhi")) fChain->SetBranchAddress("mcPhi", &mcPhi, &b_mcPhi);
  if (fChain->GetBranch("mcE")) fChain->SetBranchAddress("mcE", &mcE, &b_mcE);
  if (fChain->GetBranch("mcEt")) fChain->SetBranchAddress("mcEt", &mcEt, &b_mcEt);
  if (fChain->GetBranch("mcGMomPID")) fChain->SetBranchAddress("mcGMomPID", &mcGMomPID, &b_mcGMomPID);
  if (fChain->GetBranch("mcMomPID")) fChain->SetBranchAddress("mcMomPID", &mcMomPID, &b_mcMomPID);
  if (fChain->GetBranch("mcMomPt")) fChain->SetBranchAddress("mcMomPt", &mcMomPt, &b_mcMomPt);
  if (fChain->GetBranch("mcMomMass")) fChain->SetBranchAddress("mcMomMass", &mcMomMass, &b_mcMomMass);
  if (fChain->GetBranch("mcMomEta")) fChain->SetBranchAddress("mcMomEta", &mcMomEta, &b_mcMomEta);
  if (fChain->GetBranch("mcMomPhi")) fChain->SetBranchAddress("mcMomPhi", &mcMomPhi, &b_mcMomPhi);
  if (fChain->GetBranch("mcStatusFlag")) fChain->SetBranchAddress("mcStatusFlag", &mcStatusFlag, &b_mcStatusFlag);
  if (fChain->GetBranch("mcParentage")) fChain->SetBranchAddress("mcParentage", &mcParentage, &b_mcParentage);
  if (fChain->GetBranch("mcStatus")) fChain->SetBranchAddress("mcStatus", &mcStatus, &b_mcStatus);
  if (fChain->GetBranch("mcCalIsoDR03")) fChain->SetBranchAddress("mcCalIsoDR03", &mcCalIsoDR03, &b_mcCalIsoDR03);
  if (fChain->GetBranch("mcTrkIsoDR03")) fChain->SetBranchAddress("mcTrkIsoDR03", &mcTrkIsoDR03, &b_mcTrkIsoDR03);
  if (fChain->GetBranch("mcCalIsoDR04")) fChain->SetBranchAddress("mcCalIsoDR04", &mcCalIsoDR04, &b_mcCalIsoDR04);
  if (fChain->GetBranch("mcTrkIsoDR04")) fChain->SetBranchAddress("mcTrkIsoDR04", &mcTrkIsoDR04, &b_mcTrkIsoDR04);
  if (fChain->GetBranch("genMET")) fChain->SetBranchAddress("genMET", &genMET, &b_genMET);
  if (fChain->GetBranch("genMETPhi")) fChain->SetBranchAddress("genMETPhi", &genMETPhi, &b_genMETPhi);
  fChain->SetBranchAddress("metFilters", &metFilters, &b_metFilters);
  fChain->SetBranchAddress("pfMET", &pfMET, &b_pfMET);
  fChain->SetBranchAddress("pfMETPhi", &pfMETPhi, &b_pfMETPhi);
  fChain->SetBranchAddress("pfMETsumEt", &pfMETsumEt, &b_pfMETsumEt);
  fChain->SetBranchAddress("pfMETmEtSig", &pfMETmEtSig, &b_pfMETmEtSig);
  fChain->SetBranchAddress("pfMETSig", &pfMETSig, &b_pfMETSig);
  fChain->SetBranchAddress("pfMET_T1JERUp", &pfMET_T1JERUp, &b_pfMET_T1JERUp);
  fChain->SetBranchAddress("pfMET_T1JERDo", &pfMET_T1JERDo, &b_pfMET_T1JERDo);
  fChain->SetBranchAddress("pfMET_T1JESUp", &pfMET_T1JESUp, &b_pfMET_T1JESUp);
  fChain->SetBranchAddress("pfMET_T1JESDo", &pfMET_T1JESDo, &b_pfMET_T1JESDo);
  fChain->SetBranchAddress("pfMET_T1UESUp", &pfMET_T1UESUp, &b_pfMET_T1UESUp);
  fChain->SetBranchAddress("pfMET_T1UESDo", &pfMET_T1UESDo, &b_pfMET_T1UESDo);
  fChain->SetBranchAddress("pfMETPhi_T1JESUp", &pfMETPhi_T1JESUp, &b_pfMETPhi_T1JESUp);
  fChain->SetBranchAddress("pfMETPhi_T1JESDo", &pfMETPhi_T1JESDo, &b_pfMETPhi_T1JESDo);
  fChain->SetBranchAddress("pfMETPhi_T1UESUp", &pfMETPhi_T1UESUp, &b_pfMETPhi_T1UESUp);
  fChain->SetBranchAddress("pfMETPhi_T1UESDo", &pfMETPhi_T1UESDo, &b_pfMETPhi_T1UESDo);
  fChain->SetBranchAddress("nPho", &nPho, &b_nPho);
  fChain->SetBranchAddress("phoE", &phoE, &b_phoE);
  fChain->SetBranchAddress("phoEt", &phoEt, &b_phoEt);
  fChain->SetBranchAddress("phoEta", &phoEta, &b_phoEta);
  fChain->SetBranchAddress("phoPhi", &phoPhi, &b_phoPhi);
  fChain->SetBranchAddress("phoCalibE", &phoCalibE, &b_phoCalibE);
  fChain->SetBranchAddress("phoCalibEt", &phoCalibEt, &b_phoCalibEt);
  fChain->SetBranchAddress("phoSCE", &phoSCE, &b_phoSCE);
  fChain->SetBranchAddress("phoSCRawE", &phoSCRawE, &b_phoSCRawE);
  fChain->SetBranchAddress("phoESEnP1", &phoESEnP1, &b_phoESEnP1);
  fChain->SetBranchAddress("phoESEnP2", &phoESEnP2, &b_phoESEnP2);
  fChain->SetBranchAddress("phoSCEta", &phoSCEta, &b_phoSCEta);
  fChain->SetBranchAddress("phoSCPhi", &phoSCPhi, &b_phoSCPhi);
  fChain->SetBranchAddress("phoSCEtaWidth", &phoSCEtaWidth, &b_phoSCEtaWidth);
  fChain->SetBranchAddress("phoSCPhiWidth", &phoSCPhiWidth, &b_phoSCPhiWidth);
  fChain->SetBranchAddress("phoSCBrem", &phoSCBrem, &b_phoSCBrem);
  fChain->SetBranchAddress("phohasPixelSeed", &phohasPixelSeed, &b_phohasPixelSeed);
  fChain->SetBranchAddress("phoEleVeto", &phoEleVeto, &b_phoEleVeto);
  fChain->SetBranchAddress("phoR9", &phoR9, &b_phoR9);
  fChain->SetBranchAddress("phoHoverE", &phoHoverE, &b_phoHoverE);
  fChain->SetBranchAddress("phoE1x3", &phoE1x3, &b_phoE1x3);
  fChain->SetBranchAddress("phoE1x5", &phoE1x5, &b_phoE1x5);
  fChain->SetBranchAddress("phoE2x2", &phoE2x2, &b_phoE2x2);
  fChain->SetBranchAddress("phoE2x5Max", &phoE2x5Max, &b_phoE2x5Max);
  fChain->SetBranchAddress("phoE5x5", &phoE5x5, &b_phoE5x5);
  fChain->SetBranchAddress("phoESEffSigmaRR", &phoESEffSigmaRR, &b_phoESEffSigmaRR);
  fChain->SetBranchAddress("phoSigmaIEtaIEtaFull5x5", &phoSigmaIEtaIEtaFull5x5, &b_phoSigmaIEtaIEtaFull5x5);
  fChain->SetBranchAddress("phoSigmaIEtaIPhiFull5x5", &phoSigmaIEtaIPhiFull5x5, &b_phoSigmaIEtaIPhiFull5x5);
  fChain->SetBranchAddress("phoSigmaIPhiIPhiFull5x5", &phoSigmaIPhiIPhiFull5x5, &b_phoSigmaIPhiIPhiFull5x5);
  fChain->SetBranchAddress("phoE1x3Full5x5", &phoE1x3Full5x5, &b_phoE1x3Full5x5);
  fChain->SetBranchAddress("phoE1x5Full5x5", &phoE1x5Full5x5, &b_phoE1x5Full5x5);
  fChain->SetBranchAddress("phoE2x2Full5x5", &phoE2x2Full5x5, &b_phoE2x2Full5x5);
  fChain->SetBranchAddress("phoE2x5MaxFull5x5", &phoE2x5MaxFull5x5, &b_phoE2x5MaxFull5x5);
  fChain->SetBranchAddress("phoE5x5Full5x5", &phoE5x5Full5x5, &b_phoE5x5Full5x5);
  fChain->SetBranchAddress("phoR9Full5x5", &phoR9Full5x5, &b_phoR9Full5x5);
  fChain->SetBranchAddress("phoPFChIso", &phoPFChIso, &b_phoPFChIso);
  fChain->SetBranchAddress("phoPFPhoIso", &phoPFPhoIso, &b_phoPFPhoIso);
  fChain->SetBranchAddress("phoPFNeuIso", &phoPFNeuIso, &b_phoPFNeuIso);
  fChain->SetBranchAddress("phoPFChWorstIso", &phoPFChWorstIso, &b_phoPFChWorstIso);
  fChain->SetBranchAddress("phoPFRandConeChIso", &phoPFRandConeChIso, &b_phoPFRandConeChIso);
  fChain->SetBranchAddress("phoCITKChIso", &phoCITKChIso, &b_phoCITKChIso);
  fChain->SetBranchAddress("phoCITKPhoIso", &phoCITKPhoIso, &b_phoCITKPhoIso);
  fChain->SetBranchAddress("phoCITKNeuIso", &phoCITKNeuIso, &b_phoCITKNeuIso);
  fChain->SetBranchAddress("phoIDMVA", &phoIDMVA, &b_phoIDMVA);
  fChain->SetBranchAddress("phoFiredSingleTrgs", &phoFiredSingleTrgs, &b_phoFiredSingleTrgs);
  fChain->SetBranchAddress("phoFiredDoubleTrgs", &phoFiredDoubleTrgs, &b_phoFiredDoubleTrgs);
  fChain->SetBranchAddress("phoFiredL1Trgs", &phoFiredL1Trgs, &b_phoFiredL1Trgs);
  fChain->SetBranchAddress("phoSeedTime", &phoSeedTime, &b_phoSeedTime);
  fChain->SetBranchAddress("phoSeedEnergy", &phoSeedEnergy, &b_phoSeedEnergy);
  fChain->SetBranchAddress("phoxtalBits", &phoxtalBits, &b_phoxtalBits);
  fChain->SetBranchAddress("phoIDbit", &phoIDbit, &b_phoIDbit);
  fChain->SetBranchAddress("phoScale_stat_up", &phoScale_stat_up, &b_phoScale_stat_up);
  fChain->SetBranchAddress("phoScale_stat_dn", &phoScale_stat_dn, &b_phoScale_stat_dn);
  fChain->SetBranchAddress("phoScale_syst_up", &phoScale_syst_up, &b_phoScale_syst_up);
  fChain->SetBranchAddress("phoScale_syst_dn", &phoScale_syst_dn, &b_phoScale_syst_dn);
  fChain->SetBranchAddress("phoScale_gain_up", &phoScale_gain_up, &b_phoScale_gain_up);
  fChain->SetBranchAddress("phoScale_gain_dn", &phoScale_gain_dn, &b_phoScale_gain_dn);
  fChain->SetBranchAddress("phoResol_rho_up", &phoResol_rho_up, &b_phoResol_rho_up);
  fChain->SetBranchAddress("phoResol_rho_dn", &phoResol_rho_dn, &b_phoResol_rho_dn);
  fChain->SetBranchAddress("phoResol_phi_up", &phoResol_phi_up, &b_phoResol_phi_up);
  fChain->SetBranchAddress("phoResol_phi_dn", &phoResol_phi_dn, &b_phoResol_phi_dn);
  fChain->SetBranchAddress("nEle", &nEle, &b_nEle);
  fChain->SetBranchAddress("eleCharge", &eleCharge, &b_eleCharge);
  fChain->SetBranchAddress("eleChargeConsistent", &eleChargeConsistent, &b_eleChargeConsistent);
  fChain->SetBranchAddress("eleEn", &eleEn, &b_eleEn);
  fChain->SetBranchAddress("eleSCEn", &eleSCEn, &b_eleSCEn);
  fChain->SetBranchAddress("eleEcalEn", &eleEcalEn, &b_eleEcalEn);
  fChain->SetBranchAddress("eleESEnP1", &eleESEnP1, &b_eleESEnP1);
  fChain->SetBranchAddress("eleESEnP2", &eleESEnP2, &b_eleESEnP2);
  fChain->SetBranchAddress("eleD0", &eleD0, &b_eleD0);
  fChain->SetBranchAddress("eleDz", &eleDz, &b_eleDz);
  fChain->SetBranchAddress("eleSIP", &eleSIP, &b_eleSIP);
  fChain->SetBranchAddress("elePt", &elePt, &b_elePt);
  fChain->SetBranchAddress("eleEta", &eleEta, &b_eleEta);
  fChain->SetBranchAddress("elePhi", &elePhi, &b_elePhi);
  fChain->SetBranchAddress("eleR9", &eleR9, &b_eleR9);
  fChain->SetBranchAddress("eleCalibPt", &eleCalibPt, &b_eleCalibPt);
  fChain->SetBranchAddress("eleCalibEn", &eleCalibEn, &b_eleCalibEn);
  fChain->SetBranchAddress("eleSCEta", &eleSCEta, &b_eleSCEta);
  fChain->SetBranchAddress("eleSCPhi", &eleSCPhi, &b_eleSCPhi);
  fChain->SetBranchAddress("eleSCRawEn", &eleSCRawEn, &b_eleSCRawEn);
  fChain->SetBranchAddress("eleSCEtaWidth", &eleSCEtaWidth, &b_eleSCEtaWidth);
  fChain->SetBranchAddress("eleSCPhiWidth", &eleSCPhiWidth, &b_eleSCPhiWidth);
  fChain->SetBranchAddress("eleHoverE", &eleHoverE, &b_eleHoverE);
  fChain->SetBranchAddress("eleEoverP", &eleEoverP, &b_eleEoverP);
  fChain->SetBranchAddress("eleEoverPout", &eleEoverPout, &b_eleEoverPout);
  fChain->SetBranchAddress("eleEoverPInv", &eleEoverPInv, &b_eleEoverPInv);
  fChain->SetBranchAddress("eleBrem", &eleBrem, &b_eleBrem);
  fChain->SetBranchAddress("eledEtaAtVtx", &eledEtaAtVtx, &b_eledEtaAtVtx);
  fChain->SetBranchAddress("eledPhiAtVtx", &eledPhiAtVtx, &b_eledPhiAtVtx);
  fChain->SetBranchAddress("eledEtaAtCalo", &eledEtaAtCalo, &b_eledEtaAtCalo);
  fChain->SetBranchAddress("eleSigmaIEtaIEtaFull5x5", &eleSigmaIEtaIEtaFull5x5, &b_eleSigmaIEtaIEtaFull5x5);
  fChain->SetBranchAddress("eleSigmaIPhiIPhiFull5x5", &eleSigmaIPhiIPhiFull5x5, &b_eleSigmaIPhiIPhiFull5x5);
  fChain->SetBranchAddress("eleConvVeto", &eleConvVeto, &b_eleConvVeto);
  fChain->SetBranchAddress("eleMissHits", &eleMissHits, &b_eleMissHits);
  fChain->SetBranchAddress("eleESEffSigmaRR", &eleESEffSigmaRR, &b_eleESEffSigmaRR);
  fChain->SetBranchAddress("elePFChIso", &elePFChIso, &b_elePFChIso);
  fChain->SetBranchAddress("elePFPhoIso", &elePFPhoIso, &b_elePFPhoIso);
  fChain->SetBranchAddress("elePFNeuIso", &elePFNeuIso, &b_elePFNeuIso);
  fChain->SetBranchAddress("elePFPUIso", &elePFPUIso, &b_elePFPUIso);
  fChain->SetBranchAddress("elePFClusEcalIso", &elePFClusEcalIso, &b_elePFClusEcalIso);
  fChain->SetBranchAddress("elePFClusHcalIso", &elePFClusHcalIso, &b_elePFClusHcalIso);
  fChain->SetBranchAddress("elePFMiniIso", &elePFMiniIso, &b_elePFMiniIso);
  fChain->SetBranchAddress("eleIDMVA", &eleIDMVA, &b_eleIDMVA);
  fChain->SetBranchAddress("eleIDMVAHZZ", &eleIDMVAHZZ, &b_eleIDMVAHZZ);
  fChain->SetBranchAddress("eledEtaseedAtVtx", &eledEtaseedAtVtx, &b_eledEtaseedAtVtx);
  fChain->SetBranchAddress("eleE1x5", &eleE1x5, &b_eleE1x5);
  fChain->SetBranchAddress("eleE2x5", &eleE2x5, &b_eleE2x5);
  fChain->SetBranchAddress("eleE5x5", &eleE5x5, &b_eleE5x5);
  fChain->SetBranchAddress("eleE1x5Full5x5", &eleE1x5Full5x5, &b_eleE1x5Full5x5);
  fChain->SetBranchAddress("eleE2x5Full5x5", &eleE2x5Full5x5, &b_eleE2x5Full5x5);
  fChain->SetBranchAddress("eleE5x5Full5x5", &eleE5x5Full5x5, &b_eleE5x5Full5x5);
  fChain->SetBranchAddress("eleR9Full5x5", &eleR9Full5x5, &b_eleR9Full5x5);
  fChain->SetBranchAddress("eleEcalDrivenSeed", &eleEcalDrivenSeed, &b_eleEcalDrivenSeed);
  fChain->SetBranchAddress("eleDr03EcalRecHitSumEt", &eleDr03EcalRecHitSumEt, &b_eleDr03EcalRecHitSumEt);
  fChain->SetBranchAddress("eleDr03HcalDepth1TowerSumEt", &eleDr03HcalDepth1TowerSumEt, &b_eleDr03HcalDepth1TowerSumEt);
  fChain->SetBranchAddress("eleDr03HcalDepth2TowerSumEt", &eleDr03HcalDepth2TowerSumEt, &b_eleDr03HcalDepth2TowerSumEt);
  fChain->SetBranchAddress("eleDr03HcalTowerSumEt", &eleDr03HcalTowerSumEt, &b_eleDr03HcalTowerSumEt);
  fChain->SetBranchAddress("eleDr03TkSumPt", &eleDr03TkSumPt, &b_eleDr03TkSumPt);
  fChain->SetBranchAddress("elecaloEnergy", &elecaloEnergy, &b_elecaloEnergy);
  fChain->SetBranchAddress("eleTrkdxy", &eleTrkdxy, &b_eleTrkdxy);
  fChain->SetBranchAddress("eleKFHits", &eleKFHits, &b_eleKFHits);
  fChain->SetBranchAddress("eleKFChi2", &eleKFChi2, &b_eleKFChi2);
  fChain->SetBranchAddress("eleGSFChi2", &eleGSFChi2, &b_eleGSFChi2);
  fChain->SetBranchAddress("eleGSFPt", &eleGSFPt, &b_eleGSFPt);
  fChain->SetBranchAddress("eleGSFEta", &eleGSFEta, &b_eleGSFEta);
  fChain->SetBranchAddress("eleGSFPhi", &eleGSFPhi, &b_eleGSFPhi);
  fChain->SetBranchAddress("eleGSFCharge", &eleGSFCharge, &b_eleGSFCharge);
  fChain->SetBranchAddress("eleGSFHits", &eleGSFHits, &b_eleGSFHits);
  fChain->SetBranchAddress("eleGSFMissHits", &eleGSFMissHits, &b_eleGSFMissHits);
  fChain->SetBranchAddress("eleGSFNHitsMax", &eleGSFNHitsMax, &b_eleGSFNHitsMax);
  fChain->SetBranchAddress("eleGSFVtxProb", &eleGSFVtxProb, &b_eleGSFVtxProb);
  fChain->SetBranchAddress("eleGSFlxyPV", &eleGSFlxyPV, &b_eleGSFlxyPV);
  fChain->SetBranchAddress("eleGSFlxyBS", &eleGSFlxyBS, &b_eleGSFlxyBS);
  fChain->SetBranchAddress("eleBCEn", &eleBCEn, &b_eleBCEn);
  fChain->SetBranchAddress("eleBCEta", &eleBCEta, &b_eleBCEta);
  fChain->SetBranchAddress("eleBCPhi", &eleBCPhi, &b_eleBCPhi);
  fChain->SetBranchAddress("eleBCS25", &eleBCS25, &b_eleBCS25);
  fChain->SetBranchAddress("eleBCS15", &eleBCS15, &b_eleBCS15);
  fChain->SetBranchAddress("eleBCSieie", &eleBCSieie, &b_eleBCSieie);
  fChain->SetBranchAddress("eleBCSieip", &eleBCSieip, &b_eleBCSieip);
  fChain->SetBranchAddress("eleBCSipip", &eleBCSipip, &b_eleBCSipip);
  fChain->SetBranchAddress("eleFiredSingleTrgs", &eleFiredSingleTrgs, &b_eleFiredSingleTrgs);
  fChain->SetBranchAddress("eleFiredDoubleTrgs", &eleFiredDoubleTrgs, &b_eleFiredDoubleTrgs);
  fChain->SetBranchAddress("eleFiredL1Trgs", &eleFiredL1Trgs, &b_eleFiredL1Trgs);
  fChain->SetBranchAddress("eleIDbit", &eleIDbit, &b_eleIDbit);
  fChain->SetBranchAddress("eleScale_stat_up", &eleScale_stat_up, &b_eleScale_stat_up);
  fChain->SetBranchAddress("eleScale_stat_dn", &eleScale_stat_dn, &b_eleScale_stat_dn);
  fChain->SetBranchAddress("eleScale_syst_up", &eleScale_syst_up, &b_eleScale_syst_up);
  fChain->SetBranchAddress("eleScale_syst_dn", &eleScale_syst_dn, &b_eleScale_syst_dn);
  fChain->SetBranchAddress("eleScale_gain_up", &eleScale_gain_up, &b_eleScale_gain_up);
  fChain->SetBranchAddress("eleScale_gain_dn", &eleScale_gain_dn, &b_eleScale_gain_dn);
  fChain->SetBranchAddress("eleResol_rho_up", &eleResol_rho_up, &b_eleResol_rho_up);
  fChain->SetBranchAddress("eleResol_rho_dn", &eleResol_rho_dn, &b_eleResol_rho_dn);
  fChain->SetBranchAddress("eleResol_phi_up", &eleResol_phi_up, &b_eleResol_phi_up);
  fChain->SetBranchAddress("eleResol_phi_dn", &eleResol_phi_dn, &b_eleResol_phi_dn);
  fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
  fChain->SetBranchAddress("muPt", &muPt, &b_muPt);
  fChain->SetBranchAddress("muEn", &muEn, &b_muEn);
  fChain->SetBranchAddress("muEta", &muEta, &b_muEta);
  fChain->SetBranchAddress("muPhi", &muPhi, &b_muPhi);
  fChain->SetBranchAddress("muCharge", &muCharge, &b_muCharge);
  fChain->SetBranchAddress("muType", &muType, &b_muType);
  fChain->SetBranchAddress("muIDbit", &muIDbit, &b_muIDbit);
  fChain->SetBranchAddress("muD0", &muD0, &b_muD0);
  fChain->SetBranchAddress("muDz", &muDz, &b_muDz);
  fChain->SetBranchAddress("muSIP", &muSIP, &b_muSIP);
  fChain->SetBranchAddress("muChi2NDF", &muChi2NDF, &b_muChi2NDF);
  fChain->SetBranchAddress("muInnerD0", &muInnerD0, &b_muInnerD0);
  fChain->SetBranchAddress("muInnerDz", &muInnerDz, &b_muInnerDz);
  fChain->SetBranchAddress("muTrkLayers", &muTrkLayers, &b_muTrkLayers);
  fChain->SetBranchAddress("muPixelLayers", &muPixelLayers, &b_muPixelLayers);
  fChain->SetBranchAddress("muPixelHits", &muPixelHits, &b_muPixelHits);
  fChain->SetBranchAddress("muMuonHits", &muMuonHits, &b_muMuonHits);
  fChain->SetBranchAddress("muStations", &muStations, &b_muStations);
  fChain->SetBranchAddress("muMatches", &muMatches, &b_muMatches);
  fChain->SetBranchAddress("muTrkQuality", &muTrkQuality, &b_muTrkQuality);
  fChain->SetBranchAddress("muIsoTrk", &muIsoTrk, &b_muIsoTrk);
  fChain->SetBranchAddress("muPFChIso", &muPFChIso, &b_muPFChIso);
  fChain->SetBranchAddress("muPFPhoIso", &muPFPhoIso, &b_muPFPhoIso);
  fChain->SetBranchAddress("muPFNeuIso", &muPFNeuIso, &b_muPFNeuIso);
  fChain->SetBranchAddress("muPFPUIso", &muPFPUIso, &b_muPFPUIso);
  fChain->SetBranchAddress("muPFChIso03", &muPFChIso03, &b_muPFChIso03);
  fChain->SetBranchAddress("muPFPhoIso03", &muPFPhoIso03, &b_muPFPhoIso03);
  fChain->SetBranchAddress("muPFNeuIso03", &muPFNeuIso03, &b_muPFNeuIso03);
  fChain->SetBranchAddress("muPFPUIso03", &muPFPUIso03, &b_muPFPUIso03);
  fChain->SetBranchAddress("muPFMiniIso", &muPFMiniIso, &b_muPFMiniIso);
  fChain->SetBranchAddress("muFiredTrgs", &muFiredTrgs, &b_muFiredTrgs);
  fChain->SetBranchAddress("muFiredL1Trgs", &muFiredL1Trgs, &b_muFiredL1Trgs);
  fChain->SetBranchAddress("muInnervalidFraction", &muInnervalidFraction, &b_muInnervalidFraction);
  fChain->SetBranchAddress("musegmentCompatibility", &musegmentCompatibility, &b_musegmentCompatibility);
  fChain->SetBranchAddress("muchi2LocalPosition", &muchi2LocalPosition, &b_muchi2LocalPosition);
  fChain->SetBranchAddress("mutrkKink", &mutrkKink, &b_mutrkKink);
  fChain->SetBranchAddress("muBestTrkPtError", &muBestTrkPtError, &b_muBestTrkPtError);
  fChain->SetBranchAddress("muBestTrkPt", &muBestTrkPt, &b_muBestTrkPt);
  fChain->SetBranchAddress("muBestTrkType", &muBestTrkType, &b_muBestTrkType);
  fChain->SetBranchAddress("npfPho", &npfPho, &b_npfPho);
  fChain->SetBranchAddress("pfphoEt", &pfphoEt, &b_pfphoEt);
  fChain->SetBranchAddress("pfphoEta", &pfphoEta, &b_pfphoEta);
  fChain->SetBranchAddress("pfphoPhi", &pfphoPhi, &b_pfphoPhi);
  fChain->SetBranchAddress("npfHF", &npfHF, &b_npfHF);
  fChain->SetBranchAddress("pfHFEn", &pfHFEn, &b_pfHFEn);
  fChain->SetBranchAddress("pfHFECALEn", &pfHFECALEn, &b_pfHFECALEn);
  fChain->SetBranchAddress("pfHFHCALEn", &pfHFHCALEn, &b_pfHFHCALEn);
  fChain->SetBranchAddress("pfHFPt", &pfHFPt, &b_pfHFPt);
  fChain->SetBranchAddress("pfHFEta", &pfHFEta, &b_pfHFEta);
  fChain->SetBranchAddress("pfHFPhi", &pfHFPhi, &b_pfHFPhi);
  fChain->SetBranchAddress("pfHFIso", &pfHFIso, &b_pfHFIso);
  fChain->SetBranchAddress("nTau", &nTau, &b_nTau);
  fChain->SetBranchAddress("taupfTausDiscriminationByDecayModeFinding", &taupfTausDiscriminationByDecayModeFinding, &b_taupfTausDiscriminationByDecayModeFinding);
  fChain->SetBranchAddress("taupfTausDiscriminationByDecayModeFindingNewDMs", &taupfTausDiscriminationByDecayModeFindingNewDMs, &b_taupfTausDiscriminationByDecayModeFindingNewDMs);
  fChain->SetBranchAddress("tauByMVA6VLooseElectronRejection", &tauByMVA6VLooseElectronRejection, &b_tauByMVA6VLooseElectronRejection);
  fChain->SetBranchAddress("tauByMVA6LooseElectronRejection", &tauByMVA6LooseElectronRejection, &b_tauByMVA6LooseElectronRejection);
  fChain->SetBranchAddress("tauByMVA6MediumElectronRejection", &tauByMVA6MediumElectronRejection, &b_tauByMVA6MediumElectronRejection);
  fChain->SetBranchAddress("tauByMVA6TightElectronRejection", &tauByMVA6TightElectronRejection, &b_tauByMVA6TightElectronRejection);
  fChain->SetBranchAddress("tauByMVA6VTightElectronRejection", &tauByMVA6VTightElectronRejection, &b_tauByMVA6VTightElectronRejection);
  fChain->SetBranchAddress("tauByLooseMuonRejection3", &tauByLooseMuonRejection3, &b_tauByLooseMuonRejection3);
  fChain->SetBranchAddress("tauByTightMuonRejection3", &tauByTightMuonRejection3, &b_tauByTightMuonRejection3);
  fChain->SetBranchAddress("tauByLooseCombinedIsolationDeltaBetaCorr3Hits", &tauByLooseCombinedIsolationDeltaBetaCorr3Hits, &b_tauByLooseCombinedIsolationDeltaBetaCorr3Hits);
  fChain->SetBranchAddress("tauByMediumCombinedIsolationDeltaBetaCorr3Hits", &tauByMediumCombinedIsolationDeltaBetaCorr3Hits, &b_tauByMediumCombinedIsolationDeltaBetaCorr3Hits);
  fChain->SetBranchAddress("tauByTightCombinedIsolationDeltaBetaCorr3Hits", &tauByTightCombinedIsolationDeltaBetaCorr3Hits, &b_tauByTightCombinedIsolationDeltaBetaCorr3Hits);
  fChain->SetBranchAddress("tauCombinedIsolationDeltaBetaCorrRaw3Hits", &tauCombinedIsolationDeltaBetaCorrRaw3Hits, &b_tauCombinedIsolationDeltaBetaCorrRaw3Hits);
  fChain->SetBranchAddress("tauByIsolationMVArun2v1DBnewDMwLTraw", &tauByIsolationMVArun2v1DBnewDMwLTraw, &b_tauByIsolationMVArun2v1DBnewDMwLTraw);
  fChain->SetBranchAddress("tauByIsolationMVArun2v1DBoldDMwLTraw", &tauByIsolationMVArun2v1DBoldDMwLTraw, &b_tauByIsolationMVArun2v1DBoldDMwLTraw);
  fChain->SetBranchAddress("tauByIsolationMVArun2v1PWnewDMwLTraw", &tauByIsolationMVArun2v1PWnewDMwLTraw, &b_tauByIsolationMVArun2v1PWnewDMwLTraw);
  fChain->SetBranchAddress("tauByIsolationMVArun2v1PWoldDMwLTraw", &tauByIsolationMVArun2v1PWoldDMwLTraw, &b_tauByIsolationMVArun2v1PWoldDMwLTraw);
  fChain->SetBranchAddress("tauByVTightIsolationMVArun2v1DBnewDMwLT", &tauByVTightIsolationMVArun2v1DBnewDMwLT, &b_tauByVTightIsolationMVArun2v1DBnewDMwLT);
  fChain->SetBranchAddress("tauByVTightIsolationMVArun2v1DBoldDMwLT", &tauByVTightIsolationMVArun2v1DBoldDMwLT, &b_tauByVTightIsolationMVArun2v1DBoldDMwLT);
  fChain->SetBranchAddress("tauByVTightIsolationMVArun2v1PWnewDMwLT", &tauByVTightIsolationMVArun2v1PWnewDMwLT, &b_tauByVTightIsolationMVArun2v1PWnewDMwLT);
  fChain->SetBranchAddress("tauByVTightIsolationMVArun2v1PWoldDMwLT", &tauByVTightIsolationMVArun2v1PWoldDMwLT, &b_tauByVTightIsolationMVArun2v1PWoldDMwLT);
  fChain->SetBranchAddress("tauByTightIsolationMVArun2v1DBnewDMwLT", &tauByTightIsolationMVArun2v1DBnewDMwLT, &b_tauByTightIsolationMVArun2v1DBnewDMwLT);
  fChain->SetBranchAddress("tauByTightIsolationMVArun2v1DBoldDMwLT", &tauByTightIsolationMVArun2v1DBoldDMwLT, &b_tauByTightIsolationMVArun2v1DBoldDMwLT);
  fChain->SetBranchAddress("tauByTightIsolationMVArun2v1PWnewDMwLT", &tauByTightIsolationMVArun2v1PWnewDMwLT, &b_tauByTightIsolationMVArun2v1PWnewDMwLT);
  fChain->SetBranchAddress("tauByTightIsolationMVArun2v1PWoldDMwLT", &tauByTightIsolationMVArun2v1PWoldDMwLT, &b_tauByTightIsolationMVArun2v1PWoldDMwLT);
  fChain->SetBranchAddress("tauByMediumIsolationMVArun2v1DBnewDMwLT", &tauByMediumIsolationMVArun2v1DBnewDMwLT, &b_tauByMediumIsolationMVArun2v1DBnewDMwLT);
  fChain->SetBranchAddress("tauByMediumIsolationMVArun2v1DBoldDMwLT", &tauByMediumIsolationMVArun2v1DBoldDMwLT, &b_tauByMediumIsolationMVArun2v1DBoldDMwLT);
  fChain->SetBranchAddress("tauByMediumIsolationMVArun2v1PWnewDMwLT", &tauByMediumIsolationMVArun2v1PWnewDMwLT, &b_tauByMediumIsolationMVArun2v1PWnewDMwLT);
  fChain->SetBranchAddress("tauByMediumIsolationMVArun2v1PWoldDMwLT", &tauByMediumIsolationMVArun2v1PWoldDMwLT, &b_tauByMediumIsolationMVArun2v1PWoldDMwLT);
  fChain->SetBranchAddress("tauByLooseIsolationMVArun2v1DBnewDMwLT", &tauByLooseIsolationMVArun2v1DBnewDMwLT, &b_tauByLooseIsolationMVArun2v1DBnewDMwLT);
  fChain->SetBranchAddress("tauByLooseIsolationMVArun2v1DBoldDMwLT", &tauByLooseIsolationMVArun2v1DBoldDMwLT, &b_tauByLooseIsolationMVArun2v1DBoldDMwLT);
  fChain->SetBranchAddress("tauByLooseIsolationMVArun2v1PWnewDMwLT", &tauByLooseIsolationMVArun2v1PWnewDMwLT, &b_tauByLooseIsolationMVArun2v1PWnewDMwLT);
  fChain->SetBranchAddress("tauByLooseIsolationMVArun2v1PWoldDMwLT", &tauByLooseIsolationMVArun2v1PWoldDMwLT, &b_tauByLooseIsolationMVArun2v1PWoldDMwLT);
  fChain->SetBranchAddress("tauByVLooseIsolationMVArun2v1DBnewDMwLT", &tauByVLooseIsolationMVArun2v1DBnewDMwLT, &b_tauByVLooseIsolationMVArun2v1DBnewDMwLT);
  fChain->SetBranchAddress("tauByVLooseIsolationMVArun2v1DBoldDMwLT", &tauByVLooseIsolationMVArun2v1DBoldDMwLT, &b_tauByVLooseIsolationMVArun2v1DBoldDMwLT);
  fChain->SetBranchAddress("tauByVLooseIsolationMVArun2v1PWnewDMwLT", &tauByVLooseIsolationMVArun2v1PWnewDMwLT, &b_tauByVLooseIsolationMVArun2v1PWnewDMwLT);
  fChain->SetBranchAddress("tauByVLooseIsolationMVArun2v1PWoldDMwLT", &tauByVLooseIsolationMVArun2v1PWoldDMwLT, &b_tauByVLooseIsolationMVArun2v1PWoldDMwLT);
  fChain->SetBranchAddress("tauEta", &tauEta, &b_tauEta);
  fChain->SetBranchAddress("tauPhi", &tauPhi, &b_tauPhi);
  fChain->SetBranchAddress("tauPt", &tauPt, &b_tauPt);
  fChain->SetBranchAddress("tauEt", &tauEt, &b_tauEt);
  fChain->SetBranchAddress("tauCharge", &tauCharge, &b_tauCharge);
  fChain->SetBranchAddress("tauP", &tauP, &b_tauP);
  fChain->SetBranchAddress("tauPx", &tauPx, &b_tauPx);
  fChain->SetBranchAddress("tauPy", &tauPy, &b_tauPy);
  fChain->SetBranchAddress("tauPz", &tauPz, &b_tauPz);
  fChain->SetBranchAddress("tauVz", &tauVz, &b_tauVz);
  fChain->SetBranchAddress("tauEnergy", &tauEnergy, &b_tauEnergy);
  fChain->SetBranchAddress("tauMass", &tauMass, &b_tauMass);
  fChain->SetBranchAddress("tauDxy", &tauDxy, &b_tauDxy);
  fChain->SetBranchAddress("tauZImpact", &tauZImpact, &b_tauZImpact);
  fChain->SetBranchAddress("tauDecayMode", &tauDecayMode, &b_tauDecayMode);
  fChain->SetBranchAddress("tauLeadChargedHadronExists", &tauLeadChargedHadronExists, &b_tauLeadChargedHadronExists);
  fChain->SetBranchAddress("tauLeadChargedHadronEta", &tauLeadChargedHadronEta, &b_tauLeadChargedHadronEta);
  fChain->SetBranchAddress("tauLeadChargedHadronPhi", &tauLeadChargedHadronPhi, &b_tauLeadChargedHadronPhi);
  fChain->SetBranchAddress("tauLeadChargedHadronPt", &tauLeadChargedHadronPt, &b_tauLeadChargedHadronPt);
  fChain->SetBranchAddress("tauChargedIsoPtSum", &tauChargedIsoPtSum, &b_tauChargedIsoPtSum);
  fChain->SetBranchAddress("tauNeutralIsoPtSum", &tauNeutralIsoPtSum, &b_tauNeutralIsoPtSum);
  fChain->SetBranchAddress("tauPuCorrPtSum", &tauPuCorrPtSum, &b_tauPuCorrPtSum);
  fChain->SetBranchAddress("tauNumSignalPFChargedHadrCands", &tauNumSignalPFChargedHadrCands, &b_tauNumSignalPFChargedHadrCands);
  fChain->SetBranchAddress("tauNumSignalPFNeutrHadrCands", &tauNumSignalPFNeutrHadrCands, &b_tauNumSignalPFNeutrHadrCands);
  fChain->SetBranchAddress("tauNumSignalPFGammaCands", &tauNumSignalPFGammaCands, &b_tauNumSignalPFGammaCands);
  fChain->SetBranchAddress("tauNumSignalPFCands", &tauNumSignalPFCands, &b_tauNumSignalPFCands);
  fChain->SetBranchAddress("tauNumIsolationPFChargedHadrCands", &tauNumIsolationPFChargedHadrCands, &b_tauNumIsolationPFChargedHadrCands);
  fChain->SetBranchAddress("tauNumIsolationPFNeutrHadrCands", &tauNumIsolationPFNeutrHadrCands, &b_tauNumIsolationPFNeutrHadrCands);
  fChain->SetBranchAddress("tauNumIsolationPFGammaCands", &tauNumIsolationPFGammaCands, &b_tauNumIsolationPFGammaCands);
  fChain->SetBranchAddress("tauNumIsolationPFCands", &tauNumIsolationPFCands, &b_tauNumIsolationPFCands);
  fChain->SetBranchAddress("taufootprintCorrection", &taufootprintCorrection, &b_taufootprintCorrection);
  fChain->SetBranchAddress("tauphotonPtSumOutsideSignalCone", &tauphotonPtSumOutsideSignalCone, &b_tauphotonPtSumOutsideSignalCone);
  fChain->SetBranchAddress("taudz", &taudz, &b_taudz);
  fChain->SetBranchAddress("taudxy", &taudxy, &b_taudxy);
  fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
  fChain->SetBranchAddress("jetPt", &jetPt, &b_jetPt);
  fChain->SetBranchAddress("jetEn", &jetEn, &b_jetEn);
  fChain->SetBranchAddress("jetEta", &jetEta, &b_jetEta);
  fChain->SetBranchAddress("jetPhi", &jetPhi, &b_jetPhi);
  fChain->SetBranchAddress("jetRawPt", &jetRawPt, &b_jetRawPt);
  fChain->SetBranchAddress("jetRawEn", &jetRawEn, &b_jetRawEn);
  fChain->SetBranchAddress("jetMt", &jetMt, &b_jetMt);
  fChain->SetBranchAddress("jetArea", &jetArea, &b_jetArea);
  fChain->SetBranchAddress("jetLeadTrackPt", &jetLeadTrackPt, &b_jetLeadTrackPt);
  fChain->SetBranchAddress("jetLeadTrackEta", &jetLeadTrackEta, &b_jetLeadTrackEta);
  fChain->SetBranchAddress("jetLeadTrackPhi", &jetLeadTrackPhi, &b_jetLeadTrackPhi);
  fChain->SetBranchAddress("jetLepTrackPID", &jetLepTrackPID, &b_jetLepTrackPID);
  fChain->SetBranchAddress("jetLepTrackPt", &jetLepTrackPt, &b_jetLepTrackPt);
  fChain->SetBranchAddress("jetLepTrackEta", &jetLepTrackEta, &b_jetLepTrackEta);
  fChain->SetBranchAddress("jetLepTrackPhi", &jetLepTrackPhi, &b_jetLepTrackPhi);
  fChain->SetBranchAddress("jetCSV2BJetTags", &jetCSV2BJetTags, &b_jetCSV2BJetTags);
  fChain->SetBranchAddress("jetJetProbabilityBJetTags", &jetJetProbabilityBJetTags, &b_jetJetProbabilityBJetTags);
  fChain->SetBranchAddress("jetpfCombinedMVAV2BJetTags", &jetpfCombinedMVAV2BJetTags, &b_jetpfCombinedMVAV2BJetTags);
  fChain->SetBranchAddress("jetDeepCSVTags_b", &jetDeepCSVTags_b, &b_jetDeepCSVTags_b);
  fChain->SetBranchAddress("jetDeepCSVTags_bb", &jetDeepCSVTags_bb, &b_jetDeepCSVTags_bb);
  fChain->SetBranchAddress("jetDeepCSVTags_c", &jetDeepCSVTags_c, &b_jetDeepCSVTags_c);
  fChain->SetBranchAddress("jetDeepCSVTags_cc", &jetDeepCSVTags_cc, &b_jetDeepCSVTags_cc);
  fChain->SetBranchAddress("jetDeepCSVTags_udsg", &jetDeepCSVTags_udsg, &b_jetDeepCSVTags_udsg);
  if (fChain->GetBranch("jetPartonID")) fChain->SetBranchAddress("jetPartonID", &jetPartonID, &b_jetPartonID);
  if (fChain->GetBranch("jetHadFlvr")) fChain->SetBranchAddress("jetHadFlvr", &jetHadFlvr, &b_jetHadFlvr);
  if (fChain->GetBranch("jetGenJetEn")) fChain->SetBranchAddress("jetGenJetEn", &jetGenJetEn, &b_jetGenJetEn);
  if (fChain->GetBranch("jetGenJetPt")) fChain->SetBranchAddress("jetGenJetPt", &jetGenJetPt, &b_jetGenJetPt);
  if (fChain->GetBranch("jetGenJetEta")) fChain->SetBranchAddress("jetGenJetEta", &jetGenJetEta, &b_jetGenJetEta);
  if (fChain->GetBranch("jetGenJetPhi")) fChain->SetBranchAddress("jetGenJetPhi", &jetGenJetPhi, &b_jetGenJetPhi);
  if (fChain->GetBranch("jetGenPartonID")) fChain->SetBranchAddress("jetGenPartonID", &jetGenPartonID, &b_jetGenPartonID);
  if (fChain->GetBranch("jetGenEn")) fChain->SetBranchAddress("jetGenEn", &jetGenEn, &b_jetGenEn);
  if (fChain->GetBranch("jetGenPt")) fChain->SetBranchAddress("jetGenPt", &jetGenPt, &b_jetGenPt);
  if (fChain->GetBranch("jetGenEta")) fChain->SetBranchAddress("jetGenEta", &jetGenEta, &b_jetGenEta);
  if (fChain->GetBranch("jetGenPhi")) fChain->SetBranchAddress("jetGenPhi", &jetGenPhi, &b_jetGenPhi);
  if (fChain->GetBranch("jetGenPartonMomID")) fChain->SetBranchAddress("jetGenPartonMomID", &jetGenPartonMomID, &b_jetGenPartonMomID);
  if (fChain->GetBranch("jetP4Smear")) fChain->SetBranchAddress("jetP4Smear", &jetP4Smear, &b_jetP4Smear);
  if (fChain->GetBranch("jetP4SmearUp")) fChain->SetBranchAddress("jetP4SmearUp", &jetP4SmearUp, &b_jetP4SmearUp);
  if (fChain->GetBranch("jetP4SmearDo")) fChain->SetBranchAddress("jetP4SmearDo", &jetP4SmearDo, &b_jetP4SmearDo);
  fChain->SetBranchAddress("jetPFLooseId", &jetPFLooseId, &b_jetPFLooseId);
  fChain->SetBranchAddress("jetID", &jetID, &b_jetID);
  fChain->SetBranchAddress("jetPUID", &jetPUID, &b_jetPUID);
  fChain->SetBranchAddress("jetPUFullID", &jetPUFullID, &b_jetPUFullID);
  fChain->SetBranchAddress("jetJECUnc", &jetJECUnc, &b_jetJECUnc);
  fChain->SetBranchAddress("jetFiredTrgs", &jetFiredTrgs, &b_jetFiredTrgs);
  fChain->SetBranchAddress("jetCHF", &jetCHF, &b_jetCHF);
  fChain->SetBranchAddress("jetNHF", &jetNHF, &b_jetNHF);
  fChain->SetBranchAddress("jetCEF", &jetCEF, &b_jetCEF);
  fChain->SetBranchAddress("jetNEF", &jetNEF, &b_jetNEF);
  fChain->SetBranchAddress("jetNCH", &jetNCH, &b_jetNCH);
  fChain->SetBranchAddress("jetNNP", &jetNNP, &b_jetNNP);
  fChain->SetBranchAddress("jetMUF", &jetMUF, &b_jetMUF);
  fChain->SetBranchAddress("jetVtxPt", &jetVtxPt, &b_jetVtxPt);
  fChain->SetBranchAddress("jetVtxMass", &jetVtxMass, &b_jetVtxMass);
  fChain->SetBranchAddress("jetVtxNtrks", &jetVtxNtrks, &b_jetVtxNtrks);
  fChain->SetBranchAddress("jetVtx3DVal", &jetVtx3DVal, &b_jetVtx3DVal);
  fChain->SetBranchAddress("jetVtx3DSig", &jetVtx3DSig, &b_jetVtx3DSig);
  fChain->SetBranchAddress("nAK8Jet", &nAK8Jet, &b_nAK8Jet);
  fChain->SetBranchAddress("AK8JetPt", &AK8JetPt, &b_AK8JetPt);
  fChain->SetBranchAddress("AK8JetEn", &AK8JetEn, &b_AK8JetEn);
  fChain->SetBranchAddress("AK8JetRawPt", &AK8JetRawPt, &b_AK8JetRawPt);
  fChain->SetBranchAddress("AK8JetRawEn", &AK8JetRawEn, &b_AK8JetRawEn);
  fChain->SetBranchAddress("AK8JetEta", &AK8JetEta, &b_AK8JetEta);
  fChain->SetBranchAddress("AK8JetPhi", &AK8JetPhi, &b_AK8JetPhi);
  fChain->SetBranchAddress("AK8JetMass", &AK8JetMass, &b_AK8JetMass);
  fChain->SetBranchAddress("AK8Jet_tau1", &AK8Jet_tau1, &b_AK8Jet_tau1);
  fChain->SetBranchAddress("AK8Jet_tau2", &AK8Jet_tau2, &b_AK8Jet_tau2);
  fChain->SetBranchAddress("AK8Jet_tau3", &AK8Jet_tau3, &b_AK8Jet_tau3);
  fChain->SetBranchAddress("AK8JetCHF", &AK8JetCHF, &b_AK8JetCHF);
  fChain->SetBranchAddress("AK8JetNHF", &AK8JetNHF, &b_AK8JetNHF);
  fChain->SetBranchAddress("AK8JetCEF", &AK8JetCEF, &b_AK8JetCEF);
  fChain->SetBranchAddress("AK8JetNEF", &AK8JetNEF, &b_AK8JetNEF);
  fChain->SetBranchAddress("AK8JetNCH", &AK8JetNCH, &b_AK8JetNCH);
  fChain->SetBranchAddress("AK8JetNNP", &AK8JetNNP, &b_AK8JetNNP);
  fChain->SetBranchAddress("AK8JetMUF", &AK8JetMUF, &b_AK8JetMUF);
  fChain->SetBranchAddress("AK8Jetnconstituents", &AK8Jetnconstituents, &b_AK8Jetnconstituents);
  fChain->SetBranchAddress("AK8JetPFLooseId", &AK8JetPFLooseId, &b_AK8JetPFLooseId);
  fChain->SetBranchAddress("AK8JetPFTightLepVetoId", &AK8JetPFTightLepVetoId, &b_AK8JetPFTightLepVetoId);
  fChain->SetBranchAddress("AK8JetSoftDropMass", &AK8JetSoftDropMass, &b_AK8JetSoftDropMass);
  fChain->SetBranchAddress("AK8JetSoftDropMassCorr", &AK8JetSoftDropMassCorr, &b_AK8JetSoftDropMassCorr);
  fChain->SetBranchAddress("AK8JetPrunedMass", &AK8JetPrunedMass, &b_AK8JetPrunedMass);
  fChain->SetBranchAddress("AK8JetPrunedMassCorr", &AK8JetPrunedMassCorr, &b_AK8JetPrunedMassCorr);
  fChain->SetBranchAddress("AK8JetpfBoostedDSVBTag", &AK8JetpfBoostedDSVBTag, &b_AK8JetpfBoostedDSVBTag);
  fChain->SetBranchAddress("AK8JetDSVnewV4", &AK8JetDSVnewV4, &b_AK8JetDSVnewV4);
  fChain->SetBranchAddress("AK8JetCSV", &AK8JetCSV, &b_AK8JetCSV);
  fChain->SetBranchAddress("AK8JetJECUnc", &AK8JetJECUnc, &b_AK8JetJECUnc);
  fChain->SetBranchAddress("AK8JetL2L3corr", &AK8JetL2L3corr, &b_AK8JetL2L3corr);
  fChain->SetBranchAddress("AK8puppiPt", &AK8puppiPt, &b_AK8puppiPt);
  fChain->SetBranchAddress("AK8puppiMass", &AK8puppiMass, &b_AK8puppiMass);
  fChain->SetBranchAddress("AK8puppiEta", &AK8puppiEta, &b_AK8puppiEta);
  fChain->SetBranchAddress("AK8puppiPhi", &AK8puppiPhi, &b_AK8puppiPhi);
  fChain->SetBranchAddress("AK8puppiTau1", &AK8puppiTau1, &b_AK8puppiTau1);
  fChain->SetBranchAddress("AK8puppiTau2", &AK8puppiTau2, &b_AK8puppiTau2);
  fChain->SetBranchAddress("AK8puppiTau3", &AK8puppiTau3, &b_AK8puppiTau3);
  fChain->SetBranchAddress("AK8puppiSDL2L3corr", &AK8puppiSDL2L3corr, &b_AK8puppiSDL2L3corr);
  fChain->SetBranchAddress("AK8puppiSDMass", &AK8puppiSDMass, &b_AK8puppiSDMass);
  fChain->SetBranchAddress("AK8puppiSDMassL2L3Corr", &AK8puppiSDMassL2L3Corr, &b_AK8puppiSDMassL2L3Corr);
  if (fChain->GetBranch("AK8JetPartonID")) fChain->SetBranchAddress("AK8JetPartonID", &AK8JetPartonID, &b_AK8JetPartonID);
  if (fChain->GetBranch("AK8JetHadFlvr")) fChain->SetBranchAddress("AK8JetHadFlvr", &AK8JetHadFlvr, &b_AK8JetHadFlvr);
  if (fChain->GetBranch("AK8JetGenJetIndex")) fChain->SetBranchAddress("AK8JetGenJetIndex", &AK8JetGenJetIndex, &b_AK8JetGenJetIndex);
  if (fChain->GetBranch("AK8JetGenJetEn")) fChain->SetBranchAddress("AK8JetGenJetEn", &AK8JetGenJetEn, &b_AK8JetGenJetEn);
  if (fChain->GetBranch("AK8JetGenJetPt")) fChain->SetBranchAddress("AK8JetGenJetPt", &AK8JetGenJetPt, &b_AK8JetGenJetPt);
  if (fChain->GetBranch("AK8JetGenJetEta")) fChain->SetBranchAddress("AK8JetGenJetEta", &AK8JetGenJetEta, &b_AK8JetGenJetEta);
  if (fChain->GetBranch("AK8JetGenJetPhi")) fChain->SetBranchAddress("AK8JetGenJetPhi", &AK8JetGenJetPhi, &b_AK8JetGenJetPhi);
  if (fChain->GetBranch("AK8JetGenPartonID")) fChain->SetBranchAddress("AK8JetGenPartonID", &AK8JetGenPartonID, &b_AK8JetGenPartonID);
  if (fChain->GetBranch("AK8JetGenEn")) fChain->SetBranchAddress("AK8JetGenEn", &AK8JetGenEn, &b_AK8JetGenEn);
  if (fChain->GetBranch("AK8JetGenPt")) fChain->SetBranchAddress("AK8JetGenPt", &AK8JetGenPt, &b_AK8JetGenPt);
  if (fChain->GetBranch("AK8JetGenEta")) fChain->SetBranchAddress("AK8JetGenEta", &AK8JetGenEta, &b_AK8JetGenEta);
  if (fChain->GetBranch("AK8JetGenPhi")) fChain->SetBranchAddress("AK8JetGenPhi", &AK8JetGenPhi, &b_AK8JetGenPhi);
  if (fChain->GetBranch("AK8JetGenPartonMomID")) fChain->SetBranchAddress("AK8JetGenPartonMomID", &AK8JetGenPartonMomID, &b_AK8JetGenPartonMomID);
  if (fChain->GetBranch("AK8JetP4Smear")) fChain->SetBranchAddress("AK8JetP4Smear", &AK8JetP4Smear, &b_AK8JetP4Smear);
  if (fChain->GetBranch("AK8JetP4SmearUp")) fChain->SetBranchAddress("AK8JetP4SmearUp", &AK8JetP4SmearUp, &b_AK8JetP4SmearUp);
  if (fChain->GetBranch("AK8JetP4SmearDo")) fChain->SetBranchAddress("AK8JetP4SmearDo", &AK8JetP4SmearDo, &b_AK8JetP4SmearDo);
  fChain->SetBranchAddress("nAK8SDSJ", &nAK8SDSJ, &b_nAK8SDSJ);
  fChain->SetBranchAddress("AK8SDSJPt", &AK8SDSJPt, &b_AK8SDSJPt);
  fChain->SetBranchAddress("AK8SDSJEta", &AK8SDSJEta, &b_AK8SDSJEta);
  fChain->SetBranchAddress("AK8SDSJPhi", &AK8SDSJPhi, &b_AK8SDSJPhi);
  fChain->SetBranchAddress("AK8SDSJMass", &AK8SDSJMass, &b_AK8SDSJMass);
  fChain->SetBranchAddress("AK8SDSJE", &AK8SDSJE, &b_AK8SDSJE);
  fChain->SetBranchAddress("AK8SDSJCharge", &AK8SDSJCharge, &b_AK8SDSJCharge);
  fChain->SetBranchAddress("AK8SDSJFlavour", &AK8SDSJFlavour, &b_AK8SDSJFlavour);
  fChain->SetBranchAddress("AK8SDSJCSV", &AK8SDSJCSV, &b_AK8SDSJCSV);
  fChain->SetBranchAddress("nAK8puppiSDSJ", &nAK8puppiSDSJ, &b_nAK8puppiSDSJ);
  fChain->SetBranchAddress("AK8puppiSDSJPt", &AK8puppiSDSJPt, &b_AK8puppiSDSJPt);
  fChain->SetBranchAddress("AK8puppiSDSJEta", &AK8puppiSDSJEta, &b_AK8puppiSDSJEta);
  fChain->SetBranchAddress("AK8puppiSDSJPhi", &AK8puppiSDSJPhi, &b_AK8puppiSDSJPhi);
  fChain->SetBranchAddress("AK8puppiSDSJMass", &AK8puppiSDSJMass, &b_AK8puppiSDSJMass);
  fChain->SetBranchAddress("AK8puppiSDSJE", &AK8puppiSDSJE, &b_AK8puppiSDSJE);
  fChain->SetBranchAddress("AK8puppiSDSJCharge", &AK8puppiSDSJCharge, &b_AK8puppiSDSJCharge);
  fChain->SetBranchAddress("AK8puppiSDSJFlavour", &AK8puppiSDSJFlavour, &b_AK8puppiSDSJFlavour);
  fChain->SetBranchAddress("AK8puppiSDSJCSV", &AK8puppiSDSJCSV, &b_AK8puppiSDSJCSV);
  fChain->SetBranchAddress("nIsoTrack", &nIsoTrack, &b_nIsoTrack);
  fChain->SetBranchAddress("isoPt", &isoPt, &b_isoPt);
  fChain->SetBranchAddress("isoEta", &isoEta, &b_isoEta);
  fChain->SetBranchAddress("isoPhi", &isoPhi, &b_isoPhi);
  fChain->SetBranchAddress("isoD0", &isoD0, &b_isoD0);
  fChain->SetBranchAddress("isoDz", &isoDz, &b_isoDz);
  fChain->SetBranchAddress("isoCharge", &isoCharge, &b_isoCharge);
  fChain->SetBranchAddress("isoFromPV", &isoFromPV, &b_isoFromPV);
  fChain->SetBranchAddress("isoPdgID", &isoPdgID, &b_isoPdgID);
  fChain->SetBranchAddress("isoLeptonOverlap", &isoLeptonOverlap, &b_isoLeptonOverlap);
  fChain->SetBranchAddress("isoChIso", &isoChIso, &b_isoChIso);
  fChain->SetBranchAddress("isoChRelIso", &isoChRelIso, &b_isoChRelIso);
  fChain->SetBranchAddress("isoChMiniIso", &isoChMiniIso, &b_isoChMiniIso);
  fChain->SetBranchAddress("isoChRelMiniIso", &isoChRelMiniIso, &b_isoChRelMiniIso);
  Notify();
}

Bool_t Analyzer::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void Analyzer::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}

template <typename T>
bool Parser(const T& var, string op, double val) {
  if      (op == "eq")      {if (var == val) return true;}
  else if (op == "Neq")     {if (var != val) return true;}
  else if (op == "less")    {if (var < val)  return true;}
  else if (op == "great")   {if (var > val)  return true;}
  else if (op == "lesseq")  {if (var <= val) return true;}
  else if (op == "greateq") {if (var >= val) return true;}
  //else if (op == "andand") {if (var && val) return true;}
  //else if (op == "oror") {if (var || val) return true;}
  else if (op == "and")   {if (var&(int)val) return true;}
  else if (op == "or")    {if (var|(int)val) return true;}
  else if (op == "xor")   {if (var^(int)val) return true;}
  else cout<<"ERROR! Unknown operator type: "<<op<<endl;
  return false;
}
bool Parser_float(double var, string op, double val) {
  if      (op == "eq") {if (var == val) return true;}
  else if (op == "Neq") {if (var != val) return true;}
  else if (op == "less")  {if (var < val)  return true;}
  else if (op == "great")  {if (var > val) return true;}
  else if (op == "lesseq") {if (var <= val) return true;}
  else if (op == "greateq") {if (var >= val) return true;}
  //else if (op == "andand") {if (var && val) return true;}
  //else if (op == "oror") {if (var || val) return true;}
  else cout<<"ERROR! Unknown operator type: "<<op<<endl;
  return false;
}

Int_t Analyzer::Cut(Long64_t entry)
{
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  bool returnvalue=true;
  for (unsigned int i=0;i<_cut_variable.size();i++){
    if      (_cut_variable[i]=="HLTPho")    returnvalue*=Parser(HLTPho,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="isPVGood") returnvalue*=Parser(isPVGood,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassEleL") {returnvalue*=Parser(nPassEleL,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[1]*ele_VETOSF;}
    else if (_cut_variable[i]=="nPassEleM") {returnvalue*=Parser(nPassEleM,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[2];}
    else if (_cut_variable[i]=="nPassEleT") {returnvalue*=Parser(nPassEleT,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[3];}
    //else if (_cut_variable[i]=="nPassMuL") {returnvalue*=Parser(nPassMuL,_cut_operator[i],_cut_value[i]); if (!isData) w*=mu_SF[0]*mu_VETOSF;}
    else if (_cut_variable[i]=="nPassMuL") {returnvalue*=Parser(nPassMuL,_cut_operator[i],_cut_value[i]); if (!isData) w*=mu_SF[0];} //mu_VETOSF not yet appliead because of dubious results
    else if (_cut_variable[i]=="nPassMuM") {returnvalue*=Parser(nPassMuM,_cut_operator[i],_cut_value[i]); if (!isData) w*=mu_SF[1];}
    else if (_cut_variable[i]=="nPassMuT") {returnvalue*=Parser(nPassMuT,_cut_operator[i],_cut_value[i]); if (!isData) w*=mu_SF[2];}
    else if (_cut_variable[i]=="nPassTauL") {returnvalue*=Parser(nPassTauL,_cut_operator[i],_cut_value[i]); if (!isData) w*=tau_SF[0];}
    else if (_cut_variable[i]=="nPassTauM") {returnvalue*=Parser(nPassTauM,_cut_operator[i],_cut_value[i]); if (!isData) w*=tau_SF[1];}
    else if (_cut_variable[i]=="nPassTauT") {returnvalue*=Parser(nPassTauT,_cut_operator[i],_cut_value[i]); if (!isData) w*=tau_SF[2];}
    else if (_cut_variable[i]=="nPassIso") {returnvalue*=Parser(nPassIso,_cut_operator[i],_cut_value[i]);}
    else if (_cut_variable[i]=="nPassLepL") {returnvalue*=Parser(nPassEleL+nPassMuL+nPassTauL,_cut_operator[i],_cut_value[i]); if (!isData) {if (nPassEleL) w*=ele_SF[1]*ele_VETOSF; if (nPassMuL) w*=mu_SF[0]; if (nPassTauL) w*=tau_SF[0];}}
    else if (_cut_variable[i]=="nPassLepM") {returnvalue*=Parser(nPassEleM+nPassMuM+nPassTauM,_cut_operator[i],_cut_value[i]); if (!isData) {if (nPassEleM) w*=ele_SF[2]; if (nPassMuM) w*=mu_SF[1]; if (nPassTauM) w*=tau_SF[1];}}
    else if (_cut_variable[i]=="nPassLepT") {returnvalue*=Parser(nPassEleT+nPassMuT+nPassTauT,_cut_operator[i],_cut_value[i]); if (!isData) {if (nPassEleT) w*=ele_SF[3]; if (nPassMuT) w*=mu_SF[2]; if (nPassTauT) w*=tau_SF[2];}}
    else if (_cut_variable[i]=="nPassLepVLL") {returnvalue*=Parser(nPassEleV+nPassMuL+nPassTauL,_cut_operator[i],_cut_value[i]); if (!isData) {if (nPassEleV) w*=ele_SF[0]*ele_VETOSF; if (nPassMuL) w*=mu_SF[0]; if (nPassTauL) w*=tau_SF[0];}}
    else if (_cut_variable[i]=="nPassLepMLL") {returnvalue*=Parser(nPassEleM+nPassMuL+nPassTauL,_cut_operator[i],_cut_value[i]); if (!isData) {if (nPassEleM) w*=ele_SF[2]*ele_VETOSF; if (nPassMuL) w*=mu_SF[0]; if (nPassTauL) w*=tau_SF[0];}}
    else if (_cut_variable[i]=="nPassLepLML") {returnvalue*=Parser(nPassEleL+nPassMuM+nPassTauL,_cut_operator[i],_cut_value[i]); if (!isData) {if (nPassEleL) w*=ele_SF[1]*ele_VETOSF; if (nPassMuM) w*=mu_SF[1]; if (nPassTauL) w*=tau_SF[0];}}
    else if (_cut_variable[i]=="nPassLepLLM") {returnvalue*=Parser(nPassEleL+nPassMuL+nPassTauM,_cut_operator[i],_cut_value[i]); if (!isData) {if (nPassEleL) w*=ele_SF[1]*ele_VETOSF; if (nPassMuL) w*=mu_SF[0]; if (nPassTauM) w*=tau_SF[1];}}
    else if (_cut_variable[i]=="nPassFREleL") {returnvalue*=Parser(nPassFREleL,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[1];}
    else if (_cut_variable[i]=="nPassFREleM") {returnvalue*=Parser(nPassFREleM,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[2];}
    else if (_cut_variable[i]=="nPassFREleT") {returnvalue*=Parser(nPassFREleT,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[3];}
    else if (_cut_variable[i]=="nPassElePhoL") returnvalue*=Parser(nPassElePhoL,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassElePhoM") returnvalue*=Parser(nPassElePhoM,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassElePhoT") returnvalue*=Parser(nPassElePhoT,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassPhoL") {returnvalue*=Parser(nPassPhoL,_cut_operator[i],_cut_value[i]); if (!isData) w*=pho_SF[0];}
    else if (_cut_variable[i]=="nPassPhoM") {returnvalue*=Parser(nPassPhoM,_cut_operator[i],_cut_value[i]); if (!isData) w*=pho_SF[1];}
    else if (_cut_variable[i]=="nPassPhoT") {returnvalue*=Parser(nPassPhoT,_cut_operator[i],_cut_value[i]); if (!isData) w*=pho_SF[2];}
    else if (_cut_variable[i]=="elePt") returnvalue*=Parser_float((*elePt)[nleadEleL],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="elePtM") returnvalue*=Parser_float((*elePt)[nleadEleM],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="elePtT") returnvalue*=Parser_float((*elePt)[nleadEleT],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="eleCalibPt") returnvalue*=Parser_float((*eleCalibPt)[nleadEleL],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="eleCalibPtM") returnvalue*=Parser_float((*eleCalibPt)[nleadEleM],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="eleCalibPtT") returnvalue*=Parser_float((*eleCalibPt)[nleadEleT],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="FReleCalibPt") returnvalue*=Parser_float((*eleCalibPt)[nleadFREleL],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="FReleCalibPtM") returnvalue*=Parser_float((*eleCalibPt)[nleadFREleM],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="FReleCalibPtT") returnvalue*=Parser_float((*eleCalibPt)[nleadFREleT],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="elephoCalibPt") returnvalue*=Parser_float((*phoCalibEt)[nleadElePhoL],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="elephoCalibPtM") returnvalue*=Parser_float((*phoCalibEt)[nleadElePhoM],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="elephoCalibPtT") returnvalue*=Parser_float((*phoCalibEt)[nleadElePhoT],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="phoEt") returnvalue*=Parser_float((*phoEt)[nleadPhoL],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="phoEtM") returnvalue*=Parser_float((*phoEt)[nleadPhoM],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="phoEtT") returnvalue*=Parser_float((*phoEt)[nleadPhoT],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="phoCalibEt") returnvalue*=Parser_float((*phoCalibEt)[nleadPhoL],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="phoCalibEtM") returnvalue*=Parser_float((*phoCalibEt)[nleadPhoM],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="phoCalibEtT") returnvalue*=Parser_float((*phoCalibEt)[nleadPhoT],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="HT") returnvalue*=Parser_float(HT_after,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="EMHT") returnvalue*=Parser_float(EMHT_after,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="MT") returnvalue*=Parser_float(MT,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="ST") returnvalue*=Parser_float(ST,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="ST_G") returnvalue*=Parser_float(ST_G,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="metFilters") returnvalue*=Parser(metFilters,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="NOTmetFilters") returnvalue*= !(Parser(metFilters,_cut_operator[i],_cut_value[i]));
    else if (_cut_variable[i]=="MET") returnvalue*=Parser_float(pfMET,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="dphi_met_jet") returnvalue*=Parser_float(dphi_met_jet,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="L1prefire") returnvalue*=Parser(L1prefire,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassAK4") returnvalue*=Parser(nPassAK4,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassAK8") returnvalue*=Parser(nPassAK8,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nonHiggsJet") returnvalue*=Parser(nonHiggsJet,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcounterCSV_L") {returnvalue*=Parser(bcounterCSV[1],_cut_operator[i],_cut_value[i]); if (!isData) w*=CSV_SF_L[CSV_whichSF];}
    else if (_cut_variable[i]=="bcounterCSV_M") {returnvalue*=Parser(bcounterCSV[2],_cut_operator[i],_cut_value[i]); if (!isData) w*=CSV_SF_M[CSV_whichSF];}
    else if (_cut_variable[i]=="bcounterCSV_T") {returnvalue*=Parser(bcounterCSV[3],_cut_operator[i],_cut_value[i]); if (!isData) w*=CSV_SF_T[CSV_whichSF];}
    else if (_cut_variable[i]=="bcountercMVA_L") returnvalue*=Parser(bcountercMVA[1],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcountercMVA_M") returnvalue*=Parser(bcountercMVA[2],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcountercMVA_T") returnvalue*=Parser(bcountercMVA[3],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcounterDeep_L") returnvalue*=Parser(bcounterDeep[1],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcounterDeep_M") returnvalue*=Parser(bcounterDeep[2],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcounterDeep_T") returnvalue*=Parser(bcounterDeep[3],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcounterBDSV_L") {returnvalue*=Parser(bcounterBDSV[1],_cut_operator[i],_cut_value[i]); if (!isData) w*=BDSV_SF_L[BDSV_whichSF];}
    else if (_cut_variable[i]=="bcounterBDSV_M1") {returnvalue*=Parser(bcounterBDSV[2],_cut_operator[i],_cut_value[i]); if (!isData) w*=BDSV_SF_M1[BDSV_whichSF];}
    else if (_cut_variable[i]=="bcounterBDSV_M2") {returnvalue*=Parser(bcounterBDSV[3],_cut_operator[i],_cut_value[i]); if (!isData) w*=BDSV_SF_M2[BDSV_whichSF];}
    else if (_cut_variable[i]=="bcounterBDSV_T") {returnvalue*=Parser(bcounterBDSV[4],_cut_operator[i],_cut_value[i]); if (!isData) w*=BDSV_SF_T[BDSV_whichSF];}
    else if (_cut_variable[i]=="BDSV_selected") {
      returnvalue*=Parser(BDSV_selected,_cut_operator[i],_cut_value[i]);
      if (_fastSim) {
        if (_cut_value[i]==1) w*=BDSV_SF_L[BDSV_whichSF];
        if (_cut_value[i]==2) w*=BDSV_SF_M1[BDSV_whichSF];
        if (_cut_value[i]==3) w*=BDSV_SF_M2[BDSV_whichSF];
        if (_cut_value[i]==4) w*=BDSV_SF_T[BDSV_whichSF];
      }
    }
    else if (_cut_variable[i]=="CSV_selected") {
      returnvalue*=Parser(CSV_selected,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (_cut_value[i]==1) w*=CSV_SF_L[CSV_whichSF];
        if (_cut_value[i]==2) w*=CSV_SF_L[CSV_whichSF]*CSV_SF_L[CSV_whichSF];
      }
    }
    else if (_cut_variable[i]=="Deep_selected") {
      returnvalue*=Parser(Deep_selected,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (_cut_value[i]==1) w*=Deep_SF_L[Deep_whichSF];
        if (_cut_value[i]==2) w*=Deep_SF_L[Deep_whichSF]*Deep_SF_L[Deep_whichSF];
      }
    }
    else if (_cut_variable[i]=="sth_selected") returnvalue*=Parser(Deep_selected+BDSV_selected,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="passBtag") returnvalue*=Parser(passBtag,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="passAK4Btag1") returnvalue*=Parser(passAK4Btag1,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="passAK4Btag2") returnvalue*=Parser(passAK4Btag2,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="passHiggsMass") returnvalue*=Parser(passHiggsMass,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="passAK4HiggsMass") returnvalue*=Parser(passAK4HiggsMass,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="notAK4") returnvalue*=Parser(notAK4,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="Hbb") returnvalue*=Parser(Hbb,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="SignalHiggs") {returnvalue*=Parser(SignalHiggs,_cut_operator[i],_cut_value[i]);}
    else if (_cut_variable[i]=="mcLeptonFilter") returnvalue*=Parser(mcLeptonFilter,_cut_operator[i],_cut_value[i]);
    else {cout<<"ERROR! Unknown cut variable: "<<_cut_variable[i]<<endl; returnvalue=false;}
    if (returnvalue) {
      if (_fastSim) h_cuts->Fill(i+1,w);
      else h_cuts->Fill(i,w);
    }
    else break;
  }
  return returnvalue;
}

double Analyzer::deltaR(double phi1, double phi2, double eta1, double eta2){
  double dR=0;
  if (abs(phi1-phi2)>M_PI) dR=sqrt(pow(2*M_PI-(phi2-phi1),2)+pow(eta1-eta2,2));
  else dR=sqrt(pow(phi1-phi2,2)+pow(eta1-eta2,2));
  return dR;
}

void Analyzer::CalcBtagSF(vector<float> *v_eta, vector<float> v_pt, vector<int> *v_had, map<int,char> passCut, TEfficiency *eff_b_L, TEfficiency *eff_c_L, TEfficiency *eff_l_L, TEfficiency *eff_b_M, TEfficiency *eff_c_M, TEfficiency *eff_l_M, TEfficiency *eff_b_T, TEfficiency *eff_c_T, TEfficiency *eff_l_T, BTCalibrationReader reader_L, BTCalibrationReader reader_M, BTCalibrationReader reader_T, double (&SF_L)[3], double (&SF_M)[3], double (&SF_T)[3]){
  double p_data[3] = {1,1,1}, p_mc[3] = {1,1,1}, p_data_up[3] = {1,1,1}, p_data_do[3] = {1,1,1};
  for (map<int,char>::iterator it=passCut.begin(); it!=passCut.end(); ++it){
    BTEntry::JetFlavor FLAV;
    double mc_eff[3]={0}, eta=0, pt=0;
    eta=(*v_eta)[it->first];
    pt=v_pt[it->first];
    if (pt>=2000) pt=1999;
    if ((*v_had)[it->first]==5) {
      FLAV = BTEntry::FLAV_B;
      mc_eff[0] = eff_b_L->GetEfficiency(eff_b_L->FindFixBin(eta,pt));
      mc_eff[1] = eff_b_M->GetEfficiency(eff_b_M->FindFixBin(eta,pt));
      mc_eff[2] = eff_b_T->GetEfficiency(eff_b_T->FindFixBin(eta,pt));
    }
    else if ((*v_had)[it->first]==4) {
      FLAV = BTEntry::FLAV_C;
      mc_eff[0] = eff_c_L->GetEfficiency(eff_c_L->FindFixBin(eta,pt));
      mc_eff[1] = eff_c_M->GetEfficiency(eff_c_M->FindFixBin(eta,pt));
      mc_eff[2] = eff_c_T->GetEfficiency(eff_c_T->FindFixBin(eta,pt));
    }
    else if ((*v_had)[it->first]==0) {
      FLAV = BTEntry::FLAV_UDSG;
      mc_eff[0] = eff_l_L->GetEfficiency(eff_l_L->FindFixBin(eta,pt));
      mc_eff[1] = eff_l_M->GetEfficiency(eff_l_M->FindFixBin(eta,pt));
      mc_eff[2] = eff_l_T->GetEfficiency(eff_l_T->FindFixBin(eta,pt));
    }
    double SF[3], SF_up[3], SF_do[3];
    SF[0] = reader_L.eval_auto_bounds("central",FLAV,eta,pt);
    SF[1] = reader_M.eval_auto_bounds("central",FLAV,eta,pt);
    SF[2] = reader_T.eval_auto_bounds("central",FLAV,eta,pt);
    SF_up[0] = reader_L.eval_auto_bounds("up", FLAV, eta, pt);
    SF_do[0] = reader_L.eval_auto_bounds("down", FLAV, eta, pt);
    SF_up[1] = reader_M.eval_auto_bounds("up", FLAV, eta, pt);
    SF_do[1] = reader_M.eval_auto_bounds("down", FLAV, eta, pt);
    SF_up[2] = reader_T.eval_auto_bounds("up", FLAV, eta, pt);
    SF_do[2] = reader_T.eval_auto_bounds("down", FLAV, eta, pt);

    if (it->second == '0') {
      for (int i=0;i<3;i++){
        p_mc[i]*=(1-mc_eff[i]);
        p_data[i]*=(1-SF[i]*mc_eff[i]);
        p_data_up[i]*=(1-SF_up[i]*mc_eff[i]);
        p_data_do[i]*=(1-SF_do[i]*mc_eff[i]);
      }
    } 
    else if (it->second == 'L') {
      p_mc[0]*=mc_eff[0];
      p_data[0]*=SF[0]*mc_eff[0];
      p_data_up[0]*=SF_up[0]*mc_eff[0];
      p_data_do[0]*=SF_do[0]*mc_eff[0];
      for (int i=1;i<3;i++){
        p_mc[i]*=(1-mc_eff[i]);
        p_data[i]*=(1-SF[i]*mc_eff[i]);
        p_data_up[i]*=(1-SF_up[i]*mc_eff[i]);
        p_data_do[i]*=(1-SF_do[i]*mc_eff[i]);
      }
    } 
    else if (it->second == 'M') {
      for (int i=0;i<2;i++){
        p_mc[i]*=mc_eff[i];
        p_data[i]*=SF[i]*mc_eff[i];
        p_data_up[i]*=SF_up[i]*mc_eff[i];
        p_data_do[i]*=SF_do[i]*mc_eff[i];
      }
      p_mc[2]*=(1-mc_eff[2]);
      p_data[2]*=(1-SF[2]*mc_eff[2]);
      p_data_up[2]*=(1-SF_up[2]*mc_eff[2]);
      p_data_do[2]*=(1-SF_do[2]*mc_eff[2]);
    } 
    else if (it->second == 'T') {
      for (int i=0;i<3;i++){
        p_mc[i]*=mc_eff[i];
        p_data[i]*=SF[i]*mc_eff[i];
        p_data_up[i]*=SF_up[i]*mc_eff[i];
        p_data_do[i]*=SF_do[i]*mc_eff[i];
      }
    } 
  }
  SF_L[0] = p_data[0]/p_mc[0];
  SF_M[0] = p_data[1]/p_mc[1];
  SF_T[0] = p_data[2]/p_mc[2];
  SF_L[1] = p_data_up[0]/p_mc[0];
  SF_L[2] = p_data_do[0]/p_mc[0];
  SF_M[1] = p_data_up[1]/p_mc[1];
  SF_M[2] = p_data_do[1]/p_mc[1];
  SF_T[1] = p_data_up[2]/p_mc[2];
  SF_T[2] = p_data_do[2]/p_mc[2];
}

void Analyzer::CalcBtagSF_AK8(vector<float> *v_eta, vector<float> v_pt, vector<int> *v_had, map<int,char> passCut, TEfficiency *eff_b_L, TEfficiency *eff_b_M1, TEfficiency *eff_b_M2, TEfficiency *eff_b_T, double (&SF_L)[3], double (&SF_M1)[3], double (&SF_M2)[3], double (&SF_T)[3]){
  double p_data[4] = {1,1,1,1}, p_mc[4] = {1,1,1,1}, p_data_up[4] = {1,1,1,1}, p_data_do[4] = {1,1,1,1};
  for (map<int,char>::iterator it=passCut.begin(); it!=passCut.end(); ++it){
    double mc_eff[4]={0}, eta=0, pt=0;
    eta=(*v_eta)[it->first];
    pt=v_pt[it->first];
    if (pt>=2000) pt=1999;
    if ((*v_had)[it->first]==5) {
      mc_eff[0] = eff_b_L->GetEfficiency(eff_b_L->FindFixBin(eta,pt));
      mc_eff[1] = eff_b_M1->GetEfficiency(eff_b_M1->FindFixBin(eta,pt));
      mc_eff[2] = eff_b_M2->GetEfficiency(eff_b_M2->FindFixBin(eta,pt));
      mc_eff[3] = eff_b_T->GetEfficiency(eff_b_T->FindFixBin(eta,pt));
    }
    else {
      continue; 
    }
    double SF[4], SF_up[4], SF_do[4];
    if (pt<350) {SF[0] = 0.96; SF[1] = 0.93; SF[2] = 0.92; SF[3] = 0.85;
      SF_up[0] = SF[0]+0.03; SF_do[0] = SF[0]-0.02;
      SF_up[1] = SF[1]+0.03; SF_do[1] = SF[1]-0.02;
      SF_up[2] = SF[2]+0.03; SF_do[2] = SF[2]-0.03;
      SF_up[3] = SF[3]+0.03; SF_do[3] = SF[3]-0.03;
    }
    else if (pt<430) {SF[0] = 1.00; SF[1] = 1.01; SF[2] = 1.01; SF[3] = 0.91;
      SF_up[0] = SF[0]+0.04; SF_do[0] = SF[0]-0.03;
      SF_up[1] = SF[1]+0.03; SF_do[1] = SF[1]-0.03;
      SF_up[2] = SF[2]+0.03; SF_do[2] = SF[2]-0.04;
      SF_up[3] = SF[3]+0.03; SF_do[3] = SF[3]-0.04;
    }
    else if (pt<840) {SF[0] = 1.01; SF[1] = 0.99; SF[2] = 0.92; SF[3] = 0.91;
      SF_up[0] = SF[0]+0.02; SF_do[0] = SF[0]-0.04;
      SF_up[1] = SF[1]+0.02; SF_do[1] = SF[1]-0.04;
      SF_up[2] = SF[2]+0.03; SF_do[2] = SF[2]-0.05;
      SF_up[3] = SF[3]+0.03; SF_do[3] = SF[3]-0.04;
    }
    else {SF[0] = 1.01; SF[1] = 0.99; SF[2] = 0.92; SF[3] = 0.91;
      SF_up[0] = SF[0]+2*0.02; SF_do[0] = SF[0]-2*0.04;
      SF_up[1] = SF[1]+2*0.02; SF_do[1] = SF[1]-2*0.04;
      SF_up[2] = SF[2]+2*0.03; SF_do[2] = SF[2]-2*0.05;
      SF_up[3] = SF[3]+2*0.03; SF_do[3] = SF[3]-2*0.04;
    }
    if (it->second == '0') {
      for (int i=0;i<4;i++){
        p_mc[i]*=(1-mc_eff[i]);
        p_data[i]*=(1-SF[i]*mc_eff[i]);
        p_data_up[i]*=(1-SF_up[i]*mc_eff[i]);
        p_data_do[i]*=(1-SF_do[i]*mc_eff[i]);
      }
    } 
    else if (it->second == 'L') {
      p_mc[0]*=mc_eff[0];
      p_data[0]*=SF[0]*mc_eff[0];
      p_data_up[0]*=SF_up[0]*mc_eff[0];
      p_data_do[0]*=SF_do[0]*mc_eff[0];
      for (int i=1;i<4;i++){
        p_mc[i]*=(1-mc_eff[i]);
        p_data[i]*=(1-SF[i]*mc_eff[i]);
        p_data_up[i]*=(1-SF_up[i]*mc_eff[i]);
        p_data_do[i]*=(1-SF_do[i]*mc_eff[i]);
      }
    } 
    else if (it->second == 'M') {
      for (int i=0;i<2;i++){
        p_mc[i]*=mc_eff[i];
        p_data[i]*=SF[i]*mc_eff[i];
        p_data_up[i]*=SF_up[i]*mc_eff[i];
        p_data_do[i]*=SF_do[i]*mc_eff[i];
      }
      for (int i=2;i<4;i++){
        p_mc[i]*=(1-mc_eff[i]);
        p_data[i]*=(1-SF[i]*mc_eff[i]);
        p_data_up[i]*=(1-SF_up[i]*mc_eff[i]);
        p_data_do[i]*=(1-SF_do[i]*mc_eff[i]);
      }
    } 
    else if (it->second == 'H') {
      for (int i=0;i<3;i++){
        p_mc[i]*=mc_eff[i];
        p_data[i]*=SF[i]*mc_eff[i];
        p_data_up[i]*=SF_up[i]*mc_eff[i];
        p_data_do[i]*=SF_do[i]*mc_eff[i];
      }
      p_mc[3]*=(1-mc_eff[3]);
      p_data[3]*=(1-SF[3]*mc_eff[3]);
      p_data_up[3]*=(1-SF_up[3]*mc_eff[3]);
      p_data_do[3]*=(1-SF_do[3]*mc_eff[3]);
    } 
    else if (it->second == 'T') {
      for (int i=0;i<4;i++){
        p_mc[i]*=mc_eff[i];
        p_data[i]*=SF[i]*mc_eff[i];
        p_data_up[i]*=SF_up[i]*mc_eff[i];
        p_data_do[i]*=SF_do[i]*mc_eff[i];
      }
    } 
  }
  SF_L[0] = p_data[0]/p_mc[0];
  SF_M1[0] = p_data[1]/p_mc[1];
  SF_M2[0] = p_data[2]/p_mc[2];
  SF_T[0] = p_data[3]/p_mc[3];
  SF_L[1] = p_data_up[0]/p_mc[0];
  SF_L[2] = p_data_do[0]/p_mc[0];
  SF_M1[1] = p_data_up[1]/p_mc[1];
  SF_M1[2] = p_data_do[1]/p_mc[1];
  SF_M2[1] = p_data_up[2]/p_mc[2];
  SF_M2[2] = p_data_do[2]/p_mc[2];
  SF_T[1] = p_data_up[3]/p_mc[3];
  SF_T[2] = p_data_do[3]/p_mc[3];
}

void Analyzer::Systematics(map<string, int> systematics) {
  for (auto const& x : systematics) {
    if (x.first=="BDSV") BDSV_whichSF=x.second;
    else if (x.first=="CSV") CSV_whichSF=x.second;
    else if (x.first=="Deep") Deep_whichSF=x.second;
    else if (x.first=="AK4Smear") AK4Smear_whichSF=x.second;
    else if (x.first=="AK8Smear") AK8Smear_whichSF=x.second;
    else if (x.first=="AK4JEC") AK4jetJEC_whichSF=x.second;
    else if (x.first=="AK8JEC") AK8jetJEC_whichSF=x.second;
    else if (x.first=="phoID") phoID_whichSF=x.second;
    else if (x.first=="phoPix") phoPix_whichSF=x.second;
    else if (x.first=="eleID") eleID_whichSF=x.second;
    else if (x.first=="eleRec") eleRec_whichSF=x.second;
    else if (x.first=="muID") muID_whichSF=x.second;
    else if (x.first=="muISO") muISO_whichSF=x.second;
    else if (x.first=="tau") tau_whichSF=x.second;
    else if (x.first=="metJER") metJER_whichSF=x.second;
    else if (x.first=="metJES") metJES_whichSF=x.second;
    else if (x.first=="metUES") metUES_whichSF=x.second;
    else if (x.first=="L1prefire") L1prefire_whichSF=x.second;
    else cout<<"ERROR! Unknown systematics variable: "<<x.first<<endl;
  }
}

void Analyzer::Sort(vector<pair<int,int>> &v, vector<float> *b, vector<float> *bb, unsigned int operation){
  for (unsigned int i=0;i<v.size();i++){
  pair<int,int> temp;
    for (unsigned int j=v.size()-1;j>i;j--){
      float DeepCSVTag_1j=(*b)[v.at(j).first]+(*bb)[v.at(j).first];
      float DeepCSVTag_2j=(*b)[v.at(j).second]+(*bb)[v.at(j).second];
      float DeepCSVTag_1j2=(*b)[v.at(j-1).first]+(*bb)[v.at(j-1).first];
      float DeepCSVTag_2j2=(*b)[v.at(j-1).second]+(*bb)[v.at(j-1).second];
      float value_j=0, value_j2=0;
      switch (operation) {
        case 0 : {value_j=DeepCSVTag_1j+DeepCSVTag_2j; value_j2=DeepCSVTag_1j2+DeepCSVTag_2j2;}
                 break;
        case 1 : {value_j=DeepCSVTag_1j*DeepCSVTag_2j; value_j2=DeepCSVTag_1j2*DeepCSVTag_2j2;}
                 break;
      }
      if (value_j>value_j2){
        temp=v[j-1];
        v[j-1]=v[j];
        v[j]=temp;
      }
    }
  }
}
void Analyzer::SelectAK4(vector<pair<int,int>> v, vector<float> *eta, vector<float> *phi, vector<float> *b, vector<float> *bb, vector<float> en, vector<float> pt, vector<int> ak4_hjets, vector<bool> &ak4selected, vector<int> &ak4trueselected){
  for (auto i : v){
    TLorentzVector bjet1, bjet2;
    bjet1.SetPtEtaPhiE(pt[i.first],(*eta)[i.first],(*phi)[i.first],en[i.first]);
    bjet2.SetPtEtaPhiE(pt[i.second],(*eta)[i.second],(*phi)[i.second],en[i.second]);
    double mass=(bjet1+bjet2).M();
    float DeepCSVTag_1=(*b)[i.first]+(*bb)[i.first];
    //float DeepCSVTag_2=(*b)[i.second]+(*bb)[i.second];
    //if (mass>70 && mass<200 && DeepCSVTag_1>BtagDeepWP[0] && DeepCSVTag_2>BtagDeepWP[0]) {
    if (mass>70 && mass<200 && DeepCSVTag_1>BtagDeepWP[0]) {
      ak4selected.push_back(1); int temp=0;
      for (auto j : ak4_hjets) if (j==i.first || j==i.second) temp++;
      ak4trueselected.push_back(temp);
    }
    else {ak4selected.push_back(0);ak4trueselected.push_back(0);}
  }
}

void Analyzer::FillAK4tagging(vector<bool> ak4selected, vector<int> ak4trueselected, bool (&MassBtagAK4)[6], int (&true_higgsak4jet)[7]){
  for (unsigned int i=0;i<ak4selected.size();i++) {
    if (ak4selected[i]) {
      if (i==0) for (int j=0;j<6;j++) MassBtagAK4[j]=1;
      else if (i==1) for (int j=1;j<6;j++) MassBtagAK4[j]=1;
      else if (i==2) for (int j=2;j<6;j++) MassBtagAK4[j]=1;
      else if (i==3) for (int j=3;j<6;j++) MassBtagAK4[j]=1;
      else if (i==4) for (int j=4;j<6;j++) MassBtagAK4[j]=1;
      else MassBtagAK4[5]=1;
      if (ak4trueselected[i]) {
        if (i==0) for (int j=1;j<7;j++) true_higgsak4jet[j]=ak4trueselected[i];
        else if (i==1) for (int j=2;j<7;j++) true_higgsak4jet[j]=ak4trueselected[i];
        else if (i==2) for (int j=3;j<7;j++) true_higgsak4jet[j]=ak4trueselected[i];
        else if (i==3) for (int j=4;j<7;j++) true_higgsak4jet[j]=ak4trueselected[i];
        else if (i==4) for (int j=5;j<7;j++) true_higgsak4jet[j]=ak4trueselected[i];
        else true_higgsak4jet[6]=ak4trueselected[i];
      }
    }
  }
}

map<string,string> _cut_list = {{"HLTPho","photon triggers"},
  {"isPVGood","Presence of any good vertices, 0 or 1"},
  {"nPassEleL","number of loose electrons"},
  {"nPassEleM","number of medium electrons"},
  {"nPassEleT","number of tight electrons"},
  {"nPassMuL","number of loose muons"},
  {"nPassMuM","number of medium muons"},
  {"nPassMuT","number of tight muons"},
  {"nPassTauL","number of loose taus"},
  {"nPassTauM","number of medium taus"},
  {"nPassTauT","number of tight taus"},
  {"nPassLepL","number of loose leptons (e+mu+tau)"},
  {"nPassLepM","number of medium leptons (e+mu+tau)"},
  {"nPassLepT","number of tight leptons (e+mu+tau)"},
  {"nPassLepVLL","number of veto e + loose mu + loose tau"},
  {"nPassLepMLL","number of medium e + loose mu + loose tau"},
  {"nPassLepLML","number of loose e + medium mu + loose tau"},
  {"nPassLepLLM","number of loose e + loose mu + medium tau"},
  {"nPassIso","number of isolated tracks"},
  {"nPassFREleL","number of loose FRele (no overlap removal with photons)"},
  {"nPassFREleM","number of medium FRele (no overlap removal with photons)"},
  {"nPassFREleT","number of tight FRele (no overlap removal with photons)"},
  {"nPassElePhoL","number of loose elephotons (electrons as inverted pixelseed photons)"},
  {"nPassElePhoM","number of medium elephotons (electrons as inverted pixelseed photons)"},
  {"nPassElePhoT","number of tight elephotons (electrons as inverted pixelseed photons)"},
  {"nPassPhoL","number of loose photons"},
  {"nPassPhoM","number of medium photons"},
  {"nPassPhoT","number of tight photons"},
  {"elePt","Pt of leading loose electron"},
  {"elePtM","Pt of leading medium electron"},
  {"elePtT","Pt of leading tight electron"},
  {"FReleCalibPt","CalibPt of leading loose FRelectron"},
  {"FReleCalibPtM","CalibPt of leading medium FRelectron"},
  {"FReleCalibPtT","CalibPt of leading tight FRelectron"},
  {"eleCalibPt","CalibPt of leading loose electron"},
  {"eleCalibPtM","CalibPt of leading medium electron"},
  {"eleCalibPtT","CalibPt of leading tight electron"},
  {"elephoCalibPt","CalibPt of leading loose electronphoton"},
  {"elephoCalibPtM","CalibPt of leading medium electronphoton"},
  {"elephoCalibPtT","CalibPt of leading tight electronphoton"},
  {"phoEt","Et of leading loose photon"},
  {"phoEtM","Et of leading medium photon"},
  {"phoEtT","Et of leading tight photon"},
  {"phoCalibEt","CalibEt of leading loose photon"},
  {"phoCalibEtM","CalibEt of leading medium photon"},
  {"phoCalibEtT","CalibEt of leading tight photon"},
  {"HT","pt sum of loose jets"},
  {"EMHT","HT + Et of loose photons"},
  {"MT","invariant mass of leading loose photon and MET"},
  {"ST","HT+MET+Et of loose photons"},
  {"ST_G","MET+Et of loose photons"},
  {"metFilters","metFilters"},
  {"NOTmetFilters","Inverse of metFilters"},
  {"MET","pfMET"},
  {"dphi_met_jet","Dphi of met and nearest jet/photon with pt>100"},
  {"L1prefire","True if event could be affected by L1prefire"},
  {"nPassAK4","number of loose ak4 jets"},
  {"nPassAK8","number of loose ak8 jets"},
  {"nonHiggsJet","number of loose ak4 jets which are not Higgs candidates"},
  {"bcounterCSV_L","number of loose CSV btagged jets"},
  {"bcounterCSV_M","number of medium CSV btagged jets"},
  {"bcounterCSV_T","number of tight CSV btagged jets"},
  {"bcountercMVA_L","number of loose cMVA btagged jets"},
  {"bcountercMVA_M","number of medium cMVA btagged jets"},
  {"bcountercMVA_T","number of tight cMVA btagged jets"},
  {"bcounterDeep_L","number of loose Deep btagged jets"},
  {"bcounterDeep_M","number of medium Deep btagged jets"},
  {"bcounterDeep_T","number of tight Deep btagged jets"},
  {"bcounterBDSV_L","number of loose BDSV btagged jets"},
  {"bcounterBDSV_M1","number of medium 1 BDSV btagged jets"},
  {"bcounterBDSV_M2","number of medium 2 BDSV btagged jets"},
  {"bcounterBDSV_T","number of tight BDSV btagged jets"},
  {"BDSV_selected","BDSV btag (0-Nobtag, 1-loose, 2-medium1, ...) of the higgs candidate ak8jet"},
  {"CSV_selected","CSV btag (0-Nobtag, 1-1 loosebtag, 2-2 loose btag) of the higgs candidate ak4jets"},
  {"Deep_selected","Deep btag (0-Nobtag, 1-1 loosebtag, 2-2 loose btag) of the higgs candidate ak4jets"},
  {"sth_selected","Deep_selected+BDSV_selected"},
  {"passBtag","Higgs candidate ak8jet passes medium btag"},
  {"passAK4Btag1","Higgs candidate 1st ak4jet passes loose btag"},
  {"passAK4Btag2","Higgs candidate 2nd ak4jet passes loose btag"},
  {"passHiggsMass","At least 1 ak8jet exist with mass 70 to 200GeV"},
  {"passAK4HiggsMass","At least 1 pair of ak4jets exist with mass 70 to 200GeV"},
  {"notAK4","True if 2AK4 Higgs candidate bjets are NOT found."},
  {"Hbb","1 detectable (bquark pt>30, eta<2.4) Higgs to bb found in the event (only for Signal...)"},
  {"SignalHiggs","Neutralinos decay to 0,1 or 2 Higgs. Cut on number of Higgs bosons."},
  {"mcLeptonFilter","True if MC truth lepton was present in the event"}};

bool CompareCuts(vector<string> input_cuts){
  for (auto i : input_cuts) {
    bool match=false;
    for (auto const& j : _cut_list) {
      if (i == j.first) {match=true; break;}
    }
    if (!match) {cout<<"ERROR! Unkown cut variable "<<i<<"\nPlease run ./Analyzer -c to see available cuts. Exiting..."<<endl; return 0;}
  }
  return 1;
}

void PrintCuts(){
  cout<<"Printing out available cut variables:"<<endl;
  for (auto const& i : _cut_list) cout<<i.first<<"\t"<<i.second<<endl;
  cout<<"Exiting..."<<endl;
}

void PrintHelp(){
  cout<<"\nHow to use Analyzer?"<<endl;
  cout<<"Options:"<<endl;
  cout<<"-o outname \t\t Output filename will be set: histos/Analyzer_histos_+outname"<<endl;
  cout<<"-i inputfile1 inputfile2 ... \t\t Inputfiles"<<endl;
  cout<<"-b bname \t\t Btag efficiency file location and name (needed only for MC)"<<endl;
  cout<<"-p pname \t\t Data PileUp file location and name"<<endl;
  cout<<"-f \t\t Turn on FastSim option (for MC)"<<endl;
  cout<<"-F 1 or 2\t\t Turn on FakeRate weights. 1->for electrons 2->\"pixelseed\" electrons. Needs input file \"input/FakeRate_EGamma.root\""<<endl;
  cout<<"-s \t\t Turn on \"signalstudy\" option, which fills MC-truth histos"<<endl;
  cout<<"-q \t\t Quiet option, only errors are printed"<<endl;
  cout<<"-S \t\t SignalScan run. Use only for T5qqqqHG MC!"<<endl;
  cout<<"-C \t\t Counts and prints out T5qqqqHg signal events for each mass point"<<endl;
  cout<<"-h \t\t Print out this help"<<endl;
  cout<<"-c \t\t Print out available cut variables"<<endl;
  cout<<"-t x \t\t Test running only on \"x\" number of events. (default is x=1000)"<<endl;
  cout<<"--lept \t\t set lepton pt cut for e/m/t"<<endl;
  cout<<"FORMAT:\n--lept e 10 m 5 t 20"<<endl;
  cout<<"--syst \t\t run with +- systematics settings"<<endl;
  cout<<"FORMAT:\n--syst systematics_type 1 systematics_type 2 ..."<<endl;
  cout<<"The number meaning: 1 = upper, 2 = lower\n"<<endl;
  cout<<"--cuts \t\t Run on specified cuts, otherwise hardcoded cuts"<<endl;
  cout<<"\nHow to set cuts?"<<endl;
  cout<<"Cuts are always set in 3 parts: variable operator value"<<endl;
  cout<<"FORMAT:\n--cuts cut_variable1 cut_operator1 cut_value1 cut_variable2 cut_operator2 cut_value2 ..."<<endl;
  cout<<"Operators can be the following strings:"<<endl;
  cout<<"eq\tWhich is == "<<endl; 
  cout<<"Neq\tWhich is != "<<endl; 
  cout<<"less\tWhich is < "<<endl; 
  cout<<"great\tWhich is > "<<endl; 
  cout<<"lesseq\tWhich is <= "<<endl; 
  cout<<"greateq\tWhich is >= "<<endl; 
  cout<<"and\tWhich is & "<<endl; 
  cout<<"or\tWhich is | "<<endl; 
  cout<<"xor\tWhich is ^ "<<endl;
  cout<<"\nExamples:"<<endl;
  cout<<"./Analyzer -i /foo/bar/ggntuple_data.root -o test.root --cuts HLTPho and 4096 nPassPhoL great 0 phoCalibEt great 175"<<endl;
  cout<<"./Analyzer -i /foo/bar/ggntuple_mc.root -o test.root -b /foo/bar/ggntuple_mc_BTagEff.root --cuts HLTPho and 4096 nPassPhoL great 0 phoCalibEt great 175"<<endl;
  cout<<"NOTE: if you want to cut on object's (electron, photon, ...) variable (Pt, Et, ...) first cut on the # of object itself!"<<endl;
  cout<<"E.g.: --cuts phoCalibEtM great 175\t might BREAK the code! (if there's an event with no photons in ntuple)"<<endl;
  cout<<"Instead use: --cuts nPassPhoM great 0 phoCalibEtM great 175\t"<<endl;
  cout<<"\nHave fun!"<<endl;
}

#endif // #ifdef Analyzer_cxx
