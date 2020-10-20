#ifndef SignalScanHistograms_h
#define SignalScanHistograms_h
#include <TH3.h>
#include <THn.h>


  //map of histos
  map< pair<int, int>, TDirectory* > MassPairToDirectoy;
  
  map< pair<int, int>, TH1D* > m_eff;
  map< pair<int, int>, TH1D* > m_nISR_jet;
  map< pair<int, int>, TH1D* > m_SR;
 
  map< pair<int, int>, TH1D* > m_phoEt;
  map< pair<int, int>, TH1D* > m_phoEta;

  map< pair<int, int>, TH1D* > m_phoPt;
  map< pair<int, int>, TH1D* > m_pfMET;
  map< pair<int, int>, TH1D* > m_pfMETsumEt;
  map< pair<int, int>, TH1D* > m_pfMETPhi;
  map< pair<int, int>, TH1D* > m_pfMETSig;

  map< pair<int, int>, TH1D* > m_ST;
  map< pair<int, int>, TH1D* > m_ST_G;
  map< pair<int, int>, TH1D* > m_MT;
  map< pair<int, int>, TH1D* > m_HT_after;
  map< pair<int, int>, TH1D* > m_EMHT_after;
  map< pair<int, int>, TH2D* > m2_ST_HT;
  map< pair<int, int>, TH2D* > m2_ST_MET;
  map< pair<int, int>, TH2D* > m2_MT_MET;
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
 
  map< pair<int, int>, TH1D* > m_njets;
  map< pair<int, int>, TH1D* > m_nonHjets;
  map< pair<int, int>, TH1D* > m_jetpt;
  map< pair<int, int>, TH1D* > m_nAK8jets;
  map< pair<int, int>, TH1D* > m_AK8jetpt;
    
  
  map< pair<int, int>, TH1D* > m_mbbjet_select;
  map< pair<int, int>, TH1D* > m_AK8mass_select;
  map< pair<int, int>, TH1D* > m_dphi_met_jet;
  map< pair<int, int>, TH1D* > m_dR_ak4_Hcandidate;
  map< pair<int, int>, TH1D* > m_pt_ak4_Hcandidate;
  map< pair<int, int>, TH2D* > m2_dphi_met_jet_nonHjets;
  map< pair<int, int>, TH2D* > m2_dphi_met_jet_njet;
  map< pair<int, int>, TH2D* > m2_dphi_met_lowjet_pt;
  map< pair<int, int>, TH2D* > m2_dphi_met_highjet_pt;
  map< pair<int, int>, TH1D* > m_dphi_met_h_ak8;
  map< pair<int, int>, TH1D* > m_dphi_met_ak8btag;
  map< pair<int, int>, TH1D* > m_dphi_met_h_ak4;
  map< pair<int, int>, TH1D* > m_dphi_met_hmin_ak4;
  map< pair<int, int>, TH1D* > m_dphi_met_ak4btag;
  map< pair<int, int>, TH2D* > m2_dphi_met_h_ak8;
  map< pair<int, int>, TH2D* > m2_dphi_met_ak8btag;
  map< pair<int, int>, TH2D* > m2_dphi_met_h_ak4;
  map< pair<int, int>, TH2D* > m2_dphi_met_hmin_ak4;
  map< pair<int, int>, TH2D* > m2_dphi_met_ak4btag;
  map< pair<int, int>, TH2D* > m2_dphi_met_h_pt_lowjet;
  map< pair<int, int>, TH2D* > m2_dphi_met_h_pt_highjet;
  map< pair<int, int>, TH2D* > m2_dphi_met_hmin_pt_lowjet;
  map< pair<int, int>, TH2D* > m2_dphi_met_hmin_pt_highjet;
  
  map< pair<int, int>, TH1D* > m_mHAK8;
  map< pair<int, int>, TH1D* > m_mHAK4;
  map< pair<int, int>, TH2D* > m2_mHAK8;
  map< pair<int, int>, TH2D* > m2_mHAK4;
  map< pair<int, int>, TH2D* > m2_dr_SRHiggs;
  map< pair<int, int>, TH2D* > m2_dr_VRHiggs;
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
   
  //signalstudy
  map< pair<int, int>, TH1D* > m_Hpt;
  map< pair<int, int>, TH1D* > m_AK8Hmass;
  map< pair<int, int>, TH1D* > m_Hbbmass;
  map< pair<int, int>, TH1D* > m_AK4Hmass;
  map< pair<int, int>, TH1D* > m_genAK4Hmass;
  map< pair<int, int>, TH1D* > m_AK4Hpt;
  map< pair<int, int>, TH1D* > m_PhoEt;
  map< pair<int, int>, TH1D* > m_dR_AK4AK4_trueHbb;
  map< pair<int, int>, TH2D* > m2_true_dR_AK4AK4_mass;
  map< pair<int, int>, TH2D* > m2_AK4_ij;
  map< pair<int, int>, TH2D* > m2_AK4_ij_njet;
  map< pair<int, int>, TH2D* > m2_AK4_btag;
  map< pair<int, int>, TH1D* > m_dphi_met_trueh_ak4;
  map< pair<int, int>, TH1D* > m_dphi_met_truehmin_ak4;
  map< pair<int, int>, TH1D* > m_dphi_trueh_gravitino;

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
  if (SignalScenario==2) {
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
      if (SignalScenario==2) temp_name = "chi" + std::to_string(i.first);
      MassPairToDirectoy[MassPair] = outFile->mkdir(temp_name.c_str());
      MassPairToDirectoy[MassPair]->cd();
  
      const int nbins_pfMET=13;
      double xbins_pfMET[nbins_pfMET+1]={0,20,40,70,100,150,200,300,500,700,1000,1500,2000,3000};
      const int nbins_ST=13;
      double xbins_ST[nbins_ST+1]={0, 200, 400, 600, 800, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5500};
      const int nbins_MT=9;
      double xbins_MT[nbins_MT+1]={0, 30, 60, 100, 130, 200, 500, 1000, 1500, 2000};
      const int nbins_photon=15;
      double xbins_photon[nbins_photon+1]={0,50,120,175,210,260,310,360,410,460,510,650,800,1000,1200,1500};
    
      
      m_cuts[MassPair] = new TH1D("h_cuts","cuts;Higgs,PV,METfilter,Pho,Pho175,Lep0,MT,ST,nonHjet,BDSV,Deep1,Deep2",15,0,15);
      m_eff[MassPair] = new TH1D("h_eff","Events;Before cuts, After cuts, only lumiweight",3,-0.5,2.5);
      m_nISR_jet[MassPair] = new TH1D("h_nISR_jet",";number of ISR jets",10,0,10);
      m_SR[MassPair] = new TH1D("h_SR","",16,0.5,16.5);
  
      m_phoEt[MassPair] = new TH1D("h_phoEt",";E_{T}^{#gamma} [GeV]",10,25,1525);
      m_phoEta[MassPair] = new TH1D("h_phoEta",";#eta^{#gamma}",30,-3,3);
      m_phoPt[MassPair] = new TH1D("h_phoPt",";#gamma{E}_{T} [GeV]",nbins_photon,xbins_photon);
  
      m_pfMET[MassPair] = new TH1D("h_pfMET",";#slash{E}_{T} [GeV]",nbins_pfMET,xbins_pfMET);
      m_pfMETsumEt[MassPair] = new TH1D("h_pfMETsumEt",";#slash{E}_{T} sumEt",20,-50,5000);
      m_pfMETPhi[MassPair] = new TH1D("h_pfMETPhi",";#Phi^{#slash{E}_{T}}",20,-4,4);
      m_pfMETSig[MassPair] = new TH1D("h_pfMETSig",";#slash{E}_{T}Sig",50,0,2000);
      m_ST[MassPair] = new TH1D("h_ST",";S_{T} [GeV]",nbins_ST,xbins_ST);
      m_ST_G[MassPair] = new TH1D("h_ST_G",";S_{T}^{#gamma} [GeV]",10,0,2000);
      m_MT[MassPair] = new TH1D("h_MT",";M_{T} [GeV]",nbins_MT,xbins_MT);
      m_HT_after[MassPair] = new TH1D("h_HT_after","HT after cuts;HT",20,0,5000);
      m_EMHT_after[MassPair] = new TH1D("h_EMHT_after","EMHT after cuts;EMHT",20,0,5000);
      m2_ST_HT[MassPair] = new TH2D("h2_ST_HT",";S_{T} [GeV];H_{T} [GeV]",nbins_ST,xbins_ST,20,0,5000);
      m2_ST_MET[MassPair]= new TH2D("h2_ST_MET",";S_{T} [GeV];MET [GeV]",nbins_ST,xbins_ST,nbins_pfMET,xbins_pfMET);
      m2_MT_MET[MassPair]= new TH2D("h2_MT_MET",";M_{T} [GeV];MET [GeV]",nbins_MT,xbins_MT,nbins_pfMET,xbins_pfMET);
      m2_MET_HT[MassPair] = new TH2D("h2_MET_HT",";MET [GeV];H_{T} [GeV]",nbins_pfMET,xbins_pfMET,20,0,5000);
      m2_MET_phoPt[MassPair] = new TH2D("h2_MET_phoPt",";MET [GeV];E_{T}^{#gamma} [GeV]",nbins_pfMET,xbins_pfMET,10,25,1525);
      m2_MET_extrajets[MassPair] = new TH2D("h2_MET_extrajets",";MET [GeV];# extra jets",nbins_pfMET,xbins_pfMET,14,-1.5,12.5);
      m2_extrajets_HT[MassPair] = new TH2D("h2_extrajets_HT",";# of extra jets;H_{T} [GeV]",14,-1.5,12.5,20,0,5000);
      
      m_nPho[MassPair] = new TH1D("h_nPho",";# of #gamma",10,-0.5,9.5);
      m_nEle[MassPair] = new TH1D("h_nEle",";# of e_{loose}",10,-0.5,9.5);
      m_nEleM[MassPair] = new TH1D("h_nEleM",";# of e_{medium}",10,-0.5,9.5);
      m_nEleT[MassPair] = new TH1D("h_nEleT",";# of e_{tight}",10,-0.5,9.5);
      m_nMu[MassPair] = new TH1D("h_nMu",";# of #mu_{loose}",10,-0.5,9.5);
      m_nMuM[MassPair] = new TH1D("h_nMuM",";# of #mu_{medium}",10,-0.5,9.5);
      m_nMuT[MassPair] = new TH1D("h_nMuT",";# of #mu_{tight}",10,-0.5,9.5);
      m_nTau[MassPair] = new TH1D("h_nTau",";# of #tau_{loose}",10,-0.5,9.5);
      m_nIso[MassPair] = new TH1D("h_nIso",";# of IsoTracks",10,-0.5,9.5);
   
      const int nbins_lepton=12;
      double xbins_lepton[nbins_lepton+1]={0,5,10,15,20,25,30,40,60,100,200,400,1000};
      m_ElePt[MassPair] = new TH1D("h_ElePt",";leading p_{T}^{electron} [GeV]",nbins_lepton,xbins_lepton);
      m_MuPt[MassPair] = new TH1D("h_MuPt",";leading p_{T}^{#mu} [GeV]",nbins_lepton,xbins_lepton);
      m_TauPt[MassPair] = new TH1D("h_TauPt",";leading p_{T}^{#tau} [GeV]",nbins_lepton,xbins_lepton);
  
      m_njets[MassPair] = new TH1D("h_njets",";# of jets",15,-0.5,14.5);
      m_nonHjets[MassPair] = new TH1D("h_nonHjets",";# of extra jets",14,-1.5,12.5);
      m_jetpt[MassPair] = new TH1D("h_jetpt","Leading jetpt;p_{T}^{Leading jet} [GeV]",10,30,2030);
      m_nAK8jets[MassPair] = new TH1D("h_nAK8jets",";# of AK8jets",15,-0.5,14.5);
      m_AK8jetpt[MassPair] = new TH1D("h_AK8jetpt","Leading AK8jetpt;p_{T}^{Leading AK8jet} [GeV]",10,30,2030);
      
      m_mbbjet_select[MassPair] = new TH1D("h_mbbjet_select","Invariant mass of selected bjets;M_{bb}[GeV]",10,18,278);
      m_AK8mass_select[MassPair] = new TH1D("h_AK8PrunedCorrjetmass_select","Selected AK8PrunedCorrjetmass;PrunedCorr m_{Higgs btagged AK8jets} [GeV]",10,18,278);
      m_dR_ak4_Hcandidate[MassPair] = new TH1D("h_dR_ak4_Hcandidate","dR between H candidate AK4 jets;dR",20,0,5);
      m_pt_ak4_Hcandidate[MassPair] = new TH1D("h_pt_ak4_Hcandidate","pt of H candidate AK4 jets;p_T [GeV]",25,0,1000);
      m_dphi_met_jet[MassPair] = new TH1D("h_dphi_met_jet",";|#Delta#phi|(MET,nearest jet)",10,0,3.2);
      m2_dphi_met_jet_nonHjets[MassPair]= new TH2D("h2_dphi_met_jet_nonHjets",";|#Delta#phi|(MET,nearest jet);nonHiggsJets",10,0,3.2,14,-1.5,12.5);
      m2_dphi_met_jet_njet[MassPair]= new TH2D("h2_dphi_met_jet_njet",";|#Delta#phi|(MET,nth jet);number",10,0,3.2,8,0.5,8.5);
      m2_dphi_met_lowjet_pt[MassPair]= new TH2D("h2_dphi_met_lowjet_pt",";|#Delta#phi|(MET,jet);jet p_{T}",10,0,3.2,10,30,2030);
      m2_dphi_met_highjet_pt[MassPair]= new TH2D("h2_dphi_met_highjet_pt",";|#Delta#phi|(MET,jet);jet p_{T}",10,0,3.2,10,30,2030);
      m_dphi_met_h_ak8[MassPair]= new TH1D("h_dphi_met_h_ak8",";|#Delta#phi|(MET,ak8 H candidate)",10,0,3.2);
      m_dphi_met_ak8btag[MassPair]= new TH1D("h_dphi_met_ak8btag",";|#Delta#phi|(MET,ak8 btag)",10,0,3.2);
      m_dphi_met_h_ak4[MassPair]= new TH1D("h_dphi_met_h_ak4",";|#Delta#phi|(MET,ak4 H candidate)",10,0,3.2);
      m_dphi_met_hmin_ak4[MassPair]= new TH1D("h_dphi_met_hmin_ak4",";|#Delta#phi|(MET,ak4 Hmin candidate)",10,0,3.2);
      m_dphi_met_ak4btag[MassPair]= new TH1D("h_dphi_met_ak4btag",";|#Delta#phi|(MET,ak4 btag)",10,0,3.2);
      m2_dphi_met_h_ak8[MassPair]= new TH2D("h2_dphi_met_h_ak8",";Unrolled bins;|#Delta#phi|(MET,ak8 H candidate)",4,0.5,4.5,10,0,3.2);
      m2_dphi_met_ak8btag[MassPair]= new TH2D("h2_dphi_met_ak8btag",";Unrolled bins;|#Delta#phi|(MET,ak8 btag)",4,0.5,4.5,10,0,3.2);
      m2_dphi_met_h_ak4[MassPair]= new TH2D("h2_dphi_met_h_ak4",";Unrolled bins;|#Delta#phi|(MET,ak4 H candidate)",8,0.5,8.5,10,0,3.2);
      m2_dphi_met_hmin_ak4[MassPair]= new TH2D("h2_dphi_met_hmin_ak4",";Unrolled bins;|#Delta#phi|(MET,ak4 Hmin candidate)",8,0.5,8.5,10,0,3.2);
      m2_dphi_met_ak4btag[MassPair]= new TH2D("h2_dphi_met_ak4btag",";Unrolled bins;|#Delta#phi|(MET,ak4 btag)",8,0.5,8.5,10,0,3.2);
      m2_dphi_met_h_pt_lowjet[MassPair]= new TH2D("h2_dphi_met_h_pt_lowjet",";|#Delta#phi|(MET,jet/H);jet/H p_{T}",10,0,3.2,10,30,2030);
      m2_dphi_met_h_pt_highjet[MassPair]= new TH2D("h2_dphi_met_h_pt_highjet",";|#Delta#phi|(MET,jet/H);jet/H p_{T}",10,0,3.2,10,30,2030);
      m2_dphi_met_hmin_pt_lowjet[MassPair]= new TH2D("h2_dphi_met_hmin_pt_lowjet",";|#Delta#phi|(MET,jet/Hmin);jet/Hmin p_{T}",10,0,3.2,10,30,2030);
      m2_dphi_met_hmin_pt_highjet[MassPair]= new TH2D("h2_dphi_met_hmin_pt_highjet",";|#Delta#phi|(MET,jet/Hmin);jet/Hmin p_{T}",10,0,3.2,10,30,2030);
      
      m_mHAK8[MassPair] = new TH1D("h_mHAK8",";M_{AK8}[GeV]",20,18,278);
      m_mHAK4[MassPair] = new TH1D("h_mHAK4",";M_{bb}[GeV]",10,18,278);
      m2_mHAK8[MassPair] = new TH2D("h2_mHAK8",";Unrolled bins;M_{AK8}[GeV]",4,0.5,4.5,40,18,278);
      m2_mHAK4[MassPair] = new TH2D("h2_mHAK4",";Unrolled bins;M_{bb}[GeV]",8,0.5,8.5,40,18,278);
      m2_dr_SRHiggs[MassPair] = new TH2D("h2_dr_SRHiggs",";Unrolled bins;dR_{bb}",8,0.5,8.5,20,0,3.2);
      m2_dr_VRHiggs[MassPair] = new TH2D("h2_dr_VRHiggs",";Unrolled bins;dR_{bb}",8,0.5,8.5,20,0,3.2);
      m3_mHAK4_dr_Higgs[MassPair] = new TH3D("h3_mHAK4_dr_Higgs",";Unrolled bins;M_{bb}[GeV];dR_{bb}",8,0.5,8.5,10,18,278,20,0,3.2);
      
      //AK4 searchbins
      const int dim_ak4=4;
      int nbins_ak4[dim_ak4]={2,3,5,2};
      double xmin_ak4[dim_ak4]={-0.5,-0.5,0.5,0.5};
      double xmax_ak4[dim_ak4]={1.5,2.5,5.5,2.5};
      mn_AK4searchBins[MassPair] = new THnD("hn_AK4searchBins",";VR;AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
      mn_AK4searchBins_noweight[MassPair] = new THnD("hn_AK4searchBins_noweight",";VR;AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
      mn_AK4HTsearchBins[MassPair] = new THnD("hn_AK4HTsearchBins",";VR;AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
      mn_AK4searchBins[MassPair]->Sumw2(); mn_AK4searchBins_noweight[MassPair]->Sumw2(); mn_AK4HTsearchBins[MassPair]->Sumw2();
      unsigned int nsbins_ak4=mn_AK4searchBins[MassPair]->GetNbins();
      m_AK4searchBins[MassPair]= new TH1D("h_AK4searchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
      m_AK4searchBins_noweight[MassPair]= new TH1D("h_AK4searchBins_noweight",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
      m_AK4HTsearchBins[MassPair]= new TH1D("h_AK4HTsearchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
     
      //AK8 searchbins
      const int dim_ak8=4;
      int nbins_ak8[dim_ak8]={2,2,5,2};
      double xmin_ak8[dim_ak8]={-0.5,-0.5,0.5,0.5};
      double xmax_ak8[dim_ak8]={1.5,1.5,5.5,2.5};
      mn_AK8searchBins[MassPair] = new THnD("hn_AK8searchBins",";VR;AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
      mn_AK8searchBins_noweight[MassPair] = new THnD("hn_AK8searchBins_noweight",";VR;AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
      mn_AK8HTsearchBins[MassPair] = new THnD("hn_AK8HTsearchBins",";VR;AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
      mn_AK8searchBins[MassPair]->Sumw2(); mn_AK8searchBins_noweight[MassPair]->Sumw2(); mn_AK8HTsearchBins[MassPair]->Sumw2();
      unsigned int nsbins_ak8=mn_AK8searchBins[MassPair]->GetNbins();
      m_AK8searchBins[MassPair]= new TH1D("h_AK8searchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
      m_AK8searchBins_noweight[MassPair]= new TH1D("h_AK8searchBins_noweight",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
      m_AK8HTsearchBins[MassPair]= new TH1D("h_AK8HTsearchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
      
       if (signalstudy){
         m_Hpt[MassPair] = new TH1D("hs_Hpt","Higgs pt;p_{T}[GeV]",25,0,1000);
         m_AK8Hmass[MassPair] = new TH1D("hs_AK8Hmass","AK8mass of Higgsmother jet;PrunedCorr m[GeV]",40,18,278);
         m_Hbbmass[MassPair] = new TH1D("hs_Hbbmass","Invariant mass of Higgsmother bb quarks;m_{bb}[GeV]",40,18,278);
         m_genAK4Hmass[MassPair] = new TH1D("hs_genAK4Hmass","Invariant mass of Higgsmother AK4Genjets;m_{bb}[GeV]",40,18,278);
         m_AK4Hmass[MassPair] = new TH1D("hs_AK4Hmass","Invariant mass of Higgsmother AK4jets;m_{bb}[GeV]",40,18,278);
         const int nbins_AK4Hpt=30;
         double xbins_AK4Hpt[nbins_AK4Hpt+1]={0,40,45,50,55,60,65,70,75,80,85,90,95,100,120,140,160,180,200,250,300,350,400,450,500,550,600,700,800,900,1000};
         m_AK4Hpt[MassPair] = new TH1D("hs_AK4Hpt","Pt of Higgsmother AK4jets;p_{T}[GeV]",nbins_AK4Hpt,xbins_AK4Hpt);
         m_PhoEt[MassPair] = new TH1D("hs_PhoEt","Et of Photon from neutralino;E_{T}[GeV]",25,0,1000);
         m_dR_AK4AK4_trueHbb[MassPair] = new TH1D("hs_dR_AK4AK4_trueHbb","dR between true Hbb jets ;dR",20,0,5);
         m_dphi_met_trueh_ak4[MassPair]= new TH1D("hs_dphi_met_h_ak4",";|#Delta#phi|(MET,ak4 H true)",10,0,3.2);
         m_dphi_met_truehmin_ak4[MassPair]= new TH1D("hs_dphi_met_hmin_ak4",";|#Delta#phi|(MET,ak4 Hmin true)",10,0,3.2);
         m_dphi_trueh_gravitino[MassPair]= new TH1D("hs_dphi_h_gravitino",";|#Delta#phi|(H,gravitino)",10,0,3.2);
         m2_true_dR_AK4AK4_mass[MassPair] = new TH2D("hs_true_dR_AK4AK4_mass",";dR;m_{bb} [GeV]",20,0,5,20,18,278);
         m2_AK4_ij[MassPair] = new TH2D("hs_AK4_ij",";index of b;index of anti b",10,0.5,10.5,10,0.5,10.5);
         m2_AK4_ij_njet[MassPair] = new TH2D("hs_AK4_ij_njet",";index of b / njet;index of anti b / njet",10,0,1,10,0,1);
         m2_AK4_btag[MassPair] = new TH2D("hs_AK4_btag",";btag WP of b;btag WP of anti b",4,-0.5,3.5,4,-0.5,3.5);
       }
      }
    }
  return grid;
}

#endif
