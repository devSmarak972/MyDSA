#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> x(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        sum+=x[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
  
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            int psum=j-x[i-1];
            if(psum>=0 && dp[i-1][psum]==1)
            dp[i][j]=1;
            // cout<<dp[i][j]<<" ";

        }
        // cout<<endl;

    }
    vector<int>poss;
    for(int s=1;s<=sum;s++)
    {
        if(dp[n][s])
        poss.push_back(s);
    }
    cout<<(int)poss.size()<<endl;
    for(int s:poss)
    {
        cout<<s<<" ";
    }
    cout<<endl;
}