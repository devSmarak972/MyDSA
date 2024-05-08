#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> AL;
int n,m;
vector<int> toposort;
vector<int> visited;
//toposorting
int cycle;
void dfs(int u,int p)
{
    // if(visited[u])return;
    // cout<<"searching node "<<u<<" "<<p<<endl;
    visited[u]=1;
    for(auto v:AL[u])
    {
    
            if(visited[v]==0)
            {
            dfs(v,u);
            if(cycle)
            return;
            }
            else if(visited[v]==1)
            {
                // cout<<"cycle found\n";
                cycle=1;
                return;
            }


        
    }
    visited[u]=2;
    toposort.push_back(u);
}
int main()
{
    cin>>n>>m;
    AL.assign(n+1,vector<int>());
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
    }
    visited.assign(n+1,0);
    cycle=0;
    for(int i=1;i<=n && !cycle;i++)
    {
        if(visited[i]==0)
        dfs(i,-1);
    }
    reverse(toposort.begin(),toposort.end());
    if(cycle)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
    for(int i=0;i<n;i++)
    {
        cout<<toposort[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}