// We use the classical reduction of the LCA problem to the RMQ problem. We traverse all nodes of the tree with DFS and keep an array with all visited nodes and the heights of these nodes. The LCA of two nodes
// u and v is the node between the occurrences of u and v 
//  in the tour, that has the smallest height.
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> AL;
vector<vector<int>> ST;
vector<int> depth;
vector<int> foccur;
vector<int> euler_tour;
void dfs(int node,int parent, int dep)
{
    depth.push_back(dep);
    euler_tour.push_back(node);
    foccur[node]=euler_tour.size()-1;
    cout<<"fouccur " <<node<<" "<<foccur[node]<<endl;
    for(int child:AL[node])
    {
        if(child!=parent)
        {
            dfs(child,node,dep+1);
            euler_tour.push_back(child);
            depth.push_back(dep);

        }
    }
}
void buildRMQ()
{
    int len=euler_tour.size();
    int log_n=log2(len)+1;
    ST.assign(len,vector<int>(log_n,-1));
    for(int i=0;i<len;i++)
    {
        ST[i][0]=i;
    }
    for(int j=1;(1<<j)<=len;j++)
    {
        for(int i=0;i+(1<<j)-1<len;i++)
        {
            if(depth[ST[i][j-1]]<depth[ST[i+(1<<(j-1))][j-1]])
            ST[i][j]=ST[i][j-1];
            else
            ST[i][j]=ST[i+(1<<(j-1))][j-1];
        }
    
    }

}



// Function to perform RMQ query
int queryRMQ(int l, int r) {
    int k = log2(r - l + 1);
    cout<<" "<<r - (1 << k) + 1<<" "<<l<<" "<<k<<endl;
    if (depth[ST[l][k]] < depth[ST[r - (1 << k) + 1][k]])
        return ST[l][k];
    else
        return ST[r - (1 << k) + 1][k];
}
// Function to find LCA using RMQ
int LCA(int u, int v) {
    int l = foccur[u];
    int r = foccur[v];
    cout<<"uv: "<<u<<" "<<v<<endl;
    if (l > r) swap(l, r);
    
    cout<<"here: "<<queryRMQ(l,r)<<endl;;
    return euler_tour[queryRMQ(l, r)];
}

int main()
{
    int q;
    cin>>n>>q;
    AL.assign(n+1,vector<int>());
    foccur.assign(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        AL[a].push_back(i);
    }
    dfs(1, -1, 0);
// Build Sparse Table for RMQ
    buildRMQ();
while (q--) {
        int u, v; // Nodes for which LCA is to be found
        cin >> u >> v;
        cout << LCA(u,v)<<endl;
    }
    return 0;
}