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
  std::string fsignal = "mc_signal_histos.root";

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

  addallMC(sbkg_cuts, fbkg, "hbkg_cuts");
  addallMC(sbkg_nVtx, fbkg, "hbkg_nVtx");
  addallMC(sbkg_nPU, fbkg, "hbkg_nPU");
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

//signal
  nsignal=2;
  TH1D *h_PUweight[nsignal];
  TH1D *hsignal_nVtx[nsignal];
  TH1D *hsignal_nPU[nsignal];
  TH1D *hsignal_cuts[nsignal];
  TH1D *hsignal_phoEt[nsignal];
  TH1D *hsignal_phoEta[nsignal];
  TH1D *hsignal_pfMET[nsignal];
  TH1D *hsignal_nPho[nsignal];
  TH1D *hsignal_nTrksPV[nsignal];
  TH1D *hsignal_nEle[nsignal];
  TH1D *hsignal_nMu[nsignal];
  TH1D *hsignal_njets[nsignal];
  TH1D *hsignal_jetpt[nsignal];
  TH1D *hsignal_nAK8jets[nsignal];
  TH1D *hsignal_AK8jetpt[nsignal];
  TH1D *hsignal_AK8ljetmass[nsignal];
  TH1D *hsignal_AK8jetmass[nsignal];
  TH1D *hsignal_dRphoAK8jet[nsignal];
  TH1D *hsignal_bjets[nsignal];
  TH1D *hsignal_doubleB[nsignal];
  TH1D *hsignal_doubleB_highdB[nsignal];
  TH1D *hsignal_bjetprob[nsignal];
  TH1D *hsignal_bjetprob2[nsignal];
  TH1D *hsignal_bjetCSV[nsignal];
  TH1D *hsignal_bjetCSV2[nsignal];
  TH1D *hsignal_bjetcMVA[nsignal];
  TH1D *hsignal_bjetcMVA2[nsignal];
  TH1D *hsignal_HT_before[nsignal];
  TH1D *hsignal_EMHT_before[nsignal];
  TH1D *hsignal_HT_after[nsignal];
  TH1D *hsignal_EMHT_after[nsignal];
  TH1D *hsignal_AK8HT_before[nsignal];
  TH1D *hsignal_AK8EMHT_before[nsignal];
  TH1D *hsignal_AK8HT_after[nsignal];
  TH1D *hsignal_AK8EMHT_after[nsignal];
  //mc truth histograms
  TH1D *hsignal_Hjetpt[nsignal];
  TH1D *hsignal_AK8Hjetpt[nsignal];
  TH1D *hsignal_AK8Hjetmass[nsignal];
  TH1D *hsignal_dRphoH[nsignal];
  TH1D *hsignal_dRTphoH[nsignal];
  TH2D *hsignal_AK8ptHpt[nsignal];
  TH2D *hsignal_AK8massHpt[nsignal];
  TH1D *hsignal_Hpt[nsignal];
  for (Int_t i=0;i<nsignal;i++){
    hsignal_cuts[i] = getplot(fsignal,Form("hsignal_cuts[%i]",i));
    hsignal_nVtx[i] = getplot(fsignal,Form("hsignal_nVtx[%i]",i));
    hsignal_nPU[i] = getplot(fsignal,Form("hsignal_nPU[%i]",i));
    
    hsignal_phoEt[i] = getplot(fsignal,Form("hsignal_phoEt[%i]",i));
    hsignal_phoEta[i]= getplot(fsignal,Form("hsignal_phoEta[%i]",i));
    hsignal_pfMET[i]= getplot(fsignal,Form("hsignal_pfMET[%i]",i));
    hsignal_nPho[i]= getplot(fsignal,Form("hsignal_nPho[%i]",i));
    hsignal_nTrksPV[i]= getplot(fsignal,Form("hsignal_nTrksPV[%i]",i));
    hsignal_nEle[i]= getplot(fsignal,Form("hsignal_nEle[%i]",i));
    hsignal_nMu[i]= getplot(fsignal,Form("hsignal_nMu[%i]",i));
    
    hsignal_njets[i] = getplot(fsignal,Form("hsignal_njets[%i]",i));
    hsignal_jetpt[i] = getplot(fsignal,Form("hsignal_jetpt[%i]",i));
    hsignal_nAK8jets[i] = getplot(fsignal,Form("hsignal_nAK8jets[%i]",i));
    hsignal_AK8jetpt[i] = getplot(fsignal,Form("hsignal_AK8jetpt[%i]",i));
    hsignal_AK8ljetmass[i] = getplot(fsignal,Form("hsignal_AK8ljetmass[%i]",i));
    hsignal_AK8jetmass[i] = getplot(fsignal,Form("hsignal_AK8jetmass[%i]",i));
   
    hsignal_dRphoAK8jet[i]= getplot(fsignal,Form("hsignal_dRphoAK8jet[%i]",i));
  
    hsignal_bjets[i] = getplot(fsignal,Form("hsignal_bjets[%i]",i));
    hsignal_doubleB[i] = getplot(fsignal,Form("hsignal_doubleB[%i]",i));
    hsignal_doubleB_highdB[i] = getplot(fsignal,Form("hsignal_doubleB_highdB[%i]",i));
    hsignal_bjetprob[i] = getplot(fsignal,Form("hsignal_bjetprob[%i]",i));
    hsignal_bjetprob2[i] = getplot(fsignal,Form("hsignal_bjetprob2[%i]",i));
    hsignal_bjetCSV[i]= getplot(fsignal,Form("hsignal_bjetCSV[%i]",i));
    hsignal_bjetCSV2[i]= getplot(fsignal,Form("hsignal_bjetCSV2[%i]",i));
    hsignal_bjetcMVA[i] = getplot(fsignal,Form("hsignal_bjetcMVA[%i]",i));
    hsignal_bjetcMVA2[i] = getplot(fsignal,Form("hsignal_bjetcMVA2[%i]",i));
 
    hsignal_HT_before[i] = getplot(fsignal,Form("hsignal_HT_before[%i]",i));
    hsignal_EMHT_before[i] = getplot(fsignal,Form("hsignal_EMHT_before[%i]",i));
    hsignal_HT_after[i] = getplot(fsignal,Form("hsignal_HT_after[%i]",i));
    hsignal_EMHT_after[i] = getplot(fsignal,Form("hsignal_EMHT_after[%i]",i));
    
    hsignal_AK8HT_before[i] = getplot(fsignal,Form("hsignal_AK8HT_before[%i]",i));
    hsignal_AK8EMHT_before[i] = getplot(fsignal,Form("hsignal_AK8EMHT_before[%i]",i));
    hsignal_AK8HT_after[i] = getplot(fsignal,Form("hsignal_AK8HT_after[%i]",i));
    hsignal_AK8EMHT_after[i] = getplot(fsignal,Form("hsignal_AK8EMHT_after[%i]",i));

    //truth histograms
    hsignal_Hjetpt[i] = getplot(fsignal,Form("hsignal_Hjetpt[%i]",i));
    hsignal_AK8Hjetpt[i] = getplot(fsignal,Form("hsignal_AK8Hjetpt[%i]",i));
    hsignal_AK8Hjetmass[i] = getplot(fsignal,Form("hsignal_AK8Hjetmass[%i]",i));
    
    hsignal_dRphoH[i]= getplot(fsignal,Form("hsignal_dRphoH[%i]",i));
    hsignal_dRTphoH[i]= getplot(fsignal,Form("hsignal_dRTphoH[%i]",i));
    
    hsignal_AK8ptHpt[i]= getplot2d(fsignal,Form("hsignal_AK8ptHpt[%i]",i));
    hsignal_AK8massHpt[i]= getplot2d(fsignal,Form("hsignal_AK8massHpt[%i]",i));
   
    hsignal_Hpt[i] = getplot(fsignal,Form("hsignal_Hpt[%i]",i));
  }

  TLegend *leg = new TLegend(0.55,0.55,0.9,1,"");

  TCanvas *c1 = new TCanvas("c1", "c1",1200,600);
  c1->Divide(3,1);
  c1->cd(1);
  gPad->SetLogy();
  sbkg_cuts->Print("all");
  hdata_cuts->Print("all");
  hdata_cuts->SetMinimum(10);
  drawthings(hdata_cuts, sbkg_cuts, hsignal_cuts[0], hsignal_cuts[1]);
  leg->AddEntry("hdata_cuts",   "Data", "P");
  leg->AddEntry("hbkg_cuts[0]",   "#gammaJet", "f");
  leg->AddEntry("hbkg_cuts[1]",   "WJetsToL#nu", "f");
  leg->AddEntry("hbkg_cuts[2]",   "Z#gammaJet", "f");
  leg->AddEntry("hbkg_cuts[3]",   "Multijet", "f");
  leg->AddEntry("hbkg_cuts[10]",   "ZJetsTo#nu#nu", "f");
  leg->AddEntry("hbkg_cuts[14]",   "TT#gammaJets", "f");
  leg->AddEntry("hbkg_cuts[15]",   "ZJetsToQQ", "f");
  leg->AddEntry("hbkg_cuts[16]",   "W#gammaJets", "f");
  leg->AddEntry("hbkg_cuts[17]",   "TTJets", "f");
  leg->AddEntry("hsignal_cuts[0]","m_{#Chi^{+}}=1400 m_{#Chi^{0}}=200 *10000", "pl");
  leg->AddEntry("hsignal_cuts[1]","m_{#Chi^{+}}=1200 m_{#Chi^{0}}=1000 *10000", "pl");
  leg->Draw("same");
  c1->cd(2);
  gPad->SetLogy();
  drawthings(hdata_nVtx, sbkg_nVtx, hsignal_nVtx[0], hsignal_nVtx[1]);
  leg->Draw("same");
  c1->cd(3);
  gPad->SetLogy();
  hdata_pfMET->SetMinimum(1);
  drawthings(hdata_pfMET, sbkg_pfMET, hsignal_pfMET[0], hsignal_pfMET[1]);
  leg->Draw("same");

  TCanvas *c2 = new TCanvas("c2", "c2",1200,600);
  c2->Divide(3,1);
  c2->cd(1);
  gPad->SetLogy();
  drawthings(hdata_nPho, sbkg_nPho, hsignal_nPho[0], hsignal_nPho[1]);
  leg->Draw("same");
  c2->cd(2);
  gPad->SetLogy();
  drawthings(hdata_phoEt, sbkg_phoEt, hsignal_phoEt[0], hsignal_phoEt[1]);
  leg->Draw("same");
  c2->cd(3);
  gPad->SetLogy();
  hdata_phoEta->SetMinimum(10);
  drawthings(hdata_phoEta, sbkg_phoEta, hsignal_phoEta[0], hsignal_phoEta[1]);
  leg->Draw("same");

  TCanvas *c3 = new TCanvas("c3", "c3",1200,600);
  c3->Divide(3,1);
  c3->cd(1);
  gPad->SetLogy();
  drawthings(hdata_nEle, sbkg_nEle, hsignal_nEle[0], hsignal_nEle[1]);
  leg->Draw("same");
  c3->cd(2);
  gPad->SetLogy();
  drawthings(hdata_nMu, sbkg_nMu, hsignal_nMu[0], hsignal_nMu[1]);
  leg->Draw("same");
  c3->cd(3);
  gPad->SetLogy();
  drawthings(hdata_njets, sbkg_njets, hsignal_njets[0], hsignal_njets[1]);
  leg->Draw("same");

  TCanvas *c4 = new TCanvas("c4", "c4",1200,600);
  c4->Divide(3,1);
  c4->cd(1);
  gPad->SetLogy();
  hdata_doubleB_highdB->SetMinimum(1);
  drawthings(hdata_doubleB_highdB, sbkg_doubleB_highdB, hsignal_doubleB_highdB[0], hsignal_doubleB_highdB[1]);
  leg->Draw("same");
  c4->cd(2);
  gPad->SetLogy();
  hdata_bjetprob->SetMinimum(1);
  drawthings(hdata_bjetprob, sbkg_bjetprob, hsignal_bjetprob[0], hsignal_bjetprob[1]);
  leg->Draw("same");
  c4->cd(3);
  gPad->SetLogy();
  hdata_bjetcMVA->SetMinimum(1);
  drawthings(hdata_bjetcMVA, sbkg_bjetcMVA, hsignal_bjetcMVA[0], hsignal_bjetcMVA[1]);
  leg->Draw("same");
  
}
