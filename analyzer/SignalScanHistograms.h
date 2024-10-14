#ifndef SignalScanHistograms_h
#define SignalScanHistograms_h
#include <TH3.h>
#include <THn.h>

  /*
  map< pair<int, int>, TH2D* > m_allAK4bjets, m_b_Deep_L, m_b_Deep_M, m_b_Deep_T;
  map< pair<int, int>, TH2D* > m_allAK4cjets, m_c_Deep_L, m_c_Deep_M, m_c_Deep_T;
  map< pair<int, int>, TH2D* > m_allAK4ljets, m_l_Deep_L, m_l_Deep_M, m_l_Deep_T;
  */

  //map of histos
  map< pair<int, int>, TDirectory* > MassPairToDirectoy;
  
  map< pair<int, int>, TH1D* > m_eff;
  map< pair<int, int>, TH1D* > m_SR;
  
  map< pair<int, int>, TH1D* > m_nPV;
 
  map< pair<int, int>, TH1D* > m_phoEt;
  map< pair<int, int>, TH1D* > m_phoEta;
  map< pair<int, int>, TH1D* > m_phoEta_highR9;

  map< pair<int, int>, TH1D* > m_phoPt;
  map< pair<int, int>, TH1D* > m_genMET;
  map< pair<int, int>, TH1D* > m_genMET_goodpair;
  map< pair<int, int>, TH1D* > m_pfMET;
  map< pair<int, int>, TH1D* > m_pfMET_fix;
  map< pair<int, int>, TH1D* > m_pfMET_fix2;
  map< pair<int, int>, TH1D* > m_pfMETsumEt;
  map< pair<int, int>, TH1D* > m_pfMETPhi;
  map< pair<int, int>, TH1D* > m_pfMETSig;
  
  map< pair<int, int>, TH2D* > m2_higgs_pfMET;

  map< pair<int, int>, TH1D* > m_ST;
  map< pair<int, int>, TH1D* > m_ST_G;
  map< pair<int, int>, TH1D* > m_ST_fix;
  map< pair<int, int>, TH1D* > m_MT;
  map< pair<int, int>, TH1D* > m_MT_fix;
  map< pair<int, int>, TH1D* > m_HT_after;
  map< pair<int, int>, TH1D* > m_EMHT_after;
  map< pair<int, int>, TH2D* > m2_ST_HT;
  map< pair<int, int>, TH2D* > m2_ST_MET;
  map< pair<int, int>, TH2D* > m2_MET_HT;
  map< pair<int, int>, TH2D* > m2_MET_phoPt;
  map< pair<int, int>, TH2D* > m2_MET_extrajets;
  map< pair<int, int>, TH2D* > m2_extrajets_HT;

  map< pair<int, int>, TH1D* > m_nPho;
  map< pair<int, int>, TH1D* > m_nEle;
  map< pair<int, int>, TH1D* > m_nEleM;
  map< pair<int, int>, TH1D* > m_nEleT;
  map< pair<int, int>, TH1D* > m_nMu;
  map< pair<int, int>, TH1D* > m_nMuM;
  map< pair<int, int>, TH1D* > m_nMuT;
  map< pair<int, int>, TH1D* > m_nTau;
  map< pair<int, int>, TH1D* > m_nIso;
  
  map< pair<int, int>, TH1D* > m_ElePt;
  map< pair<int, int>, TH1D* > m_MuPt;
  map< pair<int, int>, TH1D* > m_TauPt;
  map< pair<int, int>, TH1D* > m_ElePt_fix;
  map< pair<int, int>, TH1D* > m_MuPt_fix;
  map< pair<int, int>, TH1D* > m_TauPt_fix;
 
  map< pair<int, int>, TH1D* > m_njets;
  map< pair<int, int>, TH1D* > m_nonHjets;
  map< pair<int, int>, TH1D* > m_jetpt;
  map< pair<int, int>, TH1D* > m_nAK8jets;
  map< pair<int, int>, TH1D* > m_AK8jetpt;
  
  map< pair<int, int>, TH1D* > m_bjets_l;
  map< pair<int, int>, TH1D* > m_bjets_m;
  map< pair<int, int>, TH1D* > m_bjets_t;
  map< pair<int, int>, TH1D* > m_AK8bjets_l;
  map< pair<int, int>, TH1D* > m_AK8bjets_m;
  map< pair<int, int>, TH1D* > m_AK8bjets_h;
  map< pair<int, int>, TH1D* > m_AK8bjets_t;
  map< pair<int, int>, TH1D* > m_disc_bjets_1;
  map< pair<int, int>, TH1D* > m_disc_bjets_2;
  map< pair<int, int>, TH1D* > m_disc_AK8bjets_1;
  map< pair<int, int>, TH1D* > m_disc_AK8H4q_1;
  map< pair<int, int>, TH1D* > m_disc_AK8H4q_all;
  map< pair<int, int>, TH1D* > m_disc_AK8Hbb_1;
  map< pair<int, int>, TH1D* > m_disc_AK8Hbb_all;
  map< pair<int, int>, TH1D* > m_disc_AK8Hcc_1;
  map< pair<int, int>, TH1D* > m_disc_AK8Hcc_all;
  map< pair<int, int>, TH1D* > m_disc_AK8T_1;
  map< pair<int, int>, TH1D* > m_disc_AK8T_all;
  map< pair<int, int>, TH1D* > m_disc_AK8W_1;
  map< pair<int, int>, TH1D* > m_disc_AK8W_all;
  map< pair<int, int>, TH1D* > m_disc_AK8Z_1;
  map< pair<int, int>, TH1D* > m_disc_AK8Z_all;
  map< pair<int, int>, TH2D* > m2_disc_AK8Hbb_T;
  map< pair<int, int>, TH2D* > m2_disc_AK8Xbb_T;
  
  map< pair<int, int>, TH1D* > m_pt_bjets_l1;
  map< pair<int, int>, TH1D* > m_pt_bjets_l2;
  map< pair<int, int>, TH1D* > m_pt_bjets_m;
  map< pair<int, int>, TH1D* > m_pt_AK8bjets_l;
  
  map< pair<int, int>, TH1D* > m_true_jet;
  map< pair<int, int>, TH1D* > m_true_bjet;
  
  map< pair<int, int>, TH1D* > m_mbbjet_select;
  map< pair<int, int>, TH1D* > m_AK8mass_select;
  map< pair<int, int>, TH1D* > m_dphi_met_jet;
  map< pair<int, int>, TH1D* > m_dR_ak4_Hcandidate;
  map< pair<int, int>, TH1D* > m_deta_ak4_Hcandidate;
  map< pair<int, int>, TH1D* > m_dphi_ak4_Hcandidate;
  map< pair<int, int>, TH1D* > m_pt_ak4_Hcandidate;
  map< pair<int, int>, TH1D* > m_ptsum_ak4_Hcandidate;
  map< pair<int, int>, TH2D* > m2_eta_ak4_Hcandidate;
  map< pair<int, int>, TH2D* > m2_highestAK4_dR_mass;
  map< pair<int, int>, TH2D* > m2_dphi_met_jet_nonHjets;
  map< pair<int, int>, TH2D* > m2_dphi_met_jet_njet;
  map< pair<int, int>, TH2D* > m2_dphi_met_lowjet_pt;
  map< pair<int, int>, TH2D* > m2_dphi_met_highjet_pt;
  map< pair<int, int>, TH1D* > m_dphi_met_h_ak8;
  map< pair<int, int>, TH1D* > m_dphi_met_ak8btag;
  map< pair<int, int>, TH1D* > m_dphi_met_h_ak4;
  map< pair<int, int>, TH1D* > m_dphi_met_hmin_ak4;
  map< pair<int, int>, TH1D* > m_dphi_met_ak4btag;
  map< pair<int, int>, TH1D* > m_dphi_met_btags;
  map< pair<int, int>, TH2D* > m2_dphi_met_h_ak8;
  map< pair<int, int>, TH2D* > m2_dphi_met_ak8btag;
  map< pair<int, int>, TH2D* > m2_dphi_met_h_ak4;
  map< pair<int, int>, TH2D* > m2_dphi_met_btags_ak8;
  map< pair<int, int>, TH2D* > m2_dphi_met_btags_ak4;
  map< pair<int, int>, TH2D* > m2_dphi_met_hmin_ak4;
  map< pair<int, int>, TH2D* > m2_dphi_met_ak4btag;
  map< pair<int, int>, TH2D* > m2_dphi_met_h_pt_lowjet;
  map< pair<int, int>, TH2D* > m2_dphi_met_h_pt_highjet;
  map< pair<int, int>, TH2D* > m2_dphi_met_hmin_pt_lowjet;
  map< pair<int, int>, TH2D* > m2_dphi_met_hmin_pt_highjet;
  map< pair<int, int>, TH2D* > m2_bjet1_pt_disc;
  map< pair<int, int>, TH2D* > m2_bjet2_pt_disc;
  map< pair<int, int>, TH2D* > m2_AK4_btags;
  map< pair<int, int>, TH2D* > m2_AK4Higgs_btags;
  
  map< pair<int, int>, TH1D* > m_mHAK8;
  map< pair<int, int>, TH1D* > m_mHAK4;
  map< pair<int, int>, TH2D* > m2_mHAK8;
  map< pair<int, int>, TH2D* > m2_mHAK4;
  map< pair<int, int>, TH2D* > m2_sum_mHAK;
  map< pair<int, int>, TH1D* > m_mHAK8_fake;
  map< pair<int, int>, TH1D* > m_mHAK4_fake;
  map< pair<int, int>, TH2D* > m2_mHAK8_fake;
  map< pair<int, int>, TH2D* > m2_mHAK4_fake;
  map< pair<int, int>, TH1D* > m_mHAK4_clean;
  map< pair<int, int>, TH2D* > m2_mHAK4_clean;
  map< pair<int, int>, TH1D* > m_mHAK8_clean_fake;
  map< pair<int, int>, TH1D* > m_mHAK4_clean_fake;
  map< pair<int, int>, TH2D* > m2_mHAK8_clean_fake;
  map< pair<int, int>, TH2D* > m2_mHAK4_clean_fake;
  map< pair<int, int>, TH2D* > m2_dr_SRHiggs;
  map< pair<int, int>, TH3D* > m3_mHAK4_dr_Higgs;
  
  map< pair<int, int>, THnD* > mn_AK4searchBins;
  map< pair<int, int>, THnD* > mn_AK4searchBins_noweight;
  map< pair<int, int>, THnD* > mn_AK4HTsearchBins;
  map< pair<int, int>, TH1D* > m_AK4searchBins;
  map< pair<int, int>, TH1D* > m_AK4searchBins_noweight;
  map< pair<int, int>, TH1D* > m_AK4HTsearchBins;
  map< pair<int, int>, THnD* > mn_AK8searchBins;
  map< pair<int, int>, THnD* > mn_AK8searchBins_noweight;
  map< pair<int, int>, THnD* > mn_AK8HTsearchBins;
  map< pair<int, int>, TH1D* > m_AK8searchBins;
  map< pair<int, int>, TH1D* > m_AK8searchBins_noweight;
  map< pair<int, int>, TH1D* > m_AK8HTsearchBins;

  //syst histos
  map< pair<int, int>, map<string,THnD*> > syst_mn_AK4;
  map< pair<int, int>, map<string,THnD*> > syst_mn_AK8;
  map< pair<int, int>, map<string,TH1D*> > syst_m_AK4;
  map< pair<int, int>, map<string,TH1D*> > syst_m_AK8;
   
  //signalstudy
  map< pair<int, int>, TH1D* > m_Hpt;
  map< pair<int, int>, TH1D* > m_genAK8Hmass;
  map< pair<int, int>, TH1D* > m_AK8Hmass_soft;
  map< pair<int, int>, TH1D* > m_AK8Hmass_particleNet;
  map< pair<int, int>, TH1D* > m_Hbbmass;
  map< pair<int, int>, TH1D* > m_AK4Hmass;
  map< pair<int, int>, TH1D* > m_genAK4Hmass;
  map< pair<int, int>, TH1D* > m_AK4Hpt;
  map< pair<int, int>, TH1D* > m_AK4Hptsum;
  map< pair<int, int>, TH1D* > m_PhoEt;
  map< pair<int, int>, TH1D* > m_RecoPhoEt;
  map< pair<int, int>, TH2D* > m2_Hpt_PhoEt;
  map< pair<int, int>, TH2D* > m2_reco_AK4pt_PhoEt;
  map< pair<int, int>, TH1D* > m_dphi_photon_higgs;
  map< pair<int, int>, TH1D* > m_dphi_photon_AK4higgs;
  map< pair<int, int>, TH1D* > m_true_bjets;
  map< pair<int, int>, TH1D* > m_dR_photon_higgs;
  map< pair<int, int>, TH1D* > m_dR_photon_AK4higgs;
  map< pair<int, int>, TH1D* > m_dR_AK4AK4_trueHbb;
  map< pair<int, int>, TH1D* > m_deta_AK4AK4_trueHbb;
  map< pair<int, int>, TH1D* > m_dphi_AK4AK4_trueHbb;
  map< pair<int, int>, TH2D* > m2_true_deta_AK4AK4_mass;
  map< pair<int, int>, TH2D* > m2_true_eta_AK4AK4_highest;
  map< pair<int, int>, TH2D* > m2_true_eta_AK4AK4;
  map< pair<int, int>, TH2D* > m2_true_dR_AK4AK4_mass;
  map< pair<int, int>, TH2D* > m2_true_dR_AK4AK4_btag1;
  map< pair<int, int>, TH2D* > m2_true_dR_AK4AK4_btag2;
  map< pair<int, int>, TH2D* > m2_true_dR_AK4AK4_Hpt;
  map< pair<int, int>, TH2D* > m2_true_mass_AK4AK4_btag1;
  map< pair<int, int>, TH2D* > m2_true_mass_AK4AK4_btag2;
  map< pair<int, int>, TH2D* > m2_AK4_ij;
  map< pair<int, int>, TH2D* > m2_AK4_ij_njet;
  map< pair<int, int>, TH2D* > m2_AK4_btag;
  map< pair<int, int>, TH2D* > m2_AK4_btag_highest;
  map< pair<int, int>, TH1D* > m_dphi_met_trueh_ak4;
  map< pair<int, int>, TH1D* > m_dphi_met_truehmin_ak4;
  map< pair<int, int>, TH1D* > m_dphi_trueh_gravitino;
  map< pair<int, int>, TH2D* > m2_true_Hjet1_pt_disc;
  map< pair<int, int>, TH2D* > m2_true_Hjet2_pt_disc;
  map< pair<int, int>, TH2D* > m2_true_nonHjet1_pt_disc;
  map< pair<int, int>, TH2D* > m2_true_nonHjet2_pt_disc;

map<int,vector<int>> Analyzer::init_scan_histos(TFile *outFile, bool signalstudy, int SignalScenario){
//grid points
  std::map<int,std::vector<int>> grid; std::vector<int> Yticks;
  if (SignalScenario==1 || SignalScenario==4) {
    Yticks =  std::vector<int>({127, 200, 300, 400, 500, 600, 700, 790});
    grid.insert(pair<int,vector<int>>(800,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 200, 300, 400, 500, 600, 700, 800, 890}); 
    grid.insert(pair<int,vector<int>>(900,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 975, 990}); 
    grid.insert(pair<int,vector<int>>(1000,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 1000, 1025, 1040}); 
    grid.insert(pair<int,vector<int>>(1050,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1075, 1090}); 
    grid.insert(pair<int,vector<int>>(1100,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1100, 1125, 1140}); 
    grid.insert(pair<int,vector<int>>(1150,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1175, 1190}); 
    grid.insert(pair<int,vector<int>>(1200,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1200, 1225, 1240}); 
    grid.insert(pair<int,vector<int>>(1250,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1275, 1290}); 
    grid.insert(pair<int,vector<int>>(1300,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1300, 1325, 1340}); 
    grid.insert(pair<int,vector<int>>(1350,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1375, 1390}); 
    grid.insert(pair<int,vector<int>>(1400,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1400, 1425, 1440}); 
    grid.insert(pair<int,vector<int>>(1450,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1475, 1490}); 
    grid.insert(pair<int,vector<int>>(1500,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1500, 1525, 1540}); 
    grid.insert(pair<int,vector<int>>(1550,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1575, 1590}); 
    grid.insert(pair<int,vector<int>>(1600,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1600, 1625, 1640}); 
    grid.insert(pair<int,vector<int>>(1650,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1675, 1690}); 
    grid.insert(pair<int,vector<int>>(1700,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1725, 1740}); 
    grid.insert(pair<int,vector<int>>(1750,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1775, 1790}); 
    grid.insert(pair<int,vector<int>>(1800,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1825, 1840}); 
    grid.insert(pair<int,vector<int>>(1850,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1875, 1890}); 
    grid.insert(pair<int,vector<int>>(1900,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1900, 1925, 1940}); 
    grid.insert(pair<int,vector<int>>(1950,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 1975, 1990}); 
    grid.insert(pair<int,vector<int>>(2000,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 2000, 2025, 2040}); 
    grid.insert(pair<int,vector<int>>(2050,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2075, 2090}); 
    grid.insert(pair<int,vector<int>>(2100,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2100, 2125, 2140}); 
    grid.insert(pair<int,vector<int>>(2150,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2175, 2190}); 
    grid.insert(pair<int,vector<int>>(2200,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2200, 2225, 2240}); 
    grid.insert(pair<int,vector<int>>(2250,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2275, 2290}); 
    grid.insert(pair<int,vector<int>>(2300,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2300, 2325, 2340}); 
    grid.insert(pair<int,vector<int>>(2350,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2375, 2390}); 
    grid.insert(pair<int,vector<int>>(2400,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2400, 2425, 2440}); 
    grid.insert(pair<int,vector<int>>(2450,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2250, 2300, 2350, 2400, 2450, 2475, 2490});
    grid.insert(pair<int,vector<int>>(2500,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2250, 2300, 2350, 2400, 2450, 2500, 2525, 2540});
    grid.insert(pair<int,vector<int>>(2550,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2350, 2400, 2450, 2500, 2550, 2575, 2590});
    grid.insert(pair<int,vector<int>>(2600,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2350, 2400, 2450, 2500, 2550, 2600, 2625, 2640});
    grid.insert(pair<int,vector<int>>(2650,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2450, 2500, 2550, 2600, 2650, 2675, 2690});
    grid.insert(pair<int,vector<int>>(2700,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2450, 2500, 2550, 2600, 2650, 2700, 2725, 2740});
    grid.insert(pair<int,vector<int>>(2750,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2550, 2600, 2650, 2700, 2750, 2775, 2790});
    grid.insert(pair<int,vector<int>>(2800,Yticks));
    Yticks.clear();
  }
  if (SignalScenario==2 || SignalScenario==5) {
    for (unsigned int i=0; i<53; i++) {
      int m=(300+i*25);
      grid.insert(pair<int,vector<int>>(m,{1}));
    }
  }
  
  if (SignalScenario==3) {
    Yticks =  std::vector<int>({127, 200});
    grid.insert(pair<int,vector<int>>(1800,Yticks));
    Yticks.clear();
    Yticks =  std::vector<int>({1000, 2100, 2190});
    grid.insert(pair<int,vector<int>>(2200,Yticks));
    Yticks.clear();
  }

  for (auto const&i : grid) {
    for (auto j : i.second) {

      std::pair<int,int> MassPair(i.first,j);
      std::string temp_name;
      if (SignalScenario==1 || SignalScenario==3 || SignalScenario==4) temp_name = "g" + std::to_string(i.first) + "chi" + std::to_string(j);
      if (SignalScenario==2 || SignalScenario==5) temp_name = "chi" + std::to_string(i.first);
      MassPairToDirectoy[MassPair] = outFile->mkdir(temp_name.c_str());
      MassPairToDirectoy[MassPair]->cd();
  
      const int nbins_pfMET=13;
      double xbins_pfMET[nbins_pfMET+1]={0,20,40,70,100,150,200,300,500,700,1000,1500,2000,3000};
      const int nbins_ST=13;
      double xbins_ST[nbins_ST+1]={0, 200, 400, 600, 800, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5500};



      /*
      const int nxbins=8, nybins=10;
      double Bxbins[nxbins+1]={-3,-2.4,-1.6,-0.8,0,0.8,1.6,2.4,3};
      double Bybins[nybins+1]={20,30,50,70,100,140,200,300,600,1000,2000};
      m_allAK4bjets[MassPair] = new TH2D("h_allAK4bjets",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_b_Deep_L[MassPair]= new TH2D("h_b_Deep_L",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_b_Deep_M[MassPair]= new TH2D("h_b_Deep_M",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_b_Deep_T[MassPair]= new TH2D("h_b_Deep_T",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_allAK4cjets[MassPair] = new TH2D("h_allAK4cjets",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_c_Deep_L[MassPair]= new TH2D("h_c_Deep_L",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_c_Deep_M[MassPair]= new TH2D("h_c_Deep_M",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_c_Deep_T[MassPair]= new TH2D("h_c_Deep_T",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_allAK4ljets[MassPair] = new TH2D("h_allAK4ljets",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_l_Deep_L[MassPair]= new TH2D("h_l_Deep_L",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_l_Deep_M[MassPair]= new TH2D("h_l_Deep_M",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      m_l_Deep_T[MassPair]= new TH2D("h_l_Deep_T",";#eta;p_{T}[GeV]",nxbins,Bxbins,nybins,Bybins);
      */
      
      m_cuts[MassPair] = new TH1D("h_cuts","cuts;",15,0,15);
      m_eff[MassPair] = new TH1D("h_eff","Events;Before cuts no weights, before cuts lumi weight, before cuts all weights, after cuts no weights, after cuts lumi weight, after cuts all weights",6,-0.5,5.5);
      m_SR[MassPair] = new TH1D("h_SR","",16,0.5,16.5);
   
      m_nPV[MassPair] = new TH1D("h_nPV",";number of good vertices",20,0,70);
  
      m_phoEt[MassPair] = new TH1D("h_phoEt",";E_{T}^{#gamma} [GeV]",7,25,1075);
      m_phoEta[MassPair] = new TH1D("h_phoEta",";#eta^{#gamma}",30,-3,3);
      m_phoEta_highR9[MassPair] = new TH1D("h_phoEta_highR9",";#eta^{#gamma}",30,-3,3);
      m_phoPt[MassPair] = new TH1D("h_phoPt",";#gamma{E}_{T} [GeV]",50,0,500);
  
      m_pfMET[MassPair] = new TH1D("h_pfMET",";#slash{E}_{T} [GeV]",nbins_pfMET,xbins_pfMET);
      m_pfMET_fix[MassPair]= new TH1D("h_pfMET_fix",";#slash{E}_{T} [GeV]",50,0,500);
      m_pfMET_fix2[MassPair]= new TH1D("h_pfMET_fix2",";#slash{E}_{T} [GeV]",15,0,1500);
      m_pfMETsumEt[MassPair] = new TH1D("h_pfMETsumEt",";#slash{E}_{T} sumEt",20,-50,5000);
      m_pfMETPhi[MassPair] = new TH1D("h_pfMETPhi",";#Phi^{#slash{E}_{T}}",20,-4,4);
      m_pfMETSig[MassPair] = new TH1D("h_pfMETSig",";#slash{E}_{T}Sig",50,0,2000);
      m_genMET[MassPair] = new TH1D("h_genMET",";genMET [GeV]",25,0,2500);
      m_genMET_goodpair[MassPair] = new TH1D("h_genMET_goodpair",";genMET [GeV]",25,0,2500);

      m2_higgs_pfMET[MassPair] = new TH2D("h2_higgs_pfMET",";fakeAk4, fakeAK8, 1b, B;#slash{E}_{T} [GeV]",4,0.5,4.5,nbins_pfMET,xbins_pfMET);

      m_ST[MassPair] = new TH1D("h_ST",";S_{T} [GeV]",nbins_ST,xbins_ST);
      m_ST_G[MassPair] = new TH1D("h_ST_G",";S_{T}^{#gamma} [GeV]",10,0,2000);
      m_ST_fix[MassPair]= new TH1D("h_ST_fix",";S_{T} [GeV]",15,0,3000);
      m_MT[MassPair] = new TH1D("h_MT",";M_{T} [GeV]",50,0,200);
      m_MT_fix[MassPair]= new TH1D("h_MT_fix",";M_{T} [GeV]",8,0,800);
      m_HT_after[MassPair] = new TH1D("h_HT_after","H_{T} after cuts;H_{T}[GeV]",15,0,3000);
      m_EMHT_after[MassPair] = new TH1D("h_EMHT_after","EMHT after cuts;EMHT",15,0,3000);
      m2_ST_HT[MassPair] = new TH2D("h2_ST_HT",";S_{T} [GeV];H_{T} [GeV]",nbins_ST,xbins_ST,20,0,5000);
      m2_ST_MET[MassPair]= new TH2D("h2_ST_MET",";S_{T} [GeV];MET [GeV]",nbins_ST,xbins_ST,nbins_pfMET,xbins_pfMET);
      m2_MET_HT[MassPair] = new TH2D("h2_MET_HT",";MET [GeV];H_{T} [GeV]",nbins_pfMET,xbins_pfMET,20,0,5000);
      m2_MET_phoPt[MassPair] = new TH2D("h2_MET_phoPt",";MET [GeV];E_{T}^{#gamma} [GeV]",nbins_pfMET,xbins_pfMET,10,25,1525);
      m2_MET_extrajets[MassPair] = new TH2D("h2_MET_extrajets",";MET [GeV];# extra jets",nbins_pfMET,xbins_pfMET,14,-1.5,12.5);
      m2_extrajets_HT[MassPair] = new TH2D("h2_extrajets_HT",";# of extra jets;H_{T} [GeV]",14,-1.5,12.5,20,0,5000);
      
      m_nPho[MassPair] = new TH1D("h_nPho",";# of #gamma",5,-0.5,4.5);
      m_nEle[MassPair] = new TH1D("h_nEle",";# of e_{loose}",5,-0.5,4.5);
      m_nEleM[MassPair] = new TH1D("h_nEleM",";# of e_{medium}",5,-0.5,4.5);
      m_nEleT[MassPair] = new TH1D("h_nEleT",";# of e_{tight}",5,-0.5,4.5);
      m_nMu[MassPair] = new TH1D("h_nMu",";# of #mu_{loose}",5,-0.5,4.5);
      m_nMuM[MassPair] = new TH1D("h_nMuM",";# of #mu_{medium}",5,-0.5,4.5);
      m_nMuT[MassPair] = new TH1D("h_nMuT",";# of #mu_{tight}",5,-0.5,4.5);
      m_nTau[MassPair] = new TH1D("h_nTau",";# of #tau_{loose}",5,-0.5,4.5);
      m_nIso[MassPair] = new TH1D("h_nIso",";# of IsoTracks",5,-0.5,4.5);
   
      const int nbins_lepton=12;
      double xbins_lepton[nbins_lepton+1]={0,5,10,15,20,25,30,40,60,100,200,400,1000};
      m_ElePt[MassPair] = new TH1D("h_ElePt",";leading p_{T}^{electron} [GeV]",nbins_lepton,xbins_lepton);
      m_MuPt[MassPair] = new TH1D("h_MuPt",";leading p_{T}^{#mu} [GeV]",nbins_lepton,xbins_lepton);
      m_TauPt[MassPair] = new TH1D("h_TauPt",";leading p_{T}^{#tau} [GeV]",nbins_lepton,xbins_lepton);
      m_ElePt_fix[MassPair] = new TH1D("h_ElePt_fix",";leading p_{T}^{electron} [GeV]",10,0,1000);
      m_MuPt_fix[MassPair] = new TH1D("h_MuPt_fix",";leading p_{T}^{muon} [GeV]",10,0,1000);
      m_TauPt_fix[MassPair] = new TH1D("h_TauPt_fix",";leading p_{T}^{tau} [GeV]",10,0,1000);
  
      m_njets[MassPair] = new TH1D("h_njets",";# of jets",11,-0.5,10.5);
      m_nonHjets[MassPair] = new TH1D("h_nonHjets",";# of extra jets",14,-1.5,12.5);
      m_jetpt[MassPair] = new TH1D("h_jetpt","Leading jetpt;p_{T}^{Leading jet} [GeV]",10,30,1030);
      m_nAK8jets[MassPair] = new TH1D("h_nAK8jets",";# of AK8jets",4,-0.5,3.5);
      m_AK8jetpt[MassPair] = new TH1D("h_AK8jetpt","Leading AK8jetpt;p_{T}^{Leading AK8jet} [GeV]",10,300,1300);
   
      m_bjets_l[MassPair]  = new TH1D("h_bjets_l",";# of loose b-tagged jets",5,-0.5,4.5);
      m_bjets_m[MassPair]  = new TH1D("h_bjets_m",";# of medium b-tagged jets",5,-0.5,4.5);
      m_bjets_t[MassPair]  = new TH1D("h_bjets_t",";# of tight b-tagged jets",5,-0.5,4.5);
      m_AK8bjets_l[MassPair]  = new TH1D("h_AK8bjets_l",";# of loose b-tagged AK8 jets",5,-0.5,4.5);
      m_AK8bjets_m[MassPair]  = new TH1D("h_AK8bjets_m",";# of medium2 b-tagged AK8 jets",5,-0.5,4.5);
      m_AK8bjets_h[MassPair]  = new TH1D("h_AK8bjets_h",";# of medium1 b-tagged AK8 jets",5,-0.5,4.5);
      m_AK8bjets_t[MassPair]  = new TH1D("h_AK8bjets_t",";# of tight b-tagged AK8 jets",5,-0.5,5.4);
      m_disc_bjets_1[MassPair]  = new TH1D("h_disc_bjets_1","; Highest DeepJet discr. value",30,0,1);
      m_disc_bjets_2[MassPair]  = new TH1D("h_disc_bjets_2","; 2nd highest DeepJet discr. value",30,0,1);
      string tempname="; Highest DeepDoubleB discr. value";
      if (isParticleNet) tempname="; Highest ParticleNet discr. value";
      m_disc_AK8bjets_1[MassPair]  = new TH1D("h_disc_AK8bjets_1",tempname.c_str(),30,0,1);
      m_disc_AK8H4q_1[MassPair]  = new TH1D("h_disc_AK8H4q_1",";H4q vs QCD discriminator",30,0,1);
      m_disc_AK8H4q_all[MassPair]  = new TH1D("h_disc_AK8H4q_all",";H4q vs QCD discriminator",30,0,1);
      m_disc_AK8Hbb_1[MassPair]= new TH1D("h_disc_AK8Hbb_1",";Hbb vs QCD discriminator",30,0,1);
      m_disc_AK8Hbb_all[MassPair]= new TH1D("h_disc_AK8Hbb_all",";Hbb vs QCD discriminator",30,0,1);
      m_disc_AK8Hcc_1[MassPair]= new TH1D("h_disc_AK8Hcc_1",";Hcc vs QCD discriminator",30,0,1);
      m_disc_AK8Hcc_all[MassPair]= new TH1D("h_disc_AK8Hcc_all",";Hcc vs QCD discriminator",30,0,1);
      m_disc_AK8T_1[MassPair]= new TH1D("h_disc_AK8T_1",";T vs QCD discriminator",30,0,1);
      m_disc_AK8T_all[MassPair]= new TH1D("h_disc_AK8T_all",";T vs QCD discriminator",30,0,1);
      m_disc_AK8W_1[MassPair]= new TH1D("h_disc_AK8W_1",";W vs QCD discriminator",30,0,1);
      m_disc_AK8W_all[MassPair]= new TH1D("h_disc_AK8W_all",";W vs QCD discriminator",30,0,1);
      m_disc_AK8Z_1[MassPair]= new TH1D("h_disc_AK8Z_1",";Z vs QCD discriminator",30,0,1);
      m_disc_AK8Z_all[MassPair]= new TH1D("h_disc_AK8Z_all",";Z vs QCD discriminator",30,0,1);
      m2_disc_AK8Hbb_T[MassPair]= new TH2D("h2_disc_AK8Hbb_T",";Hbb vs QCD discriminator;T vs QCD discriminator",30,0,1,30,0,1);
      m2_disc_AK8Xbb_T[MassPair]= new TH2D("h2_disc_AK8Xbb_T",";Xbb vs QCD discriminator;T vs QCD discriminator",30,0,1,30,0,1);
      
      m_pt_bjets_l1[MassPair]  = new TH1D("h_pt_bjets_l1",";p_{T} of loose b-tagged jet (highest discr. valued) [GeV]",10,30,1030);
      m_pt_bjets_l2[MassPair]  = new TH1D("h_pt_bjets_l2",";p_{T} of loose b-tagged jet (2nd highest discr. valued) [GeV]",10,30,1030);
      m_pt_bjets_m[MassPair]  = new TH1D("h_pt_bjets_m",";p_{T} of medium b-tagged jet (highest discr. valued) [GeV]",10,30,1030);
      m_pt_AK8bjets_l[MassPair]  = new TH1D("h_pt_AK8bjets_l",";p_{T} of loose b-tagged AK8jet (highest discr. valued) [GeV]",10,300,1300);
   
      m_true_jet[MassPair] = new TH1D("h_true_jet",";# of GenJet",8,-0.5,7.5);
      m_true_bjet[MassPair] = new TH1D("h_true_bjet",";# of true b GenJet",6,-0.5,5.5);
      
      m_mbbjet_select[MassPair] = new TH1D("h_mbbjet_select","Invariant mass of selected bjets;M_{bb}[GeV]",13,20,280);
      m_AK8mass_select[MassPair] = new TH1D("h_AK8mass_select","Selected AK8PrunedCorrjetmass;PrunedCorr m_{Higgs btagged AK8jets} [GeV]",13,20,280);
      m_dR_ak4_Hcandidate[MassPair] = new TH1D("h_dR_ak4_Hcandidate","dR between H candidate AK4 jets;dR",20,0,5);
      m_deta_ak4_Hcandidate[MassPair] = new TH1D("h_deta_ak4_Hcandidate",";|#Delta#eta|",30,0,3);
      m_dphi_ak4_Hcandidate[MassPair] = new TH1D("h_dphi_ak4_Hcandidate",";|#Delta#phi|",30,0,3);
      m_pt_ak4_Hcandidate[MassPair] = new TH1D("h_pt_ak4_Hcandidate","pt of H candidate AK4 jets;p_T [GeV]",25,0,1000);
      m_ptsum_ak4_Hcandidate[MassPair] = new TH1D("h_ptsum_ak4_Hcandidate","Lorentz sum pt of H candidate AK4 jets;p_T [GeV]",25,0,1000);
      m2_eta_ak4_Hcandidate[MassPair] = new TH2D("h2_eta_ak4_Hcandidate",";#eta higher tagged jet;#eta lower jet",30,-3,3,30,-3,3);
      m_dphi_met_jet[MassPair] = new TH1D("h_dphi_met_jet",";|#Delta#phi|(MET,nearest jet)",11,0,3.3);
      m2_highestAK4_dR_mass[MassPair]= new TH2D("h2_highestAK4_dR_mass","Highest discr. AK4 jets;dR;mass [GeV]",20,0,5,20,18,278);
      m2_dphi_met_jet_nonHjets[MassPair]= new TH2D("h2_dphi_met_jet_nonHjets",";|#Delta#phi|(MET,nearest jet);nonHiggsJets",11,0,3.3,14,-1.5,12.5);
      m2_dphi_met_jet_njet[MassPair]= new TH2D("h2_dphi_met_jet_njet",";|#Delta#phi|(MET,nth jet);number",11,0,3.3,8,0.5,8.5);
      m2_dphi_met_lowjet_pt[MassPair]= new TH2D("h2_dphi_met_lowjet_pt",";|#Delta#phi|(MET,jet);jet p_{T}",11,0,3.3,10,30,2030);
      m2_dphi_met_highjet_pt[MassPair]= new TH2D("h2_dphi_met_highjet_pt",";|#Delta#phi|(MET,jet);jet p_{T}",11,0,3.3,10,30,2030);
      m_dphi_met_h_ak8[MassPair]= new TH1D("h_dphi_met_h_ak8",";|#Delta#phi|(MET,ak8 H candidate)",11,0,3.3);
      m_dphi_met_ak8btag[MassPair]= new TH1D("h_dphi_met_ak8btag",";|#Delta#phi|(MET,ak8 btag)",11,0,3.3);
      m_dphi_met_h_ak4[MassPair]= new TH1D("h_dphi_met_h_ak4",";|#Delta#phi|(MET,ak4 H candidate)",11,0,3.3);
      m_dphi_met_hmin_ak4[MassPair]= new TH1D("h_dphi_met_hmin_ak4",";|#Delta#phi|(MET,ak4 Hmin candidate)",11,0,3.3);
      m_dphi_met_ak4btag[MassPair]= new TH1D("h_dphi_met_ak4btag",";|#Delta#phi|(MET,ak4 btag)",11,0,3.3);
      m_dphi_met_btags[MassPair]= new TH1D("h_dphi_met_btags",";|#Delta#phi|(MET,loose-btag-jets)",11,0,3.3);
      m2_dphi_met_h_ak8[MassPair]= new TH2D("h2_dphi_met_h_ak8",";Unrolled bins;|#Delta#phi|(MET,ak8 H candidate)",4,0.5,4.5,11,0,3.3);
      m2_dphi_met_ak8btag[MassPair]= new TH2D("h2_dphi_met_ak8btag",";Unrolled bins;|#Delta#phi|(MET,ak8 btag)",4,0.5,4.5,11,0,3.3);
      m2_dphi_met_h_ak4[MassPair]= new TH2D("h2_dphi_met_h_ak4",";Unrolled bins;|#Delta#phi|(MET,ak4 H candidate)",8,0.5,8.5,11,0,3.3);
      m2_dphi_met_btags_ak8[MassPair]= new TH2D("h2_dphi_met_btags_ak8",";Unrolled bins;|#Delta#phi|(MET,loose-jets)",4,0.5,4.5,11,0,3.3);
      m2_dphi_met_btags_ak4[MassPair]= new TH2D("h2_dphi_met_btags_ak4",";Unrolled bins;|#Delta#phi|(MET,loose-jets)",8,0.5,8.5,11,0,3.3);
      m2_dphi_met_hmin_ak4[MassPair]= new TH2D("h2_dphi_met_hmin_ak4",";Unrolled bins;|#Delta#phi|(MET,ak4 Hmin candidate)",8,0.5,8.5,11,0,3.3);
      m2_dphi_met_ak4btag[MassPair]= new TH2D("h2_dphi_met_ak4btag",";Unrolled bins;|#Delta#phi|(MET,ak4 btag)",8,0.5,8.5,11,0,3.3);
      m2_dphi_met_h_pt_lowjet[MassPair]= new TH2D("h2_dphi_met_h_pt_lowjet",";|#Delta#phi|(MET,jet/H);jet/H p_{T}",11,0,3.3,10,30,2030);
      m2_dphi_met_h_pt_highjet[MassPair]= new TH2D("h2_dphi_met_h_pt_highjet",";|#Delta#phi|(MET,jet/H);jet/H p_{T}",11,0,3.3,10,30,2030);
      m2_dphi_met_hmin_pt_lowjet[MassPair]= new TH2D("h2_dphi_met_hmin_pt_lowjet",";|#Delta#phi|(MET,jet/Hmin);jet/Hmin p_{T}",11,0,3.3,10,30,2030);
      m2_dphi_met_hmin_pt_highjet[MassPair]= new TH2D("h2_dphi_met_hmin_pt_highjet",";|#Delta#phi|(MET,jet/Hmin);jet/Hmin p_{T}",11,0,3.3,10,30,2030);
      m2_bjet1_pt_disc[MassPair] = new TH2D("h2_bjet1_pt_disc",";p_{T} [GeV];DeepJet discr",10,0,1000,10,0,1);
      m2_bjet2_pt_disc[MassPair] = new TH2D("h2_bjet2_pt_disc",";p_{T} [GeV];DeepJet discr",10,0,1000,10,0,1);
      m2_AK4_btags[MassPair] = new TH2D("h2_AK4_btags",";btag WP of highest b-tagged jet;btag WP of 2nd highest jet",4,-0.5,3.5,4,-0.5,3.5);
      m2_AK4Higgs_btags[MassPair] = new TH2D("h2_AK4Higgs_btags",";btag WP of highest b-tagged jet;btag WP of 2nd highest jet",4,-0.5,3.5,4,-0.5,3.5);

      m_mHAK8[MassPair] = new TH1D("h_mHAK8",";M_{AK8}[GeV]",30,0,300);
      m_mHAK4[MassPair] = new TH1D("h_mHAK4",";M_{bb}[GeV]",30,0,300);
      m2_mHAK8[MassPair] = new TH2D("h2_mHAK8",";Unrolled bins;M_{AK8}[GeV]",12,0.5,12.5,30,0,300);
      m2_mHAK4[MassPair] = new TH2D("h2_mHAK4",";Unrolled bins;M_{bb}[GeV]",12,0.5,12.5,30,0,300);
      m2_sum_mHAK[MassPair] = new TH2D("h2_sum_mHAK",";Unrolled bins;M[GeV]",12,0.5,12.5,30,0,300);
      m_mHAK8_fake[MassPair]= new TH1D("h_mHAK8_fake",";M_{AK8}[GeV]",20,18,278);
      m_mHAK4_fake[MassPair]= new TH1D("h_mHAK4_fake",";M_{bb}[GeV]",13,20,280);
      m2_mHAK8_fake[MassPair]= new TH2D("h2_mHAK8_fake",";Unrolled bins;M_{AK8}[GeV]",12,0.5,12.5,30,0,300);
      m2_mHAK4_fake[MassPair]= new TH2D("h2_mHAK4_fake",";Unrolled bins;M_{bb}[GeV]",12,0.5,12.5,30,0,300);
      m_mHAK4_clean[MassPair]= new TH1D("h_mHAK4_clean",";M_{bb}[GeV]",13,20,280);
      m2_mHAK4_clean[MassPair]= new TH2D("h2_mHAK4_clean",";Unrolled bins;M_{bb}[GeV]",12,0.5,12.5,30,0,300);
      m_mHAK8_clean_fake[MassPair]= new TH1D("h_mHAK8_clean_fake",";M_{AK8}[GeV]",20,18,278);
      m_mHAK4_clean_fake[MassPair]= new TH1D("h_mHAK4_clean_fake",";M_{bb}[GeV]",13,20,280);
      m2_mHAK8_clean_fake[MassPair]= new TH2D("h2_mHAK8_clean_fake",";Unrolled bins;M_{AK8}[GeV]",12,0.5,12.5,30,0,300);
      m2_mHAK4_clean_fake[MassPair]= new TH2D("h2_mHAK4_clean_fake",";Unrolled bins;M_{bb}[GeV]",12,0.5,12.5,30,0,300);
      m2_dr_SRHiggs[MassPair] = new TH2D("h2_dr_SRHiggs",";Unrolled bins;dR_{bb}",12,0.5,12.5,20,0,3.2);
      m3_mHAK4_dr_Higgs[MassPair] = new TH3D("h3_mHAK4_dr_Higgs",";Unrolled bins;M_{bb}[GeV];dR_{bb}",12,0.5,12.5,13,20,280,20,0,3.2);
      
      //AK4 searchbins
      const int dim_ak4=3;
      int nbins_ak4[dim_ak4]={2,6,2};
      double xmin_ak4[dim_ak4]={-0.5,0.5,0.5};
      double xmax_ak4[dim_ak4]={1.5,6.5,2.5};
      mn_AK4searchBins[MassPair] = new THnD("hn_AK4searchBins",";AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
      mn_AK4searchBins_noweight[MassPair] = new THnD("hn_AK4searchBins_noweight",";AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
      mn_AK4HTsearchBins[MassPair] = new THnD("hn_AK4HTsearchBins",";AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
      mn_AK4searchBins[MassPair]->Sumw2(); mn_AK4searchBins_noweight[MassPair]->Sumw2(); mn_AK4HTsearchBins[MassPair]->Sumw2();
      unsigned int nsbins_ak4=mn_AK4searchBins[MassPair]->GetNbins();
      m_AK4searchBins[MassPair]= new TH1D("h_AK4searchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
      m_AK4searchBins_noweight[MassPair]= new TH1D("h_AK4searchBins_noweight",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
      m_AK4HTsearchBins[MassPair]= new TH1D("h_AK4HTsearchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
     
      //AK8 searchbins
      const int dim_ak8=3;
      int nbins_ak8[dim_ak8]={2,6,2};
      double xmin_ak8[dim_ak8]={-0.5,0.5,0.5};
      double xmax_ak8[dim_ak8]={1.5,6.5,2.5};
      mn_AK8searchBins[MassPair] = new THnD("hn_AK8searchBins",";AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
      mn_AK8searchBins_noweight[MassPair] = new THnD("hn_AK8searchBins_noweight",";AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
      mn_AK8HTsearchBins[MassPair] = new THnD("hn_AK8HTsearchBins",";AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
      mn_AK8searchBins[MassPair]->Sumw2(); mn_AK8searchBins_noweight[MassPair]->Sumw2(); mn_AK8HTsearchBins[MassPair]->Sumw2();
      unsigned int nsbins_ak8=mn_AK8searchBins[MassPair]->GetNbins();
      m_AK8searchBins[MassPair]= new TH1D("h_AK8searchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
      m_AK8searchBins_noweight[MassPair]= new TH1D("h_AK8searchBins_noweight",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
      m_AK8HTsearchBins[MassPair]= new TH1D("h_AK8HTsearchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);

      //syst histos
      init_syst_histograms(syst_mn_AK4[MassPair], syst_m_AK4[MassPair], syst_mn_AK8[MassPair], syst_m_AK8[MassPair]);

      
       if (signalstudy){
         m_Hpt[MassPair] = new TH1D("hs_Hpt","Higgs pt;p_{T}[GeV]",25,0,1000);
         m_genAK8Hmass[MassPair] = new TH1D("hs_genAK8Hmass","AK8mass of Higgsmother GenJet; m[GeV]",30,0,300);
         m_AK8Hmass_soft[MassPair] = new TH1D("hs_AK8Hmass_soft","Soft drop mass of Higgsmother AK8jet; m[GeV]",30,0,300);
         m_AK8Hmass_particleNet[MassPair] = new TH1D("hs_AK8Hmass_particleNet","ParticleNet mass of Higgsmother AK8jet; m[GeV]",30,0,300);
         m_Hbbmass[MassPair] = new TH1D("hs_Hbbmass","Invariant mass of Higgsmother bb quarks;m_{bb}[GeV]",30,0,300);
         m_genAK4Hmass[MassPair] = new TH1D("hs_genAK4Hmass","Invariant mass of Higgsmother AK4Genjets;m_{bb}[GeV]",30,0,300);
         m_AK4Hmass[MassPair] = new TH1D("hs_AK4Hmass","Invariant mass of Higgsmother AK4jets;m_{bb}[GeV]",30,0,300);
         const int nbins_AK4Hpt=30;
         double xbins_AK4Hpt[nbins_AK4Hpt+1]={0,40,45,50,55,60,65,70,75,80,85,90,95,100,120,140,160,180,200,250,300,350,400,450,500,550,600,700,800,900,1000};
         m_AK4Hpt[MassPair] = new TH1D("hs_AK4Hpt","Pt of Higgsmother AK4jets;p_{T}[GeV]",nbins_AK4Hpt,xbins_AK4Hpt);
         m_AK4Hptsum[MassPair] = new TH1D("hs_AK4Hptsum","Lorentz sum Pt of Higgsmother AK4jets;p_{T}[GeV]",25,0,1000);
         m_PhoEt[MassPair] = new TH1D("hs_PhoEt","Et of Photon from neutralino;E_{T}[GeV]",25,0,1000);
         m_RecoPhoEt[MassPair] = new TH1D("hs_RecoPhoEt","Reconstructed Et of Photon from neutralino;E_{T}[GeV]",25,0,1000);
         m2_Hpt_PhoEt[MassPair] = new TH2D("hs_Hpt_PhoEt","Neutralino mother;Higgs p_{T}[GeV];Photon E_{T}[GeV]",25,0,1000,25,0,1000);
         m2_reco_AK4pt_PhoEt[MassPair] = new TH2D("hs_reco_AK4pt_PhoEt","Neutralino mother, Reco objects;AK4 pair p_{T}[GeV];Photon E_{T}[GeV]",25,0,1000,25,0,1000);
         m_dphi_photon_higgs[MassPair]= new TH1D("hs_dphi_photon_higgs",";|#Delta#phi|(photon,higgs)",11,0,3.3);
         m_dphi_photon_AK4higgs[MassPair]= new TH1D("hs_dphi_photon_AK4higgs",";|#Delta#phi|(photon,higgs mother AK4 jets)",11,0,3.3);
         m_true_bjets[MassPair] = new TH1D("hs_true_bjets","# of true reco b-jets, when H-mother reco AK4 is found;# of true b-jets",10,0,10);
         m_dR_photon_higgs[MassPair] = new TH1D("hs_dR_photon_higgs","dR between photon and higgs;dR",20,0,5);
         m_dR_photon_AK4higgs[MassPair] = new TH1D("hs_dR_photon_AK4higgs","dR between photon and higgs mother AK4 jets;dR",20,0,5);
         m_dR_AK4AK4_trueHbb[MassPair] = new TH1D("hs_dR_AK4AK4_trueHbb","dR between true Hbb jets ;dR",20,0,5);
         m_deta_AK4AK4_trueHbb[MassPair] = new TH1D("hs_deta_AK4AK4_trueHbb","#Delta#eta between true Hbb jets ;#Delta#eta",30,0,3);
         m_dphi_AK4AK4_trueHbb[MassPair] = new TH1D("hs_dphi_AK4AK4_trueHbb","#Delta#phi between true Hbb jets ;#Delta#phi",30,0,3);
         m_dphi_met_trueh_ak4[MassPair]= new TH1D("hs_dphi_met_h_ak4",";|#Delta#phi|(MET,ak4 H true)",11,0,3.3);
         m_dphi_met_truehmin_ak4[MassPair]= new TH1D("hs_dphi_met_hmin_ak4",";|#Delta#phi|(MET,ak4 Hmin true)",11,0,3.3);
         m_dphi_trueh_gravitino[MassPair]= new TH1D("hs_dphi_h_gravitino",";|#Delta#phi|(H,gravitino)",11,0,3.3);
         m2_true_deta_AK4AK4_mass[MassPair] = new TH2D("hs_true_deta_AK4AK4_mass",";#Delta#eta;m_{bb} [GeV]",30,0,3,20,18,278);
         m2_true_eta_AK4AK4[MassPair] = new TH2D("hs_true_eta_AK4AK4",";#eta b-jet;#eta anti b-jet",30,-3,3,30,-3,3);
         m2_true_eta_AK4AK4_highest[MassPair] = new TH2D("hs_true_eta_AK4AK4_highest",";#eta higher b-jet;#eta lower b-jet",30,-3,3,30,-3,3);
         m2_true_dR_AK4AK4_Hpt[MassPair] = new TH2D("hs_true_dR_AK4AK4_Hpt",";dR;H p_{T} [GeV]",20,0,5,25,0,1000);
         m2_true_dR_AK4AK4_mass[MassPair] = new TH2D("hs_true_dR_AK4AK4_mass",";dR;m_{bb} [GeV]",20,0,5,20,18,278);
         m2_true_dR_AK4AK4_btag1[MassPair] = new TH2D("hs_true_dR_AK4AK4_btag1",";dR;DeepJet discriminator",20,0,5,10,0,1);
         m2_true_dR_AK4AK4_btag2[MassPair] = new TH2D("hs_true_dR_AK4AK4_btag2",";dR;DeepJet discriminator",20,0,5,10,0,1);
         m2_true_mass_AK4AK4_btag1[MassPair] = new TH2D("hs_true_mass_AK4AK4_btag1",";m_{bb};DeepJet discriminator",20,18,278,10,0,1);
         m2_true_mass_AK4AK4_btag2[MassPair] = new TH2D("hs_true_mass_AK4AK4_btag2",";m_{bb};DeepJet discriminator",20,18,278,10,0,1);
         m2_AK4_ij[MassPair] = new TH2D("hs_AK4_ij",";index of b;index of anti b",10,0.5,10.5,10,0.5,10.5);
         m2_AK4_ij_njet[MassPair] = new TH2D("hs_AK4_ij_njet",";index of b / njet;index of anti b / njet",10,0,1,10,0,1);
         m2_AK4_btag[MassPair] = new TH2D("hs_AK4_btag",";btag WP of b;btag WP of anti b",4,-0.5,3.5,4,-0.5,3.5);
         m2_AK4_btag_highest[MassPair] = new TH2D("hs_AK4_btag_highest",";btag WP of highest of bb;btag WP of lower of bb",4,-0.5,3.5,4,-0.5,3.5);
         m2_true_nonHjet1_pt_disc[MassPair] = new TH2D("hs_true_nonHjet1_pt_disc",";p_{T} [GeV];DeepJet discr",10,0,1000,10,0,1);
         m2_true_nonHjet2_pt_disc[MassPair] = new TH2D("hs_true_nonHjet2_pt_disc",";p_{T} [GeV];DeepJet discr",10,0,1000,10,0,1);
         m2_true_Hjet1_pt_disc[MassPair] = new TH2D("hs_true_Hjet1_pt_disc",";p_{T} [GeV];DeepJet discr",10,0,1000,10,0,1);
         m2_true_Hjet2_pt_disc[MassPair] = new TH2D("hs_true_Hjet2_pt_disc",";p_{T} [GeV];DeepJet discr",10,0,1000,10,0,1);
       }
      }
    }
  return grid;
}

#endif
