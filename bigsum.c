/*Big sum*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n;
int i;
long sum=0;
cin>>n;
  vector<int>arr(n);
  for (int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<n;i++){
   sum+=arr[i];
   }
   cout<<sum<<endl;
   return 0;
}
