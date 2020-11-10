{
  h1=new TH1D("h1", "one Die; Roll;counts",6,0.5,6.5);
  h2=new TH1D("h2","Two Dice;Roll;counts",12,0.5,12.5);
  for(int i=0; i<10000;i++){
    int r1=gRandom->Integer(6)+1;
    int r2=gRandom->Integer(6)+1;
    h1->Fill(r1);
    h1->Fill(r2);
    h2->Fill(r1+r2);
  }
  c1=new TCanvas("c1", "Bin Size",1000,500);
  c1->Divide(2,1);
  c1->cd(1);
  h1->SetFillColor(kBlue);
  h1->SetMinimum(0);
  h1->Draw();
  c1->cd(2);
  h2->SetFillColor(kRed);
  h2->Draw();
}
