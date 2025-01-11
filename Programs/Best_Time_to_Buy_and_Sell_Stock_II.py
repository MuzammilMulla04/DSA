""" LeetCode """
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profit= 0
        for i in range(1, len(prices)):
            if prices[i-1] < prices[i]:
                profit += prices[i] - prices[i-1]
        return profit


""" CodingNinjas """
def bestTimeToBuyAndSellStockII(prices: list[int]) -> int:
    profit= 0
    for i in range(1, len(prices)):
        if prices[i-1] < prices[i]:
            profit += prices[i] - prices[i-1]
    return profit


""" GeeksForGeeks """
class Solution:
    def maximumProfit(self, prices) -> int:
        profit= 0
        for i in range(1, len(prices)):
            if prices[i-1] < prices[i]:
                profit += prices[i] - prices[i-1]
        return profit

