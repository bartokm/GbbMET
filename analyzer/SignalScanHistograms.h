#ifndef SignalScanHistograms_h
#define SignalScanHistograms_h
#include <THn.h>

//grid points
    std::vector<int> GridX = {800, 800, 800, 800, 800, 800, 800, 800, 900, 900, 900, 900, 900, 900, 900, 900, 900, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500 };
    std::vector<int> GridY = {127, 200, 300, 400, 500, 600, 700, 800, 127, 200, 300, 400, 500, 600, 700, 800, 900, 127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 975, 1000, 127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 1000, 1025, 1050, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1075, 1100, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1100, 1125, 1150, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1175, 1200, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1200, 1225, 1250, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1275, 1300, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1300, 1325, 1350, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1375, 1400, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1400, 1425, 1450, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1475, 1500, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1500, 1525, 1550, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1575, 1600, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1600, 1625, 1650, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1675, 1700, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1725, 1750, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1775, 1800, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1825, 1850, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1875, 1900, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1900, 1925, 1950, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 1975, 2000, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 2000, 2025, 2050, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2075, 2100, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2100, 2125, 2150, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2175, 2200, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2200, 2225, 2250, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2275, 2300, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2300, 2325, 2350, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2375, 2400, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2400, 2425, 2450, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2250, 2300, 2350, 2400, 2450, 2475, 2500 };

	//map of histos
  map< pair<int, int>, TDirectory* > MassPairToDirectoy;
	
  map< pair<int, int>, TH1D* > m_cuts;
  map< pair<int, int>, TH1D* > m_eff;
	map< pair<int, int>, TH1D* > m_nVtx;
	map< pair<int, int>, TH1D* > m_nGoodVtx;
	map< pair<int, int>, TH1D* > m_nPU;
 
	map< pair<int, int>, TH1D* > m_phoEtL;
	map< pair<int, int>, TH1D* > m_phoEtM;
	map< pair<int, int>, TH1D* > m_phoEtT;
	map< pair<int, int>, TH1D* > m_phoSCEtaL;
	map< pair<int, int>, TH1D* > m_phoSCEtaM;
	map< pair<int, int>, TH1D* > m_phoSCEtaT;
	map< pair<int, int>, TH1D* > m_pfMET;
	map< pair<int, int>, TH1D* > m_pfMETsumEt;
	map< pair<int, int>, TH1D* > m_pfMETPhi;
	map< pair<int, int>, TH1D* > m_pfMETSig;
	map< pair<int, int>, TH2D* > m_MET_AK8btag;
	map< pair<int, int>, TH2D* > m_MET_AK4btag;
	map< pair<int, int>, TH1D* > m_ST;
	map< pair<int, int>, TH1D* > m_ST_G;
	map< pair<int, int>, TH1D* > m_MT;
	map< pair<int, int>, TH1D* > m_nPho;
	map< pair<int, int>, TH1D* > m_nEle;
	map< pair<int, int>, TH1D* > m_nEleM;
	map< pair<int, int>, TH1D* > m_nEleT;
	map< pair<int, int>, TH1D* > m_nMu;
	map< pair<int, int>, TH1D* > m_nMuM;
	map< pair<int, int>, TH1D* > m_nMuT;
	map< pair<int, int>, TH1D* > m_nTau;
	map< pair<int, int>, TH1D* > m_nIso;
 
	map< pair<int, int>, TH1D* > m_njets;
	map< pair<int, int>, TH1D* > m_jetpt;
	map< pair<int, int>, TH1D* > m_nAK8jets;
	map< pair<int, int>, TH1D* > m_AK8jetpt;
	map< pair<int, int>, TH1D* > m_AK8bjetpt;
	map< pair<int, int>, TH1D* > m_AK8bhjetpt;
	map< pair<int, int>, TH1D* > m_AK8ljetmass;
	map< pair<int, int>, TH1D* > m_AK8jetmass;
	map< pair<int, int>, TH1D* > m_AK8bjetmass;
	map< pair<int, int>, TH1D* > m_AK8bhjetmass;
	map< pair<int, int>, TH1D* > m_AK8bPrunedjetmass;
	map< pair<int, int>, TH1D* > m_AK8bhPrunedjetmass;
	map< pair<int, int>, TH1D* > m_AK8bhPrunedCorrjetmass;
	map< pair<int, int>, TH1D* > m_AK8PrunedCorrjetmass;
	map< pair<int, int>, TH1D* > m_AK8SoftDropCorrjetmass;
	map< pair<int, int>, TH1D* > m_AK8PUPPISDjetmass;
	map< pair<int, int>, TH1D* > m_AK8tau1;
	map< pair<int, int>, TH1D* > m_AK8tau2;
	map< pair<int, int>, TH1D* > m_AK8tau3;
	map< pair<int, int>, TH1D* > m_AK8tau2_tau1;
	map< pair<int, int>, TH1D* > m_AK8tau3_tau2;
	map< pair<int, int>, TH1D* > m_AK8puppitau1;
	map< pair<int, int>, TH1D* > m_AK8puppitau2;
	map< pair<int, int>, TH1D* > m_AK8puppitau3;
	map< pair<int, int>, TH1D* > m_AK8puppitau2_tau1;
	map< pair<int, int>, TH1D* > m_AK8puppitau3_tau2;
	 
	map< pair<int, int>, TH1D* > m_CSVbjetsL;
	map< pair<int, int>, TH1D* > m_CSVbjetsM;
	map< pair<int, int>, TH1D* > m_CSVbjetsT;
	map< pair<int, int>, TH1D* > m_cMVAbjetsL;
	map< pair<int, int>, TH1D* > m_cMVAbjetsM;
	map< pair<int, int>, TH1D* > m_cMVAbjetsT;
	map< pair<int, int>, TH1D* > m_BDSVbjetsL;
	map< pair<int, int>, TH1D* > m_BDSVbjetsM;
	map< pair<int, int>, TH1D* > m_BDSVbjetsT;
		
	map< pair<int, int>, TH1D* > m_dRphoAK8jet;
	 
	map< pair<int, int>, TH1D* > m_doubleB;
	map< pair<int, int>, TH1D* > m_doubleB_highdB;
	map< pair<int, int>, TH1D* > m_doubleB_highdB_hmass;
	map< pair<int, int>, TH1D* > m_bjetCSV;
	map< pair<int, int>, TH1D* > m_bjetCSV2;
	map< pair<int, int>, TH1D* > m_b1pb2CSV;
	map< pair<int, int>, TH1D* > m_b1tb2CSV;
	map< pair<int, int>, TH2D* > m_b1b2CSV;
	map< pair<int, int>, TH1D* > m_selectbjetCSV;
	map< pair<int, int>, TH1D* > m_selectbjetCSV2;
	map< pair<int, int>, TH1D* > m_bjetcMVA;
	map< pair<int, int>, TH1D* > m_bjetcMVA2;
 
	map< pair<int, int>, TH1D* > m_selectAK8bjetpt;
	map< pair<int, int>, TH1D* > m_selectbjetpt;
	map< pair<int, int>, TH1D* > m_selectbjetpt2;
	
	map< pair<int, int>, TH1D* > m_HT_before;
	map< pair<int, int>, TH1D* > m_EMHT_before;
	map< pair<int, int>, TH1D* > m_HT_after;
	map< pair<int, int>, TH1D* > m_EMHT_after;
 
	map< pair<int, int>, TH1D* > m_AK8HT_before;
	map< pair<int, int>, TH1D* > m_AK8EMHT_before;
	map< pair<int, int>, TH1D* > m_AK8HT_after;
	map< pair<int, int>, TH1D* > m_AK8EMHT_after;
	
	map< pair<int, int>, TH1D* > m_AK8PrunedCorrjetmass_select;
	map< pair<int, int>, TH1D* > m_AK8PrunedCorrjetmass_withABCD;
	map< pair<int, int>, TH2D* > m_AK8mass_vs_pt;
	map< pair<int, int>, TH2D* > m_AK8mass_all_vs_pt;
	map< pair<int, int>, TH1D* > m_mbbjet_select;
	map< pair<int, int>, TH1D* > m_mbbjet_withABCD;
	map< pair<int, int>, TH2D* > m_mbbjet_vs_pt1;
	map< pair<int, int>, TH2D* > m_mbbjet_vs_pt2;
	map< pair<int, int>, TH2D* > m_mbbjet_comb_vs_pt1;
	map< pair<int, int>, TH2D* > m_mbbjet_comb_vs_pt2;
 
	map< pair<int, int>, TH2D* > m_AK8mass_vs_MT;
	map< pair<int, int>, TH2D* > m_AK8mass_vs_ST;
	map< pair<int, int>, TH2D* > m_mbbjet_vs_MT;
	map< pair<int, int>, TH2D* > m_mbbjet_vs_ST;
	map< pair<int, int>, TH1D* > m_AK4_category;
	
  map< pair<int, int>, THnD* > mn_searchBins;
  map< pair<int, int>, TH1D* > m_searchBins;
   
  //signalstudy
	map< pair<int, int>, TH1D* > m_Hpt;
	map< pair<int, int>, TH1D* > m_AK8Hmass;
	map< pair<int, int>, TH1D* > m_AK4Hmass;
	map< pair<int, int>, TH1D* > m_PhoEt;
	map< pair<int, int>, TH1D* > m_AK4_AK8;
	map< pair<int, int>, TH1D* > m_AK4_AK8_true;
	map< pair<int, int>, TH1D* > m_true_HiggsAK4Jet;
	map< pair<int, int>, TH1D* > m_true_HiggsAK8Jet;
	map< pair<int, int>, TH1D* > m_whyNoAK4Higgs;
	map< pair<int, int>, TH1D* > m_whyNoAK8Higgs;
	map< pair<int, int>, TH2D* > m_ak4_selected;
	map< pair<int, int>, TH1D* > m_true_ak4bjets;

void init_scan_histos(TFile *outFile, bool signalstudy){

	for (unsigned int i=0;i<GridX.size();i++ )
	{	

		std::pair<int,int> MassPair(GridX[i],GridY[i]);
		std::string temp_name = "g" + std::to_string(GridX[i]) + "chi" + std::to_string(GridY[i]);
		MassPairToDirectoy[MassPair] = outFile->mkdir(temp_name.c_str());
		MassPairToDirectoy[MassPair]->cd();

    const int nbins_pfMET=10;
    double xbins_pfMET[nbins_pfMET+1]={0,20,40,70,100,150,200,300,500,700,1000};
    const int nbins_ST=7;
    double xbins_ST[nbins_ST+1]={0, 200, 400, 600, 800, 1000, 1500, 2000};
    const int nbins_MT=9;
    double xbins_MT[nbins_MT+1]={0, 30, 60, 100, 130, 200, 500, 1000, 1500, 2000};
	
		
		m_eff[MassPair] = new TH1D("h_eff","Events;Before cuts, After cuts",2,0,2);
		m_nVtx[MassPair] = new TH1D("h_nVtx",";# of vertices",70,-0.5,69.5);
		m_nGoodVtx[MassPair] = new TH1D("h_nGoodVtx",";# of good vertices",70,-0.5,69.5);
		m_nPU[MassPair] = new TH1D("h_nPU",";# of PileUp",70,-0.5,69.5);

		m_phoEtL[MassPair] = new TH1D("h_phoEtL",";CalibE_{T}^{#gamma_L} [GeV]",10,25,1525);
		m_phoEtM[MassPair] = new TH1D("h_phoEtM",";CalibE_{T}^{#gamma_M} [GeV]",10,25,1525);
		m_phoEtT[MassPair] = new TH1D("h_phoEtT",";CalibE_{T}^{#gamma_T} [GeV]",10,25,1525);
		m_phoSCEtaL[MassPair] = new TH1D("h_phoSCEtaL",";#eta^{#gamma_{L}}",30,-3,3);
		m_phoSCEtaM[MassPair] = new TH1D("h_phoSCEtaM",";#eta^{#gamma_{M}}",30,-3,3);
		m_phoSCEtaT[MassPair] = new TH1D("h_phoSCEtaT",";#eta^{#gamma_{T}}",30,-3,3);

		m_pfMET[MassPair] = new TH1D("h_pfMET",";#slash{E}_{T} [GeV]",nbins_pfMET,xbins_pfMET);
		m_pfMETsumEt[MassPair] = new TH1D("h_pfMETsumEt",";#slash{E}_{T} sumEt",20,-50,5000);
		m_pfMETPhi[MassPair] = new TH1D("h_pfMETPhi",";#Phi^{#slash{E}_{T}}",20,-4,4);
		m_pfMETSig[MassPair] = new TH1D("h_pfMETSig",";#slash{E}_{T}Sig",50,0,2000);
		m_MET_AK8btag[MassPair] = new TH2D("h_MET_AK8btag","MET vs selected AK8btag;pfMET;BDSV",30,5,980,30,-1,1);
		m_MET_AK4btag[MassPair] = new TH2D("h_MET_AK4btag","MET vs selected AK4btag1+AK4btag2;pfMET;CSV_{bjet1}+CSV_{bjet2}",30,5,980,30,0,2);
		m_ST[MassPair] = new TH1D("h_ST",";S_{T} [GeV]",nbins_ST,xbins_ST);
		m_ST_G[MassPair] = new TH1D("h_ST_G",";S_{T}^{#gamma} [GeV]",10,0,2000);
		m_MT[MassPair] = new TH1D("h_MT",";M_{T} [GeV]",nbins_MT,xbins_MT);
		m_nPho[MassPair] = new TH1D("h_nPho",";# of #gamma",10,-0.5,9.5);
		m_nEle[MassPair] = new TH1D("h_nEle",";# of e_{loose}",10,-0.5,9.5);
		m_nEleM[MassPair] = new TH1D("h_nEleM",";# of e_{medium}",10,-0.5,9.5);
		m_nEleT[MassPair] = new TH1D("h_nEleT",";# of e_{tight}",10,-0.5,9.5);
		m_nMu[MassPair] = new TH1D("h_nMu",";# of #mu_{loose}",10,-0.5,9.5);
		m_nMuM[MassPair] = new TH1D("h_nMuM",";# of #mu_{medium}",10,-0.5,9.5);
		m_nMuT[MassPair] = new TH1D("h_nMuT",";# of #mu_{tight}",10,-0.5,9.5);
		m_nTau[MassPair] = new TH1D("h_nTau",";# of #tau_{loose}",10,-0.5,9.5);
		m_nIso[MassPair] = new TH1D("h_nIso",";# of IsoTracks",10,-0.5,9.5);

		m_njets[MassPair] = new TH1D("h_njets",";# of jets",15,-0.5,14.5);
		m_jetpt[MassPair] = new TH1D("h_jetpt","Leading jetpt;p_{T}^{Leading jet} [GeV]",10,30,2030);
		m_nAK8jets[MassPair] = new TH1D("h_nAK8jets",";# of AK8jets",15,-0.5,14.5);
		m_AK8jetpt[MassPair] = new TH1D("h_AK8jetpt","Leading AK8jetpt;p_{T}^{Leading AK8jet} [GeV]",10,30,2030);
		m_AK8bjetpt[MassPair] = new TH1D("h_AK8bjetpt","Btagged AK8jetpt;p_{T}^{btagged AK8jet} [GeV]",10,100,2100);
		m_AK8bhjetpt[MassPair] = new TH1D("h_AK8bhjetpt","Btagged,Higgs-mass AK8jetpt;p_{T}^{Higgs btagged AK8jet} [GeV]",10,100,2100);
		m_AK8ljetmass[MassPair] = new TH1D("h_AK8ljetmass","Leading AK8jetmass;m_{AK8leading jet} [GeV]",10,5,655);
		m_AK8jetmass[MassPair] = new TH1D("h_AK8jetmass","AK8jetmass;m_{AK8jets} [GeV]",10,5,655);
		m_AK8bjetmass[MassPair] = new TH1D("h_AK8bjetmass","Btagged AK8jetmass;m_{btagged AK8jets} [GeV]",10,5,655);
		m_AK8bhjetmass[MassPair] = new TH1D("h_AK8bhjetmass","Btagged, Higgs-mass AK8jetmass;m_{Higgs btagged AK8jets} [GeV]",10,5,655);
		m_AK8bPrunedjetmass[MassPair] = new TH1D("h_AK8bPrunedjetmass","Btagged AK8Prunedjetmass;Pruned m_{btagged AK8jets} [GeV]",10,5,655);
		m_AK8bhPrunedjetmass[MassPair] = new TH1D("h_AK8bhPrunedjetmass","Btagged, Higgs-mass AK8Prunedjetmass;Pruned m_{Higgs btagged AK8jets} [GeV]",10,5,655);
		m_AK8bhPrunedCorrjetmass[MassPair] = new TH1D("h_AK8bhPrunedCorrjetmass","Btagged, Higgs-mass AK8PrunedCorrjetmass;PrunedCorr m_{Higgs btagged AK8jets} [GeV]",10,5,655);
    m_AK8PrunedCorrjetmass[MassPair] = new TH1D("h_AK8PrunedCorrjetmass","Highest btagged AK8jetmess;PrunedCorr m_{AK8jets} [GeV]",20,5,655);
    m_AK8SoftDropCorrjetmass[MassPair] = new TH1D("h_AK8SoftDropCorrjetmass","Highest btagged AK8jetmess;SoftDropCorr m_{AK8jets} [GeV]",20,5,655);
    m_AK8PUPPISDjetmass[MassPair] = new TH1D("h_AK8PUPPISDjetmass","Highest btagged AK8jetmess;PUPPISD m_{AK8jets} [GeV]",20,5,655);
		m_AK8tau1[MassPair] = new TH1D("h_AK8tau1",";#tau_{1}^{AK8Jet}",10,0,1);
		m_AK8tau2[MassPair] = new TH1D("h_AK8tau2",";#tau_{2}^{AK8Jet}",10,0,1);
		m_AK8tau3[MassPair] = new TH1D("h_AK8tau3",";#tau_{3}^{AK8Jet}",10,0,1);
		m_AK8tau2_tau1[MassPair] = new TH1D("h_AK8tau2_tau1",";AK8Jet_tau2/tau1",10,0,1);
		m_AK8tau3_tau2[MassPair] = new TH1D("h_AK8tau3_tau2",";AK8Jet_tau3/tau2",10,0,1);
    m_AK8puppitau1[MassPair] = new TH1D("h_AK8puppitau1",";puppi#tau_{1}^{AK8Jet}",10,0,1);
    m_AK8puppitau2[MassPair] = new TH1D("h_AK8puppitau2",";puppi#tau_{2}^{AK8Jet}",10,0,1);
    m_AK8puppitau3[MassPair] = new TH1D("h_AK8puppitau3",";puppi#tau_{3}^{AK8Jet}",10,0,1);
    m_AK8puppitau2_tau1[MassPair] = new TH1D("h_AK8puppitau2_tau1",";AK8Jetpuppi_tau2/tau1",10,0,1);
    m_AK8puppitau3_tau2[MassPair] = new TH1D("h_AK8puppitau3_tau2",";AK8Jetpuppi_tau3/tau2",10,0,1);

		m_CSVbjetsL[MassPair] = new TH1D("h_CSVbjetsL",";# of CSVLoosebjets",10,-0.5,9.5);
		m_CSVbjetsM[MassPair] = new TH1D("h_CSVbjetsM",";# of CSVMediumbjets",10,-0.5,9.5);
		m_CSVbjetsT[MassPair] = new TH1D("h_CSVbjetsT",";# of CSVTightbjets",10,-0.5,9.5);
		m_cMVAbjetsL[MassPair] = new TH1D("h_cMVAbjetsL",";# of cMVALoosebjets",10,-0.5,9.5);
		m_cMVAbjetsM[MassPair] = new TH1D("h_cMVAbjetsM",";# of cMVAMediumbjets",10,-0.5,9.5);
		m_cMVAbjetsT[MassPair] = new TH1D("h_cMVAbjetsT",";# of cMVATightbjets",10,-0.5,9.5);
		m_BDSVbjetsL[MassPair] = new TH1D("h_BDSVbjetsL",";# of BDSVLoosebjets",10,-0.5,9.5);
		m_BDSVbjetsM[MassPair] = new TH1D("h_BDSVbjetsM",";# of BDSVMediumbjets",10,-0.5,9.5);
		m_BDSVbjetsT[MassPair] = new TH1D("h_BDSVbjetsT",";# of BDSVTightbjets",10,-0.5,9.5);
		
		m_dRphoAK8jet[MassPair] = new TH1D("h_dRphoAK8jet","Distance between leading photon and leading AK8jet;dR",20,0,8);

		m_doubleB[MassPair] = new TH1D("h_doubleB","Highest jetPt;BoostedDoubleSVTagger",10,-1,1);
		m_doubleB_highdB[MassPair] = new TH1D("h_doubleB_highdB","Highest Boosted;BoostedDoubleSVTagger",10,-1,1);
		m_doubleB_highdB_hmass[MassPair] = new TH1D("h_doubleB_highdB_hmass","Highest Boosted with Hmass;BoostedDoubleSVTagger",10,-1,1);
		m_bjetCSV[MassPair] = new TH1D("h_bjetCSV","Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags",10,0,1);
		m_bjetCSV2[MassPair] = new TH1D("h_bjetCSV2","2nd Highest CSV;CombinedInclusiveSecondaryVertexV2BJetTags",10,0,1);
		m_b1pb2CSV[MassPair] = new TH1D("h_b1pb2CSV","Highest bjet CSVs;CSV_{bjet1}+CSV_{bjet2}",20,0,2);
		m_b1tb2CSV[MassPair] = new TH1D("h_b1tb2CSV","Highest bjet CSVs;CSV_{bjet1}*CSV_{bjet2}",20,0,1);
		m_b1b2CSV[MassPair] = new TH2D("h_b1b2CSV","Highest bjet CSVs;CSV_{bjet1};CSV_{bjet2}",20,0,1,30,0,1);
		m_selectbjetCSV[MassPair] = new TH1D("h_selectbjetCSV","Selected jet CSV;CombinedInclusiveSecondaryVertexV2BJetTags",10,0,1);
		m_selectbjetCSV2[MassPair] = new TH1D("h_selectbjetCSV2","Selected2 jet CSV;CombinedInclusiveSecondaryVertexV2BJetTags",10,0,1);
		m_bjetcMVA[MassPair] = new TH1D("h_bjetcMVA","Highest cMVA;CombinedMVAV2BJetTags",10,-1,1);
		m_bjetcMVA2[MassPair] = new TH1D("h_bjetcMVA2","2nd Highest cMVA;CombinedMVAV2BJetTags",10,-1,1);

		m_selectAK8bjetpt[MassPair] = new TH1D("h_selectAK8bjetpt","Selected AK8 jet pt;pt[GeV]",10,100,2100);
		m_selectbjetpt[MassPair] = new TH1D("h_selectbjetpt","Selected jet pt1;pt[GeV]",10,30,2030);
		m_selectbjetpt2[MassPair] = new TH1D("h_selectbjetpt2","Selected jet pt2;pt[GeV]",10,30,2030);

		m_HT_before[MassPair] = new TH1D("h_HT_before","HT before cuts;HT",10,0,3500);
		m_EMHT_before[MassPair] = new TH1D("h_EMHT_before","EMHT before cuts;EMHT",10,0,3500);
		m_HT_after[MassPair] = new TH1D("h_HT_after","HT after cuts;HT",10,0,3500);
		m_EMHT_after[MassPair] = new TH1D("h_EMHT_after","EMHT after cuts;EMHT",10,0,3500);

		m_AK8HT_before[MassPair] = new TH1D("h_AK8HT_before","AK8HT before cuts;HT",10,0,3500);
		m_AK8EMHT_before[MassPair] = new TH1D("h_AK8EMHT_before","AK8EMHT before cuts;EMHT",10,0,3500);
		m_AK8HT_after[MassPair] = new TH1D("h_AK8HT_after","AK8HT after cuts;HT",10,0,3500);
		m_AK8EMHT_after[MassPair] = new TH1D("h_AK8EMHT_after","AK8EMHT after cuts;EMHT",10,0,3500);

		m_AK8PrunedCorrjetmass_select[MassPair] = new TH1D("h_AK8PrunedCorrjetmass_select","Selected AK8PrunedCorrjetmass;PrunedCorr m_{Higgs btagged AK8jets} [GeV]",10,18,278);
		m_AK8PrunedCorrjetmass_withABCD[MassPair] = new TH1D("h_AK8PrunedCorrjetmass_select_withABCD","Highest btagged AK8PrunedCorrjetmass in Higgs mass range;PrunedCorr m_{highest btag AK8jets} [GeV]",10,18,278);
		m_AK8mass_vs_pt[MassPair] = new TH2D("h_AK8mass_vs_pt","Highest btagged AK8PrunedCorrjetmass in Higgs mass range vs its pt;PrunedCorr m_{highest btag AK8jets} [GeV];p_{T}^{highest btag AK8jets} [GeV]",20,18,278,50,0,1500);
		m_AK8mass_all_vs_pt[MassPair] = new TH2D("h_AK8mass_all_vs_pt","All AK8PrunedCorrjetmass in Higgs mass range vs its pt;PrunedCorr m_{highest btag AK8jets} [GeV];p_{T}^{highest btag AK8jets} [GeV]",20,18,278,50,0,1500);
		m_mbbjet_select[MassPair] = new TH1D("h_mbbjet_select","Invariant mass of selected bjets;M_{bb}[GeV]",10,18,278);
		m_mbbjet_withABCD[MassPair] = new TH1D("h_mbbjet_select_withABCD","Invariant mass of highest btag bjets in Higgs mass range;M_{bb}[GeV]",10,18,278);
		m_mbbjet_vs_pt1[MassPair] = new TH2D("h_mbbjet_vs_pt1","Invariant mass of highest btag bjets in Higgs mass range vs 1st p_{T};M_{bb}[GeV];p_{T}^{1} [GeV]",20,18,278,30,30,1030);
		m_mbbjet_vs_pt2[MassPair] = new TH2D("h_mbbjet_vs_pt2","Invariant mass of highest btag bjets in Higgs mass range vs 2nd p_{T};M_{bb}[GeV];p_{T}^{2} [GeV]",20,18,278,30,30,1030);
		m_mbbjet_comb_vs_pt1[MassPair] = new TH2D("h_mbbjet_comb_vs_pt1","Invariant mass of combination of all jets in Higgs mass range vs 1st p_{T};M_{bb}[GeV];p_{T}^{1} [GeV]",20,18,278,30,30,1030);
		m_mbbjet_comb_vs_pt2[MassPair] = new TH2D("h_mbbjet_comb_vs_pt2","Invariant mass of combination of all jets in Higgs mass range vs 1st p_{T};M_{bb}[GeV];p_{T}^{1} [GeV]",20,18,278,30,30,1030);
		
		m_mbbjet_vs_MT[MassPair] = new TH2D("h_mbbjet_vs_MT","Invariant mass of combination of all jets in Higgs mass range vs 1st M_{T};M_{bb}[GeV];M_{T}^{1} [GeV]",20,18,278,60,0,2000);
		m_AK8mass_vs_MT[MassPair] = new TH2D("h_AK8mass_vs_MT","Invariant mass of selected AK8 jet vs 1st M_{T};M_{AK8}[GeV];M_{T}^{1} [GeV]",20,18,278,60,0,2000);
		m_mbbjet_vs_ST[MassPair] = new TH2D("h_mbbjet_vs_ST","Invariant mass of combination of all jets in Higgs mass range vs 1st S_{T};M_{bb}[GeV];S_{T}^{1} [GeV]",20,18,278,60,0,2000);
		m_AK8mass_vs_ST[MassPair] = new TH2D("h_AK8mass_vs_ST","Invariant mass of selected AK8 jet vs 1st S_{T};M_{AK8}[GeV];S_{T}^{1} [GeV]",20,18,278,60,0,2000);
      
    m_AK4_AK8[MassPair] = new TH1D("h_AK4_AK8","Higgs candidate findings;",9,0.5,9.5);
    m_AK4_category[MassPair] = new TH1D("h_AK4_category","AK4 btag-Higgs window categories;NoBtag-NoWindow, 1Btag-NoWindow, 2Btag-NoWindow, NoBtag-Window, Undecided, 1Selected, 2Selected",7,0.5,7.5);
    
    const int dim=4;
    int nbins[dim]={3,3,6,3};
    double xmin[dim]={-0.5,-0.5,0.5,0.5};
    double xmax[dim]={2.5,2.5,6.5,3.5};
    mn_searchBins[MassPair] = new THnD("hn_searchBins",";AK4_AK8;MET;njets",dim,nbins,xmin,xmax);
    mn_searchBins[MassPair]->Sumw2();
    unsigned int nsbins=mn_searchBins[MassPair]->GetNbins();
    m_searchBins[MassPair]= new TH1D("h_searchBins",";searchBins",nsbins,0.5,nsbins+0.5);

    if (signalstudy){
      m_Hpt[MassPair] = new TH1D("hs_Hpt","Higgs pt;p_{T}[GeV]",25,0,1000);
      m_PhoEt[MassPair] = new TH1D("hs_PhoEt","Et of Photon from neutralino;E_{T}[GeV]",25,0,1000);
      m_AK8Hmass[MassPair] = new TH1D("hs_AK8Hmass","PrunedCorr AK8mass of Higgsmother jet;PrunedCorr m[GeV]",10,18,278);
      m_AK4Hmass[MassPair] = new TH1D("hs_AK4Hmass","Invariant mass of Higgsmother AK4jets;m_{bb}[GeV]",10,18,278);
      m_AK4_AK8_true[MassPair] = new TH1D("hs_AK4_AK8_true","Higgs candidate findings with truth;",9,0.5,9.5);
      m_true_HiggsAK8Jet[MassPair]= new TH1D("hs_true_HiggsAK8Jet","True Higgs AK8Jet;1 Higgs, HAK8jet, HAK8jet=highest, HAK8jet=selected",4,0.5,4.5);
      m_true_HiggsAK4Jet[MassPair]= new TH1D("hs_true_HiggsAK4Jet","True Higgs AK4Jet;1 Higgs, 1 Hjet, 1Hjet=highest, 1 Hjet=selected, 2 Hjet, 2Hjet=highest, 2Hjet=selected",7,0.5,7.5);
      m_whyNoAK4Higgs[MassPair]= new TH1D("hs_whyAK4NoHiggs","Failed AK4 Higgs tag;Higgs window, btag, both",3,0.5,3.5);
      m_whyNoAK8Higgs[MassPair]= new TH1D("hs_whyAK8NoHiggs","Failed AK8 Higgs tag;No AK8jet, Higgs window, btag, both",4,0.5,4.5);
      m_ak4_selected[MassPair] = new TH2D("hs_ak4_selected","Index of Higgs candidate ak4 jets;First;Second",20,-0.5,19.5,20,-0.5,19.5);
      m_true_ak4bjets[MassPair] = new TH1D("hs_true_ak4bjets","# of true ak4 b jets;# of true b jets",10,-0.5,9.5);
    }
	}
}

#endif
