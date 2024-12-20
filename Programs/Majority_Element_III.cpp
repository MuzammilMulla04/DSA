#include<bits/stdc++.h>
using namespace std;

/* CodingNinjas */
vector<int> countTheNumber(vector<int> &nums, int n, int k) {
    unordered_map<int, int> freq;
    for(int& num: nums)
        freq[num]++;
    
    vector<int> ans;
    for(int& num: nums) {
        if(freq[num] >= n/k) {
            ans.push_back(num);
            freq.erase(num);
        }
            
    }

    return ans;
}
