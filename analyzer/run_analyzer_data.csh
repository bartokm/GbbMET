#!/usr/local/bin/tcsh
set INPUT1="/data/bartokm/Analysis/ntuples/Data/80X_V08_00_26/Run2016B_Pho165_HE10_CopyTree_skimmed.root"

set OUTPUT="test.root"
set CUTS="HLTPho and 4096 nPassPhoL great 0 phoCalibEt great 175"

./Analyzer -i $INPUT1 -o $OUTPUT --cuts $CUTS
exit 0
