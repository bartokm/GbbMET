#ifndef SignalScanHistograms_h
#define SignalScanHistograms_h
#include <THn.h>

//grid points
    std::vector<int> GridX = {800, 800, 800, 800, 800, 800, 800, 800, 900, 900, 900, 900, 900, 900, 900, 900, 900, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1150, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1250, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1300, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1350, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1400, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1450, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1550, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1600, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1650, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1750, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1850, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1900, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 1950, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2050, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2100, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2150, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2200, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2250, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2300, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2350, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2450, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500 };
    std::vector<int> GridY = {127, 200, 300, 400, 500, 600, 700, 800, 127, 200, 300, 400, 500, 600, 700, 800, 900, 127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 975, 1000, 127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 1000, 1025, 1050, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1075, 1100, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1100, 1125, 1150, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1175, 1200, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1200, 1225, 1250, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1275, 1300, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1300, 1325, 1350, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1375, 1400, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1400, 1425, 1450, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1475, 1500, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1500, 1525, 1550, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1575, 1600, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1600, 1625, 1650, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1675, 1700, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1725, 1750, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1775, 1800, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1825, 1850, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1875, 1900, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1900, 1925, 1950, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 1975, 2000, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 2000, 2025, 2050, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2075, 2100, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2100, 2125, 2150, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2175, 2200, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2200, 2225, 2250, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2275, 2300, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2300, 2325, 2350, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2375, 2400, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2400, 2425, 2450, 127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2250, 2300, 2350, 2400, 2450, 2475, 2500 };

	//map of histos
  map< pair<int, int>, TDirectory* > MassPairToDirectoy;
	
  map< pair<int, int>, TH1D* > m_eff;
  map< pair<int, int>, TH1D* > m_nISR_jet;
  map< pair<int, int>, TH1D* > m_SR;
 
	map< pair<int, int>, TH1D* > m_phoEtL;
	map< pair<int, int>, TH1D* > m_phoEtM;
	map< pair<int, int>, TH1D* > m_phoEtT;
	map< pair<int, int>, TH1D* > m_phoEtaL;
	map< pair<int, int>, TH1D* > m_phoEtaM;
	map< pair<int, int>, TH1D* > m_phoEtaT;

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
		
	
	map< pair<int, int>, TH1D* > m_mbbjet_select;
	map< pair<int, int>, TH1D* > m_AK8mass_select;
  map< pair<int, int>, TH1D* > m_dphi_met_jet;
  map< pair<int, int>, TH1D* > m_dR_ak4_Hcandidate;
	
  map< pair<int, int>, THnD* > mn_AK4searchBins;
  map< pair<int, int>, TH1D* > m_AK4searchBins;
  map< pair<int, int>, THnD* > mn_AK8searchBins;
  map< pair<int, int>, TH1D* > m_AK8searchBins;
   
  //signalstudy
	map< pair<int, int>, TH1D* > m_Hpt;
	map< pair<int, int>, TH1D* > m_AK8Hmass;
	map< pair<int, int>, TH1D* > m_AK4Hmass;
	map< pair<int, int>, TH1D* > m_PhoEt;
	map< pair<int, int>, TH1D* > m_dR_AK4AK4_trueHbb;

void Analyzer::init_scan_histos(TFile *outFile, bool signalstudy){

	for (unsigned int i=0;i<GridX.size();i++ )
	{	

		std::pair<int,int> MassPair(GridX[i],GridY[i]);
		std::string temp_name = "g" + std::to_string(GridX[i]) + "chi" + std::to_string(GridY[i]);
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
		m_eff[MassPair] = new TH1D("h_eff","Events;Before cuts, After cuts",2,0,2);
    m_nISR_jet[MassPair] = new TH1D("h_nISR_jet",";number of ISR jets",10,0,10);
    m_SR[MassPair] = new TH1D("h_SR","",16,0.5,16.5);

		m_phoEtL[MassPair] = new TH1D("h_phoEtL",";E_{T}^{#gamma_L} [GeV]",10,25,1525);
		m_phoEtM[MassPair] = new TH1D("h_phoEtM",";E_{T}^{#gamma_M} [GeV]",10,25,1525);
		m_phoEtT[MassPair] = new TH1D("h_phoEtT",";E_{T}^{#gamma_T} [GeV]",10,25,1525);
		m_phoEtaL[MassPair] = new TH1D("h_phoEtaL",";#eta^{#gamma_{L}}",30,-3,3);
		m_phoEtaM[MassPair] = new TH1D("h_phoEtaM",";#eta^{#gamma_{M}}",30,-3,3);
		m_phoEtaT[MassPair] = new TH1D("h_phoEtaT",";#eta^{#gamma_{T}}",30,-3,3);
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
		
		m_mbbjet_select[MassPair] = new TH1D("h_mbbjet_select","Invariant mass of selected bjets;M_{bb}[GeV]",10,18,278);
		m_AK8mass_select[MassPair] = new TH1D("h_AK8PrunedCorrjetmass_select","Selected AK8PrunedCorrjetmass;PrunedCorr m_{Higgs btagged AK8jets} [GeV]",10,18,278);
    m_dR_ak4_Hcandidate[MassPair] = new TH1D("h_dR_ak4_Hcandidate","dR between H candidate AK4 jets;dR",20,0,5);
    m_dphi_met_jet[MassPair] = new TH1D("h_dphi_met_jet",";|#Delta#phi|(MET,nearest jet)",10,0,3.2);
    
    //AK4 searchbins
    const int dim_ak4=4;
    int nbins_ak4[dim_ak4]={2,3,6,2};
    double xmin_ak4[dim_ak4]={-0.5,-0.5,0.5,0.5};
    double xmax_ak4[dim_ak4]={1.5,2.5,6.5,2.5};
    mn_AK4searchBins[MassPair] = new THnD("hn_AK4searchBins",";VR;AK4;MET;njets",dim_ak4,nbins_ak4,xmin_ak4,xmax_ak4);
    mn_AK4searchBins[MassPair]->Sumw2();
    unsigned int nsbins_ak4=mn_AK4searchBins[MassPair]->GetNbins();
    m_AK4searchBins[MassPair]= new TH1D("h_AK4searchBins",";AK4searchBins",nsbins_ak4,0.5,nsbins_ak4+0.5);
   
    //AK8 searchbins
    const int dim_ak8=4;
    int nbins_ak8[dim_ak8]={2,2,6,2};
    double xmin_ak8[dim_ak8]={-0.5,-0.5,0.5,0.5};
    double xmax_ak8[dim_ak8]={1.5,1.5,6.5,2.5};
    mn_AK8searchBins[MassPair] = new THnD("hn_AK8searchBins",";VR;AK8;MET;njets",dim_ak8,nbins_ak8,xmin_ak8,xmax_ak8);
    mn_AK8searchBins[MassPair]->Sumw2();
    unsigned int nsbins_ak8=mn_AK8searchBins[MassPair]->GetNbins();
    m_AK8searchBins[MassPair]= new TH1D("h_AK8searchBins",";AK8searchBins",nsbins_ak8,0.5,nsbins_ak8+0.5);
    
     if (signalstudy){
       m_Hpt[MassPair] = new TH1D("hs_Hpt","Higgs pt;p_{T}[GeV]",25,0,1000);
       m_AK8Hmass[MassPair] = new TH1D("hs_AK8Hmass","AK8mass of Higgsmother jet;PrunedCorr m[GeV]",10,18,278);
       m_AK4Hmass[MassPair] = new TH1D("hs_AK4Hmass","Invariant mass of Higgsmother AK4jets;m_{bb}[GeV]",10,18,278);
       m_PhoEt[MassPair] = new TH1D("hs_PhoEt","Et of Photon from neutralino;E_{T}[GeV]",25,0,1000);
       m_dR_AK4AK4_trueHbb[MassPair] = new TH1D("hs_dR_AK4AK4_trueHbb","dR between true Hbb jets ;dR",20,0,5);
     }
  }
}

#endif
