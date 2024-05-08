#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pre;
vector<ll> a;

int main()
{
    ll n,t,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll sum=0;
        for(int b=1;b<=m;b++)
        {
            sum+=(ll)(((ll)(n/b)+1)/b);
        }
        cout<<sum-1<<endl;

    }
    return 0;
}