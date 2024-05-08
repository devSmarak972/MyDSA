#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main()
{
   int n;
   cin>>n; 
   ll sum=n*(n+1)/2;
       if (sum%2!=0) {
        cout<<0<<endl;
       return 0;
       }
    sum/=2;
   vector<ll> dp(sum+1,0);
    dp[0]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=sum;j>=i;j--)
        {
            if(j-i>=0)
            dp[j]=(dp[j]+dp[j-i])%MOD;
        }
    }
     
    cout<<dp[sum]<<endl;
    return 0;
}