#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> rank_;
vector<int> path;
vector<vector<int>> AL;
vector<pair<int,int>> edges;
int n,m;
int find(int i)
{
    if(parent[i]==i)
    return i;
    else 
    {
        int result=find(parent[i]);
        parent[i] = result;//path compression
        return result;

    }
}
void Union(int i,int j){
    int irep=find(i),jrep=find(j);
    parent[irep]=jrep;
}
void UnionByRank(int i , int j)
{
    int irep=find(i);
    int jrep=find(j);
    if(irep==jrep)
    return;
    int irank=rank_[irep];
    int jrank=rank_[jrep];
    if(irank<jrank) parent[irep]=jrep;
    else if(jrank<irank) parent[jrep]=irep;
    else{
        parent[irep]=jrep;
        rank_[jrep]++;
    }
}
bool hasCycle()
{
    for(auto& edge:edges)
    {
        int u=edge.first;
        int v=edge.second;

        int setU=find(u);
        int setV=find(v);
        if(setU==setV)
        {
            // path.push_back(u);
            // int curr=v;
            // cout<<"hello : "<<u<<" "<<v<<endl;
            // while(curr!=u)
            // {
            //     // cout<<"loop\n";

            //     path.push_back(curr);
            //     curr=find(curr);
            // }
            return true;
        }
        Union(setU,setV);
    }
    return false;
}
int main()
{

    cin>>n>>m;
    parent.assign(n+1,-1);
    rank_.assign(n+1,0);
    AL.assign(n+1,vector<int>(0));
    for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
        edges.push_back({a,b});
    }
    if(hasCycle())
    {
        cout<<path.size()<<endl;
        for(int i=path.size()-1;i>=0;i--)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}