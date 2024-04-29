#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    unordered_map<int,bool> arr;
    while(t--)
    {
        arr.clear();

        int n;
        cin>>n;
        ll a,x,hi=1e9,lo=-1;
        for(int i=0;i<n;i++)
        {
            cin>>a>>x;
        if(a==1 && x>lo)
         lo=x;
        if(a==2 && x<hi)
            hi=x;
        if(a==3)
         arr[x]=true;
        }
        int cnt=0;
          for (const auto& pair : arr) {
            if(pair.first>=lo&&pair.first<=hi)
             cnt++;
            }
            int ans=(lo<=hi)?hi-lo+1-cnt:0;
            cout<< ans<<endl;
    }
    return 0;
}