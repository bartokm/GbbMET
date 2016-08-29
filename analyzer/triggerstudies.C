std::map<int,double> printtrigger(TString fname, double effcut, std::map<int,std::string> triggers, std::vector<int> &promising_triggers) {
  std::map<int,double> result;
  TFile f(fname.Data(), "READ");
  f.cd("ggNtuplizer");
  TTree* tree =(TTree*)gDirectory->Get("EventTree");
  int maxentry=tree->GetEntries();

  //determine photon or jet triggers are considered
  std::string trigtype;
  if (triggers[0].find("HLT_Photon") != std::string::npos) trigtype="HLTPho&";
  else trigtype="HLTJet&";

  //std::cout<<triggers[0]<<" type triggers with efficiency >"<<effcut<<std::endl;
  for (int i=0;i<triggers.size();i++){
    std::string temp=trigtype+std::to_string(pow(2,i));
    const char *select = temp.c_str();
    int tempentry=tree->GetEntries(select);
    double eff=double(tempentry)/double(maxentry);
    
    
    if (eff>effcut) {
      //std::cout<<triggers[i]<<" eff: "<<eff<<std::endl;
      bool write=true;
      for (int j=0;j<promising_triggers.size();j++) if (i==promising_triggers.at(j)) write=false;
      if (trigtype=="HLTPho&" && i<7) write=false;
      if (trigtype=="HLTJet&" && i>9 &&i<18) write=false;
      if (write) promising_triggers.push_back(i);
    }
    
    result[i] = eff;
  }
  f.Close();
  return result;
}

void triggerstudies(){
  std::map<int,std::string> photriggers;
  photriggers[0] = "HLT_Photon22_v"; //prescaled
  photriggers[1] = "HLT_Photon30_v"; //prescaled
  photriggers[2] = "HLT_Photon36_v"; //prescaled
  photriggers[3] = "HLT_Photon50_v"; //prescaled
  photriggers[4] = "HLT_Photon75_v"; //prescaled
  photriggers[5] = "HLT_Photon90_v"; //prescaled
  photriggers[6] = "HLT_Photon120_v"; //prescaled
  photriggers[7] = "HLT_Photon175_v";
  photriggers[8] = "HLT_Photon250_NoHE_v";
  photriggers[9] = "HLT_Photon300_NoHE_v";
  photriggers[10] = "HLT_Photon500_v";
  photriggers[11] = "HLT_Photon600_v";
  photriggers[12] = "HLT_Photon165_HE10_v";
  photriggers[13] = "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v";
  photriggers[14] = "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90_v";
  photriggers[15] = "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70_v";
  photriggers[16] = "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v";
  photriggers[17] = "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55_v";
  photriggers[18] = "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55_v";
  photriggers[19] = "HLT_DoublePhoton85_v";
  photriggers[20] = "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v";
  photriggers[21] = "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE10p0_R9Id_Mass95_v";
  photriggers[22] = "HLT_Photon135_PFMET100_v";
  photriggers[23] = "HLT_Photon135_PFMET100_JetIdCleaned_v";
  photriggers[24] = "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v";
  photriggers[25] = "HLT_Photon120_R9Id90_HE10_IsoM_v"; //prescaled
  photriggers[26] = "HLT_Photon165_R9Id90_HE10_IsoM_v";
  photriggers[27] = "HLT_Photon90_CaloIdL_PFHT500_v";
  photriggers[28] = "HLT_Photon90_CaloIdL_PFHT600_v";
  photriggers[29] = "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v";
  photriggers[30] = "HLT_Photon90_R9Id90_HE10_IsoM_v"; //prescaled
  photriggers[31] = "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v";
  photriggers[32] = "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v";
  photriggers[33] = "HLT_Photon22_R9Id90_HE10_IsoM_v";
  photriggers[34] = "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v";
  photriggers[35] = "HLT_Photon36_R9Id90_HE10_IsoM_v"; //prescale at low inst.lumi
  photriggers[36] = "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15_v";
  photriggers[37] = "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v";
  photriggers[38] = "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v";
  photriggers[39] = "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v";
  
  std::map<int,std::string> jettriggers;
  jettriggers[0] = "HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460_v"; //prescaled
  jettriggers[1] = "HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500_v";
  jettriggers[2] = "HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200_v"; //prescaled
  jettriggers[3] = "HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240_v";
  jettriggers[4] = "HLT_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v";
  jettriggers[5] = "HLT_PFMETNoMu120_JetIdCleaned_PFMHTNoMu120_IDTight_v";
  jettriggers[6] = "HLT_MonoCentralPFJet80_PFMETNoMu90_JetIdCleaned_PFMHTNoMu90_IDTight_v";
  jettriggers[7] = "HLT_MonoCentralPFJet80_PFMETNoMu120_JetIdCleaned_PFMHTNoMu120_IDTight_v";
  jettriggers[8] = "HLT_PFMET170_NoiseCleaned_v";
  jettriggers[9] = "HLT_CaloJet500_NoJetID_v";
  jettriggers[10] = "HLT_PFJet40_v"; //prescaled
  jettriggers[11] = "HLT_PFJet60_v"; //prescaled
  jettriggers[12] = "HLT_PFJet80_v"; //prescaled
  jettriggers[13] = "HLT_PFJet140_v"; //prescaled
  jettriggers[14] = "HLT_PFJet200_v"; //prescaled
  jettriggers[15] = "HLT_PFJet260_v"; //prescaled
  jettriggers[16] = "HLT_PFJet320_v"; //prescaled
  jettriggers[17] = "HLT_PFJet400_v"; //prescaled
  jettriggers[18] = "HLT_PFJet450_v";
  jettriggers[19] = "HLT_PFJet500_v";
  jettriggers[20] = "HLT_AK8PFHT650_TrimR0p1PT0p3Mass50_v";
  jettriggers[21] = "HLT_AK8PFJet360_TrimMass30_v";
  jettriggers[22] = "HLT_PFHT800_v";
  jettriggers[23] = "HLT_PFHT475_v"; //prescaled
  jettriggers[24] = "HLT_PFMET170_HBHECleaned_v";
  jettriggers[25] = "HLT_BTagMu_AK8Jet300_Mu5_v";
  jettriggers[26] = "HLT_BTagMu_DiJet110_Mu5_v";
  jettriggers[27] = "HLT_BTagMu_DiJet170_Mu5_v"; //prescaled
  jettriggers[28] = "HLT_BTagMu_DiJet40_Mu5_v";
  jettriggers[29] = "HLT_BTagMu_Jet300_Mu5_v";
  jettriggers[30] = "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v";
  jettriggers[31] = "HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067_v";
  jettriggers[32] = "HLT_DoubleJet90_Double30_TripleBTagCSV_p087_v";
  jettriggers[33] = "HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6_v"; //0 at 1.6e34
  jettriggers[34] = "HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160_v"; //0 at 1.6e34
  jettriggers[35] = "HLT_DoubleJetsC100_SingleBTagCSV_p014_SinglePFJetC350_v"; //0 at 1.45e34
  jettriggers[36] = "HLT_DoubleJetsC100_SingleBTagCSV_p026_SinglePFJetC350_v"; //0 at 1.45e34
  jettriggers[37] = "HLT_DoubleJetsC112_DoubleBTagCSV_p014_DoublePFJetsC112MaxDeta1p6_v";
  jettriggers[38] = "HLT_DoubleJetsC112_DoubleBTagCSV_p026_DoublePFJetsC172_v";
  jettriggers[39] = "HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_v";
  jettriggers[40] = "HLT_PFHT450_SixJet40_BTagCSV_p056_v";
  jettriggers[41] = "HLT_QuadJet45_TripleBTagCSV_p087_v";
  jettriggers[42] = "HLT_Rsq0p02_MR300_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200_v";
  jettriggers[43] = "HLT_DiCentralPFJet55_PFMET110_v"; //0 at circ.beam, nincs
  jettriggers[44] = "HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v";
  jettriggers[45] = "HLT_MET200_v";
  jettriggers[46] = "HLT_MET250_v";
  jettriggers[47] = "HLT_MET300_v";
  jettriggers[48] = "HLT_MET600_v";
  jettriggers[49] = "HLT_MET700_v";
  jettriggers[50] = "HLT_MET75_IsoTrk50_v";
  jettriggers[51] = "HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight_v";
  jettriggers[52] = "HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_v";
  jettriggers[53] = "HLT_PFHT300_PFMET100_v"; //prescaled
  jettriggers[54] = "HLT_PFHT300_PFMET110_v";
  jettriggers[55] = "HLT_PFMET100_PFMHT100_IDTight_BeamHaloCleaned_v";
  jettriggers[56] = "HLT_PFMET110_PFMHT110_IDTight_v";
  jettriggers[57] = "HLT_PFMET120_PFMHT120_IDTight_v";
  jettriggers[58] = "HLT_PFMET170_HBHE_BeamHaloCleaned_v1";
  jettriggers[59] = "HLT_PFMET300_v";
  jettriggers[60] = "HLT_PFMET400_v";
  jettriggers[61] = "HLT_PFMET500_v";
  jettriggers[62] = "HLT_PFMET600_v";
  jettriggers[63] = "HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v";
  jettriggers[64] = "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v";
  jettriggers[65] = "HLT_PFMETTypeOne190_HBHE_BeamHaloCleaned_v";
  jettriggers[66] = "HLT_Rsq0p25_v";
  jettriggers[67] = "HLT_Rsq0p30_v";
  jettriggers[68] = "HLT_RsqMR270_Rsq0p09_MR200_v";
  jettriggers[69] = "HLT_RsqMR270_Rsq0p09_MR200_4jet_v";
  jettriggers[70] = "HLT_PFHT300_PFMET100_v"; //OFF
  jettriggers[71] = "HLT_PFHT300_PFMET110_v";
  jettriggers[72] = "HLT_PFHT200_DiPFJetAve90_PFAlphaT0p63_v";
  jettriggers[73] = "HLT_PFHT250_DiPFJetAve90_PFAlphaT0p58_v";
  jettriggers[74] = "HLT_PFHT300_DiPFJetAve90_PFAlphaT0p54_v";
  jettriggers[75] = "HLT_PFHT350_DiPFJetAve90_PFAlphaT0p53_v";
  jettriggers[76] = "HLT_PFHT400_DiPFJetAve90_PFAlphaT0p52_v";
  jettriggers[77] = "HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v";
  jettriggers[78] = "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v";
  jettriggers[79] = "HLT_AK8PFJet360_TrimMass30_v";
  jettriggers[80] = "HLT_AK8PFJet450_v"; //0 at 1.45e34
  jettriggers[81] = "HLT_AK8PFJet500_v";
  jettriggers[82] = "HLT_CaloJet500_NoJetID_v"; //0 at 1.45e34
  jettriggers[83] = "HLT_DiCentralPFJet170_CFMax0p1_v";
  jettriggers[84] = "HLT_DiCentralPFJet220_CFMax0p3_v";
  jettriggers[85] = "HLT_DiCentralPFJet330_CFMax0p5_v";
  jettriggers[86] = "HLT_DiCentralPFJet430_v";
  jettriggers[87] = "HLT_DiPFJetAve100_HFJEC_v"; //prescaled at 1e32
  jettriggers[88] = "HLT_DiPFJetAve60_HFJEC_v";
  jettriggers[89] = "HLT_HT2000_v";
  jettriggers[90] = "HLT_HT2500_v";
  jettriggers[91] = "HLT_PFHT125_v";
  jettriggers[92] = "HLT_PFHT200_v";
  jettriggers[93] = "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v";
  jettriggers[94] = "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v";
  jettriggers[95] = "HLT_PFHT750_4JetPt50_v";
  jettriggers[96] = "HLT_PFHT800_v";
  jettriggers[97] = "HLT_PFHT900_v";
  //kell meg: "HLT_DiPFJetAve300_HFJEC_v"
  //kell meg: "HLT_PFHT250_v"
  //kell meg: "HLT_PFHT450_v"
  //kell meg: "HLT_MET90_IsoTrk50_v"
  //kell meg: "HLT_DoubleMu3_PFMET50_v"
  //kell meg: "HLT_PFMET120_Mu5_v"
  //kell meg: "HLT_Mu6_PFHT200_PFMET100_v"

  TString f1="mGluino-1000_mNeutralino-200_78Xggtree_mc_fulltrigger.root";
  TString f2="mGluino-1000_mNeutralino-400_78Xggtree_mc_fulltrigger.root";
  TString f3="mGluino-1000_mNeutralino-600_78Xggtree_mc_fulltrigger.root";
  TString f4="mChargino-600_mNeutralino-200_78Xggtree_mc_fulltrigger.root";
  TString f5="mChargino-600_mNeutralino-400_78Xggtree_mc_fulltrigger.root";
  TString f6="mChargino-800_mNeutralino-200_78Xggtree_mc_fulltrigger.root";
  TString f7="mChargino-800_mNeutralino-400_78Xggtree_mc_fulltrigger.root";
  TString f8="mChargino-800_mNeutralino-600_78Xggtree_mc_fulltrigger.root";
  
  double effcut=0.5;
 
  std::vector<int> promising_photriggers;
  std::vector<int> promising_jettriggers;

  std::cout<<"mGluino-1000_mNeutralino-200"<<std::endl;
  std::map<int,double> phoresult_mN200 = printtrigger(f1, effcut, photriggers, promising_photriggers);
  std::cout<<"mGluino-1000_mNeutralino-400"<<std::endl;
  std::map<int,double> phoresult_mN400 = printtrigger(f2, effcut, photriggers, promising_photriggers);
  std::cout<<"mGluino-1000_mNeutralino-600"<<std::endl;
  std::map<int,double> phoresult_mN600 = printtrigger(f3, effcut, photriggers, promising_photriggers);
  std::cout<<"mChargino-600_mNeutralino-200"<<std::endl;
  std::map<int,double> phoresult_mC600mN200 = printtrigger(f4, effcut, photriggers, promising_photriggers);
  std::cout<<"mChargino-600_mNeutralino-400"<<std::endl;
  std::map<int,double> phoresult_mC600mN400 = printtrigger(f5, effcut, photriggers, promising_photriggers);
  std::cout<<"mChargino-800_mNeutralino-200"<<std::endl;
  std::map<int,double> phoresult_mC800mN200 = printtrigger(f6, effcut, photriggers, promising_photriggers);
  std::cout<<"mChargino-800_mNeutralino-400"<<std::endl;
  std::map<int,double> phoresult_mC800mN400 = printtrigger(f7, effcut, photriggers, promising_photriggers);
  std::cout<<"mChargino-800_mNeutralino-600"<<std::endl;
  std::map<int,double> phoresult_mC800mN600 = printtrigger(f8, effcut, photriggers, promising_photriggers);
  std::cout<<"mGluino-1000_mNeutralino-200"<<std::endl;
  std::map<int,double> jetresult_mN200 = printtrigger(f1, effcut, jettriggers, promising_jettriggers);
  std::cout<<"mGluino-1000_mNeutralino-400"<<std::endl;
  std::map<int,double> jetresult_mN400 = printtrigger(f2, effcut, jettriggers, promising_jettriggers);
  std::cout<<"mGluino-1000_mNeutralino-600"<<std::endl;
  std::map<int,double> jetresult_mN600 = printtrigger(f3, effcut, jettriggers, promising_jettriggers);
  std::cout<<"mChargino-600_mNeutralino-200"<<std::endl;
  std::map<int,double> jetresult_mC600mN200 = printtrigger(f4, effcut, jettriggers, promising_jettriggers);
  std::cout<<"mChargino-600_mNeutralino-400"<<std::endl;
  std::map<int,double> jetresult_mC600mN400 = printtrigger(f5, effcut, jettriggers, promising_jettriggers);
  std::cout<<"mChargino-800_mNeutralino-200"<<std::endl;
  std::map<int,double> jetresult_mC800mN200 = printtrigger(f6, effcut, jettriggers, promising_jettriggers);
  std::cout<<"mChargino-800_mNeutralino-400"<<std::endl;
  std::map<int,double> jetresult_mC800mN400 = printtrigger(f7, effcut, jettriggers, promising_jettriggers);
  std::cout<<"mChargino-800_mNeutralino-600"<<std::endl;
  std::map<int,double> jetresult_mC800mN600 = printtrigger(f8, effcut, jettriggers, promising_jettriggers);

  for (int i=0;i<promising_photriggers.size();i++){
    int iter=promising_photriggers.at(i);
    double ave=(phoresult_mN200[iter]+phoresult_mN400[iter]+phoresult_mN600[iter]+phoresult_mC600mN200[iter]+phoresult_mC600mN400[iter]+phoresult_mC800mN200[iter]+phoresult_mC800mN400[iter]+phoresult_mC800mN600[iter])/8;
    std::cout<<photriggers[iter]<<" & ";
    std::cout<<phoresult_mN200[iter]<<" & ";
    std::cout<<phoresult_mN400[iter]<<" & ";
    std::cout<<phoresult_mN600[iter]<<" & ";
    std::cout<<phoresult_mC600mN200[iter]<<" & ";
    std::cout<<phoresult_mC600mN400[iter]<<" & ";
    std::cout<<phoresult_mC800mN200[iter]<<" & ";
    std::cout<<phoresult_mC800mN400[iter]<<" & ";
    std::cout<<phoresult_mC800mN600[iter]<<" & ";
    std::cout<<ave<<"\\\\";
    std::cout<<"\n\\hline"<<std::endl;
  }
  for (int i=0;i<promising_jettriggers.size();i++){
    int iter=promising_jettriggers.at(i);
    double ave=(jetresult_mN200[iter]+jetresult_mN400[iter]+jetresult_mN600[iter]+jetresult_mC600mN200[iter]+jetresult_mC600mN400[iter]+jetresult_mC800mN200[iter]+jetresult_mC800mN400[iter]+jetresult_mC800mN600[iter])/8;
    std::cout<<jettriggers[iter]<<" & ";
    std::cout<<jetresult_mN200[iter]<<" & ";
    std::cout<<jetresult_mN400[iter]<<" & ";
    std::cout<<jetresult_mN600[iter]<<" & ";
    std::cout<<jetresult_mC600mN200[iter]<<" & ";
    std::cout<<jetresult_mC600mN400[iter]<<" & ";
    std::cout<<jetresult_mC800mN200[iter]<<" & ";
    std::cout<<jetresult_mC800mN400[iter]<<" & ";
    std::cout<<jetresult_mC800mN600[iter]<<" & ";
    std::cout<<ave<<"\\\\";
    std::cout<<"\n\\hline"<<std::endl;
  }

//  for (auto &kv : )
}
