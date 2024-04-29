#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
     ll n,m,t,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        vector<ll> a(n);
        set<ll> s;
        for(int i=0;i<n;i++)
        {
        ll tmp;
        cin>>tmp;
        s.insert(tmp);
        a[i]=tmp;
        }
        ll count=0;
        for(int i=0;i<n;i++)
        {
            auto it=s.find(2*c-a[i]);
            if(it!=s.end() && *it!=a[i] )
            {
                count++;
                cout<<a[i]<<" "<<*it<<endl;
            }


        }
        cout<<(int)(c*(c-1)/2)-count<<endl;

    
    }
    // cout<<mex<<endl;
  
    return 0;
}