#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string check(int a, int b)
{
    if(a%2==0 && (a/2)!=b)
        {
            return "YES";
        }
        if(b%2==0 && (b/2)!=a)
        {
            return "YES";
        }
        return "NO";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> a(n,-1);
        vector<ll> diff(n,-1);
        vector<ll> pre(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

        }
        std::vector<int> ue;

        std::sort(a.begin(), a.end());


        // Iterate through the sorted array
        for (int i = 0; i < a.size(); ++i) {
            // If it's the first element or different from the previous one, add it to ue
            if (i == 0 || (a[i] != a[i - 1])) {
                ue.push_back(a[i]);
            }
        }
        for(int i=0;i<ue.size();i++)
        {
            cout<<ue[i]<<" ";
        }
        cout<<endl;
        ll best = 1;
        ll dsum = 0;
        int s = 0, e = 1;
        while (e < n)
        {
            dsum += (ue[e] - ue[e - 1]);
            while (dsum >= n)
            {
                dsum -= (ue[s + 1] - ue[s]);
                s++;
            }
            best = max((int)best, e - s + 1);
            e++;
        }
        cout << best << endl;

    }
}
        