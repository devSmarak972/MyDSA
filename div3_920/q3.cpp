#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,f,a,b;
        cin>>n>>f>>a>>b;
        vector<ll> arr(n,0);
        for(int i=0;i<n;i++)
        {
                cin>>arr[i];
        }
        arr.insert(arr.begin(), 0);
        sort(arr.begin(),arr.end());
        int cost=f,i;
        cost-=a;
        for(i=1;i<arr.size();i++)
        {
            if(cost<=0)
             break;
            if((arr[i]-arr[i-1])*a>b)
            {
                    cost-=b;
            }
            else 
            {
                cost-=(arr[i]-arr[i-1])*a;
            }
            cout<<cost<<" ";

        }
        cout<<endl;
        cout<<cost<<endl;

       
        cout<< ((i==arr.size())?"YES\n":"NO\n");
  
    }
    return 0;
}
