#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
int logN=20;
vector<ll> ds;
vector<vector<int>> par;
vector<vector<int>> AL;
vector<int> cycleSeeds;
vector<int> cyc,AL,d,comp;
vector<bool> vis;
int find(int u)
{
    if(ds[u]<0) return u;
    ds[u]=find(ds[u]);
    return ds[u];
}
bool merge(int u,int v)
{
    u=find(u);v=find(v);
    if(u==v)return false;//already merged
    if(ds[u]<ds[v])swap(u,v);// make u the bigger tree
    ds[v]+=ds[u];//why??
    ds[u]=v;
    return true;
}

int travel(int u, int k){
    int v = u;
    for(int i = logN-1; i >= 0; i--)
        if(k&(1<<i))
            v = par[i][v];
    return v;
}
void dfs(int u,int compID)
{
    vis[u]=true;
    comp[u]=compID;
    for(int v:AL[u])
    {
        if(!vis[u])
        {
            d[v]=d[u]+1;
            dfs(v,compID);//join connected components and record distance
        }
        else
        cyc[u]=d[u]+1;
        
        cyc[u]=max(cyc[u],cyc[v]);
    }
}
int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    ds.assign(n+1,-1);
    AL.assign(n+1,vector<int>());
   par.assign(n+1,vector<int>(logN,0));
   vis.assign(n+1,false);
   d.assign(n+1,0);
   cyc.assign(n+1,0);
   comp.assign(n+1,0);
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        AL[i].push_back(a);
        par[i][0]=a;// direct parent
        if(!merge(a,i))
        {
            cycleSeeds.push_back(a);// old component
        }
    }
    for(int i=1;i<logN;i++)
    {
        for(int j=1;j<=n;j++)
        {
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
    int compID=1;
    for(int seed:cycleSeeds)
    {
        dfs(seed,compID++);
    }
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        ll count=0;
        cout<<count<<endl;
    }

    // auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    // std::chrono::duration<double> duration = end - start;

    // Output the duration
    // std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
    
}