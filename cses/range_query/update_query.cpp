#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> tree,arr;

void buildSegmentTree(int node,int l,int r)
{
     if(l==r) 
     {
        tree[node]=arr[l];

        return;
     }
     int mid=(l+r)/2;
    buildSegmentTree(2*node+1,l,mid);
    buildSegmentTree(2*node+2,mid+1,r);
     tree[node]=tree[node*2+1]+tree[node*2+2];
}

ll query(int node, int l, int r, int ql, int qr)
{
    if(ql>r || l<ql)
    {

        return 0;
    }
    if(r>=qr && l<=ql)
    {
        return tree[node];
    }
    ll mid=(l+r)/2;
    ll left=query(2*node+1,l,mid,ql,qr);
    ll right=query(2*node+2,mid+1,l,ql,qr);
    return left+right;
}
void update(int node,int l,int r,int lq,int rq,int val)
{
    if(r>=rq && l<=lq && l==r) 
    {
        cout<<r<<" "<<l<< " "<<endl;
        tree[node]+=val;
        return;
    }
    if(lq>r || l<rq)
    {
        return ;
    }
        ll mid=(l+r)/2;
    update(2*node+1,l,mid,lq,rq,val);
    update(2*node+2,mid+1,l,lq,rq,val);
    return;
    
}
int main()
{
    ll n,q;
    cin>>n>>q;
    arr.assign(n,-1);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    tree.assign(4*n,-1);
    buildSegmentTree(0,0,n-1);
    for(int i=1;i<n;i++)
    {
        cout<<query(0,0,n-1,i-1,i-1)<<endl;
    }
    while(q--)
    {
        ll a,b,c;
        int k;
        cin>>k;
        if(k==1)
        {
        cin>>a>>b>>c;
        update(0,0,n-1,a-1,b-1,c);
        }
        else{
            cin>>a;
            cout<<query(0,0,n-1,a-1,a-1)<<endl;
        }
    }
    return 0;
}