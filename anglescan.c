// calculate positions and angles of gantry scan
// for a scan in 2d (in xz plane ).
// use TVector3 with y component always zero.

// Blair Jamieson (July 2019)

const int nscanpoints = 32;
const double Rpmt = 254.0 ; // mm (radius of SK cathode surface)
const double d    = 150.0 ; // mm (disntance from PMT to gantry)
const double theta_inc_max = asin ( Rpmt/ (Rpmt+d ) ); 
const double pi   = acos(-1);
const double rad_per_deg = pi/180.0;

struct GantryTheta {
  vector<double>    thetap;    // positions on PMT that can be scanned
  vector<double>    thetaig;   // pointing angle of gantry from vertical (rad)
  vector<double>    thetai;    // pointing angle of gantry from gantry position angle (rad)
  vector<double>    thetainc;  // incidence angle (rad)
  vector<TVector3>  ri;        // vector from gantry position to point on PMT
  vector<TVector3>  rp;        // positions on PMT as vector
  TVector3          rgi;       // position of gantry this refers to
  GantryTheta( TVector3 pos = TVector3(0.,0.,0.) ) : rgi(pos) { }
};


void print_scan_params(){
  cout<<"nscanpoints = "<<nscanpoints<<endl;
  cout<<"Rpmt        = "<<Rpmt<<" mm"<<endl;
  cout<<"d           = "<<d<<" mm"<<endl;
  cout<<"theta max   = "<< theta_inc_max/rad_per_deg << " deg"<<endl;
}


void draw_scan( const GantryTheta& gth ){
  gStyle->SetOptStat(0);
  gStyle->SetPadLeftMargin(0.2);
  static int callcount=0;
  string win_name=string("hwin")+to_string(callcount);
  TH2D * hwin = new TH2D(win_name.c_str(), win_name.c_str(),100, -Rpmt-2*d, Rpmt+2*d,100, -Rpmt-2*d, Rpmt+2*d );
  string can_name=string("tc")+to_string(callcount);
  TCanvas * cc = new TCanvas( can_name.c_str(), can_name.c_str(), 1000, 1000 );
  cc->cd();
  hwin->SetTitle( " ; x (mm);  z(mm)" );
  hwin->Draw();
  
  TEllipse * pmtel = new TEllipse( 0., 0., Rpmt, 0, 0, 180. );
  pmtel->SetFillStyle(0);
  pmtel->SetLineWidth(3);
  TEllipse * ganel = new TEllipse( 0., 0., Rpmt+d, 0, 0, 180. );
  ganel->SetFillStyle(0);
  ganel->SetLineWidth(3);
  
  pmtel->Draw();
  ganel->Draw();

  // gantry position
  TLine * tlgpos = new TLine( 0., 0., gth.rgi(0), gth.rgi(2) );
  tlgpos->SetLineColor(kGreen);
  tlgpos->SetLineWidth(5);
  tlgpos->Draw();
  // scan over pmt positions
  for ( int ipos = 0; ipos< gth.ri.size(); ++ipos ){
    // Vector to point on PMT
    TArrow * tlpt = new TArrow( 0., 0., gth.rp[ipos](0), gth.rp[ipos](2), 0.01,"|>" );
    tlpt->SetLineColor(kRed);
    tlpt->SetLineWidth(3);
    tlpt->Draw();
    // Line from gantry to point
    TArrow *tlgpt = new TArrow( gth.rgi(0), gth.rgi(2), gth.rp[ipos](0), gth.rp[ipos](2), 0.01,"|>" );
    tlgpt->SetLineColor(kBlue);
    tlgpt->SetLineWidth(3);
    tlgpt->Draw();
    // Vector pointing of gantry to point
    TArrow *tlri = new TArrow( 0., 0., gth.ri[ipos](0), gth.ri[ipos](2), 0.01,"|>" );
    tlri->SetLineColor(kViolet);
    tlri->SetLineWidth(3);
    tlri->Draw();
  }

  char gifname[50];
  sprintf( gifname, "draw_scan_%04d.gif",callcount );
  cc->SaveAs( gifname );

  ++callcount;
}


void print_scan( const GantryTheta& gth ){
  cout<<"===================================="<<endl;
  cout<<" Gantry position : ( "
      << gth.rgi(0) << ", " << gth.rgi(1) << ", "<<gth.rgi(2) << " ) cm "
      << " angle " << atan2( gth.rgi(2), gth.rgi(0) ) / rad_per_deg
      << " deg"<<endl;
  cout <<"PMT-pos(deg)   Gantry-dir-fromz(deg)   G-dir-from-pos(deg)    Inc-angle(deg)"<<endl;
  for ( int i=0; i<gth.thetap.size(); ++i ){
    cout << gth.thetap[i] / rad_per_deg << "\t\t"
	 << gth.thetaig[i] / rad_per_deg << "\t\t"
	 << gth.thetai[i] / rad_per_deg << "\t\t"
	 << gth.thetainc[i] / rad_per_deg << endl;
  }
}

// given vector of gantry positions/angles to scan over
// determine print for each PMT position the incidence angles scanned
void print_inc_angles( const vector< GantryTheta > & vgt ){
  map< int, vector<double> > IncAngles;

  for ( int igp=0; igp < vgt.size(); ++igp ){ // igp gantry position counter
    for ( int iga=0; iga < vgt[igp].thetap.size(); ++iga ) { // iga is angle counter
      int curpos = round( vgt[igp].thetap[iga]/rad_per_deg ); 
      vector<double> & curangles = IncAngles[ curpos ];
      curangles.push_back( vgt[igp].thetainc[iga]/rad_per_deg );
    }
  }

  for ( pair< const int, vector<double> >& pos : IncAngles ){
    cout<<"===================================="<<endl;
    cout<<" PMT position : "<<pos.first<<" degrees"<<endl;
    cout<<" Incidence-angles (deg)"<<endl;
    sort( pos.second.begin(), pos.second.end() );
    for ( double ang : pos.second ){
      cout<<ang<<endl;
    }
  }

}


void anglescan(){
  print_scan_params();
  
  vector<double> thetag; // gantry position angles (radians)
  vector<double> thetap; // point on pmt angles to try to scan (radians)

  // build list of gantry position angles
  for ( int i=0; i<4*nscanpoints; ++i ){
    double theta = -90*rad_per_deg+i*180*rad_per_deg/nscanpoints/4;
    thetag.push_back( theta );
  }
  // build list of PMT position angles  
  for ( int i=0; i<nscanpoints; ++i ){
    double theta = -80*rad_per_deg+i*160*rad_per_deg/nscanpoints; 
    thetap.push_back( theta );
  }

  vector< GantryTheta > vgt; // gantry pointing info for given gantry position 
  for ( unsigned i=0; i<thetag.size(); ++i ){
    // scan over gantry positions
    double thg = thetag[i];
       TVector3 rgi( (Rpmt+d) * sin( thg ), 0, (Rpmt+d) * cos( thg ) );
    vgt.push_back( GantryTheta( rgi ) );
    GantryTheta& gath = vgt[ vgt.size()-1 ];
    
    for ( unsigned j=0; j<nscanpoints; ++j ){
      // scan over positions on PMT
      double thp = thetap[j];
      // position on PMT
      TVector3 rp( Rpmt * sin( thp ), 0., Rpmt * cos( thp ) );
      // vector from gantry position to position on PMT
      TVector3 ri = rp - rgi;
      double thig = atan2( ri[0], ri[2] ) + pi;
      // pointing angle relative to position angle of gantry:
      double thi = thig-thp;
      
      // Angle to check ... only keep if gt than 90 deg:
      double dirtopos = rp.Angle( ri );

      if (dirtopos > pi/2 ){
	gath.thetap.push_back( thp );
	gath.thetaig.push_back( thig );
	gath.thetai.push_back( thi );
	gath.ri.push_back( ri );
	gath.rp.push_back( rp );
	double dirtopos2 = rp.Angle(-ri);
	if ( thp > thg ) dirtopos2 *= -1.0;
	gath.thetainc.push_back( dirtopos2 );
      }
    }
  }

  for ( int iscan=0 ; iscan < vgt.size(); ++iscan ){
    draw_scan( vgt[iscan] );
    print_scan( vgt[iscan] );
  }

  gSystem->Exec("gifsicle --delay=1 --loop=5 draw_scan*.gif > drawscan.gif");
  gSystem->Exec("rm -f draw_scan*.gif");
  

  
  print_inc_angles( vgt );
  
  

}
