#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        t--;
        int n,k,x;
        cin>>n>>k>>x;
            vector<int> arr(n),prepos(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];

        }
        sort(arr.begin(),arr.end(),greater<int>());
        prepos[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prepos[i]=arr[i]+prepos[i-1];
            // cout<<prepos[i-1]<<" ";
        }
        // cout<<prepos[n-1]<<endl;
        int sum=0,summax=-1e6;
        for(int i=1;i<=k;i++)
        {
     
             if(x+i-1<n)sum+=(-prepos[x+i-1]+prepos[i-1])+prepos[n-1]-prepos[x+i-1];
            else sum+=(-prepos[n-1]+prepos[i-1]);

            summax=max(summax,sum);
            sum=0;

        }
        summax=max(-2*prepos[x-1]+prepos[n-1],summax);
        cout<<summax<<endl;

    }
    return 0;
}