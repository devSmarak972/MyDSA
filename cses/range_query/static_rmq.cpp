#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tree;
vector<ll> a;

ll buildSegmentTree(ll node,ll l, ll r)
{
    if(l==r)
    {
        tree[node]=a[l];
        return tree[node];
    }
    int mid=(l+r)/2;
    ll leftval=buildSegmentTree(2*node+1,l,mid);
    ll rightval=buildSegmentTree(2*node+2,mid+1,r);

    tree[node]=min(leftval,rightval);

    return tree[node];
}
ll query(ll node,ll l, ll r, ll ql, ll qr)
{
   if(qr<l ||ql>r)
    return LLONG_MAX;
   if(ql<=l && qr>=r)return tree[node];
    ll mid=(l+r)/2;
    ll left=query(2*node+1,l,mid,ql,qr);
    ll right=query(2*node+2,mid+1,r,ql,qr);
    // cout<<"l "<<l<<" "<<left<<" r "<<r<<" "<<right<<endl;
    return min(left,right);
}
int main()
{
    ll n,q;
    cin>>n>>q;
    a.assign(n,-1);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
      //Height of segment tree  
    ll x = (int)(ceil(log2(n)));  
  
    // Maximum size of segment tree  
    ll max_size = 2*(ll)pow(2, x) - 1;  
  
    tree.assign(max_size,-1);
    // buildSegmentTree(0,0,n-1);
    buildSegmentTree(0,0,n-1);
    ll a,b;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<query(0,0,n-1,0,i);
    //     cout<<"_______________________"<<i<<+"____________________\n";
    // }
    for(ll i=0;i<q;i++)
    {
        
        cin>>a>>b;
        cout<<query(0,0,n-1,a-1,b-1)<<endl;
    }
    return 0;
}