#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct{
    ll start;
    ll end;
    ll reward;
} project;
int main()
{
    ll n;
    cin>>n;
    vector<project> projects;
    map<ll,ll> compress;
    for(int i=0;i<n;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        projects.push_back({a,b+1,c});
        compress[a]=0;
        compress[b+1]=0;
    }

    ll d=0;
    for(auto &e:compress)
    {
        e.second=d;
        d++;
    }
    vector<vector<pair<int,int>>> p(d);
    for(int i=0;i<n;i++)
    {

        p[compress[projects[i].end]].emplace_back(compress[projects[i].start],projects[i].reward);
    }
    vector<ll> dp(d,0);
    for(int i=0;i<d;i++)
    {
        if(i>0)
        {
            dp[i]=dp[i-1];// not taking any project in ith time
        }
        for(auto it:p[i])
        {
            dp[i]=max(dp[i],dp[it.first]+it.second);// taking the last project that maximise prize at time i before i
        }
    }
    cout<<dp[d-1]<<endl;

    return 0;
}