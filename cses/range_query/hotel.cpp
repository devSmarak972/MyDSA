#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<hotel> vh;
struct hotel{
    int index;
    int value;
};
vh arr,tree;

hotel buildSegmentTree(int node, int start, int end)
{
    if(start==end)
    {
        tree[node]=arr[start];
        return tree[node];
    }
    int mid=(start+end)/2;
    hotel left=buildSegmentTree(2*node+1,start,mid);
    hotel right=buildSegmentTree(2*node+2,mid+1,end);
    tree[node]= left.value<right.value?right:left;

    return tree[node]; 
} 

int query(int node,int start,int end,int qStart,int qEnd,int val)
{
    if(qStart>end ||qEnd<start)
    return INT_MAX;

    if(qStart<=start && qEnd>=end) return tree[node].value;
    int mid=(start+end)/2;
    int left=query(2*node+1,start,mid,qStart,qEnd);
    int right=query(2*node+2,mid+1,end,qStart,qEnd);
    if(left>=val)
    return max(left,right);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<ll> h(n),r(m);
    for(int i=0;i<n;i++) 
    {
        cin>>h[i];
        arr.push_back((struct hotel){i,h[i]});
        cout<<arr[i].value<<endl;

    }
    for(int i=0;i<m;i++) cin>>r[i];
    int height = (int)(ceil(log2(m)));
        // Size of the segment tree is 2 * 2^height - 1
    int treeSize = 2 * (int)(pow(2, height)) - 1;
    tree.resize(treeSize, 0);

        // Build the segment tree
    buildSegmentTree(0, 0, m - 1);

    
    for(int i=0;i<m;i++)
    {
        
    }
    return 0;
}