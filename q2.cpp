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
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
// 1 3 5 5 2 
// 1 3 4 3 2 
// 3 3 5 5 2
//2 2 2 2 2 2
// a[i]-2*a[i-1]>0
int i=0;

    for( i=0;i<=(n-3);i++)
    {
    if(a[i]>=0)
    {
        a[i+1]-=2*a[i];
        a[i+2]-=a[i];
        a[i]=0;
    }
    else break;

    }
    if(i<=n-3)
    cout<<"NO"<<endl;
    else 
    {
        if(a[n-1]==0 & a[n-2]==0)cout<<"YES\n";
        else cout<<"NO\n";
    }

    }
    return 0;
}