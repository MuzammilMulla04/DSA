#include <bits/stdc++.h>
using namespace std;

/* CodingNinjas */
vector<int> findDuplicates(vector<int>& arr, int n) {
    unordered_map<int, int> freq;
    for(const int& num: arr)
        freq[num]++;

    vector<int> ans;    
    for(const pair<int, int>& pair: freq) {
        if(pair.second > 1)
            ans.push_back(pair.first);
    }
    return ans;
}

/* LeetCode */
// Use unordered_map
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(const int& num: nums)
            freq[num]++;

        vector<int> ans;    
        for(const pair<int, int>& pair: freq) {
            if(pair.second > 1)
                ans.push_back(pair.first);
        }
        return ans;
    }
};

// Use Negative Indexing
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++) {
            int index= abs(nums[i]) - 1;
            
            if(nums[index] < 0)
                ans.push_back(index+1);
            else
                nums[index]= -nums[index];
        }
        return ans;
    }
};