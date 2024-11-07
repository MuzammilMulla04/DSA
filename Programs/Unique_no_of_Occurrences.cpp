#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int& num: arr)
            freq[num]++;
        
        unordered_set<int> set;
        for(auto& pair: freq) {
            if(set.find(pair.second) != set.end())
                return false;
            set.insert(pair.second);
        }
        
        return true;
    }
};