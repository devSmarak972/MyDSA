#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int findNFromGP(int sum, int firstTerm, int commonRatio) {
    double n = log((double)(sum * (commonRatio - 1) / firstTerm) + 1) / log(commonRatio);
    return floor(n); // Round up to the nearest integer
}
int sumOfGP(int firstTerm, int commonRatio, int numberOfTerms) {
    // If commonRatio is 1, the sum is simply firstTerm * numberOfTerms
    if (commonRatio == 1) {
        return firstTerm * numberOfTerms;
    }

    // Compute the sum using the formula
    int sum = firstTerm * (pow(commonRatio, numberOfTerms) - 1) / (commonRatio - 1);
    return sum;
}

int main()
{
    int a,b,c,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        // 4,2,
        // 2
        // 2 2
        // 2 1 1 1

        // 2*k <a
        int n=findNFromGP(a,1,2);
        int k=sumOfGP(1,2,n);
        cout<<"first"<<n<<" "<<k<<endl;
        if((k-a)!=0)
        n+=(int)b/(k-a);
        else{
            n+=b;
        }
        cout<<n<<endl;

// 1+2+4+
// 20+21+22 <a;
// b/(2*n-a), 




    }
    return 0;
}