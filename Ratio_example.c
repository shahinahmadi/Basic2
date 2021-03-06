
void graph4() {
TCanvas *c1 = new TCanvas("c1","3 Graphs",700,900);

   auto *p2 = new TPad("p2","p3",0.,0.,1.,0.3); p2->Draw();
   p2->SetTopMargin(0.001);
   p2->SetBottomMargin(0.3);
   p2->SetLogx ();
   p2->SetGrid();

   auto *p1 = new TPad("p1","p1",0.,0.3,1.,1.);  p1->Draw();
   p1->SetBottomMargin(0.001);
   p1->cd();
   p1->SetGrid();
   p1->SetLogx ();
   p1->SetLogy();

   

   //create the coordinates arrays

   const Int_t n = 87;

   Float_t x1[n]={1.00E-009, 1.00E-008, 2.53E-008, 1.00E-007, 2.00E-007, 5.00E-007, 1.00E-006, 2.00E-006, 5.00E-006,
   1.00E-005, 2.00E-005, 5.00E-005, 0.0001, 0.0002, 0.0005, 0.001, 0.002, 0.005, 0.01, 0.02, 0.03, 0.05, 0.07, 0.1, 0.144,
   0.15, 0.2, 0.25, 0.3, 0.5, 0.565, 0.7, 0.9, 1, 1.2, 2, 2.5, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 14.8, 15, 16, 18, 19, 20, 25,
   30, 35, 40, 45, 50, 55, 60, 70, 80, 90, 100, 120, 140, 150, 160, 180, 200, 250, 300, 400, 500, 600, 700, 800, 900, 1000,
   1200, 1500, 2000, 2500, 3000, 4000, 5000};

   Float_t y1[n]={1.94E-002, 2.45E-002, 2.88E-002, 4.40E-002, 5.82E-002, 7.19E-002, 8.08E-002, 9.49E-002, 1.13E-001, 1.21E-001,
   1.31E-001, 1.44E-001, 1.59E-001, 1.64E-001, 1.83E-001, 2.04E-001, 2.09E-001, 2.20E-001, 2.45E-001, 2.65E-001, 2.86E-001,
   3.19E-001, 3.48E-001, 3.94E-001, 4.46E-001, 4.69E-001, 5.28E-001, 5.97E-001, 6.69E-001, 8.83E-001, 9.55E-001, 1.07E+000,
   1.20E+000, 1.25E+000, 1.35E+000, 1.49E+000, 1.50E+000, 1.52E+000, 1.36E+000, 1.37E+000, 1.28E+000, 1.21E+000, 1.11E+000,
   1.08E+000, 1.07E+000, 1.03E+000, 1.02E+000, 1.00E+000, 1.01E+000, 9.98E-001, 1.02E+000, 1.04E+000, 1.01E+000, 9.22E-001,
   9.53E-001, 9.50E-001, 9.98E-001, 1.02E+000, 1.05E+000, 1.07E+000, 1.08E+000, 1.11E+000, 1.16E+000, 1.18E+000, 1.22E+000,
   1.27E+000, 1.31E+000, 1.33E+000, 1.35E+000, 1.40E+000, 1.42E+000, 1.52E+000, 1.57E+000, 1.69E+000, 1.78E+000, 1.90E+000,
   1.99E+000, 2.06E+000, 2.11E+000, 2.19E+000, 2.29E+000, 2.42E+000, 2.52E+000, 2.62E+000, 2.69E+000, 2.78E+000, 2.79E+000};

   Float_t x2[n]={1.00E-009,
   1.00E-008, 2.53E-008, 1.00E-007, 2.00E-007, 5.00E-007, 1.00E-006, 2.00E-006, 5.00E-006, 1.00E-005, 2.00E-005, 5.00E-005,
   0.0001, 0.0002, 0.0005, 0.001, 0.002, 0.005, 0.01, 0.02, 0.03, 0.05, 0.07, 0.1, 0.144, 0.15, 0.2, 0.25, 0.3, 0.5, 0.565,
   0.7, 0.9, 1, 1.2, 2, 2.5, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 14.8, 15, 16, 18, 19, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70,
   80, 90, 100, 120, 140, 150, 160, 180, 200, 250, 300, 400, 500, 600, 700, 800, 900, 1000, 1200, 1500, 2000, 2500, 3000,
   4000, 5000};

   Float_t y2[n]={1.88E-002, 2.44E-002, 2.92E-002, 4.37E-002, 5.73E-002, 7.22E-002, 8.19E-002, 9.50E-002, 1.13E-001, 1.21E-001,
   1.31E-001, 1.43E-001, 1.59E-001, 1.64E-001, 1.84E-001, 2.03E-001, 2.07E-001, 2.20E-001, 2.46E-001, 2.66E-001, 2.85E-001,
   3.22E-001, 3.49E-001, 3.96E-001, 4.46E-001, 4.69E-001, 5.27E-001, 5.99E-001, 6.70E-001, 8.83E-001, 9.54E-001, 1.07E+000,
   1.20E+000, 1.25E+000, 1.34E+000, 1.49E+000, 1.48E+000, 1.53E+000, 1.36E+000, 1.36E+000, 1.29E+000, 1.21E+000, 1.11E+000,
   1.07E+000, 1.09E+000, 1.05E+000, 1.01E+000, 1.01E+000, 1.01E+000, 1.01E+000, 1.03E+000, 1.04E+000, 1.11E+000, 1.09E+000,
   1.14E+000, 1.18E+000, 1.23E+000, 1.27E+000, 1.31E+000, 1.34E+000, 1.37E+000, 1.45E+000, 1.52E+000, 1.58E+000, 1.62E+000,
   1.77E+000, 1.82E+000, 1.85E+000, 1.88E+000, 1.92E+000, 1.95E+000, 2.09E+000, 2.13E+000, 2.31E+000, 2.56E+000, 2.91E+000,
   3.09E+000, 3.27E+000, 3.41E+000, 3.59E+000, 3.80E+000, 4.14E+000, 4.62E+000, 4.92E+000, 5.17E+000, 5.64E+000, 6.10E+000};

   TGraph*gr1 = new TGraph(n,x1,y1);
   TGraph*gr2 = new TGraph(n,x2,y2);

   gr1->SetLineColor(4);
   gr1->SetMarkerColor(1);
   gr1->SetMarkerStyle(8);
   gr1->SetMarkerSize(0.8);
   gr1->SetTitle("");

   gr1->SetTitle("");

   gr1->GetXaxis()->SetTitle("Energie [MeV]");
   gr1->GetXaxis()->CenterTitle();

   gr1->GetYaxis()->SetTitle("Coups par unit#acute{e}  de fluence [cps-cm^{2}]");
   gr1->GetYaxis()->CenterTitle();
   gr1->GetYaxis()->SetRangeUser(0.8E-03,30);
   gr1->GetYaxis()->SetTitleOffset(1.5);
   gr1->GetXaxis()->SetTickSize(0.);

   gr1->Draw("AP");

   gr2->SetMarkerColor(kRed);
   gr2->SetMarkerStyle(33);
   gr2->SetMarkerSize(0.8);
   gr2->Draw("P");

   TLegend *leg = new TLegend(0.15,0.75,0.5,0.85);

   leg->AddEntry(gr1,"QGSP_BIC_HP","lp");
   leg->AddEntry(gr2,"QGSP_BERT_HP","lp");
   leg->Draw();

   // ratio
   p2->cd();
   TGraph*r = new TGraph(n); r->SetTitle("");
   for (int i=0; i<n; i++) r->SetPoint(i, x1[i], y1[i]/y2[i]);
      r->GetXaxis()->SetLabelSize(0.075);
      r->GetYaxis()->SetLabelSize(0.075);
   r->Draw("AL");
}
