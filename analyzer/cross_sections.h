#ifndef cross_sections_h
#define cross_sections_h

//Get gluino-gluino cross section, use input of gluino mass and -1/+1 for lower/upper errors
double get_cross_section(int m_primary, int SignalScenario, int center_down_up=0) {
  if (SignalScenario==1) {
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
  if (SignalScenario==1) {
    switch (year) {
      case 2016 :
      if (a==800) {
        switch (b) {
          case 127 : return 147015;
          case 200 : return 142321;
          case 300 : return 138796;
          case 400 : return 136379;
          case 500 : return 138946;
          case 600 : return 143811;
          case 700 : return 139064;
          case 790 : return 135319;
        }
      }
      if (a==900) {
        switch (b) {
          case 127 : return 136763;
          case 200 : return 135312;
          case 300 : return 141276;
          case 400 : return 137781;
          case 500 : return 138691;
          case 600 : return 141933;
          case 700 : return 139388;
          case 800 : return 145519;
          case 890 : return 137380;
        }
      }
      if (a==1000) {
        switch (b) {
          case 127 : return 142911;
          case 150 : return 144324;
          case 175 : return 139620;
          case 200 : return 137937;
          case 300 : return 144428;
          case 400 : return 147050;
          case 500 : return 136693;
          case 600 : return 146159;
          case 700 : return 144006;
          case 750 : return 147794;
          case 800 : return 139675;
          case 850 : return 140530;
          case 900 : return 150819;
          case 950 : return 133914;
          case 975 : return 150746;
          case 990 : return 131587;
        }
      }
      if (a==1050) {
        switch (b) {
          case 127 : return 146019;
          case 150 : return 135246;
          case 175 : return 144789;
          case 200 : return 143886;
          case 300 : return 148310;
          case 400 : return 141699;
          case 500 : return 139154;
          case 600 : return 142152;
          case 700 : return 143556;
          case 750 : return 148027;
          case 800 : return 147231;
          case 850 : return 137324;
          case 900 : return 146374;
          case 950 : return 146283;
          case 1000 : return 143803;
          case 1025 : return 147758;
          case 1040 : return 147764;
        }
      }
      if (a==1100) {
        switch (b) {
          case 127 : return 119304;
          case 150 : return 121996;
          case 175 : return 124500;
          case 200 : return 131485;
          case 300 : return 123653;
          case 400 : return 123298;
          case 500 : return 116248;
          case 600 : return 126045;
          case 700 : return 124964;
          case 800 : return 131343;
          case 850 : return 128339;
          case 900 : return 131995;
          case 950 : return 127654;
          case 1000 : return 124114;
          case 1050 : return 126010;
          case 1075 : return 120873;
          case 1090 : return 125265;
        }
      }
      if (a==1150) {
        switch (b) {
          case 127 : return 90241;
          case 150 : return 90993;
          case 175 : return 92460;
          case 200 : return 96859;
          case 300 : return 86246;
          case 400 : return 91016;
          case 500 : return 93643;
          case 600 : return 92000;
          case 700 : return 95991;
          case 800 : return 102504;
          case 850 : return 92416;
          case 900 : return 86764;
          case 950 : return 93989;
          case 1000 : return 95359;
          case 1050 : return 94527;
          case 1100 : return 89981;
          case 1125 : return 83493;
          case 1140 : return 90333;
        }
      }
      if (a==1200) {
        switch (b) {
          case 127 : return 61783;
          case 150 : return 68540;
          case 175 : return 64096;
          case 200 : return 64830;
          case 300 : return 70265;
          case 400 : return 61299;
          case 500 : return 61306;
          case 600 : return 62999;
          case 700 : return 61482;
          case 800 : return 65925;
          case 900 : return 65957;
          case 950 : return 63944;
          case 1000 : return 59564;
          case 1050 : return 64037;
          case 1100 : return 64605;
          case 1150 : return 65443;
          case 1175 : return 64179;
          case 1190 : return 62394;
        }
      }
      if (a==1250) {
        switch (b) {
          case 127 : return 51108;
          case 150 : return 48000;
          case 175 : return 43643;
          case 200 : return 47051;
          case 300 : return 52699;
          case 400 : return 48431;
          case 500 : return 43157;
          case 600 : return 41169;
          case 700 : return 46062;
          case 800 : return 49236;
          case 900 : return 51285;
          case 950 : return 47637;
          case 1000 : return 52339;
          case 1050 : return 46909;
          case 1100 : return 48906;
          case 1150 : return 48395;
          case 1200 : return 54162;
          case 1225 : return 43286;
          case 1240 : return 45680;
        }
      }
      if (a==1300) {
        switch (b) {
          case 127 : return 34036;
          case 150 : return 38925;
          case 175 : return 34327;
          case 200 : return 37085;
          case 300 : return 44069;
          case 400 : return 38733;
          case 500 : return 36084;
          case 600 : return 38335;
          case 700 : return 36502;
          case 800 : return 38842;
          case 900 : return 38078;
          case 1000 : return 38354;
          case 1050 : return 39975;
          case 1100 : return 35985;
          case 1150 : return 41195;
          case 1200 : return 37862;
          case 1250 : return 35607;
          case 1275 : return 37398;
          case 1290 : return 35135;
        }
      }
      if (a==1350) {
        switch (b) {
          case 127 : return 34072;
          case 150 : return 36393;
          case 175 : return 36939;
          case 200 : return 40050;
          case 300 : return 38508;
          case 400 : return 34101;
          case 500 : return 38137;
          case 600 : return 39846;
          case 700 : return 45849;
          case 800 : return 40053;
          case 900 : return 34805;
          case 1000 : return 39373;
          case 1050 : return 40544;
          case 1100 : return 39725;
          case 1150 : return 37551;
          case 1200 : return 37046;
          case 1250 : return 36968;
          case 1300 : return 38770;
          case 1325 : return 41936;
          case 1340 : return 39808;
        }
      }
      if (a==1400) {
        switch (b) {
          case 127 : return 33599;
          case 150 : return 38403;
          case 175 : return 34319;
          case 200 : return 36683;
          case 300 : return 30336;
          case 400 : return 39543;
          case 500 : return 41853;
          case 600 : return 36114;
          case 700 : return 44107;
          case 800 : return 35219;
          case 900 : return 31442;
          case 1000 : return 33693;
          case 1100 : return 39367;
          case 1150 : return 36437;
          case 1200 : return 36831;
          case 1250 : return 32489;
          case 1300 : return 33196;
          case 1350 : return 37780;
          case 1375 : return 41224;
          case 1390 : return 38698;
        }
      }
      if (a==1450) {
        switch (b) {
          case 127 : return 38610;
          case 150 : return 42334;
          case 175 : return 40811;
          case 200 : return 38347;
          case 300 : return 42470;
          case 400 : return 41302;
          case 500 : return 38352;
          case 600 : return 37283;
          case 700 : return 40532;
          case 800 : return 35651;
          case 900 : return 31370;
          case 1000 : return 33786;
          case 1100 : return 33896;
          case 1150 : return 40904;
          case 1200 : return 34412;
          case 1250 : return 35373;
          case 1300 : return 38949;
          case 1350 : return 32520;
          case 1400 : return 35752;
          case 1425 : return 31108;
          case 1440 : return 39433;
        }
      }
      if (a==1500) {
        switch (b) {
          case 127 : return 33652;
          case 150 : return 34378;
          case 175 : return 33045;
          case 200 : return 36405;
          case 300 : return 38227;
          case 400 : return 34791;
          case 500 : return 32467;
          case 600 : return 36102;
          case 700 : return 38004;
          case 800 : return 34528;
          case 900 : return 39729;
          case 1000 : return 41418;
          case 1100 : return 38843;
          case 1200 : return 36612;
          case 1250 : return 37962;
          case 1300 : return 37782;
          case 1350 : return 36617;
          case 1400 : return 36453;
          case 1450 : return 36968;
          case 1475 : return 36419;
          case 1490 : return 37024;
        }
      }
      if (a==1550) {
        switch (b) {
          case 127 : return 36989;
          case 150 : return 32718;
          case 175 : return 38299;
          case 200 : return 38172;
          case 300 : return 34929;
          case 400 : return 36449;
          case 500 : return 37592;
          case 600 : return 34927;
          case 700 : return 34401;
          case 800 : return 33061;
          case 900 : return 34938;
          case 1000 : return 32901;
          case 1100 : return 34677;
          case 1200 : return 36653;
          case 1250 : return 42446;
          case 1300 : return 31807;
          case 1350 : return 34697;
          case 1400 : return 35796;
          case 1450 : return 36866;
          case 1500 : return 35927;
          case 1525 : return 35541;
          case 1540 : return 37554;
        }
      }
      if (a==1600) {
        switch (b) {
          case 127 : return 39496;
          case 150 : return 35757;
          case 175 : return 34466;
          case 200 : return 30788;
          case 300 : return 35563;
          case 400 : return 35421;
          case 500 : return 41435;
          case 600 : return 33298;
          case 700 : return 40754;
          case 800 : return 36079;
          case 900 : return 39331;
          case 1000 : return 36801;
          case 1100 : return 36965;
          case 1200 : return 37629;
          case 1300 : return 37266;
          case 1350 : return 35390;
          case 1400 : return 38171;
          case 1450 : return 39800;
          case 1500 : return 36108;
          case 1550 : return 35446;
          case 1575 : return 36021;
          case 1590 : return 41525;
        }
      }
      if (a==1650) {
        switch (b) {
          case 127 : return 36637;
          case 150 : return 39845;
          case 175 : return 40636;
          case 200 : return 38780;
          case 300 : return 33540;
          case 400 : return 38473;
          case 500 : return 36277;
          case 600 : return 35880;
          case 700 : return 40488;
          case 800 : return 33448;
          case 900 : return 37524;
          case 1000 : return 37930;
          case 1100 : return 38835;
          case 1200 : return 36104;
          case 1300 : return 37776;
          case 1350 : return 36012;
          case 1400 : return 34638;
          case 1450 : return 42325;
          case 1500 : return 40953;
          case 1550 : return 38395;
          case 1600 : return 39808;
          case 1625 : return 39006;
          case 1640 : return 41155;
        }
      }
      if (a==1700) {
        switch (b) {
          case 127 : return 35779;
          case 150 : return 36242;
          case 175 : return 38745;
          case 200 : return 38144;
          case 300 : return 37641;
          case 400 : return 40132;
          case 500 : return 36363;
          case 600 : return 42490;
          case 700 : return 39747;
          case 800 : return 36156;
          case 900 : return 38849;
          case 1000 : return 37847;
          case 1100 : return 37684;
          case 1200 : return 38478;
          case 1300 : return 40808;
          case 1400 : return 43835;
          case 1450 : return 32939;
          case 1500 : return 39107;
          case 1550 : return 39079;
          case 1600 : return 35346;
          case 1650 : return 40036;
          case 1675 : return 38939;
          case 1690 : return 38696;
        }
      }
      if (a==1750) {
        switch (b) {
          case 127 : return 36846;
          case 150 : return 37598;
          case 175 : return 30918;
          case 200 : return 38806;
          case 300 : return 39661;
          case 400 : return 37634;
          case 500 : return 42015;
          case 600 : return 40651;
          case 700 : return 38705;
          case 800 : return 37669;
          case 900 : return 38932;
          case 1000 : return 35816;
          case 1100 : return 37993;
          case 1200 : return 40866;
          case 1300 : return 39409;
          case 1400 : return 38904;
          case 1450 : return 36136;
          case 1500 : return 38388;
          case 1550 : return 39319;
          case 1600 : return 36799;
          case 1650 : return 39221;
          case 1700 : return 38446;
          case 1725 : return 37700;
          case 1740 : return 40104;
        }
      }
      if (a==1800) {
        switch (b) {
          case 127 : return 32053;
          case 150 : return 34610;
          case 175 : return 32362;
          case 200 : return 37963;
          case 300 : return 35335;
          case 400 : return 33768;
          case 500 : return 35608;
          case 600 : return 37022;
          case 700 : return 37061;
          case 800 : return 36623;
          case 900 : return 32941;
          case 1000 : return 31343;
          case 1100 : return 37230;
          case 1200 : return 37367;
          case 1300 : return 37494;
          case 1400 : return 37424;
          case 1500 : return 34233;
          case 1550 : return 32898;
          case 1600 : return 34658;
          case 1650 : return 40862;
          case 1700 : return 34872;
          case 1750 : return 36109;
          case 1775 : return 32644;
          case 1790 : return 39054;
        }
      }
      if (a==1850) {
        switch (b) {
          case 127 : return 32329;
          case 150 : return 39965;
          case 175 : return 31761;
          case 200 : return 38329;
          case 300 : return 40827;
          case 400 : return 34471;
          case 500 : return 36231;
          case 600 : return 34642;
          case 700 : return 39613;
          case 800 : return 31635;
          case 900 : return 35917;
          case 1000 : return 36748;
          case 1100 : return 35296;
          case 1200 : return 35396;
          case 1300 : return 42178;
          case 1400 : return 34272;
          case 1500 : return 34307;
          case 1550 : return 32301;
          case 1600 : return 38348;
          case 1650 : return 35501;
          case 1700 : return 36507;
          case 1750 : return 35950;
          case 1800 : return 37413;
          case 1825 : return 37878;
          case 1840 : return 32957;
        }
      }
      if (a==1900) {
        switch (b) {
          case 127 : return 34427;
          case 150 : return 33675;
          case 175 : return 41086;
          case 200 : return 34372;
          case 300 : return 34263;
          case 400 : return 33676;
          case 500 : return 37058;
          case 600 : return 36537;
          case 700 : return 34677;
          case 800 : return 37988;
          case 900 : return 38088;
          case 1000 : return 35168;
          case 1100 : return 36043;
          case 1200 : return 36273;
          case 1300 : return 34790;
          case 1400 : return 37889;
          case 1500 : return 37281;
          case 1600 : return 37956;
          case 1650 : return 37195;
          case 1700 : return 40392;
          case 1750 : return 31431;
          case 1800 : return 43507;
          case 1850 : return 39977;
          case 1875 : return 32707;
          case 1890 : return 32650;
        }
      }
      if (a==1950) {
        switch (b) {
          case 127 : return 33561;
          case 150 : return 39835;
          case 175 : return 33078;
          case 200 : return 39464;
          case 300 : return 40279;
          case 400 : return 37971;
          case 500 : return 42622;
          case 600 : return 38371;
          case 700 : return 42629;
          case 800 : return 31589;
          case 900 : return 34902;
          case 1000 : return 36023;
          case 1100 : return 36073;
          case 1200 : return 37831;
          case 1300 : return 33967;
          case 1400 : return 37939;
          case 1500 : return 42599;
          case 1600 : return 37657;
          case 1650 : return 36486;
          case 1700 : return 37879;
          case 1750 : return 35215;
          case 1800 : return 35964;
          case 1850 : return 38192;
          case 1900 : return 42012;
          case 1925 : return 36712;
          case 1940 : return 38735;
        }
      }
      if (a==2000) {
        switch (b) {
          case 127 : return 16623;
          case 150 : return 20807;
          case 175 : return 17550;
          case 200 : return 18699;
          case 300 : return 16721;
          case 400 : return 17048;
          case 500 : return 16801;
          case 600 : return 19812;
          case 700 : return 18447;
          case 800 : return 17164;
          case 900 : return 20095;
          case 1000 : return 17438;
          case 1100 : return 19516;
          case 1200 : return 18709;
          case 1300 : return 18328;
          case 1400 : return 18982;
          case 1500 : return 20217;
          case 1600 : return 18731;
          case 1700 : return 17059;
          case 1750 : return 20412;
          case 1800 : return 15883;
          case 1850 : return 21274;
          case 1900 : return 15962;
          case 1950 : return 16822;
          case 1975 : return 21387;
          case 1990 : return 20330;
        }
      }
      if (a==2050) {
        switch (b) {
          case 127 : return 17424;
          case 150 : return 15427;
          case 175 : return 17593;
          case 200 : return 22204;
          case 300 : return 16894;
          case 400 : return 19538;
          case 500 : return 21584;
          case 600 : return 21169;
          case 700 : return 21507;
          case 800 : return 20098;
          case 900 : return 16669;
          case 1000 : return 20473;
          case 1100 : return 22447;
          case 1200 : return 19079;
          case 1300 : return 17503;
          case 1400 : return 19226;
          case 1500 : return 22240;
          case 1600 : return 15569;
          case 1700 : return 18336;
          case 1750 : return 19084;
          case 1800 : return 19148;
          case 1850 : return 14163;
          case 1900 : return 18498;
          case 1950 : return 21268;
          case 2000 : return 19134;
          case 2025 : return 20370;
          case 2040 : return 20391;
        }
      }
      if (a==2100) {
        switch (b) {
          case 127 : return 16845;
          case 150 : return 16773;
          case 175 : return 20250;
          case 200 : return 13182;
          case 300 : return 19490;
          case 400 : return 16343;
          case 500 : return 16967;
          case 600 : return 17337;
          case 700 : return 16001;
          case 800 : return 19585;
          case 900 : return 21093;
          case 1000 : return 18717;
          case 1100 : return 13729;
          case 1200 : return 16277;
          case 1300 : return 14332;
          case 1400 : return 16919;
          case 1500 : return 16717;
          case 1600 : return 16915;
          case 1700 : return 15971;
          case 1800 : return 17354;
          case 1850 : return 16212;
          case 1900 : return 19301;
          case 1950 : return 13461;
          case 2000 : return 15529;
          case 2050 : return 20458;
          case 2075 : return 17553;
          case 2090 : return 19255;
        }
      }
      if (a==2150) {
        switch (b) {
          case 127 : return 21337;
          case 150 : return 16107;
          case 175 : return 17291;
          case 200 : return 16361;
          case 300 : return 17137;
          case 400 : return 15486;
          case 500 : return 14350;
          case 600 : return 18271;
          case 700 : return 16893;
          case 800 : return 15501;
          case 900 : return 20300;
          case 1000 : return 17427;
          case 1100 : return 17435;
          case 1200 : return 14486;
          case 1300 : return 20016;
          case 1400 : return 17091;
          case 1500 : return 18760;
          case 1600 : return 17508;
          case 1700 : return 16230;
          case 1800 : return 17020;
          case 1850 : return 20454;
          case 1900 : return 16222;
          case 1950 : return 15407;
          case 2000 : return 15722;
          case 2050 : return 18195;
          case 2100 : return 15589;
          case 2125 : return 17727;
          case 2140 : return 17809;
        }
      }
      if (a==2200) {
        switch (b) {
          case 127 : return 19698;
          case 150 : return 18993;
          case 175 : return 18515;
          case 200 : return 18327;
          case 300 : return 12592;
          case 400 : return 24558;
          case 500 : return 22708;
          case 600 : return 15205;
          case 700 : return 13352;
          case 800 : return 18499;
          case 900 : return 18663;
          case 1000 : return 14891;
          case 1100 : return 16903;
          case 1200 : return 15222;
          case 1300 : return 17752;
          case 1400 : return 17448;
          case 1500 : return 20526;
          case 1600 : return 20077;
          case 1700 : return 18987;
          case 1800 : return 20180;
          case 1900 : return 19514;
          case 1950 : return 19348;
          case 2000 : return 18099;
          case 2050 : return 18403;
          case 2100 : return 20550;
          case 2150 : return 19480;
          case 2175 : return 21326;
          case 2190 : return 18598;
        }
      }
      if (a==2250) {
        switch (b) {
          case 127 : return 18311;
          case 150 : return 20355;
          case 175 : return 16723;
          case 200 : return 19134;
          case 300 : return 16651;
          case 400 : return 17685;
          case 500 : return 19322;
          case 600 : return 19379;
          case 700 : return 20946;
          case 800 : return 20008;
          case 900 : return 14697;
          case 1000 : return 15828;
          case 1100 : return 16867;
          case 1200 : return 21196;
          case 1300 : return 16511;
          case 1400 : return 18132;
          case 1500 : return 20511;
          case 1600 : return 18510;
          case 1700 : return 18288;
          case 1800 : return 20287;
          case 1900 : return 20777;
          case 1950 : return 15942;
          case 2000 : return 18010;
          case 2050 : return 15435;
          case 2100 : return 17246;
          case 2150 : return 19465;
          case 2200 : return 16449;
          case 2225 : return 18385;
          case 2240 : return 18007;
        }
      }
      if (a==2300) {
        switch (b) {
          case 127 : return 16516;
          case 150 : return 19750;
          case 175 : return 19752;
          case 200 : return 19622;
          case 300 : return 19415;
          case 400 : return 14936;
          case 500 : return 19942;
          case 600 : return 16221;
          case 700 : return 19473;
          case 800 : return 17554;
          case 900 : return 21261;
          case 1000 : return 18573;
          case 1100 : return 21144;
          case 1200 : return 17560;
          case 1300 : return 23922;
          case 1400 : return 21004;
          case 1500 : return 18649;
          case 1600 : return 19103;
          case 1700 : return 21044;
          case 1800 : return 16513;
          case 1900 : return 18084;
          case 2000 : return 16007;
          case 2050 : return 16445;
          case 2100 : return 18702;
          case 2150 : return 19478;
          case 2200 : return 18876;
          case 2250 : return 15012;
          case 2275 : return 18923;
          case 2290 : return 20161;
        }
      }
      if (a==2350) {
        switch (b) {
          case 127 : return 20118;
          case 150 : return 18647;
          case 175 : return 18835;
          case 200 : return 17179;
          case 300 : return 14530;
          case 400 : return 16209;
          case 500 : return 18686;
          case 600 : return 17722;
          case 700 : return 18055;
          case 800 : return 17276;
          case 900 : return 15425;
          case 1000 : return 14478;
          case 1100 : return 16122;
          case 1200 : return 17916;
          case 1300 : return 14292;
          case 1400 : return 18691;
          case 1500 : return 21705;
          case 1600 : return 19033;
          case 1700 : return 17649;
          case 1800 : return 18251;
          case 1900 : return 25423;
          case 2000 : return 19233;
          case 2050 : return 16890;
          case 2100 : return 17027;
          case 2150 : return 18653;
          case 2200 : return 17639;
          case 2250 : return 16724;
          case 2300 : return 19472;
          case 2325 : return 16091;
          case 2340 : return 19502;
        }
      }
      if (a==2400) {
        switch (b) {
          case 127 : return 18187;
          case 150 : return 16999;
          case 175 : return 17126;
          case 200 : return 17081;
          case 300 : return 16401;
          case 400 : return 17214;
          case 500 : return 16211;
          case 600 : return 18285;
          case 700 : return 20253;
          case 800 : return 15133;
          case 900 : return 20158;
          case 1000 : return 17999;
          case 1100 : return 15310;
          case 1200 : return 16891;
          case 1300 : return 18842;
          case 1400 : return 17630;
          case 1500 : return 19878;
          case 1600 : return 14580;
          case 1700 : return 17144;
          case 1800 : return 20426;
          case 1900 : return 15206;
          case 2000 : return 20504;
          case 2100 : return 16619;
          case 2150 : return 17140;
          case 2200 : return 16796;
          case 2250 : return 17459;
          case 2300 : return 16783;
          case 2350 : return 16328;
          case 2375 : return 16361;
          case 2390 : return 15555;
        }
      }
      if (a==2450) {
        switch (b) {
          case 127 : return 18131;
          case 150 : return 16255;
          case 175 : return 18457;
          case 200 : return 16367;
          case 300 : return 19823;
          case 400 : return 15884;
          case 500 : return 16442;
          case 600 : return 17898;
          case 700 : return 19875;
          case 800 : return 17433;
          case 900 : return 18958;
          case 1000 : return 20074;
          case 1100 : return 16356;
          case 1200 : return 19370;
          case 1300 : return 15233;
          case 1400 : return 18658;
          case 1500 : return 17410;
          case 1600 : return 19017;
          case 1700 : return 20918;
          case 1800 : return 18716;
          case 1900 : return 19358;
          case 2000 : return 18507;
          case 2100 : return 20373;
          case 2150 : return 19306;
          case 2200 : return 15268;
          case 2250 : return 15039;
          case 2300 : return 18022;
          case 2350 : return 15417;
          case 2400 : return 16991;
          case 2425 : return 19280;
          case 2440 : return 19847;
        }
      }
      if (a==2500) {
        switch (b) {
          case 127 : return 14959;
          case 150 : return 20630;
          case 175 : return 19072;
          case 200 : return 18205;
          case 300 : return 20866;
          case 400 : return 18739;
          case 500 : return 17470;
          case 600 : return 16980;
          case 700 : return 18760;
          case 800 : return 18517;
          case 900 : return 17063;
          case 1000 : return 15523;
          case 1100 : return 22152;
          case 1200 : return 18815;
          case 1300 : return 17976;
          case 1400 : return 17590;
          case 1500 : return 19195;
          case 1600 : return 14605;
          case 1700 : return 16635;
          case 1800 : return 20697;
          case 1900 : return 20254;
          case 2000 : return 18371;
          case 2100 : return 16161;
          case 2200 : return 18704;
          case 2250 : return 20915;
          case 2300 : return 15911;
          case 2350 : return 17524;
          case 2400 : return 19006;
          case 2450 : return 16844;
          case 2475 : return 19610;
          case 2490 : return 18615;
        }
      }
      if (a==2550) {
        switch (b) {
          case 127 : return 17498;
          case 150 : return 21232;
          case 175 : return 14192;
          case 200 : return 18743;
          case 300 : return 19422;
          case 400 : return 16018;
          case 500 : return 19127;
          case 600 : return 20198;
          case 700 : return 18818;
          case 800 : return 18914;
          case 900 : return 18769;
          case 1000 : return 19493;
          case 1100 : return 19788;
          case 1200 : return 16793;
          case 1300 : return 18412;
          case 1400 : return 17164;
          case 1500 : return 22010;
          case 1600 : return 20287;
          case 1700 : return 20260;
          case 1800 : return 19017;
          case 1900 : return 21187;
          case 2000 : return 20308;
          case 2100 : return 16165;
          case 2200 : return 18666;
          case 2250 : return 18179;
          case 2300 : return 20282;
          case 2350 : return 18932;
          case 2400 : return 19365;
          case 2450 : return 18685;
          case 2500 : return 15340;
          case 2525 : return 17440;
          case 2540 : return 17339;
        }
      }
      if (a==2600) {
        switch (b) {
          case 127 : return 17487;
          case 150 : return 14894;
          case 175 : return 17542;
          case 200 : return 21194;
          case 300 : return 20856;
          case 400 : return 16451;
          case 500 : return 17286;
          case 600 : return 14934;
          case 700 : return 20286;
          case 800 : return 20879;
          case 900 : return 17500;
          case 1000 : return 22782;
          case 1100 : return 17588;
          case 1200 : return 19649;
          case 1300 : return 21731;
          case 1400 : return 18142;
          case 1500 : return 15629;
          case 1600 : return 16876;
          case 1700 : return 22021;
          case 1800 : return 18745;
          case 1900 : return 16755;
          case 2000 : return 19709;
          case 2100 : return 19669;
          case 2200 : return 20589;
          case 2300 : return 19794;
          case 2350 : return 20949;
          case 2400 : return 14364;
          case 2450 : return 16594;
          case 2500 : return 18764;
          case 2550 : return 14545;
          case 2575 : return 19655;
          case 2590 : return 18270;
        }
      }
      if (a==2650) {
        switch (b) {
          case 127 : return 15117;
          case 150 : return 15172;
          case 175 : return 15532;
          case 200 : return 17148;
          case 300 : return 20149;
          case 400 : return 19383;
          case 500 : return 17454;
          case 600 : return 16200;
          case 700 : return 16558;
          case 800 : return 13949;
          case 900 : return 16699;
          case 1000 : return 19134;
          case 1100 : return 16944;
          case 1200 : return 19970;
          case 1300 : return 16699;
          case 1400 : return 20923;
          case 1500 : return 20888;
          case 1600 : return 20059;
          case 1700 : return 16488;
          case 1800 : return 21318;
          case 1900 : return 18061;
          case 2000 : return 20681;
          case 2100 : return 17448;
          case 2200 : return 19032;
          case 2300 : return 14511;
          case 2350 : return 18033;
          case 2400 : return 17285;
          case 2450 : return 16776;
          case 2500 : return 19552;
          case 2550 : return 14017;
          case 2600 : return 19693;
          case 2625 : return 15980;
          case 2640 : return 20828;
        }
      }
      if (a==2700) {
        switch (b) {
          case 127 : return 18346;
          case 150 : return 17312;
          case 175 : return 15415;
          case 200 : return 15321;
          case 300 : return 17264;
          case 400 : return 15330;
          case 500 : return 19187;
          case 600 : return 18733;
          case 700 : return 18447;
          case 800 : return 17683;
          case 900 : return 17627;
          case 1000 : return 17155;
          case 1100 : return 15757;
          case 1200 : return 15310;
          case 1300 : return 18138;
          case 1400 : return 14949;
          case 1500 : return 19627;
          case 1600 : return 17801;
          case 1700 : return 18373;
          case 1800 : return 19274;
          case 1900 : return 16648;
          case 2000 : return 18786;
          case 2100 : return 15236;
          case 2200 : return 17842;
          case 2300 : return 14636;
          case 2400 : return 14274;
          case 2450 : return 18643;
          case 2500 : return 19982;
          case 2550 : return 17719;
          case 2600 : return 17386;
          case 2650 : return 22254;
          case 2675 : return 19497;
          case 2690 : return 16774;
        }
      }
      if (a==2750) {
        switch (b) {
          case 127 : return 19079;
          case 150 : return 19881;
          case 175 : return 16421;
          case 200 : return 19274;
          case 300 : return 18399;
          case 400 : return 15749;
          case 500 : return 17859;
          case 600 : return 17806;
          case 700 : return 15308;
          case 800 : return 15712;
          case 900 : return 13398;
          case 1000 : return 18388;
          case 1100 : return 16630;
          case 1200 : return 16366;
          case 1300 : return 16881;
          case 1400 : return 18232;
          case 1500 : return 16845;
          case 1600 : return 19890;
          case 1700 : return 20414;
          case 1800 : return 19630;
          case 1900 : return 17810;
          case 2000 : return 18358;
          case 2100 : return 17388;
          case 2200 : return 16754;
          case 2300 : return 15045;
          case 2400 : return 14272;
          case 2450 : return 17931;
          case 2500 : return 19468;
          case 2550 : return 21305;
          case 2600 : return 22196;
          case 2650 : return 20843;
          case 2700 : return 17436;
          case 2725 : return 15954;
          case 2740 : return 18630;
        }
      }
      if (a==2800) {
        switch (b) {
          case 127 : return 17912;
          case 150 : return 17073;
          case 175 : return 17858;
          case 200 : return 20276;
          case 300 : return 19404;
          case 400 : return 18796;
          case 500 : return 19854;
          case 600 : return 18969;
          case 700 : return 22134;
          case 800 : return 18835;
          case 900 : return 14195;
          case 1000 : return 19484;
          case 1100 : return 14298;
          case 1200 : return 19891;
          case 1300 : return 20116;
          case 1400 : return 14551;
          case 1500 : return 17801;
          case 1600 : return 16604;
          case 1700 : return 19441;
          case 1800 : return 15250;
          case 1900 : return 18407;
          case 2000 : return 19301;
          case 2100 : return 21078;
          case 2200 : return 19424;
          case 2300 : return 15683;
          case 2400 : return 16551;
          case 2500 : return 16419;
          case 2550 : return 16026;
          case 2600 : return 17163;
          case 2650 : return 16305;
          case 2700 : return 22544;
          case 2750 : return 18088;
          case 2775 : return 15328;
          case 2790 : return 19082;
        }
      }
      break;
      case 2017 :
      if (a==800) {
        switch (b) {
          case 127 : return 164924;
          case 200 : return 179529;
          case 300 : return 141607;
          case 400 : return 158559;
          case 500 : return 194880;
          case 600 : return 184119;
          case 700 : return 195811;
          case 790 : return 181272;
        }
      }
      if (a==900) {
        switch (b) {
          case 127 : return 183638;
          case 200 : return 158814;
          case 300 : return 194014;
          case 400 : return 157036;
          case 500 : return 166532;
          case 600 : return 192318;
          case 700 : return 173473;
          case 800 : return 164550;
          case 890 : return 177845;
        }
      }
      if (a==1000) {
        switch (b) {
          case 127 : return 182002;
          case 150 : return 178877;
          case 175 : return 182779;
          case 200 : return 176567;
          case 300 : return 158713;
          case 400 : return 168797;
          case 500 : return 180537;
          case 600 : return 164145;
          case 700 : return 170294;
          case 750 : return 167533;
          case 800 : return 152925;
          case 850 : return 158668;
          case 900 : return 161252;
          case 950 : return 173636;
          case 975 : return 198050;
          case 990 : return 159509;
        }
      }
      if (a==1050) {
        switch (b) {
          case 127 : return 207452;
          case 150 : return 167187;
          case 175 : return 176282;
          case 200 : return 186359;
          case 300 : return 192425;
          case 400 : return 156190;
          case 500 : return 185768;
          case 600 : return 164483;
          case 700 : return 175542;
          case 750 : return 168811;
          case 800 : return 179631;
          case 850 : return 177295;
          case 900 : return 158648;
          case 950 : return 166174;
          case 1000 : return 177439;
          case 1025 : return 172442;
          case 1040 : return 145876;
        }
      }
      if (a==1100) {
        switch (b) {
          case 127 : return 154406;
          case 150 : return 154058;
          case 175 : return 170034;
          case 200 : return 154587;
          case 300 : return 138339;
          case 400 : return 164451;
          case 500 : return 160345;
          case 600 : return 156698;
          case 700 : return 152775;
          case 800 : return 161448;
          case 850 : return 154978;
          case 900 : return 144743;
          case 950 : return 148565;
          case 1000 : return 155731;
          case 1050 : return 150465;
          case 1075 : return 130199;
          case 1090 : return 140209;
        }
      }
      if (a==1150) {
        switch (b) {
          case 127 : return 115797;
          case 150 : return 113855;
          case 175 : return 104672;
          case 200 : return 100530;
          case 300 : return 103299;
          case 400 : return 118373;
          case 500 : return 113295;
          case 600 : return 86596;
          case 700 : return 100612;
          case 800 : return 100098;
          case 850 : return 103359;
          case 900 : return 105439;
          case 950 : return 117498;
          case 1000 : return 92623;
          case 1050 : return 105601;
          case 1100 : return 96105;
          case 1125 : return 100715;
          case 1140 : return 102997;
        }
      }
      if (a==1200) {
        switch (b) {
          case 127 : return 82026;
          case 150 : return 85702;
          case 175 : return 63571;
          case 200 : return 71699;
          case 300 : return 73130;
          case 400 : return 88637;
          case 500 : return 81779;
          case 600 : return 70976;
          case 700 : return 71394;
          case 800 : return 75722;
          case 900 : return 74116;
          case 950 : return 72008;
          case 1000 : return 89485;
          case 1050 : return 64759;
          case 1100 : return 74704;
          case 1150 : return 71612;
          case 1175 : return 74033;
          case 1190 : return 85876;
        }
      }
      if (a==1250) {
        switch (b) {
          case 127 : return 60786;
          case 150 : return 68000;
          case 175 : return 50156;
          case 200 : return 50953;
          case 300 : return 69940;
          case 400 : return 54630;
          case 500 : return 59305;
          case 600 : return 58362;
          case 700 : return 51958;
          case 800 : return 57169;
          case 900 : return 65619;
          case 950 : return 47967;
          case 1000 : return 59913;
          case 1050 : return 58315;
          case 1100 : return 44931;
          case 1150 : return 48450;
          case 1200 : return 55570;
          case 1225 : return 55593;
          case 1240 : return 61968;
        }
      }
      if (a==1300) {
        switch (b) {
          case 127 : return 36147;
          case 150 : return 52486;
          case 175 : return 45789;
          case 200 : return 38645;
          case 300 : return 47849;
          case 400 : return 49137;
          case 500 : return 43129;
          case 600 : return 56152;
          case 700 : return 46746;
          case 800 : return 46794;
          case 900 : return 46744;
          case 1000 : return 49498;
          case 1050 : return 47769;
          case 1100 : return 49673;
          case 1150 : return 52322;
          case 1200 : return 49802;
          case 1250 : return 41258;
          case 1275 : return 57050;
          case 1290 : return 43011;
        }
      }
      if (a==1350) {
        switch (b) {
          case 127 : return 40678;
          case 150 : return 51738;
          case 175 : return 45535;
          case 200 : return 49205;
          case 300 : return 51914;
          case 400 : return 52103;
          case 500 : return 40892;
          case 600 : return 46557;
          case 700 : return 45996;
          case 800 : return 47058;
          case 900 : return 53783;
          case 1000 : return 45430;
          case 1050 : return 48256;
          case 1100 : return 35326;
          case 1150 : return 41935;
          case 1200 : return 44544;
          case 1250 : return 40674;
          case 1300 : return 41094;
          case 1325 : return 38162;
          case 1340 : return 61756;
        }
      }
      if (a==1400) {
        switch (b) {
          case 127 : return 45806;
          case 150 : return 40302;
          case 175 : return 50547;
          case 200 : return 61907;
          case 300 : return 51664;
          case 400 : return 43845;
          case 500 : return 53559;
          case 600 : return 41192;
          case 700 : return 55116;
          case 800 : return 36278;
          case 900 : return 49462;
          case 1000 : return 50240;
          case 1100 : return 46665;
          case 1150 : return 40245;
          case 1200 : return 48691;
          case 1250 : return 36121;
          case 1300 : return 38422;
          case 1350 : return 37540;
          case 1375 : return 33886;
          case 1390 : return 44707;
        }
      }
      if (a==1450) {
        switch (b) {
          case 127 : return 46258;
          case 150 : return 47127;
          case 175 : return 43690;
          case 200 : return 31074;
          case 300 : return 37935;
          case 400 : return 40590;
          case 500 : return 40645;
          case 600 : return 44524;
          case 700 : return 40859;
          case 800 : return 57664;
          case 900 : return 46507;
          case 1000 : return 47960;
          case 1100 : return 39747;
          case 1150 : return 35874;
          case 1200 : return 35811;
          case 1250 : return 44607;
          case 1300 : return 36933;
          case 1350 : return 38820;
          case 1400 : return 36009;
          case 1425 : return 41661;
          case 1440 : return 48270;
        }
      }
      if (a==1500) {
        switch (b) {
          case 127 : return 52364;
          case 150 : return 41128;
          case 175 : return 48625;
          case 200 : return 41319;
          case 300 : return 38369;
          case 400 : return 46090;
          case 500 : return 45054;
          case 600 : return 58168;
          case 700 : return 50801;
          case 800 : return 52771;
          case 900 : return 43914;
          case 1000 : return 39184;
          case 1100 : return 38172;
          case 1200 : return 43027;
          case 1250 : return 41227;
          case 1300 : return 41258;
          case 1350 : return 30582;
          case 1400 : return 41954;
          case 1450 : return 48952;
          case 1475 : return 41062;
          case 1490 : return 35059;
        }
      }
      if (a==1550) {
        switch (b) {
          case 127 : return 51054;
          case 150 : return 42372;
          case 175 : return 41258;
          case 200 : return 46290;
          case 300 : return 44571;
          case 400 : return 44305;
          case 500 : return 36725;
          case 600 : return 48312;
          case 700 : return 44339;
          case 800 : return 47244;
          case 900 : return 43354;
          case 1000 : return 41378;
          case 1100 : return 43706;
          case 1200 : return 38734;
          case 1250 : return 43492;
          case 1300 : return 39546;
          case 1350 : return 46349;
          case 1400 : return 47503;
          case 1450 : return 30682;
          case 1500 : return 38758;
          case 1525 : return 49306;
          case 1540 : return 38446;
        }
      }
      if (a==1600) {
        switch (b) {
          case 127 : return 45846;
          case 150 : return 44814;
          case 175 : return 45053;
          case 200 : return 39924;
          case 300 : return 41795;
          case 400 : return 52697;
          case 500 : return 39814;
          case 600 : return 43044;
          case 700 : return 47997;
          case 800 : return 34216;
          case 900 : return 43085;
          case 1000 : return 46801;
          case 1100 : return 43581;
          case 1200 : return 43851;
          case 1300 : return 37857;
          case 1350 : return 43843;
          case 1400 : return 37296;
          case 1450 : return 43898;
          case 1500 : return 38322;
          case 1550 : return 42055;
          case 1575 : return 34386;
          case 1590 : return 41868;
        }
      }
      if (a==1650) {
        switch (b) {
          case 127 : return 43146;
          case 150 : return 42420;
          case 175 : return 55450;
          case 200 : return 39527;
          case 300 : return 51335;
          case 400 : return 50418;
          case 500 : return 52263;
          case 600 : return 37397;
          case 700 : return 52059;
          case 800 : return 44237;
          case 900 : return 44234;
          case 1000 : return 41430;
          case 1100 : return 57290;
          case 1200 : return 45095;
          case 1300 : return 50940;
          case 1350 : return 40312;
          case 1400 : return 37589;
          case 1450 : return 37097;
          case 1500 : return 37641;
          case 1550 : return 35834;
          case 1600 : return 37508;
          case 1625 : return 33626;
          case 1640 : return 48218;
        }
      }
      if (a==1700) {
        switch (b) {
          case 127 : return 43710;
          case 150 : return 41200;
          case 175 : return 51942;
          case 200 : return 46090;
          case 300 : return 49632;
          case 400 : return 34070;
          case 500 : return 49016;
          case 600 : return 42169;
          case 700 : return 51900;
          case 800 : return 41842;
          case 900 : return 57021;
          case 1000 : return 60977;
          case 1100 : return 44654;
          case 1200 : return 41201;
          case 1300 : return 39879;
          case 1400 : return 38156;
          case 1450 : return 43035;
          case 1500 : return 41948;
          case 1550 : return 45142;
          case 1600 : return 45198;
          case 1650 : return 43101;
          case 1675 : return 40164;
          case 1690 : return 47762;
        }
      }
      if (a==1750) {
        switch (b) {
          case 127 : return 32410;
          case 150 : return 39646;
          case 175 : return 61708;
          case 200 : return 45561;
          case 300 : return 44761;
          case 400 : return 47548;
          case 500 : return 53638;
          case 600 : return 37631;
          case 700 : return 43657;
          case 800 : return 47568;
          case 900 : return 41493;
          case 1000 : return 38619;
          case 1100 : return 51564;
          case 1200 : return 38590;
          case 1300 : return 41169;
          case 1400 : return 33639;
          case 1450 : return 42578;
          case 1500 : return 40584;
          case 1550 : return 30432;
          case 1600 : return 44314;
          case 1650 : return 36611;
          case 1700 : return 37770;
          case 1725 : return 59843;
          case 1740 : return 44905;
        }
      }
      if (a==1800) {
        switch (b) {
          case 127 : return 36112;
          case 150 : return 43044;
          case 175 : return 37114;
          case 200 : return 40987;
          case 300 : return 42982;
          case 400 : return 41159;
          case 500 : return 40099;
          case 600 : return 39192;
          case 700 : return 42940;
          case 800 : return 39139;
          case 900 : return 47338;
          case 1000 : return 36769;
          case 1100 : return 45312;
          case 1200 : return 37690;
          case 1300 : return 27566;
          case 1400 : return 30616;
          case 1500 : return 37033;
          case 1550 : return 53438;
          case 1600 : return 34969;
          case 1650 : return 36968;
          case 1700 : return 43140;
          case 1750 : return 49244;
          case 1775 : return 29744;
          case 1790 : return 45099;
        }
      }
      if (a==1850) {
        switch (b) {
          case 127 : return 47453;
          case 150 : return 30147;
          case 175 : return 37261;
          case 200 : return 50193;
          case 300 : return 39482;
          case 400 : return 40613;
          case 500 : return 45794;
          case 600 : return 53811;
          case 700 : return 33203;
          case 800 : return 45200;
          case 900 : return 37398;
          case 1000 : return 37555;
          case 1100 : return 41623;
          case 1200 : return 49643;
          case 1300 : return 42675;
          case 1400 : return 40417;
          case 1500 : return 47945;
          case 1550 : return 37624;
          case 1600 : return 44584;
          case 1650 : return 35264;
          case 1700 : return 49090;
          case 1750 : return 29025;
          case 1800 : return 30333;
          case 1825 : return 36258;
          case 1840 : return 36297;
        }
      }
      if (a==1900) {
        switch (b) {
          case 127 : return 42267;
          case 150 : return 47600;
          case 175 : return 46375;
          case 200 : return 49814;
          case 300 : return 36874;
          case 400 : return 43086;
          case 500 : return 40979;
          case 600 : return 47389;
          case 700 : return 41260;
          case 800 : return 44586;
          case 900 : return 46220;
          case 1000 : return 54925;
          case 1100 : return 46504;
          case 1200 : return 39930;
          case 1300 : return 55062;
          case 1400 : return 39122;
          case 1500 : return 37082;
          case 1600 : return 27555;
          case 1650 : return 38978;
          case 1700 : return 46553;
          case 1750 : return 35013;
          case 1800 : return 41375;
          case 1850 : return 41318;
          case 1875 : return 40444;
          case 1890 : return 44411;
        }
      }
      if (a==1950) {
        switch (b) {
          case 127 : return 52527;
          case 150 : return 48098;
          case 175 : return 44841;
          case 200 : return 53435;
          case 300 : return 45051;
          case 400 : return 40362;
          case 500 : return 40649;
          case 600 : return 38427;
          case 700 : return 30946;
          case 800 : return 52293;
          case 900 : return 41525;
          case 1000 : return 40550;
          case 1100 : return 36496;
          case 1200 : return 34448;
          case 1300 : return 38061;
          case 1400 : return 40521;
          case 1500 : return 48137;
          case 1600 : return 47115;
          case 1650 : return 33005;
          case 1700 : return 39413;
          case 1750 : return 43563;
          case 1800 : return 33235;
          case 1850 : return 37375;
          case 1900 : return 42820;
          case 1925 : return 42860;
          case 1940 : return 32958;
        }
      }
      if (a==2000) {
        switch (b) {
          case 127 : return 21589;
          case 150 : return 25894;
          case 175 : return 20675;
          case 200 : return 18503;
          case 300 : return 21723;
          case 400 : return 23699;
          case 500 : return 18403;
          case 600 : return 29268;
          case 700 : return 11907;
          case 800 : return 22719;
          case 900 : return 18318;
          case 1000 : return 31335;
          case 1100 : return 19497;
          case 1200 : return 24038;
          case 1300 : return 23807;
          case 1400 : return 16227;
          case 1500 : return 20471;
          case 1600 : return 16192;
          case 1700 : return 14032;
          case 1750 : return 15125;
          case 1800 : return 21766;
          case 1850 : return 18363;
          case 1900 : return 20988;
          case 1950 : return 14171;
          case 1975 : return 19585;
          case 1990 : return 14116;
        }
      }
      if (a==2050) {
        switch (b) {
          case 127 : return 19752;
          case 150 : return 20904;
          case 175 : return 23173;
          case 200 : return 25297;
          case 300 : return 24221;
          case 400 : return 21874;
          case 500 : return 27532;
          case 600 : return 17583;
          case 700 : return 19814;
          case 800 : return 31811;
          case 900 : return 17578;
          case 1000 : return 31895;
          case 1100 : return 21925;
          case 1200 : return 18890;
          case 1300 : return 20984;
          case 1400 : return 24281;
          case 1500 : return 17583;
          case 1600 : return 23066;
          case 1700 : return 24210;
          case 1750 : return 15308;
          case 1800 : return 15305;
          case 1850 : return 23029;
          case 1900 : return 15377;
          case 1950 : return 23034;
          case 2000 : return 18811;
          case 2025 : return 22134;
          case 2040 : return 28090;
        }
      }
      if (a==2100) {
        switch (b) {
          case 127 : return 23339;
          case 150 : return 18789;
          case 175 : return 19930;
          case 200 : return 18989;
          case 300 : return 24687;
          case 400 : return 19119;
          case 500 : return 21244;
          case 600 : return 23303;
          case 700 : return 22523;
          case 800 : return 25644;
          case 900 : return 18836;
          case 1000 : return 26685;
          case 1100 : return 17834;
          case 1200 : return 19051;
          case 1300 : return 25663;
          case 1400 : return 30249;
          case 1500 : return 24576;
          case 1600 : return 27819;
          case 1700 : return 13173;
          case 1800 : return 21160;
          case 1850 : return 17666;
          case 1900 : return 11214;
          case 1950 : return 14596;
          case 2000 : return 23280;
          case 2050 : return 12328;
          case 2075 : return 21377;
          case 2090 : return 16626;
        }
      }
      if (a==2150) {
        switch (b) {
          case 127 : return 12470;
          case 150 : return 24688;
          case 175 : return 24745;
          case 200 : return 16987;
          case 300 : return 21338;
          case 400 : return 18093;
          case 500 : return 14610;
          case 600 : return 25935;
          case 700 : return 19264;
          case 800 : return 22572;
          case 900 : return 14748;
          case 1000 : return 21478;
          case 1100 : return 19305;
          case 1200 : return 20500;
          case 1300 : return 21318;
          case 1400 : return 14592;
          case 1500 : return 19178;
          case 1600 : return 19300;
          case 1700 : return 19171;
          case 1800 : return 27324;
          case 1850 : return 19137;
          case 1900 : return 18122;
          case 1950 : return 21470;
          case 2000 : return 22588;
          case 2050 : return 15798;
          case 2100 : return 15980;
          case 2125 : return 22595;
          case 2140 : return 13478;
        }
      }
      if (a==2200) {
        switch (b) {
          case 127 : return 29692;
          case 150 : return 25086;
          case 175 : return 28723;
          case 200 : return 27421;
          case 300 : return 22938;
          case 400 : return 16034;
          case 500 : return 25238;
          case 600 : return 14926;
          case 700 : return 19444;
          case 800 : return 15927;
          case 900 : return 27478;
          case 1000 : return 26228;
          case 1100 : return 20601;
          case 1200 : return 27830;
          case 1300 : return 21734;
          case 1400 : return 18326;
          case 1500 : return 12726;
          case 1600 : return 19652;
          case 1700 : return 12595;
          case 1800 : return 11451;
          case 1900 : return 17238;
          case 1950 : return 21984;
          case 2000 : return 27416;
          case 2050 : return 10509;
          case 2100 : return 16169;
          case 2150 : return 20828;
          case 2175 : return 12568;
          case 2190 : return 12448;
        }
      }
      if (a==2250) {
        switch (b) {
          case 127 : return 13880;
          case 150 : return 23170;
          case 175 : return 16398;
          case 200 : return 23202;
          case 300 : return 14065;
          case 400 : return 23199;
          case 500 : return 22076;
          case 600 : return 20823;
          case 700 : return 26965;
          case 800 : return 24385;
          case 900 : return 16236;
          case 1000 : return 31403;
          case 1100 : return 18606;
          case 1200 : return 21974;
          case 1300 : return 14929;
          case 1400 : return 24275;
          case 1500 : return 26786;
          case 1600 : return 15078;
          case 1700 : return 25740;
          case 1800 : return 22243;
          case 1900 : return 25482;
          case 1950 : return 18524;
          case 2000 : return 24466;
          case 2050 : return 20808;
          case 2100 : return 16367;
          case 2150 : return 17365;
          case 2200 : return 16146;
          case 2225 : return 15183;
          case 2240 : return 11541;
        }
      }
      if (a==2300) {
        switch (b) {
          case 127 : return 24533;
          case 150 : return 16573;
          case 175 : return 16520;
          case 200 : return 21024;
          case 300 : return 21191;
          case 400 : return 23630;
          case 500 : return 22247;
          case 600 : return 12871;
          case 700 : return 31605;
          case 800 : return 18881;
          case 900 : return 22272;
          case 1000 : return 21164;
          case 1100 : return 19909;
          case 1200 : return 22417;
          case 1300 : return 23649;
          case 1400 : return 28425;
          case 1500 : return 17490;
          case 1600 : return 19969;
          case 1700 : return 30773;
          case 1800 : return 24545;
          case 1900 : return 12922;
          case 2000 : return 22326;
          case 2050 : return 15523;
          case 2100 : return 21294;
          case 2150 : return 21156;
          case 2200 : return 25973;
          case 2250 : return 18880;
          case 2275 : return 15303;
          case 2290 : return 20008;
        }
      }
      if (a==2350) {
        switch (b) {
          case 127 : return 19055;
          case 150 : return 25037;
          case 175 : return 15554;
          case 200 : return 22501;
          case 300 : return 26140;
          case 400 : return 26236;
          case 500 : return 20278;
          case 600 : return 20313;
          case 700 : return 13017;
          case 800 : return 16623;
          case 900 : return 14178;
          case 1000 : return 20214;
          case 1100 : return 17860;
          case 1200 : return 16706;
          case 1300 : return 13163;
          case 1400 : return 19026;
          case 1500 : return 15351;
          case 1600 : return 17955;
          case 1700 : return 23822;
          case 1800 : return 21347;
          case 1900 : return 10798;
          case 2000 : return 13095;
          case 2050 : return 21521;
          case 2100 : return 19108;
          case 2150 : return 16646;
          case 2200 : return 27335;
          case 2250 : return 15518;
          case 2300 : return 22503;
          case 2325 : return 14363;
          case 2340 : return 24824;
        }
      }
      if (a==2400) {
        switch (b) {
          case 127 : return 14419;
          case 150 : return 12225;
          case 175 : return 24119;
          case 200 : return 25268;
          case 300 : return 19315;
          case 400 : return 11920;
          case 500 : return 25408;
          case 600 : return 22860;
          case 700 : return 18081;
          case 800 : return 24066;
          case 900 : return 15732;
          case 1000 : return 14553;
          case 1100 : return 31342;
          case 1200 : return 14610;
          case 1300 : return 24242;
          case 1400 : return 28797;
          case 1500 : return 17944;
          case 1600 : return 21899;
          case 1700 : return 21475;
          case 1800 : return 26800;
          case 1900 : return 12008;
          case 2000 : return 24158;
          case 2100 : return 23978;
          case 2150 : return 24053;
          case 2200 : return 10866;
          case 2250 : return 14522;
          case 2300 : return 16919;
          case 2350 : return 12167;
          case 2375 : return 20363;
          case 2390 : return 19487;
        }
      }
      if (a==2450) {
        switch (b) {
          case 127 : return 18327;
          case 150 : return 24304;
          case 175 : return 23195;
          case 200 : return 13511;
          case 300 : return 18373;
          case 400 : return 17108;
          case 500 : return 19580;
          case 600 : return 14541;
          case 700 : return 9769;
          case 800 : return 28235;
          case 900 : return 23266;
          case 1000 : return 25613;
          case 1100 : return 14693;
          case 1200 : return 17170;
          case 1300 : return 18363;
          case 1400 : return 19677;
          case 1500 : return 25800;
          case 1600 : return 22028;
          case 1700 : return 15984;
          case 1800 : return 13413;
          case 1900 : return 18387;
          case 2000 : return 9807;
          case 2100 : return 20772;
          case 2150 : return 15774;
          case 2200 : return 20789;
          case 2250 : return 20780;
          case 2300 : return 13386;
          case 2350 : return 24413;
          case 2400 : return 17007;
          case 2425 : return 24298;
          case 2440 : return 14600;
        }
      }
      if (a==2500) {
        switch (b) {
          case 127 : return 23458;
          case 150 : return 18345;
          case 175 : return 19786;
          case 200 : return 31038;
          case 300 : return 32236;
          case 400 : return 29958;
          case 500 : return 18580;
          case 600 : return 27153;
          case 700 : return 18559;
          case 800 : return 19759;
          case 900 : return 21123;
          case 1000 : return 18426;
          case 1100 : return 25981;
          case 1200 : return 17131;
          case 1300 : return 21163;
          case 1400 : return 25928;
          case 1500 : return 12387;
          case 1600 : return 13488;
          case 1700 : return 24781;
          case 1800 : return 21010;
          case 1900 : return 17343;
          case 2000 : return 11213;
          case 2100 : return 29785;
          case 2200 : return 19722;
          case 2250 : return 16199;
          case 2300 : return 14810;
          case 2350 : return 11122;
          case 2400 : return 16134;
          case 2450 : return 11040;
          case 2475 : return 22216;
          case 2490 : return 20989;
        }
      }
      if (a==2550) {
        switch (b) {
          case 127 : return 18848;
          case 150 : return 23670;
          case 175 : return 21312;
          case 200 : return 33517;
          case 300 : return 27649;
          case 400 : return 23866;
          case 500 : return 30356;
          case 600 : return 20063;
          case 700 : return 27605;
          case 800 : return 27579;
          case 900 : return 13896;
          case 1000 : return 19785;
          case 1100 : return 32353;
          case 1200 : return 21257;
          case 1300 : return 22677;
          case 1400 : return 12402;
          case 1500 : return 28737;
          case 1600 : return 27646;
          case 1700 : return 18646;
          case 1800 : return 20125;
          case 1900 : return 12453;
          case 2000 : return 18662;
          case 2100 : return 13711;
          case 2200 : return 22557;
          case 2250 : return 12357;
          case 2300 : return 22477;
          case 2350 : return 17405;
          case 2400 : return 21189;
          case 2450 : return 23879;
          case 2500 : return 17547;
          case 2525 : return 13835;
          case 2540 : return 21163;
        }
      }
      if (a==2600) {
        switch (b) {
          case 127 : return 30304;
          case 150 : return 20243;
          case 175 : return 17653;
          case 200 : return 18976;
          case 300 : return 18982;
          case 400 : return 24068;
          case 500 : return 25439;
          case 600 : return 8886;
          case 700 : return 20259;
          case 800 : return 22952;
          case 900 : return 17748;
          case 1000 : return 21420;
          case 1100 : return 12659;
          case 1200 : return 24199;
          case 1300 : return 13995;
          case 1400 : return 17696;
          case 1500 : return 20418;
          case 1600 : return 19163;
          case 1700 : return 25382;
          case 1800 : return 25326;
          case 1900 : return 25330;
          case 2000 : return 16450;
          case 2100 : return 16570;
          case 2200 : return 15105;
          case 2300 : return 18789;
          case 2350 : return 30495;
          case 2400 : return 18893;
          case 2450 : return 18944;
          case 2500 : return 17757;
          case 2550 : return 15229;
          case 2575 : return 11381;
          case 2590 : return 17690;
        }
      }
      if (a==2650) {
        switch (b) {
          case 127 : return 28034;
          case 150 : return 21876;
          case 175 : return 21789;
          case 200 : return 16736;
          case 300 : return 15276;
          case 400 : return 24408;
          case 500 : return 19474;
          case 600 : return 21828;
          case 700 : return 21734;
          case 800 : return 28297;
          case 900 : return 30772;
          case 1000 : return 17926;
          case 1100 : return 28259;
          case 1200 : return 27097;
          case 1300 : return 19289;
          case 1400 : return 18072;
          case 1500 : return 28229;
          case 1600 : return 12974;
          case 1700 : return 15456;
          case 1800 : return 20551;
          case 1900 : return 24251;
          case 2000 : return 17869;
          case 2100 : return 28102;
          case 2200 : return 15326;
          case 2300 : return 12910;
          case 2350 : return 12710;
          case 2400 : return 14083;
          case 2450 : return 10217;
          case 2500 : return 20513;
          case 2550 : return 15428;
          case 2600 : return 25471;
          case 2625 : return 22074;
          case 2640 : return 21685;
        }
      }
      if (a==2700) {
        switch (b) {
          case 127 : return 23329;
          case 150 : return 23187;
          case 175 : return 15418;
          case 200 : return 15388;
          case 300 : return 18088;
          case 400 : return 24796;
          case 500 : return 37647;
          case 600 : return 24663;
          case 700 : return 21997;
          case 800 : return 21957;
          case 900 : return 15536;
          case 1000 : return 24862;
          case 1100 : return 17960;
          case 1200 : return 10401;
          case 1300 : return 16673;
          case 1400 : return 23109;
          case 1500 : return 14370;
          case 1600 : return 20647;
          case 1700 : return 15550;
          case 1800 : return 16900;
          case 1900 : return 16752;
          case 2000 : return 17976;
          case 2100 : return 27160;
          case 2200 : return 18147;
          case 2300 : return 18251;
          case 2400 : return 16808;
          case 2450 : return 29857;
          case 2500 : return 24818;
          case 2550 : return 11704;
          case 2600 : return 15686;
          case 2650 : return 20781;
          case 2675 : return 18116;
          case 2690 : return 30844;
        }
      }
      if (a==2750) {
        switch (b) {
          case 127 : return 26295;
          case 150 : return 13178;
          case 175 : return 17111;
          case 200 : return 18389;
          case 300 : return 26205;
          case 400 : return 15731;
          case 500 : return 21178;
          case 600 : return 24972;
          case 700 : return 15760;
          case 800 : return 23556;
          case 900 : return 19627;
          case 1000 : return 32807;
          case 1100 : return 19784;
          case 1200 : return 20922;
          case 1300 : return 15669;
          case 1400 : return 26155;
          case 1500 : return 21084;
          case 1600 : return 16993;
          case 1700 : return 25008;
          case 1800 : return 27634;
          case 1900 : return 31483;
          case 2000 : return 17034;
          case 2100 : return 16904;
          case 2200 : return 27657;
          case 2300 : return 19617;
          case 2400 : return 7793;
          case 2450 : return 13114;
          case 2500 : return 22333;
          case 2550 : return 13095;
          case 2600 : return 22264;
          case 2650 : return 9125;
          case 2700 : return 14492;
          case 2725 : return 12956;
          case 2740 : return 22208;
        }
      }
      if (a==2800) {
        switch (b) {
          case 127 : return 19843;
          case 150 : return 18529;
          case 175 : return 28910;
          case 200 : return 22651;
          case 300 : return 19730;
          case 400 : return 29268;
          case 500 : return 16036;
          case 600 : return 18540;
          case 700 : return 17223;
          case 800 : return 16063;
          case 900 : return 25059;
          case 1000 : return 21126;
          case 1100 : return 14658;
          case 1200 : return 27671;
          case 1300 : return 18472;
          case 1400 : return 22596;
          case 1500 : return 33034;
          case 1600 : return 30477;
          case 1700 : return 23980;
          case 1800 : return 19865;
          case 1900 : return 17252;
          case 2000 : return 25134;
          case 2100 : return 26467;
          case 2200 : return 25221;
          case 2300 : return 31557;
          case 2400 : return 17198;
          case 2500 : return 13418;
          case 2550 : return 15785;
          case 2600 : return 22558;
          case 2650 : return 26276;
          case 2700 : return 20034;
          case 2750 : return 18621;
          case 2775 : return 14355;
          case 2790 : return 20050;
        }
      }
      break;
      case 2018 :
      if (a==800) {
        switch (b) {
          case 127 : return 256999;
          case 200 : return 243726;
          case 300 : return 231228;
          case 400 : return 268028;
          case 500 : return 284270;
          case 600 : return 256774;
          case 700 : return 273839;
          case 790 : return 259296;
        }
      }
      if (a==900) {
        switch (b) {
          case 127 : return 253948;
          case 200 : return 243272;
          case 300 : return 288570;
          case 400 : return 265875;
          case 500 : return 256856;
          case 600 : return 260321;
          case 700 : return 249065;
          case 800 : return 257120;
          case 890 : return 238992;
        }
      }
      if (a==1000) {
        switch (b) {
          case 127 : return 269962;
          case 150 : return 287993;
          case 175 : return 263637;
          case 200 : return 291115;
          case 300 : return 248462;
          case 400 : return 267428;
          case 500 : return 270970;
          case 600 : return 253435;
          case 700 : return 231794;
          case 750 : return 242843;
          case 800 : return 248838;
          case 850 : return 258439;
          case 900 : return 257442;
          case 950 : return 265736;
          case 975 : return 248970;
          case 990 : return 245558;
        }
      }
      if (a==1050) {
        switch (b) {
          case 127 : return 245678;
          case 150 : return 263347;
          case 175 : return 225881;
          case 200 : return 256273;
          case 300 : return 252608;
          case 400 : return 261290;
          case 500 : return 271904;
          case 600 : return 259351;
          case 700 : return 269158;
          case 750 : return 278724;
          case 800 : return 255152;
          case 850 : return 252612;
          case 900 : return 259555;
          case 950 : return 265801;
          case 1000 : return 261829;
          case 1025 : return 267796;
          case 1040 : return 266903;
        }
      }
      if (a==1100) {
        switch (b) {
          case 127 : return 232511;
          case 150 : return 219002;
          case 175 : return 221294;
          case 200 : return 237439;
          case 300 : return 233630;
          case 400 : return 232836;
          case 500 : return 228782;
          case 600 : return 247959;
          case 700 : return 234425;
          case 800 : return 218362;
          case 850 : return 220449;
          case 900 : return 220679;
          case 950 : return 234255;
          case 1000 : return 214165;
          case 1050 : return 224118;
          case 1075 : return 213574;
          case 1090 : return 238570;
        }
      }
      if (a==1150) {
        switch (b) {
          case 127 : return 176570;
          case 150 : return 167231;
          case 175 : return 180697;
          case 200 : return 156600;
          case 300 : return 161124;
          case 400 : return 187529;
          case 500 : return 173434;
          case 600 : return 159337;
          case 700 : return 153741;
          case 800 : return 168651;
          case 850 : return 173365;
          case 900 : return 156897;
          case 950 : return 157709;
          case 1000 : return 142415;
          case 1050 : return 179896;
          case 1100 : return 151905;
          case 1125 : return 131090;
          case 1140 : return 154351;
        }
      }
      if (a==1200) {
        switch (b) {
          case 127 : return 116195;
          case 150 : return 114460;
          case 175 : return 149619;
          case 200 : return 130090;
          case 300 : return 125500;
          case 400 : return 118485;
          case 500 : return 109521;
          case 600 : return 99439;
          case 700 : return 126024;
          case 800 : return 127358;
          case 900 : return 100391;
          case 950 : return 116676;
          case 1000 : return 117515;
          case 1050 : return 113667;
          case 1100 : return 106850;
          case 1150 : return 120859;
          case 1175 : return 123788;
          case 1190 : return 113719;
        }
      }
      if (a==1250) {
        switch (b) {
          case 127 : return 92316;
          case 150 : return 91943;
          case 175 : return 82829;
          case 200 : return 85224;
          case 300 : return 95327;
          case 400 : return 87362;
          case 500 : return 95442;
          case 600 : return 85417;
          case 700 : return 76009;
          case 800 : return 86133;
          case 900 : return 81018;
          case 950 : return 76646;
          case 1000 : return 67409;
          case 1050 : return 88017;
          case 1100 : return 87478;
          case 1150 : return 78094;
          case 1200 : return 80935;
          case 1225 : return 87052;
          case 1240 : return 82780;
        }
      }
      if (a==1300) {
        switch (b) {
          case 127 : return 78815;
          case 150 : return 60337;
          case 175 : return 80723;
          case 200 : return 73183;
          case 300 : return 74665;
          case 400 : return 73478;
          case 500 : return 68896;
          case 600 : return 74228;
          case 700 : return 50702;
          case 800 : return 78521;
          case 900 : return 81257;
          case 1000 : return 59943;
          case 1050 : return 67093;
          case 1100 : return 60722;
          case 1150 : return 64260;
          case 1200 : return 68284;
          case 1250 : return 57851;
          case 1275 : return 79983;
          case 1290 : return 66070;
        }
      }
      if (a==1350) {
        switch (b) {
          case 127 : return 69678;
          case 150 : return 83206;
          case 175 : return 62035;
          case 200 : return 47698;
          case 300 : return 70663;
          case 400 : return 61370;
          case 500 : return 70245;
          case 600 : return 55627;
          case 700 : return 61053;
          case 800 : return 64819;
          case 900 : return 57555;
          case 1000 : return 64649;
          case 1050 : return 56222;
          case 1100 : return 71054;
          case 1150 : return 75059;
          case 1200 : return 53904;
          case 1250 : return 58440;
          case 1300 : return 76351;
          case 1325 : return 84377;
          case 1340 : return 67783;
        }
      }
      if (a==1400) {
        switch (b) {
          case 127 : return 69236;
          case 150 : return 75479;
          case 175 : return 75517;
          case 200 : return 69336;
          case 300 : return 65546;
          case 400 : return 80857;
          case 500 : return 58474;
          case 600 : return 64642;
          case 700 : return 74035;
          case 800 : return 76924;
          case 900 : return 48783;
          case 1000 : return 56935;
          case 1100 : return 78056;
          case 1150 : return 72763;
          case 1200 : return 67240;
          case 1250 : return 66518;
          case 1300 : return 69111;
          case 1350 : return 62970;
          case 1375 : return 61940;
          case 1390 : return 64308;
        }
      }
      if (a==1450) {
        switch (b) {
          case 127 : return 69091;
          case 150 : return 86529;
          case 175 : return 68972;
          case 200 : return 62658;
          case 300 : return 52813;
          case 400 : return 84190;
          case 500 : return 62523;
          case 600 : return 65573;
          case 700 : return 66373;
          case 800 : return 62270;
          case 900 : return 60375;
          case 1000 : return 63730;
          case 1100 : return 60255;
          case 1150 : return 67143;
          case 1200 : return 42600;
          case 1250 : return 59900;
          case 1300 : return 72826;
          case 1350 : return 81150;
          case 1400 : return 77808;
          case 1425 : return 75329;
          case 1440 : return 58172;
        }
      }
      if (a==1500) {
        switch (b) {
          case 127 : return 47685;
          case 150 : return 55270;
          case 175 : return 70948;
          case 200 : return 82567;
          case 300 : return 89929;
          case 400 : return 62989;
          case 500 : return 63822;
          case 600 : return 62366;
          case 700 : return 67334;
          case 800 : return 68756;
          case 900 : return 73658;
          case 1000 : return 77373;
          case 1100 : return 68904;
          case 1200 : return 65160;
          case 1250 : return 59299;
          case 1300 : return 65417;
          case 1350 : return 55536;
          case 1400 : return 55527;
          case 1450 : return 61415;
          case 1475 : return 54270;
          case 1490 : return 65777;
        }
      }
      if (a==1550) {
        switch (b) {
          case 127 : return 78211;
          case 150 : return 62977;
          case 175 : return 66501;
          case 200 : return 60953;
          case 300 : return 58083;
          case 400 : return 54137;
          case 500 : return 62997;
          case 600 : return 71604;
          case 700 : return 67693;
          case 800 : return 70774;
          case 900 : return 55852;
          case 1000 : return 57085;
          case 1100 : return 69543;
          case 1200 : return 67806;
          case 1250 : return 66404;
          case 1300 : return 63971;
          case 1350 : return 65843;
          case 1400 : return 58387;
          case 1450 : return 71305;
          case 1500 : return 73619;
          case 1525 : return 67424;
          case 1540 : return 51979;
        }
      }
      if (a==1600) {
        switch (b) {
          case 127 : return 58343;
          case 150 : return 65282;
          case 175 : return 70054;
          case 200 : return 62395;
          case 300 : return 63422;
          case 400 : return 68179;
          case 500 : return 53605;
          case 600 : return 64566;
          case 700 : return 63299;
          case 800 : return 68244;
          case 900 : return 73036;
          case 1000 : return 49741;
          case 1100 : return 59543;
          case 1200 : return 64525;
          case 1300 : return 57787;
          case 1350 : return 57391;
          case 1400 : return 60606;
          case 1450 : return 55795;
          case 1500 : return 64304;
          case 1550 : return 64944;
          case 1575 : return 71031;
          case 1590 : return 56241;
        }
      }
      if (a==1650) {
        switch (b) {
          case 127 : return 66073;
          case 150 : return 61144;
          case 175 : return 63201;
          case 200 : return 68262;
          case 300 : return 63006;
          case 400 : return 57543;
          case 500 : return 65264;
          case 600 : return 63240;
          case 700 : return 66035;
          case 800 : return 56285;
          case 900 : return 84656;
          case 1000 : return 83964;
          case 1100 : return 64304;
          case 1200 : return 73434;
          case 1300 : return 82804;
          case 1350 : return 64440;
          case 1400 : return 62469;
          case 1450 : return 52523;
          case 1500 : return 59452;
          case 1550 : return 53407;
          case 1600 : return 42378;
          case 1625 : return 45491;
          case 1640 : return 61942;
        }
      }
      if (a==1700) {
        switch (b) {
          case 127 : return 66946;
          case 150 : return 71218;
          case 175 : return 71000;
          case 200 : return 69053;
          case 300 : return 94870;
          case 400 : return 79913;
          case 500 : return 67174;
          case 600 : return 77714;
          case 700 : return 59181;
          case 800 : return 81819;
          case 900 : return 72813;
          case 1000 : return 74886;
          case 1100 : return 76394;
          case 1200 : return 61613;
          case 1300 : return 63063;
          case 1400 : return 65023;
          case 1450 : return 65954;
          case 1500 : return 84797;
          case 1550 : return 74356;
          case 1600 : return 70952;
          case 1650 : return 72447;
          case 1675 : return 59776;
          case 1690 : return 58940;
        }
      }
      if (a==1750) {
        switch (b) {
          case 127 : return 71155;
          case 150 : return 78763;
          case 175 : return 75955;
          case 200 : return 74317;
          case 300 : return 73070;
          case 400 : return 72836;
          case 500 : return 65876;
          case 600 : return 69047;
          case 700 : return 71026;
          case 800 : return 71028;
          case 900 : return 73682;
          case 1000 : return 64277;
          case 1100 : return 61667;
          case 1200 : return 75139;
          case 1300 : return 69036;
          case 1400 : return 54927;
          case 1450 : return 78285;
          case 1500 : return 57842;
          case 1550 : return 53594;
          case 1600 : return 51263;
          case 1650 : return 43562;
          case 1700 : return 57710;
          case 1725 : return 74953;
          case 1740 : return 58728;
        }
      }
      if (a==1800) {
        switch (b) {
          case 127 : return 73983;
          case 150 : return 58690;
          case 175 : return 65738;
          case 200 : return 67723;
          case 300 : return 51525;
          case 400 : return 62720;
          case 500 : return 65896;
          case 600 : return 62389;
          case 700 : return 74860;
          case 800 : return 66443;
          case 900 : return 73740;
          case 1000 : return 57210;
          case 1100 : return 58291;
          case 1200 : return 68706;
          case 1300 : return 62818;
          case 1400 : return 55564;
          case 1500 : return 54420;
          case 1550 : return 54420;
          case 1600 : return 69893;
          case 1650 : return 59369;
          case 1700 : return 57909;
          case 1750 : return 55534;
          case 1775 : return 66832;
          case 1790 : return 50308;
        }
      }
      if (a==1850) {
        switch (b) {
          case 127 : return 66524;
          case 150 : return 62362;
          case 175 : return 79199;
          case 200 : return 72729;
          case 300 : return 66471;
          case 400 : return 66313;
          case 500 : return 69858;
          case 600 : return 71539;
          case 700 : return 51228;
          case 800 : return 64504;
          case 900 : return 55084;
          case 1000 : return 76931;
          case 1100 : return 75694;
          case 1200 : return 66790;
          case 1300 : return 56410;
          case 1400 : return 63690;
          case 1500 : return 58558;
          case 1550 : return 56053;
          case 1600 : return 67525;
          case 1650 : return 44909;
          case 1700 : return 64359;
          case 1750 : return 55093;
          case 1800 : return 60785;
          case 1825 : return 57625;
          case 1840 : return 54901;
        }
      }
      if (a==1900) {
        switch (b) {
          case 127 : return 54081;
          case 150 : return 68438;
          case 175 : return 72830;
          case 200 : return 72781;
          case 300 : return 62404;
          case 400 : return 61245;
          case 500 : return 72549;
          case 600 : return 69715;
          case 700 : return 61267;
          case 800 : return 62213;
          case 900 : return 64091;
          case 1000 : return 73568;
          case 1100 : return 56985;
          case 1200 : return 56213;
          case 1300 : return 57767;
          case 1400 : return 57660;
          case 1500 : return 60918;
          case 1600 : return 62004;
          case 1650 : return 54946;
          case 1700 : return 62141;
          case 1750 : return 52753;
          case 1800 : return 50996;
          case 1850 : return 63609;
          case 1875 : return 56789;
          case 1890 : return 72418;
        }
      }
      if (a==1950) {
        switch (b) {
          case 127 : return 66185;
          case 150 : return 78786;
          case 175 : return 55440;
          case 200 : return 54727;
          case 300 : return 67603;
          case 400 : return 70657;
          case 500 : return 70616;
          case 600 : return 65419;
          case 700 : return 70795;
          case 800 : return 68423;
          case 900 : return 55699;
          case 1000 : return 82678;
          case 1100 : return 68414;
          case 1200 : return 58826;
          case 1300 : return 46751;
          case 1400 : return 52655;
          case 1500 : return 65072;
          case 1600 : return 50101;
          case 1650 : return 58595;
          case 1700 : return 63343;
          case 1750 : return 58114;
          case 1800 : return 62948;
          case 1850 : return 60748;
          case 1900 : return 64487;
          case 1925 : return 64292;
          case 1940 : return 73354;
        }
      }
      if (a==2000) {
        switch (b) {
          case 127 : return 37957;
          case 150 : return 32562;
          case 175 : return 29466;
          case 200 : return 34726;
          case 300 : return 30146;
          case 400 : return 32534;
          case 500 : return 39950;
          case 600 : return 29189;
          case 700 : return 37939;
          case 800 : return 41825;
          case 900 : return 42213;
          case 1000 : return 32216;
          case 1100 : return 31681;
          case 1200 : return 31365;
          case 1300 : return 32775;
          case 1400 : return 32667;
          case 1500 : return 29178;
          case 1600 : return 34740;
          case 1700 : return 29266;
          case 1750 : return 31372;
          case 1800 : return 15136;
          case 1850 : return 28117;
          case 1900 : return 28084;
          case 1950 : return 28087;
          case 1975 : return 24129;
          case 1990 : return 35921;
        }
      }
      if (a==2050) {
        switch (b) {
          case 127 : return 34953;
          case 150 : return 30776;
          case 175 : return 30848;
          case 200 : return 38473;
          case 300 : return 32865;
          case 400 : return 25214;
          case 500 : return 36334;
          case 600 : return 37389;
          case 700 : return 29621;
          case 800 : return 25353;
          case 900 : return 26393;
          case 1000 : return 25349;
          case 1100 : return 22029;
          case 1200 : return 31785;
          case 1300 : return 31803;
          case 1400 : return 41636;
          case 1500 : return 30497;
          case 1600 : return 42639;
          case 1700 : return 25346;
          case 1750 : return 38530;
          case 1800 : return 31012;
          case 1850 : return 35059;
          case 1900 : return 39588;
          case 1950 : return 24267;
          case 2000 : return 32927;
          case 2025 : return 27383;
          case 2040 : return 26317;
        }
      }
      if (a==2100) {
        switch (b) {
          case 127 : return 30095;
          case 150 : return 28865;
          case 175 : return 28962;
          case 200 : return 40216;
          case 300 : return 41091;
          case 400 : return 31328;
          case 500 : return 22263;
          case 600 : return 27885;
          case 700 : return 35535;
          case 800 : return 29983;
          case 900 : return 35509;
          case 1000 : return 34536;
          case 1100 : return 23367;
          case 1200 : return 34238;
          case 1300 : return 35751;
          case 1400 : return 29051;
          case 1500 : return 36693;
          case 1600 : return 18914;
          case 1700 : return 16671;
          case 1800 : return 24479;
          case 1850 : return 27875;
          case 1900 : return 28734;
          case 1950 : return 31200;
          case 2000 : return 19054;
          case 2050 : return 25711;
          case 2075 : return 31287;
          case 2090 : return 25499;
        }
      }
      if (a==2150) {
        switch (b) {
          case 127 : return 30688;
          case 150 : return 31533;
          case 175 : return 31565;
          case 200 : return 31409;
          case 300 : return 26160;
          case 400 : return 41848;
          case 500 : return 30631;
          case 600 : return 47064;
          case 700 : return 33957;
          case 800 : return 25020;
          case 900 : return 30469;
          case 1000 : return 33859;
          case 1100 : return 20107;
          case 1200 : return 28095;
          case 1300 : return 36140;
          case 1400 : return 29160;
          case 1500 : return 31868;
          case 1600 : return 32769;
          case 1700 : return 27340;
          case 1800 : return 30525;
          case 1850 : return 27053;
          case 1900 : return 30552;
          case 1950 : return 23831;
          case 2000 : return 35998;
          case 2050 : return 25077;
          case 2100 : return 20181;
          case 2125 : return 29325;
          case 2140 : return 29109;
        }
      }
      if (a==2200) {
        switch (b) {
          case 127 : return 35357;
          case 150 : return 33151;
          case 175 : return 32043;
          case 200 : return 43581;
          case 300 : return 27525;
          case 400 : return 25108;
          case 500 : return 32096;
          case 600 : return 28603;
          case 700 : return 20592;
          case 800 : return 26336;
          case 900 : return 32153;
          case 1000 : return 36530;
          case 1100 : return 42482;
          case 1200 : return 36711;
          case 1300 : return 36643;
          case 1400 : return 31173;
          case 1500 : return 17103;
          case 1600 : return 27484;
          case 1700 : return 36564;
          case 1800 : return 32447;
          case 1900 : return 31021;
          case 1950 : return 24016;
          case 2000 : return 30056;
          case 2050 : return 28605;
          case 2100 : return 21669;
          case 2150 : return 28609;
          case 2175 : return 18234;
          case 2190 : return 21868;
        }
      }
      if (a==2250) {
        switch (b) {
          case 127 : return 24302;
          case 150 : return 35888;
          case 175 : return 28933;
          case 200 : return 27783;
          case 300 : return 31245;
          case 400 : return 32521;
          case 500 : return 22069;
          case 600 : return 34912;
          case 700 : return 25347;
          case 800 : return 33616;
          case 900 : return 22254;
          case 1000 : return 25437;
          case 1100 : return 30043;
          case 1200 : return 38316;
          case 1300 : return 27912;
          case 1400 : return 38434;
          case 1500 : return 35715;
          case 1600 : return 29002;
          case 1700 : return 24420;
          case 1800 : return 44042;
          case 1900 : return 28911;
          case 1950 : return 27846;
          case 2000 : return 44283;
          case 2050 : return 18698;
          case 2100 : return 34790;
          case 2150 : return 34721;
          case 2200 : return 25577;
          case 2225 : return 31482;
          case 2240 : return 33788;
        }
      }
      if (a==2300) {
        switch (b) {
          case 127 : return 32726;
          case 150 : return 34195;
          case 175 : return 27139;
          case 200 : return 37689;
          case 300 : return 31671;
          case 400 : return 33200;
          case 500 : return 18748;
          case 600 : return 28139;
          case 700 : return 37697;
          case 800 : return 27190;
          case 900 : return 25849;
          case 1000 : return 39987;
          case 1100 : return 32854;
          case 1200 : return 39895;
          case 1300 : return 30612;
          case 1400 : return 34103;
          case 1500 : return 32895;
          case 1600 : return 24555;
          case 1700 : return 32995;
          case 1800 : return 24723;
          case 1900 : return 19692;
          case 2000 : return 23618;
          case 2050 : return 35545;
          case 2100 : return 28274;
          case 2150 : return 31625;
          case 2200 : return 37391;
          case 2250 : return 24706;
          case 2275 : return 38750;
          case 2290 : return 33940;
        }
      }
      if (a==2350) {
        switch (b) {
          case 127 : return 32105;
          case 150 : return 39309;
          case 175 : return 32220;
          case 200 : return 31130;
          case 300 : return 28506;
          case 400 : return 27310;
          case 500 : return 32123;
          case 600 : return 23820;
          case 700 : return 26410;
          case 800 : return 28540;
          case 900 : return 34658;
          case 1000 : return 29790;
          case 1100 : return 23800;
          case 1200 : return 29559;
          case 1300 : return 26271;
          case 1400 : return 35659;
          case 1500 : return 38166;
          case 1600 : return 27491;
          case 1700 : return 28292;
          case 1800 : return 26093;
          case 1900 : return 30804;
          case 2000 : return 32063;
          case 2050 : return 24911;
          case 2100 : return 19023;
          case 2150 : return 26342;
          case 2200 : return 20359;
          case 2250 : return 28696;
          case 2300 : return 35694;
          case 2325 : return 23846;
          case 2340 : return 28355;
        }
      }
      if (a==2400) {
        switch (b) {
          case 127 : return 37478;
          case 150 : return 33737;
          case 175 : return 32790;
          case 200 : return 37262;
          case 300 : return 30234;
          case 400 : return 36183;
          case 500 : return 26465;
          case 600 : return 32765;
          case 700 : return 27689;
          case 800 : return 41069;
          case 900 : return 25424;
          case 1000 : return 33944;
          case 1100 : return 33727;
          case 1200 : return 25492;
          case 1300 : return 27745;
          case 1400 : return 30156;
          case 1500 : return 31484;
          case 1600 : return 20457;
          case 1700 : return 26497;
          case 1800 : return 30050;
          case 1900 : return 25319;
          case 2000 : return 21871;
          case 2100 : return 20718;
          case 2150 : return 41060;
          case 2200 : return 24166;
          case 2250 : return 13351;
          case 2300 : return 29257;
          case 2350 : return 24226;
          case 2375 : return 21667;
          case 2390 : return 27853;
        }
      }
      if (a==2450) {
        switch (b) {
          case 127 : return 31777;
          case 150 : return 21931;
          case 175 : return 33968;
          case 200 : return 11086;
          case 300 : return 23272;
          case 400 : return 29547;
          case 500 : return 23337;
          case 600 : return 29971;
          case 700 : return 38817;
          case 800 : return 26828;
          case 900 : return 29458;
          case 1000 : return 34153;
          case 1100 : return 36308;
          case 1200 : return 36600;
          case 1300 : return 37679;
          case 1400 : return 19419;
          case 1500 : return 30659;
          case 1600 : return 26841;
          case 1700 : return 29295;
          case 1800 : return 35361;
          case 1900 : return 27127;
          case 2000 : return 25800;
          case 2100 : return 27018;
          case 2150 : return 32029;
          case 2200 : return 32770;
          case 2250 : return 32760;
          case 2300 : return 39082;
          case 2350 : return 30792;
          case 2400 : return 30591;
          case 2425 : return 24518;
          case 2440 : return 27934;
        }
      }
      if (a==2500) {
        switch (b) {
          case 127 : return 33322;
          case 150 : return 34418;
          case 175 : return 28388;
          case 200 : return 17437;
          case 300 : return 38279;
          case 400 : return 35996;
          case 500 : return 30953;
          case 600 : return 25798;
          case 700 : return 35794;
          case 800 : return 31176;
          case 900 : return 34714;
          case 1000 : return 38468;
          case 1100 : return 38085;
          case 1200 : return 28364;
          case 1300 : return 34632;
          case 1400 : return 31945;
          case 1500 : return 23322;
          case 1600 : return 23419;
          case 1700 : return 29889;
          case 1800 : return 29810;
          case 1900 : return 23370;
          case 2000 : return 30972;
          case 2100 : return 28535;
          case 2200 : return 27257;
          case 2250 : return 18623;
          case 2300 : return 23496;
          case 2350 : return 22329;
          case 2400 : return 33128;
          case 2450 : return 30830;
          case 2475 : return 23708;
          case 2490 : return 33249;
        }
      }
      if (a==2550) {
        switch (b) {
          case 127 : return 24922;
          case 150 : return 32543;
          case 175 : return 36422;
          case 200 : return 30188;
          case 300 : return 26220;
          case 400 : return 30072;
          case 500 : return 35066;
          case 600 : return 27573;
          case 700 : return 23640;
          case 800 : return 22422;
          case 900 : return 33963;
          case 1000 : return 23554;
          case 1100 : return 46419;
          case 1200 : return 29865;
          case 1300 : return 27523;
          case 1400 : return 36263;
          case 1500 : return 39868;
          case 1600 : return 41297;
          case 1700 : return 27527;
          case 1800 : return 29984;
          case 1900 : return 22632;
          case 2000 : return 19981;
          case 2100 : return 38643;
          case 2200 : return 24973;
          case 2250 : return 31242;
          case 2300 : return 38871;
          case 2350 : return 22764;
          case 2400 : return 32331;
          case 2450 : return 27617;
          case 2500 : return 23912;
          case 2525 : return 17455;
          case 2540 : return 19925;
        }
      }
      if (a==2600) {
        switch (b) {
          case 127 : return 33954;
          case 150 : return 23932;
          case 175 : return 20277;
          case 200 : return 26499;
          case 300 : return 29041;
          case 400 : return 29099;
          case 500 : return 30175;
          case 600 : return 24049;
          case 700 : return 32810;
          case 800 : return 31713;
          case 900 : return 24212;
          case 1000 : return 25314;
          case 1100 : return 23920;
          case 1200 : return 30485;
          case 1300 : return 34210;
          case 1400 : return 25415;
          case 1500 : return 26730;
          case 1600 : return 32874;
          case 1700 : return 23995;
          case 1800 : return 28944;
          case 1900 : return 39096;
          case 2000 : return 20130;
          case 2100 : return 22599;
          case 2200 : return 13931;
          case 2300 : return 36563;
          case 2350 : return 22750;
          case 2400 : return 22797;
          case 2450 : return 25378;
          case 2500 : return 22735;
          case 2550 : return 31678;
          case 2575 : return 32847;
          case 2590 : return 35408;
        }
      }
      if (a==2650) {
        switch (b) {
          case 127 : return 29585;
          case 150 : return 28077;
          case 175 : return 30697;
          case 200 : return 30663;
          case 300 : return 49859;
          case 400 : return 28040;
          case 500 : return 46313;
          case 600 : return 33188;
          case 700 : return 33142;
          case 800 : return 38533;
          case 900 : return 33405;
          case 1000 : return 15262;
          case 1100 : return 37156;
          case 1200 : return 30790;
          case 1300 : return 30982;
          case 1400 : return 33487;
          case 1500 : return 42428;
          case 1600 : return 34558;
          case 1700 : return 30719;
          case 1800 : return 30648;
          case 1900 : return 34560;
          case 2000 : return 33295;
          case 2100 : return 22986;
          case 2200 : return 34429;
          case 2300 : return 17863;
          case 2350 : return 23150;
          case 2400 : return 29426;
          case 2450 : return 24246;
          case 2500 : return 24306;
          case 2550 : return 26792;
          case 2600 : return 15327;
          case 2625 : return 34427;
          case 2640 : return 21650;
        }
      }
      if (a==2700) {
        switch (b) {
          case 127 : return 46212;
          case 150 : return 28463;
          case 175 : return 34953;
          case 200 : return 30065;
          case 300 : return 32378;
          case 400 : return 29923;
          case 500 : return 33508;
          case 600 : return 29886;
          case 700 : return 31241;
          case 800 : return 20757;
          case 900 : return 24329;
          case 1000 : return 34936;
          case 1100 : return 23326;
          case 1200 : return 25944;
          case 1300 : return 32533;
          case 1400 : return 33792;
          case 1500 : return 20710;
          case 1600 : return 34855;
          case 1700 : return 33733;
          case 1800 : return 20735;
          case 1900 : return 15757;
          case 2000 : return 29739;
          case 2100 : return 32367;
          case 2200 : return 20688;
          case 2300 : return 19515;
          case 2400 : return 39057;
          case 2450 : return 31116;
          case 2500 : return 25915;
          case 2550 : return 27132;
          case 2600 : return 25928;
          case 2650 : return 23393;
          case 2675 : return 25878;
          case 2690 : return 35024;
        }
      }
      if (a==2750) {
        switch (b) {
          case 127 : return 29880;
          case 150 : return 28800;
          case 175 : return 24651;
          case 200 : return 38131;
          case 300 : return 40571;
          case 400 : return 31268;
          case 500 : return 35176;
          case 600 : return 28959;
          case 700 : return 32913;
          case 800 : return 31498;
          case 900 : return 39415;
          case 1000 : return 18402;
          case 1100 : return 30243;
          case 1200 : return 27638;
          case 1300 : return 27532;
          case 1400 : return 35062;
          case 1500 : return 30020;
          case 1600 : return 23532;
          case 1700 : return 39359;
          case 1800 : return 27489;
          case 1900 : return 25099;
          case 2000 : return 19638;
          case 2100 : return 27524;
          case 2200 : return 22335;
          case 2300 : return 22216;
          case 2400 : return 28734;
          case 2450 : return 26226;
          case 2500 : return 23499;
          case 2550 : return 19773;
          case 2600 : return 32854;
          case 2650 : return 26177;
          case 2700 : return 27522;
          case 2725 : return 26163;
          case 2740 : return 18373;
        }
      }
      if (a==2800) {
        switch (b) {
          case 127 : return 31644;
          case 150 : return 34428;
          case 175 : return 25289;
          case 200 : return 22250;
          case 300 : return 26380;
          case 400 : return 23877;
          case 500 : return 34491;
          case 600 : return 22562;
          case 700 : return 25140;
          case 800 : return 38593;
          case 900 : return 37047;
          case 1000 : return 26373;
          case 1100 : return 39559;
          case 1200 : return 38449;
          case 1300 : return 45188;
          case 1400 : return 21150;
          case 1500 : return 23765;
          case 1600 : return 32962;
          case 1700 : return 37162;
          case 1800 : return 22545;
          case 1900 : return 33230;
          case 2000 : return 30392;
          case 2100 : return 22422;
          case 2200 : return 34520;
          case 2300 : return 25058;
          case 2400 : return 21150;
          case 2500 : return 28935;
          case 2550 : return 19731;
          case 2600 : return 26894;
          case 2650 : return 22601;
          case 2700 : return 30485;
          case 2750 : return 26395;
          case 2775 : return 26247;
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
  return 0;
}

std::map<pair<int,int>,int> init_signal_event(int SignalScenario) {
  std::map<pair<int,int>,int> output;
  if (SignalScenario==1) {
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
  return output;
}
#endif
