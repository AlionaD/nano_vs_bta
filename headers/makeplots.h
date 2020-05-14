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
