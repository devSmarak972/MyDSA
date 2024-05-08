#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string rev(string &str)
{
    string revs="";
    for (int i = str.length() - 1; i >= 0; i--) {
        revs += str[i];
    }
    return revs;

}
int main()
{
    ll n,m,k,t,d;
    
    cin>>t;
    while(t--)
    {
    cin>>n>>m>>k>>d;
    vector<vector<int>> a(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    vector<int> c(n);
    for(int i=0;i<n;i++)
    {
        std::vector<int> distances(m, INT_MAX); // Initialize distances to infinity
    distances[0] = 0; // Distance from source to itself is 0
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({a[i][0],0}); // Push source vertex to priority queue
    
    while (!pq.empty()) {
        int dist = pq.top().first; // Extract the distance of the vertex with the minimum distance
        int u = pq.top().second;         
        pq.pop();
        
        // Iterate through all adjacent vertices of u
        for (int j=1;j<=d+1;j++) {
            int v = u+j;
            if(v>m-1)break;
            int weight = a[i][v];
            
            // Relaxation step
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({v, distances[v]});
            }
        }
    }
    c[i]=distances[m-1];
    cout<<c[i]<<" c "<<endl;
    }
     int windowSum = 0;
    int minSum = std::numeric_limits<int>::max();

    // Calculate the sum of the first k elements
    for (int i = 0; i < k; ++i) {
        windowSum += c[i];
    }
    minSum = std::min(minSum, windowSum);

    // Slide the window to the right and update minSum accordingly
    for (int i = k; i < n; ++i) {
        windowSum += c[i] - c[i - k];
        minSum = std::min(minSum, windowSum);
    }
    cout<<minSum<<endl;

    }
    return 0;
}