#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
vector<char> c;
set<ll> pos;
vector<vector<ll>>dp;
int m,n;
int recurse(int curr,int ball)
{
if(curr==m)
{
    pos.insert(ball);
    return 1;
}
if(dp[curr][ball]!=-1) return dp[curr][ball];

if(c[curr]=='?')
dp[curr][ball]= recurse(curr+1,((ball+a[curr]))%n)+recurse(curr+1,(n+ball-a[curr])%n);
else if(c[curr]=='0')
dp[curr][ball]=  recurse(curr+1,((ball+a[curr]))%n);
else
dp[curr][ball]=  recurse(curr+1,(n+ball-a[curr])%n);
return dp[curr][ball];
}

int main()
{
    ll k,x,t;
    
    cin>>t;
    while(t--)
    {
    cin>>n>>m>>x;
    x--;
    a.assign(m,-1);
    c.assign(m,-1);
    pos.clear();
    for(int i=0;i<m;i++)
    {
        cin>>a[i]>>c[i];
    }
    dp.assign(m,vector<ll>(n,-1));
    recurse(0,x);
    cout<<pos.size()<<endl;
    // cout<<"pos:"<<pos.size()<<endl;
    for(auto &e:pos)cout<<e+1<<" ";
    cout<<endl;
    }
    return 0;
}