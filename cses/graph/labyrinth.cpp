#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<char>>grid;
vector<vector<bool>>vis;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char dir[4]={'L','R','U','D'};
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
    // if(grid[y][x]=='B')return true;
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
struct Cell{
    int y,x;
    Cell(int y_,int x_):y(y_),x(x_){};

    
    };

struct comp
{
    constexpr bool operator()(
        pair<int, Cell> const& a,
        pair<int, Cell> const& b)
        const noexcept
    {
        return a.first > b.first;
    }
};
char getDir(int y,int x, int ny,int nx)
{
    for(int i=0;i<4;i++)
    {
        if(y==ny+dy[i] && x==nx+dx[i])
        {
            return dir[i];
        }
    }
    return '_';
}
void dijkstra(Cell source,Cell dest)
{
    // auto comp=[](const pair<int,Cell> &a,const pair<int,Cell> &b){return a.first>b.first;};
    priority_queue<pair<int,Cell> , vector<pair<int,Cell>>, comp > pq;
    vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
    vector<vector<Cell>> parent(n, vector<Cell>(m, Cell(-1, -1)));

    distance[source.y][source.x]=0;
    pq.push({0,source});
    while(!pq.empty())
    {
            int dist=pq.top().first;
            Cell current=pq.top().second;
            pq.pop();
            if(current.y==dest.y && current.x==dest.x)break;

            for(int i=0;i<4;i++)
            {
                int newY=current.y+dy[i];
                int newX=current.x+dx[i];
                if(isValid(newY,newX) && dist+1<distance[newY][newX])
                {
                    distance[newY][newX]=dist+1;
                    parent[newY][newX] = current;
                    pq.push({distance[newY][newX],Cell(newY,newX)});
                }
            }
    }
    cout<<(distance[dest.y][dest.x]!=INT_MAX?"YES":"NO")<<endl;
    cout<<distance[dest.y][dest.x]<<endl;
    stack<Cell> path;
    Cell current=dest;
    while(current.y!=-1 && current.x!=-1)
    {
        path.push(current);
        current=parent[current.y][current.x];
    }
    Cell prev=path.top();
    path.pop();
    while(!path.empty())
    {
        cout<<getDir(path.top().y,path.top().x,prev.y,prev.x);
        prev=path.top();
        path.pop();
    }
    cout<<endl;
}


int main()
{
    cin>>n>>m;
    grid.assign(n,vector<char>(m));
    vis.assign(n,vector<bool>(m,false));
    Cell source(-1,-1),dest(-1,-1);
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A') source=Cell(i,j);
            if(grid[i][j]=='B') dest=Cell(i,j);
            vis[i][j]=false;
        }

    }

    dijkstra(source,dest);
    return 0;
}