/*Stringstream*/
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
vector<int> parseInts(string str) {
    stringstream s(str);
    vector<int> vect;
    char ch;
    int integer;

    while (s>> integer) {
        vect.push_back(integer);
        s>>ch;
    }

return vect;

   
}

    


int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

