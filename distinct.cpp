#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    unordered_map<ll,bool> a;
    while(n>0)
    {
        ll tmp;
        cin>>tmp;
        a[tmp]=true;
        n--;
    }
    cout<<a.size()<<endl;
    return 0;
}