#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> AL;
vector<vector<int>> up;
vector<int> depth;
int n;
void dfs(int v,int p,int dep)
{
    up[v][0]=p;
    depth[v]=dep;
    for(auto u:AL[v])
    {
        if(u!=p)
        {
            dfs(u,v,dep+1);
        }
    }
}
void precompute()
{
    dfs(1,-1,0);

    
    for(int i=1;i<ceil(log2(n));i++)
    {
    for(int j=1;j<=n;j++)
    {
        if(up[j][i-1]!=-1)
        up[j][i]=up[up[j][i-1]][i-1];
    }
    }
}
int lca(int a,int b)
{
    if(depth[a]<depth[b])
    {
        swap(a,b);
    }
    int diff=depth[a]-depth[b];
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
int main()
{
    int q;
    cin>>n>>q;
    AL.assign(n+1,vector<int>());
    up.assign(n+1,vector<int>(ceil(log2(n)),-1));
    depth.assign(n+1,-1);
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        AL[a].push_back(i);
    }
    precompute();
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}