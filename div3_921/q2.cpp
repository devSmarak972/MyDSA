#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,t,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>a(n,0);
        vector<int> str(26,0);
        int i=0,j=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            
            for(j=0;j<26;j++)
            {
                if(str[j]==a[i])
                {
                cout<<(char)(j+'a');
                str[j]++;
                break;
                }
            }

        }
        cout<<endl;

      
    }


    return 0;
}