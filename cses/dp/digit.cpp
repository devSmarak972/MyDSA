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
    int n;
    cin>>n;
    dp.assign(n+1,INT_MAX);
    // for(int i=0;i<=9;i++)
    // {
    //     dp[i]=1;
    // }
    dp[0]=0;
    set<int> digset;
    for(int i=1;i<=n;i++)
    {
        int d=i;

        while(d)
        {
            int dig=d%10;
            d=d/10;
            if(i>=dig)
                digset.insert(dig);
        }
        for(auto dig:digset)
        dp[i]=min(dp[i],1+dp[i-dig]);
        digset.clear();
    }
    cout<<dp[n]<<endl;
    return 0;

}