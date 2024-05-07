#include <bits/stdc++.h>
// #include <limits.h>
using namespace std;
typedef long long ll;
// #define INT_MAX 1e9
const ll MOD= 1e9+7;
vector<vector<ll>> dp;
int m;
vector<ll> coins;
ll dpf(int n,int k)
{
    // cout<<"jh "<<n<<" "<<k<< " "<<dp[n][k]<<"\n";
    if(n==0)return 1;
    if(dp[n][k]!=0)return dp[n][k];
    // cout<<"m: "<<m<<endl;
    for(int i=k;i<m;i++)
    {
        cout<<"in "<<n<<" "<<coins[i]<<"\n";
        if(n-coins[i]<0)
        continue;
        if(n==coins[i])
        {
            dp[n][k]=(dp[n][k]+1)%MOD;
            continue;
        }
        cout<<"was here "<<n<<" "<<i<<endl;
        if(dp[n-coins[i]][i]==0)
        dp[n-coins[i]][i]=dpf(n-coins[i],i);
        cout<<"here: "<<n<<endl;
        if(dp[n-coins[i]][i]==-1)continue;

        dp[n][k]=(dp[n][k]+dp[n-coins[i]][i])%MOD;
    
    }
    if(dp[n][k]==0)dp[n][k]=-1;
        cout<<"here dp: "<<n<<" "<< k<<" "<<dp[n][k]<<"\n";

     return dp[n][k];

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
    sort(coins.begin(),coins.end());
    dp.assign(n+1,vector<ll>(m,0));
    // dp[0]=0;
    ll out=dpf(n,0);
    cout<<((out==-1)?0:out)<<endl;


    return 0;
}