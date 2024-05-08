#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<char> s(n);
        ll c=0;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            if(s[i]=='U')c++;
        }
        if((c%2)==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;



    }
    return 0;
}