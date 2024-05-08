#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> segtLeft;
vector<ll> segtRight;
vector<ll> p;
ll n;
void build(ll node, ll l,ll r)
{
    if(l==r)
    {
        segtLeft[node]=p[l]-l;
        segtRight[node]=p[l]+l;
    }
    else{
        ll mid=(l+r)/2;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        segtLeft[node]=min(segtLeft[node*2],segtLeft[node*2+1]);
        segtRight[node]=min(segtRight[node*2],segtRight[node*2+1]);
    }
}
ll queryLeft(ll node,ll l,ll r,ll ql,ll qr)
{
      if(l>r || l>qr || r<ql)
    {
        return LLONG_MAX;
    }
    if(r<=qr && l>=ql)
    {
        return segtLeft[node];
    }
    else{
        ll mid=(l+r)/2;
        return min(queryLeft(node*2,l,mid,ql,qr),queryLeft(node*2+1,mid+1,r,ql,qr));
        
    }
}
ll queryRight(ll node,ll l,ll r,ll ql,ll qr)
{
    if(l>r || l>qr || r<ql)
    {
        return LLONG_MAX;
    }
    if(r<=qr && l>=ql)
    {
        return segtRight[node];
    }
    else{
        ll mid=(l+r)/2;
        return min(queryRight(node*2,l,mid,ql,qr),queryRight(node*2+1,mid+1,r,ql,qr));
        
    }
}

void update(ll node,ll l,ll r,ll ind,ll val)
{   
    if(l==r)
    {
        segtRight[l]=val+l;
        segtLeft[l]=val-l;
    }
    else{
        ll mid=(l+r)/2;
        if(	l<=ind && ind<=mid)update(node*2,l,mid,ind,val);
        else update(node*2+1,mid+1,r,ind,val);

        segtLeft[node]=min(segtLeft[node*2],segtLeft[node*2+1]);
        segtRight[node]=min(segtRight[node*2],segtRight[node*2+1]);
    }
}
void buildRight(ll node, ll l,ll r,ll ind)
{
    if(l==r)
    {
        segtRight[node]=p[l]+l;
    }
    else{
        ll mid=(l+r)/2;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        segtRight[node]=min(segtRight[node*2],segtRight[node*2+1]);
    }
}
int main() 
{
    int q;
    cin>>n>>q;
    p.assign(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        // cout<<p[i]<<" ";
    }
    // cout<<endl;
    segtLeft.assign(4*n+1,0);
    segtRight.assign(4*n+1,0);
    build(1,1,n);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<queryRight(1,1,n,i,i)<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<queryLeft(1,1,n,i,i)<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=q;i++)
    {
        ll a;
        cin>>a;
        if(a==1)
        {
            ll b,c;
            cin>>b>>c;
            update(1,1,n,b,c);
        }
        else{
            ll b;
            cin>>b;
            cout<<min(queryRight(1,1,n,b,n)-b,queryLeft(1,1,n,1,b)+b)<<endl;
        }
    }


    return 0;
}