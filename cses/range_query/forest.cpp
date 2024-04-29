#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,q;
    cin>>n>>q;
    int grid[n+1][n+1];
    int preSum[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            
            preSum[i][j]=0;
        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char tmp;
            cin>>tmp;
            grid[i][j]=(tmp=='*'?1:0);
            // cout<<grid[i][j]<<" ";
            preSum[i][j]=0;
        }
        // cout<<endl;

    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
   
        if(i>=2)preSum[i][j]+=preSum[i-1][j];
        if(j>=2)preSum[i][j]+=preSum[i][j-1];
        if(i>=2 && j>=2)preSum[i][j]-=preSum[i-1][j-1];
        preSum[i][j]+=grid[i][j];
        // printf("%d ",preSum[i][j]);
        }
        // printf("\n");
    }

    for(int i=0;i<q;i++)
    {
        int x1,x2,y1,y2;
        cin>>y1>>x1>>y2>>x2;
        int ans=0;
        // cornes must be opposite. 2 possibiliteis.
        // top left(lower x, lower y), bottom right(higher x,higer y)
        // top right(higher x, lower y), bottom left(lower x,higher y)
        // if(y1>y2 && x1>x2)
        // {
        //     ans=preSum[y1][x1]+preSum[y2][x2]-preSum[y2][x1]-preSum[y1][x2];
        // }
        // else if(y1<y2 && x1<x2)
        // {
        //     ans=preSum[y2][x2]+preSum[y1][x1]-preSum[y1][x2]-preSum[y2][x1];
        // }
        // else if(y1>y2 && x1<x2)
        // {
        //    ans=preSum[y1][x1]+preSum[y2][x2]-preSum[y2][x1]-preSum[y1][x2];

        // }
        int ymax=max(y1,y2),xmax=max(x1,x2),ymin=min(y1,y2),xmin=min(x1,x2);
        // printf("here %d %d %d %d\n",ymax,ymin,xmax,xmin);
        // printf("%d %d %d %d \n",preSum[ymax][xmax],preSum[ymin-1][xmin-1],preSum[ymax][xmin-1],preSum[ymin-1][xmax]);
        ans=preSum[ymax][xmax]+preSum[ymin-1][xmin-1]-preSum[ymax][xmin-1]-preSum[ymin-1][xmax];   
        cout<<ans<<endl;     
    }
    

    return 0;
}