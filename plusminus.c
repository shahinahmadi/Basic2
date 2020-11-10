/*Plusminus1*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;
  int positive=0;
  int minus=0;
  int zero=0;
  int a[n];
  cin>>n;
  //vector<int>a();
  for(int i=0; i<n;i++){
    cin>>a[i];
    }
   for(int i=0; i<n;i++){ 
  if (a[i]>0){
    positive++;
    }
  else if (a[i]<0){
    minus++;
    }
  else if(a[i]==0){
    zero++;
    }
  cout<<positive/n<<" "<<minus/n<<" "<<zero/n;
  }
  return 0;
  }
