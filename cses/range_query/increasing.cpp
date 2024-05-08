#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> x;
ll m,n;
typedef struct{
    ll val;
    ll max;
    ll min;
} inc;
vector<inc> segt;
void build(int v,int l, int r)
{
    if(l==r)
    {
        segt[v].val=x[l];
        segt[v].max=x[l];
        segt[v].min=x[l];

    }
    else{
        ll mid=(l+r)/2;
        build(v*2,l,mid);
        build(v*2+1,mid+1,r);
        segt[v].val=segt[v*2].val+segt[v*2+1].val;
        if(segt[v*2+1].min<segt[v*2].max)
        {
        segt[v].val+=(segt[v*2].max-segt[v*2].min)*(r-mid);
        segt[v].max=segt[v*2+1].max+(segt[v*2].max-segt[v*2].min);
        }
        else
        segt[v].max=segt[v*2+1].max;

        segt[v].min=segt[v*2].min;
        
    }
}
inc query(int v,int l,int r,int ql,int qr)
{
    if(l>r || l>qr || r<ql)
    return {0,0,0};
    if(l>=ql && r<=qr)
    return segt[v];
    
    ll mid=(l+r)/2;
    inc left=query(v*2,l,mid,ql,qr);
    inc right=query(v*2,mid+1,r,ql,qr);
    inc res;
    res.val=left.val+right.val;
    if(left.max>right.min)
    {
        res.val+=(left.max-right.min)*(qr-mid);
        res.max=right.max+(left.max-right.min);
    }
    else
    res.max=right.max;
    res.min=left.min;
    return res;
}
int main()
{
    cin>>n>>m;
    x.assign(n+1,0);
    for(int i=1;i<=n;i++)cin>>x[i];
    segt.assign(4*n+1,{0,0,0}); 
    build(1,1,n); 
    for(int i=1;i<=n;i++)cout<<query(1,1,n,1,i).val<<" ";
    cout<<endl;  
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        inc res=query(1,1,n,a,b);
        cout<<res.val<<endl;
    }
}
