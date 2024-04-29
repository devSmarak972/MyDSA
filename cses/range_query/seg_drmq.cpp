#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tree;
ll buildSegmentTree(vector<ll> &num,ll node,ll l,ll r)
{
    if(l==r)
    {
        tree[node]=num[l];
        return tree[node];
    }
    ll mid=(l+r)/2;
    ll left=buildSegmentTree(num,2*node+1,l,mid);
    ll right=buildSegmentTree(num,2*node+2,mid+1,r);
    tree[node]= min(left,right);
    return tree[node];
}

ll query(ll node,ll start,ll end,ll qStart,ll qEnd)
{
   if(qStart>end || qEnd<start)return INT_MAX;

   if(qStart<=start && qEnd>=end)return tree[node];
    ll mid=(start+end)/2;
    ll left=query(2*node+1,start,mid,qStart,qEnd);
    ll right=query(2*node+2,mid+1,end,qStart,qEnd);
    return min(left,right);
}
void update(ll node,ll pos,ll start,ll end,ll val)
{
    if(start==end)
    {
        tree[node]=val;
    }
    else{
        ll mid=(start+end)/2;
        if(pos<=mid)
         update(2*node+1,pos,start,mid,val);
        else
        update(2*node+2,pos,mid+1,end,val);
        tree[node]=min(tree[node*2+1],tree[node*2+2]);
    }
}
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n); 
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    tree.assign(2 * pow(2, std::ceil(std::log2(n))) - 1,-1);
    buildSegmentTree(arr,0,0,n-1);

    while(q--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        update(0,b-1,0,n-1,c);
        else{
            cout<<query(0,0,n-1,b-1,c-1)<<endl;
        }
    }
    return 0;
}