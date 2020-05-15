void pdfpainter(string path, TString s, TCanvas *c$i){
   string dir1 = path;
   dir1 += "/";
   dir1 += s;
   dir1 += ".pdf";
   const char* pdf = dir1.c_str();
   c$i->SetRightMargin(0.15);
   c$i->SetLeftMargin(0.15);
   c$i -> Print(pdf);
}

void makebeauty(){
  static Int_t  colors[100];
  static Bool_t initialized = kFALSE;
  Double_t Red[3]    = {0., 0.66, 1.00};
  Double_t Green[3]  = {0., 0.00, 0.80};
  Double_t Blue[3]   = {0., 0.00, 0.70};
  Double_t Length[3] = {0., 0.30, 1.0};
  Int_t FI = TColor::CreateGradientColorTable(3,Length,Red,Green,Blue,100);
  for (int i=0; i<100; i++) colors[i] = FI+i;
  initialized = kTRUE;
  gStyle->SetPalette(100, colors);
  gStyle -> SetOptStat(0);
}
