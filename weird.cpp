#include <bits/stdc++.h>
using namespace std;
int main(){

    long int n;
    cin>>n;
    while(n!=1)
    {
        cout<<n<<" ";
        n=n%2?(3*n+1):(n/2);
    }
    cout<<1<<endl;
}