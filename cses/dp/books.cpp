#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> price(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }
    vector<ll> dp(x+1,0);
    for(int j=0;j<n;j++)
    {
        
        for(int i=x;i>=0;i--)
        {
            if(price[j]<=i)
            dp[i]=max(pages[j]+dp[i-price[j]],dp[i]);
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}