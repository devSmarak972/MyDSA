#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
vector<vector<int>> AL;
vector<vector<int>> up;
vector<int> depth;
vector<int> prefix;
void dfs(int u,int p,int d)
{
    depth[u]=d;
    up[u][0]=p;
    for(auto v:AL[u])
    {
        if(v!=p)
        dfs(v,u,d+1);
    }
}
void precompute()
{
    dfs(1,0,0);
    for(int j=1;j<ceil(log2(n));j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(up[i][j-1]!=0)
            up[i][j]=up[up[i][j-1]][j-1];
        }

    }
}
ll dist_lca(int a ,int b)
{
    if(depth[a]<depth[b])
    {
        swap(a,b);
    }
    ll diff=depth[a]-depth[b];
    for(int i=0;i<ceil(log2(n));i++)
    {
         if(diff & (1<<i)){
            a=up[a][i];
         }
    }
    if(a==b)return b;//b is ancestor of a
    for(int i=ceil(log2(n))-1;i>=0;i--)
    {
        // lift both up till common ancestor is found

        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
        

        
    }
    return up[a][0];

}
void dfs_sum(int u,int p)
{
    for(auto v:AL[u])
    {
        if(v!=p)
        {
        dfs_sum(v,u);
        prefix[u]+=prefix[v];
        }
    }
}
int main()
{
    int q;
    cin>>n>>q;
    AL.resize(n+1);
    prefix.resize(n+1,0);
    depth.resize(n+1);
    up.assign(n+1,vector<int>(ceil(log2(n))+1));
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    precompute();
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        ll lca=dist_lca(a,b);
        prefix[a]++;
        prefix[b]++;
        prefix[lca]--;
        prefix[up[lca][0]]--;
    }
    dfs_sum(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<prefix[i]<<" ";
    }
    return 0;
}