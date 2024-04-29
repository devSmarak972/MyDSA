#include <bits/stdc++.h>
using namespace std;
int main()
{
    long int n;
    cin>>n;
    vector<bool> a(n,false);

    for(int i=0;i<n-1;i++)
    {
        int tmp;
        cin>>tmp;
        a[tmp-1]=true;
    }
    int i=0;
    while(a[i]) i++;
    cout<<i+1<<endl;
    return 0;
}