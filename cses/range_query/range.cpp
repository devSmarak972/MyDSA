#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
vector<ll> a;
typedef struct{
    ll sum;
    ll setall;
    ll inc;
    ll valid;
} node;
vector<node> segt;
vector<ll> lazy;
void compose(int parnode,int node)
{
    if(segt[parnode].valid)
    {
        segt[node].valid=1;
        segt[node].setall=segt[parnode].setall;
        segt[node].inc=segt[parnode].inc;

    }
    else segt[node].inc+=segt[parnode].inc;
}
void push(ll v,int l, int r) {
    if(segt[v].valid)
    {
        segt[v].sum=(r-l+1)*segt[v].setall;
    }
    segt[v].sum+=(r-l+1)*segt[v].inc;
    if(l!=r)
    {
        compose(v,2*v);
        compose(v,2*v+1);
    }
    segt[v].setall=0;
    segt[v].inc=0;
    segt[v].valid=0;
 
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        segt[node].sum=a[l];
        segt[node].inc=0;
        segt[node].setall=0;
        segt[node].valid=0;

    }
    else{
        int mid=(l+r)/2;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        segt[node].sum=segt[node*2].sum+segt[node*2+1].sum;
        segt[node].inc=0;
        segt[node].setall=0;
        segt[node].valid=0;

    }
}

void updateInc(int node, int l, int r, int ql, int qr, int valinc)
{
    if(l>r || l>qr || r<ql)
    return;
    if(l>=ql && r<=qr)
    {
        segt[node].inc+=valinc;
   
        // lazy[node]+=val;
    }
    else{
        push(node,l,r);
        int mid=(l+r)/2;
        updateInc(node*2,l,mid,ql,qr,valinc);
        updateInc(node*2+1,mid+1,r,ql,qr,valinc);
        push(node*2,l,mid);
        push(node*2+1,mid+1,r);
        //need correct values of children now.
        segt[node].sum=segt[node*2].sum+segt[node*2+1].sum;
        }
}
void updateSet(int node, int l, int r, int ql, int qr, int valset)
{
    if(l>r || l>qr || r<ql)
    return;
    if(l>=ql && r<=qr)
    {
        segt[node].setall=valset;
        segt[node].valid=1;
        segt[node].inc=0;
        // lazy[node]+=val;
        return;
    }
    else{
        push(node,l,r);
        int mid=(l+r)/2;
        updateSet(node*2,l,mid,ql,qr,valset);
        updateSet(node*2+1,mid+1,r,ql,qr,valset);
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
    segt.assign(4*n+1,{0,0,0,0});
    build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int p,q,r;
            cin>>p>>q>>r;
            updateInc(1,1,n,p,q,r);
        }
        else if(t==2)
        {
            int p,q,r;
            cin>>p>>q>>r;
            updateSet(1,1,n,p,q,r);
        }
        else{
            int p,q;
            cin>>p>>q;
            cout<<query(1,1,n,p,q)<<endl;
        }


    }
    return 0;
}