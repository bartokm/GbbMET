#include "TString.h"
#include <TH1F.h>
#include <iostream>
#include <THStack.h>
#include "tdrstyle.C"
using namespace std;

void Plotter(){
  setTDRStyle();
  //string outputtag = "_blinded_nobtag_cut_jetcut.root";
  string outputtag = "_Pho90_1Jet.root";
  string pretag = "histos/Analyzer_histos_";
  string data = "Data";
  string bkg[8] = {"TTJets","TTGJets","WJetsToLNu","WGJets","QCD","GJets","ZJetsToNuNu","ZGTo2NuG"};
  string signal[9] = {"mCh400_mN200","mCh600_mN200","mCh600_mN400","mCh800_mN200","mCh800_mN400","mCh800_mN600","mG1000_mN200","mG1000_mN400","mG1000_mN600"};
  string PlotOutput = "plots/Plots"+outputtag;
  vector<int> whichBkg = {6,7,0,1,2,3,4,5};
  //vector<int> whichSignal = {0,1,2,3,4,5,6,7,8};
  vector<int> whichSignal = {0,1,6,7,8};

  bool plotData = false;
  bool plotSignal = true;
  bool plotBkg = true;

  gROOT->SetBatch(true);

  TLegend *leg = new TLegend(0.55,0.45,0.9,0.85,"");
  TObjArray *DataHistos = new TObjArray();
  TObjArray *BkgStack = new TObjArray();
  vector<TObjArray*> SignalArrays;
  vector<string> histoNames;

  if (plotData) {
    histoNames.clear();
    string filename = pretag+data+outputtag;
    TFile f(filename.c_str(),"read");
    TIter next(f.GetListOfKeys());
    TKey *key;
    while ((key = (TKey*)next())) {
      TClass *cl = gROOT->GetClass(key->GetClassName());
      if (!cl->InheritsFrom("TH1")) continue;
      TH1 *h = (TH1*)key->ReadObj();
      h->SetMarkerStyle(21);
      h->SetDirectory(0);
      histoNames.push_back(h->GetName());
      DataHistos->Add(h);
    }
    leg->AddEntry(DataHistos->At(0),"Data", "P");
    f.Close();
  }
  
  if (plotBkg) {
    int fori=0;
    vector<THStack*> v_stack;
    for (auto i : whichBkg){
      histoNames.clear();
      string filename = pretag+bkg[i]+outputtag;
      TFile f(filename.c_str(),"read");
      TIter next(f.GetListOfKeys());
      TKey *key;
      int j=0;
      while ((key = (TKey*)next())) {
        TClass *cl = gROOT->GetClass(key->GetClassName());
        if (!cl->InheritsFrom("TH1")) continue;
        TH1 *h = (TH1*)key->ReadObj();
        h->SetFillColor(i+2);
        h->SetDirectory(0);
        if (fori==0) {THStack *stack = new THStack(); stack->Add(h); v_stack.push_back(stack);histoNames.push_back(h->GetName());}
        else v_stack.at(j)->Add(h);
        j++;
      }
      f.Close();
      fori++;
    }
    fori=0;
    for (const auto&& obj: *v_stack.at(0)->GetHists()) {leg->AddEntry(obj,bkg[whichBkg.at(fori)].c_str(),"f");fori++;}
    for (auto i : v_stack) BkgStack->Add(i);
  }
  
  if (plotSignal) {
    histoNames.clear();
    int fori=0;
    for (auto i : whichSignal){
      TObjArray *SignalHistos = new TObjArray();
      string filename = pretag+signal[i]+outputtag;
      TFile f(filename.c_str(),"read");
      TIter next(f.GetListOfKeys());
      TKey *key;
      while ((key = (TKey*)next())) {
        TClass *cl = gROOT->GetClass(key->GetClassName());
        if (!cl->InheritsFrom("TH1")) continue;
        TH1 *h = (TH1*)key->ReadObj();
        h->SetLineColor(9-i);
        h->SetMarkerColor(9-i);
        h->SetMarkerStyle(22+i);
        h->SetDirectory(0);
        SignalHistos->Add(h);
        if (fori==0) histoNames.push_back(h->GetName());
      }
      SignalArrays.push_back(SignalHistos);
      f.Close();
      leg->AddEntry(SignalHistos->At(0),signal[whichSignal.at(fori)].c_str(), "pl");
      fori++;
    }
  }
  //save plots
  TFile f_out(PlotOutput.c_str(),"recreate");
  int numHistos=0;
  if (plotData) numHistos = DataHistos->GetEntries();
  if (plotBkg) numHistos = BkgStack->GetEntries();
  if (plotSignal) numHistos = SignalArrays.at(0)->GetEntries();
  for (int i=0;i<numHistos;i++){
    TCanvas *c = new TCanvas(histoNames.at(i).c_str(),histoNames.at(i).c_str());
    c->cd();
    gPad->SetLogy();
    if (plotData) DataHistos->At(i)->Draw("P");
    else if (plotSignal) for (auto obj : SignalArrays) obj->At(i)->Draw();
    else if (plotBkg) BkgStack->At(i)->Draw("h");
    if (plotBkg) BkgStack->At(i)->Draw("sameh");
    if (plotSignal) for (auto obj : SignalArrays) obj->At(i)->Draw("same");
    if (plotData) DataHistos->At(i)->Draw("sameP");
    leg->Draw("same");
    c->Write();
  }
}
/*
  TCanvas *cphoEtL = new TCanvas("cphoEtL", "cphoEtL");
  cphoEtL->cd();
  gPad->SetLogy();
  hdata_phoEtL->GetYaxis()->SetTitle("Events / 33.3 GeV");
  hdata_phoEtL->GetYaxis()->SetTitleOffset(1.15);
  hdata_phoEtL->GetXaxis()->SetTitle("E_{T}^{#gamma}  [GeV]");
  hdata_phoEtL->GetXaxis()->CenterTitle(kTRUE);
  hdata_phoEtL->GetXaxis()->SetTitleOffset(1.15);
  drawthings(nsignal, fsignal, hdata_phoEtL, sbkg_phoEtL, "hsignal_phoEtL");
  leg->Draw("same");
  */
