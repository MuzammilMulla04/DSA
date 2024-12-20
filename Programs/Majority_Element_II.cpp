#include<bits/stdc++.h>
using namespace std;

/* LeetCode */
// 1. Use unordered_map
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& num: nums)
            freq[num]++;
        
        int n= nums.size();
        vector<int> ans;
        for(int& num: nums) {
            if(freq[num] > n/3) {
                ans.push_back(num);
                freq.erase(num);
            }
                
        }

        return ans;
    }
};

// 2. Boyer-Moore’s Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1= -1, ele2= -1;
        int cnt1= 0, cnt2= 0;

        for(int& num: nums) {
            if(num == ele1) {
                cnt1++;
            } else if(num == ele2) {
                cnt2++;
            } else if(cnt1 == 0) {
                ele1= num;
                cnt1= 1;
            } else if(cnt2 == 0) {
                ele2= num;
                cnt2= 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1= 0, cnt2= 0;
        for(int& num: nums) {
            cnt1 += num == ele1;
            cnt2 += num == ele2;
        }

        int n= nums.size();
        vector<int> ans;
        if(cnt1 > n/3)
            ans.push_back(ele1);
        if(cnt2 > n/3 && ele1 != ele2)
            ans.push_back(ele2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};


/* CodingNinjas */
// 2. Boyer-Moore’s Voting Algorithm
vector<int> majorityElementII(vector<int>& arr) {
    int ele1= -1, ele2= -1;
    int cnt1= 0, cnt2= 0;

    for(int& num: arr) {
        if(num == ele1) {
            cnt1++;
        } else if(num == ele2) {
            cnt2++;
        } else if(cnt1 == 0) {
            ele1= num;
            cnt1= 1;
        } else if(cnt2 == 0) {
            ele2= num;
            cnt2= 1;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1= 0, cnt2= 0;
    for(int& num: arr) {
        cnt1 += num == ele1;
        cnt2 += num == ele2;
    }

    int n= arr.size();
    vector<int> ans;
    if(cnt1 > n/3)
        ans.push_back(ele1);
    if(cnt2 > n/3 && ele1 != ele2)
        ans.push_back(ele2);

    sort(ans.begin(), ans.end());
    return ans;
}


/* GeeksForGeeks */
// 2. Boyer-Moore’s Voting Algorithm
class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int ele1= -1, ele2= -1;
        int cnt1= 0, cnt2= 0;

        for(int& num: arr) {
            if(num == ele1) {
                cnt1++;
            } else if(num == ele2) {
                cnt2++;
            } else if(cnt1 == 0) {
                ele1= num;
                cnt1= 1;
            } else if(cnt2 == 0) {
                ele2= num;
                cnt2= 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1= 0, cnt2= 0;
        for(int& num: arr) {
            cnt1 += num == ele1;
            cnt2 += num == ele2;
        }

        int n= arr.size();
        vector<int> ans;
        if(cnt1 > n/3)
            ans.push_back(ele1);
        if(cnt2 > n/3 && ele1 != ele2)
            ans.push_back(ele2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
