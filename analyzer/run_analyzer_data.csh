#!/usr/local/bin/tcsh
set INPUT1="/data/bartokm/Analysis/ntuples/Data/Run2016Bv3_CopyTree_skimmed.root"

set OUTPUT="test.root"

root << !
.L Analyzer.C
Analyzer t({"$INPUT1"}, "$OUTPUT")
t.Loop()
.q
!
exit 0
