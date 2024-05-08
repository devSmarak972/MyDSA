#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> x(n,-1);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(m+2,0));
    for(ll i=1;i<=m;i++)
    {
        if(x[0]==0)
        dp[0][i]=1;
        else
        {
        dp[0][x[0]]=1;
        break;
        }

    }
    // for(int j=1;j<=m;j++)
    // cout<<dp[0][j]<<" ";
    // cout<<endl;

    for(ll i=1;i<n;i++)
    {
        if(x[i]!=0)
        dp[i][x[i]]=(dp[i-1][x[i]-1]+dp[i-1][x[i]+1]+dp[i-1][x[i]])%MOD;
        else
        {


        for(ll j=1;j<=m;j++)
        {
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
        }
        }
        // for(int j=1;j<=m;j++)
        // cout<<dp[i][j]<<" ";
        // cout<<endl;
    }
    ll sum=0;
    for(ll j=1;j<=m;j++)
    {
        sum= (sum+dp[n-1][j])%MOD;
    }
    cout<<sum<<endl;
    return 0;
}