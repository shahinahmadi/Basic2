#include <cmath>
#include "TH2D.h"
#include "TFile.h"

const double Rearth = 6378.1; // km
const double d_atmos = 10.0; // km
const double E_atmos = 1.0; // GeV
const double pi = std::acos(-1.);

// distance in km to atmosphere at zenith angle in radians
double x_of_theta_z( double thetaz ){
  double cth = std::cos( thetaz );
  double R = Rearth;
  double d = d_atmos;
  return std::sqrt( R*R*cth*cth + d*d + 2*R*d ) - R*cth;
}

// oscillation probability given
// sin^2(2*theta), delta_m^2 (eV^2), L in km, E in GeV
double prob_osc( double sin22th, double dm2, double L, double E ){
  double sinterm = sin( 1.27 * dm2 * L / E );
  //std::cout<<"prob_osc="<<sin22th*sinterm*sinterm<<" sin22th="<<sin22th<<" dm2="<<dm2<<" L="<<L<<std::endl;
  return 1.0 - sin22th * sinterm * sinterm ;
}  

// average probability over zenith angle 
// from zenith angle thz_min to thz_max in radians
// dm2 in ev^2
double avgprob( double thz_min, double thz_max, double sin22th, double dm2 ){
  const int nangs=360;
  double dthz = (thz_max-thz_min)/nangs;
  double retval = 0.0;
  for ( int i=0; i<nangs; ++i){
    double ang = thz_min + dthz/2 + i*dthz;
    double Lang = x_of_theta_z( ang );
    //std::cout<<"avgprob, thetaz="<<ang<<" L="<<Lang<<std::endl;
    double prob_ang = prob_osc( sin22th, dm2, Lang, E_atmos );
    retval += std::sin( ang ) * prob_ang;
  }
  //  std::cout<<"avgprob="<<retval<<" dthz="<<dthz<<" 1/nang="<<1/nangs<<" P*dth="<<retval*dthz<<" P/nang="<<retval/nangs<<std::endl;
  return retval*dthz;
}

double chi2( double sin22th, double dm2 ){
  double pup = avgprob( 0., pi/2, sin22th, dm2 );
  double pdn = avgprob( pi/2, pi, sin22th, dm2 );

  //std::cout<<"chi2 pup="<<pup<<" pdn="<<pdn<<" for sin22th="<<sin22th<<" dm2="<<dm2<<std::endl;
  return ((pup-0.95)*(pup-0.95) + (pdn-0.5)*(pdn-0.5))*1000000.0;
}

void solveatmospheric(){

  TH2D* th=new TH2D("th"," ; #Delta m^{2} (eV^{2}); sin^{2} 2#theta",1000,0.0,0.005,1000,0.,1.);

  for (int ix=1; ix<=th->GetNbinsX(); ++ix ){
    for (int iy=1; iy<=th->GetNbinsX(); ++iy ){
      double dm2 = th->GetXaxis()->GetBinCenter( ix );
      double sin22th = th->GetYaxis()->GetBinCenter( iy );
      th->SetBinContent( ix, iy, chi2( sin22th, dm2 ) );
    }
  }
  th->Draw("colz");
}
