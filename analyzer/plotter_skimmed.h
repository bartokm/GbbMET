#include "TString.h"
#include <TFile.h>
#include <TH1F.h>
#include <iostream>

TH1D* getplot(TString fname, TString hname) {
  TFile f(fname.Data(), "READ");
  TH1D *h= (TH1D*)f.Get(hname.Data());
  TH1D *c=(TH1D*)h->Clone();
  c->SetDirectory(0);
  return c;
}

TH2D* getplot2d(TString fname, TString hname) {
  TFile f(fname.Data(), "READ");
  TH2D *h= (TH2D*)f.Get(hname.Data());
  TH2D *c=(TH2D*)h->Clone();
  c->SetDirectory(0);
  return c;
}

int color(unsigned int id) {

  int color = kBlack;
  if(      id == 2  ) color = kBlack;
  else if( id == 7  ) color = kGreen+1;
  else if( id == 0  ) color = kRed;
  else if( id == 1  ) color = kYellow+2;
  else if( id == 13  ) color = kRed+3;
  else if( id == 4  ) color = kBlue+3;

  return color;
}

TH1D* getonebkg(TString fname, std::string hname, std::vector<int> iter) {
  TH1D *h = new TH1D();
  for (unsigned int i=0;i<iter.size();i++){
    if (i==0){
      h = getplot(fname,Form((hname+"[%i]").c_str(),iter.at(i)));
    }
    else {
      h->Add(getplot(fname,Form((hname+"[%i]").c_str(),iter.at(i))));
    }
  }
  h->SetFillColor(color(iter.size()));
  return h;
}

void addallMC(THStack* stack, TString fname, std::string hname){
  std::vector<int> iter_qcd {6,7,8,9,10,11,12};
  int iter_rest[3]={0,1};
  std::vector<int> iter_zjet {2,3,4,5};

  stack->Add(getonebkg(fname,hname,iter_zjet));
  for (int i=0;i<2;i++){
    TH1D *h = new TH1D();
    h = getplot(fname,Form((hname+"[%i]").c_str(),iter_rest[i]));
    h->SetFillColor(color(iter_rest[i]));
    stack->Add(h);
  }
  stack->Add(getonebkg(fname,hname,iter_qcd));
  TH1D *hgjets = new TH1D();
  hgjets = getplot(fname,(hname+"[13]").c_str());
  hgjets->SetFillColor(color(13));
  stack->Add(hgjets);
  return 0;
}

void drawthings(TH1D* hdata, THStack* stack, TH1D* hsignal1, TH1D* hsignal2){
  hdata->SetMarkerStyle(21);
  hdata->Draw("P");
  stack->Draw("sameh");
  hsignal1->SetLineColor(4);
  hsignal1->SetMarkerColor(4);
  hsignal1->SetMarkerStyle(22);
  hsignal1->Scale(10000);
  hsignal1->Draw("same");
  hsignal2->SetLineColor(7);
  hsignal2->SetMarkerColor(7);
  hsignal2->SetMarkerStyle(23);
  hsignal2->Scale(10000);
  hsignal2->Draw("same");
  return 0;
}
