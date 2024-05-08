#include <bits/stdc++.h>
#include <chrono>
using namespace std;
typedef long long ll;
vector<vector<pair<ll,ll>>> AL;
stack<int> s;
vector<ll> dist;
ll n,m;
const ll MOD=1e9+7;
struct cmp{
    bool operator()(ll x, ll y)const{
        return dist[x]==dist[y] ? x<y :dist[x]<dist[y];
    }
};
set<ll, cmp> pq;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    AL.assign(n+1,vector<pair<ll,ll>>());
    vector<ll> in(n+1,0);
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        AL[a].push_back({b,c});
    }
        // auto start = std::chrono::high_resolution_clock::now();

    dist.assign(n+1,LLONG_MAX);
    vector<ll> ways(n+1,0);
    dist[1]=0;
    ways[1]=1;
    pq.insert(1);
    vector<ll> minR(n+1,0),maxR(n+1,0);
    while(!pq.empty())
    {
        ll u=*pq.begin();
        ll d=dist[u];
        // cout<<u<<" "<<d<<endl;
            // for(auto it: pq)
            // cout<<it<<" ";
            // cout<<endl;
        pq.erase(pq.begin());
        for(auto e:AL[u])
        {
            int v=e.first;
            ll w=e.second;
            if(w+d<=dist[v])
            {   
            if(dist[v]!=LLONG_MAX)pq.erase(v);// why do this? see later
            if(d+w == dist[v])
            {

                ways[v]=(ways[u]+ways[v])%MOD;
                minR[v]=min(minR[v],minR[u]+1);
                maxR[v]=max(maxR[v],maxR[u]+1);
            }
            
            if(d+w<dist[v])
            {
                dist[v]=d+w;
                ways[v]=ways[u];
                minR[v]=minR[u]+1;
                maxR[v]=maxR[u]+1;
            }
            pq.insert(v);// needs to be reinsereted afrter change of dist
            }

        }
    }
    //  auto end = std::chrono::high_resolution_clock::now();

    // // Calculate duration
    // std::chrono::duration<double> duration = end - start;

    // // Output the duration
    // std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    printf("%lld %lld %lld %lld",dist[n],ways[n],minR[n],maxR[n]);
    

    return 0;

}