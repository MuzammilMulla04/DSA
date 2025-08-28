class Solution {
public:
    int lengthAfterTransformations(string str, int t) {
        const int MOD= 1e9 + 7;

        vector<int> freq(26, 0);
        for(const char& ch: str) ++freq[ch - 'a'];

        for(int round= 0; round < t; ++round) {
            vector<int> temp(26);

            temp[0]= freq[25];
            temp[1]= (freq[25] + freq[0]) % MOD;

            for(int i=2; i<26; ++i) temp[i]= freq[i-1];

            freq= move(temp);
        }

        int sum= 0;
        for(const int& num: freq) sum= (sum + num) % MOD;
        return sum;
    }
};