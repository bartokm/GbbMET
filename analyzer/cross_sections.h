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
        case 127 : return 33093;
        case 200 : return 48647;
        case 300 : return 56837;
        case 400 : return 79004;
        case 500 : return 76981;
        case 600 : return 93410;
        case 700 : return 91419;
        case 790 : return 91176;
    }
  }
    if (a==900) {
      switch (b) {
        case 127 : return 28284;
        case 200 : return 51440;
        case 300 : return 54784;
        case 400 : return 65152;
        case 500 : return 62292;
        case 600 : return 78064;
        case 700 : return 89009;
        case 800 : return 76659;
        case 890 : return 122586;
    }
  }
    if (a==1000) {
      switch (b) {
        case 127 : return 28766;
        case 150 : return 30627;
        case 175 : return 32141;
        case 200 : return 43977;
        case 300 : return 49656;
        case 400 : return 55778;
        case 500 : return 69835;
        case 600 : return 79337;
        case 700 : return 75063;
        case 750 : return 85373;
        case 800 : return 88209;
        case 850 : return 93013;
        case 900 : return 85748;
        case 950 : return 85081;
        case 975 : return 102989;
        case 990 : return 120627;
    }
  }
    if (a==1050) {
      switch (b) {
        case 127 : return 31489;
        case 150 : return 28736;
        case 175 : return 30483;
        case 200 : return 45411;
        case 300 : return 67366;
        case 400 : return 65184;
        case 500 : return 81236;
        case 600 : return 85757;
        case 700 : return 90168;
        case 750 : return 90102;
        case 800 : return 99628;
        case 850 : return 101577;
        case 900 : return 102448;
        case 950 : return 91731;
        case 1000 : return 113953;
        case 1025 : return 115332;
        case 1040 : return 95904;
    }
  }
    if (a==1100) {
      switch (b) {
        case 127 : return 31605;
        case 150 : return 32318;
        case 175 : return 39835;
        case 200 : return 32865;
        case 300 : return 44233;
        case 400 : return 54830;
        case 500 : return 59030;
        case 600 : return 73530;
        case 700 : return 72441;
        case 800 : return 72431;
        case 850 : return 100393;
        case 900 : return 73850;
        case 950 : return 100366;
        case 1000 : return 100536;
        case 1050 : return 95956;
        case 1075 : return 96023;
        case 1090 : return 89912;
    }
  }
    if (a==1150) {
      switch (b) {
        case 127 : return 18528;
        case 150 : return 23647;
        case 175 : return 25952;
        case 200 : return 28751;
        case 300 : return 46045;
        case 400 : return 37142;
        case 500 : return 44477;
        case 600 : return 70676;
        case 700 : return 52327;
        case 800 : return 61290;
        case 850 : return 64899;
        case 900 : return 79667;
        case 950 : return 77687;
        case 1000 : return 78865;
        case 1050 : return 67354;
        case 1100 : return 77831;
        case 1125 : return 76248;
        case 1140 : return 64436;
    }
  }
    if (a==1200) {
      switch (b) {
        case 127 : return 7875;
        case 150 : return 16511;
        case 175 : return 13144;
        case 200 : return 19191;
        case 300 : return 28121;
        case 400 : return 27044;
        case 500 : return 29577;
        case 600 : return 37492;
        case 700 : return 34050;
        case 800 : return 38753;
        case 900 : return 38647;
        case 950 : return 41892;
        case 1000 : return 58723;
        case 1050 : return 68408;
        case 1100 : return 49812;
        case 1150 : return 55760;
        case 1175 : return 53451;
        case 1190 : return 42727;
    }
  }
    if (a==1250) {
      switch (b) {
        case 127 : return 7718;
        case 150 : return 13895;
        case 175 : return 12416;
        case 200 : return 14836;
        case 300 : return 18399;
        case 400 : return 26414;
        case 500 : return 22767;
        case 600 : return 35142;
        case 700 : return 35971;
        case 800 : return 34332;
        case 900 : return 28135;
        case 950 : return 36804;
        case 1000 : return 35854;
        case 1050 : return 33190;
        case 1100 : return 32411;
        case 1150 : return 43055;
        case 1200 : return 44604;
        case 1225 : return 43693;
        case 1240 : return 48980;
    }
  }
    if (a==1300) {
      switch (b) {
        case 127 : return 5217;
        case 150 : return 6938;
        case 175 : return 9596;
        case 200 : return 9559;
        case 300 : return 16615;
        case 400 : return 20223;
        case 500 : return 24602;
        case 600 : return 23006;
        case 700 : return 21757;
        case 800 : return 24557;
        case 900 : return 23828;
        case 1000 : return 30586;
        case 1050 : return 28016;
        case 1100 : return 28139;
        case 1150 : return 31658;
        case 1200 : return 25727;
        case 1250 : return 35410;
        case 1275 : return 27942;
        case 1290 : return 21907;
    }
  }
    if (a==1350) {
      switch (b) {
        case 127 : return 2647;
        case 150 : return 9670;
        case 175 : return 10636;
        case 200 : return 12299;
        case 300 : return 15869;
        case 400 : return 12471;
        case 500 : return 23507;
        case 600 : return 27311;
        case 700 : return 20152;
        case 800 : return 33591;
        case 900 : return 20426;
        case 1000 : return 31041;
        case 1050 : return 33565;
        case 1100 : return 36253;
        case 1150 : return 30017;
        case 1200 : return 23885;
        case 1250 : return 33789;
        case 1300 : return 44406;
        case 1325 : return 30803;
        case 1340 : return 26345;
    }
  }
    if (a==1400) {
      switch (b) {
        case 127 : return 7907;
        case 150 : return 8716;
        case 175 : return 3547;
        case 200 : return 8762;
        case 300 : return 9723;
        case 400 : return 22973;
        case 500 : return 15976;
        case 600 : return 21200;
        case 700 : return 15910;
        case 800 : return 25547;
        case 900 : return 25476;
        case 1000 : return 24161;
        case 1100 : return 31731;
        case 1150 : return 35174;
        case 1200 : return 23933;
        case 1250 : return 27557;
        case 1300 : return 24844;
        case 1350 : return 35336;
        case 1375 : return 23606;
        case 1390 : return 24792;
    }
  }
    if (a==1450) {
      switch (b) {
        case 127 : return 6193;
        case 150 : return 8976;
        case 175 : return 9773;
        case 200 : return 7096;
        case 300 : return 14190;
        case 400 : return 22492;
        case 500 : return 14259;
        case 600 : return 21189;
        case 700 : return 23955;
        case 800 : return 22191;
        case 900 : return 25089;
        case 1000 : return 26691;
        case 1100 : return 20257;
        case 1150 : return 34516;
        case 1200 : return 30223;
        case 1250 : return 24848;
        case 1300 : return 27424;
        case 1350 : return 31966;
        case 1400 : return 25660;
        case 1425 : return 22980;
        case 1440 : return 39226;
    }
  }
    if (a==1500) {
      switch (b) {
        case 127 : return 5319;
        case 150 : return 8079;
        case 175 : return 10716;
        case 200 : return 10524;
        case 300 : return 8937;
        case 400 : return 16126;
        case 500 : return 11603;
        case 600 : return 16892;
        case 700 : return 15955;
        case 800 : return 21458;
        case 900 : return 20496;
        case 1000 : return 24744;
        case 1100 : return 28306;
        case 1200 : return 27789;
        case 1250 : return 23259;
        case 1300 : return 31139;
        case 1350 : return 27651;
        case 1400 : return 32006;
        case 1450 : return 28525;
        case 1475 : return 31218;
        case 1490 : return 31014;
    }
  }
    if (a==1550) {
      switch (b) {
        case 127 : return 4475;
        case 150 : return 3584;
        case 175 : return 8049;
        case 200 : return 7928;
        case 300 : return 8916;
        case 400 : return 10659;
        case 500 : return 22596;
        case 600 : return 15272;
        case 700 : return 27513;
        case 800 : return 26747;
        case 900 : return 26369;
        case 1000 : return 29516;
        case 1100 : return 26921;
        case 1200 : return 29517;
        case 1250 : return 27747;
        case 1300 : return 29659;
        case 1350 : return 38542;
        case 1400 : return 26137;
        case 1450 : return 27141;
        case 1500 : return 39135;
        case 1525 : return 28836;
        case 1540 : return 31498;
    }
  }
    if (a==1600) {
      switch (b) {
        case 127 : return 10849;
        case 150 : return 6284;
        case 175 : return 7274;
        case 200 : return 10738;
        case 300 : return 17058;
        case 400 : return 15320;
        case 500 : return 13430;
        case 600 : return 16915;
        case 700 : return 20744;
        case 800 : return 16528;
        case 900 : return 22439;
        case 1000 : return 31361;
        case 1100 : return 23447;
        case 1200 : return 31685;
        case 1300 : return 42550;
        case 1350 : return 36098;
        case 1400 : return 40014;
        case 1450 : return 42518;
        case 1500 : return 31678;
        case 1550 : return 29821;
        case 1575 : return 42592;
        case 1590 : return 28009;
    }
  }
    if (a==1650) {
      switch (b) {
        case 127 : return 4583;
        case 150 : return 10859;
        case 175 : return 8178;
        case 200 : return 13502;
        case 300 : return 15551;
        case 400 : return 7249;
        case 500 : return 15644;
        case 600 : return 26445;
        case 700 : return 21771;
        case 800 : return 23647;
        case 900 : return 31046;
        case 1000 : return 29035;
        case 1100 : return 43417;
        case 1200 : return 23035;
        case 1300 : return 34551;
        case 1350 : return 23595;
        case 1400 : return 30957;
        case 1450 : return 34594;
        case 1500 : return 32599;
        case 1550 : return 41690;
        case 1600 : return 29025;
        case 1625 : return 29213;
        case 1640 : return 36090;
    }
  }
    if (a==1700) {
      switch (b) {
        case 127 : return 2735;
        case 150 : return 7358;
        case 175 : return 9112;
        case 200 : return 15591;
        case 300 : return 12667;
        case 400 : return 14614;
        case 500 : return 16217;
        case 600 : return 19844;
        case 700 : return 14804;
        case 800 : return 24569;
        case 900 : return 26559;
        case 1000 : return 32055;
        case 1100 : return 24781;
        case 1200 : return 32735;
        case 1300 : return 29392;
        case 1400 : return 25746;
        case 1450 : return 22716;
        case 1500 : return 26542;
        case 1550 : return 39170;
        case 1600 : return 34809;
        case 1650 : return 42982;
        case 1675 : return 33871;
        case 1690 : return 40948;
    }
  }
    if (a==1750) {
      switch (b) {
        case 127 : return 2740;
        case 150 : return 11077;
        case 175 : return 7318;
        case 200 : return 7222;
        case 300 : return 13713;
        case 400 : return 21192;
        case 500 : return 13848;
        case 600 : return 19444;
        case 700 : return 24119;
        case 800 : return 28483;
        case 900 : return 25826;
        case 1000 : return 35031;
        case 1100 : return 24179;
        case 1200 : return 27473;
        case 1300 : return 33269;
        case 1400 : return 27723;
        case 1450 : return 33811;
        case 1500 : return 24932;
        case 1550 : return 29355;
        case 1600 : return 39559;
        case 1650 : return 30584;
        case 1700 : return 30626;
        case 1725 : return 35781;
        case 1740 : return 29302;
    }
  }
    if (a==1800) {
      switch (b) {
        case 127 : return 7458;
        case 150 : return 5612;
        case 175 : return 11254;
        case 200 : return 12075;
        case 300 : return 18408;
        case 400 : return 11053;
        case 500 : return 16531;
        case 600 : return 18655;
        case 700 : return 22266;
        case 800 : return 22379;
        case 900 : return 29749;
        case 1000 : return 24055;
        case 1100 : return 20622;
        case 1200 : return 30834;
        case 1300 : return 32287;
        case 1400 : return 35341;
        case 1500 : return 32415;
        case 1550 : return 33285;
        case 1600 : return 29732;
        case 1650 : return 20411;
        case 1700 : return 27794;
        case 1750 : return 28748;
        case 1775 : return 32486;
        case 1790 : return 30736;
    }
  }
    if (a==1850) {
      switch (b) {
        case 127 : return 8452;
        case 150 : return 8391;
        case 175 : return 13134;
        case 200 : return 10161;
        case 300 : return 6534;
        case 400 : return 6581;
        case 500 : return 12126;
        case 600 : return 13980;
        case 700 : return 23197;
        case 800 : return 17932;
        case 900 : return 15114;
        case 1000 : return 29172;
        case 1100 : return 25260;
        case 1200 : return 25224;
        case 1300 : return 25684;
        case 1400 : return 29983;
        case 1500 : return 27275;
        case 1550 : return 36495;
        case 1600 : return 24480;
        case 1650 : return 40996;
        case 1700 : return 27262;
        case 1750 : return 32846;
        case 1800 : return 29055;
        case 1825 : return 35926;
        case 1840 : return 31755;
    }
  }
    if (a==1900) {
      switch (b) {
        case 127 : return 4681;
        case 150 : return 4869;
        case 175 : return 8563;
        case 200 : return 13843;
        case 300 : return 14873;
        case 400 : return 19028;
        case 500 : return 16063;
        case 600 : return 17060;
        case 700 : return 25563;
        case 800 : return 19190;
        case 900 : return 21661;
        case 1000 : return 34835;
        case 1100 : return 24616;
        case 1200 : return 28348;
        case 1300 : return 37775;
        case 1400 : return 36234;
        case 1500 : return 34078;
        case 1600 : return 31236;
        case 1650 : return 29696;
        case 1700 : return 36916;
        case 1750 : return 28581;
        case 1800 : return 32105;
        case 1850 : return 30281;
        case 1875 : return 28368;
        case 1890 : return 34132;
    }
  }
    if (a==1950) {
      switch (b) {
        case 127 : return 5714;
        case 150 : return 7612;
        case 175 : return 8614;
        case 200 : return 8582;
        case 300 : return 14363;
        case 400 : return 17074;
        case 500 : return 5679;
        case 600 : return 21949;
        case 700 : return 18087;
        case 800 : return 15026;
        case 900 : return 30451;
        case 1000 : return 22130;
        case 1100 : return 31486;
        case 1200 : return 37566;
        case 1300 : return 21213;
        case 1400 : return 36454;
        case 1500 : return 29031;
        case 1600 : return 36386;
        case 1650 : return 35648;
        case 1700 : return 38292;
        case 1750 : return 41083;
        case 1800 : return 36672;
        case 1850 : return 27661;
        case 1900 : return 44006;
        case 1925 : return 32602;
        case 1940 : return 36200;
    }
  }
    if (a==2000) {
      switch (b) {
        case 127 : return 4829;
        case 150 : return 3855;
        case 175 : return 4760;
        case 200 : return 5775;
        case 300 : return 3864;
        case 400 : return 1928;
        case 500 : return 11454;
        case 600 : return 10543;
        case 700 : return 9583;
        case 800 : return 11483;
        case 900 : return 13402;
        case 1000 : return 18407;
        case 1100 : return 8859;
        case 1200 : return 9793;
        case 1300 : return 6786;
        case 1400 : return 10702;
        case 1500 : return 13541;
        case 1600 : return 9667;
        case 1700 : return 15430;
        case 1750 : return 26102;
        case 1800 : return 17316;
        case 1850 : return 16445;
        case 1900 : return 19267;
        case 1950 : return 20108;
        case 1975 : return 13548;
        case 1990 : return 14425;
    }
  }
    if (a==2050) {
      switch (b) {
        case 127 : return 1984;
        case 150 : return 5884;
        case 175 : return 8674;
        case 200 : return 2859;
        case 300 : return 5768;
        case 400 : return 9634;
        case 500 : return 6889;
        case 600 : return 3977;
        case 700 : return 15401;
        case 800 : return 12685;
        case 900 : return 11593;
        case 1000 : return 14727;
        case 1100 : return 16379;
        case 1200 : return 17799;
        case 1300 : return 11647;
        case 1400 : return 16671;
        case 1500 : return 10761;
        case 1600 : return 20609;
        case 1700 : return 19594;
        case 1750 : return 20445;
        case 1800 : return 21509;
        case 1850 : return 17613;
        case 1900 : return 16640;
        case 1950 : return 16715;
        case 2000 : return 19700;
        case 2025 : return 15579;
        case 2040 : return 12507;
    }
  }
    if (a==2100) {
      switch (b) {
        case 127 : return 993;
        case 150 : return 990;
        case 175 : return 7920;
        case 200 : return 3885;
        case 300 : return 6904;
        case 400 : return 5950;
        case 500 : return 7962;
        case 600 : return 11860;
        case 700 : return 5881;
        case 800 : return 13845;
        case 900 : return 13936;
        case 1000 : return 14084;
        case 1100 : return 14809;
        case 1200 : return 14033;
        case 1300 : return 17646;
        case 1400 : return 17581;
        case 1500 : return 18714;
        case 1600 : return 6914;
        case 1700 : return 17810;
        case 1800 : return 17735;
        case 1850 : return 13973;
        case 1900 : return 10922;
        case 1950 : return 15918;
        case 2000 : return 14766;
        case 2050 : return 16709;
        case 2075 : return 16893;
        case 2090 : return 17692;
    }
  }
    if (a==2150) {
      switch (b) {
        case 127 : return 1955;
        case 150 : return 1963;
        case 175 : return 5070;
        case 200 : return 3004;
        case 300 : return 2983;
        case 400 : return 2033;
        case 500 : return 6897;
        case 600 : return 8130;
        case 700 : return 7034;
        case 800 : return 6885;
        case 900 : return 9125;
        case 1000 : return 11877;
        case 1100 : return 14807;
        case 1200 : return 18848;
        case 1300 : return 12080;
        case 1400 : return 16045;
        case 1500 : return 12984;
        case 1600 : return 16974;
        case 1700 : return 20023;
        case 1800 : return 9071;
        case 1850 : return 15974;
        case 1900 : return 21936;
        case 1950 : return 13753;
        case 2000 : return 12129;
        case 2050 : return 24105;
        case 2100 : return 12933;
        case 2125 : return 20943;
        case 2140 : return 14941;
    }
  }
    if (a==2200) {
      switch (b) {
        case 127 : return 3024;
        case 150 : return 6127;
        case 175 : return 6992;
        case 200 : return 8998;
        case 300 : return 7104;
        case 400 : return 11123;
        case 500 : return 13073;
        case 600 : return 10100;
        case 700 : return 13088;
        case 800 : return 7076;
        case 900 : return 13197;
        case 1000 : return 12096;
        case 1100 : return 16321;
        case 1200 : return 14048;
        case 1300 : return 16323;
        case 1400 : return 17081;
        case 1500 : return 17277;
        case 1600 : return 19452;
        case 1700 : return 14117;
        case 1800 : return 23484;
        case 1900 : return 17269;
        case 1950 : return 19339;
        case 2000 : return 17235;
        case 2050 : return 15299;
        case 2100 : return 18239;
        case 2150 : return 16196;
        case 2175 : return 20304;
        case 2190 : return 21316;
    }
  }
    if (a==2250) {
      switch (b) {
        case 127 : return 1036;
        case 150 : return 8405;
        case 175 : return 1000;
        case 200 : return 8093;
        case 300 : return 3165;
        case 400 : return 7191;
        case 500 : return 7163;
        case 600 : return 15292;
        case 700 : return 11262;
        case 800 : return 16448;
        case 900 : return 16533;
        case 1000 : return 7122;
        case 1100 : return 9373;
        case 1200 : return 15182;
        case 1300 : return 13380;
        case 1400 : return 10280;
        case 1500 : return 18369;
        case 1600 : return 17541;
        case 1700 : return 18757;
        case 1800 : return 18383;
        case 1900 : return 18611;
        case 1950 : return 20466;
        case 2000 : return 20638;
        case 2050 : return 18448;
        case 2100 : return 16511;
        case 2150 : return 11474;
        case 2200 : return 15431;
        case 2225 : return 15424;
        case 2240 : return 17363;
    }
  }
    if (a==2300) {
      switch (b) {
        case 127 : return 3227;
        case 150 : return 3049;
        case 175 : return 7299;
        case 200 : return 4149;
        case 300 : return 3199;
        case 400 : return 6320;
        case 500 : return 7239;
        case 600 : return 11336;
        case 700 : return 11309;
        case 800 : return 13532;
        case 900 : return 8399;
        case 1000 : return 12513;
        case 1100 : return 7274;
        case 1200 : return 19696;
        case 1300 : return 21092;
        case 1400 : return 11408;
        case 1500 : return 7381;
        case 1600 : return 27107;
        case 1700 : return 17619;
        case 1800 : return 13507;
        case 1900 : return 12449;
        case 2000 : return 18039;
        case 2050 : return 22911;
        case 2100 : return 17644;
        case 2150 : return 22993;
        case 2200 : return 13666;
        case 2250 : return 14615;
        case 2275 : return 15758;
        case 2290 : return 12426;
    }
  }
    if (a==2350) {
      switch (b) {
        case 127 : return 3094;
        case 150 : return 6373;
        case 175 : return 5263;
        case 200 : return 4230;
        case 300 : return 6323;
        case 400 : return 6394;
        case 500 : return 7430;
        case 600 : return 4190;
        case 700 : return 9424;
        case 800 : return 10589;
        case 900 : return 13659;
        case 1000 : return 14786;
        case 1100 : return 9546;
        case 1200 : return 18978;
        case 1300 : return 12706;
        case 1400 : return 10556;
        case 1500 : return 15820;
        case 1600 : return 15843;
        case 1700 : return 11584;
        case 1800 : return 19121;
        case 1900 : return 20219;
        case 2000 : return 18038;
        case 2050 : return 15016;
        case 2100 : return 8461;
        case 2150 : return 14895;
        case 2200 : return 16777;
        case 2250 : return 14977;
        case 2300 : return 12818;
        case 2325 : return 19206;
        case 2340 : return 23117;
    }
  }
    if (a==2400) {
      switch (b) {
        case 127 : return 4292;
        case 150 : return 3380;
        case 175 : return 1060;
        case 200 : return 7357;
        case 300 : return 7485;
        case 400 : return 3227;
        case 500 : return 9599;
        case 600 : return 10672;
        case 700 : return 11888;
        case 800 : return 6432;
        case 900 : return 5406;
        case 1000 : return 11872;
        case 1100 : return 12927;
        case 1200 : return 19320;
        case 1300 : return 13823;
        case 1400 : return 14004;
        case 1500 : return 18463;
        case 1600 : return 11912;
        case 1700 : return 17234;
        case 1800 : return 18276;
        case 1900 : return 15079;
        case 2000 : return 21691;
        case 2100 : return 17323;
        case 2150 : return 19208;
        case 2200 : return 8612;
        case 2250 : return 16133;
        case 2300 : return 20586;
        case 2350 : return 16086;
        case 2375 : return 16069;
        case 2390 : return 24586;
    }
  }
    if (a==2450) {
      switch (b) {
        case 127 : return 2176;
        case 150 : return 2227;
        case 175 : return 4334;
        case 200 : return 6521;
        case 300 : return 9736;
        case 400 : return 13153;
        case 500 : return 9763;
        case 600 : return 6476;
        case 700 : return 12057;
        case 800 : return 4414;
        case 900 : return 4273;
        case 1000 : return 3324;
        case 1100 : return 15215;
        case 1200 : return 21899;
        case 1300 : return 17601;
        case 1400 : return 10984;
        case 1500 : return 11052;
        case 1600 : return 16314;
        case 1700 : return 17484;
        case 1800 : return 24020;
        case 1900 : return 9818;
        case 2000 : return 18660;
        case 2100 : return 13145;
        case 2150 : return 12003;
        case 2200 : return 20969;
        case 2250 : return 14304;
        case 2300 : return 20644;
        case 2350 : return 19843;
        case 2400 : return 15412;
        case 2425 : return 14196;
        case 2440 : return 20863;
    }
  }
    if (a==2500) {
      switch (b) {
        case 127 : return 4415;
        case 150 : return 4442;
        case 175 : return 5538;
        case 200 : return 3315;
        case 300 : return 6567;
        case 400 : return 3372;
        case 500 : return 9927;
        case 600 : return 9949;
        case 700 : return 11130;
        case 800 : return 10004;
        case 900 : return 17793;
        case 1000 : return 12089;
        case 1100 : return 13203;
        case 1200 : return 21252;
        case 1300 : return 6713;
        case 1400 : return 7757;
        case 1500 : return 16659;
        case 1600 : return 17901;
        case 1700 : return 21218;
        case 1800 : return 15452;
        case 1900 : return 9048;
        case 2000 : return 12165;
        case 2100 : return 22227;
        case 2200 : return 13265;
        case 2250 : return 13349;
        case 2300 : return 23291;
        case 2350 : return 20015;
        case 2400 : return 17800;
        case 2450 : return 17825;
        case 2475 : return 19998;
        case 2490 : return 15482;
    }
  }
    if (a==2550) {
      switch (b) {
        case 127 : return 4558;
        case 150 : return 5727;
        case 175 : return 6685;
        case 200 : return 4500;
        case 300 : return 3389;
        case 400 : return 5549;
        case 500 : return 7932;
        case 600 : return 10214;
        case 700 : return 7847;
        case 800 : return 4465;
        case 900 : return 11230;
        case 1000 : return 9101;
        case 1100 : return 11236;
        case 1200 : return 11394;
        case 1300 : return 14745;
        case 1400 : return 15550;
        case 1500 : return 15747;
        case 1600 : return 13623;
        case 1700 : return 16080;
        case 1800 : return 16989;
        case 1900 : return 22764;
        case 2000 : return 20333;
        case 2100 : return 27169;
        case 2200 : return 19118;
        case 2250 : return 19213;
        case 2300 : return 16961;
        case 2350 : return 13522;
        case 2400 : return 14759;
        case 2450 : return 20409;
        case 2500 : return 12484;
        case 2525 : return 26037;
        case 2540 : return 15656;
    }
  }
    if (a==2600) {
      switch (b) {
        case 127 : return 4620;
        case 150 : return 7885;
        case 175 : return 5809;
        case 200 : return 4544;
        case 300 : return 7956;
        case 400 : return 15027;
        case 500 : return 9223;
        case 600 : return 12585;
        case 700 : return 9326;
        case 800 : return 18218;
        case 900 : return 10327;
        case 1000 : return 13675;
        case 1100 : return 17079;
        case 1200 : return 14924;
        case 1300 : return 15866;
        case 1400 : return 6871;
        case 1500 : return 10316;
        case 1600 : return 16191;
        case 1700 : return 27563;
        case 1800 : return 21664;
        case 1900 : return 19445;
        case 2000 : return 17213;
        case 2100 : return 17173;
        case 2200 : return 6965;
        case 2300 : return 16088;
        case 2350 : return 19644;
        case 2400 : return 10398;
        case 2450 : return 11417;
        case 2500 : return 24098;
        case 2550 : return 9269;
        case 2575 : return 19559;
        case 2590 : return 17165;
    }
  }
    if (a==2650) {
      switch (b) {
        case 127 : return 0;
        case 150 : return 3345;
        case 175 : return 2264;
        case 200 : return 8059;
        case 300 : return 7045;
        case 400 : return 1146;
        case 500 : return 8091;
        case 600 : return 9311;
        case 700 : return 5764;
        case 800 : return 8124;
        case 900 : return 16235;
        case 1000 : return 13025;
        case 1100 : return 16238;
        case 1200 : return 18610;
        case 1300 : return 11704;
        case 1400 : return 13834;
        case 1500 : return 14040;
        case 1600 : return 17560;
        case 1700 : return 22088;
        case 1800 : return 13899;
        case 1900 : return 12829;
        case 2000 : return 11549;
        case 2100 : return 10496;
        case 2200 : return 17419;
        case 2300 : return 12805;
        case 2350 : return 17396;
        case 2400 : return 18715;
        case 2450 : return 11616;
        case 2500 : return 17428;
        case 2550 : return 11671;
        case 2600 : return 15277;
        case 2625 : return 19863;
        case 2640 : return 5850;
    }
  }
    if (a==2700) {
      switch (b) {
        case 127 : return 3636;
        case 150 : return 1209;
        case 175 : return 3460;
        case 200 : return 8257;
        case 300 : return 11788;
        case 400 : return 11900;
        case 500 : return 10493;
        case 600 : return 8244;
        case 700 : return 5844;
        case 800 : return 11888;
        case 900 : return 8209;
        case 1000 : return 17653;
        case 1100 : return 20102;
        case 1200 : return 9462;
        case 1300 : return 12985;
        case 1400 : return 8269;
        case 1500 : return 14193;
        case 1600 : return 12026;
        case 1700 : return 11928;
        case 1800 : return 19036;
        case 1900 : return 21188;
        case 2000 : return 15481;
        case 2100 : return 20248;
        case 2200 : return 18976;
        case 2300 : return 20106;
        case 2400 : return 14321;
        case 2450 : return 21311;
        case 2500 : return 15326;
        case 2550 : return 16529;
        case 2600 : return 18988;
        case 2650 : return 6029;
        case 2675 : return 14316;
        case 2690 : return 14291;
    }
  }
    if (a==2750) {
      switch (b) {
        case 127 : return 7239;
        case 150 : return 2352;
        case 175 : return 5904;
        case 200 : return 2456;
        case 300 : return 5948;
        case 400 : return 8437;
        case 500 : return 6003;
        case 600 : return 4797;
        case 700 : return 7283;
        case 800 : return 5991;
        case 900 : return 10860;
        case 1000 : return 12014;
        case 1100 : return 19262;
        case 1200 : return 8386;
        case 1300 : return 22877;
        case 1400 : return 19302;
        case 1500 : return 16877;
        case 1600 : return 14435;
        case 1700 : return 19234;
        case 1800 : return 15674;
        case 1900 : return 16966;
        case 2000 : return 19471;
        case 2100 : return 13234;
        case 2200 : return 23073;
        case 2300 : return 18119;
        case 2400 : return 12062;
        case 2450 : return 16909;
        case 2500 : return 17035;
        case 2550 : return 7262;
        case 2600 : return 22944;
        case 2650 : return 16821;
        case 2700 : return 10857;
        case 2725 : return 20398;
        case 2740 : return 10829;
    }
  }
    if (a==2800) {
      switch (b) {
        case 127 : return 1212;
        case 150 : return 2461;
        case 175 : return 7354;
        case 200 : return 4904;
        case 300 : return 8592;
        case 400 : return 4910;
        case 500 : return 7469;
        case 600 : return 9775;
        case 700 : return 9939;
        case 800 : return 20777;
        case 900 : return 13453;
        case 1000 : return 13394;
        case 1100 : return 14643;
        case 1200 : return 20668;
        case 1300 : return 11098;
        case 1400 : return 18337;
        case 1500 : return 19598;
        case 1600 : return 7493;
        case 1700 : return 17137;
        case 1800 : return 22052;
        case 1900 : return 9870;
        case 2000 : return 14906;
        case 2100 : return 18316;
        case 2200 : return 24625;
        case 2300 : return 19769;
        case 2400 : return 20813;
        case 2500 : return 19642;
        case 2550 : return 14864;
        case 2600 : return 13614;
        case 2650 : return 7466;
        case 2700 : return 17263;
        case 2750 : return 7328;
        case 2775 : return 12422;
        case 2790 : return 10985;
    }
  }
      case 3017 :
    if (a==800) {
      switch (b) {
        case 127 : return 24411;
        case 200 : return 34251;
        case 300 : return 46944;
        case 400 : return 61769;
        case 500 : return 70920;
        case 600 : return 75206;
        case 700 : return 85105;
        case 790 : return 85728;
    }
  }
    if (a==900) {
      switch (b) {
        case 127 : return 12583;
        case 200 : return 32370;
        case 300 : return 55492;
        case 400 : return 65576;
        case 500 : return 59409;
        case 600 : return 57980;
        case 700 : return 73693;
        case 800 : return 80990;
        case 890 : return 69896;
    }
  }
    if (a==1000) {
      switch (b) {
        case 127 : return 24468;
        case 150 : return 17561;
        case 175 : return 35885;
        case 200 : return 40821;
        case 300 : return 52013;
        case 400 : return 62112;
        case 500 : return 64610;
        case 600 : return 71284;
        case 700 : return 64592;
        case 750 : return 62623;
        case 800 : return 81260;
        case 850 : return 85365;
        case 900 : return 95725;
        case 950 : return 85412;
        case 975 : return 95565;
        case 990 : return 95655;
    }
  }
    if (a==1050) {
      switch (b) {
        case 127 : return 20914;
        case 150 : return 27799;
        case 175 : return 38874;
        case 200 : return 45716;
        case 300 : return 43499;
        case 400 : return 65392;
        case 500 : return 60024;
        case 600 : return 59179;
        case 700 : return 76348;
        case 750 : return 72949;
        case 800 : return 72489;
        case 850 : return 79475;
        case 900 : return 78634;
        case 950 : return 89792;
        case 1000 : return 90688;
        case 1025 : return 94365;
        case 1040 : return 84205;
    }
  }
    if (a==1100) {
      switch (b) {
        case 127 : return 30256;
        case 150 : return 18101;
        case 175 : return 28718;
        case 200 : return 25010;
        case 300 : return 47821;
        case 400 : return 55393;
        case 500 : return 52051;
        case 600 : return 53732;
        case 700 : return 64528;
        case 800 : return 72971;
        case 850 : return 80610;
        case 900 : return 93180;
        case 950 : return 80176;
        case 1000 : return 83938;
        case 1050 : return 78189;
        case 1075 : return 94883;
        case 1090 : return 72101;
    }
  }
    if (a==1150) {
      switch (b) {
        case 127 : return 10506;
        case 150 : return 14828;
        case 175 : return 22362;
        case 200 : return 24217;
        case 300 : return 24319;
        case 400 : return 43407;
        case 500 : return 37495;
        case 600 : return 39895;
        case 700 : return 43611;
        case 800 : return 54441;
        case 850 : return 42658;
        case 900 : return 60347;
        case 950 : return 48719;
        case 1000 : return 56687;
        case 1050 : return 61619;
        case 1100 : return 69592;
        case 1125 : return 67479;
        case 1140 : return 72284;
    }
  }
    if (a==1200) {
      switch (b) {
        case 127 : return 7034;
        case 150 : return 8759;
        case 175 : return 17505;
        case 200 : return 16549;
        case 300 : return 22475;
        case 400 : return 23575;
        case 500 : return 30635;
        case 600 : return 22513;
        case 700 : return 27869;
        case 800 : return 29603;
        case 900 : return 40089;
        case 950 : return 40850;
        case 1000 : return 40092;
        case 1050 : return 36773;
        case 1100 : return 34307;
        case 1150 : return 38396;
        case 1175 : return 39966;
        case 1190 : return 44458;
    }
  }
    if (a==1250) {
      switch (b) {
        case 127 : return 6044;
        case 150 : return 5208;
        case 175 : return 6902;
        case 200 : return 4275;
        case 300 : return 21750;
        case 400 : return 13049;
        case 500 : return 20959;
        case 600 : return 24390;
        case 700 : return 21029;
        case 800 : return 30493;
        case 900 : return 32200;
        case 950 : return 29470;
        case 1000 : return 34059;
        case 1050 : return 26256;
        case 1100 : return 39300;
        case 1150 : return 28122;
        case 1200 : return 29910;
        case 1225 : return 34797;
        case 1240 : return 35806;
    }
  }
    if (a==1300) {
      switch (b) {
        case 127 : return 4447;
        case 150 : return 5271;
        case 175 : return 4382;
        case 200 : return 8719;
        case 300 : return 16440;
        case 400 : return 12883;
        case 500 : return 15684;
        case 600 : return 16784;
        case 700 : return 11265;
        case 800 : return 22200;
        case 900 : return 19330;
        case 1000 : return 35838;
        case 1050 : return 28180;
        case 1100 : return 25437;
        case 1150 : return 18364;
        case 1200 : return 21008;
        case 1250 : return 27868;
        case 1275 : return 23421;
        case 1290 : return 23553;
    }
  }
    if (a==1350) {
      switch (b) {
        case 127 : return 4437;
        case 150 : return 1715;
        case 175 : return 9712;
        case 200 : return 8730;
        case 300 : return 15806;
        case 400 : return 13253;
        case 500 : return 14065;
        case 600 : return 21045;
        case 700 : return 13159;
        case 800 : return 25624;
        case 900 : return 21135;
        case 1000 : return 21154;
        case 1050 : return 22013;
        case 1100 : return 35768;
        case 1150 : return 27980;
        case 1200 : return 29975;
        case 1250 : return 30584;
        case 1300 : return 26615;
        case 1325 : return 30527;
        case 1340 : return 28322;
    }
  }
    if (a==1400) {
      switch (b) {
        case 127 : return 2712;
        case 150 : return 7914;
        case 175 : return 7877;
        case 200 : return 9567;
        case 300 : return 9586;
        case 400 : return 12494;
        case 500 : return 20108;
        case 600 : return 12503;
        case 700 : return 14131;
        case 800 : return 18692;
        case 900 : return 19355;
        case 1000 : return 22013;
        case 1100 : return 28022;
        case 1150 : return 31116;
        case 1200 : return 27385;
        case 1250 : return 24700;
        case 1300 : return 30220;
        case 1350 : return 22934;
        case 1375 : return 21245;
        case 1390 : return 20358;
    }
  }
    if (a==1450) {
      switch (b) {
        case 127 : return 5248;
        case 150 : return 6248;
        case 175 : return 8820;
        case 200 : return 9677;
        case 300 : return 6993;
        case 400 : return 16630;
        case 500 : return 16885;
        case 600 : return 20470;
        case 700 : return 13420;
        case 800 : return 24861;
        case 900 : return 22165;
        case 1000 : return 18659;
        case 1100 : return 17854;
        case 1150 : return 26900;
        case 1200 : return 34477;
        case 1250 : return 30042;
        case 1300 : return 28358;
        case 1350 : return 30182;
        case 1400 : return 31111;
        case 1425 : return 28332;
        case 1440 : return 26660;
    }
  }
    if (a==1500) {
      switch (b) {
        case 127 : return 5313;
        case 150 : return 13448;
        case 175 : return 5278;
        case 200 : return 14087;
        case 300 : return 7808;
        case 400 : return 15303;
        case 500 : return 19568;
        case 600 : return 19536;
        case 700 : return 18636;
        case 800 : return 13274;
        case 900 : return 12410;
        case 1000 : return 15063;
        case 1100 : return 27793;
        case 1200 : return 22152;
        case 1250 : return 21318;
        case 1300 : return 32988;
        case 1350 : return 32029;
        case 1400 : return 33910;
        case 1450 : return 36827;
        case 1475 : return 20207;
        case 1490 : return 30213;
    }
  }
    if (a==1550) {
      switch (b) {
        case 127 : return 8036;
        case 150 : return 8061;
        case 175 : return 5306;
        case 200 : return 8993;
        case 300 : return 12457;
        case 400 : return 8005;
        case 500 : return 10646;
        case 600 : return 22278;
        case 700 : return 16004;
        case 800 : return 21549;
        case 900 : return 15124;
        case 1000 : return 29447;
        case 1100 : return 24155;
        case 1200 : return 26805;
        case 1250 : return 16098;
        case 1300 : return 24025;
        case 1350 : return 26714;
        case 1400 : return 35068;
        case 1450 : return 21558;
        case 1500 : return 23366;
        case 1525 : return 25318;
        case 1540 : return 22214;
    }
  }
    if (a==1600) {
      switch (b) {
        case 127 : return 4457;
        case 150 : return 2679;
        case 175 : return 6321;
        case 200 : return 12531;
        case 300 : return 10792;
        case 400 : return 11798;
        case 500 : return 15316;
        case 600 : return 12436;
        case 700 : return 24358;
        case 800 : return 22541;
        case 900 : return 15221;
        case 1000 : return 19717;
        case 1100 : return 27812;
        case 1200 : return 21642;
        case 1300 : return 28692;
        case 1350 : return 25284;
        case 1400 : return 43958;
        case 1450 : return 29706;
        case 1500 : return 28001;
        case 1550 : return 26148;
        case 1575 : return 35945;
        case 1590 : return 41538;
    }
  }
    if (a==1650) {
      switch (b) {
        case 127 : return 7341;
        case 150 : return 5522;
        case 175 : return 6346;
        case 200 : return 11563;
        case 300 : return 12521;
        case 400 : return 13530;
        case 500 : return 11678;
        case 600 : return 8193;
        case 700 : return 19864;
        case 800 : return 20893;
        case 900 : return 13475;
        case 1000 : return 25444;
        case 1100 : return 22028;
        case 1200 : return 18847;
        case 1300 : return 20798;
        case 1350 : return 36231;
        case 1400 : return 27473;
        case 1450 : return 34404;
        case 1500 : return 33751;
        case 1550 : return 26998;
        case 1600 : return 26217;
        case 1625 : return 31685;
        case 1640 : return 32518;
    }
  }
    if (a==1700) {
      switch (b) {
        case 127 : return 3633;
        case 150 : return 2687;
        case 175 : return 5550;
        case 200 : return 10136;
        case 300 : return 13507;
        case 400 : return 19976;
        case 500 : return 17405;
        case 600 : return 17249;
        case 700 : return 21649;
        case 800 : return 21476;
        case 900 : return 16668;
        case 1000 : return 23016;
        case 1100 : return 25401;
        case 1200 : return 30931;
        case 1300 : return 17184;
        case 1400 : return 32120;
        case 1450 : return 31218;
        case 1500 : return 34875;
        case 1550 : return 39433;
        case 1600 : return 28115;
        case 1650 : return 18212;
        case 1675 : return 31900;
        case 1690 : return 24458;
    }
  }
    if (a==1750) {
      switch (b) {
        case 127 : return 6458;
        case 150 : return 6423;
        case 175 : return 7375;
        case 200 : return 7360;
        case 300 : return 6405;
        case 400 : return 13771;
        case 500 : return 20112;
        case 600 : return 18570;
        case 700 : return 18362;
        case 800 : return 15598;
        case 900 : return 23879;
        case 1000 : return 21856;
        case 1100 : return 18242;
        case 1200 : return 18270;
        case 1300 : return 29275;
        case 1400 : return 29309;
        case 1450 : return 27635;
        case 1500 : return 27691;
        case 1550 : return 31280;
        case 1600 : return 34187;
        case 1650 : return 31354;
        case 1700 : return 36961;
        case 1725 : return 27630;
        case 1740 : return 32871;
    }
  }
    if (a==1800) {
      switch (b) {
        case 127 : return 5616;
        case 150 : return 5597;
        case 175 : return 13902;
        case 200 : return 10244;
        case 300 : return 21089;
        case 400 : return 13063;
        case 500 : return 12002;
        case 600 : return 9146;
        case 700 : return 14696;
        case 800 : return 13136;
        case 900 : return 20598;
        case 1000 : return 27926;
        case 1100 : return 15833;
        case 1200 : return 27883;
        case 1300 : return 31455;
        case 1400 : return 25869;
        case 1500 : return 26910;
        case 1550 : return 27031;
        case 1600 : return 37242;
        case 1650 : return 25919;
        case 1700 : return 38070;
        case 1750 : return 20323;
        case 1775 : return 35222;
        case 1790 : return 27123;
    }
  }
    if (a==1850) {
      switch (b) {
        case 127 : return 4661;
        case 150 : return 957;
        case 175 : return 5626;
        case 200 : return 11197;
        case 300 : return 5702;
        case 400 : return 11114;
        case 500 : return 6462;
        case 600 : return 25179;
        case 700 : return 12102;
        case 800 : return 15998;
        case 900 : return 26213;
        case 1000 : return 22712;
        case 1100 : return 21529;
        case 1200 : return 29936;
        case 1300 : return 18713;
        case 1400 : return 36303;
        case 1500 : return 31811;
        case 1550 : return 28082;
        case 1600 : return 32809;
        case 1650 : return 27083;
        case 1700 : return 24320;
        case 1750 : return 35498;
        case 1800 : return 30944;
        case 1825 : return 26161;
        case 1840 : return 36541;
    }
  }
    if (a==1900) {
      switch (b) {
        case 127 : return 2849;
        case 150 : return 4677;
        case 175 : return 7528;
        case 200 : return 4641;
        case 300 : return 10267;
        case 400 : return 14129;
        case 500 : return 5701;
        case 600 : return 15997;
        case 700 : return 15130;
        case 800 : return 24570;
        case 900 : return 15991;
        case 1000 : return 26335;
        case 1100 : return 41391;
        case 1200 : return 37777;
        case 1300 : return 21750;
        case 1400 : return 35027;
        case 1500 : return 34258;
        case 1600 : return 22738;
        case 1650 : return 30202;
        case 1700 : return 37697;
        case 1750 : return 33366;
        case 1800 : return 28359;
        case 1850 : return 34153;
        case 1875 : return 24547;
        case 1890 : return 33148;
    }
  }
    if (a==1950) {
      switch (b) {
        case 127 : return 7594;
        case 150 : return 7700;
        case 175 : return 3784;
        case 200 : return 12372;
        case 300 : return 12236;
        case 400 : return 12413;
        case 500 : return 18060;
        case 600 : return 14161;
        case 700 : return 21966;
        case 800 : return 18070;
        case 900 : return 25743;
        case 1000 : return 29396;
        case 1100 : return 21805;
        case 1200 : return 24654;
        case 1300 : return 33473;
        case 1400 : return 25583;
        case 1500 : return 32798;
        case 1600 : return 36993;
        case 1650 : return 27789;
        case 1700 : return 31810;
        case 1750 : return 35471;
        case 1800 : return 28726;
        case 1850 : return 22968;
        case 1900 : return 30670;
        case 1925 : return 32524;
        case 1940 : return 18200;
    }
  }
    if (a==2000) {
      switch (b) {
        case 127 : return 0;
        case 150 : return 2858;
        case 175 : return 6551;
        case 200 : return 5794;
        case 300 : return 3880;
        case 400 : return 4852;
        case 500 : return 10533;
        case 600 : return 8653;
        case 700 : return 8634;
        case 800 : return 8741;
        case 900 : return 14350;
        case 1000 : return 6665;
        case 1100 : return 10661;
        case 1200 : return 9696;
        case 1300 : return 20409;
        case 1400 : return 13443;
        case 1500 : return 10847;
        case 1600 : return 17619;
        case 1700 : return 16551;
        case 1750 : return 16306;
        case 1800 : return 16385;
        case 1850 : return 17427;
        case 1900 : return 22129;
        case 1950 : return 18240;
        case 1975 : return 23215;
        case 1990 : return 12562;
    }
  }
    if (a==2050) {
      switch (b) {
        case 127 : return 1946;
        case 150 : return 958;
        case 175 : return 2877;
        case 200 : return 6684;
        case 300 : return 4886;
        case 400 : return 10694;
        case 500 : return 7748;
        case 600 : return 3866;
        case 700 : return 10658;
        case 800 : return 4893;
        case 900 : return 8828;
        case 1000 : return 12745;
        case 1100 : return 10634;
        case 1200 : return 17593;
        case 1300 : return 12627;
        case 1400 : return 20394;
        case 1500 : return 9683;
        case 1600 : return 14723;
        case 1700 : return 25727;
        case 1750 : return 15609;
        case 1800 : return 17385;
        case 1850 : return 10806;
        case 1900 : return 10585;
        case 1950 : return 8625;
        case 2000 : return 12647;
        case 2025 : return 18572;
        case 2040 : return 19522;
    }
  }
    if (a==2100) {
      switch (b) {
        case 127 : return 1946;
        case 150 : return 1907;
        case 175 : return 7888;
        case 200 : return 3911;
        case 300 : return 6998;
        case 400 : return 9703;
        case 500 : return 2839;
        case 600 : return 4942;
        case 700 : return 5925;
        case 800 : return 6793;
        case 900 : return 15682;
        case 1000 : return 7876;
        case 1100 : return 6829;
        case 1200 : return 13745;
        case 1300 : return 17570;
        case 1400 : return 22810;
        case 1500 : return 17914;
        case 1600 : return 13758;
        case 1700 : return 16863;
        case 1800 : return 15893;
        case 1850 : return 11820;
        case 1900 : return 10907;
        case 1950 : return 12731;
        case 2000 : return 15808;
        case 2050 : return 8856;
        case 2075 : return 15891;
        case 2090 : return 23023;
    }
  }
    if (a==2150) {
      switch (b) {
        case 127 : return 6048;
        case 150 : return 2944;
        case 175 : return 1957;
        case 200 : return 4020;
        case 300 : return 7875;
        case 400 : return 9882;
        case 500 : return 4957;
        case 600 : return 9917;
        case 700 : return 5036;
        case 800 : return 11047;
        case 900 : return 8093;
        case 1000 : return 8177;
        case 1100 : return 14971;
        case 1200 : return 10937;
        case 1300 : return 6990;
        case 1400 : return 11014;
        case 1500 : return 8970;
        case 1600 : return 8035;
        case 1700 : return 14975;
        case 1800 : return 13889;
        case 1850 : return 14879;
        case 1900 : return 14856;
        case 1950 : return 24857;
        case 2000 : return 14950;
        case 2050 : return 18025;
        case 2100 : return 14968;
        case 2125 : return 17883;
        case 2140 : return 10928;
    }
  }
    if (a==2200) {
      switch (b) {
        case 127 : return 1056;
        case 150 : return 1998;
        case 175 : return 2032;
        case 200 : return 6100;
        case 300 : return 9993;
        case 400 : return 12000;
        case 500 : return 11084;
        case 600 : return 10147;
        case 700 : return 9154;
        case 800 : return 12036;
        case 900 : return 9029;
        case 1000 : return 11205;
        case 1100 : return 15213;
        case 1200 : return 7034;
        case 1300 : return 13233;
        case 1400 : return 16055;
        case 1500 : return 11096;
        case 1600 : return 15331;
        case 1700 : return 12232;
        case 1800 : return 21357;
        case 1900 : return 15250;
        case 1950 : return 14280;
        case 2000 : return 27107;
        case 2050 : return 21289;
        case 2100 : return 20172;
        case 2150 : return 16243;
        case 2175 : return 16169;
        case 2190 : return 15102;
    }
  }
    if (a==2250) {
      switch (b) {
        case 127 : return 2065;
        case 150 : return 5112;
        case 175 : return 3047;
        case 200 : return 4049;
        case 300 : return 7211;
        case 400 : return 6170;
        case 500 : return 4119;
        case 600 : return 5079;
        case 700 : return 8245;
        case 800 : return 11276;
        case 900 : return 11339;
        case 1000 : return 8289;
        case 1100 : return 8334;
        case 1200 : return 16556;
        case 1300 : return 14314;
        case 1400 : return 14346;
        case 1500 : return 13303;
        case 1600 : return 11357;
        case 1700 : return 15174;
        case 1800 : return 11136;
        case 1900 : return 20643;
        case 1950 : return 22421;
        case 2000 : return 15320;
        case 2050 : return 14461;
        case 2100 : return 17436;
        case 2150 : return 15221;
        case 2200 : return 19419;
        case 2225 : return 15498;
        case 2240 : return 22428;
    }
  }
    if (a==2300) {
      switch (b) {
        case 127 : return 4194;
        case 150 : return 5197;
        case 175 : return 6089;
        case 200 : return 6165;
        case 300 : return 4092;
        case 400 : return 7248;
        case 500 : return 4212;
        case 600 : return 7258;
        case 700 : return 5219;
        case 800 : return 8230;
        case 900 : return 12566;
        case 1000 : return 10564;
        case 1100 : return 15749;
        case 1200 : return 10285;
        case 1300 : return 11508;
        case 1400 : return 13574;
        case 1500 : return 16615;
        case 1600 : return 11600;
        case 1700 : return 19910;
        case 1800 : return 12499;
        case 1900 : return 15553;
        case 2000 : return 12416;
        case 2050 : return 17704;
        case 2100 : return 22877;
        case 2150 : return 15546;
        case 2200 : return 20934;
        case 2250 : return 25011;
        case 2275 : return 17866;
        case 2290 : return 26033;
    }
  }
    if (a==2350) {
      switch (b) {
        case 127 : return 3127;
        case 150 : return 4173;
        case 175 : return 6435;
        case 200 : return 6336;
        case 300 : return 5163;
        case 400 : return 3211;
        case 500 : return 3133;
        case 600 : return 5244;
        case 700 : return 6350;
        case 800 : return 9473;
        case 900 : return 6344;
        case 1000 : return 13605;
        case 1100 : return 15053;
        case 1200 : return 15702;
        case 1300 : return 12672;
        case 1400 : return 10721;
        case 1500 : return 17001;
        case 1600 : return 14869;
        case 1700 : return 8461;
        case 1800 : return 20005;
        case 1900 : return 17017;
        case 2000 : return 24085;
        case 2050 : return 17810;
        case 2100 : return 14742;
        case 2150 : return 11697;
        case 2200 : return 21251;
        case 2250 : return 20138;
        case 2300 : return 18972;
        case 2325 : return 14661;
        case 2340 : return 13821;
    }
  }
    if (a==2400) {
      switch (b) {
        case 127 : return 3240;
        case 150 : return 1090;
        case 175 : return 3205;
        case 200 : return 2148;
        case 300 : return 3234;
        case 400 : return 5346;
        case 500 : return 2101;
        case 600 : return 6385;
        case 700 : return 9570;
        case 800 : return 11789;
        case 900 : return 7656;
        case 1000 : return 8595;
        case 1100 : return 10685;
        case 1200 : return 18262;
        case 1300 : return 17156;
        case 1400 : return 12817;
        case 1500 : return 12878;
        case 1600 : return 16020;
        case 1700 : return 9757;
        case 1800 : return 12866;
        case 1900 : return 15047;
        case 2000 : return 11854;
        case 2100 : return 10766;
        case 2150 : return 14956;
        case 2200 : return 14956;
        case 2250 : return 16088;
        case 2300 : return 18302;
        case 2350 : return 18299;
        case 2375 : return 17213;
        case 2390 : return 11712;
    }
  }
    if (a==2450) {
      switch (b) {
        case 127 : return 4369;
        case 150 : return 3254;
        case 175 : return 4307;
        case 200 : return 5402;
        case 300 : return 1104;
        case 400 : return 4314;
        case 500 : return 4411;
        case 600 : return 8750;
        case 700 : return 9765;
        case 800 : return 11760;
        case 900 : return 8746;
        case 1000 : return 8783;
        case 1100 : return 7685;
        case 1200 : return 9875;
        case 1300 : return 19674;
        case 1400 : return 12095;
        case 1500 : return 21675;
        case 1600 : return 8757;
        case 1700 : return 12144;
        case 1800 : return 15252;
        case 1900 : return 14237;
        case 2000 : return 17261;
        case 2100 : return 18581;
        case 2150 : return 19622;
        case 2200 : return 16334;
        case 2250 : return 16348;
        case 2300 : return 12980;
        case 2350 : return 17361;
        case 2400 : return 14121;
        case 2425 : return 12137;
        case 2440 : return 6491;
    }
  }
    if (a==2500) {
      switch (b) {
        case 127 : return 2225;
        case 150 : return 1071;
        case 175 : return 7715;
        case 200 : return 7791;
        case 300 : return 4424;
        case 400 : return 3211;
        case 500 : return 10925;
        case 600 : return 7736;
        case 700 : return 11079;
        case 800 : return 6547;
        case 900 : return 7793;
        case 1000 : return 10014;
        case 1100 : return 12115;
        case 1200 : return 19963;
        case 1300 : return 8865;
        case 1400 : return 13339;
        case 1500 : return 17717;
        case 1600 : return 16774;
        case 1700 : return 12177;
        case 1800 : return 16610;
        case 1900 : return 12223;
        case 2000 : return 20999;
        case 2100 : return 12366;
        case 2200 : return 9846;
        case 2250 : return 19922;
        case 2300 : return 16605;
        case 2350 : return 16754;
        case 2400 : return 13298;
        case 2450 : return 15432;
        case 2475 : return 17685;
        case 2490 : return 11007;
    }
  }
    if (a==2550) {
      switch (b) {
        case 127 : return 4471;
        case 150 : return 5663;
        case 175 : return 7827;
        case 200 : return 2211;
        case 300 : return 4377;
        case 400 : return 4559;
        case 500 : return 6724;
        case 600 : return 7889;
        case 700 : return 8900;
        case 800 : return 11216;
        case 900 : return 14718;
        case 1000 : return 7850;
        case 1100 : return 6782;
        case 1200 : return 13394;
        case 1300 : return 13469;
        case 1400 : return 10114;
        case 1500 : return 13476;
        case 1600 : return 13454;
        case 1700 : return 14685;
        case 1800 : return 13538;
        case 1900 : return 14696;
        case 2000 : return 18224;
        case 2100 : return 10120;
        case 2200 : return 13438;
        case 2250 : return 15899;
        case 2300 : return 20412;
        case 2350 : return 15741;
        case 2400 : return 27969;
        case 2450 : return 19222;
        case 2500 : return 21377;
        case 2525 : return 17139;
        case 2540 : return 18873;
    }
  }
    if (a==2600) {
      switch (b) {
        case 127 : return 2336;
        case 150 : return 4588;
        case 175 : return 4542;
        case 200 : return 6657;
        case 300 : return 6814;
        case 400 : return 8100;
        case 500 : return 13657;
        case 600 : return 6673;
        case 700 : return 7937;
        case 800 : return 8023;
        case 900 : return 13616;
        case 1000 : return 9269;
        case 1100 : return 9211;
        case 1200 : return 22907;
        case 1300 : return 9098;
        case 1400 : return 16023;
        case 1500 : return 20496;
        case 1600 : return 14813;
        case 1700 : return 13639;
        case 1800 : return 12643;
        case 1900 : return 11435;
        case 2000 : return 19444;
        case 2100 : return 12702;
        case 2200 : return 21730;
        case 2300 : return 14800;
        case 2350 : return 13796;
        case 2400 : return 9249;
        case 2450 : return 19369;
        case 2500 : return 11527;
        case 2550 : return 16011;
        case 2575 : return 14801;
        case 2590 : return 11417;
    }
  }
    if (a==2650) {
      switch (b) {
        case 127 : return 4672;
        case 150 : return 2286;
        case 175 : return 4685;
        case 200 : return 5846;
        case 300 : return 1181;
        case 400 : return 1212;
        case 500 : return 1140;
        case 600 : return 2331;
        case 700 : return 8109;
        case 800 : return 11692;
        case 900 : return 9367;
        case 1000 : return 15429;
        case 1100 : return 11708;
        case 1200 : return 7029;
        case 1300 : return 5733;
        case 1400 : return 19649;
        case 1500 : return 10368;
        case 1600 : return 11567;
        case 1700 : return 10523;
        case 1800 : return 6913;
        case 1900 : return 14044;
        case 2000 : return 15042;
        case 2100 : return 17546;
        case 2200 : return 11620;
        case 2300 : return 16368;
        case 2350 : return 12772;
        case 2400 : return 11572;
        case 2450 : return 11627;
        case 2500 : return 9289;
        case 2550 : return 13805;
        case 2600 : return 15156;
        case 2625 : return 19757;
        case 2640 : return 17360;
    }
  }
    if (a==2700) {
      switch (b) {
        case 127 : return 1168;
        case 150 : return 0;
        case 175 : return 1202;
        case 200 : return 2394;
        case 300 : return 7048;
        case 400 : return 7117;
        case 500 : return 3548;
        case 600 : return 5881;
        case 700 : return 5907;
        case 800 : return 12985;
        case 900 : return 4720;
        case 1000 : return 7041;
        case 1100 : return 10747;
        case 1200 : return 13020;
        case 1300 : return 12992;
        case 1400 : return 15397;
        case 1500 : return 13172;
        case 1600 : return 16604;
        case 1700 : return 19964;
        case 1800 : return 16723;
        case 1900 : return 26169;
        case 2000 : return 11875;
        case 2100 : return 14321;
        case 2200 : return 22425;
        case 2300 : return 18806;
        case 2400 : return 16637;
        case 2450 : return 15612;
        case 2500 : return 16607;
        case 2550 : return 17754;
        case 2600 : return 17639;
        case 2650 : return 14099;
        case 2675 : return 14240;
        case 2690 : return 15461;
    }
  }
    if (a==2750) {
      switch (b) {
        case 127 : return 3619;
        case 150 : return 2380;
        case 175 : return 5957;
        case 200 : return 8263;
        case 300 : return 7121;
        case 400 : return 12041;
        case 500 : return 4838;
        case 600 : return 7212;
        case 700 : return 8505;
        case 800 : return 9593;
        case 900 : return 6027;
        case 1000 : return 14538;
        case 1100 : return 13176;
        case 1200 : return 14305;
        case 1300 : return 8522;
        case 1400 : return 10818;
        case 1500 : return 10928;
        case 1600 : return 10953;
        case 1700 : return 9609;
        case 1800 : return 10755;
        case 1900 : return 11942;
        case 2000 : return 13333;
        case 2100 : return 18184;
        case 2200 : return 18121;
        case 2300 : return 21581;
        case 2400 : return 14341;
        case 2450 : return 14597;
        case 2500 : return 10725;
        case 2550 : return 14215;
        case 2600 : return 21686;
        case 2650 : return 15874;
        case 2700 : return 15689;
        case 2725 : return 27704;
        case 2740 : return 14421;
    }
  }
    if (a==2800) {
      switch (b) {
        case 127 : return 3616;
        case 150 : return 0;
        case 175 : return 3693;
        case 200 : return 4922;
        case 300 : return 6081;
        case 400 : return 4905;
        case 500 : return 4973;
        case 600 : return 6064;
        case 700 : return 6151;
        case 800 : return 14739;
        case 900 : return 7348;
        case 1000 : return 8507;
        case 1100 : return 13445;
        case 1200 : return 12289;
        case 1300 : return 21111;
        case 1400 : return 20782;
        case 1500 : return 10984;
        case 1600 : return 15807;
        case 1700 : return 11099;
        case 1800 : return 17079;
        case 1900 : return 12206;
        case 2000 : return 11042;
        case 2100 : return 20873;
        case 2200 : return 14802;
        case 2300 : return 19674;
        case 2400 : return 13565;
        case 2500 : return 15921;
        case 2550 : return 15830;
        case 2600 : return 17186;
        case 2650 : return 19543;
        case 2700 : return 18277;
        case 2750 : return 9800;
        case 2775 : return 13369;
        case 2790 : return 21980;
    }
  }
      case 3018 :
    if (a==800) {
      switch (b) {
        case 127 : return 104279;
        case 200 : return 136205;
        case 300 : return 150754;
        case 400 : return 147408;
        case 500 : return 161526;
        case 600 : return 155574;
        case 700 : return 165126;
        case 790 : return 163700;
    }
  }
    if (a==900) {
      switch (b) {
        case 127 : return 88260;
        case 200 : return 126597;
        case 300 : return 132887;
        case 400 : return 154347;
        case 500 : return 128370;
        case 600 : return 167114;
        case 700 : return 178289;
        case 800 : return 175667;
        case 890 : return 166302;
    }
  }
    if (a==1000) {
      switch (b) {
        case 127 : return 92239;
        case 150 : return 121389;
        case 175 : return 117104;
        case 200 : return 116203;
        case 300 : return 130029;
        case 400 : return 124373;
        case 500 : return 159925;
        case 600 : return 141838;
        case 700 : return 149643;
        case 750 : return 150786;
        case 800 : return 178023;
        case 850 : return 176512;
        case 900 : return 169113;
        case 950 : return 195305;
        case 975 : return 184730;
        case 990 : return 179452;
    }
  }
    if (a==1050) {
      switch (b) {
        case 127 : return 75681;
        case 150 : return 94110;
        case 175 : return 108155;
        case 200 : return 112409;
        case 300 : return 131093;
        case 400 : return 118874;
        case 500 : return 149346;
        case 600 : return 183016;
        case 700 : return 173702;
        case 750 : return 166762;
        case 800 : return 175289;
        case 850 : return 138872;
        case 900 : return 179342;
        case 950 : return 166937;
        case 1000 : return 163981;
        case 1025 : return 182619;
        case 1040 : return 213925;
    }
  }
    if (a==1100) {
      switch (b) {
        case 127 : return 79960;
        case 150 : return 86291;
        case 175 : return 102308;
        case 200 : return 99986;
        case 300 : return 121556;
        case 400 : return 108766;
        case 500 : return 145622;
        case 600 : return 127702;
        case 700 : return 161559;
        case 800 : return 145396;
        case 850 : return 146799;
        case 900 : return 160822;
        case 950 : return 160488;
        case 1000 : return 179343;
        case 1050 : return 154937;
        case 1075 : return 168387;
        case 1090 : return 167152;
    }
  }
    if (a==1150) {
      switch (b) {
        case 127 : return 57441;
        case 150 : return 66833;
        case 175 : return 74635;
        case 200 : return 91431;
        case 300 : return 88246;
        case 400 : return 90234;
        case 500 : return 88139;
        case 600 : return 120367;
        case 700 : return 105318;
        case 800 : return 107699;
        case 850 : return 113912;
        case 900 : return 128961;
        case 950 : return 115618;
        case 1000 : return 129753;
        case 1050 : return 117736;
        case 1100 : return 125464;
        case 1125 : return 140532;
        case 1140 : return 139515;
    }
  }
    if (a==1200) {
      switch (b) {
        case 127 : return 45666;
        case 150 : return 52153;
        case 175 : return 43834;
        case 200 : return 41916;
        case 300 : return 51147;
        case 400 : return 64613;
        case 500 : return 71182;
        case 600 : return 64549;
        case 700 : return 78664;
        case 800 : return 83903;
        case 900 : return 89087;
        case 950 : return 60110;
        case 1000 : return 83907;
        case 1050 : return 70127;
        case 1100 : return 85567;
        case 1150 : return 88284;
        case 1175 : return 103692;
        case 1190 : return 78063;
    }
  }
    if (a==1250) {
      switch (b) {
        case 127 : return 27491;
        case 150 : return 40089;
        case 175 : return 23766;
        case 200 : return 26574;
        case 300 : return 41979;
        case 400 : return 44829;
        case 500 : return 44055;
        case 600 : return 64315;
        case 700 : return 57769;
        case 800 : return 49335;
        case 900 : return 73880;
        case 950 : return 58637;
        case 1000 : return 53664;
        case 1050 : return 57933;
        case 1100 : return 69911;
        case 1150 : return 64999;
        case 1200 : return 54057;
        case 1225 : return 72459;
        case 1240 : return 75129;
    }
  }
    if (a==1300) {
      switch (b) {
        case 127 : return 18283;
        case 150 : return 26672;
        case 175 : return 25687;
        case 200 : return 31065;
        case 300 : return 37376;
        case 400 : return 40112;
        case 500 : return 39624;
        case 600 : return 37519;
        case 700 : return 36671;
        case 800 : return 43103;
        case 900 : return 56735;
        case 1000 : return 59580;
        case 1050 : return 41472;
        case 1100 : return 52348;
        case 1150 : return 69657;
        case 1200 : return 50855;
        case 1250 : return 53902;
        case 1275 : return 58476;
        case 1290 : return 60496;
    }
  }
    if (a==1350) {
      switch (b) {
        case 127 : return 25723;
        case 150 : return 32077;
        case 175 : return 26597;
        case 200 : return 25760;
        case 300 : return 35922;
        case 400 : return 36706;
        case 500 : return 34382;
        case 600 : return 40746;
        case 700 : return 47850;
        case 800 : return 40559;
        case 900 : return 49304;
        case 1000 : return 62497;
        case 1050 : return 40562;
        case 1100 : return 41411;
        case 1150 : return 54240;
        case 1200 : return 57155;
        case 1250 : return 62992;
        case 1300 : return 44272;
        case 1325 : return 61380;
        case 1340 : return 56246;
    }
  }
    if (a==1400) {
      switch (b) {
        case 127 : return 26914;
        case 150 : return 27822;
        case 175 : return 24918;
        case 200 : return 22859;
        case 300 : return 34862;
        case 400 : return 33277;
        case 500 : return 36023;
        case 600 : return 22015;
        case 700 : return 40744;
        case 800 : return 36937;
        case 900 : return 39588;
        case 1000 : return 61989;
        case 1100 : return 41558;
        case 1150 : return 47086;
        case 1200 : return 59052;
        case 1250 : return 66998;
        case 1300 : return 55613;
        case 1350 : return 53503;
        case 1375 : return 66467;
        case 1390 : return 56332;
    }
  }
    if (a==1450) {
      switch (b) {
        case 127 : return 29647;
        case 150 : return 25102;
        case 175 : return 29786;
        case 200 : return 24948;
        case 300 : return 29659;
        case 400 : return 35997;
        case 500 : return 46200;
        case 600 : return 36121;
        case 700 : return 42416;
        case 800 : return 39728;
        case 900 : return 38042;
        case 1000 : return 46462;
        case 1100 : return 46290;
        case 1150 : return 48058;
        case 1200 : return 65652;
        case 1250 : return 41823;
        case 1300 : return 56046;
        case 1350 : return 50245;
        case 1400 : return 55804;
        case 1425 : return 54619;
        case 1440 : return 57322;
    }
  }
    if (a==1500) {
      switch (b) {
        case 127 : return 21447;
        case 150 : return 31833;
        case 175 : return 24310;
        case 200 : return 29741;
        case 300 : return 26345;
        case 400 : return 35393;
        case 500 : return 45925;
        case 600 : return 38383;
        case 700 : return 31752;
        case 800 : return 36224;
        case 900 : return 48436;
        case 1000 : return 48202;
        case 1100 : return 54865;
        case 1200 : return 50526;
        case 1250 : return 49619;
        case 1300 : return 48357;
        case 1350 : return 59475;
        case 1400 : return 43051;
        case 1450 : return 56735;
        case 1475 : return 62551;
        case 1490 : return 69122;
    }
  }
    if (a==1550) {
      switch (b) {
        case 127 : return 25395;
        case 150 : return 20553;
        case 175 : return 27947;
        case 200 : return 19503;
        case 300 : return 28142;
        case 400 : return 35838;
        case 500 : return 30000;
        case 600 : return 39097;
        case 700 : return 31782;
        case 800 : return 49048;
        case 900 : return 51313;
        case 1000 : return 41070;
        case 1100 : return 65814;
        case 1200 : return 57056;
        case 1250 : return 48804;
        case 1300 : return 48786;
        case 1350 : return 57125;
        case 1400 : return 50522;
        case 1450 : return 44792;
        case 1500 : return 51569;
        case 1525 : return 46630;
        case 1540 : return 53236;
    }
  }
    if (a==1600) {
      switch (b) {
        case 127 : return 27306;
        case 150 : return 36813;
        case 175 : return 40527;
        case 200 : return 31953;
        case 300 : return 37727;
        case 400 : return 29254;
        case 500 : return 35626;
        case 600 : return 35699;
        case 700 : return 33779;
        case 800 : return 49837;
        case 900 : return 49974;
        case 1000 : return 46046;
        case 1100 : return 60376;
        case 1200 : return 45990;
        case 1300 : return 47968;
        case 1350 : return 58560;
        case 1400 : return 43168;
        case 1450 : return 43465;
        case 1500 : return 53795;
        case 1550 : return 50850;
        case 1575 : return 67795;
        case 1590 : return 57387;
    }
  }
    if (a==1650) {
      switch (b) {
        case 127 : return 25677;
        case 150 : return 28361;
        case 175 : return 32157;
        case 200 : return 21572;
        case 300 : return 25626;
        case 400 : return 30504;
        case 500 : return 40822;
        case 600 : return 35117;
        case 700 : return 39766;
        case 800 : return 39723;
        case 900 : return 57649;
        case 1000 : return 52022;
        case 1100 : return 59081;
        case 1200 : return 65501;
        case 1300 : return 47504;
        case 1350 : return 52216;
        case 1400 : return 57302;
        case 1450 : return 46575;
        case 1500 : return 52365;
        case 1550 : return 59104;
        case 1600 : return 52959;
        case 1625 : return 48504;
        case 1640 : return 50999;
    }
  }
    if (a==1700) {
      switch (b) {
        case 127 : return 22036;
        case 150 : return 25715;
        case 175 : return 31502;
        case 200 : return 49310;
        case 300 : return 22789;
        case 400 : return 37194;
        case 500 : return 37876;
        case 600 : return 37110;
        case 700 : return 41997;
        case 800 : return 49621;
        case 900 : return 38039;
        case 1000 : return 54400;
        case 1100 : return 44843;
        case 1200 : return 50620;
        case 1300 : return 52302;
        case 1400 : return 62106;
        case 1450 : return 62732;
        case 1500 : return 61583;
        case 1550 : return 59158;
        case 1600 : return 54029;
        case 1650 : return 54120;
        case 1675 : return 52202;
        case 1690 : return 56910;
    }
  }
    if (a==1750) {
      switch (b) {
        case 127 : return 20462;
        case 150 : return 25085;
        case 175 : return 31740;
        case 200 : return 24789;
        case 300 : return 25775;
        case 400 : return 22011;
        case 500 : return 42559;
        case 600 : return 42125;
        case 700 : return 37181;
        case 800 : return 40236;
        case 900 : return 33682;
        case 1000 : return 55649;
        case 1100 : return 32562;
        case 1200 : return 50727;
        case 1300 : return 45399;
        case 1400 : return 47012;
        case 1450 : return 58409;
        case 1500 : return 56964;
        case 1550 : return 50926;
        case 1600 : return 51576;
        case 1650 : return 48051;
        case 1700 : return 56761;
        case 1725 : return 59677;
        case 1740 : return 55850;
    }
  }
    if (a==1800) {
      switch (b) {
        case 127 : return 24456;
        case 150 : return 26026;
        case 175 : return 26241;
        case 200 : return 26070;
        case 300 : return 30966;
        case 400 : return 32163;
        case 500 : return 28182;
        case 600 : return 36841;
        case 700 : return 44675;
        case 800 : return 37675;
        case 900 : return 47487;
        case 1000 : return 45675;
        case 1100 : return 47574;
        case 1200 : return 44890;
        case 1300 : return 51393;
        case 1400 : return 38013;
        case 1500 : return 54662;
        case 1550 : return 52431;
        case 1600 : return 42666;
        case 1650 : return 51458;
        case 1700 : return 43818;
        case 1750 : return 52351;
        case 1775 : return 46612;
        case 1790 : return 55111;
    }
  }
    if (a==1850) {
      switch (b) {
        case 127 : return 21471;
        case 150 : return 17652;
        case 175 : return 28368;
        case 200 : return 31049;
        case 300 : return 24369;
        case 400 : return 36092;
        case 500 : return 32004;
        case 600 : return 35111;
        case 700 : return 38182;
        case 800 : return 44233;
        case 900 : return 36266;
        case 1000 : return 48908;
        case 1100 : return 47267;
        case 1200 : return 42078;
        case 1300 : return 37140;
        case 1400 : return 49048;
        case 1500 : return 41113;
        case 1550 : return 52978;
        case 1600 : return 65926;
        case 1650 : return 41219;
        case 1700 : return 56737;
        case 1750 : return 47957;
        case 1800 : return 47945;
        case 1825 : return 51077;
        case 1840 : return 57907;
    }
  }
    if (a==1900) {
      switch (b) {
        case 127 : return 23841;
        case 150 : return 22619;
        case 175 : return 32544;
        case 200 : return 30635;
        case 300 : return 19805;
        case 400 : return 25833;
        case 500 : return 41470;
        case 600 : return 42618;
        case 700 : return 41356;
        case 800 : return 37534;
        case 900 : return 34866;
        case 1000 : return 50355;
        case 1100 : return 49826;
        case 1200 : return 50628;
        case 1300 : return 46613;
        case 1400 : return 38450;
        case 1500 : return 57126;
        case 1600 : return 51276;
        case 1650 : return 45631;
        case 1700 : return 46490;
        case 1750 : return 55399;
        case 1800 : return 48327;
        case 1850 : return 56222;
        case 1875 : return 62897;
        case 1890 : return 39632;
    }
  }
    if (a==1950) {
      switch (b) {
        case 127 : return 25993;
        case 150 : return 17788;
        case 175 : return 22863;
        case 200 : return 24950;
        case 300 : return 30910;
        case 400 : return 31812;
        case 500 : return 44154;
        case 600 : return 39601;
        case 700 : return 36819;
        case 800 : return 51594;
        case 900 : return 35292;
        case 1000 : return 50341;
        case 1100 : return 47123;
        case 1200 : return 55115;
        case 1300 : return 43978;
        case 1400 : return 61826;
        case 1500 : return 43180;
        case 1600 : return 43964;
        case 1650 : return 56695;
        case 1700 : return 56920;
        case 1750 : return 67129;
        case 1800 : return 52750;
        case 1850 : return 57846;
        case 1900 : return 55249;
        case 1925 : return 48833;
        case 1940 : return 38831;
    }
  }
    if (a==2000) {
      switch (b) {
        case 127 : return 13223;
        case 150 : return 7010;
        case 175 : return 17232;
        case 200 : return 12947;
        case 300 : return 12149;
        case 400 : return 8997;
        case 500 : return 23164;
        case 600 : return 14186;
        case 700 : return 20099;
        case 800 : return 23191;
        case 900 : return 26316;
        case 1000 : return 22247;
        case 1100 : return 21208;
        case 1200 : return 23682;
        case 1300 : return 20146;
        case 1400 : return 21206;
        case 1500 : return 20051;
        case 1600 : return 26218;
        case 1700 : return 18153;
        case 1750 : return 21173;
        case 1800 : return 29077;
        case 1850 : return 16199;
        case 1900 : return 30382;
        case 1950 : return 23349;
        case 1975 : return 28158;
        case 1990 : return 28314;
    }
  }
    if (a==2050) {
      switch (b) {
        case 127 : return 8053;
        case 150 : return 12047;
        case 175 : return 9137;
        case 200 : return 11110;
        case 300 : return 13274;
        case 400 : return 16420;
        case 500 : return 11205;
        case 600 : return 22337;
        case 700 : return 14428;
        case 800 : return 28513;
        case 900 : return 21396;
        case 1000 : return 31378;
        case 1100 : return 21332;
        case 1200 : return 21443;
        case 1300 : return 20454;
        case 1400 : return 22369;
        case 1500 : return 27681;
        case 1600 : return 28656;
        case 1700 : return 30867;
        case 1750 : return 30659;
        case 1800 : return 28485;
        case 1850 : return 36318;
        case 1900 : return 15426;
        case 1950 : return 34627;
        case 2000 : return 33375;
        case 2025 : return 19469;
        case 2040 : return 32415;
    }
  }
    if (a==2100) {
      switch (b) {
        case 127 : return 11547;
        case 150 : return 12367;
        case 175 : return 12416;
        case 200 : return 21676;
        case 300 : return 14418;
        case 400 : return 17440;
        case 500 : return 18486;
        case 600 : return 22600;
        case 700 : return 14494;
        case 800 : return 17663;
        case 900 : return 22844;
        case 1000 : return 19627;
        case 1100 : return 18699;
        case 1200 : return 28104;
        case 1300 : return 22781;
        case 1400 : return 19649;
        case 1500 : return 33013;
        case 1600 : return 33166;
        case 1700 : return 18475;
        case 1800 : return 29912;
        case 1850 : return 29953;
        case 1900 : return 25678;
        case 1950 : return 18792;
        case 2000 : return 18627;
        case 2050 : return 24965;
        case 2075 : return 20489;
        case 2090 : return 18565;
    }
  }
    if (a==2150) {
      switch (b) {
        case 127 : return 11541;
        case 150 : return 16814;
        case 175 : return 13610;
        case 200 : return 18708;
        case 300 : return 19890;
        case 400 : return 16747;
        case 500 : return 21921;
        case 600 : return 15555;
        case 700 : return 16610;
        case 800 : return 19659;
        case 900 : return 28118;
        case 1000 : return 20882;
        case 1100 : return 21675;
        case 1200 : return 30271;
        case 1300 : return 29090;
        case 1400 : return 17652;
        case 1500 : return 15851;
        case 1600 : return 29158;
        case 1700 : return 25991;
        case 1800 : return 27155;
        case 1850 : return 16644;
        case 1900 : return 18765;
        case 1950 : return 21000;
        case 2000 : return 26030;
        case 2050 : return 23122;
        case 2100 : return 21983;
        case 2125 : return 26001;
        case 2140 : return 24743;
    }
  }
    if (a==2200) {
      switch (b) {
        case 127 : return 14823;
        case 150 : return 7375;
        case 175 : return 12726;
        case 200 : return 7463;
        case 300 : return 13804;
        case 400 : return 15764;
        case 500 : return 23028;
        case 600 : return 14604;
        case 700 : return 19131;
        case 800 : return 20211;
        case 900 : return 19047;
        case 1000 : return 20054;
        case 1100 : return 21094;
        case 1200 : return 24458;
        case 1300 : return 16855;
        case 1400 : return 21063;
        case 1500 : return 24318;
        case 1600 : return 15751;
        case 1700 : return 25374;
        case 1800 : return 18014;
        case 1900 : return 35949;
        case 1950 : return 16819;
        case 2000 : return 24388;
        case 2050 : return 22062;
        case 2100 : return 31818;
        case 2150 : return 21218;
        case 2175 : return 22166;
        case 2190 : return 25354;
    }
  }
    if (a==2250) {
      switch (b) {
        case 127 : return 10759;
        case 150 : return 7547;
        case 175 : return 7613;
        case 200 : return 10748;
        case 300 : return 12939;
        case 400 : return 17239;
        case 500 : return 15179;
        case 600 : return 12853;
        case 700 : return 16072;
        case 800 : return 13905;
        case 900 : return 24602;
        case 1000 : return 20075;
        case 1100 : return 29126;
        case 1200 : return 29030;
        case 1300 : return 17104;
        case 1400 : return 19441;
        case 1500 : return 19259;
        case 1600 : return 22550;
        case 1700 : return 24567;
        case 1800 : return 31125;
        case 1900 : return 29947;
        case 1950 : return 21445;
        case 2000 : return 22653;
        case 2050 : return 23690;
        case 2100 : return 31141;
        case 2150 : return 24586;
        case 2200 : return 27989;
        case 2225 : return 21598;
        case 2240 : return 25562;
    }
  }
    if (a==2300) {
      switch (b) {
        case 127 : return 13152;
        case 150 : return 7564;
        case 175 : return 9766;
        case 200 : return 16293;
        case 300 : return 15159;
        case 400 : return 17114;
        case 500 : return 18533;
        case 600 : return 18459;
        case 700 : return 15153;
        case 800 : return 15140;
        case 900 : return 20502;
        case 1000 : return 15230;
        case 1100 : return 31683;
        case 1200 : return 26083;
        case 1300 : return 21914;
        case 1400 : return 30435;
        case 1500 : return 28417;
        case 1600 : return 32767;
        case 1700 : return 28271;
        case 1800 : return 31597;
        case 1900 : return 22788;
        case 2000 : return 28332;
        case 2050 : return 24956;
        case 2100 : return 23882;
        case 2150 : return 31462;
        case 2200 : return 24186;
        case 2250 : return 22962;
        case 2275 : return 35822;
        case 2290 : return 26006;
    }
  }
    if (a==2350) {
      switch (b) {
        case 127 : return 11034;
        case 150 : return 14358;
        case 175 : return 6573;
        case 200 : return 23181;
        case 300 : return 18777;
        case 400 : return 15370;
        case 500 : return 15410;
        case 600 : return 14386;
        case 700 : return 19589;
        case 800 : return 24270;
        case 900 : return 13333;
        case 1000 : return 16596;
        case 1100 : return 26321;
        case 1200 : return 17605;
        case 1300 : return 25479;
        case 1400 : return 30051;
        case 1500 : return 22204;
        case 1600 : return 14217;
        case 1700 : return 37739;
        case 1800 : return 16450;
        case 1900 : return 29509;
        case 2000 : return 24361;
        case 2050 : return 20991;
        case 2100 : return 14549;
        case 2150 : return 22171;
        case 2200 : return 17843;
        case 2250 : return 28844;
        case 2300 : return 30966;
        case 2325 : return 23123;
        case 2340 : return 16407;
    }
  }
    if (a==2400) {
      switch (b) {
        case 127 : return 14664;
        case 150 : return 10118;
        case 175 : return 10143;
        case 200 : return 13409;
        case 300 : return 4477;
        case 400 : return 8907;
        case 500 : return 15685;
        case 600 : return 14656;
        case 700 : return 15655;
        case 800 : return 10064;
        case 900 : return 21394;
        case 1000 : return 24919;
        case 1100 : return 18072;
        case 1200 : return 16826;
        case 1300 : return 20192;
        case 1400 : return 28025;
        case 1500 : return 30350;
        case 1600 : return 22377;
        case 1700 : return 40251;
        case 1800 : return 23491;
        case 1900 : return 28979;
        case 2000 : return 21245;
        case 2100 : return 24658;
        case 2150 : return 22383;
        case 2200 : return 22409;
        case 2250 : return 21279;
        case 2300 : return 22394;
        case 2350 : return 20133;
        case 2375 : return 19171;
        case 2390 : return 23649;
    }
  }
    if (a==2450) {
      switch (b) {
        case 127 : return 9239;
        case 150 : return 6865;
        case 175 : return 12625;
        case 200 : return 18349;
        case 300 : return 13732;
        case 400 : return 6798;
        case 500 : return 20450;
        case 600 : return 12544;
        case 700 : return 17169;
        case 800 : return 28307;
        case 900 : return 27659;
        case 1000 : return 28505;
        case 1100 : return 34174;
        case 1200 : return 29757;
        case 1300 : return 27500;
        case 1400 : return 19293;
        case 1500 : return 24038;
        case 1600 : return 20663;
        case 1700 : return 26076;
        case 1800 : return 14792;
        case 1900 : return 21694;
        case 2000 : return 25262;
        case 2100 : return 20465;
        case 2150 : return 12660;
        case 2200 : return 23861;
        case 2250 : return 18377;
        case 2300 : return 21719;
        case 2350 : return 20536;
        case 2400 : return 21800;
        case 2425 : return 17065;
        case 2440 : return 20487;
    }
  }
    if (a==2500) {
      switch (b) {
        case 127 : return 9238;
        case 150 : return 11545;
        case 175 : return 16136;
        case 200 : return 10409;
        case 300 : return 14958;
        case 400 : return 9323;
        case 500 : return 20933;
        case 600 : return 24399;
        case 700 : return 28932;
        case 800 : return 23060;
        case 900 : return 17366;
        case 1000 : return 19685;
        case 1100 : return 19628;
        case 1200 : return 14223;
        case 1300 : return 18414;
        case 1400 : return 33464;
        case 1500 : return 26537;
        case 1600 : return 29000;
        case 1700 : return 24317;
        case 1800 : return 17306;
        case 1900 : return 23296;
        case 2000 : return 26787;
        case 2100 : return 34958;
        case 2200 : return 19724;
        case 2250 : return 26563;
        case 2300 : return 22259;
        case 2350 : return 24568;
        case 2400 : return 27717;
        case 2450 : return 23168;
        case 2475 : return 27769;
        case 2490 : return 23195;
    }
  }
    if (a==2550) {
      switch (b) {
        case 127 : return 12879;
        case 150 : return 7095;
        case 175 : return 14013;
        case 200 : return 13981;
        case 300 : return 12854;
        case 400 : return 14053;
        case 500 : return 21123;
        case 600 : return 14265;
        case 700 : return 12988;
        case 800 : return 18799;
        case 900 : return 27188;
        case 1000 : return 26120;
        case 1100 : return 18728;
        case 1200 : return 34232;
        case 1300 : return 28184;
        case 1400 : return 28190;
        case 1500 : return 22436;
        case 1600 : return 30815;
        case 1700 : return 22518;
        case 1800 : return 24792;
        case 1900 : return 21137;
        case 2000 : return 28316;
        case 2100 : return 18846;
        case 2200 : return 20098;
        case 2250 : return 28119;
        case 2300 : return 23621;
        case 2350 : return 20079;
        case 2400 : return 26979;
        case 2450 : return 24652;
        case 2500 : return 22205;
        case 2525 : return 11797;
        case 2540 : return 26958;
    }
  }
    if (a==2600) {
      switch (b) {
        case 127 : return 3669;
        case 150 : return 11912;
        case 175 : return 13219;
        case 200 : return 18017;
        case 300 : return 19101;
        case 400 : return 17859;
        case 500 : return 17891;
        case 600 : return 13332;
        case 700 : return 16664;
        case 800 : return 19268;
        case 900 : return 17937;
        case 1000 : return 22763;
        case 1100 : return 14394;
        case 1200 : return 24030;
        case 1300 : return 22638;
        case 1400 : return 23941;
        case 1500 : return 27572;
        case 1600 : return 22719;
        case 1700 : return 25290;
        case 1800 : return 29915;
        case 1900 : return 27616;
        case 2000 : return 28432;
        case 2100 : return 25328;
        case 2200 : return 26303;
        case 2300 : return 19035;
        case 2350 : return 23999;
        case 2400 : return 20231;
        case 2450 : return 25468;
        case 2500 : return 32209;
        case 2550 : return 26546;
        case 2575 : return 25001;
        case 2590 : return 37266;
    }
  }
    if (a==2650) {
      switch (b) {
        case 127 : return 10968;
        case 150 : return 10865;
        case 175 : return 13449;
        case 200 : return 7372;
        case 300 : return 10888;
        case 400 : return 17113;
        case 500 : return 18181;
        case 600 : return 18117;
        case 700 : return 15947;
        case 800 : return 25585;
        case 900 : return 18021;
        case 1000 : return 17155;
        case 1100 : return 19330;
        case 1200 : return 28295;
        case 1300 : return 14743;
        case 1400 : return 17033;
        case 1500 : return 24336;
        case 1600 : return 22044;
        case 1700 : return 20477;
        case 1800 : return 10111;
        case 1900 : return 25657;
        case 2000 : return 30631;
        case 2100 : return 29349;
        case 2200 : return 25589;
        case 2300 : return 20590;
        case 2350 : return 22004;
        case 2400 : return 16931;
        case 2450 : return 24222;
        case 2500 : return 27063;
        case 2550 : return 24391;
        case 2600 : return 23020;
        case 2625 : return 23196;
        case 2640 : return 21831;
    }
  }
    if (a==2700) {
      switch (b) {
        case 127 : return 13664;
        case 150 : return 9698;
        case 175 : return 13596;
        case 200 : return 11075;
        case 300 : return 16106;
        case 400 : return 7452;
        case 500 : return 11000;
        case 600 : return 14885;
        case 700 : return 14779;
        case 800 : return 23453;
        case 900 : return 13627;
        case 1000 : return 19951;
        case 1100 : return 18505;
        case 1200 : return 27074;
        case 1300 : return 28403;
        case 1400 : return 27087;
        case 1500 : return 19767;
        case 1600 : return 31085;
        case 1700 : return 37125;
        case 1800 : return 23535;
        case 1900 : return 28582;
        case 2000 : return 20993;
        case 2100 : return 23378;
        case 2200 : return 29549;
        case 2300 : return 24798;
        case 2400 : return 31068;
        case 2450 : return 27080;
        case 2500 : return 19800;
        case 2550 : return 23644;
        case 2600 : return 27368;
        case 2650 : return 20894;
        case 2675 : return 37037;
        case 2690 : return 20950;
    }
  }
    if (a==2750) {
      switch (b) {
        case 127 : return 18841;
        case 150 : return 15171;
        case 175 : return 15239;
        case 200 : return 17746;
        case 300 : return 13730;
        case 400 : return 11341;
        case 500 : return 17612;
        case 600 : return 15120;
        case 700 : return 22697;
        case 800 : return 30036;
        case 900 : return 18930;
        case 1000 : return 23798;
        case 1100 : return 17790;
        case 1200 : return 28835;
        case 1300 : return 23793;
        case 1400 : return 32516;
        case 1500 : return 27536;
        case 1600 : return 17623;
        case 1700 : return 23894;
        case 1800 : return 17492;
        case 1900 : return 27661;
        case 2000 : return 38080;
        case 2100 : return 20247;
        case 2200 : return 27607;
        case 2300 : return 31562;
        case 2400 : return 22632;
        case 2450 : return 22902;
        case 2500 : return 33848;
        case 2550 : return 27736;
        case 2600 : return 21608;
        case 2650 : return 17612;
        case 2700 : return 17583;
        case 2725 : return 25118;
        case 2740 : return 17545;
    }
  }
    if (a==2800) {
      switch (b) {
        case 127 : return 14106;
        case 150 : return 10262;
        case 175 : return 16596;
        case 200 : return 12699;
        case 300 : return 12738;
        case 400 : return 10161;
        case 500 : return 12853;
        case 600 : return 16659;
        case 700 : return 12713;
        case 800 : return 17965;
        case 900 : return 26811;
        case 1000 : return 19170;
        case 1100 : return 14071;
        case 1200 : return 14017;
        case 1300 : return 21808;
        case 1400 : return 28115;
        case 1500 : return 22990;
        case 1600 : return 21861;
        case 1700 : return 17955;
        case 1800 : return 14199;
        case 1900 : return 24443;
        case 2000 : return 24484;
        case 2100 : return 27040;
        case 2200 : return 24231;
        case 2300 : return 30694;
        case 2400 : return 23071;
        case 2500 : return 30938;
        case 2550 : return 21605;
        case 2600 : return 30768;
        case 2650 : return 24235;
        case 2700 : return 18117;
        case 2750 : return 16721;
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
        case 200 : return 40892;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 32255;
        case 2100 : return 32558;
        case 2190 : return 42077;
    }
  }
  //year=21160 for postVFP goodpair
      case 21160 :
    if (a==1800) {
      switch (b) {
        case 127 : return 96427;
        case 200 : return 142507;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 53276;
        case 2100 : return 57742;
        case 2190 : return 70533;
    }
  }
      case 3017 :
    if (a==1800) {
      switch (b) {
        case 127 : return 119872;
        case 200 : return 141052;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 84980;
        case 2100 : return 168205;
        case 2190 : return 176454;
    }
  }
      case 3018 :
    if (a==1800) {
      switch (b) {
        case 127 : return 180831;
        case 200 : return 210537;
    }
  }
    if (a==2200) {
      switch (b) {
        case 1000 : return 93909;
        case 2100 : return 167552;
        case 2190 : return 166845;
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
