#include <bits/stdc++.h>
#include <chrono>

typedef long long ll;
using namespace std;
vector<vector<int>> AL;
int m,n;
vector<int> parent;
int dijkstra(int src=1,int dest=n)
{
    vector<int> dist(n+1,-1);
    dist[src]=0;
    priority_queue<pair<int,int>>  pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        auto [d,u]=pq.top();
        // cout<<d<<endl;
        if (d != dist[u]) continue;

        pq.pop();
        for(auto v:AL[u])
        {
            if(dist[v]<(d+1))
            {
                dist[v]=d+1;
                parent[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
    return dist[n];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    AL.assign(n+1,vector<int>());
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
    }
    parent.assign(n+1,-1);
    auto start = std::chrono::high_resolution_clock::now();

    int dist=dijkstra(1,n);
     auto end = std::chrono::high_resolution_clock::now();

    // // Calculate duration
    std::chrono::duration<double> duration = end - start;

    // // Output the duration
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    if(dist==-1)
    cout<<"IMPOSSIBLE\n";
    else
    {
    cout<<dist+1<<endl;
    int v=n;
    vector<int> path;
    for(;v!=1;v=parent[v])
    {
        path.push_back(v);
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
    }

}