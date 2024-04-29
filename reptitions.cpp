#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    string s;
    cin>>s;
    int maxl=1,curl=1;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
            curl++;
        else
            curl=1;
        maxl=max(maxl,curl);

    }
    cout<<maxl<<endl;
    return 0;
}