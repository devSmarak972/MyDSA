#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int a,b,c,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        if(a<b && b<c)cout<<"STAIR\n";
        else if(a<b && b>c)cout<<"PEAK\n";
        else cout<<"NONE\n";

    }
    return 0;
}