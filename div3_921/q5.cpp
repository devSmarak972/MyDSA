#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,t,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<int>a(n+1,0);
        for( int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<n-k+1;i++)
        {
            cout<<i;
        }
        1 4 5 2 3 6 1 4 5
        1 2 3 4 3 4
        a[i+k]=a[i]+1, 
    }
   



    return 0;
}