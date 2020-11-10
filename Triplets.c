/*Triplets*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  vector<int>a(3);
  vector<int>b(3);
  int sum1=0;
  int sum2=0;
  for (int i=0;i<3;i++)
    cin>>a[i];
  for (int j=0;j<3;j++)
    cin>>b[j];
  if(a[0]>b[0])
    sum1=sum1+1;
  else if (b[0]>a[0])
    sum2=sum2+1;
  if(a[1]>b[1])
    sum1=sum1+1;
  else if (b[1]>a[1])
    sum2=sum2+1;
  if(a[2]>b[2])
    sum1=sum1+1;
  else if (b[2]>a[2])
  sum2=sum2+1;
  cout<<sum1<<" "<<sum2;
  return 0;
}
  
