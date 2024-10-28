import List
from collections import Counter

# CodingNinjas
def twoSum(arr, target, n):
    ans= list()

    freq= dict()
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num]= 1
    # freq= Counter(arr)

    for num in arr:
        complement= target - num

        if freq.get(complement, 0) > 0:
            if num == complement:
                if freq[num] > 1:
                    ans.append([num, num])
                    freq[num] -= 2
            elif freq[num] > 0 and freq[complement] > 0:
                ans.append([num, complement])
                freq[num] -= 1
                freq[complement] -= 1

    if not ans:
        ans.append([-1, -1])

    return ans

# LeetCode
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numToIndex= dict()
        for index, num in enumerate(nums):
            complement= target - num

            if complement in numToIndex.keys():
                return [index, numToIndex[complement]]

            numToIndex[num]= index
        return []
