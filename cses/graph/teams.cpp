#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> vis;
vector<int> color;
vector<vector<int>> AL;

bool isBipartite()
{
queue<int> q;
for(int i=0;i<n;i++)
{
    if(color[i]==-1)
    {
        q.push(i);
        color[i]=0;
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(int u: AL[v])
            {
                if(color[u]==-1)
                {
                    color[u]=1-color[v];
                    q.push(u);
                }
                else if(color[u]==color[v])
                return false;
            }
        }
    }
}
return true;
}
int main()
{
    int m;
    cin>>n>>m;
    AL.assign(n+1,vector<int>(0));
    vis.assign(n+1,false);
    color.assign(n+1,-1);
    vector<int> city;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    if(isBipartite())
    {
        for(int i=1;i<=n;i++)
        cout<<color[i]+1<<" ";
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }

}