#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<int> dx={1,-1,0,0};
vector<int> dy={0,0,-1,1};
    int n,m;
struct point{
    int x;
    int y;
    point(int x_,int y_):x(x_),y(y_){};
};
bool isBoundary(int x,int y)
{
    if(x==0)return true;
    if(x==m-1)return true;
    if(y==0)return true;
    if(y==n-1)return true;

    return false;
}
bool isInGrid(int x,int y)
{
    if(x>=m)return false;
    if(y>=n)return false;
    if(x<0)return false;
    if(y<0)return false;

    return true;
}
vector<point> dest;


void dijkstra(point &src)
{
    priority_queue<pair<int,point>,vector<pair<int,point>>> pq;
    vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
    distance[src.y][src.x]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        point u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(int i=0;i<4;i++)
        {
            point pt(u.x+dx[i],u.y+dy[i]);
            if(isInGrid(pt.x,pt.y) && grid[pt.x][pt.y]=='.' && d+1<distance[pt.y][pt.y])
            {
                    distance[pt.y][pt.y]=d+1;
                    pq.push({d+1,pt});
            }
        }
        
    }

}
int main()
{
    cin>>n>>m;
    grid.assign(n,vector<char>(m,'.'));

    struct point src(0,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A')
            src=point(i,j);

            if(isBoundary(i,j) && grid[i][j]=='.')dest.push_back(point(i,j));
        }

    }


    return 0;
}