#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> BIT;
ll n,q;
void update(ll x,ll y,ll val)
{
    for(int i=x;i<=n;i+=(i&(-i)))
    {
        for(int j=y;j<=n;j+=(j&(-j)))
        {
            BIT[i][j]+=val;
        }
    }
}
ll query(int x1,int y1,int x2,int y2)
{
    ll sum=0;
    for(int i=x1;i>0;i-=(i&(-i)))
    {
        for(int j=y1;j>0;j-=(j&(-j)))
        {
            sum+=BIT[i][j];
        }
    }
    for(int i=x2-1;i>0;i-=(i&(-i)))
    {
        for(int j=y1;j>0;j-=(j&(-j)))
        {
            sum-=BIT[i][j];
        }
    }
    for(int i=x1;i>0;i-=(i&(-i)))
    {
        for(int j=y2-1;j>0;j-=(j&(-j)))
        {
            sum-=BIT[i][j];
        }
    }
    for(int i=x2-1;i>0;i-=(i&(-i)))
    {
        for(int j=y2-1;j>0;j-=(j&(-j)))
        {
            sum+=BIT[i][j];
        }
    }
    return sum;
}
int main()
{
    cin>>n>>q;
    BIT.assign(n+1,vector<ll>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char a;
            cin>>a;
            if(a=='*')update(i,j,1);
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<query(i,j,1,1)<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1;i<=q;i++)
    {
        int t;
		cin >> t;
		if (t == 1) {
            int y,x;
            cin>>y>>x;
            if(query(y,x,y,x)==1)
            update(y,x,-1);
            else update(y,x,1);
        }
        else{
            ll y1,x1,y2,x2;
            cin>>y1>>x1>>y2>>x2;
            if(x2<x1)
            cout<<query(y1,x1,y2,x2)<<endl;
            else
            cout<<query(y2,x2,y1,x1)<<endl;
        }
    }
    return 0;
}