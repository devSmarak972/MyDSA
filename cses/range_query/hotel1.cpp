#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> a;
vector<ll> segt;
void build(int l=1,int r=n,int node=1)
{
    if(l==r)segt[node]=a[l];
    else{
        int mid=(l+r)/2;
        build(l,mid,node*2);
        build(mid+1,r,node*2+1);
        segt[node]=max(segt[node*2],segt[node*2+1]);
    }
}
void update(int val,int l=1,int r=n,int node=1)
{
    if(l==r)
    {
        segt[node]-=val;
        cout<<l<<" ";
    }
    else{
        int mid=(l+r)/2;
        if(segt[node*2]>=val)update(val,l,mid,node*2);
        else update(val,mid+1,r,node*2+1);

        segt[node]=max(segt[node*2],segt[node*2+1]);
    }
}
void bin_search()
{
  
}
int main()
{
    iostream::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n >> q;
    ll x = (int)(ceil(log2(n)));
    ll max_size=2*(int)pow(2,x)-1;
    a.assign(n+1,-1);
    segt.assign(max_size+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build();
    while(q--)
    {
        ll v;
        cin>>v;
        if(segt[1]<v) cout<<"0 ";
        else update(v);
    }
    return 0;
}