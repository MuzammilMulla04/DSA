# Without Numpy
class Solution:
    def __init__(self):
        self.N= 26
        self.MOD= int(1e9 + 7)

    def createMatrix(self, m, n, val= 0):
        return [[val for _ in range(n)] for _ in range(m)]
    
    def multiplyMatrix(self, A, B):
        m, n, p= len(A), len(A[0]), len(B[0])
        C= self.createMatrix(m, p, 0)

        for i in range(m):
            for j in range(p):
                for k in range(n):
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % self.MOD
        
        return C
    def powerMatrix(self, A, t):
        m= len(A)
        res= self.createMatrix(m, m)
        for i in range(m):
            res[i][i]= 1
        
        while t > 0:
            if t & 1:
                res= self.multiplyMatrix(res, A)
            
            A= self.multiplyMatrix(A, A)
            t >>= 1
        
        return res

    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        freq= self.createMatrix(self.N, 1, 0)
        for ch in s:
            freq[ord(ch) - ord('a')][0] += 1
        
        T= self.createMatrix(self.N, self.N, 0)
        for c in range(self.N):
            for i in range(nums[c]):
                c_dash= (c + i + 1) % self.N
                T[c_dash][c]= 1
        
        T= self.powerMatrix(T, t)
        freq= self.multiplyMatrix(T, freq)

        count= 0
        for i in range(self.N):
            count= (count + freq[i][0]) % self.MOD
        return count
    
# With Numpy
import numpy as np

class Solution:
    def __init__(self):
        self.N= 26
        self.MOD= int(1e9 + 7)

    def powerMatrix(self, A, power):
        m= len(A)
        res= np.identity(m, dtype= np.int64)
        
        while power > 0:
            if power & 1:
                res= np.dot(res, A) % self.MOD
            
            A= np.dot(A, A) % self.MOD
            power >>= 1
        
        return res

    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        freq= np.zeros((self.N, 1), dtype= np.int64)
        for ch in s:
            freq[ord(ch) - ord('a')][0] += 1
        
        T= np.zeros((self.N, self.N), dtype= np.int64)
        for c in range(self.N):
            for i in range(nums[c]):
                c_dash= (c + i + 1) % self.N
                T[c_dash][c]= 1
        
        T= self.powerMatrix(T, t)
        freq= np.dot(T, freq) % self.MOD

        return int(np.sum(freq) % self.MOD)