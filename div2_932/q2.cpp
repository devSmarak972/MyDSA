#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getMex(vector<ll>& arr) {
    int n=arr.size();
    std::unordered_set<int> seen;
    
    // Insert all elements of the array into a set
    for (int i = 0; i < n; ++i) {
        seen.insert(arr[i]);
    }
    
    // Check for the smallest non-negative integer not present in the set
    int mex = 0;
    while (seen.find(mex) != seen.end()) {
        mex++;
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
        set<ll> s;
        vector<pair<int,int>> v;
        int prev_index=0,k=0;
        if(mex==0)
        {
            cout<<n<<endl;
            for(int i=0;i<n;i++)
            cout<<i+1<<" "<<i+1<<endl;
        }
        else{
        for(int i=0;i<n;i++)
        {
            if((mex-1)==a[i])k++;
            if(a[i]<mex)s.insert(i);
            if(s.size()==mex)
            {
                v.push_back({prev_index,i});
                prev_index=i+1;
                s.clear();
            }

        }
        if(s.size()!=0)
        v.push_back({prev_index,n});
        
        if(k<=1)cout<<-1<<endl;
        else if(v.size()<2 )
        cout<<-1<<endl;
        else{

        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
        {
            
        
        if(i==v.size()-1)
        cout<<v[i].first+1<<" "<<n<<endl;
        else
        cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
        }
        }
        }
    }
}