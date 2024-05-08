#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<ll> x(n,-1);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(m+2,0));

// Iterate over all indices from 0 to n - 1
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // If we are at the first index and the value is
            // unknown
            if (x[i] == 0) {
                // There is only one way to put any value at
                // the first index
                for (int val = 1; val <= m; val++)
                    dp[i][val] = 1;
            }
            else {
                // If we are at the first index and the
                // value is fixed, there is only one way to
                // put the value x[0] at 0th index
                dp[i][x[i]] = 1;
            }
        }
        else {
            // If we are not at the first index and the
            // value is unknown, then for each val from 1 to
            // m, the number of ways to put val are equal to
            // the number of ways we can put val-1, val,
            // val+1 at the previous index
            if (x[i] == 0) {
                for (int val = 1; val <= m; val++) {
                    dp[i][val] = (dp[i - 1][val - 1]
                                + dp[i - 1][val]
                                + dp[i - 1][val + 1])
                                % MOD;
                }
            }
            // If we are not at the first index and the
            // value is known, then the number of ways to
            // put x[i] are equal to the number of ways we
            // can put x[i]-1, x[i], x[i]+1 at the
            // previous index
            else {
                dp[i][x[i]] = (dp[i - 1][x[i] - 1]
                                + dp[i - 1][x[i]]
                                + dp[i - 1][x[i] + 1]) % MOD;
            }
        }
        for(int j=1;j<=m;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    // Variable to store the final answer
    ll ans = 0;

    // Sum the number of ways of putting any value in the
    // last index to get the final answer
    for (int val = 1; val <= m; val++) {
        ans = (ans + dp[n - 1][val]) % MOD;
    }
    cout<<ans<<endl;
    return 0;
    }