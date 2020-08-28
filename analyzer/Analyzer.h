//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Sep  3 16:34:46 2019 by ROOT version 6.14/04
// from TTree Events/Events
// found on file: 88877510-EB32-DD4C-ACAB-A8B99C65E6A3.root
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
#include "EgammaReader.h"

#ifndef Analyzer_h
#define Analyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <TGraph.h>

using namespace std;

// Header file for the classes stored in the TTree if any.

class Analyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   Float_t         CaloMET_phi;
   Float_t         CaloMET_pt;
   Float_t         CaloMET_sumEt;
   Float_t         ChsMET_phi;
   Float_t         ChsMET_pt;
   Float_t         ChsMET_sumEt;
   UInt_t          nCorrT1METJet;
   Float_t         CorrT1METJet_area[99];   //[nCorrT1METJet]
   Float_t         CorrT1METJet_eta[99];   //[nCorrT1METJet]
   Float_t         CorrT1METJet_muonSubtrFactor[99];   //[nCorrT1METJet]
   Float_t         CorrT1METJet_phi[99];   //[nCorrT1METJet]
   Float_t         CorrT1METJet_rawPt[99];   //[nCorrT1METJet]
   UInt_t          nElectron;
   Float_t         Electron_deltaEtaSC[99];   //[nElectron]
   Float_t         Electron_dr03EcalRecHitSumEt[99];   //[nElectron]
   Float_t         Electron_dr03HcalDepth1TowerSumEt[99];   //[nElectron]
   Float_t         Electron_dr03TkSumPt[99];   //[nElectron]
   Float_t         Electron_dr03TkSumPtHEEP[99];   //[nElectron]
   Float_t         Electron_dxy[99];   //[nElectron]
   Float_t         Electron_dxyErr[99];   //[nElectron]
   Float_t         Electron_dz[99];   //[nElectron]
   Float_t         Electron_dzErr[99];   //[nElectron]
   Float_t         Electron_eCorr[99];   //[nElectron]
   Float_t         Electron_eInvMinusPInv[99];   //[nElectron]
   Float_t         Electron_energyErr[99];   //[nElectron]
   Float_t         Electron_eta[99];   //[nElectron]
   Float_t         Electron_hoe[99];   //[nElectron]
   Float_t         Electron_ip3d[99];   //[nElectron]
   Float_t         Electron_jetPtRelv2[99];   //[nElectron]
   Float_t         Electron_jetRelIso[99];   //[nElectron]
   Float_t         Electron_mass[99];   //[nElectron]
   Float_t         Electron_miniPFRelIso_all[99];   //[nElectron]
   Float_t         Electron_miniPFRelIso_chg[99];   //[nElectron]
   Float_t         Electron_mvaFall17V1Iso[99];   //[nElectron]
   Float_t         Electron_mvaFall17V1noIso[99];   //[nElectron]
   Float_t         Electron_mvaFall17V2Iso[99];   //[nElectron]
   Float_t         Electron_mvaFall17V2noIso[99];   //[nElectron]
   Float_t         Electron_mvaSpring16GP[99];   //[nElectron]
   Float_t         Electron_mvaSpring16HZZ[99];   //[nElectron]
   Float_t         Electron_pfRelIso03_all[99];   //[nElectron]
   Float_t         Electron_pfRelIso03_chg[99];   //[nElectron]
   Float_t         Electron_phi[99];   //[nElectron]
   Float_t         Electron_pt[99];   //[nElectron]
   Float_t         Electron_r9[99];   //[nElectron]
   Float_t         Electron_sieie[99];   //[nElectron]
   Float_t         Electron_sip3d[99];   //[nElectron]
   Float_t         Electron_mvaTTH[99];   //[nElectron]
   Int_t           Electron_charge[99];   //[nElectron]
   Int_t           Electron_cutBased[99];   //[nElectron]
   Int_t           Electron_cutBased_Fall17_V1[99];   //[nElectron]
   Int_t           Electron_cutBased_HLTPreSel[99];   //[nElectron]
   Int_t           Electron_cutBased_Spring15[99];   //[nElectron]
   Int_t           Electron_cutBased_Sum16[99];   //[nElectron]
   Int_t           Electron_jetIdx[99];   //[nElectron]
   Int_t           Electron_pdgId[99];   //[nElectron]
   Int_t           Electron_photonIdx[99];   //[nElectron]
   Int_t           Electron_tightCharge[99];   //[nElectron]
   Int_t           Electron_vidNestedWPBitmap[99];   //[nElectron]
   Int_t           Electron_vidNestedWPBitmapSpring15[99];   //[nElectron]
   Int_t           Electron_vidNestedWPBitmapSum16[99];   //[nElectron]
   Bool_t          Electron_convVeto[99];   //[nElectron]
   Bool_t          Electron_cutBased_HEEP[99];   //[nElectron]
   Bool_t          Electron_isPFcand[99];   //[nElectron]
   UChar_t         Electron_lostHits[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V1Iso_WP80[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V1Iso_WP90[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V1Iso_WPL[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V1noIso_WP80[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V1noIso_WP90[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V1noIso_WPL[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V2Iso_WP80[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V2Iso_WP90[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V2Iso_WPL[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V2noIso_WP80[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V2noIso_WP90[99];   //[nElectron]
   Bool_t          Electron_mvaFall17V2noIso_WPL[99];   //[nElectron]
   Bool_t          Electron_mvaSpring16GP_WP80[99];   //[nElectron]
   Bool_t          Electron_mvaSpring16GP_WP90[99];   //[nElectron]
   Bool_t          Electron_mvaSpring16HZZ_WPL[99];   //[nElectron]
   UChar_t         Electron_seedGain[99];   //[nElectron]
   UInt_t          nFatJet;
   Float_t         FatJet_area[99];   //[nFatJet]
   Float_t         FatJet_btagCMVA[99];   //[nFatJet]
   Float_t         FatJet_btagCSVV2[99];   //[nFatJet]
   Float_t         FatJet_btagDDBvL[99];   //[nFatJet]
   Float_t         FatJet_btagDDCvB[99];   //[nFatJet]
   Float_t         FatJet_btagDDCvL[99];   //[nFatJet]
   Float_t         FatJet_btagDeepB[99];   //[nFatJet]
   Float_t         FatJet_btagHbb[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_H4qvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_HbbvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_TvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_WvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_ZHbbvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_ZHccvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_ZbbvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_ZvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_bbvsLight[99];   //[nFatJet]
   Float_t         FatJet_deepTagMD_ccvsLight[99];   //[nFatJet]
   Float_t         FatJet_deepTag_H[99];   //[nFatJet]
   Float_t         FatJet_deepTag_QCD[99];   //[nFatJet]
   Float_t         FatJet_deepTag_QCDothers[99];   //[nFatJet]
   Float_t         FatJet_deepTag_TvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTag_WvsQCD[99];   //[nFatJet]
   Float_t         FatJet_deepTag_ZvsQCD[99];   //[nFatJet]
   Float_t         FatJet_eta[99];   //[nFatJet]
   Float_t         FatJet_mass[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop_nom[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop_jerUp[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop_jerDown[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop_jesTotalUp[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop_jesTotalDown[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop_jmrUp[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop_jmrDown[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop_jmsUp[99];   //[nFatJet]
   Float_t         FatJet_msoftdrop_jmsDown[99];   //[nFatJet]
   Float_t         FatJet_n2b1[99];   //[nFatJet]
   Float_t         FatJet_n3b1[99];   //[nFatJet]
   Float_t         FatJet_phi[99];   //[nFatJet]
   Float_t         FatJet_pt[99];   //[nFatJet]
   Float_t         FatJet_pt_nom[99];   //[nJet]
   Float_t         FatJet_pt_jerUp[99];   //[nJet]
   Float_t         FatJet_pt_jerDown[99];   //[nJet]
   Float_t         FatJet_pt_jesTotalUp[99];   //[nJet]
   Float_t         FatJet_pt_jesTotalDown[99];   //[nJet]
   Float_t         FatJet_rawFactor[99];   //[nFatJet]
   Float_t         FatJet_tau1[99];   //[nFatJet]
   Float_t         FatJet_tau2[99];   //[nFatJet]
   Float_t         FatJet_tau3[99];   //[nFatJet]
   Float_t         FatJet_tau4[99];   //[nFatJet]
   Int_t           FatJet_jetId[99];   //[nFatJet]
   Int_t           FatJet_subJetIdx1[99];   //[nFatJet]
   Int_t           FatJet_subJetIdx2[99];   //[nFatJet]
   UInt_t          nGenJetAK8;
   Float_t         GenJetAK8_eta[99];   //[nGenJetAK8]
   Float_t         GenJetAK8_mass[99];   //[nGenJetAK8]
   Float_t         GenJetAK8_phi[99];   //[nGenJetAK8]
   Float_t         GenJetAK8_pt[99];   //[nGenJetAK8]
   UInt_t          nGenJet;
   Float_t         GenJet_eta[99];   //[nGenJet]
   Float_t         GenJet_mass[99];   //[nGenJet]
   Float_t         GenJet_phi[99];   //[nGenJet]
   Float_t         GenJet_pt[99];   //[nGenJet]
   UInt_t          nGenPart;
   Float_t         GenPart_eta[999];   //[nGenPart]
   Float_t         GenPart_mass[999];   //[nGenPart]
   Float_t         GenPart_phi[999];   //[nGenPart]
   Float_t         GenPart_pt[999];   //[nGenPart]
   Int_t           GenPart_genPartIdxMother[999];   //[nGenPart]
   Int_t           GenPart_pdgId[999];   //[nGenPart]
   Int_t           GenPart_status[999];   //[nGenPart]
   Int_t           GenPart_statusFlags[999];   //[nGenPart]
   UInt_t          nSubGenJetAK8;
   Float_t         SubGenJetAK8_eta[99];   //[nSubGenJetAK8]
   Float_t         SubGenJetAK8_mass[99];   //[nSubGenJetAK8]
   Float_t         SubGenJetAK8_phi[99];   //[nSubGenJetAK8]
   Float_t         SubGenJetAK8_pt[99];   //[nSubGenJetAK8]
   Float_t         Generator_binvar;
   Float_t         Generator_scalePDF;
   Float_t         Generator_weight;
   Float_t         Generator_x1;
   Float_t         Generator_x2;
   Float_t         Generator_xpdf1;
   Float_t         Generator_xpdf2;
   Int_t           Generator_id1;
   Int_t           Generator_id2;
   UInt_t          nGenVisTau;
   Float_t         GenVisTau_eta[99];   //[nGenVisTau]
   Float_t         GenVisTau_mass[99];   //[nGenVisTau]
   Float_t         GenVisTau_phi[99];   //[nGenVisTau]
   Float_t         GenVisTau_pt[99];   //[nGenVisTau]
   Int_t           GenVisTau_charge[99];   //[nGenVisTau]
   Int_t           GenVisTau_genPartIdxMother[99];   //[nGenVisTau]
   Int_t           GenVisTau_status[99];   //[nGenVisTau]
   Float_t         genWeight;
   Float_t         puWeight;
   Float_t         puWeightUp;
   Float_t         puWeightDown;
   UInt_t          nPSWeight;
   Float_t         PSWeight[99];   //[nPSWeight]
   UInt_t          nIsoTrack;
   Float_t         IsoTrack_dxy[99];   //[nIsoTrack]
   Float_t         IsoTrack_dz[99];   //[nIsoTrack]
   Float_t         IsoTrack_eta[99];   //[nIsoTrack]
   Float_t         IsoTrack_pfRelIso03_all[99];   //[nIsoTrack]
   Float_t         IsoTrack_pfRelIso03_chg[99];   //[nIsoTrack]
   Float_t         IsoTrack_phi[99];   //[nIsoTrack]
   Float_t         IsoTrack_pt[99];   //[nIsoTrack]
   Float_t         IsoTrack_miniPFRelIso_all[99];   //[nIsoTrack]
   Float_t         IsoTrack_miniPFRelIso_chg[99];   //[nIsoTrack]
   Int_t           IsoTrack_fromPV[99];   //[nIsoTrack]
   Int_t           IsoTrack_pdgId[99];   //[nIsoTrack]
   Bool_t          IsoTrack_isHighPurityTrack[99];   //[nIsoTrack]
   Bool_t          IsoTrack_isPFcand[99];   //[nIsoTrack]
   Bool_t          IsoTrack_isFromLostTrack[99];   //[nIsoTrack]
   UInt_t          nJet;
   Float_t         Jet_area[99];   //[nJet]
   Float_t         Jet_btagCMVA[99];   //[nJet]
   Float_t         Jet_btagCSVV2[99];   //[nJet]
   Float_t         Jet_btagDeepB[99];   //[nJet]
   Float_t         Jet_btagDeepC[99];   //[nJet]
   Float_t         Jet_btagDeepFlavB[99];   //[nJet]
   Float_t         Jet_btagDeepFlavC[99];   //[nJet]
   Float_t         Jet_chEmEF[99];   //[nJet]
   Float_t         Jet_chHEF[99];   //[nJet]
   Float_t         Jet_eta[99];   //[nJet]
   Float_t         Jet_jercCHF[99];   //[nJet]
   Float_t         Jet_jercCHPUF[99];   //[nJet]
   Float_t         Jet_mass[99];   //[nJet]
   Float_t         Jet_mass_nom[99];//[nJet]
   Float_t         Jet_mass_jerUp[99];   //[nJet]
   Float_t         Jet_mass_jerDown[99];  //[nJet]
   Float_t         Jet_mass_jesTotalUp[99];   //[nJet]
   Float_t         Jet_mass_jesTotalDown[99];   //[nJet]
   Float_t         Jet_muEF[99];   //[nJet]
   Float_t         Jet_muonSubtrFactor[99];   //[nJet]
   Float_t         Jet_neEmEF[99];   //[nJet]
   Float_t         Jet_neHEF[99];   //[nJet]
   Float_t         Jet_phi[99];   //[nJet]
   Float_t         Jet_pt[99];   //[nJet]
   Float_t         Jet_pt_nom[99];   //[nJet]
   Float_t         Jet_pt_raw[99];   //[nJet]
   Float_t         Jet_pt_jerUp[99];   //[nJet]
   Float_t         Jet_pt_jerDown[99];   //[nJet]
   Float_t         Jet_pt_jesTotalUp[99];   //[nJet]
   Float_t         Jet_pt_jesTotalDown[99];   //[nJet]
   Float_t         Jet_qgl[99];   //[nJet]
   Float_t         Jet_rawFactor[99];   //[nJet]
   Float_t         Jet_bRegCorr[99];   //[nJet]
   Float_t         Jet_bRegRes[99];   //[nJet]
   Int_t           Jet_electronIdx1[99];   //[nJet]
   Int_t           Jet_electronIdx2[99];   //[nJet]
   Int_t           Jet_jetId[99];   //[nJet]
   Int_t           Jet_muonIdx1[99];   //[nJet]
   Int_t           Jet_muonIdx2[99];   //[nJet]
   Int_t           Jet_nConstituents[99];   //[nJet]
   Int_t           Jet_nElectrons[99];   //[nJet]
   Int_t           Jet_nMuons[99];   //[nJet]
   Int_t           Jet_puId[99];   //[nJet]
   Float_t         L1PreFiringWeight_Dn;
   Float_t         L1PreFiringWeight_Nom;
   Float_t         L1PreFiringWeight_Up;
   Float_t         GenMET_phi;
   Float_t         GenMET_pt;
   Float_t         MET_MetUnclustEnUpDeltaX;
   Float_t         MET_MetUnclustEnUpDeltaY;
   Float_t         MET_covXX;
   Float_t         MET_covXY;
   Float_t         MET_covYY;
   Float_t         MET_phi;
   Float_t         MET_phi_nom;
   Float_t         MET_phi_jer;
   Float_t         MET_phi_jerUp;
   Float_t         MET_phi_jerDown;
   Float_t         MET_phi_jesTotalUp;
   Float_t         MET_phi_jesTotalDown;
   Float_t         MET_phi_unclustEnUp;
   Float_t         MET_phi_unclustEnDown;
   Float_t         MET_pt;
   Float_t         MET_pt_nom;
   Float_t         MET_pt_jer;
   Float_t         MET_pt_jerUp;
   Float_t         MET_pt_jerDown;
   Float_t         MET_pt_jesTotalUp;
   Float_t         MET_pt_jesTotalDown;
   Float_t         MET_pt_unclustEnUp;
   Float_t         MET_pt_unclustEnDown;
   Float_t         MET_significance;
   Float_t         MET_sumEt;
   Float_t         METFixEE2017_MetUnclustEnUpDeltaX;
   Float_t         METFixEE2017_MetUnclustEnUpDeltaY;
   Float_t         METFixEE2017_covXX;
   Float_t         METFixEE2017_covXY;
   Float_t         METFixEE2017_covYY;
   Float_t         METFixEE2017_phi;
   Float_t         METFixEE2017_phi_nom;
   Float_t         METFixEE2017_phi_jer;
   Float_t         METFixEE2017_phi_jerUp;
   Float_t         METFixEE2017_phi_jerDown;
   Float_t         METFixEE2017_phi_jesTotalUp;
   Float_t         METFixEE2017_phi_jesTotalDown;
   Float_t         METFixEE2017_phi_unclustEnUp;
   Float_t         METFixEE2017_phi_unclustEnDown;
   Float_t         METFixEE2017_pt;
   Float_t         METFixEE2017_pt_nom;
   Float_t         METFixEE2017_pt_jer;
   Float_t         METFixEE2017_pt_jerUp;
   Float_t         METFixEE2017_pt_jerDown;
   Float_t         METFixEE2017_pt_jesTotalUp;
   Float_t         METFixEE2017_pt_jesTotalDown;
   Float_t         METFixEE2017_pt_unclustEnUp;
   Float_t         METFixEE2017_pt_unclustEnDown;
   Float_t         METFixEE2017_significance;
   Float_t         METFixEE2017_sumEt;
   UInt_t          nMuon;
   Float_t         Muon_dxy[99];   //[nMuon]
   Float_t         Muon_dxyErr[99];   //[nMuon]
   Float_t         Muon_dz[99];   //[nMuon]
   Float_t         Muon_dzErr[99];   //[nMuon]
   Float_t         Muon_eta[99];   //[nMuon]
   Float_t         Muon_ip3d[99];   //[nMuon]
   Float_t         Muon_jetPtRelv2[99];   //[nMuon]
   Float_t         Muon_jetRelIso[99];   //[nMuon]
   Float_t         Muon_mass[99];   //[nMuon]
   Float_t         Muon_miniPFRelIso_all[99];   //[nMuon]
   Float_t         Muon_miniPFRelIso_chg[99];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[99];   //[nMuon]
   Float_t         Muon_pfRelIso03_chg[99];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[99];   //[nMuon]
   Float_t         Muon_phi[99];   //[nMuon]
   Float_t         Muon_pt[99];   //[nMuon]
   Float_t         Muon_ptErr[99];   //[nMuon]
   Float_t         Muon_segmentComp[99];   //[nMuon]
   Float_t         Muon_sip3d[99];   //[nMuon]
   Float_t         Muon_tkRelIso[99];   //[nMuon]
   Float_t         Muon_tunepRelPt[99];   //[nMuon]
   Float_t         Muon_mvaLowPt[99];   //[nMuon]
   Float_t         Muon_mvaTTH[99];   //[nMuon]
   Int_t           Muon_charge[99];   //[nMuon]
   Int_t           Muon_jetIdx[99];   //[nMuon]
   Int_t           Muon_nStations[99];   //[nMuon]
   Int_t           Muon_nTrackerLayers[99];   //[nMuon]
   Int_t           Muon_pdgId[99];   //[nMuon]
   Int_t           Muon_tightCharge[99];   //[nMuon]
   UChar_t         Muon_highPtId[99];   //[nMuon]
   Bool_t          Muon_inTimeMuon[99];   //[nMuon]
   Bool_t          Muon_isGlobal[99];   //[nMuon]
   Bool_t          Muon_isPFcand[99];   //[nMuon]
   Bool_t          Muon_isTracker[99];   //[nMuon]
   Bool_t          Muon_looseId[99];   //[nMuon]
   Bool_t          Muon_mediumId[99];   //[nMuon]
   Bool_t          Muon_mediumPromptId[99];   //[nMuon]
   UChar_t         Muon_miniIsoId[99];   //[nMuon]
   UChar_t         Muon_multiIsoId[99];   //[nMuon]
   UChar_t         Muon_mvaId[99];   //[nMuon]
   UChar_t         Muon_pfIsoId[99];   //[nMuon]
   Bool_t          Muon_softId[99];   //[nMuon]
   Bool_t          Muon_softMvaId[99];   //[nMuon]
   Bool_t          Muon_tightId[99];   //[nMuon]
   UChar_t         Muon_tkIsoId[99];   //[nMuon]
   Bool_t          Muon_triggerIdLoose[99];   //[nMuon]
   UInt_t          nPhoton;
   Float_t         Photon_eCorr[99];   //[nPhoton]
   Float_t         Photon_energyErr[99];   //[nPhoton]
   Float_t         Photon_eta[99];   //[nPhoton]
   Float_t         Photon_hoe[99];   //[nPhoton]
   Float_t         Photon_mass[99];   //[nPhoton]
   Float_t         Photon_mvaID[99];   //[nPhoton]
   Float_t         Photon_mvaID17[99];   //[nPhoton]
   Float_t         Photon_pfRelIso03_all[99];   //[nPhoton]
   Float_t         Photon_pfRelIso03_chg[99];   //[nPhoton]
   Float_t         Photon_phi[99];   //[nPhoton]
   Float_t         Photon_pt[99];   //[nPhoton]
   Float_t         Photon_r9[99];   //[nPhoton]
   Float_t         Photon_sieie[99];   //[nPhoton]
   Int_t           Photon_charge[99];   //[nPhoton]
   Int_t           Photon_cutBased[99];   //[nPhoton]
   Int_t           Photon_cutBasedBitmap[99];   //[nPhoton]
   Int_t           Photon_cutBasedV1Bitmap[99];   //[nPhoton]
   Int_t           Photon_cutBased17Bitmap[99];   //[nPhoton]
   Int_t           Photon_electronIdx[99];   //[nPhoton]
   Int_t           Photon_jetIdx[99];   //[nPhoton]
   Int_t           Photon_pdgId[99];   //[nPhoton]
   Int_t           Photon_vidNestedWPBitmap[99];   //[nPhoton]
   Bool_t          Photon_electronVeto[99];   //[nPhoton]
   Bool_t          Photon_isScEtaEB[99];   //[nPhoton]
   Bool_t          Photon_isScEtaEE[99];   //[nPhoton]
   Bool_t          Photon_mvaID17_WP80[99];   //[nPhoton]
   Bool_t          Photon_mvaID17_WP90[99];   //[nPhoton]
   Bool_t          Photon_mvaID_WP80[99];   //[nPhoton]
   Bool_t          Photon_mvaID_WP90[99];   //[nPhoton]
   Bool_t          Photon_pixelSeed[99];   //[nPhoton]
   UChar_t         Photon_seedGain[99];   //[nPhoton]
   Float_t         Pileup_nTrueInt;
   Float_t         Pileup_pudensity;
   Float_t         Pileup_gpudensity;
   Int_t           Pileup_nPU;
   Int_t           Pileup_sumEOOT;
   Int_t           Pileup_sumLOOT;
   Float_t         PuppiMET_phi;
   Float_t         PuppiMET_pt;
   Float_t         PuppiMET_sumEt;
   Float_t         RawMET_phi;
   Float_t         RawMET_pt;
   Float_t         RawMET_sumEt;
   Float_t         fixedGridRhoFastjetAll;
   Float_t         fixedGridRhoFastjetCentral;
   Float_t         fixedGridRhoFastjetCentralCalo;
   Float_t         fixedGridRhoFastjetCentralChargedPileUp;
   Float_t         fixedGridRhoFastjetCentralNeutral;
   UInt_t          nGenDressedLepton;
   Float_t         GenDressedLepton_eta[99];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_mass[99];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_phi[99];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_pt[99];   //[nGenDressedLepton]
   Int_t           GenDressedLepton_pdgId[99];   //[nGenDressedLepton]
   Bool_t          GenDressedLepton_hasTauAnc[99];   //[nGenDressedLepton]
   UInt_t          nSoftActivityJet;
   Float_t         SoftActivityJet_eta[99];   //[nSoftActivityJet]
   Float_t         SoftActivityJet_phi[99];   //[nSoftActivityJet]
   Float_t         SoftActivityJet_pt[99];   //[nSoftActivityJet]
   Float_t         SoftActivityJetHT;
   Float_t         SoftActivityJetHT10;
   Float_t         SoftActivityJetHT2;
   Float_t         SoftActivityJetHT5;
   Int_t           SoftActivityJetNjets10;
   Int_t           SoftActivityJetNjets2;
   Int_t           SoftActivityJetNjets5;
   UInt_t          nSubJet;
   Float_t         SubJet_btagCMVA[99];   //[nSubJet]
   Float_t         SubJet_btagCSVV2[99];   //[nSubJet]
   Float_t         SubJet_btagDeepB[99];   //[nSubJet]
   Float_t         SubJet_eta[99];   //[nSubJet]
   Float_t         SubJet_mass[99];   //[nSubJet]
   Float_t         SubJet_n2b1[99];   //[nSubJet]
   Float_t         SubJet_n3b1[99];   //[nSubJet]
   Float_t         SubJet_phi[99];   //[nSubJet]
   Float_t         SubJet_pt[99];   //[nSubJet]
   Float_t         SubJet_rawFactor[99];   //[nSubJet]
   Float_t         SubJet_tau1[99];   //[nSubJet]
   Float_t         SubJet_tau2[99];   //[nSubJet]
   Float_t         SubJet_tau3[99];   //[nSubJet]
   Float_t         SubJet_tau4[99];   //[nSubJet]
   UInt_t          nTau;
   Float_t         Tau_chargedIso[99];   //[nTau]
   Float_t         Tau_dxy[99];   //[nTau]
   Float_t         Tau_dz[99];   //[nTau]
   Float_t         Tau_eta[99];   //[nTau]
   Float_t         Tau_leadTkDeltaEta[99];   //[nTau]
   Float_t         Tau_leadTkDeltaPhi[99];   //[nTau]
   Float_t         Tau_leadTkPtOverTauPt[99];   //[nTau]
   Float_t         Tau_mass[99];   //[nTau]
   Float_t         Tau_neutralIso[99];   //[nTau]
   Float_t         Tau_phi[99];   //[nTau]
   Float_t         Tau_photonsOutsideSignalCone[99];   //[nTau]
   Float_t         Tau_pt[99];   //[nTau]
   Float_t         Tau_puCorr[99];   //[nTau]
   Float_t         Tau_rawAntiEle[99];   //[nTau]
   Float_t         Tau_rawAntiEle2018[99];   //[nTau]
   Float_t         Tau_rawIso[99];   //[nTau]
   Float_t         Tau_rawIsodR03[99];   //[nTau]
   Float_t         Tau_rawMVAnewDM2017v2[99];   //[nTau]
   Float_t         Tau_rawMVAoldDM[99];   //[nTau]
   Float_t         Tau_rawMVAoldDM2017v1[99];   //[nTau]
   Float_t         Tau_rawMVAoldDM2017v2[99];   //[nTau]
   Float_t         Tau_rawMVAoldDMdR032017v2[99];   //[nTau]
   Int_t           Tau_charge[99];   //[nTau]
   Int_t           Tau_decayMode[99];   //[nTau]
   Int_t           Tau_jetIdx[99];   //[nTau]
   Int_t           Tau_rawAntiEleCat[99];   //[nTau]
   Int_t           Tau_rawAntiEleCat2018[99];   //[nTau]
   UChar_t         Tau_idAntiEle[99];   //[nTau]
   UChar_t         Tau_idAntiEle2018[99];   //[nTau]
   UChar_t         Tau_idAntiMu[99];   //[nTau]
   Bool_t          Tau_idDecayMode[99];   //[nTau]
   Bool_t          Tau_idDecayModeNewDMs[99];   //[nTau]
   UChar_t         Tau_idMVAnewDM2017v2[99];   //[nTau]
   UChar_t         Tau_idMVAoldDM[99];   //[nTau]
   UChar_t         Tau_idMVAoldDM2017v1[99];   //[nTau]
   UChar_t         Tau_idMVAoldDM2017v2[99];   //[nTau]
   UChar_t         Tau_idMVAoldDMdR032017v2[99];   //[nTau]
   Float_t         TkMET_phi;
   Float_t         TkMET_pt;
   Float_t         TkMET_sumEt;
   UInt_t          nTrigObj;
   Float_t         TrigObj_pt[99];   //[nTrigObj]
   Float_t         TrigObj_eta[99];   //[nTrigObj]
   Float_t         TrigObj_phi[99];   //[nTrigObj]
   Float_t         TrigObj_l1pt[99];   //[nTrigObj]
   Float_t         TrigObj_l1pt_2[99];   //[nTrigObj]
   Float_t         TrigObj_l2pt[99];   //[nTrigObj]
   Int_t           TrigObj_id[99];   //[nTrigObj]
   Int_t           TrigObj_l1iso[99];   //[nTrigObj]
   Int_t           TrigObj_l1charge[99];   //[nTrigObj]
   Int_t           TrigObj_filterBits[99];   //[nTrigObj]
   Int_t           genTtbarId;
   UInt_t          nOtherPV;
   Float_t         OtherPV_z[99];   //[nOtherPV]
   Float_t         PV_ndof;
   Float_t         PV_x;
   Float_t         PV_y;
   Float_t         PV_z;
   Float_t         PV_chi2;
   Float_t         PV_score;
   Int_t           PV_npvs;
   Int_t           PV_npvsGood;
   UInt_t          nSV;
   Float_t         SV_dlen[99];   //[nSV]
   Float_t         SV_dlenSig[99];   //[nSV]
   Float_t         SV_pAngle[99];   //[nSV]
   Int_t           Electron_genPartIdx[99];   //[nElectron]
   UChar_t         Electron_genPartFlav[99];   //[nElectron]
   Int_t           GenJetAK8_partonFlavour[99];   //[nGenJetAK8]
   UChar_t         GenJetAK8_hadronFlavour[99];   //[nGenJetAK8]
   Int_t           GenJet_partonFlavour[99];   //[nGenJet]
   UChar_t         GenJet_hadronFlavour[99];   //[nGenJet]
   Int_t           Jet_genJetIdx[99];   //[nJet]
   Int_t           Jet_hadronFlavour[99];   //[nJet]
   Int_t           Jet_partonFlavour[99];   //[nJet]
   Int_t           Muon_genPartIdx[99];   //[nMuon]
   UChar_t         Muon_genPartFlav[99];   //[nMuon]
   Int_t           Photon_genPartIdx[99];   //[nPhoton]
   UChar_t         Photon_genPartFlav[99];   //[nPhoton]
   Float_t         MET_fiducialGenPhi;
   Float_t         MET_fiducialGenPt;
   UChar_t         Electron_cleanmask[99];   //[nElectron]
   UChar_t         Jet_cleanmask[99];   //[nJet]
   UChar_t         Muon_cleanmask[99];   //[nMuon]
   UChar_t         Photon_cleanmask[99];   //[nPhoton]
   UChar_t         Tau_cleanmask[99];   //[nTau]
   Float_t         SV_chi2[99];   //[nSV]
   Float_t         SV_eta[99];   //[nSV]
   Float_t         SV_mass[99];   //[nSV]
   Float_t         SV_ndof[99];   //[nSV]
   Float_t         SV_phi[99];   //[nSV]
   Float_t         SV_pt[99];   //[nSV]
   Float_t         SV_x[99];   //[nSV]
   Float_t         SV_y[99];   //[nSV]
   Float_t         SV_z[99];   //[nSV]
   Int_t           Tau_genPartIdx[99];   //[nTau]
   UChar_t         Tau_genPartFlav[99];   //[nTau]
   Bool_t          Flag_HBHENoiseFilter;
   Bool_t          Flag_HBHENoiseIsoFilter;
   Bool_t          Flag_CSCTightHaloFilter;
   Bool_t          Flag_CSCTightHaloTrkMuUnvetoFilter;
   Bool_t          Flag_CSCTightHalo2015Filter;
   Bool_t          Flag_globalTightHalo2016Filter;
   Bool_t          Flag_globalSuperTightHalo2016Filter;
   Bool_t          Flag_HcalStripHaloFilter;
   Bool_t          Flag_hcalLaserEventFilter;
   Bool_t          Flag_EcalDeadCellTriggerPrimitiveFilter;
   Bool_t          Flag_EcalDeadCellBoundaryEnergyFilter;
   Bool_t          Flag_ecalBadCalibFilter;
   Bool_t          Flag_goodVertices;
   Bool_t          Flag_eeBadScFilter;
   Bool_t          Flag_ecalLaserCorrFilter;
   Bool_t          Flag_trkPOGFilters;
   Bool_t          Flag_chargedHadronTrackResolutionFilter;
   Bool_t          Flag_muonBadTrackFilter;
   Bool_t          Flag_BadChargedCandidateFilter;
   Bool_t          Flag_BadPFMuonFilter;
   Bool_t          Flag_BadChargedCandidateSummer16Filter;
   Bool_t          Flag_BadPFMuonSummer16Filter;
   Bool_t          Flag_trkPOG_manystripclus53X;
   Bool_t          Flag_trkPOG_toomanystripclus53X;
   Bool_t          Flag_trkPOG_logErrorTooManyClusters;
   Bool_t          Flag_METFilters;
   Bool_t          HLT_Ele27_WPTight_Gsf;
   Bool_t          HLT_ECALHT800;
   Bool_t          HLT_Photon165_HE10;
   Bool_t          HLT_Photon165_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon175;
   Bool_t          HLT_Photon200;
   Bool_t          HLT_Photon250_NoHE;
   Bool_t          HLT_Photon300_NoHE;
   Bool_t          HLT_Photon500;
   Bool_t          HLT_Photon600;
   Bool_t          HLT_AK8PFJet360_TrimMass30;
   Bool_t          HLT_AK8PFJet400_TrimMass30;
   Bool_t          HLT_AK8PFJet500;
   Bool_t          HLT_PFJet450;
   Bool_t          HLT_PFJet500;
   Bool_t          HLT_PFHT900;
   Bool_t          HLT_PFMET170_HBHECleaned;
   Bool_t          HLT_PFMET170_HBHE_BeamHaloCleaned;
   Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;
   Bool_t          L1Reco_step;
   Bool_t          L1_AlwaysTrue;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_CaloMET_phi;   //!
   TBranch        *b_CaloMET_pt;   //!
   TBranch        *b_CaloMET_sumEt;   //!
   TBranch        *b_ChsMET_phi;   //!
   TBranch        *b_ChsMET_pt;   //!
   TBranch        *b_ChsMET_sumEt;   //!
   TBranch        *b_nCorrT1METJet;   //!
   TBranch        *b_CorrT1METJet_area;   //!
   TBranch        *b_CorrT1METJet_eta;   //!
   TBranch        *b_CorrT1METJet_muonSubtrFactor;   //!
   TBranch        *b_CorrT1METJet_phi;   //!
   TBranch        *b_CorrT1METJet_rawPt;   //!
   TBranch        *b_nElectron;   //!
   TBranch        *b_Electron_deltaEtaSC;   //!
   TBranch        *b_Electron_dr03EcalRecHitSumEt;   //!
   TBranch        *b_Electron_dr03HcalDepth1TowerSumEt;   //!
   TBranch        *b_Electron_dr03TkSumPt;   //!
   TBranch        *b_Electron_dr03TkSumPtHEEP;   //!
   TBranch        *b_Electron_dxy;   //!
   TBranch        *b_Electron_dxyErr;   //!
   TBranch        *b_Electron_dz;   //!
   TBranch        *b_Electron_dzErr;   //!
   TBranch        *b_Electron_eCorr;   //!
   TBranch        *b_Electron_eInvMinusPInv;   //!
   TBranch        *b_Electron_energyErr;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_hoe;   //!
   TBranch        *b_Electron_ip3d;   //!
   TBranch        *b_Electron_jetPtRelv2;   //!
   TBranch        *b_Electron_jetRelIso;   //!
   TBranch        *b_Electron_mass;   //!
   TBranch        *b_Electron_miniPFRelIso_all;   //!
   TBranch        *b_Electron_miniPFRelIso_chg;   //!
   TBranch        *b_Electron_mvaFall17V1Iso;   //!
   TBranch        *b_Electron_mvaFall17V1noIso;   //!
   TBranch        *b_Electron_mvaFall17V2Iso;   //!
   TBranch        *b_Electron_mvaFall17V2noIso;   //!
   TBranch        *b_Electron_mvaSpring16GP;   //!
   TBranch        *b_Electron_mvaSpring16HZZ;   //!
   TBranch        *b_Electron_pfRelIso03_all;   //!
   TBranch        *b_Electron_pfRelIso03_chg;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_r9;   //!
   TBranch        *b_Electron_sieie;   //!
   TBranch        *b_Electron_sip3d;   //!
   TBranch        *b_Electron_mvaTTH;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_cutBased;   //!
   TBranch        *b_Electron_cutBased_Fall17_V1;   //!
   TBranch        *b_Electron_cutBased_HLTPreSel;   //!
   TBranch        *b_Electron_cutBased_Spring15;   //!
   TBranch        *b_Electron_cutBased_Sum16;   //!
   TBranch        *b_Electron_jetIdx;   //!
   TBranch        *b_Electron_pdgId;   //!
   TBranch        *b_Electron_photonIdx;   //!
   TBranch        *b_Electron_tightCharge;   //!
   TBranch        *b_Electron_vidNestedWPBitmap;   //!
   TBranch        *b_Electron_vidNestedWPBitmapSpring15;   //!
   TBranch        *b_Electron_vidNestedWPBitmapSum16;   //!
   TBranch        *b_Electron_convVeto;   //!
   TBranch        *b_Electron_cutBased_HEEP;   //!
   TBranch        *b_Electron_isPFcand;   //!
   TBranch        *b_Electron_lostHits;   //!
   TBranch        *b_Electron_mvaFall17V1Iso_WP80;   //!
   TBranch        *b_Electron_mvaFall17V1Iso_WP90;   //!
   TBranch        *b_Electron_mvaFall17V1Iso_WPL;   //!
   TBranch        *b_Electron_mvaFall17V1noIso_WP80;   //!
   TBranch        *b_Electron_mvaFall17V1noIso_WP90;   //!
   TBranch        *b_Electron_mvaFall17V1noIso_WPL;   //!
   TBranch        *b_Electron_mvaFall17V2Iso_WP80;   //!
   TBranch        *b_Electron_mvaFall17V2Iso_WP90;   //!
   TBranch        *b_Electron_mvaFall17V2Iso_WPL;   //!
   TBranch        *b_Electron_mvaFall17V2noIso_WP80;   //!
   TBranch        *b_Electron_mvaFall17V2noIso_WP90;   //!
   TBranch        *b_Electron_mvaFall17V2noIso_WPL;   //!
   TBranch        *b_Electron_mvaSpring16GP_WP80;   //!
   TBranch        *b_Electron_mvaSpring16GP_WP90;   //!
   TBranch        *b_Electron_mvaSpring16HZZ_WPL;   //!
   TBranch        *b_Electron_seedGain;   //!
   TBranch        *b_nFatJet;   //!
   TBranch        *b_FatJet_area;   //!
   TBranch        *b_FatJet_btagCMVA;   //!
   TBranch        *b_FatJet_btagCSVV2;   //!
   TBranch        *b_FatJet_btagDDBvL;   //!
   TBranch        *b_FatJet_btagDDCvB;   //!
   TBranch        *b_FatJet_btagDDCvL;   //!
   TBranch        *b_FatJet_btagDeepB;   //!
   TBranch        *b_FatJet_btagHbb;   //!
   TBranch        *b_FatJet_deepTagMD_H4qvsQCD;   //!
   TBranch        *b_FatJet_deepTagMD_HbbvsQCD;   //!
   TBranch        *b_FatJet_deepTagMD_TvsQCD;   //!
   TBranch        *b_FatJet_deepTagMD_WvsQCD;   //!
   TBranch        *b_FatJet_deepTagMD_ZHbbvsQCD;   //!
   TBranch        *b_FatJet_deepTagMD_ZHccvsQCD;   //!
   TBranch        *b_FatJet_deepTagMD_ZbbvsQCD;   //!
   TBranch        *b_FatJet_deepTagMD_ZvsQCD;   //!
   TBranch        *b_FatJet_deepTagMD_bbvsLight;   //!
   TBranch        *b_FatJet_deepTagMD_ccvsLight;   //!
   TBranch        *b_FatJet_deepTag_H;   //!
   TBranch        *b_FatJet_deepTag_QCD;   //!
   TBranch        *b_FatJet_deepTag_QCDothers;   //!
   TBranch        *b_FatJet_deepTag_TvsQCD;   //!
   TBranch        *b_FatJet_deepTag_WvsQCD;   //!
   TBranch        *b_FatJet_deepTag_ZvsQCD;   //!
   TBranch        *b_FatJet_eta;   //!
   TBranch        *b_FatJet_mass;   //!
   TBranch        *b_FatJet_msoftdrop;   //!
   TBranch        *b_FatJet_msoftdrop_nom;   //[nFatJet]
   TBranch        *b_FatJet_msoftdrop_jerUp;   //[nFatJet]
   TBranch        *b_FatJet_msoftdrop_jerDown;   //[nFatJet]
   TBranch        *b_FatJet_msoftdrop_jesTotalUp;   //[nFatJet]
   TBranch        *b_FatJet_msoftdrop_jesTotalDown;   //[nFatJet]
   TBranch        *b_FatJet_msoftdrop_jmrUp;   //[nFatJet]
   TBranch        *b_FatJet_msoftdrop_jmrDown;   //[nFatJet]
   TBranch        *b_FatJet_msoftdrop_jmsUp;   //[nFatJet]
   TBranch        *b_FatJet_msoftdrop_jmsDown;   //[nFatJet]
   TBranch        *b_FatJet_n2b1;   //!
   TBranch        *b_FatJet_n3b1;   //!
   TBranch        *b_FatJet_phi;   //!
   TBranch        *b_FatJet_pt;   //!
   TBranch        *b_FatJet_pt_nom;   //[nJet]
   TBranch        *b_FatJet_pt_jerUp;   //[nJet]
   TBranch        *b_FatJet_pt_jerDown;   //[nJet]
   TBranch        *b_FatJet_pt_jesTotalUp;   //[nJet]
   TBranch        *b_FatJet_pt_jesTotalDown;   //[nJet]
   TBranch        *b_FatJet_rawFactor;   //!
   TBranch        *b_FatJet_tau1;   //!
   TBranch        *b_FatJet_tau2;   //!
   TBranch        *b_FatJet_tau3;   //!
   TBranch        *b_FatJet_tau4;   //!
   TBranch        *b_FatJet_jetId;   //!
   TBranch        *b_FatJet_subJetIdx1;   //!
   TBranch        *b_FatJet_subJetIdx2;   //!
   TBranch        *b_nGenJetAK8;   //!
   TBranch        *b_GenJetAK8_eta;   //!
   TBranch        *b_GenJetAK8_mass;   //!
   TBranch        *b_GenJetAK8_phi;   //!
   TBranch        *b_GenJetAK8_pt;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_GenJet_eta;   //!
   TBranch        *b_GenJet_mass;   //!
   TBranch        *b_GenJet_phi;   //!
   TBranch        *b_GenJet_pt;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_genPartIdxMother;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_statusFlags;   //!
   TBranch        *b_nSubGenJetAK8;   //!
   TBranch        *b_SubGenJetAK8_eta;   //!
   TBranch        *b_SubGenJetAK8_mass;   //!
   TBranch        *b_SubGenJetAK8_phi;   //!
   TBranch        *b_SubGenJetAK8_pt;   //!
   TBranch        *b_Generator_binvar;   //!
   TBranch        *b_Generator_scalePDF;   //!
   TBranch        *b_Generator_weight;   //!
   TBranch        *b_Generator_x1;   //!
   TBranch        *b_Generator_x2;   //!
   TBranch        *b_Generator_xpdf1;   //!
   TBranch        *b_Generator_xpdf2;   //!
   TBranch        *b_Generator_id1;   //!
   TBranch        *b_Generator_id2;   //!
   TBranch        *b_nGenVisTau;   //!
   TBranch        *b_GenVisTau_eta;   //!
   TBranch        *b_GenVisTau_mass;   //!
   TBranch        *b_GenVisTau_phi;   //!
   TBranch        *b_GenVisTau_pt;   //!
   TBranch        *b_GenVisTau_charge;   //!
   TBranch        *b_GenVisTau_genPartIdxMother;   //!
   TBranch        *b_GenVisTau_status;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_puWeight;
   TBranch        *b_puWeightUp;
   TBranch        *b_puWeightDown;
   TBranch        *b_nPSWeight;   //!
   TBranch        *b_PSWeight;   //!
   TBranch        *b_nIsoTrack;   //!
   TBranch        *b_IsoTrack_dxy;   //!
   TBranch        *b_IsoTrack_dz;   //!
   TBranch        *b_IsoTrack_eta;   //!
   TBranch        *b_IsoTrack_pfRelIso03_all;   //!
   TBranch        *b_IsoTrack_pfRelIso03_chg;   //!
   TBranch        *b_IsoTrack_phi;   //!
   TBranch        *b_IsoTrack_pt;   //!
   TBranch        *b_IsoTrack_miniPFRelIso_all;   //!
   TBranch        *b_IsoTrack_miniPFRelIso_chg;   //!
   TBranch        *b_IsoTrack_fromPV;   //!
   TBranch        *b_IsoTrack_pdgId;   //!
   TBranch        *b_IsoTrack_isHighPurityTrack;   //!
   TBranch        *b_IsoTrack_isPFcand;   //!
   TBranch        *b_IsoTrack_isFromLostTrack;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_area;   //!
   TBranch        *b_Jet_btagCMVA;   //!
   TBranch        *b_Jet_btagCSVV2;   //!
   TBranch        *b_Jet_btagDeepB;   //!
   TBranch        *b_Jet_btagDeepC;   //!
   TBranch        *b_Jet_btagDeepFlavB;   //!
   TBranch        *b_Jet_btagDeepFlavC;   //!
   TBranch        *b_Jet_chEmEF;   //!
   TBranch        *b_Jet_chHEF;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_jercCHF;   //!
   TBranch        *b_Jet_jercCHPUF;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_mass_nom;   //!
   TBranch        *b_Jet_mass_jerUp;   //[nJet]
   TBranch        *b_Jet_mass_jerDown;   //[nJet]
   TBranch        *b_Jet_mass_jesTotalUp;   //[nJet]
   TBranch        *b_Jet_mass_jesTotalDown;   //[nJet]
   TBranch        *b_Jet_muEF;   //!
   TBranch        *b_Jet_muonSubtrFactor;   //!
   TBranch        *b_Jet_neEmEF;   //!
   TBranch        *b_Jet_neHEF;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_pt_nom;   //[nJet]
   TBranch        *b_Jet_pt_raw;   //[nJet]
   TBranch        *b_Jet_pt_jerUp;   //[nJet]
   TBranch        *b_Jet_pt_jerDown;   //[nJet]
   TBranch        *b_Jet_pt_jesTotalUp;   //[nJet]
   TBranch        *b_Jet_pt_jesTotalDown;   //[nJet]
   TBranch        *b_Jet_qgl;   //!
   TBranch        *b_Jet_rawFactor;   //!
   TBranch        *b_Jet_bRegCorr;   //!
   TBranch        *b_Jet_bRegRes;   //!
   TBranch        *b_Jet_electronIdx1;   //!
   TBranch        *b_Jet_electronIdx2;   //!
   TBranch        *b_Jet_jetId;   //!
   TBranch        *b_Jet_muonIdx1;   //!
   TBranch        *b_Jet_muonIdx2;   //!
   TBranch        *b_Jet_nConstituents;   //!
   TBranch        *b_Jet_nElectrons;   //!
   TBranch        *b_Jet_nMuons;   //!
   TBranch        *b_Jet_puId;   //!
   TBranch        *b_L1PreFiringWeight_Dn;   //!
   TBranch        *b_L1PreFiringWeight_Nom;   //!
   TBranch        *b_L1PreFiringWeight_Up;   //!
   TBranch        *b_GenMET_phi;   //!
   TBranch        *b_GenMET_pt;   //!
   TBranch        *b_MET_MetUnclustEnUpDeltaX;   //!
   TBranch        *b_MET_MetUnclustEnUpDeltaY;   //!
   TBranch        *b_MET_covXX;   //!
   TBranch        *b_MET_covXY;   //!
   TBranch        *b_MET_covYY;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_MET_phi_nom;
   TBranch        *b_MET_phi_jer;
   TBranch        *b_MET_phi_jerUp;
   TBranch        *b_MET_phi_jerDown;
   TBranch        *b_MET_phi_jesTotalUp;
   TBranch        *b_MET_phi_jesTotalDown;
   TBranch        *b_MET_phi_unclustEnUp;
   TBranch        *b_MET_phi_unclustEnDown;
   TBranch        *b_MET_pt;   //!
   TBranch        *b_MET_pt_nom;
   TBranch        *b_MET_pt_jer;
   TBranch        *b_MET_pt_jerUp;
   TBranch        *b_MET_pt_jerDown;
   TBranch        *b_MET_pt_jesTotalUp;
   TBranch        *b_MET_pt_jesTotalDown;
   TBranch        *b_MET_pt_unclustEnUp;
   TBranch        *b_MET_pt_unclustEnDown;
   TBranch        *b_MET_significance;   //!
   TBranch        *b_MET_sumEt;   //!
   TBranch        *b_METFixEE2017_MetUnclustEnUpDeltaX;   //!
   TBranch        *b_METFixEE2017_MetUnclustEnUpDeltaY;   //!
   TBranch        *b_METFixEE2017_covXX;   //!
   TBranch        *b_METFixEE2017_covXY;   //!
   TBranch        *b_METFixEE2017_covYY;   //!
   TBranch        *b_METFixEE2017_phi;   //!
   TBranch        *b_METFixEE2017_phi_nom;
   TBranch        *b_METFixEE2017_phi_jer;
   TBranch        *b_METFixEE2017_phi_jerUp;
   TBranch        *b_METFixEE2017_phi_jerDown;
   TBranch        *b_METFixEE2017_phi_jesTotalUp;
   TBranch        *b_METFixEE2017_phi_jesTotalDown;
   TBranch        *b_METFixEE2017_phi_unclustEnUp;
   TBranch        *b_METFixEE2017_phi_unclustEnDown;
   TBranch        *b_METFixEE2017_pt;   //!
   TBranch        *b_METFixEE2017_pt_nom;
   TBranch        *b_METFixEE2017_pt_jer;
   TBranch        *b_METFixEE2017_pt_jerUp;
   TBranch        *b_METFixEE2017_pt_jerDown;
   TBranch        *b_METFixEE2017_pt_jesTotalUp;
   TBranch        *b_METFixEE2017_pt_jesTotalDown;
   TBranch        *b_METFixEE2017_pt_unclustEnUp;
   TBranch        *b_METFixEE2017_pt_unclustEnDown;
   TBranch        *b_METFixEE2017_significance;   //!
   TBranch        *b_METFixEE2017_sumEt;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_ip3d;   //!
   TBranch        *b_Muon_jetPtRelv2;   //!
   TBranch        *b_Muon_jetRelIso;   //!
   TBranch        *b_Muon_mass;   //!
   TBranch        *b_Muon_miniPFRelIso_all;   //!
   TBranch        *b_Muon_miniPFRelIso_chg;   //!
   TBranch        *b_Muon_pfRelIso03_all;   //!
   TBranch        *b_Muon_pfRelIso03_chg;   //!
   TBranch        *b_Muon_pfRelIso04_all;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_ptErr;   //!
   TBranch        *b_Muon_segmentComp;   //!
   TBranch        *b_Muon_sip3d;   //!
   TBranch        *b_Muon_tkRelIso;   //!
   TBranch        *b_Muon_tunepRelPt;   //!
   TBranch        *b_Muon_mvaLowPt;   //!
   TBranch        *b_Muon_mvaTTH;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_jetIdx;   //!
   TBranch        *b_Muon_nStations;   //!
   TBranch        *b_Muon_nTrackerLayers;   //!
   TBranch        *b_Muon_pdgId;   //!
   TBranch        *b_Muon_tightCharge;   //!
   TBranch        *b_Muon_highPtId;   //!
   TBranch        *b_Muon_inTimeMuon;   //!
   TBranch        *b_Muon_isGlobal;   //!
   TBranch        *b_Muon_isPFcand;   //!
   TBranch        *b_Muon_isTracker;   //!
   TBranch        *b_Muon_looseId;   //!
   TBranch        *b_Muon_mediumId;   //!
   TBranch        *b_Muon_mediumPromptId;   //!
   TBranch        *b_Muon_miniIsoId;   //!
   TBranch        *b_Muon_multiIsoId;   //!
   TBranch        *b_Muon_mvaId;   //!
   TBranch        *b_Muon_pfIsoId;   //!
   TBranch        *b_Muon_softId;   //!
   TBranch        *b_Muon_softMvaId;   //!
   TBranch        *b_Muon_tightId;   //!
   TBranch        *b_Muon_tkIsoId;   //!
   TBranch        *b_Muon_triggerIdLoose;   //!
   TBranch        *b_nPhoton;   //!
   TBranch        *b_Photon_eCorr;   //!
   TBranch        *b_Photon_energyErr;   //!
   TBranch        *b_Photon_eta;   //!
   TBranch        *b_Photon_hoe;   //!
   TBranch        *b_Photon_mass;   //!
   TBranch        *b_Photon_mvaID;   //!
   TBranch        *b_Photon_mvaID17;   //!
   TBranch        *b_Photon_pfRelIso03_all;   //!
   TBranch        *b_Photon_pfRelIso03_chg;   //!
   TBranch        *b_Photon_phi;   //!
   TBranch        *b_Photon_pt;   //!
   TBranch        *b_Photon_r9;   //!
   TBranch        *b_Photon_sieie;   //!
   TBranch        *b_Photon_charge;   //!
   TBranch        *b_Photon_cutBased;   //!
   TBranch        *b_Photon_cutBasedBitmap;   //!
   TBranch        *b_Photon_cutBasedV1Bitmap;   //!
   TBranch        *b_Photon_cutBased17Bitmap;   //!
   TBranch        *b_Photon_electronIdx;   //!
   TBranch        *b_Photon_jetIdx;   //!
   TBranch        *b_Photon_pdgId;   //!
   TBranch        *b_Photon_vidNestedWPBitmap;   //!
   TBranch        *b_Photon_electronVeto;   //!
   TBranch        *b_Photon_isScEtaEB;   //!
   TBranch        *b_Photon_isScEtaEE;   //!
   TBranch        *b_Photon_mvaID17_WP80;   //!
   TBranch        *b_Photon_mvaID17_WP90;   //!
   TBranch        *b_Photon_mvaID_WP80;   //!
   TBranch        *b_Photon_mvaID_WP90;   //!
   TBranch        *b_Photon_pixelSeed;   //!
   TBranch        *b_Photon_seedGain;   //!
   TBranch        *b_Pileup_nTrueInt;   //!
   TBranch        *b_Pileup_pudensity;   //!
   TBranch        *b_Pileup_gpudensity;   //!
   TBranch        *b_Pileup_nPU;   //!
   TBranch        *b_Pileup_sumEOOT;   //!
   TBranch        *b_Pileup_sumLOOT;   //!
   TBranch        *b_PuppiMET_phi;   //!
   TBranch        *b_PuppiMET_pt;   //!
   TBranch        *b_PuppiMET_sumEt;   //!
   TBranch        *b_RawMET_phi;   //!
   TBranch        *b_RawMET_pt;   //!
   TBranch        *b_RawMET_sumEt;   //!
   TBranch        *b_fixedGridRhoFastjetAll;   //!
   TBranch        *b_fixedGridRhoFastjetCentral;   //!
   TBranch        *b_fixedGridRhoFastjetCentralCalo;   //!
   TBranch        *b_fixedGridRhoFastjetCentralChargedPileUp;   //!
   TBranch        *b_fixedGridRhoFastjetCentralNeutral;   //!
   TBranch        *b_nGenDressedLepton;   //!
   TBranch        *b_GenDressedLepton_eta;   //!
   TBranch        *b_GenDressedLepton_mass;   //!
   TBranch        *b_GenDressedLepton_phi;   //!
   TBranch        *b_GenDressedLepton_pt;   //!
   TBranch        *b_GenDressedLepton_pdgId;   //!
   TBranch        *b_GenDressedLepton_hasTauAnc;   //!
   TBranch        *b_nSoftActivityJet;   //!
   TBranch        *b_SoftActivityJet_eta;   //!
   TBranch        *b_SoftActivityJet_phi;   //!
   TBranch        *b_SoftActivityJet_pt;   //!
   TBranch        *b_SoftActivityJetHT;   //!
   TBranch        *b_SoftActivityJetHT10;   //!
   TBranch        *b_SoftActivityJetHT2;   //!
   TBranch        *b_SoftActivityJetHT5;   //!
   TBranch        *b_SoftActivityJetNjets10;   //!
   TBranch        *b_SoftActivityJetNjets2;   //!
   TBranch        *b_SoftActivityJetNjets5;   //!
   TBranch        *b_nSubJet;   //!
   TBranch        *b_SubJet_btagCMVA;   //!
   TBranch        *b_SubJet_btagCSVV2;   //!
   TBranch        *b_SubJet_btagDeepB;   //!
   TBranch        *b_SubJet_eta;   //!
   TBranch        *b_SubJet_mass;   //!
   TBranch        *b_SubJet_n2b1;   //!
   TBranch        *b_SubJet_n3b1;   //!
   TBranch        *b_SubJet_phi;   //!
   TBranch        *b_SubJet_pt;   //!
   TBranch        *b_SubJet_rawFactor;   //!
   TBranch        *b_SubJet_tau1;   //!
   TBranch        *b_SubJet_tau2;   //!
   TBranch        *b_SubJet_tau3;   //!
   TBranch        *b_SubJet_tau4;   //!
   TBranch        *b_nTau;   //!
   TBranch        *b_Tau_chargedIso;   //!
   TBranch        *b_Tau_dxy;   //!
   TBranch        *b_Tau_dz;   //!
   TBranch        *b_Tau_eta;   //!
   TBranch        *b_Tau_leadTkDeltaEta;   //!
   TBranch        *b_Tau_leadTkDeltaPhi;   //!
   TBranch        *b_Tau_leadTkPtOverTauPt;   //!
   TBranch        *b_Tau_mass;   //!
   TBranch        *b_Tau_neutralIso;   //!
   TBranch        *b_Tau_phi;   //!
   TBranch        *b_Tau_photonsOutsideSignalCone;   //!
   TBranch        *b_Tau_pt;   //!
   TBranch        *b_Tau_puCorr;   //!
   TBranch        *b_Tau_rawAntiEle;   //!
   TBranch        *b_Tau_rawAntiEle2018;   //!
   TBranch        *b_Tau_rawIso;   //!
   TBranch        *b_Tau_rawIsodR03;   //!
   TBranch        *b_Tau_rawMVAnewDM2017v2;   //!
   TBranch        *b_Tau_rawMVAoldDM;   //!
   TBranch        *b_Tau_rawMVAoldDM2017v1;   //!
   TBranch        *b_Tau_rawMVAoldDM2017v2;   //!
   TBranch        *b_Tau_rawMVAoldDMdR032017v2;   //!
   TBranch        *b_Tau_charge;   //!
   TBranch        *b_Tau_decayMode;   //!
   TBranch        *b_Tau_jetIdx;   //!
   TBranch        *b_Tau_rawAntiEleCat;   //!
   TBranch        *b_Tau_rawAntiEleCat2018;   //!
   TBranch        *b_Tau_idAntiEle;   //!
   TBranch        *b_Tau_idAntiEle2018;   //!
   TBranch        *b_Tau_idAntiMu;   //!
   TBranch        *b_Tau_idDecayMode;   //!
   TBranch        *b_Tau_idDecayModeNewDMs;   //!
   TBranch        *b_Tau_idMVAnewDM2017v2;   //!
   TBranch        *b_Tau_idMVAoldDM;   //!
   TBranch        *b_Tau_idMVAoldDM2017v1;   //!
   TBranch        *b_Tau_idMVAoldDM2017v2;   //!
   TBranch        *b_Tau_idMVAoldDMdR032017v2;   //!
   TBranch        *b_TkMET_phi;   //!
   TBranch        *b_TkMET_pt;   //!
   TBranch        *b_TkMET_sumEt;   //!
   TBranch        *b_nTrigObj;   //!
   TBranch        *b_TrigObj_pt;   //!
   TBranch        *b_TrigObj_eta;   //!
   TBranch        *b_TrigObj_phi;   //!
   TBranch        *b_TrigObj_l1pt;   //!
   TBranch        *b_TrigObj_l1pt_2;   //!
   TBranch        *b_TrigObj_l2pt;   //!
   TBranch        *b_TrigObj_id;   //!
   TBranch        *b_TrigObj_l1iso;   //!
   TBranch        *b_TrigObj_l1charge;   //!
   TBranch        *b_TrigObj_filterBits;   //!
   TBranch        *b_genTtbarId;   //!
   TBranch        *b_nOtherPV;   //!
   TBranch        *b_OtherPV_z;   //!
   TBranch        *b_PV_ndof;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_PV_chi2;   //!
   TBranch        *b_PV_score;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_npvsGood;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_dlen;   //!
   TBranch        *b_SV_dlenSig;   //!
   TBranch        *b_SV_pAngle;   //!
   TBranch        *b_Electron_genPartIdx;   //!
   TBranch        *b_Electron_genPartFlav;   //!
   TBranch        *b_GenJetAK8_partonFlavour;   //!
   TBranch        *b_GenJetAK8_hadronFlavour;   //!
   TBranch        *b_GenJet_partonFlavour;   //!
   TBranch        *b_GenJet_hadronFlavour;   //!
   TBranch        *b_Jet_genJetIdx;   //!
   TBranch        *b_Jet_hadronFlavour;   //!
   TBranch        *b_Jet_partonFlavour;   //!
   TBranch        *b_Muon_genPartIdx;   //!
   TBranch        *b_Muon_genPartFlav;   //!
   TBranch        *b_Photon_genPartIdx;   //!
   TBranch        *b_Photon_genPartFlav;   //!
   TBranch        *b_MET_fiducialGenPhi;   //!
   TBranch        *b_MET_fiducialGenPt;   //!
   TBranch        *b_Electron_cleanmask;   //!
   TBranch        *b_Jet_cleanmask;   //!
   TBranch        *b_Muon_cleanmask;   //!
   TBranch        *b_Photon_cleanmask;   //!
   TBranch        *b_Tau_cleanmask;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_eta;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_ndof;   //!
   TBranch        *b_SV_phi;   //!
   TBranch        *b_SV_pt;   //!
   TBranch        *b_SV_x;   //!
   TBranch        *b_SV_y;   //!
   TBranch        *b_SV_z;   //!
   TBranch        *b_Tau_genPartIdx;   //!
   TBranch        *b_Tau_genPartFlav;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_CSCTightHaloTrkMuUnvetoFilter;   //!
   TBranch        *b_Flag_CSCTightHalo2015Filter;   //!
   TBranch        *b_Flag_globalTightHalo2016Filter;   //!
   TBranch        *b_Flag_globalSuperTightHalo2016Filter;   //!
   TBranch        *b_Flag_HcalStripHaloFilter;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_EcalDeadCellBoundaryEnergyFilter;   //!
   TBranch        *b_Flag_ecalBadCalibFilter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_chargedHadronTrackResolutionFilter;   //!
   TBranch        *b_Flag_muonBadTrackFilter;   //!
   TBranch        *b_Flag_BadChargedCandidateFilter;   //!
   TBranch        *b_Flag_BadPFMuonFilter;   //!
   TBranch        *b_Flag_BadChargedCandidateSummer16Filter;   //!
   TBranch        *b_Flag_BadPFMuonSummer16Filter;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_METFilters;   //!
   TBranch        *b_HLT_Ele27_WPTight_Gsf;
   TBranch        *b_HLT_ECALHT800;
   TBranch        *b_HLT_Photon165_HE10;
   TBranch        *b_HLT_Photon165_R9Id90_HE10_IsoM;
   TBranch        *b_HLT_Photon175;
   TBranch        *b_HLT_Photon200;
   TBranch        *b_HLT_Photon250_NoHE;
   TBranch        *b_HLT_Photon300_NoHE;
   TBranch        *b_HLT_Photon500;
   TBranch        *b_HLT_Photon600;
   TBranch        *b_HLT_AK8PFJet360_TrimMass30;
   TBranch        *b_HLT_AK8PFJet400_TrimMass30;
   TBranch        *b_HLT_AK8PFJet500;
   TBranch        *b_HLT_PFJet450;
   TBranch        *b_HLT_PFJet500;
   TBranch        *b_HLT_PFHT900;
   TBranch        *b_HLT_PFMET170_HBHECleaned;
   TBranch        *b_HLT_PFMET170_HBHE_BeamHaloCleaned;
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;
   TBranch        *b_L1Reco_step;
   TBranch        *b_L1_AlwaysTrue;

   //Added
   double BtagDDBvLWP[3][5]={{0.7,0.86,0.89,0.91,0.92},{0.7,0.86,0.89,0.91,0.92},{0.7,0.86,0.89,0.91,0.92}};
   double BtagDeepWP[3][3]={{0.0614,0.3093,0.7221},{0.0521,0.3033,0.7489},{0.0494,0.2770,0.7264}};
   std::string output_file="default", btag_file="", xsec_file="default";
   unsigned int nFiles=0;
   bool _fastSim=false;
   int _fakeRate=0;
   int _testRun=0;
   bool isData=true;
   bool is_quiet=false;
   bool signalstudy=false;
   bool SignalScan=false;
   bool CountSignal=false;
   int SignalScenario=0;
   vector<string> _cut_variable, _cut_operator;
   vector<double> _cut_value;
   //For cuts
   int nPassPhoL=-1, nPassPhoM=-1, nPassPhoT=-1, nPassPhoMVA80=-1, nPassPhoMVA90=-1;
   int nPassAK4=-1, nPassAK8=-1, nonHiggsJet=-1;
   int nPassEleV=-1, nPassEleL=-1, nPassEleM=-1, nPassEleT=-1, nPassEleNO=-1;
   int nPassFREleL=0, nPassFREleM=0, nPassFREleT=0;
   int nPassElePhoL=0, nPassElePhoM=0, nPassElePhoT=0, nPassElePhoMVA80=-1, nPassElePhoMVA90=-1;
   int nPassMuL=-1, nPassMuM=-1, nPassMuT=-1, nPassMuNO=-1;
   int nPassTauL=-1, nPassTauM=-1, nPassTauT=-1, nPassIso=-1;
   int nPassLepL=-1, nPassLepM=-1, nPassLepT=-1;
   int nleadPho=-1, nleadElePho=-1, nleadEle=-1, nleadMu=-1, nleadTau=-1;
   int nleadFREleL=-1, nleadFREleM=-1, nleadFREleT=-1;
   int nleadEleV=-1, nleadEleL=-1, nleadEleM=-1, nleadEleT=-1, nleadEleNO=-1;
   int nleadMuL=-1, nleadMuM=-1, nleadMuT=-1, nleadMuNO=-1;
   int nleadTauL=-1, nleadTauM=-1, nleadTauT=-1, nleadIso=-1;
   int bcounterDDBvL[6]={}, bcounterDeep[4]={};
   int DDBvL_selected=0, Deep_selected=0;
   bool L1prefire=false;
   bool passBtag=false, passHiggsMass=false;
   bool passAK4Btag1=false, passAK4Btag2=false, passAK4HiggsMass=false;
   bool notAK4=true;
   bool Hbb=false, mcLeptonFilter=false;
   int truePU=0;
   int SignalHiggs=0;
   double HT_before=0, EMHT_before=0, HT_after=0, EMHT_after=0;
   double AK8HT_before=0, AK8EMHT_before=0, AK8HT_after=0, AK8EMHT_after=0;
   double DDBvL_SF_L[3]={1,1,1}, DDBvL_SF_M1[3]={1,1,1}, DDBvL_SF_M2[3]={1,1,1}, DDBvL_SF_T1[3]={1,1,1}, DDBvL_SF_T2[3]={1,1,1};
   double Deep_SF_L[3]={1,1,1}, Deep_SF_M[3]={1,1,1}, Deep_SF_T[3]={1,1,1};
   double pho_SF[5]={1,1,1,1,1}, ele_SF[4]={1,1,1,1}, mu_SF[3]={1,1,1}, tau_SF[3]={1,1,1};
   double ele_VETOSF=1;
   int year=2016;
   int DDBvL_whichSF=0, Deep_whichSF=0;
   int JES_whichSF=0, JER_whichSF=0, UES_whichSF=0, JMR_whichSF=0, JMS_whichSF=0, ISR_whichSF=0;
   int phoID_whichSF=0, phoPix_whichSF=0, eleID_whichSF=0, eleRec_whichSF=0, muID_whichSF=0, muISO_whichSF=0, tau_whichSF=0;
   int L1prefire_whichSF=0, genMET_whichSF=0, PUweight_whichSF=0;
   int Egamma_Statscale_whichSF=0, Egamma_Systscale_whichSF=0, Egamma_Gainscale_whichSF=0, Egamma_Rhoresol_whichSF=0, Egamma_Phiresol_whichSF=0;
   unsigned int whichPhoton=0, whichElectron=1, whichMuon=0, whichTau=0;
   unsigned int ISR_MC=0;
   vector<double> phoET;
   double MET=0, ST=0, ST_G=0, MT=0;
   double dphi_met_jet=999, dphi_met_H_candidate=999, dphi_met_Hmin_candidate=999;
   double e_pt=5, mu_pt=5, tau_pt=20;
   double w=0, xsec=1;
   //histograms
   TH1D *h_cuts;
   map< pair<int, int>, TH1D* > m_cuts;
   TH1D *h_PUweight;
   //histograms needed for SFs
   TH2F *h_pho_EGamma_SF2D[5];
   TH2F *h_ele_EGamma_SF2D[4];
   TH2F *h_ele_EGamma_EffMC2D[4];
   TH2F *h_eleRec_EGamma_SF2D[2];
   TH2D *h_Scaling_Factors_HasPix_R9_high;
   TH2D *h_Scaling_Factors_HasPix_R9_low;
   TH1F *h_PixelSeed_ScaleFactors_2017[4];
   TH2D *h_PixelSeed_ScaleFactors_2018;
   TH2D *h_PixelSeed_ScaleFactors_2018_unc;
   TH2D *h_muID_SF2D[3];
   TH2D *h_muISO_SF2D[3];
   TF1  *tf1_tau_ID_SF[3];
   TH2D *h_L1prefire_phoMap;
   TH2D *h_L1prefire_jetMap;
   TEfficiency* eff_b_Deep_L;
   TEfficiency* eff_b_Deep_M;
   TEfficiency* eff_b_Deep_T;
   TEfficiency* eff_c_Deep_L;
   TEfficiency* eff_c_Deep_M;
   TEfficiency* eff_c_Deep_T;
   TEfficiency* eff_l_Deep_L;
   TEfficiency* eff_l_Deep_M;
   TEfficiency* eff_l_Deep_T;
   TH1D *h_ISR_D;
   map< pair<int, int>, TH1D* > m_ISR_D;
   //histogram for Fake Rate
   TH2D *h2_FR;
   //hardcoded values for FR
   double _A=0.0308, _B=0.4942, _C=0.615192;
   EgammaScalingReader  EgammaScaling;
   EgammaSmearingReader EgammaSmearing;

   Analyzer(TTree *tree=0);
   virtual ~Analyzer();
   Analyzer(vector<string> arg={"default"}, string outname={"default"}, string btag_fname={""}, string xsec_fname={""}, bool fastSim=false, int fakeRate=0, vector<string> cut_variable={}, vector<string> cut_operator={}, vector<double> cut_value={}, bool is_q=0, bool is_signalscan=0, bool is_signalstudy=0, bool is_countSignal=0, int testrun=0, map<string,int> systematics={}, map<string,double> leptonpts={});
   virtual Int_t    Cut(Long64_t entry,pair<int,int> mass_pair);
   map<int,vector<int>> init_scan_histos(TFile *outFile, bool signalstudy, int SignalScenario);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   void             Systematics(map<string, int> systematics);
   double           deltaR(double phi1, double phi2, double eta1, double eta2);
   double           deltaPhi(double phi1, double phi2);
   float            Photon_SCEta(const int);
   float            Photon_SCEta_Zonly(const int);
   void             CalcBtagSF(bool fastsim, float v_eta[], vector<float> v_pt, int v_had[], map<int,char> passCut, TEfficiency *eff_b_L, TEfficiency *eff_c_L, TEfficiency *eff_l_L, TEfficiency *eff_b_M, TEfficiency *eff_c_M, TEfficiency *eff_l_M, TEfficiency *eff_b_T, TEfficiency *eff_c_T, TEfficiency *eff_l_T, BTCalibrationReader reader_L, BTCalibrationReader reader_M, BTCalibrationReader reader_T, BTCalibrationReader fastreader_L, BTCalibrationReader fastreader_M, BTCalibrationReader fastreader_T, double (&SF_L)[3], double (&SF_M)[3], double (&SF_T)[3]);
   void             CalcBtagSF_AK8(int year, vector<float> v_pt, map<int,char> passCut, double (&SF_L)[3], double (&SF_M1)[3], double (&SF_M2)[3], double (&SF_T1)[3], double (&SF_T2)[3]);
   void             Sort(vector<pair<int,int>> &v, vector<float> *b, vector<float> *bb, unsigned int operation);
   void             SelectAK4(vector<pair<int,int>> v, vector<float> *eta, vector<float> *phi, vector<float> *b, vector<float> *bb, vector<float> en, vector<float> pt, vector<int> ak4_hjets, vector<bool> &ak4selected, vector<int> &ak4trueselected);
   void             FillAK4tagging(vector<bool> ak4selected, vector<int> ak4trueselected, bool (&MassBtagAK4)[6], int (&true_higgsak4jet)[7]);
   virtual Bool_t   IsGoldEvent(UInt_t run, UInt_t LS);
};

#endif

#ifdef Analyzer_cxx
Analyzer::Analyzer(vector<string> arg, string outname, string btag_fname, string xsec_fname, bool fastSim, int fakeRate, vector<string> cut_variable, vector<string> cut_operator, vector<double> cut_value, bool is_q, bool is_signalscan, bool is_signalstudy, bool is_countSignal, int testrun, map<string,int> systematics, map<string,double> leptonpts) : fChain(0) 
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.

  _cut_variable=cut_variable;
  //determine which WP photons are cut on
  for (auto i : _cut_variable) {
    if (i=="nPassPhoM" || i=="nPassElePhoM") whichPhoton=1;
    if (i=="nPassPhoT" || i=="nPassElePhoT") whichPhoton=2;
    if (i=="nPassPhoMVA80" || i=="nPassElePhoMVA80") whichPhoton=3;
    if (i=="nPassPhoMVA90" || i=="nPassElePhoMVA90") whichPhoton=4;
    if (i=="nPassEleM") whichElectron=2;
    if (i=="nPassEleT") whichElectron=3;
    if (i=="nPassMuM") whichMuon=1;
    if (i=="nPassMuT") whichMuon=2;
    if (i=="nPassTauM") whichTau=1;
    if (i=="nPassTauT") whichTau=2;
    if (i=="nPassLepVLL") {whichElectron=0; whichMuon=0; whichTau=0;}
    if (i=="nPassLepMLL") {whichElectron=2; whichMuon=0; whichTau=0;}
    if (i=="nPassLepLLM") {whichElectron=1; whichMuon=0; whichTau=1;}
    if (i=="nPassLepLML") {whichElectron=1; whichMuon=1; whichTau=0;}
    if (i=="nPassLepL") {whichElectron=1; whichMuon=0; whichTau=0;}
    if (i=="nPassLepM") {whichElectron=2; whichMuon=1; whichTau=1;}
    if (i=="nPassLepT") {whichElectron=3; whichMuon=2; whichTau=2;}
  }
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
  if (xsec_fname!="") xsec_file=xsec_fname;
  if (fastSim) _fastSim=true;
  if (fakeRate) _fakeRate=fakeRate;
  if (testrun) _testRun=testrun;
  if (outname=="" && !is_quiet) std::cout<<"No output filename is defined, using: Analyzer_histos.root"<<std::endl;
  if (outname!="") output_file=outname;
  if (arg.size()==0) {
    const char* fdefault = "/data/SUSYNANO/Nano1June2019/Data/2016/SinglePhoton_Run2016B_ver2/88877510-EB32-DD4C-ACAB-A8B99C65E6A3.root/Events";
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
          std::cout<<"Wildcard found in input argument."<<std::endl;
        }
        temp+="/Events";
        ch->Add(temp.c_str());
        continue;
      }
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(cstr_i);
      if (!f || !f->IsOpen()) {
        f = new TFile(cstr_i);
      }
      temp+="/Events";
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
  string temp=tree->GetCurrentFile()->GetName();
  if (temp.find("T5qqqqHg")!=std::string::npos) SignalScenario=1;
  else if (temp.find("TChiNG")!=std::string::npos) SignalScenario=2;
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
   
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);
   
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("CaloMET_phi", &CaloMET_phi, &b_CaloMET_phi);
   fChain->SetBranchAddress("CaloMET_pt", &CaloMET_pt, &b_CaloMET_pt);
   fChain->SetBranchAddress("CaloMET_sumEt", &CaloMET_sumEt, &b_CaloMET_sumEt);
   fChain->SetBranchAddress("ChsMET_phi", &ChsMET_phi, &b_ChsMET_phi);
   fChain->SetBranchAddress("ChsMET_pt", &ChsMET_pt, &b_ChsMET_pt);
   fChain->SetBranchAddress("ChsMET_sumEt", &ChsMET_sumEt, &b_ChsMET_sumEt);
   fChain->SetBranchAddress("nCorrT1METJet", &nCorrT1METJet, &b_nCorrT1METJet);
   fChain->SetBranchAddress("CorrT1METJet_area", CorrT1METJet_area, &b_CorrT1METJet_area);
   fChain->SetBranchAddress("CorrT1METJet_eta", CorrT1METJet_eta, &b_CorrT1METJet_eta);
   fChain->SetBranchAddress("CorrT1METJet_muonSubtrFactor", CorrT1METJet_muonSubtrFactor, &b_CorrT1METJet_muonSubtrFactor);
   fChain->SetBranchAddress("CorrT1METJet_phi", CorrT1METJet_phi, &b_CorrT1METJet_phi);
   fChain->SetBranchAddress("CorrT1METJet_rawPt", CorrT1METJet_rawPt, &b_CorrT1METJet_rawPt);
   fChain->SetBranchAddress("nElectron", &nElectron, &b_nElectron);
   fChain->SetBranchAddress("Electron_deltaEtaSC", Electron_deltaEtaSC, &b_Electron_deltaEtaSC);
   fChain->SetBranchAddress("Electron_dr03EcalRecHitSumEt", Electron_dr03EcalRecHitSumEt, &b_Electron_dr03EcalRecHitSumEt);
   fChain->SetBranchAddress("Electron_dr03HcalDepth1TowerSumEt", Electron_dr03HcalDepth1TowerSumEt, &b_Electron_dr03HcalDepth1TowerSumEt);
   fChain->SetBranchAddress("Electron_dr03TkSumPt", Electron_dr03TkSumPt, &b_Electron_dr03TkSumPt);
   fChain->SetBranchAddress("Electron_dr03TkSumPtHEEP", Electron_dr03TkSumPtHEEP, &b_Electron_dr03TkSumPtHEEP);
   fChain->SetBranchAddress("Electron_dxy", Electron_dxy, &b_Electron_dxy);
   fChain->SetBranchAddress("Electron_dxyErr", Electron_dxyErr, &b_Electron_dxyErr);
   fChain->SetBranchAddress("Electron_dz", Electron_dz, &b_Electron_dz);
   fChain->SetBranchAddress("Electron_dzErr", Electron_dzErr, &b_Electron_dzErr);
   fChain->SetBranchAddress("Electron_eCorr", Electron_eCorr, &b_Electron_eCorr);
   fChain->SetBranchAddress("Electron_eInvMinusPInv", Electron_eInvMinusPInv, &b_Electron_eInvMinusPInv);
   fChain->SetBranchAddress("Electron_energyErr", Electron_energyErr, &b_Electron_energyErr);
   fChain->SetBranchAddress("Electron_eta", Electron_eta, &b_Electron_eta);
   fChain->SetBranchAddress("Electron_hoe", Electron_hoe, &b_Electron_hoe);
   fChain->SetBranchAddress("Electron_ip3d", Electron_ip3d, &b_Electron_ip3d);
   fChain->SetBranchAddress("Electron_jetPtRelv2", Electron_jetPtRelv2, &b_Electron_jetPtRelv2);
   fChain->SetBranchAddress("Electron_jetRelIso", Electron_jetRelIso, &b_Electron_jetRelIso);
   fChain->SetBranchAddress("Electron_mass", Electron_mass, &b_Electron_mass);
   fChain->SetBranchAddress("Electron_miniPFRelIso_all", Electron_miniPFRelIso_all, &b_Electron_miniPFRelIso_all);
   fChain->SetBranchAddress("Electron_miniPFRelIso_chg", Electron_miniPFRelIso_chg, &b_Electron_miniPFRelIso_chg);
   fChain->SetBranchAddress("Electron_mvaFall17V1Iso", Electron_mvaFall17V1Iso, &b_Electron_mvaFall17V1Iso);
   fChain->SetBranchAddress("Electron_mvaFall17V1noIso", Electron_mvaFall17V1noIso, &b_Electron_mvaFall17V1noIso);
   fChain->SetBranchAddress("Electron_mvaFall17V2Iso", Electron_mvaFall17V2Iso, &b_Electron_mvaFall17V2Iso);
   fChain->SetBranchAddress("Electron_mvaFall17V2noIso", Electron_mvaFall17V2noIso, &b_Electron_mvaFall17V2noIso);
   if (fChain->GetBranch("Electron_mvaSpring16GP")) fChain->SetBranchAddress("Electron_mvaSpring16GP", Electron_mvaSpring16GP, &b_Electron_mvaSpring16GP);
   if (fChain->GetBranch("Electron_mvaSpring16HZZ")) fChain->SetBranchAddress("Electron_mvaSpring16HZZ", Electron_mvaSpring16HZZ, &b_Electron_mvaSpring16HZZ);
   fChain->SetBranchAddress("Electron_pfRelIso03_all", Electron_pfRelIso03_all, &b_Electron_pfRelIso03_all);
   fChain->SetBranchAddress("Electron_pfRelIso03_chg", Electron_pfRelIso03_chg, &b_Electron_pfRelIso03_chg);
   fChain->SetBranchAddress("Electron_phi", Electron_phi, &b_Electron_phi);
   fChain->SetBranchAddress("Electron_pt", Electron_pt, &b_Electron_pt);
   fChain->SetBranchAddress("Electron_r9", Electron_r9, &b_Electron_r9);
   fChain->SetBranchAddress("Electron_sieie", Electron_sieie, &b_Electron_sieie);
   fChain->SetBranchAddress("Electron_sip3d", Electron_sip3d, &b_Electron_sip3d);
   fChain->SetBranchAddress("Electron_mvaTTH", Electron_mvaTTH, &b_Electron_mvaTTH);
   fChain->SetBranchAddress("Electron_charge", Electron_charge, &b_Electron_charge);
   fChain->SetBranchAddress("Electron_cutBased", Electron_cutBased, &b_Electron_cutBased);
   fChain->SetBranchAddress("Electron_cutBased_Fall17_V1", Electron_cutBased_Fall17_V1, &b_Electron_cutBased_Fall17_V1);
   if (fChain->GetBranch("Electron_cutBased_HLTPreSel")) fChain->SetBranchAddress("Electron_cutBased_HLTPreSel", Electron_cutBased_HLTPreSel, &b_Electron_cutBased_HLTPreSel);
   if (fChain->GetBranch("Electron_cutBased_Spring15")) fChain->SetBranchAddress("Electron_cutBased_Spring15", Electron_cutBased_Spring15, &b_Electron_cutBased_Spring15);
   if (fChain->GetBranch("Electron_cutBased_Sum16")) fChain->SetBranchAddress("Electron_cutBased_Sum16", Electron_cutBased_Sum16, &b_Electron_cutBased_Sum16);
   fChain->SetBranchAddress("Electron_jetIdx", Electron_jetIdx, &b_Electron_jetIdx);
   fChain->SetBranchAddress("Electron_pdgId", Electron_pdgId, &b_Electron_pdgId);
   fChain->SetBranchAddress("Electron_photonIdx", Electron_photonIdx, &b_Electron_photonIdx);
   fChain->SetBranchAddress("Electron_tightCharge", Electron_tightCharge, &b_Electron_tightCharge);
   fChain->SetBranchAddress("Electron_vidNestedWPBitmap", Electron_vidNestedWPBitmap, &b_Electron_vidNestedWPBitmap);
   if (fChain->GetBranch("Electron_vidNestedWPBitmapSpring15")) fChain->SetBranchAddress("Electron_vidNestedWPBitmapSpring15", Electron_vidNestedWPBitmapSpring15, &b_Electron_vidNestedWPBitmapSpring15);
   if (fChain->GetBranch("Electron_vidNestedWPBitmapSum16")) fChain->SetBranchAddress("Electron_vidNestedWPBitmapSum16", Electron_vidNestedWPBitmapSum16, &b_Electron_vidNestedWPBitmapSum16);
   fChain->SetBranchAddress("Electron_convVeto", Electron_convVeto, &b_Electron_convVeto);
   fChain->SetBranchAddress("Electron_cutBased_HEEP", Electron_cutBased_HEEP, &b_Electron_cutBased_HEEP);
   fChain->SetBranchAddress("Electron_isPFcand", Electron_isPFcand, &b_Electron_isPFcand);
   fChain->SetBranchAddress("Electron_lostHits", Electron_lostHits, &b_Electron_lostHits);
   fChain->SetBranchAddress("Electron_mvaFall17V1Iso_WP80", Electron_mvaFall17V1Iso_WP80, &b_Electron_mvaFall17V1Iso_WP80);
   fChain->SetBranchAddress("Electron_mvaFall17V1Iso_WP90", Electron_mvaFall17V1Iso_WP90, &b_Electron_mvaFall17V1Iso_WP90);
   fChain->SetBranchAddress("Electron_mvaFall17V1Iso_WPL", Electron_mvaFall17V1Iso_WPL, &b_Electron_mvaFall17V1Iso_WPL);
   fChain->SetBranchAddress("Electron_mvaFall17V1noIso_WP80", Electron_mvaFall17V1noIso_WP80, &b_Electron_mvaFall17V1noIso_WP80);
   fChain->SetBranchAddress("Electron_mvaFall17V1noIso_WP90", Electron_mvaFall17V1noIso_WP90, &b_Electron_mvaFall17V1noIso_WP90);
   fChain->SetBranchAddress("Electron_mvaFall17V1noIso_WPL", Electron_mvaFall17V1noIso_WPL, &b_Electron_mvaFall17V1noIso_WPL);
   fChain->SetBranchAddress("Electron_mvaFall17V2Iso_WP80", Electron_mvaFall17V2Iso_WP80, &b_Electron_mvaFall17V2Iso_WP80);
   fChain->SetBranchAddress("Electron_mvaFall17V2Iso_WP90", Electron_mvaFall17V2Iso_WP90, &b_Electron_mvaFall17V2Iso_WP90);
   fChain->SetBranchAddress("Electron_mvaFall17V2Iso_WPL", Electron_mvaFall17V2Iso_WPL, &b_Electron_mvaFall17V2Iso_WPL);
   fChain->SetBranchAddress("Electron_mvaFall17V2noIso_WP80", Electron_mvaFall17V2noIso_WP80, &b_Electron_mvaFall17V2noIso_WP80);
   fChain->SetBranchAddress("Electron_mvaFall17V2noIso_WP90", Electron_mvaFall17V2noIso_WP90, &b_Electron_mvaFall17V2noIso_WP90);
   fChain->SetBranchAddress("Electron_mvaFall17V2noIso_WPL", Electron_mvaFall17V2noIso_WPL, &b_Electron_mvaFall17V2noIso_WPL);
   if (fChain->GetBranch("Electron_mvaSpring16GP_WP80")) fChain->SetBranchAddress("Electron_mvaSpring16GP_WP80", Electron_mvaSpring16GP_WP80, &b_Electron_mvaSpring16GP_WP80);
   if (fChain->GetBranch("Electron_mvaSpring16GP_WP90")) fChain->SetBranchAddress("Electron_mvaSpring16GP_WP90", Electron_mvaSpring16GP_WP90, &b_Electron_mvaSpring16GP_WP90);
   if (fChain->GetBranch("Electron_mvaSpring16HZZ_WPL")) fChain->SetBranchAddress("Electron_mvaSpring16HZZ_WPL", Electron_mvaSpring16HZZ_WPL, &b_Electron_mvaSpring16HZZ_WPL);
   fChain->SetBranchAddress("Electron_seedGain", Electron_seedGain, &b_Electron_seedGain);
   fChain->SetBranchAddress("nFatJet", &nFatJet, &b_nFatJet);
   fChain->SetBranchAddress("FatJet_area", FatJet_area, &b_FatJet_area);
   fChain->SetBranchAddress("FatJet_btagCMVA", FatJet_btagCMVA, &b_FatJet_btagCMVA);
   fChain->SetBranchAddress("FatJet_btagCSVV2", FatJet_btagCSVV2, &b_FatJet_btagCSVV2);
   fChain->SetBranchAddress("FatJet_btagDDBvL", FatJet_btagDDBvL, &b_FatJet_btagDDBvL);
   fChain->SetBranchAddress("FatJet_btagDDCvB", FatJet_btagDDCvB, &b_FatJet_btagDDCvB);
   fChain->SetBranchAddress("FatJet_btagDDCvL", FatJet_btagDDCvL, &b_FatJet_btagDDCvL);
   fChain->SetBranchAddress("FatJet_btagDeepB", FatJet_btagDeepB, &b_FatJet_btagDeepB);
   fChain->SetBranchAddress("FatJet_btagHbb", FatJet_btagHbb, &b_FatJet_btagHbb);
   fChain->SetBranchAddress("FatJet_deepTagMD_H4qvsQCD", FatJet_deepTagMD_H4qvsQCD, &b_FatJet_deepTagMD_H4qvsQCD);
   fChain->SetBranchAddress("FatJet_deepTagMD_HbbvsQCD", FatJet_deepTagMD_HbbvsQCD, &b_FatJet_deepTagMD_HbbvsQCD);
   fChain->SetBranchAddress("FatJet_deepTagMD_TvsQCD", FatJet_deepTagMD_TvsQCD, &b_FatJet_deepTagMD_TvsQCD);
   fChain->SetBranchAddress("FatJet_deepTagMD_WvsQCD", FatJet_deepTagMD_WvsQCD, &b_FatJet_deepTagMD_WvsQCD);
   fChain->SetBranchAddress("FatJet_deepTagMD_ZHbbvsQCD", FatJet_deepTagMD_ZHbbvsQCD, &b_FatJet_deepTagMD_ZHbbvsQCD);
   fChain->SetBranchAddress("FatJet_deepTagMD_ZHccvsQCD", FatJet_deepTagMD_ZHccvsQCD, &b_FatJet_deepTagMD_ZHccvsQCD);
   fChain->SetBranchAddress("FatJet_deepTagMD_ZbbvsQCD", FatJet_deepTagMD_ZbbvsQCD, &b_FatJet_deepTagMD_ZbbvsQCD);
   fChain->SetBranchAddress("FatJet_deepTagMD_ZvsQCD", FatJet_deepTagMD_ZvsQCD, &b_FatJet_deepTagMD_ZvsQCD);
   fChain->SetBranchAddress("FatJet_deepTagMD_bbvsLight", FatJet_deepTagMD_bbvsLight, &b_FatJet_deepTagMD_bbvsLight);
   fChain->SetBranchAddress("FatJet_deepTagMD_ccvsLight", FatJet_deepTagMD_ccvsLight, &b_FatJet_deepTagMD_ccvsLight);
   fChain->SetBranchAddress("FatJet_deepTag_H", FatJet_deepTag_H, &b_FatJet_deepTag_H);
   fChain->SetBranchAddress("FatJet_deepTag_QCD", FatJet_deepTag_QCD, &b_FatJet_deepTag_QCD);
   fChain->SetBranchAddress("FatJet_deepTag_QCDothers", FatJet_deepTag_QCDothers, &b_FatJet_deepTag_QCDothers);
   fChain->SetBranchAddress("FatJet_deepTag_TvsQCD", FatJet_deepTag_TvsQCD, &b_FatJet_deepTag_TvsQCD);
   fChain->SetBranchAddress("FatJet_deepTag_WvsQCD", FatJet_deepTag_WvsQCD, &b_FatJet_deepTag_WvsQCD);
   fChain->SetBranchAddress("FatJet_deepTag_ZvsQCD", FatJet_deepTag_ZvsQCD, &b_FatJet_deepTag_ZvsQCD);
   fChain->SetBranchAddress("FatJet_eta", FatJet_eta, &b_FatJet_eta);
   fChain->SetBranchAddress("FatJet_mass", FatJet_mass, &b_FatJet_mass);
   fChain->SetBranchAddress("FatJet_msoftdrop", FatJet_msoftdrop, &b_FatJet_msoftdrop);
   fChain->SetBranchAddress("FatJet_msoftdrop_nom", FatJet_msoftdrop_nom, &b_FatJet_msoftdrop_nom);
   if (fChain->GetBranch("FatJet_msoftdrop_jerUp")) fChain->SetBranchAddress("FatJet_msoftdrop_jerUp", FatJet_msoftdrop_jerUp, &b_FatJet_msoftdrop_jerUp);
   if (fChain->GetBranch("FatJet_msoftdrop_jerDown")) fChain->SetBranchAddress("FatJet_msoftdrop_jerDown", FatJet_msoftdrop_jerDown, &b_FatJet_msoftdrop_jerDown);
   if (fChain->GetBranch("FatJet_msoftdrop_jesTotalUp")) fChain->SetBranchAddress("FatJet_msoftdrop_jesTotalUp", FatJet_msoftdrop_jesTotalUp, &b_FatJet_msoftdrop_jesTotalUp);
   if (fChain->GetBranch("FatJet_msoftdrop_jesTotalDown")) fChain->SetBranchAddress("FatJet_msoftdrop_jesTotalDown", FatJet_msoftdrop_jesTotalDown, &b_FatJet_msoftdrop_jesTotalDown);
   if (fChain->GetBranch("FatJet_msoftdrop_jmrUp")) fChain->SetBranchAddress("FatJet_msoftdrop_jmrUp", FatJet_msoftdrop_jmrUp, &b_FatJet_msoftdrop_jmrUp);
   if (fChain->GetBranch("FatJet_msoftdrop_jmrDown")) fChain->SetBranchAddress("FatJet_msoftdrop_jmrDown", FatJet_msoftdrop_jmrDown, &b_FatJet_msoftdrop_jmrDown);
   if (fChain->GetBranch("FatJet_msoftdrop_jmsUp")) fChain->SetBranchAddress("FatJet_msoftdrop_jmsUp", FatJet_msoftdrop_jmsUp, &b_FatJet_msoftdrop_jmsUp);
   if (fChain->GetBranch("FatJet_msoftdrop_jmsDown")) fChain->SetBranchAddress("FatJet_msoftdrop_jmsDown", FatJet_msoftdrop_jmsDown, &b_FatJet_msoftdrop_jmsDown);
   fChain->SetBranchAddress("FatJet_n2b1", FatJet_n2b1, &b_FatJet_n2b1);
   fChain->SetBranchAddress("FatJet_n3b1", FatJet_n3b1, &b_FatJet_n3b1);
   fChain->SetBranchAddress("FatJet_phi", FatJet_phi, &b_FatJet_phi);
   fChain->SetBranchAddress("FatJet_pt", FatJet_pt, &b_FatJet_pt);
   fChain->SetBranchAddress("FatJet_pt_nom", FatJet_pt_nom, &b_FatJet_pt_nom);
   if (fChain->GetBranch("FatJet_pt_jerUp")) fChain->SetBranchAddress("FatJet_pt_jerUp", FatJet_pt_jerUp, &b_FatJet_pt_jerUp);
   if (fChain->GetBranch("FatJet_pt_jerDown")) fChain->SetBranchAddress("FatJet_pt_jerDown", FatJet_pt_jerDown, &b_FatJet_pt_jerDown);
   if (fChain->GetBranch("FatJet_pt_jesTotalUp")) fChain->SetBranchAddress("FatJet_pt_jesTotalUp", FatJet_pt_jesTotalUp, &b_FatJet_pt_jesTotalUp);
   if (fChain->GetBranch("FatJet_pt_jesTotalDown")) fChain->SetBranchAddress("FatJet_pt_jesTotalDown", FatJet_pt_jesTotalDown, &b_FatJet_pt_jesTotalDown);
   fChain->SetBranchAddress("FatJet_rawFactor", FatJet_rawFactor, &b_FatJet_rawFactor);
   fChain->SetBranchAddress("FatJet_tau1", FatJet_tau1, &b_FatJet_tau1);
   fChain->SetBranchAddress("FatJet_tau2", FatJet_tau2, &b_FatJet_tau2);
   fChain->SetBranchAddress("FatJet_tau3", FatJet_tau3, &b_FatJet_tau3);
   fChain->SetBranchAddress("FatJet_tau4", FatJet_tau4, &b_FatJet_tau4);
   fChain->SetBranchAddress("FatJet_jetId", FatJet_jetId, &b_FatJet_jetId);
   fChain->SetBranchAddress("FatJet_subJetIdx1", FatJet_subJetIdx1, &b_FatJet_subJetIdx1);
   fChain->SetBranchAddress("FatJet_subJetIdx2", FatJet_subJetIdx2, &b_FatJet_subJetIdx2);
   if (fChain->GetBranch("nGenJetAK8")) fChain->SetBranchAddress("nGenJetAK8", &nGenJetAK8, &b_nGenJetAK8);
   if (fChain->GetBranch("GenJetAK8_eta")) fChain->SetBranchAddress("GenJetAK8_eta", GenJetAK8_eta, &b_GenJetAK8_eta);
   if (fChain->GetBranch("GenJetAK8_mass")) fChain->SetBranchAddress("GenJetAK8_mass", GenJetAK8_mass, &b_GenJetAK8_mass);
   if (fChain->GetBranch("GenJetAK8_phi")) fChain->SetBranchAddress("GenJetAK8_phi", GenJetAK8_phi, &b_GenJetAK8_phi);
   if (fChain->GetBranch("GenJetAK8_pt")) fChain->SetBranchAddress("GenJetAK8_pt", GenJetAK8_pt, &b_GenJetAK8_pt);
   if (fChain->GetBranch("nGenJet")) fChain->SetBranchAddress("nGenJet", &nGenJet, &b_nGenJet);
   if (fChain->GetBranch("GenJet_eta")) fChain->SetBranchAddress("GenJet_eta", GenJet_eta, &b_GenJet_eta);
   if (fChain->GetBranch("GenJet_mass")) fChain->SetBranchAddress("GenJet_mass", GenJet_mass, &b_GenJet_mass);
   if (fChain->GetBranch("GenJet_phi")) fChain->SetBranchAddress("GenJet_phi", GenJet_phi, &b_GenJet_phi);
   if (fChain->GetBranch("GenJet_pt")) fChain->SetBranchAddress("GenJet_pt", GenJet_pt, &b_GenJet_pt);
   if (fChain->GetBranch("nGenPart")) fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   if (fChain->GetBranch("GenPart_eta")) fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   if (fChain->GetBranch("GenPart_mass")) fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   if (fChain->GetBranch("GenPart_phi")) fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   if (fChain->GetBranch("GenPart_pt")) fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   if (fChain->GetBranch("GenPart_genPartIdxMother")) fChain->SetBranchAddress("GenPart_genPartIdxMother", GenPart_genPartIdxMother, &b_GenPart_genPartIdxMother);
   if (fChain->GetBranch("GenPart_pdgId")) fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   if (fChain->GetBranch("GenPart_status")) fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   if (fChain->GetBranch("GenPart_statusFlags")) fChain->SetBranchAddress("GenPart_statusFlags", GenPart_statusFlags, &b_GenPart_statusFlags);
   if (fChain->GetBranch("nSubGenJetAK8")) fChain->SetBranchAddress("nSubGenJetAK8", &nSubGenJetAK8, &b_nSubGenJetAK8);
   if (fChain->GetBranch("SubGenJetAK8_eta")) fChain->SetBranchAddress("SubGenJetAK8_eta", SubGenJetAK8_eta, &b_SubGenJetAK8_eta);
   if (fChain->GetBranch("SubGenJetAK8_mass")) fChain->SetBranchAddress("SubGenJetAK8_mass", SubGenJetAK8_mass, &b_SubGenJetAK8_mass);
   if (fChain->GetBranch("SubGenJetAK8_phi")) fChain->SetBranchAddress("SubGenJetAK8_phi", SubGenJetAK8_phi, &b_SubGenJetAK8_phi);
   if (fChain->GetBranch("SubGenJetAK8_pt")) fChain->SetBranchAddress("SubGenJetAK8_pt", SubGenJetAK8_pt, &b_SubGenJetAK8_pt);
   if (fChain->GetBranch("Generator_binvar")) fChain->SetBranchAddress("Generator_binvar", &Generator_binvar, &b_Generator_binvar);
   if (fChain->GetBranch("Generator_scalePDF")) fChain->SetBranchAddress("Generator_scalePDF", &Generator_scalePDF, &b_Generator_scalePDF);
   if (fChain->GetBranch("Generator_weight")) fChain->SetBranchAddress("Generator_weight", &Generator_weight, &b_Generator_weight);
   if (fChain->GetBranch("Generator_x1")) fChain->SetBranchAddress("Generator_x1", &Generator_x1, &b_Generator_x1);
   if (fChain->GetBranch("Generator_x2")) fChain->SetBranchAddress("Generator_x2", &Generator_x2, &b_Generator_x2);
   if (fChain->GetBranch("Generator_xpdf1")) fChain->SetBranchAddress("Generator_xpdf1", &Generator_xpdf1, &b_Generator_xpdf1);
   if (fChain->GetBranch("Generator_xpdf2")) fChain->SetBranchAddress("Generator_xpdf2", &Generator_xpdf2, &b_Generator_xpdf2);
   if (fChain->GetBranch("Generator_id1")) fChain->SetBranchAddress("Generator_id1", &Generator_id1, &b_Generator_id1);
   if (fChain->GetBranch("Generator_id2")) fChain->SetBranchAddress("Generator_id2", &Generator_id2, &b_Generator_id2);
   if (fChain->GetBranch("nGenVisTau")) fChain->SetBranchAddress("nGenVisTau", &nGenVisTau, &b_nGenVisTau);
   if (fChain->GetBranch("GenVisTau_eta")) fChain->SetBranchAddress("GenVisTau_eta", GenVisTau_eta, &b_GenVisTau_eta);
   if (fChain->GetBranch("GenVisTau_mass")) fChain->SetBranchAddress("GenVisTau_mass", GenVisTau_mass, &b_GenVisTau_mass);
   if (fChain->GetBranch("GenVisTau_phi")) fChain->SetBranchAddress("GenVisTau_phi", GenVisTau_phi, &b_GenVisTau_phi);
   if (fChain->GetBranch("GenVisTau_pt")) fChain->SetBranchAddress("GenVisTau_pt", GenVisTau_pt, &b_GenVisTau_pt);
   if (fChain->GetBranch("GenVisTau_charge")) fChain->SetBranchAddress("GenVisTau_charge", GenVisTau_charge, &b_GenVisTau_charge);
   if (fChain->GetBranch("GenVisTau_genPartIdxMother")) fChain->SetBranchAddress("GenVisTau_genPartIdxMother", GenVisTau_genPartIdxMother, &b_GenVisTau_genPartIdxMother);
   if (fChain->GetBranch("GenVisTau_status")) fChain->SetBranchAddress("GenVisTau_status", GenVisTau_status, &b_GenVisTau_status);
   if (fChain->GetBranch("genWeight")) fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   if (fChain->GetBranch("puWeight")) fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   if (fChain->GetBranch("puWeightUp")) fChain->SetBranchAddress("puWeightUp", &puWeightUp, &b_puWeightUp);
   if (fChain->GetBranch("puWeightDown")) fChain->SetBranchAddress("puWeightDown", &puWeightDown, &b_puWeightDown);
   if (fChain->GetBranch("nPSWeight")) fChain->SetBranchAddress("nPSWeight", &nPSWeight, &b_nPSWeight);
   if (fChain->GetBranch("PSWeight")) fChain->SetBranchAddress("PSWeight", PSWeight, &b_PSWeight);
   fChain->SetBranchAddress("nIsoTrack", &nIsoTrack, &b_nIsoTrack);
   fChain->SetBranchAddress("IsoTrack_dxy", IsoTrack_dxy, &b_IsoTrack_dxy);
   fChain->SetBranchAddress("IsoTrack_dz", IsoTrack_dz, &b_IsoTrack_dz);
   fChain->SetBranchAddress("IsoTrack_eta", IsoTrack_eta, &b_IsoTrack_eta);
   fChain->SetBranchAddress("IsoTrack_pfRelIso03_all", IsoTrack_pfRelIso03_all, &b_IsoTrack_pfRelIso03_all);
   fChain->SetBranchAddress("IsoTrack_pfRelIso03_chg", IsoTrack_pfRelIso03_chg, &b_IsoTrack_pfRelIso03_chg);
   fChain->SetBranchAddress("IsoTrack_phi", IsoTrack_phi, &b_IsoTrack_phi);
   fChain->SetBranchAddress("IsoTrack_pt", IsoTrack_pt, &b_IsoTrack_pt);
   fChain->SetBranchAddress("IsoTrack_miniPFRelIso_all", IsoTrack_miniPFRelIso_all, &b_IsoTrack_miniPFRelIso_all);
   fChain->SetBranchAddress("IsoTrack_miniPFRelIso_chg", IsoTrack_miniPFRelIso_chg, &b_IsoTrack_miniPFRelIso_chg);
   fChain->SetBranchAddress("IsoTrack_fromPV", IsoTrack_fromPV, &b_IsoTrack_fromPV);
   fChain->SetBranchAddress("IsoTrack_pdgId", IsoTrack_pdgId, &b_IsoTrack_pdgId);
   fChain->SetBranchAddress("IsoTrack_isHighPurityTrack", IsoTrack_isHighPurityTrack, &b_IsoTrack_isHighPurityTrack);
   fChain->SetBranchAddress("IsoTrack_isPFcand", IsoTrack_isPFcand, &b_IsoTrack_isPFcand);
   fChain->SetBranchAddress("IsoTrack_isFromLostTrack", IsoTrack_isFromLostTrack, &b_IsoTrack_isFromLostTrack);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_area", Jet_area, &b_Jet_area);
   fChain->SetBranchAddress("Jet_btagCMVA", Jet_btagCMVA, &b_Jet_btagCMVA);
   fChain->SetBranchAddress("Jet_btagCSVV2", Jet_btagCSVV2, &b_Jet_btagCSVV2);
   fChain->SetBranchAddress("Jet_btagDeepB", Jet_btagDeepB, &b_Jet_btagDeepB);
   fChain->SetBranchAddress("Jet_btagDeepC", Jet_btagDeepC, &b_Jet_btagDeepC);
   fChain->SetBranchAddress("Jet_btagDeepFlavB", Jet_btagDeepFlavB, &b_Jet_btagDeepFlavB);
   fChain->SetBranchAddress("Jet_btagDeepFlavC", Jet_btagDeepFlavC, &b_Jet_btagDeepFlavC);
   fChain->SetBranchAddress("Jet_chEmEF", Jet_chEmEF, &b_Jet_chEmEF);
   fChain->SetBranchAddress("Jet_chHEF", Jet_chHEF, &b_Jet_chHEF);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_jercCHF", Jet_jercCHF, &b_Jet_jercCHF);
   fChain->SetBranchAddress("Jet_jercCHPUF", Jet_jercCHPUF, &b_Jet_jercCHPUF);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   //fChain->SetBranchAddress("Jet_mass_nom", Jet_mass_nom, &b_Jet_mass_nom);
   if (fChain->GetBranch("Jet_mass_jerUp")) fChain->SetBranchAddress("Jet_mass_jerUp", Jet_mass_jerUp, &b_Jet_mass_jerUp);
   if (fChain->GetBranch("Jet_mass_jerDown")) fChain->SetBranchAddress("Jet_mass_jerDown", Jet_mass_jerDown, &b_Jet_mass_jerDown);
   if (fChain->GetBranch("Jet_mass_jesTotalUp")) fChain->SetBranchAddress("Jet_mass_jesTotalUp", Jet_mass_jesTotalUp, &b_Jet_mass_jesTotalUp);
   if (fChain->GetBranch("Jet_mass_jesTotalDown")) fChain->SetBranchAddress("Jet_mass_jesTotalDown", Jet_mass_jesTotalDown, &b_Jet_mass_jesTotalDown);
   fChain->SetBranchAddress("Jet_muEF", Jet_muEF, &b_Jet_muEF);
   fChain->SetBranchAddress("Jet_muonSubtrFactor", Jet_muonSubtrFactor, &b_Jet_muonSubtrFactor);
   fChain->SetBranchAddress("Jet_neEmEF", Jet_neEmEF, &b_Jet_neEmEF);
   fChain->SetBranchAddress("Jet_neHEF", Jet_neHEF, &b_Jet_neHEF);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_pt_nom", Jet_pt_nom, &b_Jet_pt_nom);
   fChain->SetBranchAddress("Jet_pt_raw", Jet_pt_raw, &b_Jet_pt_raw);
   if (fChain->GetBranch("Jet_pt_jerUp")) fChain->SetBranchAddress("Jet_pt_jerUp", Jet_pt_jerUp, &b_Jet_pt_jerUp);
   if (fChain->GetBranch("Jet_pt_jerDown")) fChain->SetBranchAddress("Jet_pt_jerDown", Jet_pt_jerDown, &b_Jet_pt_jerDown);
   if (fChain->GetBranch("Jet_pt_jesTotalUp")) fChain->SetBranchAddress("Jet_pt_jesTotalUp", Jet_pt_jesTotalUp, &b_Jet_pt_jesTotalUp);
   if (fChain->GetBranch("Jet_pt_jesTotalDown")) fChain->SetBranchAddress("Jet_pt_jesTotalDown", Jet_pt_jesTotalDown, &b_Jet_pt_jesTotalDown);
   fChain->SetBranchAddress("Jet_qgl", Jet_qgl, &b_Jet_qgl);
   fChain->SetBranchAddress("Jet_rawFactor", Jet_rawFactor, &b_Jet_rawFactor);
   fChain->SetBranchAddress("Jet_bRegCorr", Jet_bRegCorr, &b_Jet_bRegCorr);
   fChain->SetBranchAddress("Jet_bRegRes", Jet_bRegRes, &b_Jet_bRegRes);
   fChain->SetBranchAddress("Jet_electronIdx1", Jet_electronIdx1, &b_Jet_electronIdx1);
   fChain->SetBranchAddress("Jet_electronIdx2", Jet_electronIdx2, &b_Jet_electronIdx2);
   fChain->SetBranchAddress("Jet_jetId", Jet_jetId, &b_Jet_jetId);
   fChain->SetBranchAddress("Jet_muonIdx1", Jet_muonIdx1, &b_Jet_muonIdx1);
   fChain->SetBranchAddress("Jet_muonIdx2", Jet_muonIdx2, &b_Jet_muonIdx2);
   fChain->SetBranchAddress("Jet_nConstituents", Jet_nConstituents, &b_Jet_nConstituents);
   fChain->SetBranchAddress("Jet_nElectrons", Jet_nElectrons, &b_Jet_nElectrons);
   fChain->SetBranchAddress("Jet_nMuons", Jet_nMuons, &b_Jet_nMuons);
   fChain->SetBranchAddress("Jet_puId", Jet_puId, &b_Jet_puId);
   if (fChain->GetBranch("L1PreFiringWeight_Dn")) fChain->SetBranchAddress("L1PreFiringWeight_Dn", &L1PreFiringWeight_Dn, &b_L1PreFiringWeight_Dn);
   if (fChain->GetBranch("L1PreFiringWeight_Nom")) fChain->SetBranchAddress("L1PreFiringWeight_Nom", &L1PreFiringWeight_Nom, &b_L1PreFiringWeight_Nom);
   if (fChain->GetBranch("L1PreFiringWeight_Up")) fChain->SetBranchAddress("L1PreFiringWeight_Up", &L1PreFiringWeight_Up, &b_L1PreFiringWeight_Up);
   if (fChain->GetBranch("GenMET_phi")) fChain->SetBranchAddress("GenMET_phi", &GenMET_phi, &b_GenMET_phi);
   if (fChain->GetBranch("GenMET_pt")) fChain->SetBranchAddress("GenMET_pt", &GenMET_pt, &b_GenMET_pt);
   fChain->SetBranchAddress("MET_MetUnclustEnUpDeltaX", &MET_MetUnclustEnUpDeltaX, &b_MET_MetUnclustEnUpDeltaX);
   fChain->SetBranchAddress("MET_MetUnclustEnUpDeltaY", &MET_MetUnclustEnUpDeltaY, &b_MET_MetUnclustEnUpDeltaY);
   fChain->SetBranchAddress("MET_covXX", &MET_covXX, &b_MET_covXX);
   fChain->SetBranchAddress("MET_covXY", &MET_covXY, &b_MET_covXY);
   fChain->SetBranchAddress("MET_covYY", &MET_covYY, &b_MET_covYY);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   if (fChain->GetBranch("MET_phi_nom")) fChain->SetBranchAddress("MET_phi_nom", &MET_phi_nom, &b_MET_phi_nom);
   if (fChain->GetBranch("MET_phi_jer")) fChain->SetBranchAddress("MET_phi_jer", &MET_phi_jer, &b_MET_phi_jer);
   if (fChain->GetBranch("MET_phi_jerUp")) fChain->SetBranchAddress("MET_phi_jerUp", &MET_phi_jerUp, &b_MET_phi_jerUp);
   if (fChain->GetBranch("MET_phi_jerDown")) fChain->SetBranchAddress("MET_phi_jerDown", &MET_phi_jerDown, &b_MET_phi_jerDown);
   if (fChain->GetBranch("MET_phi_jesTotalUp")) fChain->SetBranchAddress("MET_phi_jesTotalUp", &MET_phi_jesTotalUp, &b_MET_phi_jesTotalUp);
   if (fChain->GetBranch("MET_phi_jesTotalDown")) fChain->SetBranchAddress("MET_phi_jesTotalDown", &MET_phi_jesTotalDown, &b_MET_phi_jesTotalDown);
   if (fChain->GetBranch("MET_phi_unclustEnUp")) fChain->SetBranchAddress("MET_phi_unclustEnUp", &MET_phi_unclustEnUp, &b_MET_phi_unclustEnUp);
   if (fChain->GetBranch("MET_phi_unclustEnDown")) fChain->SetBranchAddress("MET_phi_unclustEnDown", &MET_phi_unclustEnDown, &b_MET_phi_unclustEnDown);
   fChain->SetBranchAddress("MET_pt", &MET_pt, &b_MET_pt);
   if (fChain->GetBranch("MET_pt_nom")) fChain->SetBranchAddress("MET_pt_nom", &MET_pt_nom, &b_MET_pt_nom);
   if (fChain->GetBranch("MET_pt_jer")) fChain->SetBranchAddress("MET_pt_jer", &MET_pt_jer, &b_MET_pt_jer);
   if (fChain->GetBranch("MET_pt_jerUp")) fChain->SetBranchAddress("MET_pt_jerUp", &MET_pt_jerUp, &b_MET_pt_jerUp);
   if (fChain->GetBranch("MET_pt_jerDown")) fChain->SetBranchAddress("MET_pt_jerDown", &MET_pt_jerDown, &b_MET_pt_jerDown);
   if (fChain->GetBranch("MET_pt_jesTotalUp")) fChain->SetBranchAddress("MET_pt_jesTotalUp", &MET_pt_jesTotalUp, &b_MET_pt_jesTotalUp);
   if (fChain->GetBranch("MET_pt_jesTotalDown")) fChain->SetBranchAddress("MET_pt_jesTotalDown", &MET_pt_jesTotalDown, &b_MET_pt_jesTotalDown);
   if (fChain->GetBranch("MET_pt_unclustEnUp")) fChain->SetBranchAddress("MET_pt_unclustEnUp", &MET_pt_unclustEnUp, &b_MET_pt_unclustEnUp);
   if (fChain->GetBranch("MET_pt_unclustEnDown")) fChain->SetBranchAddress("MET_pt_unclustEnDown", &MET_pt_unclustEnDown, &b_MET_pt_unclustEnDown);
   if (fChain->GetBranch("MET_significance")) fChain->SetBranchAddress("MET_significance", &MET_significance, &b_MET_significance);
   if (fChain->GetBranch("MET_sumEt")) fChain->SetBranchAddress("MET_sumEt", &MET_sumEt, &b_MET_sumEt);
   if (fChain->GetBranch("METFixEE2017_MetUnclustEnUpDeltaX")) fChain->SetBranchAddress("METFixEE2017_MetUnclustEnUpDeltaX", &METFixEE2017_MetUnclustEnUpDeltaX, &b_METFixEE2017_MetUnclustEnUpDeltaX);
   if (fChain->GetBranch("METFixEE2017_MetUnclustEnUpDeltaY")) fChain->SetBranchAddress("METFixEE2017_MetUnclustEnUpDeltaY", &METFixEE2017_MetUnclustEnUpDeltaY, &b_METFixEE2017_MetUnclustEnUpDeltaY);
   if (fChain->GetBranch("METFixEE2017_covXX")) fChain->SetBranchAddress("METFixEE2017_covXX", &METFixEE2017_covXX, &b_METFixEE2017_covXX);
   if (fChain->GetBranch("METFixEE2017_covXY")) fChain->SetBranchAddress("METFixEE2017_covXY", &METFixEE2017_covXY, &b_METFixEE2017_covXY);
   if (fChain->GetBranch("METFixEE2017_covYY")) fChain->SetBranchAddress("METFixEE2017_covYY", &METFixEE2017_covYY, &b_METFixEE2017_covYY);
   if (fChain->GetBranch("METFixEE2017_phi")) fChain->SetBranchAddress("METFixEE2017_phi", &METFixEE2017_phi, &b_METFixEE2017_phi);
   if (fChain->GetBranch("METFixEE2017_phi_nom")) fChain->SetBranchAddress("METFixEE2017_phi_nom", &METFixEE2017_phi_nom, &b_METFixEE2017_phi_nom);
   if (fChain->GetBranch("METFixEE2017_phi_jer")) fChain->SetBranchAddress("METFixEE2017_phi_jer", &METFixEE2017_phi_jer, &b_METFixEE2017_phi_jer);
   if (fChain->GetBranch("METFixEE2017_phi_jerUp")) fChain->SetBranchAddress("METFixEE2017_phi_jerUp", &METFixEE2017_phi_jerUp, &b_METFixEE2017_phi_jerUp);
   if (fChain->GetBranch("METFixEE2017_phi_jerDown")) fChain->SetBranchAddress("METFixEE2017_phi_jerDown", &METFixEE2017_phi_jerDown, &b_METFixEE2017_phi_jerDown);
   if (fChain->GetBranch("METFixEE2017_phi_jesTotalUp")) fChain->SetBranchAddress("METFixEE2017_phi_jesTotalUp", &METFixEE2017_phi_jesTotalUp, &b_METFixEE2017_phi_jesTotalUp);
   if (fChain->GetBranch("METFixEE2017_phi_jesTotalDown")) fChain->SetBranchAddress("METFixEE2017_phi_jesTotalDown", &METFixEE2017_phi_jesTotalDown, &b_METFixEE2017_phi_jesTotalDown);
   if (fChain->GetBranch("METFixEE2017_phi_unclustEnUp")) fChain->SetBranchAddress("METFixEE2017_phi_unclustEnUp", &METFixEE2017_phi_unclustEnUp, &b_METFixEE2017_phi_unclustEnUp);
   if (fChain->GetBranch("METFixEE2017_phi_unclustEnDown")) fChain->SetBranchAddress("METFixEE2017_phi_unclustEnDown", &METFixEE2017_phi_unclustEnDown, &b_METFixEE2017_phi_unclustEnDown);
   if (fChain->GetBranch("METFixEE2017_pt")) fChain->SetBranchAddress("METFixEE2017_pt", &METFixEE2017_pt, &b_METFixEE2017_pt);
   if (fChain->GetBranch("METFixEE2017_pt_nom")) fChain->SetBranchAddress("METFixEE2017_pt_nom", &METFixEE2017_pt_nom, &b_METFixEE2017_pt_nom);
   if (fChain->GetBranch("METFixEE2017_pt_jer")) fChain->SetBranchAddress("METFixEE2017_pt_jer", &METFixEE2017_pt_jer, &b_METFixEE2017_pt_jer);
   if (fChain->GetBranch("METFixEE2017_pt_jerUp")) fChain->SetBranchAddress("METFixEE2017_pt_jerUp", &METFixEE2017_pt_jerUp, &b_METFixEE2017_pt_jerUp);
   if (fChain->GetBranch("METFixEE2017_pt_jerDown")) fChain->SetBranchAddress("METFixEE2017_pt_jerDown", &METFixEE2017_pt_jerDown, &b_METFixEE2017_pt_jerDown);
   if (fChain->GetBranch("METFixEE2017_pt_jesTotalUp")) fChain->SetBranchAddress("METFixEE2017_pt_jesTotalUp", &METFixEE2017_pt_jesTotalUp, &b_METFixEE2017_pt_jesTotalUp);
   if (fChain->GetBranch("METFixEE2017_pt_jesTotalDown")) fChain->SetBranchAddress("METFixEE2017_pt_jesTotalDown", &METFixEE2017_pt_jesTotalDown, &b_METFixEE2017_pt_jesTotalDown);
   if (fChain->GetBranch("METFixEE2017_pt_unclustEnUp")) fChain->SetBranchAddress("METFixEE2017_pt_unclustEnUp", &METFixEE2017_pt_unclustEnUp, &b_METFixEE2017_pt_unclustEnUp);
   if (fChain->GetBranch("METFixEE2017_pt_unclustEnDown")) fChain->SetBranchAddress("METFixEE2017_pt_unclustEnDown", &METFixEE2017_pt_unclustEnDown, &b_METFixEE2017_pt_unclustEnDown);
   if (fChain->GetBranch("METFixEE2017_significance")) fChain->SetBranchAddress("METFixEE2017_significance", &METFixEE2017_significance, &b_METFixEE2017_significance);
   if (fChain->GetBranch("METFixEE2017_sumEt")) fChain->SetBranchAddress("METFixEE2017_sumEt", &METFixEE2017_sumEt, &b_METFixEE2017_sumEt);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   fChain->SetBranchAddress("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
   fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
   fChain->SetBranchAddress("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_ip3d", Muon_ip3d, &b_Muon_ip3d);
   fChain->SetBranchAddress("Muon_jetPtRelv2", Muon_jetPtRelv2, &b_Muon_jetPtRelv2);
   fChain->SetBranchAddress("Muon_jetRelIso", Muon_jetRelIso, &b_Muon_jetRelIso);
   fChain->SetBranchAddress("Muon_mass", Muon_mass, &b_Muon_mass);
   fChain->SetBranchAddress("Muon_miniPFRelIso_all", Muon_miniPFRelIso_all, &b_Muon_miniPFRelIso_all);
   fChain->SetBranchAddress("Muon_miniPFRelIso_chg", Muon_miniPFRelIso_chg, &b_Muon_miniPFRelIso_chg);
   fChain->SetBranchAddress("Muon_pfRelIso03_all", Muon_pfRelIso03_all, &b_Muon_pfRelIso03_all);
   fChain->SetBranchAddress("Muon_pfRelIso03_chg", Muon_pfRelIso03_chg, &b_Muon_pfRelIso03_chg);
   fChain->SetBranchAddress("Muon_pfRelIso04_all", Muon_pfRelIso04_all, &b_Muon_pfRelIso04_all);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_ptErr", Muon_ptErr, &b_Muon_ptErr);
   fChain->SetBranchAddress("Muon_segmentComp", Muon_segmentComp, &b_Muon_segmentComp);
   fChain->SetBranchAddress("Muon_sip3d", Muon_sip3d, &b_Muon_sip3d);
   fChain->SetBranchAddress("Muon_tkRelIso", Muon_tkRelIso, &b_Muon_tkRelIso);
   fChain->SetBranchAddress("Muon_tunepRelPt", Muon_tunepRelPt, &b_Muon_tunepRelPt);
   fChain->SetBranchAddress("Muon_mvaLowPt", Muon_mvaLowPt, &b_Muon_mvaLowPt);
   fChain->SetBranchAddress("Muon_mvaTTH", Muon_mvaTTH, &b_Muon_mvaTTH);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_jetIdx", Muon_jetIdx, &b_Muon_jetIdx);
   fChain->SetBranchAddress("Muon_nStations", Muon_nStations, &b_Muon_nStations);
   fChain->SetBranchAddress("Muon_nTrackerLayers", Muon_nTrackerLayers, &b_Muon_nTrackerLayers);
   fChain->SetBranchAddress("Muon_pdgId", Muon_pdgId, &b_Muon_pdgId);
   fChain->SetBranchAddress("Muon_tightCharge", Muon_tightCharge, &b_Muon_tightCharge);
   fChain->SetBranchAddress("Muon_highPtId", Muon_highPtId, &b_Muon_highPtId);
   fChain->SetBranchAddress("Muon_inTimeMuon", Muon_inTimeMuon, &b_Muon_inTimeMuon);
   fChain->SetBranchAddress("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
   fChain->SetBranchAddress("Muon_isPFcand", Muon_isPFcand, &b_Muon_isPFcand);
   fChain->SetBranchAddress("Muon_isTracker", Muon_isTracker, &b_Muon_isTracker);
   fChain->SetBranchAddress("Muon_looseId", Muon_looseId, &b_Muon_looseId);
   fChain->SetBranchAddress("Muon_mediumId", Muon_mediumId, &b_Muon_mediumId);
   fChain->SetBranchAddress("Muon_mediumPromptId", Muon_mediumPromptId, &b_Muon_mediumPromptId);
   fChain->SetBranchAddress("Muon_miniIsoId", Muon_miniIsoId, &b_Muon_miniIsoId);
   fChain->SetBranchAddress("Muon_multiIsoId", Muon_multiIsoId, &b_Muon_multiIsoId);
   fChain->SetBranchAddress("Muon_mvaId", Muon_mvaId, &b_Muon_mvaId);
   fChain->SetBranchAddress("Muon_pfIsoId", Muon_pfIsoId, &b_Muon_pfIsoId);
   fChain->SetBranchAddress("Muon_softId", Muon_softId, &b_Muon_softId);
   fChain->SetBranchAddress("Muon_softMvaId", Muon_softMvaId, &b_Muon_softMvaId);
   fChain->SetBranchAddress("Muon_tightId", Muon_tightId, &b_Muon_tightId);
   fChain->SetBranchAddress("Muon_tkIsoId", Muon_tkIsoId, &b_Muon_tkIsoId);
   fChain->SetBranchAddress("Muon_triggerIdLoose", Muon_triggerIdLoose, &b_Muon_triggerIdLoose);
   fChain->SetBranchAddress("nPhoton", &nPhoton, &b_nPhoton);
   fChain->SetBranchAddress("Photon_eCorr", Photon_eCorr, &b_Photon_eCorr);
   fChain->SetBranchAddress("Photon_energyErr", Photon_energyErr, &b_Photon_energyErr);
   fChain->SetBranchAddress("Photon_eta", Photon_eta, &b_Photon_eta);
   fChain->SetBranchAddress("Photon_hoe", Photon_hoe, &b_Photon_hoe);
   fChain->SetBranchAddress("Photon_mass", Photon_mass, &b_Photon_mass);
   fChain->SetBranchAddress("Photon_mvaID", Photon_mvaID, &b_Photon_mvaID);
   if (fChain->GetBranch("Photon_mvaID17")) fChain->SetBranchAddress("Photon_mvaID17", Photon_mvaID17, &b_Photon_mvaID17);
   fChain->SetBranchAddress("Photon_pfRelIso03_all", Photon_pfRelIso03_all, &b_Photon_pfRelIso03_all);
   fChain->SetBranchAddress("Photon_pfRelIso03_chg", Photon_pfRelIso03_chg, &b_Photon_pfRelIso03_chg);
   fChain->SetBranchAddress("Photon_phi", Photon_phi, &b_Photon_phi);
   fChain->SetBranchAddress("Photon_pt", Photon_pt, &b_Photon_pt);
   fChain->SetBranchAddress("Photon_r9", Photon_r9, &b_Photon_r9);
   fChain->SetBranchAddress("Photon_sieie", Photon_sieie, &b_Photon_sieie);
   fChain->SetBranchAddress("Photon_charge", Photon_charge, &b_Photon_charge);
   if (fChain->GetBranch("Photon_cutBased")) fChain->SetBranchAddress("Photon_cutBased", Photon_cutBased, &b_Photon_cutBased);
   if (fChain->GetBranch("Photon_cutBasedBitmap")) fChain->SetBranchAddress("Photon_cutBasedBitmap", Photon_cutBasedBitmap, &b_Photon_cutBasedBitmap);
   if (fChain->GetBranch("Photon_cutBasedV1Bitmap")) fChain->SetBranchAddress("Photon_cutBasedV1Bitmap", Photon_cutBasedV1Bitmap, &b_Photon_cutBasedV1Bitmap);
   if (fChain->GetBranch("Photon_cutBased17Bitmap")) fChain->SetBranchAddress("Photon_cutBased17Bitmap", Photon_cutBased17Bitmap, &b_Photon_cutBased17Bitmap);
   fChain->SetBranchAddress("Photon_electronIdx", Photon_electronIdx, &b_Photon_electronIdx);
   fChain->SetBranchAddress("Photon_jetIdx", Photon_jetIdx, &b_Photon_jetIdx);
   fChain->SetBranchAddress("Photon_pdgId", Photon_pdgId, &b_Photon_pdgId);
   fChain->SetBranchAddress("Photon_vidNestedWPBitmap", Photon_vidNestedWPBitmap, &b_Photon_vidNestedWPBitmap);
   fChain->SetBranchAddress("Photon_electronVeto", Photon_electronVeto, &b_Photon_electronVeto);
   fChain->SetBranchAddress("Photon_isScEtaEB", Photon_isScEtaEB, &b_Photon_isScEtaEB);
   fChain->SetBranchAddress("Photon_isScEtaEE", Photon_isScEtaEE, &b_Photon_isScEtaEE);
   if (fChain->GetBranch("Photon_mvaID17_WP80")) fChain->SetBranchAddress("Photon_mvaID17_WP80", Photon_mvaID17_WP80, &b_Photon_mvaID17_WP80);
   if (fChain->GetBranch("Photon_mvaID17_WP90")) fChain->SetBranchAddress("Photon_mvaID17_WP90", Photon_mvaID17_WP90, &b_Photon_mvaID17_WP90);
   fChain->SetBranchAddress("Photon_mvaID_WP80", Photon_mvaID_WP80, &b_Photon_mvaID_WP80);
   fChain->SetBranchAddress("Photon_mvaID_WP90", Photon_mvaID_WP90, &b_Photon_mvaID_WP90);
   fChain->SetBranchAddress("Photon_pixelSeed", Photon_pixelSeed, &b_Photon_pixelSeed);
   fChain->SetBranchAddress("Photon_seedGain", Photon_seedGain, &b_Photon_seedGain);
   if (fChain->GetBranch("Pileup_nTrueInt")) fChain->SetBranchAddress("Pileup_nTrueInt", &Pileup_nTrueInt, &b_Pileup_nTrueInt);
   if (fChain->GetBranch("Pileup_pudensity")) fChain->SetBranchAddress("Pileup_pudensity", &Pileup_pudensity, &b_Pileup_pudensity);
   if (fChain->GetBranch("Pileup_gpudensity")) fChain->SetBranchAddress("Pileup_gpudensity", &Pileup_gpudensity, &b_Pileup_gpudensity);
   if (fChain->GetBranch("Pileup_nPU")) fChain->SetBranchAddress("Pileup_nPU", &Pileup_nPU, &b_Pileup_nPU);
   if (fChain->GetBranch("Pileup_sumEOOT")) fChain->SetBranchAddress("Pileup_sumEOOT", &Pileup_sumEOOT, &b_Pileup_sumEOOT);
   if (fChain->GetBranch("Pileup_sumLOOT")) fChain->SetBranchAddress("Pileup_sumLOOT", &Pileup_sumLOOT, &b_Pileup_sumLOOT);
   fChain->SetBranchAddress("PuppiMET_phi", &PuppiMET_phi, &b_PuppiMET_phi);
   fChain->SetBranchAddress("PuppiMET_pt", &PuppiMET_pt, &b_PuppiMET_pt);
   fChain->SetBranchAddress("PuppiMET_sumEt", &PuppiMET_sumEt, &b_PuppiMET_sumEt);
   fChain->SetBranchAddress("RawMET_phi", &RawMET_phi, &b_RawMET_phi);
   fChain->SetBranchAddress("RawMET_pt", &RawMET_pt, &b_RawMET_pt);
   fChain->SetBranchAddress("RawMET_sumEt", &RawMET_sumEt, &b_RawMET_sumEt);
   fChain->SetBranchAddress("fixedGridRhoFastjetAll", &fixedGridRhoFastjetAll, &b_fixedGridRhoFastjetAll);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentral", &fixedGridRhoFastjetCentral, &b_fixedGridRhoFastjetCentral);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentralCalo", &fixedGridRhoFastjetCentralCalo, &b_fixedGridRhoFastjetCentralCalo);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentralChargedPileUp", &fixedGridRhoFastjetCentralChargedPileUp, &b_fixedGridRhoFastjetCentralChargedPileUp);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentralNeutral", &fixedGridRhoFastjetCentralNeutral, &b_fixedGridRhoFastjetCentralNeutral);
   if (fChain->GetBranch("nGenDressedLepton")) fChain->SetBranchAddress("nGenDressedLepton", &nGenDressedLepton, &b_nGenDressedLepton);
   if (fChain->GetBranch("GenDressedLepton_eta")) fChain->SetBranchAddress("GenDressedLepton_eta", GenDressedLepton_eta, &b_GenDressedLepton_eta);
   if (fChain->GetBranch("GenDressedLepton_mass")) fChain->SetBranchAddress("GenDressedLepton_mass", GenDressedLepton_mass, &b_GenDressedLepton_mass);
   if (fChain->GetBranch("GenDressedLepton_phi")) fChain->SetBranchAddress("GenDressedLepton_phi", GenDressedLepton_phi, &b_GenDressedLepton_phi);
   if (fChain->GetBranch("GenDressedLepton_pt")) fChain->SetBranchAddress("GenDressedLepton_pt", GenDressedLepton_pt, &b_GenDressedLepton_pt);
   if (fChain->GetBranch("GenDressedLepton_pdgId")) fChain->SetBranchAddress("GenDressedLepton_pdgId", GenDressedLepton_pdgId, &b_GenDressedLepton_pdgId);
   if (fChain->GetBranch("GenDressedLepton_hasTauAnc")) fChain->SetBranchAddress("GenDressedLepton_hasTauAnc", GenDressedLepton_hasTauAnc, &b_GenDressedLepton_hasTauAnc);
   fChain->SetBranchAddress("nSoftActivityJet", &nSoftActivityJet, &b_nSoftActivityJet);
   fChain->SetBranchAddress("SoftActivityJet_eta", SoftActivityJet_eta, &b_SoftActivityJet_eta);
   fChain->SetBranchAddress("SoftActivityJet_phi", SoftActivityJet_phi, &b_SoftActivityJet_phi);
   fChain->SetBranchAddress("SoftActivityJet_pt", SoftActivityJet_pt, &b_SoftActivityJet_pt);
   fChain->SetBranchAddress("SoftActivityJetHT", &SoftActivityJetHT, &b_SoftActivityJetHT);
   fChain->SetBranchAddress("SoftActivityJetHT10", &SoftActivityJetHT10, &b_SoftActivityJetHT10);
   fChain->SetBranchAddress("SoftActivityJetHT2", &SoftActivityJetHT2, &b_SoftActivityJetHT2);
   fChain->SetBranchAddress("SoftActivityJetHT5", &SoftActivityJetHT5, &b_SoftActivityJetHT5);
   fChain->SetBranchAddress("SoftActivityJetNjets10", &SoftActivityJetNjets10, &b_SoftActivityJetNjets10);
   fChain->SetBranchAddress("SoftActivityJetNjets2", &SoftActivityJetNjets2, &b_SoftActivityJetNjets2);
   fChain->SetBranchAddress("SoftActivityJetNjets5", &SoftActivityJetNjets5, &b_SoftActivityJetNjets5);
   fChain->SetBranchAddress("nSubJet", &nSubJet, &b_nSubJet);
   fChain->SetBranchAddress("SubJet_btagCMVA", SubJet_btagCMVA, &b_SubJet_btagCMVA);
   fChain->SetBranchAddress("SubJet_btagCSVV2", SubJet_btagCSVV2, &b_SubJet_btagCSVV2);
   fChain->SetBranchAddress("SubJet_btagDeepB", SubJet_btagDeepB, &b_SubJet_btagDeepB);
   fChain->SetBranchAddress("SubJet_eta", SubJet_eta, &b_SubJet_eta);
   fChain->SetBranchAddress("SubJet_mass", SubJet_mass, &b_SubJet_mass);
   fChain->SetBranchAddress("SubJet_n2b1", SubJet_n2b1, &b_SubJet_n2b1);
   fChain->SetBranchAddress("SubJet_n3b1", SubJet_n3b1, &b_SubJet_n3b1);
   fChain->SetBranchAddress("SubJet_phi", SubJet_phi, &b_SubJet_phi);
   fChain->SetBranchAddress("SubJet_pt", SubJet_pt, &b_SubJet_pt);
   fChain->SetBranchAddress("SubJet_rawFactor", SubJet_rawFactor, &b_SubJet_rawFactor);
   fChain->SetBranchAddress("SubJet_tau1", SubJet_tau1, &b_SubJet_tau1);
   fChain->SetBranchAddress("SubJet_tau2", SubJet_tau2, &b_SubJet_tau2);
   fChain->SetBranchAddress("SubJet_tau3", SubJet_tau3, &b_SubJet_tau3);
   fChain->SetBranchAddress("SubJet_tau4", SubJet_tau4, &b_SubJet_tau4);
   fChain->SetBranchAddress("nTau", &nTau, &b_nTau);
   fChain->SetBranchAddress("Tau_chargedIso", Tau_chargedIso, &b_Tau_chargedIso);
   fChain->SetBranchAddress("Tau_dxy", Tau_dxy, &b_Tau_dxy);
   fChain->SetBranchAddress("Tau_dz", Tau_dz, &b_Tau_dz);
   fChain->SetBranchAddress("Tau_eta", Tau_eta, &b_Tau_eta);
   fChain->SetBranchAddress("Tau_leadTkDeltaEta", Tau_leadTkDeltaEta, &b_Tau_leadTkDeltaEta);
   fChain->SetBranchAddress("Tau_leadTkDeltaPhi", Tau_leadTkDeltaPhi, &b_Tau_leadTkDeltaPhi);
   fChain->SetBranchAddress("Tau_leadTkPtOverTauPt", Tau_leadTkPtOverTauPt, &b_Tau_leadTkPtOverTauPt);
   fChain->SetBranchAddress("Tau_mass", Tau_mass, &b_Tau_mass);
   fChain->SetBranchAddress("Tau_neutralIso", Tau_neutralIso, &b_Tau_neutralIso);
   fChain->SetBranchAddress("Tau_phi", Tau_phi, &b_Tau_phi);
   fChain->SetBranchAddress("Tau_photonsOutsideSignalCone", Tau_photonsOutsideSignalCone, &b_Tau_photonsOutsideSignalCone);
   fChain->SetBranchAddress("Tau_pt", Tau_pt, &b_Tau_pt);
   fChain->SetBranchAddress("Tau_puCorr", Tau_puCorr, &b_Tau_puCorr);
   fChain->SetBranchAddress("Tau_rawAntiEle", Tau_rawAntiEle, &b_Tau_rawAntiEle);
   fChain->SetBranchAddress("Tau_rawAntiEle2018", Tau_rawAntiEle2018, &b_Tau_rawAntiEle2018);
   fChain->SetBranchAddress("Tau_rawIso", Tau_rawIso, &b_Tau_rawIso);
   fChain->SetBranchAddress("Tau_rawIsodR03", Tau_rawIsodR03, &b_Tau_rawIsodR03);
   fChain->SetBranchAddress("Tau_rawMVAnewDM2017v2", Tau_rawMVAnewDM2017v2, &b_Tau_rawMVAnewDM2017v2);
   fChain->SetBranchAddress("Tau_rawMVAoldDM", Tau_rawMVAoldDM, &b_Tau_rawMVAoldDM);
   fChain->SetBranchAddress("Tau_rawMVAoldDM2017v1", Tau_rawMVAoldDM2017v1, &b_Tau_rawMVAoldDM2017v1);
   fChain->SetBranchAddress("Tau_rawMVAoldDM2017v2", Tau_rawMVAoldDM2017v2, &b_Tau_rawMVAoldDM2017v2);
   fChain->SetBranchAddress("Tau_rawMVAoldDMdR032017v2", Tau_rawMVAoldDMdR032017v2, &b_Tau_rawMVAoldDMdR032017v2);
   fChain->SetBranchAddress("Tau_charge", Tau_charge, &b_Tau_charge);
   fChain->SetBranchAddress("Tau_decayMode", Tau_decayMode, &b_Tau_decayMode);
   fChain->SetBranchAddress("Tau_jetIdx", Tau_jetIdx, &b_Tau_jetIdx);
   fChain->SetBranchAddress("Tau_rawAntiEleCat", Tau_rawAntiEleCat, &b_Tau_rawAntiEleCat);
   fChain->SetBranchAddress("Tau_rawAntiEleCat2018", Tau_rawAntiEleCat2018, &b_Tau_rawAntiEleCat2018);
   fChain->SetBranchAddress("Tau_idAntiEle", Tau_idAntiEle, &b_Tau_idAntiEle);
   fChain->SetBranchAddress("Tau_idAntiEle2018", Tau_idAntiEle2018, &b_Tau_idAntiEle2018);
   fChain->SetBranchAddress("Tau_idAntiMu", Tau_idAntiMu, &b_Tau_idAntiMu);
   fChain->SetBranchAddress("Tau_idDecayMode", Tau_idDecayMode, &b_Tau_idDecayMode);
   fChain->SetBranchAddress("Tau_idDecayModeNewDMs", Tau_idDecayModeNewDMs, &b_Tau_idDecayModeNewDMs);
   fChain->SetBranchAddress("Tau_idMVAnewDM2017v2", Tau_idMVAnewDM2017v2, &b_Tau_idMVAnewDM2017v2);
   fChain->SetBranchAddress("Tau_idMVAoldDM", Tau_idMVAoldDM, &b_Tau_idMVAoldDM);
   fChain->SetBranchAddress("Tau_idMVAoldDM2017v1", Tau_idMVAoldDM2017v1, &b_Tau_idMVAoldDM2017v1);
   fChain->SetBranchAddress("Tau_idMVAoldDM2017v2", Tau_idMVAoldDM2017v2, &b_Tau_idMVAoldDM2017v2);
   fChain->SetBranchAddress("Tau_idMVAoldDMdR032017v2", Tau_idMVAoldDMdR032017v2, &b_Tau_idMVAoldDMdR032017v2);
   fChain->SetBranchAddress("TkMET_phi", &TkMET_phi, &b_TkMET_phi);
   fChain->SetBranchAddress("TkMET_pt", &TkMET_pt, &b_TkMET_pt);
   fChain->SetBranchAddress("TkMET_sumEt", &TkMET_sumEt, &b_TkMET_sumEt);
   if (fChain->GetBranch("nTrigObj")) fChain->SetBranchAddress("nTrigObj", &nTrigObj, &b_nTrigObj);
   if (fChain->GetBranch("TrigObj_pt")) fChain->SetBranchAddress("TrigObj_pt", TrigObj_pt, &b_TrigObj_pt);
   if (fChain->GetBranch("TrigObj_eta")) fChain->SetBranchAddress("TrigObj_eta", TrigObj_eta, &b_TrigObj_eta);
   if (fChain->GetBranch("TrigObj_phi")) fChain->SetBranchAddress("TrigObj_phi", TrigObj_phi, &b_TrigObj_phi);
   if (fChain->GetBranch("TrigObj_l1pt")) fChain->SetBranchAddress("TrigObj_l1pt", TrigObj_l1pt, &b_TrigObj_l1pt);
   if (fChain->GetBranch("TrigObj_l1pt_2")) fChain->SetBranchAddress("TrigObj_l1pt_2", TrigObj_l1pt_2, &b_TrigObj_l1pt_2);
   if (fChain->GetBranch("TrigObj_l2pt")) fChain->SetBranchAddress("TrigObj_l2pt", TrigObj_l2pt, &b_TrigObj_l2pt);
   if (fChain->GetBranch("TrigObj_id")) fChain->SetBranchAddress("TrigObj_id", TrigObj_id, &b_TrigObj_id);
   if (fChain->GetBranch("TrigObj_l1iso")) fChain->SetBranchAddress("TrigObj_l1iso", TrigObj_l1iso, &b_TrigObj_l1iso);
   if (fChain->GetBranch("TrigObj_l1charge")) fChain->SetBranchAddress("TrigObj_l1charge", TrigObj_l1charge, &b_TrigObj_l1charge);
   if (fChain->GetBranch("TrigObj_filterBits")) fChain->SetBranchAddress("TrigObj_filterBits", TrigObj_filterBits, &b_TrigObj_filterBits);
   if (fChain->GetBranch("genTtbarId")) fChain->SetBranchAddress("genTtbarId", &genTtbarId, &b_genTtbarId);
   fChain->SetBranchAddress("nOtherPV", &nOtherPV, &b_nOtherPV);
   fChain->SetBranchAddress("OtherPV_z", OtherPV_z, &b_OtherPV_z);
   fChain->SetBranchAddress("PV_ndof", &PV_ndof, &b_PV_ndof);
   fChain->SetBranchAddress("PV_x", &PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", &PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("PV_chi2", &PV_chi2, &b_PV_chi2);
   fChain->SetBranchAddress("PV_score", &PV_score, &b_PV_score);
   fChain->SetBranchAddress("PV_npvs", &PV_npvs, &b_PV_npvs);
   fChain->SetBranchAddress("PV_npvsGood", &PV_npvsGood, &b_PV_npvsGood);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_dlen", SV_dlen, &b_SV_dlen);
   fChain->SetBranchAddress("SV_dlenSig", SV_dlenSig, &b_SV_dlenSig);
   fChain->SetBranchAddress("SV_pAngle", SV_pAngle, &b_SV_pAngle);
   if (fChain->GetBranch("Electron_genPartIdx")) fChain->SetBranchAddress("Electron_genPartIdx", Electron_genPartIdx, &b_Electron_genPartIdx);
   if (fChain->GetBranch("Electron_genPartFlav")) fChain->SetBranchAddress("Electron_genPartFlav", Electron_genPartFlav, &b_Electron_genPartFlav);
   if (fChain->GetBranch("GenJetAK8_partonFlavour")) fChain->SetBranchAddress("GenJetAK8_partonFlavour", GenJetAK8_partonFlavour, &b_GenJetAK8_partonFlavour);
   if (fChain->GetBranch("GenJetAK8_hadronFlavour")) fChain->SetBranchAddress("GenJetAK8_hadronFlavour", GenJetAK8_hadronFlavour, &b_GenJetAK8_hadronFlavour);
   if (fChain->GetBranch("GenJet_partonFlavour")) fChain->SetBranchAddress("GenJet_partonFlavour", GenJet_partonFlavour, &b_GenJet_partonFlavour);
   if (fChain->GetBranch("GenJet_hadronFlavour")) fChain->SetBranchAddress("GenJet_hadronFlavour", GenJet_hadronFlavour, &b_GenJet_hadronFlavour);
   if (fChain->GetBranch("Jet_genJetIdx")) fChain->SetBranchAddress("Jet_genJetIdx", Jet_genJetIdx, &b_Jet_genJetIdx);
   if (fChain->GetBranch("Jet_hadronFlavour")) fChain->SetBranchAddress("Jet_hadronFlavour", Jet_hadronFlavour, &b_Jet_hadronFlavour);
   if (fChain->GetBranch("Jet_partonFlavour")) fChain->SetBranchAddress("Jet_partonFlavour", Jet_partonFlavour, &b_Jet_partonFlavour);
   if (fChain->GetBranch("Muon_genPartIdx")) fChain->SetBranchAddress("Muon_genPartIdx", Muon_genPartIdx, &b_Muon_genPartIdx);
   if (fChain->GetBranch("Muon_genPartFlav")) fChain->SetBranchAddress("Muon_genPartFlav", Muon_genPartFlav, &b_Muon_genPartFlav);
   if (fChain->GetBranch("Photon_genPartIdx")) fChain->SetBranchAddress("Photon_genPartIdx", Photon_genPartIdx, &b_Photon_genPartIdx);
   if (fChain->GetBranch("Photon_genPartFlav")) fChain->SetBranchAddress("Photon_genPartFlav", Photon_genPartFlav, &b_Photon_genPartFlav);
   if (fChain->GetBranch("MET_fiducialGenPhi")) fChain->SetBranchAddress("MET_fiducialGenPhi", &MET_fiducialGenPhi, &b_MET_fiducialGenPhi);
   if (fChain->GetBranch("MET_fiducialGenPt")) fChain->SetBranchAddress("MET_fiducialGenPt", &MET_fiducialGenPt, &b_MET_fiducialGenPt);
   fChain->SetBranchAddress("Electron_cleanmask", Electron_cleanmask, &b_Electron_cleanmask);
   fChain->SetBranchAddress("Jet_cleanmask", Jet_cleanmask, &b_Jet_cleanmask);
   fChain->SetBranchAddress("Muon_cleanmask", Muon_cleanmask, &b_Muon_cleanmask);
   fChain->SetBranchAddress("Photon_cleanmask", Photon_cleanmask, &b_Photon_cleanmask);
   fChain->SetBranchAddress("Tau_cleanmask", Tau_cleanmask, &b_Tau_cleanmask);
   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
   fChain->SetBranchAddress("SV_eta", SV_eta, &b_SV_eta);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_ndof", SV_ndof, &b_SV_ndof);
   fChain->SetBranchAddress("SV_phi", SV_phi, &b_SV_phi);
   fChain->SetBranchAddress("SV_pt", SV_pt, &b_SV_pt);
   fChain->SetBranchAddress("SV_x", SV_x, &b_SV_x);
   fChain->SetBranchAddress("SV_y", SV_y, &b_SV_y);
   fChain->SetBranchAddress("SV_z", SV_z, &b_SV_z);
   if (fChain->GetBranch("Tau_genPartIdx")) fChain->SetBranchAddress("Tau_genPartIdx", Tau_genPartIdx, &b_Tau_genPartIdx);
   if (fChain->GetBranch("Tau_genPartFlav")) fChain->SetBranchAddress("Tau_genPartFlav", Tau_genPartFlav, &b_Tau_genPartFlav);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloTrkMuUnvetoFilter", &Flag_CSCTightHaloTrkMuUnvetoFilter, &b_Flag_CSCTightHaloTrkMuUnvetoFilter);
   fChain->SetBranchAddress("Flag_CSCTightHalo2015Filter", &Flag_CSCTightHalo2015Filter, &b_Flag_CSCTightHalo2015Filter);
   fChain->SetBranchAddress("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter, &b_Flag_globalTightHalo2016Filter);
   fChain->SetBranchAddress("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter, &b_Flag_globalSuperTightHalo2016Filter);
   fChain->SetBranchAddress("Flag_HcalStripHaloFilter", &Flag_HcalStripHaloFilter, &b_Flag_HcalStripHaloFilter);
   fChain->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellBoundaryEnergyFilter", &Flag_EcalDeadCellBoundaryEnergyFilter, &b_Flag_EcalDeadCellBoundaryEnergyFilter);
   fChain->SetBranchAddress("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter, &b_Flag_ecalBadCalibFilter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   fChain->SetBranchAddress("Flag_chargedHadronTrackResolutionFilter", &Flag_chargedHadronTrackResolutionFilter, &b_Flag_chargedHadronTrackResolutionFilter);
   fChain->SetBranchAddress("Flag_muonBadTrackFilter", &Flag_muonBadTrackFilter, &b_Flag_muonBadTrackFilter);
   fChain->SetBranchAddress("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter, &b_Flag_BadChargedCandidateFilter);
   fChain->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, &b_Flag_BadPFMuonFilter);
   fChain->SetBranchAddress("Flag_BadChargedCandidateSummer16Filter", &Flag_BadChargedCandidateSummer16Filter, &b_Flag_BadChargedCandidateSummer16Filter);
   fChain->SetBranchAddress("Flag_BadPFMuonSummer16Filter", &Flag_BadPFMuonSummer16Filter, &b_Flag_BadPFMuonSummer16Filter);
   fChain->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   fChain->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   fChain->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   if (fChain->GetBranch("HLT_Ele27_WPTight_Gsf")) fChain->SetBranchAddress("HLT_Ele27_WPTight_Gsf", &HLT_Ele27_WPTight_Gsf, &b_HLT_Ele27_WPTight_Gsf);
   if (fChain->GetBranch("HLT_ECALHT800")) fChain->SetBranchAddress("HLT_ECALHT800", &HLT_ECALHT800, &b_HLT_ECALHT800);
   if (fChain->GetBranch("HLT_Photon165_HE10")) fChain->SetBranchAddress("HLT_Photon165_HE10", &HLT_Photon165_HE10, &b_HLT_Photon165_HE10);
   if (fChain->GetBranch("HLT_Photon165_R9Id90_HE10_IsoM")) fChain->SetBranchAddress("HLT_Photon165_R9Id90_HE10_IsoM", &HLT_Photon165_R9Id90_HE10_IsoM, &b_HLT_Photon165_R9Id90_HE10_IsoM);
   if (fChain->GetBranch("HLT_Photon175")) fChain->SetBranchAddress("HLT_Photon175", &HLT_Photon175, &b_HLT_Photon175);
   if (fChain->GetBranch("HLT_Photon200")) fChain->SetBranchAddress("HLT_Photon200", &HLT_Photon200, &b_HLT_Photon200);
   if (fChain->GetBranch("HLT_Photon250_NoHE")) fChain->SetBranchAddress("HLT_Photon250_NoHE", &HLT_Photon250_NoHE, &b_HLT_Photon250_NoHE);
   if (fChain->GetBranch("HLT_Photon300_NoHE")) fChain->SetBranchAddress("HLT_Photon300_NoHE", &HLT_Photon300_NoHE, &b_HLT_Photon300_NoHE);
   if (fChain->GetBranch("HLT_Photon500")) fChain->SetBranchAddress("HLT_Photon500", &HLT_Photon500, &b_HLT_Photon500);
   if (fChain->GetBranch("HLT_Photon600")) fChain->SetBranchAddress("HLT_Photon600", &HLT_Photon600, &b_HLT_Photon600);
   if (fChain->GetBranch("HLT_AK8PFJet360_TrimMass30")) fChain->SetBranchAddress("HLT_AK8PFJet360_TrimMass30", &HLT_AK8PFJet360_TrimMass30, &b_HLT_AK8PFJet360_TrimMass30);
   if (fChain->GetBranch("HLT_AK8PFJet400_TrimMass30")) fChain->SetBranchAddress("HLT_AK8PFJet400_TrimMass30", &HLT_AK8PFJet400_TrimMass30, &b_HLT_AK8PFJet400_TrimMass30);
   if (fChain->GetBranch("HLT_AK8PFJet500")) fChain->SetBranchAddress("HLT_AK8PFJet500", &HLT_AK8PFJet500, &b_HLT_AK8PFJet500);
   if (fChain->GetBranch("HLT_PFJet450")) fChain->SetBranchAddress("HLT_PFJet450", &HLT_PFJet450, &b_HLT_PFJet450);
   if (fChain->GetBranch("HLT_PFJet500")) fChain->SetBranchAddress("HLT_PFJet500", &HLT_PFJet500, &b_HLT_PFJet500);
   if (fChain->GetBranch("HLT_PFHT900")) fChain->SetBranchAddress("HLT_PFHT900", &HLT_PFHT900, &b_HLT_PFHT900);
   if (fChain->GetBranch("HLT_PFMET170_HBHECleaned")) fChain->SetBranchAddress("HLT_PFMET170_HBHECleaned", &HLT_PFMET170_HBHECleaned, &b_HLT_PFMET170_HBHECleaned);
   if (fChain->GetBranch("HLT_PFMET170_HBHE_BeamHaloCleaned")) fChain->SetBranchAddress("HLT_PFMET170_HBHE_BeamHaloCleaned", &HLT_PFMET170_HBHE_BeamHaloCleaned, &b_HLT_PFMET170_HBHE_BeamHaloCleaned);
   if (fChain->GetBranch("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight")) fChain->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
   if (fChain->GetBranch("HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight")) fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight);
   if (fChain->GetBranch("L1Reco_step")) fChain->SetBranchAddress("L1Reco_step", &L1Reco_step, &b_L1Reco_step);
   if (fChain->GetBranch("L1_AlwaysTrue")) fChain->SetBranchAddress("L1_AlwaysTrue", &L1_AlwaysTrue, &b_L1_AlwaysTrue);
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

Bool_t Analyzer::IsGoldEvent(UInt_t RUN, UInt_t LS){
  //needs input json formatted as each run is a new line
  string json_2016="input/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt";
  std::ifstream json (json_2016);
  if (json.is_open()) {
    std::string line;
    while( std::getline(json, line) ) {
      //check if current line is the proper run
      size_t t = line.find(to_string(RUN));
      if (t==std::string::npos) continue;
      std::size_t pos_begin = 0;
      std::size_t pos_end = 0;
      while (pos_begin!=string::npos) {
        pos_begin = line.find ("[",pos_begin+1);
        if (pos_begin==std::string::npos) break;
        if (line[pos_begin+1]=='[') pos_begin+=1;
        pos_end = line.find (",",pos_begin+1);
        unsigned int ls_1 = stoi (line.substr (pos_begin+1, pos_end-pos_begin-1));
        pos_begin = pos_end+1;
        pos_end = line.find ("]", pos_begin+1);
        unsigned int ls_2 = stoi (line.substr (pos_begin+1, pos_end-pos_begin-1));
        if (ls_1 > ls_2) {cout<<"Something is not right... "<<RUN<<" "<<LS<<endl; json.close(); return 0;}
        if (LS>=ls_1 && LS<=ls_2) {json.close(); return true;}
      }
    }
  }
  json.close();
  return false;
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


Int_t Analyzer::Cut(Long64_t entry,pair<int,int> mass_pair)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
  bool returnvalue=true;
  for (unsigned int i=0;i<_cut_variable.size();i++){
    unsigned int metFilters=0;
    metFilters += (Flag_goodVertices) ? pow(2,0) : 0;
    metFilters += (Flag_globalSuperTightHalo2016Filter) ? pow(2,1) : 0;
    metFilters += (Flag_HBHENoiseFilter) ? pow(2,2) : 0;
    metFilters += (Flag_HBHENoiseIsoFilter) ? pow(2,3) : 0;
    metFilters += (Flag_EcalDeadCellTriggerPrimitiveFilter) ? pow(2,4) : 0;
    metFilters += (Flag_BadPFMuonFilter) ? pow(2,5) : 0;
    metFilters += (Flag_BadChargedCandidateFilter) ? pow(2,6) : 0;
    metFilters += (Flag_eeBadScFilter) ? pow(2,7) : 0;
    metFilters += (Flag_ecalBadCalibFilter) ? pow(2,8) : 0;
    //current metfilter recommendations: year/data/mc/fastsim: 2016/191/63/61, 2017/447/319/317, 2018/447/319/317
    bool metFilters_hardcoded=0; unsigned int filterValue=0;
    if (year==2016 && isData) filterValue=191;
    if (year==2016 && !isData && !_fastSim) filterValue=63;
    if (year==2016 && !isData && _fastSim) filterValue=61;
    if (year!=2016 && isData) filterValue=447;
    if (year!=2016 && !isData && !_fastSim) filterValue=319;
    if (year!=2016 && !isData && _fastSim) filterValue=317;
    metFilters_hardcoded=(metFilters&filterValue)==filterValue;
    bool HLTPho=0;
    if (year==2016) HLTPho=HLT_Photon165_HE10 || HLT_Photon175 || HLT_Photon250_NoHE;
    else HLTPho=HLT_Photon200 || HLT_Photon300_NoHE;
    if      (_cut_variable[i]=="HLTPho")    returnvalue*=Parser(HLTPho,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="isPVGood") returnvalue*=Parser(PV_npvsGood,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassEleL") {returnvalue*=Parser(nPassEleL,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[1]; if (!isData && _cut_value[i]==0) w*=ele_VETOSF;}
    else if (_cut_variable[i]=="nPassEleM") {returnvalue*=Parser(nPassEleM,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[2];}
    else if (_cut_variable[i]=="nPassEleT") {returnvalue*=Parser(nPassEleT,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[3];}
    else if (_cut_variable[i]=="nPassMuL") {returnvalue*=Parser(nPassMuL,_cut_operator[i],_cut_value[i]); if (!isData) w*=mu_SF[0];}
    else if (_cut_variable[i]=="nPassMuM") {returnvalue*=Parser(nPassMuM,_cut_operator[i],_cut_value[i]); if (!isData) w*=mu_SF[1];}
    else if (_cut_variable[i]=="nPassMuT") {returnvalue*=Parser(nPassMuT,_cut_operator[i],_cut_value[i]); if (!isData) w*=mu_SF[2];}
    else if (_cut_variable[i]=="nPassTauL") {returnvalue*=Parser(nPassTauL,_cut_operator[i],_cut_value[i]); if (!isData) w*=tau_SF[0];}
    else if (_cut_variable[i]=="nPassTauM") {returnvalue*=Parser(nPassTauM,_cut_operator[i],_cut_value[i]); if (!isData) w*=tau_SF[1];}
    else if (_cut_variable[i]=="nPassTauT") {returnvalue*=Parser(nPassTauT,_cut_operator[i],_cut_value[i]); if (!isData) w*=tau_SF[2];}
    else if (_cut_variable[i]=="nPassIso") {returnvalue*=Parser(nPassIso,_cut_operator[i],_cut_value[i]);}
    //else if (_cut_variable[i]=="nPassLepL") {returnvalue*=Parser(nPassEleL+nPassMuL+nPassTauL,_cut_operator[i],_cut_value[i]); if (!isData) {double tempw=w;if (nPassEleL) {cout<<"ele w "<<ele_SF[1]<<endl; w*=ele_SF[1]; if (_cut_value[i]==0) w*=ele_VETOSF;} if (nPassMuL) {cout<<"mu w "<<mu_SF[0]<<endl; w*=mu_SF[0];} if (nPassTauL) {cout<<"tau w "<<tau_SF[0]<<endl; w*=tau_SF[0];}cout<<"lepton w "<<w/tempw<<endl;}}
    else if (_cut_variable[i]=="nPassLepL") {returnvalue*=Parser(nPassEleL+nPassMuL+nPassTauL,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (nPassEleL+nPassMuL+nPassTauL>0) {
          double max_pt=0; unsigned int whichLepton=0;
          if (nPassEleL>0 && Electron_pt[nleadEleL]>max_pt) {max_pt=Electron_pt[nleadEleL]; whichLepton=1;}
          if (nPassMuL>0 && Muon_pt[nleadMuL]>max_pt) {max_pt=Muon_pt[nleadMuL]; whichLepton=2;}
          if (nPassTauL>0 && Tau_pt[nleadTauL]>max_pt) {max_pt=Tau_pt[nleadTauL]; whichLepton=3;}
          switch (whichLepton) {
            case 1 : w*=ele_SF[1];
            break;
            case 2 : w*=mu_SF[0];
            break;
            case 3 : w*=tau_SF[0];
            break;
          }
        }
        else if (_cut_value[i]==0) w*=ele_VETOSF;
      }
    }
    else if (_cut_variable[i]=="nPassLepM") {returnvalue*=Parser(nPassEleM+nPassMuM+nPassTauM,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (nPassEleM+nPassMuM+nPassTauM>0) {
          double max_pt=0; unsigned int whichLepton=0;
          if (nPassEleM>0 && Electron_pt[nleadEleM]>max_pt) {max_pt=Electron_pt[nleadEleM]; whichLepton=1;}
          if (nPassMuM>0 && Muon_pt[nleadMuM]>max_pt) {max_pt=Muon_pt[nleadMuM]; whichLepton=2;}
          if (nPassTauM>0 && Tau_pt[nleadTauM]>max_pt) {max_pt=Tau_pt[nleadTauM]; whichLepton=3;}
          switch (whichLepton) {
            case 1 : w*=ele_SF[2];
            break;
            case 2 : w*=mu_SF[1];
            break;
            case 3 : w*=tau_SF[1];
            break;
          }
        }
        else if (_cut_value[i]==0) w*=ele_VETOSF;
      }
    }
    else if (_cut_variable[i]=="nPassLepT") {returnvalue*=Parser(nPassEleT+nPassMuT+nPassTauT,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (nPassEleT+nPassMuT+nPassTauT>0) {
          double max_pt=0; unsigned int whichLepton=0;
          if (nPassEleT>0 && Electron_pt[nleadEleT]>max_pt) {max_pt=Electron_pt[nleadEleT]; whichLepton=1;}
          if (nPassMuT>0 && Muon_pt[nleadMuT]>max_pt) {max_pt=Muon_pt[nleadMuT]; whichLepton=2;}
          if (nPassTauT>0 && Tau_pt[nleadTauT]>max_pt) {max_pt=Tau_pt[nleadTauT]; whichLepton=3;}
          switch (whichLepton) {
            case 1 : w*=ele_SF[3];
            break;
            case 2 : w*=mu_SF[2];
            break;
            case 3 : w*=tau_SF[2];
            break;
          }
        }
        else if (_cut_value[i]==0) w*=ele_VETOSF;
      }
    }
    else if (_cut_variable[i]=="nPassLepVLL") {returnvalue*=Parser(nPassEleV+nPassMuL+nPassTauL,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (nPassEleV+nPassMuL+nPassTauL>0) {
          double max_pt=0; unsigned int whichLepton=0;
          if (nPassEleV>0 && Electron_pt[nleadEleV]>max_pt) {max_pt=Electron_pt[nleadEleV]; whichLepton=1;}
          if (nPassMuL>0 && Muon_pt[nleadMuL]>max_pt) {max_pt=Muon_pt[nleadMuL]; whichLepton=2;}
          if (nPassTauL>0 && Tau_pt[nleadTauL]>max_pt) {max_pt=Tau_pt[nleadTauL]; whichLepton=3;}
          switch (whichLepton) {
            case 1 : w*=ele_SF[0];
            break;
            case 2 : w*=mu_SF[0];
            break;
            case 3 : w*=tau_SF[0];
            break;
          }
        }
        else if (_cut_value[i]==0) w*=ele_VETOSF;
      }
    }
    else if (_cut_variable[i]=="nPassLepMLL") {returnvalue*=Parser(nPassEleM+nPassMuL+nPassTauL,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (nPassEleM+nPassMuL+nPassTauL>0) {
          double max_pt=0; unsigned int whichLepton=0;
          if (nPassEleM>0 && Electron_pt[nleadEleM]>max_pt) {max_pt=Electron_pt[nleadEleM]; whichLepton=1;}
          if (nPassMuL>0 && Muon_pt[nleadMuL]>max_pt) {max_pt=Muon_pt[nleadMuL]; whichLepton=2;}
          if (nPassTauL>0 && Tau_pt[nleadTauL]>max_pt) {max_pt=Tau_pt[nleadTauL]; whichLepton=3;}
          switch (whichLepton) {
            case 1 : w*=ele_SF[2];
            break;
            case 2 : w*=mu_SF[0];
            break;
            case 3 : w*=tau_SF[0];
            break;
          }
        }
        else if (_cut_value[i]==0) w*=ele_VETOSF;
      }
    }
    else if (_cut_variable[i]=="nPassLepLML") {returnvalue*=Parser(nPassEleL+nPassMuM+nPassTauL,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (nPassEleL+nPassMuM+nPassTauL>0) {
          double max_pt=0; unsigned int whichLepton=0;
          if (nPassEleL>0 && Electron_pt[nleadEleL]>max_pt) {max_pt=Electron_pt[nleadEleL]; whichLepton=1;}
          if (nPassMuM>0 && Muon_pt[nleadMuM]>max_pt) {max_pt=Muon_pt[nleadMuM]; whichLepton=2;}
          if (nPassTauL>0 && Tau_pt[nleadTauL]>max_pt) {max_pt=Tau_pt[nleadTauL]; whichLepton=3;}
          switch (whichLepton) {
            case 1 : w*=ele_SF[1];
            break;
            case 2 : w*=mu_SF[1];
            break;
            case 3 : w*=tau_SF[0];
            break;
          }
        }
        else if (_cut_value[i]==0) w*=ele_VETOSF;
      }
    }
    else if (_cut_variable[i]=="nPassLepLLM") {returnvalue*=Parser(nPassEleL+nPassMuL+nPassTauM,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (nPassEleL+nPassMuL+nPassTauM>0) {
          double max_pt=0; unsigned int whichLepton=0;
          if (nPassEleL>0 && Electron_pt[nleadEleL]>max_pt) {max_pt=Electron_pt[nleadEleL]; whichLepton=1;}
          if (nPassMuL>0 && Muon_pt[nleadMuL]>max_pt) {max_pt=Muon_pt[nleadMuL]; whichLepton=2;}
          if (nPassTauM>0 && Tau_pt[nleadTauM]>max_pt) {max_pt=Tau_pt[nleadTauM]; whichLepton=3;}
          switch (whichLepton) {
            case 1 : w*=ele_SF[1];
            break;
            case 2 : w*=mu_SF[0];
            break;
            case 3 : w*=tau_SF[1];
            break;
          }
        }
        else if (_cut_value[i]==0) w*=ele_VETOSF;
      }
    }
    else if (_cut_variable[i]=="nPassFREleL") {returnvalue*=Parser(nPassFREleL,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[1];}
    else if (_cut_variable[i]=="nPassFREleM") {returnvalue*=Parser(nPassFREleM,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[2];}
    else if (_cut_variable[i]=="nPassFREleT") {returnvalue*=Parser(nPassFREleT,_cut_operator[i],_cut_value[i]); if (!isData) w*=ele_SF[3];}
    else if (_cut_variable[i]=="nPassElePhoL") returnvalue*=Parser(nPassElePhoL,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassElePhoM") returnvalue*=Parser(nPassElePhoM,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassElePhoT") returnvalue*=Parser(nPassElePhoT,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassElePhoMVA80") returnvalue*=Parser(nPassElePhoMVA80,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassElePhoMVA90") returnvalue*=Parser(nPassElePhoMVA90,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassPhoL") {returnvalue*=Parser(nPassPhoL,_cut_operator[i],_cut_value[i]); if (!isData) w*=pho_SF[0];}
    else if (_cut_variable[i]=="nPassPhoM") {returnvalue*=Parser(nPassPhoM,_cut_operator[i],_cut_value[i]); if (!isData) w*=pho_SF[1];}
    else if (_cut_variable[i]=="nPassPhoT") {returnvalue*=Parser(nPassPhoT,_cut_operator[i],_cut_value[i]); if (!isData) w*=pho_SF[2];}
    else if (_cut_variable[i]=="nPassPhoMVA80") {returnvalue*=Parser(nPassPhoMVA80,_cut_operator[i],_cut_value[i]); if (!isData) w*=pho_SF[3];}
    else if (_cut_variable[i]=="nPassPhoMVA90") {returnvalue*=Parser(nPassPhoMVA90,_cut_operator[i],_cut_value[i]); if (!isData) w*=pho_SF[4];}
    else if (_cut_variable[i]=="elePt") returnvalue*=Parser_float(Electron_pt[nleadEle],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="elephoPt") returnvalue*=Parser_float(phoET[nleadElePho],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="phoEt") returnvalue*=Parser_float(phoET[nleadPho],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="HT") returnvalue*=Parser_float(HT_after,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="EMHT") returnvalue*=Parser_float(EMHT_after,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="MT") returnvalue*=Parser_float(MT,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="ST") returnvalue*=Parser_float(ST,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="ST_G") returnvalue*=Parser_float(ST_G,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="metFilters") returnvalue*=Parser(metFilters&(int)_cut_value[i],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="metFilters_hardcoded") returnvalue*=Parser(metFilters_hardcoded,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="Flag_METFilters") returnvalue*=Parser(Flag_METFilters,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="MET") returnvalue*=Parser_float(MET,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="dphi_met_jet") returnvalue*=Parser_float(dphi_met_jet,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="dphi_met_jet_at_high_njet") {if (nonHiggsJet>=4) returnvalue*=Parser_float(dphi_met_jet,_cut_operator[i],_cut_value[i]);}
    else if (_cut_variable[i]=="dphi_met_jet_at_low_njet") {if (nonHiggsJet<4) returnvalue*=Parser_float(dphi_met_jet,_cut_operator[i],_cut_value[i]);}
    else if (_cut_variable[i]=="dphi_met_H_candidate") returnvalue*=Parser_float(dphi_met_H_candidate,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="dphi_met_Hmin_candidate") returnvalue*=Parser_float(dphi_met_H_candidate,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="dphi_met_H_candidate_at_low_njet") {if (nonHiggsJet<4) returnvalue*=Parser_float(dphi_met_H_candidate,_cut_operator[i],_cut_value[i]);}
    else if (_cut_variable[i]=="dphi_met_Hmin_candidate_at_low_njet") {if (nonHiggsJet<4) returnvalue*=Parser_float(dphi_met_Hmin_candidate,_cut_operator[i],_cut_value[i]);}
    else if (_cut_variable[i]=="L1prefire") returnvalue*=Parser(L1prefire,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassAK4") returnvalue*=Parser(nPassAK4,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nPassAK8") returnvalue*=Parser(nPassAK8,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="nonHiggsJet") returnvalue*=Parser(nonHiggsJet,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcounterDeep_L") returnvalue*=Parser(bcounterDeep[1],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcounterDeep_M") returnvalue*=Parser(bcounterDeep[2],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcounterDeep_T") returnvalue*=Parser(bcounterDeep[3],_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="bcounterDDBvL_L") {returnvalue*=Parser(bcounterDDBvL[1],_cut_operator[i],_cut_value[i]); if (!isData) w*=DDBvL_SF_L[DDBvL_whichSF];}
    else if (_cut_variable[i]=="bcounterDDBvL_M1") {returnvalue*=Parser(bcounterDDBvL[2],_cut_operator[i],_cut_value[i]); if (!isData) w*=DDBvL_SF_M1[DDBvL_whichSF];}
    else if (_cut_variable[i]=="bcounterDDBvL_M2") {returnvalue*=Parser(bcounterDDBvL[3],_cut_operator[i],_cut_value[i]); if (!isData) w*=DDBvL_SF_M2[DDBvL_whichSF];}
    else if (_cut_variable[i]=="bcounterDDBvL_T1") {returnvalue*=Parser(bcounterDDBvL[4],_cut_operator[i],_cut_value[i]); if (!isData) w*=DDBvL_SF_T1[DDBvL_whichSF];}
    else if (_cut_variable[i]=="bcounterDDBvL_T2") {returnvalue*=Parser(bcounterDDBvL[5],_cut_operator[i],_cut_value[i]); if (!isData) w*=DDBvL_SF_T2[DDBvL_whichSF];}
    else if (_cut_variable[i]=="DDBvL_selected") {
      returnvalue*=Parser(DDBvL_selected,_cut_operator[i],_cut_value[i]);
      if (_fastSim) {
        if (_cut_value[i]==1) w*=DDBvL_SF_L[DDBvL_whichSF];
        if (_cut_value[i]==2) w*=DDBvL_SF_M1[DDBvL_whichSF];
        if (_cut_value[i]==3) w*=DDBvL_SF_M2[DDBvL_whichSF];
        if (_cut_value[i]==4) w*=DDBvL_SF_T1[DDBvL_whichSF];
        if (_cut_value[i]==5) w*=DDBvL_SF_T2[DDBvL_whichSF];
      }
    }
    else if (_cut_variable[i]=="Deep_selected") {
      returnvalue*=Parser(Deep_selected,_cut_operator[i],_cut_value[i]);
      if (!isData) {
        if (_cut_value[i]==1) w*=Deep_SF_L[Deep_whichSF];
        if (_cut_value[i]==2) w*=Deep_SF_L[Deep_whichSF]*Deep_SF_L[Deep_whichSF];
      }
    }
    else if (_cut_variable[i]=="sth_selected") {
      returnvalue*=Parser(Deep_selected+DDBvL_selected,_cut_operator[i],_cut_value[i]);
      if (_cut_variable[i]>0) {
        if (Deep_selected==1) w*=Deep_SF_L[Deep_whichSF];
        if (Deep_selected==2) w*=Deep_SF_L[Deep_whichSF]*Deep_SF_L[Deep_whichSF];
      }
    }
    else if (_cut_variable[i]=="passBtag") returnvalue*=Parser(passBtag,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="passAK4Btag1") returnvalue*=Parser(passAK4Btag1,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="passAK4Btag2") returnvalue*=Parser(passAK4Btag2,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="passHiggsMass") returnvalue*=Parser(passHiggsMass,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="passAK4HiggsMass") returnvalue*=Parser(passAK4HiggsMass,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="notAK4") returnvalue*=Parser(notAK4,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="Hbb") returnvalue*=Parser(Hbb,_cut_operator[i],_cut_value[i]);
    else if (_cut_variable[i]=="SignalHiggs") {returnvalue*=Parser(SignalHiggs,_cut_operator[i],_cut_value[i]);}
    else if (_cut_variable[i]=="truePU") {returnvalue*=Parser(truePU,_cut_operator[i],_cut_value[i]);}
    else if (_cut_variable[i]=="nVtx") {returnvalue*=Parser(PV_npvs,_cut_operator[i],_cut_value[i]);}
    else if (_cut_variable[i]=="mcLeptonFilter") returnvalue*=Parser(mcLeptonFilter,_cut_operator[i],_cut_value[i]);
    else {cout<<"ERROR! Unknown cut variable: "<<_cut_variable[i]<<endl; returnvalue=false;}
    if (returnvalue) {
      if (SignalScan) {h_cuts->Fill(i,w); m_cuts[mass_pair]->Fill(i,w);}
      else h_cuts->Fill(i,w);
    }
    else break;
  }
  return returnvalue;
}

double Analyzer::deltaR(double phi1, double phi2, double eta1, double eta2){
  double dR=0;
  if (abs(phi1-phi2)>M_PI) dR=sqrt(pow(2*M_PI-(abs(phi2-phi1)),2)+pow(eta1-eta2,2));
  else dR=sqrt(pow(phi1-phi2,2)+pow(eta1-eta2,2));
  return dR;
}

double Analyzer::deltaPhi(double phi1, double phi2){
  return (abs(phi1-phi2)>M_PI) ? 2*M_PI-abs(phi2-phi1) : abs(phi1-phi2);
}

float Analyzer::Photon_SCEta_Zonly(const int i){
  float tg_theta_over_2   = exp(-Photon_eta[i]);
  float tg_theta          = 2 * tg_theta_over_2 / (1-tg_theta_over_2*tg_theta_over_2);//tan(atan(tg_theta_over_2)*2);//
  float tg_sctheta;

  if (Photon_isScEtaEB[i]){//barrel
    float height         = 130;
    float base           = height / tg_theta;
    float intersection_z = base + PV_z;//10;
    tg_sctheta           = height / intersection_z;
  } else if ( Photon_isScEtaEE[i]){
    float intersection_z = (Photon_eta[i]>0)?310:-310;
    float base           = intersection_z - PV_z;//10;
    float height         = base * tg_theta;
    tg_sctheta           = height/intersection_z;
  }
  else return Photon_eta[i];

  float sctheta = atan(tg_sctheta);
  if (sctheta<0) sctheta += M_PI;
  float tg_sctheta_over_2 = tan(sctheta/2);//-sqrt(tg_sctheta*tg_sctheta+1)/tg_sctheta -1/tg_sctheta;
  float SCEta = -log(tg_sctheta_over_2);

  return SCEta;
}

float Analyzer::Photon_SCEta(const int i){
  float tg_theta_over_2   = exp(-Photon_eta[i]);
  float tg_theta          = 2 * tg_theta_over_2 / (1-tg_theta_over_2*tg_theta_over_2);//tan(atan(tg_theta_over_2)*2);//
  float tg_sctheta;

  if (Photon_isScEtaEB[i]){//barrel
    float R              = 130;
    float angle_x0_y0    = 0;
    if      (PV_x>0) angle_x0_y0 = atan(PV_y/PV_x);
    else if (PV_x<0) angle_x0_y0 = M_PI + atan(PV_y/PV_x);
    else if (PV_y>0) angle_x0_y0 = M_PI / 2;
    else             angle_x0_y0 = - M_PI / 2;

    float alpha      = angle_x0_y0 + (M_PI - Photon_phi[i]);
    float sin_beta   = sqrt(PV_x*PV_x + PV_y*PV_y) / R * sin(alpha);
    float beta       = abs( asin( sin_beta ) );
    float gamma      = M_PI/2 - alpha - beta;
    float l          = sqrt(R*R + (PV_x*PV_x + PV_y*PV_y) - 2*R*sqrt(PV_x*PV_x + PV_y*PV_y)*cos(gamma));

    // cout<<"angle_x0_y0 "<<angle_x0_y0/M_PI*360<<endl;
    // cout<<"alpha "<<alpha/M_PI*360<<endl;
    // cout<<"sin_beta "<<sin_beta<<endl;
    // cout<<"beta "<<beta/M_PI*360<<endl;
    // cout<<"gamma "<<gamma/M_PI*360<<endl;
    // cout<<"l "<<l<<endl;

    float z0_zSC    = l / tg_theta;
    tg_sctheta      = R / (PV_z + z0_zSC);

   
  } else if ( Photon_isScEtaEE[i]){//endcap

      float intersection_z = (Photon_eta[i]>0)?310:-310;
      float base           = intersection_z - PV_z;//10;
      float r              = base * tg_theta;

      float crystalX       = PV_x + r * cos(Photon_phi[i]);
      float crystalY       = PV_y + r * sin(Photon_phi[i]);
      tg_sctheta           = sqrt( crystalX*crystalX + crystalY*crystalY ) /intersection_z;
  }
  else return Photon_eta[i];

  float sctheta = atan(tg_sctheta);
  if (sctheta<0) sctheta += M_PI;
  float tg_sctheta_over_2 = tan(sctheta/2);//-sqrt(tg_sctheta*tg_sctheta+1)/tg_sctheta -1/tg_sctheta;
  float SCEta = -log(tg_sctheta_over_2);

  return SCEta;
}

void Analyzer::CalcBtagSF(bool fastsim, float v_eta[], vector<float> v_pt, int v_had[], map<int,char> passCut, TEfficiency *eff_b_L, TEfficiency *eff_c_L, TEfficiency *eff_l_L, TEfficiency *eff_b_M, TEfficiency *eff_c_M, TEfficiency *eff_l_M, TEfficiency *eff_b_T, TEfficiency *eff_c_T, TEfficiency *eff_l_T, BTCalibrationReader reader_L, BTCalibrationReader reader_M, BTCalibrationReader reader_T, BTCalibrationReader fastreader_L, BTCalibrationReader fastreader_M, BTCalibrationReader fastreader_T, double (&SF_L)[3], double (&SF_M)[3], double (&SF_T)[3]){
  double p_data[3] = {1,1,1}, p_mc[3] = {1,1,1}, p_data_up[3] = {1,1,1}, p_data_do[3] = {1,1,1};
  //cout<<"njets "<<passCut.size()<<endl;
  for (map<int,char>::iterator it=passCut.begin(); it!=passCut.end(); ++it){
    BTEntry::JetFlavor FLAV;
    double mc_eff[3]={0}, eta=0, pt=0;
    eta=v_eta[it->first];
    pt=v_pt[it->first];
    //cout<<"pt "<<pt<<" eta "<<eta<<" flav "<<v_had[it->first]<<" tag "<<it->second<<endl;
    if (pt>=2000) pt=1999;
    if (v_had[it->first]==5) {
      FLAV = BTEntry::FLAV_B;
      mc_eff[0] = eff_b_L->GetEfficiency(eff_b_L->FindFixBin(eta,pt));
      mc_eff[1] = eff_b_M->GetEfficiency(eff_b_M->FindFixBin(eta,pt));
      mc_eff[2] = eff_b_T->GetEfficiency(eff_b_T->FindFixBin(eta,pt));
    }
    else if (v_had[it->first]==4) {
      FLAV = BTEntry::FLAV_C;
      mc_eff[0] = eff_c_L->GetEfficiency(eff_c_L->FindFixBin(eta,pt));
      mc_eff[1] = eff_c_M->GetEfficiency(eff_c_M->FindFixBin(eta,pt));
      mc_eff[2] = eff_c_T->GetEfficiency(eff_c_T->FindFixBin(eta,pt));
    }
    else if (v_had[it->first]==0) {
      FLAV = BTEntry::FLAV_UDSG;
      mc_eff[0] = eff_l_L->GetEfficiency(eff_l_L->FindFixBin(eta,pt));
      mc_eff[1] = eff_l_M->GetEfficiency(eff_l_M->FindFixBin(eta,pt));
      mc_eff[2] = eff_l_T->GetEfficiency(eff_l_T->FindFixBin(eta,pt));
    }
    double SF[3], SF_up[3], SF_do[3];
    SF[0] = reader_L.eval_auto_bounds("central",FLAV,eta,pt); if (fastsim) SF[0]*=fastreader_L.eval_auto_bounds("central",FLAV,eta,pt);
    SF[1] = reader_M.eval_auto_bounds("central",FLAV,eta,pt); if (fastsim) SF[1]*=fastreader_M.eval_auto_bounds("central",FLAV,eta,pt) ;
    SF[2] = reader_T.eval_auto_bounds("central",FLAV,eta,pt); if (fastsim) SF[2]*=fastreader_T.eval_auto_bounds("central",FLAV,eta,pt);
    SF_up[0] = reader_L.eval_auto_bounds("up", FLAV, eta, pt); if (fastsim)   SF_up[0]*=fastreader_L.eval_auto_bounds("up",FLAV,eta,pt);
    SF_do[0] = reader_L.eval_auto_bounds("down", FLAV, eta, pt); if (fastsim) SF_do[0]*=fastreader_L.eval_auto_bounds("down",FLAV,eta,pt);
    SF_up[1] = reader_M.eval_auto_bounds("up", FLAV, eta, pt); if (fastsim)   SF_up[1]*=fastreader_M.eval_auto_bounds("up",FLAV,eta,pt);
    SF_do[1] = reader_M.eval_auto_bounds("down", FLAV, eta, pt); if (fastsim) SF_do[1]*=fastreader_M.eval_auto_bounds("down",FLAV,eta,pt);
    SF_up[2] = reader_T.eval_auto_bounds("up", FLAV, eta, pt); if (fastsim)   SF_up[2]*=fastreader_T.eval_auto_bounds("up",FLAV,eta,pt);
    SF_do[2] = reader_T.eval_auto_bounds("down", FLAV, eta, pt); if (fastsim) SF_do[2]*=fastreader_T.eval_auto_bounds("down",FLAV,eta,pt);
    //cout<<"mc eff "<<mc_eff[0]<<" "<<mc_eff[1]<<" "<<mc_eff[2]<<endl;
    //cout<<"SF L "<<SF[0]<<" + "<<SF_up[0]<<" - "<<SF_do[0]<<" M "<<SF[1]<<" + "<<SF_up[1]<<" - "<<SF_do[1]<<" T "<<SF[2]<<" + "<<SF_up[2]<<" - "<<SF_do[2]<<endl;
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
  //cout<<"LOOSE p_data "<<p_data[0]<<" p_mc "<<p_mc[0]<<" w="<<p_data[0]/p_mc[0]<<endl;
  //if (p_data[0]/p_mc[0]>20) cout<<"HAHO"<<endl;
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

void Analyzer::CalcBtagSF_AK8(int year, vector<float> v_pt, map<int,char> passCut, double (&SF_L)[3], double (&SF_M1)[3], double (&SF_M2)[3], double (&SF_T1)[3], double (&SF_T2)[3]){
  for (unsigned int i=0;i<3;i++) {SF_L[i]=1; SF_M1[i]=1; SF_M2[i]=1; SF_T1[i]=1; SF_T2[i]=1;}
  for (map<int,char>::iterator it=passCut.begin(); it!=passCut.end(); ++it){
    double pt=v_pt[it->first];
    //cout<<it->second<<" pt "<<pt<<endl;
    if (year==2016) {
      if (pt>350 && pt<850) {
        if (it->second != '0') {SF_L[0] = 0.95; SF_L[1] = SF_L[0]+0.10; SF_L[2] = SF_L[0]-0.04;}
        if (it->second != '0' && it->second != 'L') {SF_M1[0] = 0.86; SF_M1[1] = SF_M1[0]+0.11; SF_M1[2] = SF_M1[0]-0.04;}
        if (it->second == 'H' || it->second == 'T' || it->second == 'C') {SF_M2[0] = 0.77; SF_M2[1] = SF_M2[0]+0.11; SF_M2[2] = SF_M2[0]-0.04;}
        if (it->second == 'T' || it->second == 'C') {SF_T1[0] = 0.74; SF_T1[1] = SF_T1[0]+0.10; SF_T1[2] = SF_T1[0]-0.08;}
        if (it->second == 'C') {SF_T2[0] = 0.68; SF_T2[1] = SF_T2[0]+0.20; SF_T2[2] = SF_T2[0]-0.10;}
      }
      else {
        if (it->second != '0') {SF_L[0] = 0.95; SF_L[1] = SF_L[0]+2*0.10; SF_L[2] = SF_L[0]-2*0.04;}
        if (it->second != '0' && it->second != 'L') {SF_M1[0] = 0.86; SF_M1[1] = SF_M1[0]+2*0.11; SF_M1[2] = SF_M1[0]-2*0.04;}
        if (it->second == 'H' || it->second == 'T' || it->second == 'C') {SF_M2[0] = 0.77; SF_M2[1] = SF_M2[0]+2*0.11; SF_M2[2] = SF_M2[0]-2*0.04;}
        if (it->second == 'T' || it->second == 'C') {SF_T1[0] = 0.74; SF_T1[1] = SF_T1[0]+2*0.10; SF_T1[2] = SF_T1[0]-2*0.08;}
        if (it->second == 'C') {SF_T2[0] = 0.68; SF_T2[1] = SF_T2[0]+2*0.20; SF_T2[2] = SF_T2[0]-2*0.10;}
      }
    }
    if (year==2017) {
      if (pt<350) {
        if (it->second != '0') {SF_L[0] = 0.92; SF_L[1] = SF_L[0]+0.04; SF_L[2] = SF_L[0]-0.04;}
        if (it->second != '0' && it->second != 'L') {SF_M1[1] = 0.82; SF_M1[1] = SF_M1[0]+0.04; SF_M1[2] = SF_M1[0]-0.05;}
        if (it->second == 'H' || it->second == 'T' || it->second == 'C') {SF_M2[0] = 0.72; SF_M2[1] = SF_M2[0]+0.05; SF_M2[2] = SF_M2[0]-0.05;}
        if (it->second == 'T' || it->second == 'C') {SF_T1[0] = 0.62; SF_T1[1] = SF_T1[0]+0.04; SF_T1[2] = SF_T1[0]-0.05;}
        if (it->second == 'C') {SF_T2[0] = 0.57; SF_T2[1] = SF_T2[0]+0.05; SF_T2[2] = SF_T2[0]-0.05;}
      }
      else if (pt<850) {
        if (it->second != '0') {SF_L[0] = 1.01; SF_L[1] = SF_L[0]+0.07; SF_L[2] = SF_L[0]-0.12;}
        if (it->second != '0' && it->second != 'L') {SF_M1[0] = 0.77; SF_M1[1] = SF_M1[0]+0.06; SF_M1[2] = SF_M1[0]-0.10;}
        if (it->second == 'H' || it->second == 'T' || it->second == 'C') {SF_M2[0] = 0.68; SF_M2[1] = SF_M2[0]+0.05; SF_M2[2] = SF_M2[0]-0.07;}
        if (it->second == 'T' || it->second == 'C') {SF_T1[0] = 0.65; SF_T1[1] = SF_T1[0]+0.06; SF_T1[2] = SF_T1[0]-0.11;}
        if (it->second == 'C') {SF_T2[0] = 0.54; SF_T2[1] = SF_T2[0]+0.15; SF_T2[2] = SF_T2[0]-0.23;}
      }
      else {
        if (it->second != '0') {SF_L[0] = 1.01; SF_L[1] = SF_L[0]+2*0.07; SF_L[2] = SF_L[0]-2*0.12;}
        if (it->second != '0' && it->second != 'L') {SF_M1[0] = 0.77; SF_M1[1] = SF_M1[0]+2*0.06; SF_M1[2] = SF_M1[0]-2*0.10;}
        if (it->second == 'H' || it->second == 'T' || it->second == 'C') {SF_M2[0] = 0.68; SF_M2[1] = SF_M2[0]+2*0.05; SF_M2[2] = SF_M2[0]-2*0.07;}
        if (it->second == 'T' || it->second == 'C') {SF_T1[0] = 0.65; SF_T1[1] = SF_T1[0]+2*0.06; SF_T1[2] = SF_T1[0]-2*0.11;}
        if (it->second == 'C') {SF_T2[0] = 0.54; SF_T2[1] = SF_T2[0]+2*0.15; SF_T2[2] = SF_T2[0]-2*0.23;}
      }
    }
    if (year==2018) {
      if (pt<350) {
        if (it->second != '0') {SF_L[0] = 0.97; SF_L[1] = SF_L[0]+0.04; SF_L[2] = SF_L[0]-0.05;}
        if (it->second != '0' && it->second != 'L') {SF_M1[0] = 0.81; SF_M1[1] = SF_M1[0]+0.07; SF_M1[2] = SF_M1[2]-0.05;}
        if (it->second == 'H' || it->second == 'T' || it->second == 'C') {SF_M2[0] = 0.74; SF_M2[1] = SF_M2[0]+0.06; SF_M2[2] = SF_M2[0]-0.05;}
        if (it->second == 'T' || it->second == 'C') {SF_T1[0] = 0.65; SF_T1[1] = SF_T1[0]+0.07; SF_T1[2] = SF_T1[0]-0.05;}
        if (it->second == 'C') {SF_T2[0] = 0.61; SF_T2[1] = SF_T2[0]+0.05; SF_T2[2] = SF_T2[0]-0.05;}
      }
      else if (pt<850) {
        if (it->second != '0') {SF_L[0] = 0.96; SF_L[1] = SF_L[0]+0.07; SF_L[2] = SF_L[0]-0.06;}
        if (it->second != '0' && it->second != 'L') {SF_M1[0] = 0.76; SF_M1[1] = SF_M1[0]+0.06; SF_M1[2] = SF_M1[0]-0.05;}
        if (it->second == 'H' || it->second == 'T' || it->second == 'C') {SF_M2[0] = 0.70; SF_M2[1] = SF_M2[0]+0.07; SF_M2[2] = SF_M2[0]-0.06;}
        if (it->second == 'T' || it->second == 'C') {SF_T1[0] = 0.67; SF_T1[1] = SF_T1[0]+0.10; SF_T1[2] = SF_T1[0]-0.05;}
        if (it->second == 'C') {SF_T2[0] = 0.69; SF_T2[1] = SF_T2[0]+0.07; SF_T2[2] = SF_T2[0]-0.09;}
      }
      else {
        if (it->second != '0') {SF_L[0] = 0.96; SF_L[1] = SF_L[0]+2*0.07; SF_L[2] = SF_L[0]-2*0.06;}
        if (it->second != '0' && it->second != 'L') {SF_M1[0] = 0.76; SF_M1[1] = SF_M1[0]+2*0.06; SF_M1[2] = SF_M1[0]-2*0.05;}
        if (it->second == 'H' || it->second == 'T' || it->second == 'C') {SF_M2[0] = 0.70; SF_M2[1] = SF_M2[0]+2*0.07; SF_M2[2] = SF_M2[0]-2*0.06;}
        if (it->second == 'T' || it->second == 'C') {SF_T1[0] = 0.67; SF_T1[1] = SF_T1[0]+2*0.10; SF_T1[2] = SF_T1[0]-2*0.05;}
        if (it->second == 'C') {SF_T2[0] = 0.69; SF_T2[1] = SF_T2[0]+2*0.07; SF_T2[2] = SF_T2[0]-2*0.09;}
      }
    }
  }
  /*
  cout<<"SF_L "<<SF_L[0]<<" + "<<SF_L[1]<<" - "<<SF_L[2]<<endl;
  cout<<"SF_M1 "<<SF_M1[0]<<" + "<<SF_M1[1]<<" - "<<SF_M1[2]<<endl;
  cout<<"SF_M2 "<<SF_M2[0]<<" + "<<SF_M2[1]<<" - "<<SF_M2[2]<<endl;
  cout<<"SF_T1 "<<SF_T1[0]<<" + "<<SF_T1[1]<<" - "<<SF_T1[2]<<endl;
  cout<<"SF_T2 "<<SF_T2[0]<<" + "<<SF_T2[1]<<" - "<<SF_T2[2]<<endl;
  */
}

void Analyzer::Systematics(map<string, int> systematics) {
  for (auto const& x : systematics) {
    if (x.first=="DDBvL") DDBvL_whichSF=x.second;
    else if (x.first=="Deep") Deep_whichSF=x.second;
    else if (x.first=="JER") JER_whichSF=x.second;
    else if (x.first=="JES") JES_whichSF=x.second;
    else if (x.first=="UES") UES_whichSF=x.second;
    else if (x.first=="JMS") JMS_whichSF=x.second;
    else if (x.first=="JMR") JMR_whichSF=x.second;
    else if (x.first=="phoID") phoID_whichSF=x.second;
    else if (x.first=="phoPix") phoPix_whichSF=x.second;
    else if (x.first=="eleID") eleID_whichSF=x.second;
    else if (x.first=="eleRec") eleRec_whichSF=x.second;
    else if (x.first=="muID") muID_whichSF=x.second;
    else if (x.first=="muISO") muISO_whichSF=x.second;
    else if (x.first=="tau") tau_whichSF=x.second;
    else if (x.first=="L1prefire") L1prefire_whichSF=x.second;
    else if (x.first=="Egamma_scale_stat") Egamma_Statscale_whichSF=x.second;
    else if (x.first=="Egamma_scale_syst") Egamma_Systscale_whichSF=x.second;
    else if (x.first=="Egamma_scale_gain") Egamma_Gainscale_whichSF=x.second;
    else if (x.first=="Egamma_resol_rho") Egamma_Rhoresol_whichSF=x.second;
    else if (x.first=="Egamma_resol_phi") Egamma_Phiresol_whichSF=x.second;
    else if (x.first=="genMET") genMET_whichSF=x.second;
    else if (x.first=="ISR") ISR_whichSF=x.second;
    else if (x.first=="PUweight") PUweight_whichSF=x.second;
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
  {"isPVGood","Number of good vertices"},
  {"nPassEleL","number of loose electrons, also sets the working point for electrons to LOOSE"},
  {"nPassEleM","number of medium electrons, also sets the working point for electrons to MEDIUM"},
  {"nPassEleT","number of tight electrons, also sets the working point for electrons to TIGHT"},
  {"nPassMuL","number of loose muons, also sets the working point for muons to LOOSE"},
  {"nPassMuM","number of medium muons, also sets the working point for muons to MEDIUM"},
  {"nPassMuT","number of tight muons, also sets the working point for muons to TIGHT"},
  {"nPassTauL","number of loose taus, also sets the working point for taus to LOOSE"},
  {"nPassTauM","number of medium taus, also sets the working point for taus to MEDIUM"},
  {"nPassTauT","number of tight taus, also sets the working point for taus to TIGHT"},
  {"nPassLepL","number of loose leptons (e+mu+tau), also sets the working point for leptons to LOOSE"},
  {"nPassLepM","number of medium leptons (e+mu+tau), also sets the working point for leptons to MEDIUM"},
  {"nPassLepT","number of tight leptons (e+mu+tau), also sets the working point for leptons to TIGHT"},
  {"nPassLepVLL","number of veto e + loose mu + loose tau, also sets the working point for leptons"},
  {"nPassLepMLL","number of medium e + loose mu + loose tau, also sets the working point for leptons"},
  {"nPassLepLML","number of loose e + medium mu + loose tau, also sets the working point for leptons"},
  {"nPassLepLLM","number of loose e + loose mu + medium tau, also sets the working point for leptons"},
  {"nPassIso","number of isolated tracks"},
  {"nPassFREleL","number of loose FRele (no overlap removal with photons)"},
  {"nPassFREleM","number of medium FRele (no overlap removal with photons)"},
  {"nPassFREleT","number of tight FRele (no overlap removal with photons)"},
  {"nPassElePhoL","number of loose elephotons (electrons as inverted pixelseed photons), also sets the working point for photons to LOOSE"},
  {"nPassElePhoM","number of medium elephotons (electrons as inverted pixelseed photons), also sets the working point for photons to MEDIUM"},
  {"nPassElePhoT","number of tight elephotons (electrons as inverted pixelseed photons), also sets the working point for photons to TIGHT"},
  {"nPassElePhoMVA80","number of MVA80 elephotons (electrons as inverted pixelseed photons), also sets the working point for photons to MVA80"},
  {"nPassElePhoMVA90","number of MVA90 elephotons (electrons as inverted pixelseed photons), also sets the working point for photons to MVA90"},
  {"nPassPhoL","number of loose photons, also sets the working point for photons to LOOSE"},
  {"nPassPhoM","number of medium photons, also sets the working point for photons to MEDIUM"},
  {"nPassPhoT","number of tight photons, also sets the working point for photons to TIGHT"},
  {"nPassPhoMVA80","number of MVA80 photons, also sets the working point for photons to MVA80"},
  {"nPassPhoMVA90","number of MVA90 photons, also sets the working point for photons to MVA90"},
  {"elePt","Pt of leading loose electron"},
  {"elephoPt","Pt of leading loose electronphoton"},
  {"phoEt","Et of leading loose photon"},
  {"HT","pt sum of loose jets"},
  {"EMHT","HT + Et of loose photons"},
  {"MT","invariant mass of leading loose photon and MET"},
  {"ST","HT+MET+Et of loose photons"},
  {"ST_G","MET+Et of loose photons"},
  {"metFilters","Recommended metFilters in a bitmap. Cuts on this means metFilters&cut operator cut. 2^0: goodVertices, 1: globalSuperTightHalo2016Filter, 2: HBHENoiseFilter, 3: HBHENoiseIsoFilter, 4: EcalDeadCellTriggerPrimitiveFilter, 5: BadPFMuonFilter, 6: BadChargedCandidateFilter, 7: eeBadScFilter, 8: ecalBadCalibFilter"},
  {"metFilters_hardcoded","Hardcoded recommended metFilters"},
  {"Flag_METFilters","Flag_METFilters in nanoAOD"},
  {"MET","pfMET"},
  {"dphi_met_jet","Dphi of met and nearest jet/photon with pt>100"},
  {"dphi_met_jet_at_high_njet","Dphi of met and nearest jet/photon with pt>100, only if nonHiggsJet>=4"},
  {"dphi_met_jet_at_low_njet","Dphi of met and nearest jet/photon with pt>100, only if nonHiggsJet<4"},
  {"dphi_met_H_candidate","Dphi of met and Higgs candidate"},
  {"dphi_met_Hmin_candidate","Dphi of met and minimum of Higgs candidate jets"},
  {"dphi_met_H_candidate_at_low_njet","Dphi of met and Higgs candidate, only if nonHiggsJet<4"},
  {"dphi_met_Hmin_candidate_at_low_njet","Dphi of met and minimum of Higgs candidate jets, only if nonHiggsJet<4"},
  {"L1prefire","True if event could be affected by L1prefire"},
  {"nPassAK4","number of loose ak4 jets"},
  {"nPassAK8","number of loose ak8 jets"},
  {"nonHiggsJet","number of loose ak4 jets which are not Higgs candidates"},
  {"bcounterDeep_L","number of loose Deep btagged jets"},
  {"bcounterDeep_M","number of medium Deep btagged jets"},
  {"bcounterDeep_T","number of tight Deep btagged jets"},
  {"bcounterDDBvL_L","number of loose DDBvL btagged jets"},
  {"bcounterDDBvL_M1","number of medium 1 DDBvL btagged jets"},
  {"bcounterDDBvL_M2","number of medium 2 DDBvL btagged jets"},
  {"bcounterDDBvL_T1","number of tight 1 DDBvL btagged jets"},
  {"bcounterDDBvL_T2","number of tight 2 DDBvL btagged jets"},
  {"DDBvL_selected","DDBvL btag (0-Nobtag, 1-loose, 2-medium1, ...) of the higgs candidate ak8jet"},
  {"Deep_selected","Deep btag (0-Nobtag, 1-1 loosebtag, 2-2 loose btag) of the higgs candidate ak4jets"},
  {"sth_selected","Deep_selected+DDBvL_selected"},
  {"passBtag","Higgs candidate ak8jet passes medium btag"},
  {"passAK4Btag1","Higgs candidate 1st ak4jet passes loose btag"},
  {"passAK4Btag2","Higgs candidate 2nd ak4jet passes loose btag"},
  {"passHiggsMass","At least 1 ak8jet exist with mass 70 to 200GeV"},
  {"passAK4HiggsMass","At least 1 pair of ak4jets exist with mass 70 to 200GeV"},
  {"notAK4","True if 2AK4 Higgs candidate bjets are NOT found."},
  {"Hbb","Higgs to bb found in the event (only for Signal...)"},
  {"SignalHiggs","Neutralinos decay to 0,1 or 2 Higgs. Cut on number of Higgs bosons."},
  {"truePU","Cut on number of true pileup."},
  {"nVtx","Cut on number of vertices."},
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
  cout<<"-b bname \t\t Btag efficiency file location and name (needed only for MC). Write 'hardcoded' to use predefined values."<<endl;
  cout<<"-x xname \t\t Xsec file location and name"<<endl;
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
  cout<<"./Analyzer -i /foo/bar/ggntuple_data.root -o test.root --cuts HLTPho and 4096 nPassPhoL great 0 phoEt great 175"<<endl;
  cout<<"./Analyzer -i /foo/bar/ggntuple_mc.root -o test.root -b /foo/bar/ggntuple_mc_BTagEff.root --cuts HLTPho and 4096 nPassPhoL great 0 phoEt great 175"<<endl;
  cout<<"NOTE: if you want to cut on object's (electron, photon, ...) variable (Pt, Et, ...) first cut on the # of object itself!"<<endl;
  cout<<"E.g.: --cuts phoEt great 175\t might BREAK the code! (if there's an event with no photons in ntuple)"<<endl;
  cout<<"Instead use: --cuts nPassPhoM great 0 phoEtM great 175\t"<<endl;
  cout<<"\nHave fun!"<<endl;
}
#endif // #ifdef Analyzer_cxx
