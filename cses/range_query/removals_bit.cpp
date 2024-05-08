#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> present;
vector<ll> ftree;
vector<ll> x;
ll get(ll i)
{
    ll sum=0;
    // Traverse ancestors of BITree[index] 
    while (i>0) 
    { 
        // Add current element of BITree to sum 
        sum += ftree[i]; 
  
        // Move index to parent node in getSum View 
        i -= i & (-i); 
    } 
    return sum;
}
 void update(ll i, ll delta) {
    while(i<=n)
    {
        ftree[i]+=delta;
        i+=i&(-i);
    }      
}
void build()
{
    for(int i=1;i<=n;i++)
    {
        ftree[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        update(i,present[i]);
    }
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

	ftree.assign(n+1,0);
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
        if (get(m) >= ind)
            r = m;
        else 
            l = m + 1;
		}

		// cout<<"\nl :"<<l<<endl;
		cout<<x[l]<<" ";
		update(l,-1);
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


