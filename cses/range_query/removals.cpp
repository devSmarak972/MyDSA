#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> present;
vector<ll> segt;
	vector<ll> x;

void build(int l=1,int r=n,int node=1)
{
	if(l==r) 
	{
		segt[node]=present[l];
		// cout<<"node: "<<node<<" "<<l<<endl;
	}
	else{
		ll mid=(l+r)/2;
		build(l,mid,node*2);
		build(mid+1,r,node*2+1);
		segt[node]=segt[node*2+1]+segt[node*2];
	}
}
ll query( int ql, int qr,int node=1, int l=1, int r=n)
{
    if(l>r || l>qr || r<ql)
    {
        return 0;
    }
    if(r<=qr && l>=ql)
    {
        return segt[node];
    }
    ll mid=(l+r)/2;
    ll left=query(ql,qr,2*node,l,mid);
    ll right=query(ql,qr,2*node+1,mid+1,r);
    return left+right;
}
void update(int node,int l,int r,int idx)
{
	// cout<<"r l lq rq"<<r<<" "<<l<<" "<<lq<<" "<<rq<<endl;
    if( l==r) 
    {
        segt[node]=0;
		present[l]=0;
		//  cout<<"updating :"<<l<<endl;
        return;
    }

	ll mid=(l+r)/2;
	if(l<=idx && idx<=mid)
    update(2*node,l,mid,idx);
	else
    update(2*node+1,mid+1,r,idx);
    
	segt[node]=segt[2*node]+segt[2*node+1];
    
}
int main()
{
    iostream::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n;
	x.assign(n+1,-1);
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	present.assign(n+1,1);
	ll l = (int)(ceil(log2(n)));
    ll max_size=2*(int)pow(2,l)-1;
	segt.assign(max_size+1,0);
	build();
	// for(int i=1;i<max_size+1;i++)cout<<segt[i]<<" ";
	// cout<<endl;
	ll t=n;
	// for(int i=1;i<=n;i++)
	// 	cout<<query(1,i)<<" ";
	// 	cout<<endl;
	while(t--)
	{
		ll ind;
		cin>>ind;
		ll l=1,r=n,m;
		while (l < r) {
        m = (l + r) / 2;
        if (query(1,m) >= ind)
            r = m;
        else 
            l = m + 1;
		}

		// cout<<"\nl :"<<l<<endl;
		cout<<x[l]<<" ";
		update(1,1,n,l);
		// for(int i=1;i<=n;i++)
		// {
		// cout<<query(1,i)<<" ";
		// }
		// cout<<endl;
		// for(int i=1;i<=n;i++)
		// {
		// cout<<present[i]<<" ";
		// }
		// cout<<endl;
	}

    return 0;
}


