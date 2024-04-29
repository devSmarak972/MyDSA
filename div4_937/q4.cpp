#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to generate all binary decimals of a certain length
void generateBinaryDecimals(int index, int length, string& current, vector<int>& results) {
    if (index == length) {
        results.push_back(stoi(current));
        return;
    }
 
    string tmp = current+'0';
    generateBinaryDecimals(index + 1, length, tmp, results);
    string tmp1 = current+'1';
    generateBinaryDecimals(index + 1, length, tmp1, results);
}

// Function to check if a binary decimal divides a certain integer
bool dividesInteger(const int& binaryDecimal, int number) {
    return (number % binaryDecimal == 0);
}
int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        ++count;
    }
    return count;
}
bool canFormNumber(int n, const vector<int>& numbers, int index, int currentProduct) {
    // If the product equals n, return true
    if (currentProduct == n) {
        return true;
    }
    // If the product exceeds n or we've exhausted all numbers, return false
    if (index == numbers.size() || currentProduct > n) {
        return false;
    }
    // Try including the number at the current index
    if (canFormNumber(n, numbers, index + 1, currentProduct * numbers[index])) {
        return true;
    }
    // Try excluding the number at the current index
    if (canFormNumber(n, numbers, index + 1, currentProduct)) {
        return true;
    }
    return false;
}

int main() {
    int t,n;
    cin >> t; // Input number of test cases
    int d=0;
    vector<int> results;

    std::string current="0";
    generateBinaryDecimals(0,5,current,results);
    current="1";
    generateBinaryDecimals(0,5,current,results);
    for (int i = 0; i < t; ++i) {
        cin>>n;
        int found=0;
        // cout<<canFormNumber(n,results,0,1)<<endl;

            int tmp=n;
            for(int j=0;j<results.size();j++)
            {
                if(tmp==results[j])
                {
                    tmp=1;
                    break;
                }
            }


            while(tmp!=1)
            {
                found=0;
                for(int j=0;j<results.size();j++)
                {
                   if(results[j]==0 ||results[j]==1)continue;
                    if(tmp%results[j]==0)
                    {
                    tmp/=results[j];
                    found=1;
                    }
                }
                if(!found)break;
            }
        
        if(tmp==1)cout<<"YES\n";
        else cout<<"NO\n";        
    }

    return 0;
}
