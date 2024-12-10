#include<bits/stdc++.h>
using namespace std;

/* LeetCode */
class Solution {
    void reverse(vector<int>& nums, int start, int end) {
        while(start < end)
            swap(nums[start++], nums[end--]);
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k %= n;
        k= n-k;

        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
        reverse(nums, 0, n-1);
    }
};


/* CodingNinjas */
vector<int> rotateArray(vector<int>arr, int k) {
    int n=arr.size();
    vector<int> temp(n);

    for(int i=0; i<n; i++) {
        temp[(i+(n-k))%n]= arr[i];
    }
    arr= temp;
    return arr;
}


/* GeeksForGeeks */
class Solution {
    void reverse(vector<int>& arr, int start, int end) {
        while(start < end)
            swap(arr[start++], arr[end--]);
    }
public:
    void rotateArr(vector<int>& arr, int d) {
        int n= arr.size();
        d %= n;
        
        reverse(arr, 0, d-1);
        reverse(arr, d, n-1);
        reverse(arr, 0, n-1);
    }
};