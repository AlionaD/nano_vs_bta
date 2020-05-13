void map_map(const char *BTA, const char *NANO, string map){
  TFile  *y = new TFile(NANO);
  TFile f(NANO);
  TTree *t$i = (TTree*)y->Get("Events");

  std::ofstream ofs( map, std::ofstream::trunc);

  //ofs << "lorem ipsum";

  ULong64_t event_Nano;
  t$i->SetBranchAddress("event",&event_Nano);

  TFile  *yy = new TFile (BTA);
  TFile ff(BTA);
  TDirectory* dir = gFile->GetDirectory("btagana");
  TTree *g$i;
  dir->GetObject("ttree", g$i);

  Int_t event_BTA;
  g$i->SetBranchAddress("Evt",&event_BTA);

  Long64_t nEntries_Nano=(Long64_t)t$i->GetEntries();
  Long64_t nEntries_BTA=(Long64_t)g$i->GetEntries();

  for (Long64_t iEntry_Nano=0; iEntry_Nano<nEntries_Nano; iEntry_Nano++){
    t$i->GetEntry(iEntry_Nano);
    for (Long64_t iEntry_BTA=0; ((iEntry_BTA<nEntries_BTA)&&(iEntry_BTA<nEntries_Nano+10)); iEntry_BTA++){//nEntries_BTA)&&(iEntry_BTA<nEntries_Nano+10)); iEntry_BTA++){
      g$i->GetEntry(iEntry_BTA);
      if(event_Nano==event_BTA){
        std::cout << iEntry_BTA << " eventNano: " << event_Nano \
        << " event_BTA: " << event_BTA << '\n';
        ofs << iEntry_BTA << '\n';
      }
    }
  }
  ofs.close();
}

void get_map(int n, Long64_t entry[n], string map){
  int i_f = 0;
  std::ifstream fs(map);
    while ( !fs.eof() )
  {
    fs >> entry[i_f];
    i_f++;
  }
}
