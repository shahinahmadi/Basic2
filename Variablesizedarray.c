/*Variable sized array*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q, n;
    cin>>q>>n;
    vector <int> a[n];
    for (int i=0; i<n; i++){
    int k;
    cin>>k;
    int h;
for (int j=0;j<k;j++){
    cin>> h;
    a[i].push_back(h);
}
    }
    int x,y;
    for (int k=1; k<=q ; k++){
        cin>>x>>y;
        cout<<a[x][y]<<endl;
    }
    


    
    return 0;
}

