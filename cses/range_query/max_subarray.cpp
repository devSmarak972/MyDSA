#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
typedef struct {
 ll sum;
 ll left;
 ll right;
 ll max;
} subSum;
vector<subSum> segt;
vector<ll> x;
void sum(int node)
{
    segt[node].left=max(segt[node*2].left,segt[node*2].sum+segt[node*2+1].left);
    segt[node].right=max(segt[node*2+1].right,segt[node*2+1].sum+segt[node*2].right);
    segt[node].sum=segt[node*2].sum+segt[node*2+1].sum;
    segt[node].max=max(segt[node*2].max,max(segt[node*2+1].max,segt[node*2].right+segt[node*2+1].left));
}
void build(int node,int l, int r)
{
    if(l==r)
    {
        segt[node].left=x[l];
        segt[node].right=x[l];
        segt[node].sum=x[l];
        segt[node].max=x[l];
        // ??zero ifnegative
    }
    else{
        int mid=(l+r)/2;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        // cout<<"hee1\n";
        sum(node);
        // cout<<"hee2\n";
    }
}

void update(int node, int l, int r, int ind, ll val)
{
    if(l>r)return;
    if(l==r)
    {
        x[l]=val;
        segt[node].right=val;
        segt[node].left=val;
        segt[node].sum=val;
        segt[node].max=val;
        // cout<<"\nl: "<<l<<endl;
    }
    else{
        int mid=(l+r)/2;
        if(ind<=mid && ind>=l)
        {
            update(node*2,l,mid,ind,val);
            sum(node);
        }
        else if(ind>mid && ind<=r) 
        {
            update(node*2+1,mid+1,r,ind,val);
            sum(node);
        }
    }
}
int main()
{
    cin>>n>>m;
    x.assign(n+1,-1);
    for(int i=1;i<=n;i++)cin>>x[i];
    segt.assign(4*n+1,{0,0,0,0});
    build(1,1,n);
    // cout<<segt[1].max<<endl;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        update(1,1,n,a,b);
        cout<<max(0LL,segt[1].max)<<endl;
    }



}