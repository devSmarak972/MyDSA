#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct {
    ll from;
    ll to;
    ll wt;
} edge;
vector<edge> EL;
vector<ll> cycle;
int n,m;
bool bellmanFord()
{
    vector<ll> distance(n+1,LLONG_MAX);
    vector<ll> parent(n+1,-1);

    distance[1]=0;
    for(int i=1;i<n-1;i++)
    {
        for(auto &item:EL)
        {
            ll from=item.from;
            ll to=item.to;
            ll wt=item.wt;
            if(distance[from]==LLONG_MAX)continue;
            
            if(distance[to]>distance[from]+wt)
            {
                distance[to]=distance[from]+wt;
                parent[to]=from;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(auto &item:EL)
        {
            ll from=item.from;
            ll to=item.to;
            ll wt=item.wt;
            if(distance[from]==LLONG_MAX)continue;

            if(distance[to]>distance[from]+wt)
            {

                ll v_cycle=to;
                 do {
                cycle.push_back(v_cycle);
                v_cycle = parent[v_cycle];
            } while (v_cycle != -1 && v_cycle != cycle.front());
            cycle.push_back(v_cycle);
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        EL.push_back({a,b,c});
    }
    if(bellmanFord())
    {
        cout<<"YES\n";
        for(int i=0;i<cycle.size();i++)
        cout<<cycle[i]<<" ";
    }
    else cout<<"NO"<<endl;

}