#include <bits/stdc++.h>
// #include <limits.h>
using namespace std;
typedef long long ll;
// #define INT_MAX 1e9
const ll MOD= 1e9+7;
vector<ll> dp;
int m;
vector<ll> coins;

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
    sort(coins.begin(),coins.end());
    dp.assign(n+1,0);
    dp[0]=1;

for(int k=0;k<m;k++)
{
    for(int i=1;i<=n;i++)
    {
        if(coins[k]<=i)
        dp[i]=(dp[i]+dp[i-coins[k]])%MOD;
    }
}
        
    
  
    cout<<dp[n]<<endl;


    return 0;
}