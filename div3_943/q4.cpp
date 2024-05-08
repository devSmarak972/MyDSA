#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Returns length of LCS for X[0..m-1], Y[0..n-1] 
int lcs(string X, string Y, int m, int n) 
{ 
    if (m == 0 || n == 0) 
        return 0; 
    if (X[m - 1] == Y[n - 1]) 
        return 1 + lcs(X, Y, m - 1, n - 1); 
    else
        return max(lcs(X, Y, m, n - 1), 
                   lcs(X, Y, m - 1, n)); 
} 

int main()
{
    int t,n,m;
    cin>>t;
    while (t--)
    {
        ll k,pb,ps,pbo,pso;
        cin>>n>>k>>pbo>>pso;
        vector<ll> p(n+1,-1);
        vector<ll> a(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        set<ll> permb,perms;
       
        int sb=0;
        ll scoreb=0,scores=0;

        ll maxvalb=0,maxvals=0;
        pb=pbo;
        ps=pso;
        while((permb.size()==sb || perms.size()==sb))
        {
            // scoreb+=a[pb];
            // scores+=a[ps];
            permb.insert(pb);
            perms.insert(ps);
            pb=p[pb];
            ps=p[ps];
            maxvalb=max(maxvalb,a[pb]);
            maxvals=max(maxvals,a[ps]);
            // cout<<"pb "<<pb<<endl;
            // cout<<"ps "<<ps<<endl;
            sb++;
            // cout<<"b: "<<scoreb<<endl;
            // cout<<"s: "<<scores<<endl;
        }
        pb=pbo;
        ps=pso;
        // cout<<maxvalb<<" "<<maxvals<<endl;
        ll ab=0,as=0;
        // cout<<"k: "<<k<<endl;
        sb=0;
        permb.clear();
        perms.clear();
        
        while((permb.size()==sb || perms.size()==sb) && sb<k)
        {
            permb.insert(pb);
            perms.insert(ps);

            if(ab<maxvalb)
            {
            ab=a[pb];
            pb=p[pb];

            }
            else ab=maxvalb;

            if(as<maxvals)
            {
            as=a[ps];
            ps=p[ps];
            }
            else 
            {
                as=maxvals;
            }            
            scoreb+=ab;
            scores+=as;
            
            // cout<<"pb "<<pb<<endl;
            // cout<<"ps "<<ps<<endl;
            sb++;
            // cout<<"b: "<<scoreb<<endl;
            // cout<<"s: "<<scores<<endl;
        }
        
        // cout<<sb<<endl;

        if(scoreb>scores)cout<<"Bodya\n";
        else if(scoreb<scores) cout<<"Sasha\n";
        else cout<<"Draw\n";



       
     
    }
    
    return 0;
}