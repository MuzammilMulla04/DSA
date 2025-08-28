class Solution {
    const int N = 26;
    const int MOD = 1e9 + 7;

    using Matrix = vector<vector<int>>;
    Matrix createMatrix(const int& m, const int& n, const int val = 0) {
        return Matrix(m, vector<int>(n, val));
    }

    Matrix multiplyMatrix(const Matrix& A, const Matrix& B) {
        int m = A.size(), n = A[0].size(), p = B[0].size();
        Matrix C = createMatrix(m, p, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < p; ++j) {
                for (int k = 0; k < n; ++k) {
                    C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }
    void powerMatrix(Matrix& A, int n) {
        const int m = A.size();
        Matrix res = createMatrix(m, m, 0);
        for (int i = 0; i < m; ++i) res[i][i] = 1;

        while (n > 0) {
            if (n & 1) res = multiplyMatrix(res, A);

            A = multiplyMatrix(A, A);
            n >>= 1;
        }

        A = res;
    }

public:
    int lengthAfterTransformations(string str, int t, vector<int>& nums) {
        Matrix freq = createMatrix(N, 1, 0);
        for (const char& ch : str) ++freq[ch - 'a'][0];

        Matrix T = createMatrix(N, N, 0);
        for (int c = 0; c < 26; ++c) {
            for (int i = 0; i < nums[c]; ++i) {
                int c_dash = (c + i + 1) % N;
                T[c_dash][c] = 1;
            }
        }

        powerMatrix(T, t);

        Matrix ans = multiplyMatrix(T, freq);

        int count = 0;
        for (int i = 0; i < 26; ++i) count = (count + ans[i][0]) % MOD;
        return count;
    }
};