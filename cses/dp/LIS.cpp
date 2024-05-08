#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<ll> dp;
    // dp[1]=a[1];
    // ll lis=1;
    // for(int i=2;i<=n;i++)
    // {
    //     for(int j=1;j<i;j++)
    //     {
    //         if(a[i]>a[j])
    //         dp[i]=max(1+dp[j],dp[i]);

    //     }
    //     lis=max(lis,dp[i]);
    // }
    for(int i=1;i<=n;i++)
    {
        auto it=lower_bound(dp.begin(),dp.end(),a[i]);
        if(it==dp.end())
        {
            dp.push_back(a[i]);
        }
        else *it=a[i];

    }
    cout<<dp.size()<<endl;
}