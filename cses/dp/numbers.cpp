#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a==b && a==0)
    {
        cout<<1<<endl;
        return 0;
    }
    vector<int> veca,vecb;
   ll d=b;
  set<int> digs;
  ll cnt=0;
  int prev=-1;
  int flag=1;
   while(d>0)
   {
    vecb.push_back(d%10);
    if(prev==(d%10))flag=0;
    prev=d%10;
    // digs.insert(d%10);
    d/=10;
   }
   if(flag)cnt++;
   flag=1;
//    if(digs.size()==vecb.size())cnt++;
    reverse(vecb.begin(),vecb.end());
    ll bs=vecb.size();
  d=a;
  digs.clear();
   prev=-1;
   while(d>0)
   {
    veca.push_back(d%10);
    if(prev==(d%10))flag=0;
    prev=d%10;
    d/=10;
   }
   if(flag && a!=b)cnt++;
    //   if(digs.size()==veca.size() && a!=b)cnt++;

   bs=bs-veca.size();
   ll cb=bs;
   while(cb--)
   {
    veca.push_back(0);
   }
    reverse(veca.begin(),veca.end());
    // cout<<vecb.size()<<endl;
    ll dp[20][10][2][2]={0};

    for(int i=0;i<vecb.size();i++)
    {
        for(int j=0;j<10;j++)
        {
            if(i==0 && vecb[i]<j)break;
            if(i==0 && veca[i]>j)continue;
            if(i==0)
            {
                if(j>veca[0])
                {
                    if(j==vecb[0])
                        dp[i][j][1][0]=1;
                    else if(j<vecb[0])
                    dp[i][j][1][1]=1;
                }
                else
                {
                    if(j==vecb[0])
                    dp[i][j][0][0]=1;
                    else if(j<vecb[0])
                    dp[i][j][0][1]=1;
                }
            }
            else{
            // if(i==1 && veca[i]>j)continue;
            for(int k=0;k<10;k++)
            {
            
                int p=0;
                if(k!=j || (k==0 && i<bs))
                {  
                if(veca[i]<j)
                {
                if(j==vecb[i])
                dp[i][j][1][0]+=dp[i-1][k][0][0];
                else if(j<vecb[i])
                dp[i][j][1][1]+=dp[i-1][k][0][0];
                
                dp[i][j][1][1]+=dp[i-1][k][0][1];
                // cout<<"added: "<<dp[i][j][1][1]<<endl;
                }
                else if(veca[i]==j)
                {
                if(j==vecb[i] )
                dp[i][j][0][0]+=dp[i-1][k][0][0];
                else if(j<vecb[i])
                dp[i][j][0][1]+=dp[i-1][k][0][0];

                dp[i][j][0][1]+=dp[i-1][k][0][1];
                }
                if(j==vecb[i])
                dp[i][j][1][0]+=dp[i-1][k][1][0];
                else if(j<vecb[i])
                dp[i][j][1][1]+=dp[i-1][k][1][0];
                                    // 0 2 1 0
                dp[i][j][1][1]+=dp[i-1][k][1][1];

                if(i==10)
                cout<<j<<" "<<i<<" "<<veca[i]<<" "<<k<<" "<<dp[i][j][1][1]<<" "<<dp[i-1][k][0][1]<<" "<<dp[i-1][k][1][0]<<" "<<dp[i-1][k][1][1]<< " "<<dp[i-1][k][0][0]<<endl;
    //   0 1/
                }
            }
            }
        }
    }
    ll sum=0;
    
    for(int j=0;j<10;j++)
    {
    sum+=dp[vecb.size()-1][j][1][1];
    // cout<<j<<" "<<dp[vecb.size()-1][j][1][1]<<endl;
    }
    
    
    cout<<sum+cnt<<endl;
    return 0;
}