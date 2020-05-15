void plot_plot(const char *BTA, const char *NANO, int n, Long64_t entry[n], TH2F* h_nJet){
  TFile  *y = new TFile(NANO);
  TFile f(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  UInt_t nJetsRead_Nano;
  float etaRead_Nano[50];
  float ptRead_Nano[50];
  float phiRead_Nano[50];
  float massRead_Nano[50];
  float Jet_area_Nano[50];

  t$i->SetBranchAddress("nFatJet",&nJetsRead_Nano);
  t$i->SetBranchAddress("FatJet_eta",etaRead_Nano);
  t$i->SetBranchAddress("FatJet_phi",phiRead_Nano);
  t$i->SetBranchAddress("FatJet_pt",ptRead_Nano);
  t$i->SetBranchAddress("FatJet_mass",massRead_Nano);
  t$i->SetBranchAddress("FatJet_area",Jet_area_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Int_t nJetsRead_BTA;
  float etaRead_BTA[50];
  float ptRead_BTA[50];
  float phiRead_BTA[50];
  float massRead_BTA[50];
  float Jet_area_BTA[50];

  g$i->SetBranchAddress("FatJetInfo.nJet",&nJetsRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_eta",etaRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_pt",ptRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_phi",phiRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_mass",massRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_area",Jet_area_BTA);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    Long64_t iEntry_BTA1 = entry[iEntry_Nano];
    g$i->GetEntry(iEntry_BTA1);
    t$i->GetEntry(iEntry_Nano);
    int nJet =0;
    for (size_t iJet_Nano = 0; iJet_Nano < nJetsRead_Nano; iJet_Nano++) {
      if ((abs(etaRead_Nano[iJet_Nano])<2.5)&&(ptRead_Nano[iJet_Nano]>200)) {
        nJet++;
      }
    }
    h_nJet->Fill(nJetsRead_BTA, nJet, 1);
  }
  h_nJet->GetXaxis()->SetTitle( "nFatJet BTA" );
  h_nJet->GetYaxis()->SetTitle( "nFatJet Nano" );
}

void plot_fatkin_pt(const char *BTA, const char *NANO, int n, Long64_t entry[n], TH2F* h_pt){
  TFile  *y = new TFile(NANO);
  TFile f(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  UInt_t nJetsRead_Nano;
  float etaRead_Nano[50];
  float ptRead_Nano[50];
  float phiRead_Nano[50];
  float massRead_Nano[50];
  float Jet_area_Nano[50];

  t$i->SetBranchAddress("nFatJet",&nJetsRead_Nano);
  t$i->SetBranchAddress("FatJet_eta",etaRead_Nano);
  t$i->SetBranchAddress("FatJet_phi",phiRead_Nano);
  t$i->SetBranchAddress("FatJet_pt",ptRead_Nano);
  t$i->SetBranchAddress("FatJet_mass",massRead_Nano);
  t$i->SetBranchAddress("FatJet_area",Jet_area_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Int_t nJetsRead_BTA;
  float etaRead_BTA[50];
  float ptRead_BTA[50];
  float phiRead_BTA[50];
  float massRead_BTA[50];
  float Jet_area_BTA[50];

  g$i->SetBranchAddress("FatJetInfo.nJet",&nJetsRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_eta",etaRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_pt",ptRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_phi",phiRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_mass",massRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_area",Jet_area_BTA);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    Long64_t iEntry_BTA1 = entry[iEntry_Nano];
    g$i->GetEntry(iEntry_BTA1);
    t$i->GetEntry(iEntry_Nano);
    int nJet =0;
    for (size_t iJet_Nano = 0; iJet_Nano < nJetsRead_Nano; iJet_Nano++) {
      if ((abs(etaRead_Nano[iJet_Nano])<2.5)&&(ptRead_Nano[iJet_Nano]>200)) {
        h_pt->Fill(ptRead_BTA[nJet], ptRead_Nano[iJet_Nano], 1);
        nJet++;
      }
    }
    if (nJet != nJetsRead_BTA) {
      std::cout << "nFatJets is not the same" << '\n';
      std::cout << "Potracheno" << '\n';
      break;
    }
  }
  h_pt->GetXaxis()->SetTitle( "p_{T} BTA" );
  h_pt->GetYaxis()->SetTitle( "p_{T} Nano" );
}

void plot_fatkin_eta(const char *BTA, const char *NANO, int n, Long64_t entry[n], TH2F* h_eta){
  TFile  *y = new TFile(NANO);
  TFile f(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  UInt_t nJetsRead_Nano;
  float etaRead_Nano[50];
  float ptRead_Nano[50];

  t$i->SetBranchAddress("nFatJet",&nJetsRead_Nano);
  t$i->SetBranchAddress("FatJet_eta",etaRead_Nano);
  t$i->SetBranchAddress("FatJet_pt",ptRead_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Int_t nJetsRead_BTA;
  float etaRead_BTA[50];
  float ptRead_BTA[50];

  g$i->SetBranchAddress("FatJetInfo.nJet",&nJetsRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_eta",etaRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_pt",ptRead_BTA);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    Long64_t iEntry_BTA1 = entry[iEntry_Nano];
    g$i->GetEntry(iEntry_BTA1);
    t$i->GetEntry(iEntry_Nano);
    int nJet =0;
    for (size_t iJet_Nano = 0; iJet_Nano < nJetsRead_Nano; iJet_Nano++) {
      if ((abs(etaRead_Nano[iJet_Nano])<2.5)&&(ptRead_Nano[iJet_Nano]>200)) {
        h_eta->Fill(etaRead_BTA[nJet], etaRead_Nano[iJet_Nano], 1);
        nJet++;
      }
    }
    if (nJet != nJetsRead_BTA) {
      std::cout << "nFatJets is not the same" << '\n';
      std::cout << "Potracheno" << '\n';
      break;
    }
  }
  h_eta->GetXaxis()->SetTitle( "#eta BTA" );
  h_eta->GetYaxis()->SetTitle( "#eta Nano" );
}

void plot_fatkin_phi(const char *BTA, const char *NANO, int n, Long64_t entry[n], TH2F* h_phi){
  TFile  *y = new TFile(NANO);
  TFile f(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  UInt_t nJetsRead_Nano;
  float etaRead_Nano[50];
  float ptRead_Nano[50];
  float phiRead_Nano[50];

  t$i->SetBranchAddress("nFatJet",&nJetsRead_Nano);
  t$i->SetBranchAddress("FatJet_eta",etaRead_Nano);
  t$i->SetBranchAddress("FatJet_phi",phiRead_Nano);
  t$i->SetBranchAddress("FatJet_pt",ptRead_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Int_t nJetsRead_BTA;
  float etaRead_BTA[50];
  float ptRead_BTA[50];
  float phiRead_BTA[50];

  g$i->SetBranchAddress("FatJetInfo.nJet",&nJetsRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_eta",etaRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_pt",ptRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_phi",phiRead_BTA);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    Long64_t iEntry_BTA1 = entry[iEntry_Nano];
    g$i->GetEntry(iEntry_BTA1);
    t$i->GetEntry(iEntry_Nano);
    int nJet =0;
    for (size_t iJet_Nano = 0; iJet_Nano < nJetsRead_Nano; iJet_Nano++) {
      if ((abs(etaRead_Nano[iJet_Nano])<2.5)&&(ptRead_Nano[iJet_Nano]>200)) {
        h_phi->Fill(phiRead_BTA[nJet], phiRead_Nano[iJet_Nano], 1);
        nJet++;
      }
    }
    if (nJet != nJetsRead_BTA) {
      std::cout << "nFatJets is not the same" << '\n';
      std::cout << "Potracheno" << '\n';
      break;
    }
  }
  h_phi->GetXaxis()->SetTitle( "#phi BTA" );
  h_phi->GetYaxis()->SetTitle( "#phi Nano" );
}

void plot_fatkin_area(const char *BTA, const char *NANO, int n, Long64_t entry[n], TH2F* h_area){
  TFile  *y = new TFile(NANO);
  TFile f(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  UInt_t nJetsRead_Nano;
  float etaRead_Nano[50];
  float ptRead_Nano[50];
  float phiRead_Nano[50];
  float Jet_area_Nano[50];

  t$i->SetBranchAddress("nFatJet",&nJetsRead_Nano);
  t$i->SetBranchAddress("FatJet_eta",etaRead_Nano);
  t$i->SetBranchAddress("FatJet_phi",phiRead_Nano);
  t$i->SetBranchAddress("FatJet_pt",ptRead_Nano);
  t$i->SetBranchAddress("FatJet_area",Jet_area_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Int_t nJetsRead_BTA;
  float etaRead_BTA[50];
  float ptRead_BTA[50];
  float phiRead_BTA[50];
  float Jet_area_BTA[50];

  g$i->SetBranchAddress("FatJetInfo.nJet",&nJetsRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_eta",etaRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_pt",ptRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_phi",phiRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_area",Jet_area_BTA);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    Long64_t iEntry_BTA1 = entry[iEntry_Nano];
    g$i->GetEntry(iEntry_BTA1);
    t$i->GetEntry(iEntry_Nano);
    int nJet =0;
    for (size_t iJet_Nano = 0; iJet_Nano < nJetsRead_Nano; iJet_Nano++) {
      if ((abs(etaRead_Nano[iJet_Nano])<2.5)&&(ptRead_Nano[iJet_Nano]>200)) {
        h_area->Fill(Jet_area_BTA[nJet], Jet_area_Nano[iJet_Nano], 1);
        nJet++;
      }
    }
    if (nJet != nJetsRead_BTA) {
      std::cout << "nFatJets is not the same" << '\n';
      std::cout << "Potracheno" << '\n';
      break;
    }
  }
  h_area->GetXaxis()->SetTitle( "Fat Jet area BTA" );
  h_area->GetYaxis()->SetTitle( "Fat Jet area Nano" );
}

void plot_fatkin_mass(const char *BTA, const char *NANO, int n, Long64_t entry[n], TH2F* h_mass){
  TFile  *y = new TFile(NANO);
  TFile f(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  UInt_t nJetsRead_Nano;
  float etaRead_Nano[50];
  float ptRead_Nano[50];
  float phiRead_Nano[50];
  float massRead_Nano[50];

  t$i->SetBranchAddress("nFatJet",&nJetsRead_Nano);
  t$i->SetBranchAddress("FatJet_eta",etaRead_Nano);
  t$i->SetBranchAddress("FatJet_phi",phiRead_Nano);
  t$i->SetBranchAddress("FatJet_pt",ptRead_Nano);
  t$i->SetBranchAddress("FatJet_mass",massRead_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Int_t nJetsRead_BTA;
  float etaRead_BTA[50];
  float ptRead_BTA[50];
  float phiRead_BTA[50];
  float massRead_BTA[50];

  g$i->SetBranchAddress("FatJetInfo.nJet",&nJetsRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_eta",etaRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_pt",ptRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_phi",phiRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_mass",massRead_BTA);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    Long64_t iEntry_BTA1 = entry[iEntry_Nano];
    g$i->GetEntry(iEntry_BTA1);
    t$i->GetEntry(iEntry_Nano);
    int nJet =0;
    for (size_t iJet_Nano = 0; iJet_Nano < nJetsRead_Nano; iJet_Nano++) {
      if ((abs(etaRead_Nano[iJet_Nano])<2.5)&&(ptRead_Nano[iJet_Nano]>200)) {
        h_mass->Fill(massRead_BTA[nJet], massRead_Nano[iJet_Nano], 1);
        nJet++;
      }
    }
    if (nJet != nJetsRead_BTA) {
      std::cout << "nFatJets is not the same" << '\n';
      std::cout << "Potracheno" << '\n';
      break;
    }
  }
  h_mass->GetXaxis()->SetTitle( "mass BTA" );
  h_mass->GetYaxis()->SetTitle( "mass Nano" );
}

void plot_fatdis_CMVA(const char *BTA, const char *NANO, int n, Long64_t entry[n], TH2F* h_cmva){
  TFile  *y = new TFile(NANO);
  TFile f(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  UInt_t nJetsRead_Nano;
  float etaRead_Nano[50];
  float ptRead_Nano[50];
  float cmva_Nano[50];

  t$i->SetBranchAddress("nFatJet",&nJetsRead_Nano);
  t$i->SetBranchAddress("FatJet_eta",etaRead_Nano);
  t$i->SetBranchAddress("FatJet_pt",ptRead_Nano);
  t$i->SetBranchAddress("FatJet_btagCMVA",cmva_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Int_t nJetsRead_BTA;
  float etaRead_BTA[50];
  float ptRead_BTA[50];
  float cmva_BTA[50];

  g$i->SetBranchAddress("FatJetInfo.nJet",&nJetsRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_eta",etaRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_pt",ptRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_DeepCSVb",cmva_BTA);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    Long64_t iEntry_BTA1 = entry[iEntry_Nano];
    g$i->GetEntry(iEntry_BTA1);
    t$i->GetEntry(iEntry_Nano);
    int nJet =0;
    for (size_t iJet_Nano = 0; iJet_Nano < nJetsRead_Nano; iJet_Nano++) {
      if ((abs(etaRead_Nano[iJet_Nano])<2.5)&&(ptRead_Nano[iJet_Nano]>200)) {
        h_cmva->Fill(cmva_BTA[nJet], cmva_Nano[iJet_Nano], 1);
        nJet++;
      }
    }
    if (nJet != nJetsRead_BTA) {
      std::cout << "nFatJets is not the same" << '\n';
      std::cout << "Potracheno" << '\n';
      break;
    }
  }
  h_cmva->GetXaxis()->SetTitle( "BTA" );
  h_cmva->GetYaxis()->SetTitle( "Nano" );
}

//Jet_DeepCSVBDisc
void plot_fatdis_DeepCSVb(const char *BTA, const char *NANO, int n, Long64_t entry[n], TH2F* h_cmva){
  TFile  *y = new TFile(NANO);
  TFile f(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  UInt_t nJetsRead_Nano;
  float etaRead_Nano[50];
  float ptRead_Nano[50];
  float cmva_Nano[50];

  t$i->SetBranchAddress("nFatJet",&nJetsRead_Nano);
  t$i->SetBranchAddress("FatJet_eta",etaRead_Nano);
  t$i->SetBranchAddress("FatJet_pt",ptRead_Nano);
  t$i->SetBranchAddress("FatJet_btagDeepB",cmva_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btaganaFatJets");
  TTree *g$i;
  dir->GetObject("ttree", g$i);
  Int_t nJetsRead_BTA;
  float etaRead_BTA[50];
  float ptRead_BTA[50];
  float cmva_BTA[50];

  g$i->SetBranchAddress("FatJetInfo.nJet",&nJetsRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_eta",etaRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_pt",ptRead_BTA);
  g$i->SetBranchAddress("FatJetInfo.Jet_DeepCSVBDisc",cmva_BTA);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    Long64_t iEntry_BTA1 = entry[iEntry_Nano];
    g$i->GetEntry(iEntry_BTA1);
    t$i->GetEntry(iEntry_Nano);
    int nJet =0;
    for (size_t iJet_Nano = 0; iJet_Nano < nJetsRead_Nano; iJet_Nano++) {
      if ((abs(etaRead_Nano[iJet_Nano])<2.5)&&(ptRead_Nano[iJet_Nano]>200)) {
        h_cmva->Fill(cmva_BTA[nJet], cmva_Nano[iJet_Nano], 1);
        nJet++;
      }
    }
    if (nJet != nJetsRead_BTA) {
      std::cout << "nFatJets is not the same" << '\n';
      std::cout << "Potracheno" << '\n';
      break;
    }
  }
  h_cmva->GetXaxis()->SetTitle( "BTA" );
  h_cmva->GetYaxis()->SetTitle( "Nano" );
}
