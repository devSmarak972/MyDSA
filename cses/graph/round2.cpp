#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> AL;
vector<int> cycle;
vector<int> color;
vector<int> parent;
int cycle_end,cycle_start;
int n,m;
void findCycle(int u,int p)
{
    color[u]=1;
    // cout<<"dfs of :"<<u<<" "<<p<<endl;
    for(int v:AL[u])
    {                                                                              
        // if(v==p)continue;
        // cout<<"node : "<<v<<endl;
        if(color[v]==0 )
        {
            // cout<<"node uncolored\n";
            parent[v]=u;
            // parent[v]=u;
            findCycle(v,u);
            if(cycle_start!=-1)
            {
                return;
            }
        }
        else if(color[v]==1){
            // cout<<"found cycle: "<<u<< " "<<v<<endl;
            cycle_end=u;
            cycle_start=v;
            return;
        }
    }
    color[u]=2;
    return;
}
int main()
{
    cin>>n>>m;
    AL.assign(n+1,vector<int>());
    parent.assign(n+1,-1);
    color.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        // cout<<a<<" "<<b<<endl;
    }
    // cout<<"here\n";
    cycle_end=-1;
    cycle_start=-1;
    for(int i=1;i<=n && cycle_start==-1;i++)
    {
        if(color[i]==0)
        findCycle(i,parent[i]);

    }
    if(cycle_start==-1)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else{
        // cout<<cycle_end<< " "<<cycle_start<<" "<<parent[cycle_end]<<" "<<parent[cycle_start]<<endl;
        int v=cycle_end;
        cycle.push_back(cycle_start);
        while(v!=cycle_start)
        {
            cycle.push_back(v);

            v=parent[v];
            // cout<<v<<endl;
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<endl;
        for(int i=0;i<cycle.size();i++)
        cout<<cycle[i]<<" ";
    }
}