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
    ll n,m,k,t;
    
    cin>>t;
    while(t--)
    {
    cin>>n;
    string s;
    cin>>s;
    size_t pos = 0;
    string substr="pie";
    int count=0;
    while ((pos = s.find(substr, pos)) != std::string::npos) {
        ++count;
        pos += substr.length();
    }
    pos=0;
    substr="map";
    while ((pos = s.find(substr, pos)) != std::string::npos) {
        ++count;
        pos += substr.length();
    }
    substr="mapie";
    pos=0;
    while ((pos = s.find(substr, pos)) != std::string::npos) {
        --count;
        pos += substr.length();
    }
    cout<<count<<endl;

    }
    return 0;
}