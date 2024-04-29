#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        ll a,b,r,x;
        cin>>a>>b>>r;
        bitset<32> a_bin(max(a,b));
        bitset<32> b_bin(min(a,b));
        bitset<32> x_bin(r);
        ll pmin=max(a,b)-min(a,b),result,val;
        for(int i=(int)log2(max(a,b));i>=0;i--)
        {
            if(a_bin.to_ullong()<b_bin.to_ullong())
            {
                swap(a_bin,b_bin);
                swap(a,b);
            }
            if(a_bin[i]==b_bin[i])
            {
                continue;
            }
            x_bin[i]=a_bin[i];
            result=x_bin.to_ullong();
            if(result<r )
            {
            val=abs((a^result)-(b^result));
            if(val<pmin)pmin=val;
            }
            else
            {
            x_bin[i]=0;
            continue;
            }
            

        }
        cout<<(a^result)<<" "<<(b^result)<<" "<<result<<" "<<pmin<<endl;


    }
    return 0;
}