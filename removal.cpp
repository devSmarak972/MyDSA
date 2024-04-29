#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll dp[n][n];

    for(int i=0;i<n;i++)
    {
        dp[i][i]=a[i];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
 
        }
    }
    ll score=0;
    for(int i=0;i<n;i++)
    {
        score+=a[i];
    }

    cout<<(score+dp[0][n-1])/2<<endl;

    return 0;
}