#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, r;
        cin >> a >> b >> r;

        bitset<64> aBits(a);
        bitset<64> bBits(b);

        for (int i = 62; i >= 0; i--)
        {
            a=aBits.to_ullong();
            b=bBits.to_ullong();
            if(a > b)
            {
                swap(a, b);
                swap(aBits,bBits);
            }
            if (aBits[i] != bBits[i])
            {
                if (bBits[i] == 1 && aBits[i] == 0 && abs(a - b) > abs((1ll << (i + 1))))
                {
                    if ((1ll << i) > r)
                        continue;
                    r -= (1ll << i);
                    aBits.flip(i);
                    bBits.flip(i);
                    
                }
            }
        }
        a=aBits.to_ullong();
        b=bBits.to_ullong();

        cout << abs(a-b) << endl;
    }
    return 0;
}