from collections import Counter

""" CodingNinjas """
def findDuplicates(arr, n):
    freq= Counter(arr)
    ans= []
    for num, value in freq.items():
        if value > 1:
            ans.append(num)
    return ans

""" LeetCode """
# Using Counter
class Solution:
    def findDuplicates(self, nums: list[int]) -> list[int]:
        freq= Counter(nums)
        ans= []
        for num, value in freq.items():
            if value > 1:
                ans.append(num)
        return ans

# Using Masked Index
class Solution:
    def findDuplicates(self, nums: list[int]) -> list[int]:
        ans= []
        for num in nums:
            index= abs(num)-1
            if nums[index] < 0:
                ans.append(index+1)
            else:
                nums[index]= -nums[index]
        return ans
