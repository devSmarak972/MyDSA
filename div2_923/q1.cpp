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
        for(int i=1;i<n;i++)
        {
            diff[i-1]=a[i]-a[i-1];
            // cout<<diff[i-1]<<" ";
        }
        cout<<endl;
        diff[n-1]=0;
        pre[n-1]=1;
        sort(a.begin(),a.end());
        for(int i=n-2;i>=0;i--)
        {

            pre[i]=pre[i+1]+diff[i];
            // cout<<pre[i]<<" ";
        }
        reverse(pre.begin(),pre.end());
        int i=0;
        for(i=0;i<n-1;i++)
        {

            if(pre[i]==pre[i+1])break;
            // cout<<pre[i]<<" ";
        }


        auto it = std::lower_bound(pre.begin(), pre.begin()+i, n);
        it--;
        int index = std::distance(a.begin(), it);
        cout<< i <<endl;
        

    }
}
        