# GbbMET<br>

git clone https://github.com/bartokm/GbbMET.git

#####Skimmer<br>
Write skimming condition in CopyTree event loop<br>
Run CopyTree in root:<br>
.L CopyTree.C<br>
CopyTree t({"file1.root","file2.root",...},"outputname",Xsec)<br>
t.Loop()<br>
Or use the script: skimmer.csh

#####BTagEff<br>
This code calculates MC BTag efficiencies and puts the results in a root file.<br>
The output is needed as an input for Analyzer if running on MC.<br>

#####Analyzer<br>
First you need some files:<br>
Photon ScaleFactors: https://twiki.cern.ch/twiki/bin/view/CMS/EgammaIDRecipesRun2<br>
BTag ScaleFactors: https://twiki.cern.ch/twiki/bin/view/CMS/BtagRecommendation<br>
cern AFS acces (for data pileup distribution)<br>
kinit user@CERN.CH<br>
aklog CERN.CH<br>
You need to have root without CMSSW environment! (else BTag SFs won't compile)<br>
Run Analyzer in root<br>
.L Analyzer.C<br>
Analyzer t({"file1.root","file2.root",...},"outputfile.root","../BTagEff/btagfilename.root") <br>
t.Loop() <br>
Or use thr scripts: run_analyzer_data.csh, run_analyzer_mc.csh
