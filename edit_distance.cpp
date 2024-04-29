#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int min(int x, int y, int z) { return min(min(x, y), z); }

int main()
{
    string a,b;
    cin>>a>>b;
    int n=max(a.size(),b.size());
    int dp[a.size()+1][b.size()+1];
    for(int i=0;i<=a.size();i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<=b.size();i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            if(a[i-1]!=b[j-1])
            dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
            else    
            dp[i][j]=dp[i-1][j-1];
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
            
    }
    


    cout<<dp[a.size()][b.size()]<<endl;
    return 0;
}