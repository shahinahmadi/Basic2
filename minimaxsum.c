/*Maximum sum1*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  vector<int>a(5);
 for(int i=0;i<5;i++){
   cin>>a[i];
   int maxi;
   int mini;
   int maxisum;
  int minisum;
  int sum=0;
   
  for(int i=0;i<5;i++){
 if( (a[0]>a[1])&&(a[0]>a[2])&&(a[0]>a[2])&&(a[0]>a[3])&&(a[0]>a[4]))
 maxi==a[0];
 else if ((a[1]>a[2])&&(a[1]>a[3])&&(a[1]>a[4]))
 maxi==a[1];
 else if((a[2]>a[3])&&(a[2]>a[4]))
 maxi==a[2];

 else if((a[3]>a[4]))
 maxi==a[3];
   else
   maxi==a[4];
  }
   for(int i=0;i<5;i++){
   cin>>a[i];
 if( (a[0]<a[1])&&(a[0]<a[2])&&(a[0]<a[2])&&(a[0]<a[3])&&(a[0]<a[4]))
 mini==a[0];
 else if ((a[1]<a[2])&&(a[1]<a[3])&&(a[1]<a[4]))
 mini==a[1];
else if((a[2]<a[3])&&(a[2]<a[4]))
mini==a[2];

 else if((a[3]<a[4]))
 mini==a[3];
   else
   mini==a[4];
   }
   for(int i=0;i<5;i++){
   sum+=a[i];
   maxisum=sum-mini;
   minisum=sum-maxi;
  }
   cout<<maxisum<<" "<<minisum;
   return 0;
   }
   }
   
   
    
