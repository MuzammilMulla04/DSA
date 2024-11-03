import List

# LeetCode
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        start, end= 0, len(nums)-1
        while start < end:
            mid= start + (end-start)//2

            if nums[mid] < nums[mid+1]:
                start= mid+1
            else:
                end= mid
        return start
    
# CodingNinjas
def findPeakElement(arr: [int]) -> int:
    n= len(arr)
    mid= -1
    start, end= 0, n-1
    while start <= end:
        mid= start + (end-start)//2

        leftIsGreater= mid > 0 and arr[mid-1] >= arr[mid]
        rightIsGreater= mid < n-1 and arr[mid] <= arr[mid+1]

        if leftIsGreater:
            end= mid-1
        elif rightIsGreater:
            start= mid+1
        else:
            return mid
    return mid
