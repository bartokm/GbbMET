#!/usr/local/bin/tcsh
set INPUT1="/data/bartokm/Analysis/ntuples/Bkg_MC/80X_V08_00_26/TTJets_Pho165_HE10_CopyTree_skimmed.root"

set OUTPUT="test.root"
set BTAGFILE="../BTagEff/TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8_BTagEff.root"
set CUTS="HLTPho and 4096 nPassPhoL great 0 phoCalibEt great 175"

./Analyzer -i $INPUT1 -o $OUTPUT -b $BTAGFILE --cuts $CUTS
exit 0
