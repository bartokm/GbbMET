#ifndef cross_sections_h
#define cross_sections_h

double get_cross_section(std::string name, std::string y, int center_down_up=0) {
  int year=(y.find("2016")!=std::string::npos) ? 2016 : (y.find("2017")!=std::string::npos) ? 2017 : (y.find("2018")!=std::string::npos) ? 2018 : 1;
  if (name.find("DYJetsToLL_Pt-50To100")!=std::string::npos) return 398.8;
  else if (name.find("DYJetsToLL_Pt-100To250")!=std::string::npos) return 93.61;
  else if (name.find("DYJetsToLL_Pt-250To400")!=std::string::npos) return 3.67;
  else if (name.find("DYJetsToLL_Pt-400To650")!=std::string::npos) return 0.5;
  else if (name.find("DYJetsToLL_Pt-650ToInf")!=std::string::npos) return 0.04704;
  else if (name.find("DYJetsToLL_M-10to50")!=std::string::npos) return 15890;
  else if (name.find("DYJetsToLL_M-50")!=std::string::npos) return 5398;
  else if (name.find("GJets_DR-0p4_HT-100To200")!=std::string::npos) return 5034;
  else if (name.find("GJets_DR-0p4_HT-200To400")!=std::string::npos) return 1129;
  else if (name.find("GJets_DR-0p4_HT-400To600")!=std::string::npos) return 126.2;
  else if (name.find("GJets_DR-0p4_HT-600ToInf")!=std::string::npos) return 41.31;
  else if (name.find("GJets_HT-40To100")!=std::string::npos) return 18540;
  else if (name.find("GJets_HT-100To200")!=std::string::npos) return 8644;
  else if (name.find("GJets_HT-200To400")!=std::string::npos) return 2183;
  else if (name.find("GJets_HT-400To600")!=std::string::npos) return 260.2;
  else if (name.find("GJets_HT-600ToInf")!=std::string::npos) return 86.58;
  else if (name.find("QCD_HT300to500")!=std::string::npos) return 324500;
  else if (name.find("QCD_HT500to700")!=std::string::npos) return 30310;
  else if (name.find("QCD_HT700to1000")!=std::string::npos) return 6444;
  else if (name.find("QCD_HT1000to1500")!=std::string::npos) return 1127;
  else if (name.find("QCD_HT1500to2000")!=std::string::npos) return 109.8;
  else if (name.find("QCD_HT2000toInf")!=std::string::npos) return 21.98;
  else if (name.find("ST_s-channel_4f_hadronicDecays")!=std::string::npos) return 7.104;//own calculation
  else if (name.find("ST_s-channel_4f_leptonDecays")!=std::string::npos) return 3.549;
  else if (name.find("ST_t-channel_antitop")!=std::string::npos) return 67.93; //own calculation
  else if (name.find("ST_t-channel_top")!=std::string::npos) return 113.4; //own calculation
  else if (name.find("ST_tW_antitop_5f_NoFullyHadronicDecays")!=std::string::npos) return 32.51*0.335;
  else if (name.find("ST_tW_antitop_5f_inclusiveDecays")!=std::string::npos) return 32.51;
  else if (name.find("ST_tW_top_5f_NoFullyHadronicDecays")!=std::string::npos) return 32.45*0.335;
  else if (name.find("ST_tW_top_5f_inclusiveDecays")!=std::string::npos) return 32.45;
  else if (name.find("TTGJets")!=std::string::npos) return 3.757;
  else if (name.find("TTGamma_Hadronic")!=std::string::npos) return 4.178;
  else if (name.find("TTGamma_Dilept_ptGamma100-200")!=std::string::npos) return 0.03457; //own calculation
  else if (name.find("TTGamma_Dilept_ptGamma200inf")!=std::string::npos) return 0.006854; //own calculation
  else if (name.find("TTGamma_Dilept")!=std::string::npos) return 1.502;
  else if (name.find("TTGamma_SingleLept_ptGamma100-200")!=std::string::npos) return 0.1328; //own calculation
  else if (name.find("TTGamma_SingleLept_ptGamma200inf")!=std::string::npos) return 0.02721; //own calculation
  else if (name.find("TTGamma_SingleLept")!=std::string::npos) return 5.095;
  else if (name.find("TTJets")!=std::string::npos) return 750.5;
  else if (name.find("TTTo2L2Nu")!=std::string::npos) return 687.1*0.335*0.335;
  else if (name.find("TTToSemiLeptonic")!=std::string::npos) return 687.1*2*0.665*0.335;
  else if (name.find("WGammaToJJGamma")!=std::string::npos) return 8.635;
  else if (name.find("WGJets_MonoPhoton_PtG-40to130")!=std::string::npos) return 19.75;
  else if (name.find("WGJets_MonoPhoton_PtG-130")!=std::string::npos) return 0.8099;
  else if (name.find("WGToLNuG_01J_5f_TuneCP5")!=std::string::npos) return 191.3;
  else if (name.find("WGToLNuG_01J_5f_PtG_130")!=std::string::npos) return 1.029;
  else if (name.find("WGToLNuG_01J_5f_PtG_300")!=std::string::npos) return 0.07025;
  else if (name.find("WGToLNuG_01J_5f_PtG_500")!=std::string::npos) return 0.009362;
  else if (name.find("WJetsToLNu_HT-100To200")!=std::string::npos) return 1256;
  else if (name.find("WJetsToLNu_HT-200To400")!=std::string::npos) return 335.5;
  else if (name.find("WJetsToLNu_HT-400To600")!=std::string::npos) return 45.25;
  else if (name.find("WJetsToLNu_HT-600To800")!=std::string::npos) return 10.97;
  else if (name.find("WJetsToLNu_HT-800To1200")!=std::string::npos) return 4.933;
  else if (name.find("WJetsToLNu_HT-1200To2500")!=std::string::npos) return 1.16;
  else if (name.find("WJetsToLNu_HT-2500ToInf")!=std::string::npos) return 0.02623; //own calculation
  else if (name.find("WJetsToQQ_HT-200to400")!=std::string::npos) return 2549;
  else if (name.find("WJetsToQQ_HT-400to600")!=std::string::npos) return 276.5;
  else if (name.find("WJetsToQQ_HT-600to800")!=std::string::npos) return 59.25;
  else if (name.find("WJetsToQQ_HT-800toInf")!=std::string::npos) return 28.75;
  else if (name.find("WWG")!=std::string::npos) return 0.3369; //own calculation
  else if (name.find("WW")!=std::string::npos) return 75.95;
  else if (name.find("WZ")!=std::string::npos) return 27.59;
  else if (name.find("ZGammaToJJGamma")!=std::string::npos) return 4.144;
  else if (name.find("ZGToLLG")!=std::string::npos) return 51.1;
  else if (name.find("ZGTo2NuG")!=std::string::npos) return 30.18;
  else if (name.find("ZJetsToNuNu_HT-100To200")!=std::string::npos) return 267.0*1.23;
  else if (name.find("ZJetsToNuNu_HT-200To400")!=std::string::npos) return 73.08*1.23;
  else if (name.find("ZJetsToNuNu_HT-400To600")!=std::string::npos) return 9.904*1.23;
  else if (name.find("ZJetsToNuNu_HT-600To800")!=std::string::npos) return 2.413*1.23;
  else if (name.find("ZJetsToNuNu_HT-800To1200")!=std::string::npos) return 1.071*1.23;
  else if (name.find("ZJetsToNuNu_HT-1200To2500")!=std::string::npos) return 0.2497*1.23;
  else if (name.find("ZJetsToNuNu_HT-2500ToInf")!=std::string::npos) return 0.005618*1.23;
  else if (name.find("ZJetsToQQ_HT-200to400")!=std::string::npos) return 1012;
  else if (name.find("ZJetsToQQ_HT-400to600")!=std::string::npos) return 114.2;
  else if (name.find("ZJetsToQQ_HT-600to800")!=std::string::npos) return 25.34;
  else if (name.find("ZJetsToQQ_HT-800toInf")!=std::string::npos) return 12.91; //own calculation
  else if (name.find("ZZ")!=std::string::npos) return 12.17;
  std::cout<<"No cross section found for "<<name<<"\nUsing xsec=1"<<std::endl;
  return 1;
}

//Get gluino-gluino cross section, use input of gluino mass and -1/+1 for lower/upper errors
double get_cross_section(int m_primary, int SignalScenario, int center_down_up=0) {
  if (SignalScenario==1 || SignalScenario==3 || SignalScenario==4) {
    switch (m_primary) {
      case 500 : return 0.338e+02+center_down_up*0.338e+02/100*7.86;
        break;                                            
      case 505 : return 0.319e+02+center_down_up*0.319e+02/100*7.89;
        break;                                            
      case 510 : return 0.301e+02+center_down_up*0.301e+02/100*7.92;
        break;                                            
      case 515 : return 0.284e+02+center_down_up*0.284e+02/100*7.96;
        break;                                            
      case 520 : return 0.268e+02+center_down_up*0.268e+02/100*8.0;
        break;                                            
      case 525 : return 0.253e+02+center_down_up*0.253e+02/100*8.03;
        break;                                            
      case 530 : return 0.240e+02+center_down_up*0.240e+02/100*8.07;
        break;                                            
      case 535 : return 0.227e+02+center_down_up*0.227e+02/100*8.11;
        break;                                            
      case 540 : return 0.214e+02+center_down_up*0.214e+02/100*8.14;
        break;                                            
      case 545 : return 0.203e+02+center_down_up*0.203e+02/100*8.18;
        break;                                            
      case 550 : return 0.192e+02+center_down_up*0.192e+02/100*8.22;
        break;                                            
      case 555 : return 0.182e+02+center_down_up*0.182e+02/100*8.26;
        break;                                            
      case 560 : return 0.172e+02+center_down_up*0.172e+02/100*8.3;
        break;                                            
      case 565 : return 0.163e+02+center_down_up*0.163e+02/100*8.34;
        break;                                            
      case 570 : return 0.155e+02+center_down_up*0.155e+02/100*8.37;
        break;                                            
      case 575 : return 0.147e+02+center_down_up*0.147e+02/100*8.41;
        break;                                            
      case 580 : return 0.139e+02+center_down_up*0.139e+02/100*8.45;
        break;                                            
      case 585 : return 0.132e+02+center_down_up*0.132e+02/100*8.49;
        break;                                            
      case 590 : return 0.126e+02+center_down_up*0.126e+02/100*8.53;
        break;                                            
      case 595 : return 0.119e+02+center_down_up*0.119e+02/100*8.57;
        break;                                            
      case 600 : return 0.113e+02+center_down_up*0.113e+02/100*8.62;
        break;                                            
      case 605 : return 0.108e+02+center_down_up*0.108e+02/100*8.66;
        break;                                            
      case 610 : return 0.102e+02+center_down_up*0.102e+02/100*8.7;
        break;                                            
      case 615 : return 0.974e+01+center_down_up*0.974e+01/100*8.74;
        break;                                            
      case 620 : return 0.926e+01+center_down_up*0.926e+01/100*8.78;
        break;                                            
      case 625 : return 0.881e+01+center_down_up*0.881e+01/100*8.82;
        break;                                            
      case 630 : return 0.839e+01+center_down_up*0.839e+01/100*8.86;
        break;                                            
      case 635 : return 0.799e+01+center_down_up*0.799e+01/100*8.9;
        break;                                            
      case 640 : return 0.761e+01+center_down_up*0.761e+01/100*8.94;
        break;                                            
      case 645 : return 0.725e+01+center_down_up*0.725e+01/100*8.98;
        break;                                            
      case 650 : return 0.690e+01+center_down_up*0.690e+01/100*9.02;
        break;                                            
      case 655 : return 0.658e+01+center_down_up*0.658e+01/100*9.06;
        break;                                            
      case 660 : return 0.627e+01+center_down_up*0.627e+01/100*9.1;
        break;                                            
      case 665 : return 0.598e+01+center_down_up*0.598e+01/100*9.15;
        break;                                            
      case 670 : return 0.571e+01+center_down_up*0.571e+01/100*9.19;
        break;                                            
      case 675 : return 0.544e+01+center_down_up*0.544e+01/100*9.23;
        break;                                            
      case 680 : return 0.520e+01+center_down_up*0.520e+01/100*9.27;
        break;                                            
      case 685 : return 0.496e+01+center_down_up*0.496e+01/100*9.31;
        break;                                            
      case 690 : return 0.474e+01+center_down_up*0.474e+01/100*9.35;
        break;                                            
      case 695 : return 0.452e+01+center_down_up*0.452e+01/100*9.39;
        break;                                            
      case 700 : return 0.432e+01+center_down_up*0.432e+01/100*9.43;
        break;                                            
      case 705 : return 0.413e+01+center_down_up*0.413e+01/100*9.46;
        break;                                            
      case 710 : return 0.395e+01+center_down_up*0.395e+01/100*9.5;
        break;                                            
      case 715 : return 0.377e+01+center_down_up*0.377e+01/100*9.54;
        break;                                            
      case 720 : return 0.361e+01+center_down_up*0.361e+01/100*9.58;
        break;                                            
      case 725 : return 0.345e+01+center_down_up*0.345e+01/100*9.61;
        break;                                            
      case 730 : return 0.330e+01+center_down_up*0.330e+01/100*9.65;
        break;                                            
      case 735 : return 0.316e+01+center_down_up*0.316e+01/100*9.69;
        break;                                            
      case 740 : return 0.302e+01+center_down_up*0.302e+01/100*9.72;
        break;                                            
      case 745 : return 0.289e+01+center_down_up*0.289e+01/100*9.76;
        break;                                            
      case 750 : return 0.277e+01+center_down_up*0.277e+01/100*9.8;
        break;                                            
      case 755 : return 0.265e+01+center_down_up*0.265e+01/100*9.83;
        break;                                            
      case 760 : return 0.254e+01+center_down_up*0.254e+01/100*9.87;
        break;                                            
      case 765 : return 0.243e+01+center_down_up*0.243e+01/100*9.91;
        break;                                            
      case 770 : return 0.233e+01+center_down_up*0.233e+01/100*9.94;
        break;                                            
      case 775 : return 0.223e+01+center_down_up*0.223e+01/100*9.98;
        break;                                            
      case 780 : return 0.214e+01+center_down_up*0.214e+01/100*10.01;
        break;                                            
      case 785 : return 0.205e+01+center_down_up*0.205e+01/100*10.05;
        break;                                            
      case 790 : return 0.197e+01+center_down_up*0.197e+01/100*10.09;
        break;                                            
      case 795 : return 0.188e+01+center_down_up*0.188e+01/100*10.12;
        break;                                            
      case 800 : return 0.181e+01+center_down_up*0.181e+01/100*10.16;
        break;                                            
      case 805 : return 0.173e+01+center_down_up*0.173e+01/100*10.2;
        break;                                            
      case 810 : return 0.166e+01+center_down_up*0.166e+01/100*10.23;
        break;                                            
      case 815 : return 0.160e+01+center_down_up*0.160e+01/100*10.27;
        break;                                            
      case 820 : return 0.153e+01+center_down_up*0.153e+01/100*10.31;
        break;                                            
      case 825 : return 0.147e+01+center_down_up*0.147e+01/100*10.34;
        break;                                            
      case 830 : return 0.141e+01+center_down_up*0.141e+01/100*10.38;
        break;                                            
      case 835 : return 0.136e+01+center_down_up*0.136e+01/100*10.42;
        break;                                            
      case 840 : return 0.130e+01+center_down_up*0.130e+01/100*10.45;
        break;                                            
      case 845 : return 0.125e+01+center_down_up*0.125e+01/100*10.49;
        break;                                            
      case 850 : return 0.120e+01+center_down_up*0.120e+01/100*10.53;
        break;                                            
      case 855 : return 0.115e+01+center_down_up*0.115e+01/100*10.57;
        break;                                            
      case 860 : return 0.111e+01+center_down_up*0.111e+01/100*10.6;
        break;                                            
      case 865 : return 0.107e+01+center_down_up*0.107e+01/100*10.64;
        break;                                            
      case 870 : return 0.103e+01+center_down_up*0.103e+01/100*10.68;
        break;                                            
      case 875 : return 0.986e+00+center_down_up*0.986e+00/100*10.71;
        break;                                            
      case 880 : return 0.948e+00+center_down_up*0.948e+00/100*10.75;
        break;                                            
      case 885 : return 0.912e+00+center_down_up*0.912e+00/100*10.79;
        break;                                            
      case 890 : return 0.877e+00+center_down_up*0.877e+00/100*10.82;
        break;                                            
      case 895 : return 0.844e+00+center_down_up*0.844e+00/100*10.86;
        break;                                            
      case 900 : return 0.812e+00+center_down_up*0.812e+00/100*10.89;
        break;                                            
      case 905 : return 0.781e+00+center_down_up*0.781e+00/100*10.93;
        break;                                            
      case 910 : return 0.752e+00+center_down_up*0.752e+00/100*10.97;
        break;                                            
      case 915 : return 0.723e+00+center_down_up*0.723e+00/100*11.0;
        break;                                            
      case 920 : return 0.696e+00+center_down_up*0.696e+00/100*11.04;
        break;                                            
      case 925 : return 0.670e+00+center_down_up*0.670e+00/100*11.07;
        break;                                            
      case 930 : return 0.646e+00+center_down_up*0.646e+00/100*11.11;
        break;                                            
      case 935 : return 0.622e+00+center_down_up*0.622e+00/100*11.14;
        break;                                            
      case 940 : return 0.599e+00+center_down_up*0.599e+00/100*11.18;
        break;                                            
      case 945 : return 0.577e+00+center_down_up*0.577e+00/100*11.21;
        break;                                            
      case 950 : return 0.556e+00+center_down_up*0.556e+00/100*11.25;
        break;                                            
      case 955 : return 0.535e+00+center_down_up*0.535e+00/100*11.28;
        break;                                            
      case 960 : return 0.516e+00+center_down_up*0.516e+00/100*11.32;
        break;                                            
      case 965 : return 0.497e+00+center_down_up*0.497e+00/100*11.35;
        break;                                            
      case 970 : return 0.479e+00+center_down_up*0.479e+00/100*11.39;
        break;                                            
      case 975 : return 0.462e+00+center_down_up*0.462e+00/100*11.42;
        break;                                            
      case 980 : return 0.445e+00+center_down_up*0.445e+00/100*11.46;
        break;                                            
      case 985 : return 0.430e+00+center_down_up*0.430e+00/100*11.49;
        break;                                            
      case 990 : return 0.414e+00+center_down_up*0.414e+00/100*11.53;
        break;                                            
      case 995 : return 0.399e+00+center_down_up*0.399e+00/100*11.56;
        break;
      case 1000 : return  0.385e+00+center_down_up*0.385e+00/100*11.6;
        break;                                              
      case 1005 : return  0.372e+00+center_down_up*0.372e+00/100*11.63;
        break;                                              
      case 1010 : return  0.359e+00+center_down_up*0.359e+00/100*11.67;
        break;                                              
      case 1015 : return  0.346e+00+center_down_up*0.346e+00/100*11.7;
        break;                                              
      case 1020 : return  0.334e+00+center_down_up*0.334e+00/100*11.74;
        break;                                              
      case 1025 : return  0.322e+00+center_down_up*0.322e+00/100*11.78;
        break;                                              
      case 1030 : return  0.311e+00+center_down_up*0.311e+00/100*11.81;
        break;                                              
      case 1035 : return  0.300e+00+center_down_up*0.300e+00/100*11.85;
        break;                                              
      case 1040 : return  0.290e+00+center_down_up*0.290e+00/100*11.88;
        break;                                              
      case 1045 : return  0.280e+00+center_down_up*0.280e+00/100*11.92;
        break;                                              
      case 1050 : return  0.270e+00+center_down_up*0.270e+00/100*11.95;
        break;                                              
      case 1055 : return  0.261e+00+center_down_up*0.261e+00/100*11.99;
        break;                                              
      case 1060 : return  0.252e+00+center_down_up*0.252e+00/100*12.02;
        break;                                              
      case 1065 : return  0.243e+00+center_down_up*0.243e+00/100*12.06;
        break;                                              
      case 1070 : return  0.235e+00+center_down_up*0.235e+00/100*12.09;
        break;                                              
      case 1075 : return  0.227e+00+center_down_up*0.227e+00/100*12.13;
        break;                                              
      case 1080 : return  0.219e+00+center_down_up*0.219e+00/100*12.17;
        break;                                              
      case 1085 : return  0.212e+00+center_down_up*0.212e+00/100*12.2;
        break;                                              
      case 1090 : return  0.205e+00+center_down_up*0.205e+00/100*12.24;
        break;                                              
      case 1095 : return  0.198e+00+center_down_up*0.198e+00/100*12.27;
        break;                                              
      case 1100 : return  0.191e+00+center_down_up*0.191e+00/100*12.31;
        break;                                              
      case 1105 : return  0.185e+00+center_down_up*0.185e+00/100*12.34;
        break;                                              
      case 1110 : return  0.179e+00+center_down_up*0.179e+00/100*12.38;
        break;                                              
      case 1115 : return  0.173e+00+center_down_up*0.173e+00/100*12.42;
        break;                                              
      case 1120 : return  0.167e+00+center_down_up*0.167e+00/100*12.45;
        break;                                              
      case 1125 : return  0.162e+00+center_down_up*0.162e+00/100*12.49;
        break;                                              
      case 1130 : return  0.156e+00+center_down_up*0.156e+00/100*12.53;
        break;                                              
      case 1135 : return  0.151e+00+center_down_up*0.151e+00/100*12.56;
        break;                                              
      case 1140 : return  0.146e+00+center_down_up*0.146e+00/100*12.6;
        break;                                              
      case 1145 : return  0.141e+00+center_down_up*0.141e+00/100*12.64;
        break;                                              
      case 1150 : return  0.137e+00+center_down_up*0.137e+00/100*12.67;
        break;                                              
      case 1155 : return  0.132e+00+center_down_up*0.132e+00/100*12.71;
        break;                                              
      case 1160 : return  0.128e+00+center_down_up*0.128e+00/100*12.74;
        break;                                              
      case 1165 : return  0.124e+00+center_down_up*0.124e+00/100*12.78;
        break;                                              
      case 1170 : return  0.120e+00+center_down_up*0.120e+00/100*12.82;
        break;                                              
      case 1175 : return  0.116e+00+center_down_up*0.116e+00/100*12.85;
        break;                                              
      case 1180 : return  0.112e+00+center_down_up*0.112e+00/100*12.89;
        break;                                              
      case 1185 : return  0.109e+00+center_down_up*0.109e+00/100*12.92;
        break;                                              
      case 1190 : return  0.105e+00+center_down_up*0.105e+00/100*12.96;
        break;                                              
      case 1195 : return  0.102e+00+center_down_up*0.102e+00/100*13.0;
        break;                                              
      case 1200 : return  0.985e-01+center_down_up*0.985e-01/100*13.03;
        break;                                              
      case 1205 : return  0.953e-01+center_down_up*0.953e-01/100*13.07;
        break;                                              
      case 1210 : return  0.923e-01+center_down_up*0.923e-01/100*13.1;
        break;                                              
      case 1215 : return  0.894e-01+center_down_up*0.894e-01/100*13.14;
        break;                                              
      case 1220 : return  0.866e-01+center_down_up*0.866e-01/100*13.17;
        break;                                              
      case 1225 : return  0.838e-01+center_down_up*0.838e-01/100*13.21;
        break;                                              
      case 1230 : return  0.812e-01+center_down_up*0.812e-01/100*13.24;
        break;                                              
      case 1235 : return  0.786e-01+center_down_up*0.786e-01/100*13.27;
        break;                                              
      case 1240 : return  0.762e-01+center_down_up*0.762e-01/100*13.31;
        break;                                              
      case 1245 : return  0.738e-01+center_down_up*0.738e-01/100*13.34;
        break;                                              
      case 1250 : return  0.715e-01+center_down_up*0.715e-01/100*13.38;
        break;                                              
      case 1255 : return  0.692e-01+center_down_up*0.692e-01/100*13.41;
        break;                                              
      case 1260 : return  0.671e-01+center_down_up*0.671e-01/100*13.45;
        break;                                              
      case 1265 : return  0.650e-01+center_down_up*0.650e-01/100*13.48;
        break;                                              
      case 1270 : return  0.630e-01+center_down_up*0.630e-01/100*13.51;
        break;                                              
      case 1275 : return  0.610e-01+center_down_up*0.610e-01/100*13.55;
        break;                                              
      case 1280 : return  0.591e-01+center_down_up*0.591e-01/100*13.58;
        break;                                              
      case 1285 : return  0.573e-01+center_down_up*0.573e-01/100*13.62;
        break;                                              
      case 1290 : return  0.556e-01+center_down_up*0.556e-01/100*13.65;
        break;                                              
      case 1295 : return  0.539e-01+center_down_up*0.539e-01/100*13.69;
        break;                                              
      case 1300 : return  0.522e-01+center_down_up*0.522e-01/100*13.72;
        break;                                              
      case 1305 : return  0.506e-01+center_down_up*0.506e-01/100*13.76;
        break;                                              
      case 1310 : return  0.491e-01+center_down_up*0.491e-01/100*13.79;
        break;                                              
      case 1315 : return  0.476e-01+center_down_up*0.476e-01/100*13.83;
        break;                                              
      case 1320 : return  0.461e-01+center_down_up*0.461e-01/100*13.86;
        break;                                              
      case 1325 : return  0.447e-01+center_down_up*0.447e-01/100*13.9;
        break;                                              
      case 1330 : return  0.434e-01+center_down_up*0.434e-01/100*13.94;
        break;                                              
      case 1335 : return  0.421e-01+center_down_up*0.421e-01/100*13.97;
        break;                                              
      case 1340 : return  0.408e-01+center_down_up*0.408e-01/100*14.01;
        break;                                              
      case 1345 : return  0.396e-01+center_down_up*0.396e-01/100*14.04;
        break;                                              
      case 1350 : return  0.384e-01+center_down_up*0.384e-01/100*14.08;
        break;                                              
      case 1355 : return  0.372e-01+center_down_up*0.372e-01/100*14.11;
        break;                                              
      case 1360 : return  0.361e-01+center_down_up*0.361e-01/100*14.15;
        break;                                              
      case 1365 : return  0.350e-01+center_down_up*0.350e-01/100*14.19;
        break;                                              
      case 1370 : return  0.340e-01+center_down_up*0.340e-01/100*14.22;
        break;                                              
      case 1375 : return  0.330e-01+center_down_up*0.330e-01/100*14.26;
        break;                                              
      case 1380 : return  0.320e-01+center_down_up*0.320e-01/100*14.3;
        break;                                              
      case 1385 : return  0.310e-01+center_down_up*0.310e-01/100*14.33;
        break;                                              
      case 1390 : return  0.301e-01+center_down_up*0.301e-01/100*14.37;
        break;                                              
      case 1395 : return  0.292e-01+center_down_up*0.292e-01/100*14.4;
        break;                                              
      case 1400 : return  0.284e-01+center_down_up*0.284e-01/100*14.44;
        break;                                              
      case 1405 : return  0.275e-01+center_down_up*0.275e-01/100*14.48;
        break;                                              
      case 1410 : return  0.267e-01+center_down_up*0.267e-01/100*14.51;
        break;                                              
      case 1415 : return  0.259e-01+center_down_up*0.259e-01/100*14.55;
        break;                                              
      case 1420 : return  0.252e-01+center_down_up*0.252e-01/100*14.59;
        break;                                              
      case 1425 : return  0.244e-01+center_down_up*0.244e-01/100*14.63;
        break;                                              
      case 1430 : return  0.237e-01+center_down_up*0.237e-01/100*14.66;
        break;                                              
      case 1435 : return  0.230e-01+center_down_up*0.230e-01/100*14.7;
        break;                                              
      case 1440 : return  0.224e-01+center_down_up*0.224e-01/100*14.74;
        break;                                              
      case 1445 : return  0.217e-01+center_down_up*0.217e-01/100*14.77;
        break;                                              
      case 1450 : return  0.211e-01+center_down_up*0.211e-01/100*14.81;
        break;                                              
      case 1455 : return  0.205e-01+center_down_up*0.205e-01/100*14.85;
        break;                                              
      case 1460 : return  0.199e-01+center_down_up*0.199e-01/100*14.88;
        break;                                              
      case 1465 : return  0.193e-01+center_down_up*0.193e-01/100*14.92;
        break;                                              
      case 1470 : return  0.187e-01+center_down_up*0.187e-01/100*14.96;
        break;                                              
      case 1475 : return  0.182e-01+center_down_up*0.182e-01/100*15.0;
        break;                                              
      case 1480 : return  0.177e-01+center_down_up*0.177e-01/100*15.03;
        break;                                              
      case 1485 : return  0.172e-01+center_down_up*0.172e-01/100*15.07;
        break;                                              
      case 1490 : return  0.167e-01+center_down_up*0.167e-01/100*15.11;
        break;                                              
      case 1495 : return  0.162e-01+center_down_up*0.162e-01/100*15.15;
        break;                                              
      case 1500 : return  0.157e-01+center_down_up*0.157e-01/100*15.18;
        break;                                              
      case 1505 : return  0.153e-01+center_down_up*0.153e-01/100*15.22;
        break;                                              
      case 1510 : return  0.148e-01+center_down_up*0.148e-01/100*15.26;
        break;                                              
      case 1515 : return  0.144e-01+center_down_up*0.144e-01/100*15.3;
        break;                                              
      case 1520 : return  0.140e-01+center_down_up*0.140e-01/100*15.33;
        break;                                              
      case 1525 : return  0.136e-01+center_down_up*0.136e-01/100*15.37;
        break;                                              
      case 1530 : return  0.132e-01+center_down_up*0.132e-01/100*15.41;
        break;                                              
      case 1535 : return  0.128e-01+center_down_up*0.128e-01/100*15.45;
        break;                                              
      case 1540 : return  0.125e-01+center_down_up*0.125e-01/100*15.48;
        break;                                              
      case 1545 : return  0.121e-01+center_down_up*0.121e-01/100*15.52;
        break;                                              
      case 1550 : return  0.118e-01+center_down_up*0.118e-01/100*15.56;
        break;                                              
      case 1555 : return  0.115e-01+center_down_up*0.115e-01/100*15.6;
        break;                                              
      case 1560 : return  0.111e-01+center_down_up*0.111e-01/100*15.64;
        break;                                              
      case 1565 : return  0.108e-01+center_down_up*0.108e-01/100*15.67;
        break;                                              
      case 1570 : return  0.105e-01+center_down_up*0.105e-01/100*15.71;
        break;                                              
      case 1575 : return  0.102e-01+center_down_up*0.102e-01/100*15.75;
        break;                                              
      case 1580 : return  0.993e-02+center_down_up*0.993e-02/100*15.79;
        break;                                              
      case 1585 : return  0.966e-02+center_down_up*0.966e-02/100*15.83;
        break;                                              
      case 1590 : return  0.939e-02+center_down_up*0.939e-02/100*15.87;
        break;                                              
      case 1595 : return  0.912e-02+center_down_up*0.912e-02/100*15.9;
        break;                                              
      case 1600 : return  0.887e-02+center_down_up*0.887e-02/100*15.94;
        break;                                              
      case 1605 : return  0.862e-02+center_down_up*0.862e-02/100*15.98;
        break;                                              
      case 1610 : return  0.838e-02+center_down_up*0.838e-02/100*16.02;
        break;                                              
      case 1615 : return  0.815e-02+center_down_up*0.815e-02/100*16.06;
        break;                                              
      case 1620 : return  0.792e-02+center_down_up*0.792e-02/100*16.1;
        break;                                              
      case 1625 : return  0.770e-02+center_down_up*0.770e-02/100*16.13;
        break;                                              
      case 1630 : return  0.749e-02+center_down_up*0.749e-02/100*16.17;
        break;                                              
      case 1635 : return  0.728e-02+center_down_up*0.728e-02/100*16.21;
        break;                                              
      case 1640 : return  0.708e-02+center_down_up*0.708e-02/100*16.25;
        break;                                              
      case 1645 : return  0.689e-02+center_down_up*0.689e-02/100*16.29;
        break;                                              
      case 1650 : return  0.670e-02+center_down_up*0.670e-02/100*16.33;
        break;                                              
      case 1655 : return  0.651e-02+center_down_up*0.651e-02/100*16.37;
        break;                                              
      case 1660 : return  0.633e-02+center_down_up*0.633e-02/100*16.41;
        break;                                              
      case 1665 : return  0.616e-02+center_down_up*0.616e-02/100*16.45;
        break;                                              
      case 1670 : return  0.599e-02+center_down_up*0.599e-02/100*16.49;
        break;                                              
      case 1675 : return  0.583e-02+center_down_up*0.583e-02/100*16.53;
        break;                                              
      case 1680 : return  0.567e-02+center_down_up*0.567e-02/100*16.56;
        break;                                              
      case 1685 : return  0.551e-02+center_down_up*0.551e-02/100*16.6;
        break;                                              
      case 1690 : return  0.536e-02+center_down_up*0.536e-02/100*16.64;
        break;                                              
      case 1695 : return  0.521e-02+center_down_up*0.521e-02/100*16.68;
        break;                                              
      case 1700 : return  0.507e-02+center_down_up*0.507e-02/100*16.72;
        break;                                              
      case 1705 : return  0.493e-02+center_down_up*0.493e-02/100*16.76;
        break;                                              
      case 1710 : return  0.480e-02+center_down_up*0.480e-02/100*16.81;
        break;                                              
      case 1715 : return  0.467e-02+center_down_up*0.467e-02/100*16.85;
        break;                                              
      case 1720 : return  0.454e-02+center_down_up*0.454e-02/100*16.89;
        break;                                              
      case 1725 : return  0.442e-02+center_down_up*0.442e-02/100*16.93;
        break;                                              
      case 1730 : return  0.430e-02+center_down_up*0.430e-02/100*16.97;
        break;                                              
      case 1735 : return  0.418e-02+center_down_up*0.418e-02/100*17.01;
        break;                                              
      case 1740 : return  0.407e-02+center_down_up*0.407e-02/100*17.05;
        break;                                              
      case 1745 : return  0.396e-02+center_down_up*0.396e-02/100*17.09;
        break;                                              
      case 1750 : return  0.385e-02+center_down_up*0.385e-02/100*17.13;
        break;                                              
      case 1755 : return  0.375e-02+center_down_up*0.375e-02/100*17.18;
        break;                                              
      case 1760 : return  0.365e-02+center_down_up*0.365e-02/100*17.22;
        break;                                              
      case 1765 : return  0.355e-02+center_down_up*0.355e-02/100*17.26;
        break;                                              
      case 1770 : return  0.345e-02+center_down_up*0.345e-02/100*17.3;
        break;                                              
      case 1775 : return  0.336e-02+center_down_up*0.336e-02/100*17.34;
        break;                                              
      case 1780 : return  0.327e-02+center_down_up*0.327e-02/100*17.39;
        break;                                              
      case 1785 : return  0.318e-02+center_down_up*0.318e-02/100*17.43;
        break;                                              
      case 1790 : return  0.310e-02+center_down_up*0.310e-02/100*17.47;
        break;                                              
      case 1795 : return  0.301e-02+center_down_up*0.301e-02/100*17.51;
        break;                                              
      case 1800 : return  0.293e-02+center_down_up*0.293e-02/100*17.56;
        break;                                              
      case 1805 : return  0.286e-02+center_down_up*0.286e-02/100*17.6;
        break;                                              
      case 1810 : return  0.278e-02+center_down_up*0.278e-02/100*17.64;
        break;                                              
      case 1815 : return  0.271e-02+center_down_up*0.271e-02/100*17.69;
        break;                                              
      case 1820 : return  0.263e-02+center_down_up*0.263e-02/100*17.73;
        break;                                              
      case 1825 : return  0.256e-02+center_down_up*0.256e-02/100*17.77;
        break;                                              
      case 1830 : return  0.249e-02+center_down_up*0.249e-02/100*17.82;
        break;                                              
      case 1835 : return  0.243e-02+center_down_up*0.243e-02/100*17.86;
        break;                                              
      case 1840 : return  0.236e-02+center_down_up*0.236e-02/100*17.9;
        break;                                              
      case 1845 : return  0.230e-02+center_down_up*0.230e-02/100*17.95;
        break;                                              
      case 1850 : return  0.224e-02+center_down_up*0.224e-02/100*17.99;
        break;                                              
      case 1855 : return  0.218e-02+center_down_up*0.218e-02/100*18.04;
        break;                                              
      case 1860 : return  0.212e-02+center_down_up*0.212e-02/100*18.08;
        break;                                              
      case 1865 : return  0.207e-02+center_down_up*0.207e-02/100*18.13;
        break;                                              
      case 1870 : return  0.201e-02+center_down_up*0.201e-02/100*18.17;
        break;                                              
      case 1875 : return  0.196e-02+center_down_up*0.196e-02/100*18.22;
        break;                                              
      case 1880 : return  0.191e-02+center_down_up*0.191e-02/100*18.26;
        break;                                              
      case 1885 : return  0.186e-02+center_down_up*0.186e-02/100*18.31;
        break;                                              
      case 1890 : return  0.181e-02+center_down_up*0.181e-02/100*18.35;
        break;                                              
      case 1895 : return  0.176e-02+center_down_up*0.176e-02/100*18.4;
        break;                                              
      case 1900 : return  0.171e-02+center_down_up*0.171e-02/100*18.45;
        break;                                              
      case 1905 : return  0.167e-02+center_down_up*0.167e-02/100*18.49;
        break;                                              
      case 1910 : return  0.163e-02+center_down_up*0.163e-02/100*18.54;
        break;                                              
      case 1915 : return  0.158e-02+center_down_up*0.158e-02/100*18.59;
        break;                                              
      case 1920 : return  0.154e-02+center_down_up*0.154e-02/100*18.63;
        break;                                              
      case 1925 : return  0.150e-02+center_down_up*0.150e-02/100*18.68;
        break;                                              
      case 1930 : return  0.146e-02+center_down_up*0.146e-02/100*18.73;
        break;                                              
      case 1935 : return  0.142e-02+center_down_up*0.142e-02/100*18.78;
        break;                                              
      case 1940 : return  0.139e-02+center_down_up*0.139e-02/100*18.82;
        break;                                              
      case 1945 : return  0.135e-02+center_down_up*0.135e-02/100*18.87;
        break;                                              
      case 1950 : return  0.131e-02+center_down_up*0.131e-02/100*18.92;
        break;                                              
      case 1955 : return  0.128e-02+center_down_up*0.128e-02/100*18.97;
        break;                                              
      case 1960 : return  0.125e-02+center_down_up*0.125e-02/100*19.02;
        break;                                              
      case 1965 : return  0.121e-02+center_down_up*0.121e-02/100*19.07;
        break;                                              
      case 1970 : return  0.118e-02+center_down_up*0.118e-02/100*19.12;
        break;                                              
      case 1975 : return  0.115e-02+center_down_up*0.115e-02/100*19.17;
        break;                                              
      case 1980 : return  0.112e-02+center_down_up*0.112e-02/100*19.22;
        break;                                              
      case 1985 : return  0.109e-02+center_down_up*0.109e-02/100*19.27;
        break;                                              
      case 1990 : return  0.106e-02+center_down_up*0.106e-02/100*19.32;
        break;                                              
      case 1995 : return  0.104e-02+center_down_up*0.104e-02/100*19.37;
        break;                                              
      case 2000 : return  0.101e-02+center_down_up*0.101e-02/100*19.42;
        break;                                              
      case 2005 : return  0.983e-03+center_down_up*0.983e-03/100*19.48;
        break;                                              
      case 2010 : return  0.957e-03+center_down_up*0.957e-03/100*19.53;
        break;                                              
      case 2015 : return  0.933e-03+center_down_up*0.933e-03/100*19.58;
        break;                                              
      case 2020 : return  0.908e-03+center_down_up*0.908e-03/100*19.64;
        break;                                              
      case 2025 : return  0.885e-03+center_down_up*0.885e-03/100*19.69;
        break;                                              
      case 2030 : return  0.862e-03+center_down_up*0.862e-03/100*19.74;
        break;                                              
      case 2035 : return  0.840e-03+center_down_up*0.840e-03/100*19.8;
        break;                                              
      case 2040 : return  0.818e-03+center_down_up*0.818e-03/100*19.85;
        break;                                              
      case 2045 : return  0.797e-03+center_down_up*0.797e-03/100*19.91;
        break;                                              
      case 2050 : return  0.776e-03+center_down_up*0.776e-03/100*19.96;
        break;                                              
      case 2055 : return  0.756e-03+center_down_up*0.756e-03/100*20.02;
        break;                                              
      case 2060 : return  0.737e-03+center_down_up*0.737e-03/100*20.07;
        break;                                              
      case 2065 : return  0.718e-03+center_down_up*0.718e-03/100*20.13;
        break;                                              
      case 2070 : return  0.699e-03+center_down_up*0.699e-03/100*20.19;
        break;                                              
      case 2075 : return  0.681e-03+center_down_up*0.681e-03/100*20.25;
        break;                                              
      case 2080 : return  0.664e-03+center_down_up*0.664e-03/100*20.3;
        break;                                              
      case 2085 : return  0.647e-03+center_down_up*0.647e-03/100*20.36;
        break;                                              
      case 2090 : return  0.630e-03+center_down_up*0.630e-03/100*20.42;
        break;                                              
      case 2095 : return  0.614e-03+center_down_up*0.614e-03/100*20.48;
        break;                                              
      case 2100 : return  0.598e-03+center_down_up*0.598e-03/100*20.54;
        break;                                              
      case 2105 : return  0.583e-03+center_down_up*0.583e-03/100*20.6;
        break;                                              
      case 2110 : return  0.568e-03+center_down_up*0.568e-03/100*20.66;
        break;                                              
      case 2115 : return  0.553e-03+center_down_up*0.553e-03/100*20.72;
        break;                                              
      case 2120 : return  0.539e-03+center_down_up*0.539e-03/100*20.78;
        break;                                              
      case 2125 : return  0.525e-03+center_down_up*0.525e-03/100*20.84;
        break;                                              
      case 2130 : return  0.512e-03+center_down_up*0.512e-03/100*20.9;
        break;                                              
      case 2135 : return  0.499e-03+center_down_up*0.499e-03/100*20.97;
        break;                                              
      case 2140 : return  0.486e-03+center_down_up*0.486e-03/100*21.03;
        break;                                              
      case 2145 : return  0.473e-03+center_down_up*0.473e-03/100*21.09;
        break;                                              
      case 2150 : return  0.461e-03+center_down_up*0.461e-03/100*21.16;
        break;                                              
      case 2155 : return  0.449e-03+center_down_up*0.449e-03/100*21.22;
        break;                                              
      case 2160 : return  0.438e-03+center_down_up*0.438e-03/100*21.29;
        break;                                              
      case 2165 : return  0.427e-03+center_down_up*0.427e-03/100*21.35;
        break;                                              
      case 2170 : return  0.416e-03+center_down_up*0.416e-03/100*21.42;
        break;                                              
      case 2175 : return  0.405e-03+center_down_up*0.405e-03/100*21.48;
        break;                                              
      case 2180 : return  0.395e-03+center_down_up*0.395e-03/100*21.55;
        break;                                              
      case 2185 : return  0.385e-03+center_down_up*0.385e-03/100*21.62;
        break;                                              
      case 2190 : return  0.375e-03+center_down_up*0.375e-03/100*21.69;
        break;                                              
      case 2195 : return  0.365e-03+center_down_up*0.365e-03/100*21.76;
        break;                                              
      case 2200 : return  0.356e-03+center_down_up*0.356e-03/100*21.83;
        break;                                              
      case 2205 : return  0.347e-03+center_down_up*0.347e-03/100*21.9;
        break;                                              
      case 2210 : return  0.338e-03+center_down_up*0.338e-03/100*21.97;
        break;                                              
      case 2215 : return  0.330e-03+center_down_up*0.330e-03/100*22.04;
        break;                                              
      case 2220 : return  0.321e-03+center_down_up*0.321e-03/100*22.11;
        break;                                              
      case 2225 : return  0.313e-03+center_down_up*0.313e-03/100*22.18;
        break;                                              
      case 2230 : return  0.305e-03+center_down_up*0.305e-03/100*22.25;
        break;                                              
      case 2235 : return  0.297e-03+center_down_up*0.297e-03/100*22.33;
        break;                                              
      case 2240 : return  0.290e-03+center_down_up*0.290e-03/100*22.4;
        break;                                              
      case 2245 : return  0.283e-03+center_down_up*0.283e-03/100*22.47;
        break;                                              
      case 2250 : return  0.275e-03+center_down_up*0.275e-03/100*22.55;
        break;                                              
      case 2255 : return  0.268e-03+center_down_up*0.268e-03/100*22.63;
        break;                                              
      case 2260 : return  0.262e-03+center_down_up*0.262e-03/100*22.7;
        break;                                              
      case 2265 : return  0.255e-03+center_down_up*0.255e-03/100*22.78;
        break;                                              
      case 2270 : return  0.248e-03+center_down_up*0.248e-03/100*22.86;
        break;                                              
      case 2275 : return  0.242e-03+center_down_up*0.242e-03/100*22.94;
        break;                                              
      case 2280 : return  0.236e-03+center_down_up*0.236e-03/100*23.02;
        break;                                              
      case 2285 : return  0.230e-03+center_down_up*0.230e-03/100*23.1;
        break;                                              
      case 2290 : return  0.224e-03+center_down_up*0.224e-03/100*23.18;
        break;                                              
      case 2295 : return  0.219e-03+center_down_up*0.219e-03/100*23.26;
        break;                                              
      case 2300 : return  0.213e-03+center_down_up*0.213e-03/100*23.34;
        break;                                              
      case 2305 : return  0.208e-03+center_down_up*0.208e-03/100*23.43;
        break;                                              
      case 2310 : return  0.202e-03+center_down_up*0.202e-03/100*23.51;
        break;                                              
      case 2315 : return  0.197e-03+center_down_up*0.197e-03/100*23.6;
        break;                                              
      case 2320 : return  0.192e-03+center_down_up*0.192e-03/100*23.68;
        break;                                              
      case 2325 : return  0.187e-03+center_down_up*0.187e-03/100*23.77;
        break;                                              
      case 2330 : return  0.183e-03+center_down_up*0.183e-03/100*23.86;
        break;                                              
      case 2335 : return  0.178e-03+center_down_up*0.178e-03/100*23.95;
        break;                                              
      case 2340 : return  0.174e-03+center_down_up*0.174e-03/100*24.04;
        break;                                              
      case 2345 : return  0.169e-03+center_down_up*0.169e-03/100*24.13;
        break;                                              
      case 2350 : return  0.165e-03+center_down_up*0.165e-03/100*24.22;
        break;                                              
      case 2355 : return  0.161e-03+center_down_up*0.161e-03/100*24.31;
        break;                                              
      case 2360 : return  0.157e-03+center_down_up*0.157e-03/100*24.41;
        break;                                              
      case 2365 : return  0.153e-03+center_down_up*0.153e-03/100*24.5;
        break;                                              
      case 2370 : return  0.149e-03+center_down_up*0.149e-03/100*24.6;
        break;                                              
      case 2375 : return  0.145e-03+center_down_up*0.145e-03/100*24.7;
        break;                                              
      case 2380 : return  0.142e-03+center_down_up*0.142e-03/100*24.79;
        break;                                              
      case 2385 : return  0.138e-03+center_down_up*0.138e-03/100*24.89;
        break;                                              
      case 2390 : return  0.134e-03+center_down_up*0.134e-03/100*24.99;
        break;                                              
      case 2395 : return  0.131e-03+center_down_up*0.131e-03/100*25.09;
        break;                                              
      case 2400 : return  0.128e-03+center_down_up*0.128e-03/100*25.19;
        break;                                              
      case 2405 : return  0.125e-03+center_down_up*0.125e-03/100*25.3;
        break;                                              
      case 2410 : return  0.121e-03+center_down_up*0.121e-03/100*25.4;
        break;                                              
      case 2415 : return  0.118e-03+center_down_up*0.118e-03/100*25.5;
        break;                                              
      case 2420 : return  0.115e-03+center_down_up*0.115e-03/100*25.61;
        break;                                              
      case 2425 : return  0.113e-03+center_down_up*0.113e-03/100*25.71;
        break;                                              
      case 2430 : return  0.110e-03+center_down_up*0.110e-03/100*25.82;
        break;                                              
      case 2435 : return  0.107e-03+center_down_up*0.107e-03/100*25.93;
        break;                                              
      case 2440 : return  0.104e-03+center_down_up*0.104e-03/100*26.04;
        break;                                              
      case 2445 : return  0.102e-03+center_down_up*0.102e-03/100*26.15;
        break;                                              
      case 2450 : return  0.991e-04+center_down_up*0.991e-04/100*26.26;
        break;                                              
      case 2455 : return  0.966e-04+center_down_up*0.966e-04/100*26.37;
        break;                                              
      case 2460 : return  0.941e-04+center_down_up*0.941e-04/100*26.49;
        break;                                              
      case 2465 : return  0.918e-04+center_down_up*0.918e-04/100*26.6;
        break;                                              
      case 2470 : return  0.895e-04+center_down_up*0.895e-04/100*26.72;
        break;                                              
      case 2475 : return  0.872e-04+center_down_up*0.872e-04/100*26.84;
        break;                                              
      case 2480 : return  0.850e-04+center_down_up*0.850e-04/100*26.96;
        break;                                              
      case 2485 : return  0.829e-04+center_down_up*0.829e-04/100*27.08;
        break;                                              
      case 2490 : return  0.808e-04+center_down_up*0.808e-04/100*27.2;
        break;                                              
      case 2495 : return  0.788e-04+center_down_up*0.788e-04/100*27.33;
        break;                                              
      case 2500 : return  0.768e-04+center_down_up*0.768e-04/100*27.45;
        break;                                              
      case 2505 : return  0.749e-04+center_down_up*0.749e-04/100*27.58;
        break;                                              
      case 2510 : return  0.730e-04+center_down_up*0.730e-04/100*27.71;
        break;                                              
      case 2515 : return  0.712e-04+center_down_up*0.712e-04/100*27.84;
        break;                                              
      case 2520 : return  0.694e-04+center_down_up*0.694e-04/100*27.97;
        break;                                              
      case 2525 : return  0.677e-04+center_down_up*0.677e-04/100*28.11;
        break;                                              
      case 2530 : return  0.660e-04+center_down_up*0.660e-04/100*28.24;
        break;                                              
      case 2535 : return  0.643e-04+center_down_up*0.643e-04/100*28.38;
        break;                                              
      case 2540 : return  0.627e-04+center_down_up*0.627e-04/100*28.52;
        break;                                              
      case 2545 : return  0.611e-04+center_down_up*0.611e-04/100*28.66;
        break;                                              
      case 2550 : return  0.596e-04+center_down_up*0.596e-04/100*28.8;
        break;                                              
      case 2555 : return  0.581e-04+center_down_up*0.581e-04/100*28.94;
        break;                                              
      case 2560 : return  0.566e-04+center_down_up*0.566e-04/100*29.09;
        break;                                              
      case 2565 : return  0.552e-04+center_down_up*0.552e-04/100*29.23;
        break;                                              
      case 2570 : return  0.538e-04+center_down_up*0.538e-04/100*29.38;
        break;                                              
      case 2575 : return  0.525e-04+center_down_up*0.525e-04/100*29.53;
        break;                                              
      case 2580 : return  0.512e-04+center_down_up*0.512e-04/100*29.68;
        break;                                              
      case 2585 : return  0.499e-04+center_down_up*0.499e-04/100*29.84;
        break;                                              
      case 2590 : return  0.486e-04+center_down_up*0.486e-04/100*29.99;
        break;                                              
      case 2595 : return  0.474e-04+center_down_up*0.474e-04/100*30.15;
        break;                                              
      case 2600 : return  0.462e-04+center_down_up*0.462e-04/100*30.31;
        break;                                              
      case 2605 : return  0.451e-04+center_down_up*0.451e-04/100*30.47;
        break;                                              
      case 2610 : return  0.439e-04+center_down_up*0.439e-04/100*30.63;
        break;                                              
      case 2615 : return  0.428e-04+center_down_up*0.428e-04/100*30.8;
        break;                                              
      case 2620 : return  0.418e-04+center_down_up*0.418e-04/100*30.97;
        break;                                              
      case 2625 : return  0.407e-04+center_down_up*0.407e-04/100*31.13;
        break;                                              
      case 2630 : return  0.397e-04+center_down_up*0.397e-04/100*31.3;
        break;                                              
      case 2635 : return  0.387e-04+center_down_up*0.387e-04/100*31.48;
        break;                                              
      case 2640 : return  0.377e-04+center_down_up*0.377e-04/100*31.65;
        break;                                              
      case 2645 : return  0.368e-04+center_down_up*0.368e-04/100*31.83;
        break;                                              
      case 2650 : return  0.359e-04+center_down_up*0.359e-04/100*32.01;
        break;                                              
      case 2655 : return  0.350e-04+center_down_up*0.350e-04/100*32.19;
        break;                                              
      case 2660 : return  0.341e-04+center_down_up*0.341e-04/100*32.37;
        break;                                              
      case 2665 : return  0.332e-04+center_down_up*0.332e-04/100*32.56;
        break;                                              
      case 2670 : return  0.324e-04+center_down_up*0.324e-04/100*32.74;
        break;                                              
      case 2675 : return  0.316e-04+center_down_up*0.316e-04/100*32.93;
        break;                                              
      case 2680 : return  0.308e-04+center_down_up*0.308e-04/100*33.12;
        break;                                              
      case 2685 : return  0.300e-04+center_down_up*0.300e-04/100*33.32;
        break;                                              
      case 2690 : return  0.293e-04+center_down_up*0.293e-04/100*33.52;
        break;                                              
      case 2695 : return  0.285e-04+center_down_up*0.285e-04/100*33.71;
        break;                                              
      case 2700 : return  0.278e-04+center_down_up*0.278e-04/100*33.92;
        break;                                              
      case 2705 : return  0.271e-04+center_down_up*0.271e-04/100*34.13;
        break;                                              
      case 2710 : return  0.265e-04+center_down_up*0.265e-04/100*34.34;
        break;                                              
      case 2715 : return  0.258e-04+center_down_up*0.258e-04/100*34.56;
        break;                                              
      case 2720 : return  0.251e-04+center_down_up*0.251e-04/100*34.77;
        break;                                              
      case 2725 : return  0.245e-04+center_down_up*0.245e-04/100*34.99;
        break;                                              
      case 2730 : return  0.239e-04+center_down_up*0.239e-04/100*35.22;
        break;                                              
      case 2735 : return  0.233e-04+center_down_up*0.233e-04/100*35.44;
        break;                                              
      case 2740 : return  0.227e-04+center_down_up*0.227e-04/100*35.67;
        break;                                              
      case 2745 : return  0.221e-04+center_down_up*0.221e-04/100*35.89;
        break;                                              
      case 2750 : return  0.216e-04+center_down_up*0.216e-04/100*36.12;
        break;                                              
      case 2755 : return  0.211e-04+center_down_up*0.211e-04/100*36.35;
        break;                                              
      case 2760 : return  0.205e-04+center_down_up*0.205e-04/100*36.59;
        break;                                              
      case 2765 : return  0.200e-04+center_down_up*0.200e-04/100*36.82;
        break;                                              
      case 2770 : return  0.195e-04+center_down_up*0.195e-04/100*37.05;
        break;                                              
      case 2775 : return  0.190e-04+center_down_up*0.190e-04/100*37.29;
        break;                                              
      case 2780 : return  0.185e-04+center_down_up*0.185e-04/100*37.53;
        break;                                              
      case 2785 : return  0.181e-04+center_down_up*0.181e-04/100*37.76;
        break;                                              
      case 2790 : return  0.176e-04+center_down_up*0.176e-04/100*38.0;
        break;                                              
      case 2795 : return  0.172e-04+center_down_up*0.172e-04/100*38.24;
        break;                                              
      case 2800 : return  0.168e-04+center_down_up*0.168e-04/100*38.48;
        break;                                              
      case 2805 : return  0.163e-04+center_down_up*0.163e-04/100*38.72;
        break;                                              
      case 2810 : return  0.159e-04+center_down_up*0.159e-04/100*38.95;
        break;                                              
      case 2815 : return  0.155e-04+center_down_up*0.155e-04/100*39.19;
        break;                                              
      case 2820 : return  0.151e-04+center_down_up*0.151e-04/100*39.43;
        break;                                              
      case 2825 : return  0.148e-04+center_down_up*0.148e-04/100*39.66;
        break;                                              
      case 2830 : return  0.144e-04+center_down_up*0.144e-04/100*39.9;
        break;                                              
      case 2835 : return  0.140e-04+center_down_up*0.140e-04/100*40.14;
        break;                                              
      case 2840 : return  0.137e-04+center_down_up*0.137e-04/100*40.38;
        break;                                              
      case 2845 : return  0.133e-04+center_down_up*0.133e-04/100*40.62;
        break;                                              
      case 2850 : return  0.130e-04+center_down_up*0.130e-04/100*40.86;
        break;                                              
      case 2855 : return  0.127e-04+center_down_up*0.127e-04/100*41.1;
        break;                                              
      case 2860 : return  0.124e-04+center_down_up*0.124e-04/100*41.34;
        break;                                              
      case 2865 : return  0.121e-04+center_down_up*0.121e-04/100*41.59;
        break;                                              
      case 2870 : return  0.118e-04+center_down_up*0.118e-04/100*41.83;
        break;                                              
      case 2875 : return  0.115e-04+center_down_up*0.115e-04/100*42.07;
        break;                                              
      case 2880 : return  0.112e-04+center_down_up*0.112e-04/100*42.32;
        break;                                              
      case 2885 : return  0.109e-04+center_down_up*0.109e-04/100*42.56;
        break;                                              
      case 2890 : return  0.106e-04+center_down_up*0.106e-04/100*42.81;
        break;                                              
      case 2895 : return  0.104e-04+center_down_up*0.104e-04/100*43.05;
        break;                                              
      case 2900 : return  0.101e-04+center_down_up*0.101e-04/100*43.3;
        break;                                              
      case 2905 : return  0.986e-05+center_down_up*0.986e-05/100*43.55;
        break;                                              
      case 2910 : return  0.961e-05+center_down_up*0.961e-05/100*43.79;
        break;                                              
      case 2915 : return  0.937e-05+center_down_up*0.937e-05/100*44.04;
        break;                                              
      case 2920 : return  0.914e-05+center_down_up*0.914e-05/100*44.29;
        break;                                              
      case 2925 : return  0.891e-05+center_down_up*0.891e-05/100*44.54;
        break;                                              
      case 2930 : return  0.869e-05+center_down_up*0.869e-05/100*44.79;
        break;                                              
      case 2935 : return  0.848e-05+center_down_up*0.848e-05/100*45.04;
        break;                                              
      case 2940 : return  0.827e-05+center_down_up*0.827e-05/100*45.29;
        break;                                              
      case 2945 : return  0.806e-05+center_down_up*0.806e-05/100*45.54;
        break;                                              
      case 2950 : return  0.786e-05+center_down_up*0.786e-05/100*45.8;
        break;                                              
      case 2955 : return  0.767e-05+center_down_up*0.767e-05/100*46.05;
        break;                                              
      case 2960 : return  0.748e-05+center_down_up*0.748e-05/100*46.3;
        break;                                              
      case 2965 : return  0.729e-05+center_down_up*0.729e-05/100*46.56;
        break;                                              
      case 2970 : return  0.711e-05+center_down_up*0.711e-05/100*46.81;
        break;                                              
      case 2975 : return  0.694e-05+center_down_up*0.694e-05/100*47.07;
        break;                                              
      case 2980 : return  0.677e-05+center_down_up*0.677e-05/100*47.32;
        break;                                              
      case 2985 : return  0.660e-05+center_down_up*0.660e-05/100*47.58;
        break;                                              
      case 2990 : return  0.644e-05+center_down_up*0.644e-05/100*47.84;
        break;                                              
      case 2995 : return  0.628e-05+center_down_up*0.628e-05/100*48.09;
        break;                                              
      case 3000 : return  0.612e-05+center_down_up*0.612e-05/100*48.35;
        break;
      default : return 0;
    }
  }
  if (SignalScenario==2 || SignalScenario==5) {
    //TChiNG xsec is the sum of wino like n2c1 + c1c1
    //Might "add" higgsino like xsec later
    double returnvalue=0;
    switch (m_primary) {
      //xsec_wino_n2c1
      case 100 : returnvalue+= 22670.1+center_down_up*973.967;
        break;
      case 125 : returnvalue+= 10034.8+center_down_up*457.604;
        break;
      case 150 : returnvalue+= 5180.86+center_down_up*253.223;
        break;
      case 175 : returnvalue+= 2953.28+center_down_up*154.386;
        break;
      case 200 : returnvalue+= 1807.39+center_down_up*101.316;
        break;
      case 225 : returnvalue+= 1165.09+center_down_up*68.8042;
        break;
      case 250 : returnvalue+= 782.487+center_down_up*48.7463;
        break;
      case 275 : returnvalue+= 543.03 +center_down_up*35.4083;
        break;
      case 300 : returnvalue+= 386.936+center_down_up*26.3602;
        break;
      case 325 : returnvalue+= 281.911+center_down_up*20.0201;
        break;
      case 350 : returnvalue+= 209.439+center_down_up*15.4539;
        break;
      case 375 : returnvalue+= 158.06 +center_down_up*12.0956;
        break;
      case 400 : returnvalue+= 121.013+center_down_up*9.61659;
        break;
      case 425 : returnvalue+= 93.771 +center_down_up*7.73547;
        break;
      case 450 : returnvalue+= 73.4361+center_down_up*6.2389;
        break;
      case 475 : returnvalue+= 58.0811+center_down_up*5.05005;
        break;
      case 500 : returnvalue+= 46.3533+center_down_up*4.16461;
        break;
      case 525 : returnvalue+= 37.2636+center_down_up*3.46763;
        break;
      case 550 : returnvalue+= 30.1656+center_down_up*2.88065;
        break;
      case 575 : returnvalue+= 24.5798+center_down_up*2.40183;
        break;
      case 600 : returnvalue+= 20.1372+center_down_up*2.04438;
        break;
      case 625 : returnvalue+= 16.5706+center_down_up*1.70195;
        break;
      case 650 : returnvalue+= 13.7303+center_down_up*1.43519;
        break;
      case 675 : returnvalue+= 11.3975+center_down_up*1.21937;
        break;
      case 700 : returnvalue+= 9.51032+center_down_up*1.04092;
        break;
      case 725 : returnvalue+= 7.9595 +center_down_up*0.885243;
        break;
      case 750 : returnvalue+= 6.69356+center_down_up*0.769988;
        break;
      case 775 : returnvalue+= 5.63562+center_down_up*0.654544;
        break;
      case 800 : returnvalue+= 4.75843+center_down_up*0.564061;
        break;
      case 825 : returnvalue+= 4.02646+center_down_up*0.478362;
        break;
      case 850 : returnvalue+= 3.42026+center_down_up*0.412315;
        break;
      case 875 : returnvalue+= 2.90547+center_down_up*0.366257;
        break;
      case 900 : returnvalue+= 2.49667+center_down_up*0.314019;
        break;
      case 925 : returnvalue+= 2.12907+center_down_up*0.26801;
        break;
      case 950 : returnvalue+= 1.8164 +center_down_up*0.242682;
        break;
      case 975 : returnvalue+= 1.56893+center_down_up*0.217618;
        break;
      case 1000: returnvalue+= 1.34352+center_down_up*0.175604;
        break;
      case 1025: returnvalue+= 1.15949+center_down_up*0.155683;
        break;
      case 1050: returnvalue+= 0.997903 +center_down_up*0.133077;
        break;
      case 1075: returnvalue+= 0.86504  +center_down_up*0.117638;
        break;
      case 1100: returnvalue+= 0.740372 +center_down_up*0.107178;
        break;
      case 1125: returnvalue+= 0.647288 +center_down_up*0.0917503;
        break;
      case 1150: returnvalue+= 0.555594 +center_down_up*0.0828113;
        break;
      case 1175: returnvalue+= 0.486863 +center_down_up*0.0644736;
        break;
      case 1200: returnvalue+= 0.415851 +center_down_up*0.0579252;
        break;
      case 1225: returnvalue+= 0.362455 +center_down_up*0.0561888;
        break;
      case 1250: returnvalue+= 0.316975 +center_down_up*0.046491;
        break;
      case 1275: returnvalue+= 0.276522 +center_down_up*0.0430197;
        break;
      case 1300: returnvalue+= 0.240739 +center_down_up*0.0339561;
        break;
      case 1325: returnvalue+= 0.20999  +center_down_up*0.0288259;
        break;
      case 1350: returnvalue+= 0.185601 +center_down_up*0.0309793;
        break;
      case 1375: returnvalue+= 0.161343 +center_down_up*0.0231066;
        break;
      case 1400: returnvalue+= 0.131074 +center_down_up*0.0188826;
        break;
      case 1425: returnvalue+= 0.121045 +center_down_up*0.0184156;
        break;
      case 1450: returnvalue+= 0.110889 +center_down_up*0.0173553;
        break;
      case 1475: returnvalue+= 0.0906868+center_down_up*0.0153453;
        break;
      case 1500: returnvalue+= 0.0795585+center_down_up*0.0130098;
        break;
      case 1525: returnvalue+= 0.0694615+center_down_up*0.0116491;
        break;
      case 1550: returnvalue+= 0.0610387+center_down_up*0.0106867;
        break;
      case 1575: returnvalue+= 0.0531447+center_down_up*0.0100985;
        break;
      case 1600: returnvalue+= 0.0468796+center_down_up*0.00943991;
        break;
      case 1625: returnvalue+= 0.0413666+center_down_up*0.00870228;
        break;
      case 1650: returnvalue+= 0.0359383+center_down_up*0.0078127;
        break;
      case 1675: returnvalue+= 0.0313343+center_down_up*0.00724488;
        break;
      case 1700: returnvalue+= 0.0271773+center_down_up*0.00682548;
        break;
      case 1725: returnvalue+= 0.0239993+center_down_up*0.00575157;
        break;
      case 1750: returnvalue+= 0.0209773+center_down_up*0.00520821;
        break;
      case 1775: returnvalue+= 0.0183553+center_down_up*0.00474575;
        break;
      case 1800: returnvalue+= 0.0161098+center_down_up*0.00436762;
        break;
      case 1825: returnvalue+= 0.0139216+center_down_up*0.00392561;
        break;
      case 1850: returnvalue+= 0.0120539+center_down_up*0.00376256;
        break;
      case 1875: returnvalue+= 0.0104658+center_down_up*0.00347714;
        break;
      case 1900: returnvalue+= 0.00937288+center_down_up*0.00298646;
        break;
      case 1925: returnvalue+= 0.00814838+center_down_up*0.0027116;
        break;
      case 1950: returnvalue+= 0.00713734+center_down_up*0.00244379;
        break;
      case 1975: returnvalue+= 0.00621999+center_down_up*0.00223617;
        break;
      case 2000: returnvalue+= 0.00544778+center_down_up*0.00207163;
        break;
      default : return 0;
    }
    switch (m_primary) {
      //xsec_wino_c1c1
      case 100 :returnvalue+= 11611.9+center_down_up*518.613;
        break;
      case 125 :returnvalue+= 5090.52+center_down_up*249.469;
        break;
      case 150 :returnvalue+= 2612.31+center_down_up*138.156;
        break;
      case 175 :returnvalue+= 1482.42+center_down_up*83.2672;
        break;
      case 200 :returnvalue+= 902.569+center_down_up*53.7411;
        break;
      case 225 :returnvalue+= 579.564+center_down_up*36.0699;
        break;
      case 250 :returnvalue+= 387.534+center_down_up*25.3131;
        break;
      case 275 :returnvalue+= 267.786+center_down_up*18.2886;
        break;
      case 300 :returnvalue+= 190.159+center_down_up*13.4438;
        break;
      case 325 :returnvalue+= 138.086+center_down_up*10.1835;
        break;
      case 350 :returnvalue+= 102.199+center_down_up*7.75261;
        break;
      case 375 :returnvalue+= 76.8342+center_down_up*6.02606;
        break;
      case 400 :returnvalue+= 58.6311+center_down_up*4.7276;
        break;
      case 425 :returnvalue+= 45.2189+center_down_up*3.71547;
        break;
      case 450 :returnvalue+= 35.3143+center_down_up*2.97283;
        break;
      case 475 :returnvalue+= 27.8342+center_down_up*2.41224;
        break;
      case 500 :returnvalue+= 22.1265+center_down_up*1.94904;
        break;
      case 525 :returnvalue+= 17.7394+center_down_up*1.5992;
        break;
      case 550 :returnvalue+= 14.3134+center_down_up*1.32368;
        break;
      case 575 :returnvalue+= 11.6266+center_down_up*1.09669;
        break;
      case 600 :returnvalue+= 9.49913+center_down_up*0.912324;
        break;
      case 625 :returnvalue+= 7.80081+center_down_up*0.768988;
        break;
      case 650 :returnvalue+= 6.43244+center_down_up*0.638889;
        break;
      case 675 :returnvalue+= 5.33642+center_down_up*0.541519;
        break;
      case 700 :returnvalue+= 4.4387 +center_down_up*0.457123;
        break;
      case 725 :returnvalue+= 3.70675+center_down_up*0.385799;
        break;
      case 750 :returnvalue+= 3.10861+center_down_up*0.330353;
        break;
      case 775 :returnvalue+= 2.61656+center_down_up*0.283139;
        break;
      case 800 :returnvalue+= 2.21197+center_down_up*0.245196;
        break;
      case 825 :returnvalue+= 1.86142+center_down_up*0.201762;
        break;
      case 850 :returnvalue+= 1.58356+center_down_up*0.177806;
        break;
      case 875 :returnvalue+= 1.34699+center_down_up*0.150075;
        break;
      case 900 :returnvalue+= 1.15301+center_down_up*0.135822;
        break;
      case 925 :returnvalue+= 0.981406+center_down_up*0.114539;
        break;
      case 950 :returnvalue+= 0.842779+center_down_up*0.102086;
        break;
      case 975 :returnvalue+= 0.713432+center_down_up*0.0779702;
        break;
      case 1000:returnvalue+= 0.621866+center_down_up*0.0771005;
        break;
      case 1025:returnvalue+= 0.535563+center_down_up*0.0667594;
        break;
      case 1050:returnvalue+= 0.458716+center_down_up*0.0569349;
        break;
      case 1075:returnvalue+= 0.398794+center_down_up*0.0506191;
        break;
      case 1100:returnvalue+= 0.342626+center_down_up*0.0427672;
        break;
      case 1125:returnvalue+= 0.301119+center_down_up*0.0414674;
        break;
      case 1150:returnvalue+= 0.262408+center_down_up*0.0373521;
        break;
      case 1175:returnvalue+= 0.224723+center_down_up*0.0301438;
        break;
      case 1200:returnvalue+= 0.196044+center_down_up*0.0264135;
        break;
      case 1225:returnvalue+= 0.168114+center_down_up*0.021483;
        break;
      case 1250:returnvalue+= 0.148219+center_down_up*0.0198313;
        break;
      case 1275:returnvalue+= 0.128682+center_down_up*0.0173508;
        break;
      case 1300:returnvalue+= 0.115645+center_down_up*0.018756;
        break;
      case 1325:returnvalue+= 0.0987141+center_down_up*0.014292;
        break;
      case 1350:returnvalue+= 0.0881654+center_down_up*0.0135402;
        break;
      case 1375:returnvalue+= 0.0778987+center_down_up*0.0131703;
        break;
      case 1400:returnvalue+= 0.0686671+center_down_up*0.0114478;
        break;
      case 1425:returnvalue+= 0.0591995+center_down_up*0.00946571;
        break;
      case 1450:returnvalue+= 0.0505255+center_down_up*0.00707791;
        break;
      case 1475:returnvalue+= 0.0478698+center_down_up*0.00982729;
        break;
      case 1500:returnvalue+= 0.0396228+center_down_up*0.00627315;
        break;
      case 1525:returnvalue+= 0.0348558+center_down_up*0.00559845;
        break;
      case 1550:returnvalue+= 0.0307165+center_down_up*0.00495763;
        break;
      case 1575:returnvalue+= 0.0271112+center_down_up*0.00435237;
        break;
      case 1600:returnvalue+= 0.0239083+center_down_up*0.00394854;
        break;
      case 1625:returnvalue+= 0.0209953+center_down_up*0.00362692;
        break;
      case 1650:returnvalue+= 0.0186409+center_down_up*0.003244;
        break;
      case 1675:returnvalue+= 0.01647  +center_down_up* 0.00285616;
        break;
      case 1700:returnvalue+= 0.0144992+center_down_up*0.00249881;
        break;
      case 1725:returnvalue+= 0.0128156+center_down_up*0.00222519;
        break;
      case 1750:returnvalue+= 0.0113544+center_down_up*0.00198711;
        break;
      case 1775:returnvalue+= 0.0100029+center_down_up*0.00178698;
        break;
      case 1800:returnvalue+= 0.0088942+center_down_up*0.00155231;
        break;
      case 1825:returnvalue+= 0.00788156+center_down_up*0.00139556;
        break;
      case 1850:returnvalue+= 0.00695506+center_down_up*0.001247;
        break;
      case 1875:returnvalue+= 0.00614707+center_down_up*0.00114377;
        break;
      case 1900:returnvalue+= 0.00543469+center_down_up*0.00102872;
        break;
      case 1925:returnvalue+= 0.00485995+center_down_up*0.000924302;
        break;
      case 1950:returnvalue+= 0.00432007+center_down_up*0.000896908;
        break;
      case 1975:returnvalue+= 0.00371358+center_down_up*0.000851482;
        break;
      case 2000:returnvalue+= 0.00323064+center_down_up*0.000814089;
        break;
      default : return 0;
    }
    return returnvalue/1000;//xsec is in fb, need to return it in pb
  }
  return 0;
}

//Get precalculated total number of events for each grid point
unsigned long long get_total_events(std::pair<int,int> input, std::string y, int SignalScenario, bool goodpair=0) {
  //Since 2016 in UL is split to preVFP and postVFP year is changed to string.
  //But changing switch(year) - case structure to string would be lot of work, I use the following:
  //BUT in fastsim there's no split in 2016. I assume 2016 is 2016postVFP for fastsim
  //year=2016 for preVFP
  //year=20160 for postVFP
  //goodpair: in UL neutralino masses sometimes buggy, therefor we made a selection where only goodpair events are...
  //goodpair year = year+1000
  int year=(y.find("2016preVFP")!=std::string::npos) ? 2016 : (y.find("2016postVFP")!=std::string::npos) ? 20160 : (y.find("2017")!=std::string::npos) ? 2017 : (y.find("2018")!=std::string::npos) ? 2018 : 1;
  if (goodpair) year+=1000;
  int a=input.first, b=input.second;
  if (SignalScenario==1 || SignalScenario==4) {
    switch (year) {
      case 20160 :
    if (a==800) {
      switch (b) {
        case 127 : return 34080;
        case 200 : return 61098;
        case 300 : return 67294;
        case 400 : return 96834;
        case 500 : return 110713;
        case 600 : return 145835;
        case 700 : return 150227;
        case 790 : return 115002;
    }
  }
    if (a==900) {
      switch (b) {
        case 127 : return 29996;
        case 200 : return 65473;
        case 300 : return 65935;
        case 400 : return 83497;
        case 500 : return 89728;
        case 600 : return 116079;
        case 700 : return 148682;
        case 800 : return 171339;
        case 890 : return 170340;
    }
  }
    if (a==1000) {
      switch (b) {
        case 127 : return 28766;
        case 150 : return 31721;
        case 175 : return 36039;
        case 200 : return 67594;
        case 300 : return 74091;
        case 400 : return 85557;
        case 500 : return 109254;
        case 600 : return 128891;
        case 700 : return 118753;
        case 750 : return 124175;
        case 800 : return 134991;
        case 850 : return 158323;
        case 900 : return 157347;
        case 950 : return 148038;
        case 975 : return 132173;
        case 990 : return 141622;
    }
  }
    if (a==1050) {
      switch (b) {
        case 127 : return 31489;
        case 150 : return 30700;
        case 175 : return 36038;
        case 200 : return 69903;
        case 300 : return 89680;
        case 400 : return 92885;
        case 500 : return 119632;
        case 600 : return 133064;
        case 700 : return 134213;
        case 750 : return 126263;
        case 800 : return 141090;
        case 850 : return 155935;
        case 900 : return 166346;
        case 950 : return 172807;
        case 1000 : return 191616;
        case 1025 : return 173177;
        case 1040 : return 111304;
    }
  }
    if (a==1100) {
      switch (b) {
        case 127 : return 31606;
        case 150 : return 33284;
        case 175 : return 43272;
        case 200 : return 50375;
        case 300 : return 63217;
        case 400 : return 82676;
        case 500 : return 97704;
        case 600 : return 119179;
        case 700 : return 126629;
        case 800 : return 120367;
        case 850 : return 137141;
        case 900 : return 114043;
        case 950 : return 153558;
        case 1000 : return 174331;
        case 1050 : return 167253;
        case 1075 : return 122150;
        case 1090 : return 108732;
    }
  }
    if (a==1150) {
      switch (b) {
        case 127 : return 18528;
        case 150 : return 24897;
        case 175 : return 30038;
        case 200 : return 45780;
        case 300 : return 62604;
        case 400 : return 54891;
        case 500 : return 63209;
        case 600 : return 98016;
        case 700 : return 86600;
        case 800 : return 92729;
        case 850 : return 90710;
        case 900 : return 109381;
        case 950 : return 113334;
        case 1000 : return 120849;
        case 1050 : return 117169;
        case 1100 : return 113752;
        case 1125 : return 98122;
        case 1140 : return 73014;
    }
  }
    if (a==1200) {
      switch (b) {
        case 127 : return 7875;
        case 150 : return 16715;
        case 175 : return 14346;
        case 200 : return 28295;
        case 300 : return 37417;
        case 400 : return 37046;
        case 500 : return 42464;
        case 600 : return 56480;
        case 700 : return 58740;
        case 800 : return 66581;
        case 900 : return 64010;
        case 950 : return 61379;
        case 1000 : return 84522;
        case 1050 : return 107475;
        case 1100 : return 89367;
        case 1150 : return 82002;
        case 1175 : return 64649;
        case 1190 : return 46680;
    }
  }
    if (a==1250) {
      switch (b) {
        case 127 : return 7718;
        case 150 : return 14107;
        case 175 : return 13292;
        case 200 : return 20461;
        case 300 : return 25139;
        case 400 : return 36119;
        case 500 : return 35097;
        case 600 : return 49137;
        case 700 : return 53489;
        case 800 : return 54314;
        case 900 : return 45852;
        case 950 : return 52928;
        case 1000 : return 59059;
        case 1050 : return 64206;
        case 1100 : return 61517;
        case 1150 : return 70339;
        case 1200 : return 64132;
        case 1225 : return 57583;
        case 1240 : return 52334;
    }
  }
    if (a==1300) {
      switch (b) {
        case 127 : return 5217;
        case 150 : return 7447;
        case 175 : return 11021;
        case 200 : return 14390;
        case 300 : return 22258;
        case 400 : return 28232;
        case 500 : return 35020;
        case 600 : return 35404;
        case 700 : return 35465;
        case 800 : return 40286;
        case 900 : return 42383;
        case 1000 : return 47343;
        case 1050 : return 41346;
        case 1100 : return 42063;
        case 1150 : return 49807;
        case 1200 : return 44725;
        case 1250 : return 46603;
        case 1275 : return 30705;
        case 1290 : return 22686;
    }
  }
    if (a==1350) {
      switch (b) {
        case 127 : return 2647;
        case 150 : return 10061;
        case 175 : return 11600;
        case 200 : return 15597;
        case 300 : return 18641;
        case 400 : return 16580;
        case 500 : return 31505;
        case 600 : return 38272;
        case 700 : return 34286;
        case 800 : return 48708;
        case 900 : return 37447;
        case 1000 : return 46477;
        case 1050 : return 47716;
        case 1100 : return 51617;
        case 1150 : return 47986;
        case 1200 : return 42110;
        case 1250 : return 48834;
        case 1300 : return 56953;
        case 1325 : return 43627;
        case 1340 : return 27718;
    }
  }
    if (a==1400) {
      switch (b) {
        case 127 : return 7907;
        case 150 : return 8797;
        case 175 : return 3889;
        case 200 : return 13813;
        case 300 : return 15385;
        case 400 : return 29518;
        case 500 : return 25063;
        case 600 : return 33359;
        case 700 : return 30465;
        case 800 : return 42757;
        case 900 : return 47058;
        case 1000 : return 50704;
        case 1100 : return 53946;
        case 1150 : return 49483;
        case 1200 : return 37228;
        case 1250 : return 40209;
        case 1300 : return 37880;
        case 1350 : return 51055;
        case 1375 : return 29752;
        case 1390 : return 25927;
    }
  }
    if (a==1450) {
      switch (b) {
        case 127 : return 6193;
        case 150 : return 9455;
        case 175 : return 11209;
        case 200 : return 13415;
        case 300 : return 20287;
        case 400 : return 29681;
        case 500 : return 22641;
        case 600 : return 31291;
        case 700 : return 36398;
        case 800 : return 37166;
        case 900 : return 43679;
        case 1000 : return 51206;
        case 1100 : return 43240;
        case 1150 : return 51081;
        case 1200 : return 46603;
        case 1250 : return 41601;
        case 1300 : return 43797;
        case 1350 : return 49108;
        case 1400 : return 33804;
        case 1425 : return 28388;
        case 1440 : return 41131;
    }
  }
    if (a==1500) {
      switch (b) {
        case 127 : return 5319;
        case 150 : return 8394;
        case 175 : return 11967;
        case 200 : return 19086;
        case 300 : return 16992;
        case 400 : return 24344;
        case 500 : return 22268;
        case 600 : return 28977;
        case 700 : return 28793;
        case 800 : return 36313;
        case 900 : return 38875;
        case 1000 : return 46844;
        case 1100 : return 50419;
        case 1200 : return 45074;
        case 1250 : return 34679;
        case 1300 : return 42327;
        case 1350 : return 40569;
        case 1400 : return 45210;
        case 1450 : return 38695;
        case 1475 : return 34648;
        case 1490 : return 32242;
    }
  }
    if (a==1550) {
      switch (b) {
        case 127 : return 4475;
        case 150 : return 3584;
        case 175 : return 8672;
        case 200 : return 12144;
        case 300 : return 13326;
        case 400 : return 17502;
        case 500 : return 32068;
        case 600 : return 25291;
        case 700 : return 38391;
        case 800 : return 39481;
        case 900 : return 42176;
        case 1000 : return 49888;
        case 1100 : return 52816;
        case 1200 : return 50214;
        case 1250 : return 42329;
        case 1300 : return 45255;
        case 1350 : return 56189;
        case 1400 : return 42145;
        case 1450 : return 42751;
        case 1500 : return 50345;
        case 1525 : return 40798;
        case 1540 : return 33722;
    }
  }
    if (a==1600) {
      switch (b) {
        case 127 : return 10850;
        case 150 : return 6471;
        case 175 : return 8229;
        case 200 : return 16133;
        case 300 : return 21640;
        case 400 : return 20757;
        case 500 : return 21694;
        case 600 : return 27277;
        case 700 : return 32721;
        case 800 : return 30533;
        case 900 : return 40730;
        case 1000 : return 53515;
        case 1100 : return 46172;
        case 1200 : return 53947;
        case 1300 : return 58067;
        case 1350 : return 46597;
        case 1400 : return 49840;
        case 1450 : return 54921;
        case 1500 : return 46621;
        case 1550 : return 43034;
        case 1575 : return 50492;
        case 1590 : return 29713;
    }
  }
    if (a==1650) {
      switch (b) {
        case 127 : return 4583;
        case 150 : return 11390;
        case 175 : return 9795;
        case 200 : return 20990;
        case 300 : return 22705;
        case 400 : return 14657;
        case 500 : return 23666;
        case 600 : return 35273;
        case 700 : return 31830;
        case 800 : return 38836;
        case 900 : return 49237;
        case 1000 : return 51740;
        case 1100 : return 70298;
        case 1200 : return 50418;
        case 1300 : return 54038;
        case 1350 : return 36717;
        case 1400 : return 43587;
        case 1450 : return 47452;
        case 1500 : return 44789;
        case 1550 : return 55516;
        case 1600 : return 36205;
        case 1625 : return 33014;
        case 1640 : return 36542;
    }
  }
    if (a==1700) {
      switch (b) {
        case 127 : return 2736;
        case 150 : return 7457;
        case 175 : return 9505;
        case 200 : return 19837;
        case 300 : return 16804;
        case 400 : return 19954;
        case 500 : return 23919;
        case 600 : return 28072;
        case 700 : return 24445;
        case 800 : return 37490;
        case 900 : return 40719;
        case 1000 : return 50503;
        case 1100 : return 46023;
        case 1200 : return 54024;
        case 1300 : return 49900;
        case 1400 : return 40121;
        case 1450 : return 32060;
        case 1500 : return 35055;
        case 1550 : return 47448;
        case 1600 : return 45869;
        case 1650 : return 52863;
        case 1675 : return 38893;
        case 1690 : return 44795;
    }
  }
    if (a==1750) {
      switch (b) {
        case 127 : return 2740;
        case 150 : return 11401;
        case 175 : return 8496;
        case 200 : return 12346;
        case 300 : return 19832;
        case 400 : return 28409;
        case 500 : return 20759;
        case 600 : return 28714;
        case 700 : return 34799;
        case 800 : return 41236;
        case 900 : return 40772;
        case 1000 : return 54668;
        case 1100 : return 46101;
        case 1200 : return 50310;
        case 1300 : return 54213;
        case 1400 : return 42706;
        case 1450 : return 43766;
        case 1500 : return 34709;
        case 1550 : return 40104;
        case 1600 : return 52253;
        case 1650 : return 43924;
        case 1700 : return 42692;
        case 1725 : return 45547;
        case 1740 : return 31734;
    }
  }
    if (a==1800) {
      switch (b) {
        case 127 : return 7458;
        case 150 : return 5978;
        case 175 : return 12530;
        case 200 : return 17328;
        case 300 : return 22333;
        case 400 : return 15632;
        case 500 : return 22411;
        case 600 : return 26141;
        case 700 : return 32665;
        case 800 : return 35906;
        case 900 : return 47187;
        case 1000 : return 44282;
        case 1100 : return 44695;
        case 1200 : return 53207;
        case 1300 : return 53394;
        case 1400 : return 54103;
        case 1500 : return 46789;
        case 1550 : return 44518;
        case 1600 : return 43254;
        case 1650 : return 35837;
        case 1700 : return 40576;
        case 1750 : return 38794;
        case 1775 : return 38475;
        case 1790 : return 33316;
    }
  }
    if (a==1850) {
      switch (b) {
        case 127 : return 8452;
        case 150 : return 8661;
        case 175 : return 14076;
        case 200 : return 15923;
        case 300 : return 12376;
        case 400 : return 13462;
        case 500 : return 18971;
        case 600 : return 20036;
        case 700 : return 29894;
        case 800 : return 27743;
        case 900 : return 28141;
        case 1000 : return 46998;
        case 1100 : return 47999;
        case 1200 : return 49336;
        case 1300 : return 48891;
        case 1400 : return 51042;
        case 1500 : return 40973;
        case 1550 : return 45642;
        case 1600 : return 34183;
        case 1650 : return 49700;
        case 1700 : return 36095;
        case 1750 : return 46115;
        case 1800 : return 40887;
        case 1825 : return 42964;
        case 1840 : return 32454;
    }
  }
    if (a==1900) {
      switch (b) {
        case 127 : return 4681;
        case 150 : return 5210;
        case 175 : return 9359;
        case 200 : return 16447;
        case 300 : return 18092;
        case 400 : return 24311;
        case 500 : return 23753;
        case 600 : return 26026;
        case 700 : return 36863;
        case 800 : return 32547;
        case 900 : return 35549;
        case 1000 : return 51502;
        case 1100 : return 42915;
        case 1200 : return 49395;
        case 1300 : return 59027;
        case 1400 : return 56681;
        case 1500 : return 53002;
        case 1600 : return 44440;
        case 1650 : return 37050;
        case 1700 : return 43055;
        case 1750 : return 34219;
        case 1800 : return 40306;
        case 1850 : return 38309;
        case 1875 : return 31279;
        case 1890 : return 35481;
    }
  }
    if (a==1950) {
      switch (b) {
        case 127 : return 5714;
        case 150 : return 7952;
        case 175 : return 9946;
        case 200 : return 13369;
        case 300 : return 17485;
        case 400 : return 21279;
        case 500 : return 12130;
        case 600 : return 29117;
        case 700 : return 27651;
        case 800 : return 27836;
        case 900 : return 44759;
        case 1000 : return 39145;
        case 1100 : return 52353;
        case 1200 : return 59025;
        case 1300 : return 42203;
        case 1400 : return 56555;
        case 1500 : return 47557;
        case 1600 : return 50381;
        case 1650 : return 44027;
        case 1700 : return 45841;
        case 1750 : return 48717;
        case 1800 : return 44235;
        case 1850 : return 38238;
        case 1900 : return 51201;
        case 1925 : return 36071;
        case 1940 : return 36573;
    }
  }
    if (a==2000) {
      switch (b) {
        case 127 : return 4829;
        case 150 : return 4035;
        case 175 : return 5115;
        case 200 : return 8145;
        case 300 : return 6297;
        case 400 : return 5246;
        case 500 : return 15704;
        case 600 : return 15298;
        case 700 : return 14758;
        case 800 : return 16525;
        case 900 : return 19819;
        case 1000 : return 26823;
        case 1100 : return 19683;
        case 1200 : return 22237;
        case 1300 : return 18341;
        case 1400 : return 21455;
        case 1500 : return 23445;
        case 1600 : return 19583;
        case 1700 : return 22078;
        case 1750 : return 31419;
        case 1800 : return 22971;
        case 1850 : return 22404;
        case 1900 : return 23529;
        case 1950 : return 23681;
        case 1975 : return 14795;
        case 1990 : return 14510;
    }
  }
    if (a==2050) {
      switch (b) {
        case 127 : return 1984;
        case 150 : return 5904;
        case 175 : return 8955;
        case 200 : return 6018;
        case 300 : return 8946;
        case 400 : return 12764;
        case 500 : return 10712;
        case 600 : return 8433;
        case 700 : return 21345;
        case 800 : return 18759;
        case 900 : return 19320;
        case 1000 : return 23724;
        case 1100 : return 26279;
        case 1200 : return 28657;
        case 1300 : return 24029;
        case 1400 : return 28655;
        case 1500 : return 23145;
        case 1600 : return 33337;
        case 1700 : return 27834;
        case 1750 : return 25647;
        case 1800 : return 26448;
        case 1850 : return 23178;
        case 1900 : return 21794;
        case 1950 : return 22881;
        case 2000 : return 25755;
        case 2025 : return 18879;
        case 2040 : return 12847;
    }
  }
    if (a==2100) {
      switch (b) {
        case 127 : return 993;
        case 150 : return 1181;
        case 175 : return 8400;
        case 200 : return 6215;
        case 300 : return 9250;
        case 400 : return 8644;
        case 500 : return 11862;
        case 600 : return 16655;
        case 700 : return 11093;
        case 800 : return 20566;
        case 900 : return 22775;
        case 1000 : return 23475;
        case 1100 : return 24619;
        case 1200 : return 24126;
        case 1300 : return 27449;
        case 1400 : return 27360;
        case 1500 : return 28752;
        case 1600 : return 16407;
        case 1700 : return 26245;
        case 1800 : return 23818;
        case 1850 : return 18193;
        case 1900 : return 16068;
        case 1950 : return 24256;
        case 2000 : return 21321;
        case 2050 : return 20422;
        case 2075 : return 17386;
        case 2090 : return 17718;
    }
  }
    if (a==2150) {
      switch (b) {
        case 127 : return 1955;
        case 150 : return 2111;
        case 175 : return 5441;
        case 200 : return 4220;
        case 300 : return 4312;
        case 400 : return 3536;
        case 500 : return 8963;
        case 600 : return 11146;
        case 700 : return 11447;
        case 800 : return 13562;
        case 900 : return 16766;
        case 1000 : return 19836;
        case 1100 : return 23240;
        case 1200 : return 27206;
        case 1300 : return 19684;
        case 1400 : return 23763;
        case 1500 : return 20999;
        case 1600 : return 24457;
        case 1700 : return 27966;
        case 1800 : return 16200;
        case 1850 : return 20950;
        case 1900 : return 26261;
        case 1950 : return 16840;
        case 2000 : return 14473;
        case 2050 : return 26663;
        case 2100 : return 15042;
        case 2125 : return 22211;
        case 2140 : return 16103;
    }
  }
    if (a==2200) {
      switch (b) {
        case 127 : return 3024;
        case 150 : return 6274;
        case 175 : return 7515;
        case 200 : return 10920;
        case 300 : return 9202;
        case 400 : return 14011;
        case 500 : return 16355;
        case 600 : return 14279;
        case 700 : return 18144;
        case 800 : return 12407;
        case 900 : return 18742;
        case 1000 : return 18991;
        case 1100 : return 24576;
        case 1200 : return 23595;
        case 1300 : return 25743;
        case 1400 : return 26864;
        case 1500 : return 27290;
        case 1600 : return 29559;
        case 1700 : return 22910;
        case 1800 : return 32274;
        case 1900 : return 25207;
        case 1950 : return 25135;
        case 2000 : return 22671;
        case 2050 : return 20458;
        case 2100 : return 22903;
        case 2150 : return 20179;
        case 2175 : return 20898;
        case 2190 : return 21361;
    }
  }
    if (a==2250) {
      switch (b) {
        case 127 : return 1036;
        case 150 : return 8444;
        case 175 : return 1004;
        case 200 : return 9951;
        case 300 : return 5506;
        case 400 : return 10462;
        case 500 : return 12267;
        case 600 : return 21391;
        case 700 : return 17966;
        case 800 : return 23041;
        case 900 : return 24277;
        case 1000 : return 15946;
        case 1100 : return 18644;
        case 1200 : return 25420;
        case 1300 : return 23981;
        case 1400 : return 19340;
        case 1500 : return 26077;
        case 1600 : return 25055;
        case 1700 : return 25842;
        case 1800 : return 24533;
        case 1900 : return 22661;
        case 1950 : return 23312;
        case 2000 : return 23213;
        case 2050 : return 21188;
        case 2100 : return 19569;
        case 2150 : return 15430;
        case 2200 : return 18506;
        case 2225 : return 17699;
        case 2240 : return 17639;
    }
  }
    if (a==2300) {
      switch (b) {
        case 127 : return 3227;
        case 150 : return 3236;
        case 175 : return 7966;
        case 200 : return 7950;
        case 300 : return 6073;
        case 400 : return 8437;
        case 500 : return 9240;
        case 600 : return 13230;
        case 700 : return 15167;
        case 800 : return 18318;
        case 900 : return 13554;
        case 1000 : return 20173;
        case 1100 : return 16505;
        case 1200 : return 29843;
        case 1300 : return 31984;
        case 1400 : return 22099;
        case 1500 : return 17649;
        case 1600 : return 36578;
        case 1700 : return 26597;
        case 1800 : return 23266;
        case 1900 : return 21436;
        case 2000 : return 23537;
        case 2050 : return 26283;
        case 2100 : return 20517;
        case 2150 : return 25268;
        case 2200 : return 15689;
        case 2250 : return 18127;
        case 2275 : return 17698;
        case 2290 : return 12617;
    }
  }
    if (a==2350) {
      switch (b) {
        case 127 : return 3094;
        case 150 : return 6568;
        case 175 : return 5704;
        case 200 : return 6488;
        case 300 : return 9144;
        case 400 : return 9543;
        case 500 : return 10772;
        case 600 : return 7692;
        case 700 : return 13174;
        case 800 : return 15600;
        case 900 : return 19878;
        case 1000 : return 21303;
        case 1100 : return 15774;
        case 1200 : return 25091;
        case 1300 : return 19413;
        case 1400 : return 17522;
        case 1500 : return 23132;
        case 1600 : return 24576;
        case 1700 : return 20836;
        case 1800 : return 28133;
        case 1900 : return 28006;
        case 2000 : return 23401;
        case 2050 : return 18466;
        case 2100 : return 11587;
        case 2150 : return 17525;
        case 2200 : return 19149;
        case 2250 : return 17697;
        case 2300 : return 14263;
        case 2325 : return 20739;
        case 2340 : return 23278;
    }
  }
    if (a==2400) {
      switch (b) {
        case 127 : return 4292;
        case 150 : return 3749;
        case 175 : return 2213;
        case 200 : return 10310;
        case 300 : return 9345;
        case 400 : return 4951;
        case 500 : return 12627;
        case 600 : return 15505;
        case 700 : return 17180;
        case 800 : return 11678;
        case 900 : return 9700;
        case 1000 : return 16803;
        case 1100 : return 20023;
        case 1200 : return 27497;
        case 1300 : return 20928;
        case 1400 : return 20293;
        case 1500 : return 24269;
        case 1600 : return 18014;
        case 1700 : return 23569;
        case 1800 : return 24792;
        case 1900 : return 23255;
        case 2000 : return 30651;
        case 2100 : return 21906;
        case 2150 : return 22341;
        case 2200 : return 12313;
        case 2250 : return 20222;
        case 2300 : return 24036;
        case 2350 : return 18151;
        case 2375 : return 16396;
        case 2390 : return 25732;
    }
  }
    if (a==2450) {
      switch (b) {
        case 127 : return 2176;
        case 150 : return 2227;
        case 175 : return 4450;
        case 200 : return 7982;
        case 300 : return 12271;
        case 400 : return 16206;
        case 500 : return 11592;
        case 600 : return 8718;
        case 700 : return 15932;
        case 800 : return 9509;
        case 900 : return 9956;
        case 1000 : return 9844;
        case 1100 : return 23366;
        case 1200 : return 31594;
        case 1300 : return 27511;
        case 1400 : return 20311;
        case 1500 : return 19337;
        case 1600 : return 24089;
        case 1700 : return 25444;
        case 1800 : return 32367;
        case 1900 : return 17797;
        case 2000 : return 25460;
        case 2100 : return 18036;
        case 2150 : return 15482;
        case 2200 : return 24342;
        case 2250 : return 17663;
        case 2300 : return 22759;
        case 2350 : return 21794;
        case 2400 : return 19374;
        case 2425 : return 15335;
        case 2440 : return 22056;
    }
  }
    if (a==2500) {
      switch (b) {
        case 127 : return 4415;
        case 150 : return 4639;
        case 175 : return 6292;
        case 200 : return 7339;
        case 300 : return 9295;
        case 400 : return 4269;
        case 500 : return 11489;
        case 600 : return 13174;
        case 700 : return 14330;
        case 800 : return 13845;
        case 900 : return 22770;
        case 1000 : return 17923;
        case 1100 : return 19867;
        case 1200 : return 28046;
        case 1300 : return 13484;
        case 1400 : return 14325;
        case 1500 : return 23163;
        case 1600 : return 24466;
        case 1700 : return 28407;
        case 1800 : return 22456;
        case 1900 : return 15598;
        case 2000 : return 18936;
        case 2100 : return 28663;
        case 2200 : return 17172;
        case 2250 : return 15510;
        case 2300 : return 25215;
        case 2350 : return 23320;
        case 2400 : return 22824;
        case 2450 : return 19575;
        case 2475 : return 20646;
        case 2490 : return 16191;
    }
  }
    if (a==2550) {
      switch (b) {
        case 127 : return 4558;
        case 150 : return 5727;
        case 175 : return 7020;
        case 200 : return 7259;
        case 300 : return 6713;
        case 400 : return 8963;
        case 500 : return 11543;
        case 600 : return 15921;
        case 700 : return 13284;
        case 800 : return 9931;
        case 900 : return 16409;
        case 1000 : return 15062;
        case 1100 : return 18572;
        case 1200 : return 20060;
        case 1300 : return 22995;
        case 1400 : return 23509;
        case 1500 : return 23140;
        case 1600 : return 21267;
        case 1700 : return 24797;
        case 1800 : return 26373;
        case 1900 : return 32247;
        case 2000 : return 28460;
        case 2100 : return 34474;
        case 2200 : return 23276;
        case 2250 : return 21402;
        case 2300 : return 18690;
        case 2350 : return 15871;
        case 2400 : return 18003;
        case 2450 : return 23001;
        case 2500 : return 13531;
        case 2525 : return 26207;
        case 2540 : return 16814;
    }
  }
    if (a==2600) {
      switch (b) {
        case 127 : return 4622;
        case 150 : return 7938;
        case 175 : return 5848;
        case 200 : return 5479;
        case 300 : return 10073;
        case 400 : return 17682;
        case 500 : return 11854;
        case 600 : return 14671;
        case 700 : return 12541;
        case 800 : return 23075;
        case 900 : return 15653;
        case 1000 : return 19303;
        case 1100 : return 23147;
        case 1200 : return 21354;
        case 1300 : return 22549;
        case 1400 : return 13999;
        case 1500 : return 16960;
        case 1600 : return 22710;
        case 1700 : return 34993;
        case 1800 : return 29891;
        case 1900 : return 28262;
        case 2000 : return 26823;
        case 2100 : return 24767;
        case 2200 : return 14169;
        case 2300 : return 21473;
        case 2350 : return 22640;
        case 2400 : return 13435;
        case 2450 : return 16266;
        case 2500 : return 29202;
        case 2550 : return 12792;
        case 2575 : return 20726;
        case 2590 : return 17282;
    }
  }
    if (a==2650) {
      switch (b) {
        case 127 : return 0;
        case 150 : return 3392;
        case 175 : return 2520;
        case 200 : return 9780;
        case 300 : return 8724;
        case 400 : return 2771;
        case 500 : return 10585;
        case 600 : return 14438;
        case 700 : return 11856;
        case 800 : return 14361;
        case 900 : return 22472;
        case 1000 : return 19965;
        case 1100 : return 24585;
        case 1200 : return 26948;
        case 1300 : return 18963;
        case 1400 : return 21411;
        case 1500 : return 20875;
        case 1600 : return 24592;
        case 1700 : return 29719;
        case 1800 : return 20874;
        case 1900 : return 19175;
        case 2000 : return 17355;
        case 2100 : return 15699;
        case 2200 : return 22817;
        case 2300 : return 17089;
        case 2350 : return 20492;
        case 2400 : return 21797;
        case 2450 : return 14609;
        case 2500 : return 20103;
        case 2550 : return 14525;
        case 2600 : return 17388;
        case 2625 : return 20898;
        case 2640 : return 5961;
    }
  }
    if (a==2700) {
      switch (b) {
        case 127 : return 3636;
        case 150 : return 1435;
        case 175 : return 4193;
        case 200 : return 10038;
        case 300 : return 12737;
        case 400 : return 12711;
        case 500 : return 12384;
        case 600 : return 12795;
        case 700 : return 11599;
        case 800 : return 18274;
        case 900 : return 14383;
        case 1000 : return 24391;
        case 1100 : return 29283;
        case 1200 : return 17980;
        case 1300 : return 21304;
        case 1400 : return 16234;
        case 1500 : return 22880;
        case 1600 : return 20324;
        case 1700 : return 19834;
        case 1800 : return 26852;
        case 1900 : return 28872;
        case 2000 : return 23027;
        case 2100 : return 27455;
        case 2200 : return 25553;
        case 2300 : return 26689;
        case 2400 : return 20303;
        case 2450 : return 25731;
        case 2500 : return 20474;
        case 2550 : return 20999;
        case 2600 : return 22659;
        case 2650 : return 8396;
        case 2675 : return 14635;
        case 2690 : return 15496;
    }
  }
    if (a==2750) {
      switch (b) {
        case 127 : return 7239;
        case 150 : return 2411;
        case 175 : return 6125;
        case 200 : return 5525;
        case 300 : return 8280;
        case 400 : return 10474;
        case 500 : return 9110;
        case 600 : return 8795;
        case 700 : return 10984;
        case 800 : return 9456;
        case 900 : return 15159;
        case 1000 : return 18499;
        case 1100 : return 27251;
        case 1200 : return 17171;
        case 1300 : return 32892;
        case 1400 : return 29449;
        case 1500 : return 26531;
        case 1600 : return 23450;
        case 1700 : return 28002;
        case 1800 : return 24393;
        case 1900 : return 26236;
        case 2000 : return 27059;
        case 2100 : return 19264;
        case 2200 : return 28335;
        case 2300 : return 23231;
        case 2400 : return 15697;
        case 2450 : return 19445;
        case 2500 : return 19816;
        case 2550 : return 10238;
        case 2600 : return 25000;
        case 2650 : return 17644;
        case 2700 : return 11681;
        case 2725 : return 20980;
        case 2740 : return 10888;
    }
  }
    if (a==2800) {
      switch (b) {
        case 127 : return 1212;
        case 150 : return 2463;
        case 175 : return 7424;
        case 200 : return 6558;
        case 300 : return 10981;
        case 400 : return 8197;
        case 500 : return 12250;
        case 600 : return 14902;
        case 700 : return 15597;
        case 800 : return 26990;
        case 900 : return 21339;
        case 1000 : return 23540;
        case 1100 : return 26009;
        case 1200 : return 31551;
        case 1300 : return 19792;
        case 1400 : return 25907;
        case 1500 : return 26254;
        case 1600 : return 13608;
        case 1700 : return 23502;
        case 1800 : return 29097;
        case 1900 : return 17604;
        case 2000 : return 22692;
        case 2100 : return 25928;
        case 2200 : return 31077;
        case 2300 : return 25881;
        case 2400 : return 26104;
        case 2500 : return 23388;
        case 2550 : return 17516;
        case 2600 : return 15788;
        case 2650 : return 9193;
        case 2700 : return 18718;
        case 2750 : return 8249;
        case 2775 : return 12572;
        case 2790 : return 10992;
    }
  }
      break;
      case 2017 :
    if (a==800) {
      switch (b) {
        case 127 : return 25279;
        case 200 : return 44943;
        case 300 : return 56721;
        case 400 : return 80980;
        case 500 : return 101888;
        case 600 : return 112950;
        case 700 : return 138410;
        case 790 : return 113617;
    }
  }
    if (a==900) {
      switch (b) {
        case 127 : return 13676;
        case 200 : return 44527;
        case 300 : return 65105;
        case 400 : return 78158;
        case 500 : return 79012;
        case 600 : return 85523;
        case 700 : return 120052;
        case 800 : return 152618;
        case 890 : return 95958;
    }
  }
    if (a==1000) {
      switch (b) {
        case 127 : return 24468;
        case 150 : return 18530;
        case 175 : return 39385;
        case 200 : return 59883;
        case 300 : return 69208;
        case 400 : return 85237;
        case 500 : return 99825;
        case 600 : return 113910;
        case 700 : return 104054;
        case 750 : return 99750;
        case 800 : return 122298;
        case 850 : return 138189;
        case 900 : return 159395;
        case 950 : return 146031;
        case 975 : return 121406;
        case 990 : return 115436;
    }
  }
    if (a==1050) {
      switch (b) {
        case 127 : return 20914;
        case 150 : return 28303;
        case 175 : return 41434;
        case 200 : return 61793;
        case 300 : return 58919;
        case 400 : return 85215;
        case 500 : return 88479;
        case 600 : return 96504;
        case 700 : return 108368;
        case 750 : return 99961;
        case 800 : return 106398;
        case 850 : return 132467;
        case 900 : return 137593;
        case 950 : return 160402;
        case 1000 : return 161988;
        case 1025 : return 154051;
        case 1040 : return 103554;
    }
  }
    if (a==1100) {
      switch (b) {
        case 127 : return 30256;
        case 150 : return 18503;
        case 175 : return 30880;
        case 200 : return 40954;
        case 300 : return 64728;
        case 400 : return 77711;
        case 500 : return 81932;
        case 600 : return 88009;
        case 700 : return 108899;
        case 800 : return 118171;
        case 850 : return 117885;
        case 900 : return 133985;
        case 950 : return 134243;
        case 1000 : return 152274;
        case 1050 : return 140238;
        case 1075 : return 116604;
        case 1090 : return 84039;
    }
  }
    if (a==1150) {
      switch (b) {
        case 127 : return 10506;
        case 150 : return 15965;
        case 175 : return 25530;
        case 200 : return 40179;
        case 300 : return 37367;
        case 400 : return 57599;
        case 500 : return 56135;
        case 600 : return 58461;
        case 700 : return 68515;
        case 800 : return 82235;
        case 850 : return 68153;
        case 900 : return 88684;
        case 950 : return 79484;
        case 1000 : return 94150;
        case 1050 : return 115297;
        case 1100 : return 115699;
        case 1125 : return 103006;
        case 1140 : return 83965;
    }
  }
    if (a==1200) {
      switch (b) {
        case 127 : return 7034;
        case 150 : return 9351;
        case 175 : return 19198;
        case 200 : return 24069;
        case 300 : return 30262;
        case 400 : return 32474;
        case 500 : return 41495;
        case 600 : return 35199;
        case 700 : return 44925;
        case 800 : return 55006;
        case 900 : return 67534;
        case 950 : return 64691;
        case 1000 : return 68100;
        case 1050 : return 71134;
        case 1100 : return 70627;
        case 1150 : return 73919;
        case 1175 : return 54292;
        case 1190 : return 46852;
    }
  }
    if (a==1250) {
      switch (b) {
        case 127 : return 6044;
        case 150 : return 5718;
        case 175 : return 8568;
        case 200 : return 11963;
        case 300 : return 29072;
        case 400 : return 22377;
        case 500 : return 32084;
        case 600 : return 34309;
        case 700 : return 33493;
        case 800 : return 51850;
        case 900 : return 53296;
        case 950 : return 46844;
        case 1000 : return 53974;
        case 1050 : return 49019;
        case 1100 : return 66497;
        case 1150 : return 60428;
        case 1200 : return 50246;
        case 1225 : return 50598;
        case 1240 : return 39342;
    }
  }
    if (a==1300) {
      switch (b) {
        case 127 : return 4447;
        case 150 : return 5434;
        case 175 : return 4830;
        case 200 : return 10905;
        case 300 : return 18716;
        case 400 : return 16775;
        case 500 : return 21656;
        case 600 : return 24412;
        case 700 : return 22008;
        case 800 : return 35220;
        case 900 : return 35874;
        case 1000 : return 51755;
        case 1050 : return 40748;
        case 1100 : return 40331;
        case 1150 : return 36264;
        case 1200 : return 41856;
        case 1250 : return 44239;
        case 1275 : return 28317;
        case 1290 : return 24457;
    }
  }
    if (a==1350) {
      switch (b) {
        case 127 : return 4437;
        case 150 : return 1715;
        case 175 : return 9870;
        case 200 : return 10872;
        case 300 : return 19396;
        case 400 : return 19606;
        case 500 : return 23569;
        case 600 : return 32354;
        case 700 : return 25905;
        case 800 : return 41545;
        case 900 : return 41398;
        case 1000 : return 40394;
        case 1050 : return 39263;
        case 1100 : return 54786;
        case 1150 : return 48791;
        case 1200 : return 52629;
        case 1250 : return 52191;
        case 1300 : return 38119;
        case 1325 : return 39838;
        case 1340 : return 30665;
    }
  }
    if (a==1400) {
      switch (b) {
        case 127 : return 2712;
        case 150 : return 8554;
        case 175 : return 9266;
        case 200 : return 13864;
        case 300 : return 13777;
        case 400 : return 17753;
        case 500 : return 26736;
        case 600 : return 19693;
        case 700 : return 23474;
        case 800 : return 27259;
        case 900 : return 31030;
        case 1000 : return 40692;
        case 1100 : return 47313;
        case 1150 : return 46333;
        case 1200 : return 42147;
        case 1250 : return 39195;
        case 1300 : return 44651;
        case 1350 : return 36625;
        case 1375 : return 25529;
        case 1390 : return 22121;
    }
  }
    if (a==1450) {
      switch (b) {
        case 127 : return 5248;
        case 150 : return 7032;
        case 175 : return 10995;
        case 200 : return 17974;
        case 300 : return 12748;
        case 400 : return 20938;
        case 500 : return 21035;
        case 600 : return 25985;
        case 700 : return 21093;
        case 800 : return 35801;
        case 900 : return 36827;
        case 1000 : return 36680;
        case 1100 : return 33796;
        case 1150 : return 39539;
        case 1200 : return 47202;
        case 1250 : return 43611;
        case 1300 : return 42770;
        case 1350 : return 44965;
        case 1400 : return 41836;
        case 1425 : return 39498;
        case 1440 : return 29184;
    }
  }
    if (a==1500) {
      switch (b) {
        case 127 : return 5313;
        case 150 : return 13855;
        case 175 : return 6273;
        case 200 : return 18406;
        case 300 : return 11658;
        case 400 : return 19622;
        case 500 : return 24957;
        case 600 : return 27259;
        case 700 : return 30091;
        case 800 : return 28367;
        case 900 : return 31465;
        case 1000 : return 35195;
        case 1100 : return 52484;
        case 1200 : return 44855;
        case 1250 : return 35828;
        case 1300 : return 45845;
        case 1350 : return 44202;
        case 1400 : return 45462;
        case 1450 : return 49217;
        case 1475 : return 26973;
        case 1490 : return 33801;
    }
  }
    if (a==1550) {
      switch (b) {
        case 127 : return 8036;
        case 150 : return 8379;
        case 175 : return 6406;
        case 200 : return 13454;
        case 300 : return 17616;
        case 400 : return 14687;
        case 500 : return 18202;
        case 600 : return 32245;
        case 700 : return 28403;
        case 800 : return 34446;
        case 900 : return 29061;
        case 1000 : return 47971;
        case 1100 : return 50708;
        case 1200 : return 49869;
        case 1250 : return 31084;
        case 1300 : return 38063;
        case 1350 : return 41593;
        case 1400 : return 50988;
        case 1450 : return 41466;
        case 1500 : return 35154;
        case 1525 : return 30459;
        case 1540 : return 22757;
    }
  }
    if (a==1600) {
      switch (b) {
        case 127 : return 4457;
        case 150 : return 2815;
        case 175 : return 7092;
        case 200 : return 17257;
        case 300 : return 15454;
        case 400 : return 17351;
        case 500 : return 23131;
        case 600 : return 20573;
        case 700 : return 33169;
        case 800 : return 34746;
        case 900 : return 30058;
        case 1000 : return 37539;
        case 1100 : return 48488;
        case 1200 : return 44316;
        case 1300 : return 47213;
        case 1350 : return 38668;
        case 1400 : return 57699;
        case 1450 : return 47980;
        case 1500 : return 50315;
        case 1550 : return 42003;
        case 1575 : return 39255;
        case 1590 : return 42383;
    }
  }
    if (a==1650) {
      switch (b) {
        case 127 : return 7341;
        case 150 : return 5522;
        case 175 : return 6933;
        case 200 : return 16646;
        case 300 : return 16825;
        case 400 : return 18499;
        case 500 : return 18959;
        case 600 : return 15609;
        case 700 : return 27414;
        case 800 : return 30036;
        case 900 : return 26392;
        case 1000 : return 42924;
        case 1100 : return 43193;
        case 1200 : return 42028;
        case 1300 : return 37855;
        case 1350 : return 47396;
        case 1400 : return 40268;
        case 1450 : return 50399;
        case 1500 : return 48653;
        case 1550 : return 41347;
        case 1600 : return 36201;
        case 1625 : return 41382;
        case 1640 : return 34615;
    }
  }
    if (a==1700) {
      switch (b) {
        case 127 : return 3633;
        case 150 : return 2745;
        case 175 : return 5776;
        case 200 : return 13593;
        case 300 : return 16879;
        case 400 : return 24061;
        case 500 : return 23803;
        case 600 : return 24659;
        case 700 : return 29830;
        case 800 : return 31591;
        case 900 : return 29390;
        case 1000 : return 40110;
        case 1100 : return 48783;
        case 1200 : return 57351;
        case 1300 : return 43892;
        case 1400 : return 49690;
        case 1450 : return 42175;
        case 1500 : return 46229;
        case 1550 : return 53035;
        case 1600 : return 42416;
        case 1650 : return 27357;
        case 1675 : return 37823;
        case 1690 : return 25601;
    }
  }
    if (a==1750) {
      switch (b) {
        case 127 : return 6458;
        case 150 : return 6767;
        case 175 : return 8315;
        case 200 : return 12203;
        case 300 : return 10372;
        case 400 : return 18273;
        case 500 : return 27093;
        case 600 : return 26936;
        case 700 : return 27886;
        case 800 : return 26500;
        case 900 : return 38024;
        case 1000 : return 40594;
        case 1100 : return 39535;
        case 1200 : return 40322;
        case 1300 : return 49804;
        case 1400 : return 42641;
        case 1450 : return 36388;
        case 1500 : return 36202;
        case 1550 : return 41249;
        case 1600 : return 46714;
        case 1650 : return 45353;
        case 1700 : return 49828;
        case 1725 : return 35628;
        case 1740 : return 34776;
    }
  }
    if (a==1800) {
      switch (b) {
        case 127 : return 5616;
        case 150 : return 5636;
        case 175 : return 14528;
        case 200 : return 17464;
        case 300 : return 27013;
        case 400 : return 19201;
        case 500 : return 20694;
        case 600 : return 17202;
        case 700 : return 21380;
        case 800 : return 20487;
        case 900 : return 31373;
        case 1000 : return 42486;
        case 1100 : return 32465;
        case 1200 : return 46155;
        case 1300 : return 50639;
        case 1400 : return 47951;
        case 1500 : return 45349;
        case 1550 : return 40543;
        case 1600 : return 49299;
        case 1650 : return 36019;
        case 1700 : return 47147;
        case 1750 : return 29626;
        case 1775 : return 37784;
        case 1790 : return 27357;
    }
  }
    if (a==1850) {
      switch (b) {
        case 127 : return 4661;
        case 150 : return 1121;
        case 175 : return 6259;
        case 200 : return 14518;
        case 300 : return 8276;
        case 400 : return 14643;
        case 500 : return 11917;
        case 600 : return 30876;
        case 700 : return 17962;
        case 800 : return 23407;
        case 900 : return 35093;
        case 1000 : return 34112;
        case 1100 : return 37817;
        case 1200 : return 49010;
        case 1300 : return 38066;
        case 1400 : return 54377;
        case 1500 : return 46562;
        case 1550 : return 39796;
        case 1600 : return 44605;
        case 1650 : return 37106;
        case 1700 : return 33788;
        case 1750 : return 47730;
        case 1800 : return 42418;
        case 1825 : return 35166;
        case 1840 : return 38476;
    }
  }
    if (a==1900) {
      switch (b) {
        case 127 : return 2849;
        case 150 : return 5028;
        case 175 : return 8476;
        case 200 : return 8874;
        case 300 : return 14198;
        case 400 : return 18592;
        case 500 : return 12439;
        case 600 : return 23973;
        case 700 : return 21780;
        case 800 : return 31816;
        case 900 : return 25247;
        case 1000 : return 38847;
        case 1100 : return 57349;
        case 1200 : return 56595;
        case 1300 : return 42395;
        case 1400 : return 55985;
        case 1500 : return 55160;
        case 1600 : return 38295;
        case 1650 : return 39324;
        case 1700 : return 46817;
        case 1750 : return 45573;
        case 1800 : return 40773;
        case 1850 : return 45399;
        case 1875 : return 30816;
        case 1890 : return 35417;
    }
  }
    if (a==1950) {
      switch (b) {
        case 127 : return 7594;
        case 150 : return 7749;
        case 175 : return 4578;
        case 200 : return 17513;
        case 300 : return 16681;
        case 400 : return 17788;
        case 500 : return 24110;
        case 600 : return 22794;
        case 700 : return 32668;
        case 800 : return 28649;
        case 900 : return 37853;
        case 1000 : return 43290;
        case 1100 : return 38621;
        case 1200 : return 42846;
        case 1300 : return 52223;
        case 1400 : return 45255;
        case 1500 : return 53629;
        case 1600 : return 52203;
        case 1650 : return 37792;
        case 1700 : return 41531;
        case 1750 : return 46001;
        case 1800 : return 39065;
        case 1850 : return 35902;
        case 1900 : return 41847;
        case 1925 : return 41074;
        case 1940 : return 20717;
    }
  }
    if (a==2000) {
      switch (b) {
        case 127 : return 0;
        case 150 : return 3060;
        case 175 : return 6914;
        case 200 : return 8102;
        case 300 : return 6165;
        case 400 : return 7126;
        case 500 : return 13358;
        case 600 : return 12524;
        case 700 : return 13347;
        case 800 : return 13550;
        case 900 : return 19429;
        case 1000 : return 13559;
        case 1100 : return 19453;
        case 1200 : return 19049;
        case 1300 : return 29818;
        case 1400 : return 23884;
        case 1500 : return 21730;
        case 1600 : return 27446;
        case 1700 : return 23595;
        case 1750 : return 21751;
        case 1800 : return 21545;
        case 1850 : return 21807;
        case 1900 : return 27538;
        case 1950 : return 22602;
        case 1975 : return 24819;
        case 1990 : return 12728;
    }
  }
    if (a==2050) {
      switch (b) {
        case 127 : return 1946;
        case 150 : return 1135;
        case 175 : return 3741;
        case 200 : return 9595;
        case 300 : return 6694;
        case 400 : return 12610;
        case 500 : return 11017;
        case 600 : return 8148;
        case 700 : return 15798;
        case 800 : return 11321;
        case 900 : return 17113;
        case 1000 : return 21180;
        case 1100 : return 19068;
        case 1200 : return 25995;
        case 1300 : return 22158;
        case 1400 : return 31312;
        case 1500 : return 20200;
        case 1600 : return 24255;
        case 1700 : return 32996;
        case 1750 : return 20995;
        case 1800 : return 23272;
        case 1850 : return 17022;
        case 1900 : return 16703;
        case 1950 : return 15268;
        case 2000 : return 18543;
        case 2025 : return 22900;
        case 2040 : return 20021;
    }
  }
    if (a==2100) {
      switch (b) {
        case 127 : return 1946;
        case 150 : return 2094;
        case 175 : return 8247;
        case 200 : return 6082;
        case 300 : return 10024;
        case 400 : return 13349;
        case 500 : return 6604;
        case 600 : return 8192;
        case 700 : return 8837;
        case 800 : return 10613;
        case 900 : return 19936;
        case 1000 : return 13486;
        case 1100 : return 13895;
        case 1200 : return 21869;
        case 1300 : return 26072;
        case 1400 : return 31703;
        case 1500 : return 26971;
        case 1600 : return 22544;
        case 1700 : return 25015;
        case 1800 : return 23060;
        case 1850 : return 17129;
        case 1900 : return 16143;
        case 1950 : return 17274;
        case 2000 : return 19908;
        case 2050 : return 12953;
        case 2075 : return 16480;
        case 2090 : return 24097;
    }
  }
    if (a==2150) {
      switch (b) {
        case 127 : return 6048;
        case 150 : return 3131;
        case 175 : return 2499;
        case 200 : return 5968;
        case 300 : return 9492;
        case 400 : return 12112;
        case 500 : return 8485;
        case 600 : return 13271;
        case 700 : return 8553;
        case 800 : return 15514;
        case 900 : return 13055;
        case 1000 : return 14771;
        case 1100 : return 24045;
        case 1200 : return 21073;
        case 1300 : return 16542;
        case 1400 : return 20036;
        case 1500 : return 18021;
        case 1600 : return 16586;
        case 1700 : return 22679;
        case 1800 : return 20787;
        case 1850 : return 20545;
        case 1900 : return 20519;
        case 1950 : return 30220;
        case 2000 : return 19782;
        case 2050 : return 22761;
        case 2100 : return 18698;
        case 2125 : return 22727;
        case 2140 : return 12565;
    }
  }
    if (a==2200) {
      switch (b) {
        case 127 : return 1056;
        case 150 : return 1998;
        case 175 : return 2033;
        case 200 : return 6681;
        case 300 : return 11305;
        case 400 : return 14791;
        case 500 : return 14957;
        case 600 : return 15018;
        case 700 : return 14317;
        case 800 : return 17275;
        case 900 : return 15568;
        case 1000 : return 19989;
        case 1100 : return 23878;
        case 1200 : return 16906;
        case 1300 : return 23424;
        case 1400 : return 26162;
        case 1500 : return 20187;
        case 1600 : return 24182;
        case 1700 : return 20563;
        case 1800 : return 29685;
        case 1900 : return 20931;
        case 1950 : return 17269;
        case 2000 : return 29592;
        case 2050 : return 24653;
        case 2100 : return 24920;
        case 2150 : return 21582;
        case 2175 : return 16997;
        case 2190 : return 15164;
    }
  }
    if (a==2250) {
      switch (b) {
        case 127 : return 2065;
        case 150 : return 5152;
        case 175 : return 3220;
        case 200 : return 5080;
        case 300 : return 8107;
        case 400 : return 7858;
        case 500 : return 7845;
        case 600 : return 9758;
        case 700 : return 12855;
        case 800 : return 16136;
        case 900 : return 16492;
        case 1000 : return 14716;
        case 1100 : return 15104;
        case 1200 : return 25244;
        case 1300 : return 22805;
        case 1400 : return 23197;
        case 1500 : return 22300;
        case 1600 : return 19915;
        case 1700 : return 23361;
        case 1800 : return 19069;
        case 1900 : return 27647;
        case 1950 : return 27445;
        case 2000 : return 20340;
        case 2050 : return 19351;
        case 2100 : return 22131;
        case 2150 : return 19656;
        case 2200 : return 22581;
        case 2225 : return 17564;
        case 2240 : return 22648;
    }
  }
    if (a==2300) {
      switch (b) {
        case 127 : return 4194;
        case 150 : return 5241;
        case 175 : return 6364;
        case 200 : return 8260;
        case 300 : return 6534;
        case 400 : return 9918;
        case 500 : return 6201;
        case 600 : return 9010;
        case 700 : return 7238;
        case 800 : return 10913;
        case 900 : return 15533;
        case 1000 : return 15235;
        case 1100 : return 22307;
        case 1200 : return 17226;
        case 1300 : return 18523;
        case 1400 : return 21112;
        case 1500 : return 25582;
        case 1600 : return 20745;
        case 1700 : return 28937;
        case 1800 : return 22361;
        case 1900 : return 26920;
        case 2000 : return 19499;
        case 2050 : return 22034;
        case 2100 : return 27309;
        case 2150 : return 20823;
        case 2200 : return 26358;
        case 2250 : return 28474;
        case 2275 : return 18712;
        case 2290 : return 26103;
    }
  }
    if (a==2350) {
      switch (b) {
        case 127 : return 3127;
        case 150 : return 4173;
        case 175 : return 6600;
        case 200 : return 7882;
        case 300 : return 6774;
        case 400 : return 5109;
        case 500 : return 5851;
        case 600 : return 8412;
        case 700 : return 10200;
        case 800 : return 13632;
        case 900 : return 11277;
        case 1000 : return 19474;
        case 1100 : return 23365;
        case 1200 : return 25921;
        case 1300 : return 23178;
        case 1400 : return 20535;
        case 1500 : return 26279;
        case 1600 : return 24547;
        case 1700 : return 18073;
        case 1800 : return 29428;
        case 1900 : return 25820;
        case 2000 : return 30207;
        case 2050 : return 21943;
        case 2100 : return 18597;
        case 2150 : return 16393;
        case 2200 : return 25732;
        case 2250 : return 23110;
        case 2300 : return 20595;
        case 2325 : return 15551;
        case 2340 : return 13907;
    }
  }
    if (a==2400) {
      switch (b) {
        case 127 : return 3240;
        case 150 : return 1267;
        case 175 : return 3607;
        case 200 : return 2467;
        case 300 : return 3375;
        case 400 : return 6023;
        case 500 : return 3785;
        case 600 : return 8038;
        case 700 : return 11560;
        case 800 : return 15470;
        case 900 : return 12800;
        case 1000 : return 14708;
        case 1100 : return 17782;
        case 1200 : return 25580;
        case 1300 : return 25175;
        case 1400 : return 19308;
        case 1500 : return 19388;
        case 1600 : return 22881;
        case 1700 : return 16272;
        case 1800 : return 19682;
        case 1900 : return 22657;
        case 2000 : return 18264;
        case 2100 : return 14551;
        case 2150 : return 18049;
        case 2200 : return 18669;
        case 2250 : return 20441;
        case 2300 : return 23317;
        case 2350 : return 23577;
        case 2375 : return 18676;
        case 2390 : return 11836;
    }
  }
    if (a==2450) {
      switch (b) {
        case 127 : return 4369;
        case 150 : return 3273;
        case 175 : return 4510;
        case 200 : return 7843;
        case 300 : return 3179;
        case 400 : return 6761;
        case 500 : return 6884;
        case 600 : return 11519;
        case 700 : return 13577;
        case 800 : return 15185;
        case 900 : return 12927;
        case 1000 : return 15418;
        case 1100 : return 15568;
        case 1200 : return 17409;
        case 1300 : return 27770;
        case 1400 : return 20688;
        case 1500 : return 29559;
        case 1600 : return 15536;
        case 1700 : return 18541;
        case 1800 : return 21389;
        case 1900 : return 20719;
        case 2000 : return 23598;
        case 2100 : return 23609;
        case 2150 : return 22560;
        case 2200 : return 18832;
        case 2250 : return 19073;
        case 2300 : return 16240;
        case 2350 : return 20755;
        case 2400 : return 16803;
        case 2425 : return 14488;
        case 2440 : return 6763;
    }
  }
    if (a==2500) {
      switch (b) {
        case 127 : return 2225;
        case 150 : return 1090;
        case 175 : return 8032;
        case 200 : return 9845;
        case 300 : return 6685;
        case 400 : return 5999;
        case 500 : return 14069;
        case 600 : return 11283;
        case 700 : return 15356;
        case 800 : return 11474;
        case 900 : return 14762;
        case 1000 : return 18376;
        case 1100 : return 20073;
        case 1200 : return 28489;
        case 1300 : return 17734;
        case 1400 : return 21378;
        case 1500 : return 24505;
        case 1600 : return 22877;
        case 1700 : return 18659;
        case 1800 : return 23689;
        case 1900 : return 21163;
        case 2000 : return 30040;
        case 2100 : return 21933;
        case 2200 : return 16290;
        case 2250 : return 24039;
        case 2300 : return 20291;
        case 2350 : return 20370;
        case 2400 : return 16272;
        case 2450 : return 16815;
        case 2475 : return 17844;
        case 2490 : return 13264;
    }
  }
    if (a==2550) {
      switch (b) {
        case 127 : return 4471;
        case 150 : return 5665;
        case 175 : return 8344;
        case 200 : return 5205;
        case 300 : return 6680;
        case 400 : return 7008;
        case 500 : return 9966;
        case 600 : return 11508;
        case 700 : return 12731;
        case 800 : return 16046;
        case 900 : return 19745;
        case 1000 : return 14247;
        case 1100 : return 17108;
        case 1200 : return 25154;
        case 1300 : return 24439;
        case 1400 : return 20893;
        case 1500 : return 23846;
        case 1600 : return 23041;
        case 1700 : return 23978;
        case 1800 : return 22818;
        case 1900 : return 23720;
        case 2000 : return 27352;
        case 2100 : return 18178;
        case 2200 : return 18916;
        case 2250 : return 18900;
        case 2300 : return 23378;
        case 2350 : return 19350;
        case 2400 : return 31672;
        case 2450 : return 22988;
        case 2500 : return 25326;
        case 2525 : return 18515;
        case 2540 : return 19016;
    }
  }
    if (a==2600) {
      switch (b) {
        case 127 : return 2336;
        case 150 : return 4611;
        case 175 : return 4843;
        case 200 : return 8624;
        case 300 : return 8404;
        case 400 : return 10014;
        case 500 : return 15555;
        case 600 : return 8678;
        case 700 : return 10581;
        case 800 : return 11937;
        case 900 : return 19383;
        case 1000 : return 16206;
        case 1100 : return 17436;
        case 1200 : return 30986;
        case 1300 : return 17321;
        case 1400 : return 22985;
        case 1500 : return 27530;
        case 1600 : return 22062;
        case 1700 : return 20458;
        case 1800 : return 19446;
        case 1900 : return 18636;
        case 2000 : return 28647;
        case 2100 : return 21551;
        case 2200 : return 29657;
        case 2300 : return 19760;
        case 2350 : return 17046;
        case 2400 : return 11803;
        case 2450 : return 21209;
        case 2500 : return 13806;
        case 2550 : return 17366;
        case 2575 : return 14995;
        case 2590 : return 11427;
    }
  }
    if (a==2650) {
      switch (b) {
        case 127 : return 4672;
        case 150 : return 2317;
        case 175 : return 4780;
        case 200 : return 7005;
        case 300 : return 2731;
        case 400 : return 3595;
        case 500 : return 4480;
        case 600 : return 5242;
        case 700 : return 10836;
        case 800 : return 15602;
        case 900 : return 15147;
        case 1000 : return 21497;
        case 1100 : return 19186;
        case 1200 : return 13386;
        case 1300 : return 12213;
        case 1400 : return 25638;
        case 1500 : return 16326;
        case 1600 : return 17815;
        case 1700 : return 17285;
        case 1800 : return 13288;
        case 1900 : return 20939;
        case 2000 : return 22359;
        case 2100 : return 24564;
        case 2200 : return 18648;
        case 2300 : return 20351;
        case 2350 : return 14925;
        case 2400 : return 13290;
        case 2450 : return 12762;
        case 2500 : return 10386;
        case 2550 : return 16161;
        case 2600 : return 17666;
        case 2625 : return 20530;
        case 2640 : return 18565;
    }
  }
    if (a==2700) {
      switch (b) {
        case 127 : return 1168;
        case 150 : return 0;
        case 175 : return 1202;
        case 200 : return 3976;
        case 300 : return 9314;
        case 400 : return 10112;
        case 500 : return 7002;
        case 600 : return 9927;
        case 700 : return 10009;
        case 800 : return 18357;
        case 900 : return 11100;
        case 1000 : return 14752;
        case 1100 : return 18185;
        case 1200 : return 21387;
        case 1300 : return 21560;
        case 1400 : return 24128;
        case 1500 : return 22066;
        case 1600 : return 24531;
        case 1700 : return 28578;
        case 1800 : return 26249;
        case 1900 : return 34446;
        case 2000 : return 19082;
        case 2100 : return 21415;
        case 2200 : return 29092;
        case 2300 : return 26194;
        case 2400 : return 22469;
        case 2450 : return 19683;
        case 2500 : return 21222;
        case 2550 : return 21989;
        case 2600 : return 22411;
        case 2650 : return 16754;
        case 2675 : return 14602;
        case 2690 : return 15502;
    }
  }
    if (a==2750) {
      switch (b) {
        case 127 : return 3619;
        case 150 : return 2431;
        case 175 : return 6184;
        case 200 : return 9720;
        case 300 : return 7874;
        case 400 : return 12993;
        case 500 : return 7522;
        case 600 : return 10040;
        case 700 : return 11593;
        case 800 : return 14030;
        case 900 : return 11972;
        case 1000 : return 21271;
        case 1100 : return 21441;
        case 1200 : return 23694;
        case 1300 : return 17235;
        case 1400 : return 19058;
        case 1500 : return 18606;
        case 1600 : return 17811;
        case 1700 : return 17274;
        case 1800 : return 19274;
        case 1900 : return 21996;
        case 2000 : return 24397;
        case 2100 : return 28930;
        case 2200 : return 27460;
        case 2300 : return 29560;
        case 2400 : return 20786;
        case 2450 : return 18734;
        case 2500 : return 14215;
        case 2550 : return 17135;
        case 2600 : return 24112;
        case 2650 : return 17228;
        case 2700 : return 16634;
        case 2725 : return 30276;
        case 2740 : return 16045;
    }
  }
    if (a==2800) {
      switch (b) {
        case 127 : return 3616;
        case 150 : return 401;
        case 175 : return 4890;
        case 200 : return 7683;
        case 300 : return 8166;
        case 400 : return 6642;
        case 500 : return 5970;
        case 600 : return 7319;
        case 700 : return 8223;
        case 800 : return 17727;
        case 900 : return 11556;
        case 1000 : return 13943;
        case 1100 : return 21363;
        case 1200 : return 21982;
        case 1300 : return 30717;
        case 1400 : return 30643;
        case 1500 : return 20754;
        case 1600 : return 25496;
        case 1700 : return 20629;
        case 1800 : return 26344;
        case 1900 : return 21753;
        case 2000 : return 20552;
        case 2100 : return 29772;
        case 2200 : return 25636;
        case 2300 : return 29629;
        case 2400 : return 22460;
        case 2500 : return 21951;
        case 2550 : return 20147;
        case 2600 : return 21260;
        case 2650 : return 23264;
        case 2700 : return 22608;
        case 2750 : return 13127;
        case 2775 : return 14157;
        case 2790 : return 22058;
    }
  }
      break;
      case 2018 :
    if (a==800) {
      switch (b) {
        case 127 : return 105701;
        case 200 : return 153632;
        case 300 : return 165196;
        case 400 : return 165791;
        case 500 : return 190255;
        case 600 : return 199745;
        case 700 : return 228815;
        case 790 : return 196173;
    }
  }
    if (a==900) {
      switch (b) {
        case 127 : return 89570;
        case 200 : return 146746;
        case 300 : return 149120;
        case 400 : return 175206;
        case 500 : return 155556;
        case 600 : return 205227;
        case 700 : return 240907;
        case 800 : return 276278;
        case 890 : return 204845;
    }
  }
    if (a==1000) {
      switch (b) {
        case 127 : return 92240;
        case 150 : return 122970;
        case 175 : return 121717;
        case 200 : return 139734;
        case 300 : return 154966;
        case 400 : return 158375;
        case 500 : return 206984;
        case 600 : return 200845;
        case 700 : return 203400;
        case 750 : return 194417;
        case 800 : return 230117;
        case 850 : return 246004;
        case 900 : return 247784;
        case 950 : return 270126;
        case 975 : return 225535;
        case 990 : return 206841;
    }
  }
    if (a==1050) {
      switch (b) {
        case 127 : return 75681;
        case 150 : return 95553;
        case 175 : return 113241;
        case 200 : return 136595;
        case 300 : return 155945;
        case 400 : return 148056;
        case 500 : return 185366;
        case 600 : return 238011;
        case 700 : return 226490;
        case 750 : return 211858;
        case 800 : return 225839;
        case 850 : return 206417;
        case 900 : return 257618;
        case 950 : return 265872;
        case 1000 : return 248219;
        case 1025 : return 252620;
        case 1040 : return 245671;
    }
  }
    if (a==1100) {
      switch (b) {
        case 127 : return 79962;
        case 150 : return 87893;
        case 175 : return 107257;
        case 200 : return 122181;
        case 300 : return 141638;
        case 400 : return 132844;
        case 500 : return 179467;
        case 600 : return 170108;
        case 700 : return 216233;
        case 800 : return 202921;
        case 850 : return 202943;
        case 900 : return 227229;
        case 950 : return 241960;
        case 1000 : return 274717;
        case 1050 : return 245370;
        case 1075 : return 208489;
        case 1090 : return 187465;
    }
  }
    if (a==1150) {
      switch (b) {
        case 127 : return 57441;
        case 150 : return 67234;
        case 175 : return 76095;
        case 200 : return 102739;
        case 300 : return 103929;
        case 400 : return 110624;
        case 500 : return 111445;
        case 600 : return 150919;
        case 700 : return 144295;
        case 800 : return 145997;
        case 850 : return 148999;
        case 900 : return 169280;
        case 950 : return 165706;
        case 1000 : return 190160;
        case 1050 : return 203996;
        case 1100 : return 187898;
        case 1125 : return 180049;
        case 1140 : return 147604;
    }
  }
    if (a==1200) {
      switch (b) {
        case 127 : return 45666;
        case 150 : return 52705;
        case 175 : return 45324;
        case 200 : return 50978;
        case 300 : return 62226;
        case 400 : return 78371;
        case 500 : return 88426;
        case 600 : return 84804;
        case 700 : return 105295;
        case 800 : return 123983;
        case 900 : return 123903;
        case 950 : return 87272;
        case 1000 : return 117126;
        case 1050 : return 110728;
        case 1100 : return 122596;
        case 1150 : return 120295;
        case 1175 : return 119328;
        case 1190 : return 82471;
    }
  }
    if (a==1250) {
      switch (b) {
        case 127 : return 27491;
        case 150 : return 40296;
        case 175 : return 24639;
        case 200 : return 35095;
        case 300 : return 51650;
        case 400 : return 56735;
        case 500 : return 57287;
        case 600 : return 81056;
        case 700 : return 75785;
        case 800 : return 74037;
        case 900 : return 102113;
        case 950 : return 81246;
        case 1000 : return 78080;
        case 1050 : return 87913;
        case 1100 : return 105017;
        case 1150 : return 100008;
        case 1200 : return 77341;
        case 1225 : return 86534;
        case 1240 : return 77604;
    }
  }
    if (a==1300) {
      switch (b) {
        case 127 : return 18283;
        case 150 : return 27181;
        case 175 : return 27779;
        case 200 : return 41449;
        case 300 : return 45737;
        case 400 : return 46658;
        case 500 : return 46314;
        case 600 : return 47216;
        case 700 : return 50656;
        case 800 : return 64979;
        case 900 : return 87905;
        case 1000 : return 86815;
        case 1050 : return 64728;
        case 1100 : return 75551;
        case 1150 : return 95446;
        case 1200 : return 75669;
        case 1250 : return 70403;
        case 1275 : return 64986;
        case 1290 : return 62520;
    }
  }
    if (a==1350) {
      switch (b) {
        case 127 : return 25723;
        case 150 : return 32238;
        case 175 : return 27536;
        case 200 : return 31218;
        case 300 : return 41278;
        case 400 : return 43637;
        case 500 : return 44148;
        case 600 : return 52336;
        case 700 : return 60477;
        case 800 : return 57739;
        case 900 : return 70212;
        case 1000 : return 81749;
        case 1050 : return 56791;
        case 1100 : return 59425;
        case 1150 : return 73932;
        case 1200 : return 75975;
        case 1250 : return 84054;
        case 1300 : return 56874;
        case 1325 : return 72459;
        case 1340 : return 59835;
    }
  }
    if (a==1400) {
      switch (b) {
        case 127 : return 26914;
        case 150 : return 28494;
        case 175 : return 26658;
        case 200 : return 28157;
        case 300 : return 39906;
        case 400 : return 38044;
        case 500 : return 41638;
        case 600 : return 29520;
        case 700 : return 49578;
        case 800 : return 50574;
        case 900 : return 61256;
        case 1000 : return 89374;
        case 1100 : return 63967;
        case 1150 : return 64789;
        case 1200 : return 76734;
        case 1250 : return 83087;
        case 1300 : return 73709;
        case 1350 : return 70513;
        case 1375 : return 71639;
        case 1390 : return 57796;
    }
  }
    if (a==1450) {
      switch (b) {
        case 127 : return 29647;
        case 150 : return 25477;
        case 175 : return 31009;
        case 200 : return 30046;
        case 300 : return 35189;
        case 400 : return 42820;
        case 500 : return 52944;
        case 600 : return 45877;
        case 700 : return 56880;
        case 800 : return 56996;
        case 900 : return 59604;
        case 1000 : return 74174;
        case 1100 : return 72866;
        case 1150 : return 67340;
        case 1200 : return 84327;
        case 1250 : return 58621;
        case 1300 : return 71428;
        case 1350 : return 66353;
        case 1400 : return 69038;
        case 1425 : return 68049;
        case 1440 : return 59850;
    }
  }
    if (a==1500) {
      switch (b) {
        case 127 : return 21447;
        case 150 : return 32364;
        case 175 : return 25476;
        case 200 : return 37214;
        case 300 : return 33750;
        case 400 : return 42709;
        case 500 : return 55070;
        case 600 : return 48720;
        case 700 : return 43815;
        case 800 : return 51454;
        case 900 : return 67413;
        case 1000 : return 73896;
        case 1100 : return 85429;
        case 1200 : return 73930;
        case 1250 : return 64392;
        case 1300 : return 61934;
        case 1350 : return 72807;
        case 1400 : return 58515;
        case 1450 : return 73821;
        case 1475 : return 71461;
        case 1490 : return 70054;
    }
  }
    if (a==1550) {
      switch (b) {
        case 127 : return 25395;
        case 150 : return 20743;
        case 175 : return 28689;
        case 200 : return 24923;
        case 300 : return 34096;
        case 400 : return 42151;
        case 500 : return 35856;
        case 600 : return 45963;
        case 700 : return 40365;
        case 800 : return 60888;
        case 900 : return 67448;
        case 1000 : return 64778;
        case 1100 : return 96912;
        case 1200 : return 81404;
        case 1250 : return 65281;
        case 1300 : return 65648;
        case 1350 : return 75733;
        case 1400 : return 69743;
        case 1450 : return 67064;
        case 1500 : return 68745;
        case 1525 : return 58348;
        case 1540 : return 55980;
    }
  }
    if (a==1600) {
      switch (b) {
        case 127 : return 27306;
        case 150 : return 36872;
        case 175 : return 41175;
        case 200 : return 38465;
        case 300 : return 42903;
        case 400 : return 33946;
        case 500 : return 43869;
        case 600 : return 45538;
        case 700 : return 43344;
        case 800 : return 61590;
        case 900 : return 65308;
        case 1000 : return 65774;
        case 1100 : return 87873;
        case 1200 : return 76422;
        case 1300 : return 68806;
        case 1350 : return 73099;
        case 1400 : return 57841;
        case 1450 : return 58231;
        case 1500 : return 70283;
        case 1550 : return 67779;
        case 1575 : return 73277;
        case 1590 : return 59451;
    }
  }
    if (a==1650) {
      switch (b) {
        case 127 : return 25677;
        case 150 : return 28562;
        case 175 : return 33219;
        case 200 : return 26860;
        case 300 : return 31188;
        case 400 : return 37400;
        case 500 : return 48092;
        case 600 : return 44465;
        case 700 : return 51605;
        case 800 : return 53239;
        case 900 : return 75296;
        case 1000 : return 73630;
        case 1100 : return 87185;
        case 1200 : return 97685;
        case 1300 : return 71570;
        case 1350 : return 68401;
        case 1400 : return 72582;
        case 1450 : return 61497;
        case 1500 : return 68416;
        case 1550 : return 76026;
        case 1600 : return 63906;
        case 1625 : return 55851;
        case 1640 : return 51809;
    }
  }
    if (a==1700) {
      switch (b) {
        case 127 : return 22037;
        case 150 : return 25736;
        case 175 : return 32423;
        case 200 : return 56001;
        case 300 : return 28762;
        case 400 : return 44250;
        case 500 : return 46357;
        case 600 : return 46463;
        case 700 : return 54402;
        case 800 : return 65465;
        case 900 : return 59839;
        case 1000 : return 80368;
        case 1100 : return 73778;
        case 1200 : return 85881;
        case 1300 : return 88555;
        case 1400 : return 86543;
        case 1450 : return 78043;
        case 1500 : return 76178;
        case 1550 : return 76571;
        case 1600 : return 70442;
        case 1650 : return 66432;
        case 1675 : return 57114;
        case 1690 : return 57431;
    }
  }
    if (a==1750) {
      switch (b) {
        case 127 : return 20462;
        case 150 : return 25759;
        case 175 : return 33693;
        case 200 : return 32144;
        case 300 : return 31324;
        case 400 : return 28732;
        case 500 : return 51626;
        case 600 : return 51507;
        case 700 : return 49191;
        case 800 : return 55721;
        case 900 : return 53491;
        case 1000 : return 81367;
        case 1100 : return 59338;
        case 1200 : return 77316;
        case 1300 : return 70082;
        case 1400 : return 66070;
        case 1450 : return 70847;
        case 1500 : return 69304;
        case 1550 : return 62791;
        case 1600 : return 64519;
        case 1650 : return 64187;
        case 1700 : return 65465;
        case 1725 : return 64742;
        case 1740 : return 57373;
    }
  }
    if (a==1800) {
      switch (b) {
        case 127 : return 24456;
        case 150 : return 26249;
        case 175 : return 27035;
        case 200 : return 31593;
        case 300 : return 36280;
        case 400 : return 38114;
        case 500 : return 34941;
        case 600 : return 44670;
        case 700 : return 54894;
        case 800 : return 52080;
        case 900 : return 66454;
        case 1000 : return 66592;
        case 1100 : return 70563;
        case 1200 : return 70621;
        case 1300 : return 78552;
        case 1400 : return 65397;
        case 1500 : return 74811;
        case 1550 : return 64750;
        case 1600 : return 53568;
        case 1650 : return 62890;
        case 1700 : return 54515;
        case 1750 : return 61229;
        case 1775 : return 51643;
        case 1790 : return 55962;
    }
  }
    if (a==1850) {
      switch (b) {
        case 127 : return 21471;
        case 150 : return 17676;
        case 175 : return 28608;
        case 200 : return 34114;
        case 300 : return 28065;
        case 400 : return 41464;
        case 500 : return 38840;
        case 600 : return 42112;
        case 700 : return 45866;
        case 800 : return 56005;
        case 900 : return 52433;
        case 1000 : return 71052;
        case 1100 : return 74761;
        case 1200 : return 69355;
        case 1300 : return 65851;
        case 1400 : return 75040;
        case 1500 : return 58283;
        case 1550 : return 63964;
        case 1600 : return 76943;
        case 1650 : return 52941;
        case 1700 : return 67829;
        case 1750 : return 61140;
        case 1800 : return 58026;
        case 1825 : return 58440;
        case 1840 : return 60124;
    }
  }
    if (a==1900) {
      switch (b) {
        case 127 : return 23841;
        case 150 : return 22678;
        case 175 : return 32891;
        case 200 : return 37916;
        case 300 : return 27094;
        case 400 : return 32831;
        case 500 : return 50061;
        case 600 : return 53246;
        case 700 : return 54929;
        case 800 : return 53779;
        case 900 : return 51555;
        case 1000 : return 68960;
        case 1100 : return 73985;
        case 1200 : return 76812;
        case 1300 : return 72287;
        case 1400 : return 62903;
        case 1500 : return 80486;
        case 1600 : return 69129;
        case 1650 : return 57233;
        case 1700 : return 58650;
        case 1750 : return 67503;
        case 1800 : return 61671;
        case 1850 : return 66211;
        case 1875 : return 64193;
        case 1890 : return 39735;
    }
  }
    if (a==1950) {
      switch (b) {
        case 127 : return 25993;
        case 150 : return 18047;
        case 175 : return 23637;
        case 200 : return 30965;
        case 300 : return 37812;
        case 400 : return 38525;
        case 500 : return 50958;
        case 600 : return 48180;
        case 700 : return 47087;
        case 800 : return 63527;
        case 900 : return 49540;
        case 1000 : return 68832;
        case 1100 : return 68967;
        case 1200 : return 78489;
        case 1300 : return 67731;
        case 1400 : return 82125;
        case 1500 : return 62717;
        case 1600 : return 58491;
        case 1650 : return 66243;
        case 1700 : return 67065;
        case 1750 : return 79569;
        case 1800 : return 64690;
        case 1850 : return 66851;
        case 1900 : return 62220;
        case 1925 : return 54521;
        case 1940 : return 40452;
    }
  }
    if (a==2000) {
      switch (b) {
        case 127 : return 13223;
        case 150 : return 7012;
        case 175 : return 17507;
        case 200 : return 15702;
        case 300 : return 14964;
        case 400 : return 11958;
        case 500 : return 27057;
        case 600 : return 19643;
        case 700 : return 26641;
        case 800 : return 30083;
        case 900 : return 34382;
        case 1000 : return 31674;
        case 1100 : return 32082;
        case 1200 : return 34877;
        case 1300 : return 31466;
        case 1400 : return 31542;
        case 1500 : return 30792;
        case 1600 : return 36253;
        case 1700 : return 26292;
        case 1750 : return 26774;
        case 1800 : return 35042;
        case 1850 : return 23231;
        case 1900 : return 37312;
        case 1950 : return 28342;
        case 1975 : return 29630;
        case 1990 : return 30464;
    }
  }
    if (a==2050) {
      switch (b) {
        case 127 : return 8054;
        case 150 : return 12066;
        case 175 : return 9502;
        case 200 : return 14725;
        case 300 : return 17434;
        case 400 : return 21168;
        case 500 : return 15279;
        case 600 : return 27286;
        case 700 : return 19476;
        case 800 : return 35262;
        case 900 : return 29794;
        case 1000 : return 40825;
        case 1100 : return 31495;
        case 1200 : return 33149;
        case 1300 : return 31509;
        case 1400 : return 32174;
        case 1500 : return 37111;
        case 1600 : return 38430;
        case 1700 : return 39797;
        case 1750 : return 36989;
        case 1800 : return 35324;
        case 1850 : return 42999;
        case 1900 : return 20725;
        case 1950 : return 37821;
        case 2000 : return 34783;
        case 2025 : return 20947;
        case 2040 : return 33590;
    }
  }
    if (a==2100) {
      switch (b) {
        case 127 : return 11547;
        case 150 : return 12922;
        case 175 : return 13439;
        case 200 : return 23092;
        case 300 : return 16515;
        case 400 : return 20455;
        case 500 : return 21519;
        case 600 : return 27036;
        case 700 : return 19174;
        case 800 : return 23306;
        case 900 : return 30373;
        case 1000 : return 27799;
        case 1100 : return 27687;
        case 1200 : return 37009;
        case 1300 : return 31186;
        case 1400 : return 27134;
        case 1500 : return 39988;
        case 1600 : return 41112;
        case 1700 : return 29151;
        case 1800 : return 37973;
        case 1850 : return 34691;
        case 1900 : return 29137;
        case 1950 : return 22006;
        case 2000 : return 22492;
        case 2050 : return 27501;
        case 2075 : return 21440;
        case 2090 : return 18688;
    }
  }
    if (a==2150) {
      switch (b) {
        case 127 : return 11541;
        case 150 : return 17025;
        case 175 : return 14269;
        case 200 : return 23064;
        case 300 : return 24006;
        case 400 : return 21060;
        case 500 : return 26505;
        case 600 : return 19688;
        case 700 : return 21733;
        case 800 : return 25887;
        case 900 : return 36359;
        case 1000 : return 31857;
        case 1100 : return 34411;
        case 1200 : return 43708;
        case 1300 : return 42185;
        case 1400 : return 30403;
        case 1500 : return 27547;
        case 1600 : return 40112;
        case 1700 : return 36004;
        case 1800 : return 34371;
        case 1850 : return 21417;
        case 1900 : return 22976;
        case 1950 : return 25243;
        case 2000 : return 30031;
        case 2050 : return 27924;
        case 2100 : return 25754;
        case 2125 : return 28514;
        case 2140 : return 25023;
    }
  }
    if (a==2200) {
      switch (b) {
        case 127 : return 14823;
        case 150 : return 7406;
        case 175 : return 12920;
        case 200 : return 8596;
        case 300 : return 15299;
        case 400 : return 18370;
        case 500 : return 26755;
        case 600 : return 18690;
        case 700 : return 23030;
        case 800 : return 25520;
        case 900 : return 26802;
        case 1000 : return 30236;
        case 1100 : return 33107;
        case 1200 : return 37201;
        case 1300 : return 28652;
        case 1400 : return 32814;
        case 1500 : return 35601;
        case 1600 : return 26549;
        case 1700 : return 34331;
        case 1800 : return 25178;
        case 1900 : return 40686;
        case 1950 : return 20178;
        case 2000 : return 28075;
        case 2050 : return 26511;
        case 2100 : return 37770;
        case 2150 : return 25797;
        case 2175 : return 22833;
        case 2190 : return 25404;
    }
  }
    if (a==2250) {
      switch (b) {
        case 127 : return 10759;
        case 150 : return 7776;
        case 175 : return 8117;
        case 200 : return 15552;
        case 300 : return 16713;
        case 400 : return 19058;
        case 500 : return 17611;
        case 600 : return 17026;
        case 700 : return 22698;
        case 800 : return 22077;
        case 900 : return 33094;
        case 1000 : return 29560;
        case 1100 : return 41195;
        case 1200 : return 42987;
        case 1300 : return 30996;
        case 1400 : return 32425;
        case 1500 : return 31965;
        case 1600 : return 33311;
        case 1700 : return 33583;
        case 1800 : return 40774;
        case 1900 : return 37557;
        case 1950 : return 25801;
        case 2000 : return 26857;
        case 2050 : return 27706;
        case 2100 : return 34520;
        case 2150 : return 28696;
        case 2200 : return 33519;
        case 2225 : return 24281;
        case 2240 : return 26489;
    }
  }
    if (a==2300) {
      switch (b) {
        case 127 : return 13152;
        case 150 : return 7597;
        case 175 : return 10128;
        case 200 : return 19091;
        case 300 : return 17375;
        case 400 : return 19795;
        case 500 : return 22597;
        case 600 : return 23087;
        case 700 : return 20614;
        case 800 : return 22791;
        case 900 : return 30755;
        case 1000 : return 25305;
        case 1100 : return 41662;
        case 1200 : return 36742;
        case 1300 : return 32105;
        case 1400 : return 39552;
        case 1500 : return 36751;
        case 1600 : return 40644;
        case 1700 : return 36890;
        case 1800 : return 39871;
        case 1900 : return 31086;
        case 2000 : return 33416;
        case 2050 : return 27469;
        case 2100 : return 25904;
        case 2150 : return 33974;
        case 2200 : return 27462;
        case 2250 : return 26102;
        case 2275 : return 37645;
        case 2290 : return 26195;
    }
  }
    if (a==2350) {
      switch (b) {
        case 127 : return 11034;
        case 150 : return 14917;
        case 175 : return 8131;
        case 200 : return 27592;
        case 300 : return 21949;
        case 400 : return 17506;
        case 500 : return 17215;
        case 600 : return 17608;
        case 700 : return 23852;
        case 800 : return 29079;
        case 900 : return 18885;
        case 1000 : return 23347;
        case 1100 : return 35305;
        case 1200 : return 27128;
        case 1300 : return 35162;
        case 1400 : return 39554;
        case 1500 : return 31397;
        case 1600 : return 23231;
        case 1700 : return 46778;
        case 1800 : return 24503;
        case 1900 : return 37475;
        case 2000 : return 30014;
        case 2050 : return 24038;
        case 2100 : return 17482;
        case 2150 : return 24762;
        case 2200 : return 19274;
        case 2250 : return 30919;
        case 2300 : return 33587;
        case 2325 : return 26220;
        case 2340 : return 16727;
    }
  }
    if (a==2400) {
      switch (b) {
        case 127 : return 14664;
        case 150 : return 10303;
        case 175 : return 10693;
        case 200 : return 14366;
        case 300 : return 6154;
        case 400 : return 12644;
        case 500 : return 20126;
        case 600 : return 19342;
        case 700 : return 20779;
        case 800 : return 15402;
        case 900 : return 28175;
        case 1000 : return 34808;
        case 1100 : return 29010;
        case 1200 : return 26839;
        case 1300 : return 29636;
        case 1400 : return 38238;
        case 1500 : return 41242;
        case 1600 : return 34603;
        case 1700 : return 52207;
        case 1800 : return 34213;
        case 1900 : return 39321;
        case 2000 : return 30611;
        case 2100 : return 30535;
        case 2150 : return 25586;
        case 2200 : return 25046;
        case 2250 : return 23564;
        case 2300 : return 23472;
        case 2350 : return 21208;
        case 2375 : return 20446;
        case 2390 : return 23781;
    }
  }
    if (a==2450) {
      switch (b) {
        case 127 : return 9239;
        case 150 : return 7089;
        case 175 : return 13353;
        case 200 : return 22401;
        case 300 : return 18955;
        case 400 : return 12176;
        case 500 : return 24511;
        case 600 : return 17220;
        case 700 : return 22591;
        case 800 : return 33703;
        case 900 : return 35243;
        case 1000 : return 36466;
        case 1100 : return 43068;
        case 1200 : return 41055;
        case 1300 : return 39105;
        case 1400 : return 30045;
        case 1500 : return 33649;
        case 1600 : return 29541;
        case 1700 : return 35005;
        case 1800 : return 22933;
        case 1900 : return 30722;
        case 2000 : return 33330;
        case 2100 : return 26055;
        case 2150 : return 15737;
        case 2200 : return 26182;
        case 2250 : return 20473;
        case 2300 : return 24186;
        case 2350 : return 23136;
        case 2400 : return 23969;
        case 2425 : return 18109;
        case 2440 : return 20590;
    }
  }
    if (a==2500) {
      switch (b) {
        case 127 : return 9238;
        case 150 : return 11572;
        case 175 : return 16592;
        case 200 : return 13543;
        case 300 : return 17727;
        case 400 : return 12190;
        case 500 : return 24216;
        case 600 : return 30536;
        case 700 : return 36139;
        case 800 : return 30711;
        case 900 : return 24581;
        case 1000 : return 28574;
        case 1100 : return 31043;
        case 1200 : return 26244;
        case 1300 : return 30320;
        case 1400 : return 43893;
        case 1500 : return 36917;
        case 1600 : return 38106;
        case 1700 : return 32775;
        case 1800 : return 26006;
        case 1900 : return 31634;
        case 2000 : return 33636;
        case 2100 : return 40861;
        case 2200 : return 23860;
        case 2250 : return 29444;
        case 2300 : return 24989;
        case 2350 : return 26872;
        case 2400 : return 28936;
        case 2450 : return 23490;
        case 2475 : return 27819;
        case 2490 : return 23200;
    }
  }
    if (a==2550) {
      switch (b) {
        case 127 : return 12879;
        case 150 : return 7117;
        case 175 : return 14015;
        case 200 : return 16189;
        case 300 : return 15335;
        case 400 : return 16603;
        case 500 : return 23990;
        case 600 : return 17459;
        case 700 : return 16272;
        case 800 : return 24048;
        case 900 : return 33951;
        case 1000 : return 34665;
        case 1100 : return 28485;
        case 1200 : return 44098;
        case 1300 : return 38109;
        case 1400 : return 37359;
        case 1500 : return 31256;
        case 1600 : return 39169;
        case 1700 : return 29442;
        case 1800 : return 31518;
        case 1900 : return 28615;
        case 2000 : return 36513;
        case 2100 : return 27629;
        case 2200 : return 27391;
        case 2250 : return 33600;
        case 2300 : return 28204;
        case 2350 : return 23164;
        case 2400 : return 28691;
        case 2450 : return 27266;
        case 2500 : return 24917;
        case 2525 : return 12973;
        case 2540 : return 27078;
    }
  }
    if (a==2600) {
      switch (b) {
        case 127 : return 3669;
        case 150 : return 11968;
        case 175 : return 13346;
        case 200 : return 19817;
        case 300 : return 21113;
        case 400 : return 20186;
        case 500 : return 20394;
        case 600 : return 16153;
        case 700 : return 20866;
        case 800 : return 23744;
        case 900 : return 23878;
        case 1000 : return 30552;
        case 1100 : return 25340;
        case 1200 : return 35149;
        case 1300 : return 34664;
        case 1400 : return 34935;
        case 1500 : return 39001;
        case 1600 : return 32193;
        case 1700 : return 33358;
        case 1800 : return 37739;
        case 1900 : return 35515;
        case 2000 : return 35815;
        case 2100 : return 32434;
        case 2200 : return 33026;
        case 2300 : return 23279;
        case 2350 : return 26291;
        case 2400 : return 22336;
        case 2450 : return 27758;
        case 2500 : return 33940;
        case 2550 : return 27636;
        case 2575 : return 25215;
        case 2590 : return 37280;
    }
  }
    if (a==2650) {
      switch (b) {
        case 127 : return 10968;
        case 150 : return 11078;
        case 175 : return 13910;
        case 200 : return 10424;
        case 300 : return 14651;
        case 400 : return 21297;
        case 500 : return 23167;
        case 600 : return 23750;
        case 700 : return 22417;
        case 800 : return 33803;
        case 900 : return 25759;
        case 1000 : return 25815;
        case 1100 : return 29603;
        case 1200 : return 40442;
        case 1300 : return 26182;
        case 1400 : return 27742;
        case 1500 : return 35215;
        case 1600 : return 32674;
        case 1700 : return 30620;
        case 1800 : return 18841;
        case 1900 : return 33758;
        case 2000 : return 36955;
        case 2100 : return 36328;
        case 2200 : return 31721;
        case 2300 : return 24491;
        case 2350 : return 24481;
        case 2400 : return 19226;
        case 2450 : return 26353;
        case 2500 : return 29421;
        case 2550 : return 26929;
        case 2600 : return 25267;
        case 2625 : return 24825;
        case 2640 : return 21990;
    }
  }
    if (a==2700) {
      switch (b) {
        case 127 : return 13664;
        case 150 : return 9926;
        case 175 : return 14182;
        case 200 : return 15849;
        case 300 : return 21245;
        case 400 : return 13210;
        case 500 : return 16642;
        case 600 : return 19409;
        case 700 : return 19444;
        case 800 : return 28448;
        case 900 : return 19652;
        case 1000 : return 26536;
        case 1100 : return 27221;
        case 1200 : return 36607;
        case 1300 : return 37670;
        case 1400 : return 36192;
        case 1500 : return 28143;
        case 1600 : return 39433;
        case 1700 : return 44739;
        case 1800 : return 30824;
        case 1900 : return 35150;
        case 2000 : return 27454;
        case 2100 : return 28333;
        case 2200 : return 35270;
        case 2300 : return 30234;
        case 2400 : return 35575;
        case 2450 : return 30099;
        case 2500 : return 22397;
        case 2550 : return 25938;
        case 2600 : return 29460;
        case 2650 : return 21463;
        case 2675 : return 37143;
        case 2690 : return 20956;
    }
  }
    if (a==2750) {
      switch (b) {
        case 127 : return 18841;
        case 150 : return 15411;
        case 175 : return 15892;
        case 200 : return 20615;
        case 300 : return 16104;
        case 400 : return 14239;
        case 500 : return 22530;
        case 600 : return 20233;
        case 700 : return 27232;
        case 800 : return 35427;
        case 900 : return 26043;
        case 1000 : return 32876;
        case 1100 : return 27836;
        case 1200 : return 37418;
        case 1300 : return 33059;
        case 1400 : return 42516;
        case 1500 : return 37172;
        case 1600 : return 28041;
        case 1700 : return 35049;
        case 1800 : return 26925;
        case 1900 : return 36302;
        case 2000 : return 45879;
        case 2100 : return 27042;
        case 2200 : return 33446;
        case 2300 : return 36584;
        case 2400 : return 26084;
        case 2450 : return 25073;
        case 2500 : return 35526;
        case 2550 : return 28887;
        case 2600 : return 22193;
        case 2650 : return 17864;
        case 2700 : return 17670;
        case 2725 : return 25611;
        case 2740 : return 18315;
    }
  }
    if (a==2800) {
      switch (b) {
        case 127 : return 14106;
        case 150 : return 10298;
        case 175 : return 16837;
        case 200 : return 17686;
        case 300 : return 17973;
        case 400 : return 14799;
        case 500 : return 17423;
        case 600 : return 21970;
        case 700 : return 18093;
        case 800 : return 24385;
        case 900 : return 33229;
        case 1000 : return 26583;
        case 1100 : return 22484;
        case 1200 : return 25121;
        case 1300 : return 33380;
        case 1400 : return 38336;
        case 1500 : return 32684;
        case 1600 : return 32280;
        case 1700 : return 28869;
        case 1800 : return 25575;
        case 1900 : return 35025;
        case 2000 : return 33739;
        case 2100 : return 35100;
        case 2200 : return 31376;
        case 2300 : return 36543;
        case 2400 : return 27745;
        case 2500 : return 34325;
        case 2550 : return 23517;
        case 2600 : return 32591;
        case 2650 : return 26767;
        case 2700 : return 20410;
        case 2750 : return 18135;
        case 2775 : return 26647;
        case 2790 : return 17401;
    }
  }
      case 21160 :
    if (a==800) {
      switch (b) {
        case 127 : return 34080;
        case 200 : return 49033;
        case 300 : return 57202;
        case 400 : return 79347;
        case 500 : return 77244;
        case 600 : return 93803;
        case 700 : return 91755;
        case 790 : return 91672;
    }
  }
    if (a==900) {
      switch (b) {
        case 127 : return 29996;
        case 200 : return 51846;
        case 300 : return 55110;
        case 400 : return 65491;
        case 500 : return 62566;
        case 600 : return 78353;
        case 700 : return 89344;
        case 800 : return 76897;
        case 890 : return 123134;
    }
  }
    if (a==1000) {
      switch (b) {
        case 127 : return 28766;
        case 150 : return 30840;
        case 175 : return 32373;
        case 200 : return 44314;
        case 300 : return 49975;
        case 400 : return 56066;
        case 500 : return 70109;
        case 600 : return 79642;
        case 700 : return 75338;
        case 750 : return 85663;
        case 800 : return 88454;
        case 850 : return 93271;
        case 900 : return 85962;
        case 950 : return 85308;
        case 975 : return 103226;
        case 990 : return 120803;
    }
  }
    if (a==1050) {
      switch (b) {
        case 127 : return 31489;
        case 150 : return 28955;
        case 175 : return 30645;
        case 200 : return 45713;
        case 300 : return 67685;
        case 400 : return 65511;
        case 500 : return 81563;
        case 600 : return 86021;
        case 700 : return 90464;
        case 750 : return 90398;
        case 800 : return 99946;
        case 850 : return 101876;
        case 900 : return 102682;
        case 950 : return 91970;
        case 1000 : return 114246;
        case 1025 : return 115558;
        case 1040 : return 96028;
    }
  }
    if (a==1100) {
      switch (b) {
        case 127 : return 31605;
        case 150 : return 32506;
        case 175 : return 40161;
        case 200 : return 33152;
        case 300 : return 44516;
        case 400 : return 55094;
        case 500 : return 59253;
        case 600 : return 73756;
        case 700 : return 72665;
        case 800 : return 72641;
        case 850 : return 100678;
        case 900 : return 74029;
        case 950 : return 100596;
        case 1000 : return 100760;
        case 1050 : return 96204;
        case 1075 : return 96211;
        case 1090 : return 90009;
    }
  }
    if (a==1150) {
      switch (b) {
        case 127 : return 18528;
        case 150 : return 23730;
        case 175 : return 26137;
        case 200 : return 28989;
        case 300 : return 46293;
        case 400 : return 37322;
        case 500 : return 44634;
        case 600 : return 70919;
        case 700 : return 52524;
        case 800 : return 61456;
        case 850 : return 65089;
        case 900 : return 79858;
        case 950 : return 77848;
        case 1000 : return 79037;
        case 1050 : return 67512;
        case 1100 : return 77988;
        case 1125 : return 76395;
        case 1140 : return 64496;
    }
  }
    if (a==1200) {
      switch (b) {
        case 127 : return 7875;
        case 150 : return 16569;
        case 175 : return 13258;
        case 200 : return 19309;
        case 300 : return 28287;
        case 400 : return 27198;
        case 500 : return 29716;
        case 600 : return 37660;
        case 700 : return 34156;
        case 800 : return 38850;
        case 900 : return 38768;
        case 950 : return 41986;
        case 1000 : return 58823;
        case 1050 : return 68547;
        case 1100 : return 49914;
        case 1150 : return 55898;
        case 1175 : return 53546;
        case 1190 : return 42765;
    }
  }
    if (a==1250) {
      switch (b) {
        case 127 : return 7718;
        case 150 : return 13959;
        case 175 : return 12535;
        case 200 : return 14927;
        case 300 : return 18527;
        case 400 : return 26553;
        case 500 : return 22863;
        case 600 : return 35230;
        case 700 : return 36071;
        case 800 : return 34404;
        case 900 : return 28220;
        case 950 : return 36886;
        case 1000 : return 35938;
        case 1050 : return 33258;
        case 1100 : return 32460;
        case 1150 : return 43137;
        case 1200 : return 44717;
        case 1225 : return 43753;
        case 1240 : return 49014;
    }
  }
    if (a==1300) {
      switch (b) {
        case 127 : return 5217;
        case 150 : return 7018;
        case 175 : return 9700;
        case 200 : return 9633;
        case 300 : return 16709;
        case 400 : return 20308;
        case 500 : return 24713;
        case 600 : return 23082;
        case 700 : return 21836;
        case 800 : return 24634;
        case 900 : return 23878;
        case 1000 : return 30657;
        case 1050 : return 28079;
        case 1100 : return 28188;
        case 1150 : return 31719;
        case 1200 : return 25763;
        case 1250 : return 35489;
        case 1275 : return 27979;
        case 1290 : return 21919;
    }
  }
    if (a==1350) {
      switch (b) {
        case 127 : return 2647;
        case 150 : return 9767;
        case 175 : return 10698;
        case 200 : return 12357;
        case 300 : return 15953;
        case 400 : return 12543;
        case 500 : return 23608;
        case 600 : return 27399;
        case 700 : return 20225;
        case 800 : return 33704;
        case 900 : return 20484;
        case 1000 : return 31114;
        case 1050 : return 33634;
        case 1100 : return 36316;
        case 1150 : return 30072;
        case 1200 : return 23926;
        case 1250 : return 33840;
        case 1300 : return 44492;
        case 1325 : return 30833;
        case 1340 : return 26363;
    }
  }
    if (a==1400) {
      switch (b) {
        case 127 : return 7907;
        case 150 : return 8797;
        case 175 : return 3566;
        case 200 : return 8875;
        case 300 : return 9775;
        case 400 : return 23108;
        case 500 : return 16045;
        case 600 : return 21273;
        case 700 : return 15974;
        case 800 : return 25621;
        case 900 : return 25530;
        case 1000 : return 24407;
        case 1100 : return 31806;
        case 1150 : return 35250;
        case 1200 : return 23966;
        case 1250 : return 27611;
        case 1300 : return 24873;
        case 1350 : return 35400;
        case 1375 : return 23627;
        case 1390 : return 24799;
    }
  }
    if (a==1450) {
      switch (b) {
        case 127 : return 6193;
        case 150 : return 9022;
        case 175 : return 9841;
        case 200 : return 7154;
        case 300 : return 14257;
        case 400 : return 22591;
        case 500 : return 14313;
        case 600 : return 21258;
        case 700 : return 24048;
        case 800 : return 22279;
        case 900 : return 25159;
        case 1000 : return 26748;
        case 1100 : return 20308;
        case 1150 : return 34586;
        case 1200 : return 30261;
        case 1250 : return 24890;
        case 1300 : return 27473;
        case 1350 : return 32024;
        case 1400 : return 25708;
        case 1425 : return 23004;
        case 1440 : return 39231;
    }
  }
    if (a==1500) {
      switch (b) {
        case 127 : return 5319;
        case 150 : return 8114;
        case 175 : return 10788;
        case 200 : return 10612;
        case 300 : return 9012;
        case 400 : return 16181;
        case 500 : return 11638;
        case 600 : return 16929;
        case 700 : return 16014;
        case 800 : return 21510;
        case 900 : return 20543;
        case 1000 : return 24816;
        case 1100 : return 28372;
        case 1200 : return 27832;
        case 1250 : return 23308;
        case 1300 : return 31198;
        case 1350 : return 27695;
        case 1400 : return 32059;
        case 1450 : return 28563;
        case 1475 : return 31245;
        case 1490 : return 31015;
    }
  }
    if (a==1550) {
      switch (b) {
        case 127 : return 4475;
        case 150 : return 3584;
        case 175 : return 8138;
        case 200 : return 7979;
        case 300 : return 8979;
        case 400 : return 10694;
        case 500 : return 22704;
        case 600 : return 15323;
        case 700 : return 27582;
        case 800 : return 26849;
        case 900 : return 26430;
        case 1000 : return 29576;
        case 1100 : return 26983;
        case 1200 : return 29576;
        case 1250 : return 27796;
        case 1300 : return 29717;
        case 1350 : return 38601;
        case 1400 : return 26173;
        case 1450 : return 27184;
        case 1500 : return 39195;
        case 1525 : return 28863;
        case 1540 : return 31498;
    }
  }
    if (a==1600) {
      switch (b) {
        case 127 : return 10849;
        case 150 : return 6323;
        case 175 : return 7333;
        case 200 : return 10802;
        case 300 : return 17187;
        case 400 : return 15427;
        case 500 : return 13485;
        case 600 : return 16980;
        case 700 : return 20809;
        case 800 : return 16564;
        case 900 : return 22516;
        case 1000 : return 31441;
        case 1100 : return 23494;
        case 1200 : return 31764;
        case 1300 : return 42615;
        case 1350 : return 36158;
        case 1400 : return 40065;
        case 1450 : return 42578;
        case 1500 : return 31720;
        case 1550 : return 29872;
        case 1575 : return 42628;
        case 1590 : return 28009;
    }
  }
    if (a==1650) {
      switch (b) {
        case 127 : return 4583;
        case 150 : return 10909;
        case 175 : return 8199;
        case 200 : return 13601;
        case 300 : return 15677;
        case 400 : return 7288;
        case 500 : return 15691;
        case 600 : return 26528;
        case 700 : return 21830;
        case 800 : return 23718;
        case 900 : return 31123;
        case 1000 : return 29265;
        case 1100 : return 43528;
        case 1200 : return 23250;
        case 1300 : return 34609;
        case 1350 : return 23638;
        case 1400 : return 31009;
        case 1450 : return 34661;
        case 1500 : return 32654;
        case 1550 : return 41731;
        case 1600 : return 29061;
        case 1625 : return 29236;
        case 1640 : return 36090;
    }
  }
    if (a==1700) {
      switch (b) {
        case 127 : return 2735;
        case 150 : return 7456;
        case 175 : return 9163;
        case 200 : return 15731;
        case 300 : return 12695;
        case 400 : return 14675;
        case 500 : return 16277;
        case 600 : return 19918;
        case 700 : return 14845;
        case 800 : return 24648;
        case 900 : return 26634;
        case 1000 : return 32137;
        case 1100 : return 24851;
        case 1200 : return 32792;
        case 1300 : return 29452;
        case 1400 : return 25783;
        case 1450 : return 22750;
        case 1500 : return 26590;
        case 1550 : return 39235;
        case 1600 : return 34852;
        case 1650 : return 43049;
        case 1675 : return 33885;
        case 1690 : return 40948;
    }
  }
    if (a==1750) {
      switch (b) {
        case 127 : return 2740;
        case 150 : return 11124;
        case 175 : return 7381;
        case 200 : return 7289;
        case 300 : return 13784;
        case 400 : return 21310;
        case 500 : return 13911;
        case 600 : return 19500;
        case 700 : return 24183;
        case 800 : return 28568;
        case 900 : return 25910;
        case 1000 : return 35126;
        case 1100 : return 24229;
        case 1200 : return 27537;
        case 1300 : return 33334;
        case 1400 : return 27764;
        case 1450 : return 33860;
        case 1500 : return 24961;
        case 1550 : return 29398;
        case 1600 : return 39615;
        case 1650 : return 30629;
        case 1700 : return 30655;
        case 1725 : return 35800;
        case 1740 : return 29302;
    }
  }
    if (a==1800) {
      switch (b) {
        case 127 : return 7458;
        case 150 : return 5634;
        case 175 : return 11331;
        case 200 : return 12179;
        case 300 : return 18564;
        case 400 : return 11100;
        case 500 : return 16618;
        case 600 : return 18702;
        case 700 : return 22339;
        case 800 : return 22450;
        case 900 : return 29835;
        case 1000 : return 24112;
        case 1100 : return 20658;
        case 1200 : return 30905;
        case 1300 : return 32336;
        case 1400 : return 35401;
        case 1500 : return 32470;
        case 1550 : return 33332;
        case 1600 : return 29767;
        case 1650 : return 20437;
        case 1700 : return 27832;
        case 1750 : return 28792;
        case 1775 : return 32507;
        case 1790 : return 30736;
    }
  }
    if (a==1850) {
      switch (b) {
        case 127 : return 8452;
        case 150 : return 8478;
        case 175 : return 13197;
        case 200 : return 10274;
        case 300 : return 6584;
        case 400 : return 6626;
        case 500 : return 12162;
        case 600 : return 14017;
        case 700 : return 23262;
        case 800 : return 17969;
        case 900 : return 15157;
        case 1000 : return 29243;
        case 1100 : return 25321;
        case 1200 : return 25277;
        case 1300 : return 25731;
        case 1400 : return 30029;
        case 1500 : return 27314;
        case 1550 : return 36538;
        case 1600 : return 24503;
        case 1650 : return 41049;
        case 1700 : return 27302;
        case 1750 : return 32886;
        case 1800 : return 29098;
        case 1825 : return 35951;
        case 1840 : return 31755;
    }
  }
    if (a==1900) {
      switch (b) {
        case 127 : return 4681;
        case 150 : return 4891;
        case 175 : return 8610;
        case 200 : return 13969;
        case 300 : return 14970;
        case 400 : return 19102;
        case 500 : return 16130;
        case 600 : return 17139;
        case 700 : return 25655;
        case 800 : return 19239;
        case 900 : return 21714;
        case 1000 : return 34921;
        case 1100 : return 24676;
        case 1200 : return 28391;
        case 1300 : return 37824;
        case 1400 : return 36292;
        case 1500 : return 34121;
        case 1600 : return 31278;
        case 1650 : return 29727;
        case 1700 : return 36977;
        case 1750 : return 28606;
        case 1800 : return 32137;
        case 1850 : return 30316;
        case 1875 : return 28379;
        case 1890 : return 34132;
    }
  }
    if (a==1950) {
      switch (b) {
        case 127 : return 5714;
        case 150 : return 7645;
        case 175 : return 8671;
        case 200 : return 8631;
        case 300 : return 14463;
        case 400 : return 17149;
        case 500 : return 5702;
        case 600 : return 22027;
        case 700 : return 18140;
        case 800 : return 15068;
        case 900 : return 30529;
        case 1000 : return 22181;
        case 1100 : return 31563;
        case 1200 : return 37649;
        case 1300 : return 21263;
        case 1400 : return 36518;
        case 1500 : return 29065;
        case 1600 : return 36430;
        case 1650 : return 35685;
        case 1700 : return 38342;
        case 1750 : return 41132;
        case 1800 : return 36705;
        case 1850 : return 27689;
        case 1900 : return 44051;
        case 1925 : return 32619;
        case 1940 : return 36200;
    }
  }
    if (a==2000) {
      switch (b) {
        case 127 : return 4829;
        case 150 : return 3890;
        case 175 : return 4777;
        case 200 : return 5818;
        case 300 : return 3864;
        case 400 : return 1939;
        case 500 : return 11481;
        case 600 : return 10584;
        case 700 : return 9615;
        case 800 : return 11512;
        case 900 : return 13437;
        case 1000 : return 18448;
        case 1100 : return 9049;
        case 1200 : return 9818;
        case 1300 : return 6803;
        case 1400 : return 10722;
        case 1500 : return 13563;
        case 1600 : return 9682;
        case 1700 : return 15452;
        case 1750 : return 26130;
        case 1800 : return 17332;
        case 1850 : return 16474;
        case 1900 : return 19284;
        case 1950 : return 20129;
        case 1975 : return 13560;
        case 1990 : return 14425;
    }
  }
    if (a==2050) {
      switch (b) {
        case 127 : return 1984;
        case 150 : return 5901;
        case 175 : return 8784;
        case 200 : return 2877;
        case 300 : return 5821;
        case 400 : return 9679;
        case 500 : return 6909;
        case 600 : return 3990;
        case 700 : return 15438;
        case 800 : return 12731;
        case 900 : return 11629;
        case 1000 : return 14760;
        case 1100 : return 16411;
        case 1200 : return 17857;
        case 1300 : return 11675;
        case 1400 : return 16699;
        case 1500 : return 10767;
        case 1600 : return 20648;
        case 1700 : return 19626;
        case 1750 : return 20470;
        case 1800 : return 21535;
        case 1850 : return 17626;
        case 1900 : return 16652;
        case 1950 : return 16736;
        case 2000 : return 19723;
        case 2025 : return 15582;
        case 2040 : return 12507;
    }
  }
    if (a==2100) {
      switch (b) {
        case 127 : return 993;
        case 150 : return 990;
        case 175 : return 7977;
        case 200 : return 3941;
        case 300 : return 6958;
        case 400 : return 5986;
        case 500 : return 8001;
        case 600 : return 11899;
        case 700 : return 5896;
        case 800 : return 13872;
        case 900 : return 13970;
        case 1000 : return 14278;
        case 1100 : return 14845;
        case 1200 : return 14067;
        case 1300 : return 17672;
        case 1400 : return 17609;
        case 1500 : return 18751;
        case 1600 : return 6924;
        case 1700 : return 17836;
        case 1800 : return 17754;
        case 1850 : return 13988;
        case 1900 : return 10932;
        case 1950 : return 15934;
        case 2000 : return 14777;
        case 2050 : return 16735;
        case 2075 : return 16900;
        case 2090 : return 17692;
    }
  }
    if (a==2150) {
      switch (b) {
        case 127 : return 1955;
        case 150 : return 1963;
        case 175 : return 5108;
        case 200 : return 3014;
        case 300 : return 2993;
        case 400 : return 2052;
        case 500 : return 6934;
        case 600 : return 8159;
        case 700 : return 7070;
        case 800 : return 6901;
        case 900 : return 9149;
        case 1000 : return 11900;
        case 1100 : return 14835;
        case 1200 : return 18885;
        case 1300 : return 12096;
        case 1400 : return 16072;
        case 1500 : return 13000;
        case 1600 : return 17001;
        case 1700 : return 20047;
        case 1800 : return 9087;
        case 1850 : return 15982;
        case 1900 : return 21956;
        case 1950 : return 13764;
        case 2000 : return 12143;
        case 2050 : return 24131;
        case 2100 : return 12948;
        case 2125 : return 20946;
        case 2140 : return 14941;
    }
  }
    if (a==2200) {
      switch (b) {
        case 127 : return 3024;
        case 150 : return 6127;
        case 175 : return 7031;
        case 200 : return 9080;
        case 300 : return 7170;
        case 400 : return 11178;
        case 500 : return 13137;
        case 600 : return 10137;
        case 700 : return 13140;
        case 800 : return 7084;
        case 900 : return 13234;
        case 1000 : return 12132;
        case 1100 : return 16351;
        case 1200 : return 14089;
        case 1300 : return 16356;
        case 1400 : return 17120;
        case 1500 : return 17297;
        case 1600 : return 19481;
        case 1700 : return 14137;
        case 1800 : return 23508;
        case 1900 : return 17283;
        case 1950 : return 19361;
        case 2000 : return 17251;
        case 2050 : return 15310;
        case 2100 : return 18258;
        case 2150 : return 16212;
        case 2175 : return 20309;
        case 2190 : return 21316;
    }
  }
    if (a==2250) {
      switch (b) {
        case 127 : return 1036;
        case 150 : return 8444;
        case 175 : return 1000;
        case 200 : return 8160;
        case 300 : return 3186;
        case 400 : return 7245;
        case 500 : return 7194;
        case 600 : return 15344;
        case 700 : return 11295;
        case 800 : return 16500;
        case 900 : return 16574;
        case 1000 : return 7141;
        case 1100 : return 9409;
        case 1200 : return 15210;
        case 1300 : return 13415;
        case 1400 : return 10296;
        case 1500 : return 18391;
        case 1600 : return 17563;
        case 1700 : return 18776;
        case 1800 : return 18406;
        case 1900 : return 18638;
        case 1950 : return 20478;
        case 2000 : return 20660;
        case 2050 : return 18458;
        case 2100 : return 16530;
        case 2150 : return 11481;
        case 2200 : return 15444;
        case 2225 : return 15426;
        case 2240 : return 17363;
    }
  }
    if (a==2300) {
      switch (b) {
        case 127 : return 3227;
        case 150 : return 3049;
        case 175 : return 7315;
        case 200 : return 4206;
        case 300 : return 3212;
        case 400 : return 6341;
        case 500 : return 7285;
        case 600 : return 11376;
        case 700 : return 11358;
        case 800 : return 13572;
        case 900 : return 8424;
        case 1000 : return 12540;
        case 1100 : return 7292;
        case 1200 : return 19742;
        case 1300 : return 21120;
        case 1400 : return 11432;
        case 1500 : return 7397;
        case 1600 : return 27144;
        case 1700 : return 17640;
        case 1800 : return 13524;
        case 1900 : return 12476;
        case 2000 : return 18061;
        case 2050 : return 22926;
        case 2100 : return 17657;
        case 2150 : return 23015;
        case 2200 : return 13679;
        case 2250 : return 14636;
        case 2275 : return 15759;
        case 2290 : return 12426;
    }
  }
    if (a==2350) {
      switch (b) {
        case 127 : return 3094;
        case 150 : return 6392;
        case 175 : return 5263;
        case 200 : return 4261;
        case 300 : return 6361;
        case 400 : return 6417;
        case 500 : return 7454;
        case 600 : return 4213;
        case 700 : return 9452;
        case 800 : return 10619;
        case 900 : return 13695;
        case 1000 : return 14833;
        case 1100 : return 9570;
        case 1200 : return 19028;
        case 1300 : return 12726;
        case 1400 : return 10576;
        case 1500 : return 15846;
        case 1600 : return 15873;
        case 1700 : return 11602;
        case 1800 : return 19145;
        case 1900 : return 20239;
        case 2000 : return 18055;
        case 2050 : return 15029;
        case 2100 : return 8466;
        case 2150 : return 14905;
        case 2200 : return 16787;
        case 2250 : return 14988;
        case 2300 : return 12822;
        case 2325 : return 19208;
        case 2340 : return 23117;
    }
  }
    if (a==2400) {
      switch (b) {
        case 127 : return 4292;
        case 150 : return 3394;
        case 175 : return 1060;
        case 200 : return 7385;
        case 300 : return 7536;
        case 400 : return 3238;
        case 500 : return 9650;
        case 600 : return 10709;
        case 700 : return 11915;
        case 800 : return 6452;
        case 900 : return 5422;
        case 1000 : return 11909;
        case 1100 : return 12949;
        case 1200 : return 19361;
        case 1300 : return 13849;
        case 1400 : return 14020;
        case 1500 : return 18489;
        case 1600 : return 11930;
        case 1700 : return 17262;
        case 1800 : return 18301;
        case 1900 : return 15087;
        case 2000 : return 21712;
        case 2100 : return 17343;
        case 2150 : return 19228;
        case 2200 : return 8614;
        case 2250 : return 16152;
        case 2300 : return 20607;
        case 2350 : return 16102;
        case 2375 : return 16070;
        case 2390 : return 24586;
    }
  }
    if (a==2450) {
      switch (b) {
        case 127 : return 2176;
        case 150 : return 2227;
        case 175 : return 4347;
        case 200 : return 6548;
        case 300 : return 9800;
        case 400 : return 13187;
        case 500 : return 9820;
        case 600 : return 6518;
        case 700 : return 12092;
        case 800 : return 4423;
        case 900 : return 4284;
        case 1000 : return 3331;
        case 1100 : return 15249;
        case 1200 : return 21939;
        case 1300 : return 17631;
        case 1400 : return 11001;
        case 1500 : return 11070;
        case 1600 : return 16337;
        case 1700 : return 17513;
        case 1800 : return 24048;
        case 1900 : return 9829;
        case 2000 : return 18679;
        case 2100 : return 13153;
        case 2150 : return 12011;
        case 2200 : return 20980;
        case 2250 : return 14314;
        case 2300 : return 20658;
        case 2350 : return 19856;
        case 2400 : return 15426;
        case 2425 : return 14197;
        case 2440 : return 20863;
    }
  }
    if (a==2500) {
      switch (b) {
        case 127 : return 4415;
        case 150 : return 4488;
        case 175 : return 5559;
        case 200 : return 3315;
        case 300 : return 6611;
        case 400 : return 3381;
        case 500 : return 9948;
        case 600 : return 9973;
        case 700 : return 11153;
        case 800 : return 10026;
        case 900 : return 17835;
        case 1000 : return 12124;
        case 1100 : return 13223;
        case 1200 : return 21291;
        case 1300 : return 6730;
        case 1400 : return 7769;
        case 1500 : return 16689;
        case 1600 : return 17919;
        case 1700 : return 21245;
        case 1800 : return 15472;
        case 1900 : return 9056;
        case 2000 : return 12181;
        case 2100 : return 22252;
        case 2200 : return 13274;
        case 2250 : return 13357;
        case 2300 : return 23306;
        case 2350 : return 20032;
        case 2400 : return 17816;
        case 2450 : return 17846;
        case 2475 : return 19998;
        case 2490 : return 15482;
    }
  }
    if (a==2550) {
      switch (b) {
        case 127 : return 4558;
        case 150 : return 5727;
        case 175 : return 6751;
        case 200 : return 4512;
        case 300 : return 3418;
        case 400 : return 5580;
        case 500 : return 7974;
        case 600 : return 10263;
        case 700 : return 7867;
        case 800 : return 4484;
        case 900 : return 11256;
        case 1000 : return 9128;
        case 1100 : return 11260;
        case 1200 : return 11409;
        case 1300 : return 14779;
        case 1400 : return 15585;
        case 1500 : return 15774;
        case 1600 : return 13642;
        case 1700 : return 16101;
        case 1800 : return 17018;
        case 1900 : return 22785;
        case 2000 : return 20350;
        case 2100 : return 27200;
        case 2200 : return 19140;
        case 2250 : return 19228;
        case 2300 : return 16969;
        case 2350 : return 13533;
        case 2400 : return 14765;
        case 2450 : return 20419;
        case 2500 : return 12497;
        case 2525 : return 26037;
        case 2540 : return 15656;
    }
  }
    if (a==2600) {
      switch (b) {
        case 127 : return 4620;
        case 150 : return 7938;
        case 175 : return 5847;
        case 200 : return 4591;
        case 300 : return 7974;
        case 400 : return 15081;
        case 500 : return 9274;
        case 600 : return 12614;
        case 700 : return 9358;
        case 800 : return 18275;
        case 900 : return 10364;
        case 1000 : return 13712;
        case 1100 : return 17119;
        case 1200 : return 14952;
        case 1300 : return 15893;
        case 1400 : return 6887;
        case 1500 : return 10326;
        case 1600 : return 16213;
        case 1700 : return 27602;
        case 1800 : return 21704;
        case 1900 : return 19463;
        case 2000 : return 17240;
        case 2100 : return 17194;
        case 2200 : return 6970;
        case 2300 : return 16098;
        case 2350 : return 19650;
        case 2400 : return 10408;
        case 2450 : return 11428;
        case 2500 : return 24111;
        case 2550 : return 9278;
        case 2575 : return 19559;
        case 2590 : return 17165;
    }
  }
    if (a==2650) {
      switch (b) {
        case 127 : return 0;
        case 150 : return 3391;
        case 175 : return 2305;
        case 200 : return 8134;
        case 300 : return 7061;
        case 400 : return 1156;
        case 500 : return 8135;
        case 600 : return 9368;
        case 700 : return 5791;
        case 800 : return 8150;
        case 900 : return 16282;
        case 1000 : return 13048;
        case 1100 : return 16274;
        case 1200 : return 18651;
        case 1300 : return 11727;
        case 1400 : return 13851;
        case 1500 : return 14060;
        case 1600 : return 17582;
        case 1700 : return 22115;
        case 1800 : return 13921;
        case 1900 : return 12850;
        case 2000 : return 11568;
        case 2100 : return 10500;
        case 2200 : return 17435;
        case 2300 : return 12813;
        case 2350 : return 17405;
        case 2400 : return 18731;
        case 2450 : return 11620;
        case 2500 : return 17439;
        case 2550 : return 11679;
        case 2600 : return 15291;
        case 2625 : return 19863;
        case 2640 : return 5850;
    }
  }
    if (a==2700) {
      switch (b) {
        case 127 : return 3636;
        case 150 : return 1232;
        case 175 : return 3510;
        case 200 : return 8291;
        case 300 : return 11838;
        case 400 : return 11933;
        case 500 : return 10531;
        case 600 : return 8273;
        case 700 : return 5864;
        case 800 : return 11921;
        case 900 : return 8221;
        case 1000 : return 17689;
        case 1100 : return 20153;
        case 1200 : return 9489;
        case 1300 : return 13012;
        case 1400 : return 8282;
        case 1500 : return 14222;
        case 1600 : return 12041;
        case 1700 : return 11948;
        case 1800 : return 19065;
        case 1900 : return 21215;
        case 2000 : return 15498;
        case 2100 : return 20269;
        case 2200 : return 18991;
        case 2300 : return 20122;
        case 2400 : return 14335;
        case 2450 : return 21327;
        case 2500 : return 15338;
        case 2550 : return 16540;
        case 2600 : return 18997;
        case 2650 : return 6034;
        case 2675 : return 14316;
        case 2690 : return 14291;
    }
  }
    if (a==2750) {
      switch (b) {
        case 127 : return 7239;
        case 150 : return 2411;
        case 175 : return 5959;
        case 200 : return 2476;
        case 300 : return 5977;
        case 400 : return 8472;
        case 500 : return 6026;
        case 600 : return 4819;
        case 700 : return 7308;
        case 800 : return 6007;
        case 900 : return 10875;
        case 1000 : return 12030;
        case 1100 : return 19309;
        case 1200 : return 8405;
        case 1300 : return 22917;
        case 1400 : return 19331;
        case 1500 : return 16904;
        case 1600 : return 14453;
        case 1700 : return 19257;
        case 1800 : return 15695;
        case 1900 : return 16985;
        case 2000 : return 19493;
        case 2100 : return 13254;
        case 2200 : return 23101;
        case 2300 : return 18129;
        case 2400 : return 12072;
        case 2450 : return 16916;
        case 2500 : return 17045;
        case 2550 : return 7267;
        case 2600 : return 22955;
        case 2650 : return 16829;
        case 2700 : return 10863;
        case 2725 : return 20398;
        case 2740 : return 10829;
    }
  }
    if (a==2800) {
      switch (b) {
        case 127 : return 1212;
        case 150 : return 2461;
        case 175 : return 7424;
        case 200 : return 4904;
        case 300 : return 8623;
        case 400 : return 4929;
        case 500 : return 7497;
        case 600 : return 9789;
        case 700 : return 9973;
        case 800 : return 20850;
        case 900 : return 13498;
        case 1000 : return 13431;
        case 1100 : return 14677;
        case 1200 : return 20706;
        case 1300 : return 11118;
        case 1400 : return 18358;
        case 1500 : return 19623;
        case 1600 : return 7502;
        case 1700 : return 17163;
        case 1800 : return 22081;
        case 1900 : return 9880;
        case 2000 : return 14920;
        case 2100 : return 18353;
        case 2200 : return 24657;
        case 2300 : return 19787;
        case 2400 : return 20838;
        case 2500 : return 19662;
        case 2550 : return 14871;
        case 2600 : return 13621;
        case 2650 : return 7469;
        case 2700 : return 17272;
        case 2750 : return 7337;
        case 2775 : return 12422;
        case 2790 : return 10985;
    }
  }
      case 3017 :
    if (a==800) {
      switch (b) {
        case 127 : return 25279;
        case 200 : return 34563;
        case 300 : return 47255;
        case 400 : return 62052;
        case 500 : return 71250;
        case 600 : return 75480;
        case 700 : return 85422;
        case 790 : return 86123;
    }
  }
    if (a==900) {
      switch (b) {
        case 127 : return 13676;
        case 200 : return 32664;
        case 300 : return 55759;
        case 400 : return 65881;
        case 500 : return 59628;
        case 600 : return 58175;
        case 700 : return 73924;
        case 800 : return 81212;
        case 890 : return 70251;
    }
  }
    if (a==1000) {
      switch (b) {
        case 127 : return 24468;
        case 150 : return 17621;
        case 175 : return 35977;
        case 200 : return 41082;
        case 300 : return 52362;
        case 400 : return 62404;
        case 500 : return 64894;
        case 600 : return 71579;
        case 700 : return 64802;
        case 750 : return 62815;
        case 800 : return 81480;
        case 850 : return 85592;
        case 900 : return 95989;
        case 950 : return 85634;
        case 975 : return 95750;
        case 990 : return 95793;
    }
  }
    if (a==1050) {
      switch (b) {
        case 127 : return 20914;
        case 150 : return 27994;
        case 175 : return 39134;
        case 200 : return 46133;
        case 300 : return 43818;
        case 400 : return 65659;
        case 500 : return 60256;
        case 600 : return 59357;
        case 700 : return 76572;
        case 750 : return 73179;
        case 800 : return 72694;
        case 850 : return 79689;
        case 900 : return 78849;
        case 950 : return 90000;
        case 1000 : return 90876;
        case 1025 : return 94554;
        case 1040 : return 84313;
    }
  }
    if (a==1100) {
      switch (b) {
        case 127 : return 30256;
        case 150 : return 18192;
        case 175 : return 28804;
        case 200 : return 25104;
        case 300 : return 48083;
        case 400 : return 55686;
        case 500 : return 52294;
        case 600 : return 53928;
        case 700 : return 64696;
        case 800 : return 73154;
        case 850 : return 80832;
        case 900 : return 93424;
        case 950 : return 80403;
        case 1000 : return 84119;
        case 1050 : return 78404;
        case 1075 : return 95072;
        case 1090 : return 72174;
    }
  }
    if (a==1150) {
      switch (b) {
        case 127 : return 10506;
        case 150 : return 14902;
        case 175 : return 22520;
        case 200 : return 24451;
        case 300 : return 24483;
        case 400 : return 43619;
        case 500 : return 37626;
        case 600 : return 40038;
        case 700 : return 43757;
        case 800 : return 54591;
        case 850 : return 42770;
        case 900 : return 60466;
        case 950 : return 48826;
        case 1000 : return 56805;
        case 1050 : return 61758;
        case 1100 : return 69764;
        case 1125 : return 67580;
        case 1140 : return 72349;
    }
  }
    if (a==1200) {
      switch (b) {
        case 127 : return 7034;
        case 150 : return 8783;
        case 175 : return 17574;
        case 200 : return 16656;
        case 300 : return 22611;
        case 400 : return 23682;
        case 500 : return 30697;
        case 600 : return 22595;
        case 700 : return 27939;
        case 800 : return 29674;
        case 900 : return 40195;
        case 950 : return 40942;
        case 1000 : return 40196;
        case 1050 : return 36865;
        case 1100 : return 34372;
        case 1150 : return 38472;
        case 1175 : return 40044;
        case 1190 : return 44487;
    }
  }
    if (a==1250) {
      switch (b) {
        case 127 : return 6044;
        case 150 : return 5264;
        case 175 : return 6951;
        case 200 : return 4316;
        case 300 : return 21869;
        case 400 : return 13126;
        case 500 : return 21076;
        case 600 : return 24481;
        case 700 : return 21080;
        case 800 : return 30577;
        case 900 : return 32299;
        case 950 : return 29527;
        case 1000 : return 34136;
        case 1050 : return 26311;
        case 1100 : return 39392;
        case 1150 : return 28163;
        case 1200 : return 29964;
        case 1225 : return 34860;
        case 1240 : return 35830;
    }
  }
    if (a==1300) {
      switch (b) {
        case 127 : return 4447;
        case 150 : return 5292;
        case 175 : return 4382;
        case 200 : return 8779;
        case 300 : return 16511;
        case 400 : return 12935;
        case 500 : return 15779;
        case 600 : return 16829;
        case 700 : return 11311;
        case 800 : return 22261;
        case 900 : return 19392;
        case 1000 : return 35913;
        case 1050 : return 28226;
        case 1100 : return 25477;
        case 1150 : return 18391;
        case 1200 : return 21037;
        case 1250 : return 27910;
        case 1275 : return 23455;
        case 1290 : return 23558;
    }
  }
    if (a==1350) {
      switch (b) {
        case 127 : return 4437;
        case 150 : return 1715;
        case 175 : return 9733;
        case 200 : return 8830;
        case 300 : return 15885;
        case 400 : return 13291;
        case 500 : return 14133;
        case 600 : return 21123;
        case 700 : return 13179;
        case 800 : return 25671;
        case 900 : return 21187;
        case 1000 : return 21201;
        case 1050 : return 22042;
        case 1100 : return 35853;
        case 1150 : return 28023;
        case 1200 : return 30027;
        case 1250 : return 30635;
        case 1300 : return 26655;
        case 1325 : return 30559;
        case 1340 : return 28330;
    }
  }
    if (a==1400) {
      switch (b) {
        case 127 : return 2712;
        case 150 : return 7969;
        case 175 : return 7925;
        case 200 : return 9640;
        case 300 : return 9626;
        case 400 : return 12541;
        case 500 : return 20188;
        case 600 : return 12531;
        case 700 : return 14183;
        case 800 : return 18738;
        case 900 : return 19405;
        case 1000 : return 22048;
        case 1100 : return 28095;
        case 1150 : return 31174;
        case 1200 : return 27433;
        case 1250 : return 24737;
        case 1300 : return 30263;
        case 1350 : return 22974;
        case 1375 : return 21278;
        case 1390 : return 20365;
    }
  }
    if (a==1450) {
      switch (b) {
        case 127 : return 5248;
        case 150 : return 6269;
        case 175 : return 8844;
        case 200 : return 9756;
        case 300 : return 7025;
        case 400 : return 16702;
        case 500 : return 16943;
        case 600 : return 20558;
        case 700 : return 13456;
        case 800 : return 24907;
        case 900 : return 22208;
        case 1000 : return 18708;
        case 1100 : return 17880;
        case 1150 : return 26949;
        case 1200 : return 34522;
        case 1250 : return 30088;
        case 1300 : return 28403;
        case 1350 : return 30231;
        case 1400 : return 31159;
        case 1425 : return 28366;
        case 1440 : return 26661;
    }
  }
    if (a==1500) {
      switch (b) {
        case 127 : return 5313;
        case 150 : return 13552;
        case 175 : return 5278;
        case 200 : return 14163;
        case 300 : return 7849;
        case 400 : return 15338;
        case 500 : return 19644;
        case 600 : return 19623;
        case 700 : return 18702;
        case 800 : return 13319;
        case 900 : return 12436;
        case 1000 : return 15098;
        case 1100 : return 28038;
        case 1200 : return 22194;
        case 1250 : return 21347;
        case 1300 : return 33022;
        case 1350 : return 32085;
        case 1400 : return 33950;
        case 1450 : return 36883;
        case 1475 : return 20230;
        case 1490 : return 30216;
    }
  }
    if (a==1550) {
      switch (b) {
        case 127 : return 8036;
        case 150 : return 8100;
        case 175 : return 5334;
        case 200 : return 9028;
        case 300 : return 12543;
        case 400 : return 8059;
        case 500 : return 10686;
        case 600 : return 22347;
        case 700 : return 16059;
        case 800 : return 21611;
        case 900 : return 15157;
        case 1000 : return 29515;
        case 1100 : return 24223;
        case 1200 : return 26865;
        case 1250 : return 16123;
        case 1300 : return 24070;
        case 1350 : return 26764;
        case 1400 : return 35128;
        case 1450 : return 21594;
        case 1500 : return 23406;
        case 1525 : return 25337;
        case 1540 : return 22214;
    }
  }
    if (a==1600) {
      switch (b) {
        case 127 : return 4457;
        case 150 : return 2679;
        case 175 : return 6335;
        case 200 : return 12599;
        case 300 : return 10849;
        case 400 : return 11836;
        case 500 : return 15399;
        case 600 : return 12490;
        case 700 : return 24457;
        case 800 : return 22620;
        case 900 : return 15248;
        case 1000 : return 19761;
        case 1100 : return 27861;
        case 1200 : return 21689;
        case 1300 : return 28756;
        case 1350 : return 25313;
        case 1400 : return 44021;
        case 1450 : return 29759;
        case 1500 : return 28047;
        case 1550 : return 26194;
        case 1575 : return 35978;
        case 1590 : return 41538;
    }
  }
    if (a==1650) {
      switch (b) {
        case 127 : return 7341;
        case 150 : return 5522;
        case 175 : return 6383;
        case 200 : return 11708;
        case 300 : return 12631;
        case 400 : return 13615;
        case 500 : return 11704;
        case 600 : return 8221;
        case 700 : return 19919;
        case 800 : return 20952;
        case 900 : return 13516;
        case 1000 : return 25508;
        case 1100 : return 22063;
        case 1200 : return 18872;
        case 1300 : return 20837;
        case 1350 : return 36283;
        case 1400 : return 27512;
        case 1450 : return 34451;
        case 1500 : return 33806;
        case 1550 : return 27021;
        case 1600 : return 26246;
        case 1625 : return 31709;
        case 1640 : return 32518;
    }
  }
    if (a==1700) {
      switch (b) {
        case 127 : return 3633;
        case 150 : return 2745;
        case 175 : return 5600;
        case 200 : return 10162;
        case 300 : return 13551;
        case 400 : return 20062;
        case 500 : return 17465;
        case 600 : return 17303;
        case 700 : return 21718;
        case 800 : return 21528;
        case 900 : return 16708;
        case 1000 : return 23072;
        case 1100 : return 25435;
        case 1200 : return 31005;
        case 1300 : return 17210;
        case 1400 : return 32172;
        case 1450 : return 31259;
        case 1500 : return 34929;
        case 1550 : return 39474;
        case 1600 : return 28148;
        case 1650 : return 18235;
        case 1675 : return 31916;
        case 1690 : return 24458;
    }
  }
    if (a==1750) {
      switch (b) {
        case 127 : return 6458;
        case 150 : return 6438;
        case 175 : return 7375;
        case 200 : return 7448;
        case 300 : return 6443;
        case 400 : return 13825;
        case 500 : return 20202;
        case 600 : return 18627;
        case 700 : return 18396;
        case 800 : return 15640;
        case 900 : return 23923;
        case 1000 : return 21909;
        case 1100 : return 18281;
        case 1200 : return 18309;
        case 1300 : return 29326;
        case 1400 : return 29361;
        case 1450 : return 27669;
        case 1500 : return 27734;
        case 1550 : return 31321;
        case 1600 : return 34229;
        case 1650 : return 31390;
        case 1700 : return 37001;
        case 1725 : return 27653;
        case 1740 : return 32871;
    }
  }
    if (a==1800) {
      switch (b) {
        case 127 : return 5616;
        case 150 : return 5635;
        case 175 : return 13947;
        case 200 : return 10287;
        case 300 : return 21189;
        case 400 : return 13109;
        case 500 : return 12045;
        case 600 : return 9175;
        case 700 : return 14744;
        case 800 : return 13164;
        case 900 : return 20648;
        case 1000 : return 27998;
        case 1100 : return 15868;
        case 1200 : return 27935;
        case 1300 : return 31517;
        case 1400 : return 25906;
        case 1500 : return 26953;
        case 1550 : return 27068;
        case 1600 : return 37286;
        case 1650 : return 25951;
        case 1700 : return 38117;
        case 1750 : return 20353;
        case 1775 : return 35240;
        case 1790 : return 27123;
    }
  }
    if (a==1850) {
      switch (b) {
        case 127 : return 4661;
        case 150 : return 957;
        case 175 : return 5666;
        case 200 : return 11245;
        case 300 : return 5743;
        case 400 : return 11155;
        case 500 : return 6502;
        case 600 : return 25292;
        case 700 : return 12123;
        case 800 : return 16036;
        case 900 : return 26290;
        case 1000 : return 22942;
        case 1100 : return 21578;
        case 1200 : return 29985;
        case 1300 : return 18738;
        case 1400 : return 36348;
        case 1500 : return 31857;
        case 1550 : return 28133;
        case 1600 : return 32848;
        case 1650 : return 27111;
        case 1700 : return 24356;
        case 1750 : return 35551;
        case 1800 : return 30983;
        case 1825 : return 26171;
        case 1840 : return 36541;
    }
  }
    if (a==1900) {
      switch (b) {
        case 127 : return 2849;
        case 150 : return 4717;
        case 175 : return 7560;
        case 200 : return 4686;
        case 300 : return 10343;
        case 400 : return 14180;
        case 500 : return 5724;
        case 600 : return 16035;
        case 700 : return 15171;
        case 800 : return 24643;
        case 900 : return 16034;
        case 1000 : return 26404;
        case 1100 : return 41472;
        case 1200 : return 37849;
        case 1300 : return 21791;
        case 1400 : return 35223;
        case 1500 : return 34308;
        case 1600 : return 22771;
        case 1650 : return 30240;
        case 1700 : return 37735;
        case 1750 : return 33398;
        case 1800 : return 28391;
        case 1850 : return 34185;
        case 1875 : return 24558;
        case 1890 : return 33148;
    }
  }
    if (a==1950) {
      switch (b) {
        case 127 : return 7594;
        case 150 : return 7749;
        case 175 : return 3821;
        case 200 : return 12445;
        case 300 : return 12314;
        case 400 : return 12493;
        case 500 : return 18124;
        case 600 : return 14227;
        case 700 : return 22044;
        case 800 : return 18115;
        case 900 : return 25808;
        case 1000 : return 29451;
        case 1100 : return 21848;
        case 1200 : return 24704;
        case 1300 : return 33536;
        case 1400 : return 25625;
        case 1500 : return 33007;
        case 1600 : return 37040;
        case 1650 : return 27813;
        case 1700 : return 31839;
        case 1750 : return 35523;
        case 1800 : return 28748;
        case 1850 : return 22985;
        case 1900 : return 30713;
        case 1925 : return 32546;
        case 1940 : return 18200;
    }
  }
    if (a==2000) {
      switch (b) {
        case 127 : return 0;
        case 150 : return 2892;
        case 175 : return 6596;
        case 200 : return 5832;
        case 300 : return 3914;
        case 400 : return 4868;
        case 500 : return 10579;
        case 600 : return 8668;
        case 700 : return 8673;
        case 800 : return 8761;
        case 900 : return 14386;
        case 1000 : return 6681;
        case 1100 : return 10688;
        case 1200 : return 9721;
        case 1300 : return 20446;
        case 1400 : return 13473;
        case 1500 : return 11014;
        case 1600 : return 17646;
        case 1700 : return 16578;
        case 1750 : return 16329;
        case 1800 : return 16402;
        case 1850 : return 17441;
        case 1900 : return 22152;
        case 1950 : return 18254;
        case 1975 : return 23216;
        case 1990 : return 12562;
    }
  }
    if (a==2050) {
      switch (b) {
        case 127 : return 1946;
        case 150 : return 958;
        case 175 : return 2889;
        case 200 : return 6737;
        case 300 : return 4937;
        case 400 : return 10733;
        case 500 : return 7788;
        case 600 : return 3895;
        case 700 : return 10694;
        case 800 : return 4909;
        case 900 : return 8856;
        case 1000 : return 12759;
        case 1100 : return 10656;
        case 1200 : return 17619;
        case 1300 : return 12654;
        case 1400 : return 20423;
        case 1500 : return 9692;
        case 1600 : return 14750;
        case 1700 : return 25756;
        case 1750 : return 15631;
        case 1800 : return 17403;
        case 1850 : return 10813;
        case 1900 : return 10594;
        case 1950 : return 8634;
        case 2000 : return 12659;
        case 2025 : return 18575;
        case 2040 : return 19522;
    }
  }
    if (a==2100) {
      switch (b) {
        case 127 : return 1946;
        case 150 : return 1925;
        case 175 : return 7903;
        case 200 : return 3979;
        case 300 : return 7048;
        case 400 : return 9747;
        case 500 : return 2855;
        case 600 : return 4959;
        case 700 : return 5945;
        case 800 : return 6826;
        case 900 : return 15725;
        case 1000 : return 7887;
        case 1100 : return 6845;
        case 1200 : return 13762;
        case 1300 : return 17599;
        case 1400 : return 22837;
        case 1500 : return 17936;
        case 1600 : return 13779;
        case 1700 : return 16886;
        case 1800 : return 15918;
        case 1850 : return 11832;
        case 1900 : return 10918;
        case 1950 : return 12748;
        case 2000 : return 15826;
        case 2050 : return 8862;
        case 2075 : return 15896;
        case 2090 : return 23023;
    }
  }
    if (a==2150) {
      switch (b) {
        case 127 : return 6048;
        case 150 : return 2963;
        case 175 : return 1957;
        case 200 : return 4049;
        case 300 : return 7933;
        case 400 : return 9919;
        case 500 : return 4982;
        case 600 : return 9969;
        case 700 : return 5051;
        case 800 : return 11076;
        case 900 : return 8104;
        case 1000 : return 8373;
        case 1100 : return 15005;
        case 1200 : return 10962;
        case 1300 : return 7004;
        case 1400 : return 11036;
        case 1500 : return 8982;
        case 1600 : return 8050;
        case 1700 : return 14997;
        case 1800 : return 13909;
        case 1850 : return 14888;
        case 1900 : return 14862;
        case 1950 : return 24875;
        case 2000 : return 14956;
        case 2050 : return 18045;
        case 2100 : return 14974;
        case 2125 : return 17884;
        case 2140 : return 10928;
    }
  }
    if (a==2200) {
      switch (b) {
        case 127 : return 1056;
        case 150 : return 1998;
        case 175 : return 2032;
        case 200 : return 6145;
        case 300 : return 10063;
        case 400 : return 12058;
        case 500 : return 11114;
        case 600 : return 10174;
        case 700 : return 9173;
        case 800 : return 12081;
        case 900 : return 9052;
        case 1000 : return 11238;
        case 1100 : return 15240;
        case 1200 : return 7047;
        case 1300 : return 13254;
        case 1400 : return 16080;
        case 1500 : return 11118;
        case 1600 : return 15371;
        case 1700 : return 12251;
        case 1800 : return 21383;
        case 1900 : return 15272;
        case 1950 : return 14300;
        case 2000 : return 27134;
        case 2050 : return 21301;
        case 2100 : return 20190;
        case 2150 : return 16263;
        case 2175 : return 16174;
        case 2190 : return 15102;
    }
  }
    if (a==2250) {
      switch (b) {
        case 127 : return 2065;
        case 150 : return 5152;
        case 175 : return 3077;
        case 200 : return 4049;
        case 300 : return 7236;
        case 400 : return 6199;
        case 500 : return 4149;
        case 600 : return 5095;
        case 700 : return 8268;
        case 800 : return 11306;
        case 900 : return 11361;
        case 1000 : return 8313;
        case 1100 : return 8367;
        case 1200 : return 16588;
        case 1300 : return 14339;
        case 1400 : return 14372;
        case 1500 : return 13323;
        case 1600 : return 11369;
        case 1700 : return 15192;
        case 1800 : return 11148;
        case 1900 : return 20673;
        case 1950 : return 22445;
        case 2000 : return 15331;
        case 2050 : return 14468;
        case 2100 : return 17448;
        case 2150 : return 15232;
        case 2200 : return 19438;
        case 2225 : return 15500;
        case 2240 : return 22428;
    }
  }
    if (a==2300) {
      switch (b) {
        case 127 : return 4194;
        case 150 : return 5238;
        case 175 : return 6182;
        case 200 : return 6230;
        case 300 : return 4113;
        case 400 : return 7287;
        case 500 : return 4230;
        case 600 : return 7279;
        case 700 : return 5236;
        case 800 : return 8261;
        case 900 : return 12607;
        case 1000 : return 10782;
        case 1100 : return 15768;
        case 1200 : return 10309;
        case 1300 : return 11523;
        case 1400 : return 13595;
        case 1500 : return 16638;
        case 1600 : return 11622;
        case 1700 : return 19940;
        case 1800 : return 12522;
        case 1900 : return 15568;
        case 2000 : return 12432;
        case 2050 : return 17719;
        case 2100 : return 22901;
        case 2150 : return 15560;
        case 2200 : return 20952;
        case 2250 : return 25044;
        case 2275 : return 17868;
        case 2290 : return 26033;
    }
  }
    if (a==2350) {
      switch (b) {
        case 127 : return 3127;
        case 150 : return 4173;
        case 175 : return 6435;
        case 200 : return 6346;
        case 300 : return 5226;
        case 400 : return 3238;
        case 500 : return 3142;
        case 600 : return 5258;
        case 700 : return 6374;
        case 800 : return 9497;
        case 900 : return 6354;
        case 1000 : return 13641;
        case 1100 : return 15266;
        case 1200 : return 15739;
        case 1300 : return 12696;
        case 1400 : return 10733;
        case 1500 : return 17030;
        case 1600 : return 14885;
        case 1700 : return 8472;
        case 1800 : return 20020;
        case 1900 : return 17043;
        case 2000 : return 24121;
        case 2050 : return 17819;
        case 2100 : return 14749;
        case 2150 : return 11706;
        case 2200 : return 21262;
        case 2250 : return 20151;
        case 2300 : return 18983;
        case 2325 : return 14664;
        case 2340 : return 13821;
    }
  }
    if (a==2400) {
      switch (b) {
        case 127 : return 3240;
        case 150 : return 1090;
        case 175 : return 3243;
        case 200 : return 2148;
        case 300 : return 3253;
        case 400 : return 5376;
        case 500 : return 2112;
        case 600 : return 6407;
        case 700 : return 9586;
        case 800 : return 11819;
        case 900 : return 7667;
        case 1000 : return 8608;
        case 1100 : return 10706;
        case 1200 : return 18300;
        case 1300 : return 17175;
        case 1400 : return 12840;
        case 1500 : return 12895;
        case 1600 : return 16051;
        case 1700 : return 9770;
        case 1800 : return 12871;
        case 1900 : return 15067;
        case 2000 : return 11864;
        case 2100 : return 10774;
        case 2150 : return 14969;
        case 2200 : return 14973;
        case 2250 : return 16100;
        case 2300 : return 18319;
        case 2350 : return 18311;
        case 2375 : return 17215;
        case 2390 : return 11712;
    }
  }
    if (a==2450) {
      switch (b) {
        case 127 : return 4369;
        case 150 : return 3273;
        case 175 : return 4344;
        case 200 : return 5450;
        case 300 : return 1104;
        case 400 : return 4337;
        case 500 : return 4436;
        case 600 : return 8781;
        case 700 : return 9784;
        case 800 : return 11787;
        case 900 : return 8753;
        case 1000 : return 8802;
        case 1100 : return 7707;
        case 1200 : return 9886;
        case 1300 : return 19706;
        case 1400 : return 12117;
        case 1500 : return 21712;
        case 1600 : return 8767;
        case 1700 : return 12162;
        case 1800 : return 15277;
        case 1900 : return 14258;
        case 2000 : return 17283;
        case 2100 : return 18601;
        case 2150 : return 19637;
        case 2200 : return 16353;
        case 2250 : return 16356;
        case 2300 : return 12983;
        case 2350 : return 17370;
        case 2400 : return 14132;
        case 2425 : return 12137;
        case 2440 : return 6491;
    }
  }
    if (a==2500) {
      switch (b) {
        case 127 : return 2225;
        case 150 : return 1088;
        case 175 : return 7771;
        case 200 : return 7824;
        case 300 : return 4468;
        case 400 : return 3227;
        case 500 : return 10970;
        case 600 : return 7759;
        case 700 : return 11117;
        case 800 : return 6566;
        case 900 : return 7812;
        case 1000 : return 10030;
        case 1100 : return 12145;
        case 1200 : return 20007;
        case 1300 : return 8880;
        case 1400 : return 13363;
        case 1500 : return 17740;
        case 1600 : return 16791;
        case 1700 : return 12195;
        case 1800 : return 16627;
        case 1900 : return 12235;
        case 2000 : return 21024;
        case 2100 : return 12377;
        case 2200 : return 9857;
        case 2250 : return 19936;
        case 2300 : return 16613;
        case 2350 : return 16764;
        case 2400 : return 13305;
        case 2450 : return 15446;
        case 2475 : return 17685;
        case 2490 : return 11007;
    }
  }
    if (a==2550) {
      switch (b) {
        case 127 : return 4471;
        case 150 : return 5663;
        case 175 : return 7892;
        case 200 : return 2232;
        case 300 : return 4405;
        case 400 : return 4586;
        case 500 : return 6752;
        case 600 : return 7909;
        case 700 : return 8932;
        case 800 : return 11244;
        case 900 : return 14743;
        case 1000 : return 7879;
        case 1100 : return 6797;
        case 1200 : return 13413;
        case 1300 : return 13494;
        case 1400 : return 10135;
        case 1500 : return 13505;
        case 1600 : return 13473;
        case 1700 : return 14719;
        case 1800 : return 13554;
        case 1900 : return 14712;
        case 2000 : return 18245;
        case 2100 : return 10133;
        case 2200 : return 13455;
        case 2250 : return 15911;
        case 2300 : return 20435;
        case 2350 : return 15750;
        case 2400 : return 27985;
        case 2450 : return 19228;
        case 2500 : return 21392;
        case 2525 : return 17139;
        case 2540 : return 18873;
    }
  }
    if (a==2600) {
      switch (b) {
        case 127 : return 2336;
        case 150 : return 4610;
        case 175 : return 4577;
        case 200 : return 6735;
        case 300 : return 6860;
        case 400 : return 8134;
        case 500 : return 13700;
        case 600 : return 6697;
        case 700 : return 7953;
        case 800 : return 8048;
        case 900 : return 13649;
        case 1000 : return 9492;
        case 1100 : return 9229;
        case 1200 : return 22951;
        case 1300 : return 9111;
        case 1400 : return 16051;
        case 1500 : return 20522;
        case 1600 : return 14837;
        case 1700 : return 13661;
        case 1800 : return 12653;
        case 1900 : return 11449;
        case 2000 : return 19463;
        case 2100 : return 12717;
        case 2200 : return 21758;
        case 2300 : return 14818;
        case 2350 : return 13808;
        case 2400 : return 9254;
        case 2450 : return 19387;
        case 2500 : return 11531;
        case 2550 : return 16019;
        case 2575 : return 14801;
        case 2590 : return 11417;
    }
  }
    if (a==2650) {
      switch (b) {
        case 127 : return 4672;
        case 150 : return 2317;
        case 175 : return 4685;
        case 200 : return 5873;
        case 300 : return 1181;
        case 400 : return 1212;
        case 500 : return 1140;
        case 600 : return 2338;
        case 700 : return 8124;
        case 800 : return 11734;
        case 900 : return 9392;
        case 1000 : return 15646;
        case 1100 : return 11730;
        case 1200 : return 7053;
        case 1300 : return 5738;
        case 1400 : return 19679;
        case 1500 : return 10376;
        case 1600 : return 11585;
        case 1700 : return 10533;
        case 1800 : return 6915;
        case 1900 : return 14056;
        case 2000 : return 15055;
        case 2100 : return 17547;
        case 2200 : return 11624;
        case 2300 : return 16388;
        case 2350 : return 12780;
        case 2400 : return 11586;
        case 2450 : return 11632;
        case 2500 : return 9293;
        case 2550 : return 13809;
        case 2600 : return 15161;
        case 2625 : return 19757;
        case 2640 : return 17360;
    }
  }
    if (a==2700) {
      switch (b) {
        case 127 : return 1168;
        case 150 : return 0;
        case 175 : return 1202;
        case 200 : return 2423;
        case 300 : return 7089;
        case 400 : return 7129;
        case 500 : return 3564;
        case 600 : return 5905;
        case 700 : return 5927;
        case 800 : return 13027;
        case 900 : return 4735;
        case 1000 : return 7045;
        case 1100 : return 10770;
        case 1200 : return 13048;
        case 1300 : return 13009;
        case 1400 : return 15421;
        case 1500 : return 13191;
        case 1600 : return 16631;
        case 1700 : return 19991;
        case 1800 : return 16740;
        case 1900 : return 26213;
        case 2000 : return 11884;
        case 2100 : return 14337;
        case 2200 : return 22448;
        case 2300 : return 18816;
        case 2400 : return 16653;
        case 2450 : return 15613;
        case 2500 : return 16624;
        case 2550 : return 17760;
        case 2600 : return 17649;
        case 2650 : return 14106;
        case 2675 : return 14240;
        case 2690 : return 15461;
    }
  }
    if (a==2750) {
      switch (b) {
        case 127 : return 3619;
        case 150 : return 2430;
        case 175 : return 6006;
        case 200 : return 8373;
        case 300 : return 7208;
        case 400 : return 12094;
        case 500 : return 4857;
        case 600 : return 7237;
        case 700 : return 8528;
        case 800 : return 9622;
        case 900 : return 6036;
        case 1000 : return 14572;
        case 1100 : return 13204;
        case 1200 : return 14330;
        case 1300 : return 8544;
        case 1400 : return 10837;
        case 1500 : return 10945;
        case 1600 : return 10971;
        case 1700 : return 9631;
        case 1800 : return 10771;
        case 1900 : return 11956;
        case 2000 : return 13352;
        case 2100 : return 18199;
        case 2200 : return 18140;
        case 2300 : return 21602;
        case 2400 : return 14355;
        case 2450 : return 14606;
        case 2500 : return 10729;
        case 2550 : return 14220;
        case 2600 : return 21701;
        case 2650 : return 15882;
        case 2700 : return 15702;
        case 2725 : return 27704;
        case 2740 : return 14421;
    }
  }
    if (a==2800) {
      switch (b) {
        case 127 : return 3616;
        case 150 : return 0;
        case 175 : return 3712;
        case 200 : return 4985;
        case 300 : return 6118;
        case 400 : return 4924;
        case 500 : return 4983;
        case 600 : return 6087;
        case 700 : return 6163;
        case 800 : return 14769;
        case 900 : return 7365;
        case 1000 : return 8530;
        case 1100 : return 13479;
        case 1200 : return 12313;
        case 1300 : return 21146;
        case 1400 : return 20810;
        case 1500 : return 11004;
        case 1600 : return 15843;
        case 1700 : return 11115;
        case 1800 : return 17095;
        case 1900 : return 12218;
        case 2000 : return 11058;
        case 2100 : return 20895;
        case 2200 : return 14815;
        case 2300 : return 19693;
        case 2400 : return 13582;
        case 2500 : return 15926;
        case 2550 : return 15840;
        case 2600 : return 17193;
        case 2650 : return 19554;
        case 2700 : return 18289;
        case 2750 : return 9806;
        case 2775 : return 13369;
        case 2790 : return 21980;
    }
  }
      case 3018 :
    if (a==800) {
      switch (b) {
        case 127 : return 105701;
        case 200 : return 136705;
        case 300 : return 151198;
        case 400 : return 147700;
        case 500 : return 161861;
        case 600 : return 155942;
        case 700 : return 165482;
        case 790 : return 164069;
    }
  }
    if (a==900) {
      switch (b) {
        case 127 : return 89570;
        case 200 : return 127060;
        case 300 : return 133233;
        case 400 : return 154714;
        case 500 : return 128686;
        case 600 : return 167534;
        case 700 : return 178611;
        case 800 : return 176000;
        case 890 : return 166779;
    }
  }
    if (a==1000) {
      switch (b) {
        case 127 : return 92239;
        case 150 : return 121582;
        case 175 : return 117301;
        case 200 : return 116451;
        case 300 : return 130376;
        case 400 : return 124636;
        case 500 : return 160225;
        case 600 : return 142057;
        case 700 : return 149892;
        case 750 : return 151080;
        case 800 : return 178287;
        case 850 : return 176808;
        case 900 : return 169388;
        case 950 : return 195645;
        case 975 : return 184982;
        case 990 : return 179645;
    }
  }
    if (a==1050) {
      switch (b) {
        case 127 : return 75681;
        case 150 : return 94317;
        case 175 : return 108495;
        case 200 : return 112814;
        case 300 : return 131443;
        case 400 : return 119241;
        case 500 : return 149665;
        case 600 : return 183376;
        case 700 : return 174026;
        case 750 : return 167100;
        case 800 : return 175558;
        case 850 : return 139133;
        case 900 : return 179592;
        case 950 : return 167206;
        case 1000 : return 164244;
        case 1025 : return 182870;
        case 1040 : return 214101;
    }
  }
    if (a==1100) {
      switch (b) {
        case 127 : return 79960;
        case 150 : return 86459;
        case 175 : return 102516;
        case 200 : return 100231;
        case 300 : return 121852;
        case 400 : return 109013;
        case 500 : return 145937;
        case 600 : return 127956;
        case 700 : return 161813;
        case 800 : return 145610;
        case 850 : return 147017;
        case 900 : return 161085;
        case 950 : return 160721;
        case 1000 : return 179617;
        case 1050 : return 155145;
        case 1075 : return 168580;
        case 1090 : return 167284;
    }
  }
    if (a==1150) {
      switch (b) {
        case 127 : return 57441;
        case 150 : return 66927;
        case 175 : return 74821;
        case 200 : return 91758;
        case 300 : return 88571;
        case 400 : return 90483;
        case 500 : return 88365;
        case 600 : return 120596;
        case 700 : return 105492;
        case 800 : return 107908;
        case 850 : return 114084;
        case 900 : return 129215;
        case 950 : return 115752;
        case 1000 : return 129957;
        case 1050 : return 117890;
        case 1100 : return 125630;
        case 1125 : return 140676;
        case 1140 : return 139584;
    }
  }
    if (a==1200) {
      switch (b) {
        case 127 : return 45666;
        case 150 : return 52245;
        case 175 : return 43939;
        case 200 : return 42002;
        case 300 : return 51270;
        case 400 : return 64750;
        case 500 : return 71313;
        case 600 : return 64674;
        case 700 : return 78789;
        case 800 : return 84048;
        case 900 : return 89227;
        case 950 : return 60184;
        case 1000 : return 84012;
        case 1050 : return 70231;
        case 1100 : return 85704;
        case 1150 : return 88383;
        case 1175 : return 103812;
        case 1190 : return 78096;
    }
  }
    if (a==1250) {
      switch (b) {
        case 127 : return 27491;
        case 150 : return 40159;
        case 175 : return 23782;
        case 200 : return 26662;
        case 300 : return 42024;
        case 400 : return 44916;
        case 500 : return 44173;
        case 600 : return 64439;
        case 700 : return 57877;
        case 800 : return 49432;
        case 900 : return 73996;
        case 950 : return 58733;
        case 1000 : return 53735;
        case 1050 : return 58033;
        case 1100 : return 70023;
        case 1150 : return 65072;
        case 1200 : return 54151;
        case 1225 : return 72536;
        case 1240 : return 75159;
    }
  }
    if (a==1300) {
      switch (b) {
        case 127 : return 18283;
        case 150 : return 26709;
        case 175 : return 25756;
        case 200 : return 31142;
        case 300 : return 37497;
        case 400 : return 40182;
        case 500 : return 39721;
        case 600 : return 37608;
        case 700 : return 36738;
        case 800 : return 43175;
        case 900 : return 56840;
        case 1000 : return 59666;
        case 1050 : return 41534;
        case 1100 : return 52407;
        case 1150 : return 69747;
        case 1200 : return 50934;
        case 1250 : return 53976;
        case 1275 : return 58541;
        case 1290 : return 60520;
    }
  }
    if (a==1350) {
      switch (b) {
        case 127 : return 25723;
        case 150 : return 32108;
        case 175 : return 26678;
        case 200 : return 25810;
        case 300 : return 36065;
        case 400 : return 36826;
        case 500 : return 34462;
        case 600 : return 40835;
        case 700 : return 47942;
        case 800 : return 40636;
        case 900 : return 49393;
        case 1000 : return 62606;
        case 1050 : return 40594;
        case 1100 : return 41486;
        case 1150 : return 54302;
        case 1200 : return 57258;
        case 1250 : return 63060;
        case 1300 : return 44298;
        case 1325 : return 61449;
        case 1340 : return 56264;
    }
  }
    if (a==1400) {
      switch (b) {
        case 127 : return 26914;
        case 150 : return 27868;
        case 175 : return 24978;
        case 200 : return 22964;
        case 300 : return 34982;
        case 400 : return 33338;
        case 500 : return 36120;
        case 600 : return 22055;
        case 700 : return 40793;
        case 800 : return 36994;
        case 900 : return 39639;
        case 1000 : return 62087;
        case 1100 : return 41611;
        case 1150 : return 47169;
        case 1200 : return 59112;
        case 1250 : return 67069;
        case 1300 : return 55678;
        case 1350 : return 53568;
        case 1375 : return 66540;
        case 1390 : return 56339;
    }
  }
    if (a==1450) {
      switch (b) {
        case 127 : return 29647;
        case 150 : return 25167;
        case 175 : return 29849;
        case 200 : return 25024;
        case 300 : return 29734;
        case 400 : return 36138;
        case 500 : return 46310;
        case 600 : return 36196;
        case 700 : return 42495;
        case 800 : return 39816;
        case 900 : return 38090;
        case 1000 : return 46520;
        case 1100 : return 46343;
        case 1150 : return 48120;
        case 1200 : return 65752;
        case 1250 : return 41883;
        case 1300 : return 56104;
        case 1350 : return 50333;
        case 1400 : return 55878;
        case 1425 : return 54658;
        case 1440 : return 57330;
    }
  }
    if (a==1500) {
      switch (b) {
        case 127 : return 21447;
        case 150 : return 31916;
        case 175 : return 24365;
        case 200 : return 29856;
        case 300 : return 26380;
        case 400 : return 35502;
        case 500 : return 45985;
        case 600 : return 38480;
        case 700 : return 31805;
        case 800 : return 36255;
        case 900 : return 48507;
        case 1000 : return 48284;
        case 1100 : return 54941;
        case 1200 : return 50610;
        case 1250 : return 49678;
        case 1300 : return 48408;
        case 1350 : return 59532;
        case 1400 : return 43114;
        case 1450 : return 56803;
        case 1475 : return 62590;
        case 1490 : return 69124;
    }
  }
    if (a==1550) {
      switch (b) {
        case 127 : return 25395;
        case 150 : return 20592;
        case 175 : return 28002;
        case 200 : return 19565;
        case 300 : return 28215;
        case 400 : return 35885;
        case 500 : return 30070;
        case 600 : return 39177;
        case 700 : return 31821;
        case 800 : return 49163;
        case 900 : return 51403;
        case 1000 : return 41113;
        case 1100 : return 65943;
        case 1200 : return 57127;
        case 1250 : return 48853;
        case 1300 : return 48839;
        case 1350 : return 57188;
        case 1400 : return 50570;
        case 1450 : return 44837;
        case 1500 : return 51618;
        case 1525 : return 46661;
        case 1540 : return 53236;
    }
  }
    if (a==1600) {
      switch (b) {
        case 127 : return 27306;
        case 150 : return 36872;
        case 175 : return 40574;
        case 200 : return 32017;
        case 300 : return 37891;
        case 400 : return 29336;
        case 500 : return 35708;
        case 600 : return 35769;
        case 700 : return 33823;
        case 800 : return 49926;
        case 900 : return 50092;
        case 1000 : return 46122;
        case 1100 : return 60457;
        case 1200 : return 46070;
        case 1300 : return 48053;
        case 1350 : return 58623;
        case 1400 : return 43215;
        case 1450 : return 43509;
        case 1500 : return 53853;
        case 1550 : return 50912;
        case 1575 : return 67844;
        case 1590 : return 57387;
    }
  }
    if (a==1650) {
      switch (b) {
        case 127 : return 25677;
        case 150 : return 28399;
        case 175 : return 32256;
        case 200 : return 21625;
        case 300 : return 25722;
        case 400 : return 30625;
        case 500 : return 40921;
        case 600 : return 35173;
        case 700 : return 39812;
        case 800 : return 39783;
        case 900 : return 57733;
        case 1000 : return 52099;
        case 1100 : return 59358;
        case 1200 : return 65582;
        case 1300 : return 47577;
        case 1350 : return 52280;
        case 1400 : return 57350;
        case 1450 : return 46626;
        case 1500 : return 52408;
        case 1550 : return 59176;
        case 1600 : return 53022;
        case 1625 : return 48524;
        case 1640 : return 50999;
    }
  }
    if (a==1700) {
      switch (b) {
        case 127 : return 22036;
        case 150 : return 25736;
        case 175 : return 31573;
        case 200 : return 49463;
        case 300 : return 22833;
        case 400 : return 37306;
        case 500 : return 37956;
        case 600 : return 37191;
        case 700 : return 42083;
        case 800 : return 49717;
        case 900 : return 38104;
        case 1000 : return 54488;
        case 1100 : return 44929;
        case 1200 : return 50859;
        case 1300 : return 52371;
        case 1400 : return 62175;
        case 1450 : return 62791;
        case 1500 : return 61625;
        case 1550 : return 59223;
        case 1600 : return 54066;
        case 1650 : return 54171;
        case 1675 : return 52238;
        case 1690 : return 56910;
    }
  }
    if (a==1750) {
      switch (b) {
        case 127 : return 20462;
        case 150 : return 25127;
        case 175 : return 31790;
        case 200 : return 24949;
        case 300 : return 25866;
        case 400 : return 22066;
        case 500 : return 42621;
        case 600 : return 42181;
        case 700 : return 37244;
        case 800 : return 40301;
        case 900 : return 33726;
        case 1000 : return 55702;
        case 1100 : return 32603;
        case 1200 : return 50783;
        case 1300 : return 45456;
        case 1400 : return 47073;
        case 1450 : return 58462;
        case 1500 : return 57019;
        case 1550 : return 50975;
        case 1600 : return 51608;
        case 1650 : return 48106;
        case 1700 : return 56812;
        case 1725 : return 59710;
        case 1740 : return 55850;
    }
  }
    if (a==1800) {
      switch (b) {
        case 127 : return 24456;
        case 150 : return 26101;
        case 175 : return 26267;
        case 200 : return 26165;
        case 300 : return 31023;
        case 400 : return 32230;
        case 500 : return 28254;
        case 600 : return 36930;
        case 700 : return 44762;
        case 800 : return 37721;
        case 900 : return 47563;
        case 1000 : return 45729;
        case 1100 : return 47649;
        case 1200 : return 45146;
        case 1300 : return 51469;
        case 1400 : return 38062;
        case 1500 : return 54738;
        case 1550 : return 52485;
        case 1600 : return 42702;
        case 1650 : return 51500;
        case 1700 : return 43866;
        case 1750 : return 52403;
        case 1775 : return 46627;
        case 1790 : return 55111;
    }
  }
    if (a==1850) {
      switch (b) {
        case 127 : return 21471;
        case 150 : return 17673;
        case 175 : return 28456;
        case 200 : return 31124;
        case 300 : return 24402;
        case 400 : return 36220;
        case 500 : return 32062;
        case 600 : return 35200;
        case 700 : return 38240;
        case 800 : return 44304;
        case 900 : return 36311;
        case 1000 : return 48985;
        case 1100 : return 47333;
        case 1200 : return 42299;
        case 1300 : return 37178;
        case 1400 : return 49078;
        case 1500 : return 41152;
        case 1550 : return 53027;
        case 1600 : return 65979;
        case 1650 : return 41255;
        case 1700 : return 56776;
        case 1750 : return 47991;
        case 1800 : return 48000;
        case 1825 : return 51107;
        case 1840 : return 57907;
    }
  }
    if (a==1900) {
      switch (b) {
        case 127 : return 23841;
        case 150 : return 22678;
        case 175 : return 32586;
        case 200 : return 30695;
        case 300 : return 19856;
        case 400 : return 25908;
        case 500 : return 41552;
        case 600 : return 42715;
        case 700 : return 41429;
        case 800 : return 37584;
        case 900 : return 34914;
        case 1000 : return 50421;
        case 1100 : return 50277;
        case 1200 : return 50694;
        case 1300 : return 46666;
        case 1400 : return 38497;
        case 1500 : return 57199;
        case 1600 : return 51341;
        case 1650 : return 45681;
        case 1700 : return 46535;
        case 1750 : return 55441;
        case 1800 : return 48366;
        case 1850 : return 56276;
        case 1875 : return 62926;
        case 1890 : return 39632;
    }
  }
    if (a==1950) {
      switch (b) {
        case 127 : return 25993;
        case 150 : return 17871;
        case 175 : return 22962;
        case 200 : return 25065;
        case 300 : return 30979;
        case 400 : return 31897;
        case 500 : return 44265;
        case 600 : return 39716;
        case 700 : return 36882;
        case 800 : return 51667;
        case 900 : return 35345;
        case 1000 : return 50626;
        case 1100 : return 47191;
        case 1200 : return 55388;
        case 1300 : return 44030;
        case 1400 : return 61912;
        case 1500 : return 43230;
        case 1600 : return 44026;
        case 1650 : return 56739;
        case 1700 : return 56972;
        case 1750 : return 67166;
        case 1800 : return 52790;
        case 1850 : return 57887;
        case 1900 : return 55302;
        case 1925 : return 48851;
        case 1940 : return 38831;
    }
  }
    if (a==2000) {
      switch (b) {
        case 127 : return 13223;
        case 150 : return 7010;
        case 175 : return 17315;
        case 200 : return 12979;
        case 300 : return 12149;
        case 400 : return 9016;
        case 500 : return 23231;
        case 600 : return 14234;
        case 700 : return 20145;
        case 800 : return 23224;
        case 900 : return 26349;
        case 1000 : return 22301;
        case 1100 : return 21241;
        case 1200 : return 23715;
        case 1300 : return 20169;
        case 1400 : return 21227;
        case 1500 : return 20081;
        case 1600 : return 26236;
        case 1700 : return 18175;
        case 1750 : return 21201;
        case 1800 : return 29100;
        case 1850 : return 16214;
        case 1900 : return 30402;
        case 1950 : return 23361;
        case 1975 : return 28165;
        case 1990 : return 28314;
    }
  }
    if (a==2050) {
      switch (b) {
        case 127 : return 8053;
        case 150 : return 12065;
        case 175 : return 9146;
        case 200 : return 11168;
        case 300 : return 13328;
        case 400 : return 16447;
        case 500 : return 11239;
        case 600 : return 22406;
        case 700 : return 14460;
        case 800 : return 28559;
        case 900 : return 21421;
        case 1000 : return 31412;
        case 1100 : return 21361;
        case 1200 : return 21476;
        case 1300 : return 20478;
        case 1400 : return 22395;
        case 1500 : return 27708;
        case 1600 : return 28693;
        case 1700 : return 30893;
        case 1750 : return 30679;
        case 1800 : return 28507;
        case 1850 : return 36344;
        case 1900 : return 15429;
        case 1950 : return 34649;
        case 2000 : return 33395;
        case 2025 : return 19475;
        case 2040 : return 32415;
    }
  }
    if (a==2100) {
      switch (b) {
        case 127 : return 11547;
        case 150 : return 12367;
        case 175 : return 12416;
        case 200 : return 21728;
        case 300 : return 14438;
        case 400 : return 17481;
        case 500 : return 18545;
        case 600 : return 22631;
        case 700 : return 14529;
        case 800 : return 17692;
        case 900 : return 22888;
        case 1000 : return 19662;
        case 1100 : return 18728;
        case 1200 : return 28144;
        case 1300 : return 22800;
        case 1400 : return 19677;
        case 1500 : return 33046;
        case 1600 : return 33199;
        case 1700 : return 18489;
        case 1800 : return 29953;
        case 1850 : return 29976;
        case 1900 : return 25685;
        case 1950 : return 18798;
        case 2000 : return 18643;
        case 2050 : return 24987;
        case 2075 : return 20492;
        case 2090 : return 18565;
    }
  }
    if (a==2150) {
      switch (b) {
        case 127 : return 11541;
        case 150 : return 16842;
        case 175 : return 13639;
        case 200 : return 18763;
        case 300 : return 19972;
        case 400 : return 16776;
        case 500 : return 21982;
        case 600 : return 15581;
        case 700 : return 16650;
        case 800 : return 19707;
        case 900 : return 28157;
        case 1000 : return 20933;
        case 1100 : return 21696;
        case 1200 : return 30303;
        case 1300 : return 29116;
        case 1400 : return 17669;
        case 1500 : return 15873;
        case 1600 : return 29195;
        case 1700 : return 26011;
        case 1800 : return 27188;
        case 1850 : return 16655;
        case 1900 : return 18783;
        case 1950 : return 21016;
        case 2000 : return 26051;
        case 2050 : return 23141;
        case 2100 : return 21997;
        case 2125 : return 26005;
        case 2140 : return 24743;
    }
  }
    if (a==2200) {
      switch (b) {
        case 127 : return 14823;
        case 150 : return 7404;
        case 175 : return 12761;
        case 200 : return 7463;
        case 300 : return 13827;
        case 400 : return 15836;
        case 500 : return 23088;
        case 600 : return 14646;
        case 700 : return 19141;
        case 800 : return 20238;
        case 900 : return 19073;
        case 1000 : return 20081;
        case 1100 : return 21122;
        case 1200 : return 24499;
        case 1300 : return 16874;
        case 1400 : return 21095;
        case 1500 : return 24343;
        case 1600 : return 15771;
        case 1700 : return 25394;
        case 1800 : return 18033;
        case 1900 : return 35984;
        case 1950 : return 16830;
        case 2000 : return 24404;
        case 2050 : return 22075;
        case 2100 : return 31837;
        case 2150 : return 21228;
        case 2175 : return 22169;
        case 2190 : return 25354;
    }
  }
    if (a==2250) {
      switch (b) {
        case 127 : return 10759;
        case 150 : return 7588;
        case 175 : return 7633;
        case 200 : return 10790;
        case 300 : return 12949;
        case 400 : return 17310;
        case 500 : return 15214;
        case 600 : return 12871;
        case 700 : return 16106;
        case 800 : return 13942;
        case 900 : return 24640;
        case 1000 : return 20091;
        case 1100 : return 29187;
        case 1200 : return 29071;
        case 1300 : return 17128;
        case 1400 : return 19459;
        case 1500 : return 19289;
        case 1600 : return 22570;
        case 1700 : return 24587;
        case 1800 : return 31159;
        case 1900 : return 29984;
        case 1950 : return 21456;
        case 2000 : return 22663;
        case 2050 : return 23701;
        case 2100 : return 31161;
        case 2150 : return 24602;
        case 2200 : return 28005;
        case 2225 : return 21601;
        case 2240 : return 25562;
    }
  }
    if (a==2300) {
      switch (b) {
        case 127 : return 13152;
        case 150 : return 7597;
        case 175 : return 9766;
        case 200 : return 16360;
        case 300 : return 15216;
        case 400 : return 17150;
        case 500 : return 18586;
        case 600 : return 18490;
        case 700 : return 15177;
        case 800 : return 15186;
        case 900 : return 20539;
        case 1000 : return 15240;
        case 1100 : return 31874;
        case 1200 : return 26128;
        case 1300 : return 21933;
        case 1400 : return 30461;
        case 1500 : return 28455;
        case 1600 : return 32812;
        case 1700 : return 28298;
        case 1800 : return 31623;
        case 1900 : return 22803;
        case 2000 : return 28359;
        case 2050 : return 24977;
        case 2100 : return 23898;
        case 2150 : return 31482;
        case 2200 : return 24202;
        case 2250 : return 22976;
        case 2275 : return 35826;
        case 2290 : return 26006;
    }
  }
    if (a==2350) {
      switch (b) {
        case 127 : return 11034;
        case 150 : return 14358;
        case 175 : return 6626;
        case 200 : return 23199;
        case 300 : return 18822;
        case 400 : return 15407;
        case 500 : return 15442;
        case 600 : return 14414;
        case 700 : return 19628;
        case 800 : return 24291;
        case 900 : return 13348;
        case 1000 : return 16625;
        case 1100 : return 26346;
        case 1200 : return 17631;
        case 1300 : return 25523;
        case 1400 : return 30097;
        case 1500 : return 22240;
        case 1600 : return 14224;
        case 1700 : return 37768;
        case 1800 : return 16469;
        case 1900 : return 29546;
        case 2000 : return 24383;
        case 2050 : return 21009;
        case 2100 : return 14559;
        case 2150 : return 22181;
        case 2200 : return 17850;
        case 2250 : return 28861;
        case 2300 : return 30981;
        case 2325 : return 23124;
        case 2340 : return 16407;
    }
  }
    if (a==2400) {
      switch (b) {
        case 127 : return 14664;
        case 150 : return 10118;
        case 175 : return 10233;
        case 200 : return 13454;
        case 300 : return 4477;
        case 400 : return 8925;
        case 500 : return 15715;
        case 600 : return 14689;
        case 700 : return 15686;
        case 800 : return 10083;
        case 900 : return 21411;
        case 1000 : return 24969;
        case 1100 : return 18089;
        case 1200 : return 16851;
        case 1300 : return 20232;
        case 1400 : return 28047;
        case 1500 : return 30389;
        case 1600 : return 22407;
        case 1700 : return 40309;
        case 1800 : return 23515;
        case 1900 : return 28999;
        case 2000 : return 21263;
        case 2100 : return 24681;
        case 2150 : return 22395;
        case 2200 : return 22417;
        case 2250 : return 21287;
        case 2300 : return 22410;
        case 2350 : return 20138;
        case 2375 : return 19172;
        case 2390 : return 23649;
    }
  }
    if (a==2450) {
      switch (b) {
        case 127 : return 9239;
        case 150 : return 6893;
        case 175 : return 12625;
        case 200 : return 18389;
        case 300 : return 13761;
        case 400 : return 6825;
        case 500 : return 20489;
        case 600 : return 12592;
        case 700 : return 17194;
        case 800 : return 28360;
        case 900 : return 27710;
        case 1000 : return 28564;
        case 1100 : return 34210;
        case 1200 : return 29820;
        case 1300 : return 27525;
        case 1400 : return 19319;
        case 1500 : return 24055;
        case 1600 : return 20685;
        case 1700 : return 26107;
        case 1800 : return 14805;
        case 1900 : return 21714;
        case 2000 : return 25269;
        case 2100 : return 20484;
        case 2150 : return 12669;
        case 2200 : return 23869;
        case 2250 : return 18389;
        case 2300 : return 21728;
        case 2350 : return 20549;
        case 2400 : return 21813;
        case 2425 : return 17065;
        case 2440 : return 20487;
    }
  }
    if (a==2500) {
      switch (b) {
        case 127 : return 9238;
        case 150 : return 11571;
        case 175 : return 16190;
        case 200 : return 10435;
        case 300 : return 15028;
        case 400 : return 9353;
        case 500 : return 20969;
        case 600 : return 24431;
        case 700 : return 28967;
        case 800 : return 23081;
        case 900 : return 17391;
        case 1000 : return 19718;
        case 1100 : return 19652;
        case 1200 : return 14422;
        case 1300 : return 18440;
        case 1400 : return 33515;
        case 1500 : return 26569;
        case 1600 : return 29030;
        case 1700 : return 24344;
        case 1800 : return 17326;
        case 1900 : return 23329;
        case 2000 : return 26806;
        case 2100 : return 34979;
        case 2200 : return 19741;
        case 2250 : return 26574;
        case 2300 : return 22267;
        case 2350 : return 24595;
        case 2400 : return 27728;
        case 2450 : return 23175;
        case 2475 : return 27769;
        case 2490 : return 23195;
    }
  }
    if (a==2550) {
      switch (b) {
        case 127 : return 12879;
        case 150 : return 7117;
        case 175 : return 14013;
        case 200 : return 14052;
        case 300 : return 12886;
        case 400 : return 14104;
        case 500 : return 21176;
        case 600 : return 14306;
        case 700 : return 13000;
        case 800 : return 18840;
        case 900 : return 27254;
        case 1000 : return 26368;
        case 1100 : return 18763;
        case 1200 : return 34286;
        case 1300 : return 28212;
        case 1400 : return 28231;
        case 1500 : return 22479;
        case 1600 : return 30858;
        case 1700 : return 22541;
        case 1800 : return 24811;
        case 1900 : return 21153;
        case 2000 : return 28345;
        case 2100 : return 18852;
        case 2200 : return 20110;
        case 2250 : return 28132;
        case 2300 : return 23632;
        case 2350 : return 20082;
        case 2400 : return 26992;
        case 2450 : return 24667;
        case 2500 : return 22217;
        case 2525 : return 11797;
        case 2540 : return 26958;
    }
  }
    if (a==2600) {
      switch (b) {
        case 127 : return 3669;
        case 150 : return 11968;
        case 175 : return 13236;
        case 200 : return 18074;
        case 300 : return 19172;
        case 400 : return 17891;
        case 500 : return 17929;
        case 600 : return 13361;
        case 700 : return 16692;
        case 800 : return 19300;
        case 900 : return 17982;
        case 1000 : return 22794;
        case 1100 : return 14403;
        case 1200 : return 24089;
        case 1300 : return 22657;
        case 1400 : return 23977;
        case 1500 : return 27622;
        case 1600 : return 22747;
        case 1700 : return 25318;
        case 1800 : return 29944;
        case 1900 : return 27649;
        case 2000 : return 28449;
        case 2100 : return 25353;
        case 2200 : return 26318;
        case 2300 : return 19056;
        case 2350 : return 24007;
        case 2400 : return 20246;
        case 2450 : return 25479;
        case 2500 : return 32229;
        case 2550 : return 26560;
        case 2575 : return 25001;
        case 2590 : return 37266;
    }
  }
    if (a==2650) {
      switch (b) {
        case 127 : return 10968;
        case 150 : return 10865;
        case 175 : return 13477;
        case 200 : return 7409;
        case 300 : return 10901;
        case 400 : return 17142;
        case 500 : return 18207;
        case 600 : return 18142;
        case 700 : return 15964;
        case 800 : return 25617;
        case 900 : return 18045;
        case 1000 : return 17170;
        case 1100 : return 19357;
        case 1200 : return 28341;
        case 1300 : return 14760;
        case 1400 : return 17052;
        case 1500 : return 24367;
        case 1600 : return 22059;
        case 1700 : return 20507;
        case 1800 : return 10242;
        case 1900 : return 25680;
        case 2000 : return 30669;
        case 2100 : return 29359;
        case 2200 : return 25599;
        case 2300 : return 20610;
        case 2350 : return 22019;
        case 2400 : return 16942;
        case 2450 : return 24240;
        case 2500 : return 27073;
        case 2550 : return 24399;
        case 2600 : return 23034;
        case 2625 : return 23196;
        case 2640 : return 21831;
    }
  }
    if (a==2700) {
      switch (b) {
        case 127 : return 13664;
        case 150 : return 9726;
        case 175 : return 13639;
        case 200 : return 11094;
        case 300 : return 16164;
        case 400 : return 7461;
        case 500 : return 11017;
        case 600 : return 14913;
        case 700 : return 14805;
        case 800 : return 23500;
        case 900 : return 13661;
        case 1000 : return 19977;
        case 1100 : return 18535;
        case 1200 : return 27090;
        case 1300 : return 28444;
        case 1400 : return 27128;
        case 1500 : return 19790;
        case 1600 : return 31120;
        case 1700 : return 37159;
        case 1800 : return 23549;
        case 1900 : return 28619;
        case 2000 : return 21012;
        case 2100 : return 23389;
        case 2200 : return 29574;
        case 2300 : return 24827;
        case 2400 : return 31097;
        case 2450 : return 27095;
        case 2500 : return 19812;
        case 2550 : return 23654;
        case 2600 : return 27384;
        case 2650 : return 20902;
        case 2675 : return 37037;
        case 2690 : return 20950;
    }
  }
    if (a==2750) {
      switch (b) {
        case 127 : return 18841;
        case 150 : return 15171;
        case 175 : return 15280;
        case 200 : return 17778;
        case 300 : return 13742;
        case 400 : return 11347;
        case 500 : return 17650;
        case 600 : return 15175;
        case 700 : return 22725;
        case 800 : return 30083;
        case 900 : return 18963;
        case 1000 : return 23842;
        case 1100 : return 17812;
        case 1200 : return 28875;
        case 1300 : return 23810;
        case 1400 : return 32578;
        case 1500 : return 27569;
        case 1600 : return 17644;
        case 1700 : return 23924;
        case 1800 : return 17512;
        case 1900 : return 27692;
        case 2000 : return 38108;
        case 2100 : return 20259;
        case 2200 : return 27630;
        case 2300 : return 31584;
        case 2400 : return 22644;
        case 2450 : return 22911;
        case 2500 : return 33862;
        case 2550 : return 27746;
        case 2600 : return 21621;
        case 2650 : return 17621;
        case 2700 : return 17590;
        case 2725 : return 25118;
        case 2740 : return 17545;
    }
  }
    if (a==2800) {
      switch (b) {
        case 127 : return 14106;
        case 150 : return 10296;
        case 175 : return 16642;
        case 200 : return 12739;
        case 300 : return 12760;
        case 400 : return 10216;
        case 500 : return 12875;
        case 600 : return 16676;
        case 700 : return 12725;
        case 800 : return 18007;
        case 900 : return 26869;
        case 1000 : return 19197;
        case 1100 : return 14095;
        case 1200 : return 14034;
        case 1300 : return 21828;
        case 1400 : return 28166;
        case 1500 : return 23018;
        case 1600 : return 21877;
        case 1700 : return 17977;
        case 1800 : return 14209;
        case 1900 : return 24453;
        case 2000 : return 24501;
        case 2100 : return 27062;
        case 2200 : return 24253;
        case 2300 : return 30715;
        case 2400 : return 23085;
        case 2500 : return 30966;
        case 2550 : return 21618;
        case 2600 : return 30782;
        case 2650 : return 24241;
        case 2700 : return 18127;
        case 2750 : return 16723;
        case 2775 : return 25794;
        case 2790 : return 16574;
    }
  }
      break;
    }
  }
  if (SignalScenario==2) {
    if (year==2016) { 
      switch (a) {
        case 300 : return 91921;
        case 325 : return 94725;
        case 350 : return 90346;
        case 375 : return 92320;
        case 400 : return 101303;
        case 425 : return 99179;
        case 450 : return 92049;
        case 475 : return 93178;
        case 500 : return 97289;
        case 525 : return 89647;
        case 550 : return 90884;
        case 575 : return 89127;
        case 600 : return 95155;
        case 625 : return 97637;
        case 650 : return 93133;
        case 675 : return 97975;
        case 700 : return 99719;
        case 725 : return 98160;
        case 750 : return 92786;
        case 775 : return 95520;
        case 800 : return 96456;
        case 825 : return 99248;
        case 850 : return 93770;
        case 875 : return 95678;
        case 900 : return 99174;
        case 925 : return 89656;
        case 950 : return 89334;
        case 975 : return 98710;
        case 1000 : return 92928;
        case 1025 : return 94955;
        case 1050 : return 96968;
        case 1075 : return 90557;
        case 1100 : return 87469;
        case 1125 : return 96198;
        case 1150 : return 92882;
        case 1175 : return 97852;
        case 1200 : return 97663;
        case 1225 : return 90157;
        case 1250 : return 99060;
        case 1275 : return 97720;
        case 1300 : return 99273;
        case 1325 : return 94552;
        case 1350 : return 90519;
        case 1375 : return 90029;
        case 1400 : return 103801;
        case 1425 : return 90166;
        case 1450 : return 95070;
        case 1475 : return 91803;
        case 1500 : return 95800;
        case 1525 : return 102120;
        case 1550 : return 96669;
        case 1575 : return 98562;
        case 1600 : return 99043;
      }
    }
    if (year==2017) {
      switch (a) {
        case 300 : return 116485;
        case 325 : return 130368;
        case 350 : return 124966;
        case 375 : return 111853;
        case 400 : return 111749;
        case 425 : return 111438;
        case 450 : return 110665;
        case 475 : return 145132;
        case 500 : return 124660;
        case 525 : return 113354;
        case 550 : return 118257;
        case 575 : return 103243;
        case 600 : return 109908;
        case 625 : return 97664;
        case 650 : return 115173;
        case 675 : return 105692;
        case 700 : return 125804;
        case 725 : return 108227;
        case 750 : return 114951;
        case 775 : return 113885;
        case 800 : return 107165;
        case 825 : return 108724;
        case 850 : return 120738;
        case 875 : return 98593;
        case 900 : return 111864;
        case 925 : return 104354;
        case 950 : return 112465;
        case 975 : return 106080;
        case 1000 : return 102814;
        case 1025 : return 109795;
        case 1050 : return 107427;
        case 1075 : return 104711;
        case 1100 : return 101573;
        case 1125 : return 92031;
        case 1150 : return 100948;
        case 1175 : return 113677;
        case 1200 : return 96542;
        case 1225 : return 118820;
        case 1250 : return 115387;
        case 1275 : return 105327;
        case 1300 : return 114336;
        case 1325 : return 107423;
        case 1350 : return 102114;
        case 1375 : return 90382;
        case 1400 : return 96891;
        case 1425 : return 100446;
        case 1450 : return 102065;
        case 1475 : return 107011;
        case 1500 : return 119776;
        case 1525 : return 90913;
        case 1550 : return 103056;
        case 1575 : return 102451;
        case 1600 : return 106658;
      }
    }
    if (year==2018) {
      switch (a) {
        case 300 : return 197373;
        case 325 : return 185543;
        case 350 : return 176762;
        case 375 : return 165445;
        case 400 : return 195681;
        case 425 : return 171641;
        case 450 : return 162310;
        case 475 : return 190239;
        case 500 : return 178631;
        case 525 : return 163420;
        case 550 : return 167460;
        case 575 : return 166777;
        case 600 : return 178737;
        case 625 : return 158531;
        case 650 : return 164558;
        case 675 : return 148569;
        case 700 : return 167291;
        case 725 : return 176494;
        case 750 : return 144779;
        case 775 : return 159357;
        case 800 : return 163799;
        case 825 : return 160957;
        case 850 : return 150199;
        case 875 : return 175503;
        case 900 : return 182884;
        case 925 : return 179515;
        case 950 : return 156768;
        case 975 : return 176916;
        case 1000 : return 167485;
        case 1025 : return 181749;
        case 1050 : return 154793;
        case 1075 : return 171015;
        case 1100 : return 164673;
        case 1125 : return 164751;
        case 1150 : return 160525;
        case 1175 : return 173124;
        case 1200 : return 159218;
        case 1225 : return 143154;
        case 1250 : return 157686;
        case 1275 : return 166892;
        case 1300 : return 168827;
        case 1325 : return 167550;
        case 1350 : return 161319;
        case 1375 : return 175569;
        case 1400 : return 154424;
        case 1425 : return 158942;
        case 1450 : return 168781;
        case 1475 : return 194064;
        case 1500 : return 155707;
        case 1525 : return 144484;
        case 1550 : return 152217;
        case 1575 : return 165116;
        case 1600 : return 151388;
      }
    }
  }
  if (SignalScenario==5) {
    if (year==2016) { 
      switch (a) {
        case 300 : return 58118;
        case 325 : return 61917;
        case 350 : return 57252;
        case 375 : return 53887;
        case 400 : return 59756;
        case 425 : return 60699;
        case 450 : return 55598;
        case 475 : return 56962;
        case 500 : return 57975;
        case 525 : return 56519;
        case 550 : return 57730;
        case 575 : return 57321;
        case 600 : return 57795;
        case 625 : return 56302;
        case 650 : return 58425;
        case 675 : return 57161;
        case 700 : return 57591;
        case 725 : return 58500;
        case 750 : return 60852;
        case 775 : return 61228;
        case 800 : return 56960;
        case 825 : return 63741;
        case 850 : return 64146;
        case 875 : return 56939;
        case 900 : return 57282;
        case 925 : return 56513;
        case 950 : return 60588;
        case 975 : return 59779;
        case 1000 : return 59249;
        case 1025 : return 57128;
        case 1050 : return 58805;
        case 1075 : return 56641;
        case 1100 : return 57981;
        case 1125 : return 60182;
        case 1150 : return 58791;
        case 1175 : return 58231;
        case 1200 : return 61741;
        case 1225 : return 58635;
        case 1250 : return 59486;
        case 1275 : return 61506;
        case 1300 : return 58420;
        case 1325 : return 59597;
        case 1350 : return 61382;
        case 1375 : return 61483;
        case 1400 : return 59605;
        case 1425 : return 65340;
        case 1450 : return 58465;
        case 1475 : return 61024;
        case 1500 : return 59072;
        case 1525 : return 57476;
        case 1550 : return 58584;
        case 1575 : return 57074;
        case 1600 : return 57698;
      }
    }
    if (year==2017) {
      switch (a) {
        case 300 : return 74405;
        case 325 : return 71808;
        case 350 : return 64578;
        case 375 : return 72186;
        case 400 : return 73814;
        case 425 : return 76960;
        case 450 : return 66054;
        case 475 : return 68182;
        case 500 : return 59313;
        case 525 : return 67670;
        case 550 : return 77413;
        case 575 : return 70006;
        case 600 : return 69254;
        case 625 : return 74090;
        case 650 : return 68340;
        case 675 : return 64079;
        case 700 : return 68879;
        case 725 : return 76006;
        case 750 : return 65680;
        case 775 : return 67435;
        case 800 : return 80716;
        case 825 : return 76961;
        case 850 : return 66395;
        case 875 : return 66253;
        case 900 : return 68334;
        case 925 : return 77779;
        case 950 : return 70905;
        case 975 : return 75311;
        case 1000 : return 69608;
        case 1025 : return 55661;
        case 1050 : return 62084;
        case 1075 : return 71074;
        case 1100 : return 64663;
        case 1125 : return 66667;
        case 1150 : return 65306;
        case 1175 : return 66899;
        case 1200 : return 69375;
        case 1225 : return 65900;
        case 1250 : return 63028;
        case 1275 : return 61399;
        case 1300 : return 71548;
        case 1325 : return 59712;
        case 1350 : return 75912;
        case 1375 : return 66175;
        case 1400 : return 65903;
        case 1425 : return 62548;
        case 1450 : return 64753;
        case 1475 : return 68707;
        case 1500 : return 57919;
        case 1525 : return 61900;
        case 1550 : return 64912;
        case 1575 : return 64162;
        case 1600 : return 65461;
      }
    }
    if (year==2018) {
      switch (a) {
        case 300 : return 113777;
        case 325 : return 112422;
        case 350 : return 109789;
        case 375 : return 107769;
        case 400 : return 109130;
        case 425 : return 105163;
        case 450 : return 107887;
        case 475 : return 100744;
        case 500 : return 109374;
        case 525 : return 97169;
        case 550 : return 107612;
        case 575 : return 103359;
        case 600 : return 110771;
        case 625 : return 102060;
        case 650 : return 102705;
        case 675 : return 102954;
        case 700 : return 110375;
        case 725 : return 101258;
        case 750 : return 100263;
        case 775 : return 92718;
        case 800 : return 111396;
        case 825 : return 107350;
        case 850 : return 98063;
        case 875 : return 105413;
        case 900 : return 103451;
        case 925 : return 107198;
        case 950 : return 101630;
        case 975 : return 103219;
        case 1000 : return 100693;
        case 1025 : return 110300;
        case 1050 : return 104650;
        case 1075 : return 102983;
        case 1100 : return 94621;
        case 1125 : return 105544;
        case 1150 : return 93819;
        case 1175 : return 96160;
        case 1200 : return 105247;
        case 1225 : return 102070;
        case 1250 : return 92884;
        case 1275 : return 100031;
        case 1300 : return 95203;
        case 1325 : return 103445;
        case 1350 : return 100041;
        case 1375 : return 95322;
        case 1400 : return 92622;
        case 1425 : return 97417;
        case 1450 : return 101634;
        case 1475 : return 98829;
        case 1500 : return 88159;
        case 1525 : return 96664;
        case 1550 : return 95566;
        case 1575 : return 93542;
        case 1600 : return 91173;
      }
    }
  }
  if (SignalScenario==3) {
    switch (year) {
      case 2016 :
    if (a==1800) {
      switch (b) {
        case 127 : return 21571;
        case 200 : return 78583;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 32322;
        case 2100 : return 36115;
        case 2190 : return 54940;
    }
  }
  //year=20160 for postVFP
      case 20160 :
    if (a==1800) {
      switch (b) {
        case 127 : return 96427;
        case 200 : return 180892;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 53424;
        case 2100 : return 59246;
        case 2190 : return 79966;
    }
  }
      case 2017 :
    if (a==1800) {
      switch (b) {
        case 127 : return 119872;
        case 200 : return 190318;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 85046;
        case 2100 : return 172342;
        case 2190 : return 195138;
    }
  }
      case 2018 :
    if (a==1800) {
      switch (b) {
        case 127 : return 180831;
        case 200 : return 275402;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 94024;
        case 2100 : return 176519;
        case 2190 : return 187078;
    }
  }
  //year=3016 for preVFP goodpair
      case 3016 :
    if (a==1800) {
      switch (b) {
        case 127 : return 21571;
        case 200 : return 52510;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 32322;
        case 2100 : return 32612;
        case 2190 : return 42157;
    }
  }
  //year=21160 for postVFP goodpair
      case 21160 :
    if (a==1800) {
      switch (b) {
        case 127 : return 96427;
        case 200 : return 151582;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 53424;
        case 2100 : return 57818;
        case 2190 : return 70682;
    }
  }
      case 3017 :
    if (a==1800) {
      switch (b) {
        case 127 : return 119872;
        case 200 : return 157909;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 85046;
        case 2100 : return 168258;
        case 2190 : return 176560;
    }
  }
      case 3018 :
    if (a==1800) {
      switch (b) {
        case 127 : return 180831;
        case 200 : return 219037;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 94024;
        case 2100 : return 167632;
        case 2190 : return 166962;
    }
  }
      break;
    }
  }
  return 0;
}

std::map<std::pair<int,int>,int> init_signal_event(int SignalScenario) {
  std::map<std::pair<int,int>,int> output;
  if (SignalScenario==1 || SignalScenario==4) {
    std::vector<int> Yticks;
    Yticks =  std::vector<int>({127, 200, 300, 400, 500, 600, 700, 790});
    for (auto i : Yticks) {std::pair<int,int> p(800,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 200, 300, 400, 500, 600, 700, 800, 890}); 
    for (auto i : Yticks) {std::pair<int,int> p(900,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 975, 990}); 
    for (auto i : Yticks) {std::pair<int,int> p(1000,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 1000, 1025, 1040}); 
    for (auto i : Yticks) {std::pair<int,int> p(1050,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1075, 1090}); 
    for (auto i : Yticks) {std::pair<int,int> p(1100,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1100, 1125, 1140}); 
    for (auto i : Yticks) {std::pair<int,int> p(1150,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1175, 1190}); 
    for (auto i : Yticks) {std::pair<int,int> p(1200,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1200, 1225, 1240}); 
    for (auto i : Yticks) {std::pair<int,int> p(1250,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1275, 1290}); 
    for (auto i : Yticks) {std::pair<int,int> p(1300,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1300, 1325, 1340}); 
    for (auto i : Yticks) {std::pair<int,int> p(1350,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1375, 1390}); 
    for (auto i : Yticks) {std::pair<int,int> p(1400,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1400, 1425, 1440}); 
    for (auto i : Yticks) {std::pair<int,int> p(1450,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1475, 1490}); 
    for (auto i : Yticks) {std::pair<int,int> p(1500,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1500, 1525, 1540}); 
    for (auto i : Yticks) {std::pair<int,int> p(1550,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1575, 1590}); 
    for (auto i : Yticks) {std::pair<int,int> p(1600,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1600, 1625, 1640}); 
    for (auto i : Yticks) {std::pair<int,int> p(1650,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1675, 1690}); 
    for (auto i : Yticks) {std::pair<int,int> p(1700,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1725, 1740}); 
    for (auto i : Yticks) {std::pair<int,int> p(1750,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1775, 1790}); 
    for (auto i : Yticks) {std::pair<int,int> p(1800,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1825, 1840}); 
    for (auto i : Yticks) {std::pair<int,int> p(1850,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1875, 1890}); 
    for (auto i : Yticks) {std::pair<int,int> p(1900,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1900, 1925, 1940}); 
    for (auto i : Yticks) {std::pair<int,int> p(1950,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 1975, 1990}); 
    for (auto i : Yticks) {std::pair<int,int> p(2000,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 2000, 2025, 2040}); 
    for (auto i : Yticks) {std::pair<int,int> p(2050,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2075, 2090}); 
    for (auto i : Yticks) {std::pair<int,int> p(2100,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2100, 2125, 2140}); 
    for (auto i : Yticks) {std::pair<int,int> p(2150,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2175, 2190}); 
    for (auto i : Yticks) {std::pair<int,int> p(2200,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2200, 2225, 2240}); 
    for (auto i : Yticks) {std::pair<int,int> p(2250,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2275, 2290}); 
    for (auto i : Yticks) {std::pair<int,int> p(2300,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2300, 2325, 2340}); 
    for (auto i : Yticks) {std::pair<int,int> p(2350,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2375, 2390}); 
    for (auto i : Yticks) {std::pair<int,int> p(2400,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2400, 2425, 2440}); 
    for (auto i : Yticks) {std::pair<int,int> p(2450,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2250, 2300, 2350, 2400, 2450, 2475, 2490});
    for (auto i : Yticks) {std::pair<int,int> p(2500,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2250, 2300, 2350, 2400, 2450, 2500, 2525, 2540});
    for (auto i : Yticks) {std::pair<int,int> p(2550,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2350, 2400, 2450, 2500, 2550, 2575, 2590});
    for (auto i : Yticks) {std::pair<int,int> p(2600,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2350, 2400, 2450, 2500, 2550, 2600, 2625, 2640});
    for (auto i : Yticks) {std::pair<int,int> p(2650,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2450, 2500, 2550, 2600, 2650, 2675, 2690});
    for (auto i : Yticks) {std::pair<int,int> p(2700,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2450, 2500, 2550, 2600, 2650, 2700, 2725, 2740});
    for (auto i : Yticks) {std::pair<int,int> p(2750,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2550, 2600, 2650, 2700, 2750, 2775, 2790});
    for (auto i : Yticks) {std::pair<int,int> p(2800,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
  }
  if (SignalScenario==2 || SignalScenario==5) {
    //TChiNG 300 to 1600 GeV in steps of 25 GeV.
    for (unsigned int i=0; i<53; i++) {
      int m=(300+i*25);
      std::pair<int,int> p(m,1);
      output.insert(std::pair<std::pair<int,int>,int>(p,0));
    }
  }
  if (SignalScenario==3) {
    std::vector<int> Yticks;
    Yticks =  std::vector<int>({127, 200});
    for (auto i : Yticks) {std::pair<int,int> p(1800,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({1000, 2100, 2190});
    for (auto i : Yticks) {std::pair<int,int> p(2200,i); output.insert(std::pair<std::pair<int,int>,int>(p,0));}
    Yticks.clear();
  }
  return output;
}
#endif
