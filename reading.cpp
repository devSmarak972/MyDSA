#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),greater<ll>());
    ll sum=0;
    for(int i=1;i<arr.size();i++)
    {
        sum+=arr[i];
    }
    if(sum<=arr[0])cout<<2*arr[0]<<endl;
    else cout<<sum+arr[0]<<endl;
    return 0;
}