#include <iostream>
#include <string>
#include <vector>

using namespace std;
string repeatString(const string& str, int targetLength) {
    int strLength = str.length();
    int repetitions = targetLength / strLength;

 
    string repeatedString="";
    for (int i = 0; i < repetitions; ++i) {
        repeatedString += str;
    }

    // Add the remaining characters if the target length differs by one character
    int remainingLength = targetLength - repetitions * strLength;
    if (remainingLength ==1) {
        return repeatedString ;
    }
    else return "false";

}

// Function to check if a substring starting at index start and ending at index end
// can be formed by repeating a shorter string with at most one different character.
bool isValid(const string& s, int start, int end, vector<vector<bool>>& dp) {
    int n = end - start + 1;

    // If length of substring is 1, it's always valid
    if (n == 1)
        return true;

    // If length of substring is even, check if all characters are the same
    if (n % 2 == 0) {
        char firstChar = s[start];
        for (int i = start + 1; i <= end; i++) {
            if (s[i] != firstChar)
                return false;
        }
        return true;
    }

    // If length of substring is odd, check if all characters are the same except one
    char diffChar = '\0';
    for (int i = start; i <= end; i++) {
        if (s[i] != s[start]) {
            if (diffChar == '\0')
                diffChar = s[i];
            else if (s[i] != diffChar)
                return false;
        }
    }
    return true;
}

// Function to find the shortest substring k that satisfies the condition
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}
vector<int> rabin_karp1(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        long long cur_h_s = (h_s * p_pow[i]) % m; // Hash value of pattern shifted to current position
        if (cur_h == cur_h_s) {
            // Check if substrings differ by just one character
            int diffCount = 0;
            for (int j = 0; j < S; j++) {
                if (s[j] != t[i + j]) {
                    diffCount++;
                    if (diffCount > 1) break;
                }
            }
            cout<<"dif c"<<diffCount<<endl;
            if (diffCount <= 1) occurrences.push_back(i);
        }
    }
    return occurrences;
}
string shortestString(const string& s) {
    int n = s.length();
    for (int len = 1; len <= n / 2; ++len) {
        string k = s.substr(0, len);
        vector<int> res=rabin_karp1(k,s);
        cout<<res.size()<<" "<<k<<endl;
        if(res.size()*k.length()-s.length()<=1)
            return k; 
      
    }
    return s; // If no suitable k found, return the entire string
}

// 2
// 2 1
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        string res=shortestString(s);
        cout<<"out:" <<res<<" " <<res.length()<<endl;
    }
    return 0;
}
