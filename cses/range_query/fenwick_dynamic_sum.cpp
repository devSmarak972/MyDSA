#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN (int)2e5
ll arr[MAXN+1],tree[MAXN+1];
ll n,q,a,b,t;
void update(ll idx,ll val)
{
    ll diff=val-arr[idx];
    for(int i=idx;i<=n;i+=(-i&i))
    {
        tree[i]+=diff;
    }
    arr[idx]=val;
}

ll query(ll idx)
{
    ll sum=0;
    for(int i=idx;i>0;i-=(-i&i))
    {
        sum+=tree[i];
    }
    return sum;
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[0];
        update(i,arr[0]);
    }
    while(q--)
    {
        scanf("%d %lld %lld",&t,&a,&b);
        if(t==1)update(a,b);
        else cout<<query(b)-query(a-1)<<endl;
    }
}