#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> a(n),b(n);
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        
        for(int i=0;i<n;i++)
        {
            p.push_back({a[i],b[i]});
        }
        sort(p.begin(),p.end());
        for(int i=0;i<n;i++)
        {
            cout<<p[i].first<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<p[i].second<<" ";
        }
        cout<<endl;
    }
    return 0;
}