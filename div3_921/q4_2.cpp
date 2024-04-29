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

        stack<pair<int, int>> st;
        vector<int> nxtGrt(n+1, -1), nextdiff(n+1, -1), prevGrt(n+1, -1), prevdiff(n+1, -1);
        
          for (int i = n ; i >= 1; i--)
        {
            while (!st.empty() and st.top().first != a[i])
                st.pop();
            if (!st.empty())
            {
                nextdiff[i] = st.top().second;
            }
            st.push({a[i], i});
        }
        while (!st.empty())
            st.pop();

        for (int i = 1; i <=n; i++)
        {
            while (!st.empty() && st.top().first != a[i])
                st.pop();
            if (!st.empty())
            {
                prevdiff[i] = st.top().second;
            }
            st.push({a[i], i});
        }
        while (!st.empty())
            st.pop();

 
        cin>>q;
        int l,r;
        while(q--)
        {
            cin>>l>>r;
            int s=l; 
        
            if (nextdiff[l] != -1 and nextdiff[l] <= r)
            {
                cout << l << " " << nextdiff[l]  << endl;
                continue;
            }

            else if (prevdiff[r] != -1 and prevdiff[r] >= l)
            {
                cout << prevdiff[r] << " " << r << endl;
                continue;
            }

      
            cout << -1 << " " << -1 << endl;
        }


    }
   



    return 0;
}

