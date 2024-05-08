#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int a,b;

    // 1 1 1 1 1 
    // 1 1 1 1 1
    // 1 1 1 1 1
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,INT_MAX));

    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            if(i==j)
            {
            dp[i][j]=0;
            continue;
            }
            for(int k=1;k<j;k++)
            {
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
            for(int k=1;k<i;k++)
            {
            dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}