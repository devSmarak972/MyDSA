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
        vector<int> nxtGrt(n+1, -1), nxtSm(n+1, -1), prevGrt(n+1, -1), prevSm(n+1, -1);
        
          for (int i = n ; i >= 1; i--)
        {
            while (!st.empty() and st.top().first >= a[i])
                st.pop();
            if (!st.empty())
            {
                nxtSm[i] = st.top().second;
            }
            st.push({a[i], i});
        }
        while (!st.empty())
            st.pop();

        for (int i = 1; i <=n; i++)
        {
            while (!st.empty() && st.top().first >= a[i])
                st.pop();
            if (!st.empty())
            {
                prevSm[i] = st.top().second;
            }
            st.push({a[i], i});
        }
        while (!st.empty())
            st.pop();

 
        for (int i = n ; i >= 1; i--)
        {
            while (!st.empty() and st.top().first <= a[i])
                st.pop();
            if (!st.empty())
            {
                nxtGrt[i] = st.top().second;
            }
            st.push({a[i], i});
        }
          while (!st.empty())
            st.pop();
        for (int i = 1; i <=n; i++)
        {
            while (!st.empty() and st.top().first <= a[i])
                st.pop();
            if (!st.empty())
            {
                prevGrt[i] = st.top().second;
            }
            st.push({a[i], i});
        }
   

        cin>>q;
        int l,r;
        while(q--)
        {
            cin>>l>>r;
            int s=l; 
        
            if (nxtGrt[l] != -1 and nxtGrt[l] <= r)
            {
                cout << l  << " " << nxtGrt[l]  << endl;
                continue;
            }
            else if (nxtSm[l] != -1 and nxtSm[l] <= r)
            {
                cout << l << " " << nxtSm[l]  << endl;
                continue;
            }

            else if (prevGrt[r] != -1 and prevGrt[r] >= l)
            {
                cout << prevGrt[r]  << " " << r  << endl;
                continue;
            }

            else if (prevSm[r] != -1 and prevSm[r] >= l)
            {
                cout << prevSm[r] << " " << r << endl;
                continue;
            }

            cout << -1 << " " << -1 << endl;
        }


    }
   



    return 0;
}

