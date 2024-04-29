#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string check(int a, int b)
{
    if(a%2==0 && (a/2)!=b)
        {
            return "YES";
        }
        if(b%2==0 && (b/2)!=a)
        {
            return "YES";
        }
        return "NO";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        int count=0;
        int b=n-x;
         for (int i = 1; i <= sqrt(b); ++i) {
            int k=i;
            int c=b;
        if (b % k == 0) {
            if(((b/k) %2)==0)count++;
        }    
        k=b/i;  
        if (b % k == 0) {
            if(((b/k) %2)==0)count++;
        }     
    }
    b=n-2+x;

         for (int i = 1; i <= sqrt(b); ++i) {
            int k=i;
            int c=b;
        if (b % k == 0) {
            if(((b/k) %2)==0)count++;
        }  
        k=b/i;  
        if (b % k == 0) {
            if(((b/k) %2)==0)count++;
        }          
    }
    cout<<count<<endl;
    }

}