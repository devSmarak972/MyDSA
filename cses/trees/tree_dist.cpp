#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> AL;
int n;
vector<int> dist1;
vector<int> dist2;
pair<int,int> maxdist={1,0};

pair<int,int> dfs(int u,int p,int currdist)
{
    for(int v:AL[u])
    {
        if(v==p)continue;
        dfs(v,u,currdist+1);
        if(currdist+1>maxdist.second)
        {
            maxdist.second=currdist+1;
            maxdist.first=v;
        }
    }
    return maxdist;
}
int findDistanceTo(int u,int p,int dest,int dist)
{
    for(int v:AL[u])
    {
        if(v==p)continue;
        if(v==dest)
        return dist+1;
        else
        {  
        int dis=findDistanceTo(v,u,dest,dist+1);
        if(dis>0)return dis;
        }
    }
    return 0;
}
int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    AL.assign(n+1,vector<int>());
    dist1.assign(n+1,0);
    dist2.assign(n+1,0);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    maxdist={1,0};
    pair<int,int> res1=dfs(1,-1,0);
    // cout<<res1.first<<" "<<res1.second<<endl;
    maxdist={res1.first,0};
    pair<int,int> res2=dfs(res1.first,-1,0);
    // cout<<res2.first<<" "<<res2.second<<endl;
    
    for(int i=1;i<=n;i++)
    {
        int d=findDistanceTo(i,-1,res1.first,0);
        int d1=findDistanceTo(i,-1,res2.first,0);
        cout<<max(d,d1)<<" ";
    }
    return 0;
}
