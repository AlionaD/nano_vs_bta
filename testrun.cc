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


void all_nSV_2(){
  const char *BTA = "/home/argada/work/test_b/JetTree_mc_FatJets_Subjets_Aliona_all1_2204.root";
  const char *BTA2 = "/home/argada/work/test_b/JetTree_mc_FatJets_Subjets_Aliona_all2_2204.root";
  const char *DASZLE = "/home/argada/work/test_b/nano106.root";
  bool DATA = false;
  int degree = 10;
  int degree_c = 1;
  TFile  *y = new TFile(DASZLE);
  TFile f(DASZLE);
  TTree *t$i = (TTree*)y->Get("Events");
  float radius = 0.4;
  UInt_t nJetsRead_Nano;
  UInt_t nGenJetsRead_Nano;
  float Rho_Nano;
  float etaRead_Nano[50];
  float ptRead_Nano[50];
  float phiRead_Nano[50];
  float massRead_Nano[50];
  float genptRead_Nano[50];
  float genetaRead_Nano[50];
  float genphiRead_Nano[50];
  UInt_t Run_Nano;
  ULong64_t event_Nano;
  UInt_t Lumi_Nano;
  Int_t nPU_Nano;
  Float_t nPUtrue_Nano;
  Int_t nPV_Nano;
  float mc_weight_Nano;
  UInt_t nGenPart_Nano;
  Int_t GenPart_ID_Nano[200];
  Float_t GenPart_eta_Nano[200];
  Float_t PVz_Nano;
  Int_t Jet_partonFlavour_Nano[50];
  Int_t Jet_hadronFlavour_Nano[50];
  Float_t Jet_cMVAv2_Nano[50];
  Float_t Jet_CombIVF_Nano[50];
  Float_t JRawFactor_Nano[50];
  Float_t Jet_DeepFlavourB_Nano[50];
  Float_t Jet_DeepFlavourC_Nano[50];
  Float_t Jet_DeepCSVc_Nano[50];
  Float_t Jet_DeepCSVb_Nano[50];
  Int_t GenJetsIdx_Nano[50];
  UInt_t nSV_Nano;
  Float_t SV_dlen_Nano[50];
  Float_t SV_dlenSig_Nano[50];
  Float_t SV_pAngle_Nano[50];
  Float_t SV_chi2_Nano[50];
  Float_t SV_eta_Nano[50];
  Float_t SV_mass_Nano[50];
  Float_t SV_ndof_Nano[50];
  Float_t SV_phi_Nano[50];
  Float_t SV_pt_Nano[50];
  Float_t SV_x_Nano[50];
  Float_t SV_y_Nano[50];
  Float_t SV_z_Nano[50];
  Float_t Jet_area_Nano[50];

  UInt_t nElectron_Nano;
  Int_t Electron_IdxJet_Nano[50];
  Float_t Electron_eta_Nano[50];
  Float_t Electron_pt_Nano[50];
  Float_t Electron_phi_Nano[50];

  UInt_t Muon_Nano;
  Int_t Muon_IdxJet_Nano[50];
  Float_t Muon_eta_Nano[50];
  Float_t Muon_pt_Nano[50];
  Float_t Muon_phi_Nano[50];

//Electron_jetIdx
  int n_elec=0;
  int not_emty=0;

  t$i->SetBranchAddress("nJet",&nJetsRead_Nano);
  t$i->SetBranchAddress("Jet_eta",etaRead_Nano);
  t$i->SetBranchAddress("Jet_phi",phiRead_Nano);
  t$i->SetBranchAddress("Jet_pt",ptRead_Nano);
  t$i->SetBranchAddress("Jet_mass",massRead_Nano);
  t$i->SetBranchAddress("run",&Run_Nano);
  t$i->SetBranchAddress("fixedGridRhoFastjetAll",&Rho_Nano);
  t$i->SetBranchAddress("event",&event_Nano);
  t$i->SetBranchAddress("Pileup_nPU",&nPU_Nano);
  t$i->SetBranchAddress("Pileup_nTrueInt",&nPUtrue_Nano);
  t$i->SetBranchAddress("luminosityBlock",&Lumi_Nano);
  t$i->SetBranchAddress("PV_npvs",&nPV_Nano);
  t$i->SetBranchAddress("PV_z", &PVz_Nano);
  t$i->SetBranchAddress("Jet_area", Jet_area_Nano);
  t$i->SetBranchAddress("Jet_partonFlavour", Jet_partonFlavour_Nano);
  t$i->SetBranchAddress("Jet_hadronFlavour", Jet_hadronFlavour_Nano);
  t$i->SetBranchAddress("Jet_btagCMVA", Jet_cMVAv2_Nano);
  t$i->SetBranchAddress("Jet_btagCSVV2", Jet_CombIVF_Nano);
  t$i->SetBranchAddress("Jet_rawFactor", JRawFactor_Nano);
  t$i->SetBranchAddress("Jet_btagDeepFlavB", Jet_DeepFlavourB_Nano);
  t$i->SetBranchAddress("Jet_btagDeepFlavC", Jet_DeepFlavourC_Nano);
  t$i->SetBranchAddress("Jet_btagDeepC", Jet_DeepCSVc_Nano);
  t$i->SetBranchAddress("Jet_btagDeepB", Jet_DeepCSVb_Nano);
  t$i->SetBranchAddress("nSV", &nSV_Nano);
  t$i->SetBranchAddress("SV_dlen", SV_dlen_Nano);
  t$i->SetBranchAddress("SV_dlenSig", SV_dlenSig_Nano);
  t$i->SetBranchAddress("SV_pAngle", SV_pAngle_Nano);
  t$i->SetBranchAddress("SV_chi2", SV_chi2_Nano);
  t$i->SetBranchAddress("SV_eta", SV_eta_Nano);
  t$i->SetBranchAddress("SV_mass", SV_mass_Nano);
  t$i->SetBranchAddress("SV_ndof", SV_ndof_Nano);
  t$i->SetBranchAddress("SV_phi", SV_phi_Nano);
  t$i->SetBranchAddress("SV_pt", SV_pt_Nano);
  t$i->SetBranchAddress("SV_x", SV_x_Nano);
  t$i->SetBranchAddress("SV_y", SV_y_Nano);
  t$i->SetBranchAddress("SV_z", SV_z_Nano);

  t$i->SetBranchAddress("SV_z", SV_z_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btagana");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Int_t nJetsRead_BTA;
  float etaRead_BTA[50];
  float ptRead_BTA[50];
  float phiRead_BTA[50];
  Int_t event_BTA;
  Int_t Lumi_BTA;
  Int_t nPU_BTA;
  float nPUtrue_BTA;
  Int_t nPV_BTA;
  float mc_weight_BTA;
  Int_t ncQuarks_BTA;
  float cQuark_eta_BTA[200];
  float PVz_BTA;
  float Jet_DeepFlavourB_BTA[50];
  float Jet_DeepCSVc_BTA[50];
  float Jet_DeepFlavourC_BTA[50];
  float Jet_DeepCSVb_BTA[50];
  float Jet_uncorrpt_BTA[50];
  float Jet_area_BTA[50];
  float Jet_CombIVF_BTA[50];
  float Jet_cMVAv2_BTA[50];
  Int_t Jet_ntracks_BTA[50];
  Int_t Jet_flavour_BTA[50];
  Int_t Jet_partonFlavour_BTA[50];
  Int_t Jet_hadronFlavour_BTA[50];
  Int_t Loose_ID_BTA[50];
  float Jet_jes_BTA[50];
  Int_t nGenlep_BTA;

  g$i->SetBranchAddress("nJet",&nJetsRead_BTA);
  g$i->SetBranchAddress("Jet_eta",etaRead_BTA);
  g$i->SetBranchAddress("Jet_pt",ptRead_BTA);
  g$i->SetBranchAddress("Jet_phi",phiRead_BTA);

  g$i->SetBranchAddress("nGenlep",&nGenlep_BTA);
  g$i->SetBranchAddress("Evt",&event_BTA);
  g$i->SetBranchAddress("LumiBlock",&Lumi_BTA);
  g$i->SetBranchAddress("nPU",&nPU_BTA);
  g$i->SetBranchAddress("nPUtrue",&nPUtrue_BTA);
  g$i->SetBranchAddress("nPV",&nPV_BTA);
  g$i->SetBranchAddress("mcweight",&mc_weight_BTA);
  g$i->SetBranchAddress("ncQuarks",&ncQuarks_BTA);
  g$i->SetBranchAddress("cQuark_eta",cQuark_eta_BTA);
  g$i->SetBranchAddress("PVz", &PVz_BTA);
  Int_t Jet_SV_BTA[50];
  g$i->SetBranchAddress("Jet_SV_multi",Jet_SV_BTA);

  TFile  *yy2 = new TFile (BTA2);
  TFile ff2(BTA2);
  //TTree *t$i = (TTree*)yy2->Get("btagana/ttree");
  TDirectory* dir2 = gFile->GetDirectory("btagana");
  TTree *y$i;
  dir2->GetObject("ttree", y$i);
  Int_t nJetsRead_BTA2;
  Int_t nSV_BTA2;
  float SV_vtx_pt_BTA2[50];
  float SV_mass_BTA2[50];
  float SV_vtx_eta_BTA2[50];
  float SV_vtx_phi_BTA2[50];
  y$i->SetBranchAddress("nJet",&nJetsRead_BTA2);
  y$i->SetBranchAddress("nSV",&nSV_BTA2);
  y$i->SetBranchAddress("SV_vtx_pt", SV_vtx_pt_BTA2);
  y$i->SetBranchAddress("SV_mass", SV_mass_BTA2);
  y$i->SetBranchAddress("SV_vtx_eta", SV_vtx_eta_BTA2);
  y$i->SetBranchAddress("SV_vtx_phi", SV_vtx_phi_BTA2);

  makebeauty();

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();
  Long64_t nEntries_BTA2=(Long64_t)y$i->GetEntries();
//round(value*10)/10  floor
  TH2F* h_SV_mach = new TH2F("", "Number of secondary vertices", 20, 0, 20, 20, 0, 20);
  TH2F* rho = new TH2F("rho from all PF Candidates", "rho from all PF Candidates", 140, 0, 70, 140, 0, 70);
  TH2F* h_gen_pt = new TH2F("Gen jet p_{T}", "Gen jet p_{T}", 100, 0, 100, 100, 0, 100);
  TH2F* h_nJet = new TH2F("Entry map", "Entry map", 20, 0, 20, 20, 0, 20);
  TH2F* h_DeepCSVc = new TH2F("", "DeepCSV charm btag discriminator", 101, 0, 1.01, 101, 0, 1.01);

  int phi_dis = 0;
  int eta_dis = 0;
  int mass_dis = 0;

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    t$i->GetEntry(iEntry_Nano);

    for (Long64_t iEntry_BTA=0; ((iEntry_BTA<nEntries_BTA)&&(iEntry_BTA<nEntries_Nano+10)); iEntry_BTA++){//nEntries_BTA)&&(iEntry_BTA<nEntries_Nano+10)); iEntry_BTA++){
      g$i->GetEntry(iEntry_BTA);
      y$i->GetEntry(iEntry_BTA);
      int matched_jets_event=0;
      int matched_jets[30][30];
      for (size_t ii = 0; ii < 30; ii++) {
        for (size_t iii = 0; iii < 30; iii++) {
          matched_jets[iii][ii]=0;
        }
      }
      int nSV_BTA_int = 0;
      for (int iJet_Nano=0; iJet_Nano<nJetsRead_Nano; iJet_Nano++){
        if(nJetsRead_Nano<nJetsRead_BTA){
          break;
        }

        if(ptRead_Nano[0]>ptRead_BTA[0]+1){
          break;
        }

        for (int iJet_BTA=0; iJet_BTA<nJetsRead_BTA; iJet_BTA++){
          if((ptRead_Nano[iJet_Nano]>=20)&&(abs(etaRead_Nano[iJet_Nano])<=2.5)){
            if(((floor(ptRead_Nano[iJet_Nano]*degree)/degree == floor(ptRead_BTA[iJet_BTA]*degree)/degree)||\
            (floor(ptRead_Nano[iJet_Nano]*degree+1)/degree == floor(ptRead_BTA[iJet_BTA]*degree)/degree)||\
            (floor(ptRead_Nano[iJet_Nano]*degree-1)/degree == floor(ptRead_BTA[iJet_BTA]*degree)/degree))&&
            ((floor(etaRead_Nano[iJet_Nano]*degree)/degree == floor(etaRead_BTA[iJet_BTA]*degree)/degree)||\
            (floor(etaRead_Nano[iJet_Nano]*degree+1)/degree == floor(etaRead_BTA[iJet_BTA]*degree)/degree)||
            (floor(etaRead_Nano[iJet_Nano]*degree-1)/degree == floor(etaRead_BTA[iJet_BTA]*degree)/degree))&&\
            ((floor(phiRead_Nano[iJet_Nano]*degree)/degree == floor(phiRead_BTA[iJet_BTA]*degree)/degree)||\
            (floor(phiRead_Nano[iJet_Nano]*degree+1)/degree == floor(phiRead_BTA[iJet_BTA]*degree)/degree)||
            (floor(phiRead_Nano[iJet_Nano]*degree-1)/degree == floor(phiRead_BTA[iJet_BTA]*degree)/degree))){
              //std::cout << "ALERT ALERT ALERT ALERT ALERT ALERT " << '\n';
              matched_jets_event++;
              matched_jets[iJet_BTA][iJet_Nano]++;
            }
          }
        }
      }
      int matched_SV_jets = 0;
      for (int iJet_Nano=0; iJet_Nano<nJetsRead_Nano; iJet_Nano++){
        if(matched_jets_event != nJetsRead_BTA){
          break;
        }
        //std::cout << "ALERT ALERT ALERT ALERT ALERT ALERT " << '\n';
      }
      for (int iJet_Nano=0; iJet_Nano<nJetsRead_Nano; iJet_Nano++){
        if(matched_jets_event != nJetsRead_BTA){
          break;
        }
      }

      int nlep=0;
      if (matched_jets_event == nJetsRead_BTA) {
        //std::cout << nlep << " " << nGenlep_BTA << '\n';
        not_emty++;
        for (int iJet_Nano=0; iJet_Nano<nJetsRead_Nano; iJet_Nano++){
          if((ptRead_Nano[iJet_Nano]>=20)&&(abs(etaRead_Nano[iJet_Nano])<=2.5)){
            for (size_t iSV = 0; iSV < nSV_Nano; iSV++) {
              if (sqrt(pow(SV_eta_Nano[iSV] - etaRead_Nano[iJet_Nano], 2) + \
                pow(SV_phi_Nano[iSV] - phiRead_Nano[iJet_Nano], 2)) <= 0.3) {
                  matched_SV_jets++;
              }
            }
          }
        }
        if (matched_SV_jets > nSV_Nano) {
          std::cout << "ALERT ALERT " << '\n';
          std::cout << matched_SV_jets << " " <<   nSV_Nano << '\n';
        }

        h_SV_mach->Fill(nSV_BTA2, matched_SV_jets, 1);
        std::cout << iEntry_BTA << '\n';
      }
    }
  }
  h_SV_mach->GetYaxis()->SetTitle( "nSV matched Nano" );
  h_SV_mach->GetXaxis()->SetTitle( "nSV BTA" );
  h_nJet->GetXaxis()->SetTitle( "Entry_{BTA}" );
  h_nJet->GetYaxis()->SetTitle( "Entry_{Nano}" );
  rho->GetXaxis()->SetTitle( "#rho BTA" );
  rho->GetYaxis()->SetTitle( "#rho Nano" );
  TCanvas *c$i = new TCanvas ("Reco jet", "Reco jet", 1200, 1200);
  h_SV_mach->Draw("COLZ");
  c$i->SetRightMargin(0.15);
  std::cout << not_emty << '\n';
  pdfpainter("/home/argada/work/newpics", "nSV_jet_mach2", c$i);
  c$i->Close();
}


//void test_test(const char *BTA, const char *NANO){
void test_test(){

  const char *BTA = "/home/argada/work/test_b/JetTree_mc_FatJets_Subjets_Aliona_all1_2204.root";
  const char *NANO = "/home/argada/work/test_b/nano106.root";

  string map = "./maps/mapmap.txt";
  map_map(BTA, NANO, map);
  TFile  *y = new TFile(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  TFile  *yy = new TFile (BTA);
  //TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();



  Long64_t entry[1000];
  get_map(1000, entry, map);
  TH2F* h_nJet = new TH2F("nFatJet", "nFatJet", 10, 0, 10, 10, 0, 10);
  TCanvas *c$i = new TCanvas ("Reco jet", "Reco jet", 1200, 1200);
  makebeauty();
  //plot_plot(BTA, NANO, 1000, entry, h_nJet);
  //h_nJet->Draw("COLZ");
  //pdfpainter("/home/argada/work/newpics", "nFatJet", c$i);
}
