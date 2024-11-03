#include<bits/stdc++.h>
using namespace std;

// LeetCode
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int start= 0, end= n-1;
        while(start<end) {
            int mid= start+(end-start)/2;

            if(nums[mid] < nums[mid+1])
                start= mid+1;
            else
                end= mid;
        }
        return start;
    }
};

// CodingNinjas
int findPeakElement(vector<int>& arr) {
    int mid= -1;
    int start= 0, end= arr.size() - 1;
    while(start <= end) {
        mid= start + (end-start)/2;

        if(arr[mid-1] >= arr[mid])
            end= mid-1;
        else if(arr[mid] <= arr[mid+1])
            start= mid+1;
        else
            return mid;
    }
    return mid;
}
