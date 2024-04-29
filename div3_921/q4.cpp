#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,t,m,k;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>n;
        vector<int>a(n+1,0);
        for( int i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        cin>>q;
        int l,r;
        while(q--)
        {
            cin>>l>>r;
            int s=l+1; 
            while(s<=r && a[s]==a[s-1])
            {
                s++;
            }
            if(s>r)
            {
                cout<<(-1)<<" "<<(-1)<<endl;
            }
            else cout<<s-1 <<" "<<s<<endl;
        }
                    cout<<endl;


    }
   



    return 0;
}