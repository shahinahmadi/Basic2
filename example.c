#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
int main(){
  vector<int>desired;
  string str;
  int    numbers;
  char   ch;
  stringstream ss;
  
  cout<<"Enter the string"<<endl;
  cin>>str;
  ss<<str;
  while(ss>>numbers){
  desired.push_back(numbers);
  ss>>ch;}
  for(int i=0; i<desired.size(); i++){
  cout<<desired[i]<<endl;
  }
}
