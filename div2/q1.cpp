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
        vector<ll> a(n);
        vector<ll> b(n);
        priority_queue<ll, vector<ll>, greater<ll> > arr;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            arr.push(a[i]);
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        int i=0;
         priority_queue<ll, vector<ll>, greater<ll> > temp_pq = arr;
        ll c=0;
        // Iterate through the priority queue by popping elements
        while (!temp_pq.empty()) {
            ll el= temp_pq.top() ; // Access the top element
            // temp_pq.pop(); // Remove the top element
        
            // cout<<el<<" "<<b[i]<<"\n";
            if(el>b[i])
            {
                arr.push(b[i]);
                temp_pq.push(b[i]);
                c++;
            }
                temp_pq.pop();
            
            i++;
            if(i==n)break;
        }
        // cout<<endl;
        temp_pq = arr;
        i=0;
        // while (!temp_pq.empty()) {
        //     cout<<arr.top()<<" "<<b[i]<<endl;
        //     i++;
        //     if(i==n)break;
        // }

    cout<<c<<endl;
    }
//  1000 1400 1800 2000 2000 2200 2700
// 1200  1500 1800

    return 0;
}