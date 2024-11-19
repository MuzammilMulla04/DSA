#include<bits/stdc++.h>
using namespace std;

/* LeetCode */

// 1. Brute Force
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size(), m= nums2.size();
        for(int i=0; i<n; i++) {
            bool isPresent= false;
            for(int j=0; j<m; j++) {
                if(nums1[i] == nums2[j]) {
                    isPresent= true;
                    break;
                }
            }

            if(!isPresent)
                nums1.erase(nums1.begin() + i);
        }
        return nums1;
    }
};

// 2. Use unordered_map
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> intersection;
        for(const int& num: nums1) {
            if(intersection[num] == 0)
                intersection[num]++;
        }
        for(const int& num: nums2) {
            if(intersection[num] > 0)
                intersection[num]++;
        }

        while(!nums1.empty())
            nums1.pop_back();

        for(auto& pair: intersection) {
            if(pair.second > 1)
                nums1.push_back(pair.first);
        }
        return nums1;
    }
};

// 3. Use unordered_set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        for(int& num: nums1)
            set.insert(num);
        for(int& num: nums2)
            set.erase(num);

        vector<int> ans;
        for(int& num: nums1) {
            if(set.find(num) == set.end()) {
                ans.push_back(num);
                set.insert(num);
            }
        }

        return ans;
    }
};

/* CodingNinjas */

void intersection(int *arr1, int *arr2, int n1, int n2) {
    unordered_map<int, int> freq;
    for(int i=0; i<n2; i++)
        freq[arr2[i]]++;
    
    for(int i=0; i<n1; i++) {
        if(freq.count(arr1[i]) == 1 && freq[arr1[i]]>0) {
            freq[arr1[i]]--;
            cout << arr1[i] << " ";
        }
    }
}