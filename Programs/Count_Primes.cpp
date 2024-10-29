#include <bits/stdc++.h>
using namespace std;

/*  LeetCode
Given an integer n, return the number of prime numbers that are strictly less than n.
Constraints: 0 <= n <= 5 * 106
 */

// 1. Brute Force
class Solution {
    bool isPrime(int num) {
        for(int i= 2; i< num; i++) {
            if(num % i == 0)
                return false;
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int primeCount= 0;
        for(int i=2; i<n; i++) {
            if(isPrime(i))
                primeCount++;
        }
        return primeCount;
    }
};

// 2. Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        int primeCount= 0;
        vector<bool> arr(n+1, true);
        arr[0]= arr[1]= false;

        for(int i=2; i<n; i++) {
            if(arr[i]) {
                primeCount++;

                for(int j= 2*i; j<n; j += i)
                    arr[j]= false;
            }
        }

        return primeCount;
    }
};

// 3. Optimized Sieve
class Solution {
public:
    int countPrimes(int n) {
        int primeCount= 0;
        vector<bool> arr(n+1, true);
        arr[0]= arr[1]= false;

        for(int i=2; i*i <= n; i++) {
            if(arr[i]) {
                for(int j= i*i; j <= n; j += i)
                    arr[j]= false;
            }
        }
        for(int i=2; i<n; i++) {
            if(arr[i])
                primeCount++;
        }

        return primeCount;
    }
};

/* CodingNinjas
You are given a positive integer ‘N’. Your task is to print all prime numbers less than or equal to N.
Note: A prime number is a natural number that is divisible only by 1 and itself. Example - 2, 3, 17, etc.
Constraints: 2 <= N <= 10^7
 */

// 3. Optimized Sieve
vector<int> primeNumbersTillN(int n) { 
	vector<int> ans;
	vector<bool> isPrime(n+1, true);
	isPrime[0]= isPrime[1]= false;

	for(int i=2; i*i <= n; i++) {
		if(isPrime[i]) {
			for(int j= i*i; j <= n; j += i)
				isPrime[j]= false;
		}
	}
	for(int i=2; i<n; i++) {
		if(isPrime[i])
			ans.push_back(i);
	}

	return ans;
}

// 4. segmented Sieve
vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit+1, true);

    for(int i= 2; i*i <= limit; i++) {
        if(isPrime[i]) {
            for(int j= i*i; j <= limit; j += i) {
                isPrime[j]= false;
            }
        }
    }

    vector<int> primes;
    for(int i=2; i <= limit; i++) {
        if(isPrime[i])
            primes.push_back(i);
    }

    return primes;
}
vector<int> segmentedSieve(int n) {
// Classic Sieve of Eratosthenes up to sqrt(N)
    const int limit= sqrt(n);
    vector<int> primes= simpleSieve(limit);

// Start with primes up to sqrt(N)
    vector<int> ans= primes;                

// Process each segment from low to high
    int low= limit+1;
    int high= 2*limit;
    while(low <= n) {
    // Adjust the last segment if it exceeds N
        if(high > n)
            high= n;

    // Initialize a mark array for the current segment
        vector<bool> mark(high - low + 1, true);

    // Use each prime to mark its multiples in the current segment
        for(int& prime: primes) {
            int start= max(prime * prime, (low + prime - 1)/prime * prime);

            for(int j= start; j <= high; j += prime) {
                mark[j - low]= false;               // Mark as non-prime in the segment
            }
        }
    // Collect primes from the segment
        for(int i= low; i <= high; i++) {
            if(mark[i - low])
                ans.push_back(i);
        }
    // Move to the next segment
        low += limit;
        high += limit;
    }
// Contains all primes up to N
    return ans;
}
