#include "plotter_skimmed.h"
#include "TString.h"
#include <TH1F.h>
#include <iostream>
#include <THStack.h>
//#include "tdrstyle.C"
using namespace std;

void plotter_skimmed(){
  //setTDRStyle();
  std::string fdata = "skimmed_data_histos.root";
  std::string fbkg = "skimmed_mc_histos.root";
  std::string fsignal = "mc_signal_histos_newcuts.root";

  TH1D *hdata_nPU = getplot(fdata,"pileup");
  TH1D *hdata_cuts = getplot(fdata,"hdata_cuts");
  TH1D *hdata_nVtx = getplot(fdata,"hdata_nVtx");
  TH1D *hdata_phoEt = getplot(fdata,"hdata_phoEt");
  TH1D *hdata_phoEta = getplot(fdata,"hdata_phoEta");
  TH1D *hdata_pfMET = getplot(fdata,"hdata_pfMET");
  TH1D *hdata_nPho = getplot(fdata,"hdata_nPho");
  TH1D *hdata_nEle = getplot(fdata,"hdata_nEle");
  TH1D *hdata_nMu = getplot(fdata,"hdata_nMu");
  TH1D *hdata_nTrksPV = getplot(fdata,"hdata_nTrksPV");
  TH1D *hdata_njets= getplot(fdata,"hdata_njets");
  TH1D *hdata_bjets= getplot(fdata,"hdata_bjets");
  TH1D *hdata_doubleB= getplot(fdata,"hdata_doubleB");
  TH1D *hdata_doubleB_highdB= getplot(fdata,"hdata_doubleB_highdB");
  TH1D *hdata_bjetprob = getplot(fdata,"hdata_bjetprob");
  TH1D *hdata_bjetprob2 = getplot(fdata,"hdata_bjetprob2");
  TH1D *hdata_bjetCSV= getplot(fdata,"hdata_bjetCSV");
  TH1D *hdata_bjetCSV2= getplot(fdata,"hdata_bjetCSV2");
  TH1D *hdata_bjetcMVA = getplot(fdata,"hdata_bjetcMVA");
  TH1D *hdata_bjetcMVA2 = getplot(fdata,"hdata_bjetcMVA2");
  TH1D *hdata_jetpt = getplot(fdata,"hdata_jetpt");
  TH1D *hdata_AK8jetpt = getplot(fdata,"hdata_AK8jetpt");
  TH1D *hdata_AK8ljetmass = getplot(fdata,"hdata_AK8ljetmass");
  TH1D *hdata_AK8jetmass = getplot(fdata,"hdata_AK8jetmass");
  TH1D *hdata_dRphoAK8jet= getplot(fdata,"hdata_dRphoAK8jet");
  TH1D *hdata_nAK8jets = getplot(fdata,"hdata_nAK8jets");
  TH1D *hdata_HT_before = getplot(fdata,"hdata_HT_before");
  TH1D *hdata_EMHT_before = getplot(fdata,"hdata_EMHT_before");
  TH1D *hdata_HT_after = getplot(fdata,"hdata_HT_after");
  TH1D *hdata_EMHT_after = getplot(fdata,"hdata_EMHT_after");
  TH1D *hdata_AK8HT_before = getplot(fdata,"hdata_AK8HT_before");
  TH1D *hdata_AK8EMHT_before = getplot(fdata,"hdata_AK8EMHT_before");
  TH1D *hdata_AK8HT_after = getplot(fdata,"hdata_AK8HT_after");
  TH1D *hdata_AK8EMHT_after = getplot(fdata,"hdata_AK8EMHT_after");

  THStack *sbkg_nVtx = new THStack("sbkg_nVtx","");
  THStack *sbkg_nPU = new THStack("sbkg_nPU","");
  THStack *sbkg_cuts = new THStack("sbkg_cuts","");

  THStack *sbkg_phoEt = new THStack("sbkg_phoEt","");
  THStack *sbkg_phoEta = new THStack("sbkg_phoEta","");
  THStack *sbkg_pfMET = new THStack("sbkg_pfMET","");
  THStack *sbkg_nPho = new THStack("sbkg_nPho","");
  THStack *sbkg_nTrksPV = new THStack("sbkg_nTrksPV","");
  THStack *sbkg_nEle = new THStack("sbkg_nEle","");
  THStack *sbkg_nMu = new THStack("sbkg_nMu","");
  
  THStack *sbkg_njets = new THStack("sbkg_njets","");
  THStack *sbkg_jetpt = new THStack("sbkg_jetpt","");
  THStack *sbkg_nAK8jets = new THStack("sbkg_nAK8jets","");
  THStack *sbkg_AK8jetpt = new THStack("sbkg_AK8jetpt","");
  THStack *sbkg_AK8ljetmass = new THStack("sbkg_AK8ljetmass","");
  THStack *sbkg_AK8jetmass = new THStack("sbkg_AK8jetmass","");
  
  THStack *sbkg_dRphoAK8jet = new THStack("sbkg_dRphoAK8jet","");

  THStack *sbkg_bjets = new THStack("sbkg_bjets","");
  THStack *sbkg_doubleB = new THStack("sbkg_doubleB","");
  THStack *sbkg_doubleB_highdB = new THStack("sbkg_doubleB_highdB","");
  THStack *sbkg_bjetprob = new THStack("sbkg_bjetprob","");
  THStack *sbkg_bjetprob2 = new THStack("sbkg_bjetprob2","");
  THStack *sbkg_bjetCSV = new THStack("sbkg_bjetCSV","");
  THStack *sbkg_bjetCSV2 = new THStack("sbkg_bjetCSV2","");
  THStack *sbkg_bjetcMVA = new THStack("sbkg_bjetcMVA","");
  THStack *sbkg_bjetcMVA2 = new THStack("sbkg_bjetcMVA2","");

  THStack *sbkg_HT_before = new THStack("sbkg_HT_before","");
  THStack *sbkg_EMHT_before = new THStack("sbkg_EMHT_before","");
  THStack *sbkg_HT_after = new THStack("sbkg_HT_after","");
  THStack *sbkg_EMHT_after = new THStack("sbkg_EMHT_after","");

  THStack *sbkg_AK8HT_before = new THStack("sbkg_AK8HT_before","");
  THStack *sbkg_AK8EMHT_before = new THStack("sbkg_AK8EMHT_before","");
  THStack *sbkg_AK8HT_after = new THStack("sbkg_AK8HT_after","");
  THStack *sbkg_AK8EMHT_after = new THStack("sbkg_AK8EMHT_after","");

  addallMC(sbkg_nVtx, fbkg, "hbkg_nVtx");
  addallMC(sbkg_nPU, fbkg, "hbkg_nPU");
  addallMC(sbkg_cuts, fbkg, "hbkg_cuts");
  addallMC(sbkg_phoEt, fbkg, "hbkg_phoEt");
  addallMC(sbkg_phoEta, fbkg, "hbkg_phoEta");
  addallMC(sbkg_pfMET, fbkg, "hbkg_pfMET");
  addallMC(sbkg_nPho, fbkg, "hbkg_nPho");
  addallMC(sbkg_nTrksPV, fbkg, "hbkg_nTrksPV");
  addallMC(sbkg_nEle, fbkg, "hbkg_nEle");
  addallMC(sbkg_nMu, fbkg, "hbkg_nMu");
  addallMC(sbkg_njets, fbkg, "hbkg_njets");
  addallMC(sbkg_jetpt, fbkg, "hbkg_jetpt");
  addallMC(sbkg_nAK8jets, fbkg, "hbkg_nAK8jets");
  addallMC(sbkg_AK8jetpt, fbkg, "hbkg_AK8jetpt");
  addallMC(sbkg_AK8ljetmass, fbkg, "hbkg_AK8ljetmass");
  addallMC(sbkg_AK8jetmass, fbkg, "hbkg_AK8jetmass");
  addallMC(sbkg_dRphoAK8jet, fbkg, "hbkg_dRphoAK8jet");
  addallMC(sbkg_bjets, fbkg, "hbkg_bjets");
  addallMC(sbkg_doubleB, fbkg, "hbkg_doubleB");
  addallMC(sbkg_doubleB_highdB, fbkg, "hbkg_doubleB_highdB");
  addallMC(sbkg_bjetprob, fbkg, "hbkg_bjetprob");
  addallMC(sbkg_bjetprob2, fbkg, "hbkg_bjetprob2");
  addallMC(sbkg_bjetCSV, fbkg, "hbkg_bjetCSV");
  addallMC(sbkg_bjetCSV2, fbkg, "hbkg_bjetCSV2");
  addallMC(sbkg_bjetcMVA, fbkg, "hbkg_bjetcMVA");
  addallMC(sbkg_bjetcMVA2, fbkg, "hbkg_bjetcMVA2");
  addallMC(sbkg_HT_before, fbkg, "hbkg_HT_before");
  addallMC(sbkg_EMHT_before, fbkg, "hbkg_EMHT_before");
  addallMC(sbkg_HT_after, fbkg, "hbkg_HT_after");
  addallMC(sbkg_EMHT_after, fbkg, "hbkg_EMHT_after");
  addallMC(sbkg_AK8HT_before, fbkg, "hbkg_AK8HT_before");
  addallMC(sbkg_AK8EMHT_before, fbkg, "hbkg_AK8EMHT_before");
  addallMC(sbkg_AK8HT_after, fbkg, "hbkg_AK8HT_after");
  addallMC(sbkg_AK8EMHT_after, fbkg, "hbkg_AK8EMHT_after");

  TLegend *leg = new TLegend(0.65,0.55,0.9,0.85,"");

  TCanvas *c1 = new TCanvas("c1", "c1",1200,600);
  c1->Divide(2,1);
  c1->cd(1);
  gPad->SetLogy();
  sbkg_cuts->Draw("histtext");
  sbkg_cuts->Print("all");
  //drawthings(hdata_cuts, sbkg_cuts);
  leg->AddEntry("hdata_cuts",   "Data", "P");
  leg->AddEntry("hbkg_cuts[6]",   "Multijet", "f");
  leg->AddEntry("hbkg_cuts[13]",   "#gammaJet", "f");
  leg->AddEntry("hbkg_cuts[1]",   "WJetsToL#nu", "f");
  leg->AddEntry("hbkg_cuts[0]",   "TTJets", "f");
  leg->AddEntry("hbkg_cuts[2]",   "ZJetsTo#nu#nu", "f");
  leg->Draw("same");
  c1->cd(2);
  hdata_cuts->SetMarkerStyle(21);
  hdata_cuts->Draw("textP");
  hdata_cuts->Print("all");
  /*
  c1->cd(2);
  gPad->SetLogy();
  drawthings(hdata_nVtx, sbkg_nVtx);
  leg->Draw("same");
  c1->cd(3);
  gPad->SetLogy();
  drawthings(hdata_pfMET, sbkg_pfMET);
  leg->Draw("same");

  TCanvas *c2 = new TCanvas("c2", "c2",1200,600);
  c2->Divide(3,1);
  c2->cd(1);
  gPad->SetLogy();
  drawthings(hdata_nPho, sbkg_nPho);
  leg->Draw("same");
  c2->cd(2);
  gPad->SetLogy();
  drawthings(hdata_phoEt, sbkg_phoEt);
  leg->Draw("same");
  c2->cd(3);
  gPad->SetLogy();
  drawthings(hdata_phoEta, sbkg_phoEta);
  leg->Draw("same");

  TCanvas *c3 = new TCanvas("c3", "c3",1200,600);
  c3->Divide(3,1);
  c3->cd(1);
  gPad->SetLogy();
  drawthings(hdata_nEle, sbkg_nEle);
  leg->Draw("same");
  c3->cd(2);
  gPad->SetLogy();
  drawthings(hdata_nMu, sbkg_nMu);
  leg->Draw("same");
  c3->cd(3);
  gPad->SetLogy();
  drawthings(hdata_njets, sbkg_njets);
  leg->Draw("same");
  */
}
