#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a;
    while(n>0)
    {
        ll tmp;
        cin>>tmp;
        a.push_back(tmp);
        n--;
    }
    sort(a.begin(),a.end());
    int count=1;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]!=a[i-1])
         count++;
    }
    cout<<count<<endl;
    return 0;
}