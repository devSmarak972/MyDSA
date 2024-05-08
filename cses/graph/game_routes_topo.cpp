#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> AL;
stack<int> s;
vector<int> visited;
int n,m;
const ll MOD=1e9+7;

int main()
{
    cin>>n>>m;
    AL.assign(n+1,vector<int>());
    vector<ll> in(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        in[b]++;
    }
    visited.assign(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        s.push(i);
    }
    ll count=0;
    vector<ll> dp(n+1,0);// no. of path to any node from 1
    dp[1]=1;
    while(!s.empty())
    {
        int u=s.top();
        s.pop();
        for(auto v:AL[u])
        {
            dp[v]=(dp[v]+dp[u])%MOD;
            in[v]--;
            if(in[v]==0)
            s.push(v);
        }
    }

    cout<<dp[n]<<endl;
    

    return 0;

}