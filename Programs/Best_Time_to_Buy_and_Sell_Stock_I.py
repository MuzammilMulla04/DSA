""" LeetCode """
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        maxProfit= 0
        minPrice= 1e5

        for price in prices:
            minPrice= min(price, minPrice)
            maxProfit= max(price - minPrice, maxProfit)
        
        return maxProfit


""" GeeksForGeeks """
class Solution:
    def maximumProfit(self, prices):
        maxProfit= 0
        minPrice= 1e5

        for price in prices:
            minPrice= min(price, minPrice)
            maxProfit= max(price - minPrice, maxProfit)
        
        return maxProfit

