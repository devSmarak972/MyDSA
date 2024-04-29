#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
    int x1,y1,x2,y2,x3,y3,x4,y4;

    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    cin>>x4>>y4;
    double d1=min(distance(x1,y1,x2,y2),distance(x3,y3,x2,y2));
    d1=min(d1,distance(x4,y4,x2,y2));
    d1=min(d1,distance(x4,y4,x3,y3));
    d1=min(d1,distance(x1,y1,x3,y3));
    d1=min(d1,distance(x1,y1,x4,y4));
    cout<<(int)(d1*d1)<<endl;
    }
    return 0;
}