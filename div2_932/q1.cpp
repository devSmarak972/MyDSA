#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string rev(string &str)
{
    string revs="";
    for (int i = str.length() - 1; i >= 0; i--) {
        revs += str[i];
    }
    return revs;

}
int main()
{
    ll n,m,t;
    string s;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>s;
    string str=rev(s)+s;
     if(str.compare(s)<0)
     cout<<str;
     else 
     cout<<s;
     cout<<endl;


    }
}