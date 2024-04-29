#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> pre(n,0);
    for(int i=0;i<n;i++)
    {
        ll tmp;
        cin>>tmp;
        a.push_back(tmp);
        if(i==0)
            pre[i]+=tmp;
        else
            pre[i]+=pre[i-1]+tmp;
        pre[i]=pre[i]%n;
        pre[i]=pre[i]<0?n+pre[i]:pre[i];
    }
    sort(pre.begin(),pre.end());
    ll count=1,ans=0;
    int i;
    for(i=1;i<n;i++)
    {
        
        if(pre[i]==pre[i-1])
            count++;
        else
        {    
            ans+=pre[i-1]==0?count:0;
            ans+=count*(count-1)/2;
            count=1;
        }
    }
    if(count!=1)
    {
         ans+=pre[i-1]==0?count:0;
        ans+=count*(count-1)/2;
    }
    cout<<ans<<endl;


    return 0;
}