#include<bits/stdc++.h>
using namespace std;

/* LeetCode */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        
        for(int i=0, j=0; j<n; j++) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

/* CodingNinjas */
void pushZerosAtEnd(vector<int> &arr) {
    for(int i=0, j=0; j<arr.size(); j++) {
        if(arr[j] != 0) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

/* GeeksForGeeks */
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n= arr.size();
        
        for(int i=0, j=0; j<n; j++) {
            if(arr[j] != 0) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
    }
};