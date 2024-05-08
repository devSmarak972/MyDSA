#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    vector<vector<ll>> dp(1e6+1,vector<ll>(2,0));
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<1e6+1;i++)
    {
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=(4*dp[i-1][1]+dp[i-1][0])%MOD;
    }
    while(t--)
    {
    ll n;
    cin>>n;
    cout<<(dp[n-1][1]+dp[n-1][0])%MOD<<endl;
    }
    return 0;
}