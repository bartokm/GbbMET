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

void MCintegral(int nsignal, TString fsignal, THStack* stack, std::string hsignal, int b1, int b2){
  for (int i=0;i<nsignal;i++){
    TH1D *h = new TH1D();
    h = getplot(fsignal,Form((hsignal+"[%i]").c_str(),i));
    double I_signal[nsignal], I_bkg=0;
    
    if (b1==0 && b2==0) {
      I_signal[i]=h->Integral();
      I_bkg=((TH1*)(stack->GetStack()->Last()))->Integral();
    }
    else {
      I_bkg=((TH1*)(stack->GetStack()->Last()))->Integral(b1,b2);
      I_signal[i]=h->Integral(b1,b2);
    }
    std::cout<<hsignal<<" I_signal"<<i<<": "<<I_signal[i]<<" I_bkg "<<I_bkg<<" I_signal/I_bkg="<<I_signal[i]/I_bkg<<std::endl;
  }
  return 0;
}

int color(unsigned int id) {

  int color = kBlack;
  if(      id == 4  ) color = 2;
  else if( id == 7  ) color = 3;
  else if( id == 0  ) color = 4;
  else if( id == 1  ) color = 5;
  else if( id == 2  ) color = 6;
  else if( id == 14  ) color = 7;
  else if( id == 15  ) color = 8;
  else if( id == 16  ) color = 9;
  else if( id == 17  ) color = kRed+2;

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
  std::vector<int> iter_zjet {10,11,12,13};
  //int iter_rest[7]={0,1,2,14,15,16,17};
  int iter_rest[7]={1,15,2,16,17,14,0};
  //int iter_rest[6]={15,2,16,17,14,0}; //wjetslnu off
  std::vector<int> iter_qcd {3,4,5,6,7,8,9};

  //stack->Add(getonebkg(fname,hname,iter_zjet));
  for (int i=0;i<7;i++){
    TH1D *h = new TH1D();
    h = getplot(fname,Form((hname+"[%i]").c_str(),iter_rest[i]));
    h->SetFillColor(color(iter_rest[i]));
    stack->Add(h);
    if (i==0) stack->Add(getonebkg(fname,hname,iter_zjet));
    if (i==5) stack->Add(getonebkg(fname,hname,iter_qcd));
  }
  //stack->Add(getonebkg(fname,hname,iter_qcd));
  //TH1D *hgjets = new TH1D();
  //hgjets = getplot(fname,(hname+"[13]").c_str());
  //hgjets->SetFillColor(color(13));
  //stack->Add(hgjets);
  return 0;
}

void drawthings(int nsignal, TString fsignal, TH1D* hdata, THStack* stack, std::string hsignal){
  int maximum=0;
  maximum=((TH1*)(stack->GetStack()->Last()))->GetMaximum();
  maximum+=0.1*maximum;
  hdata->SetMarkerStyle(21);
  hdata->SetMarkerColor(0);
  hdata->Draw("P");
  hdata->SetMaximum(maximum);
  stack->Draw("sameh");
  //hdata->Draw("sameP");
  double I_mc=((TH1*)(stack->GetStack()->Last()))->Integral();
  double I_data=hdata->Integral();
  //std::cout<<"Data integral: "<<I_data<<" mc integral "<<I_mc<< " I_data/I_mc="<<I_data/I_mc<<std::endl;
  int signalscale=1;
  for (int i=nsignal-1;i>-1;i--){
    TH1D *h = new TH1D();
    h = getplot(fsignal,Form((hsignal+"[%i]").c_str(),i));
    h->SetLineColor(i+1);
    h->SetMarkerColor(i+1);
    h->SetMarkerStyle(22+i);
    if (i!=1) h->Scale(signalscale);
    h->Draw("same");
    //if (i==nsignal-1) h->Draw();
    //else h->Draw("same");
  }
  return 0;
}
