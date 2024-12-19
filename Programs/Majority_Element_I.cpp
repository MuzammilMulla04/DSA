#include<bits/stdc++.h>
using namespace std;

/* LeetCode */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& num: nums)
            freq[num]++;
        
        int n= nums.size();
        for(int& num: nums) {
            if(freq[num] > n/2)
                return num;
        }

        return -1;
    }
};


/* CodingNinjas */
int findMajorityElement(int arr[], int n) {
	unordered_map<int, int> freq;

	for(int i= 0; i<n; i++)
		freq[arr[i]]++;
	
	for(int i= 0; i<n; i++) {
		if(freq[arr[i]] > n/2)
			return arr[i];
	}

	return -1;
}

