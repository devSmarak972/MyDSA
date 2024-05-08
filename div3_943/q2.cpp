#include <bits/stdc++.h>
using namespace std;
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
        cin>>n>>m;
        string a ,b;
        cin>>a>>b;
            int k=0;
            for(int i=0;i<m;i++)
            {
                if(b[i]==a[k])
                {
                    k++;
                    // cout<<b[i]<<" ";
                }
            }
                // cout<<endl;
            cout<<k<<endl;
        
        
     
    }
    
    return 0;
}