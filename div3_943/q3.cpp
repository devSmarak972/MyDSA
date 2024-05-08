#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Returns length of LCS for X[0..m-1], Y[0..n-1] 
int lcs(string X, string Y, int m, int n) 
{ 
    if (m == 0 || n == 0) 
        return 0; 
    if (X[m - 1] == Y[n - 1]) 
        return 1 + lcs(X, Y, m - 1, n - 1); 
    else
        return max(lcs(X, Y, m, n - 1), 
                   lcs(X, Y, m - 1, n)); 
} 

int main()
{
    int t,n,m;
    cin>>t;
    while (t--)
    {
        cin>>n;
        vector<ll> x(n+1,-1);
        for(int i=0;i<n-1;i++)
        {
            cin>>x[i+2];
        }
        vector<ll> a(n+1,0); 
        a[1]=x[2]+1;
        for(int i=2;i<=n;i++)
        {   
            ll l;
            if(i!=n)
            l=(ll)(x[i+1]-x[i])/(a[i-1]);
            else
            l=0;

            if(l<0)l=-1;
            // cout<<"l: "<<l<<" i "<<i<<endl;
           a[i]=a[i-1]*(l+1)+x[i];
        }
        // for(int i=2;i<=n;i++)
        // {
        //     if(x[i]!=a[i]%a[i-1])
        //     {
        //         cout<<"incorrect"<<endl;
        //         break;
        //     }
        // }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
        
     
    }
    
    return 0;
}