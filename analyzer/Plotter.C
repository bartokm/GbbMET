#include "TString.h"
#include <TH1F.h>
#include <iostream>
#include <THStack.h>
#include "tdrstyle.C"
using namespace std;

TH1* Sum(THStack s){
  //cout<<"doing sum  "<<endl;         
  TList * mylist = (TList*)s.GetHists();
  TIter next(mylist);
  TH1 *hh  = (TH1*) mylist -> First() ->Clone();
  hh -> SetLineColor(kBlack);
  hh -> SetFillStyle(0);
  TObject *obj;
  while ((obj = next()))
    {
      // cout<<obj->GetName()<<endl;
     //skip first object since it's used by creating the histogram                               
      if(obj == mylist->First()) continue;
      hh -> Add((TH1*)obj);
    }
  //cout<<"end of sum"<<endl;                                                                
  return hh;
}

TH1F* getplot(TString fname, TString hname) {
  TFile f(fname.Data(), "READ");
  TH1F *h= (TH1F*)f.Get(hname.Data());
  TH1F *c=(TH1F*)h->Clone();
  c->SetDirectory(0);
  return c;
}


void Plotter(){
  setTDRStyle();
  //string outputtagData = "_HLTPho4096_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_metFilters1536_MET100_ST1300_bcounterBDSV_M1.root";
  //string outputtagData = "_HLTPho4096_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_ST1300_metFilters1536_MET100_bcounterCSV_L2.root";
  string outputtagData = "_HLTPho4096_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_ST1300_metFilters1536_MET100_bcounterBDSV_M1.root";
  //string outputtag = "_HLTPho4096_nPassPhoL1_phoCalibEt175_nPassAK45_MT100_ST1300_NOTmetFilters94_MET100_bcounterBDSV_M1.root";
  //string outputtag = "_HLTPho4096_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_NOTmetFilters94_MET100_ST1300_bcounterBDSV_M1.root";
  //string outputtag = "_HLTPho4096_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_ST1300_NOTmetFilters94_MET100_bcounterCSV_L2.root";
  string outputtag = "_HLTPho4096_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_ST1300_NOTmetFilters94_MET100_bcounterBDSV_M1.root";
  string preoutput= "";
  string Aname = "A_";
  string Bname = "B_";
  string Cname = "C_";
  string pretag = "histos/Analyzer_histos_";
  string data = "Data";
  //string bkg[8] = {"TTJets","TTGJets","WJetsToLNu","WGJets","QCD","GJets","ZJetsToNuNu","ZGTo2NuG"};
  string bkg[15] = {"TTJets","TTGJets","ST","DYJetsToLL","WJetsToLNu","WJetsToQQ","WGToLNuG","WGJets","ZJetsToNuNu","ZJetsToQQ","ZGTo2LG","ZGTo2NuG","Diboson","QCD","GJets"};
  //string signal[9] = {"mG1000_mN200","mG1000_mN400","mG1000_mN600","mCh400_mN200","mCh600_mN200","mCh600_mN400","mCh800_mN200","mCh800_mN400","mCh800_mN600"};
  //string signal[8] = {"mG1000_mN200","mG1000_mN400","mG1000_mN600","mN300","mN500","T5qqqqHg_mG1000_mN200","T5qqqqHg_mG1000_mN400","T5qqqqHg_mG1000_mN600"};
  string signal[9] = {"T5qqqqHg_mG800_mN200","T5qqqqHg_mG800_mN400","T5qqqqHg_mG800_mN600","T5qqqqHg_mG1000_mN200","T5qqqqHg_mG1000_mN400","T5qqqqHg_mG1000_mN600","T5qqqqHg_mG1200_mN200","T5qqqqHg_mG1200_mN400","T5qqqqHg_mG1600_mN1000"};
  string PlotOutput = "plots/Plots"+preoutput+outputtag;
  //vector<int> whichBkg = {6,7,0,1,2,3,4,5};
  //vector<int> whichBkg = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
  vector<int> whichBkg = {0,1,2,3,4,5,6,8,9,10,11,12};
  //vector<int> whichSignal = {0,1,2,3,4,5,6};
  //vector<int> whichSignal = {0,1,2,3,4};
  //vector<int> whichSignal = {0,1,2,5,6,7};
  vector<int> whichSignal = {0,2,3,5,7,8};

  bool plotData = 0;
  bool plotABCD = 1;
  bool plotSignal = 1;
  bool plotBkg = 1;

  gROOT->SetBatch(true);

  TLegend *leg = new TLegend(0.55,0.45,0.9,0.85,"");
  TObjArray *DataHistos = new TObjArray();
  TObjArray *BkgStack = new TObjArray();
  vector<TObjArray*> SignalArrays;
  vector<string> histoNames;

  if (plotData) {
    histoNames.clear();
    string filename = pretag+preoutput+data+outputtagData;
    TFile f(filename.c_str(),"read");
    TIter next(f.GetListOfKeys());
    TKey *key;
    while ((key = (TKey*)next())) {
      TClass *cl = gROOT->GetClass(key->GetClassName());
      if (!cl->InheritsFrom("TH1")) continue;
      TH1 *h = (TH1*)key->ReadObj();
      //h->Rebin(2);
      h->SetMarkerStyle(21);
      h->SetDirectory(0);
      histoNames.push_back(h->GetName());
      DataHistos->Add(h);
    }
    leg->AddEntry(DataHistos->At(0),"Data", "P");
    f.Close();
  }
  
  if (plotBkg) {
    vector<THStack*> v_stack;
    histoNames.clear();
    for (int i=0;i<whichBkg.size();i++){
      string filename = pretag+preoutput+bkg[whichBkg[i]]+outputtag;
      TFile f(filename.c_str(),"read");
      TIter next(f.GetListOfKeys());
      TKey *key;
      int j=0;
      while ((key = (TKey*)next())) {
        TClass *cl = gROOT->GetClass(key->GetClassName());
        if (!cl->InheritsFrom("TH1")) continue;
        TH1 *h = (TH1*)key->ReadObj();
        //h->Rebin(2);
        h->SetFillColor(whichBkg[i]+kOrange);
        h->SetDirectory(0);
        if (i==0) {THStack *stack = new THStack(); stack->Add(h); v_stack.push_back(stack);histoNames.push_back(h->GetName());}
        else v_stack.at(j)->Add(h);
        if (plotABCD && i==whichBkg.size()-1) {
          string Afilename = pretag+Aname+data+outputtagData;
          string Bfilename = pretag+Bname+data+outputtagData;
          string Cfilename = pretag+Cname+data+outputtagData;
          TH1F *h_A = getplot(Afilename.c_str(),h->GetName());
          TH1F *h_B = getplot(Bfilename.c_str(),h->GetName());
          TH1F *h_C = getplot(Cfilename.c_str(),h->GetName());
          TH1F *h_ABCD = (TH1F*)h_B->Clone();
          h_ABCD->Multiply(h_C);
          h_ABCD->Divide(h_A);
          //h_ABCD->Rebin(2);
          h_ABCD->SetDirectory(0);
          h_ABCD->SetFillColor(6);
          v_stack.at(j)->Add(h_ABCD);
        }
        j++;
      }
      f.Close();
    }
    int fori=0;
    for (const auto&& obj: *v_stack.at(0)->GetHists()) {
      if (fori == whichBkg.size()) leg->AddEntry(obj,"QCD with ABCD","f");
      else leg->AddEntry(obj,bkg[whichBkg.at(fori)].c_str(),"f");
      fori++;
    }
    for (auto i : v_stack) BkgStack->Add(i);
  }
  
  if (plotSignal) {
    histoNames.clear();
    int fori=0;
    for (auto i : whichSignal){
      TObjArray *SignalHistos = new TObjArray();
      string filename = pretag+preoutput+signal[i]+outputtag;
      TFile f(filename.c_str(),"read");
      TIter next(f.GetListOfKeys());
      TKey *key;
      while ((key = (TKey*)next())) {
        TClass *cl = gROOT->GetClass(key->GetClassName());
        if (!cl->InheritsFrom("TH1")) continue;
        TH1 *h = (TH1*)key->ReadObj();
        h->SetLineColor(9-i);
        h->SetLineWidth(2);
        h->SetMarkerColor(9-i);
        h->SetMarkerStyle(22+i);
        h->SetMarkerSize(2);
        //h->Rebin(2);
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
    double min=1, max=0, factor=1.2;
    TH1 *hD; THStack *sB; TH1 *hS; 
    //get max value
    if (plotData) {
      hD = (TH1*)DataHistos->At(i);
      double tempmax=hD->GetMaximum();
      if (max<tempmax) max=tempmax;
    }
    if (plotBkg) {
      sB = (THStack*) BkgStack->At(i);
      double tempmax=sB->GetMaximum();
      if (max<tempmax) max=tempmax;
    }
    if (plotSignal) {
      for (auto obj : SignalArrays) {
        hS = (TH1*)obj->At(i);
        double tempmax=hS->GetMaximum();
        if (max<tempmax) max=tempmax;
      }
    }
    TCanvas *c = new TCanvas(histoNames.at(i).c_str(),histoNames.at(i).c_str());
    c->cd();
    gPad->SetLogy();
    float r=0.3, epsilon=0.02;
    if (plotData && plotBkg){
      TPad *pad1 = new TPad("pad1", "pad1", 0, r-epsilon, 1, 1.0);
      pad1->SetLogy();
      pad1->SetBottomMargin(epsilon);
      pad1->SetGridx();
      pad1->Draw();
      pad1->cd();
    }
    if (plotData) {
      DataHistos->At(i)->Draw("P");
      if (!DataHistos->At(i)->InheritsFrom("TH2")) hD->SetAxisRange(min,max*factor,"Y");
    }
    else if (plotSignal) for (auto obj : SignalArrays) {
      obj->At(i)->Draw();
      if (!obj->At(i)->InheritsFrom("TH2")) hS->SetAxisRange(min,max*factor,"Y");
    }
    else if (plotBkg) {
      if (BkgStack->At(i)->InheritsFrom("TH2")) Sum(*(THStack*)BkgStack->At(i))->Draw();
      else {BkgStack->At(i)->Draw("h");Sum(*(THStack*)BkgStack->At(i))->SetAxisRange(min,max*factor,"Y");}
    }
    if (plotBkg){ 
      if (BkgStack->At(i)->InheritsFrom("TH2")) Sum(*(THStack*)BkgStack->At(i))->Draw("same");
      else BkgStack->At(i)->Draw("sameh");
    }
    if (plotSignal) for (auto obj : SignalArrays) obj->At(i)->Draw("same");
    if (plotData) DataHistos->At(i)->Draw("sameP");
    leg->Draw("same");
    if (i==0 && plotData && plotSignal) {
      TH1 *hd = (TH1*)DataHistos->At(i);
      double nData = hd->GetBinContent(7);
      for (auto obj : SignalArrays) {
        TH1 *hS = (TH1*)obj->At(i);
        std::cout<<"percent "<<hS->GetBinContent(7)/nData*100<<std::endl;;
      }
    }
    if (plotData && plotBkg){
      TH1 *hd = (TH1*)DataHistos->At(i);
      hd->GetXaxis()->SetLabelSize(0);
      hd->GetYaxis()->SetTitleSize(20);
      hd->GetYaxis()->SetTitleFont(43);
      hd->GetYaxis()->SetTitleOffset(1.55);
      c->cd();
      TPad *pad2 = new TPad("pad2", "pad2", 0, 0, 1, r*(1-epsilon));
      pad2->SetTopMargin(0);
      pad2->SetBottomMargin(0.2);
      pad2->SetFillColor(0);
      pad2->SetFillStyle(0);
      pad2->SetGridx();
      pad2->Draw();
      pad2->cd();
      TH1D *h = (TH1D*)DataHistos->At(i)->Clone("h");
      h->SetLineColor(kBlack);
      h->SetMinimum(0);
      h->SetMaximum(2);
      h->SetStats(0);
      h->Divide(Sum(*(THStack*)BkgStack->At(i)));
      h->SetMarkerStyle(21);
      h->Draw("ep");
      h->SetTitle("");
      h->GetYaxis()->SetTitle("Ratio");
      h->GetYaxis()->SetNdivisions(505);
      h->GetYaxis()->SetTitleSize(20);
      h->GetYaxis()->SetTitleFont(43);
      h->GetYaxis()->SetTitleOffset(1.15);
      h->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
      h->GetYaxis()->SetLabelSize(10);
      // X axis ratio plot settings
      h->GetXaxis()->SetTitleSize(20);
      h->GetXaxis()->SetTitleFont(43);
      h->GetXaxis()->SetTitleOffset(2.6);
      h->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
      h->GetXaxis()->SetLabelSize(15);
    }
    c->Write();
  }
}
