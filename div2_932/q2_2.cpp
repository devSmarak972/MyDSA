#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mfreq;
    mfreq[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mfreq[a[i]] = 1;
    }
    int mex = 0;
    for (int i = 0; i <= n; i++)
    {
        if (mfreq[i] == 0)
        {
            mex = i;
            break;
        }
    }
    // cout<<mex<<endl;
    if (mex == 0)
    {
        cout << n << endl;
        for (int i = 0; i < n; i++)
            cout << i + 1 << " " << i + 1 << endl;
        return;
    }
     
    if (count(a.begin(), a.end(), mex - 1) < 2)

    {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> v;

    set<int> seg;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < mex)
        {
            seg.insert(a[i]);
        }
        if (seg.size() == mex)
        {
            v.push_back({start, i});
            start = i + 1;
            seg.clear();
        }
    }
    if (v.size() < 2)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        int nn = v.size();
        if (v[nn - 1].second != n - 1)
            v[nn - 1].second = n - 1;
        cout << nn << endl;
        for (auto x : v)
            cout << x.first + 1 << " " << x.second + 1 << endl;

        return;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}