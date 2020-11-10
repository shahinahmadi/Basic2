/*minimax2*/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
int var,i;
long long int sum=0;

vector<int> array;

for(i=0; i<5; i++)
{
        cin>>var;
        sum+=var;
        //cout<<sum<<" ";
        array.push_back(var);
}
//cout<<endl;

        sort(array.begin(), array.end());   
        
/*for(i=0; i<5; i++)
{
 cout<<array[i]<<endl;
}*/
        cout<<sum-array[4]<<" "<<sum-array[0];  
        return 0;
}
