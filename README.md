# GbbMET<br>

git clone https://github.com/bartokm/GbbMET.git

#####Skimmer<br>
Write skimming condition in CopyTree event loop<br>
Run CopyTree in root:<br>
```bash
.L CopyTree.C
CopyTree t({"file1.root","file2.root",...},"outputname",Xsec)
t.Loop()
```
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
Run Analyzer in root<br>
```bash
.L Analyzer.C
Analyzer t({"file1.root","file2.root",...},"outputfile.root","../BTagEff/btagfilename.root")
t.Loop()
```
Or use thr scripts: run_analyzer_data.csh, run_analyzer_mc.csh
