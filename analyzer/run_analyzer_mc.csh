#!/usr/local/bin/tcsh
set INPUT1="~/Analysis/ntuples/Bkg_MC/80X_V08_00_24/CopyTree_skimmed_TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8.root"

set OUTPUT="test.root"
set BTAGFILE="../BTagEff/TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8_BTagEff.root"

root << !
.L Analyzer.C
Analyzer t({"$INPUT1"}, "$OUTPUT","$BTAGFILE")
t.Loop()
.q
!
exit 0
