""" LeetCode """
class Solution:
    def reverse(nums, start, end) -> None:
        while start < end:
            nums[start], nums[end]= nums[end], nums[start]
            start += 1
            end -= 1
    def nextPermutation(self, nums: list[int]) -> None:
        n= len(nums)
        # 1. Find Pivot from Right
        pivot= -1
        for i in range(n-1, 0, -1):
            if nums[i-1] < nums[i]:
                pivot= i-1
                break
        
        # Check for Sorted
        if pivot == -1:
            self.reverse(nums, 0, n-1)
            return

        # 2. Find Rightmost Num greater than Pivot
        swapper= -1
        for i in range(n-1, 0, -1):
            if nums[pivot] < nums[i]:
                swapper= i
                break
        
        # 3. Swap Both
        nums[pivot], nums[swapper]= nums[swapper], nums[pivot]

        # 4. Reverse Array from [pivot+1, n)
        self.reverse(nums, pivot+1, n-1)
        

""" CodingNinjas """
def reverse(nums, start, end) -> None:
    while start < end:
        nums[start], nums[end]= nums[end], nums[start]
        start += 1
        end -= 1
def nextPermutation(nums, n):
    # 1. Find Pivot from Right
    pivot= -1
    for i in range(n-1, 0, -1):
        if nums[i-1] < nums[i]:
            pivot= i-1
            break
    
    # Check for Sorted
    if pivot == -1:
        reverse(nums, 0, n-1)
        return

    # 2. Find Rightmost Num greater than Pivot
    swapper= -1
    for i in range(n-1, 0, -1):
        if nums[pivot] < nums[i]:
            swapper= i
            break
    
    # 3. Swap Both
    nums[pivot], nums[swapper]= nums[swapper], nums[pivot]

    # 4. Reverse Array from [pivot+1, n)
    reverse(nums, pivot+1, n-1)
    return nums


""" GeeksForGeeks """
class Solution:
    def reverse(self, nums, start, end) -> None:
        while start < end:
            nums[start], nums[end]= nums[end], nums[start]
            start += 1
            end -= 1
    def nextPermutation(self, nums):
        n= len(nums)
        # 1. Find Pivot from Right
        pivot= -1
        for i in range(n-1, 0, -1):
            if nums[i-1] < nums[i]:
                pivot= i-1
                break
        
        # Check for Sorted
        if pivot == -1:
            self.reverse(nums, 0, n-1)
            return

        # 2. Find Rightmost Num greater than Pivot
        swapper= -1
        for i in range(n-1, 0, -1):
            if nums[pivot] < nums[i]:
                swapper= i
                break
        
        # 3. Swap Both
        nums[pivot], nums[swapper]= nums[swapper], nums[pivot]

        # 4. Reverse Array from [pivot+1, n)
        self.reverse(nums, pivot+1, n-1)

