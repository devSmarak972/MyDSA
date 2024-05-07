#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    vector<int> dp(n,-1);

    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            if(arr[i+1]-arr[i]<=2)
            count++;
        }
        
    }
    return 0;
}