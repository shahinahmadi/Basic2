#include <iostream>

using namespace std;

bool isEven(int n) //This checks whether a given number is even or not
{
    if(n%2 == 0)
        return true; //By true we mean its even
    else
        return false; //By false we mean its odd
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(isEven(num)) //If true
        cout << "Number is even." << endl;
    else //If false
        cout << "Number is odd." << endl;

    return 0;
}

	
