/*conditional operator*/
#include <iostream>
using namespace std;
#define NEWLINE '\n'
  int main()
{
  int a, b, c;//Declaring the variables
  a=2;// initializing
  b=7;// initializing
  c=(a>b) ? a:b;//condition on variables
  cout << c;
  cout<<NEWLINE;
  return 0;
}
