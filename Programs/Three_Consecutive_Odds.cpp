#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCount= 0;
        for(const int& num: arr) {
            oddCount= num & 1? oddCount + 1: 0;
            if(oddCount == 3) return true;
        }
        return false;
    }
};