#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> A(n, 0);
        for (int i = 0; i < n; i++)
            cin >> A[i];

        vector<pair<ll, pair<ll, ll>>> dp(n + 1);
        dp[n] = {0, {0, 0}};
        ll curr_seg=0;
        for (int i = n - 1; i >= 0; i--)
        {
            ll curr_blocked = dp[i + 1].second.second;
            ll maxi = dp[i + 1].first;
            ll segment_sum = dp[i + 1].second.first;
            ll curr_max = max(maxi, A[i] + curr_blocked);
            ll new_segment_sum = max(segment_sum, curr_seg+ A[i]);

            pair<ll, pair<ll, ll>> take = {(ll)max(A[i] + curr_blocked, new_segment_sum), {new_segment_sum, A[i] + curr_blocked}};
            pair<ll, pair<ll, ll>> not_take = {(ll)max(maxi,new_segment_sum), {new_segment_sum , curr_blocked}};
            if(take<not_take)
            {
                            curr_seg=0;
            }
            else curr_seg+=A[i];
            dp[i]=min(take,not_take);
        }
        cout << dp[0].first << endl;
    }
    return 0;
}