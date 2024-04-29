#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int getMex(vector<ll> &a)
{
    int n=a.size();
     map<int, int> mp;
    mp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    int c = 0, mex = 0;
    for (int i = 0; i <= n; i++)
    {
        if (mp[i] == 0)
        {
            mex = i;
            break;
        }
    }
    return mex;
}
int main()
{
     ll n,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        ll mex=getMex(a);
   
    // cout<<mex<<endl;
    if (mex == 0)
    {
        cout << n << endl;
        for (int i = 0; i < n; i++)
            cout << i + 1 << " " << i + 1 << endl;
        break;
    }
    int c = count(a.begin(), a.end(), mex - 1);
    if (c < 2)

    {
        cout << -1 << endl;
        break;
    }
    vector<pair<int, int>> v;

    set<int> seg;
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < mex)
        {
            seg.insert(a[i]);
        }
        if (seg.size() == mex)
        {
            v.push_back({prev, i});
            prev = i + 1;
            seg.clear();
        }
    }
    if (v.size() < 2)
    {
        cout << -1 << endl;
        break;
    }
    else
    {
        int nn = v.size();
        if (v[nn - 1].second != n - 1)
            v[nn - 1].second = n - 1;
        cout << nn << endl;
        for (auto x : v)
            cout << x.first + 1 << " " << x.second + 1 << endl;

        break;
    }
    }
    return 0;
}