#include<bits/stdc++.h>
using namespace std;

/* Coding Ninjas */
// Use Sorting [O(nlog(n)), O(n)]
int findDuplicate(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());
    for(int i=1; i<n; i++) {
        if(arr[i-1] == arr[i])
            return arr[i];
    }
    return -1;
}

// Use vectors [O(n), O(n)]
int findDuplicate(vector<int>& arr, int n) {
    vector<int> freq(n, 0);
    for(const int& num: arr)
        freq[num]++;
    
    for(int i=0; i<n; i++) {
        if(freq[i] > 1)
            return i;
    }
    return -1;
}

// Use unordered_map [O(n), O(n)]
int findDuplicate(vector<int>& arr, int n) {
    unordered_map<int, int> freq;
    for(const int& num: arr)
        freq[num]++;
    
    for(const pair<int, int>& pair: freq) {
        if(pair.second > 1)
            return pair.first;
    }
    return -1;
}

// Floyd's Cycle Detection [O(n), O(1)]
int findDuplicate(vector<int>& arr, int n) {
    int slow= arr[0], fast= arr[arr[0]];
    while(slow != fast) {
        slow= arr[slow];
        fast= arr[arr[fast]];
    }
    fast= 0;
    while(slow != fast) {
        slow= arr[slow];
        fast= arr[fast];
    }
    return slow;
}

/* LeetCode */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow= nums[0], fast= nums[nums[0]];
        while(slow != fast) {
            slow= nums[slow];
            fast= nums[nums[fast]];
        }
        fast= 0;
        while(slow != fast) {
            slow= nums[slow];
            fast= nums[fast];
        }
        return slow;
    }
};

