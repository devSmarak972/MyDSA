#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pre;
vector<ll> a;

// Function that returns true if the function value is less than m
bool isLessThanM(ll p, ll m) {
    // Define your function here, for example:
    // Sum of array elements less than or equal to k
    ll f=(p+1)*a[p]-pre[p];
    return f <= m;
}

// Binary search to find the maximum k such that isLessThanM(k) is true
ll binarySearch(ll n,ll m) {
    ll low = 0;
    ll high = n-1; // Maximum value in the array

    while (low < high) {
        ll mid = low + (high - low + 1) / 2; // To avoid infinite loop with low=mid
        if (isLessThanM(mid, m)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    return low;
}
int main()
{
    ll n,t,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        a.assign(n,-1);
        pre.assign(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        pre[0]=a[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+a[i];
        }
        ll p=binarySearch(n,k);
        ll rem=k-((p+1)*a[p]-pre[p]);
        ll score=a[p]+(ll)(rem/(p+1));
        rem=rem-((ll)(rem/(p+1)))*(p+1);
        // cout<<score<<" score\n";
        // cout<<"p " <<p<<endl;
        score=score*n-n+1;
        score+=n-p-1+rem;
        cout<<score<<endl;


    }
    return 0;
}