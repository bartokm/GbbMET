#!/usr/local/bin/tcsh
set INPUT1="/data/gridout/mbartok/Analysis/BkgMC/CMSSW8024p1/job_summer16_TTJets/TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8/ggNtuple_V08_00_24_00/170110_110035/0000/ggtree_mc_1.root"

set OUTPUT="test"

root << !
.L BTagEff.C
BTagEff t({"$INPUT1"}, "$OUTPUT")
t.Loop()
.q
!
exit 0
