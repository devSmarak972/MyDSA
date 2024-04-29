#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> vis;
vector<vector<int>> AL;
void dfs(int u)
{
    vis[u]=true;
    for(int &v:AL[u])
    {
    if(!vis[v])
    {
        dfs(v);
    }

    }
}
int main()
{
    int m;
    cin>>n>>m;
    AL.assign(n+1,vector<int>(0));
    vis.assign(n+1,false);
    vector<int> city;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {

        if(!vis[i])
        {
            city.push_back(i);
            dfs(i);
        }
    }
    cout<<city.size()-1<<endl;
    for(int i=0;i<city.size()-1;i++)
    {
        cout<<city[i]<<" "<<city[i+1]<<endl;
    }

    
}