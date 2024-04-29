#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string rev(string &str)
{
    string revs="";
    for (int i = str.length() - 1; i >= 0; i--) {
        revs += str[i];
    }
    return revs;

}
int main()
{
    ll n,m,k,t;
    
    cin>>t;
    while(t--)
    {
    cin>>n>>m>>k;
    vector<ll> b(n);
    vector<ll> c(m);
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<m;i++)cin>>c[i];
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    int count=0;
    for(int i=0;i<n;i++)
    {
    auto it = std::upper_bound(c.begin(), c.end(), k-b[i]);
     if (it != c.begin())
      {  --it;
    
    int index = std::distance(c.begin(), it);
    count+=index+1;
      }

    }
    cout<<count<<endl;

    }
    return 0;
}