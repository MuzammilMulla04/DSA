""" LeetCode """
# Append & Remove: O(n^2)
class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        for num in nums:
            if num == 0:
                nums.append(num)
                nums.remove(num)
# Two Pointers: O(n)
class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        i= 0
        for j in range(len(nums)):
            if nums[j] != 0:
                nums[i], nums[j]= nums[j], nums[i]
                i += 1

""" CodingNinjas """
def pushZerosAtEnd(arr):
    i= 0
    for j in range(len(arr)):
        if arr[j] != 0:
            arr[i], arr[j]= arr[j], arr[i]
            i += 1


""" GeeksForGeeks """
class Solution:
    def pushZerosToEnd(self, arr):
        i= 0
        for j in range(len(arr)):
            if arr[j] != 0:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
