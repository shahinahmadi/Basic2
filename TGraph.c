{
c1= new TCanvas("c1", "a simple");
Int_t n=10;
Double_t X[n]={.1,.2,.3,.4,.5,.6,.7,.8,.9,.10};
Double_t Y[n]={.2,.4,.6,.8,.10,.12,.14,.16,.18,.20};
 gr= new Tgraph(n,x,y);
gr->Draw();
}
