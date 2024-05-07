#include <bits/stdc++.h>
// #include <limits.h>
using namespace std;
typedef long long ll;
// #define INT_MAX 1e9
const ll MOD= 1e9+7;
vector<ll> dp;
int m;
vector<ll> coins;
ll dpf(int n)
{
    if(n==0)return 1;
    if(dp[n]!=0)return dp[n];
    for(int i=0;i<m;i++)
    {
        if(n-coins[i]<0)
        continue;
        if(n==coins[i])
        {
            dp[n]=(dp[n]+1)%MOD;
            continue;
        }
        if(dp[n-coins[i]]==0)
        dp[n-coins[i]]=dpf(n-coins[i]);

        if(dp[n-coins[i]]==-1)continue;

        dp[n]=(dp[n]+dp[n-coins[i]])%MOD;
    
    }
    if(dp[n]==0)dp[n]=-1;
     return dp[n];

}
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        int a;
    cin>>a;
    coins.push_back(a);
    }
    dp.assign(n+1,0);
    dp[0]=0;
    ll out=dpf(n);
    cout<<((out==-1)?0:out)<<endl;


    return 0;
}