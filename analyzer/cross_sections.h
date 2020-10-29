#ifndef cross_sections_h
#define cross_sections_h

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
  if (SignalScenario==2) {
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
unsigned long long get_total_events(pair<int,int> input, int year, int SignalScenario) {
  int a=input.first, b=input.second;
  if (SignalScenario==1 || SignalScenario==4) {
    switch (year) {
      case 2016 :
        if (a==800) {
          switch (b) {
            case 127 : return 147004;
            case 200 : return 142314;
            case 300 : return 138793;
            case 400 : return 136376;
            case 500 : return 138954;
            case 600 : return 143824;
            case 700 : return 139064;
            case 790 : return 135322;
        }
      }
        if (a==900) {
          switch (b) {
            case 127 : return 136763;
            case 200 : return 135301;
            case 300 : return 141293;
            case 400 : return 137761;
            case 500 : return 138694;
            case 600 : return 141951;
            case 700 : return 139376;
            case 800 : return 145521;
            case 890 : return 137383;
        }
      }
        if (a==1000) {
          switch (b) {
            case 127 : return 142938;
            case 150 : return 144293;
            case 175 : return 139601;
            case 200 : return 137953;
            case 300 : return 144404;
            case 400 : return 147058;
            case 500 : return 136710;
            case 600 : return 146163;
            case 700 : return 143995;
            case 750 : return 147799;
            case 800 : return 139703;
            case 850 : return 140519;
            case 900 : return 150818;
            case 950 : return 133920;
            case 975 : return 150745;
            case 990 : return 131574;
        }
      }
        if (a==1050) {
          switch (b) {
            case 127 : return 146003;
            case 150 : return 135306;
            case 175 : return 144720;
            case 200 : return 143894;
            case 300 : return 148366;
            case 400 : return 141676;
            case 500 : return 139140;
            case 600 : return 142157;
            case 700 : return 143559;
            case 750 : return 148013;
            case 800 : return 147223;
            case 850 : return 137374;
            case 900 : return 146365;
            case 950 : return 146249;
            case 1000 : return 143798;
            case 1025 : return 147703;
            case 1040 : return 147829;
        }
      }
        if (a==1100) {
          switch (b) {
            case 127 : return 119230;
            case 150 : return 122018;
            case 175 : return 124466;
            case 200 : return 131556;
            case 300 : return 123678;
            case 400 : return 123277;
            case 500 : return 116250;
            case 600 : return 126040;
            case 700 : return 124965;
            case 800 : return 131321;
            case 850 : return 128365;
            case 900 : return 131960;
            case 950 : return 127677;
            case 1000 : return 124145;
            case 1050 : return 125957;
            case 1075 : return 120918;
            case 1090 : return 125263;
        }
      }
        if (a==1150) {
          switch (b) {
            case 127 : return 90251;
            case 150 : return 90960;
            case 175 : return 92424;
            case 200 : return 96916;
            case 300 : return 86269;
            case 400 : return 90997;
            case 500 : return 93640;
            case 600 : return 92002;
            case 700 : return 96003;
            case 800 : return 102523;
            case 850 : return 92409;
            case 900 : return 86744;
            case 950 : return 94012;
            case 1000 : return 95325;
            case 1050 : return 94537;
            case 1100 : return 89967;
            case 1125 : return 83554;
            case 1140 : return 90282;
        }
      }
        if (a==1200) {
          switch (b) {
            case 127 : return 61805;
            case 150 : return 68529;
            case 175 : return 64099;
            case 200 : return 64814;
            case 300 : return 70290;
            case 400 : return 61280;
            case 500 : return 61300;
            case 600 : return 62976;
            case 700 : return 61500;
            case 800 : return 65920;
            case 900 : return 65974;
            case 950 : return 63933;
            case 1000 : return 59577;
            case 1050 : return 64033;
            case 1100 : return 64603;
            case 1150 : return 65424;
            case 1175 : return 64205;
            case 1190 : return 62386;
        }
      }
        if (a==1250) {
          switch (b) {
            case 127 : return 51111;
            case 150 : return 48018;
            case 175 : return 43636;
            case 200 : return 47035;
            case 300 : return 52707;
            case 400 : return 48423;
            case 500 : return 43161;
            case 600 : return 41153;
            case 700 : return 46080;
            case 800 : return 49228;
            case 900 : return 51262;
            case 950 : return 47635;
            case 1000 : return 52353;
            case 1050 : return 46896;
            case 1100 : return 48920;
            case 1150 : return 48383;
            case 1200 : return 54154;
            case 1225 : return 43324;
            case 1240 : return 45676;
        }
      }
        if (a==1300) {
          switch (b) {
            case 127 : return 34037;
            case 150 : return 38918;
            case 175 : return 34339;
            case 200 : return 37080;
            case 300 : return 44056;
            case 400 : return 38739;
            case 500 : return 36090;
            case 600 : return 38334;
            case 700 : return 36493;
            case 800 : return 38850;
            case 900 : return 38082;
            case 1000 : return 38367;
            case 1050 : return 39961;
            case 1100 : return 35981;
            case 1150 : return 41202;
            case 1200 : return 37861;
            case 1250 : return 35586;
            case 1275 : return 37437;
            case 1290 : return 35114;
        }
      }
        if (a==1350) {
          switch (b) {
            case 127 : return 34071;
            case 150 : return 36398;
            case 175 : return 36926;
            case 200 : return 40048;
            case 300 : return 38526;
            case 400 : return 34110;
            case 500 : return 38128;
            case 600 : return 39847;
            case 700 : return 45842;
            case 800 : return 40067;
            case 900 : return 34813;
            case 1000 : return 39361;
            case 1050 : return 40541;
            case 1100 : return 39726;
            case 1150 : return 37556;
            case 1200 : return 37036;
            case 1250 : return 36953;
            case 1300 : return 38794;
            case 1325 : return 41906;
            case 1340 : return 39825;
        }
      }
        if (a==1400) {
          switch (b) {
            case 127 : return 33605;
            case 150 : return 38427;
            case 175 : return 34300;
            case 200 : return 36685;
            case 300 : return 30332;
            case 400 : return 39534;
            case 500 : return 41861;
            case 600 : return 36117;
            case 700 : return 44106;
            case 800 : return 35209;
            case 900 : return 31434;
            case 1000 : return 33710;
            case 1100 : return 39382;
            case 1150 : return 36415;
            case 1200 : return 36830;
            case 1250 : return 32481;
            case 1300 : return 33211;
            case 1350 : return 37760;
            case 1375 : return 41229;
            case 1390 : return 38705;
        }
      }
        if (a==1450) {
          switch (b) {
            case 127 : return 38609;
            case 150 : return 42337;
            case 175 : return 40834;
            case 200 : return 38320;
            case 300 : return 42475;
            case 400 : return 41298;
            case 500 : return 38362;
            case 600 : return 37273;
            case 700 : return 40535;
            case 800 : return 35670;
            case 900 : return 31357;
            case 1000 : return 33783;
            case 1100 : return 33888;
            case 1150 : return 40890;
            case 1200 : return 34418;
            case 1250 : return 35390;
            case 1300 : return 38949;
            case 1350 : return 32505;
            case 1400 : return 35744;
            case 1425 : return 31129;
            case 1440 : return 39429;
        }
      }
        if (a==1500) {
          switch (b) {
            case 127 : return 33676;
            case 150 : return 34358;
            case 175 : return 33055;
            case 200 : return 36403;
            case 300 : return 38211;
            case 400 : return 34787;
            case 500 : return 32477;
            case 600 : return 36096;
            case 700 : return 38013;
            case 800 : return 34527;
            case 900 : return 39726;
            case 1000 : return 41417;
            case 1100 : return 38828;
            case 1200 : return 36618;
            case 1250 : return 37948;
            case 1300 : return 37805;
            case 1350 : return 36624;
            case 1400 : return 36441;
            case 1450 : return 36961;
            case 1475 : return 36441;
            case 1490 : return 37014;
        }
      }
        if (a==1550) {
          switch (b) {
            case 127 : return 37000;
            case 150 : return 32714;
            case 175 : return 38291;
            case 200 : return 38175;
            case 300 : return 34916;
            case 400 : return 36442;
            case 500 : return 37604;
            case 600 : return 34930;
            case 700 : return 34400;
            case 800 : return 33060;
            case 900 : return 34955;
            case 1000 : return 32884;
            case 1100 : return 34690;
            case 1200 : return 36638;
            case 1250 : return 42442;
            case 1300 : return 31809;
            case 1350 : return 34707;
            case 1400 : return 35806;
            case 1450 : return 36857;
            case 1500 : return 35931;
            case 1525 : return 35521;
            case 1540 : return 37568;
        }
      }
        if (a==1600) {
          switch (b) {
            case 127 : return 39460;
            case 150 : return 35781;
            case 175 : return 34490;
            case 200 : return 30772;
            case 300 : return 35563;
            case 400 : return 35427;
            case 500 : return 41437;
            case 600 : return 33291;
            case 700 : return 40768;
            case 800 : return 36077;
            case 900 : return 39335;
            case 1000 : return 36802;
            case 1100 : return 36954;
            case 1200 : return 37629;
            case 1300 : return 37258;
            case 1350 : return 35391;
            case 1400 : return 38170;
            case 1450 : return 39812;
            case 1500 : return 36092;
            case 1550 : return 35459;
            case 1575 : return 35988;
            case 1590 : return 41554;
        }
      }
        if (a==1650) {
          switch (b) {
            case 127 : return 36632;
            case 150 : return 39843;
            case 175 : return 40631;
            case 200 : return 38785;
            case 300 : return 33542;
            case 400 : return 38475;
            case 500 : return 36283;
            case 600 : return 35886;
            case 700 : return 40494;
            case 800 : return 33447;
            case 900 : return 37533;
            case 1000 : return 37910;
            case 1100 : return 38832;
            case 1200 : return 36101;
            case 1300 : return 37781;
            case 1350 : return 36020;
            case 1400 : return 34641;
            case 1450 : return 42308;
            case 1500 : return 40933;
            case 1550 : return 38423;
            case 1600 : return 39828;
            case 1625 : return 38987;
            case 1640 : return 41150;
        }
      }
        if (a==1700) {
          switch (b) {
            case 127 : return 35783;
            case 150 : return 36241;
            case 175 : return 38747;
            case 200 : return 38130;
            case 300 : return 37645;
            case 400 : return 40136;
            case 500 : return 36365;
            case 600 : return 42494;
            case 700 : return 39733;
            case 800 : return 36160;
            case 900 : return 38859;
            case 1000 : return 37849;
            case 1100 : return 37673;
            case 1200 : return 38481;
            case 1300 : return 40795;
            case 1400 : return 43846;
            case 1450 : return 32958;
            case 1500 : return 39080;
            case 1550 : return 39086;
            case 1600 : return 35344;
            case 1650 : return 40070;
            case 1675 : return 38914;
            case 1690 : return 38693;
        }
      }
        if (a==1750) {
          switch (b) {
            case 127 : return 36868;
            case 150 : return 37589;
            case 175 : return 30940;
            case 200 : return 38757;
            case 300 : return 39672;
            case 400 : return 37639;
            case 500 : return 42016;
            case 600 : return 40649;
            case 700 : return 38726;
            case 800 : return 37649;
            case 900 : return 38943;
            case 1000 : return 35810;
            case 1100 : return 37986;
            case 1200 : return 40882;
            case 1300 : return 39411;
            case 1400 : return 38888;
            case 1450 : return 36131;
            case 1500 : return 38391;
            case 1550 : return 39329;
            case 1600 : return 36789;
            case 1650 : return 39222;
            case 1700 : return 38459;
            case 1725 : return 37681;
            case 1740 : return 40109;
        }
      }
        if (a==1800) {
          switch (b) {
            case 127 : return 32062;
            case 150 : return 34593;
            case 175 : return 32332;
            case 200 : return 37971;
            case 300 : return 35351;
            case 400 : return 33775;
            case 500 : return 35610;
            case 600 : return 37013;
            case 700 : return 37046;
            case 800 : return 36630;
            case 900 : return 32954;
            case 1000 : return 31345;
            case 1100 : return 37242;
            case 1200 : return 37369;
            case 1300 : return 37489;
            case 1400 : return 37421;
            case 1500 : return 34220;
            case 1550 : return 32893;
            case 1600 : return 34667;
            case 1650 : return 40860;
            case 1700 : return 34895;
            case 1750 : return 36073;
            case 1775 : return 32668;
            case 1790 : return 39055;
        }
      }
        if (a==1850) {
          switch (b) {
            case 127 : return 32309;
            case 150 : return 39996;
            case 175 : return 31754;
            case 200 : return 38315;
            case 300 : return 40826;
            case 400 : return 34468;
            case 500 : return 36252;
            case 600 : return 34630;
            case 700 : return 39602;
            case 800 : return 31628;
            case 900 : return 35931;
            case 1000 : return 36767;
            case 1100 : return 35286;
            case 1200 : return 35393;
            case 1300 : return 42189;
            case 1400 : return 34258;
            case 1500 : return 34310;
            case 1550 : return 32310;
            case 1600 : return 38346;
            case 1650 : return 35506;
            case 1700 : return 36488;
            case 1750 : return 35949;
            case 1800 : return 37428;
            case 1825 : return 37884;
            case 1840 : return 32947;
        }
      }
        if (a==1900) {
          switch (b) {
            case 127 : return 34409;
            case 150 : return 33688;
            case 175 : return 41070;
            case 200 : return 34394;
            case 300 : return 34266;
            case 400 : return 33672;
            case 500 : return 37057;
            case 600 : return 36547;
            case 700 : return 34667;
            case 800 : return 37999;
            case 900 : return 38091;
            case 1000 : return 35168;
            case 1100 : return 36046;
            case 1200 : return 36273;
            case 1300 : return 34802;
            case 1400 : return 37864;
            case 1500 : return 37266;
            case 1600 : return 37954;
            case 1650 : return 37200;
            case 1700 : return 40374;
            case 1750 : return 31451;
            case 1800 : return 43524;
            case 1850 : return 39968;
            case 1875 : return 32717;
            case 1890 : return 32639;
        }
      }
        if (a==1950) {
          switch (b) {
            case 127 : return 33562;
            case 150 : return 39826;
            case 175 : return 33078;
            case 200 : return 39458;
            case 300 : return 40272;
            case 400 : return 37985;
            case 500 : return 42626;
            case 600 : return 38363;
            case 700 : return 42632;
            case 800 : return 31587;
            case 900 : return 34899;
            case 1000 : return 36020;
            case 1100 : return 36086;
            case 1200 : return 37843;
            case 1300 : return 33970;
            case 1400 : return 37927;
            case 1500 : return 42590;
            case 1600 : return 37668;
            case 1650 : return 36489;
            case 1700 : return 37874;
            case 1750 : return 35188;
            case 1800 : return 35955;
            case 1850 : return 38206;
            case 1900 : return 42024;
            case 1925 : return 36723;
            case 1940 : return 38734;
        }
      }
        if (a==2000) {
          switch (b) {
            case 127 : return 16624;
            case 150 : return 20797;
            case 175 : return 17565;
            case 200 : return 18691;
            case 300 : return 16725;
            case 400 : return 17051;
            case 500 : return 16803;
            case 600 : return 19798;
            case 700 : return 18446;
            case 800 : return 17169;
            case 900 : return 20098;
            case 1000 : return 17445;
            case 1100 : return 19522;
            case 1200 : return 18713;
            case 1300 : return 18324;
            case 1400 : return 18972;
            case 1500 : return 20218;
            case 1600 : return 18722;
            case 1700 : return 17059;
            case 1750 : return 20420;
            case 1800 : return 15879;
            case 1850 : return 21277;
            case 1900 : return 15965;
            case 1950 : return 16808;
            case 1975 : return 21395;
            case 1990 : return 20331;
        }
      }
        if (a==2050) {
          switch (b) {
            case 127 : return 17439;
            case 150 : return 15424;
            case 175 : return 17596;
            case 200 : return 22194;
            case 300 : return 16888;
            case 400 : return 19541;
            case 500 : return 21582;
            case 600 : return 21167;
            case 700 : return 21512;
            case 800 : return 20096;
            case 900 : return 16675;
            case 1000 : return 20464;
            case 1100 : return 22448;
            case 1200 : return 19073;
            case 1300 : return 17505;
            case 1400 : return 19233;
            case 1500 : return 22236;
            case 1600 : return 15575;
            case 1700 : return 18349;
            case 1750 : return 19075;
            case 1800 : return 19132;
            case 1850 : return 14160;
            case 1900 : return 18511;
            case 1950 : return 21266;
            case 2000 : return 19142;
            case 2025 : return 20360;
            case 2040 : return 20393;
        }
      }
        if (a==2100) {
          switch (b) {
            case 127 : return 16855;
            case 150 : return 16757;
            case 175 : return 20253;
            case 200 : return 13185;
            case 300 : return 19485;
            case 400 : return 16346;
            case 500 : return 16968;
            case 600 : return 17332;
            case 700 : return 16010;
            case 800 : return 19583;
            case 900 : return 21091;
            case 1000 : return 18723;
            case 1100 : return 13725;
            case 1200 : return 16269;
            case 1300 : return 14328;
            case 1400 : return 16928;
            case 1500 : return 16708;
            case 1600 : return 16922;
            case 1700 : return 15987;
            case 1800 : return 17338;
            case 1850 : return 16214;
            case 1900 : return 19299;
            case 1950 : return 13468;
            case 2000 : return 15528;
            case 2050 : return 20454;
            case 2075 : return 17573;
            case 2090 : return 19237;
        }
      }
        if (a==2150) {
          switch (b) {
            case 127 : return 21339;
            case 150 : return 16128;
            case 175 : return 17280;
            case 200 : return 16360;
            case 300 : return 17120;
            case 400 : return 15484;
            case 500 : return 14348;
            case 600 : return 18277;
            case 700 : return 16886;
            case 800 : return 15509;
            case 900 : return 20303;
            case 1000 : return 17433;
            case 1100 : return 17435;
            case 1200 : return 14478;
            case 1300 : return 20021;
            case 1400 : return 17089;
            case 1500 : return 18769;
            case 1600 : return 17501;
            case 1700 : return 16232;
            case 1800 : return 17020;
            case 1850 : return 20441;
            case 1900 : return 16229;
            case 1950 : return 15421;
            case 2000 : return 15722;
            case 2050 : return 18206;
            case 2100 : return 15562;
            case 2125 : return 17734;
            case 2140 : return 17805;
        }
      }
        if (a==2200) {
          switch (b) {
            case 127 : return 19681;
            case 150 : return 19004;
            case 175 : return 18511;
            case 200 : return 18334;
            case 300 : return 12597;
            case 400 : return 24551;
            case 500 : return 22710;
            case 600 : return 15207;
            case 700 : return 13359;
            case 800 : return 18495;
            case 900 : return 18659;
            case 1000 : return 14883;
            case 1100 : return 16899;
            case 1200 : return 15219;
            case 1300 : return 17762;
            case 1400 : return 17444;
            case 1500 : return 20532;
            case 1600 : return 20086;
            case 1700 : return 18973;
            case 1800 : return 20178;
            case 1900 : return 19510;
            case 1950 : return 19352;
            case 2000 : return 18108;
            case 2050 : return 18406;
            case 2100 : return 20552;
            case 2150 : return 19477;
            case 2175 : return 21330;
            case 2190 : return 18595;
        }
      }
        if (a==2250) {
          switch (b) {
            case 127 : return 18303;
            case 150 : return 20341;
            case 175 : return 16738;
            case 200 : return 19131;
            case 300 : return 16659;
            case 400 : return 17685;
            case 500 : return 19324;
            case 600 : return 19383;
            case 700 : return 20939;
            case 800 : return 20005;
            case 900 : return 14714;
            case 1000 : return 15830;
            case 1100 : return 16865;
            case 1200 : return 21188;
            case 1300 : return 16502;
            case 1400 : return 18127;
            case 1500 : return 20520;
            case 1600 : return 18501;
            case 1700 : return 18286;
            case 1800 : return 20304;
            case 1900 : return 20786;
            case 1950 : return 15932;
            case 2000 : return 18022;
            case 2050 : return 15433;
            case 2100 : return 17237;
            case 2150 : return 19465;
            case 2200 : return 16460;
            case 2225 : return 18370;
            case 2240 : return 18007;
        }
      }
        if (a==2300) {
          switch (b) {
            case 127 : return 16520;
            case 150 : return 19743;
            case 175 : return 19753;
            case 200 : return 19623;
            case 300 : return 19420;
            case 400 : return 14938;
            case 500 : return 19941;
            case 600 : return 16225;
            case 700 : return 19472;
            case 800 : return 17548;
            case 900 : return 21252;
            case 1000 : return 18578;
            case 1100 : return 21154;
            case 1200 : return 17555;
            case 1300 : return 23917;
            case 1400 : return 21009;
            case 1500 : return 18630;
            case 1600 : return 19113;
            case 1700 : return 21047;
            case 1800 : return 16517;
            case 1900 : return 18084;
            case 2000 : return 16009;
            case 2050 : return 16447;
            case 2100 : return 18691;
            case 2150 : return 19483;
            case 2200 : return 18883;
            case 2250 : return 15028;
            case 2275 : return 18905;
            case 2290 : return 20157;
        }
      }
        if (a==2350) {
          switch (b) {
            case 127 : return 20112;
            case 150 : return 18638;
            case 175 : return 18837;
            case 200 : return 17187;
            case 300 : return 14529;
            case 400 : return 16209;
            case 500 : return 18695;
            case 600 : return 17712;
            case 700 : return 18064;
            case 800 : return 17273;
            case 900 : return 15430;
            case 1000 : return 14479;
            case 1100 : return 16119;
            case 1200 : return 17922;
            case 1300 : return 14294;
            case 1400 : return 18683;
            case 1500 : return 21697;
            case 1600 : return 19033;
            case 1700 : return 17654;
            case 1800 : return 18249;
            case 1900 : return 25424;
            case 2000 : return 19218;
            case 2050 : return 16903;
            case 2100 : return 17038;
            case 2150 : return 18638;
            case 2200 : return 17645;
            case 2250 : return 16725;
            case 2300 : return 19459;
            case 2325 : return 16117;
            case 2340 : return 19490;
        }
      }
        if (a==2400) {
          switch (b) {
            case 127 : return 18180;
            case 150 : return 17012;
            case 175 : return 17118;
            case 200 : return 17073;
            case 300 : return 16407;
            case 400 : return 17201;
            case 500 : return 16208;
            case 600 : return 18299;
            case 700 : return 20248;
            case 800 : return 15138;
            case 900 : return 20162;
            case 1000 : return 18002;
            case 1100 : return 15313;
            case 1200 : return 16882;
            case 1300 : return 18845;
            case 1400 : return 17631;
            case 1500 : return 19869;
            case 1600 : return 14583;
            case 1700 : return 17143;
            case 1800 : return 20432;
            case 1900 : return 15205;
            case 2000 : return 20509;
            case 2100 : return 16613;
            case 2150 : return 17135;
            case 2200 : return 16802;
            case 2250 : return 17475;
            case 2300 : return 16780;
            case 2350 : return 16305;
            case 2375 : return 16378;
            case 2390 : return 15551;
        }
      }
        if (a==2450) {
          switch (b) {
            case 127 : return 18125;
            case 150 : return 16256;
            case 175 : return 18457;
            case 200 : return 16379;
            case 300 : return 19817;
            case 400 : return 15875;
            case 500 : return 16448;
            case 600 : return 17894;
            case 700 : return 19883;
            case 800 : return 17433;
            case 900 : return 18967;
            case 1000 : return 20073;
            case 1100 : return 16365;
            case 1200 : return 19354;
            case 1300 : return 15236;
            case 1400 : return 18655;
            case 1500 : return 17409;
            case 1600 : return 19020;
            case 1700 : return 20920;
            case 1800 : return 18710;
            case 1900 : return 19364;
            case 2000 : return 18503;
            case 2100 : return 20371;
            case 2150 : return 19309;
            case 2200 : return 15253;
            case 2250 : return 15038;
            case 2300 : return 18024;
            case 2350 : return 15426;
            case 2400 : return 16995;
            case 2425 : return 19282;
            case 2440 : return 19842;
        }
      }
        if (a==2500) {
          switch (b) {
            case 127 : return 14961;
            case 150 : return 20630;
            case 175 : return 19080;
            case 200 : return 18205;
            case 300 : return 20865;
            case 400 : return 18729;
            case 500 : return 17465;
            case 600 : return 16982;
            case 700 : return 18757;
            case 800 : return 18534;
            case 900 : return 17062;
            case 1000 : return 15528;
            case 1100 : return 22145;
            case 1200 : return 18810;
            case 1300 : return 17970;
            case 1400 : return 17596;
            case 1500 : return 19189;
            case 1600 : return 14611;
            case 1700 : return 16635;
            case 1800 : return 20710;
            case 1900 : return 20243;
            case 2000 : return 18363;
            case 2100 : return 16162;
            case 2200 : return 18690;
            case 2250 : return 20915;
            case 2300 : return 15913;
            case 2350 : return 17531;
            case 2400 : return 18996;
            case 2450 : return 16844;
            case 2475 : return 19598;
            case 2490 : return 18645;
        }
      }
        if (a==2550) {
          switch (b) {
            case 127 : return 17500;
            case 150 : return 21243;
            case 175 : return 14185;
            case 200 : return 18733;
            case 300 : return 19415;
            case 400 : return 16029;
            case 500 : return 19127;
            case 600 : return 20195;
            case 700 : return 18832;
            case 800 : return 18913;
            case 900 : return 18772;
            case 1000 : return 19492;
            case 1100 : return 19781;
            case 1200 : return 16788;
            case 1300 : return 18418;
            case 1400 : return 17155;
            case 1500 : return 21999;
            case 1600 : return 20315;
            case 1700 : return 20246;
            case 1800 : return 19018;
            case 1900 : return 21178;
            case 2000 : return 20312;
            case 2100 : return 16162;
            case 2200 : return 18666;
            case 2250 : return 18186;
            case 2300 : return 20270;
            case 2350 : return 18941;
            case 2400 : return 19370;
            case 2450 : return 18679;
            case 2500 : return 15336;
            case 2525 : return 17433;
            case 2540 : return 17354;
        }
      }
        if (a==2600) {
          switch (b) {
            case 127 : return 17496;
            case 150 : return 14878;
            case 175 : return 17552;
            case 200 : return 21180;
            case 300 : return 20864;
            case 400 : return 16459;
            case 500 : return 17280;
            case 600 : return 14934;
            case 700 : return 20291;
            case 800 : return 20874;
            case 900 : return 17495;
            case 1000 : return 22777;
            case 1100 : return 17589;
            case 1200 : return 19651;
            case 1300 : return 21747;
            case 1400 : return 18138;
            case 1500 : return 15629;
            case 1600 : return 16882;
            case 1700 : return 22011;
            case 1800 : return 18747;
            case 1900 : return 16760;
            case 2000 : return 19711;
            case 2100 : return 19671;
            case 2200 : return 20576;
            case 2300 : return 19793;
            case 2350 : return 20970;
            case 2400 : return 14357;
            case 2450 : return 16575;
            case 2500 : return 18768;
            case 2550 : return 14561;
            case 2575 : return 19661;
            case 2590 : return 18252;
        }
      }
        if (a==2650) {
          switch (b) {
            case 127 : return 15123;
            case 150 : return 15169;
            case 175 : return 15522;
            case 200 : return 17153;
            case 300 : return 20155;
            case 400 : return 19384;
            case 500 : return 17451;
            case 600 : return 16188;
            case 700 : return 16575;
            case 800 : return 13951;
            case 900 : return 16693;
            case 1000 : return 19139;
            case 1100 : return 16950;
            case 1200 : return 19972;
            case 1300 : return 16690;
            case 1400 : return 20928;
            case 1500 : return 20891;
            case 1600 : return 20049;
            case 1700 : return 16486;
            case 1800 : return 21327;
            case 1900 : return 18063;
            case 2000 : return 20673;
            case 2100 : return 17450;
            case 2200 : return 19025;
            case 2300 : return 14507;
            case 2350 : return 18028;
            case 2400 : return 17290;
            case 2450 : return 16767;
            case 2500 : return 19563;
            case 2550 : return 14015;
            case 2600 : return 19693;
            case 2625 : return 15959;
            case 2640 : return 20852;
        }
      }
        if (a==2700) {
          switch (b) {
            case 127 : return 18351;
            case 150 : return 17316;
            case 175 : return 15402;
            case 200 : return 15340;
            case 300 : return 17251;
            case 400 : return 15333;
            case 500 : return 19175;
            case 600 : return 18739;
            case 700 : return 18450;
            case 800 : return 17684;
            case 900 : return 17614;
            case 1000 : return 17162;
            case 1100 : return 15754;
            case 1200 : return 15311;
            case 1300 : return 18145;
            case 1400 : return 14946;
            case 1500 : return 19625;
            case 1600 : return 17803;
            case 1700 : return 18380;
            case 1800 : return 19271;
            case 1900 : return 16643;
            case 2000 : return 18788;
            case 2100 : return 15236;
            case 2200 : return 17843;
            case 2300 : return 14642;
            case 2400 : return 14282;
            case 2450 : return 18636;
            case 2500 : return 19983;
            case 2550 : return 17730;
            case 2600 : return 17378;
            case 2650 : return 22260;
            case 2675 : return 19490;
            case 2690 : return 16763;
        }
      }
        if (a==2750) {
          switch (b) {
            case 127 : return 19057;
            case 150 : return 19894;
            case 175 : return 16423;
            case 200 : return 19272;
            case 300 : return 18398;
            case 400 : return 15751;
            case 500 : return 17858;
            case 600 : return 17819;
            case 700 : return 15313;
            case 800 : return 15701;
            case 900 : return 13398;
            case 1000 : return 18379;
            case 1100 : return 16640;
            case 1200 : return 16375;
            case 1300 : return 16888;
            case 1400 : return 18221;
            case 1500 : return 16849;
            case 1600 : return 19899;
            case 1700 : return 20411;
            case 1800 : return 19624;
            case 1900 : return 17805;
            case 2000 : return 18362;
            case 2100 : return 17384;
            case 2200 : return 16747;
            case 2300 : return 15036;
            case 2400 : return 14283;
            case 2450 : return 17930;
            case 2500 : return 19466;
            case 2550 : return 21318;
            case 2600 : return 22181;
            case 2650 : return 20844;
            case 2700 : return 17447;
            case 2725 : return 15935;
            case 2740 : return 18644;
        }
      }
        if (a==2800) {
          switch (b) {
            case 127 : return 17912;
            case 150 : return 17078;
            case 175 : return 17845;
            case 200 : return 20282;
            case 300 : return 19410;
            case 400 : return 18789;
            case 500 : return 19852;
            case 600 : return 18967;
            case 700 : return 22142;
            case 800 : return 18837;
            case 900 : return 14195;
            case 1000 : return 19483;
            case 1100 : return 14289;
            case 1200 : return 19894;
            case 1300 : return 20121;
            case 1400 : return 14544;
            case 1500 : return 17807;
            case 1600 : return 16611;
            case 1700 : return 19434;
            case 1800 : return 15251;
            case 1900 : return 18416;
            case 2000 : return 19301;
            case 2100 : return 21066;
            case 2200 : return 19426;
            case 2300 : return 15685;
            case 2400 : return 16547;
            case 2500 : return 16424;
            case 2550 : return 16025;
            case 2600 : return 17154;
            case 2650 : return 16322;
            case 2700 : return 22546;
            case 2750 : return 18074;
            case 2775 : return 15309;
            case 2790 : return 19103;
        }
      }
      break;
      case 2017 :
      if (a==800) {
        switch (b) {
          case 127 : return 164945;
          case 200 : return 179515;
          case 300 : return 141551;
          case 400 : return 158603;
          case 500 : return 194888;
          case 600 : return 184120;
          case 700 : return 195814;
          case 790 : return 181265;
      }
    }
      if (a==900) {
        switch (b) {
          case 127 : return 183641;
          case 200 : return 158806;
          case 300 : return 194041;
          case 400 : return 157027;
          case 500 : return 166566;
          case 600 : return 192248;
          case 700 : return 173488;
          case 800 : return 164517;
          case 890 : return 177886;
      }
    }
      if (a==1000) {
        switch (b) {
          case 127 : return 181998;
          case 150 : return 178914;
          case 175 : return 182815;
          case 200 : return 176511;
          case 300 : return 158717;
          case 400 : return 168758;
          case 500 : return 180559;
          case 600 : return 164160;
          case 700 : return 170267;
          case 750 : return 167531;
          case 800 : return 152929;
          case 850 : return 158682;
          case 900 : return 161253;
          case 950 : return 173678;
          case 975 : return 197990;
          case 990 : return 159522;
      }
    }
      if (a==1050) {
        switch (b) {
          case 127 : return 207497;
          case 150 : return 167073;
          case 175 : return 176313;
          case 200 : return 186381;
          case 300 : return 192459;
          case 400 : return 156168;
          case 500 : return 185775;
          case 600 : return 164469;
          case 700 : return 175561;
          case 750 : return 168828;
          case 800 : return 179650;
          case 850 : return 177252;
          case 900 : return 158615;
          case 950 : return 166183;
          case 1000 : return 177454;
          case 1025 : return 172489;
          case 1040 : return 145837;
      }
    }
      if (a==1100) {
        switch (b) {
          case 127 : return 154405;
          case 150 : return 154018;
          case 175 : return 170068;
          case 200 : return 154564;
          case 300 : return 138350;
          case 400 : return 164459;
          case 500 : return 160330;
          case 600 : return 156700;
          case 700 : return 152783;
          case 800 : return 161462;
          case 850 : return 154983;
          case 900 : return 144756;
          case 950 : return 148518;
          case 1000 : return 155754;
          case 1050 : return 150445;
          case 1075 : return 130199;
          case 1090 : return 140237;
      }
    }
      if (a==1150) {
        switch (b) {
          case 127 : return 115822;
          case 150 : return 113825;
          case 175 : return 104662;
          case 200 : return 100530;
          case 300 : return 103311;
          case 400 : return 118384;
          case 500 : return 113295;
          case 600 : return 86613;
          case 700 : return 100597;
          case 800 : return 100103;
          case 850 : return 103348;
          case 900 : return 105432;
          case 950 : return 117505;
          case 1000 : return 92609;
          case 1050 : return 105570;
          case 1100 : return 96118;
          case 1125 : return 100745;
          case 1140 : return 102995;
      }
    }
      if (a==1200) {
        switch (b) {
          case 127 : return 82026;
          case 150 : return 85677;
          case 175 : return 63594;
          case 200 : return 71674;
          case 300 : return 73150;
          case 400 : return 88654;
          case 500 : return 81767;
          case 600 : return 70983;
          case 700 : return 71377;
          case 800 : return 75720;
          case 900 : return 74120;
          case 950 : return 72024;
          case 1000 : return 89443;
          case 1050 : return 64793;
          case 1100 : return 74694;
          case 1150 : return 71644;
          case 1175 : return 74004;
          case 1190 : return 85885;
      }
    }
      if (a==1250) {
        switch (b) {
          case 127 : return 60786;
          case 150 : return 67988;
          case 175 : return 50145;
          case 200 : return 50982;
          case 300 : return 69940;
          case 400 : return 54620;
          case 500 : return 59316;
          case 600 : return 58350;
          case 700 : return 51972;
          case 800 : return 57161;
          case 900 : return 65582;
          case 950 : return 48003;
          case 1000 : return 59925;
          case 1050 : return 58291;
          case 1100 : return 44901;
          case 1150 : return 48477;
          case 1200 : return 55576;
          case 1225 : return 55583;
          case 1240 : return 61987;
      }
    }
      if (a==1300) {
        switch (b) {
          case 127 : return 36150;
          case 150 : return 52478;
          case 175 : return 45813;
          case 200 : return 38633;
          case 300 : return 47847;
          case 400 : return 49132;
          case 500 : return 43120;
          case 600 : return 56158;
          case 700 : return 46750;
          case 800 : return 46801;
          case 900 : return 46745;
          case 1000 : return 49468;
          case 1050 : return 47762;
          case 1100 : return 49674;
          case 1150 : return 52332;
          case 1200 : return 49833;
          case 1250 : return 41274;
          case 1275 : return 56976;
          case 1290 : return 43055;
      }
    }
      if (a==1350) {
        switch (b) {
          case 127 : return 40639;
          case 150 : return 51747;
          case 175 : return 45544;
          case 200 : return 49232;
          case 300 : return 51919;
          case 400 : return 52078;
          case 500 : return 40883;
          case 600 : return 46560;
          case 700 : return 46007;
          case 800 : return 47064;
          case 900 : return 53785;
          case 1000 : return 45423;
          case 1050 : return 48292;
          case 1100 : return 35313;
          case 1150 : return 41923;
          case 1200 : return 44509;
          case 1250 : return 40681;
          case 1300 : return 41098;
          case 1325 : return 38158;
          case 1340 : return 61781;
      }
    }
      if (a==1400) {
        switch (b) {
          case 127 : return 45807;
          case 150 : return 40287;
          case 175 : return 50561;
          case 200 : return 61905;
          case 300 : return 51657;
          case 400 : return 43849;
          case 500 : return 53567;
          case 600 : return 41195;
          case 700 : return 55103;
          case 800 : return 36308;
          case 900 : return 49444;
          case 1000 : return 50241;
          case 1100 : return 46671;
          case 1150 : return 40221;
          case 1200 : return 48696;
          case 1250 : return 36116;
          case 1300 : return 38445;
          case 1350 : return 37535;
          case 1375 : return 33900;
          case 1390 : return 44687;
      }
    }
      if (a==1450) {
        switch (b) {
          case 127 : return 46261;
          case 150 : return 47138;
          case 175 : return 43680;
          case 200 : return 31078;
          case 300 : return 37928;
          case 400 : return 40585;
          case 500 : return 40651;
          case 600 : return 44522;
          case 700 : return 40864;
          case 800 : return 57662;
          case 900 : return 46497;
          case 1000 : return 47963;
          case 1100 : return 39731;
          case 1150 : return 35886;
          case 1200 : return 35821;
          case 1250 : return 44593;
          case 1300 : return 36954;
          case 1350 : return 38802;
          case 1400 : return 36006;
          case 1425 : return 41671;
          case 1440 : return 48272;
      }
    }
      if (a==1500) {
        switch (b) {
          case 127 : return 52381;
          case 150 : return 41133;
          case 175 : return 48617;
          case 200 : return 41323;
          case 300 : return 38352;
          case 400 : return 46091;
          case 500 : return 45060;
          case 600 : return 58160;
          case 700 : return 50797;
          case 800 : return 52768;
          case 900 : return 43927;
          case 1000 : return 39166;
          case 1100 : return 38182;
          case 1200 : return 43031;
          case 1250 : return 41226;
          case 1300 : return 41267;
          case 1350 : return 30587;
          case 1400 : return 41951;
          case 1450 : return 48956;
          case 1475 : return 41064;
          case 1490 : return 35041;
      }
    }
      if (a==1550) {
        switch (b) {
          case 127 : return 51036;
          case 150 : return 42377;
          case 175 : return 41278;
          case 200 : return 46290;
          case 300 : return 44564;
          case 400 : return 44291;
          case 500 : return 36725;
          case 600 : return 48325;
          case 700 : return 44338;
          case 800 : return 47254;
          case 900 : return 43361;
          case 1000 : return 41377;
          case 1100 : return 43684;
          case 1200 : return 38724;
          case 1250 : return 43503;
          case 1300 : return 39548;
          case 1350 : return 46352;
          case 1400 : return 47514;
          case 1450 : return 30672;
          case 1500 : return 38757;
          case 1525 : return 49297;
          case 1540 : return 38457;
      }
    }
      if (a==1600) {
        switch (b) {
          case 127 : return 45853;
          case 150 : return 44794;
          case 175 : return 45073;
          case 200 : return 39907;
          case 300 : return 41806;
          case 400 : return 52692;
          case 500 : return 39833;
          case 600 : return 43035;
          case 700 : return 47981;
          case 800 : return 34199;
          case 900 : return 43096;
          case 1000 : return 46802;
          case 1100 : return 43594;
          case 1200 : return 43843;
          case 1300 : return 37854;
          case 1350 : return 43859;
          case 1400 : return 37275;
          case 1450 : return 43925;
          case 1500 : return 38318;
          case 1550 : return 42041;
          case 1575 : return 34372;
          case 1590 : return 41891;
      }
    }
      if (a==1650) {
        switch (b) {
          case 127 : return 43161;
          case 150 : return 42408;
          case 175 : return 55437;
          case 200 : return 39547;
          case 300 : return 51330;
          case 400 : return 50408;
          case 500 : return 52289;
          case 600 : return 37380;
          case 700 : return 52065;
          case 800 : return 44227;
          case 900 : return 44256;
          case 1000 : return 41418;
          case 1100 : return 57279;
          case 1200 : return 45100;
          case 1300 : return 50941;
          case 1350 : return 40307;
          case 1400 : return 37602;
          case 1450 : return 37103;
          case 1500 : return 37627;
          case 1550 : return 35822;
          case 1600 : return 37512;
          case 1625 : return 33646;
          case 1640 : return 48201;
      }
    }
      if (a==1700) {
        switch (b) {
          case 127 : return 43703;
          case 150 : return 41206;
          case 175 : return 51938;
          case 200 : return 46077;
          case 300 : return 49639;
          case 400 : return 34088;
          case 500 : return 49025;
          case 600 : return 42163;
          case 700 : return 51905;
          case 800 : return 41828;
          case 900 : return 57026;
          case 1000 : return 60972;
          case 1100 : return 44659;
          case 1200 : return 41203;
          case 1300 : return 39870;
          case 1400 : return 38137;
          case 1450 : return 43056;
          case 1500 : return 41941;
          case 1550 : return 45154;
          case 1600 : return 45192;
          case 1650 : return 43101;
          case 1675 : return 40170;
          case 1690 : return 47756;
      }
    }
      if (a==1750) {
        switch (b) {
          case 127 : return 32422;
          case 150 : return 39609;
          case 175 : return 61728;
          case 200 : return 45579;
          case 300 : return 44749;
          case 400 : return 47569;
          case 500 : return 53622;
          case 600 : return 37632;
          case 700 : return 43648;
          case 800 : return 47571;
          case 900 : return 41492;
          case 1000 : return 38610;
          case 1100 : return 51571;
          case 1200 : return 38587;
          case 1300 : return 41185;
          case 1400 : return 33615;
          case 1450 : return 42583;
          case 1500 : return 40591;
          case 1550 : return 30431;
          case 1600 : return 44307;
          case 1650 : return 36602;
          case 1700 : return 37771;
          case 1725 : return 59878;
          case 1740 : return 44887;
      }
    }
      if (a==1800) {
        switch (b) {
          case 127 : return 36131;
          case 150 : return 43027;
          case 175 : return 37100;
          case 200 : return 41008;
          case 300 : return 42982;
          case 400 : return 41132;
          case 500 : return 40109;
          case 600 : return 39195;
          case 700 : return 42944;
          case 800 : return 39142;
          case 900 : return 47334;
          case 1000 : return 36771;
          case 1100 : return 45319;
          case 1200 : return 37686;
          case 1300 : return 27560;
          case 1400 : return 30615;
          case 1500 : return 37047;
          case 1550 : return 53449;
          case 1600 : return 34946;
          case 1650 : return 36980;
          case 1700 : return 43116;
          case 1750 : return 49258;
          case 1775 : return 29731;
          case 1790 : return 45112;
      }
    }
      if (a==1850) {
        switch (b) {
          case 127 : return 47480;
          case 150 : return 30141;
          case 175 : return 37241;
          case 200 : return 50187;
          case 300 : return 39483;
          case 400 : return 40608;
          case 500 : return 45809;
          case 600 : return 53812;
          case 700 : return 33197;
          case 800 : return 45185;
          case 900 : return 37410;
          case 1000 : return 37554;
          case 1100 : return 41614;
          case 1200 : return 49658;
          case 1300 : return 42677;
          case 1400 : return 40417;
          case 1500 : return 47924;
          case 1550 : return 37618;
          case 1600 : return 44614;
          case 1650 : return 35259;
          case 1700 : return 49101;
          case 1750 : return 29038;
          case 1800 : return 30294;
          case 1825 : return 36272;
          case 1840 : return 36295;
      }
    }
      if (a==1900) {
        switch (b) {
          case 127 : return 42280;
          case 150 : return 47586;
          case 175 : return 46392;
          case 200 : return 49786;
          case 300 : return 36885;
          case 400 : return 43069;
          case 500 : return 40986;
          case 600 : return 47403;
          case 700 : return 41268;
          case 800 : return 44578;
          case 900 : return 46218;
          case 1000 : return 54928;
          case 1100 : return 46504;
          case 1200 : return 39940;
          case 1300 : return 55062;
          case 1400 : return 39119;
          case 1500 : return 37069;
          case 1600 : return 27544;
          case 1650 : return 38994;
          case 1700 : return 46551;
          case 1750 : return 35018;
          case 1800 : return 41362;
          case 1850 : return 41299;
          case 1875 : return 40478;
          case 1890 : return 44403;
      }
    }
      if (a==1950) {
        switch (b) {
          case 127 : return 52525;
          case 150 : return 48112;
          case 175 : return 44855;
          case 200 : return 53421;
          case 300 : return 45049;
          case 400 : return 40371;
          case 500 : return 40631;
          case 600 : return 38427;
          case 700 : return 30951;
          case 800 : return 52289;
          case 900 : return 41528;
          case 1000 : return 40548;
          case 1100 : return 36501;
          case 1200 : return 34450;
          case 1300 : return 38057;
          case 1400 : return 40529;
          case 1500 : return 48129;
          case 1600 : return 47106;
          case 1650 : return 33009;
          case 1700 : return 39415;
          case 1750 : return 43566;
          case 1800 : return 33228;
          case 1850 : return 37378;
          case 1900 : return 42822;
          case 1925 : return 42858;
          case 1940 : return 32956;
      }
    }
      if (a==2000) {
        switch (b) {
          case 127 : return 21594;
          case 150 : return 25902;
          case 175 : return 20684;
          case 200 : return 18487;
          case 300 : return 21712;
          case 400 : return 23715;
          case 500 : return 18397;
          case 600 : return 29269;
          case 700 : return 11894;
          case 800 : return 22728;
          case 900 : return 18302;
          case 1000 : return 31348;
          case 1100 : return 19496;
          case 1200 : return 24044;
          case 1300 : return 23797;
          case 1400 : return 16234;
          case 1500 : return 20466;
          case 1600 : return 16208;
          case 1700 : return 14017;
          case 1750 : return 15129;
          case 1800 : return 21757;
          case 1850 : return 18376;
          case 1900 : return 20982;
          case 1950 : return 14149;
          case 1975 : return 19611;
          case 1990 : return 14113;
      }
    }
      if (a==2050) {
        switch (b) {
          case 127 : return 19754;
          case 150 : return 20904;
          case 175 : return 23163;
          case 200 : return 25311;
          case 300 : return 24223;
          case 400 : return 21867;
          case 500 : return 27525;
          case 600 : return 17586;
          case 700 : return 19806;
          case 800 : return 31814;
          case 900 : return 17576;
          case 1000 : return 31900;
          case 1100 : return 21923;
          case 1200 : return 18890;
          case 1300 : return 20992;
          case 1400 : return 24274;
          case 1500 : return 17574;
          case 1600 : return 23075;
          case 1700 : return 24207;
          case 1750 : return 15304;
          case 1800 : return 15304;
          case 1850 : return 23029;
          case 1900 : return 15375;
          case 1950 : return 23032;
          case 2000 : return 18835;
          case 2025 : return 22118;
          case 2040 : return 28100;
      }
    }
      if (a==2100) {
        switch (b) {
          case 127 : return 23328;
          case 150 : return 18789;
          case 175 : return 19944;
          case 200 : return 18986;
          case 300 : return 24707;
          case 400 : return 19113;
          case 500 : return 21229;
          case 600 : return 23287;
          case 700 : return 22508;
          case 800 : return 25667;
          case 900 : return 18832;
          case 1000 : return 26706;
          case 1100 : return 17820;
          case 1200 : return 19047;
          case 1300 : return 25670;
          case 1400 : return 30257;
          case 1500 : return 24564;
          case 1600 : return 27822;
          case 1700 : return 13174;
          case 1800 : return 21163;
          case 1850 : return 17655;
          case 1900 : return 11221;
          case 1950 : return 14599;
          case 2000 : return 23276;
          case 2050 : return 12327;
          case 2075 : return 21365;
          case 2090 : return 16644;
      }
    }
      if (a==2150) {
        switch (b) {
          case 127 : return 12480;
          case 150 : return 24675;
          case 175 : return 24740;
          case 200 : return 16992;
          case 300 : return 21340;
          case 400 : return 18082;
          case 500 : return 14619;
          case 600 : return 25936;
          case 700 : return 19263;
          case 800 : return 22568;
          case 900 : return 14748;
          case 1000 : return 21490;
          case 1100 : return 19309;
          case 1200 : return 20490;
          case 1300 : return 21316;
          case 1400 : return 14597;
          case 1500 : return 19179;
          case 1600 : return 19295;
          case 1700 : return 19172;
          case 1800 : return 27323;
          case 1850 : return 19129;
          case 1900 : return 18142;
          case 1950 : return 21465;
          case 2000 : return 22595;
          case 2050 : return 15780;
          case 2100 : return 15996;
          case 2125 : return 22594;
          case 2140 : return 13469;
      }
    }
      if (a==2200) {
        switch (b) {
          case 127 : return 29681;
          case 150 : return 25089;
          case 175 : return 28738;
          case 200 : return 27398;
          case 300 : return 22950;
          case 400 : return 16032;
          case 500 : return 25254;
          case 600 : return 14916;
          case 700 : return 19448;
          case 800 : return 15924;
          case 900 : return 27480;
          case 1000 : return 26226;
          case 1100 : return 20591;
          case 1200 : return 27836;
          case 1300 : return 21745;
          case 1400 : return 18322;
          case 1500 : return 12724;
          case 1600 : return 19654;
          case 1700 : return 12596;
          case 1800 : return 11444;
          case 1900 : return 17226;
          case 1950 : return 21999;
          case 2000 : return 27410;
          case 2050 : return 10513;
          case 2100 : return 16168;
          case 2150 : return 20819;
          case 2175 : return 12570;
          case 2190 : return 12457;
      }
    }
      if (a==2250) {
        switch (b) {
          case 127 : return 13890;
          case 150 : return 23172;
          case 175 : return 16396;
          case 200 : return 23192;
          case 300 : return 14066;
          case 400 : return 23202;
          case 500 : return 22074;
          case 600 : return 20821;
          case 700 : return 26962;
          case 800 : return 24385;
          case 900 : return 16230;
          case 1000 : return 31415;
          case 1100 : return 18598;
          case 1200 : return 21980;
          case 1300 : return 14921;
          case 1400 : return 24281;
          case 1500 : return 26792;
          case 1600 : return 15075;
          case 1700 : return 25739;
          case 1800 : return 22261;
          case 1900 : return 25464;
          case 1950 : return 18521;
          case 2000 : return 24459;
          case 2050 : return 20818;
          case 2100 : return 16373;
          case 2150 : return 17357;
          case 2200 : return 16150;
          case 2225 : return 15161;
          case 2240 : return 11560;
      }
    }
      if (a==2300) {
        switch (b) {
          case 127 : return 24534;
          case 150 : return 16572;
          case 175 : return 16520;
          case 200 : return 21026;
          case 300 : return 21197;
          case 400 : return 23628;
          case 500 : return 22248;
          case 600 : return 12872;
          case 700 : return 31613;
          case 800 : return 18862;
          case 900 : return 22280;
          case 1000 : return 21152;
          case 1100 : return 19921;
          case 1200 : return 22426;
          case 1300 : return 23652;
          case 1400 : return 28420;
          case 1500 : return 17482;
          case 1600 : return 19972;
          case 1700 : return 30781;
          case 1800 : return 24533;
          case 1900 : return 12924;
          case 2000 : return 22317;
          case 2050 : return 15537;
          case 2100 : return 21296;
          case 2150 : return 21151;
          case 2200 : return 25962;
          case 2250 : return 18893;
          case 2275 : return 15291;
          case 2290 : return 20011;
      }
    }
      if (a==2350) {
        switch (b) {
          case 127 : return 19068;
          case 150 : return 25034;
          case 175 : return 15560;
          case 200 : return 22488;
          case 300 : return 26133;
          case 400 : return 26238;
          case 500 : return 20279;
          case 600 : return 20305;
          case 700 : return 13016;
          case 800 : return 16633;
          case 900 : return 14175;
          case 1000 : return 20217;
          case 1100 : return 17871;
          case 1200 : return 16698;
          case 1300 : return 13162;
          case 1400 : return 19016;
          case 1500 : return 15354;
          case 1600 : return 17955;
          case 1700 : return 23836;
          case 1800 : return 21342;
          case 1900 : return 10794;
          case 2000 : return 13085;
          case 2050 : return 21525;
          case 2100 : return 19126;
          case 2150 : return 16658;
          case 2200 : return 27314;
          case 2250 : return 15504;
          case 2300 : return 22513;
          case 2325 : return 14345;
          case 2340 : return 24843;
      }
    }
      if (a==2400) {
        switch (b) {
          case 127 : return 14417;
          case 150 : return 12217;
          case 175 : return 24114;
          case 200 : return 25268;
          case 300 : return 19327;
          case 400 : return 11924;
          case 500 : return 25402;
          case 600 : return 22876;
          case 700 : return 18068;
          case 800 : return 24070;
          case 900 : return 15729;
          case 1000 : return 14556;
          case 1100 : return 31343;
          case 1200 : return 14613;
          case 1300 : return 24240;
          case 1400 : return 28809;
          case 1500 : return 17938;
          case 1600 : return 21893;
          case 1700 : return 21474;
          case 1800 : return 26804;
          case 1900 : return 12011;
          case 2000 : return 24157;
          case 2100 : return 23979;
          case 2150 : return 24067;
          case 2200 : return 10856;
          case 2250 : return 14516;
          case 2300 : return 16901;
          case 2350 : return 12177;
          case 2375 : return 20378;
          case 2390 : return 19472;
      }
    }
      if (a==2450) {
        switch (b) {
          case 127 : return 18321;
          case 150 : return 24300;
          case 175 : return 23188;
          case 200 : return 13535;
          case 300 : return 18363;
          case 400 : return 17113;
          case 500 : return 19580;
          case 600 : return 14547;
          case 700 : return 9770;
          case 800 : return 28232;
          case 900 : return 23258;
          case 1000 : return 25619;
          case 1100 : return 14696;
          case 1200 : return 17162;
          case 1300 : return 18365;
          case 1400 : return 19674;
          case 1500 : return 25803;
          case 1600 : return 22025;
          case 1700 : return 15977;
          case 1800 : return 13421;
          case 1900 : return 18386;
          case 2000 : return 9810;
          case 2100 : return 20774;
          case 2150 : return 15783;
          case 2200 : return 20786;
          case 2250 : return 20764;
          case 2300 : return 13402;
          case 2350 : return 24408;
          case 2400 : return 17018;
          case 2425 : return 24274;
          case 2440 : return 14609;
      }
    }
      if (a==2500) {
        switch (b) {
          case 127 : return 23461;
          case 150 : return 18333;
          case 175 : return 19794;
          case 200 : return 31038;
          case 300 : return 32238;
          case 400 : return 29958;
          case 500 : return 18593;
          case 600 : return 27152;
          case 700 : return 18557;
          case 800 : return 19749;
          case 900 : return 21111;
          case 1000 : return 18439;
          case 1100 : return 25990;
          case 1200 : return 17126;
          case 1300 : return 21156;
          case 1400 : return 25935;
          case 1500 : return 12380;
          case 1600 : return 13485;
          case 1700 : return 24788;
          case 1800 : return 21005;
          case 1900 : return 17347;
          case 2000 : return 11210;
          case 2100 : return 29784;
          case 2200 : return 19719;
          case 2250 : return 16192;
          case 2300 : return 14813;
          case 2350 : return 11124;
          case 2400 : return 16129;
          case 2450 : return 11052;
          case 2475 : return 22215;
          case 2490 : return 20990;
      }
    }
      if (a==2550) {
        switch (b) {
          case 127 : return 18852;
          case 150 : return 23656;
          case 175 : return 21322;
          case 200 : return 33518;
          case 300 : return 27661;
          case 400 : return 23855;
          case 500 : return 30349;
          case 600 : return 20063;
          case 700 : return 27628;
          case 800 : return 27556;
          case 900 : return 13889;
          case 1000 : return 19790;
          case 1100 : return 32349;
          case 1200 : return 21263;
          case 1300 : return 22675;
          case 1400 : return 12410;
          case 1500 : return 28722;
          case 1600 : return 27648;
          case 1700 : return 18657;
          case 1800 : return 20119;
          case 1900 : return 12458;
          case 2000 : return 18666;
          case 2100 : return 13705;
          case 2200 : return 22554;
          case 2250 : return 12379;
          case 2300 : return 22466;
          case 2350 : return 17412;
          case 2400 : return 21194;
          case 2450 : return 23858;
          case 2500 : return 17567;
          case 2525 : return 13837;
          case 2540 : return 21146;
      }
    }
      if (a==2600) {
        switch (b) {
          case 127 : return 30319;
          case 150 : return 20224;
          case 175 : return 17638;
          case 200 : return 18988;
          case 300 : return 18991;
          case 400 : return 24063;
          case 500 : return 25443;
          case 600 : return 8896;
          case 700 : return 20252;
          case 800 : return 22956;
          case 900 : return 17740;
          case 1000 : return 21420;
          case 1100 : return 12662;
          case 1200 : return 24196;
          case 1300 : return 14001;
          case 1400 : return 17701;
          case 1500 : return 20407;
          case 1600 : return 19169;
          case 1700 : return 25376;
          case 1800 : return 25322;
          case 1900 : return 25326;
          case 2000 : return 16465;
          case 2100 : return 16561;
          case 2200 : return 15102;
          case 2300 : return 18793;
          case 2350 : return 30487;
          case 2400 : return 18890;
          case 2450 : return 18948;
          case 2500 : return 17768;
          case 2550 : return 15235;
          case 2575 : return 11379;
          case 2590 : return 17683;
      }
    }
      if (a==2650) {
        switch (b) {
          case 127 : return 28021;
          case 150 : return 21898;
          case 175 : return 21775;
          case 200 : return 16748;
          case 300 : return 15266;
          case 400 : return 24416;
          case 500 : return 19464;
          case 600 : return 21833;
          case 700 : return 21728;
          case 800 : return 28298;
          case 900 : return 30780;
          case 1000 : return 17933;
          case 1100 : return 28254;
          case 1200 : return 27094;
          case 1300 : return 19293;
          case 1400 : return 18075;
          case 1500 : return 28236;
          case 1600 : return 12964;
          case 1700 : return 15451;
          case 1800 : return 20550;
          case 1900 : return 24249;
          case 2000 : return 17858;
          case 2100 : return 28117;
          case 2200 : return 15323;
          case 2300 : return 12908;
          case 2350 : return 12711;
          case 2400 : return 14076;
          case 2450 : return 10217;
          case 2500 : return 20525;
          case 2550 : return 15419;
          case 2600 : return 25473;
          case 2625 : return 22053;
          case 2640 : return 21710;
      }
    }
      if (a==2700) {
        switch (b) {
          case 127 : return 23316;
          case 150 : return 23199;
          case 175 : return 15414;
          case 200 : return 15397;
          case 300 : return 18086;
          case 400 : return 24797;
          case 500 : return 37649;
          case 600 : return 24658;
          case 700 : return 21989;
          case 800 : return 21970;
          case 900 : return 15533;
          case 1000 : return 24856;
          case 1100 : return 17965;
          case 1200 : return 10400;
          case 1300 : return 16680;
          case 1400 : return 23103;
          case 1500 : return 14365;
          case 1600 : return 20651;
          case 1700 : return 15544;
          case 1800 : return 16894;
          case 1900 : return 16768;
          case 2000 : return 17966;
          case 2100 : return 27162;
          case 2200 : return 18152;
          case 2300 : return 18240;
          case 2400 : return 16820;
          case 2450 : return 29844;
          case 2500 : return 24830;
          case 2550 : return 11692;
          case 2600 : return 15674;
          case 2650 : return 20794;
          case 2675 : return 18091;
          case 2690 : return 30879;
      }
    }
      if (a==2750) {
        switch (b) {
          case 127 : return 26273;
          case 150 : return 13167;
          case 175 : return 17131;
          case 200 : return 18395;
          case 300 : return 26214;
          case 400 : return 15720;
          case 500 : return 21180;
          case 600 : return 24967;
          case 700 : return 15778;
          case 800 : return 23547;
          case 900 : return 19638;
          case 1000 : return 32800;
          case 1100 : return 19788;
          case 1200 : return 20913;
          case 1300 : return 15675;
          case 1400 : return 26161;
          case 1500 : return 21084;
          case 1600 : return 16989;
          case 1700 : return 25010;
          case 1800 : return 27635;
          case 1900 : return 31471;
          case 2000 : return 17028;
          case 2100 : return 16907;
          case 2200 : return 27671;
          case 2300 : return 19605;
          case 2400 : return 7804;
          case 2450 : return 13102;
          case 2500 : return 22349;
          case 2550 : return 13089;
          case 2600 : return 22254;
          case 2650 : return 9130;
          case 2700 : return 14491;
          case 2725 : return 12964;
          case 2740 : return 22203;
      }
    }
      if (a==2800) {
        switch (b) {
          case 127 : return 19857;
          case 150 : return 18527;
          case 175 : return 28897;
          case 200 : return 22651;
          case 300 : return 19739;
          case 400 : return 29280;
          case 500 : return 16017;
          case 600 : return 18532;
          case 700 : return 17227;
          case 800 : return 16074;
          case 900 : return 25060;
          case 1000 : return 21120;
          case 1100 : return 14660;
          case 1200 : return 27674;
          case 1300 : return 18470;
          case 1400 : return 22591;
          case 1500 : return 33023;
          case 1600 : return 30488;
          case 1700 : return 23983;
          case 1800 : return 19866;
          case 1900 : return 17252;
          case 2000 : return 25131;
          case 2100 : return 26458;
          case 2200 : return 25235;
          case 2300 : return 31553;
          case 2400 : return 17198;
          case 2500 : return 13416;
          case 2550 : return 15790;
          case 2600 : return 22554;
          case 2650 : return 26256;
          case 2700 : return 20039;
          case 2750 : return 18637;
          case 2775 : return 14349;
          case 2790 : return 20053;
      }
    }
      break;
      case 2018 :
      if (a==800) {
        switch (b) {
          case 127 : return 257032;
          case 200 : return 243699;
          case 300 : return 231244;
          case 400 : return 267999;
          case 500 : return 284276;
          case 600 : return 256765;
          case 700 : return 273841;
          case 790 : return 259304;
      }
    }
      if (a==900) {
        switch (b) {
          case 127 : return 253985;
          case 200 : return 243267;
          case 300 : return 288544;
          case 400 : return 265875;
          case 500 : return 256835;
          case 600 : return 260319;
          case 700 : return 249054;
          case 800 : return 257125;
          case 890 : return 239015;
      }
    }
      if (a==1000) {
        switch (b) {
          case 127 : return 269914;
          case 150 : return 288000;
          case 175 : return 263744;
          case 200 : return 291072;
          case 300 : return 248400;
          case 400 : return 267455;
          case 500 : return 271012;
          case 600 : return 253394;
          case 700 : return 231793;
          case 750 : return 242840;
          case 800 : return 248774;
          case 850 : return 258494;
          case 900 : return 257449;
          case 950 : return 265746;
          case 975 : return 248963;
          case 990 : return 245572;
      }
    }
      if (a==1050) {
        switch (b) {
          case 127 : return 245640;
          case 150 : return 263327;
          case 175 : return 225957;
          case 200 : return 256270;
          case 300 : return 252587;
          case 400 : return 261302;
          case 500 : return 271906;
          case 600 : return 259324;
          case 700 : return 269216;
          case 750 : return 278666;
          case 800 : return 255195;
          case 850 : return 252606;
          case 900 : return 259535;
          case 950 : return 265839;
          case 1000 : return 261837;
          case 1025 : return 267853;
          case 1040 : return 266802;
      }
    }
      if (a==1100) {
        switch (b) {
          case 127 : return 232431;
          case 150 : return 219045;
          case 175 : return 221337;
          case 200 : return 237395;
          case 300 : return 233694;
          case 400 : return 232834;
          case 500 : return 228786;
          case 600 : return 247950;
          case 700 : return 234416;
          case 800 : return 218375;
          case 850 : return 220450;
          case 900 : return 220655;
          case 950 : return 234277;
          case 1000 : return 214092;
          case 1050 : return 224114;
          case 1075 : return 213579;
          case 1090 : return 238620;
      }
    }
      if (a==1150) {
        switch (b) {
          case 127 : return 176592;
          case 150 : return 167204;
          case 175 : return 180714;
          case 200 : return 156586;
          case 300 : return 161123;
          case 400 : return 187543;
          case 500 : return 173449;
          case 600 : return 159296;
          case 700 : return 153725;
          case 800 : return 168696;
          case 850 : return 173348;
          case 900 : return 156896;
          case 950 : return 157704;
          case 1000 : return 142428;
          case 1050 : return 179877;
          case 1100 : return 151930;
          case 1125 : return 131078;
          case 1140 : return 154353;
      }
    }
      if (a==1200) {
        switch (b) {
          case 127 : return 116221;
          case 150 : return 114455;
          case 175 : return 149582;
          case 200 : return 130127;
          case 300 : return 125499;
          case 400 : return 118485;
          case 500 : return 109504;
          case 600 : return 99442;
          case 700 : return 126028;
          case 800 : return 127335;
          case 900 : return 100400;
          case 950 : return 116661;
          case 1000 : return 117504;
          case 1050 : return 113703;
          case 1100 : return 106849;
          case 1150 : return 120841;
          case 1175 : return 123799;
          case 1190 : return 113721;
      }
    }
      if (a==1250) {
        switch (b) {
          case 127 : return 92316;
          case 150 : return 91950;
          case 175 : return 82797;
          case 200 : return 85223;
          case 300 : return 95341;
          case 400 : return 87391;
          case 500 : return 95414;
          case 600 : return 85455;
          case 700 : return 76007;
          case 800 : return 86104;
          case 900 : return 81053;
          case 950 : return 76640;
          case 1000 : return 67395;
          case 1050 : return 88005;
          case 1100 : return 87472;
          case 1150 : return 78095;
          case 1200 : return 80939;
          case 1225 : return 87025;
          case 1240 : return 82809;
      }
    }
      if (a==1300) {
        switch (b) {
          case 127 : return 78824;
          case 150 : return 60319;
          case 175 : return 80757;
          case 200 : return 73163;
          case 300 : return 74658;
          case 400 : return 73497;
          case 500 : return 68908;
          case 600 : return 74212;
          case 700 : return 50697;
          case 800 : return 78519;
          case 900 : return 81251;
          case 1000 : return 59919;
          case 1050 : return 67112;
          case 1100 : return 60742;
          case 1150 : return 64250;
          case 1200 : return 68284;
          case 1250 : return 57861;
          case 1275 : return 80013;
          case 1290 : return 66025;
      }
    }
      if (a==1350) {
        switch (b) {
          case 127 : return 69694;
          case 150 : return 83233;
          case 175 : return 62035;
          case 200 : return 47661;
          case 300 : return 70665;
          case 400 : return 61376;
          case 500 : return 70230;
          case 600 : return 55611;
          case 700 : return 61048;
          case 800 : return 64825;
          case 900 : return 57547;
          case 1000 : return 64660;
          case 1050 : return 56200;
          case 1100 : return 71067;
          case 1150 : return 75083;
          case 1200 : return 53907;
          case 1250 : return 58429;
          case 1300 : return 76337;
          case 1325 : return 84393;
          case 1340 : return 67787;
      }
    }
      if (a==1400) {
        switch (b) {
          case 127 : return 69229;
          case 150 : return 75493;
          case 175 : return 75503;
          case 200 : return 69347;
          case 300 : return 65563;
          case 400 : return 80844;
          case 500 : return 58451;
          case 600 : return 64652;
          case 700 : return 74031;
          case 800 : return 76926;
          case 900 : return 48809;
          case 1000 : return 56931;
          case 1100 : return 78072;
          case 1150 : return 72753;
          case 1200 : return 67247;
          case 1250 : return 66514;
          case 1300 : return 69103;
          case 1350 : return 62992;
          case 1375 : return 61962;
          case 1390 : return 64248;
      }
    }
      if (a==1450) {
        switch (b) {
          case 127 : return 69101;
          case 150 : return 86512;
          case 175 : return 68972;
          case 200 : return 62652;
          case 300 : return 52825;
          case 400 : return 84204;
          case 500 : return 62523;
          case 600 : return 65580;
          case 700 : return 66366;
          case 800 : return 62265;
          case 900 : return 60377;
          case 1000 : return 63736;
          case 1100 : return 60258;
          case 1150 : return 67153;
          case 1200 : return 42564;
          case 1250 : return 59900;
          case 1300 : return 72828;
          case 1350 : return 81177;
          case 1400 : return 77818;
          case 1425 : return 75269;
          case 1440 : return 58200;
      }
    }
      if (a==1500) {
        switch (b) {
          case 127 : return 47677;
          case 150 : return 55276;
          case 175 : return 71001;
          case 200 : return 82531;
          case 300 : return 89914;
          case 400 : return 62995;
          case 500 : return 63831;
          case 600 : return 62361;
          case 700 : return 67327;
          case 800 : return 68761;
          case 900 : return 73638;
          case 1000 : return 77361;
          case 1100 : return 68926;
          case 1200 : return 65165;
          case 1250 : return 59310;
          case 1300 : return 65384;
          case 1350 : return 55533;
          case 1400 : return 55536;
          case 1450 : return 61429;
          case 1475 : return 54255;
          case 1490 : return 65791;
      }
    }
      if (a==1550) {
        switch (b) {
          case 127 : return 78258;
          case 150 : return 62941;
          case 175 : return 66496;
          case 200 : return 60954;
          case 300 : return 58084;
          case 400 : return 54112;
          case 500 : return 63003;
          case 600 : return 71615;
          case 700 : return 67690;
          case 800 : return 70762;
          case 900 : return 55868;
          case 1000 : return 57070;
          case 1100 : return 69551;
          case 1200 : return 67801;
          case 1250 : return 66411;
          case 1300 : return 63984;
          case 1350 : return 65847;
          case 1400 : return 58353;
          case 1450 : return 71336;
          case 1500 : return 73588;
          case 1525 : return 67455;
          case 1540 : return 51969;
      }
    }
      if (a==1600) {
        switch (b) {
          case 127 : return 58342;
          case 150 : return 65273;
          case 175 : return 70015;
          case 200 : return 62438;
          case 300 : return 63430;
          case 400 : return 68189;
          case 500 : return 53586;
          case 600 : return 64561;
          case 700 : return 63298;
          case 800 : return 68223;
          case 900 : return 73049;
          case 1000 : return 49752;
          case 1100 : return 59536;
          case 1200 : return 64538;
          case 1300 : return 57806;
          case 1350 : return 57393;
          case 1400 : return 60570;
          case 1450 : return 55814;
          case 1500 : return 64327;
          case 1550 : return 64887;
          case 1575 : return 71075;
          case 1590 : return 56231;
      }
    }
      if (a==1650) {
        switch (b) {
          case 127 : return 66062;
          case 150 : return 61158;
          case 175 : return 63174;
          case 200 : return 68295;
          case 300 : return 63010;
          case 400 : return 57521;
          case 500 : return 65271;
          case 600 : return 63241;
          case 700 : return 66041;
          case 800 : return 56300;
          case 900 : return 84645;
          case 1000 : return 83963;
          case 1100 : return 64303;
          case 1200 : return 73433;
          case 1300 : return 82789;
          case 1350 : return 64443;
          case 1400 : return 62480;
          case 1450 : return 52524;
          case 1500 : return 59466;
          case 1550 : return 53399;
          case 1600 : return 42366;
          case 1625 : return 45483;
          case 1640 : return 61950;
      }
    }
      if (a==1700) {
        switch (b) {
          case 127 : return 66942;
          case 150 : return 71213;
          case 175 : return 71010;
          case 200 : return 69028;
          case 300 : return 94895;
          case 400 : return 79905;
          case 500 : return 67173;
          case 600 : return 77730;
          case 700 : return 59175;
          case 800 : return 81814;
          case 900 : return 72780;
          case 1000 : return 74903;
          case 1100 : return 76392;
          case 1200 : return 61606;
          case 1300 : return 63094;
          case 1400 : return 65014;
          case 1450 : return 65955;
          case 1500 : return 84801;
          case 1550 : return 74346;
          case 1600 : return 70940;
          case 1650 : return 72457;
          case 1675 : return 59768;
          case 1690 : return 58961;
      }
    }
      if (a==1750) {
        switch (b) {
          case 127 : return 71172;
          case 150 : return 78736;
          case 175 : return 75989;
          case 200 : return 74298;
          case 300 : return 73076;
          case 400 : return 72825;
          case 500 : return 65868;
          case 600 : return 69047;
          case 700 : return 71055;
          case 800 : return 71003;
          case 900 : return 73680;
          case 1000 : return 64274;
          case 1100 : return 61694;
          case 1200 : return 75133;
          case 1300 : return 69024;
          case 1400 : return 54943;
          case 1450 : return 78274;
          case 1500 : return 57820;
          case 1550 : return 53605;
          case 1600 : return 51277;
          case 1650 : return 43570;
          case 1700 : return 57682;
          case 1725 : return 74971;
          case 1740 : return 58722;
      }
    }
      if (a==1800) {
        switch (b) {
          case 127 : return 73944;
          case 150 : return 58703;
          case 175 : return 65743;
          case 200 : return 67744;
          case 300 : return 51531;
          case 400 : return 62713;
          case 500 : return 65897;
          case 600 : return 62383;
          case 700 : return 74864;
          case 800 : return 66451;
          case 900 : return 73736;
          case 1000 : return 57224;
          case 1100 : return 58280;
          case 1200 : return 68696;
          case 1300 : return 62820;
          case 1400 : return 55559;
          case 1500 : return 54441;
          case 1550 : return 54431;
          case 1600 : return 69867;
          case 1650 : return 59406;
          case 1700 : return 57890;
          case 1750 : return 55543;
          case 1775 : return 66784;
          case 1790 : return 50331;
      }
    }
      if (a==1850) {
        switch (b) {
          case 127 : return 66539;
          case 150 : return 62318;
          case 175 : return 79233;
          case 200 : return 72714;
          case 300 : return 66466;
          case 400 : return 66320;
          case 500 : return 69873;
          case 600 : return 71537;
          case 700 : return 51213;
          case 800 : return 64491;
          case 900 : return 55099;
          case 1000 : return 76928;
          case 1100 : return 75695;
          case 1200 : return 66801;
          case 1300 : return 56406;
          case 1400 : return 63703;
          case 1500 : return 58532;
          case 1550 : return 56076;
          case 1600 : return 67542;
          case 1650 : return 44906;
          case 1700 : return 64372;
          case 1750 : return 55067;
          case 1800 : return 60769;
          case 1825 : return 57640;
          case 1840 : return 54894;
      }
    }
      if (a==1900) {
        switch (b) {
          case 127 : return 54069;
          case 150 : return 68456;
          case 175 : return 72812;
          case 200 : return 72795;
          case 300 : return 62408;
          case 400 : return 61260;
          case 500 : return 72529;
          case 600 : return 69726;
          case 700 : return 61258;
          case 800 : return 62189;
          case 900 : return 64108;
          case 1000 : return 73541;
          case 1100 : return 57009;
          case 1200 : return 56219;
          case 1300 : return 57759;
          case 1400 : return 57663;
          case 1500 : return 60909;
          case 1600 : return 62005;
          case 1650 : return 54921;
          case 1700 : return 62167;
          case 1750 : return 52752;
          case 1800 : return 50979;
          case 1850 : return 63588;
          case 1875 : return 56872;
          case 1890 : return 72387;
      }
    }
      if (a==1950) {
        switch (b) {
          case 127 : return 66185;
          case 150 : return 78812;
          case 175 : return 55456;
          case 200 : return 54719;
          case 300 : return 67565;
          case 400 : return 70668;
          case 500 : return 70620;
          case 600 : return 65407;
          case 700 : return 70782;
          case 800 : return 68433;
          case 900 : return 55698;
          case 1000 : return 82692;
          case 1100 : return 68411;
          case 1200 : return 58816;
          case 1300 : return 46756;
          case 1400 : return 52642;
          case 1500 : return 65074;
          case 1600 : return 50125;
          case 1650 : return 58578;
          case 1700 : return 63352;
          case 1750 : return 58111;
          case 1800 : return 62953;
          case 1850 : return 60715;
          case 1900 : return 64522;
          case 1925 : return 64270;
          case 1940 : return 73366;
      }
    }
      if (a==2000) {
        switch (b) {
          case 127 : return 37954;
          case 150 : return 32563;
          case 175 : return 29456;
          case 200 : return 34724;
          case 300 : return 30163;
          case 400 : return 32530;
          case 500 : return 39959;
          case 600 : return 29182;
          case 700 : return 37936;
          case 800 : return 41819;
          case 900 : return 42233;
          case 1000 : return 32212;
          case 1100 : return 31685;
          case 1200 : return 31363;
          case 1300 : return 32765;
          case 1400 : return 32666;
          case 1500 : return 29186;
          case 1600 : return 34734;
          case 1700 : return 29267;
          case 1750 : return 31377;
          case 1800 : return 15139;
          case 1850 : return 28119;
          case 1900 : return 28069;
          case 1950 : return 28090;
          case 1975 : return 24115;
          case 1990 : return 35935;
      }
    }
      if (a==2050) {
        switch (b) {
          case 127 : return 34931;
          case 150 : return 30770;
          case 175 : return 30871;
          case 200 : return 38463;
          case 300 : return 32866;
          case 400 : return 25220;
          case 500 : return 36353;
          case 600 : return 37380;
          case 700 : return 29621;
          case 800 : return 25348;
          case 900 : return 26381;
          case 1000 : return 25371;
          case 1100 : return 22024;
          case 1200 : return 31776;
          case 1300 : return 31813;
          case 1400 : return 41624;
          case 1500 : return 30496;
          case 1600 : return 42650;
          case 1700 : return 25333;
          case 1750 : return 38558;
          case 1800 : return 30991;
          case 1850 : return 35063;
          case 1900 : return 39585;
          case 1950 : return 24267;
          case 2000 : return 32937;
          case 2025 : return 27376;
          case 2040 : return 26318;
      }
    }
      if (a==2100) {
        switch (b) {
          case 127 : return 30112;
          case 150 : return 28866;
          case 175 : return 28982;
          case 200 : return 40201;
          case 300 : return 41076;
          case 400 : return 31324;
          case 500 : return 22267;
          case 600 : return 27887;
          case 700 : return 35535;
          case 800 : return 29981;
          case 900 : return 35494;
          case 1000 : return 34541;
          case 1100 : return 23369;
          case 1200 : return 34247;
          case 1300 : return 35745;
          case 1400 : return 29047;
          case 1500 : return 36693;
          case 1600 : return 18909;
          case 1700 : return 16687;
          case 1800 : return 24474;
          case 1850 : return 27876;
          case 1900 : return 28730;
          case 1950 : return 31201;
          case 2000 : return 19048;
          case 2050 : return 25710;
          case 2075 : return 31291;
          case 2090 : return 25499;
      }
    }
      if (a==2150) {
        switch (b) {
          case 127 : return 30680;
          case 150 : return 31561;
          case 175 : return 31562;
          case 200 : return 31393;
          case 300 : return 26155;
          case 400 : return 41838;
          case 500 : return 30654;
          case 600 : return 47058;
          case 700 : return 33950;
          case 800 : return 25021;
          case 900 : return 30472;
          case 1000 : return 33855;
          case 1100 : return 20109;
          case 1200 : return 28098;
          case 1300 : return 36134;
          case 1400 : return 29157;
          case 1500 : return 31876;
          case 1600 : return 32780;
          case 1700 : return 27342;
          case 1800 : return 30515;
          case 1850 : return 27045;
          case 1900 : return 30556;
          case 1950 : return 23814;
          case 2000 : return 36007;
          case 2050 : return 25072;
          case 2100 : return 20179;
          case 2125 : return 29333;
          case 2140 : return 29117;
      }
    }
      if (a==2200) {
        switch (b) {
          case 127 : return 35380;
          case 150 : return 33130;
          case 175 : return 32029;
          case 200 : return 43562;
          case 300 : return 27543;
          case 400 : return 25109;
          case 500 : return 32092;
          case 600 : return 28613;
          case 700 : return 20592;
          case 800 : return 26335;
          case 900 : return 32157;
          case 1000 : return 36530;
          case 1100 : return 42479;
          case 1200 : return 36721;
          case 1300 : return 36631;
          case 1400 : return 31191;
          case 1500 : return 17106;
          case 1600 : return 27476;
          case 1700 : return 36557;
          case 1800 : return 32456;
          case 1900 : return 31002;
          case 1950 : return 24023;
          case 2000 : return 30063;
          case 2050 : return 28603;
          case 2100 : return 21672;
          case 2150 : return 28601;
          case 2175 : return 18230;
          case 2190 : return 21877;
      }
    }
      if (a==2250) {
        switch (b) {
          case 127 : return 24314;
          case 150 : return 35865;
          case 175 : return 28947;
          case 200 : return 27779;
          case 300 : return 31239;
          case 400 : return 32525;
          case 500 : return 22058;
          case 600 : return 34919;
          case 700 : return 25355;
          case 800 : return 33612;
          case 900 : return 22259;
          case 1000 : return 25433;
          case 1100 : return 30045;
          case 1200 : return 38321;
          case 1300 : return 27910;
          case 1400 : return 38430;
          case 1500 : return 35709;
          case 1600 : return 29002;
          case 1700 : return 24408;
          case 1800 : return 44053;
          case 1900 : return 28919;
          case 1950 : return 27842;
          case 2000 : return 44297;
          case 2050 : return 18677;
          case 2100 : return 34804;
          case 2150 : return 34715;
          case 2200 : return 25565;
          case 2225 : return 31489;
          case 2240 : return 33796;
      }
    }
      if (a==2300) {
        switch (b) {
          case 127 : return 32704;
          case 150 : return 34213;
          case 175 : return 27149;
          case 200 : return 37675;
          case 300 : return 31674;
          case 400 : return 33211;
          case 500 : return 18755;
          case 600 : return 28140;
          case 700 : return 37709;
          case 800 : return 27178;
          case 900 : return 25830;
          case 1000 : return 39993;
          case 1100 : return 32865;
          case 1200 : return 39886;
          case 1300 : return 30619;
          case 1400 : return 34092;
          case 1500 : return 32898;
          case 1600 : return 24556;
          case 1700 : return 32986;
          case 1800 : return 24740;
          case 1900 : return 19683;
          case 2000 : return 23623;
          case 2050 : return 35531;
          case 2100 : return 28288;
          case 2150 : return 31622;
          case 2200 : return 37397;
          case 2250 : return 24691;
          case 2275 : return 38751;
          case 2290 : return 33944;
      }
    }
      if (a==2350) {
        switch (b) {
          case 127 : return 32104;
          case 150 : return 39310;
          case 175 : return 32199;
          case 200 : return 31152;
          case 300 : return 28499;
          case 400 : return 27305;
          case 500 : return 32123;
          case 600 : return 23832;
          case 700 : return 26400;
          case 800 : return 28561;
          case 900 : return 34643;
          case 1000 : return 29814;
          case 1100 : return 23784;
          case 1200 : return 29549;
          case 1300 : return 26282;
          case 1400 : return 35660;
          case 1500 : return 38164;
          case 1600 : return 27491;
          case 1700 : return 28290;
          case 1800 : return 26095;
          case 1900 : return 30798;
          case 2000 : return 32053;
          case 2050 : return 24930;
          case 2100 : return 19019;
          case 2150 : return 26334;
          case 2200 : return 20370;
          case 2250 : return 28678;
          case 2300 : return 35706;
          case 2325 : return 23841;
          case 2340 : return 28359;
      }
    }
      if (a==2400) {
        switch (b) {
          case 127 : return 37476;
          case 150 : return 33711;
          case 175 : return 32820;
          case 200 : return 37255;
          case 300 : return 30236;
          case 400 : return 36201;
          case 500 : return 26479;
          case 600 : return 32750;
          case 700 : return 27687;
          case 800 : return 41060;
          case 900 : return 25418;
          case 1000 : return 33953;
          case 1100 : return 33713;
          case 1200 : return 25490;
          case 1300 : return 27760;
          case 1400 : return 30151;
          case 1500 : return 31482;
          case 1600 : return 20450;
          case 1700 : return 26497;
          case 1800 : return 30052;
          case 1900 : return 25331;
          case 2000 : return 21871;
          case 2100 : return 20717;
          case 2150 : return 41051;
          case 2200 : return 24163;
          case 2250 : return 13337;
          case 2300 : return 29293;
          case 2350 : return 24222;
          case 2375 : return 21667;
          case 2390 : return 27843;
      }
    }
      if (a==2450) {
        switch (b) {
          case 127 : return 31788;
          case 150 : return 21900;
          case 175 : return 33985;
          case 200 : return 11075;
          case 300 : return 23302;
          case 400 : return 29547;
          case 500 : return 23327;
          case 600 : return 29984;
          case 700 : return 38804;
          case 800 : return 26833;
          case 900 : return 29453;
          case 1000 : return 34158;
          case 1100 : return 36299;
          case 1200 : return 36593;
          case 1300 : return 37676;
          case 1400 : return 19419;
          case 1500 : return 30657;
          case 1600 : return 26837;
          case 1700 : return 29296;
          case 1800 : return 35363;
          case 1900 : return 27124;
          case 2000 : return 25806;
          case 2100 : return 27028;
          case 2150 : return 32024;
          case 2200 : return 32754;
          case 2250 : return 32778;
          case 2300 : return 39104;
          case 2350 : return 30770;
          case 2400 : return 30617;
          case 2425 : return 24519;
          case 2440 : return 27908;
      }
    }
      if (a==2500) {
        switch (b) {
          case 127 : return 33330;
          case 150 : return 34398;
          case 175 : return 28425;
          case 200 : return 17417;
          case 300 : return 38271;
          case 400 : return 36002;
          case 500 : return 30947;
          case 600 : return 25796;
          case 700 : return 35792;
          case 800 : return 31182;
          case 900 : return 34722;
          case 1000 : return 38472;
          case 1100 : return 38083;
          case 1200 : return 28362;
          case 1300 : return 34638;
          case 1400 : return 31948;
          case 1500 : return 23309;
          case 1600 : return 23407;
          case 1700 : return 29901;
          case 1800 : return 29806;
          case 1900 : return 23364;
          case 2000 : return 30970;
          case 2100 : return 28535;
          case 2200 : return 27245;
          case 2250 : return 18649;
          case 2300 : return 23515;
          case 2350 : return 22325;
          case 2400 : return 33112;
          case 2450 : return 30845;
          case 2475 : return 23686;
          case 2490 : return 33252;
      }
    }
      if (a==2550) {
        switch (b) {
          case 127 : return 24932;
          case 150 : return 32530;
          case 175 : return 36450;
          case 200 : return 30169;
          case 300 : return 26226;
          case 400 : return 30060;
          case 500 : return 35065;
          case 600 : return 27576;
          case 700 : return 23633;
          case 800 : return 22425;
          case 900 : return 33974;
          case 1000 : return 23554;
          case 1100 : return 46417;
          case 1200 : return 29855;
          case 1300 : return 27536;
          case 1400 : return 36259;
          case 1500 : return 39870;
          case 1600 : return 41289;
          case 1700 : return 27534;
          case 1800 : return 29977;
          case 1900 : return 22641;
          case 2000 : return 19993;
          case 2100 : return 38628;
          case 2200 : return 24982;
          case 2250 : return 31241;
          case 2300 : return 38861;
          case 2350 : return 22769;
          case 2400 : return 32317;
          case 2450 : return 27614;
          case 2500 : return 23900;
          case 2525 : return 17462;
          case 2540 : return 19938;
      }
    }
      if (a==2600) {
        switch (b) {
          case 127 : return 33954;
          case 150 : return 23921;
          case 175 : return 20287;
          case 200 : return 26505;
          case 300 : return 29040;
          case 400 : return 29098;
          case 500 : return 30187;
          case 600 : return 24029;
          case 700 : return 32817;
          case 800 : return 31710;
          case 900 : return 24207;
          case 1000 : return 25323;
          case 1100 : return 23907;
          case 1200 : return 30489;
          case 1300 : return 34216;
          case 1400 : return 25425;
          case 1500 : return 26735;
          case 1600 : return 32865;
          case 1700 : return 23990;
          case 1800 : return 28952;
          case 1900 : return 39094;
          case 2000 : return 20125;
          case 2100 : return 22609;
          case 2200 : return 13925;
          case 2300 : return 36565;
          case 2350 : return 22742;
          case 2400 : return 22814;
          case 2450 : return 25346;
          case 2500 : return 22744;
          case 2550 : return 31667;
          case 2575 : return 32872;
          case 2590 : return 35400;
      }
    }
      if (a==2650) {
        switch (b) {
          case 127 : return 29554;
          case 150 : return 28093;
          case 175 : return 30683;
          case 200 : return 30681;
          case 300 : return 49854;
          case 400 : return 28046;
          case 500 : return 46323;
          case 600 : return 33189;
          case 700 : return 33140;
          case 800 : return 38527;
          case 900 : return 33401;
          case 1000 : return 15279;
          case 1100 : return 37147;
          case 1200 : return 30789;
          case 1300 : return 30970;
          case 1400 : return 33490;
          case 1500 : return 42431;
          case 1600 : return 34556;
          case 1700 : return 30726;
          case 1800 : return 30649;
          case 1900 : return 34573;
          case 2000 : return 33284;
          case 2100 : return 22988;
          case 2200 : return 34429;
          case 2300 : return 17840;
          case 2350 : return 23154;
          case 2400 : return 29443;
          case 2450 : return 24230;
          case 2500 : return 24302;
          case 2550 : return 26809;
          case 2600 : return 15324;
          case 2625 : return 34438;
          case 2640 : return 21647;
      }
    }
      if (a==2700) {
        switch (b) {
          case 127 : return 46229;
          case 150 : return 28439;
          case 175 : return 34978;
          case 200 : return 30046;
          case 300 : return 32394;
          case 400 : return 29908;
          case 500 : return 33501;
          case 600 : return 29891;
          case 700 : return 31236;
          case 800 : return 20753;
          case 900 : return 24342;
          case 1000 : return 34921;
          case 1100 : return 23333;
          case 1200 : return 25933;
          case 1300 : return 32541;
          case 1400 : return 33794;
          case 1500 : return 20715;
          case 1600 : return 34864;
          case 1700 : return 33729;
          case 1800 : return 20731;
          case 1900 : return 15761;
          case 2000 : return 29746;
          case 2100 : return 32362;
          case 2200 : return 20691;
          case 2300 : return 19508;
          case 2400 : return 39053;
          case 2450 : return 31110;
          case 2500 : return 25938;
          case 2550 : return 27128;
          case 2600 : return 25911;
          case 2650 : return 23374;
          case 2675 : return 25917;
          case 2690 : return 35011;
      }
    }
      if (a==2750) {
        switch (b) {
          case 127 : return 29889;
          case 150 : return 28805;
          case 175 : return 24649;
          case 200 : return 38120;
          case 300 : return 40569;
          case 400 : return 31268;
          case 500 : return 35184;
          case 600 : return 28959;
          case 700 : return 32907;
          case 800 : return 31481;
          case 900 : return 39420;
          case 1000 : return 18418;
          case 1100 : return 30241;
          case 1200 : return 27646;
          case 1300 : return 27521;
          case 1400 : return 35067;
          case 1500 : return 30010;
          case 1600 : return 23541;
          case 1700 : return 39345;
          case 1800 : return 27494;
          case 1900 : return 25095;
          case 2000 : return 19651;
          case 2100 : return 27528;
          case 2200 : return 22337;
          case 2300 : return 22210;
          case 2400 : return 28741;
          case 2450 : return 26223;
          case 2500 : return 23497;
          case 2550 : return 19773;
          case 2600 : return 32853;
          case 2650 : return 26195;
          case 2700 : return 27506;
          case 2725 : return 26158;
          case 2740 : return 18371;
      }
    }
      if (a==2800) {
        switch (b) {
          case 127 : return 31638;
          case 150 : return 34431;
          case 175 : return 25271;
          case 200 : return 22267;
          case 300 : return 26376;
          case 400 : return 23878;
          case 500 : return 34491;
          case 600 : return 22565;
          case 700 : return 25144;
          case 800 : return 38588;
          case 900 : return 37044;
          case 1000 : return 26366;
          case 1100 : return 39559;
          case 1200 : return 38455;
          case 1300 : return 45195;
          case 1400 : return 21143;
          case 1500 : return 23758;
          case 1600 : return 32968;
          case 1700 : return 37154;
          case 1800 : return 22552;
          case 1900 : return 33225;
          case 2000 : return 30404;
          case 2100 : return 22432;
          case 2200 : return 34527;
          case 2300 : return 25056;
          case 2400 : return 21147;
          case 2500 : return 28933;
          case 2550 : return 19716;
          case 2600 : return 26888;
          case 2650 : return 22628;
          case 2700 : return 30477;
          case 2750 : return 26393;
          case 2775 : return 26245;
          case 2790 : return 13253;
      }
    }
      break;
    }
  }
  if (SignalScenario==2) {
    if (year==2016) { 
      switch (a) {
        case 300 : return 95627;
        case 325 : return 98593;
        case 350 : return 93916;
        case 375 : return 95932;
        case 400 : return 105424;
        case 425 : return 103170;
        case 450 : return 95823;
        case 475 : return 97048;
        case 500 : return 101161;
        case 525 : return 93220;
        case 550 : return 94616;
        case 575 : return 92720;
        case 600 : return 98954;
        case 625 : return 101490;
        case 650 : return 96751;
        case 675 : return 101820;
        case 700 : return 103522;
        case 725 : return 101940;
        case 750 : return 96260;
        case 775 : return 99207;
        case 800 : return 100133;
        case 825 : return 103021;
        case 850 : return 97301;
        case 875 : return 99278;
        case 900 : return 102816;
        case 925 : return 92994;
        case 950 : return 92593;
        case 975 : return 102253;
        case 1000 : return 96316;
        case 1025 : return 98272;
        case 1050 : return 100374;
        case 1075 : return 93754;
        case 1100 : return 90490;
        case 1125 : return 99548;
        case 1150 : return 96008;
        case 1175 : return 101310;
        case 1200 : return 100911;
        case 1225 : return 93150;
        case 1250 : return 102314;
        case 1275 : return 100963;
        case 1300 : return 102543;
        case 1325 : return 97836;
        case 1350 : return 93576;
        case 1375 : return 93014;
        case 1400 : return 107195;
        case 1425 : return 93140;
        case 1450 : return 98076;
        case 1475 : return 94828;
        case 1500 : return 98865;
        case 1525 : return 105347;
        case 1550 : return 99663;
        case 1575 : return 101730;
        case 1600 : return 102066;
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
  if (SignalScenario==3) {
    switch (year) {
      case 2016 :
      if (a==1800) {
        switch (b) {
          case 127 : return 41134;
          case 200 : return 40163;
        }
      }
      if (a==2200) {
        switch (b) {
          case 1000 : return 15989;
          case 2100 : return 22199;
          case 2190 : return 19984;
        }
      }
      case 2017 :
      if (a==1800) {
        switch (b) {
          case 127 : return 37444;
          case 200 : return 39328;
        }
      }
      if (a==2200) {
        switch (b) {
          case 1000 : return 19836;
          case 2100 : return 23072;
          case 2190 : return 18587;
        }
      }
      case 2018 :
      if (a==1800) {
        switch (b) {
          case 127 : return 68282;
          case 200 : return 66069;
        }
      }
      if (a==2200) {
        switch (b) {
          case 1000 : return 39850;
          case 2100 : return 39874;
          case 2190 : return 39972;
        }
      }
      break;
    }
  }
  return 0;
}

std::map<pair<int,int>,int> init_signal_event(int SignalScenario) {
  std::map<pair<int,int>,int> output;
  if (SignalScenario==1 || SignalScenario==4) {
    std::vector<int> Yticks;
    Yticks =  std::vector<int>({127, 200, 300, 400, 500, 600, 700, 790});
    for (auto i : Yticks) {pair<int,int> p(800,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 200, 300, 400, 500, 600, 700, 800, 890}); 
    for (auto i : Yticks) {pair<int,int> p(900,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 975, 990}); 
    for (auto i : Yticks) {pair<int,int> p(1000,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 750, 800, 850, 900, 950, 1000, 1025, 1040}); 
    for (auto i : Yticks) {pair<int,int> p(1050,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1075, 1090}); 
    for (auto i : Yticks) {pair<int,int> p(1100,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 850, 900, 950, 1000, 1050, 1100, 1125, 1140}); 
    for (auto i : Yticks) {pair<int,int> p(1150,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1175, 1190}); 
    for (auto i : Yticks) {pair<int,int> p(1200,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050, 1100, 1150, 1200, 1225, 1240}); 
    for (auto i : Yticks) {pair<int,int> p(1250,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1275, 1290}); 
    for (auto i : Yticks) {pair<int,int> p(1300,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1050, 1100, 1150, 1200, 1250, 1300, 1325, 1340}); 
    for (auto i : Yticks) {pair<int,int> p(1350,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1375, 1390}); 
    for (auto i : Yticks) {pair<int,int> p(1400,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1150, 1200, 1250, 1300, 1350, 1400, 1425, 1440}); 
    for (auto i : Yticks) {pair<int,int> p(1450,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1475, 1490}); 
    for (auto i : Yticks) {pair<int,int> p(1500,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1250, 1300, 1350, 1400, 1450, 1500, 1525, 1540}); 
    for (auto i : Yticks) {pair<int,int> p(1550,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1575, 1590}); 
    for (auto i : Yticks) {pair<int,int> p(1600,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1350, 1400, 1450, 1500, 1550, 1600, 1625, 1640}); 
    for (auto i : Yticks) {pair<int,int> p(1650,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1675, 1690}); 
    for (auto i : Yticks) {pair<int,int> p(1700,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1725, 1740}); 
    for (auto i : Yticks) {pair<int,int> p(1750,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1775, 1790}); 
    for (auto i : Yticks) {pair<int,int> p(1800,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1825, 1840}); 
    for (auto i : Yticks) {pair<int,int> p(1850,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1875, 1890}); 
    for (auto i : Yticks) {pair<int,int> p(1900,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1650, 1700, 1750, 1800, 1850, 1900, 1925, 1940}); 
    for (auto i : Yticks) {pair<int,int> p(1950,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 1975, 1990}); 
    for (auto i : Yticks) {pair<int,int> p(2000,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1750, 1800, 1850, 1900, 1950, 2000, 2025, 2040}); 
    for (auto i : Yticks) {pair<int,int> p(2050,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2075, 2090}); 
    for (auto i : Yticks) {pair<int,int> p(2100,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1850, 1900, 1950, 2000, 2050, 2100, 2125, 2140}); 
    for (auto i : Yticks) {pair<int,int> p(2150,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2175, 2190}); 
    for (auto i : Yticks) {pair<int,int> p(2200,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 1950, 2000, 2050, 2100, 2150, 2200, 2225, 2240}); 
    for (auto i : Yticks) {pair<int,int> p(2250,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2275, 2290}); 
    for (auto i : Yticks) {pair<int,int> p(2300,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2050, 2100, 2150, 2200, 2250, 2300, 2325, 2340}); 
    for (auto i : Yticks) {pair<int,int> p(2350,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2375, 2390}); 
    for (auto i : Yticks) {pair<int,int> p(2400,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2150, 2200, 2250, 2300, 2350, 2400, 2425, 2440}); 
    for (auto i : Yticks) {pair<int,int> p(2450,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2250, 2300, 2350, 2400, 2450, 2475, 2490});
    for (auto i : Yticks) {pair<int,int> p(2500,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2250, 2300, 2350, 2400, 2450, 2500, 2525, 2540});
    for (auto i : Yticks) {pair<int,int> p(2550,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2350, 2400, 2450, 2500, 2550, 2575, 2590});
    for (auto i : Yticks) {pair<int,int> p(2600,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2350, 2400, 2450, 2500, 2550, 2600, 2625, 2640});
    for (auto i : Yticks) {pair<int,int> p(2650,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2450, 2500, 2550, 2600, 2650, 2675, 2690});
    for (auto i : Yticks) {pair<int,int> p(2700,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2450, 2500, 2550, 2600, 2650, 2700, 2725, 2740});
    for (auto i : Yticks) {pair<int,int> p(2750,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({127, 150, 175, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2550, 2600, 2650, 2700, 2750, 2775, 2790});
    for (auto i : Yticks) {pair<int,int> p(2800,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
  }
  if (SignalScenario==2) {
    //TChiNG 300 to 1600 GeV in steps of 25 GeV.
    for (unsigned int i=0; i<53; i++) {
      int m=(300+i*25);
      pair<int,int> p(m,1);
      output.insert(pair<pair<int,int>,int>(p,0));
    }
  }
  if (SignalScenario==3) {
    std::vector<int> Yticks;
    Yticks =  std::vector<int>({127, 200});
    for (auto i : Yticks) {pair<int,int> p(1800,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
    Yticks =  std::vector<int>({1000, 2100, 2190});
    for (auto i : Yticks) {pair<int,int> p(2200,i); output.insert(pair<pair<int,int>,int>(p,0));}
    Yticks.clear();
  }
  return output;
}
#endif
