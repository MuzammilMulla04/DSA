#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> freq;
        for(const int& digit: digits) ++freq[digit];

        vector<int> ans;

        for(int num= 100; num < 1000; ++num) {
            int hundreds= num / 100;
            int tens= (num / 10) % 10;
            int units= num % 10;

            if(units % 2 != 0) continue;

            --freq[hundreds];
            if(freq[hundreds] >= 0) {
                --freq[tens];

                if(freq[tens] >= 0) {
                    --freq[units];

                    if(freq[units] >= 0) ans.push_back(num);

                    ++freq[units];
                }                
                ++freq[tens];
            }
            ++freq[hundreds];
        }

        return ans;
    }
};
