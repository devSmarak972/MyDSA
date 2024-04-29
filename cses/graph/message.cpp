#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> AL;
vector<bool> vis;
struct comp{
    constexpr bool operator()(const pair<int,int> &a,const pair<int,int> &b) const
    {
        return a.first>b.first;
    }
};
void dijkstra(int src,int dest)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    vector<int> distance(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    distance[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
// return 0;
        int dist=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        for(int i=0;i<AL[u].size();i++)
        {
            int v=AL[u][i];

            if((dist+1)<distance[v])
            {
                distance[v]=dist+1;
                parent[v]=u;
                pq.push({distance[v],v});
            }

        }

        vis[u]=true;

    }
    stack<int> path;
    int curr=dest;
    if(parent[dest]==-1)
    {
    cout<<"IMPOSSIBLE"<<endl;
    return;

    }
    while(curr!=src)
    {
        path.push(curr);
        curr=parent[curr];
    }
    path.push(src);
    cout<<path.size()<<endl;

    while(!path.empty())
    {
        cout<<path.top()<<" ";
        path.pop();
    }
    cout<<endl;
}
int main()
{
  int m;
  cin>>n>>m;
AL.assign(n+1,vector<int>(0));
vis.assign(n+1,false);
for(int i=0;i<m;i++)
{
    int a,b;
    cin>>a>>b;
    AL[a].push_back(b);
    AL[b].push_back(a);
}

dijkstra(1,n);
    return 0;
}