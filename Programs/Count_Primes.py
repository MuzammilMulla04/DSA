""" LeetCode
Given an integer n, return the number of prime numbers that are strictly less than n.
Constraints: 0 <= n <= 5 * 106
 """

# 1. Brute Force
class Solution:
    def isPrime(self, num: int) -> bool:
        """ [expression_if_true if condition else expression_if_false for item in iterable] """
        return not any(num % i == 0 for i in range(2, 1 + int(num**0.5)))

    def countPrimes(self, n: int) -> int:
        return sum(self.isPrime(i) for i in range(2, n))

# 2. Sieve Of Eratosthenes
class Solution:
    def countPrimes(self, n: int) -> int:
        primeCount= 0
        if n < 2:
            return primeCount

        isPrime= [True] * n
        isPrime[0]= isPrime[1]= False

        for i in range(2, n, 1):
            if isPrime[i]:
                for j in range(i*i, n, i):
                    isPrime[j]= False

        primeCount= sum(isPrime)
        return primeCount

# 3. Optimized Sieve
class Solution:
    def countPrimes(self, n: int) -> int:
        primeCount= 0
        if n < 2:
            return primeCount

        isPrime= [True] * n
        isPrime[0]= isPrime[1]= False

        for i in range(2, 1 + int(n**0.5), 1):
            if isPrime[i]:
                for j in range(i*i, n, i):
                    isPrime[j]= False

        primeCount= sum(isPrime)
        return primeCount

""" CodingNinjas
You are given a positive integer N. Your task is to print all prime numbers less than or equal to N.
Note: A prime number is a natural number that is divisible only by 1 and itself. Example - 2, 3, 17, etc.
Constraints: 2 <= N <= 10^7
 """

# 3. Optimized Sieve (How this worked!!??)
def primeNumbersTillN(n):
    isPrime= [True] * (n+1)
    isPrime[0]= isPrime[1]= False

    for i in range(2, 1 + int(n**0.5)):
        if isPrime[i]:
            for j in range(i*i, n+1, i):
                isPrime[j]= False
    return [key for key, val in enumerate(isPrime) if val]

# 4. Segmented Sieve
def primeNumbersTillN(n):
    isPrime= [True] * (n+1)
    isPrime[0]= isPrime[1]= False

    for i in range(2, 1 + int(n**0.5)):
        if isPrime[i]:
            for j in range(i*i, n+1, i):
                isPrime[j]= False
    return [key for key, val in enumerate(isPrime) if val]
