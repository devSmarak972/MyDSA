#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,t,m;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>n;
        cin>>s;
        int i=0,j=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='B')
            {
                break;
            }
        }
        for( j=n-1;j>=i;j--)
        {
            if(s[j]=='B')
            {
                break;
            }
        }
        cout<<(j-i+1)<<endl;

      
    }


    return 0;
}