#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> AL;
int n;
pair<int,int> bfs(int node)
{
    visited.assign(n+1,false);
    stack<pair<int,int>>s;
    s.push({node,0});
    visited[node]=true;
    pair<int,int> farthest={node,0};
    while(!s.empty())
    {
        auto current=s.top();
        s.pop();
        // cout<<current.first<<" "<<current.second<<endl;
        if(current.second>farthest.second)
        {
            farthest=current;
        }
        for( int v:AL[current.first])
        {
            if(!visited[v])
            {
                visited[v]=true;
                s.push({v,current.second+1});
            }
        }
    }
    return farthest;
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
    pair<int, int> farthestfirst = bfs(1);
    
    pair<int, int> farthest = bfs( farthestfirst.first);
    cout<<farthest.second<<endl;

    return 0;
}