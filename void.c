/*Void fonction*/
#include <iostream>
using namespace std;
void printGrade(double);
int main(){
  double score;
//Ask user for numerical Grade
cout<<"Enter a score: " ;
cin>>score;
cout<<" The Grade is  "<<endl;
printGrade(score);
return 0;
}
void printGrade(double score){
  if (score>=90)
    cout<<"A";
  else if (score>=80)
    cout<<"B";
  else if (score>=70)
    cout<<"C";
  else if (score>=60)
    cout<<"D";
  else
    cout<<"F";
}
