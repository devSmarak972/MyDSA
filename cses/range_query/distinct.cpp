#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;

vector<ll> x;
vector<ll> segt;
vector<ll> bit;
void updateBIT(int idx,int val)
{
    for(;idx<=n;idx+=(idx&(-idx)))
    {
        bit[idx]+=val;
    }
}
ll queryBIT(int idx)
{
    ll sum=0;
    for(;idx>0;idx-=(idx&(-idx)))
    {
        sum+=bit[idx];
    }
    return sum;
}
// vector<ll> arr;
// void build(int node,int l, int r)
// {
//     if(l==r)
//     {
//         segt[node]=arr[l];
//     }
//     else{
//         ll mid=(l+r)/2;
//         build(node*2,l,mid);
//         build(node*2+1,mid+1,r);

//         segt[node]=segt[node*2]+segt[node*2+1];

//     }
// }
void update(int idx,int val,int node=1,int l=1,int r=n)
{
    if(l>r)
    return;
    if(l==r) {
        cout<<"node: "<<node <<" "<<l <<" "<<r<<" "<<segt[node]<<endl; 

        segt[node]=val;
        // arr[l]+=val;
    }
    else{
        int mid=(l+r)/2;
        if(idx>=l && idx<=mid) update(idx,val,node*2,l,mid);
        if(idx>mid && idx<=r)update(idx,val,node*2,mid+1,r);
        segt[node]=segt[node*2]+segt[node*2+1];
    }

}
ll query(int ql, int qr,int node=1, int l=1, int r=n)
{
    if(l>r || l>qr || r<ql)
    {
        return 0;
    }
    if(l>=ql && r<=qr)
    {
        cout<<"node q: "<<node <<" "<<l <<" "<<r<<" "<<segt[node]<<endl; 
        return segt[node];
    }
    ll mid=(l+r)/2;
    return query(ql,qr,node*2,l,mid)+query(ql,qr,node*2+1,mid+1,r);
}
int main()
{
    cin>>n>>m;
    x.assign(n+1,-1);

    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    vector<vector<pair<ll,int>>> queries(n+1);
    for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		// a--, b--;
		queries[a].push_back({b, i});
	}
    segt.assign(4*n+1,0);
    bit.assign(n+1,0);
    // build(1,1,n);
    map<ll,ll> last_idx;
    vector<ll> solution(m+1,0);
    for(int i=n;i>=1;i--)
    {
        if(last_idx.count(x[i])>0){
            updateBIT(last_idx[x[i]],-1);
        }
        last_idx[x[i]]=i;
        updateBIT(i,1);
        // 3 2 3 1 2
        //         1
        // cout<<queryBIT(i)<<"  query\n";
        for(auto q:queries[i])
        {
            solution[q.second]=queryBIT(q.first)-queryBIT(i-1);
        }

    }
    for(int i=0;i<m;i++)
    {
        cout<<solution[i]<<endl;
    }
    return 0;
}