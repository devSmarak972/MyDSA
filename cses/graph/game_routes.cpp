#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> AL;
stack<int> toposort;
vector<int> visited;
int n,m;
ll cont;
const ll MOD=1e9+7;
void dfs(int u)
{
    visited[u]=1;
    for(auto v:AL[u])
    {
        // if(visited[v]==0)
        // {
        dfs(v);
        // }
        if(v==n)
        {
            cont=(cont+1)%MOD;
        }

        
    }
    // toposort.push(u);
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
    cont=0;
    // for(int i=1;i<=n;i++)
    // {
    //     if(!visited[i])
    //     dfs(i);
    // }
    dfs(1);
    cout<<cont<<endl;
    // reverse(toposort.begin(),toposort.end());
    return 0;

}