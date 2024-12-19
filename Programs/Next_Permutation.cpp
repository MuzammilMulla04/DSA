#include<bits/stdc++.h>
using namespace std;

/* LeetCode */
class Solution {
    void reverse(vector<int>& arr, int start, int end) {
        while(start < end)
            swap(arr[start++], arr[end--]);
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
    // 1. Find Pivot From Right
        int pivot= -1;
        for(int i= n-1; i>0; i--) {
            if(nums[i-1] < nums[i]) {
                pivot= i-1;
                break;
            }
        }

        // Check for Sorted
        if(pivot == -1) {
            reverse(nums, 0, n-1);
            return;
        }

    // 2. Get Rightmost Greater Num than Pivot
        int swapper= -1;
        for(int i= n-1; i>=0; i--) {
            if(nums[pivot] < nums[i]) {
                swapper= i;
                break;
            }
        }

    // 3. Swap Pivot with it
        swap(nums[pivot], nums[swapper]);

    // 4. Reverse Array from [pivot+1, n)
        reverse(nums, pivot+1, n-1);
    }
};


/* CodingNinjas */
void reverse(vector<int>& arr, int start, int end) {
    while(start < end)
        swap(arr[start++], arr[end--]);
}
vector<int> nextPermutation(vector<int>& permutation, int n) {
// 1. Find Pivot From Right
    int pivot= -1;
    for(int i= n-1; i>0; i--) {
        if(permutation[i-1] < permutation[i]) {
            pivot= i-1;
            break;
        }
    }

    // Check for Sorted
    if(pivot == -1) {
        reverse(permutation, 0, n-1);
        return permutation;
    }

// 2. Get Rightmost Greater Num than Pivot
    int swapper= -1;
    for(int i= n-1; i>=0; i--) {
        if(permutation[pivot] < permutation[i]) {
            swapper= i;
            break;
        }
    }

// 3. Swap Pivot with it
    swap(permutation[pivot], permutation[swapper]);

// 4. Reverse Array from [pivot+1, n)
    reverse(permutation, pivot+1, n-1);

    return permutation;
}


/* GeeksForGeeks */
class Solution {
    void reverse(vector<int>& arr, int start, int end) {
        while(start < end)
            swap(arr[start++], arr[end--]);
    }
public:
    void nextPermutation(vector<int>& arr) {
        int n= arr.size();
    // 1. Find Pivot From Right
        int pivot= -1;
        for(int i= n-1; i>0; i--) {
            if(arr[i-1] < arr[i]) {
                pivot= i-1;
                break;
            }
        }

        // Check for Sorted
        if(pivot == -1) {
            reverse(arr, 0, n-1);
            return;
        }

    // 2. Get Rightmost Greater Num than Pivot
        int swapper= -1;
        for(int i= n-1; i>=0; i--) {
            if(arr[pivot] < arr[i]) {
                swapper= i;
                break;
            }
        }

    // 3. Swap Pivot with it
        swap(arr[pivot], arr[swapper]);

    // 4. Reverse Array from [pivot+1, n)
        reverse(arr, pivot+1, n-1);
    }
};
