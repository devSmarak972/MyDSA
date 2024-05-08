#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
vector<ll> a;
typedef struct{
    ll sum;
    ll inc1;
    ll inc2;
} node;
vector<node> segt;
vector<ll> lazy;
ll f(ll v)
{
    return v*(v+1)/2;
}
void composeLeft(int parnode,int node)
{
     segt[node].inc1+=segt[parnode].inc1;
     segt[node].inc2+=segt[parnode].inc2;
}
void composeRight(int parnode,int node,int l, int r)
{
    int mid=(l+r)/2;
     segt[node].inc1+=segt[parnode].inc1+(mid-l+1)*segt[parnode].inc2;
     segt[node].inc2+=segt[parnode].inc2;
}
void push(ll v,int l, int r) {
    
    segt[v].sum+=segt[v].inc1 *(r-l+1) + segt[v].inc2* f(r-l+1);    
    if(l!=r)
    {
        composeLeft(v,2*v);
        composeRight(v,2*v+1,l,r);
    }
    segt[v].inc1=0;
    segt[v].inc2=0;
 
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        segt[node].sum=a[l];
        segt[node].inc1=0;
        segt[node].inc2=0;

    }
    else{
        int mid=(l+r)/2;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        segt[node].sum=segt[node*2].sum+segt[node*2+1].sum;
        segt[node].inc1=0;
        segt[node].inc2=0;
    }
}

void update(int node, int l, int r, int ql, int qr)
{
    if(l>r || l>qr || r<ql)
    return;
    if(l>=ql && r<=qr)
    {
        ll v=(ql-qr+1); 
        segt[node].inc1+=(ql-l);
        segt[node].inc2+=1;
        // lazy[node]+=val;
    }
    else{
        push(node,l,r);
        int mid=(l+r)/2;
        update(node*2,l,mid,ql,qr);
        update(node*2+1,mid+1,r,ql,qr);
        push(node*2,l,mid);
        push(node*2+1,mid+1,r);
        //need correct values of children now.
        segt[node].sum=segt[node*2].sum+segt[node*2+1].sum;
    }
}

ll query(int node,int l,int r, int ql,int qr)
{
    if(l>r ||  l>qr || r<ql)
    return 0;
    push(node,l,r);
    if(l>=ql &&r<=qr )return segt[node].sum;
    else{
        int mid=(l+r)/2;
        return query(node*2,l,mid,ql,qr)+query(node*2+1,mid+1,r,ql,qr);
    }
}
int main()
{
    cin>>n>>q;
    a.assign(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>> a[i];
    }
    segt.assign(4*n+1,{0,0});
    build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int p,q,r;
            cin>>p>>q;
            update(1,1,n,p,q);
        }
        else{
            int p,q;
            cin>>p>>q;
            cout<<query(1,1,n,p,q)<<endl;
        }


    }
    return 0;
}