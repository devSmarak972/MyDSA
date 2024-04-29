#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> AL;
vector<int> color;
vector<int> parent;
int n,m;
bool f=false;
int cycle_start=-1,cycle_end=-1;
int length=0;
bool findCycle(int v,int par)
{
    color[v]=1;

    for(int &u:AL[v])
    {
        if(u == par) continue; // skipping edge to parent vertex
        if(color[u]==0)
        {
        parent[u]=v;

        if(findCycle(u,v))
        {
           return true;
        }
        
        }
        else {
           
            cycle_end=v;
            cycle_start=u;
            return true;
        
        }

    }

    color[v]=2;
    return false;
}
int main()
{
    cin>>n>>m;
    AL.assign(n+1,vector<int>(0));
    color.assign(n+1,0);
    parent.assign(n+1,-1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    cycle_start=-1;
    for(int v=1;v<=n;v++)
    {

        if(color[v]==0 && findCycle(v,parent[v])) break;
    }
    if(cycle_start==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int>cycle;
        cycle.push_back(cycle_start);
        for(int v=cycle_end;v!=cycle_start;v=parent[v])
        cycle.push_back(v);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()+1<<endl;
        cout<<cycle[cycle.size()-1]<<" ";
        for(int i=0;i<cycle.size();i++)
        {
            cout<<cycle[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}