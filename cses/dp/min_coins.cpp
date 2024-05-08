#include <bits/stdc++.h>
// #include <limits.h>
using namespace std;
typedef long long ll;
// #define INT_MAX 1e9
const ll MOD= 1e9+7;
vector<ll> dp;
vector<ll> best;
vector<ll> coins;
ll dpf(int n)
{
    if(n==0)return 0;
    if(n<0)return -1;

    if(dp[n]!=INT_MAX)return dp[n];
    for(int i=0;i<coins.size();i++)
    {
        if(n-coins[i]<0)continue;
        if(dp[n-coins[i]]==INT_MAX)
        dp[n-coins[i]]=dpf(n-coins[i]);

        if(dp[n-coins[i]]==-1)continue;

        // cout<<n<<" n- coins "<<coins[i]<<" " <<dp[n-coins[i]]<<endl;
        dp[n]=min(1+dp[n-coins[i]],dp[n]);
    
    }
    if(dp[n]==INT_MAX)return -1;

    // cout<<"dp n: "<<n<<" "<<dp[n]<<endl;
    return dp[n];

}
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        int a;
    cin>>a;
    coins.push_back(a);
    }
    dp.assign(n+1,INT_MAX);
    dp[0]=0;
    cout<<dpf(n)<<endl;
    // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    return 0;
}