#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> AL;
vector<pair<ll,ll>> subsum;
vector<int> parent;
ll n;
void dfs(int u,int p,int depth)
{
    subsum[1].second+=depth;
    subsum[u].first=1;
    for(auto v:AL[u])
    {
        if(v==p)continue;
        dfs(v,u,depth+1);
        // subsum[u].first+=subsum[v].first;
        subsum[u].first+=subsum[v].first;
        // cout<<"node "<<u<<" exploring "<<v<<" "<<subsum[u].second<<endl;
        
    }
}
void upstream(int u,int p)
{
    for(auto v:AL[u])
    {
        if(v==p)continue;
        // subsum[u].first+=subsum[v].first;
        subsum[v].second+=subsum[u].second +n- 2*subsum[v].first;
        upstream(v,u);
        
    }
}
int main()
{
    cin>>n;
    AL.assign(n+1,vector<int>());
    subsum.assign(n+1,pair<int,int>(0,0));
    parent.assign(n+1,0);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);

        
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<AL[i].size()<<" ";
    // }
    // cout<<endl;
    dfs(1,0,0);
    upstream(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<subsum[i].second<<" ";
    }


    return 0;
}
