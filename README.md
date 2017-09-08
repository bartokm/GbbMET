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
Electron & Photon ScaleFactors: https://twiki.cern.ch/twiki/bin/view/CMS/EgammaIDRecipesRun2<br>
BTag ScaleFactors: https://twiki.cern.ch/twiki/bin/view/CMS/BtagRecommendation<br>
Data pileup distribution: /afs/cern.ch/work/m/mbartok/public/data/ggNtuples/13TeV_data/PILEUP/Full2016PileUp_ReReco_FINALCert_forggNtuple.root<br>
Compile analyzer with makefile, then run Analyzer. Note: there is a warning after compilation, please ignore it.<br>
```bash
make clean; make
./Analyzer -h
```
Or use the scripts: run_analyzer_data.csh, run_analyzer_mc.csh
