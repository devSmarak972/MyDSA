#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> AL;
int n;
vector<int> distances;
void dijkstra(int src){
    distances.assign(n+1,-1);
    vector<int> visited(n+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<int>> pq;
    pq.push({0,src});
    distances[src]=0;
    visited[src]=true;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        for(auto v: AL[it.second])
        {
            if(distances[v]<distances[it.second]+1)
            {
                distances[v]=distances[it.second]+1;
                pq.push({distances[v],v});
            }
        }
        visited[it.second]=true;
    }
}
vector<int> firstMax;
vector<int> secondMax;
vector<int> c;
void dfs(int u,int p)
{
    for(auto v:AL[u])
    {
        if(v==p)continue;
        dfs(v,u);
        if(firstMax[v]+1>firstMax[u])
        {
            secondMax[u]=firstMax[u];
            firstMax[u]=firstMax[v]+1;
            c[u]=v;
        }
        else if(firstMax[v]+1>secondMax[u]){
            secondMax[u]=firstMax[v]+1;
        }

    }
}
void dfs2(int u,int p)
{
    for(auto v:AL[u])
    {
        if(v==p)continue;
        if(c[u]==v)
        {
        if(firstMax[v]<secondMax[u]+1)
        {
            secondMax[v]=firstMax[u];
            firstMax[v]=secondMax[v]+1;
            c[v]=u;
        }else {
				secondMax[v] = max(secondMax[v], secondMax[u] + 1);
			}

        }else {
			secondMax[v] = firstMax[v];
			firstMax[v] = firstMax[u] + 1;
			c[v] = u;
		}
		dfs2(v, u);
    }
}
int main()
{
    cin>>n;
    AL.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);

    }
    // dijkstra(1);
    firstMax.assign(n+1,0);
    secondMax.assign(n+1,0);
    c.assign(n+1,-1);
    return 0;

}