// Example of ROOt Formulaclass
{
  f1=new TF1("f1","sin(x)",0,5);
  f1->SetLineColor(kBlue+2);
  f1->SetTitle("My Function;X;Y");
  f1->Draw();
  
  f2=new TF1("f2","cos(x)",0,5);
   f2->SetLineColor(kRed+2);
    f2->SetTitle("My second Function;Xs;Ys");
    f2->Draw("same");
}
