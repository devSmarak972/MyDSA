#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    int n,q;
    cin>>n>>q;
    vector<ll> a(n),pre(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    for(int i=1;i<=n;i++)
    pre[i]=pre[i-1]+a[i-1];


    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<pre[b]-pre[a-1]<<endl;

    }
    return 0;
}