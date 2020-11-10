/*For loop*/
#include <iostream>
#include <cstdio>
using namespace std;
// Complete the code.
using namespace std;
int main(){
int a, b;
cin>>a>>b;
for (int i=a; i<=b ; i++){
string b[11]={"one","two","three","four","five","six","seven","eight","nine", "odd","even"};

if ((i>=1)&&(i<=9))
cout<< b[i-1]<<endl;
else if ((i>9)&&(i%2==0))
cout<<b[10]<<endl;
else 
cout<<b[9]<<endl;
}

return 0;
}


