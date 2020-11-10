#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdio>
#include "TGraph.h"
#include "TAxis.h"
#include "TGraphErrors.h"
using namespace std;

//so that the function plot() gets renamed to something with declaration like:TGraph * get_graph( const string & infile = "/home/shahin/Desktop/NEW.CSV" );

TGraph* plot(string filename){

    vector<double> wavelengths;
    vector<double> transmissions;
//Change the line that opens the ifstream to use infile instead of the hard coded file name, and at the end of the function return gr (which is a TGraph *).
    ifstream myfile(filename); //file opening constructor

    //Operation to check if the file opened
    if ( myfile.is_open() ){
    
        double wavelength, transmission, stddev;
        char delimiter;
        
        // Reading the file
        myfile.ignore(1000, '\n');
        while(myfile >> wavelength >> delimiter >> transmission >> delimiter >> stddev){

            //putting data into the vector
            wavelengths.push_back(wavelength);
            transmissions.push_back(transmission);

        }
    }

    
    //   Writing a for loop which prints the data in the vectors to screen.
    for (int i; i < wavelengths.size(); ++i){
       // cout<< wavelengths.at(i)<<" "<<transmissions.at(i)<< endl; 
        }

    //   Writing for loop here to loop through wavelength and transmission vectors and store their information in an array
    int n=911;
    double x[n],y[n];
    for (int i=0; i<wavelengths.size();i++){
    x[i]=wavelengths.at(i);
    y[i]=transmissions.at(i);

    }
 //
    auto gr = new TGraph(n,x,y);
        gr->SetTitle("Transmittance measurement(Three repeated measurements are averaged);Light wavelength(nm);Transmittance(%)");
        gr->GetXaxis()->CenterTitle();
        gr->GetYaxis()->CenterTitle();
    return gr;
}
//Then you can modify the function I said you should make to take const std::vector< TGraph* > & as an argument, and return a TGraphErrors* that is the average and RMS for error bar of the vector of TGraph* you give it.

TGraphErrors* Errors(vector<TGraph*> GS){
	double wave[GS.at(0)->GetN()];
	double trans[GS.at(0)->GetN()];
	double waveE[GS.at(0)->GetN()];
	double transE[GS.at(0)->GetN()];

	for(int i = 0; i < GS.at(0)->GetN(); i++){
		wave[i]=0;
		trans[i]=0;
		waveE[i] = 0;
		transE[i] = 0;		
	}
	for(int i = 0; i < GS.at(0)->GetN(); i++){
		double mean = 0;
		double sigma = 0;
		for (int j=0;j<GS.size();j++){
			double x,y;
			GS.at(j)->GetPoint(i,x,y);
			mean += y;
			wave[i] = x;
		}
		mean /=GS.size();
		for (int j=0;j<GS.size();j++){
			double x,y;
			GS.at(j)->GetPoint(i,x,y);		
		
			sigma += (y-mean)*(y-mean);
		}
		sigma = sqrt(sigma/GS.size());
		trans[i] = mean;
		transE[i] = sigma;	

	}

	TGraphErrors* gr1=new TGraphErrors(GS.at(0)->GetN(),wave,trans);//,waveE,transE);
	gr1->SetTitle("Transmittance measurement(Three repeated measurements are averaged);Light wavelength(nm);Transmittance(%)");
        gr1->GetXaxis()->CenterTitle();
        gr1->GetYaxis()->CenterTitle();
	gr1->SetLineColor(kRed+1);
	return gr1;
}
///
/// void scale_fix( vector<TGraph* > SC, double scale=1.0,
///                 double xmin=599.9,   double xmax=600.1 )
/// Function to scale TGraphs pointed to in SC
/// Scaling set value to scale for
/// average from xmin to xmax
TGraph* scale(TGraph* SC, double scale=100,
	       double xmin=599.9,  double xmax=600.1 ){ /* note default parameters can be passed */

  /* there is no need for the following variables commenting them out
     double wavelength[SC.at(0)->GetN()];
     double transmittance[SC.at(0)->GetN()];
     double t;
     double scaling;
  */
  //for ( int i=0; i<SC->GetN(); ++i ) // loop over graphs
  int wavelength[SC->GetN()];
  double transmittance[SC->GetN()];
    //TGraph * curgraph = SC[i];//
    /* Again there is no need for the following variables. 
       Also note that the following variables have the same name
       as the onew in the outer scope!  This make code confusing.
       double wavelength[SC.at(0)->GetN()];
       double transmittance[SC.at(0)->GetN()];
    */
    // Loop to calculate value of scaling
    // Note change loop index to j (so it doesn't hide outer loop index i)
    double scaling = 0.0;
    int nbinscale = 0;
    for (int j=0; j < SC->GetN(); ++j ) {
      double x,y;
      SC->GetPoint(j, x, y);
      if ( x > xmin && x < xmax ){
	scaling += y;
	++nbinscale;
      }
    }
    
    // Loop a second time to do the scaling if we
    // found any bins in the requested range
    if (nbinscale>0){
      scaling /= nbinscale; // average over bins
      scaling = scale / scaling; // calculate scaling factor
      for ( int j=0; j < SC->GetN(); ++j ){
	double x,y;
	SC->GetPoint( j, x, y );
	wavelength[j]=x;
	transmittance[j]=y*scaling;
      }
    }	  	     

TGraph* g1 = new TGraph(SC->GetN(), wavelength, transmittance);
return g1; 
}
	      
    
    
	      	   

	      

//Then make a new plot() function that calls get_graph.  You can call it multiple times on different files to get multiple graphs.  Store the pointers to graphs that you read in and make in a std::vector:< TGraph* > graphs;

//Main function
void graphs1(){
	std::vector<TGraph*> graphs1;
	std::vector<TGraph*> graphs5;
	string filename [6]={"NEW1.CSV","NEW3.CSV","NEW4.CSV","NEW5.CSV","NEW6.CSV","NEW7.CSV"};
	int lineColors[6]={1,2,4,5,6,7};
	string plotOpt[6] = {"AL", "same", "same","same","same","same"};
	
	for(int i=0;i<3;i++){
		graphs1.push_back(plot(filename[i]));
		graphs1.at(i)->SetLineColor(lineColors[i]);
		//graphs1.at(i)->Draw(plotOpt[i].c_str());
	}
	for(int i=3;i<6;i++){
		graphs5.push_back(plot(filename[i]));
		graphs5.at(i-3)->SetLineColor(lineColors[i]);
		//graphs5.at(i)->Draw(plotOpt[i].c_str());
	}
	cerr << graphs5.size() <<endl;	
	//scale_fix(graphs1);//
	TGraphErrors* graphs2= Errors(graphs1);
	TGraphErrors* graphs6= Errors(graphs5);
	graphs2->SetMarkerStyle(22);
	graphs2->Draw("AL");
	graphs6->Draw("Lsame");
	TGraph*  graphs3=scale(graphs2);
	TGraph*  graphs7=scale(graphs6);
	graphs3->Draw("Lsame");
	graphs7->Draw("Lsame");
	
}



