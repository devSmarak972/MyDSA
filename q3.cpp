#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;
int count_points(int n, const std::vector<int>& arr) {
    int points = 0;

    for (int k = 1; k <= sqrt(n); ++k) {
        if (n % k == 0) {
        int i=n/k;

        for(int j=0;j<k;j++)
        {
            for(int m=0;m<n;m++)
            {
                int p;
            for(p=1;p<k;p++)
            {          

            if(arr[j+p*i]%m!= arr[j+p*i-i]%m)
            {

                break;
            }
            }
            if(p==k)
                {
                    points++;
                    break;
                }
            }
        }
        i=k;
        int m;
        for(m=0;m<n;m++)
        {
        for(int j=0;j<k;j++)
        {
                int p;
            for(p=1;p<k;p++)
            {          

            if(arr[j+p*i]%m!= arr[j+p*i-i]%m)
            {

                break;
            }
            }
            if(p!=k)
                {
                    break;
                }
            }
            if(j==k)
            {
                points++;
                break;
            }
            
            

        }
      
        }
        }

    return points;
}

int main() {
    int n = 6;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    int result = count_points(n, arr);
    std::cout <<result << std::endl;
    }



    return 0;
}
