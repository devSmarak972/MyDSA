#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> AL;
vector<int> subtree;
int calc(int node)
{
    if(AL[node].size()==0)
    return 1;
    else{
        for(int& n: AL[node])
        {
            subtree[node]+=calc(n);
        }
        return subtree[node]+1;
    }
}
int main()
{
    int n;
    cin>>n;
    AL.assign(n+1,vector<int>(0));
    subtree.assign(n+1,0);
    for(int i=2;i<=n;i++)
    {
        int boss;
        cin>>boss;
        AL[boss].push_back(i);
    }
    calc(1);
    for(int i=1;i<=n;i++)
    cout<< subtree[i]<<" ";
      

    return 0;
}