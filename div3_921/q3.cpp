#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,t,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        vector<int>a(n,0),b(m,0);
        int i=0,j=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<m;i++)
        {
            cin>>b[i];
        }
         vector<int> count_a(k + 1, 0);
    vector<int> count_b(k + 1, 0);

    for (int num : a) {
        if (num <= k) {
            count_a[num]++;
        }
    }

    for (int num : b) {
        if (num <= k) {
            count_b[num]++;
        }
    }

    int count = 0,ac=0,bc=0,z=0;
    for (int i = 1; i <= k; i++) {

        
        if(count_a[i]>0 && count_b[i]>0)
        {
            // if(ac>bc)bc++;
            // else ac++;
            z++;
            count++;
        }
        else if(count_a[i]>0){
            ac++;

            count++;
            count_a[i]=0;
        }
        else if(count_b[i]>0) 
        {
            bc++;
            count++;
            count_b[i]=0;

        }

    }

    // cout<<ac<<" "<<bc<<" "<<z<<endl;
        int diff=abs(ac-bc);
        if(diff>0 && z>=diff)
        {
            z-=diff;
            ac=bc;

        }
        if(count==k && ac==bc && z%2==0 )cout<<"YES\n";
        else cout<<"NO\n";
      
    }


    return 0;
}