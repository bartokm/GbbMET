#!/usr/local/bin/tcsh
set INPUT1="/data/gridout/mbartok/Analysis/BkgMC/CMSSW8024p1/job_summer16_GJet/GJet_Pt-15To6000_TuneCUETP8M1-Flat_13TeV_pythia8_20M/ggNtuple_V08_00_24_00/161216_111111/0000/ggtree_mc_1.root"
set INPUT2="/data/gridout/mbartok/Analysis/BkgMC/CMSSW8024p1/job_summer16_GJet/GJet_Pt-15To6000_TuneCUETP8M1-Flat_13TeV_pythia8_20M/ggNtuple_V08_00_24_00/161216_111111/0000/ggtree_mc_2.root"

set OUTPUT="../test"
set XSEC=2

set currentdir=$PWD

root << !
.L CopyTree.C
CopyTree t({"$INPUT1","$INPUT2"}, "$OUTPUT",$XSEC)
t.Loop()
.q
!
cd $currentdir
exit 0
