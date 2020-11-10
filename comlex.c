#include <complex>
#include <iostream>
using namespace std;
int main()
{
    complex<double> a = {1,2};
    complex<double> b(3,4);

    cout << a + b << "\n";
}
