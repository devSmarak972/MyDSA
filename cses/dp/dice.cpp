#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD= 1e9+7;
vector<ll> dp;
ll dpf(int n)
{
    if(n==0)return 1;

    if(dp[n]!=0)return dp[n];
    for(int i=1;i<=6 && i<=n;i++)
    {
        if(dp[n-i]==0)
        dp[n-i]=dpf(n-i);

        dp[n]=(dp[n]+dp[n-i])%MOD;
    }
    return dp[n];

}
int main()
{
    int n;
    cin>>n;
    dp.assign(n+1,0);
    dp[0]=1;
    cout<<dpf(n)<<endl;
    // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    return 0;
}