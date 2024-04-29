#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> AL;
vector<vector<int>> up;
int n;
void dfs(int v, int p)
{
    up[v][0] = p;
 
    for (int u : AL[v]) {
        if (u != p)
            dfs(u, v);
    }


}
// Precomputes the binary lifting table
void precompute(int root, int n) {
    dfs(root, -1);
    
    for (int j = 1; j <= ceil(log2(n)); ++j) {
        for (int i = 1; i <= n; ++i) {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

// Finds the kth ancestor of a node u
int kthAncestor(int u, int k) {
    for (int i = 0; i <= ceil(log2(n)); ++i) {
        if (k & (1 << i)) {
            // 6=110?
            // cout<<up[u][i]<<" "<<u<<" "<<i<<endl;
            u = up[u][i];
            if (u == -1) return -1; // Beyond root, return -1
        }
    }
    return u;
}
int main()
{
    int q;
    cin>>n>>q;
    AL.assign(n+1,vector<int>());
    up.assign(n+1,vector<int>(ceil(log2(n))+1,-1));
    
    for(int i=2;i<=n;i++)
    {
        int a;
        cin>>a;
        AL[a].push_back(i);
    }
    precompute(1,n);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<kthAncestor(a,b)<<endl;
    }
    return 0;
}