#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int n,m;
#include <chrono>

int comp(int s,int s1)
{
    if(s&s1)return 0;
    int r=(((~s)&(~s1)))&((1<<n)-1);// this will have active bits in adjacent pairs if x do not have odd numbered contigous pairings
    if(r%3==0)
    {
        int q=r/3;
        // cout<<r<<" "<<s<<" "<<s1<<endl;
        if((q&(q<<1))==0)
        {
            return 1;
        // cout<<s<<" "<<s1<<endl;
        }
    }
    return 0;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    ll size=1<<n;
    vector<vector<ll>> dp(m+1,vector<ll>(size+1,0));
    //number of ways to have first i columns completely filled with i-1 completely filled and poking out some having s mask poking out
    vector<vector<int>> compatible(size,vector<int>(size,0));
    // for(int s=0;s<(1<<n);s++)
    // {
    //     for(int s1=0;s1<(1<<n);s1++)
    //     {
    //         if(s&s1)continue;
    //         int c=0;
    //         int b=s|s1;
    //         // cout<<"S : s1 "<<s<<" "<<s1<<endl;
    //         if(n%2==1 && b==0)
    //         {
    //             compatible[s][s1]=0;
    //             continue;
    //         }
    //         b|=(1<<n);
    //         int p=0;
    //         for(;b>0;b-=b&(-b))
    //         {
    //             // if(((~s)&(1<<p)) && ((~s1)&(1<<p)))
    //             // c++;
    //             // else
    //             // {
    //             // if(c%2==1)
    //             // {
    //             // compatible[s][s1]=0;
    //             // break;
    //             // }
    //             // c=0;
    //             // }
    //             c=log2(b&(-b))-p;
    //             p=log2(b&(-b))+1;
    //             // cout<<c<<endl;
    //             if(c%2!=0)break;
    //         }
    //         if(b<=0)
    //         {
    //         compatible[s][s1]=1;
    //         // cout<<s<<" "<<s1<<endl;
            
    //         }

    //     }
    // }
    //this is the fastest way
    // for(int s=0;s<(1<<n);s++)
    // {
    //     for(int s1=0;s1<(1<<n);s1++)
    //     {
    //         if(s&s1)continue;
    //         int r=(((~s)&(~s1)))&((1<<n)-1);// this will have active bits in adjacent pairs if x do not have odd numbered contigous pairings
    //         if(r%3==0)
    //         {
    //             int q=r/3;
    //             // cout<<r<<" "<<s<<" "<<s1<<endl;
    //             if((q&(q<<1))==0)
    //             {
    //             compatible[s][s1]=1;
    //             // cout<<s<<" "<<s1<<endl;
    //             continue;
    //             }
    //         }
    //     }
    // }
    // cout<<"too long?\n";

    for(int i=0;i<=m;i++)
    {
    auto start = std::chrono::high_resolution_clock::now();
    
    for(int s=0;s<(1<<n);s++)
    {
        if(i==0)
        {

            // if(compatible[(1<<n)-1][s])
            // dp[i][s]=1;
            if(comp((1<<n)-1,s))
            dp[i][s]=1;
        }
        else
        {
            
        for(int s1=0;s1<(1<<n);s1++)
        {
            if(s&(s1))continue;
            // dp[i][s]=(dp[i][s]+dp[i-1][s1]*compatible[s1][s])%MOD;
            dp[i][s]=(dp[i][s]+dp[i-1][s1]*comp(s1,s))%MOD;
        }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    std::chrono::duration<double> duration = end - start;

    // Output the duration
    std::cout << "Time taken: " <<i<<" "<< duration.count() << " seconds" << std::endl;
    }
    
    cout<<dp[m][0]<<endl;

    return 0;
}