class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int totalSum = 0, n = num.size();
        vector<int> digitFreq(10);

        // Count digit frequency and total digit sum
        for (char ch : num) {
            int d = ch - '0';
            digitFreq[d]++;
            totalSum += d;
        }

        // Can't split into equal sums
        if (totalSum % 2 != 0) return 0;

        int targetSum = totalSum / 2;
        int maxOddSlots = (n + 1) / 2;

        // Precompute prefix sum of digit frequencies
        vector<int> prefixFreq(11);
        for (int i = 9; i >= 0; --i) {
            prefixFreq[i] = prefixFreq[i + 1] + digitFreq[i];
        }

        // Precompute combinations (n choose k)
        vector<vector<long long>> comb(maxOddSlots + 1, vector<long long>(maxOddSlots + 1));
        for (int i = 0; i <= maxOddSlots; ++i) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        // 3D memoization array: [digit][currSum][oddSlotsLeft]
        long long memo[10][targetSum + 1][maxOddSlots + 1];
        memset(memo, -1, sizeof(memo));

        // Recursive DFS with memoization
        function<long long(int, int, int)> dfs = [&](int digit, int currSum, int oddLeft) -> long long {
            // Invalid state
            if (oddLeft < 0 || prefixFreq[digit] < oddLeft || currSum > targetSum) return 0;
            // All digits considered
            if (digit > 9) return (currSum == targetSum && oddLeft == 0);

            // Memoized result
            if (memo[digit][currSum][oddLeft] != -1) return memo[digit][currSum][oddLeft];

            long long res = 0;
            int evenLeft = prefixFreq[digit] - oddLeft;

            // Try placing 'i' occurrences of this digit in odd slots
            for (int i = max(0, digitFreq[digit] - evenLeft);
                 i <= min(digitFreq[digit], oddLeft); ++i) {
                int oddUse = i;
                int evenUse = digitFreq[digit] - i;

                long long ways = (comb[oddLeft][oddUse] * comb[evenLeft][evenUse]) % MOD;

                res = (res + ways * dfs(digit + 1, currSum + oddUse * digit, oddLeft - oddUse) % MOD) % MOD;
            }

            return memo[digit][currSum][oddLeft] = res;
        };

        return dfs(0, 0, maxOddSlots);
    }
};
