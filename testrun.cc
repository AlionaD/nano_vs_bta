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


void test_map(const char *BTA, const char *NANO){ /*Need files with event branches */

  //const char *BTA = "/home/argada/work/test_b/JetTree_mc_FatJets_Subjets_Aliona_all1_2204.root";
  //const char *NANO = "/home/argada/work/test_b/nano106.root";

  string map = "./maps/mapmap.txt";
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

void test_fatnjetpic(const char *BTA, const char *NANO){ /* Need map */

  //const char *BTA = "/home/argada/work/test_b/JetTree_mc_FatJets_Subjets_Aliona_all4_2204.root";
  //const char *NANO = "/home/argada/work/test_b/nano106.root";
  string map = "./maps/mapmap.txt";
  TH2F* h_nJet = new TH2F("nFatJet", "nFatJet", 10, 0, 10, 10, 0, 10);
  TCanvas *c$i = new TCanvas ("Reco jet", "Reco jet", 1200, 1200);
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
    plot_plot(BTA, NANO, 1000, entry, h_nJet);
  }
  makebeauty();
  h_nJet->Draw("COLZ");
  pdfpainter(".", "nFatJet", c$i); .

}
