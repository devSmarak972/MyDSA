#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> a(n);
            vector<ll> prefixSum(n + 1, 0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
                    prefixSum[i] = prefixSum[i - 1] + a[i];

        }

         vector<pair<ll,ll>> dp(n + 1,make_pair(LLONG_MAX,LLONG_MAX));
        dp[0] = {0,0};
    
        for (int i = 1; i <= n; ++i) {

            ll maxSegmentSum = LLONG_MIN;

            for (int j = 0; j <i; ++j) {
                ll sum =dp[j].first+a[j];
                maxSegmentSum = max(maxSegmentSum, prefixSum[i] - prefixSum[j]);

                dp[i] = min(dp[i], dp[j] + a[j] + maxSegmentSum);
            }
        }

    cout << dp[n] << endl;

    }
    return 0;
}