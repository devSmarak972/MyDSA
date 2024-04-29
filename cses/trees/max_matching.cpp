#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> AL;
vector<int> paired;
bool dfs(int u) {
    if (visited[u]) return false;
    visited[u] = true;

    for (int v : AL[u]) {
        if (paired[v] == -1 || dfs(paired[v])) {
            paired[u] = v;
            paired[v] = u;
            return true;
        }
    }

    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> EL;
    vector<pair<int,int>> edges;
    AL.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        EL.push_back({a,b});


    }  
    paired.assign(n+1,-1);
    for(auto e: EL)
    {
        if(paired[e.first]==-1 && paired[e.second]==-1)
        {
            paired[e.first]=e.second;
            paired[e.second]=e.first;
            edges.push_back(e);
        }
    }

    // Build graph
    for (const auto& edge : EL) {
        AL[edge.first].push_back(edge.second);
        AL[edge.second].push_back(edge.first);
    }

    // Find augmenting paths and update matching
    bool foundAugmentingPath = true;
    while (foundAugmentingPath) {
        foundAugmentingPath = false;
        visited.assign(n+1,false);
        for (int i = 0; i < n; ++i) {
            if (paired[i] == -1 && dfs(i)) {
                foundAugmentingPath = true;
            }
        }
    }

    // Construct the maximal matching
    vector<pair<int, int>> matching;
    for (int i = 0; i < n; ++i) {
        if (paired[i] != -1 && paired[i] > i) { // Avoid duplicates
            matching.push_back({i, paired[i]});
        }
    }

    cout<<matching.size()<<endl; 
}