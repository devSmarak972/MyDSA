#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> AL;
stack<int> toposort;
vector<int> visited;
int n,m;
void dfs(int u)
{
    visited[u]=1;
    for(auto v:AL[u])
    {
        if(visited[v]==0)
        {
            dfs(v);
        }
        
    }
    toposort.push(u);
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
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        dfs(i);
    }
    // reverse(toposort.begin(),toposort.end());
    if(toposort.size()!=n)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<int> dist(n+1,-INT_MAX);
    dist[1]=0;
    vector<int> parent(n+1,-1);
    while(!toposort.empty())
    {
        int u=toposort.top();
        toposort.pop();
        for(auto v:AL[u])
        {
            if(dist[u]!=(-INT_MAX) && dist[v]<dist[u]+1)
            {
                dist[v]=dist[u]+1;
                parent[v]=u;
            }
        }

    }
    if(dist[n]==(-INT_MAX))
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;
    path.push_back(n);
    while(n!=1)
    {
        n=parent[n];
        path.push_back(n);
    }
    cout<<path.size()<<endl;
    for(int i=path.size()-1;i>=0;i--)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
    

    return 0;

}