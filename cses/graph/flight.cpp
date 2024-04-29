#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=2e5+5;
vector<vector<pair<ll,ll>>> AL;
priority_queue<ll> bes[MX];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    AL.assign(n+1,vector<pair<ll,ll>>());
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        AL[a].push_back({b,c});
    }
    bes[1].push(0);//stores a periority queue of the min distnces to it
    pq.push({0,1});
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        if(a.first>bes[a.second].top()) continue;//if distance of a is greater than the biggest path already ppresetn
        for(auto &v:AL[a.second])
        {
            ll tmp=a.first+v.second;//updated distance
            if(bes[v.first].size()<k)// if already k slots not full 
            {
                bes[v.first].push(tmp);
                pq.push({tmp,v.first});
            }
            else if(tmp<bes[v.first].top())//if k slots full, replace the biggest one in max heap with current if current is smaller
            {
                bes[v.first].pop();
                bes[v.first].push(tmp);
                pq.push({tmp,v.first});
            }
        }
    }
    vector<ll> ans;
    while(!bes[n].empty())
    {
        ans.push_back(bes[n].top());
        bes[n].pop();
    }
    reverse(ans.begin(),ans.end());
    for(auto a:ans)cout<<a<<" ";

    return 0;
}