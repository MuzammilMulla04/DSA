#include<bits/stdc++.h>
using namespace std;

/* LeetCode */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int profit= 0;

        for(int i=1; i<n; i++) {
            if(prices[i-1] < prices[i])
                profit += prices[i] - prices[i-1];
        }

        return profit;
    }
};


/* CodingNinjas */
int bestTimeToBuyAndSellStockII(vector<int>& prices) {
    int n= prices.size();
    int profit= 0;
    for(int i=1; i<n; i++) {
        if(prices[i-1] < prices[i])
            profit += prices[i] - prices[i-1];
    }
    return profit;
}


/* GekksForGeeks */
class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int n= prices.size();
        int profit= 0;
        
        for(int i=1; i<n; i++) {
            if(prices[i-1] < prices[i])
                profit += prices[i] - prices[i-1];
        }
        
        return profit;
    }
};