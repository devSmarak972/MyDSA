#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<char>>grid;
vector<vector<bool>>vis;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

bool isValid(int y,int x)
{
    if(y<0)return false;
    if(x<0)return false;
    if(y>=n)return false;
    if(x>=m)return false;
    if(grid[y][x]=='#')return false;
    return true;
}
void dfs(int y,int x)
{
 
    vis[y][x]=true;
    for(int i=0;i<4;i++)
    {

        int newY=y+dy[i],newX=x+dx[i];
        if(isValid(newY,newX))
        {

            if(!vis[newY][newX])
            {
                dfs(newY,newX);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    grid.assign(n,vector<char>(m));
    vis.assign(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            vis[i][j]=false;
        }

    }

    int count=0;
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='.' && !vis[i][j])
            {

                dfs(i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}