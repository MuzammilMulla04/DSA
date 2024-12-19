from collections import Counter


""" LeetCode """
class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        freq= Counter(nums)

        n= len(nums)
        for key, value in freq.items():
            if value > n//2:
                return key
        
        return -1


""" CodingNinjas """
def findMajorityElement(arr, n):
	freq= Counter(arr)

	for key, value in freq.items():
		if value > n//2:
			return key
	
	return -1

