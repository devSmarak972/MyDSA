#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> w;
int main()
{
    ll n,x;
    cin>>n>>x;
    w.assign(n+1,0);
    for(int i=0;i<n;i++)
    cin>>w[i];
    ll s=1<<n;
    vector<pair<ll,ll>> dp(s+1,{0,0});
    dp[0]={1,0};
    for(int s=1;s<(1<<n);s++)// going through all possible subsets of n people
    {
        dp[s]={n+1,0};// initial value of the subset is that n+1 rides are needed for the given number of people.this is the more than the maximum possible
        for(int p=0;p<n;p++)
        {
            if(s&(1<<p))// if the pth bit is set
            {
                auto option=dp[s^(1<<p)];// the case without the pth man
                if(option.second+w[p]<=x)//total cost of adding the pth person to the set is less than x
                {
                    //add p to the ride
                    option.second+=w[p];

                }
                else{
                    option.first++;//get a new ride for p. inc number of rides
                    option.second=w[p];
                }
                dp[s]=min(dp[s],option);//min number of rides wins. keep the previus for state s subset of people or not
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
    return 0;
}