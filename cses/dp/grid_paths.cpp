#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    vector<vector<int>> grid(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char a;
            cin>>a;
            if(a=='.')grid[i][j]=0;
            else grid[i][j]=1;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(grid[n-1][i]==1)break;
        dp[n-1][i]=1;
    }
        
    for(int i=n-1;i>=0;i--)
    {
        if(grid[i][n-1]==1)break;
        dp[i][n-1]=1;
    }
    dp[n-1][n-1]=1;
    if(grid[n-1][n-1]==1)
    {
    cout<<0<<endl;
    return 0;
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            if(grid[i][j]==1)continue;
            dp[i][j]=(dp[i+1][j]+dp[i][j+1])%MOD;
            // cout<<"i: "<<i<<" j: "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][0]<<endl;
    return 0;

}