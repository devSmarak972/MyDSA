#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        int i=0;
        int m=n-1;
        int mmax=-1;
        for( i=n-1;i>=1;i--)
        {
            if(gcd(n,i)+i>mmax)
            {
            m=i;
            mmax=gcd(n,i)+i;
            // cout<<i<<" " <<mmax<<endl;
            }
        }
        
            cout<<m<<endl;
     
    }
    
    return 0;
}