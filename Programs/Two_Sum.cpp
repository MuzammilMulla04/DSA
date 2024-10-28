#include<bits/stdc++.h>
using namespace std;

/* CodingNinjas:
You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements such that they add up to Target.
Note: We cannot use the element at a given index twice.
Follow Up: Try to do this problem in O(N) time complexity. 
 */
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n) {
    unordered_map<int, int> freq;
    vector<pair<int,int>> ans;
    for(int& num: arr)
        freq[num]++;

    for(int& num: arr) {
        int complement= target - num;

        if(freq[complement] > 0) {
            if(num == complement) {
                if(freq[num] >= 2) {
                    ans.push_back({num, complement});
                    freq[num] -= 2;
                }
            } else if(freq[num] >= 1 && freq[complement] >= 1) {
                    ans.push_back({num, complement});
                    freq[num]--;
                    freq[complement]--;
            }
        }
    }

    if(ans.empty())
        ans.push_back({-1, -1});
    return ans;
}

/* LeetCode
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }

            numToIndex[nums[i]] = i;
        }

        return {};
    }
};
