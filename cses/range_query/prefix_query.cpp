#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> ftree;
vector<ll> x;
vector<ll> segt;
int n;
vector<ll> lazy;
vector<ll> pre;
void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        segt[v] = pre[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        segt[v] = max(segt[v*2], segt[v*2 + 1]);
    }
}

void push(ll v) {
    segt[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    segt[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        segt[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        segt[v] = max(segt[v*2], segt[v*2+1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return -LLONG_MAX;
    if (l == tl && tr == r)
        return segt[v];
    push(v);
    ll tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void buildsegtree(int node,int l,int r)
{
    if(l==r)
    {
        segt[node]=pre[l];
    }
    else{
        ll mid=(l+r)/2;
        buildsegtree(node*2,l,mid);
        buildsegtree(node*2+1,mid+1,r);
        segt[node]=max(segt[node*2],segt[node*2+1]);
    }
}
ll querysegtree(int node,int l,int r,int ql,int qr)
{
    if(l>r || l>qr || r<ql )
    {
        return -LLONG_MAX;
    }
    else if(l>=ql && r<=qr)
    {
        return segt[node];

    }
    else{
        push(node);

        ll mid=(l+r)/2;
        return max(querysegtree(node*2,l,mid,ql,qr),querysegtree(node*2+1,mid+1,r,ql,qr));
    }

}
void updatetree(ll node,ll l,ll r,ll ql,ll qr,ll addend)
{

    if (l > r) 
        return;
    if(ql>r || l>qr)
    {
        return ;
    }
    if(r<=qr && l>=ql) 
    {
        // cout<<"here:"<<l<<" "<<r<<endl;
        segt[node]+=addend;
        if(r!=l)
        lazy[node] += addend;
    }
     else {
        push(node);
        ll mid = (l + r) / 2;
        updatetree(node*2, l, mid, ql, qr, addend);
        updatetree(node*2+1, mid+1, r, ql, qr, addend);
        segt[node] = max(segt[node*2], segt[node*2+1]);
    }
}
int main()
{
    int q;
    cin>>n>>q;
    x.assign(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        
    }
    pre.assign(n+1,0);
    pre[1]=x[1];
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1]+x[i];
    }
    // for(int i=1;i<=n;i++)cout<<pre[i]<<" ";
    // cout<<endl;
    // ftree.assign(n+1,0);
    segt.assign(4*n+1,0);
    lazy.assign(4*n+1,0);
    build(1,1,n);
    // for(int i=1;i<=n;i++)cout<<query(1,1,n,i,i)<<" ";
    // cout<<endl;
    for(int j=0;j<q;j++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            // cout<<"update quwery : "<<b<<" "<<c<<endl;
            update(1,1,n,b,n,c-x[b]);
            // cout<<"update\/n";
        }
        else{
        // cout<<"query :"<<b<<" "<<c<<endl;
            cout<<query(1,1,n,b-1,c)-query(1,1,n,b-1,b-1)<<endl;
        }
    }
}