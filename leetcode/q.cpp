#include <bits/stdc++.h>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted=nums;

        vector<int> indices;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
        }
        sort(sorted.begin(),sorted.end());
        int i=0;
        while(i<sorted.size()-1)
        {
            auto it=lower_bound(sorted.begin()+i+1,sorted.end(),target-sorted[i]);
        if(*it==(target-sorted[i]))
        {
            if(sorted[i]==*it)
            {
            indices.push_back(m[sorted[i]][0]);
            indices.push_back(m[sorted[i]][1]);
            }
            else
            {
            indices.push_back(m[sorted[i]][0]);
            indices.push_back(m[*it][0]);

            }
            break;
        }
        i++;
        }
        return indices;

    }

int main()
{
    vector<int> a={3,3,2};
    vector<int> ind=twoSum(a,6);
    cout<<ind[0]<<" "<<ind[1]<<endl;
}