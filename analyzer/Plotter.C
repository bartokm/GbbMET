#include "TString.h"
#include <TH1F.h>
#include <iostream>
#include <fstream>
#include <THStack.h>
#include "input/tdrstyle.C"
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
  bool ak8=1; string AK; if (ak8) AK="ak8"; else AK="ak4";
  //string ak8_data = "_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_ST500_metFilters1536_notAK41_passHiggsMass1_MET100_BDSV_selected2.root";
  //string ak4_data ="_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_ST500_metFilters1536_passAK4HiggsMass1_MET100_CSV_selected2.root";
  //string ak8_mc = "_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_ST500_NOTmetFilters94_notAK41_passHiggsMass1_MET100_BDSV_selected2.root";
  //string ak4_mc = "_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_nPassEleL0_nPassMuL0_nPassAK45_MT100_ST500_NOTmetFilters94_passAK4HiggsMass1_MET100_CSV_selected2.root";
  string ak8_data = "_rebinned_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_MT100_ST600_metFilters1536_nPassEleL0_nPassMuL0_nPassAK42_notAK41_MET100_BDSV_selected2.root";
  string ak4_data ="_rebinned_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_MT100_ST600_metFilters1536_nPassEleL0_nPassMuL0_nPassAK42_MET100_CSV_selected2.root";
  string ak8_mc = "_rebinned_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_MT100_ST600_NOTmetFilters94_nPassEleL0_nPassMuL0_nPassAK42_notAK41_MET100_BDSV_selected2.root";
  string ak4_mc = "_rebinned_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_MT100_ST600_NOTmetFilters94_nPassEleL0_nPassMuL0_nPassAK42_MET100_CSV_selected2.root";
  string outputtagData, outputtag;
  if (ak8) {outputtagData=ak8_data; outputtag=ak8_mc;}
  else {outputtagData=ak4_data; outputtag=ak4_mc;}
  string preoutput= "CRbtag_";
  
  
  string Aname = "A_", Bname, Cname;
  if (preoutput=="") {Bname = "B_";Cname = "C_";}
  if (preoutput=="CRlow_") {Bname = "Bp_";Cname = "Cp_";}
  if (preoutput=="CRmet_") {Bname = "B_";Cname = "Cp_";}
  if (preoutput=="CRbtag_") {Bname = "Bp_";Cname = "C_";}
  string pretag = "histos/Analyzer_histos_";
  string data = "Data";
  //string bkg[8] = {"TTJets","TTGJets","WJetsToLNu","WGJets","QCD","GJets","ZJetsToNuNu","ZGTo2NuG"};
  string bkg[15] = {"TTJets","TTGJets","ST","DYJetsToLL","WJetsToLNu","WJetsToQQ","WGToLNuG","WGJets","ZJetsToNuNu","ZJetsToQQ","ZGTo2LG","ZGTo2NuG","Diboson","QCD","GJets"};
  //string signal[9] = {"mG1000_mN200","mG1000_mN400","mG1000_mN600","mCh400_mN200","mCh600_mN200","mCh600_mN400","mCh800_mN200","mCh800_mN400","mCh800_mN600"};
  //string signal[8] = {"mG1000_mN200","mG1000_mN400","mG1000_mN600","mN300","mN500","T5qqqqHg_mG1000_mN200","T5qqqqHg_mG1000_mN400","T5qqqqHg_mG1000_mN600"};
  string signal[9] = {"T5qqqqHg_mG800_mN200","T5qqqqHg_mG800_mN400","T5qqqqHg_mG800_mN600","T5qqqqHg_mG1000_mN200","T5qqqqHg_mG1000_mN400","T5qqqqHg_mG1000_mN600","T5qqqqHg_mG1200_mN200","T5qqqqHg_mG1200_mN400","T5qqqqHg_mG1600_mN1000"};
  string est_bkg[3] = {"ABCD","Wbb","FRData"};
  string PlotOutput = "plots/Plots"+preoutput+outputtag;
  //vector<int> whichBkg = {6,7,0,1,2,3,4,5};
  vector<int> whichBkg = {0,1,2,3,4,5,6,8,9,10,11,12,13,14};
  //vector<int> whichBkg = {0,1,2,3,4,5,6,8,9,10,11,12};
  //vector<int> whichSignal = {0,1,2,3,4,5,6};
  //vector<int> whichSignal = {0,1,2,3,4};
  //vector<int> whichSignal = {0,1,2,5,6,7};
  vector<int> whichSignal = {0,2,3,5,7,8};
  vector<int> whichEstBkg = {0,1,2};
  vector<int> whichEstBkgMC = {8,11};
  //vector<int> whichEstBkgMC = {0,1,2,3,4,5,6,8,9,10,11,12};
  vector<int> whichMC_ABCD= {13,14};
  int rebin=1;
  bool savePNG=1; string png_out="plots/2017.10.16/rebinned/base/"+preoutput;
  bool plotData = 1;
  bool plotABCD = 0;
  bool plotSignal = 0;
  bool plotBkg = 0;
  bool plotSumBkg = 0;
  bool plotEstBkg = 1; bool corrABCD=1; bool smooth=0;
  bool plotMC_ABCD = 0;
  if (plotEstBkg) PlotOutput = "plots/Plots_EstBkg"+preoutput+outputtag;
  if (plotEstBkg && smooth) PlotOutput = "plots/Plots_EstBkgSmooth"+preoutput+outputtag;

  gROOT->SetBatch(true);

  map<string,string> hist_save;
  hist_save["h_eff"]=AK+"_heff.png";
  hist_save["h_phoEtL"]=AK+"_phoet.png";
  hist_save["h_njets"]=AK+"_njets.png";
  hist_save["h_HT_after"]=AK+"_ht.png";
  hist_save["h_EMHT_after"]=AK+"_emht.png";
  if (ak8) hist_save["h_AK8PrunedCorrjetmass_select_withABCD"]=AK+"_hmass.png";
  else hist_save["h_mbbjet_select_withABCD"]=AK+"_hmass.png";

  TLegend *leg = new TLegend(0.7,0.5,0.95,0.9,"");
  TObjArray *DataHistos = new TObjArray();
  TObjArray *BkgStack = new TObjArray();
  TObjArray *EstBkgStack = new TObjArray();
  vector<TObjArray*> SignalArrays;
  vector<TObjArray*> MC_ABCD_Arrays;
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
      if (cl->InheritsFrom("TH2")) continue;
      TH1 *h = (TH1*)key->ReadObj();
      string temp = h->GetName();
      if (temp == "h_cuts") continue;
      std::string type=cl->GetName();
      if (type.find("TH1") != std::string::npos) h->Rebin(rebin);
      h->SetMarkerStyle(21);
      h->SetDirectory(0);
      histoNames.push_back(h->GetName());
      DataHistos->Add(h);
    }
    leg->AddEntry(DataHistos->At(0),"Data", "P");
    f.Close();
  }

  TFile *f_ABCD;
  if (plotABCD) {
    string filename = pretag+preoutput+"ABCD"+outputtagData;
    f_ABCD=new TFile(filename.c_str(),"recreate");
  }

  if (plotBkg || plotSumBkg) {
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
        if (cl->InheritsFrom("TH2")) continue;
        TH1 *h = (TH1*)key->ReadObj();
        string temp = h->GetName();
        if (temp == "h_cuts") continue;
        std::string type=cl->GetName();
        if (type.find("TH1") != std::string::npos) h->Rebin(rebin);
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
          std::string type=cl->GetName();
          if (type.find("TH1") != std::string::npos) h->Rebin(rebin);
          h_ABCD->SetDirectory(0);
          h_ABCD->SetFillColor(6);
          f_ABCD->cd();
          h_ABCD->Write();
          f.cd();
          v_stack.at(j)->Add(h_ABCD);
        }
        j++;
      }
      f.Close();
    }
    int fori=0;
    if (!plotSumBkg) {
      for (const auto&& obj: *v_stack.at(0)->GetHists()) {
        if (fori == whichBkg.size()) leg->AddEntry(obj,"QCD with ABCD","f");
        else leg->AddEntry(obj,bkg[whichBkg.at(fori)].c_str(),"f");
        fori++;
      }
    }
    for (auto i : v_stack) BkgStack->Add(i);
  }
  if (plotABCD) f_ABCD->Close();
  
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
        if (cl->InheritsFrom("TH2")) continue;
        TH1 *h = (TH1*)key->ReadObj();
        string temp = h->GetName();
        if (temp == "h_cuts") continue;
        h->SetLineColor(9-i);
        h->SetLineWidth(2);
        h->SetMarkerColor(9-i);
        h->SetMarkerStyle(22+i);
        h->SetMarkerSize(2);
        std::string type=cl->GetName();
        if (type.find("TH1") != std::string::npos) h->Rebin(rebin);
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
  if (plotEstBkg) {
    vector<THStack*> v_stack;
    histoNames.clear();
    for (int i=0;i<whichEstBkg.size();i++){
      string filename = pretag+preoutput+est_bkg[whichEstBkg[i]]+outputtagData;
      TFile f(filename.c_str(),"read");
      TIter next(f.GetListOfKeys());
      TKey *key;
      int j=0;
      while ((key = (TKey*)next())) {
        TClass *cl = gROOT->GetClass(key->GetClassName());
        if (!cl->InheritsFrom("TH1")) continue;
        if (cl->InheritsFrom("TH2")) continue;
        TH1 *h = (TH1*)key->ReadObj();
        string temp = h->GetName();
        if (temp == "h_cuts") continue;
        std::string type=cl->GetName();
        if (type.find("TH1") != std::string::npos) h->Rebin(rebin);
        if (est_bkg[whichEstBkg[i]]=="ABCD" && corrABCD) {
          string filename_corr = pretag+preoutput+"ABCD_corr"+outputtagData;
          TH1F *h_corr = getplot(filename_corr.c_str(),h->GetName());
          if (smooth) h_corr->Smooth();
          h->Multiply(h_corr);
        }
        h->SetFillColor(whichEstBkg[i]+2);
        h->SetDirectory(0);
        if (i==0) {THStack *stack = new THStack(); stack->Add(h); v_stack.push_back(stack);histoNames.push_back(h->GetName());}
        else v_stack.at(j)->Add(h);
        j++;
      }
      f.Close();
    }

    for (int i=0;i<whichEstBkgMC.size();i++){
      string filename = pretag+preoutput+bkg[whichEstBkgMC[i]]+outputtag;
      TFile f(filename.c_str(),"read");
      TIter next(f.GetListOfKeys());
      TKey *key;
      int j=0;
      while ((key = (TKey*)next())) {
        TClass *cl = gROOT->GetClass(key->GetClassName());
        if (!cl->InheritsFrom("TH1")) continue;
        if (cl->InheritsFrom("TH2")) continue;
        TH1 *h = (TH1*)key->ReadObj();
        string temp = h->GetName();
        if (temp == "h_cuts") continue;
        std::string type=cl->GetName();
        if (type.find("TH1") != std::string::npos) h->Rebin(rebin);
        h->SetFillColor(whichEstBkgMC[i]);
        h->SetDirectory(0);
        v_stack.at(j)->Add(h);
        j++;
      }
      f.Close();
    }
    int fori=0, forj=0;
    for (const auto&& obj: *v_stack.at(0)->GetHists()) {
      if (fori >= whichEstBkg.size()) {
        leg->AddEntry(obj,bkg[whichEstBkgMC.at(forj)].c_str(),"f");
        forj++;
      }
      else leg->AddEntry(obj,est_bkg[whichEstBkg.at(fori)].c_str(),"f");
      fori++;
    }
    for (auto i : v_stack) EstBkgStack->Add(i);
  }
  
  TFile *f_MC_ABCD_m; TFile *f_MC_ABCD_c;
  if (plotMC_ABCD) {
    histoNames.clear();
    TObjArray *temp_histos= new TObjArray();
    TObjArray *MC_Ahistos= new TObjArray();
    TObjArray *MC_Bhistos= new TObjArray();
    TObjArray *MC_Chistos= new TObjArray();
    TObjArray *MC_ABCDhistos= new TObjArray();
    if (preoutput != "CRall_") {
      string filename = pretag+preoutput+"QCDGJets"+outputtag;
      string filename2 = pretag+preoutput+"MC_ABCD"+outputtag;
      f_MC_ABCD_m=new TFile(filename.c_str(),"recreate");
      f_MC_ABCD_c=new TFile(filename2.c_str(),"recreate");
      for (int i=0;i<whichMC_ABCD.size();i++){
        string filename = pretag+preoutput+bkg[whichMC_ABCD[i]]+outputtag;
        TFile f(filename.c_str(),"read");
        TIter next(f.GetListOfKeys());
        TKey *key;
        int j=0;
        while ((key = (TKey*)next())) {
          TClass *cl = gROOT->GetClass(key->GetClassName());
          if (!cl->InheritsFrom("TH1")) continue;
          if (cl->InheritsFrom("TH2")) continue;
          TH1 *h = (TH1*)key->ReadObj();
          string temp = h->GetName();
          if (temp == "h_cuts") continue;
          std::string type=cl->GetName();
          if (type.find("TH1") != std::string::npos) h->Rebin(rebin);
          h->SetDirectory(0);
          if (i==0) {
            h->SetMarkerStyle(2);
            h->SetMarkerColor(2);
            h->SetMarkerSize(2);
            temp_histos->Add(h);
            histoNames.push_back(h->GetName());
          }
          else {
            TH1D *htemp= (TH1D*)temp_histos->At(j)->Clone();
            htemp->Add(h);
            htemp->SetDirectory(0);
            temp_histos->AddAt(htemp,j);
            f_MC_ABCD_m->cd();
            htemp->Write();
            f.cd();
          }
          string Afilename = pretag+Aname+bkg[whichMC_ABCD[i]]+outputtag;
          string Bfilename = pretag+Bname+bkg[whichMC_ABCD[i]]+outputtag;
          string Cfilename = pretag+Cname+bkg[whichMC_ABCD[i]]+outputtag;
          TH1F *h_A = getplot(Afilename.c_str(),h->GetName());
          TH1F *h_B = getplot(Bfilename.c_str(),h->GetName());
          TH1F *h_C = getplot(Cfilename.c_str(),h->GetName());
          h_A->SetDirectory(0);
          h_B->SetDirectory(0);
          h_C->SetDirectory(0);
          if (i==0) {
            MC_Ahistos->Add(h_A);
            MC_Bhistos->Add(h_B);
            MC_Chistos->Add(h_C);
          }
          else {
            TH1D *hAtemp= (TH1D*)MC_Ahistos->At(j)->Clone();
            TH1D *hBtemp= (TH1D*)MC_Bhistos->At(j)->Clone();
            TH1D *hCtemp= (TH1D*)MC_Chistos->At(j)->Clone();
            hAtemp->Add(h_A);
            hBtemp->Add(h_B);
            hCtemp->Add(h_C);
            hAtemp->SetDirectory(0);
            hBtemp->SetDirectory(0);
            hCtemp->SetDirectory(0);
            MC_Ahistos->AddAt(hAtemp,j);
            MC_Bhistos->AddAt(hBtemp,j);
            MC_Chistos->AddAt(hCtemp,j);
          }
          j++;
        }
        f.Close();
      }
      MC_ABCD_Arrays.push_back(temp_histos);
      for (int i=0;i<MC_Ahistos->GetEntries();i++) {
        TH1F *h_A = (TH1F*)MC_Ahistos->At(i);
        TH1F *h_B = (TH1F*)MC_Bhistos->At(i);
        TH1F *h_C = (TH1F*)MC_Chistos->At(i);
        TH1F *h_ABCD = (TH1F*)h_B->Clone();
        h_ABCD->Multiply(h_C);
        h_ABCD->Divide(h_A);
        h_ABCD->SetMarkerStyle(3);
        h_ABCD->SetMarkerColor(3);
        h_ABCD->SetMarkerSize(2);
        h_ABCD->SetDirectory(0);
        MC_ABCDhistos->Add(h_ABCD);
        f_MC_ABCD_c->cd();
        h_ABCD->Write();
      }
      MC_ABCD_Arrays.push_back(MC_ABCDhistos);
    }
    else {
      string filename = pretag+preoutput+"QCDGJets"+outputtag;
      TFile f(filename.c_str(),"read");
      TIter next(f.GetListOfKeys());
      TKey *key;
      while ((key = (TKey*)next())) {
        TClass *cl = gROOT->GetClass(key->GetClassName());
        if (!cl->InheritsFrom("TH1")) continue;
        if (cl->InheritsFrom("TH2")) continue;
        TH1 *h = (TH1*)key->ReadObj();
        string temp = h->GetName();
        if (temp == "h_cuts") continue;
        std::string type=cl->GetName();
        if (type.find("TH1") != std::string::npos) h->Rebin(rebin);
        h->SetDirectory(0);
        h->SetMarkerStyle(2);
        h->SetMarkerColor(2);
        h->SetMarkerSize(2);
        temp_histos->Add(h);
        histoNames.push_back(h->GetName());
        string ABCDfilename = pretag+preoutput+"MC_ABCD"+outputtag;
        TH1F *h_ABCD = getplot(ABCDfilename.c_str(),h->GetName());
        h_ABCD->SetDirectory(0);
        h_ABCD->SetMarkerStyle(3);
        h_ABCD->SetMarkerColor(3);
        h_ABCD->SetMarkerSize(2);
        h_ABCD->SetDirectory(0);
        MC_ABCDhistos->Add(h_ABCD);
      }
      f.Close();
      MC_ABCD_Arrays.push_back(temp_histos);
      MC_ABCD_Arrays.push_back(MC_ABCDhistos);
    }
    leg->AddEntry(MC_ABCD_Arrays.at(0)->At(0),"QCD+GJets", "pl");
    leg->AddEntry(MC_ABCD_Arrays.at(1)->At(0),"ABCD from QCD+GJets", "pl");
  }

  if (plotABCD) f_ABCD->Close();
  TFile *f_abcd_corr;
  if (plotMC_ABCD){ 
    if (preoutput != "CRall_") {
      f_MC_ABCD_m->Close();
      f_MC_ABCD_c->Close();
    }
    string filename = pretag+preoutput+"ABCD_corr"+outputtagData;
    f_abcd_corr=new TFile(filename.c_str(),"recreate");
  }
  //save plots
  TFile f_out(PlotOutput.c_str(),"recreate");
  int numHistos=0;
  if (plotData) numHistos = DataHistos->GetEntries();
  if (plotBkg) numHistos = BkgStack->GetEntries();
  if (plotSignal) numHistos = SignalArrays.at(0)->GetEntries();
  if (plotMC_ABCD) numHistos = MC_ABCD_Arrays.at(0)->GetEntries();
  if (plotEstBkg) numHistos = EstBkgStack->GetEntries();
  for (int i=0;i<numHistos;i++){
    double min=0.1, max=0, factor=2;
    TH1 *hD; THStack *sB; TH1 *hS; TH1 *hMC; THStack *sEB; TH1 *sumBkg;
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
    if (plotSumBkg) {
      sumBkg = Sum(*(THStack*)BkgStack->At(i));
      double tempmax=sumBkg->GetMaximum();
      if (max<tempmax) max=tempmax;
    }
    if (plotEstBkg) {
      sEB = (THStack*) EstBkgStack->At(i);
      double tempmax=sEB->GetMaximum();
      if (max<tempmax) max=tempmax;
    }
    if (plotMC_ABCD) {
      for (auto obj : MC_ABCD_Arrays) {
        hMC = (TH1*)obj->At(i);
        double tempmax=hMC->GetMaximum();
        if (max<tempmax) max=tempmax;
      }
    }
    TCanvas *c = new TCanvas(histoNames.at(i).c_str(),histoNames.at(i).c_str());
    c->cd();
    //gPad->SetLogy();
    float r=0.3, epsilon=0.02;
    if ((plotData && (plotBkg || plotEstBkg)) || plotMC_ABCD || (plotSumBkg && plotEstBkg)){
      TPad *pad1 = new TPad("pad1", "pad1", 0, r-epsilon, 1, 1.0);
      //pad1->SetLogy();
      pad1->SetBottomMargin(epsilon);
      pad1->SetGridx();
      pad1->SetGridy();
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
    else if (plotSumBkg) {
      sumBkg->SetMarkerStyle(20);
      sumBkg->SetMarkerColor(kBlack);
      sumBkg->SetLineColor(kBlack);
      sumBkg->Draw("p");
      if (i==0) leg->AddEntry(sumBkg,"Sum of Bkg MC", "p");
    }
    else if (plotEstBkg) {
      if (EstBkgStack->At(i)->InheritsFrom("TH2")) Sum(*(THStack*)EstBkgStack->At(i))->Draw();
      else {EstBkgStack->At(i)->Draw("h");Sum(*(THStack*)EstBkgStack->At(i))->SetAxisRange(min,max*factor,"Y");}
    }
    else if (plotMC_ABCD) for (auto obj : MC_ABCD_Arrays) {
      obj->At(i)->Draw();
      if (!obj->At(i)->InheritsFrom("TH2")) hMC->SetAxisRange(min,max*factor,"Y");
    }
    if (plotBkg){ 
      if (BkgStack->At(i)->InheritsFrom("TH2")) Sum(*(THStack*)BkgStack->At(i))->Draw("same");
      else BkgStack->At(i)->Draw("sameh");
    }
    if (plotEstBkg){ 
      if (EstBkgStack->At(i)->InheritsFrom("TH2")) Sum(*(THStack*)EstBkgStack->At(i))->Draw("same");
      else {EstBkgStack->At(i)->Draw("sameh hist");Sum(*(THStack*)EstBkgStack->At(i))->Draw("sameh");}
    }
    if (plotSumBkg) {
      sumBkg->Draw("samep");
    }
    if (plotSignal) for (auto obj : SignalArrays) obj->At(i)->Draw("same");
    if (plotMC_ABCD) for (auto obj : MC_ABCD_Arrays) obj->At(i)->Draw("same");
    if (plotData) DataHistos->At(i)->Draw("sameP");
    leg->Draw("same");
    //gStyle->SetOptStat(0);
    //gStyle->SetOptTitle(0);
    //c->Update();
    if (histoNames.at(i) == "h_eff"){
      if (plotData && plotSignal) {
        TH1 *hd = (TH1*)DataHistos->At(i);
        double nData = hd->GetBinContent(2);
        for (auto obj : SignalArrays) {
          TH1 *hS = (TH1*)obj->At(i);
          std::cout<<"percent "<<hS->GetBinContent(2)/nData*100<<std::endl;;
        }
      }
    }
    if ((plotData && (plotBkg || plotEstBkg)) || plotMC_ABCD || (plotSumBkg && plotEstBkg)){
      TH1 *hd;
      if (plotData) hd = (TH1*)DataHistos->At(i);
      else if (plotMC_ABCD) hd = (TH1*)MC_ABCD_Arrays.at(0)->At(i);
      else if (plotSumBkg) hd = sumBkg;
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
      pad2->SetGridy();
      pad2->Draw();
      pad2->cd();
      TH1D *h;
      if (plotData) h = (TH1D*)DataHistos->At(i)->Clone("h");
      else if (plotMC_ABCD) h = (TH1D*)MC_ABCD_Arrays.at(0)->At(i)->Clone();
      else if (plotSumBkg) h = (TH1D*)sumBkg->Clone("h");
      h->SetLineColor(kBlack);
      h->SetMinimum(0);
      h->SetMaximum(3);
      h->SetStats(0);
      if (plotData && plotBkg) h->Divide(Sum(*(THStack*)BkgStack->At(i)));
      else if (plotData && plotEstBkg) h->Divide(Sum(*(THStack*)EstBkgStack->At(i)));
      else if (plotMC_ABCD) {
        h->Divide((TH1*)MC_ABCD_Arrays.at(1)->At(i));
        f_abcd_corr->cd();
        h->Write();
        f_out.cd();
      }
      else if (plotSumBkg && plotEstBkg) h->Divide(Sum(*(THStack*)EstBkgStack->At(i)));
      if (savePNG && histoNames.at(i) == "h_eff"){
        ofstream myfile;
        string foutname=png_out+AK+"_integral.txt";
        myfile.open(foutname);
        double nData = hd->GetBinContent(2);
        cout<<"nData: "<<nData<<" ratio: "<<setprecision(2)<<h->GetBinContent(2)<<" +- "<<h->GetBinError(2)<<endl;
        myfile<<"nData: "<<nData<<" ratio: "<<setprecision(2)<<h->GetBinContent(2)<<" +- "<<h->GetBinError(2)<<endl;
        myfile.close();
      }
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
    if (savePNG) {
      string currentname=c->GetName();
      string foutname="";
      for (auto const& x : hist_save) if (x.first == currentname) foutname=png_out+x.second;
      if (foutname != "") c->SaveAs(foutname.c_str());
    }
  }
  if (plotMC_ABCD) f_abcd_corr->Close();
}
