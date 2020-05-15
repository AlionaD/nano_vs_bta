#include <TSystem.h>
#include <TRandom2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TF1.h>
#include <TFitResult.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TGraphErrors.h>
#include <TProfile.h>
#include <TLegend.h>
#include <TString.h>
#include <TGaxis.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <TH2.h>
#include <TList.h>
#include <TPaveStats.h>
#include <vector>
#include "THStack.h"
#include "headers/picmake.h"
#include "headers/makemap.h"
#include "headers/makeplots.h"

using namespace std;


void test_map(){ /*Need files with event branches */

  const char *BTA = "/home/argada/work/test_b/JetTree_mc_FatJets_Subjets_Aliona_all1_2204.root";
  const char *NANO = "/home/argada/work/test_b/nano107.root";

  string map = "./maps/mapmap8.txt";
  TFile  *y = new TFile(NANO);
  TTree *t$i = (TTree*)y->Get("Events");
  TFile  *yy = new TFile (BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  if (nEntries_Nano != nEntries_BTA) {
    std::cout << "Different number of events" << '\n';
    std::cout << "No map for you" << '\n';
  } else {
    int nEntries = nEntries_BTA;
    Long64_t entry[nEntries];
    map_map(BTA, NANO, map);
  }

}

//void test_fatnjetpic(const char *BTA, const char *NANO){ /* Need map */
void test_fatnjetpic(){
  const char *BTA = "/home/argada/work/test_b/JetTree_mc_FatJets_Subjets_Aliona_all4_2204.root";
  const char *NANO = "/home/argada/work/test_b/nano106.root";
  string map = "./maps/mapmap.txt";
  TH2F* h_nJet = new TH2F("nFatJet", "nFatJet", 10, 0, 10, 10, 0, 10);
  TH2F* h_pt = new TH2F("Fat Jet p_{T}", "Fat Jet p_{T}", 100, 150, 1150, 100, 150, 1150);//"Fat Jet p_{T}", 85, 150, 1000, 85, 150, 1000);
  TH2F* h_eta = new TH2F("Fat jet #eta", "Fat jet #eta", 100, -3, 3, 100, -3, 3);
  TH2F* h_phi = new TH2F("Fat jet #phi", "Fat jet #phi", 100, -4, 4, 100, -4, 4);
  TH2F* h_area = new TH2F("", "Fat Jet catchment area", 100, 0.8, 2.8, 100, 0.8, 2.8);
  TH2F* h_mass = new TH2F("Fat jet mass", "Fat jet mass", 100, 0, 400, 100, 0, 400);
  TCanvas *c$i = new TCanvas ("Fat jet", "Fat jet", 1200, 1200);
  TFile  *y = new TFile(NANO);
  TTree *t$i = (TTree*)y->Get("Events");
  TFile  *yy = new TFile (BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  if (nEntries_Nano != nEntries_BTA) {
    std::cout << "Different number of events" << '\n';
  } else {
    int nEntries = nEntries_BTA;
    Long64_t entry[nEntries];
    get_map(nEntries, entry, map);
    //plot_fatkin(BTA, NANO, nEntries, entry, h_nJet);
    plot_fatkin_mass(BTA, NANO, nEntries, entry, h_mass);
  }
  makebeauty();
  h_mass->Draw("COLZ");
  pdfpainter("/home/argada/work/newpics", "FatJet_mass", c$i);
}

void test_fatnjetdis(){
  const char *BTA = "/home/argada/work/test_b/JetTree_mc_FatJets_Subjets_Aliona_all4_2204.root";
  const char *NANO = "/home/argada/work/test_b/nano107.root";
  string map = "./maps/mapmap8.txt";
  TH2F* h_btagCMVA = new TH2F("", "CMVA V2 btag discriminator", 202, -1.01, 1.01, 202, -1.01, 1.01);
  TH2F* h_DeepCSVb = new TH2F("", "DeepCSV b+bb tag discriminator", 101, 0, 1.01, 101, 0, 1.01);
  TCanvas *c$i = new TCanvas ("Fat jet", "Fat jet", 1200, 1200);
  TFile  *y = new TFile(NANO);
  TTree *t$i = (TTree*)y->Get("Events");
  TFile  *yy = new TFile (BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  if (nEntries_Nano != nEntries_BTA) {
    std::cout << "Different number of events" << '\n';
  } else {
    int nEntries = nEntries_BTA;
    Long64_t entry[nEntries];
    get_map(nEntries, entry, map);
    plot_fatdis_DeepCSVb(BTA, NANO, nEntries, entry, h_DeepCSVb);
  }
  makebeauty();
  h_DeepCSVb->Draw("COLZ");
  pdfpainter("/home/argada/work/newpics", "FatJet_DeepCSVb2", c$i);
}
