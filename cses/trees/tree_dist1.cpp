#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> AL;
int n;
vector<int> distances;
vector<int> firstMax;
vector<int> secondMax;
vector<int> c;
void dfs(int u,int p)
{
    firstMax[u] = 0;
	secondMax[u] = 0;
    for(auto v:AL[u])
    {
        if(v==p)continue;
        dfs(v,u);
        if(firstMax[v]+1>firstMax[u])
        {
            secondMax[u]=firstMax[u];
            firstMax[u]=firstMax[v]+1;
            c[u]=v;
        }
        else if(firstMax[v]+1>secondMax[u]){
            secondMax[u]=firstMax[v]+1;
        }

    }
}
void dfs2(int u,int p)
{
    for(auto v:AL[u])
    {
        if(v==p)continue;
        if(c[u]==v)// the chosen child iwth longest path
        {
        if(firstMax[v]<secondMax[u]+1)//found a path through parternt that is longer if we go up one step
        {
            secondMax[v]=firstMax[v];//shouldnt it be -1? this is the path through v longest from u
            firstMax[v]=secondMax[u]+1;
            c[v]=u;
        }else {
				secondMax[v] = max(secondMax[v], secondMax[u] + 1);// already the chosen path and also the largest, must see if the second largest is from the one chosen by parent or differnt
			}

        }else {
			secondMax[v] = firstMax[v];// this is clealry not the chosen one. so the path down his tree is the scond largest from it
			firstMax[v] = firstMax[u] + 1;
			c[v] = u;
		}
		dfs2(v, u);
    }
}
int main()
{
    cin>>n;
    AL.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);

    }
    // dijkstra(1);
    firstMax.assign(n+1,0);
    secondMax.assign(n+1,0);
    c.assign(n+1,-1);
    dfs(1,-1);
    dfs2(1,-1);
    for(int i=1;i<=n;i++)
    {
        cout<<firstMax[i]<<" ";
    }
    return 0;

}