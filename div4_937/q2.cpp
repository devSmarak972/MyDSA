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
        for(int i=0;i<2*n;i++)
        {
            if(i%2==0)
            {
                if((i/2+1)%2==0)
                {
                for(int j=0;j<n;j+=1)
                {
                    if(j%2==0) cout<<"..";
                    else cout<<"##";
                }  
                }
                else{
                for(int j=0;j<n;j+=1)
                {
                    if(j%2==0) cout<<"##";
                    else cout<<"..";
                }  

                }
            }
            else{
                if(((i-1)/2+1)%2==0)
                {
                for(int j=0;j<n;j+=1)
                {
                    if(j%2==0) cout<<"..";
                    else cout<<"##";
                }  
                }
                else{
                for(int j=0;j<n;j+=1)
                {
                    if(j%2==0) cout<<"##";
                    else cout<<"..";
                }  

                }
            }
                cout<<"\n";
        }
    }
    return 0;
}