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
        ll a,b;
        cin>>a>>b;
        ll count=0;
        set<int> s;
    
        while(a!=b && s.size()==count)
        {
        a=par[a][0];// inverted the direction of edges to make cchilren to ancestors
        s.insert(a);
        count++;
        }
        if(s.size()!=count)
        cout<<-1<<endl;
        else
        cout<<count<<endl;
    }
    //GIVES TLE-----------------------------

    // auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration
    // std::chrono::duration<double> duration = end - start;

    // Output the duration
    // std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
    
}