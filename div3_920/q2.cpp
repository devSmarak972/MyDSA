#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s,f;
        cin>>s;
        cin>>f;
        int cs=0,cf=0,count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1' && f[i]=='1' )
            {
                s[i]='0';
                f[i]='0';
            }
 
            if(s[i]=='1' )
            cs++;
            if(f[i]=='1')
            cf++;
        }

        cout<<cf+ (cs>cf?cs-cf:0)<<endl;






    }
    return 0;
}
