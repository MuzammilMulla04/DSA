#include<bits/stdc++.h>
using namespace std;

/* LeetCode */
// 1. Keep Track of Min & Max
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit= 0, minPrice= INT_MAX;
        
        for(int& price: prices) {
            minPrice= min(price, minPrice);
            maxProfit= max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

// 2. Two Pointers
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();

        int maxProfit= 0;
        int profit= 0;
        
        int b= 0, s= 1;
        while(s<n) {
            if(prices[b] <= prices[s]) {
                profit= prices[s] - prices[b];
                maxProfit= max(profit, maxProfit);
            } else {
                b= s;
            }

            s++;
        }

        return maxProfit;
    }
};


/* GeeksForGeeks */
class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int maxProfit= 0, minPrice= INT_MAX;
        
        for(int& price: prices) {
            minPrice= min(price, minPrice);
            maxProfit= max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
