#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll> a(n,0);
        vector<ll> b(m,0);
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
        }
        for(int i=0;i<m;i++)
        {
                cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        ll diff=0;
        for(int i=0;i<a.size();i++)
        {
            diff+=abs(a[i]-b[i]);
        }
        ll ans=diff;
        for(int i=n-1;i>=0;i--)
        {
            diff-=abs(a[i]-b[i]);
            diff+=abs(b[m-n+i]-a[i]);
            ans=max(ans,diff);
            // cout<<n-(m-i)<<" "<<i<<" "<<abs(b[i]-a[n-(m-i)])-abs(b[n-(m-i)]-a[n-(m-i)])<<" : ";
        }
       
        cout<<ans<<endl;
  
    }
    return 0;
}
