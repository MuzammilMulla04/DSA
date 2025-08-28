class Solution:
    def lengthAfterTransformations(self, str: str, t: int) -> int:
        MOD= 1e9 + 7

        freq= [0] * 26
        for ch in str:
            freq[ord(ch) - ord('a')] += 1

        for _ in range(t):
            temp= [0] * 26
            
            temp[0]= freq[25]
            temp[1]= (freq[25] + freq[0]) % MOD

            for i in range(2, 26):
                temp[i]= freq[i-1]
            
            freq= temp
        
        ans= 0
        for num in freq:
            ans= (ans + num) % MOD
        return int(ans)
