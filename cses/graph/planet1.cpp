#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
int logk=31;
int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    // AL.assign(n+1,0);
    vector<vector<int>> par(n+1,vector<int>(logk,0));
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        // AL[i]=a;
        par[i][0]=a;// direct parent
    }
    for(int i=1;i<logk;i++)
    {
        for(int j=1;j<=n;j++)
        {
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
    while(q--)
    {
        ll x,k;
        cin>>x>>k;
        for(int i=0;i<logk;i++)
        {
            if(k&(1<<i))
            {
                x=par[x][i];// inverted the direction of edges to make cchilren to ancestors
            }
        }
        cout<<x<<endl;
    }

    // auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    // std::chrono::duration<double> duration = end - start;

    // Output the duration
    // std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
    
}