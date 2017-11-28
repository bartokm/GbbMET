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


void SignalPlotter(){
  setTDRStyle();
  string outputtag = "_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_MT100_ST600_NOTmetFilters94_nPassEleL0_nPassMuL0_nPassAK42_MET100.root";
  //string outputtag = "_HLTPho4096_isPVGood1_nPassPhoL1_phoCalibEt175_MT100_ST600_NOTmetFilters94_nPassEleL0_nPassMuL0_nPassAK42_MET100_BDSV_selected1_CSV_selected2.root";
  string preoutput= "truth_";
  
  string pretag = "histos/Analyzer_histos_";
  //string bkg[8] = {"TTJets","TTGJets","WJetsToLNu","WGJets","QCD","GJets","ZJetsToNuNu","ZGTo2NuG"};
  string bkg[15] = {"TTJets","TTGJets","ST","DYJetsToLL","WJetsToLNu","WJetsToQQ","WGToLNuG","WGJets","ZJetsToNuNu","ZJetsToQQ","ZGTo2LG","ZGTo2NuG","Diboson","QCD","GJets"};
  string signal[9] = {"T5qqqqHg_mG800_mN200","T5qqqqHg_mG800_mN400","T5qqqqHg_mG800_mN600","T5qqqqHg_mG1000_mN200","T5qqqqHg_mG1000_mN400","T5qqqqHg_mG1000_mN600","T5qqqqHg_mG1200_mN200","T5qqqqHg_mG1200_mN400","T5qqqqHg_mG1600_mN1000"};
  string PlotOutput = "plots/Plots"+preoutput+outputtag;
  //vector<int> whichBkg = {6,7,0,1,2,3,4,5};
  vector<int> whichBkg = {0,1,2,3,4,5,6,8,9,10,11,12,13,14};
  //vector<int> whichBkg = {0,1,2,3,4,5,6,8,9,10,11,12};
  //vector<int> whichSignal = {0,1,2,3,4,5,6};
  //vector<int> whichSignal = {0,1,2,3,4};
  //vector<int> whichSignal = {0,1,2,5,6,7};
  //vector<int> whichSignal = {0,2,3,5,7,8};
  vector<int> whichSignal = {0,1,2,3,4,5,6,7,8};
  int rebin=1; bool logarithmic=0;
  bool savePNG=0; string png_out="plots/2017.11.23/"+preoutput;
  bool plotSignal = 1;
  bool plotBkg = 1;
  bool plotSumBkg = 0;

  gROOT->SetBatch(true);

  map<string,string> hist_save;
  //hist_save["h_eff"]="_heff.png";
  hist_save["h_phoEtL"]="base_phoet.png";
  hist_save["h_pfMET"]="base_pfmet.png";
  hist_save["h_ST"]="base_ST.png";
  hist_save["h_njets"]="base_njets.png";
  hist_save["h_HT_after"]="base_ht.png";
  hist_save["h_EMHT_after"]="base_emht.png";

  TLegend *leg = new TLegend(0.7,0.5,0.95,0.9,"");
  TObjArray *DataHistos = new TObjArray();
  TObjArray *BkgStack = new TObjArray();
  TObjArray *EstBkgStack = new TObjArray();
  vector<TObjArray*> SignalArrays;
  vector<TObjArray*> MC_ABCD_Arrays;
  vector<string> histoNames;

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
        j++;
      }
      f.Close();
    }
    int fori=0;
    if (!plotSumBkg) {
      for (const auto&& obj: *v_stack.at(0)->GetHists()) {
        leg->AddEntry(obj,bkg[whichBkg.at(fori)].c_str(),"f");
        fori++;
      }
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
  
  //save plots
  TFile f_out(PlotOutput.c_str(),"recreate");
  int numHistos=0;
  if (plotBkg) numHistos = BkgStack->GetEntries();
  if (plotSignal) numHistos = SignalArrays.at(0)->GetEntries();
  for (int i=0;i<numHistos;i++){
    double min=0.1, max=0, factor=2;
    THStack *sB; TH1 *hS; TH1 *hMC; TH1 *sumBkg;
    //get max value
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
    TCanvas *c = new TCanvas(histoNames.at(i).c_str(),histoNames.at(i).c_str());
    c->cd();
    if (logarithmic) gPad->SetLogy();
    float r=0.3, epsilon=0.02;
    /*
    if (plotBkg && plotSignal){
      TPad *pad1 = new TPad("pad1", "pad1", 0, r-epsilon, 1, 1.0);
      //pad1->SetLogy();
      pad1->SetBottomMargin(epsilon);
      pad1->SetGridx();
      pad1->SetGridy();
      pad1->Draw();
      pad1->cd();
    }
    */
    if (plotSignal) for (auto obj : SignalArrays) {
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
    if (plotBkg){ 
      if (BkgStack->At(i)->InheritsFrom("TH2")) Sum(*(THStack*)BkgStack->At(i))->Draw("same");
      else BkgStack->At(i)->Draw("sameh");
    }
    if (plotSumBkg) {
      sumBkg->Draw("samep");
    }
    if (plotSignal) for (auto obj : SignalArrays) obj->At(i)->Draw("same");
    leg->Draw("same");
    //gStyle->SetOptStat(0);
    //gStyle->SetOptTitle(0);
    //c->Update();
    /*
    if (plotBkg plotSignal){
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
    */
    c->Write();
    if (savePNG) {
      string currentname=c->GetName();
      string foutname="";
      for (auto const& x : hist_save) if (x.first == currentname) foutname=png_out+x.second;
      if (foutname != "") c->SaveAs(foutname.c_str());
    }
  }
}
